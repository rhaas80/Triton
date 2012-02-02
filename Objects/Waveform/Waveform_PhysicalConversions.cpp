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
  History() << "### this->SetArealRadius(\"" << AreaFileName << "\");" << endl;
  //// Read data files
  vector<vector<double> > Area;
  vector<string> Header;
  ReadDatFile(AreaFileName,  Area,  Header);
  RRef().resize(Area.size());
  for(unsigned int i=0; i<r.size(); ++i) {
    RRef(i) = sqrt(Area[i][1]/(4*M_PI));
  }
  return *this;
}

Waveform& Waveform::RescaleMagForRadius(const double OldRadius) {
  History() << "### this->RescaleMagForRadius(\"" << OldRadius << "\");" << endl;
  if(TypeIndex()>5) {
    cerr << "\n\nWarning: This Waveform type is not multiplied by 'r', so this function has no effect.\n" << endl;
    return *this;
  }
  if(R().size()<1) {
    cerr << "\n\nr.size()=" << R().size() << endl;
    throw("Known radii not big enough.");
  }
  if(R().size()==1) {
    const double ScaleFactor = R(0)/OldRadius;
    for(unsigned int mode=0; mode<NModes(); ++mode) {
      MagRef(mode) *= ScaleFactor;
    }
  } else if(R().size() != NTimes()) {
    cerr << "\n\nR().size()=" << R().size() << "\tNTimes()=" << NTimes() << endl;
    throw("Known radii vector has wrong size.");
  } else {
    for(unsigned int t=0; t<NTimes(); ++t) {
      for(unsigned int mode=0; mode<NModes(); ++mode) {
	MagRef(mode,t) *= R(t)/OldRadius;
      }
    }
  }
  return *this;
}

Waveform& Waveform::SetTimeFromLapseSurfaceIntegral(const string& LapseFileName, const double ADMMass) {
  if(R().size()==0) { throw("Bad size for radius data."); }
  History() << "### this->SetTimeFromLapseSurfaceIntegral(\"" << LapseFileName << "\", " << setprecision(16) << ADMMass << ");" << endl;
  //// Read data files
  vector<vector<double> > LapseData;
  vector<string> Header;
  ReadDatFile(LapseFileName,  LapseData,  Header);
  vector<double> Lapse(LapseData.size());
  if(Lapse.size() != R().size() && R().size()!=1) {
    cerr << "\nLapse.size()=" << Lapse.size() << "\tR().size()=" << R().size() << "\tLapseFileName=" << LapseFileName << endl;
    throw("Bad size for Lapse data");
  }
  if(R().size()==1) {
    for(unsigned int i=0; i<Lapse.size(); ++i) {
      Lapse[i] = LapseData[i][1]/((4*M_PI)*(R(0)*R(0)));
    }
    TRef() = cumtrapz(T(), Lapse/sqrt(((-2.0*ADMMass)/R(0)) + 1.0)) + T(0);
  } else {
    for(unsigned int i=0; i<Lapse.size(); ++i) {
      Lapse[i] = LapseData[i][1]/((4*M_PI)*(R(i)*R(i)));
    }
    TRef() = cumtrapz(T(), Lapse/sqrt(((-2.0*ADMMass)/R()) + 1.0)) + T(0);
  }
  return *this;
}

Waveform& Waveform::TortoiseOffset(const double ADMMass) {
  History() << "### this->TortoiseOffset(" << setprecision(16) << ADMMass << ");" << endl;
  TimeScaleRef() = "(t-r*)";
  if(R().size()==1) {
    TRef() = T() - (R(0) + (2.0*ADMMass)*log((R(0)/(2.0*ADMMass))-1.0));
  } else {
    TRef() = T() - (R() + (2.0*ADMMass)*log((R()/(2.0*ADMMass))-1.0));
  }
  return *this;
}

Waveform& Waveform::SetTotalMassToOne(const double TotalMassInCurrentUnits) {
  History() << "### this->SetTotalMassToOne(" << setprecision(16) << TotalMassInCurrentUnits << ");" << endl;
  MagRef() *= ScaleMag(TotalMassInCurrentUnits, TypeIndex());
  TRef() = T() / TotalMassInCurrentUnits;
  RRef() = R() / TotalMassInCurrentUnits;
  if((TypeIndex()>2 && TypeIndex()<6) || TypeIndex()>8) { TypeIndexRef() = TypeIndex() - 3; }
  if(TimeScale().find("/M") == string::npos) { TimeScaleRef() = TimeScale() + "/M"; }
  return *this;
}

Waveform& Waveform::SetPhysicalMassAndDistance(const double CurrentUnitMassInSolarMasses, const double DistanceInMegaparsecs) {
  History() << "### this->SetPhysicalMassAndDistance(" << setprecision(16)
	  << CurrentUnitMassInSolarMasses << ", "
	  << DistanceInMegaparsecs << ");" << endl;
  // See the note above Waveform::Types.  This function removes the (G*M/c^3)
  // from each type, then scales the Time into seconds, and Radius into meters.
  // It then removes the (r/c) from the amplitude of each type.
  if((TypeIndex()>2 && TypeIndex()<6) || TypeIndex()>8) { throw(("Cannot SetPhysicalMass for Waveform of Type " + Type()).c_str()); }
  if(TypeIndex()>5) { throw(("Cannot SetPhysicalDistance for Waveform of Type " + Type()).c_str()); }
  double MassInSeconds = CurrentUnitMassInSolarMasses * SolarMass * NewtonsConstant / (SpeedOfLight*SpeedOfLight*SpeedOfLight);
  double DistanceInMeters = DistanceInMegaparsecs * OneMegaparsec;
  MagRef() *= (ScaleMag(1.0/MassInSeconds, TypeIndex()) * SpeedOfLight / DistanceInMeters);
  TRef() *= MassInSeconds;
  RRef() = vector<double>(R().size(), DistanceInMeters);
  TypeIndexRef() = TypeIndex() + 9;
  if(TimeScale().find("/M") != string::npos) { TimeScaleRef().erase(TimeScale().find("/M"),2); }
  return *this;
}
