#include "WaveformFT.hpp"
#include "NoiseCurves.hpp"
#include "VectorFunctions.hpp"
#include "fft.hpp"

#include <iostream>
#include <cmath>

using namespace std;

WaveformFT::WaveformFT()
  : InitialTime(0), Normalized(false)
{ }

WaveformFT::WaveformFT(const WaveformAtAPoint& W, const double DetectorResponseAmp, const double DetectorResponsePhase)
  : InitialTime(W.Time[0]), Normalized(false)
{
  Type = W.Type;
  TimeScale = "f(Hz)";
  LM = vector<vector<int> >(0, vector<int>(0));
  Radius = W.Radius;
  Time = TimeToFrequency(W.Time);
  amp.resize(1, vector<double>(Time.size(), 0.0));
  phi.resize(1, vector<double>(Time.size(), 0.0));
  double Ndt = W.Time[W.Time.size()-1]-W.Time[0];
  vector<double> re(Time.size(), 0.0), im(Time.size(), 0.0);
  fft(W.Re()*(DetectorResponseAmp*cos(DetectorResponsePhase))-W.Im()*(DetectorResponseAmp*sin(DetectorResponsePhase)), vector<double>(Time.size(),0.0), re, im);
  AmpPhi(re, im, amp[0], phi[0]);
  //// The return from fft multiplies by 1/N because NR's ifft is our fft, so we remove that factor
  amp[0] *= Ndt;
}

WaveformFT& WaveformFT::operator=(const WaveformFT& In) {
  this->Waveform::operator=(In);
  InitialTime = In.InitialTime;
  Normalized = In.Normalized;
  return *this;
}

WaveformFT& WaveformFT::Integrate(const unsigned int IntegrateNTimes) {
  amp[0] /= pow(2.0*M_PI*Freq(), int(IntegrateNTimes));
  amp[0][static_cast<int>(floor((static_cast<int>(Time.size())-1.0)/2.0))] = 0.0; // Set the f=0 datum to 0
  phi[0] += -M_PI*IntegrateNTimes/2.0;
  return *this;
}

WaveformFT& WaveformFT::Normalize(const std::vector<double>& InversePSD) {
  if(Freq().size() != InversePSD.size()) {
    cerr << "Waveform size, " << Freq().size() << ", is not compatible with InversePSD size, " << InversePSD.size() << " in 'Normalize'." << endl;
    exit(1);
  }
  const double NormSquared = 2*fabs(Freq(1)-Freq(0))*sum(amp[0]*amp[0]*InversePSD); // Remember: double-sided frequency
  amp *= 1.0/sqrt(NormSquared);
  Normalized = true;
  return *this;
}

double WaveformFT::SNR(const std::vector<double>& InversePSD) const {
  if(Freq().size() != InversePSD.size()) {
    cerr << "Waveform size, " << Freq().size() << ", is not compatible with InversePSD size, " << InversePSD.size() << " in 'SNR'." << endl;
    exit(1);
  }
  return sqrt(2*fabs(Freq(1)-Freq(0))*sum(amp[0]*amp[0]*InversePSD)); // Remember: double-sided frequency
}

double WaveformFT::Match(const WaveformFT& B, const std::vector<double>& InversePSD) const {
  if(!Normalized || !B.Normalized) {
    cerr << "\n\nWARNING!!!  Matching non-normalized WaveformFT objects.  WARNING!!!\n" << endl;
  }
  if(Freq().size() != B.Freq().size() || Freq().size() != InversePSD.size()) {
    cerr << "Waveform sizes, " << Freq().size() << " and " << B.Freq().size() << ", are not compatible with InversePSD size, " << InversePSD.size() << " in Match." << endl;
    exit(1);
  }
  if(Freq(1)-Freq(0) != B.Freq(1)-B.Freq(0)) {
    cerr << "Waveform frequency steps, " << Freq(1)-Freq(0) << " and " << B.Freq(1)-B.Freq(0) << ", are not compatible in Match." << endl;
    exit(1);
  }
  double df = fabs(Freq(1)-Freq(0));
  vector<double> Amp = amp[0]*B.amp[0]*InversePSD;
  vector<double> Phi = phi[0] - B.phi[0];
  vector<double> IFFTRe(Amp.size());
  vector<double> IFFTIm(Amp.size());
  ifft(Amp*cos(Phi), Amp*sin(Phi), IFFTRe, IFFTIm);
  //// The return from ifft is just the bare FFT sum, so we multiply by df to get the continuum-analog FT.
  return 2.0*df*maxmag(IFFTRe, IFFTIm);
}

double WaveformFT::Match(const WaveformFT& B, const std::string& Detector) const {
  if(Freq().size() != B.Freq().size()) {
    cerr << "Waveform sizes, " << Freq().size() << " and " << B.Freq().size() << ", are not compatible." << endl;
    exit(1);
  }
  if(Freq(1)-Freq(0) != B.Freq(1)-B.Freq(0)) {
    cerr << "Waveform frequency steps, " << Freq(1)-Freq(0) << " and " << B.Freq(1)-B.Freq(0) << ", are not compatible." << endl;
    exit(1);
  }
  return (this -> Match(B, NoiseCurve(Freq(), Detector, true)));
}

ostream& operator<<(ostream& os, const WaveformFT& a) {
  os << "# [1] = " << a.TimeScale << endl;
  os << "# [2] = Amp{F[" << Waveform::Types[a.Type] << "]}" << endl;
  os << "# [3] = Arg{F[" << Waveform::Types[a.Type] << "]}" << endl;
  for(unsigned int i=0; i<a.Freq().size(); ++i) {
    os << a.Freq(i) << " " << a.Amp(i) << " " << a.Phi(i) << endl;
  }
  return os;
}
