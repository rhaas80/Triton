#include "SWSHs.hpp"
#include <cstdlib>
#include <cmath>

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}


void SWSH(const int L, const int M, const double& vartheta, const double& varphi, double& Amp, double& Phi) {
  if(L<2) { throw("l<2 unsupported."); }
  if(labs(M)>L) { throw("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(L>12) { throw("l>12 unsupported."); }
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      Amp = (sqrt(5.0/M_PI)*pow(sin(vartheta/2.0),4))/2.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = sqrt(5.0/M_PI)*cos(vartheta/2.0)*pow(sin(vartheta/2.0),3);
      Phi = -varphi;
      break;
    case 0:
      Amp = (sqrt(15.0/(2.0*M_PI))*pow(sin(vartheta),2))/4.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = sqrt(5.0/M_PI)*pow(cos(vartheta/2.0),3)*sin(vartheta/2.0);
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(5.0/M_PI)*pow(cos(vartheta/2.0),4))/2.0;
      Phi = 2.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 3:
    switch(M) {
    case -3:
      Amp = sqrt(21.0/(2.0*M_PI))*cos(vartheta/2.0)*pow(sin(vartheta/2.0),5);
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(7.0/M_PI)*(2.0 + 3.0*cos(vartheta))*pow(sin(vartheta/2.0),4))/2.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (sqrt(35.0/(2.0*M_PI))*cos(vartheta/2.0)*(1.0 + 3.0*cos(vartheta))*pow(sin(vartheta/2.0),3))/2.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (sqrt(105.0/(2.0*M_PI))*cos(vartheta)*pow(sin(vartheta),2))/4.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (sqrt(35.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(-1.0 + 3.0*cos(vartheta))*sin(vartheta/2.0))/2.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(7.0/M_PI)*pow(cos(vartheta/2.0),4)*(-2.0 + 3.0*cos(vartheta)))/2.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -(sqrt(21.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*sin(vartheta/2.0));
      Phi = 3.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 4:
    switch(M) {
    case -4:
      Amp = 3.0*sqrt(7.0/M_PI)*pow(cos(vartheta/2.0),2)*pow(sin(vartheta/2.0),6);
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = 3.0*sqrt(7.0/(2.0*M_PI))*cos(vartheta/2.0)*(1.0 + 2.0*cos(vartheta))*pow(sin(vartheta/2.0),5);
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (3.0*(9.0 + 14.0*cos(vartheta) + 7.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),4))/(4.0*sqrt(M_PI));
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (3.0*cos(vartheta/2.0)*(6.0 + 7.0*cos(vartheta) + 7.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),3))/(2.0*sqrt(2.0*M_PI));
      Phi = -varphi;
      break;
    case 0:
      Amp = (3.0*sqrt(5.0/(2.0*M_PI))*(5.0 + 7.0*cos(2.0*vartheta))*pow(sin(vartheta),2))/16.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (3.0*pow(cos(vartheta/2.0),3)*(6.0 - 7.0*cos(vartheta) + 7.0*cos(2.0*vartheta))*sin(vartheta/2.0))/(2.0*sqrt(2.0*M_PI));
      Phi = varphi;
      break;
    case 2:
      Amp = (3.0*pow(cos(vartheta/2.0),4)*(9.0 - 14.0*cos(vartheta) + 7.0*cos(2.0*vartheta)))/(4.0*sqrt(M_PI));
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -3.0*sqrt(7.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(-1.0 + 2.0*cos(vartheta))*sin(vartheta/2.0);
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = 3.0*sqrt(7.0/M_PI)*pow(cos(vartheta/2.0),6)*pow(sin(vartheta/2.0),2);
      Phi = 4.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 5:
    switch(M) {
    case -5:
      Amp = sqrt(330.0/M_PI)*pow(cos(vartheta/2.0),3)*pow(sin(vartheta/2.0),7);
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = sqrt(33.0/M_PI)*pow(cos(vartheta/2.0),2)*(2.0 + 5.0*cos(vartheta))*pow(sin(vartheta/2.0),6);
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (sqrt(33.0/(2.0*M_PI))*cos(vartheta/2.0)*(17.0 + 24.0*cos(vartheta) + 15.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),5))/4.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(11.0/M_PI)*(32.0 + 57.0*cos(vartheta) + 36.0*cos(2.0*vartheta) + 15.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),4))/8.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (sqrt(77.0/M_PI)*cos(vartheta/2.0)*(14.0 + 33.0*cos(vartheta) + 18.0*cos(2.0*vartheta) + 15.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),3))/16.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (sqrt(1155.0/(2.0*M_PI))*cos(vartheta)*(1.0 + 3.0*cos(2.0*vartheta))*pow(sin(vartheta),2))/16.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (sqrt(77.0/M_PI)*pow(cos(vartheta/2.0),3)*(-14.0 + 33.0*cos(vartheta) - 18.0*cos(2.0*vartheta) + 15.0*cos(3.0*vartheta))*sin(vartheta/2.0))/16.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(11.0/M_PI)*pow(cos(vartheta/2.0),4)*(-32.0 + 57.0*cos(vartheta) - 36.0*cos(2.0*vartheta) + 15.0*cos(3.0*vartheta)))/8.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -(sqrt(33.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(17.0 - 24.0*cos(vartheta) + 15.0*cos(2.0*vartheta))*sin(vartheta/2.0))/4.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = sqrt(33.0/M_PI)*pow(cos(vartheta/2.0),6)*(-2.0 + 5.0*cos(vartheta))*pow(sin(vartheta/2.0),2);
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(330.0/M_PI)*pow(cos(vartheta/2.0),7)*pow(sin(vartheta/2.0),3));
      Phi = 5.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 6:
    switch(M) {
    case -6:
      Amp = (3.0*sqrt(715.0/M_PI)*pow(cos(vartheta/2.0),4)*pow(sin(vartheta/2.0),8))/2.0;
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (sqrt(2145.0/M_PI)*pow(cos(vartheta/2.0),3)*(1.0 + 3.0*cos(vartheta))*pow(sin(vartheta/2.0),7))/2.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (sqrt(195.0/(2.0*M_PI))*pow(cos(vartheta/2.0),2)*(35.0 + 44.0*cos(vartheta) + 33.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),6))/8.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (3.0*sqrt(13.0/M_PI)*cos(vartheta/2.0)*(98.0 + 185.0*cos(vartheta) + 110.0*cos(2.0*vartheta) + 55.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),5))/32.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(13.0/M_PI)*(1709.0 + 3096.0*cos(vartheta) + 2340.0*cos(2.0*vartheta) + 1320.0*cos(3.0*vartheta) + 495.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),4))/256.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (sqrt(65.0/(2.0*M_PI))*cos(vartheta/2.0)*(161.0 + 252.0*cos(vartheta) + 252.0*cos(2.0*vartheta) + 132.0*cos(3.0*vartheta) + 99.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),3))/64.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (sqrt(1365.0/M_PI)*(35.0 + 60.0*cos(2.0*vartheta) + 33.0*cos(4.0*vartheta))*pow(sin(vartheta),2))/512.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (sqrt(65.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(161.0 - 252.0*cos(vartheta) + 252.0*cos(2.0*vartheta) - 132.0*cos(3.0*vartheta) + 99.0*cos(4.0*vartheta))*sin(vartheta/2.0))/64.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(13.0/M_PI)*pow(cos(vartheta/2.0),4)*(1709.0 - 3096.0*cos(vartheta) + 2340.0*cos(2.0*vartheta) - 1320.0*cos(3.0*vartheta) + 495.0*cos(4.0*vartheta)))/256.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = (-3.0*sqrt(13.0/M_PI)*pow(cos(vartheta/2.0),5)*(-98.0 + 185.0*cos(vartheta) - 110.0*cos(2.0*vartheta) + 55.0*cos(3.0*vartheta))*sin(vartheta/2.0))/32.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (sqrt(195.0/(2.0*M_PI))*pow(cos(vartheta/2.0),6)*(35.0 - 44.0*cos(vartheta) + 33.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),2))/8.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(2145.0/M_PI)*pow(cos(vartheta/2.0),7)*(-1.0 + 3.0*cos(vartheta))*pow(sin(vartheta/2.0),3))/2.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = (3.0*sqrt(715.0/M_PI)*pow(cos(vartheta/2.0),8)*pow(sin(vartheta/2.0),4))/2.0;
      Phi = 6.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 7:
    switch(M) {
    case -7:
      Amp = sqrt(15015.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*pow(sin(vartheta/2.0),9);
      Phi = -7.0*varphi;
      break;
    case -6:
      Amp = (sqrt(2145.0/M_PI)*pow(cos(vartheta/2.0),4)*(2.0 + 7.0*cos(vartheta))*pow(sin(vartheta/2.0),8))/2.0;
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (sqrt(165.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(93.0 + 104.0*cos(vartheta) + 91.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),7))/8.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (sqrt(165.0/(2.0*M_PI))*pow(cos(vartheta/2.0),2)*(140.0 + 285.0*cos(vartheta) + 156.0*cos(2.0*vartheta) + 91.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),6))/16.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (sqrt(15.0/(2.0*M_PI))*cos(vartheta/2.0)*(3115.0 + 5456.0*cos(vartheta) + 4268.0*cos(2.0*vartheta) + 2288.0*cos(3.0*vartheta) + 1001.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),5))/128.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(15.0/M_PI)*(5220.0 + 9810.0*cos(vartheta) + 7920.0*cos(2.0*vartheta) + 5445.0*cos(3.0*vartheta) + 2860.0*cos(4.0*vartheta) + 1001.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),4))/512.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (3.0*sqrt(5.0/(2.0*M_PI))*cos(vartheta/2.0)*(1890.0 + 4130.0*cos(vartheta) + 3080.0*cos(2.0*vartheta) + 2805.0*cos(3.0*vartheta) + 1430.0*cos(4.0*vartheta) + 1001.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),3))/512.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (3.0*sqrt(35.0/M_PI)*cos(vartheta)*(109.0 + 132.0*cos(2.0*vartheta) + 143.0*cos(4.0*vartheta))*pow(sin(vartheta),2))/512.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (3.0*sqrt(5.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(-1890.0 + 4130.0*cos(vartheta) - 3080.0*cos(2.0*vartheta) + 2805.0*cos(3.0*vartheta) - 1430.0*cos(4.0*vartheta) + 1001.0*cos(5.0*vartheta))*sin(vartheta/2.0))/512.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(15.0/M_PI)*pow(cos(vartheta/2.0),4)*(-5220.0 + 9810.0*cos(vartheta) - 7920.0*cos(2.0*vartheta) + 5445.0*cos(3.0*vartheta) - 2860.0*cos(4.0*vartheta) + 1001.0*cos(5.0*vartheta)))/512.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -(sqrt(15.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(3115.0 - 5456.0*cos(vartheta) + 4268.0*cos(2.0*vartheta) - 2288.0*cos(3.0*vartheta) + 1001.0*cos(4.0*vartheta))*sin(vartheta/2.0))/128.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (sqrt(165.0/(2.0*M_PI))*pow(cos(vartheta/2.0),6)*(-140.0 + 285.0*cos(vartheta) - 156.0*cos(2.0*vartheta) + 91.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),2))/16.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(165.0/(2.0*M_PI))*pow(cos(vartheta/2.0),7)*(93.0 - 104.0*cos(vartheta) + 91.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),3))/8.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = (sqrt(2145.0/M_PI)*pow(cos(vartheta/2.0),8)*(-2.0 + 7.0*cos(vartheta))*pow(sin(vartheta/2.0),4))/2.0;
      Phi = 6.0*varphi;
      break;
    case 7:
      Amp = -(sqrt(15015.0/(2.0*M_PI))*pow(cos(vartheta/2.0),9)*pow(sin(vartheta/2.0),5));
      Phi = 7.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 8:
    switch(M) {
    case -8:
      Amp = sqrt(34034.0/M_PI)*pow(cos(vartheta/2.0),6)*pow(sin(vartheta/2.0),10);
      Phi = -8.0*varphi;
      break;
    case -7:
      Amp = sqrt(17017.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(1.0 + 4.0*cos(vartheta))*pow(sin(vartheta/2.0),9);
      Phi = -7.0*varphi;
      break;
    case -6:
      Amp = sqrt(255255.0/M_PI)*pow(cos(vartheta/2.0),4)*(1.0 + 2.0*cos(vartheta))*sin(M_PI/4.0 - vartheta/2.0)*sin(M_PI/4.0 + vartheta/2.0)*pow(sin(vartheta/2.0),8);
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (sqrt(12155.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(19.0 + 42.0*cos(vartheta) + 21.0*cos(2.0*vartheta) + 14.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),7))/8.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (sqrt(935.0/(2.0*M_PI))*pow(cos(vartheta/2.0),2)*(265.0 + 442.0*cos(vartheta) + 364.0*cos(2.0*vartheta) + 182.0*cos(3.0*vartheta) + 91.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),6))/32.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (sqrt(561.0/(2.0*M_PI))*cos(vartheta/2.0)*(869.0 + 1660.0*cos(vartheta) + 1300.0*cos(2.0*vartheta) + 910.0*cos(3.0*vartheta) + 455.0*cos(4.0*vartheta) + 182.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),5))/128.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(17.0/M_PI)*(7626.0 + 14454.0*cos(vartheta) + 12375.0*cos(2.0*vartheta) + 9295.0*cos(3.0*vartheta) + 6006.0*cos(4.0*vartheta) + 3003.0*cos(5.0*vartheta) + 1001.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),4))/512.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (sqrt(595.0/(2.0*M_PI))*cos(vartheta/2.0)*(798.0 + 1386.0*cos(vartheta) + 1386.0*cos(2.0*vartheta) + 1001.0*cos(3.0*vartheta) + 858.0*cos(4.0*vartheta) + 429.0*cos(5.0*vartheta) + 286.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),3))/512.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (3.0*sqrt(595.0/M_PI)*(210.0 + 385.0*cos(2.0*vartheta) + 286.0*cos(4.0*vartheta) + 143.0*cos(6.0*vartheta))*pow(sin(vartheta),2))/4096.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (sqrt(595.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(798.0 - 1386.0*cos(vartheta) + 1386.0*cos(2.0*vartheta) - 1001.0*cos(3.0*vartheta) + 858.0*cos(4.0*vartheta) - 429.0*cos(5.0*vartheta) + 286.0*cos(6.0*vartheta))*sin(vartheta/2.0))/512.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(17.0/M_PI)*pow(cos(vartheta/2.0),4)*(7626.0 - 14454.0*cos(vartheta) + 12375.0*cos(2.0*vartheta) - 9295.0*cos(3.0*vartheta) + 6006.0*cos(4.0*vartheta) - 3003.0*cos(5.0*vartheta) + 1001.0*cos(6.0*vartheta)))/512.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -(sqrt(561.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(-869.0 + 1660.0*cos(vartheta) - 1300.0*cos(2.0*vartheta) + 910.0*cos(3.0*vartheta) - 455.0*cos(4.0*vartheta) + 182.0*cos(5.0*vartheta))*sin(vartheta/2.0))/128.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (sqrt(935.0/(2.0*M_PI))*pow(cos(vartheta/2.0),6)*(265.0 - 442.0*cos(vartheta) + 364.0*cos(2.0*vartheta) - 182.0*cos(3.0*vartheta) + 91.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),2))/32.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(12155.0/(2.0*M_PI))*pow(cos(vartheta/2.0),7)*(-19.0 + 42.0*cos(vartheta) - 21.0*cos(2.0*vartheta) + 14.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),3))/8.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = sqrt(255255.0/M_PI)*pow(cos(vartheta/2.0),8)*(-1.0 + 2.0*cos(vartheta))*sin(M_PI/4.0 - vartheta/2.0)*sin(M_PI/4.0 + vartheta/2.0)*pow(sin(vartheta/2.0),4);
      Phi = 6.0*varphi;
      break;
    case 7:
      Amp = -(sqrt(17017.0/(2.0*M_PI))*pow(cos(vartheta/2.0),9)*(-1.0 + 4.0*cos(vartheta))*pow(sin(vartheta/2.0),5));
      Phi = 7.0*varphi;
      break;
    case 8:
      Amp = sqrt(34034.0/M_PI)*pow(cos(vartheta/2.0),10)*pow(sin(vartheta/2.0),6);
      Phi = 8.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 9:
    switch(M) {
    case -9:
      Amp = 6.0*sqrt(4199.0/M_PI)*pow(cos(vartheta/2.0),7)*pow(sin(vartheta/2.0),11);
      Phi = -9.0*varphi;
      break;
    case -8:
      Amp = sqrt(8398.0/M_PI)*pow(cos(vartheta/2.0),6)*(2.0 + 9.0*cos(vartheta))*pow(sin(vartheta/2.0),10);
      Phi = -8.0*varphi;
      break;
    case -7:
      Amp = (sqrt(247.0/M_PI)*pow(cos(vartheta/2.0),5)*(151.0 + 136.0*cos(vartheta) + 153.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),9))/4.0;
      Phi = -7.0*varphi;
      break;
    case -6:
      Amp = (sqrt(741.0/M_PI)*pow(cos(vartheta/2.0),4)*(62.0 + 149.0*cos(vartheta) + 68.0*cos(2.0*vartheta) + 51.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),8))/4.0;
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (sqrt(1235.0/M_PI)*pow(cos(vartheta/2.0),3)*(427.0 + 672.0*cos(vartheta) + 588.0*cos(2.0*vartheta) + 272.0*cos(3.0*vartheta) + 153.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),7))/32.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (sqrt(1729.0/(2.0*M_PI))*pow(cos(vartheta/2.0),2)*(676.0 + 1330.0*cos(vartheta) + 1000.0*cos(2.0*vartheta) + 725.0*cos(3.0*vartheta) + 340.0*cos(4.0*vartheta) + 153.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),6))/64.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (sqrt(399.0/M_PI)*cos(vartheta/2.0)*(4906.0 + 9152.0*cos(vartheta) + 7865.0*cos(2.0*vartheta) + 5720.0*cos(3.0*vartheta) + 3718.0*cos(4.0*vartheta) + 1768.0*cos(5.0*vartheta) + 663.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),5))/512.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(19.0/M_PI)*(21252.0 + 40887.0*cos(vartheta) + 36036.0*cos(2.0*vartheta) + 29029.0*cos(3.0*vartheta) + 20748.0*cos(4.0*vartheta) + 12831.0*cos(5.0*vartheta) + 6188.0*cos(6.0*vartheta) + 1989.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),4))/1024.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (sqrt(209.0/(2.0*M_PI))*cos(vartheta/2.0)*(6468.0 + 13671.0*cos(vartheta) + 11466.0*cos(2.0*vartheta) + 10829.0*cos(3.0*vartheta) + 7644.0*cos(4.0*vartheta) + 6279.0*cos(5.0*vartheta) + 3094.0*cos(6.0*vartheta) + 1989.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),3))/2048.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (3.0*sqrt(1045.0/M_PI)*cos(vartheta)*(166.0 + 403.0*cos(2.0*vartheta) + 234.0*cos(4.0*vartheta) + 221.0*cos(6.0*vartheta))*pow(sin(vartheta),2))/4096.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (sqrt(209.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(-6468.0 + 13671.0*cos(vartheta) - 11466.0*cos(2.0*vartheta) + 10829.0*cos(3.0*vartheta) - 7644.0*cos(4.0*vartheta) + 6279.0*cos(5.0*vartheta) - 3094.0*cos(6.0*vartheta) + 1989.0*cos(7.0*vartheta))*sin(vartheta/2.0))/2048.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(19.0/M_PI)*pow(cos(vartheta/2.0),4)*(-21252.0 + 40887.0*cos(vartheta) - 36036.0*cos(2.0*vartheta) + 29029.0*cos(3.0*vartheta) - 20748.0*cos(4.0*vartheta) + 12831.0*cos(5.0*vartheta) - 6188.0*cos(6.0*vartheta) + 1989.0*cos(7.0*vartheta)))/1024.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -(sqrt(399.0/M_PI)*pow(cos(vartheta/2.0),5)*(4906.0 - 9152.0*cos(vartheta) + 7865.0*cos(2.0*vartheta) - 5720.0*cos(3.0*vartheta) + 3718.0*cos(4.0*vartheta) - 1768.0*cos(5.0*vartheta) + 663.0*cos(6.0*vartheta))*sin(vartheta/2.0))/512.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (sqrt(1729.0/(2.0*M_PI))*pow(cos(vartheta/2.0),6)*(-676.0 + 1330.0*cos(vartheta) - 1000.0*cos(2.0*vartheta) + 725.0*cos(3.0*vartheta) - 340.0*cos(4.0*vartheta) + 153.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),2))/64.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(1235.0/M_PI)*pow(cos(vartheta/2.0),7)*(427.0 - 672.0*cos(vartheta) + 588.0*cos(2.0*vartheta) - 272.0*cos(3.0*vartheta) + 153.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),3))/32.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = (sqrt(741.0/M_PI)*pow(cos(vartheta/2.0),8)*(-62.0 + 149.0*cos(vartheta) - 68.0*cos(2.0*vartheta) + 51.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),4))/4.0;
      Phi = 6.0*varphi;
      break;
    case 7:
      Amp = -(sqrt(247.0/M_PI)*pow(cos(vartheta/2.0),9)*(151.0 - 136.0*cos(vartheta) + 153.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),5))/4.0;
      Phi = 7.0*varphi;
      break;
    case 8:
      Amp = sqrt(8398.0/M_PI)*pow(cos(vartheta/2.0),10)*(-2.0 + 9.0*cos(vartheta))*pow(sin(vartheta/2.0),6);
      Phi = 8.0*varphi;
      break;
    case 9:
      Amp = -6.0*sqrt(4199.0/M_PI)*pow(cos(vartheta/2.0),11)*pow(sin(vartheta/2.0),7);
      Phi = 9.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 10:
    switch(M) {
    case -10:
      Amp = 3.0*sqrt(146965.0/(2.0*M_PI))*pow(cos(vartheta/2.0),8)*pow(sin(vartheta/2.0),12);
      Phi = -10.0*varphi;
      break;
    case -9:
      Amp = 3.0*sqrt(29393.0/(2.0*M_PI))*pow(cos(vartheta/2.0),7)*(1.0 + 5.0*cos(vartheta))*pow(sin(vartheta/2.0),11);
      Phi = -9.0*varphi;
      break;
    case -8:
      Amp = (3.0*sqrt(1547.0/M_PI)*pow(cos(vartheta/2.0),6)*(93.0 + 76.0*cos(vartheta) + 95.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),10))/8.0;
      Phi = -8.0*varphi;
      break;
    case -7:
      Amp = (sqrt(4641.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(314.0 + 819.0*cos(vartheta) + 342.0*cos(2.0*vartheta) + 285.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),9))/16.0;
      Phi = -7.0*varphi;
      break;
    case -6:
      Amp = (sqrt(273.0/(2.0*M_PI))*pow(cos(vartheta/2.0),4)*(13159.0 + 19448.0*cos(vartheta) + 18156.0*cos(2.0*vartheta) + 7752.0*cos(3.0*vartheta) + 4845.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),8))/128.0;
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (sqrt(1365.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(3990.0 + 8162.0*cos(vartheta) + 5848.0*cos(2.0*vartheta) + 4437.0*cos(3.0*vartheta) + 1938.0*cos(4.0*vartheta) + 969.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),7))/128.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (sqrt(273.0/M_PI)*pow(cos(vartheta/2.0),2)*(35126.0 + 63960.0*cos(vartheta) + 55875.0*cos(2.0*vartheta) + 39100.0*cos(3.0*vartheta) + 26010.0*cos(4.0*vartheta) + 11628.0*cos(5.0*vartheta) + 4845.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),6))/1024.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (sqrt(273.0/(2.0*M_PI))*cos(vartheta/2.0)*(52052.0 + 100639.0*cos(vartheta) + 87010.0*cos(2.0*vartheta) + 69685.0*cos(3.0*vartheta) + 48076.0*cos(4.0*vartheta) + 29631.0*cos(5.0*vartheta) + 13566.0*cos(6.0*vartheta) + 4845.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),5))/2048.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(21.0/M_PI)*(919611.0 + 1777776.0*cos(vartheta) + 1609608.0*cos(2.0*vartheta) + 1349712.0*cos(3.0*vartheta) + 1041404.0*cos(4.0*vartheta) + 717808.0*cos(5.0*vartheta) + 429624.0*cos(6.0*vartheta) + 201552.0*cos(7.0*vartheta) + 62985.0*cos(8.0*vartheta))*pow(sin(vartheta/2.0),4))/32768.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (3.0*sqrt(7.0/M_PI)*cos(vartheta/2.0)*(92169.0 + 168168.0*cos(vartheta) + 168168.0*cos(2.0*vartheta) + 137592.0*cos(3.0*vartheta) + 124852.0*cos(4.0*vartheta) + 86632.0*cos(5.0*vartheta) + 68952.0*cos(6.0*vartheta) + 33592.0*cos(7.0*vartheta) + 20995.0*cos(8.0*vartheta))*pow(sin(vartheta/2.0),3))/16384.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (3.0*sqrt(385.0/(2.0*M_PI))*(8085.0 + 15288.0*cos(2.0*vartheta) + 12740.0*cos(4.0*vartheta) + 8840.0*cos(6.0*vartheta) + 4199.0*cos(8.0*vartheta))*pow(sin(vartheta),2))/65536.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (3.0*sqrt(7.0/M_PI)*pow(cos(vartheta/2.0),3)*(92169.0 - 168168.0*cos(vartheta) + 168168.0*cos(2.0*vartheta) - 137592.0*cos(3.0*vartheta) + 124852.0*cos(4.0*vartheta) - 86632.0*cos(5.0*vartheta) + 68952.0*cos(6.0*vartheta) - 33592.0*cos(7.0*vartheta) + 20995.0*cos(8.0*vartheta))*sin(vartheta/2.0))/16384.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(21.0/M_PI)*pow(cos(vartheta/2.0),4)*(919611.0 - 1777776.0*cos(vartheta) + 1609608.0*cos(2.0*vartheta) - 1349712.0*cos(3.0*vartheta) + 1041404.0*cos(4.0*vartheta) - 717808.0*cos(5.0*vartheta) + 429624.0*cos(6.0*vartheta) - 201552.0*cos(7.0*vartheta) + 62985.0*cos(8.0*vartheta)))/32768.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = -(sqrt(273.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(-52052.0 + 100639.0*cos(vartheta) - 87010.0*cos(2.0*vartheta) + 69685.0*cos(3.0*vartheta) - 48076.0*cos(4.0*vartheta) + 29631.0*cos(5.0*vartheta) - 13566.0*cos(6.0*vartheta) + 4845.0*cos(7.0*vartheta))*sin(vartheta/2.0))/2048.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (sqrt(273.0/M_PI)*pow(cos(vartheta/2.0),6)*(35126.0 - 63960.0*cos(vartheta) + 55875.0*cos(2.0*vartheta) - 39100.0*cos(3.0*vartheta) + 26010.0*cos(4.0*vartheta) - 11628.0*cos(5.0*vartheta) + 4845.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),2))/1024.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(1365.0/(2.0*M_PI))*pow(cos(vartheta/2.0),7)*(-3990.0 + 8162.0*cos(vartheta) - 5848.0*cos(2.0*vartheta) + 4437.0*cos(3.0*vartheta) - 1938.0*cos(4.0*vartheta) + 969.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),3))/128.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = (sqrt(273.0/(2.0*M_PI))*pow(cos(vartheta/2.0),8)*(13159.0 - 19448.0*cos(vartheta) + 18156.0*cos(2.0*vartheta) - 7752.0*cos(3.0*vartheta) + 4845.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),4))/128.0;
      Phi = 6.0*varphi;
      break;
    case 7:
      Amp = -(sqrt(4641.0/(2.0*M_PI))*pow(cos(vartheta/2.0),9)*(-314.0 + 819.0*cos(vartheta) - 342.0*cos(2.0*vartheta) + 285.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),5))/16.0;
      Phi = 7.0*varphi;
      break;
    case 8:
      Amp = (3.0*sqrt(1547.0/M_PI)*pow(cos(vartheta/2.0),10)*(93.0 - 76.0*cos(vartheta) + 95.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),6))/8.0;
      Phi = 8.0*varphi;
      break;
    case 9:
      Amp = -3.0*sqrt(29393.0/(2.0*M_PI))*pow(cos(vartheta/2.0),11)*(-1.0 + 5.0*cos(vartheta))*pow(sin(vartheta/2.0),7);
      Phi = 9.0*varphi;
      break;
    case 10:
      Amp = 3.0*sqrt(146965.0/(2.0*M_PI))*pow(cos(vartheta/2.0),12)*pow(sin(vartheta/2.0),8);
      Phi = 10.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 11:
    switch(M) {
    case -11:
      Amp = sqrt(2860165.0/M_PI)*pow(cos(vartheta/2.0),9)*pow(sin(vartheta/2.0),13);
      Phi = -11.0*varphi;
      break;
    case -10:
      Amp = sqrt(260015.0/(2.0*M_PI))*pow(cos(vartheta/2.0),8)*(2.0 + 11.0*cos(vartheta))*pow(sin(vartheta/2.0),12);
      Phi = -10.0*varphi;
      break;
    case -9:
      Amp = (sqrt(111435.0/M_PI)*pow(cos(vartheta/2.0),7)*(75.0 + 56.0*cos(vartheta) + 77.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),11))/8.0;
      Phi = -9.0*varphi;
      break;
    case -8:
      Amp = (sqrt(7429.0/M_PI)*pow(cos(vartheta/2.0),6)*(388.0 + 1095.0*cos(vartheta) + 420.0*cos(2.0*vartheta) + 385.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),10))/16.0;
      Phi = -8.0*varphi;
      break;
    case -7:
      Amp = (sqrt(391.0/M_PI)*pow(cos(vartheta/2.0),5)*(19529.0 + 27056.0*cos(vartheta) + 26980.0*cos(2.0*vartheta) + 10640.0*cos(3.0*vartheta) + 7315.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),9))/128.0;
      Phi = -7.0*varphi;
      break;
    case -6:
      Amp = (3.0*sqrt(1955.0/(2.0*M_PI))*pow(cos(vartheta/2.0),4)*(5644.0 + 12078.0*cos(vartheta) + 8208.0*cos(2.0*vartheta) + 6555.0*cos(3.0*vartheta) + 2660.0*cos(4.0*vartheta) + 1463.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),8))/256.0;
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (sqrt(345.0/M_PI)*pow(cos(vartheta/2.0),3)*(178010.0 + 314160.0*cos(vartheta) + 281673.0*cos(2.0*vartheta) + 188632.0*cos(3.0*vartheta) + 129846.0*cos(4.0*vartheta) + 54264.0*cos(5.0*vartheta) + 24871.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),7))/2048.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (sqrt(2415.0/M_PI)*pow(cos(vartheta/2.0),2)*(37960.0 + 74347.0*cos(vartheta) + 62764.0*cos(2.0*vartheta) + 50609.0*cos(3.0*vartheta) + 33592.0*cos(4.0*vartheta) + 20995.0*cos(5.0*vartheta) + 9044.0*cos(6.0*vartheta) + 3553.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),6))/2048.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (3.0*sqrt(161.0/(2.0*M_PI))*cos(vartheta/2.0)*(274703.0 + 526240.0*cos(vartheta) + 474760.0*cos(2.0*vartheta) + 388960.0*cos(3.0*vartheta) + 296140.0*cos(4.0*vartheta) + 196384.0*cos(5.0*vartheta) + 116280.0*cos(6.0*vartheta) + 51680.0*cos(7.0*vartheta) + 17765.0*cos(8.0*vartheta))*pow(sin(vartheta/2.0),5))/16384.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (sqrt(23.0/M_PI)*(2414412.0 + 4702698.0*cos(vartheta) + 4324320.0*cos(2.0*vartheta) + 3751020.0*cos(3.0*vartheta) + 3033072.0*cos(4.0*vartheta) + 2266236.0*cos(5.0*vartheta) + 1519392.0*cos(6.0*vartheta) + 886635.0*cos(7.0*vartheta) + 406980.0*cos(8.0*vartheta) + 124355.0*cos(9.0*vartheta))*pow(sin(vartheta/2.0),4))/65536.0;
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (sqrt(1495.0/(2.0*M_PI))*cos(vartheta/2.0)*(126126.0 + 261954.0*cos(vartheta) + 232848.0*cos(2.0*vartheta) + 224028.0*cos(3.0*vartheta) + 179928.0*cos(4.0*vartheta) + 158508.0*cos(5.0*vartheta) + 108528.0*cos(6.0*vartheta) + 84303.0*cos(7.0*vartheta) + 40698.0*cos(8.0*vartheta) + 24871.0*cos(9.0*vartheta))*pow(sin(vartheta/2.0),3))/65536.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (sqrt(49335.0/(2.0*M_PI))*cos(vartheta)*(2719.0 + 4264.0*cos(2.0*vartheta) + 4556.0*cos(4.0*vartheta) + 2584.0*cos(6.0*vartheta) + 2261.0*cos(8.0*vartheta))*pow(sin(vartheta),2))/65536.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (sqrt(1495.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(-126126.0 + 261954.0*cos(vartheta) - 232848.0*cos(2.0*vartheta) + 224028.0*cos(3.0*vartheta) - 179928.0*cos(4.0*vartheta) + 158508.0*cos(5.0*vartheta) - 108528.0*cos(6.0*vartheta) + 84303.0*cos(7.0*vartheta) - 40698.0*cos(8.0*vartheta) + 24871.0*cos(9.0*vartheta))*sin(vartheta/2.0))/65536.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (sqrt(23.0/M_PI)*pow(cos(vartheta/2.0),4)*(-2414412.0 + 4702698.0*cos(vartheta) - 4324320.0*cos(2.0*vartheta) + 3751020.0*cos(3.0*vartheta) - 3033072.0*cos(4.0*vartheta) + 2266236.0*cos(5.0*vartheta) - 1519392.0*cos(6.0*vartheta) + 886635.0*cos(7.0*vartheta) - 406980.0*cos(8.0*vartheta) + 124355.0*cos(9.0*vartheta)))/65536.0;
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = (-3.0*sqrt(161.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(274703.0 - 526240.0*cos(vartheta) + 474760.0*cos(2.0*vartheta) - 388960.0*cos(3.0*vartheta) + 296140.0*cos(4.0*vartheta) - 196384.0*cos(5.0*vartheta) + 116280.0*cos(6.0*vartheta) - 51680.0*cos(7.0*vartheta) + 17765.0*cos(8.0*vartheta))*sin(vartheta/2.0))/16384.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (sqrt(2415.0/M_PI)*pow(cos(vartheta/2.0),6)*(-37960.0 + 74347.0*cos(vartheta) - 62764.0*cos(2.0*vartheta) + 50609.0*cos(3.0*vartheta) - 33592.0*cos(4.0*vartheta) + 20995.0*cos(5.0*vartheta) - 9044.0*cos(6.0*vartheta) + 3553.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),2))/2048.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = -(sqrt(345.0/M_PI)*pow(cos(vartheta/2.0),7)*(178010.0 - 314160.0*cos(vartheta) + 281673.0*cos(2.0*vartheta) - 188632.0*cos(3.0*vartheta) + 129846.0*cos(4.0*vartheta) - 54264.0*cos(5.0*vartheta) + 24871.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),3))/2048.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = (3.0*sqrt(1955.0/(2.0*M_PI))*pow(cos(vartheta/2.0),8)*(-5644.0 + 12078.0*cos(vartheta) - 8208.0*cos(2.0*vartheta) + 6555.0*cos(3.0*vartheta) - 2660.0*cos(4.0*vartheta) + 1463.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),4))/256.0;
      Phi = 6.0*varphi;
      break;
    case 7:
      Amp = -(sqrt(391.0/M_PI)*pow(cos(vartheta/2.0),9)*(19529.0 - 27056.0*cos(vartheta) + 26980.0*cos(2.0*vartheta) - 10640.0*cos(3.0*vartheta) + 7315.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),5))/128.0;
      Phi = 7.0*varphi;
      break;
    case 8:
      Amp = (sqrt(7429.0/M_PI)*pow(cos(vartheta/2.0),10)*(-388.0 + 1095.0*cos(vartheta) - 420.0*cos(2.0*vartheta) + 385.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),6))/16.0;
      Phi = 8.0*varphi;
      break;
    case 9:
      Amp = -(sqrt(111435.0/M_PI)*pow(cos(vartheta/2.0),11)*(75.0 - 56.0*cos(vartheta) + 77.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),7))/8.0;
      Phi = 9.0*varphi;
      break;
    case 10:
      Amp = sqrt(260015.0/(2.0*M_PI))*pow(cos(vartheta/2.0),12)*(-2.0 + 11.0*cos(vartheta))*pow(sin(vartheta/2.0),8);
      Phi = 10.0*varphi;
      break;
    case 11:
      Amp = -(sqrt(2860165.0/M_PI)*pow(cos(vartheta/2.0),13)*pow(sin(vartheta/2.0),9));
      Phi = 11.0*varphi;
      break;
    } // switch(M)
    break;
    
  case 12:
    switch(M) {
    case -12:
      Amp = 5.0*sqrt(490314.0/M_PI)*pow(cos(vartheta/2.0),10)*pow(sin(vartheta/2.0),14);
      Phi = -12.0*varphi;
      break;
    case -11:
      Amp = 5.0*sqrt(81719.0/M_PI)*pow(cos(vartheta/2.0),9)*(1.0 + 6.0*cos(vartheta))*pow(sin(vartheta/2.0),13);
      Phi = -11.0*varphi;
      break;
    case -10:
      Amp = (5.0*sqrt(3553.0/(2.0*M_PI))*pow(cos(vartheta/2.0),8)*(67.0 + 46.0*cos(vartheta) + 69.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),12))/2.0;
      Phi = -10.0*varphi;
      break;
    case -9:
      Amp = (5.0*sqrt(969.0/M_PI)*pow(cos(vartheta/2.0),7)*(235.0 + 715.0*cos(vartheta) + 253.0*cos(2.0*vartheta) + 253.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),11))/8.0;
      Phi = -9.0*varphi;
      break;
    case -8:
      Amp = (5.0*sqrt(2261.0/M_PI)*pow(cos(vartheta/2.0),6)*(2005.0 + 2604.0*cos(vartheta) + 2772.0*cos(2.0*vartheta) + 1012.0*cos(3.0*vartheta) + 759.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),10))/64.0;
      Phi = -8.0*varphi;
      break;
    case -7:
      Amp = (5.0*sqrt(2261.0/M_PI)*pow(cos(vartheta/2.0),5)*(2755.0 + 6190.0*cos(vartheta) + 3980.0*cos(2.0*vartheta) + 3355.0*cos(3.0*vartheta) + 1265.0*cos(4.0*vartheta) + 759.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),9))/128.0;
      Phi = -7.0*varphi;
      break;
    case -6:
      Amp = (5.0*sqrt(357.0/(2.0*M_PI))*pow(cos(vartheta/2.0),4)*(34170.0 + 58140.0*cos(vartheta) + 53865.0*cos(2.0*vartheta) + 34390.0*cos(3.0*vartheta) + 24662.0*cos(4.0*vartheta) + 9614.0*cos(5.0*vartheta) + 4807.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),8))/512.0;
      Phi = -6.0*varphi;
      break;
    case -5:
      Amp = (5.0*sqrt(51.0/M_PI)*pow(cos(vartheta/2.0),3)*(152150.0 + 303975.0*cos(vartheta) + 249375.0*cos(2.0*vartheta) + 204421.0*cos(3.0*vartheta) + 130074.0*cos(4.0*vartheta) + 83391.0*cos(5.0*vartheta) + 33649.0*cos(6.0*vartheta) + 14421.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),7))/2048.0;
      Phi = -5.0*varphi;
      break;
    case -4:
      Amp = (5.0*sqrt(3.0/(2.0*M_PI))*pow(cos(vartheta/2.0),2)*(3952975.0 + 7469800.0*cos(vartheta) + 6769672.0*cos(2.0*vartheta) + 5408312.0*cos(3.0*vartheta) + 4115020.0*cos(4.0*vartheta) + 2622760.0*cos(5.0*vartheta) + 1563320.0*cos(6.0*vartheta) + 653752.0*cos(7.0*vartheta) + 245157.0*cos(8.0*vartheta))*pow(sin(vartheta/2.0),6))/16384.0;
      Phi = -4.0*varphi;
      break;
    case -3:
      Amp = (5.0*sqrt(3.0/(2.0*M_PI))*cos(vartheta/2.0)*(1748175.0 + 3408834.0*cos(vartheta) + 3092232.0*cos(2.0*vartheta) + 2654652.0*cos(3.0*vartheta) + 2089164.0*cos(4.0*vartheta) + 1531020.0*cos(5.0*vartheta) + 984504.0*cos(6.0*vartheta) + 564927.0*cos(7.0*vartheta) + 245157.0*cos(8.0*vartheta) + 81719.0*cos(9.0*vartheta))*pow(sin(vartheta/2.0),5))/16384.0;
      Phi = -3.0*varphi;
      break;
    case -2:
      Amp = (5.0*(6205914.0 + 12123540.0*cos(vartheta) + 11312730.0*cos(2.0*vartheta) + 10030680.0*cos(3.0*vartheta) + 8427240.0*cos(4.0*vartheta) + 6627960.0*cos(5.0*vartheta) + 4830465.0*cos(6.0*vartheta) + 3168630.0*cos(7.0*vartheta) + 1812030.0*cos(8.0*vartheta) + 817190.0*cos(9.0*vartheta) + 245157.0*cos(10.0*vartheta))*pow(sin(vartheta/2.0),4))/(131072.0*sqrt(M_PI));
      Phi = -2.0*varphi;
      break;
    case -1:
      Amp = (5.0*sqrt(77.0/(2.0*M_PI))*cos(vartheta/2.0)*(144144.0 + 270270.0*cos(vartheta) + 270270.0*cos(2.0*vartheta) + 235620.0*cos(3.0*vartheta) + 220320.0*cos(4.0*vartheta) + 174420.0*cos(5.0*vartheta) + 150195.0*cos(6.0*vartheta) + 101745.0*cos(7.0*vartheta) + 77520.0*cos(8.0*vartheta) + 37145.0*cos(9.0*vartheta) + 22287.0*cos(10.0*vartheta))*pow(sin(vartheta/2.0),3))/65536.0;
      Phi = -varphi;
      break;
    case 0:
      Amp = (5.0*sqrt(3003.0/(2.0*M_PI))*(18018.0 + 34650.0*cos(2.0*vartheta) + 30600.0*cos(4.0*vartheta) + 24225.0*cos(6.0*vartheta) + 16150.0*cos(8.0*vartheta) + 7429.0*cos(10.0*vartheta))*pow(sin(vartheta),2))/524288.0;
      Phi = 0.0*varphi;
      break;
    case 1:
      Amp = (5.0*sqrt(77.0/(2.0*M_PI))*pow(cos(vartheta/2.0),3)*(144144.0 - 270270.0*cos(vartheta) + 270270.0*cos(2.0*vartheta) - 235620.0*cos(3.0*vartheta) + 220320.0*cos(4.0*vartheta) - 174420.0*cos(5.0*vartheta) + 150195.0*cos(6.0*vartheta) - 101745.0*cos(7.0*vartheta) + 77520.0*cos(8.0*vartheta) - 37145.0*cos(9.0*vartheta) + 22287.0*cos(10.0*vartheta))*sin(vartheta/2.0))/65536.0;
      Phi = varphi;
      break;
    case 2:
      Amp = (5.0*pow(cos(vartheta/2.0),4)*(6205914.0 - 12123540.0*cos(vartheta) + 11312730.0*cos(2.0*vartheta) - 10030680.0*cos(3.0*vartheta) + 8427240.0*cos(4.0*vartheta) - 6627960.0*cos(5.0*vartheta) + 4830465.0*cos(6.0*vartheta) - 3168630.0*cos(7.0*vartheta) + 1812030.0*cos(8.0*vartheta) - 817190.0*cos(9.0*vartheta) + 245157.0*cos(10.0*vartheta)))/(131072.0*sqrt(M_PI));
      Phi = 2.0*varphi;
      break;
    case 3:
      Amp = (-5.0*sqrt(3.0/(2.0*M_PI))*pow(cos(vartheta/2.0),5)*(-1748175.0 + 3408834.0*cos(vartheta) - 3092232.0*cos(2.0*vartheta) + 2654652.0*cos(3.0*vartheta) - 2089164.0*cos(4.0*vartheta) + 1531020.0*cos(5.0*vartheta) - 984504.0*cos(6.0*vartheta) + 564927.0*cos(7.0*vartheta) - 245157.0*cos(8.0*vartheta) + 81719.0*cos(9.0*vartheta))*sin(vartheta/2.0))/16384.0;
      Phi = 3.0*varphi;
      break;
    case 4:
      Amp = (5.0*sqrt(3.0/(2.0*M_PI))*pow(cos(vartheta/2.0),6)*(3952975.0 - 7469800.0*cos(vartheta) + 6769672.0*cos(2.0*vartheta) - 5408312.0*cos(3.0*vartheta) + 4115020.0*cos(4.0*vartheta) - 2622760.0*cos(5.0*vartheta) + 1563320.0*cos(6.0*vartheta) - 653752.0*cos(7.0*vartheta) + 245157.0*cos(8.0*vartheta))*pow(sin(vartheta/2.0),2))/16384.0;
      Phi = 4.0*varphi;
      break;
    case 5:
      Amp = (-5.0*sqrt(51.0/M_PI)*pow(cos(vartheta/2.0),7)*(-152150.0 + 303975.0*cos(vartheta) - 249375.0*cos(2.0*vartheta) + 204421.0*cos(3.0*vartheta) - 130074.0*cos(4.0*vartheta) + 83391.0*cos(5.0*vartheta) - 33649.0*cos(6.0*vartheta) + 14421.0*cos(7.0*vartheta))*pow(sin(vartheta/2.0),3))/2048.0;
      Phi = 5.0*varphi;
      break;
    case 6:
      Amp = (5.0*sqrt(357.0/(2.0*M_PI))*pow(cos(vartheta/2.0),8)*(34170.0 - 58140.0*cos(vartheta) + 53865.0*cos(2.0*vartheta) - 34390.0*cos(3.0*vartheta) + 24662.0*cos(4.0*vartheta) - 9614.0*cos(5.0*vartheta) + 4807.0*cos(6.0*vartheta))*pow(sin(vartheta/2.0),4))/512.0;
      Phi = 6.0*varphi;
      break;
    case 7:
      Amp = (-5.0*sqrt(2261.0/M_PI)*pow(cos(vartheta/2.0),9)*(-2755.0 + 6190.0*cos(vartheta) - 3980.0*cos(2.0*vartheta) + 3355.0*cos(3.0*vartheta) - 1265.0*cos(4.0*vartheta) + 759.0*cos(5.0*vartheta))*pow(sin(vartheta/2.0),5))/128.0;
      Phi = 7.0*varphi;
      break;
    case 8:
      Amp = (5.0*sqrt(2261.0/M_PI)*pow(cos(vartheta/2.0),10)*(2005.0 - 2604.0*cos(vartheta) + 2772.0*cos(2.0*vartheta) - 1012.0*cos(3.0*vartheta) + 759.0*cos(4.0*vartheta))*pow(sin(vartheta/2.0),6))/64.0;
      Phi = 8.0*varphi;
      break;
    case 9:
      Amp = (-5.0*sqrt(969.0/M_PI)*pow(cos(vartheta/2.0),11)*(-235.0 + 715.0*cos(vartheta) - 253.0*cos(2.0*vartheta) + 253.0*cos(3.0*vartheta))*pow(sin(vartheta/2.0),7))/8.0;
      Phi = 9.0*varphi;
      break;
    case 10:
      Amp = (5.0*sqrt(3553.0/(2.0*M_PI))*pow(cos(vartheta/2.0),12)*(67.0 - 46.0*cos(vartheta) + 69.0*cos(2.0*vartheta))*pow(sin(vartheta/2.0),8))/2.0;
      Phi = 10.0*varphi;
      break;
    case 11:
      Amp = -5.0*sqrt(81719.0/M_PI)*pow(cos(vartheta/2.0),13)*(-1.0 + 6.0*cos(vartheta))*pow(sin(vartheta/2.0),9);
      Phi = 11.0*varphi;
      break;
    case 12:
      Amp = 5.0*sqrt(490314.0/M_PI)*pow(cos(vartheta/2.0),14)*pow(sin(vartheta/2.0),10);
      Phi = 12.0*varphi;
      break;
    } // switch(M)
    break;
    
  } // switch(L)
  
  return;
}

void SWSH(const std::vector<std::vector<int> >& LM, const double& vartheta, const double& varphi, std::vector<double>& amp, std::vector<double>& phi) {
  amp = std::vector<double>(LM.size(), 0.0);
  phi = std::vector<double>(LM.size(), 0.0);
  for(unsigned int i=0; i<LM.size(); ++i) {
    SWSH(LM[i][0], LM[i][1], vartheta, varphi, amp[i], phi[i]);
  }
  return;
}
