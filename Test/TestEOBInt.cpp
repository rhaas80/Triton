#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

#include "OrbitalPhasing_EOB.hpp"
#include "EasyParser.hpp"
using namespace std;

int main() {
  const bool WriteFiles = false;
  
  const double q = 15;
  const double delta=(q-1.0)/(q+1.0);
  //const double delta = 0.6;
  const double chis = 0;//-0.9900;
  const double v0 = 0.144;//0.02025;
  vector<double> t, v, Phi;
  vector<double> r, prstar, pPhi;
  const int nsave = 0;
  const bool denseish = false;
  cout << "v0 = " << v0 << "\tOmega0 = " << v0*v0*v0 << "\tdelta = " << delta << "\tnu = " << (1.0-delta*delta)/4.0 << "\tchis = " << chis << endl;
  
  clock_t start,end;
  
  for(double rtol=1e-1; rtol>1.01e-9; rtol/=10) {
    start = clock();
    WaveformUtilities::EOB(delta, chis, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish, rtol);
    end = clock();
    cout << "rtol=" << rtol << " took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << flush;
    if(WriteFiles) {
      ofstream ofs(("Outputs/TestEOBInt_rtol" + WaveformUtilities::DoubleToString(rtol) + ".dat").c_str());
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
