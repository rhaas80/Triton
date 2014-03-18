#ifndef VECTORFUNCTIONS_HPP
#define VECTORFUNCTIONS_HPP

#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <limits>
#include "Matrix.hpp"

/// IO operators for vectors and matrices
std::ostream& operator<<(std::ostream& out, const std::vector<double>& v);
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v);
std::ostream& operator<<(std::ostream& out, const WaveformUtilities::Matrix<double>& v);
std::ostream& operator<<(std::ostream& out, const WaveformUtilities::Matrix<int>& v);
std::string RowFormat(const std::vector<double>& v);
std::string RowFormat(const std::vector<int>& v);
std::string RowFormat(const WaveformUtilities::Matrix<double>& m);
std::string RowFormat(const WaveformUtilities::Matrix<int>& m);

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
  /// 3-vector operations
  double dot(const std::vector<double>& x, const std::vector<double>& y);
  std::vector<double> dot(const std::vector<std::vector<double> >& x, const std::vector<std::vector<double> >& y);
  std::vector<double> cross(const std::vector<double>& x, const std::vector<double>& y);
  double norm(const std::vector<double>& x);
  std::vector<double> norm(const std::vector<std::vector<double> >& x);

  /// NOTE!!! After optimization, the following are barely faster than pow.  These are, of course, incorrectly implemented because of the 'inline's.
  ///
  /// Small integer powers:
  /// To compute x^n efficiently, write n in binary, then replace each 1 with "SX" and each 0 with "S",
  /// and cross off the first SX appearing at the left.  Read from left to right, this rule tells us to
  /// square (S) or multiply by x (X) in turn.  This algorithm is the most efficient choice up to n=15.
  /// [Knuth, Vol 2., 4.6.3]
  inline double square(const double x) { return x*x; } // n=10; 1==1
  inline double cube(const double x) { return x*x*x; } // n=11; 2==2
  inline double fourth(const double x) { return square(square(x)); } // n=100; 2<3
  inline double fifth(const double x) { return x*square(square(x)); } // n=101; 3<4
  inline double sixth(const double x) { return square(x*square(x)); } // n=110; 3<5
  inline double seventh(const double x) { return x*square(x*square(x)); } // n=111; 4<6
  inline double eighth(const double x) { return square(square(square(x))); } // n=1000; 3<7
  inline double ninth(const double x) { return x*square(square(square(x))); } // n=1001; 4<8
  inline double tenth(const double x) { return square(x*square(square(x))); } // n=1010; 3<9
  inline std::vector<double> square(const std::vector<double>& x);
  inline std::vector<double> cube(const std::vector<double>& x);
  inline std::vector<double> fourth(const std::vector<double>& x);
  inline std::vector<double> fifth(const std::vector<double>& x);
  inline std::vector<double> sixth(const std::vector<double>& x);
  inline std::vector<double> seventh(const std::vector<double>& x);
  inline std::vector<double> eighth(const std::vector<double>& x);

  /// Max-type functions
  double maxfabs(const std::vector<double>& x);
  double maxmag(const std::vector<double>& Re, const std::vector<double>& Im);
  double maxfabs(const WaveformUtilities::Matrix<double>& x);
  double maxmag(const WaveformUtilities::Matrix<double>& Re, const WaveformUtilities::Matrix<double>& Im);
  unsigned int maxIndex(const std::vector<double>& a);
  unsigned int maxIndex(const WaveformUtilities::Matrix<double>& a);
  double max(const std::vector<double>& In);
  double min(const std::vector<double>& In);
  int max(const std::vector<int>& In);
  int min(const std::vector<int>& In);
//   template <class T>
//   inline T min(const T a, const T b) {
//     return (a<b ? a : b);
//   }
//   template <class T>
//   inline T max(const T a, const T b) {
//     return (a>b ? a : b);
//   }

  /// Integral, derivative, etc.
  std::vector<double> diff(const std::vector<double>& In);
  double sum(const std::vector<double>& In);
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
  std::vector<double>& Unwrap(std::vector<double>& a, const unsigned int i1, const unsigned int i2); // Unwrap between two indices
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

  /// NaN, inf, and monotonicity checks
  inline bool isnan(const double a) {
    return (a != a);
  }
  bool hasnan(const std::vector<double>& a);
  bool hasnan(const WaveformUtilities::Matrix<double>& a);
  inline bool isinf(const double a) {
    return (a == std::numeric_limits<double>::infinity());
  }
  bool hasinf(const std::vector<double>& a);
  bool hasinf(const WaveformUtilities::Matrix<double>& a);
  bool ismonotonic(const std::vector<double>& a);

  /// Transition functions
  inline double TransitionFunction_Linear(const double x) {
    return (x<0.0 ? 0.0 : (x>1.0 ? 1.0 : x) );
  }
  inline double TransitionFunction_Linear(const double x, const double a, const double b) {
    return TransitionFunction_Linear((x-a)/b);
  }
  inline double TransitionFunction_Smooth(const double x) {
    return (x<=0.0 ? 0.0 : (x>=1.0 ? 1.0 : 1.0/(1.0+::exp(1.0/(x-1.0) + 1.0/x))) );
  }
  inline double TransitionFunction_Smooth(const double x, const double a, const double b) {
    return TransitionFunction_Smooth((x-a)/b);
  }

} // namespace WaveformUtilities

#endif // VECTORFUNCTIONS_HPP
