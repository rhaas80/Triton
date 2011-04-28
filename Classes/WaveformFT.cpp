#include "NumericalRecipes.hpp"

#include "WaveformFT.hpp"

//#include "NoiseCurves.hpp"
#include "VectorFunctions.hpp"
#include "fft.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::vector;
using std::cerr;
using std::endl;

WaveformFT::WaveformFT()
  : Normalized(false)
{ }

WaveformFT::WaveformFT(const WaveformAtAPoint& W, const double DetectorResponseAmp, const double DetectorResponsePhase)
  : WaveformAtAPoint(W), Normalized(false)
{
  // Record that this is happening
  history << "### WaveformFT(W, " << DetectorResponseAmp << ", " << DetectorResponsePhase << ");" << endl;
  
  // Set up the frequency data
  const double dt = W.T(1)-W.T(0);
  T() = TimeToFrequency(W.T());
  
  // Now do the actual work
  vector<double> zero(NTimes(), 0.0);
  vector<double> RealT;
  if(DetectorResponsePhase!=0.0) {
    RealT = W.Re()*(DetectorResponseAmp*cos(DetectorResponsePhase)) - W.Im()*(DetectorResponseAmp*sin(DetectorResponsePhase));
  } else if(DetectorResponseAmp!=1.0) {
    RealT = DetectorResponseAmp*W.Re();
  } else {
    RealT = W.Re();
  }
  fft(RealT, zero, Re(), Im());
  //// The return from fft needs to be multiplied by dt to correspond to the continuum FT
  Re() *= dt;
  Im() *= dt;
}

WaveformFT& WaveformFT::Normalize(const std::vector<double>& InversePSD) {
  if(Normalized) { return *this; }
  const double snr = SNR(InversePSD);
  Re() /= snr;
  Im() /= snr;
  Normalized = true;
  return *this;
}

double WaveformFT::SNR(const std::vector<double>& InversePSD) const {
  if(NTimes() != InversePSD.size()) {
    cerr << "\nWaveform size=" << NTimes() << "\tInversePSD.size()=" << InversePSD.size() << endl;
    throw("Incompatible sizes");
  }
  double SNRSquared = 0.0;
  for(unsigned int i=0; i<NTimes(); ++i) {
    SNRSquared += (Re(i)*Re(i)+Im(i)*Im(i))*InversePSD[i];
  }
  SNRSquared = 2*(F(1)-F(0))*SNRSquared;
  return sqrt(SNRSquared); // Remember: double-sided frequency
}

double WaveformFT::Match(const WaveformFT& B, const std::vector<double>& InversePSD) const {
  if(!Normalized || !B.Normalized) {
    cerr << "\n\nWARNING!!!  Matching non-normalized WaveformFT objects.  WARNING!!!\n" << endl;
  }
  if(NTimes() != B.NTimes() || NTimes() != InversePSD.size()) {
    cerr << "Waveform sizes, " << NTimes() << " and " << B.NTimes()
	 << ", are not compatible with InversePSD size, " << InversePSD.size() << endl;
    throw("Incompatible sizes");
  }
  const double df = F(1)-F(0);
  if(df != B.F(1)-B.F(0)) {
    cerr << "Waveform frequency steps, " << df << " and " << B.F(1)-B.F(0) << ", are not compatible in Match." << endl;
    throw("Incompatible resolutions");
  }
  vector<double> re = (Re()*B.Re()-Im()*B.Im())*InversePSD;
  vector<double> im = (Re()*B.Im()+Im()*B.Re())*InversePSD;
  vector<double> IFFTRe(NTimes());
  vector<double> IFFTIm(NTimes());
  ifft(re, im, IFFTRe, IFFTIm);
  //// The return from ifft is just the bare FFT sum, so we multiply by df to get the continuum-analog FT.
  return 2.0*df*maxmag(IFFTRe, IFFTIm);
}

// double WaveformFT::Match(const WaveformFT& B, const std::string& Detector) const {
//   return Match(B, NoiseCurve(F(), Detector, true));
// }

std::ostream& operator<<(std::ostream& os, const WaveformFT& a) {
  os << "# [1] = " << a.TimeScale() << endl;
  os << "# [2] = Re{F[" << Waveform::Types[a.TypeIndex()] << "(" << a.Vartheta() << "," << a.Varphi() << ")]}" << endl;
  os << "# [3] = Im{F[" << Waveform::Types[a.TypeIndex()] << "(" << a.Vartheta() << "," << a.Vartheta() << ")]}" << endl;
  for(unsigned int i=0; i<a.NTimes(); ++i) {
    os << a.T(i) << " " << a.Re(i) << " " << a.Im(i) << endl;
  }
  return os;
}
