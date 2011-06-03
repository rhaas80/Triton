#include "EOBModel.hpp"

#include <cmath>
#include "VectorFunctions.hpp"
using WaveformUtilities::square;
using WaveformUtilities::cube;
using WaveformUtilities::fourth;
using std::sqrt;


WaveformUtilities::EOBMetricNonspinning::EOBMetricNonspinning(const double delta, const double chis, const double chia)
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
    r(0.0), Dt(0.0), Dr(0.0), dDtdr(0.0), dDrdr(0.0), drdrstar(0.0), drstardr(0.0)
{ }


void WaveformUtilities::EOBMetricNonspinning::operator()(const double r_new) const {
  if(r==r_new) { return; }
  r = r_new;
  const double DtNum = pow(r,6)*(DtNum0 + r*(DtNum1));
  const double DtDen = DtDen0 + r*(DtDen1 + r*(DtDen2 + r*(DtDen3 + r*(DtDen4 + r*(DtDen5) ) ) ) );
  const double Dinv = Dinv0 + (Dinv2 + Dinv3/r)/(r*r);
  Dt = DtNum / DtDen;
  Dr = Dt * Dinv;
  dDtdr = ((pow(r,5)*(6*DtNum0 + 7*r*(DtNum1)))*DtDen - DtNum*(DtDen1 + r*(2*DtDen2 + r*(3*DtDen3 + r*(4*DtDen4 + r*(5*DtDen5)))))) / (DtDen*DtDen);
  dDrdr = dDtdr*Dinv + (pow(r,3)*(DtNum0+r*(DtNum1))/DtDen)*(-2*Dinv2 + -3*Dinv3/r);
  drdrstar = sqrt(Dt*Dr) / (r*r);  // Eq. (28) of PRD 81, 084041 [Pan et al., 2010]
  drstardr = 1.0 / drdrstar;
  return;
}

WaveformUtilities::EOBHamiltonianNonspinning::EOBHamiltonianNonspinning(const double delta, const double chis, const double chia, const EOBMetricNonspinning& ig)
  : nu((1.0-delta*delta)/4.0), g(ig),
    r(0.0), prstar(0.0), pPhi(0.0),
    Heff(0.0), H(0.0), dHdr(0.0), dHdPhi(0.0), dHdprstar(0.0), dHdpPhi(0.0), v(0.0)
{ }

void WaveformUtilities::EOBHamiltonianNonspinning::operator()(const double r_new, const double prstar_new, const double pPhi_new) const {
  g(r_new);
  if(r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return; }
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  Heff = sqrt(pow(prstar,2) + (g.Dt*(1 + (pow(pPhi,2) + ((8 - 6*nu)*nu*pow(prstar,4)))/pow(r,2)))/pow(r,2));
  H = sqrt(1 + 2*nu*(Heff-1)) / nu;
  dHdr = ((g.dDtdr*r*(pow(pPhi,2) + 2*(4-3*nu)*nu*pow(prstar,4) + pow(r,2)) - 2*g.Dt*(2*pow(pPhi,2) + 4*(4-3*nu)*nu*pow(prstar,4) + pow(r,2)))/pow(r,5)) / (2*nu*H*Heff);
  ///dHdPhi = 0.0;
  dHdprstar = (2*prstar + (8*g.Dt*(4 - 3*nu)*nu*pow(prstar,3))/pow(r,4)) / (2*nu*H*Heff);
  dHdpPhi = ((2*g.Dt*pPhi)/pow(r,4)) / (2*nu*H*Heff);
  H -= 1.0/nu;
  v = (dHdpPhi>0 ? pow(dHdpPhi, 1./3.) : -pow(-dHdpPhi, 1./3.));
  return;
}


WaveformUtilities::EOBMetricWithSpin::EOBMetricWithSpin(const double delta, const double chis, const double chia)
  : nu((1.0-delta*delta)/4.0),
//     a4(((94./3.) - M_PI*M_PI*41./32.)*nu), // Eq. (9) of Pan et al., 2011
//     a5((-5.828-143.5*nu+447*nu*nu)*nu), // Eq. (35a) of Pan et al., 2011
//     a6(184*nu), // Eq. (35b) of Pan et al., 2011
    a4(((94.0/3.0)-(41.0/32.0)*M_PI*M_PI)*nu),
    a5(nu*(-82.5384+508.681*nu-787.826*nu*nu)), // Eq. (27) of Pan et al. 2011
    a6(nu*(500.0-1800.0*nu)), // Eq. (28) of Pan et al. 2011
    chiKerr(chis + delta*chia), // a.k.a. chieff.  See Eq. (17) of PRD 81, 084041
    DtNum0(4*a5 + a6 - 24*pow(chiKerr,4) + pow(chiKerr,6) - 2*a4*(-6 + pow(chiKerr,2)) + pow(chiKerr,2)*(80 - 24*nu) - 4*(16 + (-16 + nu)*nu)),
    DtNum1(32 - 4*a4 - a5 + 6*pow(chiKerr,4) + 4*pow(chiKerr,2)*(-8 + nu) - 24*nu),
    DtDen0(pow(a5,2) + 16*a6 - 12*a6*pow(chiKerr,2) + a6*pow(chiKerr,4) + pow(chiKerr,10) + 2*pow(a4,2)*(2 + pow(chiKerr,2)) - 8*(a6 - 2*pow(chiKerr,6))*nu + 12*pow(chiKerr,2)*(4 + pow(chiKerr,2))*pow(nu,2) + 32*pow(nu,3) - 8*a5*(-2 + pow(chiKerr,2))*(pow(chiKerr,2) + nu) + a4*(4*a5 - a6 + 12*pow(chiKerr,4) - 3*pow(chiKerr,6) + 8*pow(chiKerr,2)*nu + 4*nu*(8 + nu))),
    DtDen1(4*pow(a4,2) + 8*(2*a5 + a6) - 4*(a5 + a6)*pow(chiKerr,2) - a5*pow(chiKerr,4) + 2*pow(chiKerr,8) + 2*(-a6 + 12*pow(chiKerr,4) + pow(chiKerr,6))*nu + 32*(1 + pow(chiKerr,2))*pow(nu,2) + 8*pow(nu,3) + a4*(a5 + 16*pow(chiKerr,2) - 2*pow(chiKerr,4) + 32*nu)),
    DtDen2(-((-4 + pow(chiKerr,2))*(a6 + pow(chiKerr,6))) + 2*a5*(4 + nu) - 4*(-8 + pow(chiKerr,2))*nu*(pow(chiKerr,2) + nu) + 2*a4*(8 - 2*pow(chiKerr,2) + pow(chiKerr,4) + 4*nu)),
    DtDen3(8*a4 + a5*(4 + pow(chiKerr,2)) + 2*(a6 - 2*(pow(chiKerr,6) + pow(chiKerr,4)*(-2 + nu) + 2*pow(chiKerr,2)*nu + 2*(-4 + nu)*nu))),
    DtDen4(2*a5 + a6 - 12*pow(chiKerr,4) + pow(chiKerr,6) - 2*a4*(-2 + pow(chiKerr,2)) - 16*pow(chiKerr,2)*(-1 + nu) - 4*(-4 + nu)*nu),
    DtDen5(32 - 4*a4 - a5 + 6*pow(chiKerr,4) + 4*pow(chiKerr,2)*(-8 + nu) - 24*nu),
    Dinv0(1),
    Dinv2(6*nu),
    Dinv3(2*(26 - 3*nu)*nu),
    r(0.0), Dt(0.0), Dr(0.0), dDtdr(0.0), dDrdr(0.0), drdrstar(0.0), drstardr(0.0)
{ }


void WaveformUtilities::EOBMetricWithSpin::operator()(const double r_new) const {
  if(r==r_new) { return; }
  r = r_new;
  const double DtNum = pow(r,6)*(DtNum0 + r*(DtNum1));
  const double DtDen = DtDen0 + r*(DtDen1 + r*(DtDen2 + r*(DtDen3 + r*(DtDen4 + r*(DtDen5) ) ) ) );
  const double Dinv = Dinv0 + (Dinv2 + Dinv3/r)/(r*r);
  Dt = DtNum / DtDen;
  Dr = Dt * Dinv;
  dDtdr = ((pow(r,5)*(6*DtNum0 + 7*r*(DtNum1)))*DtDen - DtNum*(DtDen1 + r*(2*DtDen2 + r*(3*DtDen3 + r*(4*DtDen4 + r*(5*DtDen5)))))) / (DtDen*DtDen);
  dDrdr = dDtdr*Dinv + (pow(r,3)*(DtNum0+r*(DtNum1))/DtDen)*(-2*Dinv2 + -3*Dinv3/r);
  drdrstar = sqrt(Dt*Dr) / (r*r + chiKerr*chiKerr);  // Eq. (28) of PRD 81, 084041 [Pan et al., 2010]
  drstardr = 1.0 / drdrstar;
  ddrstardrdr = (2*r/(r*r+chiKerr*chiKerr) - 0.5*dDrdr/Dr - 0.5*dDtdr/Dr) * drstardr;
  return;
}


WaveformUtilities::EOBHamiltonianWithSpin::EOBHamiltonianWithSpin(const double delta, const double chis, const double chia, const EOBMetricWithSpin& ig)
  : nu((1.0-delta*delta)/4.0), g(ig),
    chi((1-2*nu)*chis + delta*chia),
    chistar(2*nu*chis),
    chiKerr(chis + delta*chia),
    a(0.0), /// calibrated; PRD 81, 084041
    b(-1.65), /// calibrated; PRD 81, 084041 p. 10
    aSSterm(1.5*nu*chiKerr*chistar), /// calibrated; PRD 81, 084041 Eq. (19) and p. 10
    sigmaconst(-chistar/4.),
    sigmarinv((-4*a*chi - 4*chi*nu - chistar*(2 + 4*b + 5*nu))/8.),
    sigmapPhi((8*a*chi + 3*chi*nu + chistar*(-5 + 8*b + 4*nu))/16.),
    sigmapr((-3*(4*a*chi + (5 + 4*b)*chistar + 6*chi*nu))/8.),
    sigmaprDr((8*a*chi + 3*chi*nu + chistar*(-5 + 8*b + 4*nu))/16.),
    r(0.0), prstar(0.0), pPhi(0.0),
    Heff(0.0), H(0.0), dHdr(0.0), dHdPhi(0.0), dHdprstar(0.0), dHdpPhi(0.0), v(0.0)
{ }

void WaveformUtilities::EOBHamiltonianWithSpin::operator()(const double r_new, const double prstar_new, const double pPhi_new) const {
  g(r_new);
  if(r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return; }
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  
  const double lambda = -(pow(chiKerr,2)*g.Dt) + pow(pow(chiKerr,2) + pow(r,2),2);
  const double dlambdadr = -(pow(chiKerr,2)*g.dDtdr) + 4*r*(pow(chiKerr,2) + pow(r,2));
  const double kappa = pow(chiKerr,2) - g.Dt + pow(r,2);
  const double dkappadr = -g.dDtdr + 2*r;
  
  const double sigma = sigmaconst + (pow(pPhi,2)*sigmapPhi)/pow(r,2) + sigmarinv/r + pow(prstar,2)*(sigmapr + (g.Dr*sigmaprDr)/pow(r,2))*pow(g.drstardr,2);
  const double dsigmadr = (-2*pow(pPhi,2)*sigmapPhi)/pow(r,3) + pow(g.drstardr,2)*pow(prstar,2)*((-2*g.Dr*sigmaprDr)/pow(r,3) + (g.dDrdr*sigmaprDr)/pow(r,2)) + 2*g.ddrstardrdr*g.drstardr*pow(prstar,2)*(sigmapr + (g.Dr*sigmaprDr)/pow(r,2)) - sigmarinv/pow(r,2);
  const double dsigmadprstar = 2*pow(g.drstardr,2)*prstar*(sigmapr + (g.Dr*sigmaprDr)/pow(r,2));
  const double dsigmadpPhi = (2*pPhi*sigmapPhi)/pow(r,2);
  
  const double HeffRadicand = (pow(prstar,2)*pow(pow(chiKerr,2) + pow(r,2),2) + (g.Dt*(2*pow(g.drstardr,4)*lambda*(4 - 3*nu)*nu*pow(prstar,4) + lambda*pow(r,2) + pow(pPhi,2)*pow(r,4)))/lambda)/lambda;
  
  const double dHeffRadicanddr = (-(pow(chiKerr,4)*dlambdadr*lambda*pow(prstar,2)) - 2*pow(g.drstardr,3)*lambda*(-(dlambdadr*g.drstardr*g.Dt) + g.dDtdr*g.drstardr*lambda + 4*g.ddrstardrdr*g.Dt*lambda)*nu*(-4 + 3*nu)*pow(prstar,4) + 2*pow(lambda,2)*(g.Dt + 2*pow(chiKerr,2)*pow(prstar,2))*r + lambda*(g.dDtdr*lambda - dlambdadr*(g.Dt + 2*pow(chiKerr,2)*pow(prstar,2)))*pow(r,2) + 4*lambda*(g.Dt*pow(pPhi,2) + lambda*pow(prstar,2))*pow(r,3) + ((-2*dlambdadr*g.Dt + g.dDtdr*lambda)*pow(pPhi,2) - dlambdadr*lambda*pow(prstar,2))*pow(r,4))/pow(lambda,3);
  const double dHeffRadicanddprstar = (2*prstar*(2*pow(g.drstardr,4)*g.Dt*(8 - 6*nu)*nu*pow(prstar,2) + pow(pow(chiKerr,2) + pow(r,2),2)))/lambda;
  const double dHeffRadicanddpPhi = (2*g.Dt*pPhi*pow(r,4))/pow(lambda,2);
  
  const double dHeffdr = dHeffRadicanddr/(2.*sqrt(HeffRadicand)) - (4*aSSterm)/pow(r,5) + (dsigmadr*kappa*lambda*pPhi + (-(dlambdadr*kappa) + dkappadr*lambda)*pPhi*(chiKerr + sigma))/pow(lambda,2);
  const double dHeffdprstar = dHeffRadicanddprstar/(2.*sqrt(HeffRadicand)) + (dsigmadprstar*kappa*pPhi)/lambda;
  const double dHeffdpPhi = dHeffRadicanddpPhi/(2.*sqrt(HeffRadicand)) + (kappa*(chiKerr + dsigmadpPhi*pPhi + sigma))/lambda;
  
  Heff = sqrt(HeffRadicand)
    + pPhi*kappa*(chiKerr+sigma)/lambda
    + aSSterm/fourth(r);
  H = sqrt(1 + 2*nu*(Heff-1)); /// This is a temporary value; see below
  dHdr = dHeffdr / H;
  ///dHdPhi = 0.0;
  dHdprstar = dHeffdprstar / H;
  dHdpPhi = dHeffdpPhi / H;
  
  H = (H-1.0)/nu;
  
  v = (dHdpPhi>0 ? pow(dHdpPhi, 1./3.) : -pow(-dHdpPhi, 1./3.));
  
  return;
}
