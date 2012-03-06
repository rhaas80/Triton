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



// Rotate all modes by the given Euler angles
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
  
  return *this;
}

Waveform& WaveformObjects::Waveform::RotateCoordinates(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma) {
  History() << "### this->RotateCoordinates(alpha, beta, gamma);\n#";
  RotatePhysicalSystem(-gamma, -beta, -alpha);
  return *this;
}

// Rotate all modes by the given Euler angles
Waveform& WaveformObjects::Waveform::RotatePhysicalSystem(const std::vector<WaveformUtilities::Quaternion>& Q) {
  if(Q.size()!=NTimes()) {
    cerr << "\nQ.size()=" << Q.size() << "  NTimes()=" << NTimes() << endl;
    throw("Mismatched sizes of vectors to Rotate.");
  }
  vector<double> alpha(NTimes()), beta(NTimes()), gamma(NTimes());
  for(unsigned int t=0; t<NTimes(); ++t) {
    const vector<double> ABC = Q[t].EulerAnglesZYZ();
    alpha[t] = ABC[0];
    beta[t] = ABC[1];
    gamma[t] = ABC[2];
  }
  
  return this -> RotatePhysicalSystem(alpha, beta, gamma);
}

Waveform& WaveformObjects::Waveform::RotateCoordinates(const std::vector<WaveformUtilities::Quaternion>& Q) {
  History() << "### this->RotateCoordinates(Q);\n#";
  RotatePhysicalSystem(WaveformUtilities::Conjugate(Q));
  return *this;
}
