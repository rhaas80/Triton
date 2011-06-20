#ifndef ROOTS_HPP
#define ROOTS_HPP

#include <vector>
#include <cmath>

double abs(const double a) { return fabs(a); }

template <class T>
void zbrak(T &fx, const double x1, const double x2, const unsigned int n, std::vector<double>& xb1,
	   std::vector<double>& xb2, unsigned int& nroot)
{
  unsigned int nb=20;
  xb1.resize(nb);
  xb2.resize(nb);
  nroot=0;
  double dx=(x2-x1)/n;
  double x=x1;
  double fp=fx(x1);
  for (unsigned int i=0;i<n;i++) {
    double fc=fx(x += dx);
    if (fc*fp <= 0.0) {
      xb1[nroot]=x-dx;
      xb2[nroot++]=x;
      if(nroot == nb) {
	std::vector<double> tempvec1(xb1),tempvec2(xb2);
	xb1.resize(2*nb);
	xb2.resize(2*nb);
	for (unsigned int j=0; j<nb; j++) {
	  xb1[j]=tempvec1[j];
	  xb2[j]=tempvec2[j];
	}
	nb *= 2;
      }
    }
    fp=fc;
  }
}

template <class T>
double rtbis(T &func, const double x1, const double x2, const double xacc) {
  const int JMAX=75;
  double dx,xmid,rtb;
  double f=func(x1);
  double fmid=func(x2);
  if (f*fmid >= 0.0) throw("Root must be bracketed for bisection in rtbis");
  rtb = f < 0.0 ? (dx=x2-x1,x1) : (dx=x1-x2,x2);
  for (int j=0;j<JMAX;j++) {
    fmid=func(xmid=rtb+(dx *= 0.5));
    if (fmid <= 0.0) rtb=xmid;
    if (abs(dx) < xacc || fmid == 0.0) { return rtb; }
  }
  throw("Too many bisections in rtbis");
}

#endif // ROOTS_HPP
