#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

#include "OrbitalPhasing_T1.hpp"
#include "OrbitalPhasing_T2.hpp"
#include "OrbitalPhasing_T3.hpp"
#include "OrbitalPhasing_T4.hpp"
#include "OrbitalPhasing_T4_Spin.hpp"
#include "Waveform.hpp"
#include "VectorFunctions.hpp"
using namespace std;

int main() {
  const bool SpeedComparison = false;
  const bool WaveformOutput = true;
  
  const double q = 1.0;
  const double delta=(q-1.0)/(q+1.0);
  const double v0 = 0.05;
  vector<double> t, v, Phi;
  vector<double> chis, chia, alpha, beta, gamma;
  vector<double> r, prstar, pPhi;
  const int NPoints = 10000;
  const int nsave = 40;
  const bool denseish = true;
  vector<double> chi1(3), chi2(3);
  const double chi1Mag = 0.999;
  const double chi2Mag = 0.999;
  chi1[0] = chi1Mag*sqrt(2);
  chi1[1] = 0.0;
  chi1[2] = chi1Mag*sqrt(2);
  chi2[0] = 0.0;
  chi2[1] = chi2Mag*sqrt(2);
  chi2[2] = -chi2Mag*sqrt(2);
  cout << "v0 = " << v0 << "\tdelta = " << delta << "\tchi1 = " << chi1 << "\tchi2 = " << chi2 << endl;
  
  clock_t start,end;
  
  const unsigned int N=1000;
  
  cout << "Calculating T4Spin ... " << flush;
  start = clock();
  WaveformUtilities::TaylorT4Spin(delta, chi1, chi2, v0,
				  t, v, Phi,
				  chis, chia, alpha, beta, gamma,
				  nsave, denseish);
  end = clock();
  cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
  cout << "Calculating TaylorT4Spin Waveform ... " << flush;
  start = clock();
  WaveformObjects::Waveform W("TaylorT4Spin", delta, chi1, chi2, v0, alpha, beta, gamma);
  end = clock();
  cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
  ofstream ofs("Outputs/TestPNSpin_T4Spin.dat");
  ofs << "# [1] = t" << endl
      << "# [2] = v" << endl
      << "# [3] = Phi" << endl
      << "# [4] = chis" << endl
      << "# [5] = chia" << endl
      << "# [6] = alpha" << endl
      << "# [7] = beta" << endl
      << "# [8] = gamma" << endl
      << "# [9] = x_PrecessionAxis" << endl
      << "# [10] = y_PrecessionAxis" << endl;
  ofs << setprecision(16);
  for(unsigned int i=0; i<t.size(); ++i) {
    ofs << t[i] << " " << v[i] << " " << Phi[i] << " "
	<< chis[i] << " " << chia[i] << " "
	<< alpha[i] << " " << beta[i] << " " << gamma[i] << " "
	<< sin(beta[i])*cos(alpha[i]) << " " << sin(beta[i])*sin(alpha[i])
	<< endl;
  }
  ofs.close();
  
  return 0;
}
