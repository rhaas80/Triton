#include "WaveformAmplitudes.hpp"

#include <cstdlib>
#include <cmath>
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
using namespace WaveformUtilities;
using std::vector;

#define Log std::log
#define Power std::pow
#define Pi M_PI
#define Sqrt std::sqrt

WaveformUtilities::WaveformAmplitudes::WaveformAmplitudes(const double idelta, const double ichis)
  : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis),
    NormalizationFactor(2*nu*sqrt(16*M_PI/5.0)),
    Hhat_L2_M2_Re_v0(1),
    Hhat_L2_M2_Re_v2((-107 + 55*nu)/42.),
    Hhat_L2_M2_Re_v3(2*Pi),
    Hhat_L2_M2_Re_v4((-2173 - 7483*nu + 2047*Power(nu,2))/1512.),
    Hhat_L2_M2_Re_v5(((-107 + 34*nu)*Pi)/21.),
    Hhat_L2_M2_Im_v5(-24*nu),
    Hhat_L2_M2_Re_v6(41.78634662956092 - (856*EulerGamma)/105. - (20261*Power(nu,2))/2772. + (114635*Power(nu,3))/99792. + (2*Power(Pi,2))/3. + (41*nu*(-13570 + 693*Power(Pi,2)))/66528. - (428*Log(16))/105.),
    Hhat_L2_M2_Im_v6((428*Pi)/105.),
    Hhat_L2_M2_Re_v6lnv(-8.152380952380952),
    Hhat_L2_M1_Im_v1(delta/3.),
    Hhat_L2_M1_Im_v3((delta*(-17 + 20*nu))/84.),
    Hhat_L2_M1_Re_v4((delta*(1 + Log(16)))/6.),
    Hhat_L2_M1_Im_v4((delta*Pi)/3.),
    Hhat_L2_M1_Im_v5((delta*(-172 - 2036*nu + 237*Power(nu,2)))/1512.),
    Hhat_L2_M1_Re_v6((delta*(2*nu*(995 + 36*Log(2)) - 51*(1 + Log(16))))/504.),
    Hhat_L2_M1_Im_v6((delta*(-17 + 6*nu)*Pi)/84.),
    Hhat_L2_M0_Re_v0(-5/(14.*Sqrt(6))),
    Hhat_L3_M3_Im_v1((-3*Sqrt(1.0714285714285714)*delta)/4.),
    Hhat_L3_M3_Im_v3((-3*Sqrt(1.0714285714285714)*delta*(-2 + nu))/2.),
    Hhat_L3_M3_Re_v4((9*Sqrt(0.04285714285714286)*delta*(-7 + 10*Log(1.5)))/4.),
    Hhat_L3_M3_Im_v4((-9*Sqrt(1.0714285714285714)*delta*Pi)/4.),
    Hhat_L3_M3_Im_v5(-(Sqrt(0.04285714285714286)*delta*(369 - 3676*nu + 887*Power(nu,2)))/88.),
    Hhat_L3_M3_Re_v6((delta*(-2916*(-7 + 10*Log(1.5)) + nu*(-48103 + 10935*Log(1.5))))/(108.*Sqrt(210))),
    Hhat_L3_M3_Im_v6((9*Sqrt(1.0714285714285714)*delta*(8 - 3*nu)*Pi)/8.),
    Hhat_L3_M2_Re_v2((Sqrt(0.7142857142857143)*(1 - 3*nu))/3.),
    Hhat_L3_M2_Re_v4(-(193 - 725*nu + 365*Power(nu,2))/(54.*Sqrt(35))),
    Hhat_L3_M2_Re_v5((2*Sqrt(0.7142857142857143)*(1 - 3*nu)*Pi)/3.),
    Hhat_L3_M2_Im_v5((-5 + 22*nu)/Sqrt(35)),
    Hhat_L3_M2_Re_v6(-(1451 + 17387*nu - 100026*Power(nu,2) + 16023*Power(nu,3))/(2376.*Sqrt(35))),
    Hhat_L3_M1_Im_v1(delta/(12.*Sqrt(14))),
    Hhat_L3_M1_Im_v3(-(delta*(4 + nu))/(18.*Sqrt(14))),
    Hhat_L3_M1_Re_v4((delta*(7 + Log(1024)))/(60.*Sqrt(14))),
    Hhat_L3_M1_Im_v4((delta*Pi)/(12.*Sqrt(14))),
    Hhat_L3_M1_Im_v5(-(delta*(-607 + 272*nu + 247*Power(nu,2)))/(2376.*Sqrt(14))),
    Hhat_L3_M1_Re_v6((delta*(-56 + nu - 80*Log(2) - 35*nu*Log(2)))/(180.*Sqrt(14))),
    Hhat_L3_M1_Im_v6(-(delta*(16 + 7*nu)*Pi)/(72.*Sqrt(14))),
    Hhat_L3_M0_Im_v5((-2*Sqrt(0.8571428571428571)*nu)/5.),
    Hhat_L4_M4_Re_v2((8*Sqrt(0.7142857142857143)*(-1 + 3*nu))/9.),
    Hhat_L4_M4_Re_v4((4*(1779 - 6365*nu + 2625*Power(nu,2)))/(297.*Sqrt(35))),
    Hhat_L4_M4_Re_v5((32*Sqrt(0.7142857142857143)*(-1 + 3*nu)*Pi)/9.),
    Hhat_L4_M4_Im_v5((336 - 320*Log(2) + nu*(-1193 + 960*Log(2)))/(9.*Sqrt(35))),
    Hhat_L4_M4_Re_v6((-9618039 + 68551497*nu - 113096830*Power(nu,2) + 23740185*Power(nu,3))/(405405.*Sqrt(35))),
    Hhat_L4_M3_Im_v3((9*delta*(-1 + 2*nu))/(4.*Sqrt(70))),
    Hhat_L4_M3_Im_v5((3*delta*(468 - 1267*nu + 524*Power(nu,2)))/(176.*Sqrt(70))),
    Hhat_L4_M3_Re_v6((delta*(-5184 + 16301*nu + 4860*Log(1.5) - 9720*nu*Log(1.5)))/(360.*Sqrt(70))),
    Hhat_L4_M3_Im_v6((27*delta*(-1 + 2*nu)*Pi)/(4.*Sqrt(70))),
    Hhat_L4_M2_Re_v2((Sqrt(5)*(1 - 3*nu))/63.),
    Hhat_L4_M2_Re_v4(-(1311 - 4025*nu + 285*Power(nu,2))/(4158.*Sqrt(5))),
    Hhat_L4_M2_Re_v5((2*Sqrt(5)*(1 - 3*nu)*Pi)/63.),
    Hhat_L4_M2_Im_v5((-1 + 4*nu)/(3.*Sqrt(5))),
    Hhat_L4_M2_Re_v6((9342351 - 38225313*nu + 28031710*Power(nu,2) + 2707215*Power(nu,3))/(2.270268e7*Sqrt(5))),
    Hhat_L4_M1_Im_v3((delta*(1 - 2*nu))/(84.*Sqrt(10))),
    Hhat_L4_M1_Im_v5(-(delta*(404 - 1011*nu + 332*Power(nu,2)))/(11088.*Sqrt(10))),
    Hhat_L4_M1_Re_v6((delta*(64 + 60*Log(2) - nu*(1661 + 120*Log(2))))/(2520.*Sqrt(10))),
    Hhat_L4_M1_Im_v6((delta*(1 - 2*nu)*Pi)/(84.*Sqrt(10))),
    Hhat_L4_M0_Re_v0(-1/(504.*Sqrt(2))),
    Hhat_L5_M5_Im_v3((-625*delta*(-1 + 2*nu))/(96.*Sqrt(66))),
    Hhat_L5_M5_Im_v5((-625*delta*(263 - 688*nu + 256*Power(nu,2)))/(3744.*Sqrt(66))),
    Hhat_L5_M5_Re_v6((delta*(3125*(181 - 140*Log(2.5)) + 28*nu*(-52917 + 31250*Log(2.5))))/(6720.*Sqrt(66))),
    Hhat_L5_M5_Im_v6((-3125*delta*(-1 + 2*nu)*Pi)/(96.*Sqrt(66))),
    Hhat_L5_M4_Re_v4((-32*(1 - 5*nu + 5*Power(nu,2)))/(9.*Sqrt(165))),
    Hhat_L5_M4_Re_v6((-16*(-4451 + 25333*nu - 36470*Power(nu,2) + 11865*Power(nu,3)))/(4095.*Sqrt(165))),
    Hhat_L5_M3_Im_v3((9*Sqrt(0.02727272727272727)*delta*(-1 + 2*nu))/32.),
    Hhat_L5_M3_Im_v5((3*Sqrt(0.02727272727272727)*delta*(207 - 464*nu + 88*Power(nu,2)))/416.),
    Hhat_L5_M3_Re_v6((delta*(2187*(-181 + 140*Log(1.5)) - 28*nu*(-41851 + 21870*Log(1.5))))/(60480.*Sqrt(330))),
    Hhat_L5_M3_Im_v6((27*Sqrt(0.02727272727272727)*delta*(-1 + 2*nu)*Pi)/32.),
    Hhat_L5_M2_Re_v4((2*(1 - 5*nu + 5*Power(nu,2)))/(27.*Sqrt(55))),
    Hhat_L5_M2_Re_v6((-3911 + 21553*nu - 28910*Power(nu,2) + 8085*Power(nu,3))/(12285.*Sqrt(55))),
    Hhat_L5_M1_Im_v3((delta*(1 - 2*nu))/(288.*Sqrt(385))),
    Hhat_L5_M1_Im_v5(-(delta*(179 - 352*nu + 4*Power(nu,2)))/(11232.*Sqrt(385))),
    Hhat_L5_M1_Re_v6((delta*(181 + 140*Log(2) - 28*nu*(313 + Log(1024))))/(20160.*Sqrt(385))),
    Hhat_L5_M1_Im_v6((delta*(1 - 2*nu)*Pi)/(288.*Sqrt(385))),
    Hhat_L6_M6_Re_v4((54*(1 - 5*nu + 5*Power(nu,2)))/(5.*Sqrt(143))),
    Hhat_L6_M6_Re_v6((27*(-113 + 637*nu - 896*Power(nu,2) + 273*Power(nu,3)))/(35.*Sqrt(143))),
    Hhat_L6_M5_Im_v5((3125*delta*(1 - 4*nu + 3*Power(nu,2)))/(504.*Sqrt(429))),
    Hhat_L6_M4_Re_v4((-128*Sqrt(0.05128205128205128)*(1 - 5*nu + 5*Power(nu,2)))/495.),
    Hhat_L6_M4_Re_v6((-64*Sqrt(0.05128205128205128)*(-93 + 497*nu - 616*Power(nu,2) + 133*Power(nu,3)))/3465.),
    Hhat_L6_M3_Im_v5((-81*delta*(1 - 4*nu + 3*Power(nu,2)))/(616.*Sqrt(65))),
    Hhat_L6_M2_Re_v4((2*(1 - 5*nu + 5*Power(nu,2)))/(297.*Sqrt(65))),
    Hhat_L6_M2_Re_v6((-81 + 413*nu - 448*Power(nu,2) + 49*Power(nu,3))/(2079.*Sqrt(65))),
    Hhat_L6_M1_Im_v5((delta*(1 - 4*nu + 3*Power(nu,2)))/(8316.*Sqrt(26))),
    Hhat_L7_M7_Im_v5((-16807*Sqrt(0.008158508158508158)*delta*(1 - 4*nu + 3*Power(nu,2)))/1440.),
    Hhat_L7_M6_Re_v6((-81*Sqrt(0.02097902097902098)*(-1 + 7*nu - 14*Power(nu,2) + 7*Power(nu,3)))/35.),
    Hhat_L7_M5_Im_v5((15625*delta*(1 - 4*nu + 3*Power(nu,2)))/(26208.*Sqrt(66))),
    Hhat_L7_M4_Re_v6((128*Sqrt(0.06060606060606061)*(-1 + 7*nu - 14*Power(nu,2) + 7*Power(nu,3)))/1365.),
    Hhat_L7_M3_Im_v5((-243*Sqrt(1.5)*delta*(1 - 4*nu + 3*Power(nu,2)))/160160.),
    Hhat_L7_M2_Re_v6((1 - 7*nu + 14*Power(nu,2) - 7*Power(nu,3))/(3003.*Sqrt(3))),
    Hhat_L7_M1_Im_v5((delta*(1 - 4*nu + 3*Power(nu,2)))/(864864.*Sqrt(2))),
    Hhat_L8_M8_Re_v6((16384*Sqrt(0.000023505905858847036)*(-1 + 7*nu - 14*Power(nu,2) + 7*Power(nu,3)))/63.),
    Hhat_L8_M6_Re_v6((-243*Sqrt(0.00017629429394135277)*(-1 + 7*nu - 14*Power(nu,2) + 7*Power(nu,3)))/35.),
    Hhat_L8_M4_Re_v6((128*Sqrt(0.0106951871657754)*(-1 + 7*nu - 14*Power(nu,2) + 7*Power(nu,3)))/4095.),
    Hhat_L8_M2_Re_v6((1 - 7*nu + 14*Power(nu,2) - 7*Power(nu,3))/(9009.*Sqrt(85)))
{ }



void WaveformUtilities::WaveformAmplitudes::Hhat(const int L, const int M, const double v, double& Re, double& Im) const {
  Re = 0.0;
  Im = 0.0;
  double lnv;
  if(L<2 || L>8 || abs(M)>L) { return; }
  switch(L) {
  case 2:
    switch(abs(M)) {
    case 2:
      lnv = log(v);
      Re = Hhat_L2_M2_Re_v0 + v*v*(Hhat_L2_M2_Re_v2 + v*(Hhat_L2_M2_Re_v3 + v*(Hhat_L2_M2_Re_v4 + v*(Hhat_L2_M2_Re_v5 + v*(Hhat_L2_M2_Re_v6 + lnv*Hhat_L2_M2_Re_v6lnv)))));
      Im = fifth(v)*(Hhat_L2_M2_Im_v5 + v*Hhat_L2_M2_Im_v6);
      break;
    case 1:
      Re = fourth(v)*(Hhat_L2_M1_Re_v4 + v*v*Hhat_L2_M1_Re_v6);
      Im = v*(Hhat_L2_M1_Im_v1 + v*v*(Hhat_L2_M1_Im_v3 + v*(Hhat_L2_M1_Im_v4 + v*(Hhat_L2_M1_Im_v5 + v*Hhat_L2_M1_Im_v6))));
      break;
    case 0:
      Re = Hhat_L2_M0_Re_v0;
      break;
    }
    break;
  case 3:
    switch(abs(M)) {
    case 3:
      Re = fourth(v)*(Hhat_L3_M3_Re_v4 + v*v*Hhat_L3_M3_Re_v6);
      Im = v*(Hhat_L3_M3_Im_v1 + v*v*(Hhat_L3_M3_Im_v3 + v*(Hhat_L3_M3_Im_v4 + v*(Hhat_L3_M3_Im_v5 + v*Hhat_L3_M3_Im_v6))));
      break;
    case 2:
      Re = v*v*(Hhat_L3_M2_Re_v2 + v*v*(Hhat_L3_M2_Re_v4 + v*(Hhat_L3_M2_Re_v5 + v*Hhat_L3_M2_Re_v6)));
      Im = fifth(v)*Hhat_L3_M2_Im_v5;
      break;
    case 1:
      Re = fourth(v)*(Hhat_L3_M1_Re_v4 + v*v*Hhat_L3_M1_Re_v6);
      Im = v*(Hhat_L3_M1_Im_v1 + v*v*(Hhat_L3_M1_Im_v3 + v*(Hhat_L3_M1_Im_v4 + v*(Hhat_L3_M1_Im_v5 + v*Hhat_L3_M1_Im_v6))));
      break;
    case 0:
      Im = fifth(v)*Hhat_L3_M0_Im_v5;
      break;
    }
    break;
  case 4:
    switch(abs(M)) {
    case 4:
      Re = v*v*(Hhat_L4_M4_Re_v2 + v*v*(Hhat_L4_M4_Re_v4 + v*(Hhat_L4_M4_Re_v5 + v*Hhat_L4_M4_Re_v6)));
      Im = fifth(v)*Hhat_L4_M4_Im_v5;
      break;
    case 3:
      Re = sixth(v)*Hhat_L4_M3_Re_v6;
      Im = v*v*v*(Hhat_L4_M3_Im_v3 + v*v*(Hhat_L4_M3_Im_v5 + v*Hhat_L4_M3_Im_v6));
      break;
    case 2:
      Re = v*v*(Hhat_L4_M2_Re_v2 + v*v*(Hhat_L4_M2_Re_v4 + v*(Hhat_L4_M2_Re_v5 + v*Hhat_L4_M2_Re_v6)));
      Im = fifth(v)*Hhat_L4_M2_Im_v5;
      break;
    case 1:
      Re = sixth(v)*Hhat_L4_M1_Re_v6;
      Im = v*v*v*(Hhat_L4_M1_Im_v3 + v*v*(Hhat_L4_M1_Im_v5 + v*Hhat_L4_M1_Im_v6));
      break;
    case 0:
      Re = Hhat_L4_M0_Re_v0;
      break;
    }
    break;
  case 5:
    switch(abs(M)) {
    case 5:
      Re = sixth(v)*Hhat_L5_M5_Re_v6;
      Im = v*v*v*(Hhat_L5_M5_Im_v3 + v*v*(Hhat_L5_M5_Im_v5 + v*Hhat_L5_M5_Im_v6));
      break;
    case 4:
      Re = fourth(v)*(Hhat_L5_M4_Re_v4 + v*v*Hhat_L5_M4_Re_v6);
      break;
    case 3:
      Re = sixth(v)*Hhat_L5_M3_Re_v6;
      Im = v*v*v*(Hhat_L5_M3_Im_v3 + v*v*(Hhat_L5_M3_Im_v5 + v*Hhat_L5_M3_Im_v6));
      break;
    case 2:
      Re = fourth(v)*(Hhat_L5_M2_Re_v4 + v*v*Hhat_L5_M2_Re_v6);
      break;
    case 1:
      Re = sixth(v)*Hhat_L5_M1_Re_v6;
      Im = v*v*v*(Hhat_L5_M1_Im_v3 + v*v*(Hhat_L5_M1_Im_v5 + v*Hhat_L5_M1_Im_v6));
      break;
    case 0:
      break;
    }
    break;
  case 6:
    switch(abs(M)) {
    case 6:
      Re = fourth(v)*(Hhat_L6_M6_Re_v4 + v*v*Hhat_L6_M6_Re_v6);
      break;
    case 5:
      Im = fifth(v)*Hhat_L6_M5_Im_v5;
      break;
    case 4:
      Re = fourth(v)*(Hhat_L6_M4_Re_v4 + v*v*Hhat_L6_M4_Re_v6);
      break;
    case 3:
      Im = fifth(v)*Hhat_L6_M3_Im_v5;
      break;
    case 2:
      Re = fourth(v)*(Hhat_L6_M2_Re_v4 + v*v*Hhat_L6_M2_Re_v6);
      break;
    case 1:
      Im = fifth(v)*Hhat_L6_M1_Im_v5;
      break;
    case 0:
      break;
    }
    break;
  case 7:
    switch(abs(M)) {
    case 7:
      Im = fifth(v)*Hhat_L7_M7_Im_v5;
      break;
    case 6:
      Re = sixth(v)*Hhat_L7_M6_Re_v6;
      break;
    case 5:
      Im = fifth(v)*Hhat_L7_M5_Im_v5;
      break;
    case 4:
      Re = sixth(v)*Hhat_L7_M4_Re_v6;
      break;
    case 3:
      Im = fifth(v)*Hhat_L7_M3_Im_v5;
      break;
    case 2:
      Re = sixth(v)*Hhat_L7_M2_Re_v6;
      break;
    case 1:
      Im = fifth(v)*Hhat_L7_M1_Im_v5;
      break;
    case 0:
      break;
    }
    break;
  case 8:
    switch(abs(M)) {
    case 8:
      Re = sixth(v)*Hhat_L8_M8_Re_v6;
      break;
    case 7:
      break;
    case 6:
      Re = sixth(v)*Hhat_L8_M6_Re_v6;
      break;
    case 5:
      break;
    case 4:
      Re = sixth(v)*Hhat_L8_M4_Re_v6;
      break;
    case 3:
      break;
    case 2:
      Re = sixth(v)*Hhat_L8_M2_Re_v6;
      break;
    case 1:
      break;
    case 0:
      break;
    }
    break;
  } // switch(L)
  
  /// h_{l,-m} = (-1)^l h_{l,m}^\ast
  if(M<0) {
    if(L%2==0) {
      Im *= -1.0;
    } else {
      Re *= -1.0;
    }
  }
  
  return;
}

void WaveformUtilities::WaveformAmplitudes::rhOverM(const int L, const int M, const double v, const double psi, double& Mag, double& Arg) const {
  double Re, Im;
  Hhat(L, M, v, Re, Im);
  Mag = NormalizationFactor*v*v*sqrt(Re*Re+Im*Im);
  Arg = atan2(Im, Re) - M*psi;
  return;
}

void WaveformUtilities::WaveformAmplitudes::rhOverM(const int L, const int M, const vector<double>& v, const vector<double>& psi, vector<double>& Mag, vector<double>& Arg) const {
  vector<double> Re(v.size()), Im(v.size());
  for(unsigned int i=0; i<v.size(); ++i) {
    Hhat(L, M, v[i], Re[i], Im[i]);
  }
  Mag = NormalizationFactor*v*v*sqrt(Re*Re+Im*Im);
  Arg = Unwrap(atan2(Im, Re)) - M*psi;
  return;
}

WaveformUtilities::WaveformAmplitudesSumMMagSquared::WaveformAmplitudesSumMMagSquared(const WaveformUtilities::WaveformAmplitudes& WA)
  : NormalizationFactor(WA.NormalizationFactor*WA.NormalizationFactor),
    Sum_v0(8*Power(WA.Hhat_L2_M2_Re_v0,2)),
    Sum_v2(2*(Power(WA.Hhat_L2_M1_Im_v1,2) + 8*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v2 + Power(WA.Hhat_L3_M1_Im_v1,2) + 9*Power(WA.Hhat_L3_M3_Im_v1,2))),
    Sum_v3(16*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v3),
    Sum_v4(4*WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v3 + 8*Power(WA.Hhat_L2_M2_Re_v2,2) + 16*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v4 + 4*WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v3 + 8*Power(WA.Hhat_L3_M2_Re_v2,2) + 36*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v3 + 8*Power(WA.Hhat_L4_M2_Re_v2,2) + 32*Power(WA.Hhat_L4_M4_Re_v2,2)),
    Sum_v5(4*WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v4 + 16*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v3 + 16*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v5 + 4*WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v4 + 36*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v4),
    Sum_v6(2*(Power(WA.Hhat_L2_M1_Im_v3,2) + 2*WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v5 + 4*Power(WA.Hhat_L2_M2_Re_v3,2) + 8*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v4 + 8*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v6 + Power(WA.Hhat_L3_M1_Im_v3,2) + 2*WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v5 + 8*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v4 + 9*Power(WA.Hhat_L3_M3_Im_v3,2) + 18*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v5 + Power(WA.Hhat_L4_M1_Im_v3,2) + 8*WA.Hhat_L4_M2_Re_v2*WA.Hhat_L4_M2_Re_v4 + 9*Power(WA.Hhat_L4_M3_Im_v3,2) + 32*WA.Hhat_L4_M4_Re_v2*WA.Hhat_L4_M4_Re_v4 + Power(WA.Hhat_L5_M1_Im_v3,2) + 9*Power(WA.Hhat_L5_M3_Im_v3,2) + 25*Power(WA.Hhat_L5_M5_Im_v3,2))),
    Sum_v6lnv(16*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v7(4*(WA.Hhat_L2_M1_Im_v3*WA.Hhat_L2_M1_Im_v4 + WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v6 + 4*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v4 + 4*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v5 + WA.Hhat_L3_M1_Im_v3*WA.Hhat_L3_M1_Im_v4 + WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v6 + 4*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v5 + 9*WA.Hhat_L3_M3_Im_v3*WA.Hhat_L3_M3_Im_v4 + 9*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v6 + 4*WA.Hhat_L4_M2_Re_v2*WA.Hhat_L4_M2_Re_v5 + 16*WA.Hhat_L4_M4_Re_v2*WA.Hhat_L4_M4_Re_v5)),
    Sum_v8(2*(Power(WA.Hhat_L2_M1_Re_v4,2) + Power(WA.Hhat_L2_M1_Im_v4,2) + 2*WA.Hhat_L2_M1_Im_v3*WA.Hhat_L2_M1_Im_v5 + 4*Power(WA.Hhat_L2_M2_Re_v4,2) + 8*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v5 + 8*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v6 + Power(WA.Hhat_L3_M1_Re_v4,2) + Power(WA.Hhat_L3_M1_Im_v4,2) + 2*WA.Hhat_L3_M1_Im_v3*WA.Hhat_L3_M1_Im_v5 + 4*Power(WA.Hhat_L3_M2_Re_v4,2) + 8*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v6 + 9*Power(WA.Hhat_L3_M3_Re_v4,2) + 9*Power(WA.Hhat_L3_M3_Im_v4,2) + 18*WA.Hhat_L3_M3_Im_v3*WA.Hhat_L3_M3_Im_v5 + 2*WA.Hhat_L4_M1_Im_v3*WA.Hhat_L4_M1_Im_v5 + 4*Power(WA.Hhat_L4_M2_Re_v4,2) + 8*WA.Hhat_L4_M2_Re_v2*WA.Hhat_L4_M2_Re_v6 + 18*WA.Hhat_L4_M3_Im_v3*WA.Hhat_L4_M3_Im_v5 + 16*Power(WA.Hhat_L4_M4_Re_v4,2) + 32*WA.Hhat_L4_M4_Re_v2*WA.Hhat_L4_M4_Re_v6 + 2*WA.Hhat_L5_M1_Im_v3*WA.Hhat_L5_M1_Im_v5 + 4*Power(WA.Hhat_L5_M2_Re_v4,2) + 18*WA.Hhat_L5_M3_Im_v3*WA.Hhat_L5_M3_Im_v5 + 16*Power(WA.Hhat_L5_M4_Re_v4,2) + 50*WA.Hhat_L5_M5_Im_v3*WA.Hhat_L5_M5_Im_v5 + 4*Power(WA.Hhat_L6_M2_Re_v4,2) + 16*Power(WA.Hhat_L6_M4_Re_v4,2) + 36*Power(WA.Hhat_L6_M6_Re_v4,2))),
    Sum_v8lnv(16*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v9(4*(WA.Hhat_L2_M1_Im_v4*WA.Hhat_L2_M1_Im_v5 + WA.Hhat_L2_M1_Im_v3*WA.Hhat_L2_M1_Im_v6 + 4*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v5 + 4*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v6 + WA.Hhat_L3_M1_Im_v4*WA.Hhat_L3_M1_Im_v5 + WA.Hhat_L3_M1_Im_v3*WA.Hhat_L3_M1_Im_v6 + 4*WA.Hhat_L3_M2_Re_v4*WA.Hhat_L3_M2_Re_v5 + 9*WA.Hhat_L3_M3_Im_v4*WA.Hhat_L3_M3_Im_v5 + 9*WA.Hhat_L3_M3_Im_v3*WA.Hhat_L3_M3_Im_v6 + WA.Hhat_L4_M1_Im_v3*WA.Hhat_L4_M1_Im_v6 + 4*WA.Hhat_L4_M2_Re_v4*WA.Hhat_L4_M2_Re_v5 + 9*WA.Hhat_L4_M3_Im_v3*WA.Hhat_L4_M3_Im_v6 + 16*WA.Hhat_L4_M4_Re_v4*WA.Hhat_L4_M4_Re_v5 + WA.Hhat_L5_M1_Im_v3*WA.Hhat_L5_M1_Im_v6 + 9*WA.Hhat_L5_M3_Im_v3*WA.Hhat_L5_M3_Im_v6 + 25*WA.Hhat_L5_M5_Im_v3*WA.Hhat_L5_M5_Im_v6)),
    Sum_v9lnv(16*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v10(2*(Power(WA.Hhat_L2_M1_Im_v5,2) + 2*WA.Hhat_L2_M1_Re_v4*WA.Hhat_L2_M1_Re_v6 + 2*WA.Hhat_L2_M1_Im_v4*WA.Hhat_L2_M1_Im_v6 + 4*Power(WA.Hhat_L2_M2_Re_v5,2) + 4*Power(WA.Hhat_L2_M2_Im_v5,2) + 8*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v6 + Power(WA.Hhat_L3_M1_Im_v5,2) + 2*WA.Hhat_L3_M1_Re_v4*WA.Hhat_L3_M1_Re_v6 + 2*WA.Hhat_L3_M1_Im_v4*WA.Hhat_L3_M1_Im_v6 + 4*Power(WA.Hhat_L3_M2_Re_v5,2) + 4*Power(WA.Hhat_L3_M2_Im_v5,2) + 8*WA.Hhat_L3_M2_Re_v4*WA.Hhat_L3_M2_Re_v6 + 9*Power(WA.Hhat_L3_M3_Im_v5,2) + 18*WA.Hhat_L3_M3_Re_v4*WA.Hhat_L3_M3_Re_v6 + 18*WA.Hhat_L3_M3_Im_v4*WA.Hhat_L3_M3_Im_v6 + Power(WA.Hhat_L4_M1_Im_v5,2) + 4*Power(WA.Hhat_L4_M2_Re_v5,2) + 4*Power(WA.Hhat_L4_M2_Im_v5,2) + 8*WA.Hhat_L4_M2_Re_v4*WA.Hhat_L4_M2_Re_v6 + 9*Power(WA.Hhat_L4_M3_Im_v5,2) + 16*Power(WA.Hhat_L4_M4_Re_v5,2) + 16*Power(WA.Hhat_L4_M4_Im_v5,2) + 32*WA.Hhat_L4_M4_Re_v4*WA.Hhat_L4_M4_Re_v6 + Power(WA.Hhat_L5_M1_Im_v5,2) + 8*WA.Hhat_L5_M2_Re_v4*WA.Hhat_L5_M2_Re_v6 + 9*Power(WA.Hhat_L5_M3_Im_v5,2) + 32*WA.Hhat_L5_M4_Re_v4*WA.Hhat_L5_M4_Re_v6 + 25*Power(WA.Hhat_L5_M5_Im_v5,2) + Power(WA.Hhat_L6_M1_Im_v5,2) + 8*WA.Hhat_L6_M2_Re_v4*WA.Hhat_L6_M2_Re_v6 + 9*Power(WA.Hhat_L6_M3_Im_v5,2) + 32*WA.Hhat_L6_M4_Re_v4*WA.Hhat_L6_M4_Re_v6 + 25*Power(WA.Hhat_L6_M5_Im_v5,2) + 72*WA.Hhat_L6_M6_Re_v4*WA.Hhat_L6_M6_Re_v6 + Power(WA.Hhat_L7_M1_Im_v5,2) + 9*Power(WA.Hhat_L7_M3_Im_v5,2) + 25*Power(WA.Hhat_L7_M5_Im_v5,2) + 49*Power(WA.Hhat_L7_M7_Im_v5,2))),
    Sum_v10lnv(16*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v11(4*WA.Hhat_L2_M1_Im_v5*WA.Hhat_L2_M1_Im_v6 + 16*WA.Hhat_L2_M2_Re_v5*WA.Hhat_L2_M2_Re_v6 + 16*WA.Hhat_L2_M2_Im_v5*WA.Hhat_L2_M2_Im_v6 + 4*WA.Hhat_L3_M1_Im_v5*WA.Hhat_L3_M1_Im_v6 + 16*WA.Hhat_L3_M2_Re_v5*WA.Hhat_L3_M2_Re_v6 + 36*WA.Hhat_L3_M3_Im_v5*WA.Hhat_L3_M3_Im_v6 + 4*WA.Hhat_L4_M1_Im_v5*WA.Hhat_L4_M1_Im_v6 + 16*WA.Hhat_L4_M2_Re_v5*WA.Hhat_L4_M2_Re_v6 + 36*WA.Hhat_L4_M3_Im_v5*WA.Hhat_L4_M3_Im_v6 + 64*WA.Hhat_L4_M4_Re_v5*WA.Hhat_L4_M4_Re_v6 + 4*WA.Hhat_L5_M1_Im_v5*WA.Hhat_L5_M1_Im_v6 + 36*WA.Hhat_L5_M3_Im_v5*WA.Hhat_L5_M3_Im_v6 + 100*WA.Hhat_L5_M5_Im_v5*WA.Hhat_L5_M5_Im_v6),
    Sum_v11lnv(16*WA.Hhat_L2_M2_Re_v5*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v12(2*Power(WA.Hhat_L2_M1_Re_v6,2) + 2*Power(WA.Hhat_L2_M1_Im_v6,2) + 8*Power(WA.Hhat_L2_M2_Re_v6,2) + 8*Power(WA.Hhat_L2_M2_Im_v6,2) + 2*Power(WA.Hhat_L3_M1_Re_v6,2) + 2*Power(WA.Hhat_L3_M1_Im_v6,2) + 8*Power(WA.Hhat_L3_M2_Re_v6,2) + 18*Power(WA.Hhat_L3_M3_Re_v6,2) + 18*Power(WA.Hhat_L3_M3_Im_v6,2) + 2*Power(WA.Hhat_L4_M1_Re_v6,2) + 2*Power(WA.Hhat_L4_M1_Im_v6,2) + 8*Power(WA.Hhat_L4_M2_Re_v6,2) + 18*Power(WA.Hhat_L4_M3_Re_v6,2) + 18*Power(WA.Hhat_L4_M3_Im_v6,2) + 32*Power(WA.Hhat_L4_M4_Re_v6,2) + 2*Power(WA.Hhat_L5_M1_Re_v6,2) + 2*Power(WA.Hhat_L5_M1_Im_v6,2) + 8*Power(WA.Hhat_L5_M2_Re_v6,2) + 18*Power(WA.Hhat_L5_M3_Re_v6,2) + 18*Power(WA.Hhat_L5_M3_Im_v6,2) + 32*Power(WA.Hhat_L5_M4_Re_v6,2) + 50*Power(WA.Hhat_L5_M5_Re_v6,2) + 50*Power(WA.Hhat_L5_M5_Im_v6,2) + 8*Power(WA.Hhat_L6_M2_Re_v6,2) + 32*Power(WA.Hhat_L6_M4_Re_v6,2) + 72*Power(WA.Hhat_L6_M6_Re_v6,2) + 8*Power(WA.Hhat_L7_M2_Re_v6,2) + 32*Power(WA.Hhat_L7_M4_Re_v6,2) + 72*Power(WA.Hhat_L7_M6_Re_v6,2) + 8*Power(WA.Hhat_L8_M2_Re_v6,2) + 32*Power(WA.Hhat_L8_M4_Re_v6,2) + 72*Power(WA.Hhat_L8_M6_Re_v6,2) + 128*Power(WA.Hhat_L8_M8_Re_v6,2)),
    Sum_v12lnv(16*WA.Hhat_L2_M2_Re_v6*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v12lnv2(8*Power(WA.Hhat_L2_M2_Re_v6lnv,2))
{ }

double WaveformUtilities::WaveformAmplitudesSumMMagSquared::SumMMagSquared(const double v) const {
  const double lnv = log(v);
  return
    NormalizationFactor*fourth(v)
    *(Sum_v0
     + v*(Sum_v2
	  + v*(Sum_v3
	       + v*(Sum_v4
		    + v*(Sum_v5
			 + v*(Sum_v6 + lnv*Sum_v6lnv
			      + v*(Sum_v7
				   + v*(Sum_v8 + lnv*Sum_v8lnv
					+ v*(Sum_v9 + lnv*Sum_v9lnv
					     + v*(Sum_v10 + lnv*Sum_v10lnv
						  + v*(Sum_v11 + lnv*Sum_v11lnv
						       + v*(Sum_v12 + lnv*(Sum_v12lnv + lnv*Sum_v12lnv2) )
						       )
						  )
					     )
					)
				   )
			      )
			 )
		    )
	       )
	 )
     );
}
