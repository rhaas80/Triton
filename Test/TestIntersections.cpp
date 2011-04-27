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
  
  ofstream ofsuab("TestIntersections_iab.dat", ofstream::out);
  ofsuab << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Intersection(xa, xb, MinStep, MinTime);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuab << i << " " << T[i] << endl;
  }
  ofsuab.close();
  
  ofstream ofsubc("TestIntersections_ibc.dat", ofstream::out);
  ofsubc << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Intersection(xb, xc, MinStep, MinTime);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsubc << i << " " << T[i] << endl;
  }
  ofsubc.close();
  
  ofstream ofsuba("TestIntersections_iba.dat", ofstream::out);
  ofsuba << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Intersection(xb, xa, MinStep, MinTime);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuba << i << " " << T[i] << endl;
  }
  ofsuba.close();
  
  ofstream ofsucb("TestIntersections_icb.dat", ofstream::out);
  ofsucb << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  T = WU::Intersection(xc, xb, MinStep, MinTime);
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsucb << i << " " << T[i] << endl;
  }
  ofsucb.close();
  
  ofstream ofsuca("TestIntersections_ica.dat", ofstream::out);
  ofsuca << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  try {
    T = WU::Intersection(xc, xa, MinStep, MinTime);
    cerr << "!!! Should have thrown an exception !!! " << __LINE__ << " " << __FILE__ << endl;
  } catch(int a) {
    //sprintf("%s", a);
    cerr << "Got empty intersection, as expected" << endl;
    T = vector<double>(0);
  }
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuca << i << " " << T[i] << endl;
  }
  ofsuca.close();
  
  ofstream ofsuac("TestIntersections_iac.dat", ofstream::out);
  ofsuac << "# [1] = Index\n"
	 << "# [2] = Time\n"
	 << setprecision(8) << flush;
  try {
    T = WU::Intersection(xa, xc, MinStep, MinTime);
    cerr << "!!! Should have thrown an exception !!! " << __LINE__ << " " << __FILE__ << endl;
  } catch(int a) {
    //sprintf("%s", a);
    cerr << "Got empty intersection, as expected" << endl;
    T = vector<double>(0);
  }
  for(unsigned int i=0; i<T.size(); ++i) {
    ofsuac << i << " " << T[i] << endl;
  }
  ofsuac.close();
  
  return 0;
}
