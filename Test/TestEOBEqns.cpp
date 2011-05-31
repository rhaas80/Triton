#include <iostream>
#include <fstream>
#include <iomanip>
#include "NumericalRecipes.hpp"
#include "EOBModel.hpp"
#include "Flux.hpp"
#include "VectorFunctions.hpp"

namespace WU = WaveformUtilities;
using WaveformUtilities::dydx;
using WaveformUtilities::max;
using WaveformUtilities::min;
using WaveformUtilities::avg;
using WaveformUtilities::cube;
using WaveformUtilities::sixth;
//using WaveformUtilities::PNLMax;
using WaveformUtilities::Flux_Taylor;
using WaveformUtilities::Flux_Pade44LogConst;
using WaveformUtilities::Flux_Pade44LogFac;
using WaveformUtilities::Flux_SumAmplitudes;
using WaveformUtilities::Flux_SumAmplitudesResummed;
using WaveformUtilities::Torque_KFPhi;
using WaveformUtilities::Torque_nKFPhi;
using WaveformUtilities::EOBMetricNonspinning;
using WaveformUtilities::EOBHamiltonianNonspinning;
using WaveformUtilities::EOBMetricWithSpin;
using WaveformUtilities::EOBHamiltonianWithSpin;
using WaveformUtilities::WaveformAmplitudes;
using WaveformUtilities::WaveformAmplitudesResummed;

using namespace std;

typedef int NRerror;

const unsigned int PNLMax=8;


//////////////////////////////////////////////////////////////////////////
//// Objects of this class will act as the functor
//// for use in the integration scheme.
//////////////////////////////////////////////////////////////////////////
class EOBRightHandSide {
  friend int main();
private:
  double delta, nu, chis, chia, PNOrder;
  double a4, a5, a6;
  double d4;
  double chitot, chistar, chieff, ageff, bgeff, a3PNSS;
  double Deltat15Num0, Deltat15Num1, Deltat15Den2, Deltat15Den3, Deltat15Den4, Deltat15Den5, Deltat15Den6, Deltat15Den7;
  double DeltaR15Num0, DeltaR15Num1, DeltaR15Num2, DeltaR15Num3, DeltaR15Num4, DeltaR15Num5;
  double DeltaR15Den2, DeltaR15Den3, DeltaR15Den4, DeltaR15Den5, DeltaR15Den6, DeltaR15Den7;
  double vPole, vLSO;
  double f1, f2, f3, f4, f5, f6, f7, f8;
  double PadeFlux44Num0, PadeFlux44Num1, PadeFlux44Num2, PadeFlux44Num3, PadeFlux44Num4;
  double PadeFlux44Den0, PadeFlux44Den1, PadeFlux44Den2, PadeFlux44Den3, PadeFlux44Den4;
  
protected:
  inline double SQR(const double& a) const { return a*a; }
  inline double CUB(const double& a) const { return a*a*a; }
  
  //// Metric functions Deltat and DeltaR
  double Deltat15(const double& r) const;
  double dDeltat15dr(const double& r) const;
  double DeltaR15(const double& r) const;
  double dDeltaR15dr(const double& r) const;
  //// Hamiltonians and derivatives
  vector<double> HamiltoniansAndDerivatives(const double& r, const double& prstar, const double& pPhi) const;
  //// Flux
  double SummSquaredMagnitudeSquaredhlm(const double& vOmega) const;
  double nKFhatPhi(const double& Omega) const;
  double PadeFlux(const double& v) const;
  double nKFhatPhiPade(const double& r, const double& prstar, const double& pPhi, const double& Heff, const double& Hreal, const double& Omega) const;
  double nKFhatPhiResummed(const double& r, const double& prstar, const double& pPhi, const double& Heff, const double& Hreal, const double& Omega) const;
  
public:
  //// Constructor
  EOBRightHandSide(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder);
  //// Rough initial data estimate
  vector<double> InitialData(const double& r0) const;
  //// Make this object into a functor for use in the integration routine
  void operator() (const double t, const vector<double>& y, vector<double>& dydt) const;
  //// Public access
  double Omega(const double& r, const double& prstar, const double& pPhi) const;
  double v(const double& r, const double& prstar, const double& pPhi) const { return pow(Omega(r, prstar, pPhi), 1.0/3.0); }
  double drdrstar(const double& r) const { return sqrt(Deltat15(r)*DeltaR15(r)) / (r*r+chieff*chieff); }
  double drstardr(const double& r) const { return (r*r+chieff*chieff) / sqrt(Deltat15(r)*DeltaR15(r)); }
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////  EOBRightHandSide class definitions
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
EOBRightHandSide::EOBRightHandSide(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder)
  : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), chia(ichia), PNOrder(PNPhaseOrder),
    a4((94./3. - M_PI*M_PI*41./32.)*nu), // Eq. (9) of Pan et al., 2011
    a5((-5.828-143.5*nu+447*nu*nu)*nu), // Eq. (35a) of Pan et al., 2011
    a6(184*nu), // Eq. (35b) of Pan et al., 2011
    d4(36*nu*nu), // Below Eq. (59) of PRD 78, 104020
    chitot((1-2*nu)*chis+delta*chia), // a.k.a. chi; S = S1 + S2
    chistar(2*nu*chis), // Sstar = S1*m2/m1 + S2*m1/m2
    chieff(chis+delta*chia), // a.k.a. chiKerr; SKerr = S + Sstar
    ageff(0.0),
    bgeff(-1.65),
    a3PNSS(1.5),
    Deltat15Num0(32 - 4*a4 - a5 - 24*nu + SQR(chieff)*(-32 + 6*SQR(chieff) + 4*nu)),
    Deltat15Num1(-64 + 12*a4 + 4*a5 + a6 + SQR(chieff)*(80 - 2*a4 + SQR(chieff)*(-24 + SQR(chieff)) - 24*nu) + 64*nu - 4*SQR(nu)),
    Deltat15Den2(32 - 4*a4 - a5 - 24*nu + SQR(chieff)*(-32 + 6*SQR(chieff) + 4*nu)),
    Deltat15Den3(4*a4 + 2*a5 + a6 + SQR(chieff)*(16 - 2*a4 + SQR(chieff)*(-12 + SQR(chieff)) - 16*nu) + 16*nu - 4*SQR(nu)),
    Deltat15Den4(8*a4 + 4*a5 + 2*a6 + SQR(chieff)*(a5 + SQR(chieff)*(8 - 4*SQR(chieff) - 4*nu) - 8*nu) + 32*nu - 8*SQR(nu)),
    Deltat15Den5(16*a4 + 8*a5 + 4*a6 + 8*a4*nu + 2*a5*nu + 32*SQR(nu) + SQR(chieff)*(-4*a4 - a6 + SQR(chieff)*(2*a4 + SQR(chieff)*(4 - SQR(chieff)) - 4*nu) + 32*nu - 4*SQR(nu))),
    Deltat15Den6(4*SQR(a4) + 16*a5 + a4*a5 + 8*a6 + 32*a4*nu - 2*a6*nu + 32*SQR(nu) + 8*(nu*nu*nu) + SQR(chieff)*(16*a4 - 4*a5 - 4*a6 + 32*SQR(nu) + SQR(chieff)*(-2*a4 - a5 + 24*nu + SQR(chieff)*(2*SQR(chieff) + 2*nu)))),
    Deltat15Den7(4*SQR(a4) + 4*a4*a5 + SQR(a5) + 16*a6 - a4*a6 + 32*a4*nu + 16*a5*nu - 8*a6*nu + 4*a4*SQR(nu) + 32*(nu*nu*nu) + SQR(chieff)*(2*SQR(a4) + 16*a5 - 12*a6 + 8*a4*nu - 8*a5*nu + 48*SQR(nu) + SQR(chieff)*(12*a4 - 8*a5 + a6 + 12*SQR(nu) + SQR(chieff)*(-3*a4 + SQR(SQR(chieff)) + 16*nu)))),
    DeltaR15Num0(32 - 4*a4 - a5 - 24*nu + SQR(chieff)*(-32 + 6*SQR(chieff) + 4*nu)),
    DeltaR15Num1(-64 + 12*a4 + 4*a5 + a6 + SQR(chieff)*(80 - 2*a4 + SQR(chieff)*(-24 + SQR(chieff)) - 24*nu) + 64*nu - 4*SQR(nu)),
    DeltaR15Num2(192*nu - 24*a4*nu - 6*a5*nu - 144*SQR(nu) + SQR(chieff)*(-192*nu + 36*SQR(chieff)*nu + 24*SQR(nu))),
    DeltaR15Num3(1280*nu - 136*a4*nu - 28*a5*nu + 6*a6*nu - 1056*SQR(nu) + 24*a4*SQR(nu) + 6*a5*SQR(nu) + 120*(nu*nu*nu) + SQR(chieff)*(-1184*nu - 12*a4*nu + 256*SQR(nu) - 24*(nu*nu*nu) + SQR(chieff)*(168*nu + 6*SQR(chieff)*nu - 36*SQR(nu)))),
    DeltaR15Num4(-32*d4 + 4*a4*d4 + a5*d4 - 3328*nu + 624*a4*nu + 208*a5*nu + 52*a6*nu + 24*d4*nu + 4864*SQR(nu) - 216*a4*SQR(nu) - 60*a5*SQR(nu) - 6*a6*SQR(nu) - 1456*(nu*nu*nu) + 24*SQR(SQR(nu)) + SQR(chieff)*(32*d4 + 4160*nu - 104*a4*nu - 4*d4*nu - 2880*SQR(nu) + 12*a4*SQR(nu) + 288*(nu*nu*nu) + SQR(chieff)*(-6*d4 - 1248*nu + 360*SQR(nu) + SQR(chieff)*(52*nu - 6*SQR(nu))))),
    DeltaR15Num5(64*d4 - 12*a4*d4 - 4*a5*d4 - a6*d4 - 64*d4*nu - 2304*SQR(nu) + 432*a4*SQR(nu) + 144*a5*SQR(nu) + 36*a6*SQR(nu) + 4*d4*SQR(nu) + 2304*(nu*nu*nu) - 144*SQR(SQR(nu)) + SQR(chieff)*(-80*d4 + 2*a4*d4 + 24*d4*nu + 2880*SQR(nu) - 72*a4*SQR(nu) - 864*(nu*nu*nu) + SQR(chieff)*(24*d4 - 864*SQR(nu) + SQR(chieff)*(-d4 + 36*SQR(nu))))),
    DeltaR15Den2(32 - 4*a4 - a5 - 24*nu + SQR(chieff)*(-32 + 6*SQR(chieff) + 4*nu)),
    DeltaR15Den3(4*a4 + 2*a5 + a6 + SQR(chieff)*(16 - 2*a4 + SQR(chieff)*(-12 + SQR(chieff)) - 16*nu) + 16*nu - 4*SQR(nu)),
    DeltaR15Den4(8*a4 + 4*a5 + 2*a6 + SQR(chieff)*(a5 + SQR(chieff)*(8 - 4*SQR(chieff) - 4*nu) - 8*nu) + 32*nu - 8*SQR(nu)),
    DeltaR15Den5(16*a4 + 8*a5 + 4*a6 + 8*a4*nu + 2*a5*nu + 32*SQR(nu) + SQR(chieff)*(-4*a4 - a6 + SQR(chieff)*(2*a4 + SQR(chieff)*(4 - SQR(chieff)) - 4*nu) + 32*nu - 4*SQR(nu))),
    DeltaR15Den6(4*SQR(a4) + 16*a5 + a4*a5 + 8*a6 + 32*a4*nu - 2*a6*nu + 32*SQR(nu) + 8*(nu*nu*nu) + SQR(chieff)*(16*a4 - 4*a5 - 4*a6 + 32*SQR(nu) + SQR(chieff)*(-2*a4 - a5 + 24*nu + SQR(chieff)*(2*SQR(chieff) + 2*nu)))),
    DeltaR15Den7(4*SQR(a4) + 4*a4*a5 + SQR(a5) + 16*a6 - a4*a6 + 32*a4*nu + 16*a5*nu - 8*a6*nu + 4*a4*SQR(nu) + 32*(nu*nu*nu) + SQR(chieff)*(2*SQR(a4) + 16*a5 - 12*a6 + 8*a4*nu - 8*a5*nu + 48*SQR(nu) + SQR(chieff)*(12*a4 - 8*a5 + a6 + 12*SQR(nu) + SQR(chieff)*(-3*a4 + SQR(SQR(chieff)) + 16*nu)))),
    vPole( (2*(3 + nu))/(4*chis*(-2 + nu) + sqrt((-3 - nu)*(-36 + 35*nu))) ), // The pole of the 2,2 approximant of the energy function, with lowest-order spin dependence
    //vPole( sqrt( (1+nu/3.0) / (3.0-35.0*nu/12.0) ) ), // Eq. (41) of PRD 78, 104020
    vLSO( 2*sqrt(((3 + nu)*(-1 + 2*(3 + nu)*sqrt(1/(144 + nu*(-81 + 4*nu)))))/(-36 + 35*nu)) ), // Table 1 of PRD 63, 044023
    f1(-(1/vPole)),
    f2((-1247 - 980*nu)/336.),
    f3((1247 + 980*nu + 84*(-11*chia*delta + chis*(-11 + 12*nu) + 16*M_PI)*vPole)/(336.*vPole)),
    f4((2268*(11*chia*delta + chis*(11 - 12*nu) - 16*M_PI) + (-44711 + 18711*pow(chis,2) + 166878*nu + 63*(297*chia*(chia + 2*chis*delta) - 36*(32*pow(chia,2) + pow(chis,2))*nu + 520*pow(nu,2)))*vPole)/(9072.*vPole)),
    f5((89422 + 1134*pow(chis,2)*(-33 + 4*nu) - 36*nu*(9271 + 1820*nu) + 13608*pow(chia,3)*delta*(-1 + nu)*vPole - 9*(14*chis*(567 + 108*pow(chis,2)*(1 - 3*nu) + 4*nu*(-935 + 628*nu)) + 3*(8191 + 16324*nu)*M_PI)*vPole + 1134*pow(chia,2)*(-33 + 128*nu + 36*chis*(-1 + 3*nu)*vPole) + 126*chia*delta*(-594*chis + (-567 + 324*pow(chis,2)*(-1 + nu) + 2840*nu)*vPole))/(18144.*vPole)),
    f6(95.10839000836025 - (1712*EulerGamma)/105. - (94403*pow(nu,2))/3024. - (775*pow(nu,3))/324. + (16*pow(M_PI,2))/3. + (nu*(-134543 + 6642*pow(M_PI,2)))/7776. + (24573*M_PI - 14*(324*chia*pow(chis,2)*delta*(-1 + nu) + 108*pow(chis,3)*(-1 + 3*nu) + chia*delta*(-567 + 108*pow(chia,2)*(-1 + nu) + 2840*nu) + chis*(-567 + 4*(935 - 628*nu)*nu + 324*pow(chia,2)*(-1 + 3*nu)) - 3498*nu*M_PI))/(2016.*vPole) - (856*log(16*pow(vLSO,2)))/105.),
    f7((3416878080*EulerGamma - 3*(6643739519 + 372556800*pow(M_PI,2)) + 1925*(2*nu*(941801 + 6*nu*(283209 + 21700*nu) - 46494*pow(M_PI,2)) + 45*(-78168 + nu*(300643 + 154708*nu))*M_PI*vPole) + 1708439040*log(16*pow(vLSO,2)))/(2.095632e8*vPole)),
    f8(-101.65745990813167 + (232597*EulerGamma)/4410. - (1369*pow(M_PI,2))/126. - (5*(-78168 + nu*(300643 + 154708*nu))*M_PI)/(12096.*vPole) + (39931*log(2))/294. - (47385*log(3))/1568. + (232597*log(vLSO))/4410.),
    PadeFlux44Num0(pow(f4,4) + pow(f3,2)*pow(f5,2) - f1*pow(f5,3) + pow(f2,2)*pow(f6,2) - f3*f6*(2*f2*f5 + f1*f6) - pow(f3,3)*f7 - pow(f2,2)*f5*f7 + f1*f3*f5*f7 - pow(f4,2)*(3*f3*f5 + 2*f2*f6 + f1*f7) + 2*f4*((pow(f3,2) + f1*f5)*f6 + f2*(pow(f5,2) + f3*f7))),
    PadeFlux44Num1(-(pow(f4,3)*f5) - f2*pow(f5,3) - 2*pow(f3,2)*f5*f6 + f2*f3*pow(f6,2) + f2*f3*f5*f7 - pow(f2,2)*f6*f7 + pow(f4,2)*(f3*f6 + f2*f7) - pow(f1,2)*(pow(f5,3) + f3*pow(f6,2) + pow(f4,2)*f7 - f5*(2*f4*f6 + f3*f7)) + pow(f3,3)*f8 + pow(f2,2)*f5*f8 - f3*f4*(-2*pow(f5,2) + f3*f7 + 2*f2*f8) + f1*(pow(f4,4) + pow(f3,2)*pow(f5,2) + f6*(pow(f5,2) + pow(f2,2)*f6) - pow(f3,3)*f7 - pow(f2,2)*f5*f7 + f4*(2*pow(f3,2)*f6 - pow(f6,2) - f5*f7 + 2*f2*(pow(f5,2) + f3*f7)) + pow(f4,2)*(-3*f3*f5 - 2*f2*f6 + f8) + f3*(-2*f2*f5*f6 + f6*f7 - f5*f8))),
    PadeFlux44Num2(pow(f4,2)*pow(f5,2) - f3*pow(f5,3) - pow(f4,3)*f6 + f3*pow(f4,2)*f7 + pow(f3,2)*f5*f7 + pow(f2,3)*(pow(f6,2) - f5*f7) - pow(f3,2)*f4*f8 + pow(f2,2)*(-2*pow(f4,2)*f6 - 2*f3*f5*f6 - f1*f6*f7 + pow(f7,2) + 2*f4*(pow(f5,2) + f3*f7) + f1*f5*f8 - f6*f8) + pow(f1,2)*(pow(f5,2)*f6 - f4*pow(f6,2) + f3*f6*f7 + pow(f4,2)*f8 - f5*(f4*f7 + f3*f8)) + f2*(pow(f4,4) - (pow(f3,2) - 2*f1*f5 + f6)*(-pow(f5,2) + f3*f7) + f3*f5*f8 + pow(f4,2)*(-3*f3*f5 + f8) + f4*(2*pow(f3,2)*f6 + 2*f1*f5*f6 + pow(f6,2) - 3*f5*f7 - 2*f1*f3*f8)) + f1*(-(pow(f4,3)*f5) + f3*pow(f4,2)*f6 - 2*pow(f3,2)*f5*f6 - f5*pow(f6,2) + pow(f5,2)*f7 - f3*pow(f7,2) + f3*(pow(f3,2) + f6)*f8 + f4*(2*f3*pow(f5,2) - pow(f3,2)*f7 + f6*f7 - f5*f8))),
    PadeFlux44Num3(f1*pow(f4,2)*pow(f5,2) - f4*pow(f5,3) - f1*pow(f4,3)*f6 + 2*pow(f4,2)*f5*f6 - pow(f1,2)*f5*pow(f6,2) + f1*pow(f6,3) - pow(f3,4)*f7 - pow(f4,3)*f7 + pow(f1,2)*pow(f5,2)*f7 + pow(f1,2)*f4*f6*f7 - 2*f1*f5*f6*f7 + f1*f4*pow(f7,2) + f1*(-(f1*f4*f5) + pow(f5,2) - f4*f6)*f8 + pow(f3,3)*(pow(f5,2) + 2*f4*f6 + f2*f8) + pow(f2,3)*(-(f6*f7) + f5*f8) - pow(f3,2)*(3*pow(f4,2)*f5 + 4*f2*f5*f6 + f1*pow(f6,2) - f2*f4*f7 - 2*f1*f5*f7 - f6*f7 + f1*f4*f8 + f5*f8) + pow(f2,2)*(-pow(f5,3) + f7*(pow(f4,2) + f1*f7) - f1*f6*f8) + f3*(pow(f4,4) - 2*f1*pow(f5,3) + pow(f5,2)*f6 + 2*pow(f2,2)*pow(f6,2) - pow(f1,2)*pow(f7,2) - f2*pow(f7,2) + (pow(f1,2) + f2)*f6*f8 + pow(f4,2)*(-(f2*f6) + f8) - 2*f4*(-2*f2*pow(f5,2) - f1*f5*f6 + pow(f6,2) + pow(f2,2)*f8)) + f2*(-(pow(f4,3)*f5) + f5*(2*f1*f5*f6 - pow(f6,2) + f5*f7) + 2*f1*pow(f4,2)*f8 + f4*(-4*f1*f5*f7 + f6*f7 - f5*f8))),
    PadeFlux44Num4(pow(f4,5) + pow(f5,4) - 2*pow(f3,3)*f5*f6 + 2*f1*f3*pow(f5,2)*f6 + 2*f3*f5*pow(f6,2) + pow(f1,2)*pow(f6,3) - 2*f3*pow(f5,2)*f7 + 2*f1*pow(f3,2)*f6*f7 - 2*pow(f1,2)*f5*f6*f7 + pow(f3,2)*pow(f7,2) + (pow(pow(f3,2) - f1*f5,2) - pow(f3,2)*f6)*f8 - pow(f4,3)*(4*f3*f5 + 3*f2*f6 + 2*f1*f7 + f8) + pow(f4,2)*(3*f2*pow(f5,2) + 3*pow(f3,2)*f6 + 4*f1*f5*f6 + pow(f6,2) + 4*f2*f3*f7 + 2*f5*f7 + pow(f2,2)*f8 + 2*f1*f3*f8) + pow(f2,2)*(pow(f5,2)*f6 - 2*f3*f6*f7 + 2*f3*f5*f8) + pow(f2,3)*(pow(f7,2) - f6*f8) - f4*(3*pow(f5,2)*f6 - 2*pow(f2,2)*pow(f6,2) + 2*pow(f3,3)*f7 + 4*pow(f2,2)*f5*f7 + f2*pow(f7,2) + 2*f3*f6*(f2*f5 + 2*f1*f6 + f7) - 2*f3*f5*f8 - f2*f6*f8 - 3*pow(f3,2)*(pow(f5,2) - f2*f8) + 2*f1*(pow(f5,3) - f2*f6*f7 + f2*f5*f8) + pow(f1,2)*(-pow(f7,2) + f6*f8)) + f2*(-pow(f6,3) + 2*f5*f6*f7 + 2*f1*f5*(-pow(f6,2) + f5*f7) + pow(f3,2)*(pow(f6,2) + 2*f5*f7) - pow(f5,2)*f8 - 2*f3*(pow(f5,3) + f1*(pow(f7,2) - f6*f8)))),
    PadeFlux44Den0(pow(f4,4) + pow(f3,2)*pow(f5,2) - f1*pow(f5,3) + pow(f2,2)*pow(f6,2) - f3*f6*(2*f2*f5 + f1*f6) - pow(f3,3)*f7 - pow(f2,2)*f5*f7 + f1*f3*f5*f7 - pow(f4,2)*(3*f3*f5 + 2*f2*f6 + f1*f7) + 2*f4*((pow(f3,2) + f1*f5)*f6 + f2*(pow(f5,2) + f3*f7))),
    PadeFlux44Den1(-(pow(f4,3)*f5) - 2*pow(f3,2)*f5*f6 + f1*pow(f5,2)*f6 + f1*f3*f6*f7 + f2*(-pow(f5,3) + f3*pow(f6,2) + f3*f5*f7) + pow(f3,3)*f8 - f1*f3*f5*f8 + pow(f4,2)*(f3*f6 + f2*f7 + f1*f8) - f4*(-2*f3*pow(f5,2) + f1*pow(f6,2) + pow(f3,2)*f7 + f1*f5*f7 + 2*f2*f3*f8) + pow(f2,2)*(-(f6*f7) + f5*f8)),
    PadeFlux44Den2(-(pow(f4,3)*f6) + f2*pow(f5,2)*f6 - f1*f5*pow(f6,2) + pow(f3,2)*f5*f7 + f1*pow(f5,2)*f7 + pow(f2,2)*pow(f7,2) - f3*(pow(f5,3) + f2*f6*f7 + f1*pow(f7,2)) - pow(f2,2)*f6*f8 + f3*(f2*f5 + f1*f6)*f8 + pow(f4,2)*(pow(f5,2) + f3*f7 + f2*f8) + f4*(f1*f6*f7 + f2*(pow(f6,2) - 3*f5*f7) - (pow(f3,2) + f1*f5)*f8)),
    PadeFlux44Den3(-(f2*f5*pow(f6,2)) + f1*pow(f6,3) - pow(f4,3)*f7 + f2*pow(f5,2)*f7 - 2*f1*f5*f6*f7 + f1*pow(f5,2)*f8 + pow(f4,2)*(2*f5*f6 + f3*f8) + pow(f3,2)*(f6*f7 - f5*f8) - f4*(pow(f5,3) + 2*f3*pow(f6,2) - f7*(f2*f6 + f1*f7) + f2*f5*f8 + f1*f6*f8) + f3*(pow(f5,2)*f6 - f2*pow(f7,2) + f2*f6*f8)),
    PadeFlux44Den4(pow(f5,4) + pow(f4,2)*pow(f6,2) - f2*pow(f6,3) + pow(f3,2)*pow(f7,2) - f4*f7*(2*f3*f6 + f2*f7) - pow(f4,3)*f8 - pow(f3,2)*f6*f8 + f2*f4*f6*f8 - pow(f5,2)*(3*f4*f6 + 2*f3*f7 + f2*f8) + 2*f5*((pow(f4,2) + f2*f6)*f7 + f3*(pow(f6,2) + f4*f8)))
{ }
//// Metric function Deltat
double EOBRightHandSide::Deltat15(const double& r) const {
  const double u=1.0/r;
  const double Deltat15Num = Deltat15Num0 + u*Deltat15Num1;
  const double Deltat15Den = u*u*(Deltat15Den2 + u*(Deltat15Den3 + u*(Deltat15Den4 + u*(Deltat15Den5 + u*(Deltat15Den6 + u*(Deltat15Den7))))));
  return Deltat15Num / Deltat15Den;
}
double EOBRightHandSide::dDeltat15dr(const double& r) const {
  const double u=1.0/r;
  const double Deltat15Num = Deltat15Num0 + u*Deltat15Num1;
  const double Deltat15Den = u*u*(Deltat15Den2 + u*(Deltat15Den3 + u*(Deltat15Den4 + u*(Deltat15Den5 + u*(Deltat15Den6 + u*(Deltat15Den7))))));
  const double Deltat15Nump = Deltat15Num1;
  const double Deltat15Denp = u*(2*Deltat15Den2 + u*(3*Deltat15Den3 + u*(4*Deltat15Den4 + u*(5*Deltat15Den5 + u*(6*Deltat15Den6 + u*(7*Deltat15Den7))))));
  return u * u * (Deltat15Num*Deltat15Denp-Deltat15Nump*Deltat15Den) / SQR(Deltat15Den);
}
double EOBRightHandSide::DeltaR15(const double& r) const {
  const double u=1.0/r;
  const double DeltaR15Num = DeltaR15Num0 + u*(DeltaR15Num1 + u*(DeltaR15Num2 + u*(DeltaR15Num3 + u*(DeltaR15Num4 + u*(DeltaR15Num5)))));
  const double DeltaR15Den = u*u*(DeltaR15Den2 + u*(DeltaR15Den3 + u*(DeltaR15Den4 + u*(DeltaR15Den5 + u*(DeltaR15Den6 + u*(DeltaR15Den7))))));
  return DeltaR15Num / DeltaR15Den;
}
double EOBRightHandSide::dDeltaR15dr(const double& r) const {
  const double u=1.0/r;
  const double DeltaR15Num = DeltaR15Num0 + u*(DeltaR15Num1 + u*(DeltaR15Num2 + u*(DeltaR15Num3 + u*(DeltaR15Num4 + u*(DeltaR15Num5)))));
  const double DeltaR15Den = u*u*(DeltaR15Den2 + u*(DeltaR15Den3 + u*(DeltaR15Den4 + u*(DeltaR15Den5 + u*(DeltaR15Den6 + u*(DeltaR15Den7))))));
  const double DeltaR15Nump = DeltaR15Num1 + u*(2*DeltaR15Num2 + u*(3*DeltaR15Num3 + u*(4*DeltaR15Num4 + u*(5*DeltaR15Num5))));
  const double DeltaR15Denp = u*(2*DeltaR15Den2 + u*(3*DeltaR15Den3 + u*(4*DeltaR15Den4 + u*(5*DeltaR15Den5 + u*(6*DeltaR15Den6 + u*(7*DeltaR15Den7))))));
  return u * u * (DeltaR15Num*DeltaR15Denp-DeltaR15Nump*DeltaR15Den) / SQR(DeltaR15Den);
}
vector<double> EOBRightHandSide::HamiltoniansAndDerivatives(const double& r, const double& prstar, const double& pPhi) const {
  vector<double> Derivatives(5);
  const double Deltat = Deltat15(r);
  const double dDeltatdr = dDeltat15dr(r);
  const double DeltaR = DeltaR15(r);
  const double dDeltaRdr = dDeltaR15dr(r);
  const double Den = SQR(r*r+chieff*chieff) - chieff*chieff*Deltat;
  const double dDendr = 4*r*(r*r+chieff*chieff) - chieff*chieff*dDeltatdr;
  const double H0 = r*r*Deltat/Den;
  const double dH0dr = (2*r*Deltat+r*r*dDeltatdr)/Den - dDendr*H0/Den;
  const double H1 = (Deltat*Den-chieff*chieff*Den+chieff*chieff*SQR(r*r+chieff*chieff-Deltat)) / SQR(Den);
  const double dH1dr = (dDeltatdr*Den+Deltat*dDendr-chieff*chieff*dDendr+chieff*chieff*2*(2*r-dDeltatdr)*(r*r+chieff*chieff-dDeltatdr)) / SQR(Den) - 2*dDendr*H1/Den;
  const double H2 = SQR(r*r+chieff*chieff)/Den;
  const double dH2dr = 4*r*(r*r+chieff*chieff)/Den - dDendr*H2/Den;
  const double H3 = (8-6*nu)*nu*SQR(SQR(r*r+chieff*chieff))/(Den*SQR(Deltat)*DeltaR);
  const double dH3dr = (8-6*nu)*nu*8*r*CUB(r*r+chieff*chieff)/(Den*SQR(Deltat)*DeltaR)
    - (dDendr*SQR(Deltat)*DeltaR+Den*2*Deltat*dDeltatdr*DeltaR+Den*SQR(Deltat)*dDeltaRdr)*H3/(Den*SQR(Deltat)*DeltaR);
  const double H4 = (r*r+chieff*chieff-Deltat)/Den;
  const double dH4dr = (2*r-dDeltatdr)/Den - dDendr*H4/Den;
  
  const double geffS = 2 + SQR(pPhi)*(0.375*nu+ageff)/(r*r) - SQR(prstar)*(4.125*nu+2*ageff)*SQR(r*r+chieff*chieff)/(Deltat*DeltaR) - (nu+ageff)/r;
  const double dgeffSdr = -2*SQR(pPhi)*(0.375*nu+ageff)/(r*r*r)
    - SQR(prstar)*(4.125*nu+2*ageff)*(4*r*(r*r+chieff*chieff)/(Deltat*DeltaR) - (dDeltatdr*DeltaR+Deltat*dDeltaRdr)*SQR(r*r+chieff*chieff)/SQR(Deltat*DeltaR))
    + (nu+ageff)/(r*r);
  const double dgeffSdprstar = - 2*prstar*(4.125*nu+2*ageff)*SQR(r*r+chieff*chieff)/(Deltat*DeltaR);
  const double dgeffSdpPhi = 2*pPhi*(0.375*nu+ageff)/(r*r);
  const double geffSstar = 1.5+SQR(pPhi)*(-0.625+0.5*nu+bgeff)/(r*r) - SQR(prstar)*(0.625+3.25*nu+2*bgeff)*SQR(r*r+chieff*chieff)/(Deltat*DeltaR) - (0.5+1.25*nu+bgeff)/r;
  const double dgeffSstardr = -2*SQR(pPhi)*(-0.625+0.5*nu+bgeff)/(r*r*r)
    - SQR(prstar)*(0.625+3.25*nu+2*bgeff)*(4*r*(r*r+chieff*chieff)/(Deltat*DeltaR) - (dDeltatdr*DeltaR+Deltat*dDeltaRdr)*SQR(r*r+chieff*chieff)/SQR(Deltat*DeltaR))
    + (0.5+1.25*nu+bgeff)/(r*r);
  const double dgeffSstardprstar = - 2*prstar*(0.625+3.25*nu+2*bgeff)*SQR(r*r+chieff*chieff)/(Deltat*DeltaR);
  const double dgeffSstardpPhi = 2*pPhi*(-0.625+0.5*nu+bgeff)/(r*r);
  const double sigma = 0.5*((geffS-2)*chitot+(geffSstar-2)*chistar);
  const double dsigmadr = 0.5*(dgeffSdr*chitot+dgeffSstardr*chistar);
  const double dsigmadprstar = 0.5*(dgeffSdprstar*chitot+dgeffSstardprstar*chistar);
  const double dsigmadpPhi = 0.5*(dgeffSdpPhi*chitot+dgeffSstardpPhi*chistar);
  
  const double Heffsqrt = sqrt(H0 + SQR(pPhi)*H1 + SQR(prstar)*H2 + SQR(SQR(prstar))*H3);
  const double Heff =
    Heffsqrt
    + pPhi*(chieff+sigma)*H4
    + a3PNSS*chieff*chistar/(r*r*r*r);
  const double dHeffdr =
    0.5*(dH0dr + SQR(pPhi)*dH1dr + SQR(prstar)*dH2dr + SQR(SQR(prstar))*dH3dr)/Heffsqrt
    + pPhi*dsigmadr*H4 + pPhi*(chieff+sigma)*dH4dr
    - 4*a3PNSS*chieff*chistar/(r*r*r*r*r);
  const double dHeffdprstar =
    0.5*(2*prstar*H2 + 4*CUB(prstar)*H3)/Heffsqrt
    + pPhi*(dsigmadprstar)*H4;
  const double dHeffdpPhi =
    pPhi*H1/Heffsqrt
    + (chieff+sigma)*H4 + pPhi*(dsigmadpPhi)*H4;
  
  const double Hreal = sqrt(1+2*nu*(Heff-1)) / nu;
  
  Derivatives[0] = dHeffdr / (nu*Hreal);
  Derivatives[1] = dHeffdprstar / (nu*Hreal);
  Derivatives[2] = dHeffdpPhi / (nu*Hreal);
  Derivatives[3] = Heff;
  Derivatives[4] = Hreal - 1/nu;
  return Derivatives;
}
//// Flux
double EOBRightHandSide::SummSquaredMagnitudeSquaredhlm(const double& vOmega) const {
  double Sum=0.0;
//   vector<double> amp(1,0.0);
//   vector<double> phi(1,0.0);
//   for(int l=2; l<=PNLMax; ++l) {
//     for(int m=1; m<=l; ++m) {
//       PNAmplitudes(l, m, vector<double>(1, vOmega), vector<double>(1, 0.0),
// 		   delta, chia, chis, amp, phi);
//       Sum += m*m*amp[0]*amp[0];
//       PNAmplitudes(l, -m, vector<double>(1, vOmega), vector<double>(1, 0.0),
// 		   delta, chia, chis, amp, phi);
//       Sum += m*m*amp[0]*amp[0];
//     }
//   }
  cerr << "Debugging!!!" << endl;
  cout << "Debugging!!!" << endl;
  return Sum;
}
double EOBRightHandSide::nKFhatPhi(const double& Omega) const { // Eqs. (13) and (16) of Pan et al. 2011
  return -(Omega/(16.0*M_PI*nu))*SummSquaredMagnitudeSquaredhlm(pow(Omega, 1.0/3.0));
}
double EOBRightHandSide::PadeFlux(const double& v) const {
  const double PadeFluxTermNum = (PadeFlux44Num0 + v*(PadeFlux44Num1 + v*(PadeFlux44Num2 + v*(PadeFlux44Num3 + v*(PadeFlux44Num4)))));
  const double PadeFluxTermDen = (PadeFlux44Den0 + v*(PadeFlux44Den1 + v*(PadeFlux44Den2 + v*(PadeFlux44Den3 + v*(PadeFlux44Den4)))));
  return PadeFluxTermNum / PadeFluxTermDen;
}
// D = r*r*A; Dp = 2*r*A + r*r*Ap = 2*D/r + r*r*Ap ; Ap = (Dp-2*D/r)/(r*r)
double EOBRightHandSide::nKFhatPhiPade(const double& r, const double& prstar, const double& pPhi, const double& Heff, const double& Hreal, const double& Omega) const
{ // Eqs. (13) and (16) of Pan et al. 2011
  const double vOmega( pow(Omega, 1.0/3.0) );
  //const double pPhiCirc = 
  const vector<double> CircularHDerivs( HamiltoniansAndDerivatives(r, 0.0, pPhi) );
  const double& dHrealdpPhi = CircularHDerivs[2];
  const double psi( 1.0/(dHrealdpPhi*dHrealdpPhi*r*r*r) ); // Eq. (66) of PRD 78, 104020
  const double vPhi( Omega*r*pow(psi, 1.0/3.0) ); // Eq. (66) of PRD 78, 104020
  const double PadeFluxTerm = PadeFlux(vOmega);
  //cout << setprecision(10) << setw(16) << vOmega << " " << setw(16) << PadeFluxTermNum << " " << setw(16) << PadeFluxTermDen << " " << setw(16) << PadeFluxTerm << endl;
  const double f = (32.0/5.0)*nu*nu*pow(vOmega, 10)*(1 + log(vOmega/vLSO)*((-1712.0/105.0)*pow(vOmega,6))) * PadeFluxTerm; // Eq. (40) of PRD 78, 104020
  const double Flux = f / (1.0-vOmega/vPole); // Eq. (39) of PRD 78, 104020
  return -Omega*Flux/(nu*SQR(CUB(vPhi)));
}
double EOBRightHandSide::nKFhatPhiResummed(const double& r, const double& prstar, const double& pPhi, const double& Heff, const double& Hreal, const double& Omega) const
{ // Eqs. (13) and (16) of Pan et al. 2011
  const double vOmega( pow(Omega, 1.0/3.0) );
  const vector<double> CircularHDerivs( HamiltoniansAndDerivatives(r, 0.0, pPhi) );
  const double& dHrealdpPhi = CircularHDerivs[2];
  const double psi( 1.0/(dHrealdpPhi*dHrealdpPhi*r*r*r) );
  const double vPhi( Omega*r*pow(psi, 1.0/3.0) );
  double Sum=0.0;
  vector<double> amp(1,0.0);
  vector<double> phi(1,0.0);
  for(int l=2; l<=PNLMax; ++l) {
    for(int m=1; m<=l; ++m) {
//       PNResummedAmplitudes(l, m, vector<double>(1, r), vector<double>(1, vOmega), vector<double>(1, vPhi), vector<double>(1, 0.0),
// 			   vector<double>(1, Omega), vector<double>(1, pPhi), vector<double>(1, Heff), vector<double>(1, Hreal),
// 			   delta, chia, chis, amp, phi);
//       Sum += m*m*amp[0]*amp[0];
//       PNResummedAmplitudes(l, -m, vector<double>(1, r), vector<double>(1, vOmega), vector<double>(1, vPhi), vector<double>(1, 0.0),
// 			   vector<double>(1, Omega), vector<double>(1, pPhi), vector<double>(1, Heff), vector<double>(1, Hreal),
// 			   delta, chia, chis, amp, phi);
//       Sum += m*m*amp[0]*amp[0];
      cerr << "Debugging!!!" << endl;
      cout << "Debugging!!!" << endl;
    }
  }
  return -(Omega/(16.0*M_PI*nu))*Sum;
}
vector<double> EOBRightHandSide::InitialData(const double& r0) const {
  //// See discussion around Eqs. (4.6) and (4.13) of PRD 62, 064015
  vector<double> ystart(4, 0.0);
  const double jprime = ((-6 + r0)*pow(r0,4)+(r0*r0)*(20 + 3*r0)*nu - 30*(nu*nu))/(2.*sqrt((r0*r0 - 3*nu)/((-3 + r0)*(r0*r0) + 5*nu))*pow((-3 + r0)*(r0*r0) + 5*nu,2));
  ystart[0] = r0;
  ystart[1] = 0.0;
  ystart[3] = r0*sqrt((r0*dDeltat15dr(r0) - 2*Deltat15(r0))/(-(r0*dDeltat15dr(r0)) + 4*Deltat15(r0)));
  vector<double> HDerivs( HamiltoniansAndDerivatives(r0, 0, ystart[3]) );
  ystart[2] = drstardr(r0) * nu * nKFhatPhi(HDerivs[2])/jprime;
  HDerivs = HamiltoniansAndDerivatives(r0, ystart[2], ystart[3]);
  ystart[2] = drstardr(r0) * nu * nKFhatPhi(HDerivs[2])/jprime;
  return ystart;
}
//// Make this object into a functor for use in the integration routine
void EOBRightHandSide::operator() (const double t, const vector<double>& y, vector<double>& dydt) const {
  //cout << t << endl;
  const double& r      = y[0];
  const double& prstar = y[2];
  const double& pPhi   = y[3];
  const vector<double> HDerivs( HamiltoniansAndDerivatives(r, prstar, pPhi) );
  const double& Omega = HDerivs[2];
  const double& dHrealdr = HDerivs[0];
  const double& dHrealdprstar = HDerivs[1];
  const double& dHrealdpPhi = HDerivs[2];
  const double& Heff = HDerivs[3];
  const double& Hreal = HDerivs[4];
  
  //// Eqs. (10) through (13) of Pan et al., 2011
  dydt[0] = drdrstar(r) * dHrealdprstar;
  dydt[1] = dHrealdpPhi;
  dydt[2] = -drdrstar(r) * dHrealdr;
  //dydt[3] = nKFhatPhi(Omega);
  dydt[3] = nKFhatPhiPade(r, prstar, pPhi, Heff, Hreal, Omega);
  //dydt[3] = nKFhatPhiResummed(r, prstar, pPhi, Heff, Hreal, Omega);
  
  //cout << setprecision(15) << t << "\t" << y << "\t\t" << dydt << endl;
}
double EOBRightHandSide::Omega(const double& r, const double& prstar, const double& pPhi) const {
  const vector<double> HDerivs = HamiltoniansAndDerivatives(r, prstar, pPhi);
  return HDerivs[2];
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



/// The following template is the general structure containing the EOB Hamilton equations
/// y[0] = r
/// y[1] = Phi
/// y[2] = prstar
/// y[3] = pPhi
template <class Metric, class Hamiltonian, class Torque>
class EOBHamiltonEquations {
private:
  Metric& g;
  Hamiltonian& H;
  Torque& T;
public:
  EOBHamiltonEquations(Metric& ig, Hamiltonian& iH, Torque& iT) : g(ig), H(iH), T(iT) { }
  void operator()(const double t, const vector<double>& y, vector<double>& dydt) const {
    /// Refresh the Metric, Hamiltonian, and Torque objects
    g(y[0]);
    H(y[0], y[2], y[3]);
    T(pow(H.dHdpPhi,1./3.), y[0], y[2], y[3]); /// (v, r, prstar, pPhi)
    
    /// Eqs. (10) of Pan et al., 2011:
    dydt[0] = g.drdrstar * H.dHdprstar;
    dydt[1] = H.dHdpPhi;
    dydt[2] = -g.drdrstar * H.dHdr + (T.Torque * y[2] / y[3]);
    dydt[3] = T.Torque;
  }
  bool ContinueIntegrating(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (y[0]>1.0 && y[2]<0.0); /// Ensures that r>1 and that prstar<0
  }
};

typedef Flux_Pade44LogFac Flu;
typedef Torque_KFPhi<Flu> Tor;
typedef EOBMetricNonspinning Met;
typedef EOBHamiltonianNonspinning Ham;
typedef EOBHamiltonEquations<Met, Ham, Tor> HamEqn;
typedef EOBMetricWithSpin MetS;
typedef EOBHamiltonianWithSpin HamS;
typedef EOBHamiltonEquations<MetS, HamS, Tor> HamEqnS;
typedef bool (HamEqn::*ContinueTest)(const double& t, const vector<double>& y, const vector<double>& dydt) const;


int main() {
  const double delta = 0.0;
  const double chis = 0.0;
  const double chia = 0.0;
  
  // Old one
  EOBRightHandSide d1(delta, chis, 0.0, 7);
  
  // New one
  Met g(delta);
  Ham H(delta, g);
  Flu F(delta, chis);
  Tor T(delta, chis, F);
  HamEqn d2(g, H, T);
  
  // Newest one
  MetS gS(delta, chis, chia);
  HamS HS(delta, chis, chia, gS);
  Flu FS(delta, chis);
  Tor TS(delta, chis, FS);
  HamEqnS d3(gS, HS, TS);
  
  const unsigned int N = 400;
  const double r0=30;
  const double r1=2;
  const double prstar0 = 1e-4;
  const double prstar1 = 1e-3;
  const double pPhi0 = 6;
  const double pPhi1 = 1;
  
  { /// Test the metric
    ofstream ofs("Outputs/TestEOBEqns_g.dat");
    ofs << "# [1] = r" << endl
	<< "# [2] = Dt1" << endl
	<< "# [3] = Dr1" << endl
	<< "# [4] = dDtdr1" << endl
	<< "# [5] = dDrdr1" << endl
	<< "# [6] = drstardr1" << endl
	<< "# [7] = Dt2" << endl
	<< "# [8] = Dr2" << endl
	<< "# [9] = dDtdr2" << endl
	<< "# [10] = dDrdr2" << endl
	<< "# [11] = drstardr2" << endl
	<< "# [12] = d Dt" << endl
	<< "# [13] = d Dr" << endl
	<< "# [14] = d dDtdr" << endl
	<< "# [15] = d dDrdr" << endl
	<< "# [16] = d drstardr" << endl;
    for(unsigned int n=0; n<N; ++n) {
      const double r = r0 - n*(r0-r1)/(N-1.0);
      g(r);
      ofs << r << " "
	  << d1.Deltat15(r) << " " << d1.DeltaR15(r) << " "
	  << d1.dDeltat15dr(r) << " " << d1.dDeltaR15dr(r) << " "
	  << d1.drstardr(r) << " "
	  << g.Dt << " " << g.Dr << " "
	  << g.dDtdr << " " << g.dDrdr << " "
	  << g.drstardr << " "
	  << g.Dt-d1.Deltat15(r) << " " << g.Dr-d1.DeltaR15(r) << " "
	  << g.dDtdr-d1.dDeltat15dr(r) << " " << g.dDrdr-d1.dDeltaR15dr(r) << " "
	  << g.drstardr-d1.drstardr(r) << endl;
    }
    ofs.close();
  }
  
  { /// Test the metric
    ofstream ofs("Outputs/TestEOBEqns_gS.dat");
    ofs << "# [1] = r" << endl
	<< "# [2] = Dt1" << endl
	<< "# [3] = Dr1" << endl
	<< "# [4] = dDtdr1" << endl
	<< "# [5] = dDrdr1" << endl
	<< "# [6] = drstardr1" << endl
	<< "# [7] = Dt3" << endl
	<< "# [8] = Dr3" << endl
	<< "# [9] = dDtdr3" << endl
	<< "# [10] = dDrdr3" << endl
	<< "# [11] = drstardr3" << endl
	<< "# [12] = d Dt" << endl
	<< "# [13] = d Dr" << endl
	<< "# [14] = d dDtdr" << endl
	<< "# [15] = d dDrdr" << endl
	<< "# [16] = d drstardr" << endl;
    for(unsigned int n=0; n<N; ++n) {
      const double r = r0 - n*(r0-r1)/(N-1.0);
      gS(r);
      ofs << r << " "
	  << d1.Deltat15(r) << " " << d1.DeltaR15(r) << " "
	  << d1.dDeltat15dr(r) << " " << d1.dDeltaR15dr(r) << " "
	  << d1.drstardr(r) << " "
	  << gS.Dt << " " << gS.Dr << " "
	  << gS.dDtdr << " " << gS.dDrdr << " "
	  << gS.drstardr << " "
	  << gS.Dt-d1.Deltat15(r) << " " << gS.Dr-d1.DeltaR15(r) << " "
	  << gS.dDtdr-d1.dDeltat15dr(r) << " " << gS.dDrdr-d1.dDeltaR15dr(r) << " "
	  << gS.drstardr-d1.drstardr(r) << endl;
    }
    ofs.close();
  }
  
  { /// Test the Hamiltonian
    ofstream ofs("Outputs/TestEOBEqns_H.dat");
    ofs << "# [1] = r" << endl
	<< "# [2] = prstar" << endl
	<< "# [3] = pPhi" << endl
	<< "# [4] = d1.H" << endl
	<< "# [5] = d1.Heff" << endl
	<< "# [6] = d1.dHdr" << endl
	<< "# [7] = d1.dHdprstar" << endl
	<< "# [8] = d1.dHdpPhi" << endl
	<< "# [9] = d2.H" << endl
	<< "# [10] = d2.Heff" << endl
	<< "# [11] = d2.dHdr" << endl
	<< "# [12] = d2.dHdprstar" << endl
	<< "# [13] = d2.dHdpPhi" << endl
	<< "# [14] = d H" << endl
	<< "# [15] = d Heff" << endl
	<< "# [16] = d dHdr" << endl
	<< "# [17] = d dHdprstar" << endl
	<< "# [18] = d dHdpPhi" << endl;
    for(unsigned int n=0; n<N; ++n) {
      const double r = r0 - n*(r0-r1)/(N-1.0);
      const double prstar = prstar0 - n*(prstar0-prstar1)/(N-1.0);
      const double pPhi = pPhi0 - n*(pPhi0-pPhi1)/(N-1.0);
      
      vector<double> Hderivs = d1.HamiltoniansAndDerivatives(r, prstar, pPhi);
//   Derivatives[0] = dHeffdr / (nu*Hreal);
//   Derivatives[1] = dHeffdprstar / (nu*Hreal);
//   Derivatives[2] = dHeffdpPhi / (nu*Hreal);
//   Derivatives[3] = Heff;
//   Derivatives[4] = Hreal;
      
      H(r, prstar, pPhi);
      ofs << r << " " << prstar << " " << pPhi << " "
	  << Hderivs[4] << " " << Hderivs[3] << " " << Hderivs[0] << " " << Hderivs[1] << " " << Hderivs[2] << " "
	  << H.H << " " << H.Heff << " " << H.dHdr << " " << H.dHdprstar << " " << H.dHdpPhi << " "
	  << H.H-Hderivs[4] << " " << H.Heff-Hderivs[3] << " " << H.dHdr-Hderivs[0] << " " << H.dHdprstar-Hderivs[1] << " " << H.dHdpPhi-Hderivs[2] << endl;
    }
    ofs.close();
  }
  
  { /// Test the Hamiltonian
    ofstream ofs("Outputs/TestEOBEqns_HS.dat");
    ofs << "# [1] = r" << endl
	<< "# [2] = prstar" << endl
	<< "# [3] = pPhi" << endl
	<< "# [4] = d1.H" << endl
	<< "# [5] = d1.Heff" << endl
	<< "# [6] = d1.dHdr" << endl
	<< "# [7] = d1.dHdprstar" << endl
	<< "# [8] = d1.dHdpPhi" << endl
	<< "# [9] = d3.H" << endl
	<< "# [10] = d3.Heff" << endl
	<< "# [11] = d3.dHdr" << endl
	<< "# [12] = d3.dHdprstar" << endl
	<< "# [13] = d3.dHdpPhi" << endl
	<< "# [14] = d H" << endl
	<< "# [15] = d Heff" << endl
	<< "# [16] = d dHdr" << endl
	<< "# [17] = d dHdprstar" << endl
	<< "# [18] = d dHdpPhi" << endl;
    for(unsigned int n=0; n<N; ++n) {
      const double r = r0 - n*(r0-r1)/(N-1.0);
      const double prstar = prstar0 - n*(prstar0-prstar1)/(N-1.0);
      const double pPhi = pPhi0 - n*(pPhi0-pPhi1)/(N-1.0);
      
      vector<double> Hderivs = d1.HamiltoniansAndDerivatives(r, prstar, pPhi);
//   Derivatives[0] = dHeffdr / (nu*Hreal);
//   Derivatives[1] = dHeffdprstar / (nu*Hreal);
//   Derivatives[2] = dHeffdpPhi / (nu*Hreal);
//   Derivatives[3] = Heff;
//   Derivatives[4] = Hreal;
      
      HS(r, prstar, pPhi);
      ofs << r << " " << prstar << " " << pPhi << " "
	  << Hderivs[4] << " " << Hderivs[3] << " " << Hderivs[0] << " " << Hderivs[1] << " " << Hderivs[2] << " "
	  << HS.H << " " << HS.Heff << " " << HS.dHdr << " " << HS.dHdprstar << " " << HS.dHdpPhi << " "
	  << HS.H-Hderivs[4] << " " << HS.Heff-Hderivs[3] << " " << HS.dHdr-Hderivs[0] << " " << HS.dHdprstar-Hderivs[1] << " " << HS.dHdpPhi-Hderivs[2] << endl;
    }
    ofs.close();
  }
  
  return 0;
}
