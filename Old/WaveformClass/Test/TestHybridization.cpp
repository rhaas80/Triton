#include "Waveform.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}


int main() {
  const double PNOrder=3.5;
  const double delta=0.0;
  const double chis=0.0;
  const double chia=0.0;
  const double v0=0.10;
  const double DeltaT=500;
  const unsigned int Precision=15;
  const double omega=0.04;
  const double omegat1=-4e6, omegat2=3000;
  const double t1=500, t2=2000;
  cout << "Reading TestWaveforms/Hybrid/rhOverM_Hybrid.bbh ... " << flush;
  Waveform WaveformB("TestWaveforms/Hybrid/rhOverM_Hybrid.bbh");
  WaveformB.DropLMode(8);
  WaveformB.DropLMode(7);
  WaveformB.DropLMode(6);
  WaveformB.DropLMode(5);
  WaveformB.DropLMode(4);
  WaveformB.DropLMode(3);
  WaveformB.DropLMMode(2,-1);
  WaveformB.DropLMMode(2, 0);
  WaveformB.DropLMMode(2, 1);
  cout << "☺" << endl;
  
  cout << "Getting PN waveform ... \n\t" << flush;
  Waveform WaveformA("TaylorT2", delta, chis, chia, v0, PNOrder, WaveformB.LM);
  WaveformA.OffsetTime(4000);
  cout << "\t☺" << endl;
  
  /// Do the matching
  Waveform A = WaveformA.MatchToFrequency(WaveformB, omega, omegat1, omegat2);
  Waveform H = WaveformA.MatchToFrequency(WaveformB, omega, omegat1, omegat2, DeltaT);
  
  /// Output matching results
  cout << "Writing TestWaveforms/PNMatchedToNR.dat ... " << flush;
  ofstream ofsm("TestWaveforms/PNMatchedToNR.dat", ofstream::out);
  ofsm << setprecision(Precision) << flush;
  ofsm << A;
  ofsm.close();
  cout << "☺" << endl;
  cout << "Writing TestWaveforms/NR.dat ... " << flush;
  ofstream ofsn("TestWaveforms/NR.dat", ofstream::out);
  ofsn << setprecision(Precision) << flush;
  ofsn << WaveformB;
  ofsn.close();
  cout << "☺" << endl;
  cout << "Writing TestWaveforms/PNMatched-NR.dat ... " << flush;
  ofstream ofsmd("TestWaveforms/PNMatched-NR.dat", ofstream::out);
  ofsmd << setprecision(Precision) << flush;
  ofsmd << A/WaveformB;
  ofsmd.close();
  cout << "☺" << endl;
  
  /// Do the hybridization
  //Waveform H = WaveformA.HybridizeWith(WaveformB, t1, t2);
  cout << "Writing TestWaveforms/PNNRHybrid.dat ... " << flush;
  ofstream ofsh("TestWaveforms/PNNRHybrid.dat", ofstream::out);
  ofsh << setprecision(Precision) << flush;
  ofsh << H;
  ofsh.close();
  cout << "☺" << endl;
  cout << "Writing TestWaveforms/PNNRHybrid-PN.dat ... " << flush;
  ofstream ofshd("TestWaveforms/PNNRHybrid-PN.dat", ofstream::out);
  ofshd << setprecision(Precision) << flush;
  ofshd << H/WaveformA;
  ofshd.close();
  cout << "☺" << endl;
  cout << "Writing TestWaveforms/PNNRHybrid-NR.dat ... " << flush;
  ofstream ofshd2("TestWaveforms/PNNRHybrid-NR.dat", ofstream::out);
  ofshd2 << setprecision(Precision) << flush;
  ofshd2 << H/WaveformB;
  ofshd2.close();
  cout << "☺" << endl;
  
  return 0;
}
