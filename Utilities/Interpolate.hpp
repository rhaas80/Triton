#ifndef INTERPOLATE_HPP
#define INTERPOLATE_HPP

#include <vector>

namespace WaveformUtilities {
  
  std::vector<double> Interpolate(const std::vector<double>& X1, const std::vector<double>& Y1, const std::vector<double>& X2);
  void Interpolate(const std::vector<double>& X1, const std::vector<double>& Y1, const std::vector<double>& X2, std::vector<double>& Y2);
  double Interpolate(const std::vector<double>& X1, const std::vector<double>& Y1, const double& X2);
  
  
  class Interpolator {
  protected:
    int n, mm, jsav, cor, dj;
    const std::vector<double> &xx, &yy;
    
  public:
    Interpolator(const std::vector<double>& x, const std::vector<double>& y, int m);
    virtual ~Interpolator() { }//  delete[] xx; delete[] yy; }
    
    double interp(double x) {
      int jlo = cor ? hunt(x) : locate(x);
      return rawinterp(jlo,x);
    }
    
    int locate(const double x);
    int hunt(const double x);
    
    double virtual rawinterp(int jlo, double x) = 0;
  };
  
  
  class PolynomialInterpolator : Interpolator {
    double dy;
    
  public:
    PolynomialInterpolator(const std::vector<double>& xv, const std::vector<double>& yv, int m)
      : Interpolator(xv,yv,m), dy(0.) { }
    double rawinterp(int jl, double x);
  };
  
  class SplineInterpolator : public Interpolator {
    std::vector<double> y2;
    
  public:
    SplineInterpolator(const std::vector<double>& xv, const std::vector<double>& yv, double yp1=1.e99, double ypn=1.e99)
      : Interpolator(xv,yv,2), y2(xv.size())
    { sety2(xv,yv,yp1,ypn); }
    
    void sety2(const std::vector<double>& xv, const std::vector<double>& yv, double yp1, double ypn);
    double rawinterp(int jl, double xv);
  };
  
} // namespace WaveformUtilities

#endif // INTERPOLATE_HPP
