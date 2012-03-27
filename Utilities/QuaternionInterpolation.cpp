#include <limits>
#include <cmath>
#include <iostream>
#include "QuaternionInterpolation.hpp"

using namespace std;
namespace WU = WaveformUtilities;
using WU::Quaternion;

Quaternion WU::Slerp(double t, const Quaternion& q0, const Quaternion& q1, bool shortest) {
  double o,so,a,b;
  bool neg_q1 = false;   // Does q1 have to be negated (so that the shortest path is taken)?
  
  double ca = q0.Dot(q1);
  if (shortest && ca<0) {
    ca = -ca;
    neg_q1 = true;
  }
  o = acos(ca);
  so = sin(o);
  
  if (abs(so)<numeric_limits<double>::epsilon()) {
    return q0;
  }
  
  a = sin(o*(1.0-t)) / so;
  b = sin(o*t) / so;
  if (neg_q1) {
    return q0*a - q1*b;
  } else {
    return q0*a + q1*b;
  }
}

Quaternion WU::Squad(double t, const Quaternion& q0, const Quaternion& c0, const Quaternion& c1, const Quaternion& q1) {
  return WU::Slerp(2*t*(1.0-t), WU::Slerp(t,q0,q1), WU::Slerp(t,c0,c1));
}

vector<Quaternion> WU::Squad(const vector<double>& tIn, const vector<Quaternion>& qIn, const vector<double>& tOut) {
  vector<Quaternion> qOut(tOut.size());
  QuaternionInterpolator qInterp(tIn, qIn);
  for(unsigned int i=0; i<qOut.size(); ++i) {
    qOut[i] = qInterp.Interpolate(tOut[i]);
  }
  return qOut;
}

vector<Quaternion> WU::QuaternionInterpolator::SetControlPoints(const vector<Quaternion>& q) {
  vector<Quaternion> c(q.size());
  c[0] = q[0];
  std::cerr << "Warning: The squad interpolation control points may be incorrectly set at: " << __FILE__ << ": " << __LINE__+2 << std::endl;
  for(unsigned int i=1; i<c.size()-1; ++i) {
    //c[i] = q[i] * exp(-0.25 * (log(q[i+1]/q[i]) + log(q[i-1]/q[i])) ); // from http://www.sjbrown.co.uk/2002/05/01/quaternions/, but I think it's wrong
    c[i] = (-0.25 * ((q[i+1]/q[i]).log() + (q[i-1]/q[i]).log()) ).exp() * q[i];
    //c[i] = exp(-0.25 * q[i] * (WU::log(q[i+1]/q[i]) - WU::log(q[i]/q[i-1])) / q[i] ) * q[i];
  }
  c[c.size()-1] = q[q.size()-1];
  return c;
}

Quaternion WU::QuaternionInterpolator::RawInterpolate(int jlo, double t) {
  if(t<=xx[0]) return q[0];
  if(t>=xx[xx.size()-1]) return q[q.size()-1];
  const double tFrac = (t - xx[jlo])/(xx[jlo+1]-xx[jlo]);
  return WU::Squad(tFrac, q[jlo], c[jlo], c[jlo+1], q[jlo+1]);
}

double WU::QuaternionInterpolator::rawinterp(int jlo, double t) {
  // This just has to be here to override the empty default in the
  // base class.  The virtual function returns a double; we want to
  // return a Quaternion.
  return 0.;
}
