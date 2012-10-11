#include "WaveformAmplitudes.hpp"

#include <cstdlib>
#include <cmath>
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
using namespace WaveformUtilities;
using std::vector;

#define Log std::log
#define Power std::pow
#define Sqrt std::sqrt

WaveformUtilities::WaveformAmplitudes::WaveformAmplitudes(const double idelta, const double ichis, const double ichia)
  : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), chia(ichia),
    NormalizationFactor(2*nu*sqrt(16*M_PI/5.0)),
    Hhat_L2_M2_Re_v0(1.),
    Hhat_L2_M2_Re_v2(0.023809523809523808*(-107. + 55.*nu)),
    Hhat_L2_M2_Re_v3(0.3333333333333333*(18.84955592153876 - 4.*chia*delta + 4.*chis*(-1. + nu))),
    Hhat_L2_M2_Re_v4(0.0006613756613756613*(-2173. - 7.*(1069. + 432.*Power(chia,2) - 432.*Power(chis,2))*nu + 2047.*Power(nu,2))),
    Hhat_L2_M2_Re_v5(0.1495996501709425*(-107. + 34.*nu)),
    Hhat_L2_M2_Im_v5(-24.*nu),
    Hhat_L2_M2_Re_v6(32.35880116100775 - 4.147801379146346*nu - 7.309163059163059*Power(nu,2) + 1.1487393779060446*Power(nu,3)),
    Hhat_L2_M2_Im_v6(12.80573005463268),
    Hhat_L2_M2_Re_v6lnv(-8.152380952380952),
    Hhat_L2_M2_Re_v7(0.004155545838081737*(-2173. + nu*(-4918. + 1120.*nu))),
    Hhat_L2_M2_Im_v7(0.0001763668430335097*(501655. - 24396.*nu)*nu),
    Hhat_L2_M1_Im_v1(0.3333333333333333*delta),
    Hhat_L2_M1_Im_v2(0.5*(chia + chis*delta)),
    Hhat_L2_M1_Im_v3(0.011904761904761904*delta*(-17. + 20.*nu)),
    Hhat_L2_M1_Re_v4(0.6287647870399635*delta),
    Hhat_L2_M1_Im_v4(1.0471975511965976*delta),
    Hhat_L2_M1_Im_v5(0.0006613756613756613*delta*(-172. - 2036.*nu + 237.*Power(nu,2))),
    Hhat_L2_M1_Re_v6(0.001984126984126984*delta*(-192.40202483422883 + 2039.906597000316*nu)),
    Hhat_L2_M1_Im_v6(0.03739991254273563*delta*(-17. + 6.*nu)),
    Hhat_L2_M0_Re_v0(-0.1458029608799511),
    Hhat_L3_M3_Im_v1(-0.7763237542601484*delta),
    Hhat_L3_M3_Im_v3(-1.5526475085202969*delta*(-2. + nu)),
    Hhat_L3_M3_Re_v4(-1.3719265982044606*delta),
    Hhat_L3_M3_Im_v4(-7.316679009572791*delta),
    Hhat_L3_M3_Im_v5(-0.002352496225030753*delta*(369. - 3676.*nu + 887.*Power(nu,2))),
    Hhat_L3_M3_Re_v6(0.0006389495919836613*delta*(8588.637447565925 - 43669.239042837224*nu)),
    Hhat_L3_M3_Im_v6(3.6583395047863956*delta*(8. - 3.*nu)),
    Hhat_L3_M2_Re_v2(0.2817180849095055*(1. - 3.*nu)),
    Hhat_L3_M2_Re_v3(1.126872339638022*chis*nu),
    Hhat_L3_M2_Re_v4(-0.00313020094343895*(193. - 725.*nu + 365.*Power(nu,2))),
    Hhat_L3_M2_Re_v5(1.7700869318701762*(1. - 3.*nu)),
    Hhat_L3_M2_Im_v5(0.1690308509457033*(-5. + 22.*nu)),
    Hhat_L3_M2_Re_v6(-0.00007114093053270341*(1451. + 17387.*nu - 100026.*Power(nu,2) + 16023.*Power(nu,3))),
    Hhat_L3_M1_Im_v1(0.0222717701593687*delta),
    Hhat_L3_M1_Im_v3(-0.014847846772912466*delta*(4. + nu)),
    Hhat_L3_M1_Re_v4(0.06205570760720725*delta),
    Hhat_L3_M1_Im_v4(0.06996882951511307*delta),
    Hhat_L3_M1_Im_v5(-0.00011248368767357928*delta*(-607. + 272.*nu + 247.*Power(nu,2))),
    Hhat_L3_M1_Re_v6(0.0014847846772912468*delta*(-111.45177444479563 - 23.260151319598084*nu)),
    Hhat_L3_M1_Im_v6(-0.01166147158585218*delta*(16. + 7.*nu)),
    Hhat_L3_M0_Im_v5(-0.3703280399090206*nu),
    Hhat_L4_M4_Re_v2(0.751248226425348*(-1. + 3.*nu)),
    Hhat_L4_M4_Re_v4(0.002276509777046509*(1779. - 6365.*nu + 2625.*Power(nu,2))),
    Hhat_L4_M4_Re_v5(9.44046363664094*(-1. + 3.*nu)),
    Hhat_L4_M4_Im_v5(0.0187812056606337*(114.1929022208175 - 527.5787066624525*nu)),
    Hhat_L4_M4_Re_v6(4.1694318260925076e-7*(-9.618039e6 + 6.8551497e7*nu - 1.1309683e8*Power(nu,2) + 2.3740185e7*Power(nu,3))),
    Hhat_L4_M3_Im_v3(0.26892643710023856*delta*(-1. + 2.*nu)),
    Hhat_L4_M3_Im_v5(0.0020373214931836254*delta*(468. - 1267.*nu + 524.*Power(nu,2))),
    Hhat_L4_M3_Re_v6(0.0003320079470373316*delta*(-3213.439574594321 + 12359.879149188642*nu)),
    Hhat_L4_M3_Im_v6(2.534571957450561*delta*(-1. + 2.*nu)),
    Hhat_L4_M2_Re_v2(0.03549314249999666*(1. - 3.*nu)),
    Hhat_L4_M2_Re_v4(-0.00010755497727271716*(1311. - 4025.*nu + 285.*Power(nu,2))),
    Hhat_L4_M2_Re_v5(0.22300999146161035*(1. - 3.*nu)),
    Hhat_L4_M2_Im_v5(0.14907119849998596*(-1. + 4.*nu)),
    Hhat_L4_M2_Re_v6(1.9698713786211933e-8*(9.342351e6 - 3.8225313e7*nu + 2.803171e7*Power(nu,2) + 2.707215e6*Power(nu,3))),
    Hhat_L4_M1_Im_v3(0.0037646162621052135*delta*(1. - 2.*nu)),
    Hhat_L4_M1_Im_v5(-0.00002851982016746374*delta*(404. - 1011.*nu + 332.*Power(nu,2))),
    Hhat_L4_M1_Re_v6(0.00012548720873684045*delta*(105.58883083359672 - 1744.1776616671934*nu)),
    Hhat_L4_M1_Im_v6(0.011826890792614406*delta*(1. - 2.*nu)),
    Hhat_L4_M0_Re_v0(-0.0014029896452114037),
    Hhat_L5_M5_Im_v3(-0.8013768943966975*delta*(-1. + 2.*nu)),
    Hhat_L5_M5_Im_v5(-0.020548125497351216*delta*(263. - 688.*nu + 256.*Power(nu,2))),
    Hhat_L5_M5_Re_v6(0.0000183171861576388*delta*(164747.8048050571 - 679921.6096101142*nu)),
    Hhat_L5_M5_Im_v6(-12.587998820966341*delta*(-1. + 2.*nu)),
    Hhat_L5_M4_Re_v4(-0.2767996245907637*(1. - 5.*nu + 5.*Power(nu,2))),
    Hhat_L5_M4_Re_v6(-0.0003041754116382019*(-4451. + 25333.*nu - 36470.*Power(nu,2) + 11865.*Power(nu,3))),
    Hhat_L5_M3_Im_v3(0.046446908841268335*delta*(-1. + 2.*nu)),
    Hhat_L5_M3_Im_v5(0.001190946380545342*delta*(207. - 464.*nu + 88.*Power(nu,2))),
    Hhat_L5_M3_Re_v6(9.101882978888565e-7*delta*(-271701.69319944223 + 923537.3863988845*nu)),
    Hhat_L5_M3_Im_v6(0.4377518027930503*delta*(-1. + 2.*nu)),
    Hhat_L5_M2_Re_v4(0.009988146110566549*(1. - 5.*nu + 5.*Power(nu,2))),
    Hhat_L5_M2_Re_v6(0.000010975984736886318*(-3911. + 21553.*nu - 28910.*Power(nu,2) + 8085.*Power(nu,3))),
    Hhat_L5_M1_Im_v3(0.00017696083036028665*delta*(1. - 2.*nu)),
    Hhat_L5_M1_Im_v5(-4.537457188725299e-6*delta*(179. - 352.*nu + 4.*Power(nu,2))),
    Hhat_L5_M1_Re_v6(2.528011862289809e-6*delta*(278.0406052783923 - 8958.081210556786*nu)),
    Hhat_L5_M1_Im_v6(0.0005559388446330261*delta*(1. - 2.*nu)),
    Hhat_L6_M6_Re_v4(0.9031413708076581*(1. - 5.*nu + 5.*Power(nu,2))),
    Hhat_L6_M6_Re_v6(0.06451009791483273*(-113. + 637.*nu - 896.*Power(nu,2) + 273.*Power(nu,3))),
    Hhat_L6_M5_Im_v5(0.2993579796535637*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L6_M4_Re_v4(-0.058558165806265966*(1. - 5.*nu + 5.*Power(nu,2))),
    Hhat_L6_M4_Re_v6(-0.004182726129018997*(-93. + 497.*nu - 616.*Power(nu,2) + 133.*Power(nu,3))),
    Hhat_L6_M3_Im_v5(-0.01630976217812644*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L6_M2_Re_v4(0.0008352507379744677*(1. - 5.*nu + 5.*Power(nu,2))),
    Hhat_L6_M2_Re_v6(0.000059660766998176277*(-81. + 413.*nu - 448.*Power(nu,2) + 49.*Power(nu,3))),
    Hhat_L6_M1_Im_v5(0.000023582988833355464*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L7_M7_Im_v5(-1.0542244493439168*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L7_M6_Re_v6(-0.3352043015692001*(-1. + 7.*nu - 14.*Power(nu,2) + 7.*Power(nu,3))),
    Hhat_L7_M5_Im_v5(0.07338616249054006*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L7_M4_Re_v6(0.023085290615904162*(-1. + 7.*nu - 14.*Power(nu,2) + 7.*Power(nu,3))),
    Hhat_L7_M3_Im_v5(-0.0018582230503756002*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L7_M2_Re_v6(0.0001922578318979773*(1. - 7.*nu + 14.*Power(nu,2) - 7.*Power(nu,3))),
    Hhat_L7_M1_Im_v5(8.175930333399787e-7*delta*(1. - 4.*nu + 3.*Power(nu,2))),
    Hhat_L8_M8_Re_v6(1.2608629579851318*(-1. + 7.*nu - 14.*Power(nu,2) + 7.*Power(nu,3))),
    Hhat_L8_M6_Re_v6(-0.0921843838337631*(-1. + 7.*nu - 14.*Power(nu,2) + 7.*Power(nu,3))),
    Hhat_L8_M4_Re_v6(0.0032325872683449304*(-1. + 7.*nu - 14.*Power(nu,2) + 7.*Power(nu,3))),
    Hhat_L8_M2_Re_v6(0.000012039652448587866*(1. - 7.*nu + 14.*Power(nu,2) - 7.*Power(nu,3)))
{ }

void WaveformUtilities::WaveformAmplitudes::SetParameters(const double idelta, const double ichis, const double ichia) {
  *this = WaveformAmplitudes(idelta, ichis, ichia);
  return;
}

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
      Re = Hhat_L2_M2_Re_v0 + v*v*(Hhat_L2_M2_Re_v2 + v*(Hhat_L2_M2_Re_v3 + v*(Hhat_L2_M2_Re_v4 + v*(Hhat_L2_M2_Re_v5 + v*(Hhat_L2_M2_Re_v6 + lnv*Hhat_L2_M2_Re_v6lnv + v*(Hhat_L2_M2_Re_v7))))));
      Im = v*v*v*v*v*(Hhat_L2_M2_Im_v5 + v*(Hhat_L2_M2_Im_v6 + v*(Hhat_L2_M2_Im_v7)));
      break;
    case 1:
      Re = v*v*v*v*(Hhat_L2_M1_Re_v4 + v*v*Hhat_L2_M1_Re_v6);
      Im = v*(Hhat_L2_M1_Im_v1 + v*(Hhat_L2_M1_Im_v2 + v*(Hhat_L2_M1_Im_v3 + v*(Hhat_L2_M1_Im_v4 + v*(Hhat_L2_M1_Im_v5 + v*Hhat_L2_M1_Im_v6)))));
      break;
    case 0:
      Re = Hhat_L2_M0_Re_v0;
      break;
    }
    break;
  case 3:
    switch(abs(M)) {
    case 3:
      Re = v*v*v*v*(Hhat_L3_M3_Re_v4 + v*v*Hhat_L3_M3_Re_v6);
      Im = v*(Hhat_L3_M3_Im_v1 + v*v*(Hhat_L3_M3_Im_v3 + v*(Hhat_L3_M3_Im_v4 + v*(Hhat_L3_M3_Im_v5 + v*Hhat_L3_M3_Im_v6))));
      break;
    case 2:
      Re = v*v*(Hhat_L3_M2_Re_v2 + v*(Hhat_L3_M2_Re_v3 + v*(Hhat_L3_M2_Re_v4 + v*(Hhat_L3_M2_Re_v5 + v*Hhat_L3_M2_Re_v6))));
      Im = v*v*v*v*v*Hhat_L3_M2_Im_v5;
      break;
    case 1:
      Re = v*v*v*v*(Hhat_L3_M1_Re_v4 + v*v*Hhat_L3_M1_Re_v6);
      Im = v*(Hhat_L3_M1_Im_v1 + v*v*(Hhat_L3_M1_Im_v3 + v*(Hhat_L3_M1_Im_v4 + v*(Hhat_L3_M1_Im_v5 + v*Hhat_L3_M1_Im_v6))));
      break;
    case 0:
      Im = v*v*v*v*v*Hhat_L3_M0_Im_v5;
      break;
    }
    break;
  case 4:
    switch(abs(M)) {
    case 4:
      Re = v*v*(Hhat_L4_M4_Re_v2 + v*v*(Hhat_L4_M4_Re_v4 + v*(Hhat_L4_M4_Re_v5 + v*Hhat_L4_M4_Re_v6)));
      Im = v*v*v*v*v*Hhat_L4_M4_Im_v5;
      break;
    case 3:
      Re = v*v*v*v*v*v*Hhat_L4_M3_Re_v6;
      Im = v*v*v*(Hhat_L4_M3_Im_v3 + v*v*(Hhat_L4_M3_Im_v5 + v*Hhat_L4_M3_Im_v6));
      break;
    case 2:
      Re = v*v*(Hhat_L4_M2_Re_v2 + v*v*(Hhat_L4_M2_Re_v4 + v*(Hhat_L4_M2_Re_v5 + v*Hhat_L4_M2_Re_v6)));
      Im = v*v*v*v*v*Hhat_L4_M2_Im_v5;
      break;
    case 1:
      Re = v*v*v*v*v*v*Hhat_L4_M1_Re_v6;
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
      Re = v*v*v*v*v*v*Hhat_L5_M5_Re_v6;
      Im = v*v*v*(Hhat_L5_M5_Im_v3 + v*v*(Hhat_L5_M5_Im_v5 + v*Hhat_L5_M5_Im_v6));
      break;
    case 4:
      Re = v*v*v*v*(Hhat_L5_M4_Re_v4 + v*v*Hhat_L5_M4_Re_v6);
      break;
    case 3:
      Re = v*v*v*v*v*v*Hhat_L5_M3_Re_v6;
      Im = v*v*v*(Hhat_L5_M3_Im_v3 + v*v*(Hhat_L5_M3_Im_v5 + v*Hhat_L5_M3_Im_v6));
      break;
    case 2:
      Re = v*v*v*v*(Hhat_L5_M2_Re_v4 + v*v*Hhat_L5_M2_Re_v6);
      break;
    case 1:
      Re = v*v*v*v*v*v*Hhat_L5_M1_Re_v6;
      Im = v*v*v*(Hhat_L5_M1_Im_v3 + v*v*(Hhat_L5_M1_Im_v5 + v*Hhat_L5_M1_Im_v6));
      break;
    case 0:
      break;
    }
    break;
  case 6:
    switch(abs(M)) {
    case 6:
      Re = v*v*v*v*(Hhat_L6_M6_Re_v4 + v*v*Hhat_L6_M6_Re_v6);
      break;
    case 5:
      Im = v*v*v*v*v*Hhat_L6_M5_Im_v5;
      break;
    case 4:
      Re = v*v*v*v*(Hhat_L6_M4_Re_v4 + v*v*Hhat_L6_M4_Re_v6);
      break;
    case 3:
      Im = v*v*v*v*v*Hhat_L6_M3_Im_v5;
      break;
    case 2:
      Re = v*v*v*v*(Hhat_L6_M2_Re_v4 + v*v*Hhat_L6_M2_Re_v6);
      break;
    case 1:
      Im = v*v*v*v*v*Hhat_L6_M1_Im_v5;
      break;
    case 0:
      break;
    }
    break;
  case 7:
    switch(abs(M)) {
    case 7:
      Im = v*v*v*v*v*Hhat_L7_M7_Im_v5;
      break;
    case 6:
      Re = v*v*v*v*v*v*Hhat_L7_M6_Re_v6;
      break;
    case 5:
      Im = v*v*v*v*v*Hhat_L7_M5_Im_v5;
      break;
    case 4:
      Re = v*v*v*v*v*v*Hhat_L7_M4_Re_v6;
      break;
    case 3:
      Im = v*v*v*v*v*Hhat_L7_M3_Im_v5;
      break;
    case 2:
      Re = v*v*v*v*v*v*Hhat_L7_M2_Re_v6;
      break;
    case 1:
      Im = v*v*v*v*v*Hhat_L7_M1_Im_v5;
      break;
    case 0:
      break;
    }
    break;
  case 8:
    switch(abs(M)) {
    case 8:
      Re = v*v*v*v*v*v*Hhat_L8_M8_Re_v6;
      break;
    case 7:
      break;
    case 6:
      Re = v*v*v*v*v*v*Hhat_L8_M6_Re_v6;
      break;
    case 5:
      break;
    case 4:
      Re = v*v*v*v*v*v*Hhat_L8_M4_Re_v6;
      break;
    case 3:
      break;
    case 2:
      Re = v*v*v*v*v*v*Hhat_L8_M2_Re_v6;
      break;
    case 1:
      break;
    case 0:
      break;
    }
    break;
  } // switch(L)
  
  /// Hhat_{l,-m} = (-1)^l Hhat_{l,m}^\ast
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

void WaveformUtilities::WaveformAmplitudes::rhOverM(const int L, const int M, const vector<double>& v, const vector<double>& psi,
						    const vector<double>& ichis, const vector<double>& ichia, vector<double>& Mag, vector<double>& Arg) {
  vector<double> Re(v.size()), Im(v.size());
  for(unsigned int i=0; i<v.size(); ++i) {
    SetParameters(delta, ichis[i], ichia[i]);
    Hhat(L, M, v[i], Re[i], Im[i]);
  }
  Mag = NormalizationFactor*v*v*sqrt(Re*Re+Im*Im);
  Arg = Unwrap(atan2(Im, Re)) - M*psi;
  return;
}

WaveformUtilities::WaveformAmplitudesSumMMagSquared::WaveformAmplitudesSumMMagSquared(const WaveformUtilities::WaveformAmplitudes& WA)
  : NormalizationFactor(WA.NormalizationFactor*WA.NormalizationFactor),
    Sum_v0(8.*pow(WA.Hhat_L2_M2_Re_v0,2)),
    Sum_v2(2.*(pow(WA.Hhat_L2_M1_Im_v1,2) + 8.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v2 + pow(WA.Hhat_L3_M1_Im_v1,2) + 9.*pow(WA.Hhat_L3_M3_Im_v1,2))),
    Sum_v3(4.*WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v2 + 16.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v3),
    Sum_v4(2.*pow(WA.Hhat_L2_M1_Im_v2,2) + 4.*WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v3 + 8.*pow(WA.Hhat_L2_M2_Re_v2,2) + 16.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v4 + 4.*WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v3 + 8.*pow(WA.Hhat_L3_M2_Re_v2,2) + 36.*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v3 + 8.*pow(WA.Hhat_L4_M2_Re_v2,2) + 32.*pow(WA.Hhat_L4_M4_Re_v2,2)),
    Sum_v5(4.*(WA.Hhat_L2_M1_Im_v2*WA.Hhat_L2_M1_Im_v3 + WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v4 + 4.*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v3 + 4.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v5 + WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v4 + 4.*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v3 + 9.*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v4)),
    Sum_v6(2.*(pow(WA.Hhat_L2_M1_Im_v3,2) + 2.*WA.Hhat_L2_M1_Im_v2*WA.Hhat_L2_M1_Im_v4 + 2.*WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v5 + 4.*pow(WA.Hhat_L2_M2_Re_v3,2) + 8.*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v4 + 8.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v6 + pow(WA.Hhat_L3_M1_Im_v3,2) + 2.*WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v5 + 4.*pow(WA.Hhat_L3_M2_Re_v3,2) + 8.*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v4 + 9.*pow(WA.Hhat_L3_M3_Im_v3,2) + 18.*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v5 + pow(WA.Hhat_L4_M1_Im_v3,2) + 8.*WA.Hhat_L4_M2_Re_v2*WA.Hhat_L4_M2_Re_v4 + 9.*pow(WA.Hhat_L4_M3_Im_v3,2) + 32.*WA.Hhat_L4_M4_Re_v2*WA.Hhat_L4_M4_Re_v4 + pow(WA.Hhat_L5_M1_Im_v3,2) + 9.*pow(WA.Hhat_L5_M3_Im_v3,2) + 25.*pow(WA.Hhat_L5_M5_Im_v3,2))),
    Sum_v6lnv(16.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v7(4.*(WA.Hhat_L2_M1_Im_v3*WA.Hhat_L2_M1_Im_v4 + WA.Hhat_L2_M1_Im_v2*WA.Hhat_L2_M1_Im_v5 + WA.Hhat_L2_M1_Im_v1*WA.Hhat_L2_M1_Im_v6 + 4.*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v4 + 4.*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v5 + 4.*WA.Hhat_L2_M2_Re_v0*WA.Hhat_L2_M2_Re_v7 + WA.Hhat_L3_M1_Im_v3*WA.Hhat_L3_M1_Im_v4 + WA.Hhat_L3_M1_Im_v1*WA.Hhat_L3_M1_Im_v6 + 4.*WA.Hhat_L3_M2_Re_v3*WA.Hhat_L3_M2_Re_v4 + 4.*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v5 + 9.*WA.Hhat_L3_M3_Im_v3*WA.Hhat_L3_M3_Im_v4 + 9.*WA.Hhat_L3_M3_Im_v1*WA.Hhat_L3_M3_Im_v6 + 4.*WA.Hhat_L4_M2_Re_v2*WA.Hhat_L4_M2_Re_v5 + 16.*WA.Hhat_L4_M4_Re_v2*WA.Hhat_L4_M4_Re_v5)),
    Sum_v8(2.*(pow(WA.Hhat_L2_M1_Re_v4,2) + pow(WA.Hhat_L2_M1_Im_v4,2) + 2.*WA.Hhat_L2_M1_Im_v3*WA.Hhat_L2_M1_Im_v5 + 2.*WA.Hhat_L2_M1_Im_v2*WA.Hhat_L2_M1_Im_v6 + 4.*pow(WA.Hhat_L2_M2_Re_v4,2) + 8.*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v5 + 8.*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v6 + pow(WA.Hhat_L3_M1_Re_v4,2) + pow(WA.Hhat_L3_M1_Im_v4,2) + 2.*WA.Hhat_L3_M1_Im_v3*WA.Hhat_L3_M1_Im_v5 + 4.*pow(WA.Hhat_L3_M2_Re_v4,2) + 8.*WA.Hhat_L3_M2_Re_v3*WA.Hhat_L3_M2_Re_v5 + 8.*WA.Hhat_L3_M2_Re_v2*WA.Hhat_L3_M2_Re_v6 + 9.*pow(WA.Hhat_L3_M3_Re_v4,2) + 9.*pow(WA.Hhat_L3_M3_Im_v4,2) + 18.*WA.Hhat_L3_M3_Im_v3*WA.Hhat_L3_M3_Im_v5 + 2.*WA.Hhat_L4_M1_Im_v3*WA.Hhat_L4_M1_Im_v5 + 4.*pow(WA.Hhat_L4_M2_Re_v4,2) + 8.*WA.Hhat_L4_M2_Re_v2*WA.Hhat_L4_M2_Re_v6 + 18.*WA.Hhat_L4_M3_Im_v3*WA.Hhat_L4_M3_Im_v5 + 16.*pow(WA.Hhat_L4_M4_Re_v4,2) + 32.*WA.Hhat_L4_M4_Re_v2*WA.Hhat_L4_M4_Re_v6 + 2.*WA.Hhat_L5_M1_Im_v3*WA.Hhat_L5_M1_Im_v5 + 4.*pow(WA.Hhat_L5_M2_Re_v4,2) + 18.*WA.Hhat_L5_M3_Im_v3*WA.Hhat_L5_M3_Im_v5 + 16.*pow(WA.Hhat_L5_M4_Re_v4,2) + 50.*WA.Hhat_L5_M5_Im_v3*WA.Hhat_L5_M5_Im_v5 + 4.*pow(WA.Hhat_L6_M2_Re_v4,2) + 16.*pow(WA.Hhat_L6_M4_Re_v4,2) + 36.*pow(WA.Hhat_L6_M6_Re_v4,2))),
    Sum_v8lnv(16.*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v9(4.*(WA.Hhat_L2_M1_Im_v4*WA.Hhat_L2_M1_Im_v5 + WA.Hhat_L2_M1_Im_v3*WA.Hhat_L2_M1_Im_v6 + 4.*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v5 + 4.*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v6 + 4.*WA.Hhat_L2_M2_Re_v2*WA.Hhat_L2_M2_Re_v7 + WA.Hhat_L3_M1_Im_v4*WA.Hhat_L3_M1_Im_v5 + WA.Hhat_L3_M1_Im_v3*WA.Hhat_L3_M1_Im_v6 + 4.*WA.Hhat_L3_M2_Re_v4*WA.Hhat_L3_M2_Re_v5 + 4.*WA.Hhat_L3_M2_Re_v3*WA.Hhat_L3_M2_Re_v6 + 9.*WA.Hhat_L3_M3_Im_v4*WA.Hhat_L3_M3_Im_v5 + 9.*WA.Hhat_L3_M3_Im_v3*WA.Hhat_L3_M3_Im_v6 + WA.Hhat_L4_M1_Im_v3*WA.Hhat_L4_M1_Im_v6 + 4.*WA.Hhat_L4_M2_Re_v4*WA.Hhat_L4_M2_Re_v5 + 9.*WA.Hhat_L4_M3_Im_v3*WA.Hhat_L4_M3_Im_v6 + 16.*WA.Hhat_L4_M4_Re_v4*WA.Hhat_L4_M4_Re_v5 + WA.Hhat_L5_M1_Im_v3*WA.Hhat_L5_M1_Im_v6 + 9.*WA.Hhat_L5_M3_Im_v3*WA.Hhat_L5_M3_Im_v6 + 25.*WA.Hhat_L5_M5_Im_v3*WA.Hhat_L5_M5_Im_v6)),
    Sum_v9lnv(16.*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v10(2.*(pow(WA.Hhat_L2_M1_Im_v5,2) + 2.*WA.Hhat_L2_M1_Re_v4*WA.Hhat_L2_M1_Re_v6 + 2.*WA.Hhat_L2_M1_Im_v4*WA.Hhat_L2_M1_Im_v6 + 4.*pow(WA.Hhat_L2_M2_Re_v5,2) + 4.*pow(WA.Hhat_L2_M2_Im_v5,2) + 8.*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v6 + 8.*WA.Hhat_L2_M2_Re_v3*WA.Hhat_L2_M2_Re_v7 + pow(WA.Hhat_L3_M1_Im_v5,2) + 2.*WA.Hhat_L3_M1_Re_v4*WA.Hhat_L3_M1_Re_v6 + 2.*WA.Hhat_L3_M1_Im_v4*WA.Hhat_L3_M1_Im_v6 + 4.*pow(WA.Hhat_L3_M2_Re_v5,2) + 4.*pow(WA.Hhat_L3_M2_Im_v5,2) + 8.*WA.Hhat_L3_M2_Re_v4*WA.Hhat_L3_M2_Re_v6 + 9.*pow(WA.Hhat_L3_M3_Im_v5,2) + 18.*WA.Hhat_L3_M3_Re_v4*WA.Hhat_L3_M3_Re_v6 + 18.*WA.Hhat_L3_M3_Im_v4*WA.Hhat_L3_M3_Im_v6 + pow(WA.Hhat_L4_M1_Im_v5,2) + 4.*pow(WA.Hhat_L4_M2_Re_v5,2) + 4.*pow(WA.Hhat_L4_M2_Im_v5,2) + 8.*WA.Hhat_L4_M2_Re_v4*WA.Hhat_L4_M2_Re_v6 + 9.*pow(WA.Hhat_L4_M3_Im_v5,2) + 16.*pow(WA.Hhat_L4_M4_Re_v5,2) + 16.*pow(WA.Hhat_L4_M4_Im_v5,2) + 32.*WA.Hhat_L4_M4_Re_v4*WA.Hhat_L4_M4_Re_v6 + pow(WA.Hhat_L5_M1_Im_v5,2) + 8.*WA.Hhat_L5_M2_Re_v4*WA.Hhat_L5_M2_Re_v6 + 9.*pow(WA.Hhat_L5_M3_Im_v5,2) + 32.*WA.Hhat_L5_M4_Re_v4*WA.Hhat_L5_M4_Re_v6 + 25.*pow(WA.Hhat_L5_M5_Im_v5,2) + pow(WA.Hhat_L6_M1_Im_v5,2) + 8.*WA.Hhat_L6_M2_Re_v4*WA.Hhat_L6_M2_Re_v6 + 9.*pow(WA.Hhat_L6_M3_Im_v5,2) + 32.*WA.Hhat_L6_M4_Re_v4*WA.Hhat_L6_M4_Re_v6 + 25.*pow(WA.Hhat_L6_M5_Im_v5,2) + 72.*WA.Hhat_L6_M6_Re_v4*WA.Hhat_L6_M6_Re_v6 + pow(WA.Hhat_L7_M1_Im_v5,2) + 9.*pow(WA.Hhat_L7_M3_Im_v5,2) + 25.*pow(WA.Hhat_L7_M5_Im_v5,2) + 49.*pow(WA.Hhat_L7_M7_Im_v5,2))),
    Sum_v10lnv(16.*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v11(4.*(WA.Hhat_L2_M1_Im_v5*WA.Hhat_L2_M1_Im_v6 + 4.*WA.Hhat_L2_M2_Re_v5*WA.Hhat_L2_M2_Re_v6 + 4.*WA.Hhat_L2_M2_Im_v5*WA.Hhat_L2_M2_Im_v6 + 4.*WA.Hhat_L2_M2_Re_v4*WA.Hhat_L2_M2_Re_v7 + WA.Hhat_L3_M1_Im_v5*WA.Hhat_L3_M1_Im_v6 + 4.*WA.Hhat_L3_M2_Re_v5*WA.Hhat_L3_M2_Re_v6 + 9.*WA.Hhat_L3_M3_Im_v5*WA.Hhat_L3_M3_Im_v6 + WA.Hhat_L4_M1_Im_v5*WA.Hhat_L4_M1_Im_v6 + 4.*WA.Hhat_L4_M2_Re_v5*WA.Hhat_L4_M2_Re_v6 + 9.*WA.Hhat_L4_M3_Im_v5*WA.Hhat_L4_M3_Im_v6 + 16.*WA.Hhat_L4_M4_Re_v5*WA.Hhat_L4_M4_Re_v6 + WA.Hhat_L5_M1_Im_v5*WA.Hhat_L5_M1_Im_v6 + 9.*WA.Hhat_L5_M3_Im_v5*WA.Hhat_L5_M3_Im_v6 + 25.*WA.Hhat_L5_M5_Im_v5*WA.Hhat_L5_M5_Im_v6)),
    Sum_v11lnv(16.*WA.Hhat_L2_M2_Re_v5*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v12(2.*(pow(WA.Hhat_L2_M1_Re_v6,2) + pow(WA.Hhat_L2_M1_Im_v6,2) + 4.*pow(WA.Hhat_L2_M2_Re_v6,2) + 4.*pow(WA.Hhat_L2_M2_Im_v6,2) + 8.*WA.Hhat_L2_M2_Re_v5*WA.Hhat_L2_M2_Re_v7 + 8.*WA.Hhat_L2_M2_Im_v5*WA.Hhat_L2_M2_Im_v7 + pow(WA.Hhat_L3_M1_Re_v6,2) + pow(WA.Hhat_L3_M1_Im_v6,2) + 4.*pow(WA.Hhat_L3_M2_Re_v6,2) + 9.*pow(WA.Hhat_L3_M3_Re_v6,2) + 9.*pow(WA.Hhat_L3_M3_Im_v6,2) + pow(WA.Hhat_L4_M1_Re_v6,2) + pow(WA.Hhat_L4_M1_Im_v6,2) + 4.*pow(WA.Hhat_L4_M2_Re_v6,2) + 9.*pow(WA.Hhat_L4_M3_Re_v6,2) + 9.*pow(WA.Hhat_L4_M3_Im_v6,2) + 16.*pow(WA.Hhat_L4_M4_Re_v6,2) + pow(WA.Hhat_L5_M1_Re_v6,2) + pow(WA.Hhat_L5_M1_Im_v6,2) + 4.*pow(WA.Hhat_L5_M2_Re_v6,2) + 9.*pow(WA.Hhat_L5_M3_Re_v6,2) + 9.*pow(WA.Hhat_L5_M3_Im_v6,2) + 16.*pow(WA.Hhat_L5_M4_Re_v6,2) + 25.*pow(WA.Hhat_L5_M5_Re_v6,2) + 25.*pow(WA.Hhat_L5_M5_Im_v6,2) + 4.*pow(WA.Hhat_L6_M2_Re_v6,2) + 16.*pow(WA.Hhat_L6_M4_Re_v6,2) + 36.*pow(WA.Hhat_L6_M6_Re_v6,2) + 4.*pow(WA.Hhat_L7_M2_Re_v6,2) + 16.*pow(WA.Hhat_L7_M4_Re_v6,2) + 36.*pow(WA.Hhat_L7_M6_Re_v6,2) + 4.*pow(WA.Hhat_L8_M2_Re_v6,2) + 16.*pow(WA.Hhat_L8_M4_Re_v6,2) + 36.*pow(WA.Hhat_L8_M6_Re_v6,2) + 64.*pow(WA.Hhat_L8_M8_Re_v6,2))),
    Sum_v12lnv(16.*WA.Hhat_L2_M2_Re_v6*WA.Hhat_L2_M2_Re_v6lnv),
    Sum_v12lnvSquared(8.*pow(WA.Hhat_L2_M2_Re_v6lnv,2)),
    Sum_v13(16.*WA.Hhat_L2_M2_Re_v6*WA.Hhat_L2_M2_Re_v7 + 16.*WA.Hhat_L2_M2_Im_v6*WA.Hhat_L2_M2_Im_v7),
    Sum_v13lnv(16.*WA.Hhat_L2_M2_Re_v6lnv*WA.Hhat_L2_M2_Re_v7),
    Sum_v14(8.*(pow(WA.Hhat_L2_M2_Re_v7,2) + pow(WA.Hhat_L2_M2_Im_v7,2)))
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
							+ v*(Sum_v12 + lnv*(Sum_v12lnv + lnv*(Sum_v12lnvSquared))
							     + v*(Sum_v13 + lnv*(Sum_v13lnv)
								  + v*(Sum_v14)
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
		)
	   )
      );
}
