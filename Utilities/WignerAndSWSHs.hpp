#ifndef WignerAndSWSHs_HPP
#define WignerAndSWSHs_HPP

#include <vector>
#include <complex>
#include "Quaternions.hpp"

// This file is taken from the GWFrames code I wrote for my paper on
// frames.  I've changed the namespace, but otherwise, I'm trying to
// make sure that they're just the same.

namespace WaveformUtilities {
  const int ellMax = 16;

  class FactorialFunctor {
  private:
    std::vector<double> FactorialTable;
  public:
    FactorialFunctor();
    inline double operator()(const unsigned int i) const { return FactorialTable[i]; }
  };

  class BinomialCoefficientFunctor {
  private:
    std::vector<double> BinomialCoefficientTable;
  public:
    BinomialCoefficientFunctor();
    inline double operator()(const unsigned int n, const unsigned int k) const { return BinomialCoefficientTable[(n*(n+1))/2+k]; }
  };

  class LadderOperatorFactorFunctor {
  private:
    std::vector<double> FactorTable;
  public:
    LadderOperatorFactorFunctor();
    inline double operator()(const int ell, const int m) const { return FactorTable[ell*ell+ell+m]; }
  };

  class WignerCoefficientFunctor {
  private:
    std::vector<double> CoefficientTable;
  public:
    WignerCoefficientFunctor();
    inline double operator()(const int ell, const int mp, const int m) const {
      return CoefficientTable[int(ell*(ell*(1.3333333333333333*ell + 2) + 1.6666666666666667) + mp*(2*ell + 1) + m + 0.5)];
    }
  };

  class WignerDMatrix {
  private:
    BinomialCoefficientFunctor BinomialCoefficient;
    WignerCoefficientFunctor WignerCoefficient;
    std::complex<double> Ra, Rb;
    double absRa, absRb, absRRatioSquared;
  public:
    WignerDMatrix(const Quaternion& iR=Quaternion(1,0,0,0));
    WignerDMatrix& SetRotation(const Quaternion& iR);
    std::complex<double> operator()(const int ell, const int mp, const int m) const;
  };

  class SWSH {
  private:
    WignerDMatrix D;
    int spin;
    double sign;
  public:
    SWSH(const int s=-2, const Quaternion& iR=Quaternion(1,0,0,0))
      : D(iR), spin(s), sign(s%2==0 ? 1.0 : -1.0)
    { }
    inline SWSH& SetRotation(const Quaternion& iR) { D.SetRotation(iR); return *this; }
    inline SWSH& SetAngles(const double vartheta, const double varphi) { D.SetRotation(Quaternion(vartheta, varphi)); return *this; }
    inline std::complex<double> operator()(const int ell, const int m) const {
      return sign * std::sqrt((2*ell+1)/(4*M_PI)) * D(ell, -spin, m);
    }
  };


} // namespace WaveformUtilities

#endif // WignerAndSWSHs_HPP
