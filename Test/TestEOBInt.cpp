#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

#include "OrbitalPhasing_EOB.hpp"
#include "EasyParser.hpp"
using namespace std;

int main() {
  const double delta = 0.0000;
  const double chis = 0;//-0.9900;
  const double v0 = 0.104;//0.02025;
//   vector<double> t, v, Phi;
//   vector<double> r, prstar, pPhi;
  const int nsave = 10;
  const bool denseish = true;
  cout << "v0 = " << v0 << "\tOmega0 = " << v0*v0*v0 << "\tdelta = " << delta << "\tchis = " << chis << endl;
  
  clock_t start,end;
  
//   {
//     const double rtol=1e-11;
//     const unsigned int trynum=0;
//     vector<double> t, v, Phi;
//     vector<double> r, prstar, pPhi;
//     start = clock();
//     WaveformUtilities::EOB(delta, chis, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish, rtol);
//     end = clock();
//     cout << "rtol=" << rtol << " took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << flush;
//     ofstream ofs(("Outputs/TestEOBInt_try" + WaveformUtilities::DoubleToString(trynum) + ".dat").c_str());
//     ofs << "# [1] = t" << endl << "# [2] = v" << endl << "# [3] = Phi" << endl
// 	<< "# [4] = r" << endl << "# [5] = prstar" << endl << "# [6] = pPhi" << endl;
//     ofs << setprecision(16);
//     for(unsigned int i=0; i<t.size(); ++i) {
//       ofs << t[i] << " " << v[i] << " " << Phi[i] << " " << r[i] << " " << prstar[i] << " " << pPhi[i] << endl;
//     }
//     ofs.close();
//     cout << "  t.size()=" << t.size();
//     cout << "  ☺" << endl;
//     t1.swap(t);
//   }
  
  const double sqrt10 = sqrt(10);
  for(double rtol=1e-9; rtol>1.01e-10; rtol/=10) {
    vector<double> t, v, Phi;
    vector<double> r, prstar, pPhi;
    start = clock();
    WaveformUtilities::EOB(delta, chis, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish, rtol);
    end = clock();
    cout << "rtol=" << rtol << " took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << flush;
    ofstream ofs(("Outputs/TestEOBInt_rtol" + WaveformUtilities::DoubleToString(rtol) + ".dat").c_str());
    ofs << "# [1] = t" << endl << "# [2] = v" << endl << "# [3] = Phi" << endl
	<< "# [4] = r" << endl << "# [5] = prstar" << endl << "# [6] = pPhi" << endl;
    ofs << setprecision(16);
    for(unsigned int i=0; i<t.size(); ++i) {
      ofs << t[i] << " " << v[i] << " " << Phi[i] << " " << r[i] << " " << prstar[i] << " " << pPhi[i] << endl;
    }
    ofs.close();
    cout << "  t.size()=" << t.size();
    cout << "  ☺" << endl;
  }
  
  return 0;
}
