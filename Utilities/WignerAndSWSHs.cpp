#include "WignerAndSWSHs.hpp"
#include <cmath>
using std::vector;
using std::complex;


/// Class to create an object returning the factorial of an argument.
WaveformUtilities::FactorialFunctor::FactorialFunctor()
  : FactorialTable(171)
{
  /// Note that because a double is returned, only values up to 28!
  /// will be exact; higher values will be accurate to machine
  /// precision.  Values up to 170! only are allowed because higher
  /// values overflow.
  FactorialTable[0] = 1.0;
  for (int i=1;i<171;i++) {
    FactorialTable[i] = i*FactorialTable[i-1];
  }
}

WaveformUtilities::BinomialCoefficientFunctor::BinomialCoefficientFunctor()
  : BinomialCoefficientTable(2*ellMax*ellMax + 3*ellMax + 1)
{
  /// We need (n+1) coefficients for each value of n from 0 (for
  /// completeness) up to 2*ellMax (hard coded in the header file).
  /// That's a total of
  ///   >>> from sympy import summation, symbols
  ///   >>> ellMax, n, k = symbols('ellMax n k', integer=True)
  ///   >>> summation(n+1, (n, 0, 2*ellMax))
  ///  2*ellMax**2 + 3*ellMax + 1
  /// With a similar calculation, we can see that the associated access
  /// operator needs element (n*(n+1)/2 + k) of the array.
  unsigned int i=0;
  WaveformUtilities::FactorialFunctor Factorial;
  for(unsigned int n=0; n<=2*ellMax; ++n) {
    for(unsigned int k=0; k<=n; ++k) {
      BinomialCoefficientTable[i++] = std::floor(0.5+Factorial(n)/(Factorial(k)*Factorial(n-k)));
    }
  }
}

WaveformUtilities::LadderOperatorFactorFunctor::LadderOperatorFactorFunctor()
  : FactorTable(ellMax*ellMax + 2*ellMax + 1)
{
  /// We need (2*ell+1) coefficients for each value of ell from 0 (for
  /// completeness) up to ellMax (hard coded in the header file).
  /// That's a total of
  ///   >>> from sympy import summation, symbols
  ///   >>> ell, ellMax, m, mp = symbols('ell ellMax m mp', integer=True)
  ///   >>> summation(2*ell+1, (ell, 0, ellMax))
  ///   ellMax**2 + 2*ellMax + 1
  /// With a similar calculation, we can see that the associated access
  /// operator needs element (ell**2 + ell + m) of the array.
  unsigned int i=0;
  for(int ell=0; ell<=ellMax; ++ell) {
    for(int m=-ell; m<=ell; ++m) {
      FactorTable[i++] = std::sqrt(ell*(ell+1)-m*(m+1));
    }
  }
}

WaveformUtilities::WignerCoefficientFunctor::WignerCoefficientFunctor()
  : CoefficientTable(int(ellMax*(ellMax*(1.3333333333333333*ellMax + 4) + 3.6666666666666667) + 1 + 0.5))
{
  /// We need (2*ell+1)*(2*ell+1) coefficients for each value of ell
  /// from 0 (for completenes) up to ellMax (hard coded in the header
  /// file).  That's a total of
  ///   >>> from sympy import summation, symbols, simplify
  ///   >>> from sympy.polys.polyfuncs import horner
  ///   >>> ell, ellMax, m, mp = symbols('ell ellMax m mp', integer=True)
  ///   >>> horner(simplify(summation((2*ell+1)**2, (ell, 0, ellMax))))
  ///   ellMax*(ellMax*(4*ellMax/3 + 4) + 11/3) + 1
  /// With a similar calculation, we can see that the associated access
  /// operator needs element
  ///   >>> horner(summation((2*ell+1)**2, (ell, 0, ell-1)) + (2*ell+1)*(ell+mp) + ell + m)
  ///   ell*(ell*(4*ell/3 + 2) + 5/3) + mp*(2*ell + 1) + m
  /// of the array.
  WaveformUtilities::FactorialFunctor Factorial;
  unsigned int i=0;
  for(int ell=0; ell<=ellMax; ++ell) {
    for(int mp=-ell; mp<=ell; ++mp) {
      for(int m=-ell; m<=ell; ++m) {
        CoefficientTable[i++] =
          std::sqrt( Factorial(ell+mp)*Factorial(ell-mp)
                     / double(Factorial(ell+m)*Factorial(ell-m)) );
      }
    }
  }
}


WaveformUtilities::WignerDMatrix::WignerDMatrix(const Quaternion& R)
  : BinomialCoefficient(), WignerCoefficient(),
    Ra(R[0], R[3]), Rb(R[2], R[1]),
    absRa(abs(Ra)), absRb(abs(Rb)), absRRatioSquared(absRb*absRb/(absRa*absRa))
{ }

WaveformUtilities::WignerDMatrix& WaveformUtilities::WignerDMatrix::SetRotation(const Quaternion& R) {
  Ra = complex<double>(R[0], R[3]);
  Rb = complex<double>(R[2], R[1]);
  absRa = abs(Ra);
  absRb = abs(Rb);
  absRRatioSquared = absRb*absRb/(absRa*absRa);
  return *this;
}

complex<double> WaveformUtilities::WignerDMatrix::operator()(const int ell, const int mp, const int m) const {
  if(absRa == 0.0) {
    return (m!=mp ? 0.0 : ((ell+m)%2==0 ? 1.0 : -1.0) * std::pow(Rb, -2*m) );
  }
  if(absRb == 0.0) {
    return (m!=mp ? 0.0 : std::pow(Ra, 2*m) );
  }
  const complex<double> Prefactor =
    (WignerCoefficient(ell, mp, m) * std::pow(absRa, 2*ell-2*mp))
    * std::pow(Ra,mp+m) * std::pow(Rb, mp-m);
  const int rhoMin = std::max(0,m-mp);
  const int rhoMax = std::min(ell+m,ell-mp);
  double Sum = 0.0;
  for(int rho=rhoMax; rho>=rhoMin; --rho) {
    Sum = ( (rho%2==0 ? 1 : -1) * BinomialCoefficient(ell+m,rho) * BinomialCoefficient(ell-m, ell-rho-mp) )
      + ( Sum * absRRatioSquared );
  }
  return Prefactor * Sum * std::pow(absRRatioSquared, rhoMin);
}
