#include "NumericalRecipes.hpp"

#include "WaveformFT.hpp"

#include "NoiseCurves.hpp"
#include "VectorFunctions.hpp"
#include "fft.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::vector;
using std::cerr;
using std::endl;
using std::ios_base;

double BumpFunction(const double x, const double x0, const double x1) {
  if(x<=x0) { return 0.0; }
  if(x>=x1) { return 1.0; }
  const double t = (x-x0)/(x1-x0);
  return 1.0 / (1.0 + exp(1.0/t - 1.0/(1-t)));
}

WaveformFT::WaveformFT()
  : Normalized(false)
{ }

WaveformFT::WaveformFT(const WaveformAtAPoint& W, const unsigned int WindowNCycles,
		       const double DetectorResponseAmp, const double DetectorResponsePhase)
  : WaveformAtAPoint(W), Normalized(false)
{
  // Record that this is happening
  History() << "### WaveformFT(W, " << DetectorResponseAmp << ", " << DetectorResponsePhase << ");" << endl;
  
  // Set up the frequency data
  const double dt = W.T(1)-W.T(0);
  TRef() = TimeToFrequency(W.T());
  
  // Now get the actual data
  vector<double> zero(NTimes(), 0.0);
  vector<double> RealT;
  if(DetectorResponsePhase!=0.0) {
    RealT = W.Re()*(DetectorResponseAmp*cos(DetectorResponsePhase)) - W.Im()*(DetectorResponseAmp*sin(DetectorResponsePhase));
  } else if(DetectorResponseAmp!=1.0) {
    RealT = DetectorResponseAmp*W.Re();
  } else {
    RealT = W.Re();
  }
  
  {
    // Zero up to the first zero crossing for continuity
    unsigned int i=0;
    const double Sign = RealT[0] / abs(RealT[0]);
    while(RealT[i++]*Sign>0) { }
    for(unsigned int j=0; j<i; ++j) {
      RealT[j] = 0.0;
    }
    // Now find the following 2*N zero crossings
    const unsigned int i0 = i;
    const double t0 = W.T(i0);
    for(unsigned int j=0; j<WindowNCycles; ++j) {
      while(RealT[i++]*Sign<0) { }
      while(RealT[i++]*Sign>0) { }
    }
    // And window the data
    const unsigned int i1 = i;
    const double t1 = W.T(i1);
    for(unsigned int j=i0; j<=i1; j++) {
      RealT[j] *= BumpFunction(W.T(j), t0, t1);
    }
  }
  
  // Do the actual work
  fft(RealT, zero, ReRef(), ImRef());
  //// The return from fft needs to be multiplied by N*dt to correspond to the continuum FT
  ReRef() *= NTimes()*dt;
  ImRef() *= NTimes()*dt;
}

WaveformFT& WaveformFT::Normalize(const std::vector<double>& InversePSD) {
  if(Normalized) { return *this; }
  const double snr = SNR(InversePSD);
  ReRef() /= snr;
  ImRef() /= snr;
  Normalized = true;
  return *this;
}

WaveformFT& WaveformFT::ZeroAbove(const double Frequency) {
  for(unsigned int f=0; f<NTimes(); ++f) {
    if(fabs(F(f))>Frequency) { ReRef(f) = 0.0; ImRef(f) = 0.0; }
  }
  return *this;
}

double WaveformFT::InnerProduct(const WaveformFT& B, const std::vector<double>& InversePSD) const {
  if(NTimes() != B.NTimes()) {
    cerr << "\nthis->NTimes()=" << NTimes() << "\tB.NTimes()=" << B.NTimes() << endl;
    throw("Incompatible sizes");
  }
  if(NTimes() != InversePSD.size()) {
    cerr << "\nWaveform size=" << NTimes() << "\tInversePSD.size()=" << InversePSD.size() << endl;
    throw("Incompatible sizes");
  }
  double InnerProduct = 0.0;
  for(unsigned int i=0; i<NTimes(); ++i) {
    InnerProduct += (Re(i)*B.Re(i)+Im(i)*B.Im(i))*InversePSD[i];
  }
  InnerProduct = 2*(F(1)-F(0))*InnerProduct;
  return InnerProduct; // Remember: double-sided frequency
}

double WaveformFT::SNR(const std::vector<double>& InversePSD) const {
  if(NTimes() != InversePSD.size()) {
    cerr << "\nWaveform size=" << NTimes() << "\tInversePSD.size()=" << InversePSD.size() << endl;
    throw("Incompatible sizes");
  }
  double SNRSquared = 0.0;
  for(unsigned int i=0; i<NTimes(); ++i) {
//   cerr << "\nDEBUGGING!!! " << __LINE__ << " " << __FILE__ << endl;
//   for(unsigned int i=NTimes()/2; i<NTimes(); ++i) {
    SNRSquared += (Re(i)*Re(i)+Im(i)*Im(i))*InversePSD[i];
  }
  SNRSquared = 2*(F(1)-F(0))*SNRSquared;
  return sqrt(SNRSquared); // Remember: double-sided frequency
}

double WaveformFT::Match(const WaveformFT& B, const std::vector<double>& InversePSD) const {
//   if(!Normalized || !B.Normalized) {
//     cerr << "\n\nWARNING!!!  Matching non-normalized WaveformFT objects.  WARNING!!!\n" << endl;
//   }
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
  // s1 x s2* = (a1 + i b1) (a2 - i b2) = (a1 a2 + b1 b2) + i(b1 a2 - a1 b2)
  vector<double> re(NTimes(),0.0);
  vector<double> im(NTimes(),0.0);
  for(unsigned int i=NTimes()/2; i<NTimes(); ++i) {
    re[i] = (Re(i)*B.Re(i)+Im(i)*B.Im(i))*InversePSD[i];
    im[i] = (Im(i)*B.Re(i)-Re(i)*B.Im(i))*InversePSD[i];
  }
  vector<double> IFFTRe(NTimes());
  vector<double> IFFTIm(NTimes());
  ifft(re, im, IFFTRe, IFFTIm);
  /// The return from ifft is just the bare FFT sum, so we multiply by df to get
  /// the continuum-analog FT.  This is correct because the input data (re,im) are
  /// the continuum-analog data, rather than just the return from the bare FFT sum.
  /// See, e.g., Eq. (A.33) [rather than Eq. (A.35)] of
  /// http://etd.caltech.edu/etd/available/etd-01122009-143851/
  return 4.0*df*maxmag(IFFTRe, IFFTIm);
  
//   vector<double> re(NTimes()/2), im(NTimes()/2);
//   cerr << "\nDEBUGGING!!! " << __LINE__ << " " << __FILE__ << endl;
//   for(unsigned int i=NTimes()/2; i<NTimes(); ++i) {
//     re[i-NTimes()/2] = (Re(i)*B.Re(i)+Im(i)*B.Im(i))*InversePSD[i];
//     im[i-NTimes()/2] = (Im(i)*B.Re(i)-Re(i)*B.Im(i))*InversePSD[i];
//   }
//   vector<double> IFFTRe(NTimes()/2);
//   vector<double> IFFTIm(NTimes()/2);
}

double WaveformFT::Match(const WaveformFT& B, const std::string& Detector) const {
  return Match(B, NoiseCurve(F(), Detector, true));
}

WaveformFT WaveformFT::operator-(const WaveformFT& b) const {
  WaveformFT c(*this);
  c.ReRef() = Re()-b.Re();
  c.ImRef() = Im()-b.Im();
  return c;
}

WaveformFT WaveformFT::operator*(const double b) const {
  WaveformFT c(*this);
  c.ReRef() *= b;
  c.ImRef() *= b;
  return c;
}

std::ostream& operator<<(std::ostream& os, const WaveformFT& a) {
  os << a.HistoryStr()
     << "# [1] = " << a.TimeScale() << endl
     << "# [2] = Re{F[" << Waveform::Types[a.TypeIndex()] << "(" << a.Vartheta() << "," << a.Varphi() << ")]}" << endl
     << "# [3] = Im{F[" << Waveform::Types[a.TypeIndex()] << "(" << a.Vartheta() << "," << a.Vartheta() << ")]}" << endl;
  for(unsigned int i=0; i<a.NTimes(); ++i) {
    os << a.T(i) << " " << a.Re(i) << " " << a.Im(i) << endl;
  }
  return os;
}
