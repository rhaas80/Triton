#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include "Waveform.hpp"
#include "EasyParser.hpp"
using namespace std;


int main() {
  string Approximant("T1");
  string OutDir("Output/");
  
  const double PNOrder=3.5;
  const double v0=0.144;//pow(0.006/2, 1.0/3.0);
  
  vector<double> MassRatio(1,0.0);
  MassRatio[0]=4.0;
  
  vector<double> Spins(1, 0.0);
  Spins[0]=0.85;
  
  vector<vector<int> > LMs(20, vector<int>(2, 0));
  LMs[0][0] = 2;  LMs[0][1]  = -2;
  LMs[1][0] = 2;  LMs[1][1]  =  2;
  LMs[2][0] = 3;  LMs[2][1]  = -2;
  LMs[3][0] = 3;  LMs[3][1]  =  2;
  LMs[4][0] = 4;  LMs[4][1]  = -4;
  LMs[5][0] = 4;  LMs[5][1]  = -2;
  LMs[6][0] = 4;  LMs[6][1]  =  2;
  LMs[7][0] = 4;  LMs[7][1]  =  4;
  LMs[8][0] = 5;  LMs[8][1]  = -4;
  LMs[9][0] = 5;  LMs[9][1]  =  4;
  LMs[10][0] = 6; LMs[10][1] = -6;
  LMs[11][0] = 6; LMs[11][1] = -4;
  LMs[12][0] = 6; LMs[12][1] =  4;
  LMs[13][0] = 6; LMs[13][1] =  6;
  LMs[14][0] = 7; LMs[14][1] = -6;
  LMs[15][0] = 7; LMs[15][1] =  6;
  LMs[16][0] = 8; LMs[16][1] = -8;
  LMs[17][0] = 8; LMs[17][1] = -6;
  LMs[18][0] = 8; LMs[18][1] =  6;
  LMs[19][0] = 8; LMs[19][1] =  8;
  
  for(unsigned int m=0; m<MassRatio.size(); ++m) {
    for(unsigned int s=0; s<Spins.size(); ++s) {
      const double q=MassRatio[m];
      const double delta((q-1)/(q+1));
      const double chis(0.5*(Spins[s]+Spins[s]));
      const double chia(0.5*(Spins[s]-Spins[s]));
      cout << "\nEvaluating q=" << q << " s=" << Spins[s] << endl;
      const int nsaveDense = 28000000;
      Waveform WDense("Taylor" + Approximant, delta, chis, chia, v0, PNOrder, LMs, nsaveDense, false);
      const int nsaveDenseish = 10;
      Waveform WDenseish("Taylor" + Approximant, delta, chis, chia, v0, PNOrder, LMs, nsaveDenseish, true);
      WDenseish = WDenseish.MatchTo(WDense, -6.0e5, -1.0e4);
      Waveform Diff = WDense/WDenseish;
      string FileName(OutDir + "q" + DoubleToString(MassRatio[m]) + "_s" + DoubleToString(Spins[s])+ "_s" + DoubleToString(Spins[s])
		      + "_" + Approximant + "_dense-denseish.dat");
      cout << "Writing " << FileName << " ... " << flush;
      ofstream ofs(FileName.c_str(), ofstream::out);
      ofs << Diff;
      ofs.close();
      cout << "☺" << endl;
    }
  }
  
  
  return 0;
}
