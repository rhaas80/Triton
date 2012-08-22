#include <limits>
#include <cmath>
#include <iostream>
#include "QuaternionInterpolation.hpp"

using namespace std;
namespace WU = WaveformUtilities;
using WU::Quaternion;

Quaternion WU::Slerp(double t, const Quaternion& Q0, const Quaternion& Q1, bool shortest) {
  double o,so,a,b;
  bool neg_Q1 = false;   // Does Q1 have to be negated (so that the shortest path is taken)?
  
  double ca = Q0.Dot(Q1);
  if (shortest && ca<0) {
    ca = -ca;
    neg_Q1 = true;
  }
  o = acos(ca);
  so = sin(o);
  
  if (abs(so)<numeric_limits<double>::epsilon()) {
    return Q0;
  }
  
  a = sin(o*(1.0-t)) / so;
  b = sin(o*t) / so;
  if (neg_Q1) {
    return Q0*a - Q1*b;
  } else {
    return Q0*a + Q1*b;
  }
}

Quaternion WU::Squad(double t, const Quaternion& Q0, const Quaternion& c0, const Quaternion& c1, const Quaternion& Q1) {
  return WU::Slerp(2*t*(1.0-t), WU::Slerp(t,Q0,Q1), WU::Slerp(t,c0,c1));
}

vector<Quaternion> WU::Squad(const vector<double>& tIn, const vector<Quaternion>& QIn, const vector<double>& tOut) {
  vector<Quaternion> QOut(tOut.size());
  QuaternionInterpolator QInterp(tIn, QIn);
  for(unsigned int i=0; i<QOut.size(); ++i) {
    QOut[i] = QInterp.Interpolate(tOut[i]);
  }
  return QOut;
}

vector<Quaternion> WU::dQdt_Squad(const vector<Quaternion>& QIn, const vector<double>& tIn) {
  if(tIn.size()<2) {
    cerr << "\ntIn.size()=" << tIn.size() << endl;
    throw("Can't take derivative of fewer than 2 points.");
  }
  if(tIn.size()!=QIn.size()) {
    cerr << "\ntIn.size()=" << tIn.size() << "  QIn.size()=" << QIn.size() << endl;
    throw("Input size mismatch in dQdt_Squad");
  }
  vector<Quaternion> QOut(QIn.size());
  QOut[0] = (QIn[0] * (QIn[0].Inverse()*QIn[1]).log()) * (1.0/(tIn[1]-tIn[0]));
  for(unsigned int i=1; i<tIn.size()-1; ++i) {
    QOut[i] = ( QIn[i] * ( (QIn[i].Inverse()*QIn[i+1]).log() - (QIn[i].Inverse()*QIn[i-1]).log()) ) / (tIn[i+1]-tIn[i-1]);
  }
  QOut[QOut.size()-1] = (QIn[QIn.size()-1] * (QIn[QIn.size()-2].Inverse()*QIn[QIn.size()-1]).log()) * (1.0/(tIn[tIn.size()-1]-tIn[tIn.size()-2]));
  return QOut;
}

vector<Quaternion> WU::SquadVelocities(const vector<double>& tIn, const vector<Quaternion>& QIn) {
  cerr << "\n\nWARNING!!!  SquadVelocities may still assume evenly spaced samples!!!  (This needs to be checked.)\n" << endl;
  if(tIn.size()<2) {
    cerr << "\ntIn.size()=" << tIn.size() << endl;
    throw("Can't take derivative of fewer than 2 points.");
  }
  if(tIn.size()!=QIn.size()) {
    cerr << "\ntIn.size()=" << tIn.size() << "  QIn.size()=" << QIn.size() << endl;
    throw("Input size mismatch in SquadVelocities");
  }
  vector<Quaternion> v(tIn.size());
  v[0] = (QIn[0] * (QIn[0].Inverse()*QIn[1]).log()) * (1.0/(tIn[1]-tIn[0]));
  for(unsigned int i=1; i<tIn.size()-1; ++i) {
    v[i] = QIn[i] * (0.5 * ((QIn[i].Inverse()*QIn[i+1]).log()/(tIn[i+1]-tIn[i]) + (QIn[i-1].Inverse()*QIn[i]).log()/(tIn[i]-tIn[i-1])) );
  }
  v[v.size()-1] = (QIn.back() * (QIn[QIn.size()-2].Inverse()*QIn.back()).log()) * (1.0/(tIn.back()-tIn[tIn.size()-2]));
  return v;
}

void WU::QuaternionInterpolator::SetControlPoints() {
  A[0] = Q[0];
  B[0] = Q[0]; // Even though this should never be used...
  double DtLast = xx[1]-xx[0];
  for(unsigned int i=1; i<A.size()-1; ++i) {
    // The following three formulas are only valid for unequally spaced time steps
    //c[i] = q[i] * exp(-0.25 * (log(q[i+1]/q[i]) + log(q[i-1]/q[i])) ); // from http://www.sjbrown.co.uk/2002/05/01/quaternions/, but I think it's wrong
    //c[i] = (-0.25 * ((q[i+1]/q[i]).log() + (q[i-1]/q[i]).log()) ).exp() * q[i]; // This should be equivalent to the following
    //c[i] = q[i] * ((-0.5/(xx[i+1]-xx[i-1])) * ((xx[i]-xx[i-1])*(q[i].Inverse()*q[i+1]).log() + (xx[i+1]-xx[i])*(q[i].Inverse()*q[i-1]).log()) ).exp();
    const double DtThis = xx[i+1]-xx[i];
    const Quaternion ExponentTerm = (Q[i].Inverse()*Q[i+1]).log()/DtThis - (Q[i-1].Inverse()*Q[i]).log()/DtLast;
    A[i] = Q[i] * ( (-DtThis/4.0) * ExponentTerm ).exp();
    B[i] = Q[i] * ( (-DtLast/4.0) * ExponentTerm ).exp();
    DtLast = DtThis;
  }
  A[A.size()-1] = Q[Q.size()-1]; // Even though this should never be used...
  B[B.size()-1] = Q[Q.size()-1];
}

Quaternion WU::QuaternionInterpolator::RawInterpolate(int jlo, double t) {
  if(t<=xx[0]) return Q[0];
  if(t>=xx[xx.size()-1]) return Q[Q.size()-1];
  const double tFrac = (t - xx[jlo])/(xx[jlo+1]-xx[jlo]);
  return WU::Squad(tFrac, Q[jlo], A[jlo], B[jlo+1], Q[jlo+1]);
}

double WU::QuaternionInterpolator::rawinterp(int jlo, double t) {
  // This just has to be here to override the empty default in the
  // base class.  The virtual function returns a double; we want to
  // return a Quaternion.
  return 0.;
}
