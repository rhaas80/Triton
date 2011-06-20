#include "PNAmplitudes.hpp"
#include "VectorFunctions.hpp"
#include <cmath>
using namespace std;

///  Waveforms taken from Eqs. (9.3) and (9.4) of
///  arXiv:0802.1249v2, with spin terms derived using
///  Eq. (9.2) of that reference with Eqs. (F24) and(F25)
///  of doi:10.1103/PhysRevD.54.4813, noting the overall
///  sign error in Eq. (F25c).

void PNAmplitudes(const int L, const int M, const vector<double>& v, const vector<double>& Phi, const double delta,
		  const double chia, const double chis, vector<double>& amp, vector<double>& phi, const double PNAmpOrder)
{
  const double nu = (1.0-delta*delta)/4.0;
  vector<double> Re(0);
  vector<double> Im(0);
  
  if(L>8 || abs(M)>L) {
    
    amp = 0.0*Phi;
    phi = 0.0*Phi;
    return;
    
  } else {
    
    if(PNAmpOrder==0) {
      //cerr << "PNAmpOrder==0\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 1);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==0
    
    else if(PNAmpOrder==0.5) {
      //cerr << "PNAmpOrder==0.5\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = (v*delta)/3.;
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 1);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = (v*delta)/(12.*sqrt(14));
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = (-3*sqrt(1.0714285714285714)*v*delta)/4.;
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==0.5
    
    else if(PNAmpOrder==1.) {
      //cerr << "PNAmpOrder==1.\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = v*(delta/3. + v*(chia/2. + (delta*chis)/2.));
          break;
          
        case 2:
          Re = 1 + pow(v,2)*(-2.5476190476190474 + (55*nu)/42.);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = (v*delta)/(12.*sqrt(14));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(0.7142857142857143)/3. - sqrt(0.7142857142857143)*nu);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = (-3*sqrt(1.0714285714285714)*v*delta)/4.;
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(5)/63. - (sqrt(5)*nu)/21.);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = pow(v,2)*((-8*sqrt(0.7142857142857143))/9. + (8*sqrt(0.7142857142857143)*nu)/3.);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==1.
    
    else if(PNAmpOrder==1.5) {
      //cerr << "PNAmpOrder==1.5\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = v*(delta/3. + v*(v*((-17*delta)/84. + (5*delta*nu)/21.) + chia/2. + (delta*chis)/2.));
          break;
          
        case 2:
          Re = 1 + pow(v,2)*(-2.5476190476190474 + (55*nu)/42. + v*(2*M_PI - (4*delta*chia)/3. + (-1.3333333333333333 + (4*nu)/3.)*chis));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = v*(delta/(12.*sqrt(14)) + pow(v,2)*(-(sqrt(0.2857142857142857)*delta)/9. - (delta*nu)/(18.*sqrt(14))));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(0.7142857142857143)/3. - sqrt(0.7142857142857143)*nu + (4*sqrt(0.7142857142857143)*v*nu*chis)/3.);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = v*((-3*sqrt(1.0714285714285714)*delta)/4. + pow(v,2)*(3*sqrt(1.0714285714285714)*delta - (3*sqrt(1.0714285714285714)*delta*nu)/2.));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*(delta/(84.*sqrt(10)) - (delta*nu)/(42.*sqrt(10)));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(5)/63. - (sqrt(5)*nu)/21.);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((-9*delta)/(4.*sqrt(70)) + (9*delta*nu)/(2.*sqrt(70)));
          break;
          
        case 4:
          Re = pow(v,2)*((-8*sqrt(0.7142857142857143))/9. + (8*sqrt(0.7142857142857143)*nu)/3.);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*(delta/(288.*sqrt(385)) - (delta*nu)/(144.*sqrt(385)));
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((-9*sqrt(0.02727272727272727)*delta)/32. + (9*sqrt(0.02727272727272727)*delta*nu)/16.);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((625*delta)/(96.*sqrt(66)) - (625*delta*nu)/(48.*sqrt(66)));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==1.5
    
    else if(PNAmpOrder==2.) {
      //cerr << "PNAmpOrder==2.\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = pow(v,4)*(delta/6. + (delta*log(16))/6.);
          Im = v*(delta/3. + v*(v*((-17*delta)/84. + (M_PI*v*delta)/3. + (5*delta*nu)/21.) + chia/2. + (delta*chis)/2.));
          break;
          
        case 2:
          Re = 1 + pow(v,2)*(-2.5476190476190474 + (55*nu)/42. + v*(2*M_PI - (4*delta*chia)/3. + (-1.3333333333333333 + (4*nu)/3.)*chis + v*(-1.437169312169312 + nu*(-4.949074074074074 + (2047*nu)/1512.) - 2*nu*pow(chia,2) + 2*nu*pow(chis,2))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = pow(v,4)*((sqrt(3.5)*delta)/60. + (delta*log(1024))/(60.*sqrt(14)));
          Im = v*(delta/(12.*sqrt(14)) + pow(v,2)*(-(sqrt(0.2857142857142857)*delta)/9. + (M_PI*v*delta)/(12.*sqrt(14)) - (delta*nu)/(18.*sqrt(14))));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(0.7142857142857143)/3. - sqrt(0.7142857142857143)*nu + v*(v*(-193/(54.*sqrt(35)) + nu*((145*sqrt(0.7142857142857143))/54. - (73*sqrt(0.7142857142857143)*nu)/54.)) + (4*sqrt(0.7142857142857143)*nu*chis)/3.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = pow(v,4)*((-9*sqrt(2.1)*delta)/4. + (9*sqrt(1.0714285714285714)*delta*log(1.5))/2.);
          Im = v*((-3*sqrt(1.0714285714285714)*delta)/4. + pow(v,2)*(3*sqrt(1.0714285714285714)*delta - (9*sqrt(1.0714285714285714)*M_PI*v*delta)/4. - (3*sqrt(1.0714285714285714)*delta*nu)/2.));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*(delta/(84.*sqrt(10)) - (delta*nu)/(42.*sqrt(10)));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(5)/63. - (sqrt(5)*nu)/21. + pow(v,2)*(-437/(1386.*sqrt(5)) + nu*((115*sqrt(5))/594. - (19*sqrt(5)*nu)/1386.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((-9*delta)/(4.*sqrt(70)) + (9*delta*nu)/(2.*sqrt(70)));
          break;
          
        case 4:
          Re = pow(v,2)*((-8*sqrt(0.7142857142857143))/9. + (8*sqrt(0.7142857142857143)*nu)/3. + pow(v,2)*(2372/(99.*sqrt(35)) + nu*((-5092*sqrt(0.7142857142857143))/297. + (100*sqrt(35)*nu)/99.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*(delta/(288.*sqrt(385)) - (delta*nu)/(144.*sqrt(385)));
          break;
          
        case 2:
          Re = pow(v,4)*(2/(27.*sqrt(55)) + nu*((-2*sqrt(0.45454545454545453))/27. + (2*sqrt(0.45454545454545453)*nu)/27.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((-9*sqrt(0.02727272727272727)*delta)/32. + (9*sqrt(0.02727272727272727)*delta*nu)/16.);
          break;
          
        case 4:
          Re = pow(v,4)*(-32/(9.*sqrt(165)) + nu*((32*sqrt(0.15151515151515152))/9. - (32*sqrt(0.15151515151515152)*nu)/9.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((625*delta)/(96.*sqrt(66)) - (625*delta*nu)/(48.*sqrt(66)));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = pow(v,4)*(2/(297.*sqrt(65)) + nu*((-2*sqrt(0.38461538461538464))/297. + (2*sqrt(0.38461538461538464)*nu)/297.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = pow(v,4)*((-128*sqrt(0.05128205128205128))/495. + nu*((128*sqrt(0.05128205128205128))/99. - (128*sqrt(0.05128205128205128)*nu)/99.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = pow(v,4)*(54/(5.*sqrt(143)) + nu*(-54/sqrt(143) + (54*nu)/sqrt(143)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==2.
    
    else if(PNAmpOrder==2.5) {
      //cerr << "PNAmpOrder==2.5\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = pow(v,4)*(delta/6. + (delta*log(16))/6.);
          Im = v*(delta/3. + v*(v*((-17*delta)/84. + (5*delta*nu)/21. + v*((M_PI*delta)/3. + v*((-43*delta)/378. + nu*((-509*delta)/378. + (79*delta*nu)/504.)))) + chia/2. + (delta*chis)/2.));
          break;
          
        case 2:
          Re = 1 + pow(v,2)*(-2.5476190476190474 + (55*nu)/42. + v*(2*M_PI - (4*delta*chia)/3. + (-1.3333333333333333 + (4*nu)/3.)*chis + v*(-1.437169312169312 + nu*(-4.949074074074074 + (2047*nu)/1512.) + v*((-107*M_PI)/21. + (34*M_PI*nu)/21.) - 2*nu*pow(chia,2) + 2*nu*pow(chis,2))));
          Im = -24*pow(v,5)*nu;
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = (-2*sqrt(0.8571428571428571)*pow(v,5)*nu)/5.;
          break;
          
        case 1:
          Re = pow(v,4)*((sqrt(3.5)*delta)/60. + (delta*log(1024))/(60.*sqrt(14)));
          Im = v*(delta/(12.*sqrt(14)) + pow(v,2)*(-(sqrt(0.2857142857142857)*delta)/9. - (delta*nu)/(18.*sqrt(14)) + v*((M_PI*delta)/(12.*sqrt(14)) + v*((607*delta)/(2376.*sqrt(14)) + nu*((-17*sqrt(0.2857142857142857)*delta)/297. - (247*delta*nu)/(2376.*sqrt(14)))))));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(0.7142857142857143)/3. - sqrt(0.7142857142857143)*nu + v*(v*(-193/(54.*sqrt(35)) + nu*((145*sqrt(0.7142857142857143))/54. - (73*sqrt(0.7142857142857143)*nu)/54.) + v*((2*sqrt(0.7142857142857143)*M_PI)/3. - 2*sqrt(0.7142857142857143)*M_PI*nu)) + (4*sqrt(0.7142857142857143)*nu*chis)/3.));
          Im = pow(v,5)*(-sqrt(0.7142857142857143) + (22*nu)/sqrt(35));
          break;
          
        case 3:
          Re = pow(v,4)*((-9*sqrt(2.1)*delta)/4. + (9*sqrt(1.0714285714285714)*delta*log(1.5))/2.);
          Im = v*((-3*sqrt(1.0714285714285714)*delta)/4. + pow(v,2)*(3*sqrt(1.0714285714285714)*delta - (3*sqrt(1.0714285714285714)*delta*nu)/2. + v*((-9*sqrt(1.0714285714285714)*M_PI*delta)/4. + v*((-369*sqrt(0.04285714285714286)*delta)/88. + nu*((919*sqrt(0.04285714285714286)*delta)/22. - (887*sqrt(0.04285714285714286)*delta*nu)/88.)))));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*(delta/(84.*sqrt(10)) - (delta*nu)/(42.*sqrt(10)) + pow(v,2)*((-101*delta)/(2772.*sqrt(10)) + nu*((337*delta)/(3696.*sqrt(10)) - (83*delta*nu)/(2772.*sqrt(10)))));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(5)/63. - (sqrt(5)*nu)/21. + pow(v,2)*(-437/(1386.*sqrt(5)) + nu*((115*sqrt(5))/594. - (19*sqrt(5)*nu)/1386.) + v*((2*sqrt(5)*M_PI)/63. - (2*sqrt(5)*M_PI*nu)/21.)));
          Im = pow(v,5)*(-1/(3.*sqrt(5)) + (4*nu)/(3.*sqrt(5)));
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((-9*delta)/(4.*sqrt(70)) + (9*delta*nu)/(2.*sqrt(70)) + pow(v,2)*((351*delta)/(44.*sqrt(70)) + nu*((-543*sqrt(0.7)*delta)/176. + (393*delta*nu)/(44.*sqrt(70)))));
          break;
          
        case 4:
          Re = pow(v,2)*((-8*sqrt(0.7142857142857143))/9. + (8*sqrt(0.7142857142857143)*nu)/3. + pow(v,2)*(2372/(99.*sqrt(35)) + nu*((-5092*sqrt(0.7142857142857143))/297. + (100*sqrt(35)*nu)/99.) + v*((-32*sqrt(0.7142857142857143)*M_PI)/9. + (32*sqrt(0.7142857142857143)*M_PI*nu)/3.)));
          Im = pow(v,5)*((16*sqrt(1.4))/3. - (64*sqrt(0.7142857142857143)*log(2))/9. + nu*(-1193/(9.*sqrt(35)) + (64*sqrt(0.7142857142857143)*log(2))/3.));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*(delta/(288.*sqrt(385)) - (delta*nu)/(144.*sqrt(385)) + pow(v,2)*((-179*delta)/(11232.*sqrt(385)) + nu*((sqrt(0.3142857142857143)*delta)/351. - (delta*nu)/(2808.*sqrt(385)))));
          break;
          
        case 2:
          Re = pow(v,4)*(2/(27.*sqrt(55)) + nu*((-2*sqrt(0.45454545454545453))/27. + (2*sqrt(0.45454545454545453)*nu)/27.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((-9*sqrt(0.02727272727272727)*delta)/32. + (9*sqrt(0.02727272727272727)*delta*nu)/16. + pow(v,2)*((621*sqrt(0.02727272727272727)*delta)/416. + nu*((-87*sqrt(0.02727272727272727)*delta)/26. + (3*sqrt(3.3)*delta*nu)/52.)));
          break;
          
        case 4:
          Re = pow(v,4)*(-32/(9.*sqrt(165)) + nu*((32*sqrt(0.15151515151515152))/9. - (32*sqrt(0.15151515151515152)*nu)/9.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,3)*((625*delta)/(96.*sqrt(66)) - (625*delta*nu)/(48.*sqrt(66)) + pow(v,2)*((-164375*delta)/(3744.*sqrt(66)) + nu*((26875*delta)/(234.*sqrt(66)) - (2500*sqrt(0.06060606060606061)*delta*nu)/117.)));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*(delta/(8316.*sqrt(26)) + nu*(-delta/(2079.*sqrt(26)) + (delta*nu)/(2772.*sqrt(26))));
          break;
          
        case 2:
          Re = pow(v,4)*(2/(297.*sqrt(65)) + nu*((-2*sqrt(0.38461538461538464))/297. + (2*sqrt(0.38461538461538464)*nu)/297.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((-81*delta)/(616.*sqrt(65)) + nu*((81*delta)/(154.*sqrt(65)) - (243*delta*nu)/(616.*sqrt(65))));
          break;
          
        case 4:
          Re = pow(v,4)*((-128*sqrt(0.05128205128205128))/495. + nu*((128*sqrt(0.05128205128205128))/99. - (128*sqrt(0.05128205128205128)*nu)/99.));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((3125*delta)/(504.*sqrt(429)) + nu*((-3125*delta)/(126.*sqrt(429)) + (3125*delta*nu)/(168.*sqrt(429))));
          break;
          
        case 6:
          Re = pow(v,4)*(54/(5.*sqrt(143)) + nu*(-54/sqrt(143) + (54*nu)/sqrt(143)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*(delta/(864864.*sqrt(2)) + nu*(-delta/(216216.*sqrt(2)) + (delta*nu)/(288288.*sqrt(2))));
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((-243*sqrt(1.5)*delta)/160160. + nu*((243*sqrt(1.5)*delta)/40040. - (729*sqrt(1.5)*delta*nu)/160160.));
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((15625*delta)/(26208.*sqrt(66)) + nu*((-15625*delta)/(6552.*sqrt(66)) + (15625*delta*nu)/(8736.*sqrt(66))));
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((-16807*sqrt(0.008158508158508158)*delta)/1440. + nu*((16807*sqrt(0.008158508158508158)*delta)/360. - (16807*sqrt(0.008158508158508158)*delta*nu)/480.));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==2.5
    
    else if(PNAmpOrder==3.) {
      //cerr << "PNAmpOrder==3.\tL=" << L << "\tM=" << M << "\tabs(M)=" << abs(M) << endl;
      if(L==2) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -5/(14.*sqrt(6)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = pow(v,4)*(delta/6. + (delta*log(16))/6. + pow(v,2)*((-17*delta)/168. + nu*((995*delta)/252. + (delta*log(2))/7.) - (17*delta*log(16))/168.));
          Im = v*(delta/3. + v*(v*((-17*delta)/84. + (5*delta*nu)/21. + v*((M_PI*delta)/3. + v*((-43*delta)/378. + nu*((-509*delta)/378. + (79*delta*nu)/504.) + v*((-17*M_PI*delta)/84. + (M_PI*delta*nu)/14.)))) + chia/2. + (delta*chis)/2.));
          break;
          
        case 2:
          Re = 1 + pow(v,2)*(-2.5476190476190474 + (55*nu)/42. + v*(2*M_PI - (4*delta*chia)/3. + (-1.3333333333333333 + (4*nu)/3.)*chis + v*(-1.437169312169312 + nu*(-4.949074074074074 + (2047*nu)/1512.) - 2*nu*pow(chia,2) + 2*nu*pow(chis,2) + v*((-107*M_PI)/21. + (34*M_PI*nu)/21. + v*(41.78634662956092 - (856*EulerGamma)/105. + (2*pow(M_PI,2))/3. + nu*(-8.362944925444925 + (41*pow(M_PI,2))/96. + nu*(-7.309163059163059 + (114635*nu)/99792.)) - (428*log(16))/105. - (856*log(v))/105.)))));
          Im = pow(v,5)*((428*M_PI*v)/105. - 24*nu);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==2
      
      else if(L==3) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = (-2*sqrt(0.8571428571428571)*pow(v,5)*nu)/5.;
          break;
          
        case 1:
          Re = pow(v,4)*((sqrt(3.5)*delta)/60. + (delta*log(1024))/(60.*sqrt(14)) + pow(v,2)*(-(sqrt(14)*delta)/45. + nu*(delta/(180.*sqrt(14)) - (sqrt(3.5)*delta*log(2))/36.) - (sqrt(0.2857142857142857)*delta*log(1024))/45.));
          Im = v*(delta/(12.*sqrt(14)) + pow(v,2)*(-(sqrt(0.2857142857142857)*delta)/9. - (delta*nu)/(18.*sqrt(14)) + v*((M_PI*delta)/(12.*sqrt(14)) + v*((607*delta)/(2376.*sqrt(14)) + nu*((-17*sqrt(0.2857142857142857)*delta)/297. - (247*delta*nu)/(2376.*sqrt(14))) + v*(-(sqrt(0.2857142857142857)*M_PI*delta)/9. - (sqrt(3.5)*M_PI*delta*nu)/72.)))));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(0.7142857142857143)/3. - sqrt(0.7142857142857143)*nu + v*(v*(-193/(54.*sqrt(35)) + nu*((145*sqrt(0.7142857142857143))/54. - (73*sqrt(0.7142857142857143)*nu)/54.) + v*((2*sqrt(0.7142857142857143)*M_PI)/3. - 2*sqrt(0.7142857142857143)*M_PI*nu + v*(-1451/(2376.*sqrt(35)) + nu*(-17387/(2376.*sqrt(35)) + nu*(5557/(132.*sqrt(35)) - (763*sqrt(1.4)*nu)/792.))))) + (4*sqrt(0.7142857142857143)*nu*chis)/3.));
          Im = pow(v,5)*(-sqrt(0.7142857142857143) + (22*nu)/sqrt(35));
          break;
          
        case 3:
          Re = pow(v,4)*((-9*sqrt(2.1)*delta)/4. + (9*sqrt(1.0714285714285714)*delta*log(1.5))/2. + pow(v,2)*(9*sqrt(2.1)*delta - 9*sqrt(4.285714285714286)*delta*log(1.5) + nu*((-48103*delta)/(108.*sqrt(210)) + (27*sqrt(1.0714285714285714)*delta*log(1.5))/4.)));
          Im = v*((-3*sqrt(1.0714285714285714)*delta)/4. + pow(v,2)*(3*sqrt(1.0714285714285714)*delta - (3*sqrt(1.0714285714285714)*delta*nu)/2. + v*((-9*sqrt(1.0714285714285714)*M_PI*delta)/4. + v*((-369*sqrt(0.04285714285714286)*delta)/88. + nu*((919*sqrt(0.04285714285714286)*delta)/22. - (887*sqrt(0.04285714285714286)*delta*nu)/88.) + v*(9*sqrt(1.0714285714285714)*M_PI*delta - (27*sqrt(1.0714285714285714)*M_PI*delta*nu)/8.)))));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==3
      
      else if(L==4) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), -1/(504.*sqrt(2)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = pow(v,6)*((4*sqrt(0.4)*delta)/315. + (delta*log(2))/(42.*sqrt(10)) + nu*((-1661*delta)/(2520.*sqrt(10)) - (delta*log(2))/(21.*sqrt(10))));
          Im = pow(v,3)*(delta/(84.*sqrt(10)) - (delta*nu)/(42.*sqrt(10)) + pow(v,2)*((-101*delta)/(2772.*sqrt(10)) + nu*((337*delta)/(3696.*sqrt(10)) - (83*delta*nu)/(2772.*sqrt(10))) + v*((M_PI*delta)/(84.*sqrt(10)) - (M_PI*delta*nu)/(42.*sqrt(10)))));
          break;
          
        case 2:
          Re = pow(v,2)*(sqrt(5)/63. - (sqrt(5)*nu)/21. + pow(v,2)*(-437/(1386.*sqrt(5)) + nu*((115*sqrt(5))/594. - (19*sqrt(5)*nu)/1386.) + v*((2*sqrt(5)*M_PI)/63. - (2*sqrt(5)*M_PI*nu)/21. + v*(346013/(840840.*sqrt(5)) + nu*(-606751/(360360.*sqrt(5)) + nu*(400453/(324324.*sqrt(5)) + (25783*nu)/(216216.*sqrt(5))))))));
          Im = pow(v,5)*(-1/(3.*sqrt(5)) + (4*nu)/(3.*sqrt(5)));
          break;
          
        case 3:
          Re = pow(v,6)*((-36*sqrt(0.05714285714285714)*delta)/5. + (27*delta*log(1.5))/(2.*sqrt(70)) + nu*((16301*delta)/(360.*sqrt(70)) - (27*delta*log(1.5))/sqrt(70)));
          Im = pow(v,3)*((-9*delta)/(4.*sqrt(70)) + (9*delta*nu)/(2.*sqrt(70)) + pow(v,2)*((351*delta)/(44.*sqrt(70)) + nu*((-543*sqrt(0.7)*delta)/176. + (393*delta*nu)/(44.*sqrt(70))) + v*((-27*M_PI*delta)/(4.*sqrt(70)) + (27*M_PI*delta*nu)/(2.*sqrt(70)))));
          break;
          
        case 4:
          Re = pow(v,2)*((-8*sqrt(0.7142857142857143))/9. + (8*sqrt(0.7142857142857143)*nu)/3. + pow(v,2)*(2372/(99.*sqrt(35)) + nu*((-5092*sqrt(0.7142857142857143))/297. + (100*sqrt(35)*nu)/99.) + v*((-32*sqrt(0.7142857142857143)*M_PI)/9. + (32*sqrt(0.7142857142857143)*M_PI*nu)/3. + v*(-1068671/(45045.*sqrt(35)) + nu*(1088119/(6435.*sqrt(35)) + nu*(-293758/(1053.*sqrt(35)) + (226097*nu)/(3861.*sqrt(35))))))));
          Im = pow(v,5)*((16*sqrt(1.4))/3. - (64*sqrt(0.7142857142857143)*log(2))/9. + nu*(-1193/(9.*sqrt(35)) + (64*sqrt(0.7142857142857143)*log(2))/3.));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==4
      
      else if(L==5) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = pow(v,6)*((181*delta)/(20160.*sqrt(385)) + (delta*log(2))/(144.*sqrt(385)) + nu*((-313*delta)/(720.*sqrt(385)) - (delta*log(1024))/(720.*sqrt(385))));
          Im = pow(v,3)*(delta/(288.*sqrt(385)) - (delta*nu)/(144.*sqrt(385)) + pow(v,2)*((-179*delta)/(11232.*sqrt(385)) + nu*((sqrt(0.3142857142857143)*delta)/351. - (delta*nu)/(2808.*sqrt(385))) + v*((M_PI*delta)/(288.*sqrt(385)) - (M_PI*delta*nu)/(144.*sqrt(385)))));
          break;
          
        case 2:
          Re = pow(v,4)*(2/(27.*sqrt(55)) + nu*((-2*sqrt(0.45454545454545453))/27. + (2*sqrt(0.45454545454545453)*nu)/27.) + pow(v,2)*(-3911/(12285.*sqrt(55)) + nu*(3079/(1755.*sqrt(55)) + nu*(-826/(351.*sqrt(55)) + (7*sqrt(2.2)*nu)/117.))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = pow(v,6)*((-4887*sqrt(0.02727272727272727)*delta)/2240. + (27*sqrt(0.02727272727272727)*delta*log(1.5))/16. + nu*((41851*delta)/(2160.*sqrt(330)) - (27*sqrt(0.02727272727272727)*delta*log(1.5))/8.));
          Im = pow(v,3)*((-9*sqrt(0.02727272727272727)*delta)/32. + (9*sqrt(0.02727272727272727)*delta*nu)/16. + pow(v,2)*((621*sqrt(0.02727272727272727)*delta)/416. + nu*((-87*sqrt(0.02727272727272727)*delta)/26. + (3*sqrt(3.3)*delta*nu)/52.) + v*((-27*sqrt(0.02727272727272727)*M_PI*delta)/32. + (27*sqrt(0.02727272727272727)*M_PI*delta*nu)/16.)));
          break;
          
        case 4:
          Re = pow(v,4)*(-32/(9.*sqrt(165)) + nu*((32*sqrt(0.15151515151515152))/9. - (32*sqrt(0.15151515151515152)*nu)/9.) + pow(v,2)*(71216/(4095.*sqrt(165)) + nu*((-5264*sqrt(0.7333333333333333))/585. + nu*(16672/(117.*sqrt(165)) - (1808*nu)/(39.*sqrt(165))))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = pow(v,6)*((113125*delta)/(1344.*sqrt(66)) - (3125*delta*log(2.5))/(48.*sqrt(66)) + nu*((-17639*delta)/(80.*sqrt(66)) + (3125*delta*log(2.5))/(24.*sqrt(66))));
          Im = pow(v,3)*((625*delta)/(96.*sqrt(66)) - (625*delta*nu)/(48.*sqrt(66)) + pow(v,2)*((-164375*delta)/(3744.*sqrt(66)) + nu*((26875*delta)/(234.*sqrt(66)) - (2500*sqrt(0.06060606060606061)*delta*nu)/117.) + v*((3125*M_PI*delta)/(96.*sqrt(66)) - (3125*M_PI*delta*nu)/(48.*sqrt(66)))));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==5
      
      else if(L==6) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*(delta/(8316.*sqrt(26)) + nu*(-delta/(2079.*sqrt(26)) + (delta*nu)/(2772.*sqrt(26))));
          break;
          
        case 2:
          Re = pow(v,4)*(2/(297.*sqrt(65)) + nu*((-2*sqrt(0.38461538461538464))/297. + (2*sqrt(0.38461538461538464)*nu)/297.) + pow(v,2)*(-3/(77.*sqrt(65)) + nu*(59/(297.*sqrt(65)) + nu*(-64/(297.*sqrt(65)) + (7*nu)/(297.*sqrt(65))))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((-81*delta)/(616.*sqrt(65)) + nu*((81*delta)/(154.*sqrt(65)) - (243*delta*nu)/(616.*sqrt(65))));
          break;
          
        case 4:
          Re = pow(v,4)*((-128*sqrt(0.05128205128205128))/495. + nu*((128*sqrt(0.05128205128205128))/99. - (128*sqrt(0.05128205128205128)*nu)/99.) + pow(v,2)*((1984*sqrt(0.05128205128205128))/1155. + nu*((-4544*sqrt(0.05128205128205128))/495. + nu*((512*sqrt(0.05128205128205128))/45. - (1216*sqrt(0.05128205128205128)*nu)/495.))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((3125*delta)/(504.*sqrt(429)) + nu*((-3125*delta)/(126.*sqrt(429)) + (3125*delta*nu)/(168.*sqrt(429))));
          break;
          
        case 6:
          Re = pow(v,4)*(54/(5.*sqrt(143)) + nu*(-54/sqrt(143) + (54*nu)/sqrt(143)) + pow(v,2)*(-3051/(35.*sqrt(143)) + nu*((189*sqrt(1.1818181818181819))/5. + nu*(-3456/(5.*sqrt(143)) + (81*sqrt(1.1818181818181819)*nu)/5.))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==6
      
      else if(L==7) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*(delta/(864864.*sqrt(2)) + nu*(-delta/(216216.*sqrt(2)) + (delta*nu)/(288288.*sqrt(2))));
          break;
          
        case 2:
          Re = pow(v,6)*(1/(3003.*sqrt(3)) + nu*(-1/(429.*sqrt(3)) + nu*(2/(429.*sqrt(3)) - nu/(429.*sqrt(3)))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((-243*sqrt(1.5)*delta)/160160. + nu*((243*sqrt(1.5)*delta)/40040. - (729*sqrt(1.5)*delta*nu)/160160.));
          break;
          
        case 4:
          Re = pow(v,6)*((-128*sqrt(0.06060606060606061))/1365. + nu*((128*sqrt(0.06060606060606061))/195. + nu*((-256*sqrt(0.06060606060606061))/195. + (128*sqrt(0.06060606060606061)*nu)/195.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((15625*delta)/(26208.*sqrt(66)) + nu*((-15625*delta)/(6552.*sqrt(66)) + (15625*delta*nu)/(8736.*sqrt(66))));
          break;
          
        case 6:
          Re = pow(v,6)*((81*sqrt(0.02097902097902098))/35. + nu*((-81*sqrt(0.02097902097902098))/5. + nu*((162*sqrt(0.02097902097902098))/5. - (81*sqrt(0.02097902097902098)*nu)/5.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = pow(v,5)*((-16807*sqrt(0.008158508158508158)*delta)/1440. + nu*((16807*sqrt(0.008158508158508158)*delta)/360. - (16807*sqrt(0.008158508158508158)*delta*nu)/480.));
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==7
      
      else if(L==8) {
        switch(abs(M)) {
        case 0:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 1:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 2:
          Re = pow(v,6)*(1/(9009.*sqrt(85)) + nu*(-1/(1287.*sqrt(85)) + nu*(2/(1287.*sqrt(85)) - nu/(1287.*sqrt(85)))));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 3:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 4:
          Re = pow(v,6)*((-128*sqrt(0.0106951871657754))/4095. + nu*((128*sqrt(0.0106951871657754))/585. + nu*((-256*sqrt(0.0106951871657754))/585. + (128*sqrt(0.0106951871657754)*nu)/585.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 5:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 6:
          Re = pow(v,6)*((243*sqrt(0.00017629429394135277))/35. + nu*((-243*sqrt(0.00017629429394135277))/5. + nu*((486*sqrt(0.00017629429394135277))/5. - (243*sqrt(0.00017629429394135277)*nu)/5.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 7:
          Re = vector<double>(Phi.size(), 0);
          Im = vector<double>(Phi.size(), 0);
          break;
          
        case 8:
          Re = pow(v,6)*((-16384*sqrt(0.000023505905858847036))/63. + nu*((16384*sqrt(0.000023505905858847036))/9. + nu*((-32768*sqrt(0.000023505905858847036))/9. + (16384*sqrt(0.000023505905858847036)*nu)/9.)));
          Im = vector<double>(Phi.size(), 0);
          break;
          
        default:
          cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
          throw(1);
        } // switch(abs(M))
      } // L==8
      
    } // PNAmpOrder==3.
    
    else {
      cerr << PNAmpOrder << " didn't stop anywhere!!!" << endl;
      exit(1);
    }
  }
  
  AmpPhi(Re, Im, amp, phi); // void AmpPhi(const vector<double>& Re, const vector<double>& Im, vector<double>& amp, vector<double>& phi);
  amp = (6.3413236761696176*nu)*pow(v,2)*amp;
  if(M<0) {
    if(L%2) { phi = M_PI - phi - M*Phi; }
    else { phi = 0. - phi - M*Phi; }
  } else {
    phi = phi - M*Phi;
  }
  
  return;
}
