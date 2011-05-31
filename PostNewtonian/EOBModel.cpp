#include "EOBModel.hpp"

#include <cmath>
#include "VectorFunctions.hpp"
using WaveformUtilities::square;
using WaveformUtilities::cube;
using WaveformUtilities::fourth;
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
  dDrdr = dDtdr*Dinv + Dt * (-2*Dinv2 + -3*Dinv3/r)/(r*r*r);
  drdrstar = sqrt(Dt*Dr) / (r*r);  // Eq. (28) of PRD 81, 084041 [Pan et al., 2010]
  drstardr = 1.0 / drdrstar;
  return;
}

WaveformUtilities::EOBHamiltonianNonspinning::EOBHamiltonianNonspinning(const double delta, const EOBMetricNonspinning& ig)
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
    a4((94./3. - M_PI*M_PI*41./32.)*nu), // Eq. (9) of Pan et al., 2011
    a5((-5.828-143.5*nu+447*nu*nu)*nu), // Eq. (35a) of Pan et al., 2011
    a6(184*nu), // Eq. (35b) of Pan et al., 2011
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
  dDrdr = dDtdr*Dinv + Dt * (-2*Dinv2 + -3*Dinv3/r)/(r*r*r);
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
    sigmapPhi((chi*(a+3*nu/8.0)+chistar*(b-nu/8.0))/2.0),
    sigmapr(chi*(2*a+39*nu/16.0)-chistar*(b+31*nu/16.0)),
    sigmarinv(chi*(a+nu)/2.0+chistar*(4*b+5*nu+2)/8.0),
    sigmaconst(chistar/4.0),
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
  
  const double sigma = -sigmaconst + (pow(pPhi,2)*sigmapPhi)/pow(r,2) + (pow(prstar,2)*pow(pow(chiKerr,2) + pow(r,2),2)*sigmapr)/(g.Dr*g.Dt) - sigmarinv/r;
  const double dsigmadr = (-2*pow(pPhi,2)*sigmapPhi)/pow(r,3) + (4*pow(prstar,2)*r*(pow(chiKerr,2) + pow(r,2))*sigmapr)/(g.Dr*g.Dt) - (g.dDtdr*pow(prstar,2)*pow(pow(chiKerr,2) + pow(r,2),2)*sigmapr)/(g.Dr*pow(g.Dt,2)) - (g.dDrdr*pow(prstar,2)*pow(pow(chiKerr,2) + pow(r,2),2)*sigmapr)/(pow(g.Dr,2)*g.Dt) + sigmarinv/pow(r,2);
  const double dsigmadprstar = (2*prstar*pow(pow(chiKerr,2) + pow(r,2),2)*sigmapr)/(g.Dr*g.Dt);
  const double dsigmadpPhi = (2*pPhi*sigmapPhi)/pow(r,2);
  
  const double HeffRadicand = prstar*prstar*square(r*r+chiKerr*chiKerr)/lambda + (r*r*g.Dt/lambda)*(1 + r*r*pPhi*pPhi/lambda + (8-6*nu)*nu*fourth(prstar*g.drstardr)/(r*r));
  const double dHeffRadicanddr = (2*pow(chiKerr,8)*lambda*(dlambdadr*g.Dr*g.Dt + g.dDtdr*g.Dr*lambda + 2*g.dDrdr*g.Dt*lambda)*nu*(-4 + 3*nu)*pow(prstar,4) + pow(chiKerr,4)*lambda*pow(prstar,2)*(-(dlambdadr*pow(g.Dr,3)*pow(g.Dt,2)) + 48*g.Dr*g.Dt*lambda*(4 - 3*nu)*nu*pow(prstar,2)*pow(r,3) + 12*(dlambdadr*g.Dr*g.Dt + g.dDtdr*g.Dr*lambda + 2*g.dDrdr*g.Dt*lambda)*nu*(-4 + 3*nu)*pow(prstar,2)*pow(r,4)) + 2*pow(chiKerr,2)*lambda*pow(prstar,2)*r*(8*g.dDrdr*g.Dt*lambda*nu*(-4 + 3*nu)*pow(prstar,2)*pow(r,5) + pow(g.Dr,3)*pow(g.Dt,2)*(2*lambda - dlambdadr*r) + 4*g.Dr*nu*(-4 + 3*nu)*pow(prstar,2)*pow(r,4)*(-6*g.Dt*lambda + dlambdadr*g.Dt*r + g.dDtdr*lambda*r)) + 8*pow(chiKerr,6)*lambda*nu*(-4 + 3*nu)*pow(prstar,4)*r*(2*g.dDrdr*g.Dt*lambda*r + g.Dr*(-2*g.Dt*lambda + dlambdadr*g.Dt*r + g.dDtdr*lambda*r)) + r*(4*g.dDrdr*g.Dt*pow(lambda,2)*nu*(-4 + 3*nu)*pow(prstar,4)*pow(r,7) + 2*g.Dr*lambda*nu*(-4 + 3*nu)*pow(prstar,4)*pow(r,6)*(-8*g.Dt*lambda + dlambdadr*g.Dt*r + g.dDtdr*lambda*r) + pow(g.Dr,3)*pow(g.Dt,2)*(g.Dt*(2*lambda - dlambdadr*r)*(lambda + 2*pow(pPhi,2)*pow(r,2)) + lambda*r*(pow(prstar,2)*r*(4*lambda - dlambdadr*r) + g.dDtdr*(lambda + pow(pPhi,2)*pow(r,2))))))/(pow(g.Dr,3)*pow(g.Dt,2)*pow(lambda,3));
  const double dHeffRadicanddprstar = (2*prstar*pow(pow(chiKerr,2) + pow(r,2),2)*(1 + (2*(8 - 6*nu)*nu*pow(prstar,2)*pow(pow(chiKerr,2) + pow(r,2),2))/(pow(g.Dr,2)*g.Dt)))/lambda;
  const double dHeffRadicanddpPhi = (2*g.Dt*pPhi*pow(r,4))/pow(lambda,2);
  
  const double dHeffdr = dHeffRadicanddr/(2.*sqrt(HeffRadicand)) - (4*aSSterm)/pow(r,5) + (dsigmadr*kappa*lambda*pPhi*r + pPhi*(dkappadr*lambda*r + kappa*(lambda - dlambdadr*r))*(chiKerr + sigma))/pow(lambda,2);
  const double dHeffdprstar = dHeffRadicanddprstar/(2.*sqrt(HeffRadicand)) + (dsigmadprstar*kappa*pPhi*r)/lambda;
  const double dHeffdpPhi = dHeffRadicanddpPhi/(2.*sqrt(HeffRadicand)) + (kappa*r*(chiKerr + dsigmadpPhi*pPhi + sigma))/lambda;
  
  Heff = sqrt(HeffRadicand) + pPhi*r*kappa*(chiKerr+sigma)/lambda + aSSterm/fourth(r);
  H = sqrt(1 + 2*nu*(Heff-1)); /// This is a temporary value; see below
  dHdr = dHeffdr / H;
  ///dHdPhi = 0.0;
  dHdprstar = dHeffdprstar / H;
  dHdpPhi = dHeffdpPhi / H;
  
  H = (H-1.0)/nu;
  
  v = (dHdpPhi>0 ? pow(dHdpPhi, 1./3.) : -pow(-dHdpPhi, 1./3.));
  
  return;
}
