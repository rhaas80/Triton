#include "Quaternions.hpp"
#include "QuaternionInterpolation.hpp"

#include <iostream>
#include <cmath>
#include <limits>
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
using namespace std;
using WaveformUtilities::Quaternion;

Quaternion::Quaternion()
  : q0(0.0), q1(0.0), q2(0.0), q3(0.0) { }

Quaternion::Quaternion(const double iq0, const double iq1, const double iq2, const double iq3)
  : q0(iq0), q1(iq1), q2(iq2), q3(iq3) { }

Quaternion::Quaternion(const double angle, const std::vector<double>& axis)
  : q0(cos(angle/2.0)),
    q1(sin(angle/2.0)*axis[0]/sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2])),
    q2(sin(angle/2.0)*axis[1]/sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2])),
    q3(sin(angle/2.0)*axis[2]/sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2]))
{ }

Quaternion::Quaternion(const std::vector<double>& vec)
  : q0(0.0),
    q1(vec[0]),
    q2(vec[1]),
    q3(vec[2])
{ }

Quaternion::Quaternion(const double alpha, const double beta, const double gamma)
  : q0(  cos(beta/2.)*cos((alpha + gamma)/2.)),
    q1(-(sin(beta/2.)*sin((alpha - gamma)/2.))),
    q2(  sin(beta/2.)*cos((alpha - gamma)/2.)),
    q3(  cos(beta/2.)*sin((alpha + gamma)/2.))
{ }

double Quaternion::operator[](const unsigned int i) const {
  if(i>3) { cerr << "\ni=" << i << endl; throw("Bad Quaternion index"); }
  if(i==0) { return q0; }
  else if(i==1) { return q1; }
  else if(i==2) { return q2; }
  else if(i==3) { return q3; }
  cerr << "\ni=" << i << endl;
  throw("We shouldn't have gotten here!");
}
				    
double& Quaternion::operator[](const unsigned int i) {
  if(i>3) { cerr << "\ni=" << i << endl; throw("Bad Quaternion index"); }
  if(i==0) { return q0; }
  else if(i==1) { return q1; }
  else if(i==2) { return q2; }
  else if(i==3) { return q3; }
  cerr << "\ni=" << i << endl;
  throw("We shouldn't have gotten here!");
}

bool Quaternion::operator==(const Quaternion& p) const {
  if(q0!=p.q0) { return false; }
  if(q1!=p.q1) { return false; }
  if(q2!=p.q2) { return false; }
  if(q3!=p.q3) { return false; }
  return true;
}

bool Quaternion::operator!=(const Quaternion& p) const {
  if(q0!=p.q0) { return true; }
  if(q1!=p.q1) { return true; }
  if(q2!=p.q2) { return true; }
  if(q3!=p.q3) { return true; }
  return false;
}

std::vector<double> Quaternion::Components() const {
  std::vector<double> v(4, 0.0);
  v[0] = q0;
  v[1] = q1;
  v[2] = q2;
  v[3] = q3;
  return v;
}

std::vector<double> Quaternion::Vector() const {
  std::vector<double> v(3, 0.0);
  v[0] = q1;
  v[1] = q2;
  v[2] = q3;
  return v;
}

double Quaternion::NormSquared() const {
  return q0*q0+q1*q1+q2*q2+q3*q3;
}

double Quaternion::Norm() const {
  return sqrt(q0*q0+q1*q1+q2*q2+q3*q3);
}

Quaternion Quaternion::operator-() const {
  return Quaternion(-q0, -q1, -q2, -q3);
}

Quaternion Quaternion::operator*(const double x) const {
  return Quaternion(q0*x, q1*x, q2*x, q3*x);
}

Quaternion Quaternion::operator/(const double x) const {
  return Quaternion(q0/x, q1/x, q2/x, q3/x);
}

Quaternion Quaternion::operator*(const Quaternion& Q) const {
  return Quaternion(q0*Q.q0 - q1*Q.q1 - q2*Q.q2 - q3*Q.q3,
		    q0*Q.q1 + q1*Q.q0 + q2*Q.q3 - q3*Q.q2,
		    q0*Q.q2 - q1*Q.q3 + q2*Q.q0 + q3*Q.q1,
		    q0*Q.q3 + q1*Q.q2 - q2*Q.q1 + q3*Q.q0);
}

Quaternion Quaternion::operator/(const Quaternion& Q) const {
  return (*this)*(Q.Inverse());
}

Quaternion Quaternion::operator+(const Quaternion& Q) const {
  return Quaternion(q0+Q.q0,q1+Q.q1,q2+Q.q2,q3+Q.q3);
}

Quaternion Quaternion::operator-(const Quaternion& Q) const {
  return Quaternion(q0-Q.q0,q1-Q.q1,q2-Q.q2,q3-Q.q3);
}

Quaternion Quaternion::Conjugate() const {
  return Quaternion(q0, -q1, -q2, -q3);
}

Quaternion Quaternion::Inverse() const {
  return Conjugate()/NormSquared();
}

Quaternion Quaternion::Normalized() const {
  return (*this)/Norm();
}

double Quaternion::Angle() const {
  if(q0==0.0) { return M_PI; }
  const double norm = sqrt(q1*q1+q2*q2+q3*q3);
  if(norm<=3*numeric_limits<double>::epsilon()) { return 0.0; }
//   return 2.0*atan2(norm, q0);
  return 2.0*acos(q0/Norm());
}

std::vector<double> Quaternion::Axis() const {
  std::vector<double> v(3, 0.0);
  const double norm = sqrt(q1*q1+q2*q2+q3*q3);
  if(norm<=3*numeric_limits<double>::epsilon()) { v[0]=1.0; return v; }
  v[0] = q1/norm;
  v[1] = q2/norm;
  v[2] = q3/norm;
  return v;
}

std::vector<double> Quaternion::Vec() const {
  std::vector<double> v(3);
  v[0] = q1;
  v[1] = q2;
  v[2] = q3;
  return v;
}

std::vector<double> Quaternion::EulerAnglesZYZ() const {
  std::vector<double> AlphaBetaGamma(3, 0.0);
  Quaternion Q = Normalized();
  // AlphaBetaGamma[1] = acos(1-2*q1*q1-2*q2*q2);
  // if(std::abs(AlphaBetaGamma[1])<=4*numeric_limits<double>::epsilon()) { return AlphaBetaGamma; }
  // AlphaBetaGamma[0] = asin((-2*q0*q1 + 2*q2*q3)/sin(AlphaBetaGamma[1]));
  // AlphaBetaGamma[2] = asin((2*q0*q1 + 2*q2*q3)/sin(AlphaBetaGamma[1]));
  // AlphaBetaGamma[0] = acos((2*q0*q2 + 2*q1*q3)/sin(AlphaBetaGamma[1]));
  // AlphaBetaGamma[2] = acos((2*q0*q2 - 2*q1*q3)/sin(AlphaBetaGamma[1]));
  AlphaBetaGamma[0] = atan2((-2*q0*q1 + 2*q2*q3), (2*q0*q2 + 2*q1*q3));
  AlphaBetaGamma[1] = acos(1-2*q1*q1-2*q2*q2);
  AlphaBetaGamma[2] = atan2((2*q0*q1 + 2*q2*q3), (2*q0*q2 - 2*q1*q3));
  return AlphaBetaGamma;
}

Quaternion Quaternion::exp() const {
  Quaternion P;
  const double b = sqrt(q1*q1 + q2*q2 + q3*q3);
  if (b<=3*numeric_limits<double>::epsilon()) {
    P[0] = ::exp(q0);
  } else {
    const double e = ::exp(q0);
    const double f = sin(b)/b;
    P[0] = e*cos(b);
    P[1] = e*f*q1;
    P[2] = e*f*q2;
    P[3] = e*f*q3;
  }
  return P;
}

Quaternion Quaternion::log() const {
  Quaternion P;
  double b = sqrt(q1*q1 + q2*q2 + q3*q3);
  if (b<=3*numeric_limits<double>::epsilon()) {
    // if (q0<=numeric_limits<double>::epsilon()) {
    //   cerr << "Q=" << Q << endl;
    //   throw("Q is too close to 0 to take the logarithm.");
    // }
    P[0] = ::log(q0);
  } else {
    double t = atan2(b, q0);
    double f = t/b;
    double ct = cos(t);
    // if (std::abs(ct)<=numeric_limits<double>::epsilon())
    //   throw EValueError("math domain error");
    double r = q0/ct;
    // if (r<=numeric_limits<double>::epsilon())
    //   throw EValueError("math domain error");
    P[0] = ::log(r);
    P[1] = f*q1;
    P[2] = f*q2;
    P[3] = f*q3;
  }
  return P;
}


// Useful other functions
std::vector<WaveformUtilities::Quaternion> WaveformUtilities::Quaternions(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma) {
  if(alpha.size() != beta.size() || alpha.size() != gamma.size()) {
    cerr << "\nalpha.size()=" << alpha.size() << "\tbeta.size()=" << beta.size() << "\tgamma.size()=" << gamma.size() << endl;
    throw("std::vector size mismatch");
  }
  std::vector<Quaternion> Qs(alpha.size());
  for(unsigned int i=0; i<alpha.size(); ++i) {
    Qs[i] = Quaternion(alpha[i], beta[i], gamma[i]);
  }
  return Qs;
}

std::vector<WaveformUtilities::Quaternion> WaveformUtilities::Conjugate(const std::vector<WaveformUtilities::Quaternion>& Q) {
  std::vector<Quaternion> P(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    P[i] = Q[i].Conjugate();
  }
  return P;
}

std::vector<WaveformUtilities::Quaternion> WaveformUtilities::dQdt(const std::vector<WaveformUtilities::Quaternion>& Q, const std::vector<double>& t) {
  if(Q.size() != t.size()) {
    cerr << "\nQ.size()=" << Q.size() << "\tt.size()=" << t.size() << endl;
    throw("std::vector size mismatch");
  }
  std::vector<Quaternion> dQ(Q.size());
  for(unsigned int i=0; i<4; ++i) {
    std::vector<double> qi(Q.size());
    for(unsigned int j=0; j<t.size(); ++j) {
      qi[j] = Q[j][i];
    }
    qi = WaveformUtilities::dydx(qi, t);
    for(unsigned int j=0; j<t.size(); ++j) {
      dQ[j][i] = qi[j];
    }
  }
  return dQ;
}

std::vector<WaveformUtilities::Quaternion> WaveformUtilities::MinimalRotation(const std::vector<WaveformUtilities::Quaternion>& Q,
									      const std::vector<double>& t,
									      const unsigned int NIterations) {
  if(Q.size() != t.size()) {
    cerr << "\nQ.size()=" << Q.size() << "\tt.size()=" << t.size() << endl;
    throw("std::vector size mismatch");
  }
  std::vector<Quaternion> MinRot(Q);
  const Quaternion z(0.,0.,0.,1.);
  for(unsigned int iteration=0; iteration<NIterations; ++iteration) {
    // Note that Component0 gives -1 times the dot product of two vectors
    const vector<double> gammaover2 = SplineIntegral(t, Component0( Conjugate(MinRot) * dQdt_Squad(MinRot,t) * z ));
    for(unsigned int i=0; i<gammaover2.size(); ++i) {
      MinRot[i] = MinRot[i] * (gammaover2[i]*z).exp();
    }
  }
  return MinRot;
}

std::vector<double> WaveformUtilities::Re(const std::vector<WaveformUtilities::Quaternion>& Q) {
  std::vector<double> re(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    re[i] = Q[i].Re();
  }
  return re;
}

std::vector<double> WaveformUtilities::Component(const std::vector<WaveformUtilities::Quaternion>& Q, const unsigned int i) {
  std::vector<double> v(Q.size());
  for(unsigned int j=0; j<Q.size(); ++j) {
    v[j] = Q[j][i];
  }
  return v;
}

std::vector<double> WaveformUtilities::Component0(const std::vector<WaveformUtilities::Quaternion>& Q) {
  return Component(Q, 0);
}

std::vector<double> WaveformUtilities::Component1(const std::vector<WaveformUtilities::Quaternion>& Q) {
  return Component(Q, 1);
}

std::vector<double> WaveformUtilities::Component2(const std::vector<WaveformUtilities::Quaternion>& Q) {
  return Component(Q, 2);
}

std::vector<double> WaveformUtilities::Component3(const std::vector<WaveformUtilities::Quaternion>& Q) {
  return Component(Q, 3);
}

Quaternion operator*(const double x, const Quaternion& Q) {
  return (Q*x);
}

Quaternion operator/(const double x, const Quaternion& Q) {
  return (Q.Inverse() * x);
}

std::vector<WaveformUtilities::Quaternion> operator*(const Quaternion& P, const std::vector<WaveformUtilities::Quaternion>& Q) {
  std::vector<Quaternion> PQ(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    PQ[i] = P*Q[i];
  }
  return PQ;
}

std::vector<WaveformUtilities::Quaternion> operator/(const Quaternion& P, const std::vector<WaveformUtilities::Quaternion>& Q) {
  std::vector<Quaternion> PQ(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    PQ[i] = P/Q[i];
  }
  return PQ;
}

std::vector<WaveformUtilities::Quaternion> operator*(const std::vector<WaveformUtilities::Quaternion>& Q, const Quaternion& P) {
  std::vector<Quaternion> QP(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    QP[i] = Q[i]*P;
  }
  return QP;
}

std::vector<WaveformUtilities::Quaternion> operator/(const std::vector<WaveformUtilities::Quaternion>& Q, const Quaternion& P) {
  std::vector<Quaternion> QP(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    QP[i] = Q[i]/P;
  }
  return QP;
}

std::vector<WaveformUtilities::Quaternion> operator*(const std::vector<WaveformUtilities::Quaternion>& P, const std::vector<WaveformUtilities::Quaternion>& Q) {
  if(P.size() != Q.size()) {
    cerr << "\nP.size()=" << P.size() << "\tQ.size()=" << Q.size() << endl;
    throw("std::vector<Quaternion> size mismatch");
  }
  std::vector<Quaternion> PQ(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    PQ[i] = P[i]*Q[i];
  }
  return PQ;
}

std::vector<WaveformUtilities::Quaternion> operator/(const std::vector<WaveformUtilities::Quaternion>& P, const std::vector<WaveformUtilities::Quaternion>& Q) {
  if(P.size() != Q.size()) {
    cerr << "\nP.size()=" << P.size() << "\tQ.size()=" << Q.size() << endl;
    throw("std::vector<Quaternion> size mismatch");
  }
  std::vector<Quaternion> PQ(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    PQ[i] = P[i]/Q[i];
  }
  return PQ;
}

std::vector<WaveformUtilities::Quaternion> operator-(const std::vector<WaveformUtilities::Quaternion>& Q) {
  std::vector<Quaternion> P(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    P[i] = -Q[i];
  }
  return P;
}

ostream& operator<<(ostream& out, const WaveformUtilities::Quaternion& q) {
  out << "[" << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << "]";
  return out;
}
