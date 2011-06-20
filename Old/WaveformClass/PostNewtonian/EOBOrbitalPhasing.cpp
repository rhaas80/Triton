#include <fstream>
#include <iomanip>
using namespace std;

#include "EOBOrbitalPhasing.hpp"
#include "PNWaveform.hpp"
#include "Fit.hpp"
#include "ODEIntegrator.hpp"
typedef int NRerror;



//////////////////////////////////////////////////////////////////////////
//// Objects of this class will act as the functor
//// for use in the integration scheme.
//////////////////////////////////////////////////////////////////////////
class EOBRightHandSide {
  friend void EOB(const double delta, const double chis, const double chia, const double v0,
	 vector<double>& t, vector<double>& v, vector<double>& Phi, const double PNPhaseOrder,
	 vector<double>& r, vector<double>& prstar, vector<double>& pPhi,
		  const int nsave, const bool denseish);

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
  
private:
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

//// Some helper functions
void CutOutNonsenseSteps(const Output& out, const EOBRightHandSide& d, vector<double>& t, vector<double>& Phi,
			 vector<double>& v, vector<double>& r, vector<double>& prstar, vector<double>& pPhi);
double Eccentricity_rDot(const vector<double>& t, const vector<double>& rDot, const double& r0, const double& Omega0,
			 double& DeltarDot, double& DeltaPhiDot);
vector<double> ReduceEccentricity(EOBRightHandSide& d, const vector<double>& ystartGuess, const double& AcceptableEcc, const double& v0);
bool ContinueIntegratingEOB(const double& x, const std::vector<double>& y, const std::vector<double>& dydx) {
  if(y[0] < 1.0) { // if r<1
    cerr << "\nIn EOBOrbitalPhasing.cpp, r<1." << endl;
    return false;
  }
  if(y[2] > 0.0) { // if prstar>0
    cerr << "\nIn EOBOrbitalPhasing.cpp, prstar>0." << endl;
    return false;
  }
  return true;
}


//////////////////////////////////////////////////////////////////////////
//// This is the main function called from outside this file
//////////////////////////////////////////////////////////////////////////
void EOB(const double delta, const double chis, const double chia, const double v0,
	 vector<double>& t, vector<double>& v, vector<double>& Phi, const double PNPhaseOrder,
	 vector<double>& r, vector<double>& prstar, vector<double>& pPhi,
	 const int nsave, const bool denseish)
{
  const double r0( 1.0/(v0*v0) );
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  //const double GuessedLength = 0.10*pow(((1.0-delta*delta)/4.0)/(r0*r0*r0), -8.0/6.0);
  const double rtol=1.0e-8, atol=0.0, h1=1.0, hmin=1.0e-3, t0=0.0;
  EOBRightHandSide d(delta, chis, chia, PNPhaseOrder);
  vector<double> ystart( d.InitialData(r0) );
  cout << "GuessedLength = " << GuessedLength << " M" << endl;
  
  ofstream ofs("Output/Flux.dat", ofstream::out);
  const unsigned int vSteps=5000;
  for(unsigned int i=0; i<vSteps; ++i) {
    double v = i/(vSteps-1.0);
    ofs << setprecision(14) << v << " " << d.PadeFlux(v) << endl;
  }
  ofs.close();
  
  //// If spin is too large, build up to the goal gradually, reducing eccentricity at each step
  vector<double> chisMax(9);
  chisMax[0] = 0.1; chisMax[1] = 0.2; chisMax[2] = 0.3; chisMax[3] = 0.4; chisMax[4] = 0.5; chisMax[5] = 0.6; chisMax[6] = 0.7; chisMax[7] = 0.8; chisMax[8] = 0.9;
  for(unsigned int i=0; i<chisMax.size(); ++i) {
    const double chismax( chisMax[i] );
    if(fabs(chis)>chismax) {
      cout << "Reducing eccentricity with chis=" << (chis>0 ? chismax : -chismax) << " ... " << flush;
      EOBRightHandSide d1(delta, chis>0 ? chismax : -chismax, chia, PNPhaseOrder);
      ystart = ReduceEccentricity(d1, ystart, 1.e-8, v0);
    }
  }
  
  //// Now reduce eccentricity with the real parameters
  cout << "Reducing eccentricity ... " << flush;
  ystart = ReduceEccentricity(d, ystart, 1.e-14, v0);
  
  //// Finally, do the full integration
  Output out(nsave);
  cout << "Integrating the full inspiral ... " << flush;
  //Odeint< ::StepperBS<EOBRightHandSide> > ode(ystart, t0, GuessedLength, atol, rtol, h1, hmin, out, d, denseish, ContinueIntegratingEOB);
  Odeint< ::StepperDopr853<EOBRightHandSide> > ode(ystart, t0, GuessedLength, atol, rtol, h1, hmin, out, d, denseish, ContinueIntegratingEOB);
  try {
    ode.integrate();
  } catch(NRerror err) { }
  
  //// Save the full data to the output vectors
  CutOutNonsenseSteps(out, d, t, Phi, v, r, prstar, pPhi);
  
  cout << "vLSO=" << d.vLSO << "  vPole=" << d.vPole << endl;
  
  return;
}






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////  EOBRightHandSide class definitions
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
EOBRightHandSide::EOBRightHandSide(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder)
  : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), chia(ichia), PNOrder(PNPhaseOrder),
    a4(((94.0/3.0)-(41.0/32.0)*M_PI*M_PI)*nu),
    a5(nu*(-82.5384+508.681*nu-787.826*nu*nu)), // Eq. (27) of Pan et al. 2011
    a6(nu*(500.0-1800.0*nu)), // Eq. (28) of Pan et al. 2011
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
  const double dH1dr = (dDeltatdr*Den+Deltat*dDendr-chieff*chieff*dDendr+chieff*chieff*2*(2*r-dDeltatdr)*(r*r+chieff*chieff-Deltat)) / SQR(Den) - 2*dDendr*H1/Den;
  const double H2 = SQR(r*r+chieff*chieff)/Den;
  const double dH2dr = 4*r*(r*r+chieff*chieff)/Den - dDendr*H2/Den;
  const double H3 = (8-6*nu)*nu*SQR(SQR(r*r+chieff*chieff))/(Den*SQR(DeltaR)*Deltat);
  const double dH3dr = (8-6*nu)*nu*8*r*CUB(r*r+chieff*chieff)/(Den*SQR(DeltaR)*Deltat)
    - (dDendr*SQR(DeltaR)*Deltat+Den*2*DeltaR*dDeltaRdr*Deltat+Den*SQR(DeltaR)*dDeltatdr)*H3/(Den*SQR(DeltaR)*Deltat);
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
    + a3PNSS*nu*chieff*chistar/(r*r*r*r);
  const double dHeffdr =
    0.5*(dH0dr + SQR(pPhi)*dH1dr + SQR(prstar)*dH2dr + SQR(SQR(prstar))*dH3dr)/Heffsqrt
    + pPhi*dsigmadr*H4 + pPhi*(chieff+sigma)*dH4dr
    - 4*a3PNSS*nu*chieff*chistar/(r*r*r*r*r);
  const double dHeffdprstar =
    0.5*(2*prstar*H2 + 4*CUB(prstar)*H3)/Heffsqrt
    + pPhi*(dsigmadprstar)*H4;
  const double dHeffdpPhi =
    pPhi*H1/Heffsqrt
    + (chieff+sigma)*H4 + pPhi*(dsigmadpPhi)*H4;
  
  const double Hreal = sqrt(1+2*nu*(Heff-1))/nu;
  
  Derivatives[0] = dHeffdr / (nu*Hreal);
  Derivatives[1] = dHeffdprstar / (nu*Hreal);
  Derivatives[2] = dHeffdpPhi / (nu*Hreal);
  Derivatives[3] = Heff;
  Derivatives[4] = Hreal-1/nu;
  return Derivatives;
}
//// Flux
double EOBRightHandSide::SummSquaredMagnitudeSquaredhlm(const double& vOmega) const {
  double Sum=0.0;
  vector<double> amp(1,0.0);
  vector<double> phi(1,0.0);
  for(int l=2; l<=PNLMax; ++l) {
    for(int m=1; m<=l; ++m) {
      PNAmplitudes(l, m, vector<double>(1, vOmega), vector<double>(1, 0.0),
		   delta, chia, chis, amp, phi);
      Sum += m*m*amp[0]*amp[0];
      PNAmplitudes(l, -m, vector<double>(1, vOmega), vector<double>(1, 0.0),
		   delta, chia, chis, amp, phi);
      Sum += m*m*amp[0]*amp[0];
    }
  }
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
      PNResummedAmplitudes(l, m, vector<double>(1, r), vector<double>(1, vOmega), vector<double>(1, vPhi), vector<double>(1, 0.0),
			   vector<double>(1, Omega), vector<double>(1, pPhi), vector<double>(1, Heff), vector<double>(1, Hreal),
			   delta, chia, chis, amp, phi);
      Sum += m*m*amp[0]*amp[0];
      PNResummedAmplitudes(l, -m, vector<double>(1, r), vector<double>(1, vOmega), vector<double>(1, vPhi), vector<double>(1, 0.0),
			   vector<double>(1, Omega), vector<double>(1, pPhi), vector<double>(1, Heff), vector<double>(1, Hreal),
			   delta, chia, chis, amp, phi);
      Sum += m*m*amp[0]*amp[0];
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







//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//// Clean up time stepper output
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void CutOutNonsenseSteps(const Output& out, const EOBRightHandSide& d, vector<double>& t, vector<double>& Phi,
			 vector<double>& v, vector<double>& r, vector<double>& prstar, vector<double>& pPhi)
{
  int iFinal=out.count;
  double tFinal=out.xsave[out.count-1];
  for(int i=1; i<out.count; ++i) {
    if(out.ysave[0][i]<1.0) {
      iFinal=i-1;
      tFinal=out.xsave[i-1];
      break;
    }
  }
  t.resize(iFinal);
  Phi.resize(iFinal);
  v.resize(iFinal);
  r.resize(iFinal);
  prstar.resize(iFinal);
  pPhi.resize(iFinal);
  for (int i=0;i<iFinal;i++) {
    t[i] = out.xsave[i]-tFinal;
    Phi[i] = out.ysave[1][i];
    v[i] = d.v(out.ysave[0][i], out.ysave[2][i], out.ysave[3][i]);
    r[i] = out.ysave[0][i];
    prstar[i] = out.ysave[2][i];
    pPhi[i] = out.ysave[3][i];
  }
  return;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////








//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//// Eccentricity measurement and removal
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void Eccentricity_rDotFit(const double x, const vector<double> &a, double &y, vector<double> &dyda) {
  //// Model: y(x) =  a0 + a1*x + a2*cos(a3*x+a4);
  y = a[0] + a[1]*x + a[2]*cos(a[3]*x+a[4]);
  dyda[0] = 1.0;
  dyda[1] = x;
  dyda[2] = cos(a[3]*x+a[4]);
  dyda[3] = -a[2]*sin(a[3]*x+a[4])*x;
  dyda[4] = -a[2]*sin(a[3]*x+a[4]);
  return;
}
void Eccentricity_rDotDotFit(const double x, const vector<double> &a, double &y, vector<double> &dyda) {
  //// Model: y(x) =  -a0*sin(a1*x+a2);
  y = -a[0]*sin(a[1]*x+a[2]);
  dyda[0] = -sin(a[1]*x+a[2]);
  dyda[1] = -a[0]*cos(a[1]*x+a[2])*x;
  dyda[2] = -a[0]*cos(a[1]*x+a[2]);
  return;
}
double Eccentricity_rDot(const vector<double>& t, const vector<double>& rDot, const double& r0, const double& Omega0, double& DeltarDot, double& DeltaPhiDot) {
  //// Do the fit to the model:
  ////   rDot(t) = vbar0 + arbar0*t + Br*cos(omegar*t+phir)
  
  //// First fit to rDotDot to find phase, frequency, and amplitude
  vector<double> rDotDot( dydx(rDot, t) );
  vector<double> aDotDotGuesses(3);
  aDotDotGuesses[0] = 0.5*(max(rDotDot)-min(rDotDot));
  aDotDotGuesses[1] = Omega0;
  aDotDotGuesses[2] = 0.0;
  vector<double> rDotDotMinusAvg( rDotDot-avg(rDotDot) );
  vector<double> TrivialSigmas(t.size(), 1.0);
  FitNonlinear rDotDotFit(t, rDotDotMinusAvg, TrivialSigmas, aDotDotGuesses, Eccentricity_rDotDotFit, 1.e-6);
  rDotDotFit.hold(0, aDotDotGuesses[0]);
  rDotDotFit.hold(1, aDotDotGuesses[1]);
  rDotDotFit.fit();
  rDotDotFit.free(1);
  rDotDotFit.fit();
  rDotDotFit.free(0);
  rDotDotFit.fit();
  
  //// Next fit to rDot to find all parameters
  vector<double> aDotGuesses(5);
  aDotGuesses[0] = avg(rDot);
  aDotGuesses[1] = avg(rDotDot);
  aDotGuesses[2] = rDotDotFit.a[0] / rDotDotFit.a[1];
  aDotGuesses[3] = rDotDotFit.a[1];
  aDotGuesses[4] = rDotDotFit.a[2];
  FitNonlinear rDotFit(t, rDot, TrivialSigmas, aDotGuesses, Eccentricity_rDotFit, 1.e-6);
  rDotFit.fit();
  
  //// Adjust the parameters
  //double& vbar0 = rDotFit.a[0];
  //double& arbar0 = rDotFit.a[1];
  double& Br = rDotFit.a[2];
  double& omegar = rDotFit.a[3];
  double& phir = rDotFit.a[4];
  DeltarDot = -Br * cos(phir); // Eq. (71) of arXiv:1012.1549
  DeltaPhiDot = Br * omegar * sin(phir) / (2* r0 * Omega0);  // Eq. (73) of arXiv:1012.1549
  
  //// Return the measured eccentricity
  return -Br / (r0 * omegar);
}
vector<double> ReduceEccentricity(EOBRightHandSide& d, const vector<double>& ystartGuess, const double& AcceptableEcc, const double& v0) {
  const double Omega0( v0*v0*v0 );
  const double r0( 1.0/(v0*v0) );
  const double rtol=1.0e-6, atol=0.0, h1=1.0, hmin=1.0e-3, t0=0.0, t1=2*(2.0*M_PI/Omega0);
  vector<double> ystart(ystartGuess);
  vector<double> ystartinitial(ystart);
  vector<double> Bestystart(ystart);
  vector<double> t, Phi, v, r, prstar, pPhi;
  
  //// Reduce eccentricity
  double BestEcc(1.e100);
  //// Iterations of arXiv:1012.1549's method
  for(unsigned int i=0; i<1000; ++i) {
    double DeltarDot(666), DeltaPhiDot(-666);
    Output out(20);
    Odeint< ::StepperDopr853<EOBRightHandSide> > ode(ystart, t0, t1, atol, rtol, h1, hmin, out, d, true);
    try {
      ode.integrate();
    } catch(NRerror err) { }
    CutOutNonsenseSteps(out, d, t, Phi, v, r, prstar, pPhi);
    double Ecc( Eccentricity_rDot(t, prstar, ystartinitial[0], d.Omega(ystartinitial[0], ystartinitial[2], ystartinitial[3]), DeltarDot, DeltaPhiDot) );
//     cout << setprecision(16)
// 	 << "e = " << setw(22) << Ecc
// 	 << "   ystartinitial[2] = " << setw(22) << ystartinitial[2]
// 	 << "   ystartinitial[3] = " << setw(22) << ystartinitial[3]
// 	 << endl;
    if(i==0) {
      BestEcc = Ecc;
    } else {
      if(fabs(Ecc)<fabs(BestEcc)) {
	BestEcc = Ecc;
	Bestystart = ystartinitial;
      }
    }
    if(fabs(BestEcc)<AcceptableEcc) {
      cout << "Achieved acceptable eccentricity of e=" << BestEcc << "." << endl;
      return Bestystart;
    }
    ystart = ystartinitial;
    double Multiplier(0.95);
    if(fabs(Ecc)<1e-10) { Multiplier = 0.05; }
    if(fabs(Ecc)<1e-12) { Multiplier = 0.01; }
    ystart[2] += Multiplier*d.drdrstar(r0) * DeltarDot;
    ystart[3] += Multiplier*r0*r0 * DeltaPhiDot;
    ystartinitial = ystart;
  }
  cout << "!!! Did not achieve acceptable eccentricity reduction !!!" << endl
       << "Proceeding anyway, with e=" << BestEcc << "." << endl;
  
  return Bestystart;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
