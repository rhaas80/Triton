#include "NumericalRecipes.hpp"

#include <iostream>

#include "VectorFunctions.hpp"
#include "Quaternions.hpp"
#include "Utilities.hpp"
#include "RadiationAxis.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

using WaveformUtilities::Matrix;
using WaveformUtilities::RadiationAxis;
using WaveformUtilities::MinimalRotation;
using WaveformUtilities::Quaternion;
using WaveformObjects::Waveform;


/// This tests the Schmidt technique (implemented as "RadiationAxis")
/// for finding the radiation axis of an arbitrary waveform.
/// More-or-less random functions alpha(t), beta(t), and gamma(t) are
/// chosen.  The physical system is then rotated by this amount.  The
/// resulting waveform is input to the RadiationAxis function, which
/// spits out its best guess for alpha(t) and beta(t).  The function
/// gamma(t) is not guessed, because this does not affect the
/// radiation axis.
/// 
/// The first output of this test is TestRadiationAxis.dat, which
/// gives columns of the angles input, the angles found, and the
/// error.  In each case, gamma can be safely ignored.  The error in
/// alpha and beta should be <~1e-8, except where the input beta is
/// close to 0 or pi.
/// 
/// The second output is a series of waveforms,
/// rhOverM_TestRadiationAxis{1,2,3,4}.dat.  Here, 1 is the original
/// waveform; 2 is the waveform when the physical system is rotated; 3
/// is the waveform when the coordinates are rotated by the angles
/// found by RadiationAxis; and 4 is the waveform when the coordinates
/// are rotated by the input angles.  Plotting the magnitudes of the
/// waveforms, 1, 3, and 4 should lie on top of each other, while 2
/// should look ugly.


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
	 << alpha[t]-alphaOut[t] << " "
	 << beta[t]-betaOut[t] << " "
	 << gamma[t]-gammaOut[t] << endl;
  }
  file.close();
  
  // Output Waveforms
  Output("rhOverM_TestRadiationAxis1.dat", WIni);
  Output("rhOverM_TestRadiationAxis2.dat", W);
  Waveform W3 = W;
  Output("rhOverM_TestRadiationAxis3.dat", W3.RotateCoordinates(alphaOut, betaOut, gammaOut));
  Waveform W4 = W;
  Output("rhOverM_TestRadiationAxis4.dat", W4.RotateCoordinates(alpha, beta, gamma));
  
  
  
  // Find the radiation axis
  vector<Quaternion> Q;
  RadiationAxis(W, Q);
  Quaternion Z(0,0,0,1);
  
  // Write the results to files
  ofstream file2("TestRadiationAxis2.dat");
  file2 << "# [1] = t\n"
       << "# [2] = xIn\n"
       << "# [3] = yIn\n"
       << "# [4] = zIn\n"
       << "# [5] = xOut\n"
       << "# [6] = yOut\n"
       << "# [7] = zOut\n"
       << "# [8] = xOut2\n"
       << "# [9] = yOut2\n"
       << "# [10] = zOut2\n"
       << setprecision(16);
  for(unsigned int t=0; t<W.NTimes(); ++t) {
    vector<double> AlphaBetaGamma = Q[t].EulerAnglesZYZ();
    file2 << W.T(t) << " "
	  << sin(beta[t])*cos(alpha[t]) << " "
	  << sin(beta[t])*sin(alpha[t]) << " "
	  << cos(beta[t]) << " "
	  << (Q[t]*Z*(Q[t].Conjugate())).Axis() << " "
	  << sin(AlphaBetaGamma[1])*cos(AlphaBetaGamma[0]) << " "
	  << sin(AlphaBetaGamma[1])*sin(AlphaBetaGamma[0]) << " "
	  << cos(AlphaBetaGamma[1])
	  << endl;
  }
  file2.close();
  
  return 0;
}
