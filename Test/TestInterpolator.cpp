#include <fstream>
#include "NumericalRecipes.hpp"
#include "SingularValueDecomposition.hpp"
#include "Interpolate.hpp"
#include "VectorFunctions.hpp"
#include "EasyParser.hpp"
using namespace std;
namespace WU = WaveformUtilities;

inline double f(const double x) {
  return sin(2*M_PI*x)+cos(17*M_E*x)*sqrt(2);
}

int main() {

  const unsigned int log2N = 17;
  const unsigned int N = (1 << log2N);
  const double XMin = -1.0;
  const double XMax = 1.0;
  const double dX = (XMax-XMin)/(N-1.0);
  vector<double> X(N);
  vector<double> Y(N);
  for(unsigned int i=0; i<N; ++i) {
    X[i] = XMin + dX*i;
    Y[i] = f(X[i]);
  }

  for(unsigned int log2n=5; log2n<log2N; log2n++) {
    const unsigned int n = (1 << log2n);
    const double dx = (XMax-XMin)/(n-1.0);
    vector<double> x(n);
    vector<double> y(n);
    for(unsigned int i=0; i<n; ++i) {
      x[i] = XMin + dx*i;
      y[i] = f(x[i]);
    }
    vector<double> YInterp = WU::Interpolate(x, y, X);
    ofstream ofs(("TestInterpolator_n" + WU::DoubleToString(n, 6) + ".dat").c_str(), ios::out);
    ofs << "# [1] = X\n"
        << "# [2] = Y\n"
        << "# [3] = error" << endl;
    for(unsigned int i=0; i<N; ++i) {
      ofs << X[i] << " " << Y[i] << " " << YInterp[i]-Y[i] << endl;
    }
    ofs.close();
  }

  return 0;
}
