#include <limits>
#include <cmath>
#include <iostream>
#include "QuaternionInterpolation.hpp"
#include "WaveformUtilities_ErrorCodes.hpp"

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

/// Minimal-rotation version of the input frame.
std::vector<Quaternion> WU::MinimalRotation(const std::vector<Quaternion>& R, const std::vector<double>& T, const unsigned int NIterations) {
  ///
  /// \param R Vector of rotors.
  /// \param T Vector of corresponding time steps.
  /// \param NIterations Number of refinements [default: 5]
  /// 
  /// This function returns a copy of the input R, which takes the z
  /// axis to the same point as R, but adjusts the rotation about that
  /// new point by imposing the minimal-rotation condition.
  if(T.size() != R.size()) {
    cerr << "\n\nT.size()=" << T.size() << " != R.size()=" << R.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size=T.size();
  const Quaternion z(0,0,0,1);
  vector<double> gammaover2dot(Size);
  vector<Quaternion> Rreturn(R);
  for(unsigned int iteration=0; iteration<NIterations; ++iteration) {
    cout << "\t\tIteration " << iteration << endl;
    const vector<Quaternion> Rdot = WU::CenteredDifferencing(Rreturn, T);
    for(unsigned int i=0; i<Size; ++i) {
      gammaover2dot[i] = ( Rreturn[i].conjugate() * Rdot[i] * z )[0];
    }
    const vector<double> gammaover2 = WU::ScalarIntegral(gammaover2dot, T);
    for(unsigned int i=0; i<Size; ++i) {
      Rreturn[i] = Rreturn[i] * (gammaover2[i]*z).exp();
    }
  }
  cout << "\tFinished" << endl;
  return Rreturn;
}

/// Construct frame given the X and Y basis vectors of that frame.
std::vector<Quaternion> WU::FrameFromXY(const std::vector<Quaternion>& X, const std::vector<Quaternion>& Y) {
  ///
  /// \param X Vector of Quaternions
  /// \param Y Vector of Quaternions
  ///
  /// The input parameters are Quaternions, assumed to be pure unit
  /// vectors, representing the X and Y basis vectors of the frame at
  /// each instant of time.  The returned vector of rotors will rotate
  /// the stationary frame's (x,y,z) vectors into the new frame's
  /// (X,Y,Z) vectors.
  if(X.size() != Y.size()) {
    cerr << "\n\nX.size()=" << X.size() << " != Y.size()=" << Y.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size=X.size();
  const Quaternion x(0,1,0,0);
  const Quaternion y(0,0,1,0);
  const Quaternion z(0,0,0,1);
  vector<Quaternion> R(Size);
  for(unsigned int k=0; k<Size; ++k) {
    const Quaternion Ra = sqrtOfRotor(-X[k]*x);
    const double beta = std::atan2(WU::dot(Ra*z*Ra.conjugate(), Y[k]),
				   WU::dot(Ra*y*Ra.conjugate(), Y[k]));
    R[k] = Ra * WU::exp((beta/2.0)*x);
  }
  return R;
}

/// Construct minimal-rotation frame from Z basis vector of that frame.
std::vector<Quaternion> WU::FrameFromZ(const std::vector<Quaternion>& Z, const std::vector<double>& T, const unsigned int NIterations) {
  ///
  /// \param Z Vector of Quaternions
  /// \param T Vector of corresponding times
  /// \param NIterations Number of refinements [default: 5]
  /// 
  /// The input vector of Quaternions, assumed to be pure unit
  /// vectors, represent the Z basis vectors of the frame at each
  /// instant of time.  The returned vector of rotors will rotate the
  /// stationary frame's (x,y,z) vectors into the new frame's (X,Y,Z)
  /// vectors.  The X and Y vectors are deduced by imposing the
  /// minimal-rotation condition.
  if(Z.size() != T.size()) {
    cerr << "\n\nZ.size()=" << Z.size() << " != T.size()=" << T.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size=Z.size();
  const Quaternion z(0,0,0,1);
  vector<Quaternion> R(Size);
  cout << "\tComputing basic frame" << endl;
  for(unsigned int k=0; k<Size; ++k) {
    R[k] = WU::sqrt(-Z[k]*z);
  }
  cout << "\tRemoving rotation:" << endl;
  return WU::MinimalRotation(WU::UnflipRotors(R), T, NIterations);
}

/// Remove sign-ambiguity of rotors.
std::vector<Quaternion> WU::UnflipRotors(const std::vector<Quaternion>& R, const double discont) {
  ///
  /// \param R Vector of rotors
  /// \param discont Acceptable discontinuity [default: sqrt(2)]
  /// 
  /// Because of the two-sided nature of quaternion rotations, the
  /// sign of a rotor may be undetermined in many cases.
  /// Discontinuous flips in that sign for rotor-valued functions of
  /// time can cause significant problems.  This function removes
  /// those flips by ensuring that the output rotors at successive
  /// instants are within 'discont' of each other.
  vector<Quaternion> Q(R.size());
  Q[0] = R[0];
  for(unsigned int i=1; i<R.size(); ++i) {
    if((R[i]-Q[i-1]).abs() > discont) {
      Q[i] = -R[i];
    } else {
      Q[i] = R[i];
    }
  }
  return Q;
}

/// Difference between frame rotors
std::vector<Quaternion> WU::RDelta(const std::vector<Quaternion>& R1, const std::vector<Quaternion>& R2, const unsigned int IndexOfFiducialTime) {
  ///
  /// \param R1 Vector of rotors
  /// \param R2 Vector of rotors
  /// \param IndexOfFiducialTime Integer index of time at which
  ///        difference is set to zero [default: 0]
  if(R1.size() != R2.size()) {
    cerr << "\n\nR1.size()=" << R1.size() << " != R2.size()=" << R2.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size=R1.size();
  vector<Quaternion> Rd(Size);
  const Quaternion Offset = R1[IndexOfFiducialTime].conjugate() * R2[IndexOfFiducialTime];
  for(unsigned int i=0; i<Size; ++i) {
    Rd[i] = R1[i] * Offset * R2[i].conjugate();
  }
  return Rd;
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
