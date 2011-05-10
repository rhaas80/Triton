#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T1.hpp"

#include "ODEIntegrator.hpp"
#include "VectorFunctions.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;
using WaveformUtilities::Output;
using WaveformUtilities::Odeint;
using WaveformUtilities::StepperDopr853;
using std::vector;

using std::cerr;
using std::endl;

inline double CUB(const double x) { return x*x*x; }

class T1 {
private:
  double delta;
  double nu;
  double chis;
  double dvdtNum2, dvdtNum3, dvdtNum4, dvdtNum5, dvdtNum6, dvdtNum6Ln4v, dvdtNum7;
  double dvdtDen2, dvdtDen3, dvdtDen4, dvdtDen5, dvdtDen6;
  
public:
  T1(const double idelta, const double ichis)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis),
      dvdtNum2(-3.7113095238095237 - (35*nu)/12.),
      dvdtNum3((-11*chis)/4. + 3*chis*nu + 4*M_PI),
      dvdtNum4((-44711 + 18711*pow(chis,2) + 166878*nu - 2268*pow(chis,2)*nu + 32760*pow(nu,2))/9072.),
      dvdtNum5((-8442*chis - 3024*pow(chis,3) + 53872*chis*nu + 9072*pow(chis,3)*nu - 35168*chis*pow(nu,2) - 24573*M_PI - 48972*nu*M_PI)/2016.),
      dvdtNum6((19931218557 - 3416878080*EulerGamma - 3625933850*nu - 6542127900*pow(nu,2) - 501270000*pow(nu,3) + 1117670400*pow(M_PI,2) + 179001900*nu*pow(M_PI,2))/2.095632e8),
      dvdtNum6Ln4v(-16.304761904761904),
      dvdtNum7((5*(-78168*M_PI + 300643*nu*M_PI + 154708*pow(nu,2)*M_PI))/12096.),
      dvdtDen2(-1.5 - nu/6.),
      dvdtDen3((-10*(-2*chis + chis*nu))/3.),
      dvdtDen4((-81 - 24*pow(chis,2) + 57*nu - pow(nu,2))/8.),
      dvdtDen5(28*chis - (847*chis*nu)/18. + (7*chis*pow(nu,2))/9.),
      dvdtDen6((-5*(10935 - 62001*nu + 1674*pow(nu,2) + 7*pow(nu,3) + 2214*nu*pow(M_PI,2)))/1296.)
  {}
  
  void operator() (const double t, const vector<double>& y, vector<double>& dydt) {
    const double& v=y[0];
    const double cubv=CUB(v);
    dydt[0] = (6.4*nu)*CUB(cubv)
      * (1.0 + v*v*(dvdtNum2 + v*(dvdtNum3 + v*(dvdtNum4 + v*(dvdtNum5 + v*(dvdtNum6 + dvdtNum6Ln4v*log(4.0*v) + v*(dvdtNum7) ) ) ) ) ) )
      / (1.0 + v*v*(dvdtDen2 + v*(dvdtDen3 + v*(dvdtDen4 + v*(dvdtDen5 + v*(dvdtDen6) ) ) ) ) );
    dydt[1]=cubv;
  }
  
  bool ContinueIntegrating(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (dydt[0]>0.0 && y[0]<1.0);
  }
  
};

typedef bool (T1::*ContinueTest)(const double& t, const vector<double>& y, const vector<double>& dydt) const;

void WU::TaylorT1(const double delta, const double chis, const double v0,
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
  T1 d(delta, chis);
  ContinueTest test = &T1::ContinueIntegrating;
  Odeint<StepperDopr853<T1> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d,denseish,test);
  try {
    ode.integrate();
  } catch(NRerror err) { }
  
  t.resize(out.count);
  v.resize(out.count);
  Phi.resize(out.count);
  for (int i=0;i<out.count;i++) {
    t[i] = out.xsave[i]-out.xsave[out.count-1];
    v[i] = out.ysave[0][i];
    Phi[i] = out.ysave[1][i];
  }
  
  return;
}
