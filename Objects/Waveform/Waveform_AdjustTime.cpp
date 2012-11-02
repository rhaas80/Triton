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


/// Simply add the input constant to the time data of the Waveform.
Waveform& WaveformObjects::Waveform::AddToTime(const double time) {
  History() << "### this->AddToTime(" << setprecision(16) << time << ");" << endl;
  TRef() += time;
  return *this;
}

/// Delete data from the Waveform occurring at or before the input time.
Waveform& WaveformObjects::Waveform::DropBefore(const double time) {
  History() << "### this->DropBefore(" << setprecision(16) << time << ");" << endl;
  unsigned int i=0;
  while(i<NTimes()-1 && T(i+1)<=time) { ++i; }
  if(R().size()==NTimes()) { RRef().erase(RRef().begin(), (RRef().begin())+i); }
  if(Frame().size()==NTimes()) { FrameRef().erase(FrameRef().begin(), (FrameRef().begin())+i); }
  t.erase(t.begin(), t.begin()+i);
  for(unsigned int j=0; j<NModes(); ++j) {
    MagRef(j).erase(MagRef(j).begin(), MagRef(j).begin()+i);
    ArgRef(j).erase(ArgRef(j).begin(), ArgRef(j).begin()+i);
  }
  return *this;
}

/// Delete data from the Waveform occurring after the input time.
Waveform& WaveformObjects::Waveform::DropAfter(const double time) {
  History() << "### this->DropAfter(" << setprecision(16) << time << ");" << endl;
  unsigned int i=NTimes()-1;
  while(i>0 && T(i)>time) { --i; }
  if(RRef().size()==NTimes()) { RRef().erase((RRef().begin())+i, RRef().end()); }
  if(Frame().size()==NTimes()) { FrameRef().erase((FrameRef().begin())+i, FrameRef().begin()); }
  TRef().erase(TRef().begin()+i, TRef().end());
  for(unsigned int j=0; j<NModes(); ++j) {
    MagRef(j).erase(MagRef(j).begin()+i, MagRef(j).end());
    ArgRef(j).erase(ArgRef(j).begin()+i, ArgRef(j).end());
  }
  return *this;
}

/// Set magnitude to zero for data at or before the input time.
Waveform& WaveformObjects::Waveform::ZeroBefore(const double time) {
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

/// Interpolate to evenly spaced time axis with size 2^n for integer n.
Waveform& WaveformObjects::Waveform::UniformTimeToPowerOfTwo() {
  /// This function is useful for interpolating the data to a time
  /// series appropriate for FFTing.  The size of the output is the
  /// smallest 2^n that is larger than the current size of the data.
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

/// Interpolate to evenly spaced time axis of size N.
Waveform& WaveformObjects::Waveform::UniformTime(const unsigned int N) {
  History() << "### this->UniformTime(" << N << ");" << endl << "#";
  double dt = (T().back()-T(0))/(N-1);
  vector<double> NewTime(N, 0.0);
  for(unsigned int i=0; i<N; ++i) {
    NewTime[i] = T(0) + i*dt;
  }
  this->Interpolate(NewTime);
  return *this;
}

/// Resample data such that there are N samples per cycle of the (2,2) mode.
Waveform& WaveformObjects::Waveform::NSamplesPerCycle22(const unsigned int N) {
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

/// Erase earliest data that overlaps later data.
Waveform& WaveformObjects::Waveform::MakeTimeMonotonic(const double MinTimeStep) {
  History() << "### this->MakeTimeMonotonic(" << MinTimeStep << ");" << endl << "#";
  vector<double> NewTime(T());
  int Size = NewTime.size();
  int i=1;
  while(i<Size) {
    if(NewTime[i]<=NewTime[i-1]+MinTimeStep) {
      int j=0;
      while(NewTime[j]+MinTimeStep<NewTime[i]) { ++j; }
      // erase data from j (inclusive) to i (exclusive)
      NewTime.erase(NewTime.begin()+j, NewTime.begin()+i);
      Size = NewTime.size();
      i = j-1;
    }
    ++i;
  }
  this->Interpolate(NewTime);
  return *this;
}
