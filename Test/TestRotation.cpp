#include "NumericalRecipes.hpp"

#include <iostream>

#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Waveform.hpp"
#include "WaveformAmplitudes.hpp"
#include "RotationMaximization.hpp"
#include "RotationMaximizationNeg2.hpp"
#include "RotationMinimization.hpp"
#include "Minimize_MultiDim.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

using WaveformUtilities::Matrix;
using WaveformUtilities::WaveformAmplitudes;
using WaveformObjects::Waveform;

class MaximizeMagDiff {
private:
  MinimizeMag20 Min;
  MaximizeMag22 Max;
  MaximizeMag2Neg2 Maxn;
public:
  MaximizeMagDiff(const WaveformObjects::Waveform& iW)
    : Min(iW), Max(iW), Maxn(iW) { }
  void SetT(const unsigned int T) {
    Min.SetT(T);
    Max.SetT(T);
    Maxn.SetT(T);
  }
  double operator() (const std::vector<double>& x) const {
    return Min(x)+Max(x)+Maxn(x);
  }
  void df(const std::vector<double>& x, std::vector<double>& dfdx) const {
    Min.df(x, dfdx);
    std::vector<double> dfdx2(dfdx.size(), 0);
    Max.df(x, dfdx2);
    dfdx += dfdx2;
    Maxn.df(x, dfdx2);
    dfdx += dfdx2;
    return;
  }
};

class MaximizeMagSum {
private:
  MaximizeMag22 M;
  MaximizeMag2Neg2 Mn;
public:
  MaximizeMagSum(const WaveformObjects::Waveform& iW)
    : M(iW), Mn(iW) { }
  void SetT(const unsigned int T) {
    M.SetT(T);
    Mn.SetT(T);
  }
  double operator() (const std::vector<double>& x) const {
    return M(x)+Mn(x);
  }
  void df(const std::vector<double>& x, std::vector<double>& dfdx) const {
    M.df(x, dfdx);
    std::vector<double> dfdx2(dfdx.size(), 0);
    Mn.df(x, dfdx2);
    dfdx += dfdx2;
    return;
  }
};



int main() {
  vector<double> AlphaBetaGammaA(3, 0.0);
  AlphaBetaGammaA[0] = M_PI/17.0;
  AlphaBetaGammaA[1] = M_PI/7.0;
  AlphaBetaGammaA[2] = M_PI/23.0;
  vector<double> AlphaBetaGamma0 = AlphaBetaGammaA;
  vector<double> AlphaBetaGammaB(3, 0.0);
  AlphaBetaGammaB[0] = -AlphaBetaGammaA[2];
  AlphaBetaGammaB[1] = -AlphaBetaGammaA[1];
  AlphaBetaGammaB[2] = -AlphaBetaGammaA[0];
  
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
  W.DropLMode(4);
  W.DropLMode(3);
//   W.MagRef(1) *= 0.0;
//   W.MagRef(2) *= 0.0;
//   W.MagRef(3) *= 0.0;
  const Waveform WIni = W;
  unsigned int i=0;
  unsigned int j=0;
//   cout << "Writing Ini" << flush;
//   Output("Outputs/TestRotation_Ini.dat", W);
//   cout << "\nRotating " << j++ << flush;
//   W.Rotate(0, 0, 0);
//   cout << "\nWriting " << i++ << flush;
//   Output("Outputs/TestRotation_0.dat", W);
//   Output("Outputs/TestRotation_0-Ini.dat", W/WIni);
//   cout << "\nRotating " << j++ << flush;
//   W.Rotate(M_PI/7.0, 0, 0);
//   cout << "\nWriting " << i++ << flush;
//   Output("Outputs/TestRotation_1.dat", W);
//   Output("Outputs/TestRotation_1-Ini.dat", W/WIni);
//   W = WIni;
//   cout << "\nRotating " << j++ << flush;
//   W.Rotate(-M_PI/7.0, 0, M_PI/7.0);
//   cout << "\nWriting " << i++ << flush;
//   Output("Outputs/TestRotation_2.dat", W);
//   Output("Outputs/TestRotation_2-Ini.dat", W/WIni);
  cout << "\nRotating " << j++ << flush;
  W = WIni;
  W.Rotate(AlphaBetaGammaA[0], AlphaBetaGammaA[1], AlphaBetaGammaA[2]);
  cout << "\nWriting " << i++ << flush;
  Output("Outputs/TestRotation_3.dat", W);
  Output("Outputs/TestRotation_3-Ini.dat", W/WIni);
  cout << endl << "Done" << endl;
  
  WaveformAmplitudes Amp(delta, chis, chia);
  double hMag, hArg;
  Amp.rhOverM(2, 2, v0, 0.0, hMag, hArg);
  const unsigned int Prec = 18;
  const double Tolerance = 2.0e-15;
  int Iterations1=0, Iterations2=0;
  MaximizeMagDiff Minimizer(W);
//   MaximizeMagSum Minimizer(W);
//   MaximizeMag22 Minimizer(W);
//   MaximizeMag2Neg2 Minimizer(W);
//   MinimizeMag20 Minimizer(W);
  double Mag22=0;
  vector<double> BetaGamma(2, 0.0);
  BetaGamma[0] = AlphaBetaGammaB[1];
  BetaGamma[1] = AlphaBetaGammaB[2];
  BetaGamma = BetaGamma + M_PI/2.0;
  try {
    WaveformUtilities::dfpmin(BetaGamma, Tolerance, Iterations1, Mag22, Minimizer);
  } catch(int) { }
  try {
    WaveformUtilities::dfpmin(BetaGamma, Tolerance, Iterations2, Mag22, Minimizer);
  } catch(int) { }
  
  cout << "Exact:" << endl;
  cout << "xmin=" << setprecision(Prec) << -AlphaBetaGamma0 << "\tfmin=" << setprecision(Prec) << -hMag*hMag << "=" << -0.060432566507885*0.060432566507885 << endl;
  cout << "Numerical:" << endl;
  cout << "xmin=" << setprecision(Prec) << fmod(BetaGamma, M_PI) << " or " << fmod(BetaGamma, M_PI)-M_PI << "\tfmin=" << setprecision(Prec) << Mag22 << endl;
  cout << "Iterations=" << Iterations1+Iterations2 << endl;
  
  return 0;
}
