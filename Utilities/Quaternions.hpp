#ifndef QUATERNIONS_HPP
#define QUATERNIONS_HPP

#include <vector>
#include <iostream>

namespace WaveformUtilities {
  
  class Quaternion {
  private:
    double q0, q1, q2, q3;
  public:
    Quaternion();
    Quaternion(const double q0, const double q1, const double q2, const double q3);
    Quaternion(const double angle, const std::vector<double>& axis);
    Quaternion(const std::vector<double>& vec);
    Quaternion(const double alpha, const double beta, const double gamma);
  public:
    double operator[](const unsigned int i) const;
    double& operator[](const unsigned int i);
    bool operator==(const Quaternion& p) const;
    bool operator!=(const Quaternion& p) const;
    std::vector<double> Components() const;
    const double& Re() const { return q0; }
    std::vector<double> Vector() const;
  public:
    double NormSquared() const;
    double Norm() const;
    inline Quaternion operator-() const { return Quaternion(-q0, -q1, -q2, -q3); }
    inline Quaternion operator+(const double t) const { return Quaternion(q0+t, q1, q2, q3); }
    inline Quaternion operator-(const double t) const { return Quaternion(q0-t, q1, q2, q3); }
    inline Quaternion operator*(const double t) const { return Quaternion(q0*t, q1*t, q2*t, q3*t); }
    inline Quaternion operator/(const double t) const { return Quaternion(q0/t, q1/t, q2/t, q3/t); }
    inline Quaternion operator+(const Quaternion& Q) const { return Quaternion(q0+Q.q0,q1+Q.q1,q2+Q.q2,q3+Q.q3); }
    inline Quaternion operator-(const Quaternion& Q) const { return Quaternion(q0-Q.q0,q1-Q.q1,q2-Q.q2,q3-Q.q3); }
    Quaternion operator*(const Quaternion& Q) const;
    inline Quaternion operator/(const Quaternion& Q) const { return (*this)*(Q.Inverse()); }
    inline Quaternion pow(const double t) const { return (this->log() * t).exp(); }
    inline Quaternion pow(const Quaternion& Q) const { return (this->log() * Q).exp(); }
    inline double     abs() const { return std::sqrt(NormSquared()); }
    double Dot(const Quaternion& Q) const { return q0*Q.q0+q1*Q.q1+q2*Q.q2+q3*Q.q3; }
    Quaternion Conjugate() const;
    Quaternion Inverse() const;
    Quaternion Normalized() const;
    double Angle() const;
    std::vector<double> Axis() const;
    std::vector<double> Vec() const;
    std::vector<double> EulerAnglesZYZ() const;
    Quaternion exp() const;
    Quaternion log() const;
    //Quaternion pow(const double x) const;
    inline double     angle() const { return 2*log().abs(); }
    inline Quaternion sqrtOfRotor() const { return (*this+1)/std::sqrt(2+2*q0); }
  };
  
  // const Quaternion Quaternion1(1.0,0.0,0.0,0.0);
  // const Quaternion Quaternionx(0.0,1.0,0.0,0.0);
  // const Quaternion Quaterniony(0.0,0.0,1.0,0.0);
  // const Quaternion Quaternionz(0.0,0.0,0.0,1.0);
  
  // inline WaveformUtilities::Quaternion exp(const WaveformUtilities::Quaternion& Q) { return Q.exp(); }
  // inline WaveformUtilities::Quaternion log(const WaveformUtilities::Quaternion& Q) { return Q.log(); }
  // inline WaveformUtilities::Quaternion pow(const WaveformUtilities::Quaternion& Q, const double x) { return Q.pow(x); }
  
  std::vector<WaveformUtilities::Quaternion> Quaternions(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma);
  std::vector<WaveformUtilities::Quaternion> Conjugate(const std::vector<WaveformUtilities::Quaternion>& Q);
  // std::vector<WaveformUtilities::Quaternion> dQdt(const std::vector<WaveformUtilities::Quaternion>& Q, const std::vector<double>& t);
  // std::vector<WaveformUtilities::Quaternion> MinimalRotation(const std::vector<WaveformUtilities::Quaternion>& Q, const std::vector<double>& t,
  // 							     const unsigned int NIterations=5);
  
  std::vector<double> Re(const std::vector<WaveformUtilities::Quaternion>& Q);
  std::vector<double> Component(const std::vector<WaveformUtilities::Quaternion>& Q, const unsigned int i);
  std::vector<double> Component0(const std::vector<WaveformUtilities::Quaternion>& Q);
  std::vector<double> Component1(const std::vector<WaveformUtilities::Quaternion>& Q);
  std::vector<double> Component2(const std::vector<WaveformUtilities::Quaternion>& Q);
  std::vector<double> Component3(const std::vector<WaveformUtilities::Quaternion>& Q);
}

#ifndef SWIG
WaveformUtilities::Quaternion operator*(const double a, const WaveformUtilities::Quaternion& Q);
WaveformUtilities::Quaternion operator/(const double a, const WaveformUtilities::Quaternion& Q);

std::vector<WaveformUtilities::Quaternion> operator*(const WaveformUtilities::Quaternion& P, const std::vector<WaveformUtilities::Quaternion>& Q);
std::vector<WaveformUtilities::Quaternion> operator/(const WaveformUtilities::Quaternion& P, const std::vector<WaveformUtilities::Quaternion>& Q);
std::vector<WaveformUtilities::Quaternion> operator*(const std::vector<WaveformUtilities::Quaternion>& Q, const WaveformUtilities::Quaternion& P);
std::vector<WaveformUtilities::Quaternion> operator/(const std::vector<WaveformUtilities::Quaternion>& Q, const WaveformUtilities::Quaternion& P);
std::vector<WaveformUtilities::Quaternion> operator*(const std::vector<WaveformUtilities::Quaternion>& P, const std::vector<WaveformUtilities::Quaternion>& Q);
std::vector<WaveformUtilities::Quaternion> operator/(const std::vector<WaveformUtilities::Quaternion>& P, const std::vector<WaveformUtilities::Quaternion>& Q);
std::vector<WaveformUtilities::Quaternion> operator-(const std::vector<WaveformUtilities::Quaternion>& Q);

std::ostream& operator<<(std::ostream& out, const WaveformUtilities::Quaternion& q);
#endif // SWIG

#endif // QUATERNIONS_HPP
