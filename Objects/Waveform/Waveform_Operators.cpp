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

/// Set contents of this Waveform equal to the contents of another.
Waveform& WaveformObjects::Waveform::operator=(const Waveform& b) {
  // This call should not be explicitly recorded in the history
  SetHistory(b.HistoryStr());
  History().seekp(0, ios_base::end);
  TypeIndexRef() = b.TypeIndex();
  TimeScaleRef() = b.TimeScale();
  TRef() = b.T();
  RRef() = b.R();
  FrameRef() = b.Frame();
  LMRef() = b.LM();
  MagRef() = b.Mag();
  ArgRef() = b.Arg();
  return *this;
}

/// Subtract Waveforms and normalize.
Waveform WaveformObjects::Waveform::operator/(const Waveform& b) const {
  /// The two Waveforms are interpolated onto their intersection, then
  /// the second is subtracted from this Waveform, and the difference
  /// in magnitudes is normalized by the magnitude of the second
  /// Waveform.  [Note that subtraction in this case means subtraction
  /// of Mag and Arg data, rather than Real and Imaginary data.]  The
  /// two Waveforms are assumed to have identical (l,m) modes, and any
  /// alignment should be done before calling this function.
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
  c.AlignPhasesToTwoPi(d, 0.25);
  c.FrameRef() = RDelta(c.Frame(), d.Frame());
  c.MagRef() = (c.Mag() - d.Mag()) / d.Mag();
  c.ArgRef() = c.Arg()-d.Arg();
  return c;
}

/// Return a copy of the Waveform with only the requested mode.
Waveform WaveformObjects::Waveform::operator[](const unsigned int mode) const {
  /// All other data (history, typeIndex, timeScale, t, r, frame) are
  /// kept as they are.  Only the lm, mag, and arg data are reduced to
  /// the single mode requested.
  Waveform copy;
  copy.SetHistory(HistoryStr());
  copy.History().seekp(0, ios_base::end);
  copy.History() << "### this = this[" << mode << "];" << endl;
  copy.TypeIndexRef() = TypeIndex();
  copy.TimeScaleRef() = TimeScale();
  copy.TRef() = T();
  copy.RRef() = R();
  copy.FrameRef() = Frame();
  copy.LMRef().resize(1,2);
  copy.MagRef().resize(1,NTimes());
  copy.ArgRef().resize(1,NTimes());
  copy.LMRef(0) = LM(mode);
  copy.MagRef(0) = Mag(mode);
  copy.ArgRef(0) = Arg(mode);
  return copy;
}
