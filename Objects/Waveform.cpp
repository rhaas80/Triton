/// \file

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

int GetWaveformType(const string& FullPath, const std::vector<string>& Header);
string GetFileFormat(const std::vector<string>& Header);
void GetWaveformTimeScaleAndLM(const string& FullPath, const std::vector<string>& Header, string& Scale, Matrix<int>& lm);


/// \namespace WaveformObjects
/// \brief The collection of objects that define encapsulated
/// Waveform-type objects.  This includes Waveform, WaveformAtAPoint,
/// WaveformFT, and Waveforms.

/// \class WaveformObjects::Waveform
/// \brief Fundamental object encapsulating waveform data, such as
/// time, amplitude, and phase information.
/// 
/// This object provides the main user interface for this collection
/// of code.  The various methods for this class are intended to
/// provide all manipulations that might be necessary in the course of
/// waveform analysis.

// ** Get-data access functions
/// \fn inline const unsigned int WaveformObjects::Waveform::NTimes() const
/// \brief Return the number of time steps in the data.

/// \fn inline const unsigned int WaveformObjects::Waveform::NModes() const
/// \brief Return the number of modes in the data.

/// \fn inline const unsigned int WaveformObjects::Waveform::TypeIndex() const
/// \brief Return the index for the Type of the data.
/// 
/// A more useful function might be the 'Type()' function, which
/// returns the type as a string.

/// \fn inline const std::string WaveformObjects::Waveform::HistoryStr() const
/// \brief Return a string containing the history of the Waveform.

/// \fn inline const std::string WaveformObjects::Waveform::TimeScale() const
/// \brief Return a string describing the time scale (e.g., units).

/// \fn inline const std::string WaveformObjects::Waveform::Type() const
/// \brief Return a string describing the Type of the data.

/// \fn inline const double WaveformObjects::Waveform::T(const unsigned int Time) const
/// \brief Return the time value at time index 'Time'.

/// \fn inline const double WaveformObjects::Waveform::R(const unsigned int Time) const
/// \brief Return the radius of the measured data at time index 'Time'.

/// \fn inline const WaveformUtilities::Quaternion& WaveformObjects::Waveform::Frame(const unsigned int Time) const
/// \brief Return a quaternion describing the frame in which the data are decomposed at time index 'Time'.

/// \fn inline const double WaveformObjects::Waveform::Mag(const unsigned int Mode, const unsigned int Time) const
/// \brief Return the magnitude of mode 'Mode' at time index 'Time'.

/// \fn inline const double WaveformObjects::Waveform::Arg(const unsigned int Mode, const unsigned int Time) const
/// \brief Return the argument (phase) of mode 'Mode' at time index 'Time'.

/// \fn inline const std::vector<double>& WaveformObjects::Waveform::T() const
/// \brief Return the entire vector of times in the data.

/// \fn inline const std::vector<double>& WaveformObjects::Waveform::R() const
/// \brief Return the vector of radii of the measured data.
/// 
/// Note that this vector may contain 0, 1, or NTimes() elements.  If
/// 1, the radius is assumed to be constant.

/// \fn inline const std::vector<WaveformUtilities::Quaternion>& WaveformObjects::Waveform::Frame() const
/// \brief Return the entire vector of frames in which the data are decomposed.
/// 
/// Note that this vector may contain 0, 1, or NTimes() elements.  If
/// 1, the frame is assumed to be constant.  If 0, it is constant, and
/// equal to the standard frame.

/// \fn inline const int WaveformObjects::Waveform::L(const unsigned int Mode) const
/// \brief Return the 'l' (azimuthal) index of mode 'Mode'.

/// \fn inline const int WaveformObjects::Waveform::M(const unsigned int Mode) const
/// \brief Return the 'm' (magnetic) index of mode 'Mode'.

/// \fn inline const std::vector<int>& WaveformObjects::Waveform::LM(const unsigned int Mode) const
/// \brief Return the (l,m) indices of mode 'Mode'.

/// \fn inline const std::vector<double>& WaveformObjects::Waveform::Mag(const unsigned int Mode) const
/// \brief Return the magnitude of mode 'Mode' as a function of time.

/// \fn inline const std::vector<double>& WaveformObjects::Waveform::Arg(const unsigned int Mode) const
/// \brief Return the argument (phase) of mode 'Mode' as a function of time.

/// \fn inline const std::vector<std::vector<int> >& WaveformObjects::Waveform::LM() const
/// \brief Return the (l,m) data for all modes.
/// 
/// The return value is actually a Matrix when called from c++.

/// \fn inline const std::vector<std::vector<double> >& WaveformObjects::Waveform::Mag() const
/// \brief Return the magnitude of all modes as a function of time.
/// 
/// The return value is actually a Matrix when called from c++.

/// \fn inline const std::vector<std::vector<double> >& WaveformObjects::Waveform::Arg() const
/// \brief Return the argument (phase) of all modes as a function of time.
/// 
/// The return value is actually a Matrix when called from c++.

// ** Set-data implicit access functions
/// \fn inline unsigned int& WaveformObjects::Waveform::TypeIndexRef()
/// \brief Return a reference to the index for the Type of the data.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::stringstream& WaveformObjects::Waveform::History()
/// \brief Return a reference to the stringstream recording the Waveform's history.
/// 
/// Note that the methods 'SetHistory(const std::string& Hist)' and
/// 'AppendHistory(const std::string& Hist)' are also available.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::string& WaveformObjects::Waveform::TimeScaleRef()
/// \brief Return a reference to the string describing the time scale (e.g., units).
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline double& WaveformObjects::Waveform::TRef(const unsigned int Time)
/// \brief Return a reference 
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline double& WaveformObjects::Waveform::RRef(const unsigned int Time)
/// \brief Return a reference to the radius at time index 'Time'.
/// 
/// Note that this may return a reference to the sole element of the
/// vector of radii, in the case that the radius is constant.  Thus,
/// setting the radius at different instants of time may simply
/// overwrite that sole value.  It would be better to use 'RRef()' for
/// that application.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline WaveformUtilities::Quaternion& WaveformObjects::Waveform::FrameRef(const unsigned int Time)
/// \brief Return a reference to the frames in which the data are decomposed at time index 'Time'.
/// 
/// Note that this may return a reference to the sole element of the
/// vector of frames, in the case that the frame is constant.  Thus,
/// setting the frame at different instants of time may simply
/// overwrite that sole value.  It would be better to use 'FrameRef()'
/// for that application.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline double& WaveformObjects::Waveform::MagRef(const unsigned int Mode, const unsigned int Time)
/// \brief Return a reference to the magnitude of mode 'Mode' at time index 'Time'.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline double& WaveformObjects::Waveform::ArgRef(const unsigned int Mode, const unsigned int Time)
/// \brief Return a reference to the argument (phase) of mode 'Mode' at time index 'Time'.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::vector<double>& WaveformObjects::Waveform::TRef()
/// \brief Return a reference to the entire vector of times in the data.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::vector<double>& WaveformObjects::Waveform::RRef()
/// \brief Return a reference to the vector of radii of the measured data.
/// 
/// Note that this vector may contain 0, 1, or NTimes() elements.  If
/// 1, the radius is assumed to be constant.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::vector<WaveformUtilities::Quaternion>& WaveformObjects::Waveform::FrameRef()
/// \brief Return a reference to the vector of frames in which the data are decomposed.
/// 
/// Note that this vector may contain 0, 1, or NTimes() elements.  If
/// 1, the frame is assumed to be constant.  If 0, it is constant, and
/// equal to the standard frame.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline int& WaveformObjects::Waveform::LRef(const unsigned int Mode)
/// \brief Return a reference to the l (azimuthal) index of mode 'Mode'.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline int& WaveformObjects::Waveform::MRef(const unsigned int Mode)
/// \brief Return a reference to the m (magnetic) index of mode 'Mode'.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::vector<int>& WaveformObjects::Waveform::LMRef(const unsigned int Mode)
/// \brief Return a reference to the (l,m) data of mode 'Mode'.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::vector<double>& WaveformObjects::Waveform::MagRef(const unsigned int Mode)
/// \brief Return a reference to the magnitude of mode 'Mode' as a function of time.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline std::vector<double>& WaveformObjects::Waveform::ArgRef(const unsigned int Mode)
/// \brief Return a reference to the argument (phase) of mode 'Mode' as a function of time.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline WaveformUtilities::Matrix<int>& WaveformObjects::Waveform::LMRef()
/// \brief Return a reference to the (l,m) data for all modes.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline WaveformUtilities::Matrix<double>& WaveformObjects::Waveform::MagRef()
/// \brief Return a reference to the magnitude of all modes as a function of time.
/// 
/// This function is not available via SWIG (e.g., in python).

/// \fn inline WaveformUtilities::Matrix<double>& WaveformObjects::Waveform::ArgRef()
/// \brief Return a reference to the argument (phase) of all modes as a function of time.
/// 
/// This function is not available via SWIG (e.g., in python).

// ** Set-data explicit access functions
/// \fn inline void WaveformObjects::Waveform::AppendHistory(const std::string& Hist)
/// \brief Append the input string to the Waveform history.

/// \fn inline void WaveformObjects::Waveform::SetHistory(const std::string& Hist)
/// \brief Replace the Waveform history with the input string.

/// \fn inline void WaveformObjects::Waveform::SetTypeIndex(const unsigned int NewTypeIndex)
/// \brief Change the Waveform type index to the input int.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetTimeScale(const std::string& NewTimeScale)
/// \brief Change the Waveform time scale to the input string.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetT(const unsigned int Time, const double a)
/// \brief Set the time at index 'Time' to value 'a'.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetT(const std::vector<double>& a)
/// \brief Set the time vector to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetR(const unsigned int Time, const double a)
/// \brief Set the radius at index 'Time' to value 'a'.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetR(const std::vector<double>& a)
/// \brief Set the radius vector to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetFrame(const unsigned int Time, const WaveformUtilities::Quaternion& a)
/// \brief Set the frame at index 'Time' to the value 'a'.
/// 
/// Note that no transformation of the modes is done by this function.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetFrame(const std::vector<WaveformUtilities::Quaternion>& a)
/// \brief Set the frame to the input data.
/// 
/// Note that no transformation of the modes is done by this function.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetLM(const unsigned int Mode, const std::vector<int>& a)
/// \brief Set the (l,m) data of mode 'Mode' to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetLM(const WaveformUtilities::Matrix<int>& a)
/// \brief Set the (l,m) data to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetMag(const unsigned int Mode, const unsigned int Time, const double a)
/// \brief Set the magnitude of mode 'Mode' at time index 'Time' to the value 'a'.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetMag(const unsigned int Mode, const std::vector<double>& a)
/// \brief Set the magnitude of mode 'Mode' to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetMag(const WaveformUtilities::Matrix<double>& a)
/// \brief Set the magnitude of the Waveform to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetArg(const unsigned int Mode, const unsigned int Time, const double a)
/// \brief Set the argument (phase) of mode 'Mode' at time index 'Time' to the value 'a'.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetArg(const unsigned int Mode, const std::vector<double>& a)
/// \brief Set the argument (phase) of mode 'Mode' to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.

/// \fn inline void WaveformObjects::Waveform::SetArg(const WaveformUtilities::Matrix<double>& a)
/// \brief Set the argument (phase) of the Waveform to the input data.
/// 
/// This function is only available via SWIG (e.g., python), not c++.
/// In c++, use the reference method.


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
  history("### Waveform(); // empty constructor\n"), typeIndex(0), timeScale("Time"),
  t(0), r(0), frame(0), lm(0, 2), mag(0, 0), arg(0, 0)
{
  SetWaveformTypes();
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
  ///     # [2] = Mag{rMPsi4(2,-2)} \n
  ///     # [3] = Arg{rMPsi4(2,-2)} \n
  /// Finally, the data format is also deduced from the header, and a
  /// warning is issued if it mismatches the input parameter to this
  /// function.
  
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
    std::vector<string> Pair(2,"");
    std::vector<string> LandMString(2,"");
    std::vector<int> LandM(2);
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
    std::vector<string> Header;
    std::vector<std::vector<double> > Times(0);
    std::vector<std::vector<double> > Re(0);
    std::vector<std::vector<double> > Im(0);
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
      std::vector<std::vector<double> > Data;
      ReadDatFile(Dir+DataFileName,  Data,  Header);
      Times.push_back(std::vector<double>(Data.size()));
      Re.push_back(std::vector<double>(Data.size()));
      Im.push_back(std::vector<double>(Data.size()));
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
    ReadDatFile(DataFileName,  Data,  Header);
    history << "#### Begin Previous History\n#";
    for(unsigned int i=0; i<Header.size(); ++i) {
      history << Header[i] << "\n#";
    }
    history << "### End Previous History\n";
    t = std::vector<double>(Data.size());
    for(unsigned int i=0; i<t.size(); ++i) {
      t[i] = Data[i][0];
    }
    r = std::vector<double>(1, 0.0);
    
    // Get mag and arg data
    // The data has std::vectors of std::vectors of components at a given time;
    // we transpose the matrix to std::vectors of components, each of which
    // is a std::vector through time.
    //ORIENTATION!!!  7 following lines
    std::vector<std::vector<double> > Re((Data[0].size()-1)/2, std::vector<double>(Data.size(), 0));
    std::vector<std::vector<double> > Im(Re.size(), std::vector<double>(Data.size(), 0));
    std::vector<double> ReEnds(Re.size(), 0.0);
    std::vector<double> ImEnds(Re.size(), 0.0);
    for(unsigned int i = 0; i<Re.size(); ++i) { // Loop over components of Re
      ReEnds[i] = (ZeroEnds ? Data[Data.size()-1][2*i+1] : 0.0);
      ImEnds[i] = (ZeroEnds ? Data[Data.size()-1][2*i+2] : 0.0);
      for(unsigned int j = 0; j<Re[i].size(); ++j) { // Loop over time steps
	Re[i][j] = Data[j][2*i+1];
	Im[i][j] = Data[j][2*i+2];
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
      throw(("Unknown format " + Format).c_str());
    }
  }
}

/// Simple PN/EOB constructor for non-precessing systems
WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const double chis, const double chia, const double v0,
		   const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish, const double PNPhaseOrder, const double PNAmplitudeOrder) :
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


/// PN/EOB constructor for precessing systems
WaveformObjects::Waveform::Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
		   const double v0, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma,
		   const WaveformUtilities::Matrix<int> LM, const int nsave, const bool denseish, const double PNPhaseOrder, const double PNAmplitudeOrder) :
  history(""), typeIndex(2), timeScale("(t-r*)/M"), t(0), r(0), frame(0),
  lm(LM.nrows()>0 ? LM : Matrix<int>((PNLMax+3)*(PNLMax-1), 2)), mag(lm.nrows(), 0), arg(lm.nrows(), 0)
{
  /// \param Approximant ("TaylorT4Spin")
  /// \param delta \f$\delta = (M_1 - M_2) / (M_2 + M_2)\f$
  /// \param chi1 \f$\vec{\chi}_1 = \vec{S}_1 / M_1^2\f$
  /// \param chi2 \f$\vec{\chi}_2 = \vec{S}_2 / M_2^2\f$
  /// \param v0 Initial Newtonian velocity: \f$v = \left( \frac{G\, M\, \Omega}{c^3} \right)^{1/3}\f$
  /// \param alpha Returns vector containing \f$\alpha\f$ coordinates of frame rotation
  /// \param beta Returns vector containing \f$\beta\f$ coordinates of frame rotation
  /// \param gamma Returns vector containing \f$\gamma\f$ coordinates of frame rotation
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

// Operators
//   These functions are defined in Waveform/Waveform_Operators.cpp

// Extract features
//   These functions are defined in Waveform/Waveform_Features.cpp

// Interpolation routines
//   These functions are defined in Waveform/Waveform_Interpolate.cpp

// Adjust time axis
//   These functions are defined in Waveform/Waveform_AdjustTime.cpp

// Physical conversions for extrapolations or conversion to frequency space
//   These functions are defined in Waveform/Waveform_PhysicalConversions.cpp

// Manipulate (l,m) modes
//   These functions are defined in Waveform/Waveform_ManipulateModes.cpp

// Align and hybridize waveforms
//   These functions are defined in Waveform/Waveform_AlignAndHybridize.cpp

// Rotate by the given Euler angles or Quaternion
//   These functions are defined in Waveform/Waveform_Rotation.cpp

// Output functions (members and non-members)
//   These functions are defined in Waveform/Waveform_Output.cpp

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
      break;
    } else if(tolower(Header[j]).find(tolower("r*Re")) != string::npos) {
      DetectedFormat = "ReIm";
      break;
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
