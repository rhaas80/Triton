#include "NumericalRecipes.hpp"
#include "fft.hpp"
namespace WU = WaveformUtilities;
using std::cout;
using std::flush;
using std::endl;
using std::vector;
using std::ofstream;
using std::setprecision;
using std::complex;

inline Complex* Cmplx(VecDoub &d) {return (Complex *)&d[0];}

int main() {
  const unsigned int N = (1 << 14);
  const double T = 10.0;
  const double dt = T/N;
  const double df = 1.0/(N*dt);
  const double Fs = 1.0/dt;
  const double FNy = Fs/2.0;
  cout << "N=" << N << "\tT=" << T << "\tdt=" << dt << "\tdf=" << df
       << "\tFs=" << Fs << "\tFNy=" << FNy << endl;
  vector<double> t(N,0.0);
  WU::WrapVecDoub data(2*N);
  vector<double> data2(2*N, 0.0);
  vector<double> Data(N, 0.0);
  const double Amp1 = 1.0;
  const double Freq1 = 1.0;
  const double Amp2 = 10.0;
  const double Freq2 = 201.8;
  for(unsigned int i=0; i<N; ++i) {
    t[i] = i*dt;
    data.real(i) = Amp1*cos(2*M_PI*Freq1*t[i]) + Amp2*sin(2*M_PI*Freq2*t[i]);
    data.imag(i) = 0.0;
    data2[2*i] = data.real(i);
    Data[i] = data.real(i);
  }

  /// Output time-domain data
  ofstream ofst("TestRealFFT.t.dat", ofstream::out);
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
  WU::dft(data2);
  for(unsigned int i=0; i<N; ++i) {
    if(fabs(f[i]-Freq1)<1e-12 || fabs(f[i]+Freq1)<1e-12) { ReFexact[i] = double(N)*Amp1/2.0; }
    if(fabs(f[i]-Freq2)<1e-12) { ImFexact[i] = double(N)*Amp2/(-2.0); }
    if(fabs(f[i]+Freq2)<1e-12) { ImFexact[i] = double(N)*Amp2/2.0; }
  }

  /// Output frequency-domain data
  ofstream ofsf("TestRealFFT.f.dat", ofstream::out);
  ofsf << "# [1] = f\n"
       << "# [2] = Re{dft}\n"
       << "# [3] = Im{dft}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<N; ++i) {
    ofsf << f[i] << "\t" << data2[2*i] << "\t" << data2[2*i+1] << endl;
    //ofsf << f[i] << "\t" << data.real(i) << "\t" << data.imag(i) << endl;
  }
  ofsf.close();

//   /// Output errors
//   ofstream ofse("TestRealFFT.ef.dat", ofstream::out);
//   ofse << "# [1] = f\n"
//        << "# [2] = Re{error_f}\n"
//        << "# [3] = Im{error_f}\n"
//        << "# [4] = Re{exactdft}\n"
//        << "# [5] = Im{exactdft}\n"
//        << setprecision(12) << flush;
//   for(unsigned int i=0; i<N; ++i) {
//     ofse << f[i] << "\t" << data.real(i)-ReFexact[i] << "\t" << data.imag(i)-ImFexact[i]
//       << "\t" << ReFexact[i] << "\t" << ImFexact[i] << endl;
//   }
//   ofse.close();

//   /// FFT the data back
//   vector<double> ReFI(N, 0.0), ImFI(N, 0.0);
//   WU::idft(data);

//   /// Output time-domain data
//   ofstream ofsi("TestRealFFT.tt.dat", ofstream::out);
//   ofsi << "# [1] = t\n"
//        << "# [2] = Re{time}\n"
//        << "# [3] = Im{time}\n"
//        << setprecision(8) << flush;
//   for(unsigned int i=0; i<N; ++i) {
//     ofsi << t[i] << "\t" << data.real(i)/double(N) << "\t" << data.imag(i)/double(N) << endl;
//   }
//   ofsi.close();

  /// FFT the data's real part
  WU::realdft(Data);

  /// Output time-domain data
  complex<double> c;
  ofstream ofs("TestRealFFT.ref.dat", ofstream::out);
  ofs << "# [1] = t\n"
      << "# [2] = Re{realdft}\n"
      << "# [3] = Im{realdft}\n"
      << setprecision(8) << flush;
  c = Cmplx(Data)[0];
  ofs << f[0] << "\t" << c.real() << "\t" << 0.0 << endl;
  for(unsigned int i=1; i<N/2; ++i) {
    c = Cmplx(Data)[i];
    ofs << f[i] << "\t" << c.real() << "\t" << c.imag() << endl;
  }
  c = Cmplx(Data)[0];
  ofs << -f[N/2] << "\t" << c.imag() << "\t" << 0.0 << endl;
  ofs.close();

  return 0;
}
