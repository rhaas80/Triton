#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T4.hpp"

#include "ODEIntegrator.hpp"
#include "VectorFunctions.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;
using WaveformUtilities::Output;
using WaveformUtilities::Odeint;
using WaveformUtilities::StepperDopr853;
using std::vector;

inline double CUB(const double x) { return x*x*x; }

class T4 {
private:
  double delta;
  double nu;
  double chis;
  double dvdt2, dvdt3, dvdt4, dvdt5, dvdt6, dvdt6Ln4v, dvdt7;
  
public:
  T4(const double idelta, const double ichis)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis),
      dvdt2(-2.2113095238095237 - (11*nu)/4.),
      dvdt3((-113*chis)/12. + (19*chis*nu)/3. + 4*M_PI),
      dvdt4((34103 + 91854*pow(chis,2) + 122949*nu - 4536*pow(chis,2)*nu + 59472*pow(nu,2))/18144.),
      dvdt5((-63646*chis - 3024*pow(chis,3) + 186824*chis*nu + 9072*pow(chis,3)*nu - 53088*chis*pow(nu,2) - 12477*M_PI - 47628*nu*M_PI)/2016.),
      dvdt6((49341966789 + 26714110500*pow(chis,2) - 6833756160*EulerGamma - 108182476325*nu - 34113687300*pow(chis,2)*nu + 253066275*pow(nu,2) + 8830760400*pow(chis,2)*pow(nu,2) - 906328500*pow(nu,3) - 15717240000*chis*M_PI + 10338451200*chis*nu*M_PI + 2235340800*pow(M_PI,2) + 3938041800*nu*pow(M_PI,2))/4.191264e8),
      dvdt6Ln4v(-16.304761904761904),
      dvdt7((-10158452*chis - 6994512*pow(chis,3) + 21663778*chis*nu + 4794552*pow(chis,3)*nu - 21479310*chis*pow(nu,2) - 9072*pow(chis,3)*pow(nu,2) + 1030680*chis*pow(nu,3) - 119205*M_PI + 1306368*pow(chis,2)*M_PI + 6456150*nu*M_PI + 6587640*pow(nu,2)*M_PI)/108864.)
  {}
  
  void operator() (const double t, const vector<double>& y, vector<double>& dydt) {
    const double& v=y[0];
    const double cubv=CUB(v);
    dydt[0] = (6.4*nu)*CUB(cubv)
      * (1.0 + v*v*(dvdt2 + v*(dvdt3 + v*(dvdt4 + v*(dvdt5 + v*(dvdt6 + dvdt6Ln4v*log(4.0*v) + v*(dvdt7) ) ) ) ) ) );
    dydt[1]=cubv;
  }
  
  bool ContinueIntegrating(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (dydt[0]>0.0 && y[0]<1.0);
  }
  
};

typedef bool (T4::*ContinueTest)(const double& t, const vector<double>& y, const vector<double>& dydt) const;

void WU::TaylorT4(const double delta, const double chis, const double v0,
		  vector<double>& t, vector<double>& v, vector<double>& Phi,
		  const int nsave, const bool denseish)
{
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  const double rtol=1.0e-11, atol=0.0, h1=1.0e2, hmin=1.0e-3, t0=-GuessedLength, t1=0.0;
  vector<double> ystart(2);
  ystart[0]=v0;
  ystart[1]=0.0;
  Output out(nsave);
  T4 d(delta, chis);
  ContinueTest test = &T4::ContinueIntegrating;
  Odeint<StepperDopr853<T4> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d,denseish,test);
  try {
    ode.integrate();
  } catch(NRerror err) { }
  
  out.xsave.resize(out.count);
  t.swap(out.xsave);
  out.ysave.resize(out.ysave.nrows(), out.count);
  v.swap(out.ysave[0]);
  Phi.swap(out.ysave[1]);
  t -= t.back();
  
  return;
}
