#include "Flux.hpp"

using WaveformUtilities::cube;
using WaveformUtilities::fifth;
using std::pow;
using std::log;

inline double nu(const double delta) {
  return (1.0-delta*delta)/4.0;
}


WaveformUtilities::TidalHeating::TidalHeating(const double delta, const double chis, const double chia)
  : N(1.6*(-chis*(1+9*chia*chia+3*chis*chis)*(1-3*nu(delta))-chia*(1+3*chia*chia+9*chis*chis)*delta*(1-nu(delta)))*nu(delta)*nu(delta))
{ }

double WaveformUtilities::TidalHeating::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  return N*cube(fifth(v));
}


WaveformUtilities::Flux_Taylor::Flux_Taylor(const double delta, const double chis, const double chia)
  : nu((1.0-delta*delta)/4.0),
    F0(6.4*pow(nu,2)),
    F2(0.002976190476190476*(-1247. - 980.*nu)),
    F3(12.566370614359172 - 2.75*chia*delta + chis*(-2.75 + 3.*nu)),
    F4(4.125*chia*chis*delta + pow(chia,2)*(2.0625 - 8.*nu) + 0.00011022927689594356*(-44711. + 567.*pow(chis,2)*(33. - 4.*nu) + 18.*nu*(9271. + 1820.*nu))),
    F5(chia*delta*(-3.6875 + 19.47222222222222*nu) - 0.0046749890678419535*(8191. + 16324.*nu) + chis*(-3.6875 + 0.1111111111111111*(227. - 157.*nu)*nu)),
    F6(63.09382653646809 - 34.033920413889426*(chis + chia*delta) + 35.604716740684324*chis*nu + 0.20561675835602827*(256. + 41.*nu) - 0.000018371546149323927*nu*(941801. + 6.*nu*(283209. + 21700.*nu))),
    F6lnv(-16.304761904761904),
    F7(0.0012986080744005427*(-78168. + nu*(300643. + 154708.*nu)))
{ }

double WaveformUtilities::Flux_Taylor::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  return Flux = F0*tenth(v)*(1 + v*v*(F2 + v*(F3 + v*(F4 + v*(F5 + v*(F6 + log(v)*F6lnv + v*F7) ) ) ) ) );
}


WaveformUtilities::Flux_Taylor8::Flux_Taylor8(const double delta, const double chis, const double chia)
  : nu((1.0-delta*delta)/4.0),
    F0(6.4*pow(nu,2)),
    F2(0.002976190476190476*(-1247. - 980.*nu)),
    F3(12.566370614359172 - 2.75*chia*delta + chis*(-2.75 + 3.*nu)),
    F4(4.125*chia*chis*delta + pow(chia,2)*(2.0625 - 8.*nu) + 0.00011022927689594356*(-44711. + 567.*pow(chis,2)*(33. - 4.*nu) + 18.*nu*(9271. + 1820.*nu))),
    F5(chia*delta*(-3.6875 + 19.47222222222222*nu) - 0.0046749890678419535*(8191. + 16324.*nu) + chis*(-3.6875 + 0.1111111111111111*(227. - 157.*nu)*nu)),
    F6(63.09382653646809 - 34.033920413889426*(chis + chia*delta) + 35.604716740684324*chis*nu + 0.20561675835602827*(256. + 41.*nu) - 0.000018371546149323927*nu*(941801. + 6.*nu*(283209. + 21700.*nu))),
    F6lnv(-16.304761904761904),
    F7(0.0012986080744005427*(-78168. + nu*(300643. + 154708.*nu))),
    F8(-117.50439072267731),
    F8lnv(52.74308390022676)
{ }

double WaveformUtilities::Flux_Taylor8::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  const double lnv = log(v);
  return Flux = F0*tenth(v)*(1 + v*v*(F2 + v*(F3 + v*(F4 + v*(F5 + v*(F6 + lnv*F6lnv + v*(F7 + v*(F8 + lnv*F8lnv) ) ) ) ) ) ) );
}


WaveformUtilities::Flux_Pade44LogConst::Flux_Pade44LogConst(const double delta, const double chis, const double chia)
  : nu((1.0-delta*delta)/4.0), N((32*nu*nu)/5.),
    f2(0.002976190476190476*(-1247. - 980.*nu)),
    f3(12.566370614359172 - 2.75*chia*delta + chis*(-2.75 + 3.*nu)),
    f4(4.125*chia*chis*delta + pow(chia,2)*(2.0625 - 8.*nu) + 0.00011022927689594356*(-44711. + 567.*pow(chis,2)*(33. - 4.*nu) + 18.*nu*(9271. + 1820.*nu))),
    f5(chia*delta*(-3.6875 + 19.47222222222222*nu) - 0.0046749890678419535*(8191. + 16324.*nu) + chis*(-3.6875 + 0.1111111111111111*(227. - 157.*nu)*nu)),
    f6(63.09382653646809 - 34.033920413889426*(chis + chia*delta) + 35.604716740684324*chis*nu + 0.20561675835602827*(256. + 41.*nu) - 0.000018371546149323927*nu*(941801. + 6.*nu*(283209. + 21700.*nu))),
    f6lnv(-16.304761904761904),
    f7(0.0012986080744005427*(-78168. + nu*(300643. + 154708.*nu))),
    f8(-117.50439072267731),
    f8lnv(52.74308390022676),
    FNum0(pow(f4,4) + pow(f3*f5 - 1.*f2*f6,2) - 1.*pow(f4,2)*(3.*f3*f5 + 2.*f2*f6) - 1.*(pow(f3,3) + pow(f2,2)*f5)*f7 + 2.*f4*(pow(f3,2)*f6 + f2*(pow(f5,2) + f3*f7))),
    FNum0lnv(2.*pow(f3,2)*f4*f6lnv + 2.*pow(f2,2)*f6*f6lnv + f2*(-2.*pow(f4,2)*f6lnv - 2.*f3*f5*f6lnv)),
    FNum0lnv2(pow(f2,2)*pow(f6lnv,2)),
    FNum1(-1.*pow(f4,3)*f5 + f3*f4*(2.*pow(f5,2) + f4*f6) - 1.*pow(f3,2)*(2.*f5*f6 + f4*f7) + pow(f3,3)*f8 + pow(f2,2)*(-1.*f6*f7 + f5*f8) + f2*(-1.*pow(f5,3) + pow(f4,2)*f7 + f3*(pow(f6,2) + f5*f7 - 2.*f4*f8))),
    FNum1lnv(f3*pow(f4,2)*f6lnv - 2.*pow(f3,2)*f5*f6lnv + pow(f3,3)*f8lnv + f2*f3*(2.*f6*f6lnv - 2.*f4*f8lnv) + pow(f2,2)*(-1.*f6lnv*f7 + f5*f8lnv)),
    FNum1lnv2(f2*f3*pow(f6lnv,2)),
    FNum2(-1.*pow(f4,3)*f6 + f3*f5*(-1.*pow(f5,2) + f3*f7) + pow(f4,2)*(pow(f5,2) + f3*f7) + pow(f2,3)*(pow(f6,2) - 1.*f5*f7) - 1.*pow(f3,2)*f4*f8 + f2*(pow(f4,4) - 1.*(pow(f3,2) + f6)*(-1.*pow(f5,2) + f3*f7) + f4*(2.*pow(f3,2)*f6 + pow(f6,2) - 3.*f5*f7) + f3*f5*f8 + pow(f4,2)*(-3.*f3*f5 + f8)) + pow(f2,2)*(-2.*pow(f4,2)*f6 + pow(f7,2) + 2.*f4*(pow(f5,2) + f3*f7) - 1.*f6*(2.*f3*f5 + f8))),
    FNum2lnv(-1.*pow(f4,3)*f6lnv + 2.*pow(f2,3)*f6*f6lnv - 1.*pow(f3,2)*f4*f8lnv + pow(f2,2)*(-2.*pow(f4,2)*f6lnv - 2.*f3*f5*f6lnv - 1.*f6lnv*f8 - 1.*f6*f8lnv) + f2*(2.*pow(f3,2)*f4*f6lnv + pow(f5,2)*f6lnv + 2.*f4*f6*f6lnv + pow(f4,2)*f8lnv + f3*(-1.*f6lnv*f7 + f5*f8lnv))),
    FNum2lnv2(pow(f2,3)*pow(f6lnv,2) + f2*f4*pow(f6lnv,2) - 1.*pow(f2,2)*f6lnv*f8lnv),
    FNum3(-1.*pow(f3,4)*f7 + pow(f2,2)*(-1.*pow(f5,3) + pow(f4,2)*f7) - 1.*f4*(pow(f5,3) - 2.*f4*f5*f6 + pow(f4,2)*f7) + pow(f3,3)*(pow(f5,2) + 2.*f4*f6 + f2*f8) + pow(f3,2)*(-3.*pow(f4,2)*f5 - 4.*f2*f5*f6 + f2*f4*f7 + f6*f7 - 1.*f5*f8) + pow(f2,3)*(-1.*f6*f7 + f5*f8) - 1.*f2*(pow(f4,3)*f5 + f5*(pow(f6,2) - 1.*f5*f7) + f4*(-1.*f6*f7 + f5*f8)) + f3*(pow(f4,4) + pow(f5,2)*f6 + pow(f4,2)*(-1.*f2*f6 + f8) - 2.*f4*(-2.*f2*pow(f5,2) + pow(f6,2) + pow(f2,2)*f8) + f2*(-1.*pow(f7,2) + f6*(2.*f2*f6 + f8)))),
    FNum3lnv(2.*pow(f3,3)*f4*f6lnv + 2.*pow(f4,2)*f5*f6lnv + pow(f2,2)*f3*(4.*f6*f6lnv - 2.*f4*f8lnv) + f3*(pow(f5,2)*f6lnv - 4.*f4*f6*f6lnv + pow(f4,2)*f8lnv) + pow(f3,2)*(f6lnv*f7 - 1.*f5*f8lnv) + pow(f2,3)*(-1.*f6lnv*f7 + f5*f8lnv) + f2*(-4.*pow(f3,2)*f5*f6lnv - 2.*f5*f6*f6lnv + pow(f3,3)*f8lnv + f4*(f6lnv*f7 - 1.*f5*f8lnv) + f3*(-1.*pow(f4,2)*f6lnv + f6lnv*f8 + f6*f8lnv))),
    FNum3lnv2(2.*pow(f2,2)*f3*pow(f6lnv,2) - 2.*f3*f4*pow(f6lnv,2) + f2*(-1.*f5*pow(f6lnv,2) + f3*f6lnv*f8lnv)),
    FNum4(pow(f4,5) + pow(f5,4) - 3.*f4*pow(f5,2)*f6 - 2.*pow(f3,3)*(f5*f6 + f4*f7) + pow(f4,2)*(pow(f6,2) + 2.*f5*f7) + pow(f3,4)*f8 - 1.*pow(f4,3)*f8 + pow(f2,2)*(pow(f5,2)*f6 + 2.*f4*pow(f6,2) - 4.*f4*f5*f7 - 2.*f3*f6*f7 + pow(f4,2)*f8 + 2.*f3*f5*f8) - 2.*f3*(2.*pow(f4,3)*f5 - 1.*f5*pow(f6,2) + pow(f5,2)*f7 + f4*f6*f7 - 1.*f4*f5*f8) + pow(f2,3)*(pow(f7,2) - 1.*f6*f8) + pow(f3,2)*(3.*f4*(pow(f5,2) + f4*f6) + pow(f7,2) - 1.*f6*f8) + f2*(3.*pow(f4,2)*pow(f5,2) - 3.*pow(f4,3)*f6 - 1.*pow(f6,3) + 2.*f5*f6*f7 - 2.*f3*(pow(f5,3) + f4*f5*f6 - 2.*pow(f4,2)*f7) - 1.*pow(f5,2)*f8 + pow(f3,2)*(pow(f6,2) + 2.*f5*f7 - 3.*f4*f8) + f4*(-1.*pow(f7,2) + f6*f8))),
    FNum4lnv(-2.*pow(f3,3)*f5*f6lnv - 3.*f4*pow(f5,2)*f6lnv + 2.*pow(f4,2)*f6*f6lnv + pow(f3,4)*f8lnv - 1.*pow(f4,3)*f8lnv + pow(f2,3)*(-1.*f6lnv*f8 - 1.*f6*f8lnv) + pow(f3,2)*(3.*pow(f4,2)*f6lnv - 1.*f6lnv*f8 - 1.*f6*f8lnv) + pow(f2,2)*(pow(f5,2)*f6lnv + 4.*f4*f6*f6lnv + pow(f4,2)*f8lnv + f3*(-2.*f6lnv*f7 + 2.*f5*f8lnv)) + f3*(4.*f5*f6*f6lnv + f4*(-2.*f6lnv*f7 + 2.*f5*f8lnv)) + f2*(-3.*pow(f4,3)*f6lnv - 2.*f3*f4*f5*f6lnv - 3.*pow(f6,2)*f6lnv + pow(f3,2)*(2.*f6*f6lnv - 3.*f4*f8lnv) + f5*(2.*f6lnv*f7 - 1.*f5*f8lnv) + f4*(f6lnv*f8 + f6*f8lnv))),
    FNum4lnv2(2.*pow(f2,2)*f4*pow(f6lnv,2) + pow(f4,2)*pow(f6lnv,2) + 2.*f3*f5*pow(f6lnv,2) - 1.*pow(f2,3)*f6lnv*f8lnv - 1.*pow(f3,2)*f6lnv*f8lnv + f2*(pow(f3,2)*pow(f6lnv,2) - 3.*f6*pow(f6lnv,2) + f4*f6lnv*f8lnv)),
    FNum4lnv3(-1.*f2*pow(f6lnv,3)),
    FDen0(pow(f4,4) + pow(f3*f5 - 1.*f2*f6,2) - 1.*pow(f4,2)*(3.*f3*f5 + 2.*f2*f6) - 1.*(pow(f3,3) + pow(f2,2)*f5)*f7 + 2.*f4*(pow(f3,2)*f6 + f2*(pow(f5,2) + f3*f7))),
    FDen0lnv(2.*pow(f3,2)*f4*f6lnv + 2.*pow(f2,2)*f6*f6lnv + f2*(-2.*pow(f4,2)*f6lnv - 2.*f3*f5*f6lnv)),
    FDen0lnv2(pow(f2,2)*pow(f6lnv,2)),
    FDen1(-1.*pow(f4,3)*f5 + f3*f4*(2.*pow(f5,2) + f4*f6) - 1.*pow(f3,2)*(2.*f5*f6 + f4*f7) + pow(f3,3)*f8 + pow(f2,2)*(-1.*f6*f7 + f5*f8) + f2*(-1.*pow(f5,3) + pow(f4,2)*f7 + f3*(pow(f6,2) + f5*f7 - 2.*f4*f8))),
    FDen1lnv(f3*pow(f4,2)*f6lnv - 2.*pow(f3,2)*f5*f6lnv + pow(f3,3)*f8lnv + f2*f3*(2.*f6*f6lnv - 2.*f4*f8lnv) + pow(f2,2)*(-1.*f6lnv*f7 + f5*f8lnv)),
    FDen1lnv2(f2*f3*pow(f6lnv,2)),
    FDen2(-1.*pow(f4,3)*f6 + pow(f3,2)*f5*f7 + pow(f4,2)*(pow(f5,2) + f3*f7 + f2*f8) + f4*(f2*(pow(f6,2) - 3.*f5*f7) - 1.*pow(f3,2)*f8) - 1.*f3*(pow(f5,3) + f2*f6*f7 - 1.*f2*f5*f8) + f2*(pow(f5,2)*f6 + f2*pow(f7,2) - 1.*f2*f6*f8)),
    FDen2lnv(-1.*pow(f4,3)*f6lnv - 1.*pow(f3,2)*f4*f8lnv + pow(f2,2)*(-1.*f6lnv*f8 - 1.*f6*f8lnv) + f2*(pow(f5,2)*f6lnv + 2.*f4*f6*f6lnv + pow(f4,2)*f8lnv + f3*(-1.*f6lnv*f7 + f5*f8lnv))),
    FDen2lnv2(f2*f4*pow(f6lnv,2) - 1.*pow(f2,2)*f6lnv*f8lnv),
    FDen3(-1.*pow(f4,3)*f7 + f2*f5*(-1.*pow(f6,2) + f5*f7) + pow(f4,2)*(2.*f5*f6 + f3*f8) + pow(f3,2)*(f6*f7 - 1.*f5*f8) - 1.*f4*(pow(f5,3) + f6*(2.*f3*f6 - 1.*f2*f7) + f2*f5*f8) + f3*(pow(f5,2)*f6 - 1.*f2*pow(f7,2) + f2*f6*f8)),
    FDen3lnv(2.*pow(f4,2)*f5*f6lnv + f3*(pow(f5,2)*f6lnv - 4.*f4*f6*f6lnv + pow(f4,2)*f8lnv) + pow(f3,2)*(f6lnv*f7 - 1.*f5*f8lnv) + f2*(-2.*f5*f6*f6lnv + f4*(f6lnv*f7 - 1.*f5*f8lnv) + f3*(f6lnv*f8 + f6*f8lnv))),
    FDen3lnv2(-2.*f3*f4*pow(f6lnv,2) + f2*(-1.*f5*pow(f6lnv,2) + f3*f6lnv*f8lnv)),
    FDen4(pow(f5,4) + pow(f4,2)*pow(f6,2) - 1.*f2*pow(f6,3) + pow(f3,2)*pow(f7,2) - 1.*f4*f7*(2.*f3*f6 + f2*f7) - 1.*pow(f4,3)*f8 - 1.*pow(f3,2)*f6*f8 + f2*f4*f6*f8 - 1.*pow(f5,2)*(3.*f4*f6 + 2.*f3*f7 + f2*f8) + 2.*f5*((pow(f4,2) + f2*f6)*f7 + f3*(pow(f6,2) + f4*f8))),
    FDen4lnv(-3.*f4*pow(f5,2)*f6lnv + 2.*pow(f4,2)*f6*f6lnv - 1.*pow(f4,3)*f8lnv + pow(f3,2)*(-1.*f6lnv*f8 - 1.*f6*f8lnv) + f3*(4.*f5*f6*f6lnv + f4*(-2.*f6lnv*f7 + 2.*f5*f8lnv)) + f2*(-3.*pow(f6,2)*f6lnv + f5*(2.*f6lnv*f7 - 1.*f5*f8lnv) + f4*(f6lnv*f8 + f6*f8lnv))),
    FDen4lnv2(pow(f4,2)*pow(f6lnv,2) + 2.*f3*f5*pow(f6lnv,2) - 1.*pow(f3,2)*f6lnv*f8lnv + f2*(-3.*f6*pow(f6lnv,2) + f4*f6lnv*f8lnv)),
    FDen4lnv3(-1.*f2*pow(f6lnv,3))
{ }

double WaveformUtilities::Flux_Pade44LogConst::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  const double lnv = log(v);
  return Flux = N * pow(v,10) * (FNum0 + lnv*(FNum0lnv + lnv*FNum0lnv2) + v*(FNum1 + lnv*(FNum1lnv + lnv*FNum1lnv2) + v*(FNum2 + lnv*(FNum2lnv + lnv*FNum2lnv2) + v*(FNum3 + lnv*(FNum3lnv + lnv*FNum3lnv2) + v*(FNum4 + lnv*(FNum4lnv +lnv*(FNum4lnv2 + lnv*FNum4lnv3) ) ) ) ) ) )
    / (FDen0 + lnv*(FDen0lnv + lnv*FDen0lnv2) + v*(FDen1 +lnv*(FDen1lnv +lnv*FDen1lnv2) + v*(FDen2 + lnv*(FDen2lnv + lnv*FDen2lnv2) + v*(FDen3 + lnv*(FDen3lnv + lnv*FDen3lnv2) + v*(FDen4 + lnv*(FDen4lnv + lnv*(FDen4lnv2 + lnv*FDen4lnv3) ) ) ) ) ) );
}


WaveformUtilities::Flux_Pade44LogFac::Flux_Pade44LogFac(const double delta, const double chis, const double chia)
  : nu((1.0-delta*delta)/4.0), N((32*nu*nu)/5.),
    vPole( (2*(3 + nu))/(4*chis*(-2 + nu) + sqrt((-3 - nu)*(-36 + 35*nu))) ), // The pole of the 2,2 approximant of the energy function, with lowest-order spin dependence
    //vPole( sqrt( (1+nu/3.0) / (3.0-35.0*nu/12.0) ) ), // Eq. (41) of PRD 78, 104020
    vLSO( 2*sqrt(((3 + nu)*(-1 + 2*(3 + nu)*sqrt(1/(144 + nu*(-81 + 4*nu)))))/(-36 + 35*nu)) ), // Table 1 of PRD 63, 044023
    flogfac6(-16.304761904761904),
    flogfac8(52.74308390022676),
    f1(-1./vPole),
    f2(0.002976190476190476*(-1247. - 980.*nu)),
    f3((0.002976190476190476*(1247. + 980.*nu + 84.*(50.26548245743669 - 11.*chia*delta + chis*(-11. + 12.*nu))*vPole))/vPole),
    f4((0.00011022927689594356*(2268.*(-50.26548245743669 + 11.*chia*delta + chis*(11. - 12.*nu)) + (-44711. + 18711.*pow(chis,2) + 166878.*nu + 63.*(297.*chia*(chia + 2.*chis*delta) - 36.*(32.*pow(chia,2) + pow(chis,2))*nu + 520.*pow(nu,2)))*vPole))/vPole),
    f5((0.00005511463844797178*(89422. - 74844.*chia*chis*delta + 1134.*pow(chis,2)*(-33. + 4.*nu) + 1134.*pow(chia,2)*(-33. + 128.*nu) - 36.*nu*(9271. + 1820.*nu) - 9.*(7434.*(chis + chia*delta) - 56.*(908.*chis + 701.*chia*delta)*nu + 35168.*chis*pow(nu,2) + 9.42477796076938*(8191. + 16324.*nu))*vPole))/vPole),
    f6(138.33491616358515 - 8.872053442382263*nu - 31.217923280423282*pow(nu,2) - 2.3919753086419755*pow(nu,3) + 0.5235987755982988*(-65.*(chis + chia*delta) + 68.*chis*nu) + (0.000496031746031746*(7434.*(chis + chia*delta) - 56.*(908.*chis + 701.*chia*delta)*nu + 35168.*chis*pow(nu,2) + 9.42477796076938*(8191. + 16324.*nu)))/vPole - 8.152380952380952*log(16.*pow(vLSO,2))),
    f7((4.771830168655566e-9*(-1.795894300416533e10 + 7.132257270479993e9*(chis + chia*delta) + 1925.*(-3.876071883257858e6*chis*nu - 22384.262781670663*(256. + 41.*nu) + 2.*nu*(941801. + 6.*nu*(283209. + 21700.*nu)) + 141.3716694115407*(-78168. + nu*(300643. + 154708.*nu))*vPole) + 1.70843904e9*log(16.*pow(vLSO,2))))/vPole),
    f8((1.5731308248315051e-10*(-4.5268533641080023e11*vPole - 15015.*(549.7787143782137*(-78168. + nu*(300643. + 154708.*nu)) + 5.055278461580653e7*vPole) + 3.3527461968e11*vPole*log(4.*vLSO)))/vPole),
    FNum0(pow(f4,4) - 3.*f3*pow(f4,2)*f5 + pow(f3,2)*(pow(f5,2) + 2.*f4*f6) - 1.*pow(f3,3)*f7 + pow(f2,2)*(pow(f6,2) - 1.*f5*f7) + f2*(2.*f4*pow(f5,2) - 2.*pow(f4,2)*f6 + f3*(-2.*f5*f6 + 2.*f4*f7)) + f1*(-1.*pow(f5,3) + 2.*f4*f5*f6 - 1.*pow(f4,2)*f7 + f3*(-1.*pow(f6,2) + f5*f7))),
    FNum1(-1.*pow(f4,3)*f5 + f3*(2.*f4*pow(f5,2) + pow(f4,2)*f6) + pow(f3,2)*(-2.*f5*f6 - 1.*f4*f7) + pow(f1,2)*(-1.*pow(f5,3) + 2.*f4*f5*f6 - 1.*pow(f4,2)*f7 + f3*(-1.*pow(f6,2) + f5*f7)) + pow(f3,3)*f8 + pow(f2,2)*(-1.*f6*f7 + f5*f8) + f2*(-1.*pow(f5,3) + pow(f4,2)*f7 + f3*(pow(f6,2) + f5*f7 - 2.*f4*f8)) + f1*(pow(f4,4) + pow(f5,2)*f6 - 1.*f4*pow(f6,2) + pow(f3,2)*(pow(f5,2) + 2.*f4*f6) - 1.*pow(f3,3)*f7 - 1.*f4*f5*f7 + pow(f2,2)*(pow(f6,2) - 1.*f5*f7) + f2*(2.*f4*pow(f5,2) - 2.*pow(f4,2)*f6 + f3*(-2.*f5*f6 + 2.*f4*f7)) + pow(f4,2)*f8 + f3*(-3.*pow(f4,2)*f5 + f6*f7 - 1.*f5*f8))),
    FNum2(pow(f4,2)*pow(f5,2) - 1.*pow(f4,3)*f6 + f3*(-1.*pow(f5,3) + pow(f4,2)*f7) + pow(f2,3)*(pow(f6,2) - 1.*f5*f7) + pow(f3,2)*(f5*f7 - 1.*f4*f8) + pow(f2,2)*(2.*f4*pow(f5,2) - 2.*pow(f4,2)*f6 + pow(f7,2) + f3*(-2.*f5*f6 + 2.*f4*f7) - 1.*f6*f8) + pow(f1,2)*(pow(f5,2)*f6 - 1.*f4*pow(f6,2) - 1.*f4*f5*f7 + pow(f4,2)*f8 + f3*(f6*f7 - 1.*f5*f8)) + f2*(pow(f4,4) + pow(f5,2)*f6 + f4*pow(f6,2) + pow(f3,2)*(pow(f5,2) + 2.*f4*f6) - 1.*pow(f3,3)*f7 - 3.*f4*f5*f7 + pow(f4,2)*f8 + f3*(-3.*pow(f4,2)*f5 - 1.*f6*f7 + f5*f8)) + f1*(-1.*pow(f4,3)*f5 - 1.*f5*pow(f6,2) + pow(f5,2)*f7 + f4*f6*f7 + pow(f3,2)*(-2.*f5*f6 - 1.*f4*f7) + pow(f3,3)*f8 - 1.*f4*f5*f8 + pow(f2,2)*(-1.*f6*f7 + f5*f8) + f3*(2.*f4*pow(f5,2) + pow(f4,2)*f6 - 1.*pow(f7,2) + f6*f8) + f2*(-2.*pow(f5,3) + 2.*f4*f5*f6 + f3*(2.*f5*f7 - 2.*f4*f8)))),
    FNum3(-1.*f4*pow(f5,3) + 2.*pow(f4,2)*f5*f6 + pow(f3,3)*(pow(f5,2) + 2.*f4*f6) - 1.*pow(f3,4)*f7 - 1.*pow(f4,3)*f7 + f3*(pow(f4,4) + pow(f5,2)*f6 - 2.*f4*pow(f6,2) + pow(f4,2)*f8) + pow(f3,2)*(-3.*pow(f4,2)*f5 + f6*f7 - 1.*f5*f8) + pow(f2,3)*(-1.*f6*f7 + f5*f8) + pow(f2,2)*(-1.*pow(f5,3) + pow(f4,2)*f7 + f3*(2.*pow(f6,2) - 2.*f4*f8)) + f1*(pow(f4,2)*pow(f5,2) - 1.*pow(f4,3)*f6 + pow(f6,3) + f3*(-2.*pow(f5,3) + 2.*f4*f5*f6) - 2.*f5*f6*f7 + f4*pow(f7,2) + pow(f5,2)*f8 - 1.*f4*f6*f8 + pow(f3,2)*(-1.*pow(f6,2) + 2.*f5*f7 - 1.*f4*f8) + f2*(2.*pow(f5,2)*f6 - 4.*f4*f5*f7 + 2.*pow(f4,2)*f8) + pow(f2,2)*(pow(f7,2) - 1.*f6*f8)) + pow(f1,2)*(-1.*f5*pow(f6,2) + pow(f5,2)*f7 + f4*f6*f7 - 1.*f4*f5*f8 + f3*(-1.*pow(f7,2) + f6*f8)) + f2*(-1.*pow(f4,3)*f5 - 1.*f5*pow(f6,2) + pow(f5,2)*f7 + f4*f6*f7 + pow(f3,2)*(-4.*f5*f6 + f4*f7) + pow(f3,3)*f8 - 1.*f4*f5*f8 + f3*(4.*f4*pow(f5,2) - 1.*pow(f4,2)*f6 - 1.*pow(f7,2) + f6*f8))),
    FNum4(pow(f4,5) + pow(f5,4) - 3.*f4*pow(f5,2)*f6 + pow(f4,2)*pow(f6,2) + 2.*pow(f4,2)*f5*f7 + pow(f3,3)*(-2.*f5*f6 - 2.*f4*f7) + pow(f3,4)*f8 - 1.*pow(f4,3)*f8 + f3*(-4.*pow(f4,3)*f5 + 2.*f5*pow(f6,2) - 2.*pow(f5,2)*f7 - 2.*f4*f6*f7 + 2.*f4*f5*f8) + pow(f2,3)*(pow(f7,2) - 1.*f6*f8) + pow(f3,2)*(3.*f4*pow(f5,2) + 3.*pow(f4,2)*f6 + pow(f7,2) - 1.*f6*f8) + f2*(3.*pow(f4,2)*pow(f5,2) - 3.*pow(f4,3)*f6 - 1.*pow(f6,3) + 2.*f5*f6*f7 - 1.*f4*pow(f7,2) + f3*(-2.*pow(f5,3) - 2.*f4*f5*f6 + 4.*pow(f4,2)*f7) - 1.*pow(f5,2)*f8 + f4*f6*f8 + pow(f3,2)*(pow(f6,2) + 2.*f5*f7 - 3.*f4*f8)) + pow(f2,2)*(pow(f5,2)*f6 + 2.*f4*pow(f6,2) - 4.*f4*f5*f7 + pow(f4,2)*f8 + f3*(-2.*f6*f7 + 2.*f5*f8)) + pow(f1,2)*(pow(f6,3) - 2.*f5*f6*f7 + pow(f5,2)*f8 - 1.*f4*(-1.*pow(f7,2) + f6*f8)) + f1*(-2.*f4*pow(f5,3) + 4.*pow(f4,2)*f5*f6 - 2.*pow(f4,3)*f7 + f3*(2.*pow(f5,2)*f6 - 4.*f4*pow(f6,2) + 2.*pow(f4,2)*f8) + pow(f3,2)*(2.*f6*f7 - 2.*f5*f8) + f2*(2.*f4*f6*f7 + 2.*f5*(-1.*pow(f6,2) + f5*f7) - 2.*f4*f5*f8 - 2.*f3*(pow(f7,2) - 1.*f6*f8)))),
    FDen0(pow(f4,4) - 3.*f3*pow(f4,2)*f5 + pow(f3,2)*(pow(f5,2) + 2.*f4*f6) - 1.*pow(f3,3)*f7 + pow(f2,2)*(pow(f6,2) - 1.*f5*f7) + f2*(2.*f4*pow(f5,2) - 2.*pow(f4,2)*f6 + f3*(-2.*f5*f6 + 2.*f4*f7)) + f1*(-1.*pow(f5,3) + 2.*f4*f5*f6 - 1.*pow(f4,2)*f7 + f3*(-1.*pow(f6,2) + f5*f7))),
    FDen1(-1.*pow(f4,3)*f5 + f3*(2.*f4*pow(f5,2) + pow(f4,2)*f6) + pow(f3,2)*(-2.*f5*f6 - 1.*f4*f7) + pow(f3,3)*f8 + pow(f2,2)*(-1.*f6*f7 + f5*f8) + f2*(-1.*pow(f5,3) + pow(f4,2)*f7 + f3*(pow(f6,2) + f5*f7 - 2.*f4*f8)) + f1*(pow(f5,2)*f6 - 1.*f4*pow(f6,2) - 1.*f4*f5*f7 + pow(f4,2)*f8 + f3*(f6*f7 - 1.*f5*f8))),
    FDen2(pow(f4,2)*pow(f5,2) - 1.*pow(f4,3)*f6 + f3*(-1.*pow(f5,3) + pow(f4,2)*f7) + pow(f3,2)*(f5*f7 - 1.*f4*f8) + pow(f2,2)*(pow(f7,2) - 1.*f6*f8) + f2*(pow(f5,2)*f6 + f4*(pow(f6,2) - 3.*f5*f7) + pow(f4,2)*f8 + f3*(-1.*f6*f7 + f5*f8)) + f1*(-1.*f5*pow(f6,2) + pow(f5,2)*f7 + f4*f6*f7 - 1.*f4*f5*f8 + f3*(-1.*pow(f7,2) + f6*f8))),
    FDen3(-1.*f4*pow(f5,3) + 2.*pow(f4,2)*f5*f6 - 1.*pow(f4,3)*f7 + f3*(pow(f5,2)*f6 - 2.*f4*pow(f6,2) + pow(f4,2)*f8) + pow(f3,2)*(f6*f7 - 1.*f5*f8) + f1*(pow(f6,3) - 2.*f5*f6*f7 + f4*pow(f7,2) + pow(f5,2)*f8 - 1.*f4*f6*f8) + f2*(-1.*f5*pow(f6,2) + pow(f5,2)*f7 + f4*f6*f7 - 1.*f4*f5*f8 + f3*(-1.*pow(f7,2) + f6*f8))),
    FDen4(pow(f5,4) - 3.*f4*pow(f5,2)*f6 + pow(f4,2)*pow(f6,2) + 2.*pow(f4,2)*f5*f7 - 1.*pow(f4,3)*f8 + pow(f3,2)*(pow(f7,2) - 1.*f6*f8) + f2*(-1.*pow(f6,3) + 2.*f5*f6*f7 - 1.*f4*pow(f7,2) - 1.*pow(f5,2)*f8 + f4*f6*f8) + f3*(-2.*pow(f5,2)*f7 - 2.*f4*f6*f7 + 2.*f5*(pow(f6,2) + f4*f8)))
{ }

double WaveformUtilities::Flux_Pade44LogFac::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  return Flux = N * pow(v,10) * (vPole/(vPole-v)) * (1.0 + log(v/vLSO)*pow(v,6)*(flogfac6 + v*v*flogfac8))
    * (FNum0 + v*(FNum1 + v*(FNum2 + v*(FNum3 + v*(FNum4)))))
    / (FDen0 + v*(FDen1 + v*(FDen2 + v*(FDen3 + v*(FDen4)))));
}


WaveformUtilities::Flux_SumAmplitudes::Flux_SumAmplitudes(const double delta, const double chis, const double chia)
  : WaveformAmplitudesSumMMagSquared(WaveformAmplitudes(delta, chis, chis)),
    N(1.0/(16.0*M_PI))
{ }

double WaveformUtilities::Flux_SumAmplitudes::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  return Flux = N*WaveformUtilities::sixth(v)*SumMMagSquared(v);
}
