#include <omp.h>

#include "NumericalRecipes.hpp"

#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <algorithm>

#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Units.hpp"
#include "PostNewtonian.hpp"
#include "NoiseCurves.hpp"
#include "Waveforms.hpp"
#include "WaveformAtAPoint.hpp"
#include "WaveformAtAPointFT.hpp"

using WaveformUtilities::DoubleToString;
using WaveformUtilities::StringToDouble;
using WaveformUtilities::StringToInt;
using WaveformUtilities::max;
using WaveformUtilities::min;
using WaveformUtilities::InverseNoiseCurve;
using WaveformUtilities::AdvLIGOSeismicWall;
using WaveformUtilities::AdvLIGOSamplingFreq;
using WaveformUtilities::NewtonsConstant;
using WaveformUtilities::SolarMass;
using WaveformUtilities::SpeedOfLight;
using WaveformUtilities::QNMLMs;
using WaveformUtilities::FinalSpinApproximation;
using WaveformObjects::Waveform;
using WaveformObjects::Waveforms;
using WaveformObjects::WaveformAtAPoint;
using WaveformObjects::WaveformAtAPointFT;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::ofstream;
using std::stringstream;
using std::setprecision;
using std::setw;
using std::ios;


/// Call this program with 'MMContours <q> <chis>', where <q> is the mass ratio and <chis> is the symmetric spin parameter
/// Optionally, use 'MMContours <q> <chis> <StartWithMassNumber> <StartWithFreqNumber>' for restarts

int main(int argc, char* argv[]) {
  if(argc<3) {
    cerr << "Expecting at least two arguments; got " << argc-1 << endl;
    throw("Bad arguments");
  }
  
  const string Unique = "";
  
  // In case restart is needed:
  unsigned int StartWithMassNumber = argc>3 ? StringToInt(argv[3]) : 0;
  const unsigned int StartWithFreqNumber = argc>3 ? StringToInt(argv[4]) : 0;
  
  // Physical parameters
  const double q=StringToDouble(argv[1]);
  const double delta=(q-1.0)/(q+1.0);
  const double chis=StringToDouble(argv[2]);
  const double chia=0.0;
  const double vartheta = 0.0;
  const double varphi = 0.0;
  const double DistanceInMegaparsecs=100;
  
  // Ersatz NR
  const bool DropOddMModes = false; // (q==1) ? true : false;
  const double RoughMatchT1=-5000;
  const double RoughMatchT2=-2000;
  const double HybridDeltaT=10;
  
  // Boundaries and resolution of the graph
//   const double MinMass=5.0;  // Total binary mass in solar masses
  const double MinMass=7.5;  // Total binary mass in solar masses
  const double MaxMass=51.0;
//   const double MassStep = 0.25;
  const double MassStep = 2.5;
  const unsigned int NMasses=static_cast<unsigned int>(1.0+(MaxMass-MinMass)/MassStep);
  const double Minomega=0.005;  // Hybridization angular GW frequency (dimensionless)
  const double Maxomega=0.065;
//   const double omegaStep=0.0005;
  const double omegaStep=0.005;
  const unsigned int Nomegas=static_cast<unsigned int>(1.0+(Maxomega-Minomega)/omegaStep);
  
  // Detector and FFT info
  const string PSDName("AdvLIGO_ZeroDet_HighP");
  const double DetectorMinFreq=AdvLIGOSeismicWall;
  const double DetectorSamplingFreq=AdvLIGOSamplingFreq/2.0;
//   const double WaveformMinOmega=2.0*M_PI*DetectorMinFreq/2.0;
  const double WaveformMinOmega=2.0*M_PI*DetectorMinFreq*2;
  const double MinMismatch=1.0e-13; // This is the smallest mismatch we would believe, remembering that the match is actually subtracted from 1.0; roughly roundoff
  
  // PN waveforms
  const double v0=std::min(pow(0.4*Minomega, 1.0/3.0),
			   pow(NewtonsConstant*MinMass*SolarMass*(0.4*WaveformMinOmega)/(SpeedOfLight*SpeedOfLight*SpeedOfLight), 1.0/3.0));
  
  // Files
  const string MassesFileName("Output/Masses_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + Unique + ".dat");
  const string FrequenciesFileName("Output/Frequencies_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + Unique + ".dat");
  const string MismatchesMaxFileName("Output/MismatchesMax_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + Unique + ".dat");
  vector<string> ApproximantNames(5,"");
  ApproximantNames[0] = "T1";
  ApproximantNames[1] = "T2";
  ApproximantNames[2] = "T3";
  ApproximantNames[3] = "T4";
  ApproximantNames[4] = "NR";
  vector<string> MismatchesFileNames(0,"");
  for(unsigned int i=0; i<ApproximantNames.size(); ++i) {
    for(unsigned int j=i+1; j<ApproximantNames.size(); ++j) {
      MismatchesFileNames.push_back("Output/Mismatches" + ApproximantNames[i] + "-" + ApproximantNames[j]
				    +"_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + Unique + ".dat");
    }
  }
  const unsigned int FilePrecision=14;
  
  // Screen output
  const unsigned int MatchDisplayPrecision=4;
  const unsigned int MatchDisplayWidth=MatchDisplayPrecision+5;
  
  const unsigned int nsave=20;
  const unsigned int nsaveEOB=5;
  const bool denseish=true;
  
  
  //////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////
  
  const double dt = 1.0/DetectorSamplingFreq;
  time_t start,end;
  
  //// Initialize the Masses, omegas, and Mismatches
  vector<double> Masses(NMasses, MinMass);
  vector<double> omegas(Nomegas, Minomega);
  for(unsigned int i=1; i<NMasses; ++i) {
    Masses[i] = MinMass + i*(MaxMass-MinMass)/double(NMasses-1);
  }
  for(unsigned int i=1; i<Nomegas; ++i) {
    omegas[i] = Minomega + i*(Maxomega-Minomega)/double(Nomegas-1);
  }
  cout << "Running\n\tMasses=" << Masses << "\n\tomegas=" << omegas << endl << endl;
  
  //// Load NR Waveform, get rid of unecessary modes, and hybridize if necessary
  cout << "Creating EOB... " << endl;
  Waveform NRc("EOB", delta, chis, chia, v0, QNMLMs(), nsaveEOB, denseish);
  NRc.AttachQNMs(delta, FinalSpinApproximation(delta, chis));
  if(DropOddMModes) { NRc.DropOddMModes(); }
  const double NRPeak22Time = NRc.Peak22Time();
  cout << "☺ \t(Peak time = " << NRPeak22Time << ")\n" << endl;
  
  //// Compute PN Waveforms and roughly match to the NR waveform
  cout << "Creating PN... " << endl;
  const int NWaveforms = 4;
  Waveforms Wsc(NWaveforms);
  Wsc[0] = Waveform("TaylorT1", delta, chis, chia, v0, NRc.LM(), nsave, denseish);
  Wsc[3] = Waveform("TaylorT4", delta, chis, chia, v0, NRc.LM(), nsave, denseish);
  Wsc[1] = Waveform("TaylorT2", delta, chis, chia, v0, NRc.LM(), std::max(Wsc[0].NTimes(), Wsc[3].NTimes()));
  Wsc[2] = Waveform("TaylorT3", delta, chis, chia, v0, NRc.LM(), std::max(Wsc[0].NTimes(), Wsc[3].NTimes()));
  //#pragma omp parallel for
  for(int n=0; n<NWaveforms; ++n) {
    Wsc[n].AddToTime(NRPeak22Time-Wsc[n].T().back());
    Wsc[n].AlignTo(NRc, RoughMatchT1, RoughMatchT2);
  }
  
  // Output some nice diagnostics
  cout << "Length of TaylorT1: " << Wsc[0].NTimes() << endl;
  cout << "Length of TaylorT2: " << Wsc[1].NTimes() << endl;
  cout << "Length of TaylorT3: " << Wsc[2].NTimes() << endl;
  cout << "Length of TaylorT4: " << Wsc[3].NTimes() << endl;
  cout << "Length of EOB: " << NRc.NTimes() << endl << endl;
  cout << "Phase extent of TaylorT1: " << Wsc[0].Arg(0).back()-Wsc[0].Arg(0,0) << endl;
  cout << "Phase extent of TaylorT2: " << Wsc[1].Arg(0).back()-Wsc[1].Arg(0,0) << endl;
  cout << "Phase extent of TaylorT3: " << Wsc[2].Arg(0).back()-Wsc[2].Arg(0,0) << endl;
  cout << "Phase extent of TaylorT4: " << Wsc[3].Arg(0).back()-Wsc[3].Arg(0,0) << endl;
  cout << "Phase extent of EOB: " << NRc.Arg(0).back()-NRc.Arg(0,0) << endl << endl;
  
  //// Find the parameters possible with these waveforms
  double MaxAvailableomega=0.0;
  double MinAvailableomega=0.0;
  double MaxAvailableT=0.0;
  double MinAvailableT=0.0;
  {
    vector<double> MaxAvailableomegas(NWaveforms+1, 0.0);
    vector<double> MinAvailableomegas(NWaveforms+1, 0.0);
    vector<double> MaxAvailableTs(NWaveforms+1, 0.0);
    vector<double> MinAvailableTs(NWaveforms+1, 0.0);
    for(int i=0; i<NWaveforms; ++i) {
      vector<double> PNomega(Wsc[i].Omega2m2());
      MaxAvailableomegas[i]=max(PNomega);
      MinAvailableomegas[i]=min(PNomega);
      MaxAvailableTs[i]=Wsc[i].T().back();
      MinAvailableTs[i]=Wsc[i].T(0);
    }
    vector<double> NROmega(NRc.Omega2m2());
    unsigned int i=0;
    while(NRc.T(i)<NRPeak22Time) { ++i; }
    NROmega.erase(NROmega.begin()+i, NROmega.begin()+NROmega.size());
    MaxAvailableomegas[NWaveforms] = max(NROmega);
    MinAvailableomegas[NWaveforms] = min(NROmega);
    MaxAvailableTs[NWaveforms] = NRPeak22Time;
    MinAvailableTs[NWaveforms] = NRc.T(0);
    MaxAvailableomega=min(MaxAvailableomegas); // Note that the reversal
    MinAvailableomega=max(MinAvailableomegas); //   between min and
    MaxAvailableT=min(MaxAvailableTs);         //   max in these lines
    MinAvailableT=max(MinAvailableTs);         //   is correct
  }
  cout << "Maximum mutually available omega: " << MaxAvailableomega << "." << endl;
  cout << "Minimum mutually available omega: " << MinAvailableomega << "." << endl;
  cout << "Maximum mutually available time: "  << MaxAvailableT << "." << endl;
  cout << "Minimum mutually available time: "  << MinAvailableT << ".\n" << endl;
  
  //// Clear the output files
  if(StartWithMassNumber==0 && StartWithFreqNumber==0) {
    ofstream ofsm(MassesFileName.c_str(), ofstream::out);
    ofstream ofsf(FrequenciesFileName.c_str(), ofstream::out);
    ofstream ofsu(MismatchesMaxFileName.c_str(), ofstream::out);
    ofsm.seekp(0,ios::beg);
    ofsf.seekp(0,ios::beg);
    ofsu.seekp(0,ios::beg);
    ofsm.close();
    ofsf.close();
    ofsu.close();
    for(unsigned int i=0; i<MismatchesFileNames.size(); ++i) {
      ofstream ofs(MismatchesFileNames[i].c_str(), ofstream::out);
      ofs.seekp(0,ios::beg);
      ofs.close();
    }
  }
  
  
  //////////////////////////////////////
  //// Main calculation loops below ////
  //////////////////////////////////////
  
  
  //// Loop over matching frequencies
  for(unsigned int o=StartWithFreqNumber; o<omegas.size(); ++o) {
    const double omega = omegas[o];
    cout << "omega=" << omega << endl;
    //// Construct the hybrids
    Waveforms Ws(Wsc);
    time (&start);
    #pragma omp parallel for
    for(int n=0; n<NWaveforms; n++) {
      Ws[n].AlignTo_F(NRc, omega, MinAvailableT, MaxAvailableT); // Just match
      Ws[n].AlignTo_F(NRc, omega, MinAvailableT, MaxAvailableT, HybridDeltaT); // Now hybridize
    }
    #pragma omp barrier
    time (&end);
    cout << "\t\tHybridization took " << difftime(end,start) << " seconds." << endl;
    
    //// Loop over total masses
    for(unsigned int m=StartWithMassNumber; m<Masses.size(); ++m) {
      time (&start);
      
      const double Mass = Masses[m];
      cout << "\tm = " << setw(4) << Mass << ": " << flush;
      
      //// Scale the Waveforms to their physical (dimensionful) sizes
      const int NFs=NWaveforms+1;
      Waveforms Hs(NFs);
      //#pragma omp parallel for
      for(int n=0; n<NWaveforms; ++n) {
	Hs[n] = Ws[n];
	Hs[n].SetPhysicalMassAndDistance(Mass, DistanceInMegaparsecs);
      }
      Hs[NWaveforms] = NRc;
      Hs[NWaveforms].SetPhysicalMassAndDistance(Mass, DistanceInMegaparsecs);
      Hs.SetCommonTime(dt/4.0, -1.e300);
      
      //// Cut off the Waveforms below the detector's minimum frequency
      double DropBeforeTime(Hs[NFs-1].T(0));
      {
	vector<double> Omega = Hs[NFs-1].Omega2m2();
	unsigned int i=0;
	while(i<Omega.size() && Omega[i]<WaveformMinOmega) { ++i; }
	DropBeforeTime = Hs[NFs-1].T(i);
	//#pragma omp parallel for
	for(int n=0; n<NFs; ++n) {
	  Hs[n].DropBefore(DropBeforeTime);
	}
      }
      
      //// Transform to Fourier domain
      vector<WaveformAtAPointFT> Fs(NFs);
      vector<double> InversePSD;
      #pragma omp parallel
      {
	#pragma omp for
	for(int n=0; n<NFs; ++n) {
	  Fs[n] = WaveformAtAPointFT(WaveformAtAPoint(Hs[n], dt, vartheta, varphi));
	  //Hs[n].clear(); /// Clear some memory
	}
	#pragma omp barrier /// I think this is implied, but just in case...
	
	#pragma omp master
	Hs.clear(); /// Clear some memory
	
	//// Get the InversePSD
	#pragma omp master
	InversePSD = InverseNoiseCurve(Fs[0].F(), PSDName);
	#pragma omp barrier
	
	//// Normalize the waveforms
	#pragma omp for
	for(int n=0; n<NFs; ++n) {
	  Fs[n].Normalize(InversePSD);
	}
	#pragma omp barrier
      }
      
      //// Calculate mismatches
      //double MaxMismatch=0.0;
      vector<double> Mismatches((NFs*(NFs-1))/2);
      #pragma omp parallel for
      for(int i=0; i<(NFs*(NFs-1))/2; ++i) {
	int n1=3, n2=4;
	if(i<4) { n1=0; n2=i+1; }
	else if(i<7) { n1=1; n2=i-2; }
	else if(i<9) { n1=2; n2=i-4; }
	double Mismatch = 1.0-Fs[n1].Match(Fs[n2], InversePSD);
	if(Mismatch<MinMismatch) { Mismatch = MinMismatch; }
	//if(Mismatch>MaxMismatch) { MaxMismatch = Mismatch; }
	Mismatches[i] = Mismatch;
      }
      #pragma omp barrier
      time (&end);
      for(int n1=0; n1<NFs; ++n1) {
	Fs[n1].clear();
      }
      const double MaxMismatch = max(Mismatches);
      cout << setw(MatchDisplayWidth) << setprecision(MatchDisplayPrecision) << Mismatches << "  max(Mismatches)=" << MaxMismatch << endl;
      cout << "\t\tComputation took " << difftime(end,start) << " seconds." << endl;
      
      //// Output data to Masses and Frequencies files
      ofstream ofsm(MassesFileName.c_str(), ofstream::app);
      ofstream ofsf(FrequenciesFileName.c_str(), ofstream::app);
      ofsm << setprecision(FilePrecision) << Mass << " " << flush;
      ofsf << setprecision(FilePrecision) << omega << " " << flush;
      if(m==Masses.size()-1) {
	ofsm << endl;
	ofsf << endl;
      }
      ofsm.close();
      ofsf.close();
      
      //// Output max mismatch
      ofstream ofsu(MismatchesMaxFileName.c_str(), ofstream::app);
      ofsu << setprecision(FilePrecision) << MaxMismatch << " " << flush;
      if(m==Masses.size()-1) {
	ofsu << endl;
      }
      ofsu.close();
      
      //// Output individual mismatches
      for(unsigned int FileNameCounter=0; FileNameCounter<MismatchesFileNames.size(); FileNameCounter++) {
	ofstream ofsu(MismatchesFileNames[FileNameCounter].c_str(), ofstream::app);
	ofsu << setprecision(FilePrecision) << Mismatches[FileNameCounter] << " " << flush;
	if(m==Masses.size()-1) {
	  ofsu << endl;
	}
	ofsu.close();
      }
      
      //// Note that we've finished this step
      ofstream ofs(("FinishedStep_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + Unique).c_str(), ofstream::out);
      if(m==Masses.size()-1) {
	if(o==omegas.size()-1) {
	  ofs << 0 << " " << 0 << flush;
	} else {
	  ofs << 0 << " " << o+1 << flush;
	}
      } else {
	ofs << m+1 << " " << o << flush;
      }
      ofs.close();
    } // Loop over masses
    
    StartWithMassNumber=0; // Make sure the next loop includes all masses
    
  } // Loop over frequencies
  
  return 0;
}
