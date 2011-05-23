#include <fstream>
#include <iomanip>
#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_EOB.hpp"

#include "Flux.hpp"
#include "EOBModel.hpp"
#include "ODEIntegrator.hpp"
#include "Fit.hpp"
#include "VectorFunctions.hpp"
#include "PNWaveform.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;

using WaveformUtilities::Output;
using WaveformUtilities::Odeint;
using WaveformUtilities::StepperBS;
using WaveformUtilities::StepperDopr853;
using WaveformUtilities::dydx;
using WaveformUtilities::max;
using WaveformUtilities::min;
using WaveformUtilities::avg;
using WaveformUtilities::cube;
using WaveformUtilities::sixth;
using WaveformUtilities::FitNonlinear;
using WaveformUtilities::PNLMax;
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
using std::vector;
using std::cerr;
using std::cout;
using std::flush;
using std::endl;


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
  bool ContinueIntegratingEarly(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (y[0]>15.0); /// Ensures that r>15
  }
  bool ContinueIntegrating(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (y[0]>1.0 && y[2]<0.0); /// Ensures that r>1 and that prstar<0
  }
};

typedef EOBMetricNonspinning Met;
typedef EOBHamiltonianNonspinning Ham;
typedef Flux_Pade44LogFac Flu;
typedef Torque_nKFPhi<Ham, Flu> Tor;
typedef EOBHamiltonEquations<Met, Ham, Tor> HamEqn;
typedef bool (HamEqn::*ContinueTest)(const double& t, const vector<double>& y, const vector<double>& dydt) const;

vector<double> ReduceEccentricity(Met& g, Ham& H, HamEqn& d, const vector<double>& ystartGuess, const double AcceptableEcc, const double& v0);

void EOBIntegration(Ham& H, HamEqn& d, vector<double>& y0, const double tLength, const double rtol, const int nsave, const bool denseish,
		    vector<double>& t, vector<double>& v, vector<double>& Phi,
		    vector<double>& r, vector<double>& prstar, vector<double>& pPhi);

void WU::EOB(const double delta, const double chis, const double v0,
	     vector<double>& t, vector<double>& v, vector<double>& Phi,
	     vector<double>& r, vector<double>& prstar, vector<double>& pPhi,
	     const int nsave, const bool denseish, const double rtol)
{
  //vector<double> r, prstar, pPhi;
  
  /// Construct the physics objects
  Met g(delta);
  Ham H(delta, g);
  Ham Hcirc(delta, g);
  Flu F(delta, chis);
  Tor T(delta, chis, Hcirc, F);
  HamEqn d(g, H, T);
  
  /// Guess some parameters
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  //const double rtol=1.0e-10;
  const double AcceptableEcc=1e-12;
  const double r0 = 1.0/(v0*v0);
  
  /// Set up initial conditions
  vector<double> ystart(4, 0.0);
  g(r0);
  F(v0);
  ystart[0] = r0;
  ystart[1] = 0.0;
  ystart[3] = r0*sqrt((r0*g.dDtdr - 2*g.Dt)/(-r0*g.dDtdr + 4*g.Dt));
  H(r0, 0.0, ystart[3]);
  T(v0, r0, 0.0, ystart[3]);
  const double dpPhi0dr = (-8*pow(g.Dt,2) + 7*g.dDtdr*g.Dt*r0 - 2*pow(g.dDtdr,2)*pow(r0,2))/(pow(4*g.Dt - g.dDtdr*r0,1.5)*sqrt(-2*g.Dt + g.dDtdr*r0));
  ystart[2] = nu * g.drstardr * T.Torque / dpPhi0dr;
  if(ystart[2]>0.0) ystart[2] *= -1;
  //ystart = ReduceEccentricity(g, H, d, ystart, AcceptableEcc, v0);
  
//   //// This block is for testing only!!!
//   const vector<double> ystartsave = ystart; // DEBUG TEST
//   ystart = ReduceEccentricity(g, H, d, ystartsave, AcceptableEcc, v0);
//   g(r0);
//   F(v0);
//   H(r0, 0.0, ystartsave[3]);
//   T(v0, r0, 0.0, ystartsave[3]);
//   ystart = ReduceEccentricity(g, H, d, ystartsave, AcceptableEcc, v0);
//   //// This block is for testing only!!!
  cout << std::setprecision(16) << ystart << endl;
  cout << std::setprecision(16) << GuessedLength << endl;
  cout << std::setprecision(16) << rtol << endl;
  cout << std::setprecision(16) << nsave << endl;
  cout << std::setprecision(16) << denseish << endl;
  cout << std::setprecision(16) << delta << endl;
  cout << std::setprecision(16) << chis << endl;
  cout << std::setprecision(16) << v0 << endl;
  
  EOBIntegration(H, d, ystart, GuessedLength, rtol, nsave, denseish, t, v, Phi, r, prstar, pPhi);
  
  return;
}



void EOBIntegration(Ham& H, HamEqn& d, vector<double>& y0, const double tLength, const double rtol, const int nsave, const bool denseish,
		    vector<double>& t, vector<double>& v, vector<double>& Phi,
		    vector<double>& r, vector<double>& prstar, vector<double>& pPhi)
{
  const double atol = 0.0;
  const double t0 = -tLength, t1 = 0.0;
  const double h1=1.0e2, hmin=1.0e-2;
  Output out(nsave);
  
//   /// First pass, integrating until tLength or the 'Early' integration test fails
//   ContinueTest test = &HamEqn::ContinueIntegratingEarly;
//   Odeint<StepperBS<HamEqn> > odeA(y0, t0, t1, atol, rtol, h1, hmin, out, d, denseish, test);
//   try {
//     odeA.integrate();
//   } catch(NRerror err) { }
  
//   /// Second pass, only if 'Early' integration test failed
//   {
//     const double t1A = out.xsave[out.count-1];
//     vector<double> y(out.ysave.nrows());
//     for(unsigned int i=0; i<y.size(); ++i) {
//       y[i] = out.ysave[i][out.count-1];
//     }
//     vector<double> dydt(out.ysave.nrows());
//     d(t1A, y, dydt);
//     if(! (d.*test)(t1A, y, dydt) ) {
//       cout << "A: out.count=" << out.count << endl;
//       test = &HamEqn::ContinueIntegrating;
//       Odeint<StepperDopr853<HamEqn> > odeB(y, t1A, t1, atol, rtol, out.xsave[out.count-1]-out.xsave[out.count-2], hmin, out, d, denseish, test);
//       try {
// 	odeB.integrate();
//       } catch(NRerror err) { }
//       cout << "B: out.count=" << out.count << endl;
//     }
//   }
  
  
  
  
  //// This block is just for testing
  ContinueTest test = &HamEqn::ContinueIntegrating;
  Odeint<StepperBS<HamEqn> > odeB(y0, t0, t1, atol, rtol, h1, hmin, out, d, denseish, test);
//   ContinueTest test = &HamEqn::ContinueIntegrating;
//   Odeint<StepperDopr853<HamEqn> > odeB(y0, t0, t1, atol, rtol, h1, hmin, out, d, denseish, test);
  try {
    odeB.integrate();
  } catch(NRerror err) { }
  //// This block is just for testing
  
  
  
  /// Save the results
  out.xsave.resize(out.count);
  t.swap(out.xsave);
  out.ysave.resize(out.ysave.nrows(), out.count);
  r.swap(out.ysave[0]);
  Phi.swap(out.ysave[1]);
  prstar.swap(out.ysave[2]);
  pPhi.swap(out.ysave[3]);
  v.resize(out.count);
  for (int i=0;i<out.count;i++) {
    H(r[i], prstar[i], pPhi[i]);
    v[i] = pow(H.dHdpPhi, 1./3.);
  }
  cout << "Debug line " << __LINE__ + 1 << " of " << __FILE__ << endl;
  //t -= t.back();
  
  return;
}






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//// Eccentricity measurement and removal
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Eccentricity_rDotFit {
public:
  Eccentricity_rDotFit() { }
  void operator()(const Doub x, VecDoub_I &a, Doub &y, VecDoub_O &dyda) const {
    //// Model: y(x) =  a0 + a1*x + a2*cos(a3*x+a4);
    y = a[0] + a[1]*x + a[2]*cos(a[3]*x+a[4]);
    dyda[0] = 1.0;
    dyda[1] = x;
    dyda[2] = cos(a[3]*x+a[4]);
    dyda[3] = -a[2]*sin(a[3]*x+a[4])*x;
    dyda[4] = -a[2]*sin(a[3]*x+a[4]);
    return;
  }
};
class Eccentricity_rDotDotFit {
public:
  Eccentricity_rDotDotFit() { }
  void operator()(const double x, const vector<double> &a, double &y, vector<double> &dyda) const {
    //// Model: y(x) =  -a0*sin(a1*x+a2);
    y = -a[0]*sin(a[1]*x+a[2]);
    dyda[0] = -sin(a[1]*x+a[2]);
    dyda[1] = -a[0]*cos(a[1]*x+a[2])*x;
    dyda[2] = -a[0]*cos(a[1]*x+a[2]);
    return;
  }
};
double Eccentricity_rDot(const vector<double>& t, const vector<double>& rDot, const double r0, const double Omega0, double& DeltarDot, double& DeltaPhiDot) {
  //// Do the fit to the model:
  ////   rDot(t) = vbar0 + arbar0*t + Br*cos(omegar*t+phir)
  
  //// First fit to rDotDot to find phase, frequency, and amplitude
  vector<double> rDotDot = dydx(rDot, t);
  vector<double> aDotDotGuesses(3);
  aDotDotGuesses[0] = 0.5*(max(rDotDot)-min(rDotDot));
  aDotDotGuesses[1] = Omega0;
  aDotDotGuesses[2] = 0.0;
  vector<double> rDotDotMinusAvg = rDotDot-avg(rDotDot);
  vector<double> TrivialSigmas(t.size(), 1.0);
  Eccentricity_rDotDotFit e_dd;
  WU::FitNonlinear<Eccentricity_rDotDotFit> rDotDotFit(t, rDotDotMinusAvg, TrivialSigmas, aDotDotGuesses, e_dd, 1.e-6);
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
  Eccentricity_rDotFit e_d;
  WU::FitNonlinear<Eccentricity_rDotFit> rDotFit(t, rDot, TrivialSigmas, aDotGuesses, e_d, 1.e-6);
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
vector<double> ReduceEccentricity(Met& g, Ham& H, HamEqn& d, const vector<double>& ystartGuess, const double AcceptableEcc, const double& v0) {
  const double Omega0( v0*v0*v0 );
  const double r0( 1.0/(v0*v0) );
  const double rtol=1.0e-10, GuessedLength=2*(2.0*M_PI/Omega0), nsave=100, denseish=false;
  vector<double> ystart(ystartGuess);
  vector<double> ystartinitial(ystart);
  vector<double> Bestystart(ystart);
  vector<double> t, Phi, v, r, prstar, pPhi;
  
  //// Reduce eccentricity
  double BestEcc=1.e100;
  //// Iterations of arXiv:1012.1549's method
  for(unsigned int i=0; i<2; ++i) {
//   for(unsigned int i=0; i<1000; ++i) {
    double DeltarDot=666, DeltaPhiDot=-666;
    EOBIntegration(H, d, ystart, GuessedLength, rtol, nsave, denseish, t, v, Phi, r, prstar, pPhi);
    g(ystartinitial[0]);
    H(ystartinitial[0], ystartinitial[2], ystartinitial[3]);
    double Ecc = Eccentricity_rDot(t, prstar, ystartinitial[0], H.dHdpPhi, DeltarDot, DeltaPhiDot);
    cout << "i:" << i << std::setprecision(14) << "\tEcc=" << Ecc << endl;
    
    if(i==0) {
      BestEcc = Ecc;
    } else {
      if(fabs(Ecc)<fabs(BestEcc)) {
	BestEcc = Ecc;
	Bestystart = ystartinitial;
      }
    }
    if(fabs(BestEcc)<AcceptableEcc) {
      cout << "Achieved acceptable eccentricity of e=" << std::setprecision(14) << BestEcc << " in " << i << " iterations." << endl;
      return Bestystart;
    }
    ystart = ystartinitial;
    double Multiplier(0.95);
    if(fabs(Ecc)<1e-10) { Multiplier = 0.05; }
    if(fabs(Ecc)<1e-12) { Multiplier = 0.01; }
    ystart[2] += Multiplier*g.drdrstar * DeltarDot;
    ystart[3] += Multiplier*r0*r0 * DeltaPhiDot;
    ystartinitial = ystart;
  }
  cerr << "!!! Did not achieve acceptable eccentricity reduction !!!" << endl
       << "Proceeding anyway, with e=" << BestEcc << "." << endl;
  
  return Bestystart;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
