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
  double nu;
  double v0;
  bool Findv0;
  double v2, v3, v4, v5, v6, v6lntau, v7;
  double Phi2, Phi3, Phi4, Phi5lntau, Phi6, Phi6lntau, Phi7;
  
public:
  T3(const double delta, const double chis, const double chia, const double iv0)
    : nu((1.0-delta*delta)/4.0), v0(iv0), Findv0(true),
      v2(0.09213789682539683 + 0.11458333333333333*nu),
      v3(0.0020833333333333333*(-150.79644737231007 + 113.*chis + 113.*chia*delta - 76.*chis*nu)),
      v4(7.688984158478207e-9*(4.461199e6 - 1.0287648e7*pow(chia,2) - 1.0287648e7*pow(chis,2) - 2.0575296e7*chia*chis*delta + 6.825672e6*nu + 4.064256e7*pow(chia,2)*nu + 508032.*pow(chis,2)*nu + 6.145776e6*pow(nu,2))),
      v5(5.166997354497355e-7*(-18.84955592153876*(32701. - 12852.*nu) - 15120.*pow(chia,3)*delta*(-1. + nu) - 45360.*chia*pow(chis,2)*delta*(-1. + nu) - 15120.*pow(chis,3)*(-1. + 3.*nu) - 1.*chia*delta*(-1.387051e6 + 38892.*nu) - 1.*chis*(-1.387051e6 + 1.421624e6*nu + 101136.*pow(nu,2) + 45360.*pow(chia,2)*(-1. + 3.*nu)))),
      v6(3.4672547612185274e-15*(9.108262559010062e12 + 3.7019103844749206e14*nu - 7.9487302356e12*pow(nu,2) + 9.5501753424e12*pow(nu,3) + 4.7191403182892845e10*chis*(-5223. + 3596.*nu) + 1.397088e6*pow(chis,2)*(-108937. - 9.4733152e7*nu + 3.0247952e7*pow(nu,2)) - 2.794176e6*chia*delta*(8.821230259806445e7 + chis*(108937. + 6.4068676e7*nu)) + 1.397088e6*pow(chia,2)*(3.6044288e7*pow(delta,2) + 25.*(-1.446129e6 + 4.448348e6*nu + 4.886784e6*pow(nu,2))))),
      v6lntau(-0.015922619047619047),
      v7(6.407486798731838e-10*(-1.915235518786236e7*pow(chia,2)*(-57. + 224.*nu) - 37.69911184307752*(1.5419335e7 + 1.2718104e7*nu - 4.975824e6*pow(nu,2)) - 18144.*pow(chia,3)*delta*(19422. - 87455.*nu + 2856.*pow(nu,2)) - 18144.*pow(chis,3)*(19422. - 14929.*nu + 10136.*pow(nu,2)) - 1.*chia*delta*(-4.074790483e9 - 4.10784696e8*nu + 8.16654384e8*pow(nu,2)) - 18144.*pow(chis,2)*(1055.5751316061705*(-57. + 4.*nu) + chia*delta*(58266. - 39625.*nu + 8568.*pow(nu,2))) - 1.*chis*(-4.074790483e9 - 2.183368491416309e9*chia*delta + 3.478848284e9*nu + 2.255806224e9*pow(nu,2) - 4.04760384e8*pow(nu,3) + 18144.*pow(chia,2)*(13452. + 44814.*pow(delta,2) - 88271.*nu + 100072.*pow(nu,2))))),
      Phi2(0.46068948412698413 + 0.5729166666666666*nu),
      Phi3(0.015625*(-150.79644737231007 + 113.*chis + 113.*chia*delta - 76.*chis*nu)),
      Phi4(3.4600428713151927e-7*(1.855099e6 - 3.429216e6*pow(chia,2) - 3.429216e6*pow(chis,2) - 6.858432e6*chia*chis*delta + 3.1906e6*nu + 1.354752e7*pow(chia,2)*nu + 169344.*pow(chis,2)*nu + 2.617776e6*pow(nu,2))),
      Phi5lntau(-9.688120039682539e-6*(9.42477796076938*(7729. - 1092.*nu) + 1512.*pow(chia,3)*delta*(-1. + nu) + 4536.*chia*pow(chis,2)*delta*(-1. + nu) + 1512.*pow(chis,3)*(-1. + 3.*nu) - 1.*chia*delta*(147101. + 6552.*nu) + chis*(-147101. + 137368.*nu + 17136.*pow(nu,2) + 4536.*pow(chia,2)*(-1. + 3.*nu)))),
      Phi6(1.7336273806092635e-14*(-1.18415140772865e14 - 1.1265842458316762e15*nu + 4.8586704012e12*pow(nu,2) - 3.845426508e13*pow(nu,3) - 1.4157420954867856e11*chis*(-6127. + 4204.*nu) - 4.191264e6*pow(chis,2)*(8.322937e6 - 1.13716448e8*nu + 3.5608048e7*pow(nu,2)) + 5.8677696e7*chia*delta*(1.47828773288023e7 + chis*(-1.188991e6 + 1.0786532e7*nu)) - 4.191264e6*pow(chia,2)*(4.7485312e7*pow(delta,2) + 25.*(-1.566495e6 + 4.77418e6*nu + 5.478144e6*pow(nu,2))))),
      Phi6lntau(0.23883928571428573),
      Phi7(1.9222460396195517e-9*(7.182133195448384e6*pow(chia,2)*(-407. + 1600.*nu) + 9.42477796076938*(1.88516689e8 + 1.642452e8*nu - 4.7634384e7*pow(nu,2)) + 756.*pow(chia,3)*delta*(1.350103e6 - 6.00847e6*nu + 180600.*pow(nu,2)) + 756.*pow(chis,3)*(1.350103e6 - 1.021458e6*nu + 642264.*pow(nu,2)) + 2.*chia*delta*(-5.386538891e9 - 8.84569035e8*nu + 9.80367696e8*pow(nu,2)) + 2268.*pow(chis,2)*(3166.7253948185116*(-407. + 28.*nu) + chia*delta*(1.350103e6 - 883658.*nu + 180600.*pow(nu,2))) + 2.*chis*(-5.386538891e9 - 2.9231282105474925e9*chia*delta + 4.258127587e9*nu + 3.156448596e9*pow(nu,2) - 4.49340192e8*pow(nu,3) + 1134.*pow(chia,2)*(325681. + 1.024422e6*pow(delta,2) - 2.048582e6*nu + 2.1994e6*pow(nu,2)))))
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

void WU::TaylorT3(const double delta, const double chis, const double chia, const double v0,
		  vector<double>& t, vector<double>& v, vector<double>& Phi,
		  const int NPoints)
{
  const double nu((1.0-delta*delta)/4.0);
  bool BadPoints(false);
  
  //// The T3 object 'd' serves as a functor, first to find the time at which v(t)=v0,
  //// then -- after d.Findv0=false is set -- to find the time at which v(t) is a maximum.
  T3 d(delta, chis, chia, v0);
  
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
