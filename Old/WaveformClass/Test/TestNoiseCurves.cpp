#include "fft.hpp"
#include "NoiseCurves.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main () {
  /// Create the data
  const string DetectorName("AdvLIGO_NSNSOptimal");
  const unsigned int Samples = 8192;
  const double dt = 1.0/Samples;
  const int Seconds = 1;
  vector<double> T(Samples*Seconds, 0.0);
  for(unsigned int i=0; i<T.size(); ++i) {
    T[i] = dt*i;
  }
  vector<double> F = TimeToFrequency(T);
  vector<double> PSD = NoiseCurve(F, DetectorName);
  vector<double> InversePSD = NoiseCurve(F, DetectorName, true);
  
  /// Output the data
  ofstream ofs1(("TestNoiseCurves." + DetectorName + ".dat").c_str(), ofstream::out);
  ofs1 << "# [1] = T\n"
       << "# [2] = F\n"
       << "# [3] = PSD(F)\n"
       << "# [4] = InversePSD(F)\n"
       << setprecision(8) << flush;
  for(unsigned int i=0; i<T.size(); ++i) {
    ofs1 << T[i] << " " << F[i] << " ";
    if(PSD[i]==numeric_limits<double>::infinity()) { ofs1 << 1.0e-200; } else { ofs1 << PSD[i]; }
    ofs1 << " " << InversePSD[i];
    ofs1 << endl;
  }
  ofs1.close();
  
  return 0;
}
