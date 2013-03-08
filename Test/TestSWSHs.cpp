#include "SWSHs.hpp"
#include "FileIO.hpp"
#include "NumericalRecipes.hpp"
#include "Utilities.hpp"
using namespace std;
namespace WU = WaveformUtilities;

// These are taken from Eqs. (II.9)--(II.13) of arXiv:0709.0093v3, the 'Data Formats' document
void m2Y22(const double iota, const double phi, double& amp, double& arg) {
  amp = sqrt(5/(64*M_PI))*SQR(1+cos(iota));
  arg = 2*phi;
  return;
}

void m2Y21(const double iota, const double phi, double& amp, double& arg) {
  amp = sqrt(5/(16*M_PI))*sin(iota)*(1+cos(iota));
  arg = phi;
  return;
}

void m2Y20(const double iota, const double phi, double& amp, double& arg) {
  amp = sqrt(15/(32*M_PI))*SQR(sin(iota));
  arg = 0.0;
  return;
}

void m2Y2m1(const double iota, const double phi, double& amp, double& arg) {
  amp = sqrt(5/(16*M_PI))*sin(iota)*(1-cos(iota));
  arg = -phi;
  return;
}

void m2Y2m2(const double iota, const double phi, double& amp, double& arg) {
  amp = sqrt(5/(64*M_PI))*SQR(1-cos(iota));
  arg = -2*phi;
  return;
}

void m2Y2M(const int L, const int M, const double iota, const double phi, double& amp, double& arg) {
  if(abs(M)>L) {
    cerr << "abs(m)=" << abs(M) << "\tl=" << L << endl;
    Throw1WithMessage("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics.");
  }
  if(L!=2) {
    cerr << "l=" << L << endl;
    Throw1WithMessage("l!=2 not available in this function.");
  }
  switch(M) {
  case -2:
    m2Y2m2(iota, phi, amp, arg);
    return;
  case -1:
    m2Y2m1(iota, phi, amp, arg);
    return;
  case  0:
    m2Y20(iota, phi, amp, arg);
    return;
  case  1:
    m2Y21(iota, phi, amp, arg);
    return;
  case  2:
    m2Y22(iota, phi, amp, arg);
    return;
  }
  return;
}


int main() {
  
  // First, test against the 'Data Formats' convention
  {
    // Set up the angles at which comparison will be done
    const unsigned int N = 997;
    vector<double> varthetas(N);
    vector<double> varphis(N);
    for(unsigned int i=0; i<N; ++i) {
      varthetas[i] = M_PI*i/double(N);
      varphis[i] = 2*M_PI*i/double(N);
    }
    cout << "Testing against 'Data Formats' convention" << endl;
    const double AbsTol = 5.0e-16;
    const double RelTol = 5.0e-16;
    const int L=2;
    for(int M=-L; M<=L; ++M) {
      cout << "L=" << L << "\tM=" << M << endl;
      for(unsigned int i=0; i<N; ++i) {
	for(unsigned int j=0; j<N; ++j) {
	  double ampDF, argDF, ampWU, argWU;
	  m2Y2M(L, M, varthetas[i], varphis[j], ampDF, argDF);
	  WU::SWSH(L, M, varthetas[i], varphis[j], ampWU, argWU);
	  const double AbsAmpErr = (ampDF-ampWU);
	  const double RelAmpErr = 2*AbsAmpErr/(ampDF+ampWU);
	  const double AbsArgErr = (argDF-argWU);
	  if(abs(RelAmpErr)>RelTol && abs(AbsAmpErr)>AbsTol) {
	    cerr << "RelAmp: " << L << "\t" << M << "\t" << varthetas[i] << "\t" << varphis[j] << "\t" << ampDF << "\t" << ampWU << "\t" << RelAmpErr << "\t" << AbsAmpErr << endl;
	  }
	  if(abs(AbsArgErr)>AbsTol) {
	    cerr << "AbsArg: " << L << "\t" << M << "\t" << varthetas[i] << "\t" << varphis[j] << "\t" << argDF << "\t" << argWU << "\t" << AbsArgErr << endl;
	  }
	}
      }
    }
  }
  
  // Next, test against the Mathematica results
  {
    // Set up the angles at which comparison will be done
    const unsigned int N = 97;
    vector<double> varthetas(N);
    vector<double> varphis(N);
    for(unsigned int i=0; i<N; ++i) {
      varthetas[i] = M_PI*i/double(N);
      varphis[i] = 2*M_PI*i/double(N);
    }
    cout << "Testing against Mathematica results" << endl;
    const int LMax = 12;
    // sum_{l=2}^{LMax} (2l+1) = 2*(LMax*(LMax-1)/2-1) + (LMax-2) = (LMax+3)*(LMax-1)
    const int NModes = (LMax+3)*(LMax-1);
    vector<vector<double> > Data(NModes*SQR(N), vector<double>(2));
    vector<string> Header;
    WU::ReadDatFile("TestSWSHs.dat", Data, Header);
    const double AbsTol = 3.0e-13;
    const double RelTol = 1.0e-13;
    unsigned int k=0;
    for(int L=2; L<=LMax; ++L) {
      for(int M=-L; M<=L; ++M) {
	cout << "L=" << L << "\tM=" << M << endl;
	for(unsigned int i=0; i<N; ++i) {
	  for(unsigned int j=0; j<N; ++j) {
	    double ampMA, argMA, ampWU, argWU;
	    ampMA = Data[k][0];
	    argMA = Data[k][1];
	    k++;
	    WU::SWSH(L, M, varthetas[i], varphis[j], ampWU, argWU);
	    const double AbsAmpErr = (ampMA-ampWU);
	    const double RelAmpErr = 2*AbsAmpErr/(ampMA+ampWU);
	    const double RelArgErr = fmod(argMA-argWU, 2*M_PI);
	    if(abs(RelAmpErr)>RelTol && abs(AbsAmpErr)>AbsTol) {
	      cerr << "RelAmp: " << L << "\t" << M << "\t"
		   << setw(10) << setprecision(5) << varthetas[i] << "\t" << setw(10) << setprecision(5) << varphis[j] << "\t"
		   << setw(10) << setprecision(5) << ampMA << "\t" << setw(10) << setprecision(5) << ampWU << "\t"
		   << setw(10) << setprecision(5) << RelAmpErr << "\t" << setw(10) << setprecision(5) << AbsAmpErr << endl;
	    }
	    if(abs(RelArgErr)>AbsTol && abs(abs(RelArgErr)-2*M_PI)>AbsTol && abs(ampMA)>AbsTol) {
	      cerr << "RelArg: " << L << "\t" << M << "\t" << varthetas[i] << "\t" << varphis[j] << "\t" << argMA << "\t" << argWU << "\t" << RelArgErr << endl;
	    }
	  }
	}
      }
    }
  }
  
  return 0;
}
