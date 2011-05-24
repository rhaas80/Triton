#include "EOBModel.hpp"

#include <cmath>
using std::sqrt;

WaveformUtilities::EOBMetricNonspinning::EOBMetricNonspinning(const double delta)
  : nu((1.0-delta*delta)/4.0),
    a4((94./3. - M_PI*M_PI*41./32.)*nu), // Eq. (9) of Pan et al., 2011
    a5((-5.828-143.5*nu+447*nu*nu)*nu), // Eq. (35a) of Pan et al., 2011
    a6(184*nu), // Eq. (35b) of Pan et al., 2011
    DtNum0(-64 + 12*a4 + 4*a5 + a6 + 64*nu - 4*pow(nu,2)),
    DtNum1(32 - 4*a4 - a5 - 24*nu),
    DtDen0(4*pow(a4,2) + pow(a5,2) + 16*a6 + 16*a5*nu - 8*a6*nu + 32*pow(nu,3) + a4*(4*a5 - a6 + 4*nu*(8 + nu))),
    DtDen1(4*pow(a4,2) + 16*a5 - 2*a6*(-4 + nu) + 8*pow(nu,2)*(4 + nu) + a4*(a5 + 32*nu)),
    DtDen2(2*(4*a4*(2 + nu) + a5*(4 + nu) + 2*(a6 + 8*pow(nu,2)))),
    DtDen3(2*(4*a4 + 2*a5 + a6 - 4*(-4 + nu)*nu)),
    DtDen4(4*a4 + 2*a5 + a6 - 4*(-4 + nu)*nu),
    DtDen5(32 - 4*a4 - a5 - 24*nu),
    Dinv0(1),
    Dinv2(6*nu),
    Dinv3(2*(26 - 3*nu)*nu),
    r(0.0), Dt(0.0), DR(0.0), dDtdr(0.0), dDRdr(0.0), drdrstar(0.0), drstardr(0.0)
{ }


void WaveformUtilities::EOBMetricNonspinning::operator()(const double r_new) {
  if(r==r_new) { return; }
  r = r_new;
  const double DtNum = pow(r,6)*(DtNum0 + r*(DtNum1));
  const double DtDen = DtDen0 + r*(DtDen1 + r*(DtDen2 + r*(DtDen3 + r*(DtDen4 + r*(DtDen5) ) ) ) );
  const double Dinv = Dinv0 + (Dinv2 + Dinv3/r)/(r*r);
  Dt = DtNum / DtDen;
  DR = Dt * Dinv;
  dDtdr = ((pow(r,5)*(6*DtNum0 + 7*r*(DtNum1)))*DtDen - DtNum*(DtDen1 + r*(2*DtDen2 + r*(3*DtDen3 + r*(4*DtDen4 + r*(5*DtDen5)))))) / (DtDen*DtDen);
  dDRdr = dDtdr*Dinv + Dt * (-2*Dinv2 + -3*Dinv3/r)/(r*r*r);
  drdrstar = sqrt(Dt*DR) / (r*r);  // Eq. (20) of PRD 81, 084041 [Buonanno et al., 2010]
  drstardr = 1.0 / drdrstar;
  return;
}

WaveformUtilities::EOBHamiltonianNonspinning::EOBHamiltonianNonspinning(const double delta, EOBMetricNonspinning& ig)
  : nu((1.0-delta*delta)/4.0), g(ig),
    r(0.0), prstar(0.0), pPhi(0.0),
    Heff(0.0), H(0.0), dHdr(0.0), dHdPhi(0.0), dHdprstar(0.0), dHdpPhi(0.0), v(0.0)
{ }

void WaveformUtilities::EOBHamiltonianNonspinning::operator()(const double r_new, const double prstar_new, const double pPhi_new) {
  g(r_new);
  if(r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return; }
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  Heff = sqrt(pow(prstar,2) + (g.Dt*(1 + (pow(pPhi,2) + ((8 - 6*nu)*nu*pow(prstar,4)))/pow(r,2)))/pow(r,2));
  H = sqrt(1 + 2*nu*(Heff-1)) / nu;
  dHdr = ((g.dDtdr*r*(pow(pPhi,2) + 2*(4-3*nu)*nu*pow(prstar,4) + pow(r,2)) - 2*g.Dt*(2*pow(pPhi,2) + 4*(4-3*nu)*nu*pow(prstar,4) + pow(r,2)))/pow(r,5)) / (2*nu*H*Heff);
  //dHdPhi = 0.0;
  dHdprstar = (2*prstar + (8*g.Dt*(4 - 3*nu)*nu*pow(prstar,3))/pow(r,4)) / (2*nu*H*Heff);
  dHdpPhi = ((2*g.Dt*pPhi)/pow(r,4)) / (2*nu*H*Heff);
  H -= 1.0/nu;
  v = dHdpPhi<0 ? -pow(-dHdpPhi, 1./3.) : pow(dHdpPhi, 1./3.);
  return;
}



WaveformUtilities::EOBMetricWithSpin::EOBMetricWithSpin(const double delta, const double chis)
  : nu((1.0-delta*delta)/4.0),
    a4(94./3. - M_PI*M_PI*41./32.), // Eq. (9) of Pan et al., 2011
    a5(-5.828-143.5*nu+447*nu*nu), // Eq. (35a) of Pan et al., 2011
    a6(184*nu), // Eq. (35b) of Pan et al., 2011
    chikerr(chis), // a.k.a. chieff.  See Eq. (17) of PRD 81, 084041
    DtNum0(4*a5 + a6 - 24*pow(chikerr,4) + pow(chikerr,6) - 2*a4*(-6 + pow(chikerr,2)) + pow(chikerr,2)*(80 - 24*nu) - 4*(16 + (-16 + nu)*nu)),
    DtNum1(32 - 4*a4 - a5 + 6*pow(chikerr,4) + 4*pow(chikerr,2)*(-8 + nu) - 24*nu),
    DtDen0(pow(a5,2) + 16*a6 - 12*a6*pow(chikerr,2) + a6*pow(chikerr,4) + pow(chikerr,10) + 2*pow(a4,2)*(2 + pow(chikerr,2)) - 8*(a6 - 2*pow(chikerr,6))*nu + 12*pow(chikerr,2)*(4 + pow(chikerr,2))*pow(nu,2) + 32*pow(nu,3) - 8*a5*(-2 + pow(chikerr,2))*(pow(chikerr,2) + nu) + a4*(4*a5 - a6 + 12*pow(chikerr,4) - 3*pow(chikerr,6) + 8*pow(chikerr,2)*nu + 4*nu*(8 + nu))),
    DtDen1(4*pow(a4,2) + 8*(2*a5 + a6) - 4*(a5 + a6)*pow(chikerr,2) - a5*pow(chikerr,4) + 2*pow(chikerr,8) + 2*(-a6 + 12*pow(chikerr,4) + pow(chikerr,6))*nu + 32*(1 + pow(chikerr,2))*pow(nu,2) + 8*pow(nu,3) + a4*(a5 + 16*pow(chikerr,2) - 2*pow(chikerr,4) + 32*nu)),
    DtDen2(-((-4 + pow(chikerr,2))*(a6 + pow(chikerr,6))) + 2*a5*(4 + nu) - 4*(-8 + pow(chikerr,2))*nu*(pow(chikerr,2) + nu) + 2*a4*(8 - 2*pow(chikerr,2) + pow(chikerr,4) + 4*nu)),
    DtDen3(8*a4 + a5*(4 + pow(chikerr,2)) + 2*(a6 - 2*(pow(chikerr,6) + pow(chikerr,4)*(-2 + nu) + 2*pow(chikerr,2)*nu + 2*(-4 + nu)*nu))),
    DtDen4(2*a5 + a6 - 12*pow(chikerr,4) + pow(chikerr,6) - 2*a4*(-2 + pow(chikerr,2)) - 16*pow(chikerr,2)*(-1 + nu) - 4*(-4 + nu)*nu),
    DtDen5(32 - 4*a4 - a5 + 6*pow(chikerr,4) + 4*pow(chikerr,2)*(-8 + nu) - 24*nu),
    Dinv0(1),
    Dinv2(6*nu),
    Dinv3(2*(26 - 3*nu)*nu),
    r(0.0), Dt(0.0), DR(0.0), dDtdr(0.0), dDRdr(0.0), drdrstar(0.0), drstardr(0.0)
{ }


void WaveformUtilities::EOBMetricWithSpin::operator()(const double r_new) {
  if(r==r_new) { return; }
  r = r_new;
  const double DtNum = pow(r,6)*(DtNum0 + r*(DtNum1));
  const double DtDen = DtDen0 + r*(DtDen1 + r*(DtDen2 + r*(DtDen3 + r*(DtDen4 + r*(DtDen5) ) ) ) );
  const double Dinv = Dinv0 + (Dinv2 + Dinv3/r)/(r*r);
  Dt = DtNum / DtDen;
  DR = Dt * Dinv;
  dDtdr = ((pow(r,5)*(6*DtNum0 + 7*r*(DtNum1)))*DtDen - DtNum*(DtDen1 + r*(2*DtDen2 + r*(3*DtDen3 + r*(4*DtDen4 + r*(5*DtDen5)))))) / (DtDen*DtDen);
  dDRdr = dDtdr*Dinv + Dt * (-2*Dinv2 + -3*Dinv3/r)/(r*r*r);
  drdrstar = sqrt(Dt*DR) / (r*r + chikerr*chikerr);  // Eq. (20) of PRD 81, 084041 [Buonanno et al., 2010]
  drstardr = 1.0 / drdrstar;
  return;
}
