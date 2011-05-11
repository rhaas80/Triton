#ifndef VECTORFUNCTIONS_HPP
#define VECTORFUNCTIONS_HPP

#include <iostream>
#include <complex>
#include <vector>
#include "Matrix.hpp"

/// IO operators for vectors and matrices
std::ostream& operator<<(std::ostream& out, const std::vector<double>& v);
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v);
std::ostream& operator<<(std::ostream& out, const WaveformUtilities::Matrix<double>& v);
std::ostream& operator<<(std::ostream& out, const WaveformUtilities::Matrix<int>& v);

/// Arithmetic operators on vectors and matrices
std::vector<double> operator+(const std::vector<double>& a, const double& b);
std::vector<double> operator-(const std::vector<double>& a, const double& b);
std::vector<double> operator*(const std::vector<double>& a, const double& b);
std::vector<double> operator/(const std::vector<double>& a, const double& b);
std::vector<double> operator+(const double& a, const std::vector<double>& b);
std::vector<double> operator-(const double& a, const std::vector<double>& b);
std::vector<double> operator*(const double& a, const std::vector<double>& b);
std::vector<double> operator/(const double& a, const std::vector<double>& b);
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator*(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator/(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator+=(std::vector<double>& a, const double& b);
std::vector<double>& operator-=(std::vector<double>& a, const double& b);
std::vector<double>& operator*=(std::vector<double>& a, const double& b);
std::vector<double>& operator/=(std::vector<double>& a, const double& b);
std::vector<double>& operator+=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator-=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator*=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double>& operator/=(std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator-(const std::vector<double>& a);
WaveformUtilities::Matrix<double> operator+(const WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double> operator-(const WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double> operator*(const WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double> operator/(const WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double> operator+(const double& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator-(const double& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator*(const double& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator/(const double& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator+(const WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator-(const WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator*(const WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator/(const WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double>& operator+=(WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double>& operator-=(WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double>& operator*=(WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double>& operator/=(WaveformUtilities::Matrix<double>& a, const double& b);
WaveformUtilities::Matrix<double>& operator+=(WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double>& operator-=(WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double>& operator*=(WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double>& operator/=(WaveformUtilities::Matrix<double>& a, const WaveformUtilities::Matrix<double>& b);
WaveformUtilities::Matrix<double> operator-(const WaveformUtilities::Matrix<double>& a);

/// cmath functions (other than frexp, ldexp, and modf)
///   Note that if more than one template argument is given,
///   they are assumed to have the same dimensions.
std::vector<double> cos(const std::vector<double>& theta);
std::vector<double> sin(const std::vector<double>& theta);
std::vector<double> tan(const std::vector<double>& theta);
std::vector<double> acos(const std::vector<double>& y);
std::vector<double> asin(const std::vector<double>& y);
std::vector<double> atan(const std::vector<double>& y);
std::vector<double> atan2(const std::vector<double>& Im, const std::vector<double>& Re);
std::vector<double> cosh(const std::vector<double>& theta);
std::vector<double> sinh(const std::vector<double>& theta);
std::vector<double> tanh(const std::vector<double>& theta);
std::vector<double> exp(const std::vector<double>& x);
std::vector<double> log(const std::vector<double>& x);
std::vector<double> log10(const std::vector<double>& x);
std::vector<double> pow(const std::vector<double>& base, const std::vector<double>& exponent);
std::vector<double> pow(const std::vector<double>& base, const double& exponent);
std::vector<double> sqrt(const std::vector<double>& x);
std::vector<double> ceil(const std::vector<double>& x);
std::vector<double> fabs(const std::vector<double>& x);
std::vector<double> floor(const std::vector<double>& x);
std::vector<double> fmod(const std::vector<double>& numerator, const std::vector<double>& denominator);
std::vector<double> fmod(const std::vector<double>& numerator, const double& denominator);
WaveformUtilities::Matrix<double> cos(const WaveformUtilities::Matrix<double>& theta);
WaveformUtilities::Matrix<double> sin(const WaveformUtilities::Matrix<double>& theta);
WaveformUtilities::Matrix<double> tan(const WaveformUtilities::Matrix<double>& theta);
WaveformUtilities::Matrix<double> acos(const WaveformUtilities::Matrix<double>& y);
WaveformUtilities::Matrix<double> asin(const WaveformUtilities::Matrix<double>& y);
WaveformUtilities::Matrix<double> atan(const WaveformUtilities::Matrix<double>& y);
WaveformUtilities::Matrix<double> atan2(const WaveformUtilities::Matrix<double>& Im, const WaveformUtilities::Matrix<double>& Re);
WaveformUtilities::Matrix<double> cosh(const WaveformUtilities::Matrix<double>& theta);
WaveformUtilities::Matrix<double> sinh(const WaveformUtilities::Matrix<double>& theta);
WaveformUtilities::Matrix<double> tanh(const WaveformUtilities::Matrix<double>& theta);
WaveformUtilities::Matrix<double> exp(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> log(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> log10(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> pow(const WaveformUtilities::Matrix<double>& base, const WaveformUtilities::Matrix<double>& exponent);
WaveformUtilities::Matrix<double> pow(const WaveformUtilities::Matrix<double>& base, const double& exponent);
WaveformUtilities::Matrix<double> sqrt(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> ceil(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> fabs(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> floor(const WaveformUtilities::Matrix<double>& x);
WaveformUtilities::Matrix<double> fmod(const WaveformUtilities::Matrix<double>& numerator, const WaveformUtilities::Matrix<double>& denominator);
WaveformUtilities::Matrix<double> fmod(const WaveformUtilities::Matrix<double>& numerator, const double& denominator);

namespace WaveformUtilities {
  
  /// Max functions
  double maxfabs(const std::vector<double>& x);
  double maxmag(const std::vector<double>& Re, const std::vector<double>& Im);
  double maxfabs(const WaveformUtilities::Matrix<double>& x);
  double maxmag(const WaveformUtilities::Matrix<double>& Re, const WaveformUtilities::Matrix<double>& Im);
  unsigned int maxIndex(const std::vector<double>& a);
  unsigned int maxIndex(const WaveformUtilities::Matrix<double>& a);
  
  /// Integral, derivative, etc.
  std::vector<double> diff(const std::vector<double>& In);
  double sum(const std::vector<double>& In);
  double max(const std::vector<double>& In);
  double min(const std::vector<double>& In);
  double avg(const std::vector<double>& In);
  double trapz(const std::vector<double>& t, const std::vector<double>& f);
  std::vector<double> cumtrapz(const std::vector<double>& t, const std::vector<double>& f);
  std::vector<double> dydx(const std::vector<double>& y, const std::vector<double>& x);
  
  /// Common-time functions
  /// The input to each of these functions must be strictly monotonic.
  /// 
  /// This function returns the intersection of two time sequences, 
  ///   where the time step at each point is the minimum of the 
  ///   time steps in t1 and t2 at that instant, or MinStep, 
  ///   whichever is greater.  The output starts at the earliest
  ///   moment common to t1 and t2, or MinTime, whichever is greater.
  std::vector<double> Intersection(const std::vector<double>& t1, const std::vector<double>& t2, const double MinStep, const double MinTime);
  /// This function simply iterates the above procedure, for a
  ///   collection of time sequences.  This is used, for example,
  ///   in the 'Extrapolate' routine.
  std::vector<double> Intersection(const std::vector<std::vector<double> >& Times, const double MinStep, const double MinTime);
  /// This function returns the union of two time sequences,
  ///   similar to the 'Intersection' function above.
  ///   This is used when hybridizing Waveform objects.
  std::vector<double> Union(const std::vector<double>& t1, const std::vector<double>& t2, const double MinStep);
  
  /// Phase-conversion functions
  std::vector<double> Unwrap(const std::vector<double>& a);
  void MagArg(const std::vector<double>& Re, const std::vector<double>& Im,
	      std::vector<double>& mag, std::vector<double>& arg);
  void ReIm(const std::vector<std::vector<double> >& mag, const std::vector<std::vector<double> >& arg,
	    std::vector<std::vector<double> >& Re, std::vector<std::vector<double> >& Im);
  
  /// Factorial and Gamma functions
  double Factorial(const int n);
  double DoubleFactorial(const int n);
  double LogFactorial(const int x);
  double LogGammaFunction(const double x);
  std::complex<double> LogGammaFunction(const std::complex<double>& x);
  std::vector<std::complex<double> > LogGammaFunction(const std::vector<std::complex<double> >& x);
  
} // namespace WaveformUtilities

#endif // VECTORFUNCTIONS_HPP
