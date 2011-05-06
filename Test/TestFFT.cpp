#include "NumericalRecipes.hpp"
#include "fft.hpp"
namespace WU = WaveformUtilities;
using std::cout;
using std::flush;
using std::endl;
using std::vector;
using std::ofstream;
using std::setprecision;

int main() {
  const unsigned int N = (1 << 13);
  const double T = 10.0;
  const double dt = T/N;
  const double df = 1.0/(N*dt);
  const double Fs = 1.0/dt;
  const double FNy = Fs/2.0;
  cout << "N=" << N << "\tT=" << T << "\tdt=" << dt << "\tdf=" << df
       << "\tFs=" << Fs << "\tFNy=" << FNy << endl;
  vector<double> t(N,0.0);
  WU::WrapVecDoub data(2*N);
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
    data.real(i) = Amp1*cos(2*M_PI*Freq1*t[i]) + Amp2*sin(2*M_PI*Freq2*t[i]) + Amp3*cos(2*M_PI*Freq3*t[i]);
    data.imag(i) = Amp1*sin(2*M_PI*Freq1*t[i]) + Amp2*cos(2*M_PI*Freq2*t[i]) + Amp4*cos(2*M_PI*Freq4*t[i]);
  }
  
  /// Output time-domain data
  ofstream ofst("TestFFT.t.dat", ofstream::out);
  ofst << "# [1] = t\n"
       << "# [2] = Re{time}\n"
       << "# [3] = Im{time}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<N; ++i) {
    ofst << t[i] << "\t" << data.real(i) << "\t" << data.imag(i) << endl;
  }
  ofst.close();
  
  /// FFT the data
  vector<double> ReFexact(N, 0.0), ImFexact(N, 0.0), f(N, 0.0);
  f = WU::TimeToFrequency(t);
  WU::dft(data);
  for(unsigned int i=0; i<N; ++i) {
    if(f[i]==Freq1) { ReFexact[i] = N*Amp1; }
    if(f[i]==-Freq2) { ImFexact[i] = N*Amp2; }
    if(f[i]==Freq3 || f[i]==-Freq3) { ReFexact[i] = N*Amp3/2.0; }
    if(f[i]==Freq4 || f[i]==-Freq4) { ImFexact[i] = N*Amp4/2.0; }
  }
  
  /// Output frequency-domain data
  ofstream ofsf("TestFFT.f.dat", ofstream::out);
  ofsf << "# [1] = f\n"
       << "# [2] = Re{dft}\n"
       << "# [3] = Im{dft}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<N; ++i) {
    ofsf << f[i] << "\t" << data.real(i) << "\t" << data.imag(i) << endl;
  }
  ofsf.close();
  
  /// Output errors
  ofstream ofse("TestFFT.ef.dat", ofstream::out);
  ofse << "# [1] = f\n"
       << "# [2] = Re{error_f}\n"
       << "# [3] = Im{error_f}\n"
//        << "# [4] = Re{error_t}\n"
//        << "# [5] = Im{error_t}\n"
       << setprecision(12) << flush;
  for(unsigned int i=0; i<N; ++i) {
    ofse << f[i] << "\t" << data.real(i)-ReFexact[i] << "\t" << data.imag(i)-ImFexact[i] << endl; // "\t" << ReT[i]-ReFI[i] << "\t" << ImT[i]-ImFI[i] << endl;
  }
  ofse.close();
  
  /// FFT the data back
  vector<double> ReFI(N, 0.0), ImFI(N, 0.0);
  WU::idft(data);
  
  /// Output time-domain data
  ofstream ofsi("TestFFT.tt.dat", ofstream::out);
  ofsi << "# [1] = t\n"
       << "# [2] = Re{time}\n"
       << "# [3] = Im{time}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<N; ++i) {
    ofsi << t[i] << "\t" << data.real(i) << "\t" << data.imag(i) << endl;
  }
  ofsi.close();
  
  return 0;
}
