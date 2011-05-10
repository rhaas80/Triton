#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T3.hpp"

#include "Minimize.hpp"
#include "VectorFunctions.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;
using WaveformUtilities::Brent;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

class T3 {
private:
  double delta;
  double nu;
  double chis;
  double v0;
  bool Findv0;
  double v2, v3, v4, v5, v6, v6lntau, v7;
  double Phi2, Phi3, Phi4, Phi5lntau, Phi6, Phi6lntau, Phi7;
  
public:
  T3(const double idelta, const double ichis, const double iv0)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), v0(iv0), Findv0(true),
      v2(0.09213789682539683 + (11*nu)/96.),
      v3((113*chis - 76*chis*nu - 48*M_PI)/480.),
      v4((4461199 - 10287648*pow(chis,2) + 6825672*nu + 508032*pow(chis,2)*nu + 6145776*pow(nu,2))/1.30056192e8),
      v5((1392091*chis + 30240*pow(chis,3) - 1436744*chis*nu - 90720*pow(chis,3)*nu - 101136*chis*pow(nu,2) - 196206*M_PI + 77112*nu*M_PI)/1.93536e6),
      v6((-260539947604339 - 152194575456*pow(chis,2) + 36738273116160*EulerGamma + 579139571772300*nu - 132350549861376*pow(chis,2)*nu - 7948730235600*pow(nu,2) + 42259050763776*pow(chis,2)*pow(nu,2) + 9550175342400*pow(nu,3) - 102867164725248*chis*M_PI + 79553811972096*chis*nu*M_PI + 22592321224704*pow(M_PI,2) - 21170912716800*nu*pow(M_PI,2) + 36738273116160*log(2))/2.884126113792e14),
      v6lntau(-0.015922619047619047),
      v7((4092843763*chis - 298232928*pow(chis,3) - 3515735036*chis*nu + 160211520*pow(chis,3)*nu - 2307625488*chis*pow(nu,2) - 339365376*pow(chis,3)*pow(nu,2) + 404760384*chis*pow(nu,3) - 185032020*M_PI + 347493888*pow(chis,2)*M_PI - 152617248*nu*M_PI - 24385536*pow(chis,2)*nu*M_PI + 59709888*pow(nu,2)*M_PI)/1.560674304e9),
      Phi2(0.46068948412698413 + (55*nu)/96.),
      Phi3((113*chis - 76*chis*nu - 48*M_PI)/64.),
      Phi4((5*(1855099 - 3429216*pow(chis,2) + 3190600*nu + 169344*pow(chis,2)*nu + 2617776*pow(nu,2)))/1.4450688e7),
      Phi5lntau((5*(147605*chis + 3024*pow(chis,3) - 138880*chis*nu - 9072*pow(chis,3)*nu - 17136*chis*pow(nu,2) - 23187*M_PI + 3276*nu*M_PI))/516096.),
      Phi6((775925041075117 - 110214819348480*EulerGamma - 1753429845806100*nu + 4858670401200*pow(nu,2) - 38454265080000*pow(nu,3) - 4191264*pow(chis,2)*(8322937 - 113716448*nu + 35608048*pow(nu,2)) - 1081547292672*chis*(-323 + 246*nu)*M_PI - 76429342015488*pow(M_PI,2) + 63512738150400*nu*pow(M_PI,2) - 110214819348480*log(2))/5.768252227584e13),
      Phi6lntau(0.23883928571428573),
      Phi7((756*pow(chis,3)*(1163573 - 642468*nu + 1184064*pow(nu,2)) + chis*(-10820083342 + 8611760654*nu + 6449430792*pow(nu,2) - 898680384*pow(nu,3)) + 2286144*pow(chis,2)*(-407 + 28*nu)*M_PI + 3*(188516689 + 164245200*nu - 47634384*pow(nu,2))*M_PI)/5.20224768e8)
  { }
  
  void operator() (double& v, const double t, double& Phi) const {
    const double taum8 = pow((-nu/5.0)*t,-1./8.);
    const double lntau = log((-nu/5.0)*t);
    v = 0.5*taum8*(1.0 + taum8*taum8*(v2 + taum8*(v3 + taum8*(v4 + taum8*(v5 + taum8*(v6 + v6lntau*lntau + taum8*(v7) ) ) ) ) ) );
    Phi = (-1.0/(nu*pow(taum8,5)))*(1.0 + taum8*taum8*(Phi2 + taum8*(Phi3 + taum8*(Phi4 + taum8*(Phi5lntau*lntau + taum8*(Phi6 + Phi6lntau*lntau + taum8*(Phi7) ) ) ) ) ) );
  }
  
  double operator()(const double t) const {
    double v, Phi;
    (*this)(v, t, Phi);
    if(Findv0) {
      return (v-v0)*(v-v0);
    } else {
      return -v;
    }
  }
  
  void FindMaxv() {
    Findv0 = false;
  }
  
};

void WU::TaylorT3(const double delta, const double chis, const double v0,
		  vector<double>& t, vector<double>& v, vector<double>& Phi,
		  const int NPoints)
{
  const double nu((1.0-delta*delta)/4.0);
  bool BadPoints(false);
  
  //// The T3 object 'd' serves as a functor, first to find the time at which v(t)=v0,
  //// then -- after d.Findv0=false is set -- to find the time at which v(t) is a maximum.
  T3 d(delta, chis, v0);
  
  // Set up the t vector by finding the t which gives v[0]=v0,
  // then distributing points roughly evenly spaced in v by
  // approximating as t=-5/(256*nu*v^8).
  Brent Minimizer;
  Minimizer.ax = -50./(256*nu*pow(v0,8));
  Minimizer.bx = -5./(256*nu*pow(v0,8));
  Minimizer.cx = -0.5/(256*nu*pow(v0,8));
  const double t0 = Minimizer.minimize(d);
  const double v0Bad = pow(-256*nu*t0/5., -1./8.);
  
  //// Now switch d, and find the max of v(t)
  d.FindMaxv();
  Minimizer.ax = t0;
  Minimizer.bx = -10.;
  Minimizer.cx = 0.0;
  double v1Bad(0.5);
  try {
    const double t1 = Minimizer.minimize(d);
    v1Bad = pow(-256*nu*t1/5., -1./8.);
  } catch(NRerror err) {
    cerr << "\nCouldn't find max of v(t) in TaylorT3.  Assuming it continues to v=" << v1Bad << endl;
    BadPoints = true;
  }
  t.resize(NPoints);
  v.resize(NPoints);
  Phi.resize(NPoints);
  t[0] = (-5.0/(256.0*nu))*pow(v0Bad,-8);
  d(v[0], t[0], Phi[0]);
  for(int i=1; i<NPoints; ++i) {
    t[i] = (-5.0/(256.0*nu))*pow(v0Bad + (v1Bad-v0Bad)*i/double(NPoints-1),-8);
    d(v[i], t[i], Phi[i]);
    Phi[i] = Phi[i]-Phi[0];
  }
  Phi[0] = 0.0;
  
  //// If we couldn't find the max of v(t), remove v>1 from the data
  if(BadPoints) {
    unsigned int i=0;
    while(v[i]<1.0) { ++i; }
    v.erase(v.begin()+i, v.end());
    t.erase(t.begin()+i, t.end());
    Phi.erase(Phi.begin()+i, Phi.end());
  }
  
  return;
}
