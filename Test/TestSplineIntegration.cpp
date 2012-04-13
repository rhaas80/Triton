#include <iostream>
#include <iomanip>
#include <cmath>
#include "Interpolate.hpp"
#include "Utilities.hpp"

using namespace std;
using WaveformUtilities::SplineInterpolator;
using WaveformUtilities::SplineIntegrator;

int main() {
  cout << setprecision(15);
  unsigned int N = 50;
  double x0=0.0, x1=10.0;
  vector<double> x(N);
  vector<double> y(N);
  vector<double> i(N);
  vector<double> I(N);
  
  for(unsigned int j=0; j<N; ++j) {
    x[j] = x0 + j*(x1-x0)/double(N);
    y[j] = sin(x[j]);
  }
  
  SplineInterpolator s(x, y);
  SplineIntegrator S(x, y);
  I = S();
  
  // cout << "# [1] = x\n"
  //      << "# [2] = y\n"
  //      << "# [3] = SplineInterpolator\n"
  //      << "# [4] = SplineIntegrator\n"
  //      << "# [5] = SplineIntegratorConstants\n"
  //      << "# [6] = AnalyticIntegral\n";
  
  // for(unsigned int j=0; j<N; ++j) {
  //   i[j] = s.interp(x[j]);
  //   I[j] = S(x[j]);
  //   cout << x[j] << " " << y[j] << " " << i[j] << " " << S(x[j]) << " " << I[j] << " " << 1-cos(x[j]) << endl;
  // }
  
  cout << "# [1] = x\n"
       << "# [2] = Error\n";
  
  // for(unsigned int j=0; j<N; ++j) {
  //   cout << x[j] << " " << I[j] - (1-cos(x[j])) << endl;
  // }
  for(unsigned int j=1; j<N; ++j) {
    const double xval = (x[j]+x[j-1])/2.;
    cout << xval << " " << S(xval) - (1-cos(xval)) << endl;
  }
  
  return 0;
}
