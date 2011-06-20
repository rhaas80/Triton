#include "Waveform.hpp"
#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include "Minimize.hpp"
#include "FileIO.hpp"
#include "SWSHs.hpp"
#include "EasyParser.hpp"
#include "PNWaveform.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

namespace WaveformUnits {
#include "Units.hpp"
};
using namespace WaveformUnits;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}


typedef unsigned int uint;

string Rev = "$Rev$";
int Revision = atoi(Rev.substr(5,Rev.size()-6).c_str());

int GetWaveformType(const string& FullPath, const vector<string>& Header);
string GetFileFormat(const vector<string>& Header);
void GetWaveformTimeScaleAndLM(const vector<string>& Header, string& Scale, vector<vector<int> >& LM);

vector<string> Waveform::Types(12, "");

//// Note on Waveform Types:
// In any system, h -- being strain -- should be dimensionless.
// When G=c=1, the dimensionless quantities are rMPsi4, rhdot, and rhOverM; as are rOverM and tOverM.
// When G and c are dimensionful, the dimensionless quantities are 
//   -  (r/c) * (M*G/c^3) * Psi4
//   -  (r/c) * hdot
//   -  (r/c) * h / (M*G/c^3)
//   -  (r/c) / (M*G/c^3)
//   -  t / (M*G/c^3)
// To regain the dimensionful quantities, we simply need to remove the relevant dimensionful elements.
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
  Type(0), TimeScale("Time"), LM(0, vector<int>(0)), Radius(0),
  Time(0), amp(0, vector<double>(0)), phi(0, vector<double>(0))
{ SetWaveformTypes(); }

Waveform::Waveform(const Waveform& a) :
  Type(a.Type), TimeScale(a.TimeScale), LM(a.LM), Radius(a.Radius),
  Time(a.Time), amp(a.amp), phi(a.phi)
{ }

Waveform::Waveform(const string& DataFileName, const string& Format) :
  Type(0), TimeScale("Time"), LM(0, vector<int>(0)), Radius(0),
  Time(0), amp(0, vector<double>(0)), phi(0, vector<double>(0))
{
  SetWaveformTypes();
  
  if((DataFileName.size()>4 && DataFileName.compare(DataFileName.size()-4,4,".bbh")==0)
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
    string SectionHeadingAmpPhi = "[ht-ampphi-data]";
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
      exit(1);
    }
    while(ifs.getline(LineChars, LineLength, '\n')) {
      string TrimmedLine(LineChars);
      TrimmedLine = TrimWhiteSpace(StripComments(TrimmedLine));
      if(TrimmedLine.compare(SectionHeadingReIm) == 0) {
	Format = "ReIm";
	break;
      } else if(TrimmedLine.compare(SectionHeadingAmpPhi) == 0) {
	Format = "AmpPhi";
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
      LM.push_back(LandM);
      
      //// Read data file
      vector<vector<double> > Data;
      ReadDatFile(Dir+DataFileName,  Data,  Header);
      Times.push_back(vector<double>(Data.size()));
      Re.push_back(vector<double>(Data.size()));
      Im.push_back(vector<double>(Data.size()));
      int End=Times.size()-1;
      for(unsigned int i=0; i<Times[End].size(); ++i) {
	Times[End][i] = Data[i][0];
      }
      if(Time.size()==0) {
	Time = Times[End];
      } else {
	Time = Intersection(Time, Times[End], 0.05, -1.e300);
      }
      for(unsigned int i = 0; i<Data.size(); ++i) { // Loop over time steps
	Re[End][i] = Data[i][1];
	Im[End][i] = Data[i][2];
      }
    }
    ifs.close();
    
    Radius = vector<double>(Time.size(), 0.0);
    amp = Re; //   Just to size these correctly, or
    phi = Im; //      finish if the format is AmpPhi.
    
    //// Search for TimeScale, LM info, Format, and Waveform Type
    //LM = vector<vector<int> > (amp.size(), vector<int>(2, 0));
    //GetWaveformTimeScaleAndLM(Header, TimeScale, LM);
    TimeScale = "(t-r*)/M";
    Type = GetWaveformType(DataFileName, Header);
    
    if(Format.compare("ReIm") == 0) {
      //ORIENTATION!!! 3 following lines
      for(unsigned int i=0; i<Re.size(); ++i) { // Loop over components
	AmpPhi(Re[i], Im[i], amp[i], phi[i]);
      }
    } else if(Format.compare("AmpPhi") == 0) {
      // Don't need to do anything
    } else {
      cerr << "Unknown format " << Format << endl;
      exit(1);
    }
    Re = vector<vector<double> >(0);
    Im = vector<vector<double> >(0);
    
    for(unsigned int i=0; i<amp.size(); ++i) {
      amp[i] = ::Interpolate(Times[i], amp[i], Time);
      phi[i] = ::Interpolate(Times[i], phi[i], Time);
    }
    
    
  } else {  //// Treat this file like a normal data file
    
    //// Read data file
    vector<vector<double> > Data;
    vector<string> Header;
    ReadDatFile(DataFileName,  Data,  Header);
    Time = vector<double>(Data.size());
    for(unsigned int i=0; i<Time.size(); ++i) {
      Time[i] = Data[i][0];
    }
    Radius = vector<double>(Time.size(), 0.0);
    
    //// Get amp and phi data
    // The data has vectors of vectors of components at a given time;
    // we transpose the matrix to vectors of components, each of which is a vector through time.
    //ORIENTATION!!!  7 following lines
    vector<vector<double> > Re((Data[0].size()-1)/2, vector<double>(Data.size(), 0));
    vector<vector<double> > Im = Re;
    for(unsigned int i = 0; i<Re.size(); ++i) { // Loop over components of Re
      for(unsigned int j = 0; j<Re[i].size(); ++j) { // Loop over time steps
	Re[i][j] = Data[j][2*i+1];
	Im[i][j] = Data[j][2*i+2];
      }
    }
    Data = vector<vector<double> >(0);
    amp = Re; // Just to size these
    phi = Im; //   things properly.
    
    //// Search for TimeScale, LM info, and Waveform Type
    LM = vector<vector<int> > (amp.size(), vector<int>(2, 0));
    GetWaveformTimeScaleAndLM(Header, TimeScale, LM);
    Type = GetWaveformType(DataFileName, Header);
    string DetectedFormat = GetFileFormat(Header);
    if(DetectedFormat.empty()) {
      DetectedFormat = Format;
    } else if(DetectedFormat.compare(Format) != 0) {
      cerr << "Detected file format '" << DetectedFormat << "' does not match explicit file format '" << Format << "'.  Proceeding with detected format." << endl;
    }
    
    if(DetectedFormat.compare("ReIm") == 0) {
      //ORIENTATION!!! 3 following lines
      for(unsigned int i=0; i<Re.size(); ++i) { // Loop over components
	AmpPhi(Re[i], Im[i], amp[i], phi[i]);
      }
    } else if(DetectedFormat.compare("AmpPhi") == 0) {
      // Don't need to do anything
    } else {
      throw(("Unknown format " + Format).c_str());
    }
  }
}

// sum_{l=2}^{PNLMax} (2l+1) = 2*(PNLMax*(PNLMax-1)/2-1) + (PNLMax-2) = (PNLMax+3)*(PNLMax-1)
Waveform::Waveform(const string& Approximant, const double delta, const double chis, const double chia, const double v0,
		   const double PNOrder, const std::vector<std::vector<int> >& LMs, const int nsave, const bool denseish, const double PNAmpOrder) :
  Type(2), TimeScale("(t-r*)/M"), LM((PNLMax+3)*(PNLMax-1), vector<int>(2, 0)),
  Radius(0), Time(0), amp(LM.size(), vector<double>(0)), phi(LM.size(), vector<double>(0))
{
  vector<double> v(0), Phi(0);
  if(Approximant.compare("TaylorT1")==0) {
    if(nsave==-1) {
      TaylorT1(delta, chis, chia, v0, Time, v, Phi, PNOrder);
    } else {
      TaylorT1(delta, chis, chia, v0, Time, v, Phi, PNOrder, nsave, denseish);
    }
  } else if(Approximant.compare("TaylorT2")==0) {
    if(nsave==-1) {
      TaylorT2(delta, chis, chia, v0, Time, v, Phi, PNOrder);
    } else {
      TaylorT2(delta, chis, chia, v0, Time, v, Phi, PNOrder, nsave);
    }
  } else if(Approximant.compare("TaylorT3")==0) {
    if(nsave==-1) {
      TaylorT3(delta, chis, chia, v0, Time, v, Phi, PNOrder);
    } else {
      TaylorT3(delta, chis, chia, v0, Time, v, Phi, PNOrder, nsave);
    }
  } else if(Approximant.compare("TaylorT4")==0) {
    if(nsave==-1) {
      TaylorT4(delta, chis, chia, v0, Time, v, Phi, PNOrder);
    } else {
      TaylorT4(delta, chis, chia, v0, Time, v, Phi, PNOrder, nsave, denseish);
    }
  } else if(Approximant.compare("EOB")==0) {
    vector<double> r(0), prstar(0), pPhi(0);
    if(nsave==-1) {
      EOB(delta, chis, chia, v0, Time, v, Phi, PNOrder, r, prstar, pPhi);
    } else {
      EOB(delta, chis, chia, v0, Time, v, Phi, PNOrder, r, prstar, pPhi, nsave, denseish);
    }
  } else {
    cerr << "Unknown approximant '" << Approximant << "'." << endl;
    exit(1);
  }
  if(LMs.size()>0) {
    LM = LMs;
    amp = vector<vector<double> >(LM.size(), vector<double>(0));
    phi = vector<vector<double> >(LM.size(), vector<double>(0));
    for(unsigned int i=0; i<LMs.size(); ++i) {
      PNAmplitudes(LMs[i][0], LMs[i][1], v, Phi, delta, chia, chis, amp[i], phi[i], PNAmpOrder);
    }
  } else {
    unsigned int i=0;
    for(int l=2; l<=PNLMax; ++l) {
      for(int m=-l; m<=l; ++m) {
	LM[i][0] = l;
	LM[i][1] = m;
	PNAmplitudes(l, m, v, Phi, delta, chia, chis, amp[i], phi[i], PNAmpOrder);
	++i;
      }
    }
  }
  Radius = vector<double>(Time.size(), 0.0);
}


// Member functions

Waveform& Waveform::SetArealRadius(const string& AreaFileName) {
  //// Read data files
  vector<vector<double> > Area;
  vector<string> Header;
  ReadDatFile(AreaFileName,  Area,  Header);
  Radius = vector<double>(Area.size());
  for(unsigned int i=0; i<Radius.size(); ++i) {
    Radius[i] = sqrt(Area[i][1]/(4*M_PI));
  }
  return *this;
}

Waveform& Waveform::SetTimeFromLapseSurfaceIntegral(const string& LapseFileName, const double ADMMass) {
  //// Read data files
  vector<vector<double> > LapseData;
  vector<string> Header;
  ReadDatFile(LapseFileName,  LapseData,  Header);
  vector<double> Lapse(LapseData.size());
  for(unsigned int i=0; i<Lapse.size(); ++i) {
    Lapse[i] = LapseData[i][1]/((4*M_PI)*(Radius[i]*Radius[i]));
  }
  Time = cumtrapz(Time, Lapse/sqrt(((-2.0*ADMMass)/Radius) + 1.0)) + Time[0];
  return *this;
}

Waveform& Waveform::TortoiseOffset(const double ADMMass) {
  TimeScale = "(t-r*)";
  Time = Time - (Radius + (2.0*ADMMass)*log((Radius/(2.0*ADMMass))-1.0));
  return *this;
}

double Waveform::Peak22Time() const {
  //// Find 2,2 component
  int TwoTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<LM.size(); ++i) {
    if(LM[i][0]==2 && LM[i][1]==2) { TwoTwo=i; break; }
  }
  //// Error if not found
  if(TwoTwo==-1) throw("Can't find the 2,2 component of the data!");
  return Time[maxIndex(amp[TwoTwo])];
}

vector<double> Waveform::Omega22() const {
  //// Find 2,2 component
  int TwoTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<LM.size(); ++i) {
    if(LM[i][0]==2 && LM[i][1]==2) { TwoTwo=i; break; }
  }
  
  //// Error if not found
  if(TwoTwo==-1) throw("Can't find the 2,2 component of the data!");
  
  //// Return differentiated Phi data
  //ORIENTATION!!! following line
  return dydx(phi[TwoTwo], Time);
}

vector<double> Waveform::Omega2m2(const double t1, const double t2) const {
  //// Find 2,2 component
  int TwomTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<LM.size(); ++i) {
    if(LM[i][0]==2 && LM[i][1]==-2) { TwomTwo=i; break; }
  }
  
  //// Error if not found
  if(TwomTwo==-1) {
    cerr << "Can't find the 2,-2 component of the data!" << endl;
    exit(1);
  }
  
  //// Return differentiated Phi data
  //ORIENTATION!!! following line
  if((t1!=-1e300 && t1>Time[0]) && (t2!=1e300 && t2<Time[Time.size()-1])) {
    vector<double> NewTime(Time);
    vector<double> phase(phi[TwomTwo]);
    int i=NewTime.size()-1;
    while(NewTime[i]>t2) { --i; }
    NewTime.erase(NewTime.begin()+i, NewTime.begin()+NewTime.size());
    phase.erase(phase.begin()+i, phase.begin()+phase.size());
    i=0;
    while(NewTime[i]<t1) { ++i; }
    NewTime.erase(NewTime.begin(), NewTime.begin()+i);
    phase.erase(phase.begin(), phase.begin()+i);
    return dydx(phase, NewTime);
  } else if((t1!=-1e300 && t1>Time[0])) {
    vector<double> NewTime(Time);
    vector<double> phase(phi[TwomTwo]);
    int i=0;
    while(NewTime[i]<t1) { ++i; }
    NewTime.erase(NewTime.begin(), NewTime.begin()+i);
    phase.erase(phase.begin(), phase.begin()+i);
    return dydx(phase, NewTime);
  } else if((t2!=1e300 && t2<Time[Time.size()-1])) {
    vector<double> NewTime(Time);
    vector<double> phase(phi[TwomTwo]);
    int i=NewTime.size()-1;
    while(NewTime[i]>t2) { --i; }
    NewTime.erase(NewTime.begin()+i, NewTime.begin()+NewTime.size());
    phase.erase(phase.begin()+i, phase.begin()+phase.size());
    return dydx(phase, NewTime);
  } else {
    return dydx(phi[TwomTwo], Time);
  }
}

void Waveform::Omega2m2Smooth(vector<double>& Omega, vector<double>& Time, const int NLeft, const int NRight, const int PolyOrder) const {
  //// Find 2,2 component
  int TwomTwo = -1;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<LM.size(); ++i) {
    if(LM[i][0]==2 && LM[i][1]==-2) { TwomTwo=i; break; }
  }
  
  //// Error if not found
  if(TwomTwo==-1) {
    cerr << "Can't find the 2,-2 component of the data!" << endl;
    exit(1);
  }
  
  //// Return differentiated Phi data
  //ORIENTATION!!! following line
  Omega = phi[TwomTwo];
  dydxSmooth(Omega, Time, NLeft, NRight, PolyOrder, 1);
  return;
}

vector<double> Waveform::Omega2m2Smooth(const int NLeft, const int NRight, const int PolyOrder) const {
  vector<double> T=Time;
  vector<double> Omega=Time;
  unsigned int Size=Omega.size();
  this->Omega2m2Smooth(Omega, T, NLeft, NRight, PolyOrder);
  Omega.erase(Omega.begin()+Size, Omega.end());
  return Omega;
}

Waveform Waveform::ZeroBefore(const double t) const {
  Waveform b = *this;
  unsigned int i=0;
  while(i<b.Time.size()-1 && b.Time[i+1]<=t) { ++i; }
  for(unsigned int j=0; j<b.amp.size(); ++j) {
    for(unsigned int k=0; k<i; ++k) {
      b.amp[j][k] = 0.0;
    }
  }
  return b;
}

Waveform Waveform::UniformTime() const {
  Waveform b = *this;
  double AvgDiff = (Time[Time.size()-1]-Time[0])/(Time.size()-1);
  vector<double> NewTime(Time.size(), 0.0);
  for(unsigned int i=0; i<NewTime.size(); ++i) {
    NewTime[i] = Time[0] + i*AvgDiff;
  }
  b.Interpolate(NewTime);
  return b;
}

Waveform Waveform::UniformTimeToPowerOfTwo() const {
  if(((Time.size()) & (Time.size()-1)) == 0) { return *this; } // Return *this if we already have a power of 2
  Waveform b(*this);
  unsigned int N = static_cast<unsigned int>(pow(2.0,ceil(log2(b.Time.size()))));
  double dt = (b.Time[b.Time.size()-1]-b.Time[0])/(N-1);
  vector<double> NewTime(N, 0.0);
  for(unsigned int i=0; i<N; ++i) {
    NewTime[i] = b.Time[0] + i*dt;
  }
  b.Interpolate(NewTime);
  return b;
}

Waveform Waveform::Differentiate() const {
  if(Type%3==0) { throw("Derivative of Psi4 not supported."); }
  Waveform b(*this);
  b.Type = Type-1;
  vector<double> ampdot=amp[0], phidot=phi[0];
  // Loop over each component, doing the differentiation
  //ORIENTATION!!!! Following loop
  for(unsigned int i=0; i<LM.size(); ++i) {
    ampdot = dydx(amp[i], Time);
    phidot = dydx(phi[i], Time);
    b.amp[i] = sqrt(ampdot*ampdot + amp[i]*amp[i]*phidot*phidot);
    b.phi[i] = phi[i] + Unwrap(atan2(amp[i]*phidot, ampdot));
  }
  return b;
}

Waveform& Waveform::ScaleAmp(const double S) {
  //        { Amp*S when Type mod 3 = 0 (Psi4)
  // Amp -> { Amp   when Type mod 3 = 1 (hdot)
  //        { Amp/S when Type mod 3 = 2 (h)
  switch( Type % 3 ) {
  case 0:
    amp = amp * S;
    break;
  case 1:
    //amp = amp;
    break;
  case 2:
    amp = amp / S;
    break;
  default:
    throw("That was unexpected!");
  }
  return *this;
}

Waveform& Waveform::SetTotalMassToOne(const double TotalMassInCurrentUnits) {
  this -> ScaleAmp(TotalMassInCurrentUnits);
  Time = Time / TotalMassInCurrentUnits;
  Radius = Radius / TotalMassInCurrentUnits;
  if((Type>2 && Type<6) || Type>8) { Type = Type - 3; }
  if(TimeScale.find("/M") == string::npos) { TimeScale = TimeScale + "/M"; }
  return *this;
}

Waveform& Waveform::SetPhysicalMass(const double CurrentUnitMassInSolarMasses) {
  // See the note above Waveform::Types.  This function removes the (G*M/c^3)
  // from each type, then scales the Time into seconds, and Radius into meters.
  if((Type>2 && Type<6) || Type>8) { throw(("Cannot SetPhysicalMass for Waveform of Type " + Waveform::Types[Type]).c_str()); }
  double MassInSeconds = CurrentUnitMassInSolarMasses * SolarMass * NewtonsConstant / (SpeedOfLight*SpeedOfLight*SpeedOfLight);
  this -> ScaleAmp(1.0/MassInSeconds);
  Time = Time * MassInSeconds;
  Radius = Radius * (MassInSeconds * SpeedOfLight);
  Type = Type + 3;
  if(TimeScale.find("/M") != string::npos) { TimeScale.erase(TimeScale.find("/M"),2); }
  return *this;
}

Waveform& Waveform::SetPhysicalDistance(const double DistanceInMegaparsecs) {
  // See the note above Waveform::Types.  This function removes the (r/c)
  // from the amplitude of each type.
  if(Type>5) { throw(("Cannot SetPhysicalDistance for Waveform of Type " + Waveform::Types[Type]).c_str()); }
  double DistanceInMeters = DistanceInMegaparsecs * OneMegaparsec;
  amp = amp * (SpeedOfLight / DistanceInMeters);
  Radius = vector<double>(Radius.size(), DistanceInMeters);
  Type = Type + 6;
  return *this;
}

Waveform Waveform::SetPhysicalMass(const double CurrentUnitMassInSolarMasses) const {
  Waveform b = *this;
  b.SetPhysicalMass(CurrentUnitMassInSolarMasses);
  return b;
}

Waveform Waveform::SetPhysicalDistance(const double DistanceInMegaparsecs) const {
  Waveform b = *this;
  b.SetPhysicalDistance(DistanceInMegaparsecs);
  return b;
}

Waveform Waveform::operator/(const Waveform& b) const {
  if(b.LM.size() != LM.size() || b.LM != LM) {
    cerr << "Trying to subtract Waveforms with mismatched LM data." << endl;
    exit(1);
  }
  vector<double> NewTime = Intersection(Time, b.Time, 0.005, -1e300);
  Waveform c = *this;
  Waveform d = b;
  c.Interpolate(NewTime);
  d.Interpolate(NewTime);
  c.amp = (c.amp - d.amp) / d.amp;
  c.phi = c.phi-d.phi;
  return c;
}

Waveform& Waveform::operator=(const Waveform& b) {
  Type = b.Type;
  TimeScale = b.TimeScale;
  LM = b.LM;
//   vartheta = b.vartheta;
//   varphi = b.varphi;
  Radius = b.Radius;
  Time = b.Time;
  amp = b.amp;
  phi = b.phi;
  return *this;
}

Waveform Waveform::operator[](const unsigned int Index) const {
  Waveform A(*this);
  A.amp = vector<vector<double> >(1,amp[Index]);
  A.phi = vector<vector<double> >(1,phi[Index]);
  A.LM = vector<vector<int> >(1, LM[Index]);
  return A;
}

Waveform& Waveform::Interpolate(const vector<double>& NewTime) {
  Radius = ::Interpolate(Time, Radius, NewTime);
  //ORIENTATION!!! 4 following lines
  for(unsigned int i=0; i<phi.size(); ++i) {
    amp[i] = ::Interpolate(Time, amp[i], NewTime);
    phi[i] = ::Interpolate(Time, phi[i], NewTime);
  }
  Time = NewTime;
  return *this;
}

Waveform& Waveform::Interpolate(const double& NewTime) {
  this->Interpolate(vector<double>(1, NewTime));
  return *this;
}

Waveform& Waveform::Interpolate(const Waveform& b) {
  this->Interpolate(b.Time);
  return *this;
}

Waveform Waveform::Interpolate(const vector<double>& NewTime) const {
  Waveform b(*this);
  b.Interpolate(NewTime);
  return b;
}

Waveform Waveform::Interpolate(const double& NewTime) const {
  Waveform b(*this);
  b.Interpolate(NewTime);
  return b;
}

Waveform Waveform::Interpolate(const Waveform& b) const {
  Waveform c(*this);
  c.Interpolate(b.Time);
  return c;
}

Waveform& Waveform::OffsetTime(const double& t) {
  Time += t;
  return *this;
}

Waveform& Waveform::DropBefore(const double& t) {
  unsigned int i=0;
  while(i<Time.size()-1 && Time[i+1]<=t) { ++i; }
  Time.erase(Time.begin(), Time.begin()+i);
  Radius.erase(Radius.begin(), Radius.begin()+i);
  for(unsigned int j=0; j<amp.size(); ++j) {
    amp[j].erase(amp[j].begin(), amp[j].begin()+i);
    phi[j].erase(phi[j].begin(), phi[j].begin()+i);
  }
  return *this;
}

Waveform Waveform::DropBefore(const double& t) const {
  Waveform b(*this);
  b.DropBefore(t);
  return b;
}

Waveform& Waveform::DropAfter(const double& t) {
  unsigned int i=Time.size()-1;
  while(i>0 && Time[i]>t) { --i; }
  Time.erase(Time.begin()+i, Time.end());
  Radius.erase(Radius.begin()+i, Radius.end());
  for(unsigned int j=0; j<amp.size(); ++j) {
    amp[j].erase(amp[j].begin()+i, amp[j].end());
    phi[j].erase(phi[j].begin()+i, phi[j].end());
  }
  return *this;
}

Waveform& Waveform::DropLMode(const int L) {
  vector<vector<double> >::iterator amprit=amp.end();
  vector<vector<double> >::iterator phirit=phi.end();
  vector<vector<int> >::iterator LMrit=LM.end();
  amprit--;
  phirit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LM.begin()) {
    if((*LMrit)[0]==L) {
      amp.erase(amprit);
      phi.erase(phirit);
      LM.erase(LMrit);
    }
    amprit--;
    phirit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropLMMode(const int L, const int M) {
  vector<vector<double> >::iterator amprit=amp.end();
  vector<vector<double> >::iterator phirit=phi.end();
  vector<vector<int> >::iterator LMrit=LM.end();
  amprit--;
  phirit--;
  LMrit--;
  while(LMrit >= LM.begin()) {
    //ORIENTATION!!! following if statements
    if((*LMrit)[0]==L && (*LMrit)[1]==M) {
      amp.erase(amprit);
      phi.erase(phirit);
      LM.erase(LMrit);
    } else if((*LMrit)[0]==L && (*LMrit)[1]==-M) {
      amp.erase(amprit);
      phi.erase(phirit);
      LM.erase(LMrit);
    }
    amprit--;
    phirit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropOddMModes() {
  vector<vector<double> >::iterator amprit=amp.end();
  vector<vector<double> >::iterator phirit=phi.end();
  vector<vector<int> >::iterator LMrit=LM.end();
  amprit--;
  phirit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LM.begin()) {
    if((*LMrit)[1]%2!=0) {
      amp.erase(amprit);
      phi.erase(phirit);
      LM.erase(LMrit);
    }
    amprit--;
    phirit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropZeroMModes() {
  vector<vector<double> >::iterator amprit=amp.end();
  vector<vector<double> >::iterator phirit=phi.end();
  vector<vector<int> >::iterator LMrit=LM.end();
  amprit--;
  phirit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LM.begin()) {
    if((*LMrit)[1]==0) {
      amp.erase(amprit);
      phi.erase(phirit);
      LM.erase(LMrit);
    }
    amprit--;
    phirit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::DropNegativeMModes() {
  vector<vector<double> >::iterator amprit=amp.end();
  vector<vector<double> >::iterator phirit=phi.end();
  vector<vector<int> >::iterator LMrit=LM.end();
  amprit--;
  phirit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LM.begin()) {
    if((*LMrit)[1]<1) {
      amp.erase(amprit);
      phi.erase(phirit);
      LM.erase(LMrit);
    }
    amprit--;
    phirit--;
    LMrit--;
  }
  return *this;
}

Waveform& Waveform::Conjugate() {
  for(unsigned int i=0; i<LM.size(); ++i) {
    phi[i] = -phi[i];
  }
  return *this;
}

Waveform& Waveform::FixNonOscillatingData() {
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<LM.size(); ++i) { // Loop over components
    if(LM[i][1]==0) {
      vector<double> Im = amp[i] * sin(phi[i]);
      amp[i] = amp[i] * cos(phi[i]);
      phi[i] = Im;
    }
  }
  return *this;
}

Waveform& Waveform::UnfixNonOscillatingData() {
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<LM.size(); ++i) { // Loop over components
    if(LM[i][1]==0) {
      vector<double> Re = amp[i];
      vector<double> Im = phi[i];
      AmpPhi(Re, Im, amp[i], phi[i]);
    }
  }
  return *this;
}

std::vector<double> Waveform::Flux() const {
  if(Type%3!=1) { throw("Can't get flux for Waveform of Type other than rhdot."); }
  vector<double> Flux(Time.size(), 0.0);
  //ORIENTATION!!! Following loop
  for(unsigned int i=0; i<amp.size(); ++i) {
    Flux += amp[i]*amp[i];
  }
  return (Flux/(16.0*M_PI));
}

Waveform Waveform::L2Norm() const {
  Waveform Norm;
  Norm.TimeScale = TimeScale;
  Norm.Radius = Radius;
  Norm.Time =  Time;
  Norm.LM = vector<vector<int> >(1, vector<int>(2,0));
  //ORIENTATION!!!  7 following lines
  Norm.amp = vector<vector<double> >(1, vector<double>(amp[0].size(), 0.0));
  Norm.phi = vector<vector<double> >(1, vector<double>(phi[0].size(), 0.0));
  for(unsigned int i=0; i<amp[0].size(); ++i) { // Loop over times
    for(unsigned int j=0; j<amp.size(); ++j) { // Loop over components
      Norm.amp[0][i] += amp[j][i]*amp[j][i];
    }
    Norm.amp[0][i] = sqrt(Norm.amp[0][i]);
  }
  return Norm;
}

Waveform Waveform::L2NormalizedDifference(const Waveform& b) const {
  Waveform c = b;
  if(b.LM.size() != LM.size() || b.LM != LM) {
    cerr << "Trying to subtract Waveforms with mismatched LM data." << endl;
    exit(1);
  }
  if(b.Time.size() != Time.size() || b.Time != Time) {
    c.Interpolate(Time);
  }
  //ORIENTATION!!! 4 following lines
  vector<double> Norm = L2Norm().amp[0] + c.L2Norm().amp[0];
  for(unsigned int i=0; i<amp[0].size(); ++i) {
    c.amp[i] = (amp[i] - c.amp[i]) / Norm;
  }
  c.phi = phi-c.phi;
  return c;
}

class WaveformMatcher {
  friend class Waveform;
protected:
  const Waveform& a, b;
  vector<double> t, phia;
  int LMa, LMb;
public:
  WaveformMatcher(const Waveform& A, const Waveform& B, const double t1, const double t2)
    : a(A), b(B), t(A.Time), phia(0), LMa(-1), LMb(-1)
  {
    if(a.LM.size() != b.LM.size() || a.LM != b.LM) {
      cerr << "Trying to MatchTo* Waveforms with mismatched LM data." << endl;
      exit(1);
    }
    if(t1<A.Time[0]) {
      cerr << "Matching time t1=" << t1 << " does not occur in Waveform A (which has A.Time[0]=" << A.Time[0] << ")." << endl;
      exit(1);
    }
    if(t1<B.Time[0]) {
      cerr << "Matching time t1=" << t1 << " does not occur in Waveform B (which has B.Time[0]=" << B.Time[0] << ")." << endl;
      exit(1);
    }
    if(t2>A.Time[A.Time.size()-1]) {
      cerr << "Matching time t2=" << t2 << " does not occur in Waveform A (which has A.Time[-1]=" << A.Time[A.Time.size()-1] << ")." << endl;
      exit(1);
    }
    if(t2>B.Time[B.Time.size()-1]) {
      cerr << "Matching time t2=" << t2 << " does not occur in Waveform B (which has B.Time[-1]=" << B.Time[B.Time.size()-1] << ")." << endl;
      exit(1);
    }
    unsigned int i=0;
    //ORIENTATION!!! following loops
    for(i=0; i<a.LM.size(); ++i) {
      if(a.LM[i][0]==2 && a.LM[i][1]==2) { LMa=i; break; }
    }
    if(LMa==-1) throw("Can't find the 2,2 component of the Waveform a!");
    for(i=0; i<b.LM.size(); ++i) {
      if(b.LM[i][0]==2 && b.LM[i][1]==2) { LMb=i; break; }
    }
    if(LMb==-1) throw("Can't find the 2,2 component of the Waveform b!");
    phia = a.phi[LMa];
    i=t.size()-1;
    while(t[i]>t2 && i>0) { --i; }
    t.erase(t.begin()+i, t.end());
    phia.erase(phia.begin()+i, phia.end());
    i=0;
    while(i<a.Time.size() && a.Time[i]<t1) { ++i; }
    t.erase(t.begin(), t.begin()+i);
    phia.erase(phia.begin(), phia.begin()+i);
  }
  
  double dphi(const double dt, const unsigned int I) const {
    vector<double> phiA = Interpolate(a.Time, a.phi[I], t);
    vector<double> phiB = Interpolate(b.Time, b.phi[I], t-dt);
    return trapz(t, phiA-phiB) / (t[t.size()-1]-t[0]);
  }
  
  double operator()(const double dt) const {
    vector<double> phib = Interpolate(b.Time, b.phi[LMb], t-dt);
    double dphi = trapz(t, phia-phib) / (t[t.size()-1]-t[0]);
    return trapz(t, (phia-phib-dphi)*(phia-phib-dphi));
  }
};

Waveform Waveform::MatchTo(const Waveform& a, const double t1, const double t2) const {
  Waveform b(*this);
  WaveformMatcher Match(a, b, t1, t2);
  Brent Minimizer;
  Minimizer.ax = max(t1-t2, b.Time[0]-t1);
  Minimizer.bx = 0.0;
  Minimizer.cx = min(t2-t1, b.Time[b.Time.size()-1]-t2);
  double dt = Minimizer.minimize(Match);
  cout << "\nMatching gave dt=" << dt << endl;
  b.Time += dt;
  for(unsigned int i=0; i<a.LM.size() && i<b.LM.size(); ++i) {
    b.phi[i] += Match.dphi(dt, i);
  }
  return b;
}

Waveform Waveform::MatchToFrequency(const Waveform& a, const double omega, const double t1, const double t2, const double DeltaT, const double MinStep) const {
  if(omega==0.0) {
    cerr << "\n\nThe frequency input to MatchToFrequency is exactly 0.0.  This is probably not what you want.  I'll keep trying anyway...\n" << endl;
  }
  Waveform b(*this);
  unsigned int i=0;
  double T1(t1), T2(t2);
  if(T1<a.Time[0]) { T1=a.Time[0]; }
  if(T1<b.Time[0]) { T1=b.Time[0]; }
  if(T2>a.Time[a.Time.size()-1]) { T2=a.Time[a.Time.size()-1]; }
  if(T2>b.Time[b.Time.size()-1]) { T2=b.Time[b.Time.size()-1]; }
  WaveformMatcher Match(a, b, T1, T2);
  vector<double> NewTimeA(a.Time);
  vector<double> NewOmegaA(a.Omega2m2());
  vector<double> NewTimeB(b.Time);
  vector<double> NewOmegaB(b.Omega2m2());
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
    /// Make sure NewOmegaA gets up to fabs(omega), but is strictly monotonically increasing before it
    i=1;
    while(i<NewOmegaA.size() && NewOmegaA[i]<fabs(omega)) { ++i; }
    while(i>0 && NewOmegaA[i-1]<NewOmegaA[i]) { --i; }
    if(i!=1) {
      NewTimeA.erase(NewTimeA.begin(), NewTimeA.begin()+i);
      NewOmegaA.erase(NewOmegaA.begin(), NewOmegaA.begin()+i);
    }
    /// Make sure NewOmegaA gets past fabs(omega), and is strictly monotonically increasing afterward
    i=1;
    while(i<NewTimeA.size() && NewOmegaA[i]<fabs(omega)) { ++i; }
    while(i<NewTimeA.size() && NewOmegaA[i]>NewOmegaA[i-1]) { ++i; }
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
    while(i<NewOmegaB.size() && NewOmegaB[i]<fabs(omega)) { ++i; }
    while(i>0 && NewOmegaB[i-1]<NewOmegaB[i]) { --i; }
    if(i>1) {
      NewTimeB.erase(NewTimeB.begin(), NewTimeB.begin()+i);
      NewOmegaB.erase(NewOmegaB.begin(), NewOmegaB.begin()+i);
    }
    /// Make sure NewOmegaB gets past fabs(omega), and is strictly monotonically increasing afterward
    i=1;
    while(i<NewOmegaB.size() && NewOmegaB[i]<fabs(omega)) { ++i; }
    while(i<NewTimeB.size() && NewOmegaB[i]>NewOmegaB[i-1]) { ++i; }
    if(i>1) {
      NewTimeB.erase(NewTimeB.begin()+i, NewTimeB.begin()+NewTimeB.size());
      NewOmegaB.erase(NewOmegaB.begin()+i, NewOmegaB.begin()+NewOmegaB.size());
    }
  } catch (char* str) {
    cerr << "Bad news from MatchToFrequency: " << str << endl
	 << "\nThe frequency requested is probably out of range of one or both of the Waveforms, or your t1 and t2 are too restrictive.\n" << endl;
    exit(1);
  }
  const double TA = ::Interpolate(NewOmegaA, NewTimeA, fabs(omega));
  NewOmegaA.clear();
  NewTimeA.clear();
  const double TB = ::Interpolate(NewOmegaB, NewTimeB, fabs(omega));
  NewOmegaB.clear();
  NewTimeB.clear();
  
  const double dt = TA-TB;
  b.Time += dt;
  for(unsigned int i=0; i<a.LM.size() && i<b.LM.size(); ++i) {
    b.phi[i] += ::Interpolate(a.Time, a.phi[i], TA) - ::Interpolate(b.Time, b.phi[i], TA);
  }
  
  if(DeltaT!=1e300) {
    //cerr << "\nomega=" << omega << "\tTA=" << TA << "\tt1=" << max(TA-DeltaT, max(a.Time[0], b.Time[0]))
    //     << "\tt2=" << min(TA+DeltaT, min(a.Time[a.Time.size()-1], b.Time[b.Time.size()-1])) << endl;
    return b.HybridizeWith(a, max(TA-DeltaT, max(a.Time[0], b.Time[0])), min(TA+DeltaT, min(a.Time[a.Time.size()-1], b.Time[b.Time.size()-1])), MinStep);
  } // else
  return b;
}

Waveform Waveform::HybridizeFrequencyWith(const Waveform& a, const double omega, const double omegat1, const double omegat2, const double DeltaT, const double MinStep) const {
  return this -> MatchToFrequency(a, omega, omegat1, omegat2, DeltaT);
}

Waveform Waveform::HybridizeWith(const Waveform& b, const double t1, const double t2, const double MinStep) const {
  Waveform c(*this);
  if(b.LM.size() != LM.size() || b.LM != LM) {
    cerr << "Trying to hybridize Waveforms with mismatched LM data." << endl;
    exit(1);
  }
  c.Time = Union(Time, b.Time, MinStep);
  int it=c.Time.size()-1;
  while(c.Time[it]>b.Time[b.Time.size()-1]) { --it; }
  c.Time.erase(c.Time.begin()+it, c.Time.end());
  c.Radius = vector<double>(c.Time.size(), 0.0);
  c.amp = vector<vector<double> >(LM.size(), vector<double>(c.Time.size(), 0.0));
  c.phi = vector<vector<double> >(LM.size(), vector<double>(c.Time.size(), 0.0));
  unsigned int J01=0, J12=c.Time.size()-1;
  while(c.Time[J01]<t1) { J01++; }
  while(c.Time[J12]>t2 && J12>0) { J12--; }
  double Transition=0.0;
  double TransitionLength=max(1,static_cast<double>(J12-J01-1));
  //ORIENTATION!!! Following loop
  for(unsigned int i=0; i<LM.size(); ++i) {
    SplineInterpolator SplineAmpA(  Time,   amp[i]);
    SplineInterpolator SplineAmpB(b.Time, b.amp[i]);
    SplineInterpolator SplinePhiA(  Time,   phi[i]);
    SplineInterpolator SplinePhiB(b.Time, b.phi[i]);
    for(unsigned int j=0; j<J01; ++j) {
      c.amp[i][j] = SplineAmpA.interp(c.Time[j]);
      c.phi[i][j] = SplinePhiA.interp(c.Time[j]);
    }
    for(unsigned int j=J01; j<J12; ++j) {
      Transition = static_cast<double>(j-J01)/TransitionLength;
      c.amp[i][j] = SplineAmpA.interp(c.Time[j])*(1.0-Transition) + SplineAmpB.interp(c.Time[j])*Transition;
      c.phi[i][j] = SplinePhiA.interp(c.Time[j])*(1.0-Transition) + SplinePhiB.interp(c.Time[j])*Transition;
    }
    for(unsigned int j=J12; j<c.Time.size(); ++j) {
      c.amp[i][j] = SplineAmpB.interp(c.Time[j]);
      c.phi[i][j] = SplinePhiB.interp(c.Time[j]);
    }
  }
  
  /// Check for NaNs
  c.HasNaNs();
  
  return c;
}


// Returns true if the input (x,y) data can be interpolated
// between indices I0 and I1 to within a tolerance of Tol
// at the midpoint between I0 and I1.
bool MinimalGrid_Check(const vector<double>& x, const vector<double>& y,
	   const int I0, const int I1, const double Tol)
{
  if(I1==I0+1) { return true; }
  int IMid = ((I0+I1) >> 1); // = floor(avg(I0+I1))
  if(abs(y[I0] + (x[IMid]-x[I0])*(y[I1]-y[I0])/(x[I1]-x[I0]) - y[IMid]) > Tol) {
    return false; // Interval is not fine enough
  }
  return true; // Interval is fine enough
}


// Given data (t,phi), some initial index I0, and a guess
// for I1, this function outputs the optimal index I1 so
// that (t,phi) can be interpolated between I0 and I1 to
// just within phiTol of the full input data set.
// Compare Numerical Recipes's 'hunt' function; this is
// basically a hunt for that optimal index.
int MinimalGrid_Hunt(const vector<double>& t, const vector<double>& phi,
		    const double phiTol, const int I0, const int I1)
{
  int Inc=1, I1lo = I1, I1hi=I1+1;
  
  // Bracket the optimal I1 between I1lo and I1hi
  if( MinimalGrid_Check(t, phi, I0, I1lo, phiTol) ) {
    while( MinimalGrid_Check(t, phi, I0, I1hi, phiTol) ) {
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
    while( ! MinimalGrid_Check(t, phi, I0, I1lo, phiTol) ) {
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
    if( MinimalGrid_Check(t, phi, I0, I1m, phiTol) ) {
      I1lo = I1m;
    } else {
      I1hi = I1m;
    }
  }
  
  return I1lo;
}


Waveform Waveform::MinimalGrid(const double ampTol, const double phiTol) const {
  // The objective here will be to create a vector of bool's, the same
  // length as t.  The truth value will correspond to whether or not
  // that time step should be kept in the final data.  We begin by
  // assuming that the very first and last steps should obviously be
  // kept.  Then, there are two stages.  First is a coarse stage,
  // which steps through the data making intervals small enough to
  // reproduce the phi data at the interval's midpoint to within
  // phiTol, but no smaller.  Second is the finer stage, which goes
  // through each interval, checking that every single point in the
  // input data can be reproduced to within phiTol and ampTol.  If
  // that's not true, the interval is split evenly into two, and the
  // algorithm proceeds with the earlier interval.  Finally, the input
  // t, amp, and phi vectors are replaced by the smaller vectors given
  // by our vector of bool's.
  
  // We can only have one mode here
  if(LM.size()>1) {
    cerr << "\nToo many modes (" << LM.size() << ") in MinimalGrid!\n" << endl;
    exit(1);
  }
  
  unsigned int I0 = 0;
  unsigned int I1 = ((Time.size()-1) >> 1); // = midpoint of the input data set
  unsigned int NumPoints = 2;
  vector<bool> T(Time.size(), false);
  T[0] = true;
  T[Time.size()-1] = true;
  
  // Coarse -- check only phi at midpoints of each interval
  //   This loop starts from the beginning of the data set, and
  //   forms the smallest interval such that the phi Tolerance
  //   is achieved by linear interpolation.  Then, it moves to
  //   the end of that interval to find the next interval, etc.
  while(((I0+I1)>>1) < T.size()-1) {
    // hunt for optimal I1
    I1 = MinimalGrid_Hunt(Time, phi[0], phiTol, I0, I1);
    
    if(!T[I1]) {
      T[I1] = true;
      ++NumPoints;
    }
    I0 = I1;
    I1 = 2*I1 - I0;
    if(I1<I0+2) { I1 = I0+2; }
  }
  
  // Fine -- check amp and phi at every point
  //   This loop goes through each of the intervals found above,
  //   and makes sure that every data point in both phi and amp
  //   can be reconstructed to within the given tolerances.  If
  //   not, it just adds the midpoint of the interval, and
  //   checks the new interval again.
  I0 = 0;
  I1 = 1;
  unsigned int i=1;
  while(i<Time.size()) {
    if(i>I1) { // This could happen below
      while(i>I1) { ++I1; }
      I0 = i;
      while(!T[I0]) { --I0; }
    }
    while(!T[I1]) { ++I1; }
    if(i != I0 && i != I1) {
      if(abs(1-(amp[0][I0]+(Time[i]-Time[I0])*(amp[0][I1]-amp[0][I0])/(Time[I1]-Time[I0]))/amp[0][i]) > ampTol
	 || abs(phi[0][I0]+(Time[i]-Time[I0])*(phi[0][I1]-phi[0][I0])/(Time[I1]-Time[I0])-phi[0][i]) > phiTol) {
	I1 = ((I0+I1)>>1);
	if(!T[I1]) {
	  //if(I1==I0+1) { Caution(ampTol, phiTol); }
	  T[I1] = true;
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
  for(unsigned int i=0; i<T.size(); ++i) {
    if(T[i]) {
      tOut[Point]   = Time[i];
      ++Point;
    }
  }
  Waveform Wout = *this;
  Wout.Interpolate(tOut);
  
  return Wout;
}

void Waveform::OutputToNINJAFormat(const string& MetadataFileName) const {
  ofstream meta(MetadataFileName.c_str(), ofstream::app);
  meta << "[ht-ampphi-data]" << endl;
  for(unsigned int i=0; i<LM.size(); ++i) {
    char DataFile[1000];
    sprintf(DataFile, (Waveform::Types[Type] + "_L%d_M%d.dat").c_str(), LM[i][0], LM[i][1]);
    meta << LM[i][0] << "," << LM[i][1] << " \t= " << string(DataFile) << endl;
    ofstream data(DataFile, ofstream::out);
    data << setprecision(10) << flush;
    data << (*this)[i];
    data.close();
  }
  meta.close();
  return;
}


//// Friends

Waveform CSSDiff(const Waveform& A, const Waveform& B) {
  Waveform Norm = A.L2Norm();
  Waveform Diff = Norm;
  vector<vector<double> > ReA=A.amp, ImA=A.amp, ReB=B.amp, ImB=B.amp, Re, Im;
  ReIm(A.amp, A.phi, ReA, ImA);
  ReIm(B.amp, B.phi, ReB, ImB);
  Re = ReA - ReB;
  Im = ImA - ImB;
  vector<vector<double> >& Sqr = Re;
  Sqr = Re*Re + Im*Im;
  for(unsigned int i=0; i<Diff.amp[0].size(); ++i) { // Loop over times
    Diff.amp[0][i] = 0.0;
    for(unsigned int j=0; j<Sqr.size(); ++j) { // Loop over components
      Diff.amp[0][i] += Sqr[j][i];
    }
    Diff.amp[0][i] = sqrt(Diff.amp[0][i]) / Norm.amp[0][i];
  }
  return Diff;
}

ostream& operator<<(ostream& os, const Waveform& a) {
  os << "# [1] = " << a.TimeScale << endl;
  for(unsigned int i=0; i<a.LM.size(); ++i) {
    os << "# [" << 2*i+2 << "] = Amp{" << Waveform::Types[a.Type] << "(" << a.LM[i][0] << "," << a.LM[i][1] << ")}" << endl;
    os << "# [" << 2*i+3 << "] = Arg{" << Waveform::Types[a.Type] << "(" << a.LM[i][0] << "," << a.LM[i][1] << ")}" << endl;
  }
  for(unsigned int i=0; i<a.Time.size(); ++i) {
    os << a.Time[i];
    //ORIENTATION!!! following loop
    for(unsigned int j=0; j<a.amp.size(); ++j) {
      os << " " << a.amp[j][i] << " " << a.phi[j][i];
    }
    os << endl;
  }
  return os;
}




//// Utilities

string tolower(const string& A) {
  string B = A;
  string::iterator it;
  for(it=B.begin(); it<B.end(); it++) {
    *it = tolower(*it);
  }
  return B;
}

int GetWaveformType(const string& FullPath, const vector<string>& Header) {
  int Type = 0;
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
	Type = i;
	break;
      }
    }
  }
  return Type;
}

string GetFileFormat(const vector<string>& Header) {
  string DetectedFormat("");
  
  //// Look for the info in the Header
  for(unsigned int j=0; j<Header.size(); ++j) {
    if(tolower(Header[j]).find(tolower("Amp{")) != string::npos) {
      DetectedFormat = "AmpPhi";
      break;
    } else if(tolower(Header[j]).find(tolower("r*Re")) != string::npos) {
      DetectedFormat = "ReIm";
      break;
    }
  }
  
  return DetectedFormat;
}

void GetWaveformTimeScaleAndLM(const vector<string>& Header, string& Scale, vector<vector<int> >& LM) {
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
	LM[i][0] = atoi(Header[j].substr(Paren1+1,Comma-Paren1-1).c_str());
	LM[i][1] = atoi(Header[j].substr(Comma+1,Paren2-Comma-1).c_str());
	++i;
	++j;
      }
    }
  }
  if(i!=LM.size()) {
    cerr << "i=" << i << " but LM.size()=" << LM.size() << "\nThat's bad news for the LM modes..." << endl;
    exit(1);
  }
  return;
}

bool Waveform::HasNaNs() const {
  bool hasnans = false;
  for(unsigned int i=0; i<Time.size(); ++i) {
    if(Time[i]!=Time[i]) {
      cerr << "\nChecking Waveform, a NaN was detected in the Time at index i=" << i << "." << endl;
      hasnans = true;
    }
  }
  for(unsigned int i=0; i<Amp().size(); ++i) {
    for(unsigned int j=0; j<Amp(i).size(); ++j) {
      if(Amp(i,j)!=Amp(i,j)) {
	cerr << "\nChecking Waveform, a NaN was detected in the Amp at index i=" << i << ", j=" << j << " of " << Amp(i).size() << "." << endl;
	hasnans = true;
      }
    }
  }
  for(unsigned int i=0; i<Phi().size(); ++i) {
    for(unsigned int j=0; j<Phi(i).size(); ++j) {
      if(Phi(i,j)!=Phi(i,j)) {
	cerr << "\nChecking Waveform, a NaN was detected in the Phi at index i=" << i << ", j=" << j << " of " << Phi(i).size() << "." << endl;
	hasnans = true;
      }
    }
  }
  return hasnans;
}
