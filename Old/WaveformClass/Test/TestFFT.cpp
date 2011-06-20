#include "fft.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main () {
  /// Create the random data + sinusoids
  srand(13);
  const unsigned int N = pow(2.0,12.0);
  const double T = 10.0;
  const double dt = T/N;
  const double df = 1.0/(N*dt);
  const double Fs = 1.0/dt;
  const double FNy = Fs/2.0;
  cout << "N=" << N << "\tT=" << T << "\tdt=" << dt << "\tdf=" << df
       << "\tFs=" << Fs << "\tFNy=" << FNy << endl;
  vector<double> t(N,0.0), ReT(N,0.0), ImT(N,0.0);
  const double Amp1 = 1.0;
  const double Freq1 = 1.0;
  const double Amp2 = 0.0;
  const double Freq2 = -204.8;
  for(unsigned int i=0; i<N; ++i) {
    t[i] = i*dt;
//     ReT[i] = Amp*sin(2*M_PI*Freq*t[i]);
//     ImT[i] = 0.0;
    ReT[i] = Amp1*cos(2*M_PI*Freq1*t[i]) + Amp2*cos(2*M_PI*Freq2*t[i]);
    ImT[i] = Amp1*sin(2*M_PI*Freq1*t[i]) + Amp2*sin(2*M_PI*Freq2*t[i]);
    // + 0*8*(double(rand())/double(RAND_MAX) - 0.5)
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
  f = TimeToFrequency(t);
  fft(ReT, ImT, ReF, ImF);
  
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
  
  /// Test vector-half swapping
  vector<double> fTest=f;
  SwapVectorHalvesToNumRecForm(fTest);
  ofstream ofsTest("TestFFT.fSwap.dat", ofstream::out);
  ofsTest << "# [1] = f\n"
	  << "# [2] = fSwapped\n"
	  << setprecision(8) << flush;
  for(unsigned int i=0; i<f.size(); ++i) {
    ofsTest << f[i] << "\t" << fTest[i] << endl;
  }
  ofsTest.close();
  
  /// FFT the data
  vector<double> ReFI(N, 0.0), ImFI(N, 0.0);
  ifft(ReF, ImF, ReFI, ImFI);
  
  /// Output frequency-domain data
  ofstream ofsi("TestFFT.i.dat", ofstream::out);
  ofsi << "# [1] = t\n"
       << "# [2] = Re{t}\n"
       << "# [3] = Im{t}\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<f.size(); ++i) {
    ofsi << t[i] << "\t" << ReFI[i] << "\t" << ImFI[i] << endl;
  }
  ofsi.close();
  
  return 0;
}
