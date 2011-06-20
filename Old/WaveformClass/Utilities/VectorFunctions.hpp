#ifndef VECTORFUNCTIONS_HPP
#define VECTORFUNCTIONS_HPP

#include <complex>
#include <iostream>
#include <vector>

#ifndef EulerGamma
#define EulerGamma 0.5772156649015328606065120900824024
#endif // EulerGamma


// IO
std::ostream& operator<<(std::ostream& out, const std::vector<double>& v);
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v);


// Arithmetic
std::vector<double> operator+(const std::vector<double>& a, const double& b);
std::vector<double> operator-(const std::vector<double>& a, const double& b);
std::vector<double> operator*(const std::vector<double>& a, const double& b);
std::vector<double> operator/(const std::vector<double>& a, const double& b);
std::vector<double> operator+(const double& a, const std::vector<double>& b);
std::vector<double> operator-(const double& a, const std::vector<double>& b);
std::vector<double> operator*(const double& a, const std::vector<double>& b);
std::vector<double> operator/(const double& a, const std::vector<double>& b);
std::vector<std::vector<double> > operator+(const std::vector<std::vector<double> >& a, const double& b);
std::vector<std::vector<double> > operator-(const std::vector<std::vector<double> >& a, const double& b);
std::vector<std::vector<double> > operator*(const std::vector<std::vector<double> >& a, const double& b);
std::vector<std::vector<double> > operator/(const std::vector<std::vector<double> >& a, const double& b);
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator*(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator/(const std::vector<double>& a, const std::vector<double>& b);
std::vector<std::vector<double> > operator+(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b);
std::vector<std::vector<double> > operator-(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b);
std::vector<std::vector<double> > operator*(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b);
std::vector<std::vector<double> > operator/(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b);
std::vector<std::vector<double> >& operator+=(std::vector<std::vector<double> >& a, const double b);
std::vector<std::vector<double> >& operator-=(std::vector<std::vector<double> >& a, const double b);
std::vector<std::vector<double> >& operator*=(std::vector<std::vector<double> >& a, const double b);
std::vector<std::vector<double> >& operator/=(std::vector<std::vector<double> >& a, const double b);
std::vector<double>& operator+=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator-=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator*=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator/=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator+=(std::vector<double>& a, const double b);
std::vector<double>& operator-=(std::vector<double>& a, const double b);
std::vector<double>& operator*=(std::vector<double>& a, const double b);
std::vector<double>& operator/=(std::vector<double>& a, const double b);
std::vector<double>& operator-(std::vector<double>& a);
std::vector<std::complex<double> > operator-(const std::vector<std::complex<double> >& a, const double& b);

// Higher-level functions
std::vector<double> sqrt(const std::vector<double>& a);
std::vector<double> exp(const std::vector<double>& a);
std::vector<double> log(const std::vector<double>& a);
std::vector<double> log10(const std::vector<double>& a);
std::vector<double> sin(const std::vector<double>& a);
std::vector<double> cos(const std::vector<double>& a);
std::vector<double> fabs(const std::vector<double>& a);
std::vector<std::vector<double> > sin(const std::vector<std::vector<double> >& a);
std::vector<std::vector<double> > cos(const std::vector<std::vector<double> >& a);
std::vector<std::vector<double> > fabs(const std::vector<std::vector<double> >& a);
double maxfabs(const std::vector<double>& a);
double maxmag(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> pow(const std::vector<double>& a, const double& b);
std::vector<double> pow(const double& a, const std::vector<double>& b);
std::vector<double> pow(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> fmod(const std::vector<double>& a, const double& b);
std::vector<std::vector<double> > fmod(const std::vector<std::vector<double> >& a, const double& b);
std::vector<double> atan2(const std::vector<double>& a, const std::vector<double>& b);
std::vector<std::complex<double> > exp(const std::vector<std::complex<double> >& a);

// Integral and derivative
std::vector<double> diff(const std::vector<double>& In);
double sum(const std::vector<double>& In);
double avg(const std::vector<double>& In);
double trapz(const std::vector<double>& t, const std::vector<double>& f);
std::vector<double> cumtrapz(const std::vector<double>& t, const std::vector<double>& f);
std::vector<double> dydx(const std::vector<double>& y, const std::vector<double>& x);
void dydxSmooth(std::vector<double>& y, std::vector<double>& x, const int NLeft=16, const int NRight=16, const int PolyOrder=4, const int DerivOrder=1);

// Common-time functions
std::vector<double> Intersection(const std::vector<double>& t1, const std::vector<double>& t2, const double& MinStep=0.0, const double& MinTime=0.0);
std::vector<double> Intersection(const std::vector<std::vector<double> >& Times, const double& MinStep=0.0, const double& MinTime=0.0);
std::vector<double> Union(const std::vector<double>& t1, const std::vector<double>& t2, const double& MinStep=0.0);

// Phase-conversion functions
std::vector<double> Unwrap(const std::vector<double>& a);
void AmpPhi(const std::vector<double>& Re, const std::vector<double>& Im,
	    std::vector<double>& amp, std::vector<double>& phi);
void ReIm(const std::vector<std::vector<double> >& amp, const std::vector<std::vector<double> >& phi,
	  std::vector<std::vector<double> >& Re, std::vector<std::vector<double> >& Im);

// max functions
inline int max(const std::vector<int>& a) {
  int b=a[0];
  for(unsigned int i=1; i<a.size(); ++i) { b = (b<a[i] ? a[i] : b); }
  return b;
}

inline double max(const std::vector<double>& a) {
  double b=a[0];
  for(unsigned int i=1; i<a.size(); ++i) { b = (b<a[i] ? a[i] : b); }
  return b;
}

inline unsigned int maxIndex(const std::vector<double>& a) {
  double max=a[0];
  unsigned int Index=0;
  for(unsigned int i=1; i<a.size(); ++i) {
    if(a[i]>max) {
      max = a[i];
      Index = i;
    }
  }
  return Index;
}

inline double max(const double a, const double b) {
  return (a>b ? a : b);
}

inline int min(const std::vector<int>& a) {
  int b=a[0];
  for(unsigned int i=1; i<a.size(); ++i) { b = (b>a[i] ? a[i] : b); }
  return b;
}

inline double min(const std::vector<double>& a) {
  double b=a[0];
  for(unsigned int i=1; i<a.size(); ++i) { b = (b>a[i] ? a[i] : b); }
  return b;
}

inline double min(const double a, const double b) {
  return (a>b ? b : a);
}

// miscellanea
inline double sign(const double& a, const double& b) {
  return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a);
}

inline void swap(double& a, double& b) {
  double dum=a; a=b; b=dum;
}

double Fac(const int n);
double DoubleFac(const int n);
double LogFac(const double& x);
double LogGamma(const double& x);
std::complex<double> LogGamma(const std::complex<double>& x);
std::vector<std::complex<double> > LogGamma(const std::vector<std::complex<double> >& x);


#endif // VECTORFUNCTIONS_HPP
