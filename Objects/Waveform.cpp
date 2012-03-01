#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

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

string tolower(const string& A);

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
  history("### Waveform(); // empty constructor\n"), typeIndex(0), timeScale("Time"),
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
  history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
	  << "### pwd = " << pwd << endl
	  << "### hostname = " << hostname << endl
	  << "### Waveform(\"" << DataFileName << "\", \"" << Format << "\"); // constructor from data file" << endl;
  
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
    history << "###### Begin Previous History\n";
    for(unsigned int i=0; i<Header.size(); ++i) {
      history << Header[i];
    }
    history << "###### End Previous History\n";
    t = vector<double>(Data.size());
    for(unsigned int i=0; i<t.size(); ++i) {
      t[i] = Data[i][0];
    }
    r = vector<double>(1, 0.0);
    
    //// Get mag and arg data
    // The data has vectors of vectors of components at a given time;
    // we transpose the matrix to vectors of components, each of which
    // is a vector through time.
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
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
	    << "### Waveform("
	    << Approximant << ", "
	    << delta << ", "
	    << chis << ", "
	    << chia << ", "
	    << v0 << ", "
	    << PNPhaseOrder << ", "
	    << PNAmplitudeOrder << ", "
	    << RowFormat(lm) << ", "
	    << nsave << ", "
	    << denseish
	    << "); // PN constructor" << endl;
  }
  
  vector<double> v(0), Phi(0);
  if(Approximant.compare("TaylorT1")==0) {
    if(nsave==-1) {
      TaylorT1(delta, chis, chia, v0, t, v, Phi);
    } else {
      TaylorT1(delta, chis, chia, v0, t, v, Phi, nsave, denseish);
    }
  } else if(Approximant.compare("TaylorT2")==0) {
    if(nsave==-1) {
      TaylorT2(delta, chis, chia, v0, t, v, Phi);
    } else {
      TaylorT2(delta, chis, chia, v0, t, v, Phi, nsave);
    }
  } else if(Approximant.compare("TaylorT3")==0) {
    if(nsave==-1) {
      TaylorT3(delta, chis, chia, v0, t, v, Phi);
    } else {
      TaylorT3(delta, chis, chia, v0, t, v, Phi, nsave);
    }
  } else if(Approximant.compare("TaylorT4")==0) {
    if(nsave==-1) {
      TaylorT4(delta, chis, chia, v0, t, v, Phi);
    } else {
      TaylorT4(delta, chis, chia, v0, t, v, Phi, nsave, denseish);
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
  WaveformAmplitudes PNAmp(delta, chis, chia);
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

// sum_{l=2}^{PNLMax} (2l+1) = 2*(PNLMax*(PNLMax-1)/2-1) + (PNLMax-2) = (PNLMax+3)*(PNLMax-1)
Waveform::Waveform(const string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
		   const double v0, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma,
		   const Matrix<int> LM, const int nsave, const bool denseish, const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  SetWaveformTypes();
  
  {
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
	    << "### Waveform("
	    << Approximant << ", "
	    << delta << ", ("
	    << chi1 << "), ("
	    << chi2 << "), "
	    << v0 << ", alpha, beta, gamma, "
	    << PNPhaseOrder << ", "
	    << PNAmplitudeOrder << ", "
	    << RowFormat(lm) << ", "
	    << nsave << ", "
	    << denseish
	    << ") // PN constructor" << endl;
  }
  
  vector<double> v(0), Phi(0), chis(0), chia(0);
  if(Approximant.compare("TaylorT4Spin")==0) {
    if(nsave==-1) {
      TaylorT4Spin(delta, chi1, chi2, v0, t, v, Phi,
		   chis, chia, alpha, beta, gamma);
    } else {
      TaylorT4Spin(delta, chi1, chi2, v0, t, v, Phi,
		   chis, chia, alpha, beta, gamma,
		   nsave, denseish);
    }
  } else {
    cerr << "Unknown approximant '" << Approximant << "'." << endl;
    throw("Bad approximant");
  }
  mag.resize(lm.nrows(), t.size());
  arg.resize(lm.nrows(), t.size());
  WaveformAmplitudes PNAmp(delta, chis[0], chia[0]);
  if(LM.nrows()>0) {
    for(unsigned int m=0; m<NModes(); ++m) {
      PNAmp.rhOverM(L(m), M(m), v, Phi, chis, chia, mag[m], arg[m]);
    }
  } else {
    unsigned int i=0;
    for(int l=2; l<=PNLMax; ++l) {
      for(int m=-l; m<=l; ++m) {
	lm[i][0] = l;
	lm[i][1] = m;
	PNAmp.rhOverM(l, m, v, Phi, chis, chia, mag[i], arg[i]);
	++i;
      }
    }
  }
  r.resize(1, 0.0);
}


// Member functions

void Waveform::swap(Waveform& b) {
  /// This call should not be recorded explicitly in the history, because the histories are swapped
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

//// Operators
////   These functions are defined in Waveform/Waveform_Operators.cpp

//// Extract features
////   These functions are defined in Waveform/Waveform_Features.cpp

//// Interpolation routines
////   These functions are defined in Waveform/Waveform_Interpolate.cpp

//// Adjust time axis
////   These functions are defined in Waveform/Waveform_AdjustTime.cpp

//// Physical conversions for extrapolations or conversion to frequency space
////   These functions are defined in Waveform/Waveform_PhysicalConversions.cpp

//// Manipulate (l,m) modes
////   These functions are defined in Waveform/Waveform_ManipulateModes.cpp

//// Align and hybridize waveforms
////   These functions are defined in Waveform/Waveform_AlignAndHybridize.cpp

//// Rotate by the given Euler angles or Quaternion
////   These functions are defined in Waveform/Waveform_Rotation.cpp

//// Output functions (members and non-members)
////   These functions are defined in Waveform/Waveform_Output.cpp

//// Radiation-frame utilities
////   These functions are defined in Waveform/Waveform_RadiationFrame.cpp


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
  size_t found=FileName.find_last_of("/\\");
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
    if(tolower(Header[j]).find(tolower("Mag{")) != string::npos || tolower(Header[j]).find(tolower("Abs{")) != string::npos || tolower(Header[j]).find(tolower("Amp{")) != string::npos) {
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
