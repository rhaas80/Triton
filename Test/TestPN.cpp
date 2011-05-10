#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>

#include "OrbitalPhasing_T1.hpp"
#include "OrbitalPhasing_T4.hpp"
using namespace std;

int main() {
  const double delta = 0.0;
  const double chis = 0.0;
  const double v0 = 0.024;
  vector<double> t, v, Phi;
  const int nsave = 40;
  const bool denseish = true;
  
  for(unsigned int i=0; i<1000; ++i) {
    WaveformUtilities::TaylorT1(delta, chis, v0, t, v, Phi, nsave, denseish);
    WaveformUtilities::TaylorT4(delta, chis, v0, t, v, Phi, nsave, denseish);
  }
  
  {
    cout << "Calculating T1 ... " << endl;
    WaveformUtilities::TaylorT1(delta, chis, v0, t, v, Phi, nsave, denseish);
    cout << "☺" << endl;
    ofstream ofs("Outputs/TestPN_T1.dat");
    ofs << "# [1] = t" << endl
	<< "# [2] = v" << endl
	<< "# [3] = Phi" << endl;
    ofs << setprecision(16);
    for(unsigned int i=0; i<t.size(); ++i) {
      ofs << t[i] << " " << v[i] << " " << Phi[i] << endl;
    }
    ofs.close();
  }
  
  {
    cout << "Calculating T4 ... " << flush;
    WaveformUtilities::TaylorT4(delta, chis, v0, t, v, Phi, nsave, denseish);
    cout << "☺" << endl;
    ofstream ofs("Outputs/TestPN_T4.dat");
    ofs << "# [1] = t" << endl
	<< "# [2] = v" << endl
	<< "# [3] = Phi" << endl;
    ofs << setprecision(16);
    for(unsigned int i=0; i<t.size(); ++i) {
      ofs << t[i] << " " << v[i] << " " << Phi[i] << endl;
    }
    ofs.close();
  }
  
  return 0;
}
