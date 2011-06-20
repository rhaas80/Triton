#include "Waveforms.hpp"
#include "VectorFunctions.hpp"
#include "Fit.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

// Constructors

Waveforms::Waveforms(const Waveforms& In) :
  Ws(In.Ws), CommonTimeSet(In.CommonTimeSet), PhasesAligned(In.PhasesAligned)
{ }

Waveforms::Waveforms(const int N) :
  Ws(N), CommonTimeSet(false), PhasesAligned(false)
{ }

Waveforms::Waveforms(const vector<double>& Radii, const string& DataFile,
		     const string& AreaFile, const string& LapseFile,
		     const double& ADMMass, const double& ChMass) :
  Ws(Radii.size()), CommonTimeSet(false), PhasesAligned(false)
{
  int BufferSize = 5000;
  for(unsigned int i=0; i<Radii.size(); ++i) { // Loop over Radii
    char DataFileName[BufferSize], AreaFileName[BufferSize], LapseFileName[BufferSize];
    sprintf(DataFileName,  DataFile.c_str(),  Radii[i]);
    sprintf(AreaFileName,  AreaFile.c_str(),  Radii[i]);
    sprintf(LapseFileName, LapseFile.c_str(), Radii[i]);
    cout << "Reading " << DataFileName << ", " << AreaFileName << ", and " << LapseFileName << "." << endl;
    Ws[i] = Waveform(DataFileName);
    Ws[i].SetArealRadius(AreaFileName);
    Ws[i].SetTimeFromLapseSurfaceIntegral(LapseFileName, ADMMass);
    Ws[i].TortoiseOffset(ADMMass);
    Ws[i].SetTotalMassToOne(ChMass);
    cout << "\tRead " << Ws[i].phi.size() << " components and " << Ws[i].phi[0].size() << " time steps." << endl;
  }
}



// Member functions

void Waveforms::SetCommonTime(const double& MinStep, const double& MinTime) {
  std::vector<double> Time(Ws[0].Time);
  //// Get the intersection of all the time data
  for(unsigned int i=1; i<Ws.size(); ++i) {
    Time = Intersection(Time, Ws[i].Time, MinStep, MinTime);
  }
  //// Interpolate each Waveform to the common time series
  for(unsigned int i=0; i<Ws.size(); ++i) {
    Ws[i].Interpolate(Time);
  }
  CommonTimeSet = true;
  return;
}

void Waveforms::FixNonOscillatingData() {
  //// Step through each Waveform doing the work
  for(unsigned int i=0; i<Ws.size(); ++i) {
    Ws[i].FixNonOscillatingData();
  }
  return;
}

void Waveforms::AlignPhases(const double& AlignmentPoint) {
  if(!CommonTimeSet) { SetCommonTime(); }
  int I = int(floor(AlignmentPoint * Ws[0].Time.size()));
  for(unsigned int i=1; i<Ws.size(); ++i) { // Loop over Waveforms
    for(unsigned int j=0; j<Ws[i].phi.size(); ++j) { // Loop over components
      Ws[i].phi[j] = Ws[i].phi[j] + (2.0 * M_PI * round((Ws[i-1].phi[j][I]-Ws[i].phi[j][I])/(2.0*M_PI)));
    }
  }
  PhasesAligned = true;
  return;
}

Waveform Waveforms::Extrapolate(const int ExtrapolationOrder) {
  if(!PhasesAligned) { AlignPhases(); }
  if(ExtrapolationOrder<0) { return Ws[Ws.size() + ExtrapolationOrder]; }
  Waveform Extrap = Ws[0];
  
  //// Set up the important variables
  vector<double> oor(Ws.size(), 0.0);  // one over radii
  vector<double> amp(Ws.size(), 0.0);
  vector<double> phi(Ws.size(), 0.0);
  const vector<double> sig(Ws.size(), 3e-6);  // These sigmas should never be less than 3e-6.
  Fit ampFit = Fit(oor, amp, sig, ExtrapolationOrder);
  Fit phiFit = Fit(oor, phi, sig, ExtrapolationOrder);
  
  //// Loop over time
  for(unsigned int i=0; i<Extrap.Time.size(); ++i) {
    if(i % 1000 == 0) {
      cout << "Time = " << setprecision(5) << Extrap.Time[i] << "\tStep " << i << " of " << Extrap.Time.size() << endl;
    }
    
    //// Set the radii at this time
    for(unsigned int k=0; k<Ws.size(); ++k) {
      oor[k] = 1.0 / Ws[k].Radius[i];
    }
    
    //// Loop over components
    for(unsigned int j=0; j<Extrap.phi.size(); ++j) {
      //// Fill vectors with data from various radii
      for(unsigned int k=0; k<Ws.size(); ++k) {
	amp[k] = Ws[k].amp[j][i];
	phi[k] = Ws[k].phi[j][i];
      }
      
      //// Fit to polynomial in 1/R
      ampFit.fit();
      phiFit.fit();
      
      //// Evaluate at 0 and set the relevant component of Extrap
      Extrap.Radius[i] = numeric_limits<double>::infinity( );
      Extrap.amp[j][i] = ampFit.Evaluate(0.0);
      Extrap.phi[j][i] = phiFit.Evaluate(0.0);
    }
  }
  
  return Extrap;
}
