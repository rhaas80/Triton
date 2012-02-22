#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

#include "../Waveform.hpp"

#include "Interpolate.hpp"
#include "Minimize.hpp"
#include "FileIO.hpp"
#include "SWSHs.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Units.hpp"
#include "PostNewtonian.hpp"
#include "WignerDMatrix.hpp"
#include "Quaternions.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::setprecision;
using std::stringstream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::min;
using std::max;
using std::ios_base;


unsigned int Waveform::FindModeIndex(const int l, const int m) const {
  int ModeIndex = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==l && M(i)==m) { ModeIndex=i; break; }
  }
  if(ModeIndex==-1) {
    std::cerr << "\n\nl=" << l << " m=" << m << std::endl;
    throw("Can't find the l,m component of the data!");
  }
  return (unsigned int)(ModeIndex);
}

unsigned int Waveform::Peak22TimeIndex() const {
  //// Find 2,2 component
  int TwoTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==2 && M(i)==2) { TwoTwo=i; break; }
  }
  //// Error if not found
  if(TwoTwo==-1) { throw("Can't find the 2,2 component of the data!"); }
  return (unsigned int)(maxIndex(Mag(TwoTwo)));
}

double Waveform::Peak22Time() const {
  return T(Peak22TimeIndex());
}

vector<double> Waveform::Omega2m2(const double t1, const double t2) const {
  //// Find 2,2 component
  int TwomTwo = -1;
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==2 && M(i)==-2) { TwomTwo=i; break; }
  }
  
  //// Error if not found
  if(TwomTwo==-1) {
    for(unsigned int i=0; i<NModes(); ++i) {
      if(L(i)==2 && M(i)==2) { TwomTwo=i; break; }
    }
    if(TwomTwo==-1) {
      cerr << "\nlm=\n" << LM() << endl;
      throw("Bad L,M data; no (2,-2) mode.");
    }
    cerr << "\n(2,-2) mode not found; proceeding with (2,2) mode.\n" << endl;
  }
  
  //// Return differentiated Arg data
  //ORIENTATION!!! following section
  if((t1!=-1e300 && t1>T(0)) && (t2!=1e300 && t2<T().back())) {
    vector<double> NewTime(T());
    vector<double> phase(Arg(TwomTwo));
    int i=NewTime.size()-1;
    while(NewTime[i]>t2) { --i; }
    NewTime.erase(NewTime.begin()+i, NewTime.begin()+NewTime.size());
    phase.erase(phase.begin()+i, phase.begin()+phase.size());
    i=0;
    while(NewTime[i]<t1) { ++i; }
    NewTime.erase(NewTime.begin(), NewTime.begin()+i);
    phase.erase(phase.begin(), phase.begin()+i);
    return dydx(phase, NewTime);
  } else if((t1!=-1e300 && t1>T(0))) {
    vector<double> NewTime(T());
    vector<double> phase(Arg(TwomTwo));
    int i=0;
    while(NewTime[i]<t1) { ++i; }
    NewTime.erase(NewTime.begin(), NewTime.begin()+i);
    phase.erase(phase.begin(), phase.begin()+i);
    return dydx(phase, NewTime);
  } else if((t2!=1e300 && t2<T().back())) {
    vector<double> NewTime(T());
    vector<double> phase(Arg(TwomTwo));
    int i=NewTime.size()-1;
    while(NewTime[i]>t2) { --i; }
    NewTime.erase(NewTime.begin()+i, NewTime.begin()+NewTime.size());
    phase.erase(phase.begin()+i, phase.begin()+phase.size());
    return dydx(phase, NewTime);
  } else {
    return dydx(Arg(TwomTwo), t);
  }
}

bool Waveform::HasNaNs() const {
  bool hasnans = false;
  for(unsigned int i=0; i<NTimes(); ++i) {
    if(t[i]!=t[i]) {
      cerr << "\nChecking Waveform, a NaN was detected in the Time at index i=" << i << "." << endl;
      hasnans = true;
    }
  }
  for(unsigned int i=0; i<NModes(); ++i) {
    for(unsigned int j=0; j<NTimes(); ++j) {
      if(Mag(i,j)!=Mag(i,j)) {
	cerr << "\nChecking Waveform, a NaN was detected in the Mag at index i=" << i << ", j=" << j << " of " << Mag(i).size() << "." << endl;
	hasnans = true;
      }
    }
  }
  for(unsigned int i=0; i<NModes(); ++i) {
    for(unsigned int j=0; j<NTimes(); ++j) {
      if(Arg(i,j)!=Arg(i,j)) {
	cerr << "\nChecking Waveform, a NaN was detected in the Arg at index i=" << i << ", j=" << j << " of " << Arg(i).size() << "." << endl;
	hasnans = true;
      }
    }
  }
  return hasnans;
}

vector<double> Waveform::Flux() const {
  if(TypeIndex()%3!=1) {
    cerr << "\nType = " << Type() << endl;
    throw("Can't get Flux() for Waveform of Type other than rhdot.  Maybe you should use Differentiate().");
  }
  vector<double> Flux(NTimes(), 0.0);
  //ORIENTATION!!! Following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    Flux += Mag(i)*Mag(i);
  }
  return (Flux/(16.0*M_PI));
}

// Mostly useful for getting the flux
Waveform& Waveform::Differentiate() {
  if(TypeIndex()%3==0) {
    cerr << "\nType=" << Type() << endl;
    throw("Derivative of Psi4 not supported.");
  }
  TypeIndexRef() -= 1;
  vector<double> magdot(NTimes()), argdot(NTimes());
  // Loop over each component, doing the differentiation
  //ORIENTATION!!!! Following loop
  for(unsigned int iMode=0; iMode<NModes(); ++iMode) {
    magdot = dydx(Mag(iMode), T());
    argdot = dydx(Arg(iMode), T());
    MagRef(iMode) = sqrt(magdot*magdot + Mag(iMode)*Mag(iMode)*argdot*argdot);
    ArgRef(iMode) = Arg(iMode) + Unwrap(atan2(Mag(iMode)*argdot, magdot));
  }
  return *this;
}
