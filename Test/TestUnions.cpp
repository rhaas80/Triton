#include <iostream>
#include <fstream>
#include <iomanip>
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

int main() {
  const double MinStep = 0.0;
  const double MinTime = -1e210;
  
  const unsigned int Na = 47;
  const unsigned int Nb = 97;
  const unsigned int Nc = 103;
  const double xaI = -10.0;
  const double dxa = 0.3;
  const double xaF = xaI + dxa*(Na-1); // = 3.8
  const double xbI = -1.01;
  const double dxb = 0.55;
  const double xbF = xbI + dxb*(Nb-1); // = 51.79
  const double xcI = 12.4;
  const double dxc = 0.179;
  const double xcF = xcI + dxc*(Nc-1); // = 30.658
  
  vector<double> xa(Na);
  for(unsigned int i=0; i<Na; ++i) {
    xa[i] = xaI + i*dxa;
  }
  vector<double> xb(Nb);
  for(unsigned int i=0; i<Nb; ++i) {
    xb[i] = xbI + i*dxb;
  }
  vector<double> xc(Nc);
  for(unsigned int i=0; i<Nc; ++i) {
    xc[i] = xcI + i*dxc;
  }
  
//   unsigned int Nuab;
//   {
    
//   }
  
  vector<double> T;
  
  ofstream ofsuab("TestUnions_uab.dat", ofstream::out);
  ofsuab << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Union(xa, xb, MinStep);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuab << i << " " << T[i] << endl;
  }
  ofsuab.close();
  
  ofstream ofsubc("TestUnions_ubc.dat", ofstream::out);
  ofsubc << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Union(xb, xc, MinStep);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsubc << i << " " << T[i] << endl;
  }
  ofsubc.close();
  
  ofstream ofsuba("TestUnions_uba.dat", ofstream::out);
  ofsuba << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Union(xb, xa, MinStep);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuba << i << " " << T[i] << endl;
  }
  ofsuba.close();
  
  ofstream ofsucb("TestUnions_ucb.dat", ofstream::out);
  ofsucb << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Union(xc, xb, MinStep);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsucb << i << " " << T[i] << endl;
  }
  ofsucb.close();
  
  ofstream ofsuca("TestUnions_uca.dat", ofstream::out);
  ofsuca << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  try {
    T = WU::Union(xc, xa, MinStep);
    cerr << "!!! Should have thrown an exception !!! " << __LINE__ << " " << __FILE__ << endl;
  } catch(int a) {
    //sprintf("%s", a);
    cerr << "Got disjoint union, as expected" << endl;
    T = vector<double>(0);
  }
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuca << i << " " << T[i] << endl;
  }
  ofsuca.close();
  
  ofstream ofsuac("TestUnions_uac.dat", ofstream::out);
  ofsuac << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  try {
    T = WU::Union(xa, xc, MinStep);
    cerr << "!!! Should have thrown an exception !!! " << __LINE__ << " " << __FILE__ << endl;
  } catch(int a) {
    //sprintf("%s", a);
    cerr << "Got disjoint union, as expected" << endl;
    T = vector<double>(0);
  }
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuac << i << " " << T[i] << endl;
  }
  ofsuac.close();
  
  return 0;
}
