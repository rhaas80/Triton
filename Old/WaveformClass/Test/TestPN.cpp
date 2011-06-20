#include "Waveform.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  const double PNOrder = 3.5;
  vector<string> Approximants(4);
  Approximants[0] = "TaylorT1";
  Approximants[1] = "TaylorT2";
  Approximants[2] = "TaylorT3";
  Approximants[3] = "TaylorT4";
  Approximants[3] = "EOB";
  const double delta = 0.0;
  const double chis = 0.0;
  const double chia = 0.0;
  const double v0 = 0.11; //0.144;
  
  for(unsigned int i=0; i<Approximants.size(); ++i) {
    cout << "Approximant " << Approximants[i] << " ... \n" << flush;
    Waveform W(Approximants[i], delta, chis, chia, v0);//, vector<vector<int> >(1, vector<int>(2,2)), PNOrder);
    ofstream ofs(("TestWaveforms/rhOverM_" + Approximants[i] + ".dat").c_str(), ofstream::out);
    ofs << setprecision(14) << flush;
    ofs << W;
    ofs.close();
    cout << "☺" << endl;
  }
  
  return 0;
}
