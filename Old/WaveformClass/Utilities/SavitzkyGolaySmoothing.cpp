#include "VectorFunctions.hpp"
#include "SavitzkyGolaySmoothing.hpp"
#include "LUdcmp.hpp"
#include "fft.hpp"
#include <cmath>
using namespace std;

#define throw(message) \
{printf("ERROR: %s\n     in file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}



void savgol(vector<double>& c, const int np, const int nl, const int nr,
	    const int ld, const int m)
{
  int j,k,imj,ipj,kk,mm;
  double fac,sum;
  if (np < nl+nr+1 || nl < 0 || nr < 0 || ld > m || nl+nr < m)
    throw("bad args in savgol");
  vector<vector<double> > a(m+1, vector<double>(m+1));
  vector<double> b(m+1);
  for (ipj=0;ipj<=(m << 1);ipj++) {
    sum=(ipj ? 0.0 : 1.0);
    for (k=1;k<=nr;k++) sum += pow(double(k),double(ipj));
    for (k=1;k<=nl;k++) sum += pow(double(-k),double(ipj));
    mm=min(ipj,2*m-ipj);
    for (imj = -mm;imj<=mm;imj+=2) a[(ipj+imj)/2][(ipj-imj)/2]=sum;
  }
  LUdcmp alud(a);
  for (j=0;j<m+1;j++) b[j]=0.0;
  b[ld]=1.0;
  alud.solve(b,b);
  for (kk=0;kk<np;kk++) c[kk]=0.0;
  for (k = -nl;k<=nr;k++) {
    sum=b[0];
    fac=1.0;
    for (mm=1;mm<=m;mm++) sum += b[mm]*(fac *= k);
    kk=(np-k) % np;
    c[kk]=sum;
  }
}

vector<double> SavitzkyGolaySmoothing(const vector<double>& y, const int NLeft, const int NRight, const int PolyOrder, const int DerivOrder) {
  //// Get the coefficients of the smoothing filter
  vector<double> Coefficients(NLeft+NRight+1);
  savgol(Coefficients, Coefficients.size(), NLeft, NRight, DerivOrder, PolyOrder);
  
  //// Do the smoothing
  if(((y.size()) & (y.size()-1)) == 0) {
    return convlv(y, Coefficients, +1);  // Return if we already have a power of 2
  } else {
    unsigned int N = (unsigned int)(pow(2.0,ceil(log2(y.size()))));
    vector<double> y2 = y;
    y2.resize(N, y[y.size()-1]);
    y2 = convlv(y2, Coefficients, +1);
    y2.resize(y.size());
    return y2;
  }
}
