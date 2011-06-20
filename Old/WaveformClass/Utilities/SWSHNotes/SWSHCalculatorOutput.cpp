#include "SWSHs.hpp"
#include <cstdlib>
#include <cmath>

void SWSH(const int L, const int M, const double& vartheta, const double& varphi, double& Amp, double& Phi) {
  if(L<2) { throw("l<2 unsupported."); }
  if(labs(M)>L) { throw("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(L>12) { throw("l>12 unsupported."); }
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      Amp = (Sqrt(5/Pi)*Power(Sin(vartheta/2.),4))/2.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = Sqrt(5/Pi)*Cos(vartheta/2.)*Power(Sin(vartheta/2.),3);
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (Sqrt(15/(2.*Pi))*Power(Sin(vartheta),2))/4.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = Sqrt(5/Pi)*Power(Cos(vartheta/2.),3)*Sin(vartheta/2.);
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(5/Pi)*Power(Cos(vartheta/2.),4))/2.;
      Phi = 2*varphi;
      break;
    } // switch(M)
    
  case 3:
    switch(M) {
    case -3:
      Amp = Sqrt(21/(2.*Pi))*Cos(vartheta/2.)*Power(Sin(vartheta/2.),5);
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(7/Pi)*(2 + 3*Cos(vartheta))*Power(Sin(vartheta/2.),4))/2.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (Sqrt(35/(2.*Pi))*Cos(vartheta/2.)*(1 + 3*Cos(vartheta))*Power(Sin(vartheta/2.),3))/2.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (Sqrt(105/(2.*Pi))*Cos(vartheta)*Power(Sin(vartheta),2))/4.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (Sqrt(35/(2.*Pi))*Power(Cos(vartheta/2.),3)*(-1 + 3*Cos(vartheta))*Sin(vartheta/2.))/2.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(7/Pi)*Power(Cos(vartheta/2.),4)*(-2 + 3*Cos(vartheta)))/2.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -(Sqrt(21/(2.*Pi))*Power(Cos(vartheta/2.),5)*Sin(vartheta/2.));
      Phi = 3*varphi;
      break;
    } // switch(M)
    
  case 4:
    switch(M) {
    case -4:
      Amp = 3*Sqrt(7/Pi)*Power(Cos(vartheta/2.),2)*Power(Sin(vartheta/2.),6);
      Phi = -4*varphi;
      break;
    case -3:
      Amp = 3*Sqrt(7/(2.*Pi))*Cos(vartheta/2.)*(1 + 2*Cos(vartheta))*Power(Sin(vartheta/2.),5);
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (3*(9 + 14*Cos(vartheta) + 7*Cos(2*vartheta))*Power(Sin(vartheta/2.),4))/(4.*Sqrt(Pi));
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (3*Cos(vartheta/2.)*(6 + 7*Cos(vartheta) + 7*Cos(2*vartheta))*Power(Sin(vartheta/2.),3))/(2.*Sqrt(2*Pi));
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (3*Sqrt(5/(2.*Pi))*(5 + 7*Cos(2*vartheta))*Power(Sin(vartheta),2))/16.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (3*Power(Cos(vartheta/2.),3)*(6 - 7*Cos(vartheta) + 7*Cos(2*vartheta))*Sin(vartheta/2.))/(2.*Sqrt(2*Pi));
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (3*Power(Cos(vartheta/2.),4)*(9 - 14*Cos(vartheta) + 7*Cos(2*vartheta)))/(4.*Sqrt(Pi));
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -3*Sqrt(7/(2.*Pi))*Power(Cos(vartheta/2.),5)*(-1 + 2*Cos(vartheta))*Sin(vartheta/2.);
      Phi = 3*varphi;
      break;
    case 4:
      Amp = 3*Sqrt(7/Pi)*Power(Cos(vartheta/2.),6)*Power(Sin(vartheta/2.),2);
      Phi = 4*varphi;
      break;
    } // switch(M)
    
  case 5:
    switch(M) {
    case -5:
      Amp = Sqrt(330/Pi)*Power(Cos(vartheta/2.),3)*Power(Sin(vartheta/2.),7);
      Phi = -5*varphi;
      break;
    case -4:
      Amp = Sqrt(33/Pi)*Power(Cos(vartheta/2.),2)*(2 + 5*Cos(vartheta))*Power(Sin(vartheta/2.),6);
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (Sqrt(33/(2.*Pi))*Cos(vartheta/2.)*(17 + 24*Cos(vartheta) + 15*Cos(2*vartheta))*Power(Sin(vartheta/2.),5))/4.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(11/Pi)*(32 + 57*Cos(vartheta) + 36*Cos(2*vartheta) + 15*Cos(3*vartheta))*Power(Sin(vartheta/2.),4))/8.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (Sqrt(77/Pi)*Cos(vartheta/2.)*(14 + 33*Cos(vartheta) + 18*Cos(2*vartheta) + 15*Cos(3*vartheta))*Power(Sin(vartheta/2.),3))/16.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (Sqrt(1155/(2.*Pi))*Cos(vartheta)*(1 + 3*Cos(2*vartheta))*Power(Sin(vartheta),2))/16.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (Sqrt(77/Pi)*Power(Cos(vartheta/2.),3)*(-14 + 33*Cos(vartheta) - 18*Cos(2*vartheta) + 15*Cos(3*vartheta))*Sin(vartheta/2.))/16.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(11/Pi)*Power(Cos(vartheta/2.),4)*(-32 + 57*Cos(vartheta) - 36*Cos(2*vartheta) + 15*Cos(3*vartheta)))/8.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -(Sqrt(33/(2.*Pi))*Power(Cos(vartheta/2.),5)*(17 - 24*Cos(vartheta) + 15*Cos(2*vartheta))*Sin(vartheta/2.))/4.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = Sqrt(33/Pi)*Power(Cos(vartheta/2.),6)*(-2 + 5*Cos(vartheta))*Power(Sin(vartheta/2.),2);
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(330/Pi)*Power(Cos(vartheta/2.),7)*Power(Sin(vartheta/2.),3));
      Phi = 5*varphi;
      break;
    } // switch(M)
    
  case 6:
    switch(M) {
    case -6:
      Amp = (3*Sqrt(715/Pi)*Power(Cos(vartheta/2.),4)*Power(Sin(vartheta/2.),8))/2.;
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (Sqrt(2145/Pi)*Power(Cos(vartheta/2.),3)*(1 + 3*Cos(vartheta))*Power(Sin(vartheta/2.),7))/2.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (Sqrt(195/(2.*Pi))*Power(Cos(vartheta/2.),2)*(35 + 44*Cos(vartheta) + 33*Cos(2*vartheta))*Power(Sin(vartheta/2.),6))/8.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (3*Sqrt(13/Pi)*Cos(vartheta/2.)*(98 + 185*Cos(vartheta) + 110*Cos(2*vartheta) + 55*Cos(3*vartheta))*Power(Sin(vartheta/2.),5))/32.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(13/Pi)*(1709 + 3096*Cos(vartheta) + 2340*Cos(2*vartheta) + 1320*Cos(3*vartheta) + 495*Cos(4*vartheta))*Power(Sin(vartheta/2.),4))/256.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (Sqrt(65/(2.*Pi))*Cos(vartheta/2.)*(161 + 252*Cos(vartheta) + 252*Cos(2*vartheta) + 132*Cos(3*vartheta) + 99*Cos(4*vartheta))*Power(Sin(vartheta/2.),3))/64.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (Sqrt(1365/Pi)*(35 + 60*Cos(2*vartheta) + 33*Cos(4*vartheta))*Power(Sin(vartheta),2))/512.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (Sqrt(65/(2.*Pi))*Power(Cos(vartheta/2.),3)*(161 - 252*Cos(vartheta) + 252*Cos(2*vartheta) - 132*Cos(3*vartheta) + 99*Cos(4*vartheta))*Sin(vartheta/2.))/64.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(13/Pi)*Power(Cos(vartheta/2.),4)*(1709 - 3096*Cos(vartheta) + 2340*Cos(2*vartheta) - 1320*Cos(3*vartheta) + 495*Cos(4*vartheta)))/256.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = (-3*Sqrt(13/Pi)*Power(Cos(vartheta/2.),5)*(-98 + 185*Cos(vartheta) - 110*Cos(2*vartheta) + 55*Cos(3*vartheta))*Sin(vartheta/2.))/32.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (Sqrt(195/(2.*Pi))*Power(Cos(vartheta/2.),6)*(35 - 44*Cos(vartheta) + 33*Cos(2*vartheta))*Power(Sin(vartheta/2.),2))/8.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(2145/Pi)*Power(Cos(vartheta/2.),7)*(-1 + 3*Cos(vartheta))*Power(Sin(vartheta/2.),3))/2.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = (3*Sqrt(715/Pi)*Power(Cos(vartheta/2.),8)*Power(Sin(vartheta/2.),4))/2.;
      Phi = 6*varphi;
      break;
    } // switch(M)
    
  case 7:
    switch(M) {
    case -7:
      Amp = Sqrt(15015/(2.*Pi))*Power(Cos(vartheta/2.),5)*Power(Sin(vartheta/2.),9);
      Phi = -7*varphi;
      break;
    case -6:
      Amp = (Sqrt(2145/Pi)*Power(Cos(vartheta/2.),4)*(2 + 7*Cos(vartheta))*Power(Sin(vartheta/2.),8))/2.;
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (Sqrt(165/(2.*Pi))*Power(Cos(vartheta/2.),3)*(93 + 104*Cos(vartheta) + 91*Cos(2*vartheta))*Power(Sin(vartheta/2.),7))/8.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (Sqrt(165/(2.*Pi))*Power(Cos(vartheta/2.),2)*(140 + 285*Cos(vartheta) + 156*Cos(2*vartheta) + 91*Cos(3*vartheta))*Power(Sin(vartheta/2.),6))/16.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (Sqrt(15/(2.*Pi))*Cos(vartheta/2.)*(3115 + 5456*Cos(vartheta) + 4268*Cos(2*vartheta) + 2288*Cos(3*vartheta) + 1001*Cos(4*vartheta))*Power(Sin(vartheta/2.),5))/128.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(15/Pi)*(5220 + 9810*Cos(vartheta) + 7920*Cos(2*vartheta) + 5445*Cos(3*vartheta) + 2860*Cos(4*vartheta) + 1001*Cos(5*vartheta))*Power(Sin(vartheta/2.),4))/512.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (3*Sqrt(5/(2.*Pi))*Cos(vartheta/2.)*(1890 + 4130*Cos(vartheta) + 3080*Cos(2*vartheta) + 2805*Cos(3*vartheta) + 1430*Cos(4*vartheta) + 1001*Cos(5*vartheta))*Power(Sin(vartheta/2.),3))/512.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (3*Sqrt(35/Pi)*Cos(vartheta)*(109 + 132*Cos(2*vartheta) + 143*Cos(4*vartheta))*Power(Sin(vartheta),2))/512.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (3*Sqrt(5/(2.*Pi))*Power(Cos(vartheta/2.),3)*(-1890 + 4130*Cos(vartheta) - 3080*Cos(2*vartheta) + 2805*Cos(3*vartheta) - 1430*Cos(4*vartheta) + 1001*Cos(5*vartheta))*Sin(vartheta/2.))/512.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(15/Pi)*Power(Cos(vartheta/2.),4)*(-5220 + 9810*Cos(vartheta) - 7920*Cos(2*vartheta) + 5445*Cos(3*vartheta) - 2860*Cos(4*vartheta) + 1001*Cos(5*vartheta)))/512.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -(Sqrt(15/(2.*Pi))*Power(Cos(vartheta/2.),5)*(3115 - 5456*Cos(vartheta) + 4268*Cos(2*vartheta) - 2288*Cos(3*vartheta) + 1001*Cos(4*vartheta))*Sin(vartheta/2.))/128.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (Sqrt(165/(2.*Pi))*Power(Cos(vartheta/2.),6)*(-140 + 285*Cos(vartheta) - 156*Cos(2*vartheta) + 91*Cos(3*vartheta))*Power(Sin(vartheta/2.),2))/16.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(165/(2.*Pi))*Power(Cos(vartheta/2.),7)*(93 - 104*Cos(vartheta) + 91*Cos(2*vartheta))*Power(Sin(vartheta/2.),3))/8.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = (Sqrt(2145/Pi)*Power(Cos(vartheta/2.),8)*(-2 + 7*Cos(vartheta))*Power(Sin(vartheta/2.),4))/2.;
      Phi = 6*varphi;
      break;
    case 7:
      Amp = -(Sqrt(15015/(2.*Pi))*Power(Cos(vartheta/2.),9)*Power(Sin(vartheta/2.),5));
      Phi = 7*varphi;
      break;
    } // switch(M)
    
  case 8:
    switch(M) {
    case -8:
      Amp = Sqrt(34034/Pi)*Power(Cos(vartheta/2.),6)*Power(Sin(vartheta/2.),10);
      Phi = -8*varphi;
      break;
    case -7:
      Amp = Sqrt(17017/(2.*Pi))*Power(Cos(vartheta/2.),5)*(1 + 4*Cos(vartheta))*Power(Sin(vartheta/2.),9);
      Phi = -7*varphi;
      break;
    case -6:
      Amp = Sqrt(255255/Pi)*Power(Cos(vartheta/2.),4)*(1 + 2*Cos(vartheta))*Sin(Pi/4. - vartheta/2.)*Sin(Pi/4. + vartheta/2.)*Power(Sin(vartheta/2.),8);
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (Sqrt(12155/(2.*Pi))*Power(Cos(vartheta/2.),3)*(19 + 42*Cos(vartheta) + 21*Cos(2*vartheta) + 14*Cos(3*vartheta))*Power(Sin(vartheta/2.),7))/8.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (Sqrt(935/(2.*Pi))*Power(Cos(vartheta/2.),2)*(265 + 442*Cos(vartheta) + 364*Cos(2*vartheta) + 182*Cos(3*vartheta) + 91*Cos(4*vartheta))*Power(Sin(vartheta/2.),6))/32.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (Sqrt(561/(2.*Pi))*Cos(vartheta/2.)*(869 + 1660*Cos(vartheta) + 1300*Cos(2*vartheta) + 910*Cos(3*vartheta) + 455*Cos(4*vartheta) + 182*Cos(5*vartheta))*Power(Sin(vartheta/2.),5))/128.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(17/Pi)*(7626 + 14454*Cos(vartheta) + 12375*Cos(2*vartheta) + 9295*Cos(3*vartheta) + 6006*Cos(4*vartheta) + 3003*Cos(5*vartheta) + 1001*Cos(6*vartheta))*Power(Sin(vartheta/2.),4))/512.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (Sqrt(595/(2.*Pi))*Cos(vartheta/2.)*(798 + 1386*Cos(vartheta) + 1386*Cos(2*vartheta) + 1001*Cos(3*vartheta) + 858*Cos(4*vartheta) + 429*Cos(5*vartheta) + 286*Cos(6*vartheta))*Power(Sin(vartheta/2.),3))/512.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (3*Sqrt(595/Pi)*(210 + 385*Cos(2*vartheta) + 286*Cos(4*vartheta) + 143*Cos(6*vartheta))*Power(Sin(vartheta),2))/4096.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (Sqrt(595/(2.*Pi))*Power(Cos(vartheta/2.),3)*(798 - 1386*Cos(vartheta) + 1386*Cos(2*vartheta) - 1001*Cos(3*vartheta) + 858*Cos(4*vartheta) - 429*Cos(5*vartheta) + 286*Cos(6*vartheta))*Sin(vartheta/2.))/512.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(17/Pi)*Power(Cos(vartheta/2.),4)*(7626 - 14454*Cos(vartheta) + 12375*Cos(2*vartheta) - 9295*Cos(3*vartheta) + 6006*Cos(4*vartheta) - 3003*Cos(5*vartheta) + 1001*Cos(6*vartheta)))/512.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -(Sqrt(561/(2.*Pi))*Power(Cos(vartheta/2.),5)*(-869 + 1660*Cos(vartheta) - 1300*Cos(2*vartheta) + 910*Cos(3*vartheta) - 455*Cos(4*vartheta) + 182*Cos(5*vartheta))*Sin(vartheta/2.))/128.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (Sqrt(935/(2.*Pi))*Power(Cos(vartheta/2.),6)*(265 - 442*Cos(vartheta) + 364*Cos(2*vartheta) - 182*Cos(3*vartheta) + 91*Cos(4*vartheta))*Power(Sin(vartheta/2.),2))/32.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(12155/(2.*Pi))*Power(Cos(vartheta/2.),7)*(-19 + 42*Cos(vartheta) - 21*Cos(2*vartheta) + 14*Cos(3*vartheta))*Power(Sin(vartheta/2.),3))/8.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = Sqrt(255255/Pi)*Power(Cos(vartheta/2.),8)*(-1 + 2*Cos(vartheta))*Sin(Pi/4. - vartheta/2.)*Sin(Pi/4. + vartheta/2.)*Power(Sin(vartheta/2.),4);
      Phi = 6*varphi;
      break;
    case 7:
      Amp = -(Sqrt(17017/(2.*Pi))*Power(Cos(vartheta/2.),9)*(-1 + 4*Cos(vartheta))*Power(Sin(vartheta/2.),5));
      Phi = 7*varphi;
      break;
    case 8:
      Amp = Sqrt(34034/Pi)*Power(Cos(vartheta/2.),10)*Power(Sin(vartheta/2.),6);
      Phi = 8*varphi;
      break;
    } // switch(M)
    
  case 9:
    switch(M) {
    case -9:
      Amp = 6*Sqrt(4199/Pi)*Power(Cos(vartheta/2.),7)*Power(Sin(vartheta/2.),11);
      Phi = -9*varphi;
      break;
    case -8:
      Amp = Sqrt(8398/Pi)*Power(Cos(vartheta/2.),6)*(2 + 9*Cos(vartheta))*Power(Sin(vartheta/2.),10);
      Phi = -8*varphi;
      break;
    case -7:
      Amp = (Sqrt(247/Pi)*Power(Cos(vartheta/2.),5)*(151 + 136*Cos(vartheta) + 153*Cos(2*vartheta))*Power(Sin(vartheta/2.),9))/4.;
      Phi = -7*varphi;
      break;
    case -6:
      Amp = (Sqrt(741/Pi)*Power(Cos(vartheta/2.),4)*(62 + 149*Cos(vartheta) + 68*Cos(2*vartheta) + 51*Cos(3*vartheta))*Power(Sin(vartheta/2.),8))/4.;
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (Sqrt(1235/Pi)*Power(Cos(vartheta/2.),3)*(427 + 672*Cos(vartheta) + 588*Cos(2*vartheta) + 272*Cos(3*vartheta) + 153*Cos(4*vartheta))*Power(Sin(vartheta/2.),7))/32.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (Sqrt(1729/(2.*Pi))*Power(Cos(vartheta/2.),2)*(676 + 1330*Cos(vartheta) + 1000*Cos(2*vartheta) + 725*Cos(3*vartheta) + 340*Cos(4*vartheta) + 153*Cos(5*vartheta))*Power(Sin(vartheta/2.),6))/64.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (Sqrt(399/Pi)*Cos(vartheta/2.)*(4906 + 9152*Cos(vartheta) + 7865*Cos(2*vartheta) + 5720*Cos(3*vartheta) + 3718*Cos(4*vartheta) + 1768*Cos(5*vartheta) + 663*Cos(6*vartheta))*Power(Sin(vartheta/2.),5))/512.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(19/Pi)*(21252 + 40887*Cos(vartheta) + 36036*Cos(2*vartheta) + 29029*Cos(3*vartheta) + 20748*Cos(4*vartheta) + 12831*Cos(5*vartheta) + 6188*Cos(6*vartheta) + 1989*Cos(7*vartheta))*Power(Sin(vartheta/2.),4))/1024.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (Sqrt(209/(2.*Pi))*Cos(vartheta/2.)*(6468 + 13671*Cos(vartheta) + 11466*Cos(2*vartheta) + 10829*Cos(3*vartheta) + 7644*Cos(4*vartheta) + 6279*Cos(5*vartheta) + 3094*Cos(6*vartheta) + 1989*Cos(7*vartheta))*Power(Sin(vartheta/2.),3))/2048.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (3*Sqrt(1045/Pi)*Cos(vartheta)*(166 + 403*Cos(2*vartheta) + 234*Cos(4*vartheta) + 221*Cos(6*vartheta))*Power(Sin(vartheta),2))/4096.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (Sqrt(209/(2.*Pi))*Power(Cos(vartheta/2.),3)*(-6468 + 13671*Cos(vartheta) - 11466*Cos(2*vartheta) + 10829*Cos(3*vartheta) - 7644*Cos(4*vartheta) + 6279*Cos(5*vartheta) - 3094*Cos(6*vartheta) + 1989*Cos(7*vartheta))*Sin(vartheta/2.))/2048.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(19/Pi)*Power(Cos(vartheta/2.),4)*(-21252 + 40887*Cos(vartheta) - 36036*Cos(2*vartheta) + 29029*Cos(3*vartheta) - 20748*Cos(4*vartheta) + 12831*Cos(5*vartheta) - 6188*Cos(6*vartheta) + 1989*Cos(7*vartheta)))/1024.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -(Sqrt(399/Pi)*Power(Cos(vartheta/2.),5)*(4906 - 9152*Cos(vartheta) + 7865*Cos(2*vartheta) - 5720*Cos(3*vartheta) + 3718*Cos(4*vartheta) - 1768*Cos(5*vartheta) + 663*Cos(6*vartheta))*Sin(vartheta/2.))/512.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (Sqrt(1729/(2.*Pi))*Power(Cos(vartheta/2.),6)*(-676 + 1330*Cos(vartheta) - 1000*Cos(2*vartheta) + 725*Cos(3*vartheta) - 340*Cos(4*vartheta) + 153*Cos(5*vartheta))*Power(Sin(vartheta/2.),2))/64.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(1235/Pi)*Power(Cos(vartheta/2.),7)*(427 - 672*Cos(vartheta) + 588*Cos(2*vartheta) - 272*Cos(3*vartheta) + 153*Cos(4*vartheta))*Power(Sin(vartheta/2.),3))/32.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = (Sqrt(741/Pi)*Power(Cos(vartheta/2.),8)*(-62 + 149*Cos(vartheta) - 68*Cos(2*vartheta) + 51*Cos(3*vartheta))*Power(Sin(vartheta/2.),4))/4.;
      Phi = 6*varphi;
      break;
    case 7:
      Amp = -(Sqrt(247/Pi)*Power(Cos(vartheta/2.),9)*(151 - 136*Cos(vartheta) + 153*Cos(2*vartheta))*Power(Sin(vartheta/2.),5))/4.;
      Phi = 7*varphi;
      break;
    case 8:
      Amp = Sqrt(8398/Pi)*Power(Cos(vartheta/2.),10)*(-2 + 9*Cos(vartheta))*Power(Sin(vartheta/2.),6);
      Phi = 8*varphi;
      break;
    case 9:
      Amp = -6*Sqrt(4199/Pi)*Power(Cos(vartheta/2.),11)*Power(Sin(vartheta/2.),7);
      Phi = 9*varphi;
      break;
    } // switch(M)
    
  case 10:
    switch(M) {
    case -10:
      Amp = 3*Sqrt(146965/(2.*Pi))*Power(Cos(vartheta/2.),8)*Power(Sin(vartheta/2.),12);
      Phi = -10*varphi;
      break;
    case -9:
      Amp = 3*Sqrt(29393/(2.*Pi))*Power(Cos(vartheta/2.),7)*(1 + 5*Cos(vartheta))*Power(Sin(vartheta/2.),11);
      Phi = -9*varphi;
      break;
    case -8:
      Amp = (3*Sqrt(1547/Pi)*Power(Cos(vartheta/2.),6)*(93 + 76*Cos(vartheta) + 95*Cos(2*vartheta))*Power(Sin(vartheta/2.),10))/8.;
      Phi = -8*varphi;
      break;
    case -7:
      Amp = (Sqrt(4641/(2.*Pi))*Power(Cos(vartheta/2.),5)*(314 + 819*Cos(vartheta) + 342*Cos(2*vartheta) + 285*Cos(3*vartheta))*Power(Sin(vartheta/2.),9))/16.;
      Phi = -7*varphi;
      break;
    case -6:
      Amp = (Sqrt(273/(2.*Pi))*Power(Cos(vartheta/2.),4)*(13159 + 19448*Cos(vartheta) + 18156*Cos(2*vartheta) + 7752*Cos(3*vartheta) + 4845*Cos(4*vartheta))*Power(Sin(vartheta/2.),8))/128.;
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (Sqrt(1365/(2.*Pi))*Power(Cos(vartheta/2.),3)*(3990 + 8162*Cos(vartheta) + 5848*Cos(2*vartheta) + 4437*Cos(3*vartheta) + 1938*Cos(4*vartheta) + 969*Cos(5*vartheta))*Power(Sin(vartheta/2.),7))/128.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (Sqrt(273/Pi)*Power(Cos(vartheta/2.),2)*(35126 + 63960*Cos(vartheta) + 55875*Cos(2*vartheta) + 39100*Cos(3*vartheta) + 26010*Cos(4*vartheta) + 11628*Cos(5*vartheta) + 4845*Cos(6*vartheta))*Power(Sin(vartheta/2.),6))/1024.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (Sqrt(273/(2.*Pi))*Cos(vartheta/2.)*(52052 + 100639*Cos(vartheta) + 87010*Cos(2*vartheta) + 69685*Cos(3*vartheta) + 48076*Cos(4*vartheta) + 29631*Cos(5*vartheta) + 13566*Cos(6*vartheta) + 4845*Cos(7*vartheta))*Power(Sin(vartheta/2.),5))/2048.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(21/Pi)*(919611 + 1777776*Cos(vartheta) + 1609608*Cos(2*vartheta) + 1349712*Cos(3*vartheta) + 1041404*Cos(4*vartheta) + 717808*Cos(5*vartheta) + 429624*Cos(6*vartheta) + 201552*Cos(7*vartheta) + 62985*Cos(8*vartheta))*Power(Sin(vartheta/2.),4))/32768.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (3*Sqrt(7/Pi)*Cos(vartheta/2.)*(92169 + 168168*Cos(vartheta) + 168168*Cos(2*vartheta) + 137592*Cos(3*vartheta) + 124852*Cos(4*vartheta) + 86632*Cos(5*vartheta) + 68952*Cos(6*vartheta) + 33592*Cos(7*vartheta) + 20995*Cos(8*vartheta))*Power(Sin(vartheta/2.),3))/16384.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (3*Sqrt(385/(2.*Pi))*(8085 + 15288*Cos(2*vartheta) + 12740*Cos(4*vartheta) + 8840*Cos(6*vartheta) + 4199*Cos(8*vartheta))*Power(Sin(vartheta),2))/65536.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (3*Sqrt(7/Pi)*Power(Cos(vartheta/2.),3)*(92169 - 168168*Cos(vartheta) + 168168*Cos(2*vartheta) - 137592*Cos(3*vartheta) + 124852*Cos(4*vartheta) - 86632*Cos(5*vartheta) + 68952*Cos(6*vartheta) - 33592*Cos(7*vartheta) + 20995*Cos(8*vartheta))*Sin(vartheta/2.))/16384.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(21/Pi)*Power(Cos(vartheta/2.),4)*(919611 - 1777776*Cos(vartheta) + 1609608*Cos(2*vartheta) - 1349712*Cos(3*vartheta) + 1041404*Cos(4*vartheta) - 717808*Cos(5*vartheta) + 429624*Cos(6*vartheta) - 201552*Cos(7*vartheta) + 62985*Cos(8*vartheta)))/32768.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = -(Sqrt(273/(2.*Pi))*Power(Cos(vartheta/2.),5)*(-52052 + 100639*Cos(vartheta) - 87010*Cos(2*vartheta) + 69685*Cos(3*vartheta) - 48076*Cos(4*vartheta) + 29631*Cos(5*vartheta) - 13566*Cos(6*vartheta) + 4845*Cos(7*vartheta))*Sin(vartheta/2.))/2048.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (Sqrt(273/Pi)*Power(Cos(vartheta/2.),6)*(35126 - 63960*Cos(vartheta) + 55875*Cos(2*vartheta) - 39100*Cos(3*vartheta) + 26010*Cos(4*vartheta) - 11628*Cos(5*vartheta) + 4845*Cos(6*vartheta))*Power(Sin(vartheta/2.),2))/1024.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(1365/(2.*Pi))*Power(Cos(vartheta/2.),7)*(-3990 + 8162*Cos(vartheta) - 5848*Cos(2*vartheta) + 4437*Cos(3*vartheta) - 1938*Cos(4*vartheta) + 969*Cos(5*vartheta))*Power(Sin(vartheta/2.),3))/128.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = (Sqrt(273/(2.*Pi))*Power(Cos(vartheta/2.),8)*(13159 - 19448*Cos(vartheta) + 18156*Cos(2*vartheta) - 7752*Cos(3*vartheta) + 4845*Cos(4*vartheta))*Power(Sin(vartheta/2.),4))/128.;
      Phi = 6*varphi;
      break;
    case 7:
      Amp = -(Sqrt(4641/(2.*Pi))*Power(Cos(vartheta/2.),9)*(-314 + 819*Cos(vartheta) - 342*Cos(2*vartheta) + 285*Cos(3*vartheta))*Power(Sin(vartheta/2.),5))/16.;
      Phi = 7*varphi;
      break;
    case 8:
      Amp = (3*Sqrt(1547/Pi)*Power(Cos(vartheta/2.),10)*(93 - 76*Cos(vartheta) + 95*Cos(2*vartheta))*Power(Sin(vartheta/2.),6))/8.;
      Phi = 8*varphi;
      break;
    case 9:
      Amp = -3*Sqrt(29393/(2.*Pi))*Power(Cos(vartheta/2.),11)*(-1 + 5*Cos(vartheta))*Power(Sin(vartheta/2.),7);
      Phi = 9*varphi;
      break;
    case 10:
      Amp = 3*Sqrt(146965/(2.*Pi))*Power(Cos(vartheta/2.),12)*Power(Sin(vartheta/2.),8);
      Phi = 10*varphi;
      break;
    } // switch(M)
    
  case 11:
    switch(M) {
    case -11:
      Amp = Sqrt(2860165/Pi)*Power(Cos(vartheta/2.),9)*Power(Sin(vartheta/2.),13);
      Phi = -11*varphi;
      break;
    case -10:
      Amp = Sqrt(260015/(2.*Pi))*Power(Cos(vartheta/2.),8)*(2 + 11*Cos(vartheta))*Power(Sin(vartheta/2.),12);
      Phi = -10*varphi;
      break;
    case -9:
      Amp = (Sqrt(111435/Pi)*Power(Cos(vartheta/2.),7)*(75 + 56*Cos(vartheta) + 77*Cos(2*vartheta))*Power(Sin(vartheta/2.),11))/8.;
      Phi = -9*varphi;
      break;
    case -8:
      Amp = (Sqrt(7429/Pi)*Power(Cos(vartheta/2.),6)*(388 + 1095*Cos(vartheta) + 420*Cos(2*vartheta) + 385*Cos(3*vartheta))*Power(Sin(vartheta/2.),10))/16.;
      Phi = -8*varphi;
      break;
    case -7:
      Amp = (Sqrt(391/Pi)*Power(Cos(vartheta/2.),5)*(19529 + 27056*Cos(vartheta) + 26980*Cos(2*vartheta) + 10640*Cos(3*vartheta) + 7315*Cos(4*vartheta))*Power(Sin(vartheta/2.),9))/128.;
      Phi = -7*varphi;
      break;
    case -6:
      Amp = (3*Sqrt(1955/(2.*Pi))*Power(Cos(vartheta/2.),4)*(5644 + 12078*Cos(vartheta) + 8208*Cos(2*vartheta) + 6555*Cos(3*vartheta) + 2660*Cos(4*vartheta) + 1463*Cos(5*vartheta))*Power(Sin(vartheta/2.),8))/256.;
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (Sqrt(345/Pi)*Power(Cos(vartheta/2.),3)*(178010 + 314160*Cos(vartheta) + 281673*Cos(2*vartheta) + 188632*Cos(3*vartheta) + 129846*Cos(4*vartheta) + 54264*Cos(5*vartheta) + 24871*Cos(6*vartheta))*Power(Sin(vartheta/2.),7))/2048.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (Sqrt(2415/Pi)*Power(Cos(vartheta/2.),2)*(37960 + 74347*Cos(vartheta) + 62764*Cos(2*vartheta) + 50609*Cos(3*vartheta) + 33592*Cos(4*vartheta) + 20995*Cos(5*vartheta) + 9044*Cos(6*vartheta) + 3553*Cos(7*vartheta))*Power(Sin(vartheta/2.),6))/2048.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (3*Sqrt(161/(2.*Pi))*Cos(vartheta/2.)*(274703 + 526240*Cos(vartheta) + 474760*Cos(2*vartheta) + 388960*Cos(3*vartheta) + 296140*Cos(4*vartheta) + 196384*Cos(5*vartheta) + 116280*Cos(6*vartheta) + 51680*Cos(7*vartheta) + 17765*Cos(8*vartheta))*Power(Sin(vartheta/2.),5))/16384.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (Sqrt(23/Pi)*(2414412 + 4702698*Cos(vartheta) + 4324320*Cos(2*vartheta) + 3751020*Cos(3*vartheta) + 3033072*Cos(4*vartheta) + 2266236*Cos(5*vartheta) + 1519392*Cos(6*vartheta) + 886635*Cos(7*vartheta) + 406980*Cos(8*vartheta) + 124355*Cos(9*vartheta))*Power(Sin(vartheta/2.),4))/65536.;
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (Sqrt(1495/(2.*Pi))*Cos(vartheta/2.)*(126126 + 261954*Cos(vartheta) + 232848*Cos(2*vartheta) + 224028*Cos(3*vartheta) + 179928*Cos(4*vartheta) + 158508*Cos(5*vartheta) + 108528*Cos(6*vartheta) + 84303*Cos(7*vartheta) + 40698*Cos(8*vartheta) + 24871*Cos(9*vartheta))*Power(Sin(vartheta/2.),3))/65536.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (Sqrt(49335/(2.*Pi))*Cos(vartheta)*(2719 + 4264*Cos(2*vartheta) + 4556*Cos(4*vartheta) + 2584*Cos(6*vartheta) + 2261*Cos(8*vartheta))*Power(Sin(vartheta),2))/65536.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (Sqrt(1495/(2.*Pi))*Power(Cos(vartheta/2.),3)*(-126126 + 261954*Cos(vartheta) - 232848*Cos(2*vartheta) + 224028*Cos(3*vartheta) - 179928*Cos(4*vartheta) + 158508*Cos(5*vartheta) - 108528*Cos(6*vartheta) + 84303*Cos(7*vartheta) - 40698*Cos(8*vartheta) + 24871*Cos(9*vartheta))*Sin(vartheta/2.))/65536.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (Sqrt(23/Pi)*Power(Cos(vartheta/2.),4)*(-2414412 + 4702698*Cos(vartheta) - 4324320*Cos(2*vartheta) + 3751020*Cos(3*vartheta) - 3033072*Cos(4*vartheta) + 2266236*Cos(5*vartheta) - 1519392*Cos(6*vartheta) + 886635*Cos(7*vartheta) - 406980*Cos(8*vartheta) + 124355*Cos(9*vartheta)))/65536.;
      Phi = 2*varphi;
      break;
    case 3:
      Amp = (-3*Sqrt(161/(2.*Pi))*Power(Cos(vartheta/2.),5)*(274703 - 526240*Cos(vartheta) + 474760*Cos(2*vartheta) - 388960*Cos(3*vartheta) + 296140*Cos(4*vartheta) - 196384*Cos(5*vartheta) + 116280*Cos(6*vartheta) - 51680*Cos(7*vartheta) + 17765*Cos(8*vartheta))*Sin(vartheta/2.))/16384.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (Sqrt(2415/Pi)*Power(Cos(vartheta/2.),6)*(-37960 + 74347*Cos(vartheta) - 62764*Cos(2*vartheta) + 50609*Cos(3*vartheta) - 33592*Cos(4*vartheta) + 20995*Cos(5*vartheta) - 9044*Cos(6*vartheta) + 3553*Cos(7*vartheta))*Power(Sin(vartheta/2.),2))/2048.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = -(Sqrt(345/Pi)*Power(Cos(vartheta/2.),7)*(178010 - 314160*Cos(vartheta) + 281673*Cos(2*vartheta) - 188632*Cos(3*vartheta) + 129846*Cos(4*vartheta) - 54264*Cos(5*vartheta) + 24871*Cos(6*vartheta))*Power(Sin(vartheta/2.),3))/2048.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = (3*Sqrt(1955/(2.*Pi))*Power(Cos(vartheta/2.),8)*(-5644 + 12078*Cos(vartheta) - 8208*Cos(2*vartheta) + 6555*Cos(3*vartheta) - 2660*Cos(4*vartheta) + 1463*Cos(5*vartheta))*Power(Sin(vartheta/2.),4))/256.;
      Phi = 6*varphi;
      break;
    case 7:
      Amp = -(Sqrt(391/Pi)*Power(Cos(vartheta/2.),9)*(19529 - 27056*Cos(vartheta) + 26980*Cos(2*vartheta) - 10640*Cos(3*vartheta) + 7315*Cos(4*vartheta))*Power(Sin(vartheta/2.),5))/128.;
      Phi = 7*varphi;
      break;
    case 8:
      Amp = (Sqrt(7429/Pi)*Power(Cos(vartheta/2.),10)*(-388 + 1095*Cos(vartheta) - 420*Cos(2*vartheta) + 385*Cos(3*vartheta))*Power(Sin(vartheta/2.),6))/16.;
      Phi = 8*varphi;
      break;
    case 9:
      Amp = -(Sqrt(111435/Pi)*Power(Cos(vartheta/2.),11)*(75 - 56*Cos(vartheta) + 77*Cos(2*vartheta))*Power(Sin(vartheta/2.),7))/8.;
      Phi = 9*varphi;
      break;
    case 10:
      Amp = Sqrt(260015/(2.*Pi))*Power(Cos(vartheta/2.),12)*(-2 + 11*Cos(vartheta))*Power(Sin(vartheta/2.),8);
      Phi = 10*varphi;
      break;
    case 11:
      Amp = -(Sqrt(2860165/Pi)*Power(Cos(vartheta/2.),13)*Power(Sin(vartheta/2.),9));
      Phi = 11*varphi;
      break;
    } // switch(M)
    
  case 12:
    switch(M) {
    case -12:
      Amp = 5*Sqrt(490314/Pi)*Power(Cos(vartheta/2.),10)*Power(Sin(vartheta/2.),14);
      Phi = -12*varphi;
      break;
    case -11:
      Amp = 5*Sqrt(81719/Pi)*Power(Cos(vartheta/2.),9)*(1 + 6*Cos(vartheta))*Power(Sin(vartheta/2.),13);
      Phi = -11*varphi;
      break;
    case -10:
      Amp = (5*Sqrt(3553/(2.*Pi))*Power(Cos(vartheta/2.),8)*(67 + 46*Cos(vartheta) + 69*Cos(2*vartheta))*Power(Sin(vartheta/2.),12))/2.;
      Phi = -10*varphi;
      break;
    case -9:
      Amp = (5*Sqrt(969/Pi)*Power(Cos(vartheta/2.),7)*(235 + 715*Cos(vartheta) + 253*Cos(2*vartheta) + 253*Cos(3*vartheta))*Power(Sin(vartheta/2.),11))/8.;
      Phi = -9*varphi;
      break;
    case -8:
      Amp = (5*Sqrt(2261/Pi)*Power(Cos(vartheta/2.),6)*(2005 + 2604*Cos(vartheta) + 2772*Cos(2*vartheta) + 1012*Cos(3*vartheta) + 759*Cos(4*vartheta))*Power(Sin(vartheta/2.),10))/64.;
      Phi = -8*varphi;
      break;
    case -7:
      Amp = (5*Sqrt(2261/Pi)*Power(Cos(vartheta/2.),5)*(2755 + 6190*Cos(vartheta) + 3980*Cos(2*vartheta) + 3355*Cos(3*vartheta) + 1265*Cos(4*vartheta) + 759*Cos(5*vartheta))*Power(Sin(vartheta/2.),9))/128.;
      Phi = -7*varphi;
      break;
    case -6:
      Amp = (5*Sqrt(357/(2.*Pi))*Power(Cos(vartheta/2.),4)*(34170 + 58140*Cos(vartheta) + 53865*Cos(2*vartheta) + 34390*Cos(3*vartheta) + 24662*Cos(4*vartheta) + 9614*Cos(5*vartheta) + 4807*Cos(6*vartheta))*Power(Sin(vartheta/2.),8))/512.;
      Phi = -6*varphi;
      break;
    case -5:
      Amp = (5*Sqrt(51/Pi)*Power(Cos(vartheta/2.),3)*(152150 + 303975*Cos(vartheta) + 249375*Cos(2*vartheta) + 204421*Cos(3*vartheta) + 130074*Cos(4*vartheta) + 83391*Cos(5*vartheta) + 33649*Cos(6*vartheta) + 14421*Cos(7*vartheta))*Power(Sin(vartheta/2.),7))/2048.;
      Phi = -5*varphi;
      break;
    case -4:
      Amp = (5*Sqrt(3/(2.*Pi))*Power(Cos(vartheta/2.),2)*(3952975 + 7469800*Cos(vartheta) + 6769672*Cos(2*vartheta) + 5408312*Cos(3*vartheta) + 4115020*Cos(4*vartheta) + 2622760*Cos(5*vartheta) + 1563320*Cos(6*vartheta) + 653752*Cos(7*vartheta) + 245157*Cos(8*vartheta))*Power(Sin(vartheta/2.),6))/16384.;
      Phi = -4*varphi;
      break;
    case -3:
      Amp = (5*Sqrt(3/(2.*Pi))*Cos(vartheta/2.)*(1748175 + 3408834*Cos(vartheta) + 3092232*Cos(2*vartheta) + 2654652*Cos(3*vartheta) + 2089164*Cos(4*vartheta) + 1531020*Cos(5*vartheta) + 984504*Cos(6*vartheta) + 564927*Cos(7*vartheta) + 245157*Cos(8*vartheta) + 81719*Cos(9*vartheta))*Power(Sin(vartheta/2.),5))/16384.;
      Phi = -3*varphi;
      break;
    case -2:
      Amp = (5*(6205914 + 12123540*Cos(vartheta) + 11312730*Cos(2*vartheta) + 10030680*Cos(3*vartheta) + 8427240*Cos(4*vartheta) + 6627960*Cos(5*vartheta) + 4830465*Cos(6*vartheta) + 3168630*Cos(7*vartheta) + 1812030*Cos(8*vartheta) + 817190*Cos(9*vartheta) + 245157*Cos(10*vartheta))*Power(Sin(vartheta/2.),4))/(131072.*Sqrt(Pi));
      Phi = -2*varphi;
      break;
    case -1:
      Amp = (5*Sqrt(77/(2.*Pi))*Cos(vartheta/2.)*(144144 + 270270*Cos(vartheta) + 270270*Cos(2*vartheta) + 235620*Cos(3*vartheta) + 220320*Cos(4*vartheta) + 174420*Cos(5*vartheta) + 150195*Cos(6*vartheta) + 101745*Cos(7*vartheta) + 77520*Cos(8*vartheta) + 37145*Cos(9*vartheta) + 22287*Cos(10*vartheta))*Power(Sin(vartheta/2.),3))/65536.;
      Phi = -1*varphi;
      break;
    case 0:
      Amp = (5*Sqrt(3003/(2.*Pi))*(18018 + 34650*Cos(2*vartheta) + 30600*Cos(4*vartheta) + 24225*Cos(6*vartheta) + 16150*Cos(8*vartheta) + 7429*Cos(10*vartheta))*Power(Sin(vartheta),2))/524288.;
      Phi = 0*varphi;
      break;
    case 1:
      Amp = (5*Sqrt(77/(2.*Pi))*Power(Cos(vartheta/2.),3)*(144144 - 270270*Cos(vartheta) + 270270*Cos(2*vartheta) - 235620*Cos(3*vartheta) + 220320*Cos(4*vartheta) - 174420*Cos(5*vartheta) + 150195*Cos(6*vartheta) - 101745*Cos(7*vartheta) + 77520*Cos(8*vartheta) - 37145*Cos(9*vartheta) + 22287*Cos(10*vartheta))*Sin(vartheta/2.))/65536.;
      Phi = 1*varphi;
      break;
    case 2:
      Amp = (5*Power(Cos(vartheta/2.),4)*(6205914 - 12123540*Cos(vartheta) + 11312730*Cos(2*vartheta) - 10030680*Cos(3*vartheta) + 8427240*Cos(4*vartheta) - 6627960*Cos(5*vartheta) + 4830465*Cos(6*vartheta) - 3168630*Cos(7*vartheta) + 1812030*Cos(8*vartheta) - 817190*Cos(9*vartheta) + 245157*Cos(10*vartheta)))/(131072.*Sqrt(Pi));
      Phi = 2*varphi;
      break;
    case 3:
      Amp = (-5*Sqrt(3/(2.*Pi))*Power(Cos(vartheta/2.),5)*(-1748175 + 3408834*Cos(vartheta) - 3092232*Cos(2*vartheta) + 2654652*Cos(3*vartheta) - 2089164*Cos(4*vartheta) + 1531020*Cos(5*vartheta) - 984504*Cos(6*vartheta) + 564927*Cos(7*vartheta) - 245157*Cos(8*vartheta) + 81719*Cos(9*vartheta))*Sin(vartheta/2.))/16384.;
      Phi = 3*varphi;
      break;
    case 4:
      Amp = (5*Sqrt(3/(2.*Pi))*Power(Cos(vartheta/2.),6)*(3952975 - 7469800*Cos(vartheta) + 6769672*Cos(2*vartheta) - 5408312*Cos(3*vartheta) + 4115020*Cos(4*vartheta) - 2622760*Cos(5*vartheta) + 1563320*Cos(6*vartheta) - 653752*Cos(7*vartheta) + 245157*Cos(8*vartheta))*Power(Sin(vartheta/2.),2))/16384.;
      Phi = 4*varphi;
      break;
    case 5:
      Amp = (-5*Sqrt(51/Pi)*Power(Cos(vartheta/2.),7)*(-152150 + 303975*Cos(vartheta) - 249375*Cos(2*vartheta) + 204421*Cos(3*vartheta) - 130074*Cos(4*vartheta) + 83391*Cos(5*vartheta) - 33649*Cos(6*vartheta) + 14421*Cos(7*vartheta))*Power(Sin(vartheta/2.),3))/2048.;
      Phi = 5*varphi;
      break;
    case 6:
      Amp = (5*Sqrt(357/(2.*Pi))*Power(Cos(vartheta/2.),8)*(34170 - 58140*Cos(vartheta) + 53865*Cos(2*vartheta) - 34390*Cos(3*vartheta) + 24662*Cos(4*vartheta) - 9614*Cos(5*vartheta) + 4807*Cos(6*vartheta))*Power(Sin(vartheta/2.),4))/512.;
      Phi = 6*varphi;
      break;
    case 7:
      Amp = (-5*Sqrt(2261/Pi)*Power(Cos(vartheta/2.),9)*(-2755 + 6190*Cos(vartheta) - 3980*Cos(2*vartheta) + 3355*Cos(3*vartheta) - 1265*Cos(4*vartheta) + 759*Cos(5*vartheta))*Power(Sin(vartheta/2.),5))/128.;
      Phi = 7*varphi;
      break;
    case 8:
      Amp = (5*Sqrt(2261/Pi)*Power(Cos(vartheta/2.),10)*(2005 - 2604*Cos(vartheta) + 2772*Cos(2*vartheta) - 1012*Cos(3*vartheta) + 759*Cos(4*vartheta))*Power(Sin(vartheta/2.),6))/64.;
      Phi = 8*varphi;
      break;
    case 9:
      Amp = (-5*Sqrt(969/Pi)*Power(Cos(vartheta/2.),11)*(-235 + 715*Cos(vartheta) - 253*Cos(2*vartheta) + 253*Cos(3*vartheta))*Power(Sin(vartheta/2.),7))/8.;
      Phi = 9*varphi;
      break;
    case 10:
      Amp = (5*Sqrt(3553/(2.*Pi))*Power(Cos(vartheta/2.),12)*(67 - 46*Cos(vartheta) + 69*Cos(2*vartheta))*Power(Sin(vartheta/2.),8))/2.;
      Phi = 10*varphi;
      break;
    case 11:
      Amp = -5*Sqrt(81719/Pi)*Power(Cos(vartheta/2.),13)*(-1 + 6*Cos(vartheta))*Power(Sin(vartheta/2.),9);
      Phi = 11*varphi;
      break;
    case 12:
      Amp = 5*Sqrt(490314/Pi)*Power(Cos(vartheta/2.),14)*Power(Sin(vartheta/2.),10);
      Phi = 12*varphi;
      break;
    } // switch(M)
    
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
