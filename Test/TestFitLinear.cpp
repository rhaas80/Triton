#include "NumericalRecipes.hpp"
#include "SingularValueDecomposition.hpp"
#include "Fit.hpp"
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

double cubicexample(const double x) {
  return 0.14 + 3.89*x + 7.12*x*x + 0.93*x*x*x;
}

int main() {
  
  {
    const int npts=20;
    vector<double> xx(npts),yy(npts),ssig(npts);
    for(unsigned int i=0; i<npts; ++i) {
      xx[i] = 0.1*i;
      yy[i] = cubicexample(xx[i]);
      ssig[i] = 1.0;
    }
    WU::PolynomialBasisFunctions p(3);
    WU::Fit<WU::PolynomialBasisFunctions> myfit(xx,yy,ssig,p);
    myfit.fit();
    cout << myfit.a << endl;
  }
  
  {
    const int npts=20;
    vector<double> xx(npts),yy(npts),ssig(npts);
    for(unsigned int i=0; i<npts; ++i) {
      xx[i] = 0.1*i;
      yy[i] = cubicexample(xx[i]);
      ssig[i] = 1.0;
    }
    WU::PolynomialBasisFunctions p(3);
    WU::FitSVD<WU::PolynomialBasisFunctions> myfit(xx,yy,ssig,p);
    myfit.fit();
    cout << myfit.a << endl;
  }
  
  return 0;
}
