#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>

#include "WaveformAtAPointFT.hpp"
#include "NoiseCurves.hpp"
#include "VectorFunctions.hpp"

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
  
  const bool WriteFiles = true;
  
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
  
  WaveformAtAPointFT WFT(WAAP);
  //WFT = WFT*(1.0/WFT.NTimes());
  
  if(WriteFiles) {
    cout << "Writing " << OutWaveformFT << " ... " << flush;
    ofstream ofs(OutWaveformFT.c_str(), ofstream::out);
    ofs << setprecision(14) << flush;
    ofs << WFT;
    ofs.close();
    cout << "☺" << endl;
  }
  
  vector<double> InversePSD = InverseNoiseCurve(WFT.F(), Detector);
  cout << "WFT.SNR() = " << WFT.SNR(InversePSD) << " [76 is typical]" << endl;
  cout << "WFT.InnerProduct(WFT, InversePSD) = " << WFT.InnerProduct(WFT, InversePSD) << " [5850 is typical]" << endl;
  cout << "WFT.Match(WFT, InversePSD) = " << WFT.Match(WFT, InversePSD) << " [5850 is typical]" << endl;
  cout << "Normalizing" << endl;
  WFT.Normalize(InversePSD);
  cout << "WFT.SNR() = " << WFT.SNR(InversePSD) << " [This should be 1]" << endl;
  cout << "WFT.InnerProduct(WFT, InversePSD) = " << WFT.InnerProduct(WFT, InversePSD) << " [This should be 1]" << endl;
  cout << "WFT.Match(WFT, InversePSD) = " << WFT.Match(WFT, InversePSD) << " [This should be 1]" << endl;
  
//   // Test that WFT.Re() is even and WFT.Im() is odd
//   const double Tol = 1e-7;
//   cout << "\n\nChecking that \\tilde{h}(-f) = \\tilde{h}^\\ast(f) to within " << Tol << " ..." << endl;
//   const WaveformAtAPointFT& F = WFT;
//   const double Max = max(maxfabs(F.Re()), maxfabs(F.Im()));
//   for(unsigned int i=0; i<F.NTimes()/2; ++i) {
//     const double a = 1.0 - F.Re(i)/F.Re(F.NTimes()-2-i);
//     const double b = 1.0 + F.Im(i)/F.Im(F.NTimes()-2-i);
//     if(a==a && abs(a)>Tol && fabs(F.Re(i))>Tol*Max) {
//       cout << "Re " << i << " " << F.Re(i) << " " << F.Re(F.NTimes()-2-i) << " " << a << endl;
//     }
//     if(b==b && abs(b)>Tol && fabs(F.Im(i))>Tol*Max) {
//       cout << "Im " << i << " " << F.Im(i) << " " << F.Im(F.NTimes()-2-i) << " " << b << endl;
//     }
//   }
//   cout << "Done checking." << endl;
  
  return 0;
}
