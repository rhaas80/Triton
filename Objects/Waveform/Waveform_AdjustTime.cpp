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



Waveform& Waveform::AddToTime(const double time) {
  History() << "### this->AddToTime(" << setprecision(16) << time << ");" << endl;
  TRef() += time;
  return *this;
}

Waveform& Waveform::DropBefore(const double time) {
  History() << "### this->DropBefore(" << setprecision(16) << time << ");" << endl;
  unsigned int i=0;
  while(i<NTimes()-1 && T(i+1)<=time) { ++i; }
  if(R().size()==NTimes()) { RRef().erase(RRef().begin(), (RRef().begin())+i); }
  t.erase(t.begin(), t.begin()+i);
  for(unsigned int j=0; j<NModes(); ++j) {
    MagRef(j).erase(MagRef(j).begin(), MagRef(j).begin()+i);
    ArgRef(j).erase(ArgRef(j).begin(), ArgRef(j).begin()+i);
  }
  return *this;
}

Waveform& Waveform::DropAfter(const double time) {
  History() << "### this->DropAfter(" << setprecision(16) << time << ");" << endl;
  unsigned int i=NTimes()-1;
  while(i>0 && T(i)>time) { --i; }
  if(RRef().size()==NTimes()) { RRef().erase(RRef().begin()+i, RRef().end()); }
  TRef().erase(TRef().begin()+i, TRef().end());
  for(unsigned int j=0; j<NModes(); ++j) {
    MagRef(j).erase(MagRef(j).begin()+i, MagRef(j).end());
    ArgRef(j).erase(ArgRef(j).begin()+i, ArgRef(j).end());
  }
  return *this;
}

Waveform& Waveform::ZeroBefore(const double time) {
  History() << "### this->ZeroBefore(" << setprecision(16) << time << ");" << endl;
  unsigned int i=0;
  while(i<NTimes()-1 && T(i+1)<=time) { ++i; }
  for(unsigned int j=0; j<NModes(); ++j) {
    for(unsigned int k=0; k<i; ++k) {
      MagRef(j,k) = 0.0;
    }
  }
  return *this;
}

Waveform& Waveform::UniformTimeToPowerOfTwo() {
  if(((NTimes()) & (NTimes()-1)) == 0) { return *this; } // Return *this if we already have a power of 2
  History() << "### this->UniformTimeToPowerOfTwo();" << endl << "#";
  unsigned int N = static_cast<unsigned int>(pow(2.0,ceil(log2(NTimes()))));
  double dt = (T().back()-T(0))/(N-1);
  vector<double> NewTime(N, 0.0);
  for(unsigned int i=0; i<N; ++i) {
    NewTime[i] = T(0) + i*dt;
  }
  this->Interpolate(NewTime);
  return *this;
}

Waveform& Waveform::UniformTime(const unsigned int N) {
  History() << "### this->UniformTime(" << N << ");" << endl << "#";
  double dt = (T().back()-T(0))/(N-1);
  vector<double> NewTime(N, 0.0);
  for(unsigned int i=0; i<N; ++i) {
    NewTime[i] = T(0) + i*dt;
  }
  this->Interpolate(NewTime);
  return *this;
}

Waveform& Waveform::NSamplesPerCycle22(const unsigned int N) {
  History() << "### this->NSamplesPerCycle22(" << N << ");" << endl << "#";
  vector<double> NewTime(NTimes());
  vector<double> omega22s = Omega2m2();
  NewTime[0] = T(0);
  unsigned int iNew=1;
  double dt_Last = T(1)-T(0);
  for(unsigned int iOld=1; iNew<NTimes() && iOld<NTimes(); iNew++) {
    const double omega22 = omega22s[iOld];
    const double dt_Data = T(iOld)-T(iOld-1);
    const double dt_Samples = (fabs(omega22)==0.0 ? 0.0 : 2*M_PI / (N*fabs(omega22)));
    const double dt_New = max(dt_Data, min(dt_Samples, 1.1*dt_Last));
    const double t_New = NewTime[iNew-1] + dt_New;
    if(t_New>T().back()) { break; }
    while(T(iOld)<t_New && iOld<NTimes()) { iOld++; }
    NewTime[iNew] = t_New;
    dt_Last = dt_New;
  }
  NewTime.erase(NewTime.begin()+iNew, NewTime.end());
  this->Interpolate(NewTime);
  return *this;
}
