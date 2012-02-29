#ifndef QUATERNIONS_HPP
#define QUATERNIONS_HPP

#include <vector>

namespace WaveformUtilities {
  
  class Quaternion {
  private:
    double q0, q1, q2, q3;
  public:
    Quaternion();
    Quaternion(const double q0, const double q1, const double q2, const double q3);
    Quaternion(const double angle, const std::vector<double>& axis);
    Quaternion(const double alpha, const double beta, const double gamma);
  public:
    const double& operator[](const unsigned int i) const;
    double& operator[](const unsigned int i);
    std::vector<double> Components() const;
    const double& Re() const { return q0; }
    std::vector<double> Vector() const;
  public:
    double NormSquared() const;
    double Norm() const;
    Quaternion operator-() const;
    Quaternion operator*(const double x) const;
    Quaternion operator/(const double x) const;
    Quaternion operator*(const Quaternion& Q) const;
    Quaternion operator/(const Quaternion& Q) const;
    Quaternion operator+(const Quaternion& Q) const;
    Quaternion operator-(const Quaternion& Q) const;
    double Dot(const Quaternion& Q) const { return q0*Q.q0+q1*Q.q1+q2*Q.q2+q3*Q.q3; }
    Quaternion Conjugate() const;
    Quaternion Inverse() const;
    Quaternion Normalized() const;
    double Angle() const;
    std::vector<double> Axis() const;
    std::vector<double> EulerAnglesZYZ() const;
  };
  
  WaveformUtilities::Quaternion exp(const WaveformUtilities::Quaternion& Q);
  WaveformUtilities::Quaternion log(const WaveformUtilities::Quaternion& Q);
  WaveformUtilities::Quaternion pow(const WaveformUtilities::Quaternion& Q, const double x);
  
  std::vector<WaveformUtilities::Quaternion> Quaternions(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma);
  std::vector<WaveformUtilities::Quaternion> Conjugate(const std::vector<WaveformUtilities::Quaternion>& Q);
  std::vector<WaveformUtilities::Quaternion> dQdt(const std::vector<WaveformUtilities::Quaternion>& Q, const std::vector<double>& t);
  std::vector<double> Re(const std::vector<WaveformUtilities::Quaternion>& Q);
  
}

WaveformUtilities::Quaternion operator*(const double a, const WaveformUtilities::Quaternion& Q);
WaveformUtilities::Quaternion operator/(const double a, const WaveformUtilities::Quaternion& Q);

std::vector<WaveformUtilities::Quaternion> operator*(const WaveformUtilities::Quaternion& P, const std::vector<WaveformUtilities::Quaternion>& Q);
std::vector<WaveformUtilities::Quaternion> operator*(const std::vector<WaveformUtilities::Quaternion>& Q, const WaveformUtilities::Quaternion& P);
std::vector<WaveformUtilities::Quaternion> operator*(const std::vector<WaveformUtilities::Quaternion>& P, const std::vector<WaveformUtilities::Quaternion>& Q);
std::vector<WaveformUtilities::Quaternion> operator-(const std::vector<WaveformUtilities::Quaternion>& Q);



#endif // QUATERNIONS_HPP
