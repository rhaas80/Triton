#include "NumericalRecipes.hpp"
#include "fft.hpp"
using namespace std;
namespace WU = WaveformUtilities;

int main() {
  const unsigned int N = (1 << 13);
  const double T = 10.0;
  const double dt = T/N;
  const double df = 1.0/(N*dt);
  const double Fs = 1.0/dt;
  const double FNy = Fs/2.0;
  cout << "N=" << N << "\tT=" << T << "\tdt=" << dt << "\tdf=" << df
       << "\tFs=" << Fs << "\tFNy=" << FNy << endl;
  vector<double> t(N,0.0), ReT(N,0.0), ImT(N,0.0), ReFexact(N,0.0), ImFexact(N,0.0);
  const double Amp1 = 1.0;
  const double Freq1 = 1.0;
  const double Amp2 = 10.0;
  const double Freq2 = -201.8;
  const double Amp3 = -1.7;
  const double Freq3 = 124.0;
  const double Amp4 = 2.3;
  const double Freq4 = 14.0;
  for(unsigned int i=0; i<N; ++i) {
    t[i] = i*dt;
    ReT[i] = Amp1*cos(2*M_PI*Freq1*t[i]) + Amp2*cos(2*M_PI*Freq2*t[i]) + Amp3*cos(2*M_PI*Freq3*t[i]);
    ImT[i] = Amp1*sin(2*M_PI*Freq1*t[i]) + Amp2*sin(2*M_PI*Freq2*t[i]) + Amp4*cos(2*M_PI*Freq4*t[i]);
  }
  
  
  /// Output time-domain data
  ofstream ofst("TestFFT.t.dat", ofstream::out);
  ofst << "# [1] = t\n"
       << "# [2] = Re{time}\n"
       << "# [3] = Im{time}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<t.size(); ++i) {
    ofst << t[i] << "\t" << ReT[i] << "\t" << ImT[i] << endl;
  }
  ofst.close();
  
  /// FFT the data
  vector<double> ReF(N, 0.0), ImF(N, 0.0), f(t.size(), 0.0);
  f = WU::TimeToFrequency(t);
  WU::fft(ReT, ImT, ReF, ImF);
  for(unsigned int i=0; i<N; ++i) {
    if(f[i]==Freq1) { ReFexact[i] = Amp1; }
    if(f[i]==Freq2) { ReFexact[i] = Amp2; }
    if(f[i]==Freq3 || f[i]==-Freq3) { ReFexact[i] = Amp3/2.0; }
    if(f[i]==Freq4 || f[i]==-Freq4) { ImFexact[i] = Amp4/2.0; }
  }
  
  /// Output frequency-domain data
  ofstream ofsf("TestFFT.f.dat", ofstream::out);
  ofsf << "# [1] = f\n"
       << "# [2] = Re{freq}\n"
       << "# [3] = Im{freq}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<f.size(); ++i) {
    ofsf << f[i] << "\t" << ReF[i] << "\t" << ImF[i] << endl;
  }
  ofsf.close();
  
  /// FFT the data back
  vector<double> ReFI(N, 0.0), ImFI(N, 0.0);
  WU::ifft(ReF, ImF, ReFI, ImFI);
  
  /// Output time-domain data
  ofstream ofsi("TestFFT.tt.dat", ofstream::out);
  ofsi << "# [1] = t\n"
       << "# [2] = Re{time}\n"
       << "# [3] = Im{time}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<f.size(); ++i) {
    ofsi << t[i] << "\t" << ReFI[i] << "\t" << ImFI[i] << endl;
  }
  ofsi.close();
  
  /// Output errors
  ofstream ofse("TestFFT.e.dat", ofstream::out);
  ofse << "# [1] = t\n"
       << "# [2] = Re{error_f}\n"
       << "# [3] = Im{error_f}\n"
       << "# [4] = Re{error_t}\n"
       << "# [5] = Im{error_t}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<t.size(); ++i) {
    ofse << t[i] << "\t" << ReF[i]-ReFexact[i] << "\t" << ImF[i]-ImFexact[i] << "\t" << ReT[i]-ReFI[i] << "\t" << ImT[i]-ImFI[i] << endl;
  }
  ofse.close();
  
  return 0;
}
