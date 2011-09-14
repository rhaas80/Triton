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
//   W.DropLMode(5);
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
    alpha[t] = 2*M_PI*(0.134 + (W.T(t)-W.T(0))/1000.0);
    beta[t] = M_PI*(0.012 + (W.T(t)-W.T(0))/(W.T().back()-W.T(0)));
    gamma[t] = 2*M_PI*(0.034 + (W.T(t)-W.T(0))/2000.0);
  }
  
  // Add the time-dependent rotation to the Waveform
  const Waveform WIni = W;
  W.RotatePhysicalSystem(alpha, beta, gamma);
  
  // Find the radiation axis
  vector<double> alphaOut, betaOut, gammaOut;
  YawFreeFrame(W, alphaOut, betaOut, gammaOut);
  
  // Write the results to file
  ofstream file("TestYawFree.dat");
  file << "# [1] = t\n"
       << "# [2] = alphaIn\n"
       << "# [3] = betaIn\n"
       << "# [4] = gammaIn\n"
       << "# [5] = alphaOut\n"
       << "# [6] = betaOut\n"
       << "# [7] = gammaOut\n"
       << "# [8] = alphaErr\n"
       << "# [9] = betaErr\n"
       << "# [10] = gammaErr\n"
       << setprecision(16);
  for(unsigned int t=0; t<W.NTimes(); ++t) {
    file << W.T(t) << " "
	 << alpha[t] << " "
	 << beta[t] << " "
	 << gamma[t] << " "
	 << alphaOut[t] << " "
	 << betaOut[t] << " "
	 << gammaOut[t] << " "
	 << alpha[t]+alphaOut[t] << " "
	 << beta[t]+betaOut[t] << " "
	 << gamma[t]+gammaOut[t] << endl;
  }
  file.close();
  
  // Output Waveforms
  Output("rhOverM_TestYawFree1.dat", WIni);
  Output("rhOverM_TestYawFree2.dat", W);
  Waveform W3 = W;
  Output("rhOverM_TestYawFree3.dat", W3.RotateCoordinates(alpha, beta, gamma));
  Waveform W4 = W;
  Output("rhOverM_TestYawFree4.dat", W4.RotateCoordinates(alphaOut, betaOut, gammaOut));
  Waveform W5 = W;
  Output("rhOverM_TestYawFree5.dat", W5.RotateCoordinates(alphaOut, betaOut, vector<double>(beta.size(), 0.0)));
  
  {
    const double Alpha = 0.0*M_PI;
    const double Beta = 0.3789*M_PI;
    const double Gamma = 0.0*M_PI;
    Waveform W6 = WIni;
    W6.RotatePhysicalSystem(alpha, beta, gamma).RotatePhysicalSystem(Alpha, Beta, Gamma);
    //W6.RotatePhysicalSystem(Alpha, Beta, Gamma).RotatePhysicalSystem(alpha, beta, gamma);
    YawFreeFrame(W6, alphaOut, betaOut, gammaOut);
    Output("rhOverM_TestYawFree6.dat", W6.RotateCoordinates(alphaOut, betaOut, gammaOut));
    Waveform W7 = WIni;
    W7.RotatePhysicalSystem(alpha, beta, gamma).RotatePhysicalSystem(Alpha, Beta, Gamma);
    //W7.RotatePhysicalSystem(Alpha, Beta, Gamma).RotatePhysicalSystem(alpha, beta, gamma);
    YawFreeFrame(W7, alphaOut, betaOut, gammaOut);
    Output("rhOverM_TestYawFree7.dat", W7.RotateCoordinates(alphaOut, betaOut, vector<double>(beta.size(), 0.0)));
  }
  
  return 0;
}
