Flux_Taylor::Flux_Taylor(const double delta, const double chis)
  : nu((1.0-delta*delta)/4.0),
    F0((32*std::pow(nu,2))/5.),
    F2((-1247 - 980*nu)/336.),
    F3(chis*(-2.75 + 3*nu) + 4*M_PI),
    F4((-44711 - 567*std::pow(chis,2)*(-33 + 4*nu) + 18*nu*(9271 + 1820*nu))/9072.),
    F5((3*std::pow(chis,3)*(-1 + 3*nu))/4. - (chis*(567 + 4*nu*(-935 + 628*nu)))/144. - ((8191 + 16324*nu)*M_PI)/672.),
    F6(95.10839000836025 - (1712*EulerGamma)/105. - (nu*(941801 + 6*nu*(283209 + 21700*nu)))/54432. - (65*chis*M_PI)/6. + (34*chis*nu*M_PI)/3. + ((256 + 41*nu)*std::pow(M_PI,2))/48. - (1712*std::log(4))/105.),
    F6lnv(-16.304761904761904),
    F7((5*(-78168 + nu*(300643 + 154708*nu))*M_PI)/12096.)
{ }

double Flux_Taylor::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  return Flux = F0*tenth(v)*(1 + v*v*(F2 + v*(F3 + v*(F4 + v*(F5 + v*(F6 + std::log(v)*F6lnv + v*F7) ) ) ) ) );
}


Flux_Taylor8::Flux_Taylor8(const double delta, const double chis)
  : nu((1.0-delta*delta)/4.0),
    F0((32*std::pow(nu,2))/5.),
    F2((-1247 - 980*nu)/336.),
    F3(chis*(-2.75 + 3*nu) + 4*M_PI),
    F4((-44711 - 567*std::pow(chis,2)*(-33 + 4*nu) + 18*nu*(9271 + 1820*nu))/9072.),
    F5((3*std::pow(chis,3)*(-1 + 3*nu))/4. - (chis*(567 + 4*nu*(-935 + 628*nu)))/144. - ((8191 + 16324*nu)*M_PI)/672.),
    F6(95.10839000836025 - (1712*EulerGamma)/105. - (nu*(941801 + 6*nu*(283209 + 21700*nu)))/54432. - (65*chis*M_PI)/6. + (34*chis*nu*M_PI)/3. + ((256 + 41*nu)*std::pow(M_PI,2))/48. - (1712*std::log(4))/105.),
    F6lnv(-16.304761904761904),
    F7((5*(-78168 + nu*(300643 + 154708*nu))*M_PI)/12096.),
    F8(-117.5043907226773),
    F8lnv(52.74308390022676)
{ }

double Flux_Taylor8::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  const double lnv = std::log(v);
  return Flux = F0*tenth(v)*(1 + v*v*(F2 + v*(F3 + v*(F4 + v*(F5 + v*(F6 + lnv*F6lnv + v*(F7 + v*(F8 + lnv*F8lnv) ) ) ) ) ) ) );
}


Flux_Pade44LogConst::Flux_Pade44LogConst(const double delta, const double chis)
  : nu((1.0-delta*delta)/4.0), N((32*nu*nu)/5.),
    f2((-1247 - 980*nu)/336.),
    f3(chis*(-2.75 + 3*nu) + 4*M_PI),
    f4((-44711 - 567*std::pow(chis,2)*(-33 + 4*nu) + 18*nu*(9271 + 1820*nu))/9072.),
    f5((3*std::pow(chis,3)*(-1 + 3*nu))/4. - (chis*(567 + 4*nu*(-935 + 628*nu)))/144. - ((8191 + 16324*nu)*M_PI)/672.),
    f6(95.10839000836025 - (1712*EulerGamma)/105. - (nu*(941801 + 6*nu*(283209 + 21700*nu)))/54432. - (65*chis*M_PI)/6. + (34*chis*nu*M_PI)/3. + ((256 + 41*nu)*std::pow(M_PI,2))/48. - (1712*std::log(4))/105.),
    f6lnv(-16.304761904761904),
    f7((5*(-78168 + nu*(300643 + 154708*nu))*M_PI)/12096.),
    f8(-101.65745990813167 + (232597*EulerGamma)/4410. - (1369*std::pow(M_PI,2))/126. + (39931*std::log(2))/294. - (47385*std::log(3))/1568.),
    f8lnv(52.74308390022676),
    FNum0(std::pow(f4,4) + std::pow(f3*f5 - f2*f6,2) - std::pow(f4,2)*(3*f3*f5 + 2*f2*f6) - (std::pow(f3,3) + std::pow(f2,2)*f5)*f7 + 2*f4*(std::pow(f3,2)*f6 + f2*(std::pow(f5,2) + f3*f7))),
    FNum0lnv(2*std::pow(f3,2)*f4*f6lnv + 2*std::pow(f2,2)*f6*f6lnv + f2*(-2*std::pow(f4,2)*f6lnv - 2*f3*f5*f6lnv)),
    FNum0lnv2(std::pow(f2,2)*std::pow(f6lnv,2)),
    FNum1(-(std::pow(f4,3)*f5) + f3*f4*(2*std::pow(f5,2) + f4*f6) - std::pow(f3,2)*(2*f5*f6 + f4*f7) + std::pow(f3,3)*f8 + std::pow(f2,2)*(-(f6*f7) + f5*f8) + f2*(-std::pow(f5,3) + std::pow(f4,2)*f7 + f3*(std::pow(f6,2) + f5*f7 - 2*f4*f8))),
    FNum1lnv(f3*std::pow(f4,2)*f6lnv - 2*std::pow(f3,2)*f5*f6lnv + std::pow(f3,3)*f8lnv + f2*f3*(2*f6*f6lnv - 2*f4*f8lnv) + std::pow(f2,2)*(-(f6lnv*f7) + f5*f8lnv)),
    FNum1lnv2(f2*f3*std::pow(f6lnv,2)),
    FNum2(-(std::pow(f4,3)*f6) + f3*f5*(-std::pow(f5,2) + f3*f7) + std::pow(f4,2)*(std::pow(f5,2) + f3*f7) + std::pow(f2,3)*(std::pow(f6,2) - f5*f7) - std::pow(f3,2)*f4*f8 + f2*(std::pow(f4,4) - (std::pow(f3,2) + f6)*(-std::pow(f5,2) + f3*f7) + f4*(2*std::pow(f3,2)*f6 + std::pow(f6,2) - 3*f5*f7) + f3*f5*f8 + std::pow(f4,2)*(-3*f3*f5 + f8)) + std::pow(f2,2)*(-2*std::pow(f4,2)*f6 + std::pow(f7,2) + 2*f4*(std::pow(f5,2) + f3*f7) - f6*(2*f3*f5 + f8))),
    FNum2lnv(-(std::pow(f4,3)*f6lnv) + 2*std::pow(f2,3)*f6*f6lnv - std::pow(f3,2)*f4*f8lnv + std::pow(f2,2)*(-2*std::pow(f4,2)*f6lnv - 2*f3*f5*f6lnv - f6lnv*f8 - f6*f8lnv) + f2*(2*std::pow(f3,2)*f4*f6lnv + std::pow(f5,2)*f6lnv + 2*f4*f6*f6lnv + std::pow(f4,2)*f8lnv + f3*(-(f6lnv*f7) + f5*f8lnv))),
    FNum2lnv2(std::pow(f2,3)*std::pow(f6lnv,2) + f2*f4*std::pow(f6lnv,2) - std::pow(f2,2)*f6lnv*f8lnv),
    FNum3(-(std::pow(f3,4)*f7) + std::pow(f2,2)*(-std::pow(f5,3) + std::pow(f4,2)*f7) - f4*(std::pow(f5,3) - 2*f4*f5*f6 + std::pow(f4,2)*f7) + std::pow(f3,3)*(std::pow(f5,2) + 2*f4*f6 + f2*f8) + std::pow(f3,2)*(-3*std::pow(f4,2)*f5 - 4*f2*f5*f6 + f2*f4*f7 + f6*f7 - f5*f8) + std::pow(f2,3)*(-(f6*f7) + f5*f8) - f2*(std::pow(f4,3)*f5 + f5*(std::pow(f6,2) - f5*f7) + f4*(-(f6*f7) + f5*f8)) + f3*(std::pow(f4,4) + std::pow(f5,2)*f6 + std::pow(f4,2)*(-(f2*f6) + f8) - 2*f4*(-2*f2*std::pow(f5,2) + std::pow(f6,2) + std::pow(f2,2)*f8) + f2*(-std::pow(f7,2) + f6*(2*f2*f6 + f8)))),
    FNum3lnv(2*std::pow(f3,3)*f4*f6lnv + 2*std::pow(f4,2)*f5*f6lnv + std::pow(f2,2)*f3*(4*f6*f6lnv - 2*f4*f8lnv) + f3*(std::pow(f5,2)*f6lnv - 4*f4*f6*f6lnv + std::pow(f4,2)*f8lnv) + std::pow(f3,2)*(f6lnv*f7 - f5*f8lnv) + std::pow(f2,3)*(-(f6lnv*f7) + f5*f8lnv) + f2*(-4*std::pow(f3,2)*f5*f6lnv - 2*f5*f6*f6lnv + std::pow(f3,3)*f8lnv + f4*(f6lnv*f7 - f5*f8lnv) + f3*(-(std::pow(f4,2)*f6lnv) + f6lnv*f8 + f6*f8lnv))),
    FNum3lnv2(2*std::pow(f2,2)*f3*std::pow(f6lnv,2) - 2*f3*f4*std::pow(f6lnv,2) + f2*(-(f5*std::pow(f6lnv,2)) + f3*f6lnv*f8lnv)),
    FNum4(std::pow(f4,5) + std::pow(f5,4) - 3*f4*std::pow(f5,2)*f6 - 2*std::pow(f3,3)*(f5*f6 + f4*f7) + std::pow(f4,2)*(std::pow(f6,2) + 2*f5*f7) + std::pow(f3,4)*f8 - std::pow(f4,3)*f8 + std::pow(f2,2)*(std::pow(f5,2)*f6 + 2*f4*std::pow(f6,2) - 4*f4*f5*f7 - 2*f3*f6*f7 + std::pow(f4,2)*f8 + 2*f3*f5*f8) - 2*f3*(2*std::pow(f4,3)*f5 - f5*std::pow(f6,2) + std::pow(f5,2)*f7 + f4*f6*f7 - f4*f5*f8) + std::pow(f2,3)*(std::pow(f7,2) - f6*f8) + std::pow(f3,2)*(3*f4*(std::pow(f5,2) + f4*f6) + std::pow(f7,2) - f6*f8) + f2*(3*std::pow(f4,2)*std::pow(f5,2) - 3*std::pow(f4,3)*f6 - std::pow(f6,3) + 2*f5*f6*f7 - 2*f3*(std::pow(f5,3) + f4*f5*f6 - 2*std::pow(f4,2)*f7) - std::pow(f5,2)*f8 + std::pow(f3,2)*(std::pow(f6,2) + 2*f5*f7 - 3*f4*f8) + f4*(-std::pow(f7,2) + f6*f8))),
    FNum4lnv(-2*std::pow(f3,3)*f5*f6lnv - 3*f4*std::pow(f5,2)*f6lnv + 2*std::pow(f4,2)*f6*f6lnv + std::pow(f3,4)*f8lnv - std::pow(f4,3)*f8lnv + std::pow(f2,3)*(-(f6lnv*f8) - f6*f8lnv) + std::pow(f3,2)*(3*std::pow(f4,2)*f6lnv - f6lnv*f8 - f6*f8lnv) + std::pow(f2,2)*(std::pow(f5,2)*f6lnv + 4*f4*f6*f6lnv + std::pow(f4,2)*f8lnv + f3*(-2*f6lnv*f7 + 2*f5*f8lnv)) + f3*(4*f5*f6*f6lnv + f4*(-2*f6lnv*f7 + 2*f5*f8lnv)) + f2*(-3*std::pow(f4,3)*f6lnv - 2*f3*f4*f5*f6lnv - 3*std::pow(f6,2)*f6lnv + std::pow(f3,2)*(2*f6*f6lnv - 3*f4*f8lnv) + f5*(2*f6lnv*f7 - f5*f8lnv) + f4*(f6lnv*f8 + f6*f8lnv))),
    FNum4lnv2(2*std::pow(f2,2)*f4*std::pow(f6lnv,2) + std::pow(f4,2)*std::pow(f6lnv,2) + 2*f3*f5*std::pow(f6lnv,2) - std::pow(f2,3)*f6lnv*f8lnv - std::pow(f3,2)*f6lnv*f8lnv + f2*(std::pow(f3,2)*std::pow(f6lnv,2) - 3*f6*std::pow(f6lnv,2) + f4*f6lnv*f8lnv)),
    FNum4lnv3(-(f2*std::pow(f6lnv,3))),
    FDen0(std::pow(f4,4) + std::pow(f3*f5 - f2*f6,2) - std::pow(f4,2)*(3*f3*f5 + 2*f2*f6) - (std::pow(f3,3) + std::pow(f2,2)*f5)*f7 + 2*f4*(std::pow(f3,2)*f6 + f2*(std::pow(f5,2) + f3*f7))),
    FDen0lnv(2*std::pow(f3,2)*f4*f6lnv + 2*std::pow(f2,2)*f6*f6lnv + f2*(-2*std::pow(f4,2)*f6lnv - 2*f3*f5*f6lnv)),
    FDen0lnv2(std::pow(f2,2)*std::pow(f6lnv,2)),
    FDen1(-(std::pow(f4,3)*f5) + f3*f4*(2*std::pow(f5,2) + f4*f6) - std::pow(f3,2)*(2*f5*f6 + f4*f7) + std::pow(f3,3)*f8 + std::pow(f2,2)*(-(f6*f7) + f5*f8) + f2*(-std::pow(f5,3) + std::pow(f4,2)*f7 + f3*(std::pow(f6,2) + f5*f7 - 2*f4*f8))),
    FDen1lnv(f3*std::pow(f4,2)*f6lnv - 2*std::pow(f3,2)*f5*f6lnv + std::pow(f3,3)*f8lnv + f2*f3*(2*f6*f6lnv - 2*f4*f8lnv) + std::pow(f2,2)*(-(f6lnv*f7) + f5*f8lnv)),
    FDen1lnv2(f2*f3*std::pow(f6lnv,2)),
    FDen2(-(std::pow(f4,3)*f6) + std::pow(f3,2)*f5*f7 + std::pow(f4,2)*(std::pow(f5,2) + f3*f7 + f2*f8) + f4*(f2*(std::pow(f6,2) - 3*f5*f7) - std::pow(f3,2)*f8) - f3*(std::pow(f5,3) + f2*f6*f7 - f2*f5*f8) + f2*(std::pow(f5,2)*f6 + f2*std::pow(f7,2) - f2*f6*f8)),
    FDen2lnv(-(std::pow(f4,3)*f6lnv) - std::pow(f3,2)*f4*f8lnv + std::pow(f2,2)*(-(f6lnv*f8) - f6*f8lnv) + f2*(std::pow(f5,2)*f6lnv + 2*f4*f6*f6lnv + std::pow(f4,2)*f8lnv + f3*(-(f6lnv*f7) + f5*f8lnv))),
    FDen2lnv2(f2*f4*std::pow(f6lnv,2) - std::pow(f2,2)*f6lnv*f8lnv),
    FDen3(-(std::pow(f4,3)*f7) + f2*f5*(-std::pow(f6,2) + f5*f7) + std::pow(f4,2)*(2*f5*f6 + f3*f8) + std::pow(f3,2)*(f6*f7 - f5*f8) - f4*(std::pow(f5,3) + f6*(2*f3*f6 - f2*f7) + f2*f5*f8) + f3*(std::pow(f5,2)*f6 - f2*std::pow(f7,2) + f2*f6*f8)),
    FDen3lnv(2*std::pow(f4,2)*f5*f6lnv + f3*(std::pow(f5,2)*f6lnv - 4*f4*f6*f6lnv + std::pow(f4,2)*f8lnv) + std::pow(f3,2)*(f6lnv*f7 - f5*f8lnv) + f2*(-2*f5*f6*f6lnv + f4*(f6lnv*f7 - f5*f8lnv) + f3*(f6lnv*f8 + f6*f8lnv))),
    FDen3lnv2(-2*f3*f4*std::pow(f6lnv,2) + f2*(-(f5*std::pow(f6lnv,2)) + f3*f6lnv*f8lnv)),
    FDen4(std::pow(f5,4) + std::pow(f4,2)*std::pow(f6,2) - f2*std::pow(f6,3) + std::pow(f3,2)*std::pow(f7,2) - f4*f7*(2*f3*f6 + f2*f7) - std::pow(f4,3)*f8 - std::pow(f3,2)*f6*f8 + f2*f4*f6*f8 - std::pow(f5,2)*(3*f4*f6 + 2*f3*f7 + f2*f8) + 2*f5*((std::pow(f4,2) + f2*f6)*f7 + f3*(std::pow(f6,2) + f4*f8))),
    FDen4lnv(-3*f4*std::pow(f5,2)*f6lnv + 2*std::pow(f4,2)*f6*f6lnv - std::pow(f4,3)*f8lnv + std::pow(f3,2)*(-(f6lnv*f8) - f6*f8lnv) + f3*(4*f5*f6*f6lnv + f4*(-2*f6lnv*f7 + 2*f5*f8lnv)) + f2*(-3*std::pow(f6,2)*f6lnv + f5*(2*f6lnv*f7 - f5*f8lnv) + f4*(f6lnv*f8 + f6*f8lnv))),
    FDen4lnv2(std::pow(f4,2)*std::pow(f6lnv,2) + 2*f3*f5*std::pow(f6lnv,2) - std::pow(f3,2)*f6lnv*f8lnv + f2*(-3*f6*std::pow(f6lnv,2) + f4*f6lnv*f8lnv)),
    FDen4lnv3(-(f2*std::pow(f6lnv,3)))
{ }

double Flux_Pade44LogConst::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  const double lnv = std::log(v);
  return Flux = N * std::pow(v,10) * (FNum0 + lnv*(FNum0lnv + lnv*FNum0lnv2) + v*(FNum1 + lnv*(FNum1lnv + lnv*FNum1lnv2) + v*(FNum2 + lnv*(FNum2lnv + lnv*FNum2lnv2) + v*(FNum3 + lnv*(FNum3lnv + lnv*FNum3lnv2) + v*(FNum4 + lnv*(FNum4lnv +lnv*(FNum4lnv2 + lnv*FNum4lnv3) ) ) ) ) ) )
    / (FDen0 + lnv*(FDen0lnv + lnv*FDen0lnv2) + v*(FDen1 +lnv*(FDen1lnv +lnv*FDen1lnv2) + v*(FDen2 + lnv*(FDen2lnv + lnv*FDen2lnv2) + v*(FDen3 + lnv*(FDen3lnv + lnv*FDen3lnv2) + v*(FDen4 + lnv*(FDen4lnv + lnv*(FDen4lnv2 + lnv*FDen4lnv3) ) ) ) ) ) );
}


Flux_Pade44LogFac::Flux_Pade44LogFac(const double delta, const double chis)
  : nu((1.0-delta*delta)/4.0), N((32*nu*nu)/5.),
    vPole( (2*(3 + nu))/(4*chis*(-2 + nu) + sqrt((-3 - nu)*(-36 + 35*nu))) ), // The pole of the 2,2 approximant of the energy function, with lowest-order spin dependence
    //vPole( sqrt( (1+nu/3.0) / (3.0-35.0*nu/12.0) ) ), // Eq. (41) of PRD 78, 104020
    vLSO( 2*sqrt(((3 + nu)*(-1 + 2*(3 + nu)*sqrt(1/(144 + nu*(-81 + 4*nu)))))/(-36 + 35*nu)) ), // Table 1 of PRD 63, 044023
    flogfac6(-16.304761904761904),
    flogfac8(52.74308390022676),
    f1(-(1/vPole)),
    f2((-1247 - 980*nu)/336.),
    f3(chis*(-2.75 + 3*nu) + 4*M_PI + (1247 + 980*nu)/(336.*vPole)),
    f4(-4.928461199294532 + (std::pow(chis,2)*(33 - 4*nu))/16. + (nu*(9271 + 1820*nu))/504. + (chis*(11 - 12*nu))/(4.*vPole) - (4*M_PI)/vPole),
    f5((89422 + 1134*std::pow(chis,2)*(-33 + 4*nu) - 36*nu*(9271 + 1820*nu) - 9*(14*chis*(567 + 108*std::pow(chis,2)*(1 - 3*nu) + 4*nu*(-935 + 628*nu)) + 3*(8191 + 16324*nu)*M_PI)*vPole)/(18144.*vPole)),
    f6(95.10839000836025 - (1712*EulerGamma)/105. - (94403*std::pow(nu,2))/3024. - (775*std::pow(nu,3))/324. + (chis*(-65 + 68*nu)*M_PI)/6. + (16*std::pow(M_PI,2))/3. + (nu*(-134543 + 6642*std::pow(M_PI,2)))/7776. + (14*chis*(567 + 108*std::pow(chis,2)*(1 - 3*nu) + 4*nu*(-935 + 628*nu)) + 3*(8191 + 16324*nu)*M_PI)/(2016.*vPole) - (856*std::log(16*std::pow(vLSO,2)))/105.),
    f7((5*(-78168 + nu*(300643 + 154708*nu))*M_PI)/12096. - (95.10839000836025 - (1712*EulerGamma)/105. - (nu*(941801 + 6*nu*(283209 + 21700*nu)))/54432. - (65*chis*M_PI)/6. + (34*chis*nu*M_PI)/3. + ((256 + 41*nu)*std::pow(M_PI,2))/48. - (856*std::log(16*std::pow(vLSO,2)))/105.)/vPole),
    f8(-101.65745990813167 + (232597*EulerGamma)/4410. - (1369*std::pow(M_PI,2))/126. - (5*(-78168 + nu*(300643 + 154708*nu))*M_PI)/(12096.*vPole) + (39931*std::log(2))/294. - (47385*std::log(3))/1568. + (232597*std::log(vLSO))/4410.),
    FNum0(std::pow(f4,4) - 3*f3*std::pow(f4,2)*f5 + std::pow(f3,2)*(std::pow(f5,2) + 2*f4*f6) - std::pow(f3,3)*f7 + std::pow(f2,2)*(std::pow(f6,2) - f5*f7) + f2*(2*f4*std::pow(f5,2) - 2*std::pow(f4,2)*f6 + f3*(-2*f5*f6 + 2*f4*f7)) + f1*(-std::pow(f5,3) + 2*f4*f5*f6 - std::pow(f4,2)*f7 + f3*(-std::pow(f6,2) + f5*f7))),
    FNum1(-(std::pow(f4,3)*f5) + f3*(2*f4*std::pow(f5,2) + std::pow(f4,2)*f6) + std::pow(f3,2)*(-2*f5*f6 - f4*f7) + std::pow(f1,2)*(-std::pow(f5,3) + 2*f4*f5*f6 - std::pow(f4,2)*f7 + f3*(-std::pow(f6,2) + f5*f7)) + std::pow(f3,3)*f8 + std::pow(f2,2)*(-(f6*f7) + f5*f8) + f2*(-std::pow(f5,3) + std::pow(f4,2)*f7 + f3*(std::pow(f6,2) + f5*f7 - 2*f4*f8)) + f1*(std::pow(f4,4) + std::pow(f5,2)*f6 - f4*std::pow(f6,2) + std::pow(f3,2)*(std::pow(f5,2) + 2*f4*f6) - std::pow(f3,3)*f7 - f4*f5*f7 + std::pow(f2,2)*(std::pow(f6,2) - f5*f7) + f2*(2*f4*std::pow(f5,2) - 2*std::pow(f4,2)*f6 + f3*(-2*f5*f6 + 2*f4*f7)) + std::pow(f4,2)*f8 + f3*(-3*std::pow(f4,2)*f5 + f6*f7 - f5*f8))),
    FNum2(std::pow(f4,2)*std::pow(f5,2) - std::pow(f4,3)*f6 + f3*(-std::pow(f5,3) + std::pow(f4,2)*f7) + std::pow(f2,3)*(std::pow(f6,2) - f5*f7) + std::pow(f3,2)*(f5*f7 - f4*f8) + std::pow(f2,2)*(2*f4*std::pow(f5,2) - 2*std::pow(f4,2)*f6 + std::pow(f7,2) + f3*(-2*f5*f6 + 2*f4*f7) - f6*f8) + std::pow(f1,2)*(std::pow(f5,2)*f6 - f4*std::pow(f6,2) - f4*f5*f7 + std::pow(f4,2)*f8 + f3*(f6*f7 - f5*f8)) + f2*(std::pow(f4,4) + std::pow(f5,2)*f6 + f4*std::pow(f6,2) + std::pow(f3,2)*(std::pow(f5,2) + 2*f4*f6) - std::pow(f3,3)*f7 - 3*f4*f5*f7 + std::pow(f4,2)*f8 + f3*(-3*std::pow(f4,2)*f5 - f6*f7 + f5*f8)) + f1*(-(std::pow(f4,3)*f5) - f5*std::pow(f6,2) + std::pow(f5,2)*f7 + f4*f6*f7 + std::pow(f3,2)*(-2*f5*f6 - f4*f7) + std::pow(f3,3)*f8 - f4*f5*f8 + std::pow(f2,2)*(-(f6*f7) + f5*f8) + f3*(2*f4*std::pow(f5,2) + std::pow(f4,2)*f6 - std::pow(f7,2) + f6*f8) + f2*(-2*std::pow(f5,3) + 2*f4*f5*f6 + f3*(2*f5*f7 - 2*f4*f8)))),
    FNum3(-(f4*std::pow(f5,3)) + 2*std::pow(f4,2)*f5*f6 + std::pow(f3,3)*(std::pow(f5,2) + 2*f4*f6) - std::pow(f3,4)*f7 - std::pow(f4,3)*f7 + f3*(std::pow(f4,4) + std::pow(f5,2)*f6 - 2*f4*std::pow(f6,2) + std::pow(f4,2)*f8) + std::pow(f3,2)*(-3*std::pow(f4,2)*f5 + f6*f7 - f5*f8) + std::pow(f2,3)*(-(f6*f7) + f5*f8) + std::pow(f2,2)*(-std::pow(f5,3) + std::pow(f4,2)*f7 + f3*(2*std::pow(f6,2) - 2*f4*f8)) + f1*(std::pow(f4,2)*std::pow(f5,2) - std::pow(f4,3)*f6 + std::pow(f6,3) + f3*(-2*std::pow(f5,3) + 2*f4*f5*f6) - 2*f5*f6*f7 + f4*std::pow(f7,2) + std::pow(f5,2)*f8 - f4*f6*f8 + std::pow(f3,2)*(-std::pow(f6,2) + 2*f5*f7 - f4*f8) + f2*(2*std::pow(f5,2)*f6 - 4*f4*f5*f7 + 2*std::pow(f4,2)*f8) + std::pow(f2,2)*(std::pow(f7,2) - f6*f8)) + std::pow(f1,2)*(-(f5*std::pow(f6,2)) + std::pow(f5,2)*f7 + f4*f6*f7 - f4*f5*f8 + f3*(-std::pow(f7,2) + f6*f8)) + f2*(-(std::pow(f4,3)*f5) - f5*std::pow(f6,2) + std::pow(f5,2)*f7 + f4*f6*f7 + std::pow(f3,2)*(-4*f5*f6 + f4*f7) + std::pow(f3,3)*f8 - f4*f5*f8 + f3*(4*f4*std::pow(f5,2) - std::pow(f4,2)*f6 - std::pow(f7,2) + f6*f8))),
    FNum4(std::pow(f4,5) + std::pow(f5,4) - 3*f4*std::pow(f5,2)*f6 + std::pow(f4,2)*std::pow(f6,2) + 2*std::pow(f4,2)*f5*f7 + std::pow(f3,3)*(-2*f5*f6 - 2*f4*f7) + std::pow(f3,4)*f8 - std::pow(f4,3)*f8 + f3*(-4*std::pow(f4,3)*f5 + 2*f5*std::pow(f6,2) - 2*std::pow(f5,2)*f7 - 2*f4*f6*f7 + 2*f4*f5*f8) + std::pow(f2,3)*(std::pow(f7,2) - f6*f8) + std::pow(f3,2)*(3*f4*std::pow(f5,2) + 3*std::pow(f4,2)*f6 + std::pow(f7,2) - f6*f8) + f2*(3*std::pow(f4,2)*std::pow(f5,2) - 3*std::pow(f4,3)*f6 - std::pow(f6,3) + 2*f5*f6*f7 - f4*std::pow(f7,2) + f3*(-2*std::pow(f5,3) - 2*f4*f5*f6 + 4*std::pow(f4,2)*f7) - std::pow(f5,2)*f8 + f4*f6*f8 + std::pow(f3,2)*(std::pow(f6,2) + 2*f5*f7 - 3*f4*f8)) + std::pow(f2,2)*(std::pow(f5,2)*f6 + 2*f4*std::pow(f6,2) - 4*f4*f5*f7 + std::pow(f4,2)*f8 + f3*(-2*f6*f7 + 2*f5*f8)) + std::pow(f1,2)*(std::pow(f6,3) - 2*f5*f6*f7 + std::pow(f5,2)*f8 - f4*(-std::pow(f7,2) + f6*f8)) + f1*(-2*f4*std::pow(f5,3) + 4*std::pow(f4,2)*f5*f6 - 2*std::pow(f4,3)*f7 + f3*(2*std::pow(f5,2)*f6 - 4*f4*std::pow(f6,2) + 2*std::pow(f4,2)*f8) + std::pow(f3,2)*(2*f6*f7 - 2*f5*f8) + f2*(2*f4*f6*f7 + 2*f5*(-std::pow(f6,2) + f5*f7) - 2*f4*f5*f8 - 2*f3*(std::pow(f7,2) - f6*f8)))),
    FDen0(std::pow(f4,4) - 3*f3*std::pow(f4,2)*f5 + std::pow(f3,2)*(std::pow(f5,2) + 2*f4*f6) - std::pow(f3,3)*f7 + std::pow(f2,2)*(std::pow(f6,2) - f5*f7) + f2*(2*f4*std::pow(f5,2) - 2*std::pow(f4,2)*f6 + f3*(-2*f5*f6 + 2*f4*f7)) + f1*(-std::pow(f5,3) + 2*f4*f5*f6 - std::pow(f4,2)*f7 + f3*(-std::pow(f6,2) + f5*f7))),
    FDen1(-(std::pow(f4,3)*f5) + f3*(2*f4*std::pow(f5,2) + std::pow(f4,2)*f6) + std::pow(f3,2)*(-2*f5*f6 - f4*f7) + std::pow(f3,3)*f8 + std::pow(f2,2)*(-(f6*f7) + f5*f8) + f2*(-std::pow(f5,3) + std::pow(f4,2)*f7 + f3*(std::pow(f6,2) + f5*f7 - 2*f4*f8)) + f1*(std::pow(f5,2)*f6 - f4*std::pow(f6,2) - f4*f5*f7 + std::pow(f4,2)*f8 + f3*(f6*f7 - f5*f8))),
    FDen2(std::pow(f4,2)*std::pow(f5,2) - std::pow(f4,3)*f6 + f3*(-std::pow(f5,3) + std::pow(f4,2)*f7) + std::pow(f3,2)*(f5*f7 - f4*f8) + std::pow(f2,2)*(std::pow(f7,2) - f6*f8) + f2*(std::pow(f5,2)*f6 + f4*(std::pow(f6,2) - 3*f5*f7) + std::pow(f4,2)*f8 + f3*(-(f6*f7) + f5*f8)) + f1*(-(f5*std::pow(f6,2)) + std::pow(f5,2)*f7 + f4*f6*f7 - f4*f5*f8 + f3*(-std::pow(f7,2) + f6*f8))),
    FDen3(-(f4*std::pow(f5,3)) + 2*std::pow(f4,2)*f5*f6 - std::pow(f4,3)*f7 + f3*(std::pow(f5,2)*f6 - 2*f4*std::pow(f6,2) + std::pow(f4,2)*f8) + std::pow(f3,2)*(f6*f7 - f5*f8) + f1*(std::pow(f6,3) - 2*f5*f6*f7 + f4*std::pow(f7,2) + std::pow(f5,2)*f8 - f4*f6*f8) + f2*(-(f5*std::pow(f6,2)) + std::pow(f5,2)*f7 + f4*f6*f7 - f4*f5*f8 + f3*(-std::pow(f7,2) + f6*f8))),
    FDen4(std::pow(f5,4) - 3*f4*std::pow(f5,2)*f6 + std::pow(f4,2)*std::pow(f6,2) + 2*std::pow(f4,2)*f5*f7 - std::pow(f4,3)*f8 + std::pow(f3,2)*(std::pow(f7,2) - f6*f8) + f2*(-std::pow(f6,3) + 2*f5*f6*f7 - f4*std::pow(f7,2) - std::pow(f5,2)*f8 + f4*f6*f8) + f3*(-2*std::pow(f5,2)*f7 - 2*f4*f6*f7 + 2*f5*(std::pow(f6,2) + f4*f8)))
{ }

double Flux_Pade44LogFac::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  return Flux = N * std::pow(v,10) * (vPole/(vPole-v)) * (1.0 + std::log(v/vLSO)*std::pow(v,6)*(flogfac6 + v*v*flogfac8))
    * (FNum0 + v*(FNum1 + v*(FNum2 + v*(FNum3 + v*(FNum4)))))
    / (FDen0 + v*(FDen1 + v*(FDen2 + v*(FDen3 + v*(FDen4)))));
}


Flux_SumAmplitudes::Flux_SumAmplitudes(const double idelta, const double ichis)
  : WaveformAmplitudesSumMMagSquared(WaveformAmplitudes(idelta, ichis)),
    N(1.0/(16.0*M_PI))
{ }

double Flux_SumAmplitudes::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new) { return Flux; }
  v = v_new;
  return Flux = N*WaveformUtilities::sixth(v)*SumMMagSquared(v);
}


template <class Metric, class Hamiltonian>
Flux_SumAmplitudesResummed<Metric, Hamiltonian>::Flux_SumAmplitudesResummed(const double idelta, const double ichis, const Metric& ig, const Hamiltonian& iH)
  : WaveformUtilities::WaveformAmplitudesResummedSumMMagSquared<Metric, Hamiltonian>(idelta, ichis, ig, iH),
    N(1.0/(16.0*M_PI))
{ }

template <class Metric, class Hamiltonian>
double Flux_SumAmplitudesResummed<Metric, Hamiltonian>::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new && r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return Flux; }
  v = v_new;
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  return Flux = N*WaveformUtilities::sixth(v)*WaveformUtilities::WaveformAmplitudesResummedSumMMagSquared<Metric, Hamiltonian>::SumMMagSquared(v, r, prstar, pPhi);
}


template <class Flux>
Torque_KFPhi<Flux>::Torque_KFPhi(const double delta, const double chis, const Flux& iF)
  : nu((1.0-delta*delta)/4.0), F(iF),
    v(0.0), r(0.0), prstar(0.0), pPhi(0.0), Torque(0.0)
{ }

template <class Flux> template <class Ham>
Torque_KFPhi<Flux>::Torque_KFPhi(const double delta, const double chis, const Flux& iF, const Ham& H)
  : nu((1.0-delta*delta)/4.0), F(iF),
    v(0.0), r(0.0), prstar(0.0), pPhi(0.0), Torque(0.0)
{ }

template <class Flux>
double Torque_KFPhi<Flux>::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new && r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return Torque; }
  v = v_new;
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  F(v, r, prstar, pPhi);
  return Torque = -F.Flux/(nu*cube(v));
}


// template <class HamiltonianCircular, class Flux>
// Torque_nKFPhi<HamiltonianCircular, Flux>::Torque_nKFPhi(const double delta, const double chis, const Flux& iF, const HamiltonianCircular& iHcirc)
//   : nu((1.0-delta*delta)/4.0), Hcirc(iHcirc), F(iF),
//     v(0.0), r(0.0), prstar(0.0), pPhi(0.0), Torque(0.0)
// { }

// template <class HamiltonianCircular, class Flux>
// double Torque_nKFPhi<HamiltonianCircular, Flux>::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
//   if(v==v_new && r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return Torque; }
//   v = v_new;
//   r = r_new;
//   prstar = prstar_new;
//   pPhi = pPhi_new;
//   Hcirc(r, 0.0, pPhi);
//   F(v, r, prstar, pPhi);
//   /// Eqs. (65) and (66) of Boyle et al., 2008: PRD 78, 104020
//   /// r_Omega := (dH/dpPhi)^(-2/3) = (Omega_circ)^(-2/3)
//   /// VPhi := Omega * r_Omega
//   /// VPhi^6 = v^18 * (dH/dpPhi)^(-4)
//   /// v^3 / VPhi^6 = (dH/dpPhi)^4 / v^15
//   return Torque = -F.Flux * std::pow(Hcirc.dHdpPhi,4) / (nu*std::pow(v,15));
// }
