#include "Fit.hpp"
#include "VectorFunctions.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;


void fgauss(const double x, const vector<double> &a, double &y, vector<double> &dyda) {
  int i,na=a.size();
  double fac,ex,arg;
  y=0.;
  for (i=0;i<na-1;i+=3) {
    arg=(x-a[i+1])/a[i+2];
    ex=exp(-(arg*arg));
    fac=a[i]*ex*2.*arg;
    y += a[i]*ex;
    dyda[i]=ex;
    dyda[i+1]=fac/a[i+2];
    dyda[i+2]=fac*arg/a[i+2];
  }
}

vector<double> cubicfit(const double x) {
  vector<double> ans(4);
  ans[0] = 1.;
  for (int i=1;i<4;i++) ans[i] = x*ans[i-1];
  return ans;
}

double cubicexample(const double x) {
  return 0.14 + 3.89*x + 7.12*x*x + 0.93*x*x*x;
}

double gaussiansexample(const double x) {
  vector<double> aa(3);
  aa[0] = 1.623245;
  aa[1] = 3.9;
  aa[2] = 4.8647;
  double y;
  vector<double> dyda(aa.size());
  fgauss(x, aa, y, dyda);
  return y;
}

int main () {
  {
    const int npts=20;
    vector<double> xx(npts),yy(npts),ssig(npts);
    for(unsigned int i=0; i<npts; ++i) {
      xx[i] = 0.1*i;
      yy[i] = cubicexample(xx[i]);
      ssig[i] = 1.0;
    }
    Fit myfit(xx,yy,ssig,cubicfit);
    myfit.fit();
    cout << myfit.a << endl;
  }
  {
    const int npts=20;
    const int k=3*1;
    vector<double> xx(npts),yy(npts),ssig(npts), aa(k);
    for(unsigned int i=0; i<npts; ++i) {
      xx[i] = 0.1*i;
      yy[i] = gaussiansexample(xx[i]);
      ssig[i] = 1.0;
    }
    aa[0] = 1.0;
    aa[1] = 2.1;
    aa[2] = 4.8;
    FitNonlinear myfit(xx,yy,ssig,aa,fgauss);
    myfit.fit();
    cout << myfit.a << endl;
  }
  
  return 0;
}
