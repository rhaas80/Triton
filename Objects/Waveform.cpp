#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include "Waveform.hpp"

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
using std::complex;
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

string tolower(const string& A);

string Rev = "$Rev: 16185 $";
int Revision = atoi(Rev.substr(5,Rev.size()-6).c_str());

int GetWaveformType(const string& FullPath, const vector<string>& Header);
string GetFileFormat(const vector<string>& Header);
void GetWaveformTimeScaleAndLM(const string& FullPath, const vector<string>& Header, string& Scale, Matrix<int>& lm);

vector<string> Waveform::Types(12, "");
/// Note on Waveform Types:
/// In any system, h -- being strain -- should be dimensionless.
/// When G=c=1, the dimensionless quantities are rMPsi4, rhdot, and rhOverM; as are rOverM and tOverM.
/// When G and c are dimensionful, the dimensionless quantities are 
///   -  (r/c) * (M*G/c^3) * Psi4
///   -  (r/c) * hdot
///   -  (r/c) * h / (M*G/c^3)
///   -  (r/c) / (M*G/c^3)
///   -  t / (M*G/c^3)
/// To regain the dimensionful quantities, we simply need to remove the relevant dimensionful elements.
void SetWaveformTypes() {
  Waveform::Types[0]  = "rMPsi4";
  Waveform::Types[1]  = "rhdot";
  Waveform::Types[2]  = "rhOverM";
  Waveform::Types[3]  = "rPsi4";
  Waveform::Types[4]  = "rhdot";
  Waveform::Types[5]  = "rh";
  Waveform::Types[6]  = "MPsi4";
  Waveform::Types[7]  = "hdot";
  Waveform::Types[8]  = "hOverM";
  Waveform::Types[9]  = "Psi4";
  Waveform::Types[10] = "hdot";
  Waveform::Types[11] = "h";
  return;
}


// Constructors
Waveform::Waveform() :
  history("### Waveform() // empty constructor\n"), typeIndex(0), timeScale("Time"),
  t(0), r(0), lm(0, 2), mag(0, 0), arg(0, 0)
{
  SetWaveformTypes();
}

Waveform::Waveform(const Waveform& a) :
  history(a.history.str()), typeIndex(a.typeIndex), timeScale(a.timeScale),
  t(a.t), r(a.r), lm(a.lm), mag(a.mag), arg(a.arg)
{ history.seekp(0, ios_base::end); }

Waveform::Waveform(const string& DataFileName, const string& Format, const bool ZeroEnds) :
  history(""), typeIndex(0), timeScale("Time"),
  t(0), r(0), lm(0, 2), mag(0, 0), arg(0, 0)
{
  SetWaveformTypes();
  
  string pwd;
  {
    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    pwd = path;
  }
  string hostname;
  {
    char host[MAXHOSTNAMELEN];
    gethostname(host, MAXHOSTNAMELEN);
    hostname = host;
  }
  history << "### Code revision Rev = " << Revision << endl
	  << "### pwd = " << pwd << endl
	  << "### hostname = " << hostname << endl
	  << "### Waveform(\"" << DataFileName << "\", \"" << Format << "\") // constructor from data file" << endl;
  
  if(tolower(Format).find("ninja") != string::npos
     || (DataFileName.size()>4 && DataFileName.compare(DataFileName.size()-4,4,".bbh")==0)
     || (DataFileName.size()>8 && DataFileName.compare(DataFileName.size()-8,8,".minimal")==0)) {  //// Is this a NINJA-style metadata file?
    
    // Get the directory of the .bbh file
    string Dir = DataFileName;
    size_t LastSlash = Dir.rfind("/");
    if (LastSlash!=string::npos) {
      Dir = Dir.substr(0, LastSlash+1);
    } else {
      Dir = "";
    }
    
    // Open the metadata file and look for "[ht-ampphi-data]" or "[ht-data]"
    string SectionHeadingMagArg = "[ht-ampphi-data]";
    string SectionHeadingReIm = "[ht-data]";
    string Format = "ReIm";
    int LineLength=8192;
    char LineChars[LineLength];
    string Line="";
    vector<string> Pair(2,"");
    vector<string> LandMString(2,"");
    vector<int> LandM(2);
    ifstream ifs(DataFileName.c_str(), ifstream::in);
    if(!ifs.is_open()) {
      cerr << "Couldn't open '" << DataFileName << "'" << endl;
      throw("Bad file descriptor");
    }
    while(ifs.getline(LineChars, LineLength, '\n')) {
      string TrimmedLine(LineChars);
      TrimmedLine = TrimWhiteSpace(StripComments(TrimmedLine));
      if(TrimmedLine.compare(SectionHeadingReIm) == 0) {
	Format = "ReIm";
	break;
      } else if(TrimmedLine.compare(SectionHeadingMagArg) == 0) {
	Format = "MagArg";
	break;
      }
    }
    
    // Loop through following lines getting data
    string DataFileName = "";
    vector<string> Header;
    vector<vector<double> > Times(0);
    vector<vector<double> > Re(0);
    vector<vector<double> > Im(0);
    while(ifs.getline(LineChars, LineLength, '\n')) {
      string LineCharsStripped(LineChars);
      LineCharsStripped = TrimWhiteSpace(StripComments(LineCharsStripped));
      if(LineCharsStripped.length()==0) { continue; }
      Pair = split(Line.assign(LineCharsStripped), '=');
      LandMString = split(Pair[0], ',');
      DataFileName = TrimWhiteSpace(Pair[1]);
      LandM[0] = atoi(LandMString[0].c_str());
      LandM[1] = atoi(LandMString[1].c_str());
      lm.push_back(LandM);
      
      //// Read data file
      vector<vector<double> > Data;
      ReadDatFile(Dir+DataFileName,  Data,  Header);
      Times.push_back(vector<double>(Data.size()));
      Re.push_back(vector<double>(Data.size()));
      Im.push_back(vector<double>(Data.size()));
      unsigned int End=Times.size()-1;
      for(unsigned int i=0; i<Times[End].size(); ++i) {
	Times[End][i] = Data[i][0];
      }
      if(t.size()==0) {
	t = Times[End];
      } else {
	t = Intersection(t, Times[End], 0.05, -1.e300);
      }
      for(unsigned int i = 0; i<Data.size(); ++i) { // Loop over time steps
	Re[End][i] = Data[i][1];
	Im[End][i] = Data[i][2];
      }
    }
    ifs.close();
    
    r = vector<double>(1, 0.0);
    
    //// Search for TimeScale, LM info, Format, and Waveform Type
    //LM = vector<vector<int> > (mag.size(), vector<int>(2, 0));
    //GetWaveformTimeScaleAndLM(Header, timeScale, LM);
    timeScale = "(t-r*)/M";
    typeIndex = GetWaveformType(DataFileName, Header);
    
    if(Format.compare("ReIm") == 0) {
      vector<vector<double> > ReA=Re, ImA=Im;
      //ORIENTATION!!! 3 following lines
      for(unsigned int i=0; i<Re.size(); ++i) { // Loop over components
	MagArg(ReA[i], ImA[i], Re[i], Im[i]);
      }
    }
    
    mag.resize(Re.size(), t.size());
    arg.resize(Im.size(), t.size());
    for(unsigned int i=0; i<Times.size(); ++i) {
      mag[i] = WaveformUtilities::Interpolate(Times[i], Re[i], t);
      arg[i] = WaveformUtilities::Interpolate(Times[i], Im[i], t);
    }
    
  } else {  //// Treat this file like a normal data file
    
    //// Read data file
    vector<vector<double> > Data;
    vector<string> Header;
    ReadDatFile(DataFileName,  Data,  Header);
    t = vector<double>(Data.size());
    for(unsigned int i=0; i<t.size(); ++i) {
      t[i] = Data[i][0];
    }
    r = vector<double>(1, 0.0);
    
    //// Get mag and arg data
    // The data has vectors of vectors of components at a given time;
    // we transpose the matrix to vectors of components, each of which is a vector through time.
    //ORIENTATION!!!  7 following lines
    vector<vector<double> > Re((Data[0].size()-1)/2, vector<double>(Data.size(), 0));
    vector<vector<double> > Im(Re.size(), vector<double>(Data.size(), 0));
    vector<double> ReEnds(Re.size(), 0.0);
    vector<double> ImEnds(Re.size(), 0.0);
    for(unsigned int i = 0; i<Re.size(); ++i) { // Loop over components of Re
      ReEnds[i] = (ZeroEnds ? Data[Data.size()-1][2*i+1] : 0.0);
      ImEnds[i] = (ZeroEnds ? Data[Data.size()-1][2*i+2] : 0.0);
      for(unsigned int j = 0; j<Re[i].size(); ++j) { // Loop over time steps
	Re[i][j] = Data[j][2*i+1];
	Im[i][j] = Data[j][2*i+2];
      }
    }
    Data.clear();
    
    //// Search for TimeScale, LM info, and Waveform Type
    lm.resize(Re.size(), 2);
    GetWaveformTimeScaleAndLM(DataFileName, Header, timeScale, lm);
    typeIndex = GetWaveformType(DataFileName, Header);
    string DetectedFormat = GetFileFormat(Header);
    if(DetectedFormat.empty()) {
      DetectedFormat = Format;
    } else if(DetectedFormat.compare(Format) != 0) {
      cerr << "Detected file format '" << DetectedFormat << "' does not match explicit file format '" << Format << "'.  Proceeding with detected format." << endl;
    }
    
    mag.resize(Re.size(), Re[0].size());
    arg.resize(Re.size(), Re[0].size());
    if(DetectedFormat.compare("ReIm") == 0) {
      //ORIENTATION!!! 3 following lines
      if(ZeroEnds) std::cout << "ReEnds=" << ReEnds << "\nImEnds=" << ImEnds << std::endl;
      for(unsigned int i=0; i<Re.size(); ++i) { // Loop over components
	MagArg(Re[i]-ReEnds[i], Im[i]-ImEnds[i], mag[i], arg[i]);
      }
    } else if(DetectedFormat.compare("MagArg") == 0) {
      mag = Re;
      arg = Im;
    } else {
      throw(("Unknown format " + Format).c_str());
    }
  }
}

// sum_{l=2}^{PNLMax} (2l+1) = 2*(PNLMax*(PNLMax-1)/2-1) + (PNLMax-2) = (PNLMax+3)*(PNLMax-1)
Waveform::Waveform(const string& Approximant, const double delta, const double chis, const double chia, const double v0,
		   const Matrix<int> LM, const int nsave, const bool denseish, const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  SetWaveformTypes();
  
  {
    history << "### Code revision Rev=" << Revision << endl
	    << "### Waveform("
	    << Approximant << ", "
	    << delta << ", "
	    << chis << ", "
	    << chia << ", "
	    << v0 << ", "
	    << PNPhaseOrder << ", "
	    << PNAmplitudeOrder << ", "
	    << RowFormat(LM) << ", "
	    << nsave << ", "
	    << denseish
	    << ") // PN constructor" << endl;
  }
  
  vector<double> v(0), Phi(0);
  if(Approximant.compare("TaylorT1")==0) {
    if(nsave==-1) {
      TaylorT1(delta, chis, v0, t, v, Phi);
    } else {
      TaylorT1(delta, chis, v0, t, v, Phi, nsave, denseish);
    }
  } else if(Approximant.compare("TaylorT2")==0) {
    if(nsave==-1) {
      TaylorT2(delta, chis, v0, t, v, Phi);
    } else {
      TaylorT2(delta, chis, v0, t, v, Phi, nsave);
    }
  } else if(Approximant.compare("TaylorT3")==0) {
    if(nsave==-1) {
      TaylorT3(delta, chis, v0, t, v, Phi);
    } else {
      TaylorT3(delta, chis, v0, t, v, Phi, nsave);
    }
  } else if(Approximant.compare("TaylorT4")==0) {
    if(nsave==-1) {
      TaylorT4(delta, chis, v0, t, v, Phi);
    } else {
      TaylorT4(delta, chis, v0, t, v, Phi, nsave, denseish);
    }
  } else if(Approximant.compare("EOB")==0) {
    if(nsave==-1) {
      EOB(delta, chis, chia, v0, t, v, Phi);
    } else {
      EOB(delta, chis, chia, v0, t, v, Phi, nsave, denseish);
    }
  } else {
    cerr << "Unknown approximant '" << Approximant << "'." << endl;
    throw("Bad approximant");
  }
  mag.resize(lm.nrows(), t.size());
  arg.resize(lm.nrows(), t.size());
  WaveformAmplitudes PNAmp(delta, chis);
  if(LM.nrows()>0) {
    for(unsigned int m=0; m<NModes(); ++m) {
      PNAmp.rhOverM(L(m), M(m), v, Phi, mag[m], arg[m]);
    }
  } else {
    unsigned int i=0;
    for(int l=2; l<=PNLMax; ++l) {
      for(int m=-l; m<=l; ++m) {
	lm[i][0] = l;
	lm[i][1] = m;
	PNAmp.rhOverM(l, m, v, Phi, mag[i], arg[i]);
	++i;
      }
    }
  }
  r.resize(1, 0.0);
}


// Member functions

// Operators
Waveform& Waveform::operator=(const Waveform& b) {
  /// This call should not be recorded in the history
  history.str(b.history.str());
  history.seekp(0, ios_base::end);
  typeIndex = b.typeIndex;
  timeScale = b.timeScale;
  t = b.t;
  r = b.r;
  lm = b.LM();
  mag = b.mag;
  arg = b.arg;
  return *this;
}

Waveform Waveform::operator/(const Waveform& b) const {
  if(b.NModes() != NModes() || b.LM().RawData() != LM().RawData()) {
    throw("Trying to divide Waveform objects with mismatched LM data");
  }
  Waveform c = *this;
  Waveform d = b;
  c.history << "### this->Waveform::operator/(const Waveform& b) const" << endl
	    << "###### Begin b.history:" << endl
	    << d.history.str()
	    << "###### End b.history:" << endl;
  vector<double> NewTime = Intersection(c.t, d.t, 0.005, -1e300);
  c.Interpolate(NewTime);
  d.Interpolate(NewTime);
  c.mag = (c.mag - d.mag) / d.mag;
  c.arg = c.arg-d.arg;
  return c;
}

Waveform Waveform::operator[](const unsigned int mode) const {
  Waveform copy;
  copy.history.str(history.str());
  copy.history.seekp(0, ios_base::end);
  copy.history << "### this = this[" << mode << "]" << endl;
  copy.typeIndex = typeIndex;
  copy.timeScale = timeScale;
  copy.t = t;
  copy.r = r;
  copy.lm.resize(1,2);
  copy.mag.resize(1,NTimes());
  copy.arg.resize(1,NTimes());
  copy.lm[0] = LM(mode);
  copy.mag[0] = Mag(mode);
  copy.arg[0] = Arg(mode);
  return copy;
}

void Waveform::swap(Waveform& b) {
  /// This call should not be recorded explicitly in the history
  { const string historyb=b.history.str(); b.history.str(history.str()); history.str(historyb); }
  history.seekp(0, ios_base::end);
  b.history.seekp(0, ios_base::end);
  { const unsigned int typeIndexb = b.typeIndex; b.typeIndex=typeIndex; typeIndex=typeIndexb; }
  timeScale.swap(b.timeScale);
  t.swap(b.t);
  r.swap(b.r);
  lm.swap(b.lm);
  mag.swap(b.mag);
  arg.swap(b.arg);
  return;
}


// Handy description routines
double Waveform::Peak22Time() const {
  //// Find 2,2 component
  int TwoTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==2 && M(i)==2) { TwoTwo=i; break; }
  }
  //// Error if not found
  if(TwoTwo==-1) { throw("Can't find the 2,2 component of the data!"); }
  return t[maxIndex(mag[TwoTwo])];
}

vector<double> Waveform::Omega2m2(const double t1, const double t2) const {
  //// Find 2,2 component
  int TwomTwo = -1;
  for(unsigned int i=0; i<NModes(); ++i) {
    if(L(i)==2 && M(i)==-2) { TwomTwo=i; break; }
  }
  
  //// Error if not found
  if(TwomTwo==-1) {
    for(unsigned int i=0; i<NModes(); ++i) {
      if(L(i)==2 && M(i)==2) { TwomTwo=i; break; }
    }
    if(TwomTwo==-1) {
      cerr << "\nlm=\n" << lm << endl;
      throw("Bad L,M data; no (2,-2) mode.");
    }
    cerr << "\n(2,-2) mode not found; proceeding with (2,2) mode.\n" << endl;
  }
  
  //// Return differentiated Arg data
  //ORIENTATION!!! following section
  if((t1!=-1e300 && t1>t[0]) && (t2!=1e300 && t2<t.back())) {
    vector<double> NewTime(t);
    vector<double> phase(arg[TwomTwo]);
    int i=NewTime.size()-1;
    while(NewTime[i]>t2) { --i; }
    NewTime.erase(NewTime.begin()+i, NewTime.begin()+NewTime.size());
    phase.erase(phase.begin()+i, phase.begin()+phase.size());
    i=0;
    while(NewTime[i]<t1) { ++i; }
    NewTime.erase(NewTime.begin(), NewTime.begin()+i);
    phase.erase(phase.begin(), phase.begin()+i);
    return dydx(phase, NewTime);
  } else if((t1!=-1e300 && t1>t[0])) {
    vector<double> NewTime(t);
    vector<double> phase(arg[TwomTwo]);
    int i=0;
    while(NewTime[i]<t1) { ++i; }
    NewTime.erase(NewTime.begin(), NewTime.begin()+i);
    phase.erase(phase.begin(), phase.begin()+i);
    return dydx(phase, NewTime);
  } else if((t2!=1e300 && t2<t.back())) {
    vector<double> NewTime(t);
    vector<double> phase(arg[TwomTwo]);
    int i=NewTime.size()-1;
    while(NewTime[i]>t2) { --i; }
    NewTime.erase(NewTime.begin()+i, NewTime.begin()+NewTime.size());
    phase.erase(phase.begin()+i, phase.begin()+phase.size());
    return dydx(phase, NewTime);
  } else {
    return dydx(arg[TwomTwo], t);
  }
}

bool Waveform::HasNaNs() const {
  bool hasnans = false;
  for(unsigned int i=0; i<t.size(); ++i) {
    if(t[i]!=t[i]) {
      cerr << "\nChecking Waveform, a NaN was detected in the Time at index i=" << i << "." << endl;
      hasnans = true;
    }
  }
  for(unsigned int i=0; i<NModes(); ++i) {
    for(unsigned int j=0; j<NTimes(); ++j) {
      if(Mag(i,j)!=Mag(i,j)) {
	cerr << "\nChecking Waveform, a NaN was detected in the Mag at index i=" << i << ", j=" << j << " of " << Mag(i).size() << "." << endl;
	hasnans = true;
      }
    }
  }
  for(unsigned int i=0; i<NModes(); ++i) {
    for(unsigned int j=0; j<NTimes(); ++j) {
      if(Arg(i,j)!=Arg(i,j)) {
	cerr << "\nChecking Waveform, a NaN was detected in the Arg at index i=" << i << ", j=" << j << " of " << Arg(i).size() << "." << endl;
	hasnans = true;
      }
    }
  }
  return hasnans;
}

vector<double> Waveform::Flux() const {
  if(typeIndex%3!=1) {
    cerr << "\nType = " << Type() << endl;
    throw("Can't get Flux() for Waveform of Type other than rhdot.  Maybe you should use Differentiate().");
  }
  vector<double> Flux(t.size(), 0.0);
  //ORIENTATION!!! Following loop
  for(unsigned int i=0; i<NModes(); ++i) {
    Flux += mag[i]*mag[i];
  }
  return (Flux/(16.0*M_PI));
}


// Interpolation routines
Waveform& Waveform::Interpolate(const vector<double>& NewTime) {
  history << "### this->Interpolate(const vector<double>& NewTime)" << endl;
  if(r.size()==t.size()) {
    r = WaveformUtilities::Interpolate(t, r, NewTime);
  }
  //ORIENTATION!!! 4 following lines
  for(unsigned int i=0; i<NModes(); ++i) {
    mag[i] = WaveformUtilities::Interpolate(t, mag[i], NewTime);
    arg[i] = WaveformUtilities::Interpolate(t, arg[i], NewTime);
  }
  t = NewTime;
  return *this;
}

Waveform& Waveform::Interpolate(const vector<double>& NewTime, const double ExtrapVal) {
  history << "### this->Interpolate(const vector<double>& NewTime, " << ExtrapVal << ")" << endl;
  if(r.size()==t.size()) {
    r = WaveformUtilities::Interpolate(t, r, NewTime, r.back());
  }
  //ORIENTATION!!! 4 following lines
  for(unsigned int i=0; i<NModes(); ++i) {
    mag[i] = WaveformUtilities::Interpolate(t, mag[i], NewTime, ExtrapVal);
    arg[i] = WaveformUtilities::Interpolate(t, arg[i], NewTime, arg[i].back());
  }
  t = NewTime;
  return *this;
}

Waveform& Waveform::Interpolate(const double NewTime) {
  history << "### this->Interpolate(" << setprecision(16) << NewTime << ")" << endl;
  this->Interpolate(vector<double>(1, NewTime));
  return *this;
}

Waveform& Waveform::Interpolate(const Waveform& b) {
  history << "### this->Interpolate(const Waveform& b)" << endl;
  this->Interpolate(b.t);
  return *this;
}

Waveform& Waveform::Interpolate(const Waveform& b, const double ExtrapVal) {
  history << "### this->Interpolate(const Waveform& b, " << ExtrapVal << ")" << endl;
  this->Interpolate(b.t, ExtrapVal);
  return *this;
}

// Trim or adjust time axis
Waveform& Waveform::AddToTime(const double time) {
  history << "### this->AddToTime(" << setprecision(16) << time << ")" << endl;
  t += time;
  return *this;
}

Waveform& Waveform::DropBefore(const double time) {
  history << "### this->DropBefore(" << setprecision(16) << time << ")" << endl;
  unsigned int i=0;
  while(i<t.size()-1 && t[i+1]<=time) { ++i; }
  if(r.size()==t.size()) { r.erase(r.begin(), r.begin()+i); }
  t.erase(t.begin(), t.begin()+i);
  for(unsigned int j=0; j<NModes(); ++j) {
    mag[j].erase(mag[j].begin(), mag[j].begin()+i);
    arg[j].erase(arg[j].begin(), arg[j].begin()+i);
  }
  return *this;
}

Waveform& Waveform::DropAfter(const double time) {
  history << "### this->DropAfter(" << setprecision(16) << time << ")" << endl;
  unsigned int i=t.size()-1;
  while(i>0 && t[i]>time) { --i; }
  if(r.size()==t.size()) { r.erase(r.begin()+i, r.end()); }
  t.erase(t.begin()+i, t.end());
  for(unsigned int j=0; j<NModes(); ++j) {
    mag[j].erase(mag[j].begin()+i, mag[j].end());
    arg[j].erase(arg[j].begin()+i, arg[j].end());
  }
  return *this;
}

Waveform& Waveform::ZeroBefore(const double time) {
  history << "### this->ZeroBefore(" << setprecision(16) << time << ")" << endl;
  unsigned int i=0;
  while(i<t.size()-1 && t[i+1]<=time) { ++i; }
  for(unsigned int j=0; j<NModes(); ++j) {
    for(unsigned int k=0; k<i; ++k) {
      mag[j][k] = 0.0;
    }
  }
  return *this;
}

Waveform& Waveform::UniformTimeToPowerOfTwo() {
  if(((t.size()) & (t.size()-1)) == 0) { return *this; } // Return *this if we already have a power of 2
  history << "### this->UniformTimeToPowerOfTwo()" << endl;
  unsigned int N = static_cast<unsigned int>(pow(2.0,ceil(log2(t.size()))));
  double dt = (t.back()-t[0])/(N-1);
  vector<double> NewTime(N, 0.0);
  for(unsigned int i=0; i<N; ++i) {
    NewTime[i] = t[0] + i*dt;
  }
  this->Interpolate(NewTime);
  return *this;
}

Waveform& Waveform::UniformTime(const unsigned int N) {
  history << "### this->UniformTime(" << N << ")" << endl;
  double dt = (t.back()-t[0])/(N-1);
  vector<double> NewTime(N, 0.0);
  for(unsigned int i=0; i<N; ++i) {
    NewTime[i] = t[0] + i*dt;
  }
  this->Interpolate(NewTime);
  return *this;
}


// Used before converting to frequency space or when scaling the mass
double ScaleMag(const double S, const unsigned int typeIndex) {
  //        { Amp*S when typeIndex mod 3 = 0 (Psi4)
  // Amp -> { Amp   when typeIndex mod 3 = 1 (hdot)
  //        { Amp/S when typeIndex mod 3 = 2 (h)
  switch( typeIndex % 3 ) {
  case 0:
    return S;
  case 1:
    return 1.0;
  case 2:
    return 1.0/S;
  default:
    throw("That was unexpected!");
  }
}

// Used in extrapolation
Waveform& Waveform::SetArealRadius(const string& AreaFileName) {
  history << "### this->SetArealRadius(\"" << AreaFileName << "\")" << endl;
  //// Read data files
  vector<vector<double> > Area;
  vector<string> Header;
  ReadDatFile(AreaFileName,  Area,  Header);
  r.resize(Area.size());
  for(unsigned int i=0; i<r.size(); ++i) {
    r[i] = sqrt(Area[i][1]/(4*M_PI));
  }
  return *this;
}

Waveform& Waveform::SetTimeFromLapseSurfaceIntegral(const string& LapseFileName, const double ADMMass) {
  if(r.size()==0) { throw("Bad size for r data."); }
  history << "### this->SetTimeFromLapseSurfaceIntegral(\"" << LapseFileName << "\", " << setprecision(16) << ADMMass << ")" << endl;
  //// Read data files
  vector<vector<double> > LapseData;
  vector<string> Header;
  ReadDatFile(LapseFileName,  LapseData,  Header);
  vector<double> Lapse(LapseData.size());
  if(Lapse.size() != r.size() && r.size()!=1) {
    cerr << "\nLapse.size()=" << Lapse.size() << "\tr.size()=" << r.size() << "\tLapseFileName=" << LapseFileName << endl;
    throw("Bad size for Lapse data");
  }
  if(r.size()==1) {
    for(unsigned int i=0; i<Lapse.size(); ++i) {
      Lapse[i] = LapseData[i][1]/((4*M_PI)*(r[0]*r[0]));
    }
    t = cumtrapz(t, Lapse/sqrt(((-2.0*ADMMass)/r[0]) + 1.0)) + t[0];
  } else {
    for(unsigned int i=0; i<Lapse.size(); ++i) {
      Lapse[i] = LapseData[i][1]/((4*M_PI)*(r[i]*r[i]));
    }
    t = cumtrapz(t, Lapse/sqrt(((-2.0*ADMMass)/r) + 1.0)) + t[0];
  }
  return *this;
}

Waveform& Waveform::TortoiseOffset(const double ADMMass) {
  history << "### this->TortoiseOffset(" << setprecision(16) << ADMMass << ")" << endl;
  timeScale = "(t-r*)";
  if(r.size()==1) {
    t = t - (r[0] + (2.0*ADMMass)*log((r[0]/(2.0*ADMMass))-1.0));
  } else {
    t = t - (r + (2.0*ADMMass)*log((r/(2.0*ADMMass))-1.0));
  }
  return *this;
}

Waveform& Waveform::SetTotalMassToOne(const double TotalMassInCurrentUnits) {
  history << "### this->SetTotalMassToOne(" << setprecision(16) << TotalMassInCurrentUnits << ")" << endl;
  mag *= ScaleMag(TotalMassInCurrentUnits, typeIndex);
  t = t / TotalMassInCurrentUnits;
  r = r / TotalMassInCurrentUnits;
  if((typeIndex>2 && typeIndex<6) || typeIndex>8) { typeIndex = typeIndex - 3; }
  if(timeScale.find("/M") == string::npos) { timeScale = timeScale + "/M"; }
  return *this;
}

Waveform& Waveform::SetPhysicalMassAndDistance(const double CurrentUnitMassInSolarMasses, const double DistanceInMegaparsecs) {
  history << "### this->SetPhysicalMassAndDistance(" << setprecision(16)
	  << CurrentUnitMassInSolarMasses << ", "
	  << DistanceInMegaparsecs << ")" << endl;
  // See the note above Waveform::Types.  This function removes the (G*M/c^3)
  // from each type, then scales the Time into seconds, and Radius into meters.
  // It then removes the (r/c) from the amplitude of each type.
  if((typeIndex>2 && typeIndex<6) || typeIndex>8) { throw(("Cannot SetPhysicalMass for Waveform of Type " + Type()).c_str()); }
  if(typeIndex>5) { throw(("Cannot SetPhysicalDistance for Waveform of Type " + Type()).c_str()); }
  double MassInSeconds = CurrentUnitMassInSolarMasses * SolarMass * NewtonsConstant / (SpeedOfLight*SpeedOfLight*SpeedOfLight);
  double DistanceInMeters = DistanceInMegaparsecs * OneMegaparsec;
  mag *= (ScaleMag(1.0/MassInSeconds, typeIndex) * SpeedOfLight / DistanceInMeters);
  t *= MassInSeconds;
  r = vector<double>(r.size(), DistanceInMeters);
  typeIndex = typeIndex + 9;
  if(timeScale.find("/M") != string::npos) { timeScale.erase(timeScale.find("/M"),2); }
  return *this;
}

Waveform& Waveform::DropLMode(const int L) {
  history << "### this->DropLMode(" << L << ")" << endl;
  vector<vector<double> >::iterator magrit=mag.RawData().end();
  vector<vector<double> >::iterator argrit=arg.RawData().end();
  vector<vector<int> >::iterator LMrit=lm.RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= lm.RawData().begin()) {
    if((*LMrit)[0]==L) {
      mag.RawData().erase(magrit);
      arg.RawData().erase(argrit);
      lm.RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropLMMode(const int L, const int M) {
  history << "### this->DropLMMode(" << L << ", " << M << ")" << endl;
  vector<vector<double> >::iterator magrit=mag.RawData().end();
  vector<vector<double> >::iterator argrit=arg.RawData().end();
  vector<vector<int> >::iterator LMrit=lm.RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  while(LMrit >= lm.RawData().begin()) {
    //ORIENTATION!!! following if statements
    if((*LMrit)[0]==L && (((*LMrit)[1]==M) || ((*LMrit)[1]==-M))) {
      mag.RawData().erase(magrit);
      arg.RawData().erase(argrit);
      lm.RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropOddMModes() {
  history << "### this->DropOddMModes()" << endl;
  vector<vector<double> >::iterator magrit=mag.RawData().end();
  vector<vector<double> >::iterator argrit=arg.RawData().end();
  vector<vector<int> >::iterator LMrit=lm.RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= lm.RawData().begin()) {
    if((*LMrit)[1]%2!=0) {
      mag.RawData().erase(magrit);
      arg.RawData().erase(argrit);
      lm.RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropZeroMModes() {
  history << "### this->DropZeroMModes()" << endl;
  vector<vector<double> >::iterator magrit=mag.RawData().end();
  vector<vector<double> >::iterator argrit=arg.RawData().end();
  vector<vector<int> >::iterator LMrit=lm.RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= lm.RawData().begin()) {
    if((*LMrit)[1]==0) {
      mag.RawData().erase(magrit);
      arg.RawData().erase(argrit);
      lm.RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropNegativeMModes() {
  history << "### this->DropNegativeMModes()" << endl;
  vector<vector<double> >::iterator magrit=mag.RawData().end();
  vector<vector<double> >::iterator argrit=arg.RawData().end();
  vector<vector<int> >::iterator LMrit=lm.RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= lm.RawData().begin()) {
    if((*LMrit)[1]<1) {
      mag.RawData().erase(magrit);
      arg.RawData().erase(argrit);
      lm.RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::Conjugate() {
  ArgRef() *= -1.0;
  return *this;
}


// Convert (mag,arg) to (re,im) for, e.g., m=0 modes
Waveform& Waveform::FixNonOscillatingData() {
  history << "### this->FixNonOscillatingData()" << endl;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) { // Loop over components
    if(M(i)==0) {
      vector<double> Im = mag[i] * sin(arg[i]);
      mag[i] = mag[i] * cos(arg[i]);
      arg[i] = Im;
    }
  }
  return *this;
}

Waveform& Waveform::UnfixNonOscillatingData() {
  history << "### this->UnfixNonOscillatingData()" << endl;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) { // Loop over components
    if(M(i)==0) {
      vector<double> Re = mag[i];
      vector<double> Im = arg[i];
      MagArg(Re, Im, mag[i], arg[i]);
    }
  }
  return *this;
}


// Align and hybridize waveforms
class WaveformAligner {
  friend class Waveform;
protected:
  const Waveform& a, b;
  vector<double> t, arga;
  int LMa, LMb;
public:
  WaveformAligner(const Waveform& A, const Waveform& B, const double t1, const double t2)
    : a(A), b(B), t(a.T()), arga(0), LMa(-1), LMb(-1)
  {
    if(a.NModes() != b.NModes()) {
      cerr << "\nTrying to Align Waveforms with mismatched LM data." << endl;
      cerr << "a.NModes()=" << a.NModes() << "\tb.NModes()=" << b.NModes() << endl;
      throw("Different number of modes");
    }
    if(a.LM() != b.LM()) {
      cerr << "\nTrying to Align Waveforms with different LM data." << endl;
      cerr << "a.LM()=" << a.LM() << "\nb.LM()=" << b.LM() << endl;
      throw("Different modes");
    }
    if(t1<a.T(0)) {
      cerr << "\nAlignment time t1=" << t1 << " does not occur in Waveform A (which has A.T(0)=" << A.T(0) << ")." << endl;
      throw("Bad matching time for Waveform A");
    }
    if(t1<b.T(0)) {
      cerr << "\nAlignment time t1=" << t1 << " does not occur in Waveform B (which has B.T(0)=" << B.T(0) << ")." << endl;
      throw("Bad matching time for Waveform B");
    }
    if(t2>a.T().back()) {
      cerr << "\nAlignment time t2=" << t2 << " does not occur in Waveform A (which has A.t[-1]=" << A.T().back() << ")." << endl;
      throw("Bad matching time for Waveform A");
    }
    if(t2>B.T().back()) {
      cerr << "\nAlignment time t2=" << t2 << " does not occur in Waveform B (which has B.t[-1]=" << B.T().back() << ")." << endl;
      throw("Bad matching time for Waveform B");
    }
    unsigned int i=0;
    //ORIENTATION!!! following loops
    for(i=0; i<a.NModes(); ++i) {
      if(a.L(i)==2 && a.M(i)==2) { LMa=i; break; }
    }
    if(LMa==-1) {
      cerr << "\na.LM()=" << a.LM() << endl;
      throw("Can't find the 2,2 component of the Waveform a!");
    }
    for(i=0; i<b.NModes(); ++i) {
      if(b.L(i)==2 && b.M(i)==2) { LMb=i; break; }
    }
    if(LMb==-1) {
      cerr << "\nb.LM()=" << b.LM() << endl;
      throw("Can't find the 2,2 component of the Waveform b!");
    }
    arga = a.Arg(LMa);
    i=t.size()-1;
    while(t[i]>t2 && i>0) { --i; }
    t.erase(t.begin()+i, t.end());
    arga.erase(arga.begin()+i, arga.end());
    i=0;
    while(i<a.T().size() && a.T(i)<t1) { ++i; }
    t.erase(t.begin(), t.begin()+i);
    arga.erase(arga.begin(), arga.begin()+i);
  }
  
  double darg(const double dt, const unsigned int mode) const {
    vector<double> argA = Interpolate(a.T(), a.Arg(mode), t);
    vector<double> argB = Interpolate(b.T(), b.Arg(mode), t-dt);
    return trapz(t, argA-argB) / (t.back()-t[0]);
  }
  
  double operator()(const double dt) const {
    vector<double> argb = Interpolate(b.T(), b.Arg(LMb), t-dt);
    double darg = trapz(t, arga-argb) / (t.back()-t[0]);
    return trapz(t, (arga-argb-darg)*(arga-argb-darg));
  }
};

Waveform& Waveform::AlignTo(const Waveform& a, const double t1, const double t2) {
  WaveformAligner Align(a, *this, t1, t2);
  Brent Minimizer;
  Minimizer.ax = max(t1-t2, t[0]-t1);
  Minimizer.bx = 0.0;
  Minimizer.cx = min(t2-t1, t.back()-t2);
  double dt = Minimizer.minimize(Align);
  t += dt;
  for(unsigned int mode=0; mode<a.NModes() && mode<NModes(); ++mode) {
    arg[mode] += Align.darg(dt, mode);
  }
  return *this;
}

Waveform Waveform::HybridizeWith(const Waveform& b, const double t1, const double t2, const double MinStep) const {
  if(NModes() != b.NModes()) {
    cerr << "\nTrying to Align Waveforms with mismatched LM data." << endl;
    cerr << "NModes()=" << NModes() << "\tb.NModes()=" << b.NModes() << endl;
    throw("Different number of modes");
  }
  if(LM() != b.LM()) {
    cerr << "\nTrying to Align Waveforms with different LM data." << endl;
    cerr << "LM()=" << LM() << "\nb.LM()=" << b.LM() << endl;
    throw("Different modes");
  }
  Waveform c(*this);
  c.t = Union(t, b.t, MinStep);
  int it=c.t.size()-1;
  while(c.T(it)>b.T().back() && it>0) { --it; }
  c.t.erase(c.t.begin()+it, c.t.end());
  c.r = vector<double>(1, 0.0);
  c.mag.resize(NModes(), NTimes());
  c.arg.resize(NModes(), NTimes());
  unsigned int J01=0, J12=c.t.size()-1;
  while(c.t[J01]<t1 && J01<c.t.size()) { J01++; }
  while(c.t[J12]>t2 && J12>0) { J12--; }
  const double TransitionLength=max(1.0,double(J12-J01-1.0)); // This is an int that will be used for division
  //ORIENTATION!!! Following loop
  for(unsigned int Mode=0; Mode<NModes(); ++Mode) {
    SplineInterpolator SplineMagA(  t,   mag[Mode]);
    SplineInterpolator SplineMagB(b.t, b.mag[Mode]);
    SplineInterpolator SplineArgA(  t,   arg[Mode]);
    SplineInterpolator SplineArgB(b.t, b.arg[Mode]);
    for(unsigned int j=0; j<J01; ++j) {
      c.mag[Mode][j] = SplineMagA.interp(c.t[j]);
      c.arg[Mode][j] = SplineArgA.interp(c.t[j]);
    }
    for(unsigned int j=J01; j<J12; ++j) {
      const double Transition = double(j-J01)/TransitionLength;
      c.mag[Mode][j] = SplineMagA.interp(c.t[j])*(1.0-Transition) + SplineMagB.interp(c.t[j])*Transition;
      c.arg[Mode][j] = SplineArgA.interp(c.t[j])*(1.0-Transition) + SplineArgB.interp(c.t[j])*Transition;
    }
    for(unsigned int j=J12; j<c.t.size(); ++j) {
      c.mag[Mode][j] = SplineMagB.interp(c.t[j]);
      c.arg[Mode][j] = SplineArgB.interp(c.t[j]);
    }
  }
  
  // Check for NaNs
  c.HasNaNs();
  
  return c;
}

inline double sign(const double x) {
  return (x<0 ? -1.0 : 1.0);
}

Waveform& Waveform::AlignTo_F(const Waveform& a, const double omega, const double t1, const double t2, const double DeltaT, const double MinStep) {
  if(omega==0.0) {
    cerr << "\nThe frequency input to AlignTo_F is exactly 0.0.  This will give you garbage" << endl;
    throw("Bad frequency");
  }
  unsigned int i=0;
  double T1(t1), T2(t2);
  if(T1<a.t[0]) { T1=a.t[0]; }
  if(T1<  t[0]) { T1=  t[0]; }
  if(T2>a.T().back()) { T2=a.T().back(); }
  if(T2>  T().back()) { T2=  T().back(); }
  WaveformAligner Align(a, *this, T1, T2);
  vector<double> NewTimeA(a.T());
  vector<double> NewOmegaA(a.Omega2m2());
  const double NewOmegaASign = sign(NewOmegaA[NewOmegaA.size()/2]);
  vector<double> NewTimeB(T());
  vector<double> NewOmegaB(Omega2m2());
  const double NewOmegaBSign = sign(NewOmegaB[NewOmegaB.size()/2]);
  try {
    /// Make sure A only includes data before T2
    i=NewTimeA.size()-1;
    while(NewTimeA[i]>T2 && i>0) { --i; }
    if(i!=NewTimeA.size()-1) {
      NewTimeA.erase(NewTimeA.begin()+i, NewTimeA.begin()+NewTimeA.size());
      NewOmegaA.erase(NewOmegaA.begin()+i, NewOmegaA.begin()+NewOmegaA.size());
    }
    /// Make sure A only includes data after T1
    i=0;
    while(i<NewTimeA.size() && NewTimeA[i]<T1) { ++i; }
    if(i!=0) {
      NewTimeA.erase(NewTimeA.begin(), NewTimeA.begin()+i);
      NewOmegaA.erase(NewOmegaA.begin(), NewOmegaA.begin()+i);
    }
    /// Make sure NewOmegaA gets up to abs(omega), but is strictly monotonically increasing before it
    i=1;
    while(i<NewOmegaA.size() && NewOmegaASign*NewOmegaA[i]<fabs(omega)) { ++i; }
    while(i>0 && NewOmegaASign*NewOmegaA[i-1]<NewOmegaASign*NewOmegaA[i]) { --i; }
    if(i!=1) {
      NewTimeA.erase(NewTimeA.begin(), NewTimeA.begin()+i);
      NewOmegaA.erase(NewOmegaA.begin(), NewOmegaA.begin()+i);
    }
    /// Make sure NewOmegaA gets past abs(omega), and is strictly monotonically increasing afterward
    i=1;
    while(i<NewTimeA.size() && NewOmegaASign*NewOmegaA[i]<fabs(omega)) { ++i; }
    while(i<NewTimeA.size() && NewOmegaASign*NewOmegaA[i]>NewOmegaASign*NewOmegaA[i-1]) { ++i; }
    if(i!=1) {
      NewTimeA.erase(NewTimeA.begin()+i, NewTimeA.begin()+NewTimeA.size());
      NewOmegaA.erase(NewOmegaA.begin()+i, NewOmegaA.begin()+NewOmegaA.size());
    }
    
    /// Make sure B only includes data before T2
    i=NewTimeB.size()-1;
    while(NewTimeB[i]>T2 && i>0) { --i; }
    if(i!=NewTimeB.size()-1) {
      NewTimeB.erase(NewTimeB.begin()+i, NewTimeB.begin()+NewTimeB.size());
      NewOmegaB.erase(NewOmegaB.begin()+i, NewOmegaB.begin()+NewOmegaB.size());
    }
    /// Make sure B only includes data after T1
    i=0;
    while(i<NewTimeB.size() && NewTimeB[i]<T1) { ++i; }
    if(i!=0) {
      NewTimeB.erase(NewTimeB.begin(), NewTimeB.begin()+i);
      NewOmegaB.erase(NewOmegaB.begin(), NewOmegaB.begin()+i);
    }
    /// Make sure NewOmegaB gets up to fabs(omega), but is strictly monotonically increasing before it
    i=1;
    while(i<NewOmegaB.size() && NewOmegaBSign*NewOmegaB[i]<fabs(omega)) { ++i; }
    while(i>0 && NewOmegaBSign*NewOmegaB[i-1]<NewOmegaBSign*NewOmegaB[i]) { --i; }
    if(i>1) {
      NewTimeB.erase(NewTimeB.begin(), NewTimeB.begin()+i);
      NewOmegaB.erase(NewOmegaB.begin(), NewOmegaB.begin()+i);
    }
    /// Make sure NewOmegaB gets past fabs(omega), and is strictly monotonically increasing afterward
    i=1;
    while(i<NewOmegaB.size() && NewOmegaBSign*NewOmegaB[i]<fabs(omega)) { ++i; }
    while(i<NewTimeB.size() && NewOmegaBSign*NewOmegaB[i]>NewOmegaBSign*NewOmegaB[i-1]) { ++i; }
    if(i>1) {
      NewTimeB.erase(NewTimeB.begin()+i, NewTimeB.begin()+NewTimeB.size());
      NewOmegaB.erase(NewOmegaB.begin()+i, NewOmegaB.begin()+NewOmegaB.size());
    }
  } catch (char* str) {
    cerr << "Bad news from AlignTo_F: " << str << endl
	 << "\nThe frequency requested is probably out of range of one or both of the Waveforms, or your t1 and t2 are too restrictive.\n" << endl;
    exit(1);
  }
  const double TA = WaveformUtilities::Interpolate(NewOmegaA, NewTimeA, NewOmegaASign*fabs(omega));
  NewOmegaA.clear();
  NewTimeA.clear();
  const double TB = WaveformUtilities::Interpolate(NewOmegaB, NewTimeB, NewOmegaBSign*fabs(omega));
  NewOmegaB.clear();
  NewTimeB.clear();
  
  const double dt = TA-TB;
  t += dt;
  for(unsigned int i=0; i<a.NModes() && i<NModes(); ++i) {
    arg[i] += WaveformUtilities::Interpolate(a.t, a.arg[i], TA) - WaveformUtilities::Interpolate(t, arg[i], TA);
  }
  
  if(DeltaT!=1e300) {
    //cerr << "\nomega=" << omega << "\tTA=" << TA << "\tt1=" << max(TA-DeltaT, max(a.t[0], t[0]))
    //     << "\tt2=" << min(TA+DeltaT, min(a.t[a.t.size()-1], t[t.size()-1])) << endl;
    this->HybridizeWith(a, max(TA-DeltaT, max(a.t[0], t[0])), min(TA+DeltaT, min(a.T().back(), T().back())), MinStep);
  }
  return *this;
}

Waveform Waveform::HybridizeWith_F(const Waveform& a, const double omega, const double omegat1, const double omegat2, const double DeltaT, const double MinStep) const {
  Waveform b(*this);
  b.AlignTo_F(a, omega, omegat1, omegat2, DeltaT, MinStep);
  return b;
}

Waveform& Waveform::AttachQNMs(const double delta, const double chiKerr, double dt, const double TLength) {
  if(LM() != QNMLMs()) {
    cerr << "LM=" << LM() << "\nQNMLMs()=" << QNMLMs() << endl;
    throw("Bad input LMs.");
  }
  
  if(dt==0.0) { dt = 2*M_PI/(4*2.0); } // 2.0 -> MAX(omegaRe of all the QNM modes)
  history << "### this->AttachQNMs(" << chiKerr << ", " << dt << ", " << TLength << ");" << endl;
  
  /// Add the new times, and resize everything as appropriate
  const unsigned int NTimesEnd = NTimes();
  const double TEnd = T().back();
  TRef().resize(NTimes()+floor(TLength/dt), T().back());
  for(unsigned int i=1; i<NTimes()-NTimesEnd; ++i) {
    TRef(i+NTimesEnd) += i*dt;
  }
  if(R().size()>1) { RRef().resize(NTimes(), 0.0); }
  MagRef().resize(NModes(), NTimes(), 0.0);
  ArgRef().resize(NModes(), NTimes(), 0.0);
  
  for(unsigned int mode=0; mode<NModes(); ++mode) {
    //// If this mode should be exactly zero, let it be
    if(delta==0.0 && !(M(mode)%2==0)) {
      continue;
    }
    
    //// Get the QNM frequency
    double omegaRe, omegaIm;
    QNM(L(mode), M(mode), 0, chiKerr, omegaRe, omegaIm);
    
    //// Extract the invertible data of the l,m mode
    unsigned int iPeak=maxIndex(Mag(mode));
    const double tDropBefore(T(iPeak));
    unsigned int i=iPeak;
    i++;
    while(Mag(mode, i) < Mag(mode, i-1) && i<NTimesEnd) { ++i; }
    const unsigned int iBad=i;
    const double tDropAfter(T(iBad));
    Waveform InspiralLM((this->operator[](mode)).DropBefore(tDropBefore).DropAfter(tDropAfter));
    
    //// Find the solution
    vector<double> Fvec = dydx(InspiralLM.Mag(0), InspiralLM.T()) + (InspiralLM.Mag(0) * abs(omegaRe));
    vector<double> Tvec = InspiralLM.T();
    {
      unsigned int k=1;
      if(Fvec[0]>0.0) {
	while(Fvec[k]>Fvec[k-1] && k<Fvec.size()) { ++k; }
	Fvec.erase(Fvec.begin(), Fvec.begin()+k);
	Tvec.erase(Tvec.begin(), Tvec.begin()+k);
	k=1;
      }
      while(Fvec[k]<Fvec[k-1]) { ++k; }
      Fvec.erase(Fvec.begin()+k, Fvec.end());
      Tvec.erase(Tvec.begin()+k, Tvec.end());
    }
    double tmatch = WaveformUtilities::Interpolate(Fvec, Tvec, 0.0);
    if((delta==deltaOFq(10.0) && chiKerr==FinalSpinApproximation(deltaOFq(10), 0.95))) {
      cerr << "Redoing tmatch find! (tailored to q==10 && chis==0.95)" << endl;
      iPeak = NTimesEnd-1;
      while(T(iPeak) > -40.0 && iPeak>1) { --iPeak; }
      InspiralLM = (this->operator[](mode)).DropBefore(T(iPeak)).DropAfter(TEnd-1.0);
      cerr << "InspiralLM.NTimes()=" << InspiralLM.NTimes()
	   << " InspiralLM.T(0)=" << InspiralLM.T(0)
	   << " InspiralLM.T().back()=" << InspiralLM.T().back() << endl;
      const double tLength = InspiralLM.T().back()-InspiralLM.T(0);
      for(unsigned int j=0; j<InspiralLM.NTimes(); ++j) {
	InspiralLM.MagRef(0,j) *= (1.0-TransitionFunction_Smooth((InspiralLM.T(j)-InspiralLM.T(0))/tLength));
	MagRef(mode, j+iPeak) = InspiralLM.Mag(0, j);
      }
      Fvec = dydx(InspiralLM.Mag(0), InspiralLM.T()) + (InspiralLM.Mag(0) * abs(omegaRe));
      Tvec = InspiralLM.T();
      {
	unsigned int k=1;
	while(Fvec[k]>Fvec[k-1] && k<Fvec.size()) { ++k; }
	Fvec.erase(Fvec.begin(), Fvec.begin()+k);
	Tvec.erase(Tvec.begin(), Tvec.begin()+k);
	k=1;
	while(Fvec[k]<Fvec[k-1] && k<Fvec.size()) { ++k; }
	Fvec.erase(Fvec.begin()+k, Fvec.end());
	Tvec.erase(Tvec.begin()+k, Tvec.end());
      }
      tmatch = WaveformUtilities::Interpolate(Fvec, Tvec, 0.0);
      
      ofstream ofs("Output/F.dat", ofstream::out);
      for(unsigned int k=0; k<Fvec.size(); ++k) {
	ofs << setprecision(14) << Tvec[k] << " " << Fvec[k] << " " << InspiralLM.Mag(0, k) << endl;
      }
      ofs.close();
      
    } else if(tmatch<tDropBefore || tmatch>tDropAfter) {
      cerr << "Redoing tmatch find!" << endl;
      InspiralLM = (this->operator[](mode)).DropBefore(tDropBefore).DropAfter(TEnd);
      const double tLength = InspiralLM.T().back()-InspiralLM.T(0);
      for(unsigned int j=0; j<InspiralLM.NTimes(); ++j) {
	InspiralLM.MagRef(0, j) *= (1.0-TransitionFunction_Smooth((InspiralLM.T(j)-InspiralLM.T(0))/tLength));
	MagRef(mode, j+iPeak) = InspiralLM.Mag(0, j);
      }
      Fvec = dydx(InspiralLM.Mag(0), InspiralLM.T()) + (InspiralLM.Mag(0) * abs(omegaRe));
      Tvec = InspiralLM.T();
      {
	unsigned int k=1;
	if(Fvec[0]>0.0) {
	  while(Fvec[k]>Fvec[k-1] && k<Fvec.size()) { ++k; }
	  Fvec.erase(Fvec.begin(), Fvec.begin()+k);
	  Tvec.erase(Tvec.begin(), Tvec.begin()+k);
	  k=1;
	}
	while(Fvec[k]<Fvec[k-1]) { ++k; }
	Fvec.erase(Fvec.begin()+k, Fvec.end());
	Tvec.erase(Tvec.begin()+k, Tvec.end());
      }
      tmatch = WaveformUtilities::Interpolate(Fvec, Tvec, 0.0);
      
    }
    InspiralLM = InspiralLM.Interpolate(tmatch);
    const double Alm0Re = (InspiralLM.Mag(0,0))*cos(InspiralLM.Arg(0,0));
    const double Alm0Im = (InspiralLM.Mag(0,0))*sin(InspiralLM.Arg(0,0));
    i=iPeak;
    while(tmatch>T(i) && i<NTimes()) { ++i; }
    const unsigned int iMatch=i; // iMatch points at or to the right of tmatch
    
    //// Read data into the QNM portion of the waveform
    const double phiPeak = Arg(mode, iPeak);
    const double omegaPeak = (Arg(mode, iPeak+1)-Arg(mode, iPeak-1)) / (T(iPeak+1)-T(iPeak-1));
    const double omegaQNM = omegaRe;
    cerr << "tPeak=" << tDropBefore << " tmatch=" << tmatch << " tBad=" << tDropAfter << " omegaPeak=" << omegaPeak << " omegaQNM=" << omegaQNM << endl;
    vector<double> omegaTransition(iMatch-iPeak, omegaPeak);
    for(unsigned int k=1; k<omegaTransition.size(); ++k) {
      omegaTransition[k] = omegaPeak + (omegaQNM-omegaPeak)*TransitionFunction_Linear((T(k+iPeak)-T(iPeak))/(T(iMatch-1)-T(iPeak)));
    }
    vector<double> phiTransition(iMatch-iPeak, phiPeak);
    for(unsigned int k=1; k<phiTransition.size(); ++k) {
      phiTransition[k] = phiTransition[k-1] + (T(k+iPeak)-T(k+iPeak-1))*(omegaTransition[k]+omegaTransition[k-1])/2.0;
    }
    for(unsigned int j=iPeak; j<iMatch; ++j) {
      ArgRef(mode, j) = phiTransition[j-iPeak];
    }
    const double phiOffset = phiTransition.back() + omegaTransition.back()*(tmatch-T(iMatch-1));
    for(unsigned int j=iMatch; j<NTimes(); ++j) {
      const double qnmRe = Alm0Re*cos(omegaRe*(T(j)-tmatch)) - Alm0Im*sin(omegaRe*(T(j)-tmatch));
      const double qnmIm = Alm0Im*cos(omegaRe*(T(j)-tmatch)) + Alm0Re*sin(omegaRe*(T(j)-tmatch));
      MagRef(mode, j) = sqrt(qnmRe*qnmRe + qnmIm*qnmIm) * exp(-omegaIm*(T(j)-tmatch));
      ArgRef(mode, j) = atan2(qnmIm, qnmRe) + phiOffset - atan2(Alm0Im, Alm0Re);
    }
    ArgRef(mode) = Unwrap(Arg(mode));
  }
  return *this;
}

// Mostly useful for getting the flux
Waveform& Waveform::Differentiate() {
  if(typeIndex%3==0) {
    cerr << "\nType=" << Type() << endl;
    throw("Derivative of Psi4 not supported.");
  }
  typeIndex -= 1;
  vector<double> magdot(NTimes()), argdot(NTimes());
  // Loop over each component, doing the differentiation
  //ORIENTATION!!!! Following loop
  for(unsigned int iMode=0; iMode<NModes(); ++iMode) {
    magdot = dydx(Mag(iMode), T());
    argdot = dydx(Arg(iMode), T());
    mag[iMode] = sqrt(magdot*magdot + Mag(iMode)*Mag(iMode)*argdot*argdot);
    arg[iMode] = Arg(iMode) + Unwrap(atan2(Mag(iMode)*argdot, magdot));
  }
  return *this;
}


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


Waveform& Waveform::MinimalGrid(const double magTol, const double argTol) {
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
    throw("Too many modes");
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
      while(i>I1) { ++I1; }
      I0 = i;
      while(!Tbool[I0]) { --I0; }
    }
    while(!Tbool[I1]) { ++I1; }
    if(i != I0 && i != I1) {
      if(fabs(1-(mag[0][I0]+(T(i)-T(I0))*(mag[0][I1]-mag[0][I0])/(T(I1)-T(I0)))/mag[0][i]) > magTol
	 || fabs(arg[0][I0]+(T(i)-T(I0))*(arg[0][I1]-arg[0][I0])/(T(I1)-T(I0))-arg[0][i]) > argTol) {
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

void Waveform::OutputToNINJAFormat(const string& MetadataFileName) const {
  ofstream meta(MetadataFileName.c_str(), ofstream::app);
  meta << history;
  meta << "[ht-ampphi-data]" << endl;
  for(unsigned int i=0; i<NModes(); ++i) {
    char DataFile[1000];
    sprintf(DataFile, (Type() + "_L%d_M%d.dat").c_str(), L(i), M(i));
    meta << L(i) << "," << M(i) << " \t= " << string(DataFile) << endl;
    ofstream data(DataFile, ofstream::out);
    data << setprecision(12) << flush;
    data << "# [1] = " << TimeScale() << endl;
    unsigned int Mode=i;
    data << "# [2] = Mag{" << Type() << "(" << L(Mode) << "," << M(Mode) << ")}" << endl;
    data << "# [3] = Arg{" << Type() << "(" << L(Mode) << "," << M(Mode) << ")}" << endl;
    for(unsigned int Time=0; Time<NTimes(); ++Time) {
      data << T(Time) << " " << Mag(Mode, Time) << " " << Arg(Mode, Time) << endl;
    }
    data.close();
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

void Output(const string& FileName, const Waveform& a, const unsigned int precision) {
  ofstream ofs(FileName.c_str(), ofstream::out);
  ofs << setprecision(precision);
  ofs << a;
  ofs.close();
  return;
}

void OutputSingleMode(ostream& os, const Waveform& a, const unsigned int Mode) {
  os << a.HistoryStr()
     << "# [1] = " << a.TimeScale() << endl
     << "# [2] = Mag{" << a.Type() << "(" << a.L(Mode) << "," << a.M(Mode) << ")}" << endl
     << "# [3] = Arg{" << a.Type() << "(" << a.L(Mode) << "," << a.M(Mode) << ")}" << endl;
  for(unsigned int Time=0; Time<a.NTimes(); ++Time) {
    os << a.T(Time) << " " << a.Mag(Mode, Time) << " " << a.Arg(Mode, Time) << endl;
  }
  return;
}

void OutputSingleMode(const string& FileName, const Waveform& a, const unsigned int Mode, const unsigned int precision) {
  ofstream ofs(FileName.c_str(), ofstream::out);
  ofs << setprecision(precision);
  OutputSingleMode(ofs, a, Mode);
  ofs.close();
  return;
}



//// Utilities for this file only
string tolower(const string& A) {
  string B = A;
  string::iterator it;
  for(it=B.begin(); it<B.end(); it++) {
    *it = tolower(*it);
  }
  return B;
}

int GetWaveformType(const string& FullPath, const vector<string>& Header) {
  int typeIndex = 0;
  string FileName = FullPath;
  
  //// Look for the info at the beginning of the file name
  size_t found;
  found=FileName.find_last_of("/\\");
  if (found!=string::npos) { FileName = FileName.substr(found+1); }
  for(unsigned int i=0; i<Waveform::Types.size(); ++i) {
    if(tolower(FileName).find(tolower(Waveform::Types[i])) != string::npos &&
       tolower(FileName).find(tolower(Waveform::Types[i])) == 0) {
      return i;
    }
  }
  
  //// Look for the info in the Header
  for(unsigned int j=0; j<Header.size(); ++j) {
    for(unsigned int i=0; i<Waveform::Types.size(); ++i) {
      if(tolower(Header[j]).find(tolower(Waveform::Types[i])) != string::npos) {
	typeIndex = i;
	break;
      }
    }
  }
  return typeIndex;
}

string GetFileFormat(const vector<string>& Header) {
  string DetectedFormat("");
  
  //// Look for the info in the Header
  for(unsigned int j=0; j<Header.size(); ++j) {
    if(tolower(Header[j]).find(tolower("Mag{")) != string::npos || tolower(Header[j]).find(tolower("Abs{")) != string::npos) {
      DetectedFormat = "MagArg";
      break;
    } else if(tolower(Header[j]).find(tolower("r*Re")) != string::npos) {
      DetectedFormat = "ReIm";
      break;
    }
  }
  
  return DetectedFormat;
}

void GetWaveformTimeScaleAndLM(const string& FullPath, const vector<string>& Header, string& Scale, Matrix<int>& lm) {
  //// Look for the info at the beginning of the file name
  size_t found;
  string FileName = FullPath;
  found=FileName.find_last_of("/\\");
  if (found!=string::npos) { FileName = FileName.substr(found+1); }
  if((found = tolower(FileName).find("_l")) != string::npos &&
     tolower(FileName).find("_m", found) != string::npos)
    {
      if(lm.nrows()!=1) {
	cerr << "\nlm.nrows()=" << lm.nrows() << " but file name " << FileName << " indicates there is just one mode." << endl;
	throw("Bad LM modes");
      }
      size_t LBegin, LEnd, MBegin, MEnd;
      LBegin = found+2;
      LEnd = tolower(FileName).find("_m", LBegin);
      MBegin = LEnd+2;
      MEnd = tolower(FileName).find_first_of("._", MBegin);
      lm[0][0] = atoi(FileName.substr(LBegin,LEnd-LBegin).c_str());
      lm[0][1] = atoi(FileName.substr(MBegin,MEnd-MBegin).c_str());
      return;
    }
  
  //// Look for the info in the Header
  unsigned int i=0;
  size_t Comma, Paren1, Paren2;
  for(unsigned int j=0; j<Header.size(); ++j) {
    if(Header[j].compare(0,8,"# [1] = ")==0) {
      Scale = Header[j].substr(8);
    } else if(Header[j].compare(0,3,"# [")==0) {
      Comma = Header[j].rfind(",");
      Paren1 = Header[j].rfind("(",Comma);
      Paren2 = Header[j].find(")",Comma);
      if(Comma != string::npos && Paren1 != string::npos && Paren2 != string::npos) {
	lm[i][0] = atoi(Header[j].substr(Paren1+1,Comma-Paren1-1).c_str());
	lm[i][1] = atoi(Header[j].substr(Comma+1,Paren2-Comma-1).c_str());
	++i;
	++j;
      }
    }
  }
  if(i!=lm.nrows()) {
    cerr << "i=" << i << " but lm.nrows()=" << lm.nrows() << "\nThat's bad news for the LM modes..." << endl;
    throw("Bad LM modes");
  }
  return;
}
