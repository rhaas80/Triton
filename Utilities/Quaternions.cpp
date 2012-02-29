#include "Quaternions.hpp"

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

Quaternion::Quaternion(const double angle, const vector<double>& axis)
  : q0(cos(angle/2.0)),
    q1(sin(angle/2.0)*axis[0]/sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2])),
    q2(sin(angle/2.0)*axis[1]/sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2])),
    q3(sin(angle/2.0)*axis[2]/sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2]))
{ }

Quaternion::Quaternion(const double alpha, const double beta, const double gamma)
  : q0(cos(beta/2.)*cos((alpha + gamma)/2.)),
    q1(-(sin(beta/2.)*sin((alpha - gamma)/2.))),
    q2(cos((alpha - gamma)/2.)*sin(beta/2.)),
    q3(cos(beta/2.)*sin((alpha + gamma)/2.))
{ }

const double& Quaternion::operator[](const unsigned int i) const {
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

vector<double> Quaternion::Components() const {
  vector<double> v(4, 0.0);
  v[0] = q0;
  v[1] = q1;
  v[2] = q2;
  v[3] = q3;
  return v;
}

vector<double> Quaternion::Vector() const {
  vector<double> v(3, 0.0);
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
  if(norm==0.0) { return 0.0; }
//   return 2.0*atan2(norm, q0);
  return 2.0*acos(q0/Norm());
}

vector<double> Quaternion::Axis() const {
  vector<double> v(3, 0.0);
  const double norm = sqrt(q1*q1+q2*q2+q3*q3);
  if(norm==0.0) { v[0]=1.0; return v; }
  v[0] = q1/norm;
  v[1] = q2/norm;
  v[2] = q3/norm;
  return v;
}

vector<double> Quaternion::EulerAnglesZYZ() const {
  vector<double> AlphaBetaGamma(3, 0.0);
  Quaternion Q = Normalized();
  AlphaBetaGamma[1] = acos(1-2*q1*q1-2*q2*q2);
  if(AlphaBetaGamma[1]==0.0) { return AlphaBetaGamma; }
//   AlphaBetaGamma[0] = asin((-2*q0*q1 + 2*q2*q3)/sin(AlphaBetaGamma[1]));
//   AlphaBetaGamma[2] = asin((2*q0*q1 + 2*q2*q3)/sin(AlphaBetaGamma[1]));
//   AlphaBetaGamma[0] = acos((2*q0*q2 + 2*q1*q3)/sin(AlphaBetaGamma[1]));
//   AlphaBetaGamma[2] = acos((2*q0*q2 - 2*q1*q3)/sin(AlphaBetaGamma[1]));
  AlphaBetaGamma[0] = atan2((-2*q0*q1 + 2*q2*q3), (2*q0*q2 + 2*q1*q3));
  AlphaBetaGamma[2] = atan2((2*q0*q1 + 2*q2*q3), (2*q0*q2 - 2*q1*q3));
  return AlphaBetaGamma;
}


//// The basic math functions
Quaternion exp(const Quaternion& Q) {
  Quaternion P;
  double b = sqrt(Q[1]*Q[1] + Q[2]*Q[2] + Q[3]*Q[3]);
  if (abs(b)<=numeric_limits<double>::epsilon()) {
    P[0] = ::exp(Q[0]);
  } else {
    double f = sin(b)/b;
    P[0] = ::exp(Q[0])*cos(b);
    P[1] = f*Q[1];
    P[2] = f*Q[2];
    P[3] = f*Q[3];
  }
  return P;
}

Quaternion log(const Quaternion& Q) {
  Quaternion P;
  double b = sqrt(Q[1]*Q[1] + Q[2]*Q[2] + Q[3]*Q[3]);
  if (abs(b)<=numeric_limits<double>::epsilon()) {
    // if (Q[0]<=numeric_limits<double>::epsilon()) {
    //   cerr << "Q=" << Q << endl;
    //   throw("Q is too close to 0 to take the logarithm.");
    // }
    P[0] = ::log(Q[0]);
  } else {
    double t = atan2(b, Q[0]);
    double f = t/b;
    double ct = cos(t);
    // if (abs(ct)<=numeric_limits<double>::epsilon())
    //   throw EValueError("math domain error");
    double r = Q[0]/ct;
    // if (r<=numeric_limits<double>::epsilon())
    //   throw EValueError("math domain error");
    P[0] = ::log(r);
    P[1] = f*Q[1];
    P[2] = f*Q[2];
    P[3] = f*Q[3];
  }
  return P;
}

//// Useful other functions
vector<Quaternion> WaveformUtilities::Quaternions(const vector<double>& alpha, const vector<double>& beta, const vector<double>& gamma) {
  if(alpha.size() != beta.size() || alpha.size() != gamma.size()) {
    cerr << "\nalpha.size()=" << alpha.size() << "\tbeta.size()=" << beta.size() << "\tgamma.size()=" << gamma.size() << endl;
    throw("vector size mismatch");
  }
  vector<Quaternion> Qs(alpha.size());
  for(unsigned int i=0; i<alpha.size(); ++i) {
    Qs[i] = Quaternion(alpha[i], beta[i], gamma[i]);
  }
  return Qs;
}

vector<Quaternion> WaveformUtilities::Conjugate(const vector<Quaternion>& Q) {
  vector<Quaternion> P(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    P[i] = Q[i].Conjugate();
  }
  return P;
}

vector<Quaternion> WaveformUtilities::dQdt(const vector<Quaternion>& Q, const vector<double>& t) {
  if(Q.size() != t.size()) {
    cerr << "\nQ.size()=" << Q.size() << "\tt.size()=" << t.size() << endl;
    throw("vector size mismatch");
  }
  vector<Quaternion> dQ(Q.size());
  for(unsigned int i=0; i<4; ++i) {
    vector<double> qi(Q.size());
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

vector<double> WaveformUtilities::Re(const vector<Quaternion>& Q) {
  vector<double> re(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    re[i] = Q[i].Re();
  }
  return re;
}


Quaternion operator*(const double x, const Quaternion& Q) {
  return (Q*x);
}

Quaternion operator/(const double x, const Quaternion& Q) {
  return (Q.Inverse() * x);
}

vector<Quaternion> operator*(const Quaternion& P, const vector<Quaternion>& Q) {
  vector<Quaternion> PQ(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    PQ[i] = P*Q[i];
  }
  return PQ;
}

vector<Quaternion> operator*(const vector<Quaternion>& Q, const Quaternion& P) {
  vector<Quaternion> QP(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    QP[i] = Q[i]*P;
  }
  return QP;
}

vector<Quaternion> operator*(const vector<Quaternion>& P, const vector<Quaternion>& Q) {
  if(P.size() != Q.size()) {
    cerr << "\nP.size()=" << P.size() << "\tQ.size()=" << Q.size() << endl;
    throw("vector<Quaternion> size mismatch");
  }
  vector<Quaternion> PQ(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    PQ[i] = P[i]*Q[i];
  }
  return PQ;
}

vector<Quaternion> operator-(const vector<Quaternion>& Q) {
  vector<Quaternion> P(Q.size());
  for(unsigned int i=0; i<Q.size(); ++i) {
    P[i] = -Q[i];
  }
  return P;
}
