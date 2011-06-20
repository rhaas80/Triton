#include "QuasinormalModes.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
  int L=2, M=1, N=7;
  double chi(0.998);
  
  double omegaRe, omegaIm;
  
  QNMFrequencies(L, M, N, chi, omegaRe, omegaIm);
  cout << L << " " << M << " " << N << " " << chi << " " << setprecision(16) << omegaRe << " " << omegaIm << endl;
  
  return 0;
}
