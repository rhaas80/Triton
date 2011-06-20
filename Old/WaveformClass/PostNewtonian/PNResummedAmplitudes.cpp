#include "PNResummedAmplitudes.hpp"
#include "PNAmplitudes.hpp"
#include "VectorFunctions.hpp"
#include <cmath>
using namespace std;

//  Waveforms taken from ... 

void PNResummedAmplitudes(const int L, const int M, const vector<double>& r, const vector<double>& v, const vector<double>& vPhi, const vector<double>& Phi,
			  const vector<double>& Omega, const vector<double>& pPhi, const vector<double>& Heff, const vector<double>& Hreal,
			  const double delta, const double chia, const double chis, vector<double>& amp, vector<double>& phi,
			  const double PNAmpOrder)
{
  const double nu = (1.0-delta*delta)/4.0;
  const double chieff(chis+delta*chia); // a.k.a. chiKerr; SKerr = S + Sstar
  //const int epsilon = ((L+M) & 1) ? 1 : 0; // 1 if L+M is odd; 0 otherwise
  vector<double> Re(0);
  vector<double> Im(0);
  
  if(L>8 || abs(M)>L) {
    
    amp = 0.0*Phi;
    phi = 0.0*Phi;
    return;
    
  } else if(M==0) {
    
    PNAmplitudes(L, M, v, Phi, delta, chia, chis, amp, phi, PNAmpOrder);
    return;
    
  } else {
    
    //// On returning from the below, the remaining items not yet accounted for are:
    ////  (1) the Gamma terms in the Tlm
    ////  (2) the overal Phi dependence
    ////  (3) M<0 conversion
    #include "PNResummedAmplitudeTerms.hpp"
    
  }
  
  //// Take care of item (1) above
  vector<double> GammaArg(v.size());
  for(unsigned int i=0; i<v.size(); ++i) {
    const complex<double> LGamma( LogGamma(complex<double>(L+1, -2*M*Omega[i]*Hreal[i])) - complex<double>(LogGamma(L+1), 0.0) );
    amp[i] *= exp(real(LGamma));
    GammaArg[i] = imag(LGamma);
  }
  GammaArg = Unwrap(GammaArg);
  
  //// Take care of items (2) and (3) above
  if(M<0) {
    if(L%2) { phi = M_PI - GammaArg - phi - M*Phi; }
    else { phi = 0. - GammaArg - phi - M*Phi; }
  } else {
    phi = GammaArg + phi - M*Phi;
  }
  
  return;
}
