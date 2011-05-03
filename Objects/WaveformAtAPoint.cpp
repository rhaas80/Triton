#include "NumericalRecipes.hpp"

#include "WaveformAtAPoint.hpp"

#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include "SWSHs.cpp"
#include "Utilities.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::vector;
using std::setprecision;
using std::ios_base;


WaveformAtAPoint::WaveformAtAPoint(const Waveform& W, const double dt, const double Vartheta, const double Varphi)
  : vartheta(Vartheta), varphi(Varphi)
{
  // Record that this is happening
  SetHistory(W.History());
  history.seekp(0, ios_base::end);
  history << "### WaveformAtAPoint(W, " << setprecision(16) << dt << ", " << Vartheta << ", " << Varphi << ");" << endl;
  
  // Make sure to copy over some other data
  TypeIndex() = W.TypeIndex();
  TimeScale() = W.TimeScale();
  
  // Store the vartheta, varphi data instead of l,m data
  LM() = Matrix<int>(1, 2);
  L(0) = vartheta;
  M(0) = varphi;
  
  // Construct a grid with even spacing dt whose size is the next power of 2
  const unsigned int N1 = floor((W.T().back()-W.T(0))/dt);
  const unsigned int N2 = (unsigned int)(pow(2.0,ceil(log2(N1))));
  vector<double> NewTime(N2);
  for(unsigned int i=0; i<N2; ++i) {
    NewTime[i] = W.T(0) + i*dt;
  }
  mag = Matrix<double>(1, N2, 0.0);
  arg = Matrix<double>(1, N2, 0.0);
  
  // Step through the modes interpolating to the new time
  vector<double> SWSHAmp, SWSHPhi, Amplitude, Phase;
  SWSH(W.LM().RawData(), vartheta, varphi, SWSHAmp, SWSHPhi);
//   cout << "\nDebugging at " << __LINE__ << " of " << __FILE__ << endl;
//   cout << "W.LM() = " << W.LM();
//   cout << "SWSHAmp = " << SWSHAmp << endl;
//   cout << "SWSHPhi = " << SWSHPhi << endl;
  for(unsigned int mode=0; mode<W.NModes(); ++mode) { // Loop over components
    Amplitude = SWSHAmp[mode] * WaveformUtilities::Interpolate(W.T(), W.Mag(mode), NewTime, 0.0);
    Phase     = SWSHPhi[mode] + WaveformUtilities::Interpolate(W.T(), W.Arg(mode), NewTime, W.Arg(mode).back());
    Re() += Amplitude * cos(Phase);
    Im() += Amplitude * sin(Phase);
  }
  t = NewTime;
  r = WaveformUtilities::Interpolate(W.T(), W.R(), t);
}

std::ostream& operator<<(std::ostream& os, const WaveformAtAPoint& a) {
  os << a.History()
     << "# [1] = " << a.TimeScale() << endl
     << "# [2] = Re{" << Waveform::Types[a.TypeIndex()] << "(" << a.Vartheta() << "," << a.Varphi() << ")}" << endl
     << "# [3] = Im{" << Waveform::Types[a.TypeIndex()] << "(" << a.Vartheta() << "," << a.Vartheta() << ")}" << endl;
  for(unsigned int i=0; i<a.NTimes(); ++i) {
    os << a.T(i) << " " << a.Re(i) << " " << a.Im(i) << endl;
  }
  return os;
}
