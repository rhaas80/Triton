#include "WaveformAtAPoint.hpp"
#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include "SWSHs.cpp"
#include <cmath>
using namespace std;

WaveformAtAPoint::WaveformAtAPoint(const Waveform& W, const double Vartheta, const double Varphi)
  : vartheta(Vartheta), varphi(Varphi)
{
  Type = W.Type;
  TimeScale = W.TimeScale;
  Radius = W.Radius;
  Time = W.Time;
  //ORIENTATION!!! following lines
  amp = vector<vector<double> >(1, vector<double>(W.amp[0].size(), 0.0));
  phi = vector<vector<double> >(1, vector<double>(W.phi[0].size(), 0.0));
  vector<double> Amp, Phi, Amplitude, Phase;
  SWSH(W.LM, vartheta, varphi, Amp, Phi);
  for(unsigned int i=0; i<W.amp.size(); ++i) { // Loop over components
    Amplitude = Amp[i] * W.amp[i];
    Phase     = Phi[i] + W.phi[i];
    amp[0] += Amplitude * cos(Phase);
    phi[0] += Amplitude * sin(Phase);
  }
}

WaveformAtAPoint::WaveformAtAPoint(const Waveform& W, const double dt, const double Vartheta, const double Varphi)
  : vartheta(Vartheta), varphi(Varphi)
{
  Time = vector<double>((unsigned int)(floor((W.Time[W.Time.size()-1]-W.Time[0])/dt)));
  for(unsigned int i=0; i<Time.size(); ++i) {
    Time[i] = W.Time[0]+i*dt;
  }
  Type = W.Type;
  TimeScale = W.TimeScale;
  Radius = ::Interpolate(W.Time, W.Radius, Time);
  //ORIENTATION!!! following lines
  amp = vector<vector<double> >(1, vector<double>(Time.size(), 0.0));
  phi = vector<vector<double> >(1, vector<double>(Time.size(), 0.0));
  vector<double> Amp, Phi, Amplitude, Phase;
  SWSH(W.LM, vartheta, varphi, Amp, Phi);
  for(unsigned int i=0; i<W.amp.size(); ++i) { // Loop over components
    Amplitude = Amp[i] * ::Interpolate(W.Time, W.amp[i], Time);
    Phase     = Phi[i] + ::Interpolate(W.Time, W.phi[i], Time);
    amp[0] += Amplitude * cos(Phase);
    phi[0] += Amplitude * sin(Phase);
  }
}

inline double WindowFactor(const unsigned int k, const unsigned int NumPoints) {
  return 0.5*(1.0-cos((M_PI)*k/NumPoints));
}

WaveformAtAPoint & WaveformAtAPoint::Window(const unsigned int NumPointsStart, const unsigned int NumPointsEnd) {
  if(NumPointsStart/double(Time.size())>=0.5 || NumPointsEnd/double(Time.size())>=0.5) {
    cerr << "Can't window more than half of the data on either side.\n"
	 << "You requested a starting window of " << NumPointsStart
	 << " of the data, and an ending widnow of " << NumPointsEnd
	 << " for data of length " << Time.size() << "." << endl;
    exit(1);
  }
  for(unsigned int k=0; k<NumPointsStart; ++k) { // Turn on the amplitude
    Re(k) *= WindowFactor(k, NumPointsStart);
    Im(k) *= WindowFactor(k, NumPointsStart);
  }
  for(unsigned int k=0; k<NumPointsEnd; ++k) { // Turn off the amplitude
    Re(Time.size()-1-k) *= WindowFactor(k, NumPointsEnd);
    Im(Time.size()-1-k) *= WindowFactor(k, NumPointsEnd);
  }
  return *this;
}

// WaveformAtAPoint & WaveformAtAPoint::Window(const double FractionStart, const double FractionEnd) {
//   if(FractionStart>=0.5 || FractionEnd>=0.5) {
//     cerr << "Can't window more than half of the data on either side.\n"
// 	 << "You requested a starting window of " << FractionStart
// 	 << " of the data, and an ending widnow of " << FractionEnd << "." << endl;
//     exit(1);
//   }
//   Window((unsigned int)(floor(FractionStart*Time.size())), (unsigned int)(floor(FractionEnd*Time.size())));
//   return *this;
// }

WaveformAtAPoint & WaveformAtAPoint::PadToPowerOfTwo() {
  const unsigned int N1 = Time.size();
  const unsigned int N2 = (unsigned int)(pow(2.0,ceil(log2(Time.size()))));
  const double dt = (Time[N1-1]-Time[0])/double(N1);
  Time.resize(N2, Time[N1-1]);
  amp[0].resize(N2, 0.0);
  phi[0].resize(N2, 0.0);
  for(unsigned int i=N1; i<N2; ++i) {
    Time[i] += (i-N1+1)*dt;
  }
  return *this;
}

ostream& operator<<(ostream& os, const WaveformAtAPoint& a) {
  os << "# [1] = " << a.TimeScale << endl;
  os << "# [2] = Re{" << Waveform::Types[a.Type] << "}" << endl;
  os << "# [3] = Im{" << Waveform::Types[a.Type] << "}" << endl;
  for(unsigned int i=0; i<a.T().size(); ++i) {
    os << a.T(i) << " " << a.Re(i) << " " << a.Im(i) << endl;
  }
  return os;
}
