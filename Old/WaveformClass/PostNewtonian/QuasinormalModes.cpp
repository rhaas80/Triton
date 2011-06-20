#include "QuasinormalModes.hpp"
#include "Interpolate.hpp"
#include <iostream>
using namespace std;

//// We have the following modes at present:
////   [0] = 2,2
////   [1] = 2,1
////   [2] = 3,3
////   [3] = 3,2
////   [4] = 4,4
//// We have the 8 overtones 0 through 7


vector<vector<int> > AvailableQNMLMs() {
  vector<vector<int> >LMs(10, vector<int>(2));
  LMs[0][0] = 2; LMs[0][1] = -2;
  LMs[1][0] = 2; LMs[1][1] = -1;
  LMs[2][0] = 2; LMs[2][1] =  1;
  LMs[3][0] = 2; LMs[3][1] =  2;
  LMs[4][0] = 3; LMs[4][1] = -3;
  LMs[5][0] = 3; LMs[5][1] = -2;
  LMs[6][0] = 3; LMs[6][1] =  2;
  LMs[7][0] = 3; LMs[7][1] =  3;
  LMs[8][0] = 4; LMs[8][1] = -4;
  LMs[9][0] = 4; LMs[9][1] =  4;
  return LMs;
}

void Initialize();
static bool Initialized=false;
static vector<double> EvaluatedSpins(21);
static vector<vector<vector<double> > > omegasRe(5, vector<vector<double> >(8, vector<double>(21, 0.0)));
static vector<vector<vector<double> > > omegasIm(5, vector<vector<double> >(8, vector<double>(21, 0.0)));

complex<double> QNMFrequencies(const int& L, const int& M, const int& N, const double& chi) {
  double omegaRe, omegaIm;
  QNMFrequencies(L,M,N,chi,omegaRe,omegaIm);
  return complex<double>(omegaRe, omegaIm);
}

void QNMFrequencies(const int& L, const int& M, const int& N, const double& chi, double& omegaRe, double& omegaIm) {
  if(N>7) {
    cerr << "N=" << N << " has not been included in the data." << endl;
    exit(1);
  }
  
  if(!Initialized) Initialize();
  
  //// Find the right pair of vectors
  unsigned int i=0;
  if(L==2 && abs(M)==2) {
    i=0;
  } else if(L==2 && abs(M)==1) {
    i=1;
  } else if(L==3 && abs(M)==3) {
    i=2;
  } else if(L==3 && abs(M)==2) {
    i=3;
  } else if(L==4 && abs(M)==4) {
    i=4;
  } else {
    cerr << "(L,M)=(" << L << "," << M << ") has not been included in the data." << endl;
    exit(1);
  }
  
  //// Interpolate each to the desired spin
  omegaRe = Interpolate(EvaluatedSpins, omegasRe[i][N], chi);
  omegaIm = -1*Interpolate(EvaluatedSpins, omegasIm[i][N], chi);
  
  return;
}

void Initialize() {
  //// Set the values of EvaluatedSpins, omegasRe, and omegasIm
  #include "QuasinormalModesTable.hpp"
  
  Initialized = true;
  return;
}
