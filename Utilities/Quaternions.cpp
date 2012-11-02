#include <cmath>
#include <limits>
#include <iostream>

#include "Quaternions.hpp"
#include "WaveformUtilities_ErrorCodes.hpp"
using WaveformUtilities::Quaternion;

// Note: Don't do 'using namespace std' because we don't want to
// confuse which log, exp, etc., is being used in any instance.
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

const Quaternion  one(1,0,0,0);
const Quaternion xHat(0,1,0,0);
const Quaternion yHat(0,0,1,0);
const Quaternion zHat(0,0,0,1);


#define Quaternion_Epsilon 1.0e-14


// // CHANGED:
// // I had to take the following out of the namespace
// A couple useful scalar functions
std::vector<double> ScalarDerivative(const std::vector<double>& f, const std::vector<double>& t);
std::vector<double> ScalarIntegral(const std::vector<double>& fdot, const std::vector<double>& t);


////////////////////////////////////
// Functions for the class itself //
////////////////////////////////////
/// Empty constructor (initialized to 0s).
WaveformUtilities::Quaternion::Quaternion()
  : w(0.0), x(0.0), y(0.0), z(0.0) { }

/// Copy constructor.
WaveformUtilities::Quaternion::Quaternion(const Quaternion& Q)
  : w(Q.w), x(Q.x), y(Q.y), z(Q.z) { }

/// Constructor from spherical coordinates.
WaveformUtilities::Quaternion::Quaternion(const double vartheta, const double varphi) {
  /// 
  /// \param vartheta Float representing the polar angle
  /// \param varphi Float representing the azimuthal angle
  /// 
  /// The unit Quaternion constructed in this way rotates the z axis
  /// onto the point given by the coordinates (vartheta, varphi).
  *this = WaveformUtilities::exp((varphi/2.)*zHat) * WaveformUtilities::exp((vartheta/2.)*yHat);
}

/// Constructor from Euler angles.
WaveformUtilities::Quaternion::Quaternion(const double alpha, const double beta, const double gamma) {
  /// 
  /// \param alpha First Euler angle
  /// \param beta Second Euler angle
  /// \param gamma Third Euler angle
  /// 
  /// The unit Quaternion constructed in this way corresponds to a
  /// rotation by the given Euler angles.  The convention used here is
  /// the z-y-z convention.  That is, the rotations occur about the
  /// fixed axes: first a rotation by gamma about the z axis, then a
  /// rotation by beta about the y axis, and finally a rotation by
  /// alpha about the z axis.
  *this = WaveformUtilities::exp((alpha/2.)*zHat) * WaveformUtilities::exp((beta/2.)*yHat) * WaveformUtilities::exp((gamma/2.)*zHat);
}

/// Constructor by components.
WaveformUtilities::Quaternion::Quaternion(const double w0, const double x0, const double y0, const double z0)
  : w(w0), x(x0), y(y0), z(z0)
{
  ///
  /// \param w0 Scalar component of Quaternion
  /// \param x0 First vector component of Quaternion
  /// \param y0 Second vector component of Quaternion
  /// \param z0 Third vector component of Quaternion
}

/// Constructor from vector.
WaveformUtilities::Quaternion::Quaternion(const std::vector<double>& q) {
  ///
  /// \param q Vector containing three or four components
  /// 
  /// If the input vector has three components, they are assumed to
  /// represent the vector components of the Quaternion, and the
  /// scalar component is set to zero.  If the input vector has four
  /// components, they are assumed to represent the four components of
  /// the Quaternion, with the 0 component being the scalar part.
  if(q.size()==3) {
    w = 0.0;
    x = q[0];
    y = q[1];
    z = q[2];
  } else if(q.size()==4) {
    w = q[0];
    x = q[1];
    y = q[2];
    z = q[3];
  } else {
    cerr << "\n\nq.size()=" << q.size() << endl;
    throw(WaveformUtilities_QuaternionVectorSizeNotUnderstood);
  }
}

/// Constructor from axis-angle.
WaveformUtilities::Quaternion::Quaternion(const double angle, const std::vector<double>& axis)
  : w(std::cos(angle/2.)), x(std::sin(angle/2.)*axis[0]), y(std::sin(angle/2.)*axis[1]), z(std::sin(angle/2.)*axis[2])
{
  /// 
  /// \param angle Single number giving the rotation angle
  /// \param axis Three-component vector (assumed to be normalized) giving the axis
  /// 
  /// This constructs a rotor (assuming 'axis' is normalized)
  /// corresponding to rotation about the given axis through the given
  /// angle.
}

/// Get component of Quaternion.
double WaveformUtilities::Quaternion::operator[](const unsigned int i) const {
  switch(i) {
  case 0:
    return w;
  case 1:
    return x;
  case 2:
    return y;
  case 3:
    return z;
  default:
    cerr << "\ni=" << i << " is not a possible quaternion index" << endl; 
    throw(WaveformUtilities_IndexOutOfBounds);
  }
}

/// Get reference to component of Quaternion.
double& WaveformUtilities::Quaternion::operator[](const unsigned int i) {
  /// Note: This is unavailable from python.
  switch(i) {
  case 0:
    return w;
  case 1:
    return x;
  case 2:
    return y;
  case 3:
    return z;
  default:
    cerr << "\ni=" << i << " is not a possible quaternion index" << endl; 
    throw(WaveformUtilities_IndexOutOfBounds);
  }
}

/// Quaternion multiplication.
Quaternion WaveformUtilities::Quaternion::operator*(const Quaternion& Q) const {
  return Quaternion(w*Q.w - x*Q.x - y*Q.y - z*Q.z,
		    w*Q.x + x*Q.w + y*Q.z - z*Q.y,
		    w*Q.y - x*Q.z + y*Q.w + z*Q.x,
		    w*Q.z + x*Q.y - y*Q.x + z*Q.w);
}

/// Return logarithm of Quaternion.
Quaternion WaveformUtilities::Quaternion::log() const {
  Quaternion Result;
  const double b = std::sqrt(x*x + y*y + z*z);
  if(std::abs(b) <= Quaternion_Epsilon*std::abs(w)) {
    if(w<0.0) {
      cerr << "Infinitely many solutions for log of a negative scalar: w=" << w << "." << endl;
      throw(WaveformUtilities_InfinitelyManySolutions);
    }
    Result.w = std::log(w);
  } else {
    const double v = std::atan2(b, w);
    const double f = v/b;
    Result.w = std::log(w/std::cos(v));
    Result.x = f*x;
    Result.y = f*y;
    Result.z = f*z;
  }
  return Result;
}

/// Return exponent of Quaternion.
Quaternion WaveformUtilities::Quaternion::exp() const {
  Quaternion Result;
  const double b = std::sqrt(x*x + y*y + z*z);
  if(std::abs(b)<=Quaternion_Epsilon*std::abs(w)) {
    Result.w = std::exp(w);
  } else {
    const double e = std::exp(w);
    const double f = std::sin(b)/b; // Note: b is never 0.0 at this point
    Result.w = e*std::cos(b);
    Result.x = e*f*x;
    Result.y = e*f*y;
    Result.z = e*f*z;
  }
  return Result;
}

/// Print the quaternion nicely to stream
std::ostream& WaveformUtilities::operator<<(std::ostream& out, const WaveformUtilities::Quaternion& q) {
  out << "[" << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << "]";
  return out;
}


/////////////////////
// Array operators //
/////////////////////
/// Centered differencing of vector of Quaternions.
std::vector<Quaternion> WaveformUtilities::CenteredDifferencing(const std::vector<Quaternion>& QIn, const std::vector<double>& tIn) {
  ///
  /// \param QIn Vector of Quaternions.
  /// \param tIn Vector of corresponding time steps.
  if(tIn.size() != QIn.size()) {
    cerr << "\n\ntIn.size()=" << tIn.size() << " != QIn.size()=" << QIn.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size = QIn.size();
  vector<Quaternion> QOut(Size);
  QOut[0] = (QIn[0] * WaveformUtilities::log(QIn[0].inverse()*QIn[1])) / (tIn[1]-tIn[0]);
  for(unsigned int i=1; i<Size-1; ++i) {
    QOut[i] = QIn[i] * (0.5 * (WaveformUtilities::log(QIn[i].inverse()*QIn[i+1])/(tIn[i+1]-tIn[i])
			       + WaveformUtilities::log(QIn[i-1].inverse()*QIn[i])/(tIn[i]-tIn[i-1])) );
  }
  QOut[Size-1] = (QIn[Size-1] * WaveformUtilities::log(QIn[Size-2].inverse()*QIn[Size-1])) / (tIn[Size-1]-tIn[Size-2]);
  return QOut;
}

/// Minimal-rotation version of the input frame.
std::vector<Quaternion> WaveformUtilities::MinimalRotation(const std::vector<Quaternion>& R, const std::vector<double>& T, const unsigned int NIterations) {
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
    const vector<Quaternion> Rdot = WaveformUtilities::CenteredDifferencing(Rreturn, T);
    for(unsigned int i=0; i<Size; ++i) {
      gammaover2dot[i] = ( Rreturn[i].conjugate() * Rdot[i] * z )[0];
    }
    const vector<double> gammaover2 = ScalarIntegral(gammaover2dot, T);
    for(unsigned int i=0; i<Size; ++i) {
      Rreturn[i] = Rreturn[i] * (gammaover2[i]*z).exp();
    }
  }
  cout << "\tFinished" << endl;
  return Rreturn;
}

/// Construct frame given the X and Y basis vectors of that frame.
std::vector<Quaternion> WaveformUtilities::FrameFromXY(const std::vector<Quaternion>& X, const std::vector<Quaternion>& Y) {
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
    const double beta = std::atan2(WaveformUtilities::dot(Ra*z*Ra.conjugate(), Y[k]),
				   WaveformUtilities::dot(Ra*y*Ra.conjugate(), Y[k]));
    R[k] = Ra * WaveformUtilities::exp((beta/2.0)*x);
  }
  return R;
}

/// Construct minimal-rotation frame from Z basis vector of that frame.
std::vector<Quaternion> WaveformUtilities::FrameFromZ(const std::vector<Quaternion>& Z, const std::vector<double>& T, const unsigned int NIterations) {
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
    R[k] = WaveformUtilities::sqrt(-Z[k]*z);
  }
  cout << "\tRemoving rotation:" << endl;
  return WaveformUtilities::MinimalRotation(WaveformUtilities::UnflipRotors(R), T, NIterations);
}

/// Remove sign-ambiguity of rotors.
std::vector<Quaternion> WaveformUtilities::UnflipRotors(const std::vector<Quaternion>& R, const double discont) {
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
std::vector<Quaternion> WaveformUtilities::RDelta(const std::vector<Quaternion>& R1, const std::vector<Quaternion>& R2, const unsigned int IndexOfFiducialTime) {
  ///
  /// \param R1 Vector of rotors
  /// \param R2 Vector of rotors
  /// \param IndexOfFiducialTime Integer index of time at which
  ///        difference is set to zero [default: 0]
  if(R1.size() != R2.size()) {
    cerr << "\n\nR1.size()=" << R1.size() << " != R2.size()=" << R2.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  if(R1.size()==0) {
    return vector<Quaternion>(0);
  }
  if(R1.size()<=IndexOfFiducialTime) {
    cerr << "\n\nR1.size()=" << R1.size() << " <= IndexOfFiducialTime=" << IndexOfFiducialTime << endl;
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

/// Squad interpolation of Quaternion time series.
std::vector<Quaternion> WaveformUtilities::Squad(const std::vector<Quaternion>& RIn, const std::vector<double>& tIn, const std::vector<double>& tOut) {
  ///
  /// \param RIn Vector of rotors
  /// \param tIn Vector of corresponding times
  /// \param tOut Vector of times to which RIn will be interpolated
  /// 
  /// This function implements a version of cubic-spline interpolation
  /// designed for unit quaternions, which delivers more accurate,
  /// smooth, and physical rotations than other forms of
  /// interpolation.
  if(RIn.size() != tIn.size()) {
    cerr << "\n\nRIn.size()=" << RIn.size() << " != tIn.size()=" << tIn.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> ROut(tOut.size());
  unsigned int iIn = 0;
  unsigned int iOut = 0;
  while(iOut<tOut.size() && iIn<tIn.size() && tIn[tIn.size()-1]>=tOut[iOut]) {
    double Dtim1, Dti, Dtip1;
    Quaternion Qim1, Qi, Qip1, Qip2, Ai, Bip1;
    while(iIn+1<tIn.size() && tIn[iIn+1]<tOut[iOut]) {
      iIn += 1;
    }
    if(iIn+1==tIn.size()) {
      cerr << "Time " << tOut[iOut] << " is beyond the end of the input data (time " << tIn.back() << ")." << endl;
      throw(WaveformUtilities_CannotExtrapolateQuaternions);
    }
    if(iIn==0) {
      Dti = tIn[iIn+1]-tIn[iIn];
      Dtim1 = Dti;
      Dtip1 = tIn[iIn+2]-tIn[iIn+1];
      Qim1 = RIn[iIn]*RIn[iIn+1].conjugate()*RIn[iIn];
      // Qim1 = RIn[iIn];
      Qi = RIn[iIn];
      Qip1 = RIn[iIn+1];
      Qip2 = RIn[iIn+2];
    } else if(iIn+2==tIn.size()) {
      Dtim1 = tIn[iIn]-tIn[iIn-1];
      Dti = tIn[iIn+1]-tIn[iIn];
      Dtip1 = Dti;
      Qim1 = RIn[iIn-1];
      Qi = RIn[iIn];
      Qip1 = RIn[iIn+1];
      Qip2 = RIn[iIn+1]*RIn[iIn].conjugate()*RIn[iIn+1];
      // Qip2 = RIn[iIn+1];
    } else {
      Dtim1 = tIn[iIn]-tIn[iIn-1];
      Dti = tIn[iIn+1]-tIn[iIn];
      Dtip1 = tIn[iIn+2]-tIn[iIn+1];
      Qim1 = RIn[iIn-1];
      Qi = RIn[iIn];
      Qip1 = RIn[iIn+1];
      Qip2 = RIn[iIn+2];
    }
    Ai = Qi * WaveformUtilities::exp((
		       WaveformUtilities::log(Qi.conjugate()*Qip1)
		       +(Dti/Dtim1)*WaveformUtilities::log(Qim1.conjugate()*Qi)
		       -2*WaveformUtilities::log(Qip1*Qi.conjugate())
		       )*0.25);
    Bip1 = Qip1 * WaveformUtilities::exp((
			   (Dti/Dtip1)*WaveformUtilities::log(Qip1.conjugate()*Qip2)
			   +WaveformUtilities::log(Qi.conjugate()*Qip1)
			   -2*WaveformUtilities::log(Qip1*Qi.conjugate())
			   )*-0.25);
    while(iOut<tOut.size() && tOut[iOut]<=tIn[iIn+1]) {
      const double taui = (tOut[iOut]-tIn[iIn]) / Dti;
      ROut[iOut] = WaveformUtilities::Slerp(2*taui*(1-taui),
			     WaveformUtilities::Slerp(taui, Qi, Qip1),
			     WaveformUtilities::Slerp(taui, Ai, Bip1));
      iOut += 1;
    }
    iIn += 1;
  }
  return ROut;
}

std::vector<Quaternion> WaveformUtilities::operator+(const double a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const double a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = a-Q[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const double a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const double a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = a/Q[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const std::vector<double>& a, const Quaternion& Q) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q+a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const std::vector<double>& a, const Quaternion& Q) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = a[i]-Q;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const std::vector<double>& a, const Quaternion& Q) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q*a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const std::vector<double>& a, const Quaternion& Q) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = a[i]/Q;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const std::vector<double>& a, const std::vector<Quaternion>& Q) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const std::vector<double>& a, const std::vector<Quaternion>& Q) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = a[i]-Q[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const std::vector<double>& a, const std::vector<Quaternion>& Q) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const std::vector<double>& a, const std::vector<Quaternion>& Q) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = a[i]/Q[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const Quaternion& a, const std::vector<Quaternion>& Q) {
  std::vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const Quaternion& a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]-a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const Quaternion& a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const Quaternion& a, const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]/a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const std::vector<Quaternion>& Q, const Quaternion& a) {
  std::vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const std::vector<Quaternion>& Q, const Quaternion& a) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]-a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const std::vector<Quaternion>& Q, const Quaternion& a) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const std::vector<Quaternion>& Q, const Quaternion& a) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]/a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const std::vector<Quaternion>& Q, const double a) {
  std::vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const std::vector<Quaternion>& Q, const double a) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]-a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const std::vector<Quaternion>& Q, const double a) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const std::vector<Quaternion>& Q, const double a) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]/a;
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const Quaternion& Q, const std::vector<double>& a) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q+a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const Quaternion& Q, const std::vector<double>& a) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q-a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const Quaternion& Q, const std::vector<double>& a) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q*a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const Quaternion& Q, const std::vector<double>& a) {
  vector<Quaternion> R(a.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q/a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const std::vector<Quaternion>& Q, const std::vector<double>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const std::vector<Quaternion>& Q, const std::vector<double>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]-a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const std::vector<Quaternion>& Q, const std::vector<double>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const std::vector<Quaternion>& Q, const std::vector<double>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]/a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator+(const std::vector<Quaternion>& Q, const std::vector<Quaternion>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]+a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator-(const std::vector<Quaternion>& Q, const std::vector<Quaternion>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]-a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator*(const std::vector<Quaternion>& Q, const std::vector<Quaternion>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]*a[i];
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::operator/(const std::vector<Quaternion>& Q, const std::vector<Quaternion>& a) {
  if(a.size() != Q.size()) {
    cerr << "\n\na.size()=" << a.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i]/a[i];
  }
  return R;
}


/////////////////////
// Array functions //
/////////////////////
std::vector<Quaternion> WaveformUtilities::pow(const std::vector<Quaternion>& Q, const double t) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].pow(t);
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::pow(const std::vector<Quaternion>& Q, const Quaternion& P) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].pow(P);
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::pow(const Quaternion& Q, const std::vector<double>& t) {
  vector<Quaternion> R(t.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q.pow(t[i]);
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::pow(const Quaternion& Q, const std::vector<Quaternion>& P) {
  vector<Quaternion> R(P.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q.pow(P[i]);
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::pow(const std::vector<Quaternion>& Q, const std::vector<double>& t) {
  if(t.size() != Q.size()) {
    cerr << "\n\nt.size()=" << t.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].pow(t[i]);
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::pow(const std::vector<Quaternion>& Q, const std::vector<Quaternion>& P) {
  if(P.size() != Q.size()) {
    cerr << "\n\nP.size()=" << P.size() << " != Q.size()=" << Q.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].pow(P[i]);
  }
  return R;
}
std::vector<double> WaveformUtilities::abs(const std::vector<Quaternion>& Q) {
  vector<double> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].abs();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::log(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].log();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::exp(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].exp();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::sqrt(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].sqrt();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::sqrtOfRotor(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].sqrtOfRotor();
  }
  return R;
}
std::vector<double> WaveformUtilities::angle(const std::vector<Quaternion>& Q) {
  vector<double> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].angle();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::inverse(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].inverse();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::conjugate(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].conjugate();
  }
  return R;
}
std::vector<Quaternion> WaveformUtilities::normalized(const std::vector<Quaternion>& Q) {
  vector<Quaternion> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].normalized();
  }
  return R;
}
std::vector<double> WaveformUtilities::normsquared(const std::vector<Quaternion>& Q) {
  vector<double> R(Q.size());
  for(unsigned int i=0; i<R.size(); ++i) {
    R[i] = Q[i].normsquared();
  }
  return R;
}

std::vector<Quaternion> WaveformUtilities::Quaternions(const std::vector<double>& vartheta, const std::vector<double>& varphi) {
  vector<Quaternion> Qs(vartheta.size());
  for(unsigned int i=0; i<Qs.size(); ++i) {
    Qs[i] = Quaternion(vartheta[i], varphi[i]);
  }
  return Qs;
}

std::vector<Quaternion> WaveformUtilities::Quaternions(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma) {
  vector<Quaternion> Qs(alpha.size());
  for(unsigned int i=0; i<Qs.size(); ++i) {
    Qs[i] = Quaternion(alpha[i], beta[i], gamma[i]);
  }
  return Qs;
}

std::vector<Quaternion> WaveformUtilities::Quaternions(const std::vector<double>& w0, const std::vector<double>& x0, const std::vector<double>& y0, const std::vector<double>& z0) {
  vector<Quaternion> Qs(w0.size());
  for(unsigned int i=0; i<Qs.size(); ++i) {
    Qs[i] = Quaternion(w0[i], x0[i], y0[i], z0[i]);
  }
  return Qs;
}

std::vector<Quaternion> WaveformUtilities::Quaternions(const std::vector<std::vector<double> >& q) {
  vector<Quaternion> Qs(q.size());
  for(unsigned int i=0; i<Qs.size(); ++i) {
    Qs[i] = Quaternion(q[i]);
  }
  return Qs;
}

std::vector<Quaternion> WaveformUtilities::Quaternions(const std::vector<double>& angle, const std::vector<std::vector<double> >& axis) {
  vector<Quaternion> Qs(angle.size());
  for(unsigned int i=0; i<Qs.size(); ++i) {
    Qs[i] = Quaternion(angle[i], axis[i]);
  }
  return Qs;
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



//////////////////////////////
// Scalar utility functions //
//////////////////////////////
std::vector<double> ScalarDerivative(const std::vector<double>& f, const std::vector<double>& t) {
  if(f.size() != t.size()) {
    cerr << "\n\nf.size()=" << f.size() << " != t.size()=" << t.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size=f.size();
  vector<double> dfdt(Size);
  dfdt[0] = (f[1]-f[0])/(t[1]-t[0]);
  for(unsigned int i=1; i<Size-1; ++i) {
    dfdt[i] = (f[i+1] - f[i-1])/(t[i+1] - t[i-1]);
  }
  dfdt[Size-1] = (f[Size-1] - f[Size-2])/(t[Size-1] - t[Size-2]);
  return dfdt;
}

std::vector<double> ScalarIntegral(const std::vector<double>& fdot, const std::vector<double>& t) {
  if(fdot.size() != t.size()) {
    cerr << "\n\nfdot.size()=" << fdot.size() << " != t.size()=" << t.size() << endl;
    throw(WaveformUtilities_VectorSizeMismatch);
  }
  const unsigned int Size=fdot.size();
  vector<double> f(Size);
  f[0] = 0.0;
  for(unsigned int i=1; i<Size; ++i) {
    f[i] = f[i-1] + (t[i]-t[i-1])*(fdot[i]+fdot[i-1])/2.0;
  }
  return f;
}
