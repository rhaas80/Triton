#include "Waveforms.hpp"
#include "WaveformFT.hpp"
#include "NoiseCurves.hpp"
#include "Units.hpp"
#include "VectorFunctions.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
  const double MinMass=3;  // Total binary masses in solar masses
  const double MaxMass=51;
  const unsigned int NMasses=17;
  const double Minomega=0.005;  // Hybridization angular GW frequency (dimensionless)
  const double Maxomega=0.07;
  const unsigned int Nomegas=14;
  
  const string PSDName("AdvLIGO_ZeroDet_HighP");
  const double DetectorMinFreq=10.0;
  const double DetectorSamplingFreq=2048.0;
  const string NRFileName("TestWaveforms/NRRaw/rhOverM_ExtrapolatedN5.dat");
  const double Hybridt1=-1e30;
  //const double Hybridt2=3500; /// Defined below
  const double HybridDeltaT=200;
  const double PNOrder=3.5;
  const double delta=0.0;
  const double chis=0.0;
  const double chia=0.0;
  const double v0=min(0.1, pow(0.99*Minomega/2.0, 1./3.));
  const double DistanceInMegaparsecs=100;
  const unsigned int WindowSize=1024;
  const double vartheta = 0.0;
  const double varphi = 0.0;
  
  const string MassesFileName("TestWaveforms/Masses.dat");
  const string FrequenciesFileName("TestWaveforms/Frequencies.dat");
  const string MismatchesFileName("TestWaveforms/Mismatches.dat");
  const unsigned int Precision=13;
  const unsigned int Width=8;
  
  // Initialize the Masses, omegas, and Mismatches
  vector<double> Masses(NMasses, MinMass);
  vector<double> omegas(Nomegas, Minomega);
  vector<vector<double> > Mismatches(NMasses, vector<double>(Nomegas, 0.0));
  for(unsigned int i=1; i<NMasses; ++i) {
    Masses[i] = MinMass + i*(MaxMass-MinMass)/double(NMasses-1);
  }
  for(unsigned int i=1; i<Nomegas; ++i) {
    omegas[i] = Minomega + i*(Maxomega-Minomega)/double(Nomegas-1);
  }
  
  // Load NR Waveform, hybridize, and clean up
  cout << "Reading NR... " << flush;
  Waveform NRc;
  {
    const double t1=536.1, t2=1448.9;
    Waveform NRRaw(NRFileName, "AmpPhi");
    NRRaw.DropZeroMModes();
    NRRaw.DropLMode(8);
    NRRaw.DropLMode(7);
    NRRaw.DropLMode(6);
    NRRaw.DropLMode(5);
    NRRaw.DropLMode(4);
    NRRaw.DropLMode(3);
    Waveform PN("TaylorT4", delta, chis, chia, v0, PNOrder, NRRaw.LM);
    NRc = PN.OffsetTime(3950).MatchTo(NRRaw, t1, t2).HybridizeWith(NRRaw, t1, t2);
  }
  const double NRPeak22Time = NRc.Peak22Time();
  const double Hybridt2 = NRPeak22Time;
  cout << "☺ \t(Peak time = " << NRPeak22Time << ")\n" << endl;
  
  // Compute PN Waveforms
  cout << "Creating PN...\n\t" << flush;
  const int NWaveforms = 4;
  Waveforms Wsc(NWaveforms);
  Wsc[0] = Waveform("TaylorT1", delta, chis, chia, v0, PNOrder, NRc.LM);
  cout << "\t" << flush;
  Wsc[1] = Waveform("TaylorT2", delta, chis, chia, v0, PNOrder, NRc.LM);
  Wsc[2] = Waveform("TaylorT3", delta, chis, chia, v0, PNOrder, NRc.LM);
  Wsc[3] = Waveform("TaylorT4", delta, chis, chia, v0, PNOrder, NRc.LM);
  for(unsigned int n=0; n<NWaveforms; ++n) {
    Wsc[n].OffsetTime(NRPeak22Time-Wsc[n].Time[Wsc[n].Time.size()-1]);
  }
  cout << "\t☺\n" << endl;
  
  // Find the highest common frequency
  double MaxAvailableomega=0.0;
  {
    vector<double> Availableomegas(NWaveforms+1, 0.0);
    for(unsigned int i=0; i<NWaveforms; ++i) {
      vector<double> PNomega(Wsc[i].Omega2m2());
      Availableomegas[i]=max(PNomega);
    }
    vector<double> NROmega(NRc.Omega2m2());
    unsigned int i=0;
    while(NRc.Time[i]<NRPeak22Time) { ++i; }
    NROmega.erase(NROmega.begin()+i, NROmega.begin()+NROmega.size());
    Availableomegas[NWaveforms] = max(NROmega);
    MaxAvailableomega=min(Availableomegas);
  }
  cout << "Maximum mutually available omega: " << MaxAvailableomega << ".\n" << endl;
  
  // Loop over total masses
  const double dt = 1.0/DetectorSamplingFreq;
  for(unsigned int m=0; m<Masses.size(); ++m) {
    cout << "m = " << Masses[m] << endl;
    // Make copies of the Waveforms, scaled to this mass at a distance 100 Mpc
    Waveform NR(NRc);
    Waveforms Ws(Wsc);
    NR.SetPhysicalMass(Masses[m]).SetPhysicalDistance(DistanceInMegaparsecs);
    for(unsigned int n=0; n<NWaveforms; ++n) {
      Ws[n].SetPhysicalMass(Masses[m]).SetPhysicalDistance(DistanceInMegaparsecs);
    }
    const double t1(Hybridt1*NewtonsConstant*Masses[m]*SolarMass/(SpeedOfLight*SpeedOfLight*SpeedOfLight));
    const double t2(Hybridt2*NewtonsConstant*Masses[m]*SolarMass/(SpeedOfLight*SpeedOfLight*SpeedOfLight));
    const double DeltaT(HybridDeltaT*NewtonsConstant*Masses[m]*SolarMass/(SpeedOfLight*SpeedOfLight*SpeedOfLight));
    
    // Loop over matching frequencies
    for(unsigned int omega=0; omega<omegas.size(); ++omega) {
      const double omega_m(omegas[omega]*SpeedOfLight*SpeedOfLight*SpeedOfLight/(NewtonsConstant*Masses[m]*SolarMass));
      cout << "\tomega=" << setw(Width) << omegas[omega] << "\tomega_m=" << setw(Width) << omega_m << flush;
      if(omega_m>2.0*M_PI*DetectorMinFreq && omegas[omega]<MaxAvailableomega) {
	// Construct the hybrids
	Waveforms Hs(NWaveforms);
	for(unsigned int n=0; n<NWaveforms; ++n) {
	  Hs[n] = Ws[n].MatchToFrequency(NR, omega_m, t1, t2, DeltaT);
	}
	Hs.SetCommonTime(dt, -1.e300);
	
	// Cut off the hybrids at half the detector's minimum frequency
	{
	  vector<double> Omega = Hs[0].Omega2m2();
	  unsigned int i=0;
	  while(Omega[i]<M_PI*DetectorMinFreq && i<Omega.size()) { ++i; }
	  const double DropTime = Hs[0].T(i);
	  for(unsigned int n=0; n<NWaveforms; ++n) {
	    Hs[n].DropBefore(DropTime);
	  }
	}
	
	// Transform to Fourier domain
	vector<WaveformFT> Fs(NWaveforms);
	for(unsigned int n=0; n<NWaveforms; ++n) {
	  Fs[n] = WaveformFT(WaveformAtAPoint(Hs[n], dt, vartheta, varphi).Window(WindowSize).PadToPowerOfTwo());
	}
	Hs.clear(); /// Clear some memory
	
	// Get the InversePSD
	const bool InvertThePSD = true;
	const vector<double> InversePSD(NoiseCurve(Fs[0].Freq(), "AdvLIGO_NSNSOptimal", InvertThePSD));
	
	// Normalize the waveforms
	for(unsigned int n=0; n<NWaveforms; ++n) {
	  Fs[n].Normalize(InversePSD);
	}
	
	// Calculate mismatches
	cout << "\tMismatches: " << flush;
	for(unsigned int n1=0; n1<NWaveforms; ++n1) {
	  for(unsigned int n2=n1+1; n2<NWaveforms; ++n2) {
	    double Mismatch = 1.0-Fs[n1].Match(Fs[n2], InversePSD);
	    cout << setw(Width) << Mismatch << " " << flush;
	    if(Mismatch==Mismatch) { Mismatches[m][omega] = max(Mismatches[m][omega], Mismatch); }
	  }
	}
      } else if(omegas[omega]>= MaxAvailableomega) {
	Mismatches[m][omega] = 1.0;
	cout << "\tUnavailable omega: " << omegas[omega] << ".  Mismatch is effectively 1." << flush;
      } else {
	cout << "\tPhysical omega (" << omega_m << ") is lower than the detector's lowest frequency." << flush;
      }
      cout << "\tmax(Mismatches)=" << Mismatches[m][omega] << endl;
    }
  }
  
  // Output the results
  cout << "\nOutputting the results... " << flush;
  ofstream ofsm(MassesFileName.c_str(), ofstream::out);
  ofstream ofsf(FrequenciesFileName.c_str(), ofstream::out);
  ofstream ofsu(MismatchesFileName.c_str(), ofstream::out);
  ofsm << setprecision(Precision) << flush;
  ofsf << setprecision(Precision) << flush;
  ofsu << setprecision(Precision) << flush;
  for(unsigned int omega=0; omega<omegas.size(); ++omega) {
    for(unsigned int m=0; m<Masses.size(); ++m) {
      ofsm << Masses[m] << " ";
      ofsf << omegas[omega] << " ";
      ofsu << Mismatches[m][omega] << " ";
    }
    ofsm << endl;
    ofsf << endl;
    ofsu << endl;
  }
  ofsm.close();
  ofsf.close();
  ofsu.close();
  cout << "☺\n" << endl;
  
  return 0;
}
