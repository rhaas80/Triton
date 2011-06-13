#include "NumericalRecipes.hpp"

#include "Waveforms.hpp"

#include "VectorFunctions.hpp"
#include "Fit.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::setprecision;
using std::cerr;
using std::cout;
using std::endl;


// Constructors

Waveforms::Waveforms(const Waveforms& In) :
  Ws(In.Ws), CommonTimeSet(In.CommonTimeSet), PhasesAligned(In.PhasesAligned)
{ }

Waveforms::Waveforms(const int N) :
  Ws(N), CommonTimeSet(false), PhasesAligned(false)
{ }

Waveforms::Waveforms(const vector<double>& Radii, const string& DataFile,
		     const string& AreaFile, const string& LapseFile,
		     const double& ADMMass, const double& ChMass, const bool ZeroEnds) :
  Ws(Radii.size()), CommonTimeSet(false), PhasesAligned(false)
{
  int BufferSize = 5000;
  for(unsigned int i=0; i<Radii.size(); ++i) { // Loop over Radii
    char DataFileName[BufferSize], AreaFileName[BufferSize], LapseFileName[BufferSize];
    sprintf(DataFileName,  DataFile.c_str(),  Radii[i]);
    sprintf(AreaFileName,  AreaFile.c_str(),  Radii[i]);
    sprintf(LapseFileName, LapseFile.c_str(), Radii[i]);
    cout << "Reading " << DataFileName << ", " << AreaFileName << ", and " << LapseFileName << "." << endl;
    Ws[i] = Waveform(DataFileName, "ReIm", ZeroEnds);
    Ws[i].SetArealRadius(AreaFileName);
    Ws[i].SetTimeFromLapseSurfaceIntegral(LapseFileName, ADMMass);
    Ws[i].TortoiseOffset(ADMMass);
    Ws[i].SetTotalMassToOne(ChMass);
    cout << "\tRead " << Ws[i].NModes() << " components and " << Ws[i].NTimes() << " time steps." << endl;
  }
}



// Member functions

void Waveforms::SetCommonTime(const double& MinStep, const double& MinTime) {
  std::vector<double> Time(Ws[0].T());
  //// Get the intersection of all the time data
  for(unsigned int i=1; i<Ws.size(); ++i) {
    Time = Intersection(Time, Ws[i].T(), MinStep, MinTime);
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
  int I = int(floor(AlignmentPoint * Ws[0].NTimes()));
  for(unsigned int i=1; i<Ws.size(); ++i) { // Loop over Waveforms
    for(unsigned int j=0; j<Ws[i].NModes(); ++j) { // Loop over components
      Ws[i].ArgRef(j) = Ws[i].Arg(j) + (2.0 * M_PI * round((Ws[i-1].Arg(j,I)-Ws[i].Arg(j,I))/(2.0*M_PI)));
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
  PolynomialBasisFunctions Poly(ExtrapolationOrder);
  Fit<PolynomialBasisFunctions> ampFit(oor, amp, sig, Poly);
  Fit<PolynomialBasisFunctions> phiFit(oor, phi, sig, Poly);
  
  //// Loop over time
  for(unsigned int i=0; i<Extrap.NTimes(); ++i) {
    if(i % 1000 == 0) {
      cout << "Time = " << setprecision(5) << Extrap.T(i) << "\tStep " << i << " of " << Extrap.NTimes() << endl;
    }
    
    //// Set the radii at this time
    for(unsigned int k=0; k<Ws.size(); ++k) {
      oor[k] = 1.0 / Ws[k].R(i);
    }
    
    //// Loop over components
    for(unsigned int j=0; j<Extrap.NModes(); ++j) {
      //// Fill vectors with data from various radii
      for(unsigned int k=0; k<Ws.size(); ++k) {
	amp[k] = Ws[k].Mag(j,i);
	phi[k] = Ws[k].Arg(j,i);
      }
      
      //// Fit to polynomial in 1/R
      ampFit.fit();
      phiFit.fit();
      
      //// Evaluate at 0 and set the relevant component of Extrap
      Extrap.MagRef(j,i) = ampFit.a[0];
      Extrap.ArgRef(j,i) = phiFit.a[0];
    }
  }
  Extrap.RRef() = vector<double>(1, numeric_limits<double>::infinity( ) );
  
  return Extrap;
}
