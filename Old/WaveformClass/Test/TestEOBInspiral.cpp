#include "Waveform.hpp"
#include "EOBOrbitalPhasing.hpp"
#include "PNOrbitalPhasingT1.hpp"
#include "PNOrbitalPhasingT2.hpp"
#include "PNOrbitalPhasingT3.hpp"
#include "PNOrbitalPhasingT4.hpp"
#include "NoiseCurves.hpp"
#include "Units.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  const double PNOrder = 3.5;
  const double q=10.0;
  const double delta = (q-1)/(q+1);
  const double chis = 0.95;
  const double chia = 0.0;
  
  const double DetectorMinFreq=AdvLIGOSeismicWall;
  const double WaveformMinOmega=2.0*M_PI*DetectorMinFreq/2.0;
  const double MinMass=5.0;  // Total binary mass in solar masses
  const double Minomega=0.005;  // Hybridization angular GW frequency (dimensionless)
//   const double v0=min(pow(0.49*Minomega, 1.0/3.0),
// 		      pow(NewtonsConstant*MinMass*SolarMass*(0.49*WaveformMinOmega)/(SpeedOfLight*SpeedOfLight*SpeedOfLight), 1.0/3.0));
  const double v0=0.14;
  cerr << "\nv0=" << v0 << " r0=" << pow(v0, -2.0) << " delta=" << delta << " chis=" << chis << "\n" << endl;
  
  vector<double> t(0);
  vector<double> v(0);
  vector<double> Phi(0);
  vector<double> r(0);
  vector<double> prstar(0);
  vector<double> pPhi(0);
  vector<double> tTn(0);
  vector<double> vTn(0);
  vector<double> PhiTn(0);
  
  cout << "Performing EOB calculation... " << endl;
  EOB(delta, chis, chia, v0, t, v, Phi, PNOrder, r, prstar, pPhi);
  cout << "☺" << endl;
  
  cout << "Writing Output/EOBPhasing.dat ... " << t.size() << flush;
  ofstream ofs("Output/EOBPhasing.dat", ofstream::out);
  ofs << "# [1] = t/M" << endl
      << "# [2] = Phi" << endl
      << "# [3] = v" << endl
      << "# [4] = r" << endl
      << "# [5] = prstar" << endl
      << "# [6] = pPhi" << endl;
  ofs << setprecision(14) << flush;
  for(unsigned int i=0; i<t.size(); ++i) {
    ofs << t[i] << " " << Phi[i] << " " << v[i] << " " << r[i] << " " << prstar[i] << " " << pPhi[i] << endl;
  }
  ofs.close();
  cout << "☺" << endl;
  
  vector<string> Approximants(4, "");
  Approximants[0] = "T1";
  Approximants[1] = "T2";
  Approximants[2] = "T3";
  Approximants[3] = "T4";
  for(unsigned int i=0; i<Approximants.size(); ++i) {
    const string Approximant = Approximants[i];
    cout << "Performing " + Approximant + " calculation... " << flush;
    if(Approximant == "T1") {
      TaylorT1(delta, chis, chia, v0, tTn, vTn, PhiTn, PNOrder);
    } else if(Approximant == "T2") {
      TaylorT2(delta, chis, chia, v0, tTn, vTn, PhiTn, PNOrder);
    } else if(Approximant == "T3") {
      TaylorT3(delta, chis, chia, v0, tTn, vTn, PhiTn, PNOrder);
    } else if(Approximant == "T4") {
      TaylorT4(delta, chis, chia, v0, tTn, vTn, PhiTn, PNOrder);
    }
    cout << "☺" << endl;
    
    cout << "Writing " + Approximant + "Phasing.dat ... " << flush;
    ofstream ofsTn(("Output/" + Approximant + "Phasing.dat").c_str(), ofstream::out);
    ofsTn << "# [1] = t/M" << endl
	  << "# [2] = Phi" << endl
	  << "# [3] = v" << endl;
    ofsTn << setprecision(14) << flush;
    for(unsigned int i=0; i<tTn.size(); ++i) {
      ofsTn << tTn[i] << " " << PhiTn[i] << " " << vTn[i] << endl;
    }
    ofsTn.close();
    cout << "☺" << endl;
  }
  
//   cout << "Reading NR data ... " << flush;
//   Waveform WNR("TestWaveforms/NRRaw/rhOverM_ExtrapolatedN5.dat", "AmpPhi");
//   cout << "☺" << endl;
//   WNR.DropLMode(8);
//   WNR.DropLMode(7);
//   WNR.DropLMode(6);
//   WNR.DropLMode(5);
//   WNR.DropZeroMModes();
//   WNR.DropOddMModes();
//   cout << "Trying to construct EOB ... " << flush;
//   Waveform WEOB("EOB", delta, chis, chia, v0, PNOrder, WNR.LM);
//   cout << "☺" << endl;
//   //WEOB = WEOB.OffsetTime(WNR.Peak22Time()).MatchTo(WNR, 580, 2000);
//   WEOB = WEOB.OffsetTime(WNR.Peak22Time()).MatchTo(WNR, 820, 2250);
//   cout << "Writing EOBWaveformError.dat ... " << flush;
//   ofstream ofW("Output/EOBWaveformError.dat", ofstream::out);
//   ofW << setprecision(12) << WEOB/WNR<< flush;
//   ofW.close();
//   cout << "☺" << endl;
  
//   Waveform WNR("TestWaveforms/NRRaw/rhOverM_ExtrapolatedN5.dat", "AmpPhi");
//   WNR.DropLMode(8);
//   WNR.DropLMode(7);
//   WNR.DropLMode(6);
//   WNR.DropLMode(5);
//   WNR.DropZeroMModes();
//   WNR.DropOddMModes();
//   Waveform WTn("Output/Taylor"+Approximant, delta, chis, chia, v0, PNOrder, WNR.LM);
//   WTn = WTn.OffsetTime(WNR.Peak22Time()).MatchTo(WNR, 580, 2000);
//   cout << "Writing " + Approximant + "WaveformError.dat ... " << flush;
//   ofstream ofW2(Approximant + "WaveformError.dat", ofstream::out);
//   ofW2 << setprecision(12) << WTn/WNR<< flush;
//   ofW2.close();
//   cout << "☺" << endl;
  
//   Waveform WTn("Taylor"+Approximant, delta, chis, chia, v0, PNOrder);
//   cout << "Writing Output/" + Approximant + "Waveform.dat ... " << flush;
//   ofstream ofW2(("Output/" + Approximant + "Waveform.dat").c_str(), ofstream::out);
//   ofW2 << setprecision(12) << WTn << flush;
//   ofW2.close();
//   cout << "☺" << endl;
  
//   Waveform WTn("EOB", delta, chis, chia, v0, PNOrder);
//   WTn.DropLMode(8);
//   WTn.DropLMode(7);
//   WTn.DropLMode(6);
//   WTn.DropLMode(5);
//   WTn.DropZeroMModes();
//   WTn.DropLMMode(4,3);
//   WTn.DropLMMode(4,2);
//   WTn.DropLMMode(4,1);
//   WTn.DropLMMode(3,1);
//   cout << "Writing Output/EOBWaveform.dat ... " << flush;
//   ofstream ofW2("Output/EOBWaveform.dat", ofstream::out);
//   ofW2 << setprecision(12) << WTn << flush;
//   ofW2.close();
//   cout << "☺" << endl;
  
  return 0;
}
