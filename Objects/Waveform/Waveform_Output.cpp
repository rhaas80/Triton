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



/// Returns true if the input (x,y) data can be interpolated
/// between indices I0 and I1 to within a tolerance of Tol
/// at the midpoint between I0 and I1.
bool MinimalGrid_Check(const vector<double>& x, const vector<double>& y,
	   const int I0, const int I1, const double Tol)
{
  if(I1==I0+1) { return true; }
  int IMid = ((I0+I1) >> 1); // = floor(avg(I0+I1))
  if(fabs(y[I0] + (x[IMid]-x[I0])*(y[I1]-y[I0])/(x[I1]-x[I0]) - y[IMid]) > Tol) {
    return false; // Interval is not fine enough
  }
  return true; // Interval is fine enough
}


/// Given data (t,arg), some initial index I0, and a guess
/// for I1, this function outputs the optimal index I1 so
/// that (t,arg) can be interpolated between I0 and I1 to
/// just within argTol of the full input data set.
/// Compare Numerical Recipes's 'hunt' function; this is
/// basically a hunt for that optimal index.
int MinimalGrid_Hunt(const vector<double>& t, const vector<double>& arg,
		    const double argTol, const int I0, const int I1)
{
  int Inc=1, I1lo = I1, I1hi=I1+1;
  
  // Bracket the optimal I1 between I1lo and I1hi
  if( MinimalGrid_Check(t, arg, I0, I1lo, argTol) ) {
    while( MinimalGrid_Check(t, arg, I0, I1hi, argTol) ) {
      I1lo = I1hi;
      Inc *= 2;
      I1hi += Inc;
      if(I1hi>int(t.size())) {
	I1hi = t.size();
	break;
      }
    }
  } else {
    if(I1lo<=I0+2) {
      return I0+2;
    }
    I1hi = I1lo;
    I1lo -= 1;
    while( ! MinimalGrid_Check(t, arg, I0, I1lo, argTol) ) {
      I1hi = I1lo;
      Inc *= 2;
      if(Inc > I1hi) {
	I1lo = I0+2;
	break;
      } else {
	I1lo = I1hi-Inc;
      }
    }
  }
  
  // Now use bisection between I1lo and I1hi
  if(I1hi==I1lo) { I1hi++; }
  while(I1hi-I1lo != 1) {
    int I1m=((I1hi+I1lo)>>1);
    if( MinimalGrid_Check(t, arg, I0, I1m, argTol) ) {
      I1lo = I1m;
    } else {
      I1hi = I1m;
    }
  }
  
  return I1lo;
}


Waveform& WaveformObjects::Waveform::MinimalGrid(const double magTol, const double argTol) {
  /// The objective here will be to create a vector of bool's, the same
  /// length as t.  The truth value will correspond to whether or not
  /// that time step should be kept in the final data.  We begin by
  /// assuming that the very first and last steps should obviously be
  /// kept.  Then, there are two stages.  First is a coarse stage,
  /// which steps through the data making intervals small enough to
  /// reproduce the arg data at the interval's midpoint to within
  /// argTol, but no smaller.  Second is the finer stage, which goes
  /// through each interval, checking that every single point in the
  /// input data can be reproduced to within argTol and magTol.  If
  /// that's not true, the interval is split evenly into two, and the
  /// algorithm proceeds with the earlier interval.  Finally, the input
  /// t, mag, and arg vectors are replaced by the smaller vectors given
  /// by our vector of bool's.
  
  // We can only have one mode here
  if(NModes()>1) {
    cerr << "\nThis function is only designed to work on one mode at a time."
	 << "There are " << NModes() << " modes in this data." << endl;
    Throw1WithMessage("Too many modes");
  }
  
  unsigned int I0 = 0;
  unsigned int I1 = ((NTimes()-1) >> 1); // = midpoint of the input data set
  unsigned int NumPoints = 2;
  vector<bool> Tbool(NTimes(), false);
  Tbool[0] = true;
  Tbool.back() = true;
  
  // Coarse -- check only arg at midpoints of each interval
  //   This loop starts from the beginning of the data set, and
  //   forms the smallest interval such that the arg Tolerance
  //   is achieved by linear interpolation.  Then, it moves to
  //   the end of that interval to find the next interval, etc.
  while(((I0+I1)>>1) < Tbool.size()-1) {
    // hunt for optimal I1
    I1 = MinimalGrid_Hunt(T(), Arg(0), argTol, I0, I1);
    
    if(!Tbool[I1]) {
      Tbool[I1] = true;
      ++NumPoints;
    }
    I0 = I1;
    I1 = 2*I1 - I0;
    if(I1<I0+2) { I1 = I0+2; }
  }
  
  // Fine -- check mag and arg at every point
  //   This loop goes through each of the intervals found above,
  //   and makes sure that every data point in both arg and mag
  //   can be reconstructed to within the given tolerances.  If
  //   not, it just adds the midpoint of the interval, and
  //   checks the new interval again.
  I0 = 0;
  I1 = 1;
  unsigned int i=1;
  while(i<NTimes()) {
    if(i>I1) { // This could happen below
      //while(i>I1) { ++I1; } WHAT???
      I1 = i;
      I0 = i;
      while(!Tbool[I0] && I0>0) { --I0; }
    }
    while(!Tbool[I1]) { ++I1; }
    if(i != I0 && i != I1) {
      if(fabs(1-(Mag(0,I0)+(T(i)-T(I0))*(Mag(0,I1)-Mag(0,I0))/(T(I1)-T(I0)))/Mag(0,i)) > magTol
	 || fabs(Arg(0,I0)+(T(i)-T(I0))*(Arg(0,I1)-Arg(0,I0))/(T(I1)-T(I0))-Arg(0,i)) > argTol) {
	I1 = ((I0+I1)>>1);
	if(!Tbool[I1]) {
	  //if(I1==I0+1) { Caution(magTol, argTol); }
	  Tbool[I1] = true;
	  ++NumPoints;
	}
	continue;
      }
    }
    if(i==I1) {
      I0 = I1;
      ++I1;
    }
    ++i;
  }
  
  // Take only the smaller grid
  vector<double> tOut(NumPoints, 0.0);
  int Point = 0;
  for(unsigned int i=0; i<Tbool.size(); ++i) {
    if(Tbool[i]) {
      tOut[Point]   = T(i);
      ++Point;
    }
  }
  this->Interpolate(tOut);
  
  return *this;
}

void WaveformObjects::Waveform::OutputToNINJAFormat(const string& MetadataFileName, const string ExtractionRadiusString, const string WaveformIdentifier) const {
  size_t found = MetadataFileName.find_last_of("/\\");
  const string Dir = (found!=string::npos ? MetadataFileName.substr(0,found) : ".");
  ofstream meta(MetadataFileName.c_str(), ofstream::app);
  meta << "\n##### Waveform header:\n" << HistoryStr() << "[ht-ampphi-data]" << endl;
  if(!ExtractionRadiusString.empty()) { meta << "extraction-radius = " << ExtractionRadiusString << endl; }
  for(unsigned int mode=0; mode<NModes(); ++mode) {
    char DataFile[1000];
    sprintf(DataFile, (Type() + (WaveformIdentifier.empty() ? "" : "_"+WaveformIdentifier) + "_L%d_M%d.dat").c_str(), L(mode), M(mode));
    meta << L(mode) << "," << M(mode) << " \t= " << string(DataFile) << ".gz" << endl;
    ofstream data((Dir + "/" + DataFile).c_str(), ofstream::out);
    data << setprecision(12) << flush;
    data << "# [1] = " << TimeScale() << endl;
    data << "# [2] = Mag{" << Type() << "(" << L(mode) << "," << M(mode) << ")}" << endl;
    data << "# [3] = Arg{" << Type() << "(" << L(mode) << "," << M(mode) << ")}" << endl;
    for(unsigned int Time=0; Time<NTimes(); ++Time) {
      data << T(Time) << " " << Mag(mode, Time) << " " << Arg(mode, Time) << endl;
    }
    data.close();
    system(("gzip " + Dir + "/" + DataFile).c_str());
  }
  meta.close();
  return;
}


// Related functions
ostream& operator<<(ostream& os, const Waveform& a) {
  os << a.HistoryStr()
     << "# [1] = " << a.TimeScale() << endl;
  for(unsigned int Mode=0; Mode<a.NModes(); ++Mode) {
    os << "# [" << 2*Mode+2 << "] = Mag{" << a.Type() << "(" << a.L(Mode) << "," << a.M(Mode) << ")}" << endl;
    os << "# [" << 2*Mode+3 << "] = Arg{" << a.Type() << "(" << a.L(Mode) << "," << a.M(Mode) << ")}" << endl;
  }
  for(unsigned int Time=0; Time<a.NTimes(); ++Time) {
    os << a.T(Time);
    //ORIENTATION!!! following loop
    for(unsigned int Mode=0; Mode<a.NModes(); ++Mode) {
      os << " " << a.Mag(Mode, Time) << " " << a.Arg(Mode, Time);
    }
    os << endl;
  }
  return os;
}

/// Output Waveform to file.
void Output(const std::string& FileName, const WaveformObjects::Waveform& a, const unsigned int precision) {
  ofstream ofs(FileName.c_str(), ofstream::out);
  if(ofs.is_open()) {
    ofs << setprecision(precision);
    ofs << a;
    ofs.close();
  } else {
    cerr << "\n\nFailed to open '" << FileName << "' for writing.  May be write-protected." << endl;
    Throw1WithMessage("Unwritable file");
  }
  return;
}

/// Output single mode of Waveform to ostream.
void OutputSingleMode(ostream& os, const Waveform& a, const unsigned int Mode) {
  /// This is intended to be a helper function.
  os << a.HistoryStr()
     << "# [1] = " << a.TimeScale() << endl
     << "# [2] = Mag{" << a.Type() << "(" << a.L(Mode) << "," << a.M(Mode) << ")}" << endl
     << "# [3] = Arg{" << a.Type() << "(" << a.L(Mode) << "," << a.M(Mode) << ")}" << endl;
  for(unsigned int Time=0; Time<a.NTimes(); ++Time) {
    os << a.T(Time) << " " << a.Mag(Mode, Time) << " " << a.Arg(Mode, Time) << endl;
  }
  return;
}

/// Output single mode of Waveform to file.
void OutputSingleMode(const std::string& FileName, const WaveformObjects::Waveform& a, const unsigned int Mode, const unsigned int precision) {
  ofstream ofs(FileName.c_str(), ofstream::out);
  ofs << setprecision(precision);
  OutputSingleMode(ofs, a, Mode);
  ofs.close();
  return;
}
