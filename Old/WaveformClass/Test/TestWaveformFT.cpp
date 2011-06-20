#include "WaveformFT.hpp"
#include "VectorFunctions.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  //const double AdvLIGOSamplingFreq = 16384.0;
  const double AdvLIGOSamplingFreq = 4096.0;
  //const double AdvLIGOSamplingFreq = 2048.0;
  const double dt = 1.0/AdvLIGOSamplingFreq;
  const double HighMassLength = 4000.0;
  const int OutputPrecision = 6;
  cerr << "HighMassLength=" << HighMassLength << "\tSampFreq=" << AdvLIGOSamplingFreq << endl;
  
  // Read the data in and drop t<0
  //string InFileName = "TestWaveforms/Hybrid/rMPsi4_Hybrid_TaylorT4_N5.bbh";
  string InFileName = "TestWaveforms/Hybrid/rhOverM_Hybrid_TaylorT4_N5.bbh";
  cout << "Reading Waveform from " << InFileName << " ..." << flush;
  Waveform TConst = Waveform(InFileName.c_str(), "AmpPhi");
  TConst.DropZeroMModes();
  cout << " ☺" << endl;
  
  vector<double> Mass(3);
  Mass[0] = 33.0;
  Mass[1] = 110.0;
  Mass[2] = 311.0;
  
  for(unsigned int j=0; j<Mass.size(); ++j) {
    Waveform T=TConst;
    
    // Cut the data off below f=1Hz => Omega=2piHz
    //double Length = pow(311.0/Mass[j], 8./3.)*(HighMassLength);
    //T.DropBefore(3095-pow(311.0/Mass[j], 8./3.)*(HighMassLength));
    //cerr << "Dropped Before " << 3095-pow(311.0/Mass[j], 8./3.)*(HighMassLength) << endl;
    
    // Scale the data to the desired physical mass (in solar masses) and distance (in megaparsecs)
    T.SetPhysicalMass(Mass[j]).SetPhysicalDistance(100);
    
    // Interpolate to a LIGO grid with power-of-2 size
    WaveformAtAPoint T2(T, dt, 0.0, 0.0);
    T2.Window(1024).PadToPowerOfTwo();
    
//     // Check the time-domain waveform
//     if(j==0) {
//       cout << "Writing Waveform to Temp.dat ..." << flush;
//       ofstream ofs("Temp.dat", ofstream::out);
//       ofs << setprecision(OutputPrecision) << flush;
//       ofs << T2;
//       ofs.close();
//       cout << " ☺" << endl;
//     }
//     cerr << "Mass=" << Mass[j] << "MSun\tN=" << T2.Time.size() << "\tdt=" << T2.Time[1]-T2.Time[0] << endl;
    
    // Take the real part on the positive z-axis and FT
    cout << "Calculating WaveformFT..." << flush;
    WaveformFT F(T2);
    cout << " ☺" << endl;
    
    // If necessary, integrate twice
    int IntegrateNTimes = 2-(F.Type%3);
    if(IntegrateNTimes == 2) {
      cout << "Integrating twice... " << flush;
      F.Integrate(IntegrateNTimes);
      cout << "☺" << endl;
    } else if(IntegrateNTimes == 1) {
      cout << "Integrating once... " << flush;
      F.Integrate(IntegrateNTimes);
      cout << "☺" << endl;
    }
    
    // Output
    stringstream FileName;
    FileName << "TestWaveforms/TestWaveformFT_" << Waveform::Types[TConst.Type] << "_M" << Mass[j] << ".dat";
    cout << "Writing WaveformFT to " << FileName.str() << " ..." << flush;
    ofstream ofs(FileName.str().c_str(), ofstream::out);
    ofs << setprecision(OutputPrecision) << flush;
    ofs << F;
    ofs.close();
    cout << " ☺" << endl;
  }
  
  return 0;
}
