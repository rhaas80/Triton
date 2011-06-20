#include "NoiseCurves.hpp"
#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

vector<double> AdvLIGO_NSNSOptimal(const vector<double>& F, const bool Invert=false, const double NoiseFloor=0.0) {
  const double FMin = max(NoiseFloor, AdvLIGOSeismicWall);
  const double FMax = 8192;
  vector<double> PSD(F.size(), 0.0);
  if(Invert) {
    for(unsigned int i=0; i<F.size(); ++i) {
      if(fabs(F[i])<FMin || fabs(F[i])>FMax) { PSD[i] = 0.0; }
      else {
	PSD[i] = 1.0e49 / (pow(10, -4*(fabs(F[i])-7.9)*(fabs(F[i])-7.9)+16)
			+ 2.4e-62*pow(fabs(F[i])/215.0,-50)
			+ 0.08*pow(fabs(F[i])/215.0,-4.69)
			+ 123.35*(1.0 - 0.23*(fabs(F[i])/215)*(fabs(F[i])/215) + 0.0764*(fabs(F[i])/215)*(fabs(F[i])/215)*(fabs(F[i])/215)*(fabs(F[i])/215)) / (1.0 + 0.17*(fabs(F[i])/215)*(fabs(F[i])/215)) );
      }
    }
  } else {
    for(unsigned int i=0; i<F.size(); ++i) {
      if(fabs(F[i])<FMin || fabs(F[i])>FMax) { PSD[i] = numeric_limits<double>::infinity(); }
      else {
	PSD[i] = 1.0e-49*(pow(10, -4*(fabs(F[i])-7.9)*(fabs(F[i])-7.9)+16)
			  + 2.4e-62*pow(fabs(F[i])/215.0,-50)
			  + 0.08*pow(fabs(F[i])/215.0,-4.69)
			  + 123.35*(1.0-0.23*(fabs(F[i])/215)*(fabs(F[i])/215)+ 0.0764*(fabs(F[i])/215)*(fabs(F[i])/215)*(fabs(F[i])/215)*(fabs(F[i])/215)) / (1.0 +0.17*(fabs(F[i])/215)*(fabs(F[i])/215)));
      }
    }
  }
  return PSD;
}

vector<double> AdvLIGO_ZeroDet_HighP(const vector<double>& F, const bool Invert=false, const double NoiseFloor=0.0) {
  #include "AdvLIGO_ZeroDet_HighP.hpp"
  vector<double> LogPSD(Interpolate(ZERO_DET_high_PLogF, ZERO_DET_high_PLogPSD, log(fabs(F))));
  const double MinFreq(max(NoiseFloor, AdvLIGOSeismicWall));
  for(unsigned int i=0; i<LogPSD.size(); ++i) if(fabs(F[i])<MinFreq) { LogPSD[i] = 500.0; }
  if(Invert) { return exp(-1.0*LogPSD); }
  return exp(LogPSD);
}

vector<double> AdvLIGO_ZeroDet_LowP(const vector<double>& F, const bool Invert=false, const double NoiseFloor=0.0) {
  #include "AdvLIGO_ZeroDet_LowP.hpp"
  vector<double> LogPSD(Interpolate(ZERO_DET_low_PLogF, ZERO_DET_low_PLogPSD, log(fabs(F))));
  const double MinFreq(max(NoiseFloor, AdvLIGOSeismicWall));
  for(unsigned int i=0; i<LogPSD.size(); ++i) if(fabs(F[i])<MinFreq) { LogPSD[i] = 500.0; }
  if(Invert) { return exp(-1.0*LogPSD); }
  return exp(LogPSD);
}

vector<double> IniLIGO_Approx(const vector<double>& F, const bool Invert=false, const double NoiseFloor=0.0) {
  const double FMin = max(NoiseFloor, IniLIGOSeismicWall);
  const double FMax = IniLIGOSamplingFreq;
  vector<double> PSD(F.size(), 0.0);
  if(Invert) {
    for(unsigned int i=0; i<F.size(); ++i) {
      const double f = fabs(F[i]);
      if(f<FMin || f>FMax) { PSD[i] = 0.0; }
      else {
// 	const double x = f / 150.0;
// 	PSD[i] = 1.0 / ( ( pow( 4.49 * x, -56.0 ) + 0.16 * pow( x, -4.52 ) + 0.52 + 0.32 * x * x ) );
	PSD[i] = 1.0 / (3.316e-46 * (pow((4.49/150.0)*f, -56) + 0.16*pow(f/150.0, -4.52) + 0.32*pow(f/150.0,2) + 0.52));
      }
    }
  } else {
    for(unsigned int i=0; i<F.size(); ++i) {
      const double f = fabs(F[i]);
      if(f<FMin || f>FMax) { PSD[i] = numeric_limits<double>::infinity(); }
      else {
// 	const double x = f / 150.0;
// 	PSD[i] =  ( pow( 4.49 * x, -56.0 ) + 0.16 * pow( x, -4.52 ) + 0.52 + 0.32 * x * x );
	PSD[i] = 3.316e-46 * (pow((4.49/150.0)*f, -56) + 0.16*pow(f/150.0, -4.52) + 0.32*pow(f/150.0,2) + 0.52);
      }
    }
  }
  return PSD;
}

vector<double> NoiseCurve(const vector<double>& F, const string& Detector, const bool Invert, const double NoiseFloor) {
  if(Detector.compare("AdvLIGO_NSNSOptimal")==0) { return AdvLIGO_NSNSOptimal(F, Invert, NoiseFloor); }
  else if(Detector.compare("AdvLIGO_ZeroDet_HighP")==0) { return AdvLIGO_ZeroDet_HighP(F, Invert, NoiseFloor); }
  else if(Detector.compare("AdvLIGO_ZeroDet_LowP")==0) { return AdvLIGO_ZeroDet_LowP(F, Invert, NoiseFloor); }
  else if(Detector.compare("IniLIGO_Approx")==0) { return IniLIGO_Approx(F, Invert, NoiseFloor); }
  else { cerr << "Unknown Detector type: " << Detector << endl;  exit(1); }
}

vector<double> InverseNoiseCurve(const std::vector<double>& F, const std::string& Detector, const double NoiseFloor) {
  return NoiseCurve(F, Detector, true, NoiseFloor);
}
