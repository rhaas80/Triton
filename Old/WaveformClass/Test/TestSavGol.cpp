#include "SavitzkyGolaySmoothing.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
  unsigned int N = (unsigned int)(pow(2.0, 10));
  vector<double> x(N, 0.0);
  vector<double> y(N, 0.0);
  srand(12);
  const double dx = 0.25*2*M_PI/double(N);
  for(unsigned int i=0; i<N; ++i) {
    x[i] = i*dx;
    y[i] = 0.5-0.5*cos(1.0/pow(x[i]+0.01, 1.1)) + .1*(rand()/double(RAND_MAX)-0.5);
  }
  
  int NLeft = 4, NRight = NLeft, PolyOrder=4, DerivOrder=0;
  vector<double> yS = SavitzkyGolaySmoothing(y, NLeft, NRight, PolyOrder, DerivOrder);
  for(unsigned int i=0; i<N; ++i) {
    cout << x[i] << " " << y[i] << " " << yS[i] << endl;
  }
  return 0;
}
