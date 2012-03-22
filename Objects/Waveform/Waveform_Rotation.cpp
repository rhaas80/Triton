#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

#include "../Waveform.hpp"

#include "Interpolate.hpp"
#include "Minimize.hpp"
#include "FileIO.hpp"
#include "SWSHs.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Units.hpp"
#include "PostNewtonian.hpp"
#include "WignerDMatrix.hpp"
#include "WignerDMatrix_Q.hpp"
#include "Quaternions.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::setprecision;
using std::stringstream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::min;
using std::max;
using std::ios_base;



/// Rotate all modes by the given Euler angles.
Waveform& WaveformObjects::Waveform::RotatePhysicalSystem(const double alpha, const double beta, const double gamma) {
  // Make sure the ordering is as expected (could program something to make this unecessary...)
  {
    unsigned int mode=0;
    for(int l=2; ; ++l) {
      if(mode>=NModes()) { break; }
      for(int m=-l; m<=l; ++m) {
	if(mode>=NModes()) { break; }
	if(L(mode)!=l) {
	  std::cerr << "\nmode=" << mode << "  L(mode)=" << L(mode) << "  l=" << l << std::endl;
	  throw("Unrecognized mode ordering in this Waveform.");
	}
	if(M(mode)!=m) {
	  std::cerr << "\nmode=" << mode << "  M(mode)=" << M(mode) << "  m=" << m << std::endl;
	  throw("Unrecognized mode ordering in this Waveform.");
	}
	mode++;
      }
    }
  }
  
  History() << "### this->RotatePhysicalSystem(" << alpha << ", " << beta << ", " << gamma << ");" << endl;
  
  // Loop through each mode and do the rotation
  {
    unsigned int mode=1;
    for(int l=2; l<int(NModes()); ++l) {
      if(NModes()<mode) { break; }
      // Construct the D matrices
      Matrix<double> DRe(2*l+1, 2*l+1);
      Matrix<double> DIm(2*l+1, 2*l+1);
      for(int m=-l; m<=l; ++m) {
	for(int mp=-l; mp<=l; ++mp) {
	  double mag, arg;
	  WignerD(l, mp, m, alpha, beta, gamma, mag, arg);
	  DRe[mp+l][m+l] = mag*cos(arg);
	  DIm[mp+l][m+l] = mag*sin(arg);
	}
      }
      // Loop through each time step
      for(unsigned int t=0; t<NTimes(); ++t) {
	vector<double> ReData(2*l+1);
	vector<double> ImData(2*l+1);
	for(int mp=-l; mp<=l; ++mp) {
	  // Save the data at this time step
	  ReData[mp+l] = Mag((l*l-4)+(mp+l), t)*cos(Arg((l*l-4)+(mp+l), t));
	  ImData[mp+l] = Mag((l*l-4)+(mp+l), t)*sin(Arg((l*l-4)+(mp+l), t));
	}
	for(int m=-l; m<=l; ++m) {
	  MagRef((l*l-4)+(m+l), t) = 0.0;
	  ArgRef((l*l-4)+(m+l), t) = 0.0;
	  for(int mp=-l; mp<=l; ++mp) {
	    // Save the data at this time step
	    // NB: Mag and Arg are temporarily storing Re and Im data!
	    MagRef((l*l-4)+(m+l), t) += DRe[mp+l][m+l]*ReData[mp+l] - DIm[mp+l][m+l]*ImData[mp+l];
	    ArgRef((l*l-4)+(m+l), t) += DIm[mp+l][m+l]*ReData[mp+l] + DRe[mp+l][m+l]*ImData[mp+l];
	  }
	}
      }
      mode += 2*l+1;
    }
    // Convert back to MagArg form
    for(unsigned int mode=0; mode<NModes(); ++mode) {
      vector<double> Re = Mag(mode);
      vector<double> Im = Arg(mode);
      MagArg(Re, Im, MagRef(mode), ArgRef(mode));
    }
  }
  
  // Record the change of frame
  if(frame.size()==0) { // set frame data equal to input data
    frame.push_back(Quaternion(alpha, beta, gamma));
  } else if(frame.size()==1) { // (pre-)multiply frame constant by input rotation
    frame[0] = Quaternion(alpha, beta, gamma) * frame[0];
  } else { //(pre-) multiply frame data by input rotation
    frame = Quaternion(alpha, beta, gamma) * frame;
  }
  
  return *this;
}

Waveform& WaveformObjects::Waveform::RotateCoordinates(const double alpha, const double beta, const double gamma) {
  History() << "### this->RotateCoordinates(" << alpha << ", " << beta << ", " << gamma << ");\n#";
  RotatePhysicalSystem(-gamma, -beta, -alpha);
  return *this;
}

// Rotate all modes by the given Euler angles
Waveform& WaveformObjects::Waveform::RotatePhysicalSystem(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma) {
  if(alpha.size()!=NTimes()) {
    cerr << "\nalpha.size()=" << alpha.size() << "  NTimes()=" << NTimes() << endl;
    throw("Mismatched sizes of vectors to Rotate.");
  }
  if(beta.size()!=NTimes()) {
    cerr << "\nbeta.size()=" << beta.size() << "  NTimes()=" << NTimes() << endl;
    throw("Mismatched sizes of vectors to Rotate.");
  }
  if(gamma.size()!=NTimes()) {
    cerr << "\ngamma.size()=" << gamma.size() << "  NTimes()=" << NTimes() << endl;
    throw("Mismatched sizes of vectors to Rotate.");
  }
  
  // Make sure the ordering is as expected (could program something to make this unecessary...)
  {
    unsigned int mode=0;
    for(int l=2; ; ++l) {
      if(mode>=NModes()) { break; }
      for(int m=-l; m<=l; ++m) {
	if(mode>=NModes()) { break; }
	if(L(mode)!=l) {
	  std::cerr << "\nmode=" << mode << "  L(mode)=" << L(mode) << "  l=" << l << std::endl;
	  throw("Unrecognized mode ordering in this Waveform.");
	}
	if(M(mode)!=m) {
	  std::cerr << "\nmode=" << mode << "  M(mode)=" << M(mode) << "  m=" << m << std::endl;
	  throw("Unrecognized mode ordering in this Waveform.");
	}
	mode++;
      }
    }
  }
  
  History() << "### this->RotatePhysicalSystem(alpha, beta, gamma);" << endl;
  
  // Loop through each mode and do the rotation
  {
    unsigned int mode=1;
    for(int l=2; l<int(NModes()); ++l) {
      if(NModes()<mode) { break; }
      // Construct the D matrices
      Matrix<double> DRe(2*l+1, 2*l+1);
      Matrix<double> DIm(2*l+1, 2*l+1);
      // Loop through each time step
      for(unsigned int t=0; t<NTimes(); ++t) {
	for(int m=-l; m<=l; ++m) {
	  for(int mp=-l; mp<=l; ++mp) {
	    double mag, arg;
	    WignerD(l, mp, m, alpha[t], beta[t], gamma[t], mag, arg);
	    DRe[mp+l][m+l] = mag*cos(arg);
	    DIm[mp+l][m+l] = mag*sin(arg);
	  }
	}
	vector<double> ReData(2*l+1);
	vector<double> ImData(2*l+1);
	for(int mp=-l; mp<=l; ++mp) {
	  // Save the data at this time step
	  ReData[mp+l] = Mag((l*l-4)+(mp+l), t)*cos(Arg((l*l-4)+(mp+l), t));
	  ImData[mp+l] = Mag((l*l-4)+(mp+l), t)*sin(Arg((l*l-4)+(mp+l), t));
	}
	for(int m=-l; m<=l; ++m) {
	  MagRef((l*l-4)+(m+l), t) = 0.0;
	  ArgRef((l*l-4)+(m+l), t) = 0.0;
	  for(int mp=-l; mp<=l; ++mp) {
	    // Save the data at this time step
	    // NB: Mag and Arg are temporarily storing Re and Im data!
	    MagRef((l*l-4)+(m+l), t) += DRe[mp+l][m+l]*ReData[mp+l] - DIm[mp+l][m+l]*ImData[mp+l];
	    ArgRef((l*l-4)+(m+l), t) += DIm[mp+l][m+l]*ReData[mp+l] + DRe[mp+l][m+l]*ImData[mp+l];
	  }
	}
      }
      mode += 2*l+1;
    }
    // Convert back to MagArg form
    for(unsigned int mode=0; mode<NModes(); ++mode) {
      vector<double> Re = Mag(mode);
      vector<double> Im = Arg(mode);
      MagArg(Re, Im, MagRef(mode), ArgRef(mode));
    }
  }
  
  // Record the change of frame
  if(frame.size()==0) { // set frame data equal to input data
    frame = Quaternions(alpha, beta, gamma);
  } else if(frame.size()==1) { // (pre-)multiply frame constant by input rotation
    frame = Quaternions(alpha, beta, gamma) * frame[0];
  } else { //(pre-) multiply frame data by input rotation
    frame = Quaternions(alpha, beta, gamma) * frame;
  }
  
  return *this;
}

Waveform& WaveformObjects::Waveform::RotateCoordinates(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma) {
  History() << "### this->RotateCoordinates(alpha, beta, gamma);\n#";
  RotatePhysicalSystem(-gamma, -beta, -alpha);
  return *this;
}

/// Rotate all modes by the given quaternion data.
Waveform& WaveformObjects::Waveform::RotatePhysicalSystem(const std::vector<WaveformUtilities::Quaternion>& Q) {
  throw("BAAHHH!");
  /// This rotates the physical system, leaving the coordinates in
  /// place -- which is just the opposite rotation compared to
  /// RotateCoordinates.  One way of thinking about this is that
  /// whatever physical point is at the tip of the zHat axis is
  /// rotated to the point Q*zHat*Qbar.
  
  if(Q.size()!=NTimes()) {
    cerr << "\nQ.size()=" << Q.size() << "  NTimes()=" << NTimes() << endl;
    throw("Mismatched sizes of vectors to RotatePhysicalSystem.");
  }
  
  History() << "### this->RotatePhysicalSystem(Q); // const vector<Quaternion>& Q" << endl;
  
  // Loop through each mode and do the rotation
  {
    unsigned int mode=1;
    for(int l=2; l<int(NModes()); ++l) {
      if(NModes()<mode) { break; }
      // Use a vector of mode indices, in case the modes are out of
      // order.  This still assumes that we have each l from l=2 up to
      // some l_max, but it's better than assuming that plus assuming
      // that everything is in order.
      vector<unsigned int> ModeIndices(2*l+1);
      for(int m=-l, i=0; m<=l; ++m, ++i) {
	try {
	  ModeIndices[i] = FindModeIndex(l, m);
	} catch(char* thrown) {
	  cerr << thrown << endl;
	  cerr << RowFormat(LM()) << endl;
	  throw("Incomplete mode information in Waveform; cannot rotate.");
	}
      }
      // Construct the D matrices
      Matrix<WignerDMatrix_Q> Ds(2*l+1, 2*l+1);
      for(int m=-l; m<=l; ++m) {
	for(int mp=-l; mp<=l; ++mp) {
	  Ds[mp+l][m+l].SetElement(l, mp, m);
	}
      }
      Matrix<double> DRe(2*l+1, 2*l+1);
      Matrix<double> DIm(2*l+1, 2*l+1);
      // Loop through each time step
      for(unsigned int t=0; t<NTimes(); ++t) {
	// Get the Wigner D matrix data at this time step
	for(int m=-l; m<=l; ++m) {
	  for(int mp=-l; mp<=l; ++mp) {
	    Ds[mp+l][m+l].SetQuaternion(Q[t]);
	    Ds[mp+l][m+l].ValueReIm(DRe[mp+l][m+l], DIm[mp+l][m+l]);
	  }
	}
	vector<double> ReData(2*l+1);
	vector<double> ImData(2*l+1);
	for(int mp=-l, i=0; mp<=l; ++mp, ++i) {
	  // Calculate the data for all m' modes at this time step
	  ReData[mp+l] = Mag(ModeIndices[i], t)*cos(Arg(ModeIndices[i], t));
	  ImData[mp+l] = Mag(ModeIndices[i], t)*sin(Arg(ModeIndices[i], t));
	}
	for(int m=-l, i=0; m<=l; ++m, ++i) {
	  MagRef(ModeIndices[i], t) = 0.0;
	  ArgRef(ModeIndices[i], t) = 0.0;
	  for(int mp=-l; mp<=l; ++mp) {
	    // Save the data at this time step
	    // NB: Mag and Arg are temporarily storing Re and Im data!
	    MagRef(ModeIndices[i], t) += DRe[mp+l][m+l]*ReData[mp+l] - DIm[mp+l][m+l]*ImData[mp+l];
	    ArgRef(ModeIndices[i], t) += DIm[mp+l][m+l]*ReData[mp+l] + DRe[mp+l][m+l]*ImData[mp+l];
	  }
	}
      }
      mode += 2*l+1;
    }
    // Convert back to MagArg form
    for(unsigned int mode=0; mode<NModes(); ++mode) {
      vector<double> Re = Mag(mode);
      vector<double> Im = Arg(mode);
      MagArg(Re, Im, MagRef(mode), ArgRef(mode));
    }
  }
  
  // Record the change of frame
  if(frame.size()==0) { // set frame data equal to input data
    frame = Q;
  } else if(frame.size()==1) { // (pre-)multiply frame constant by input rotation
    frame = Q * frame[0];
  } else { //(pre-) multiply frame data by input rotation
    frame = Q * frame;
  }
  
  return *this;
}

/// Rotate all modes by the given quaternion data.
Waveform& WaveformObjects::Waveform::RotatePhysicalSystem(const WaveformUtilities::Quaternion& Q) {
  /// This rotates the physical system, leaving the coordinates in
  /// place -- which is just the opposite rotation compared to
  /// RotateCoordinates.  One way of thinking about this is that
  /// whatever physical point is at the tip of the zHat axis is
  /// rotated to the point Q*zHat*Qbar.
  
  History() << "### this->RotatePhysicalSystem(Q); // const Quaternion& Q" << endl;
  
  // Loop through each mode and do the rotation
  {
    unsigned int mode=1;
    for(int l=2; l<int(NModes()); ++l) {
      if(NModes()<mode) { break; }
      // Use a vector of mode indices, in case the modes are out of
      // order.  This still assumes that we have each l from l=2 up to
      // some l_max, but it's better than assuming that plus assuming
      // that everything is in order.
      vector<int> ModeIndices(2*l+1);
      for(int m=-l, i=0; m<=l; ++m, ++i) {
	try {
	  ModeIndices[i] = FindModeIndex(l, m);
	} catch(char* thrown) {
	  cerr << thrown << endl;
	  cerr << RowFormat(LM()) << endl;
	  throw("Incomplete mode information in Waveform; cannot rotate.");
	}
      }
      cout << "Mode Indices: " << RowFormat(ModeIndices) << endl;
      // Construct the D matrices
      Matrix<WignerDMatrix_Q> Ds(2*l+1, 2*l+1);
      Matrix<double> DMag(2*l+1, 2*l+1);
      Matrix<double> DArg(2*l+1, 2*l+1);
      for(int m=-l; m<=l; ++m) {
	for(int mp=-l; mp<=l; ++mp) {
	  Ds[mp+l][m+l].SetElement(l, mp, m);
	  Ds[mp+l][m+l].SetQuaternion(Q);
	  Ds[mp+l][m+l].Value(DMag[mp+l][m+l], DArg[mp+l][m+l]);
	}
      }
      cout << "D^{(" << l << ")} = \n[\n";
      for(int mp=-l; mp<=l; ++mp) {
	cout << " [ ";
	for(int m=-l; m<l; ++m) {
	  cout << "(" << DMag[mp+l][m+l] << "," << DArg[mp+l][m+l] << "), ";
	}
	cout << "(" << DMag[mp+l][2*l] << "," << DArg[mp+l][2*l] << ") ]";
	if(mp==l) { cout << ","; }
	cout << endl;
      }
      cout << "]" << endl;
      // Loop through each time step
      for(unsigned int t=0; t<NTimes(); ++t) {
	vector<double> MagData(2*l+1);
	vector<double> ArgData(2*l+1);
	for(int mp=-l, i=0; mp<=l; ++mp, ++i) {
	  // Store the data for all m' modes at this time step
	  MagData[mp+l] = Mag(ModeIndices[i], t);
	  ArgData[mp+l] = Arg(ModeIndices[i], t);
	}
	for(int m=-l, i=0; m<=l; ++m, ++i) {
	  MagRef(ModeIndices[i], t) = 0.0;
	  ArgRef(ModeIndices[i], t) = 0.0;
	  for(int mp=-l; mp<=l; ++mp) {
	    // Compute the addition to the data at this time step
	    const double Mag = DMag[mp+l][m+l]*MagData[mp+l];
	    const double Arg = DArg[mp+l][m+l]+ArgData[mp+l];
	    // NB: Mag and Arg are temporarily storing Re and Im data!
	    MagRef(ModeIndices[i], t) += Mag*cos(Arg);
	    ArgRef(ModeIndices[i], t) += Mag*sin(Arg);
	  }
	}
      }
      mode += 2*l+1;
    }
    // Convert back to MagArg form
    for(unsigned int mode=0; mode<NModes(); ++mode) {
      vector<double> Re = Mag(mode);
      vector<double> Im = Arg(mode);
      MagArg(Re, Im, MagRef(mode), ArgRef(mode));
    }
  }
  
  // Record the change of frame
  if(frame.size()==0) { // set frame data equal to input data
    frame = vector<Quaternion>(1,Q);
  } else if(frame.size()==1) { // (pre-)multiply frame constant by input rotation
    frame[0] = Q * frame[0];
  } else { //(pre-) multiply frame data by input rotation
    frame = Q * frame;
  }
  
  return *this;
}

/// Rotate all modes by the given quaternion data.
Waveform& WaveformObjects::Waveform::RotateCoordinates(const std::vector<WaveformUtilities::Quaternion>& Q) {
  /// This rotates the coordinates, leaving the physical system in
  /// place -- which is just the opposite rotation compared to
  /// RotatePhysicalSystem.  One way of thinking about this is that
  /// the zHat axis is rotated to the point Q*zHat*Qbar, while the
  /// physical point that was located there is left in place.  In the
  /// new coordinates, that physical point is at Qbar*zHat*Q.
  History() << "### this->RotateCoordinates(Q);\n#";
  return this->RotatePhysicalSystem(WaveformUtilities::Conjugate(Q));
}

/// Rotate all modes by the given quaternion.
Waveform& WaveformObjects::Waveform::RotateCoordinates(const WaveformUtilities::Quaternion& Q) {
  /// This rotates the coordinates, leaving the physical system in
  /// place -- which is just the opposite rotation compared to
  /// RotatePhysicalSystem.  One way of thinking about this is that
  /// the zHat axis is rotated to the point Q*zHat*Qbar, while the
  /// physical point that was located there is left in place.  In the
  /// new coordinates, that physical point is at Qbar*zHat*Q.
  History() << "### this->RotateCoordinates(Q);\n#";
  return this->RotatePhysicalSystem(Q.Conjugate());
}
