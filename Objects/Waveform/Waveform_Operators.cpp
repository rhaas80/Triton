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


Waveform& Waveform::operator=(const Waveform& b) {
  /// This call should not be recorded in the history
  SetHistory(b.HistoryStr());
  History().seekp(0, ios_base::end);
  TypeIndexRef() = b.TypeIndex();
  TimeScaleRef() = b.TimeScale();
  TRef() = b.T();
  RRef() = b.R();
  LMRef() = b.LM();
  MagRef() = b.Mag();
  ArgRef() = b.Arg();
  return *this;
}

Waveform Waveform::operator/(const Waveform& b) const {
  if(b.NModes() != NModes() || b.LM().RawData() != LM().RawData()) {
    throw("Trying to divide Waveform objects with mismatched LM data");
  }
  Waveform c = *this;
  Waveform d = b;
  c.History() << "### this->Waveform::operator/(const Waveform& b) const" << endl
	      << "###### Begin b.history:" << endl
	      << d.HistoryStr()
	    << "###### End b.history:" << endl;
  vector<double> NewTime = Intersection(c.T(), d.T(), 5e-8, -1e300);
  c.History() << "#";
  c.Interpolate(NewTime);
  c.History() << "#";
  d.Interpolate(NewTime);
  c.MagRef() = (c.Mag() - d.Mag()) / d.Mag();
  c.ArgRef() = c.Arg()-d.Arg();
  return c;
}

Waveform Waveform::operator[](const unsigned int mode) const {
  Waveform copy;
  copy.SetHistory(HistoryStr());
  copy.History().seekp(0, ios_base::end);
  copy.History() << "### this = this[" << mode << "];" << endl;
  copy.TypeIndexRef() = TypeIndex();
  copy.TimeScaleRef() = TimeScale();
  copy.TRef() = T();
  copy.RRef() = R();
  copy.LMRef().resize(1,2);
  copy.MagRef().resize(1,NTimes());
  copy.ArgRef().resize(1,NTimes());
  copy.LMRef(0) = LM(mode);
  copy.MagRef(0) = Mag(mode);
  copy.ArgRef(0) = Arg(mode);
  return copy;
}
