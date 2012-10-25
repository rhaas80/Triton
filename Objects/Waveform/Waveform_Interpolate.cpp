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


/// Interpolate Waveform to a new time vector.
Waveform& WaveformObjects::Waveform::Interpolate(const std::vector<double>& NewTime) {
  History() << "### this->Interpolate(const vector<double>& NewTime);" << endl;
  if(R().size()==NTimes()) {
    RRef() = WaveformUtilities::Interpolate(T(), R(), NewTime);
  }
  if(Frame().size()>1) {
    FrameRef() = Squad(Frame(), T(), NewTime);
  }
  WaveformUtilities::Matrix<double> Newmag(NModes(), NewTime.size());
  WaveformUtilities::Matrix<double> Newarg(NModes(), NewTime.size());
  //ORIENTATION!!! 4 following lines
  for(unsigned int i=0; i<NModes(); ++i) {
    Newmag[i] = WaveformUtilities::Interpolate(t, Mag(i), NewTime);
    Newarg[i] = WaveformUtilities::Interpolate(t, Arg(i), NewTime);
  }
  Newmag.swap(MagRef());
  Newarg.swap(ArgRef());
  TRef() = NewTime;
  return *this;
}

/// Interpolate Waveform to a new time vector, returning ExtrapVal when out of range.
Waveform& WaveformObjects::Waveform::Interpolate(const std::vector<double>& NewTime, const double ExtrapVal) {
  History() << "### this->Interpolate(const vector<double>& NewTime, " << ExtrapVal << ");" << endl;
  if(R().size()==NTimes()) {
    RRef() = WaveformUtilities::Interpolate(T(), R(), NewTime, R().back());
  }
  if(Frame().size()>1) {
    FrameRef() = Squad(Frame(), T(), NewTime);
  }
  WaveformUtilities::Matrix<double> Newmag(NModes(), NewTime.size());
  WaveformUtilities::Matrix<double> Newarg(NModes(), NewTime.size());
  //ORIENTATION!!! 4 following lines
  for(unsigned int i=0; i<NModes(); ++i) {
    Newmag[i] = WaveformUtilities::Interpolate(T(), Mag(i), NewTime, ExtrapVal);
    Newarg[i] = WaveformUtilities::Interpolate(T(), Arg(i), NewTime, Arg(i).back());
  }
  Newmag.swap(mag);
  Newarg.swap(arg);
  TRef() = NewTime;
  return *this;
}

/// Interpolate Waveform to a single time.
Waveform& WaveformObjects::Waveform::Interpolate(const double NewTime) {
  History() << "### this->Interpolate(" << setprecision(16) << NewTime << ");" << endl << "#";
  this->Interpolate(vector<double>(1, NewTime));
  return *this;
}

/// Interpolate Waveform to the time axis of another Waveform.
Waveform& WaveformObjects::Waveform::Interpolate(const Waveform& b) {
  History() << "### this->Interpolate(const Waveform& b);" << endl << "#";
  this->Interpolate(b.T());
  return *this;
}

/// Interpolate Waveform to the time axis of another Waveform, returning ExtrapVal when out of range.
Waveform& WaveformObjects::Waveform::Interpolate(const Waveform& b, const double ExtrapVal) {
  History() << "### this->Interpolate(const Waveform& b, " << ExtrapVal << ");" << endl << "#";
  this->Interpolate(b.T(), ExtrapVal);
  return *this;
}
