/// \file

#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

#include "Waveform.hpp"
#include "Waveforms.hpp"

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

int GetWaveformType(const string& FullPath, const std::vector<string>& Header);
string GetFileFormat(const std::vector<string>& Header);
void GetWaveformTimeScaleAndLM(const string& FullPath, const std::vector<string>& Header, string& Scale, Matrix<int>& lm);


std::vector<string> WaveformObjects::Waveform::Types(12, "");
// Note on Waveform Types:
// In any system, h -- being strain -- should be dimensionless.
// When G=c=1, the dimensionless quantities are rMPsi4, rhdot, and rhOverM; as are rOverM and tOverM.
// When G and c are dimensionful, the dimensionless quantities are
//     -  (r/c) * (M*G/c^3) * Psi4
//     -  (r/c) * hdot
//     -  (r/c) * h / (M*G/c^3)
//     -  (r/c) / (M*G/c^3)
//     -  t / (M*G/c^3)
// To regain the dimensionful quantities, we simply need to remove the relevant dimensionful elements.
void SetWaveformTypes() {
  WaveformObjects::Waveform::Types[0]  = "rMPsi4";
  WaveformObjects::Waveform::Types[1]  = "rhdot";
  WaveformObjects::Waveform::Types[2]  = "rhOverM";
  WaveformObjects::Waveform::Types[3]  = "rPsi4";
  WaveformObjects::Waveform::Types[4]  = "rhdot";
  WaveformObjects::Waveform::Types[5]  = "rh";
  WaveformObjects::Waveform::Types[6]  = "MPsi4";
  WaveformObjects::Waveform::Types[7]  = "hdot";
  WaveformObjects::Waveform::Types[8]  = "hOverM";
  WaveformObjects::Waveform::Types[9]  = "Psi4";
  WaveformObjects::Waveform::Types[10] = "hdot";
  WaveformObjects::Waveform::Types[11] = "h";
  return;
}


// Constructors

/// Default constructor for an empty object
WaveformObjects::Waveform::Waveform() :
  history(""), typeIndex(0), timeScale("Time"),
  t(0), r(0), frame(0), lm(0, 2), mag(0, 0), arg(0, 0)
{
  SetWaveformTypes();
  {
    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    string pwd = path;
    char host[MAXHOSTNAMELEN];
    gethostname(host, MAXHOSTNAMELEN);
    string hostname = host;
    time_t rawtime;
    time ( &rawtime );
    string date = asctime ( localtime ( &rawtime ) );
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
            << "### pwd = " << pwd << endl
            << "### hostname = " << hostname << endl
            << "### date = " << date // comes with a newline
            << "### Waveform(); // empty constructor" << endl;
  }
}

/// Copy constructor
WaveformObjects::Waveform::Waveform(const Waveform& a) :
  history(a.history.str()), typeIndex(a.typeIndex), timeScale(a.timeScale),
  t(a.t), r(a.r), frame(a.frame), lm(a.lm), mag(a.mag), arg(a.arg)
{
  /// Simply copies all fields in the input object to the constructed
  /// object, including history
  history.seekp(0, ios_base::end);
}

/// Construct Waveform from data file
WaveformObjects::Waveform::Waveform(const std::string& DataFileName, const std::string& Format, const bool ZeroEnds) :
  history(""), typeIndex(0), timeScale("Time"),
  t(0), r(0), frame(0), lm(0, 2), mag(0, 0), arg(0, 0)
{
  /// \param DataFileName String containing absolute or relative path to file
  /// \param Format String of either 'MagArg' (for data in magnitude-argument format) or 'ReIm'
  /// \param ZeroEnds=false Bool indicating whether or not the ends of the data should be set to 0
  ///
  /// This is the main Waveform constructor, which reads either a .dat
  /// file or a metadata file with associated data files.  For path
  /// names ending in .bbh or .minimal, the file is assumed to be a
  /// NINJA2-type metadata file, containing exactly one section
  /// entitled either '[ht-ampphi-data]' or '[ht-data]'.  (In this
  /// case, the data type is deduced from the section title, and
  /// Format is ignored.)  The following lines then point to files
  /// containing the (l,m) data, where the first column is the time,
  /// and the following two lines contain either the real-imaginary or
  /// magnitude-argument data.
  ///
  /// For all other path names, the file is assumed to be a single
  /// data file containing all necessary (l,m) modes.  The first
  /// column is assumed to be time, and consecutive pairs of columns
  /// are assumed to contain either real-imaginary or
  /// magnitude-argument data.  The Waveform type is deduced from the
  /// file name.  For example, 'rhOverM_ExtrapolatedN5.dat' will be
  /// automatically assigned a type of 'rhOverM'.  Similarly, the time
  /// scale and (l,m) values for the pairs of columns are deduced from
  /// the header, assuming standard SpEC output.  That is, the header
  /// is assumed to contain lines like \n
  ///     # [1] = (t-r*)/M \n
  ///         # [2] = Mag{rMPsi4(2,-2)} \n
  ///         # [3] = Arg{rMPsi4(2,-2)} \n
  /// Finally, the data format is also deduced from the header, and a
  /// warning is issued if it mismatches the input parameter to this
  /// function.

  //cout << "Calling Waveform(const std::string& DataFileName, const std::string& Format, ...)" << endl;

  SetWaveformTypes();
  {
    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    string pwd = path;
    char host[MAXHOSTNAMELEN];
    gethostname(host, MAXHOSTNAMELEN);
    string hostname = host;
    time_t rawtime;
    time ( &rawtime );
    string date = asctime ( localtime ( &rawtime ) );
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
            << "### pwd = " << pwd << endl
            << "### hostname = " << hostname << endl
            << "### date = " << date // comes with a newline
            << "### Waveform(\"" << DataFileName << "\", \"" << Format << "\"); // constructor from data file" << endl;
  }

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

    // Open the metadata file and look for "[ht-ampphi-data]" or "[ht-data]" or "[psi4t-ampphi-data]" or "[psi4t-data]"
    string Format = "ReIm";
    int LineLength=8192;
    char LineChars[LineLength];
    string Line="";
    std::vector<string> Pair(2,"");
    std::vector<string> LandMString(2,"");
    std::vector<int> LandM(2);
    ifstream ifs(DataFileName.c_str(), ifstream::in);
    if(!ifs.is_open()) {
      cerr << "Couldn't open '" << DataFileName << "'" << endl;
      Throw1WithMessage("Bad file descriptor");
    }
    while(ifs.getline(LineChars, LineLength, '\n')) {
      string TrimmedLine(LineChars);
      TrimmedLine = TrimWhiteSpace(StripComments(TrimmedLine));
      if(TrimmedLine.compare("[ht-data]") == 0 || TrimmedLine.compare("[psi4t-data]") == 0) {
        Format = "ReIm";
        break;
      } else if(TrimmedLine.compare("[ht-ampphi-data]") == 0 || TrimmedLine.compare("[psi4t-ampphi-data]") == 0) {
        Format = "MagArg";
        break;
      }
    }

    // Loop through following lines getting data
    string DataFileName = "";
    std::vector<string> Header;
    std::vector<std::vector<double> > Times(0);
    std::vector<std::vector<double> > Re(0);
    std::vector<std::vector<double> > Im(0);
    while(ifs.getline(LineChars, LineLength, '\n')) {
      string LineCharsStripped(LineChars);
      LineCharsStripped = TrimWhiteSpace(StripComments(LineCharsStripped));
      if(LineCharsStripped.length()==0) { continue; }
      Pair = split(Line.assign(LineCharsStripped), '=');
      if(Pair[0].find("extraction-radius")!=string::npos) { continue; }
      if((Pair[0].find("[ht-data]")!=string::npos) ||
         (Pair[0].find("[psi4t-data]")!=string::npos) ||
         (Pair[0].find("[ht-ampphi-data]")!=string::npos) ||
         (Pair[0].find("[psi4t-ampphi-data]")!=string::npos))
        { break; }
      LandMString = split(Pair[0], ',');
      DataFileName = TrimWhiteSpace(Pair[1]);
      LandM[0] = atoi(LandMString[0].c_str());
      LandM[1] = atoi(LandMString[1].c_str());
      lm.push_back(LandM);

      //// Read data file
      std::vector<std::vector<double> > Data;
      ReadDatFile(Dir+DataFileName,  Data,  Header, true); // Read "transposed" data
      Times.push_back(std::vector<double>(Data[0].size()));
      Re.push_back(std::vector<double>(Data[0].size()));
      Im.push_back(std::vector<double>(Data[0].size()));
      unsigned int End=Times.size()-1;
      for(unsigned int i=0; i<Data[0].size(); ++i) {
        Times[End][i] = Data[0][i];
      }
      if(t.size()==0) {
        t = Times[End];
      } else {
        t = Intersection(t, Times[End], 0.05, -1.e300);
      }
      for(unsigned int i = 0; i<Data[0].size(); ++i) { // Loop over time steps
        Re[End][i] = Data[1][i];
        Im[End][i] = Data[2][i];
      }
    }
    ifs.close();

    r = std::vector<double>(1, 0.0);

    // Search for TimeScale, LM info, Format, and Waveform Type
    //LM = std::vector<std::vector<int> > (mag.size(), std::vector<int>(2, 0));
    //GetWaveformTimeScaleAndLM(Header, timeScale, LM);
    timeScale = "(t-r*)/M";
    typeIndex = GetWaveformType(DataFileName, Header);

    if(Format.compare("ReIm") == 0) {
      std::vector<std::vector<double> > ReA=Re, ImA=Im;
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

  } else {  // Treat this file like a normal data file

    // Read data file
    std::vector<std::vector<double> > Data;
    std::vector<string> Header;
    ReadDatFile(DataFileName,  Data,  Header, true);
    history << "#### Begin Previous History\n#";
    for(unsigned int i=0; i<Header.size(); ++i) {
      history << Header[i] << "\n#";
    }
    history << "### End Previous History\n";
    t = std::vector<double>(Data[0].size());
    for(unsigned int i=0; i<t.size(); ++i) {
      t[i] = Data[0][i];
    }
    r = std::vector<double>(1, 0.0);

    // Get mag and arg data
    // The data has std::vectors of std::vectors of components at a given time;
    // we transpose the matrix to std::vectors of components, each of which
    // is a std::vector through time.
    //ORIENTATION!!!  7 following lines
    std::vector<std::vector<double> > Re((Data.size()-1)/2, std::vector<double>(Data[0].size(), 0));
    std::vector<std::vector<double> > Im(Re.size(), std::vector<double>(Data[0].size(), 0));
    std::vector<double> ReEnds(Re.size(), 0.0);
    std::vector<double> ImEnds(Re.size(), 0.0);
    if(ZeroEnds) {
      for(unsigned int i = 0; i<Re.size(); ++i) { // Loop over components of Re
        ReEnds[i] = Data[2*i+1][Data.size()-1];
        ImEnds[i] = Data[2*i+2][Data.size()-1];
      }
    }
    for(unsigned int i = 0; i<Re.size(); ++i) { // Loop over components of Re
      for(unsigned int j = 0; j<Re[i].size(); ++j) { // Loop over time steps
        Re[i][j] = Data[2*i+1][j];
        Im[i][j] = Data[2*i+2][j];
      }
    }
    Data.clear();

    // Search for TimeScale, LM info, and Waveform Type
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
      Throw1WithMessage(("Unknown format " + Format).c_str());
    }
  }
}

/// Construct a single Waveform from a .bbh or .minimal file.
WaveformObjects::Waveform::Waveform(const std::string& BBHFileName,
                                    const int SectionToUse, // default: 0
                                    const WaveformUtilities::Matrix<int> LM) :
  history(""), typeIndex(0), timeScale("Time"), t(0), r(0), frame(0),
  lm(), mag(), arg()
{
  //cout << "Calling Waveform(const std::string& BBHFileName, ..." << endl;

  // Get the directory of the .bbh file
  string Dir = BBHFileName;
  size_t LastSlash = Dir.rfind("/");
  if (LastSlash!=string::npos) {
    Dir = Dir.substr(0, LastSlash+1);
  } else {
    Dir = "";
  }

  // Set up variables we will use and open the metadata file
  string Format = "ReIm";
  int LineLength=8192;
  char LineChars[LineLength];
  string Line="";
  std::vector<string> Pair(2,"");
  std::vector<string> LandMString(2,"");
  std::vector<int> LandM(2);
  ifstream ifs(BBHFileName.c_str(), ifstream::in);
  if(!ifs.is_open()) {
    cerr << "Couldn't open '" << BBHFileName << "'" << endl;
    Throw1WithMessage("Bad file descriptor");
  }

  // Skip to the desired [*-data] section
  std::vector<std::string> BBHDataSection;
  int SectionToUseHere=SectionToUse;
  while(ifs.getline(LineChars, LineLength, '\n')) {
    string LineCharsStripped(LineChars);
    LineCharsStripped = TrimWhiteSpace(StripComments(LineCharsStripped));
    if((LineCharsStripped.find("[ht-data]")!=string::npos) ||
       (LineCharsStripped.find("[psi4t-data]")!=string::npos) ||
       (LineCharsStripped.find("[ht-ampphi-data]")!=string::npos) ||
       (LineCharsStripped.find("[psi4t-ampphi-data]")!=string::npos))
      {
        if(SectionToUseHere==0) {
          BBHDataSection.push_back(LineCharsStripped);
          break;
        } else {
          --SectionToUseHere;
        }
      }
  }
  if(SectionToUseHere != 0) {
    cerr << "\nSectionToUse=" << SectionToUse << "\tSectionToUseHere=" << SectionToUseHere << endl;
    Throw1WithMessage("Not enough [*-data] sections in metadata file for requested section.");
  }

  // Loop through following lines getting data
  while(ifs.getline(LineChars, LineLength, '\n')) {
    string LineCharsStripped(LineChars);
    LineCharsStripped = TrimWhiteSpace(StripComments(LineCharsStripped));
    if((LineCharsStripped.find("[ht-data]")!=string::npos) ||
       (LineCharsStripped.find("[psi4t-data]")!=string::npos) ||
       (LineCharsStripped.find("[ht-ampphi-data]")!=string::npos) ||
       (LineCharsStripped.find("[psi4t-ampphi-data]")!=string::npos))
      {
        break;
      }
    BBHDataSection.push_back(LineCharsStripped);
  }
  *this = Waveform(BBHDataSection, Dir, LM);
}

/// Construct a single Waveform from a [*-data] bbh section.
WaveformObjects::Waveform::Waveform(const std::vector<std::string>& BBHDataSection,
                                    const std::string Dir,
                                    const WaveformUtilities::Matrix<int> LM) :
  history(""), typeIndex(0), timeScale("Time"), t(0), r(0), frame(0),
  lm(LM), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  /// The section is passed as a vector of strings, each element of
  /// which contains the "l,m = path" line from a metadata file.

  //cout << "Calling Waveform(const std::vector<std::string>& BBHDataSection, ..." << endl;

  Waveforms Ws(BBHDataSection, Dir, LM);
  if(Ws.size()==0) {
    cerr << "BBHDataSection = \"\"\"\n";
    for(unsigned int i=0; i<BBHDataSection.size(); ++i) {
      cerr << BBHDataSection[i] << endl;
    }
    cerr << "\n\"\"\"\nDir = \"" << Dir
         << "\"\nLM = " << RowFormat(LM) << "\"" << endl;
    Throw1WithMessage("Found no Waveforms.");
  }
  if(Ws.size()==1) {
    *this = Ws[0];
  } else {
    *this = Ws.Merge();
  }
  // SetHistory("");
  // {
  //   char path[MAXPATHLEN];
  //   getcwd(path, MAXPATHLEN);
  //   string pwd = path;
  //   char host[MAXHOSTNAMELEN];
  //   gethostname(host, MAXHOSTNAMELEN);
  //   string hostname = host;
  //   time_t rawtime;
  //   time ( &rawtime );
  //   string date = asctime ( localtime ( &rawtime ) );
  //   history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
  //        << "### pwd = " << pwd << endl
  //        << "### hostname = " << hostname << endl
  //        << "### date = " << date // comes with a newline
  //        << "### Waveform(BBHDataSection, " << RowFormat(LM) << ", " << Dir << "); // constructor from data file" << endl
  //        << "##### BBHDataSection = " << endl;
  //   for(unsigned int i=0; i<BBHDataSection.size(); ++i) {
  //     history << "#### " << BBHDataSection[i] << endl;
  //   }
  //   history << "##### end of BBHDataSection";
  // }
}


/// Simple PN/EOB constructor for non-precessing systems
WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const double chis, const double chia, const double v0,
                                    const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish,
                                    const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0), frame(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  /// \param Approximant ("TaylorT1"|"TaylorT2"|"TaylorT3"|"TaylorT4"|"EOB")
  /// \param delta \f$\delta = (M_1 - M_2) / (M_2 + M_2)\f$
  /// \param chis \f$\chi_s = (\chi_1+\chi_2)/2\f$
  /// \param chia \f$\chi_a = (\chi_1-\chi_2)/2\f$
  /// \param v0 Initial Newtonian velocity: \f$v = \left( \frac{G\, M\, \Omega}{c^3} \right)^{1/3}\f$
  /// \param LM Desired set of (l,m) modes for the output; if empty, output all modes up to \f$L = 8\f$
  /// \param nsave Number of points to output; note denseish
  /// \param denseish If true, output nsave points per time step taken by the integrator
  /// \param PNPhaseOrder Unused parameter
  /// \param PNAmplitudeOrder Unused parameter
  ///
  /// Constructs a PN/EOB inspiral for simple non-precessing systems.
  /// Note that in all cases, only the inspiral is returned -- EOB
  /// included.  To attach a ringdown (though a hackish technique) see
  /// also the AttachQNMs function.
  ///
  /// The total number of modes required for \f$L\f$ is given by
  /// \f{align}{
  /// N_{\text{modes}}
  ///   &= \sum_{l=2}^{L} (2l+1) \\
  ///   &= 2\left[L\, (L-1)/2-1\right] + (L-2) \\
  ///   &= (L+3)\, (L-1)
  /// \f}

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

  std::vector<double> v(0), Phi(0);
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
    Throw1WithMessage("Bad approximant");
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


/// PN/EOB constructor for precessing systems
WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
                                    const double v0, const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish,
                                    const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0), frame(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  /// \param Approximant ("TaylorT4Spin")
  /// \param delta \f$\delta = (M_1 - M_2) / (M_2 + M_2)\f$
  /// \param chi1 \f$\vec{\chi}_1 = \vec{S}_1 / M_1^2\f$
  /// \param chi2 \f$\vec{\chi}_2 = \vec{S}_2 / M_2^2\f$
  /// \param v0 Initial Newtonian velocity: \f$v = \left( \frac{G\, M\, \Omega}{c^3} \right)^{1/3}\f$
  /// \param LM Desired set of (l,m) modes for the output; if empty, output all modes up to \f$L = 8\f$
  /// \param nsave Number of points to output; note denseish
  /// \param denseish If true, output nsave points per time step taken by the integrator
  /// \param PNPhaseOrder Unused parameter
  /// \param PNAmplitudeOrder Unused parameter
  ///
  /// Constructs a PN inspiral for precessing systems using the method
  /// described in [Phys. Rev. D 84, 124011
  /// (2011)](http://link.aps.org/doi/10.1103/PhysRevD.84.124011)
  SetWaveformTypes();

  std::vector<double> alpha, beta, gamma;
  {
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
            << "### Waveform("
            << Approximant << ", "
            << delta << ", ("
            << chi1 << "), ("
            << chi2 << "), "
            << v0 << ", "
            << PNPhaseOrder << ", "
            << PNAmplitudeOrder << ", "
            << RowFormat(lm) << ", "
            << nsave << ", "
            << denseish
            << ") // PN constructor" << endl;
  }

  std::vector<double> v(0), Phi(0), chis(0), chia(0);
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
    Throw1WithMessage("Bad approximant");
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
  frame = Quaternions(alpha, beta, gamma);
  r.resize(1, 0.0);
}

/// PN/EOB constructor for precessing systems
WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
                                    const double v0, vector<vector<double> >& S1, vector<vector<double> >& S2, vector<vector<double> >& LNHat,
                                    const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish,
                                    const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0), frame(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  /// \param Approximant ("TaylorT4Spin")
  /// \param delta \f$\delta = (M_1 - M_2) / (M_2 + M_2)\f$
  /// \param chi1 \f$\vec{\chi}_1 = \vec{S}_1 / M_1^2\f$
  /// \param chi2 \f$\vec{\chi}_2 = \vec{S}_2 / M_2^2\f$
  /// \param v0 Initial Newtonian velocity: \f$v = \left( \frac{G\, M\, \Omega}{c^3} \right)^{1/3}\f$
  /// \param S1 Output vector of vectors for first spin component
  /// \param S2 Output vector of vectors for second spin component
  /// \param LNHat Output vector of vectors for Newtonian orbital angular momentum direction
  /// \param LM Desired set of (l,m) modes for the output; if empty, output all modes up to \f$L = 8\f$
  /// \param nsave Number of points to output; note denseish
  /// \param denseish If true, output nsave points per time step taken by the integrator
  /// \param PNPhaseOrder Unused parameter
  /// \param PNAmplitudeOrder Unused parameter
  ///
  /// Constructs a PN inspiral for precessing systems using the method
  /// described in [Phys. Rev. D 84, 124011
  /// (2011)](http://link.aps.org/doi/10.1103/PhysRevD.84.124011)
  ///
  /// The result is in a stationary frame, though the waveform is
  /// computed in the minimal-rotation frame, and transformed back.
  /// The returned Waveform has trivial `frame` data, but the LNHat
  /// vector can be used to re-derive the coordinate-based
  /// minimal-rotation frame.  (This is the frame judged by the
  /// coordinate positions of the BHs in the PN approximation.  Note
  /// that this is distinct from the information gained by looking at
  /// the Waveform alone.)
  SetWaveformTypes();

  {
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
            << "### Waveform("
            << Approximant << ", "
            << delta << ", ("
            << chi1 << "), ("
            << chi2 << "), "
            << v0 << ", S1, S2, LNHat, "
            << PNPhaseOrder << ", "
            << PNAmplitudeOrder << ", "
            << RowFormat(lm) << ", "
            << nsave << ", "
            << denseish
            << ") // PN constructor" << endl;
  }

  std::vector<double> v(0), Phi(0);
  if(Approximant.compare("TaylorT4Spin")==0) {
    if(nsave==-1) {
      TaylorT4Spin(delta, chi1, chi2, v0, t, v, Phi,
                   S1, S2, LNHat);
    } else {
      TaylorT4Spin(delta, chi1, chi2, v0, t, v, Phi,
                   S1, S2, LNHat,
                   nsave, denseish);
    }
  } else {
    cerr << "Unknown approximant '" << Approximant << "'." << endl;
    Throw1WithMessage("Bad approximant");
  }
  // Calculate chis and chia (magnitudes) and the frame from LNHat, so
  // that we may transform back into the stationary frame.
  const vector<double> chis = norm((0.5*(S1+S2)).RawData());
  const vector<double> chia = norm((0.5*(S1-S2)).RawData());
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


///PN Constructor for tidal systems
WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const double chis,
				    const double chia, const double v0, const double love1, const double love2,
				    const double compact1, const double compact2,
				    const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish,
				    const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0), frame(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  /// \param Approximant ("TaylorT4Tidal")
  /// \param delta \f$\delta = (M_1 - M_2) / (M_2 + M_2)\f$
  /// \param chis \f$\chi_s = (\chi_1+\chi_2)/2\f$
  /// \param chia \f$\chi_a = (\chi_1-\chi_2)/2\f$
  /// \param v0 Initial Newtonian velocity: \f$v = \left( \frac{G\, M\, \Omega}{c^3} \right)^{1/3}\f$
  /// \param love1 = Object 1's Love Number corresponding to the gravito-electric tidal polarizability
  /// \param love2 = Object 2's Love Number corresponding to the gravito-electric tidal polarizability
  /// \param compact1 = Object 1's Compactness Parameter
  /// \param compact2 = Object 2's Compactness Parameter
  /// \param LM Desired set of (l,m) modes for the output; if empty, output all modes up to \f$L = 8\f$
  /// \param nsave Number of points to output; note denseish
  /// \param denseish If true, output nsave points per time step taken by the integrator
  /// \param PNPhaseOrder Unused parameter
  /// \param PNAmplitudeOrder Unused parameter
  ///
  /// Construct a TaylorT4 Waveform including Tidal terms at 10th and 12th order in the PN parameter, v.
  /// This is only for the inspiral portion of the binary.
  /// The expression of the tidal terms can be found in [Phys. Rev. D 84, 024017
  /// (2011)] which is also [arXiv:1103.3874]
  /// This might be only good for the l=2 modes.

  SetWaveformTypes();

  {
    history << "### Code revision 'git rev-parse HEAD' = " << GitRevision << endl
	    << "### Waveform("
	    << Approximant << ", "
	    << delta << ", "
	    << chis << ", "
	    << chia << ", "
	    << v0 << ", "
	    << love1 << ", "
	    << love2 << ", "
	    << compact1 << ", "
	    << compact2 << ", "
	    << PNPhaseOrder << ", "
	    << PNAmplitudeOrder << ", "
	    << RowFormat(lm) << ", "
	    << nsave << ", "
	    << denseish
	    << "); // PN constructor" << endl;
  }

  if( compact1==0 or compact2==0 ){
    cerr << "Compactness parameter of an object is M/R= 0." << endl;
    Throw1WithMessage("Bad compactness parameter");
  }

  std::vector<double> v(0), Phi(0);
  if(Approximant.compare("TaylorT4Tidal")==0) {
    if(nsave==-1) {
      TaylorT4Tidal(delta, chis, chia, v0, t, v, Phi,
		   love1, love2, compact1, compact2);
    } else {
      TaylorT4Tidal(delta, chis, chia, v0, t, v, Phi,
		   love1, love2, compact1, compact2,
		   nsave, denseish);
    }
  } else if(Approximant.compare("TaylorT3Tidal")==0) {
    if(nsave==-1) {
      TaylorT3Tidal(delta, chis, chia, v0, t, v, Phi,
                   love1, love2, compact1, compact2);
    } else {
      TaylorT3Tidal(delta, chis, chia, v0, t, v, Phi,
                   love1, love2, compact1, compact2,
                   nsave);
    }
  } else if(Approximant.compare("TaylorT2Tidal")==0) {
    if(nsave==-1) {
      TaylorT2Tidal(delta, chis, chia, v0, t, v, Phi,
		   love1, love2, compact1, compact2);
    } else {
      TaylorT2Tidal(delta, chis, chia, v0, t, v, Phi,
		   love1, love2, compact1, compact2,
		   nsave);
    }
  } else if(Approximant.compare("TaylorT1Tidal")==0) {
    if(nsave==-1) {
      TaylorT1Tidal(delta, chis, chia, v0, t, v, Phi,
		   love1, love2, compact1, compact2);
    } else {
      TaylorT1Tidal(delta, chis, chia, v0, t, v, Phi,
		   love1, love2, compact1, compact2,
		   nsave, denseish);
    }
  } else {
    cerr << "Unknown approximant '" << Approximant << "'." << endl;
    Throw1WithMessage("Bad approximant");
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


// /// PN/EOB constructor for precessing systems
// WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
//                                  const double v0, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma,
//                                  const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish,
//                                  const double PNPhaseOrder, const double PNAmplitudeOrder) :
//   history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0), frame(0),
//   lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
// {
//   /// \param Approximant ("TaylorT4Spin")
//   /// \param delta \f$\delta = (M_1 - M_2) / (M_2 + M_2)\f$
//   /// \param chi1 \f$\vec{\chi}_1 = \vec{S}_1 / M_1^2\f$
//   /// \param chi2 \f$\vec{\chi}_2 = \vec{S}_2 / M_2^2\f$
//   /// \param v0 Initial Newtonian velocity: \f$v = \left( \frac{G\, M\, \Omega}{c^3} \right)^{1/3}\f$
//   /// \param alpha Returns vector containing \f$\alpha\f$ coordinates of frame rotation
//   /// \param beta Returns vector containing \f$\beta\f$ coordinates of frame rotation
//   /// \param gamma Returns vector containing \f$\gamma\f$ coordinates of frame rotation
//   /// \param LM Desired set of (l,m) modes for the output; if empty, output all modes up to \f$L = 8\f$
//   /// \param nsave Number of points to output; note denseish
//   /// \param denseish If true, output nsave points per time step taken by the integrator
//   /// \param PNPhaseOrder Unused parameter
//   /// \param PNAmplitudeOrder Unused parameter
//   ///
//   /// Constructs a PN inspiral for precessing systems using the method
//   /// described in [Phys. Rev. D 84, 124011
//   /// (2011)](http://link.aps.org/doi/10.1103/PhysRevD.84.124011)
//   SetWaveformTypes();

//   {
//     history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
//          << "### Waveform("
//          << Approximant << ", "
//          << delta << ", ("
//          << chi1 << "), ("
//          << chi2 << "), "
//          << v0 << ", alpha, beta, gamma, "
//          << PNPhaseOrder << ", "
//          << PNAmplitudeOrder << ", "
//          << RowFormat(lm) << ", "
//          << nsave << ", "
//          << denseish
//          << ") // PN constructor" << endl;
//   }

//   std::vector<double> v(0), Phi(0), chis(0), chia(0);
//   if(Approximant.compare("TaylorT4Spin")==0) {
//     if(nsave==-1) {
//       TaylorT4Spin(delta, chi1, chi2, v0, t, v, Phi,
//                 chis, chia, alpha, beta, gamma);
//     } else {
//       TaylorT4Spin(delta, chi1, chi2, v0, t, v, Phi,
//                 chis, chia, alpha, beta, gamma,
//                 nsave, denseish);
//     }
//   } else {
//     cerr << "Unknown approximant '" << Approximant << "'." << endl;
//     Throw1WithMessage("Bad approximant");
//   }
//   mag.resize(lm.nrows(), t.size());
//   arg.resize(lm.nrows(), t.size());
//   WaveformAmplitudes PNAmp(delta, chis[0], chia[0]);
//   if(LM.nrows()>0) {
//     for(unsigned int m=0; m<NModes(); ++m) {
//       PNAmp.rhOverM(L(m), M(m), v, Phi, chis, chia, mag[m], arg[m]);
//     }
//   } else {
//     unsigned int i=0;
//     for(int l=2; l<=PNLMax; ++l) {
//       for(int m=-l; m<=l; ++m) {
//      lm[i][0] = l;
//      lm[i][1] = m;
//      PNAmp.rhOverM(l, m, v, Phi, chis, chia, mag[i], arg[i]);
//      ++i;
//       }
//     }
//   }
//   r.resize(1, 0.0);
// }


// Member functions

/// Efficiently swap data between two Waveform objects.
void WaveformObjects::Waveform::swap(Waveform& b) {
  /// This function uses the std::vector method 'swap' which simply
  /// swaps pointers to data, for efficiency.

  // This call should not be recorded explicitly in the history,
  // because the histories are swapped
  { const string historyb=b.history.str(); b.history.str(history.str()); history.str(historyb); }
  history.seekp(0, ios_base::end);
  b.history.seekp(0, ios_base::end);
  { const unsigned int typeIndexb = b.typeIndex; b.typeIndex=typeIndex; typeIndex=typeIndexb; }
  timeScale.swap(b.timeScale);
  t.swap(b.t);
  r.swap(b.r);
  frame.swap(b.frame);
  lm.swap(b.lm);
  mag.swap(b.mag);
  arg.swap(b.arg);
  return;
}

//
// Constructors

// x
// Operators
//   These functions are defined in Waveform/Waveform_Operators.cpp

// x
// Extract features
//   These functions are defined in Waveform/Waveform_Features.cpp

// x
// Interpolation routines
//   These functions are defined in Waveform/Waveform_Interpolate.cpp

// x
// Adjust time axis
//   These functions are defined in Waveform/Waveform_AdjustTime.cpp

// x
// Physical conversions for extrapolations or conversion to frequency space
//   These functions are defined in Waveform/Waveform_PhysicalConversions.cpp

// x
// Manipulate (l,m) modes
//   These functions are defined in Waveform/Waveform_ManipulateModes.cpp

//
// Align and hybridize waveforms
//   These functions are defined in Waveform/Waveform_AlignAndHybridize.cpp

// x
// Rotate by the given Euler angles or Quaternion
//   These functions are defined in Waveform/Waveform_Rotation.cpp

//
// Output functions (members and non-members)
//   These functions are defined in Waveform/Waveform_Output.cpp

// x
// Radiation-frame utilities
//   These functions are defined in Waveform/Waveform_RadiationFrame.cpp


// Utilities for this file only
std::string tolower(const std::string& A) {
  string B = A;
  string::iterator it;
  for(it=B.begin(); it<B.end(); it++) {
    *it = tolower(*it);
  }
  return B;
}

int GetWaveformType(const std::string& FullPath, const std::vector<std::string>& Header) {
  int typeIndex = 0;
  string FileName = FullPath;

  // Look for the info at the beginning of the file name
  size_t found=FileName.find_last_of("/\\");
  if (found!=string::npos) { FileName = FileName.substr(found+1); }
  for(unsigned int i=0; i<Waveform::Types.size(); ++i) {
    if(tolower(FileName).find(tolower(Waveform::Types[i])) != string::npos &&
       tolower(FileName).find(tolower(Waveform::Types[i])) == 0) {
      return i;
    }
  }

  // Look for the info in the Header
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

std::string GetFileFormat(const std::vector<std::string>& Header) {
  string DetectedFormat("");

  // Look for the info in the Header
  for(unsigned int j=0; j<Header.size(); ++j) {
    if(tolower(Header[j]).find(tolower("Mag{")) != string::npos || tolower(Header[j]).find(tolower("Abs{")) != string::npos || tolower(Header[j]).find(tolower("Amp{")) != string::npos) {
      DetectedFormat = "MagArg";
      if(Header[j].substr(0,2).compare("##")!=0) {
        break;
      }
    } else if(tolower(Header[j]).find(tolower("r*Re")) != string::npos) {
      DetectedFormat = "ReIm";
      if(Header[j].substr(0,2).compare("##")!=0) {
        break;
      }
    }
  }

  return DetectedFormat;
}

void GetWaveformTimeScaleAndLM(const std::string& FullPath, const std::vector<std::string>& Header, std::string& Scale, Matrix<int>& lm) {
  // Look for the info at the beginning of the file name
  size_t found;
  string FileName = FullPath;
  found=FileName.find_last_of("/\\");
  if (found!=string::npos) { FileName = FileName.substr(found+1); }
  if((found = tolower(FileName).find("_l")) != string::npos &&
     tolower(FileName).find("_m", found) != string::npos)
    {
      if(lm.nrows()!=1) {
        cerr << "\nlm.nrows()=" << lm.nrows() << " but file name " << FileName << " indicates there is just one mode." << endl;
        Throw1WithMessage("Bad LM modes");
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
    Throw1WithMessage("Bad LM modes");
  }
  return;
}
