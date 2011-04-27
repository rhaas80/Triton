#include "NumericalRecipes.hpp"
#include "Fit.hpp"
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

class GaussianBasisFunctions {
private: // empty private data
public:
  GaussianBasisFunctions() { }
  void operator()(const Doub x, VecDoub_I &a, Doub &y, VecDoub_O &dyda) const {
    Int i,na=a.size();
    Doub fac,ex,arg;
    y=0.;
    for (i=0;i<na-1;i+=3) {
      arg=(x-a[i+1])/a[i+2];
      ex=exp(-SQR(arg));
      fac=a[i]*ex*2.*arg;
      y += a[i]*ex;
      dyda[i]=ex;
      dyda[i+1]=fac/a[i+2];
      dyda[i+2]=fac*arg/a[i+2];
    }
  }
  Doub operator()(VecDoub_I& a, Doub x) const {
    int na=a.size();
    double y=0., fac=0., ex=0., arg=0.;
    for (int i=0;i<na-1;i+=3) {
      arg=(x-a[i+1])/a[i+2];
      ex=exp(-SQR(arg));
      fac=a[i]*ex*2.*arg;
      y += a[i]*ex;
    }
    return y;
  }
};

vector<double> aa(3);

double gaussiansexample(const double x) {
  double y;
  GaussianBasisFunctions g;
  y = g(aa, x);
  return y;
}

int main () {
  aa[0] = 1.623245187905471417189;
  aa[1] = 3.9;
  aa[2] = 4.864789743913981430541;
  
  {
    const int npts=20;
    const int k=3*1;
    vector<double> xx(npts),yy(npts),ssig(npts), aaguess(k);
    for(unsigned int i=0; i<npts; ++i) {
      xx[i] = 0.1*i;
      yy[i] = gaussiansexample(xx[i]);
      ssig[i] = 1.0;
    }
    aaguess[0] = 1.0;
    aaguess[1] = 2.1;
    aaguess[2] = 4.8;
    GaussianBasisFunctions g;
    WU::FitNonlinear<GaussianBasisFunctions> myfit(xx,yy,ssig,aaguess,g, 1.e-10);
    myfit.fit();
    cout << setprecision(15) << myfit.a << endl;
    cout << "Errors in parameters: " << setprecision(5) << aa-myfit.a << endl;
  }
  
  return 0;
}
