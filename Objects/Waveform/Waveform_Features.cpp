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


/// Find index of mode with given (l,m) data.
unsigned int WaveformObjects::Waveform::FindModeIndex(const int l, const int m) const {
  int ModeIndex = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==l && M(i)==m) { ModeIndex=i; break; }
  }
  if(ModeIndex==-1) {
    std::cerr << "\n\nl=" << l << " m=" << m << std::endl;
    Throw1WithMessage("Can't find the l,m component of the data!");
  }
  return (unsigned int)(ModeIndex);
}

/// Return the time index at which the (2,2) mode peaks.
unsigned int WaveformObjects::Waveform::Peak22TimeIndex() const {
  // Find 2,2 component
  int TwoTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==2 && M(i)==2) { TwoTwo=i; break; }
  }
  // Error if not found
  if(TwoTwo==-1) { Throw1WithMessage("Can't find the 2,2 component of the data!"); }
  return (unsigned int)(maxIndex(Mag(TwoTwo)));
}

/// Return the time at which the (2,2) mode peaks.
double WaveformObjects::Waveform::Peak22Time() const {
  return T(Peak22TimeIndex());
}

/// Return the time index at which the GW flux peaks.
unsigned int WaveformObjects::Waveform::PeakFluxTimeIndex() const {
  return (unsigned int)(maxIndex(Flux()));
}

/// Return the time at which the GW flux peaks.
double WaveformObjects::Waveform::PeakFluxTime() const {
  return T(PeakFluxTimeIndex());
}

/// Return the time index at which the L2 norm of the waveform peaks.
unsigned int WaveformObjects::Waveform::PeakL2TimeIndex() const {
  return (unsigned int)(maxIndex(L2Norm()));
}

/// Return the time at which the L2 norm of the waveform peaks.
double WaveformObjects::Waveform::PeakL2Time() const {
  return T(PeakL2TimeIndex());
}

/// Return the frequency of the (2,-2) mode.
std::vector<double> WaveformObjects::Waveform::Omega2m2(const double t1, const double t2) const {
  /// In standard configuration, this quantity will typically be
  /// increasing; the (2,2) frequency will typically be decreasing
  /// because of the definitions of h and Psi4 and the definition of
  /// the frequency as the derivative of `arg`.

  // Find 2,2 component
  int TwomTwo = -1;
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==2 && M(i)==-2) { TwomTwo=i; break; }
  }

  // Error if not found
  if(TwomTwo==-1) {
    for(unsigned int i=0; i<NModes(); ++i) {
      if(L(i)==2 && M(i)==2) { TwomTwo=i; break; }
    }
    if(TwomTwo==-1) {
      cerr << "\nlm=\n" << LM() << endl;
      Throw1WithMessage("Bad L,M data; no (2,-2) mode.");
    }
    cerr << "\n(2,-2) mode not found; proceeding with (2,2) mode.\n" << endl;
  }

  // Return differentiated Arg data
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

/// Check various data for NaNs.
bool WaveformObjects::Waveform::HasNaNs() const {
  bool hasnans = false;
  for(unsigned int i=0; i<NTimes(); ++i) {
    if(T(i)!=T(i)) {
      cerr << "\nChecking Waveform, a NaN was detected in the Time at index i=" << i << "." << endl;
      hasnans = true;
    }
  }
  for(unsigned int i=0; i<frame.size(); ++i) {
    if(Frame(i)!=Frame(i)) {
      cerr << "\nChecking Waveform, a NaN was detected in the Frame at index i=" << i << "." << endl;
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

/// Calculate the GW flux.
std::vector<double> WaveformObjects::Waveform::Flux() const {
  /// NB: This function can only be used on Waveform data of type
  /// `rhdot` or `rh`.  For `rh`, conversion to `rhdot` is done
  /// automatically.  Because there is no automatic integration method
  /// implemented at this time, `rPsi4` cannot be used with this
  /// function.
  ///
  /// Also, if the frame is non-constant, the Waveform is copied, the
  /// copy is transformed into the original frame, and the flux is
  /// calculated for that copy.  If you are using a constant frame for
  /// something else, you may be better off saving that as a separate
  /// Waveform, and applying this function to your own copy.
  if(TypeIndex()%3==2) {
    Waveform W(*this);
    return W.Differentiate().Flux();
  }
  if(TypeIndex()%3!=1) {
    cerr << "\nType = " << Type() << endl;
    Throw1WithMessage("Can't get Flux() for Waveform of type Psi4 -- don't know how to integrate automatically.");
  }
  if(Frame().size()>1) {
    Waveform W(*this);
    W.TransformToStandardFrame();
    W.FrameRef().clear();
    return W.Flux();
  }
  vector<double> Flux(NTimes(), 0.0);
  //ORIENTATION!!! Following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    Flux += Mag(i)*Mag(i);
  }
  return (Flux/(16.0*M_PI));
}

inline double sqr(const double t) { return t*t; }

/// Calculate the L2 norm of the data.
std::vector<double> WaveformObjects::Waveform::L2Norm() const {
  /// This is as suggested by Mark Scheel, Tony Chu, and Béla
  /// Szilagyi, per Mark's description at
  /// https://www.ninja-project.org/doku.php?id=nrar:internal:nr_measure_accuracy#another_idea_for_measuring_errors
  /// The L2 norm can be useful when measuring fractional errors in
  /// modes whose amplitude goes through zero (such as m=0 modes, or
  /// any mode in highly precessing systems).
  vector<double> L2(NTimes());
  for(unsigned int t=0; t<L2.size(); ++t) {
    L2[t] = 0.0;
    for(unsigned int mode=0; mode<NModes(); ++mode) {
      L2[t] += sqr(Mag(mode, t));
    }
    L2[t] = sqrt(L2[t]);
  }
  return L2;
}

/// Calculate the difference normalized by the average L2 norm.
std::vector<double> WaveformObjects::Waveform::L2NormDifference(const Waveform& b) const {
  /// This is as suggested by Mark Scheel, Tony Chu, and Béla
  /// Szilagyi, per Mark's description at
  /// https://www.ninja-project.org/doku.php?id=nrar:internal:nr_measure_accuracy#another_idea_for_measuring_errors
  /// with the only difference being that the average L2 norm is used
  /// to normalize, rather than the sum.  This can be useful when
  /// measuring fractional errors in modes whose amplitude goes
  /// through zero (such as m=0 modes, or any mode in highly
  /// precessing systems).
  if(b.NModes() != NModes() || b.LM().RawData() != LM().RawData()) {
    Throw1WithMessage("Trying to compare Waveform objects with mismatched LM data");
  }
  Waveform c = *this;
  Waveform d = b;
  vector<double> NewTime = Intersection(c.T(), d.T(), 5e-8, -1e300);
  c.Interpolate(NewTime);
  d.Interpolate(NewTime);
  vector<double> L2c = c.L2Norm();
  vector<double> L2d = d.L2Norm();
  vector<double> diff(NewTime.size());
  for(unsigned int t=0; t<NewTime.size(); ++t) {
    diff[t] = 0.0;
    for(unsigned int m=0; m<c.NModes(); ++m) {
      const double Re = c.Mag(m,t)*cos(c.Arg(m,t)) - d.Mag(m,t)*cos(d.Arg(m,t));
      const double Im = c.Mag(m,t)*sin(c.Arg(m,t)) - d.Mag(m,t)*sin(d.Arg(m,t));
      diff[t] += Re*Re + Im*Im;
    }
    diff[t] = sqrt(diff[t]) / ((L2c[t]+L2d[t])/2.0);
  }
  return diff;
}


/// Differentiate the Waveform.
Waveform& WaveformObjects::Waveform::Differentiate() {
  /// Most useful for finding the Flux, or (when used twice) for
  /// comparing h to Psi4.
  ///
  /// This function only works on data of type h or hdot (or multiples
  /// thereof).  In particular, the code does not know what data type
  /// Psi4 should be after being differentiated.
  ///
  /// Also note that if the Waveform is in a rotating frame, the data
  /// is first transformed to a stationary frame, then differentiated,
  /// then transformed back into the original rotating frame.
  History() << "### this->Differentiate();" << endl;
  if(TypeIndex()%3==0) {
    cerr << "\nType=" << Type() << endl;
    Throw1WithMessage("Derivative of Psi4 not supported.");
  }
  vector<Quaternion> OriginalFrame;
  bool Transformed = false;
  if(Frame().size()>1) {
    Transformed = true;
    OriginalFrame = this->Frame();
    this->TransformToStandardFrame();
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
  if(Transformed) { this->RotatePhysicalSystem(OriginalFrame); }
  return *this;
}
