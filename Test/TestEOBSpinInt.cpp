#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

#include "OrbitalPhasing_EOB.hpp"
#include "EOBModel.hpp"
#include "Flux.hpp"
#include "EasyParser.hpp"
using namespace std;
using WaveformUtilities::EOBParameters;

typedef WaveformUtilities::EOBMetricWithSpin Met;
typedef WaveformUtilities::EOBHamiltonianWithSpin Ham;
typedef WaveformUtilities::Flux_Pade44LogFac Flu;
typedef WaveformUtilities::Torque_KFPhi<Flu> Tor;

int main() {
  const bool WriteFiles = true;

  const double q = 1;
  const double delta=(q-1.0)/(q+1.0);
  const double chis = -0.96;//-0.9900;
  const double chia = 0.0;
  const double v0 = 0.1;//0.02025;
  vector<double> t, v, Phi;
  vector<double> r, prstar, pPhi;
  const int nsave = 20;
  const bool denseish = true;
  cout << "v0 = " << v0 << "\tOmega0 = " << v0*v0*v0 << "\tdelta = " << delta << "\tnu = " << (1.0-delta*delta)/4.0 << "\tchis = " << chis << endl;

  clock_t start,end;

  for(double rtol=1e-5; rtol>1.01e-10; rtol/=10) {
    const Met g(EOBParameters(delta, chis, chia));
    const Ham H(EOBParameters(delta, chis, chia), g);
    const Flu F(delta, chis, chia);
    const Tor T(delta, chis, chia, F);
    start = clock();
    WaveformUtilities::EOB<Met, Ham, Tor>(g, H, T, delta, chis, chia, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish, rtol);
    end = clock();
    cout << "rtol=" << rtol << " took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << flush;
    if(WriteFiles) {
      ofstream ofs(("Outputs/TestEOBSpinInt_rtol" + WaveformUtilities::DoubleToString(rtol) + ".dat").c_str());
      ofs << "# [1] = t" << endl << "# [2] = v" << endl << "# [3] = Phi" << endl
          << "# [4] = r" << endl << "# [5] = prstar" << endl << "# [6] = pPhi" << endl;
      ofs << setprecision(16);
      for(unsigned int i=0; i<t.size(); ++i) {
        ofs << t[i] << " " << v[i] << " " << Phi[i] << " " << r[i] << " " << prstar[i] << " " << pPhi[i] << endl;
      }
      ofs.close();
    }
    cout << "  t.size()=" << t.size();
    cout << "  ☺\n" << endl;
  }

  return 0;
}
