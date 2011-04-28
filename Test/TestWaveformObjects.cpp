#include <fstream>
#include <iomanip>

#include "WaveformFT.hpp"
#include "NoiseCurves.hpp";

using namespace WaveformUtilities;
using namespace WaveformObjects;
using namespace std;

int main() {
  const string Detector="IniLIGO_Approx";
  //const string InFile = "Inputs/rhOverM_GATech_L2_M2.dat";
  const string InFile = "Inputs/rhOverM_Hybrid_TaylorT4_N5_L2_M2.dat";
  const string OutWaveform = "Outputs/TestWaveformObjects_1.dat";
  const string OutWaveformScaled = "Outputs/TestWaveformObjects_2.dat";
  const string OutWaveformAAP = "Outputs/TestWaveformObjects_3.dat";
  const string OutWaveformFT = "Outputs/TestWaveformObjects_4.dat";
  const double TotalMassInSolarMasses = 110;
  const double DistanceInMegaparsecs = 100;
  const double dt = 1.0/IniLIGOSamplingFreq;
  
  const bool WriteFiles = false;
  
  cout << "Reading " << InFile << " ... " << flush;
  Waveform W(InFile, "MagArg");
  cout << "☺" << endl;
  
  if(WriteFiles) {
    cout << "Writing " << OutWaveform << " ... " << flush;
    ofstream ofs(OutWaveform.c_str(), ofstream::out);
    ofs << setprecision(14) << flush;
    ofs << W;
    ofs.close();
    cout << "☺" << endl;
  }

  W.DropBefore(-1.0e5).SetPhysicalMassAndDistance(TotalMassInSolarMasses, DistanceInMegaparsecs);
  
  if(WriteFiles) {
    cout << "Writing " << OutWaveformScaled << " ... " << flush;
    ofstream ofs1(OutWaveformScaled.c_str(), ofstream::out);
    ofs1 << setprecision(14) << flush;
    ofs1 << W;
    ofs1.close();
    cout << "☺" << endl;
  }
  
  WaveformAtAPoint WAAP(W, dt, 0.0, 0.0);
  
  if(WriteFiles) {
    cout << "Writing " << OutWaveformAAP << " ... " << flush;
    ofstream ofs2(OutWaveformAAP.c_str(), ofstream::out);
    ofs2 << setprecision(14) << flush;
    ofs2 << WAAP;
    ofs2.close();
    cout << "☺" << endl;
  }
  
  WaveformFT WFT(WAAP);
  
  if(WriteFiles) {
    cout << "Writing " << OutWaveformFT << " ... " << flush;
    ofstream ofs3(OutWaveformFT.c_str(), ofstream::out);
    ofs3 << setprecision(14) << flush;
    ofs3 << WFT;
    ofs3.close();
    cout << "☺" << endl;
  }

  vector<double> InversePSD = InverseNoiseCurve(WFT.F(), Detector);
  cout << "WFT.SNR() = " << WFT.SNR(InversePSD) << endl;
  cout << "WFT.Match(WFT, InversePSD) = " << WFT.Match(WFT, InversePSD) << endl;
  cout << "Normalizing" << endl;
  WFT.Normalize(InversePSD);
  cout << "WFT.SNR() = " << WFT.SNR(InversePSD) << endl;
  cout << "WFT.Match(WFT, InversePSD) = " << WFT.Match(WFT, InversePSD) << endl;
  
  return 0;
}
