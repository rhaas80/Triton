#include "NumericalRecipes.hpp"

#include <iostream>

#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "RadiationAxis.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

using WaveformUtilities::Matrix;
using WaveformUtilities::RadiationAxis;
using WaveformUtilities::YawFreeFrame;
using WaveformObjects::Waveform;


int main() {
  // Construct the original waveform
  string Approximant = "TaylorT4";
  const double delta = 0.05;
  const double chis = 0.0;
  const double chia = 0.0;
  const double v0 = 0.2;
  Matrix<int> LM(0,0); // This will default to all available modes
  const int nsave = 5000;
  const bool denseish = false;
  Waveform W(Approximant, delta, chis, chia, v0, LM, nsave, denseish);
  W.DropLMode(8);
  W.DropLMode(7);
  W.DropLMode(6);
  W.DropLMode(5);
//   W.DropLMode(4);
//   W.DropLMode(3);
  cout << "Created Waveform with " << W.NTimes() << " steps." << endl;
  
  // Construct the time-dependent precession angles
  vector<double> alpha(W.NTimes());
  vector<double> beta(W.NTimes());
  vector<double> gamma(W.NTimes());
//   for(unsigned int t=0; t<W.NTimes(); ++t) {
//     alpha[t] = M_PI*(0.134 + (W.T(t)-W.T(0))/3000.0);
//     beta[t] = M_PI/2.0;
//     gamma[t] = 0.0;
//   }
  for(unsigned int t=0; t<W.NTimes(); ++t) {
    alpha[t] = M_PI*(0.134 + (W.T(t)-W.T(0))/3000.0);
    beta[t] = M_PI*(0.012 + (W.T(t)-W.T(0))/(W.T().back()-W.T(0)));
    gamma[t] = M_PI*(0.034 + (W.T(t)-W.T(0))/2000.0);
  }
  
  // Add the time-dependent rotation to the Waveform
  const Waveform WIni = W;
  W.RotatePhysicalSystem(alpha, beta, gamma);
  
  // Find the radiation axis
  vector<double> alphaOut, betaOut, gammaOut;
  RadiationAxis(W, alphaOut, betaOut);
  gammaOut.resize(betaOut.size());
  
  // Write the results to files
  ofstream file("TestRadiationAxis.dat");
  file << "# [1] = t\n"
       << "# [2] = alphaIn\n"
       << "# [3] = betaIn\n"
       << "# [4] = gammaIn\n"
       << "# [5] = betaOut\n"
       << "# [6] = gammaOut\n"
       << "# [7] = betaErr\n"
       << "# [8] = gammaErr\n"
       << setprecision(16);
  for(unsigned int t=0; t<W.NTimes(); ++t) {
    file << W.T(t) << " "
	 << alpha[t] << " "
	 << beta[t] << " "
	 << gamma[t] << " "
	 << betaOut[t] << " "
	 << gammaOut[t] << " "
	 << beta[t]+betaOut[t] << " "
	 << gamma[t]+gammaOut[t] << endl;
  }
  file.close();
  
  // Output Waveforms
  Output("rhOverM_TestRadiationAxis1.dat", WIni);
  Output("rhOverM_TestRadiationAxis2.dat", W);
  Waveform W3 = W;
  Output("rhOverM_TestRadiationAxis3.dat", W3.RotateCoordinates(alphaOut, betaOut, gammaOut));
  Waveform W4 = W;
  Output("rhOverM_TestRadiationAxis4.dat", W4.RotateCoordinates(alpha, beta, gamma));
  
//   // Test the YawFree version
//   YawFreeFrame(W, alphaOut, betaOut, gammaOut);
//   Waveform W4 = W;
//   Output("rhOverM_TestRadiationAxis4.dat", W4.RotateCoordinates(alphaOut, betaOut, gammaOut));
  
  return 0;
}
