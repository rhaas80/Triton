#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T2_Tidal.hpp"

#include "Roots.hpp"
#include "VectorFunctions.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;
using WaveformUtilities::zbrak;
using WaveformUtilities::zriddr;
using WaveformUtilities::fifth;
using WaveformUtilities::eighth;
using std::vector;

class T2Tidal {
private:
  double nu, m1, m2;
  double Phi0;
  double t2, t3, t4, t5, t6, t6Lnv, t7;
  double Phi2, Phi3, Phi4, Phi5, Phi5Lnv, Phi6, Phi6Lnv, Phi7;
  double t10a, t10b, t12a, t12b, Phi10a, Phi10b, Phi12a, Phi12b; //tidal terms

public:
  T2Tidal(const double delta, const double chis, const double chia, const double v0, const double love1, const double love2, const double compact1, const double compact2)
    : m1((delta+1.)/2.),
      m2(1.-m1),
      nu((1.0-delta*delta)/4.0), Phi0(0.0),
      t2(2.9484126984126986 + 3.6666666666666665*nu),
      t3(-0.13333333333333333*(150.79644737231007 - 113.*chia*delta) + chis*(15.066666666666666 - 10.133333333333333*nu)),
      t4(1.968379944570421e-6*(3.058673e6 - 5.143824e6*pow(chia,2)) - 20.25*chia*chis*delta + pow(chis,2)*(-10.125 + 0.5*nu) + 1.968379944570421e-6*(5.472432e6 + 2.032128e7*pow(chia,2))*nu + 8.569444444444445*pow(nu,2)),
      t5(0.0013227513227513227*(-72844.10885878654 + 147101.*chia*delta + 1512.*pow(chia,3)*delta) + pow(chis,3)*(2. - 6.*nu) + 0.0013227513227513227*(10291.857533160162 + 6552.*chia*delta - 1512.*pow(chia,3)*delta)*nu + pow(chis,2)*(6.*chia*delta - 6.*chia*delta*nu) + chis*(0.0013227513227513227*(147101. + 4536.*pow(chia,2)) + 0.0013227513227513227*(-137368. - 13608.*pow(chia,2))*nu - 22.666666666666668*pow(nu,2))),
      t6(4.260562650585326e-11*(2.8369398302025723e12 - 2.1921358536e12*pow(chia,2) - 1.1158800544288205e13*chia*delta + 2.4312125376e12*pow(chia,2)*pow(delta,2)) + 4.260562650585326e-11*(1.5529970189366336e13 + 6.7107724992e12*pow(chia,2))*nu + 4.260562650585326e-11*(-2.066079708e11 + 7.5420398592e12*pow(chia,2))*pow(nu,2) + 19.72608024691358*pow(nu,3) + chis*(4.260562650585326e-11*(-1.1158800544288205e13 + 4.78153368e11*chia*delta) + 4.260562650585326e-11*(7.668603017220088e12 - 8.1249049728e12*chia*delta)*nu) + pow(chis,2)*(10.186011904761903 - 258.4940476190476*nu + 81.66666666666666*pow(nu,2))),
      t6Lnv(65.21904761904761),
      t7(6.561266481901402e-7*(-5.812952347108797e8 + 1.0916842457081544e9*pow(chia,2) + 4.074790483e9*chia*delta - 3.52392768e8*pow(chia,3)*delta) + 6.561266481901402e-7*(-4.7946122512789154e8 - 4.290127562081168e9*pow(chia,2) + 4.10784696e8*chia*delta + 1.58678352e9*pow(chia,3)*delta)*nu + 6.561266481901402e-7*(1.8758414548746935e8 - 8.16654384e8*chia*delta - 5.1819264e7*pow(chia,3)*delta)*pow(nu,2) + pow(chis,3)*(-231.21428571428572 + 177.72619047619048*nu - 120.66666666666667*pow(nu,2)) + pow(chis,2)*(6.561266481901402e-7*(1.0916842457081544e9 - 1.057178304e9*chia*delta) + 6.561266481901402e-7*(-7.660942075144944e7 + 7.18956e8*chia*delta)*nu - 102.*chia*delta*pow(nu,2)) + chis*(6.561266481901402e-7*(4.074790483e9 - 2.44073088e8*pow(chia,2) + 2.183368491416309e9*chia*delta - 8.13105216e8*pow(chia,2)*pow(delta,2)) + 6.561266481901402e-7*(-3.478848284e9 + 1.601589024e9*pow(chia,2))*nu + 6.561266481901402e-7*(-2.255806224e9 - 1.815706368e9*pow(chia,2))*pow(nu,2) + 265.5740740
 740741*pow(nu,3))),

      t10a( love1*pow((m1/compact1),5)*16.*(12.-11.*m1)/m1 ),
      t10b( love2*pow((m2/compact2),5)*16.*(12.-11.*m2)/m2 ),
      t12a( love1*pow((m1/compact1),5)*(3179.-919.*m1-2286.*m1*m1+260.*m1*m1*m1)/(m1*6.) ),
      t12b( love2*pow((m2/compact2),5)*(3179.-919.*m2-2286.*m2*m2+260.*m2*m2*m2)/(m2*6.) ),

      Phi2(3.685515873015873 + 4.583333333333333*nu),
      Phi3(-0.20833333333333334*(150.79644737231007 - 113.*chia*delta) + chis*(23.541666666666668 - 15.833333333333334*nu)),
      Phi4(4.920949861426052e-6*(3.058673e6 - 5.143824e6*pow(chia,2)) - 50.625*chia*chis*delta + 4.920949861426052e-6*(5.472432e6 + 2.032128e7*pow(chia,2))*nu + 21.42361111111111*pow(nu,2) + pow(chis,2)*(-25.3125 + 1.25*nu)),
      Phi5(0.0),
      Phi5Lnv(0.00248015873015873*(72844.10885878654 - 147101.*chia*delta - 1512.*pow(chia,3)*delta) + 0.00248015873015873*(-10291.857533160162 - 6552.*chia*delta + 1512.*pow(chia,3)*delta)*nu + pow(chis,3)*(-3.75 + 11.25*nu) + pow(chis,2)*(-11.25*chia*delta + 11.25*chia*delta*nu) + chis*(0.00248015873015873*(-147101. - 4536.*pow(chia,2)) + 0.00248015873015873*(137368. + 13608.*pow(chia,2))*nu + 42.5*pow(nu,2))),
      Phi6(5.325703313231658e-11*(-5.4079776044257227e11 + 2.1921358536e12*pow(chia,2) + 1.1158800544288205e13*chia*delta - 2.4312125376e12*pow(chia,2)*pow(delta,2)) + 5.325703313231658e-11*(-1.5529970189366336e13 - 6.7107724992e12*pow(chia,2))*nu + 5.325703313231658e-11*(2.066079708e11 - 7.5420398592e12*pow(chia,2))*pow(nu,2) - 24.657600308641975*pow(nu,3) + chis*(5.325703313231658e-11*(1.1158800544288205e13 - 4.78153368e11*chia*delta) + 5.325703313231658e-11*(-7.668603017220088e12 + 8.1249049728e12*chia*delta)*nu) + pow(chis,2)*(-12.732514880952381 + 323.1175595238095*nu - 102.08333333333333*pow(nu,2))),
      Phi6Lnv(-81.52380952380952),
      Phi7(2.0503957755941882e-7*(5.812952347108797e8 - 1.0916842457081544e9*pow(chia,2) - 4.074790483e9*chia*delta + 3.52392768e8*pow(chia,3)*delta) + 2.0503957755941882e-7*(4.7946122512789154e8 + 4.290127562081168e9*pow(chia,2) - 4.10784696e8*chia*delta - 1.58678352e9*pow(chia,3)*delta)*nu + 2.0503957755941882e-7*(-1.8758414548746935e8 + 8.16654384e8*chia*delta + 5.1819264e7*pow(chia,3)*delta)*pow(nu,2) + pow(chis,3)*(72.25446428571429 - 55.539434523809526*nu + 37.708333333333336*pow(nu,2)) + pow(chis,2)*(2.0503957755941882e-7*(-1.0916842457081544e9 + 1.057178304e9*chia*delta) + 2.0503957755941882e-7*(7.660942075144944e7 - 7.18956e8*chia*delta)*nu + 31.875*chia*delta*pow(nu,2)) + chis*(2.0503957755941882e-7*(-4.074790483e9 + 2.44073088e8*pow(chia,2) - 2.183368491416309e9*chia*delta + 8.13105216e8*pow(chia,2)*pow(delta,2)) + 2.0503957755941882e-7*(3.478848284e9 - 1.601589024e9*pow(chia,2))*nu + 2.0503957755941882e-7*(2.255806224e9 + 1.815706368e9*pow(chia,2))*pow(nu,2) - 82.
 99189814814815*pow(nu,3))),

      Phi10a( love1*pow((m1/compact1),5)*4.*(12.-11.*m1)/m1 ),
      Phi10b( love2*pow((m2/compact2),5)*4.*(12.-11.*m2)/m2 ),
      Phi12a( love1*pow((m1/compact1),5)*5.*(3179.-919.*m1-2286.*m1*m1+260.*m1*m1*m1)/(m1*84.) ),
      Phi12b( love2*pow((m2/compact2),5)*5.*(3179.-919.*m2-2286.*m2*m2+260.*m2*m2*m2)/(m2*84.) )
  {
    double t;
    (*this)(v0, t, Phi0);
    Phi0 *= -1.0;
  }

  /// Make this object a functor for finding the value of v for which t=0
  double operator()(const double v) const {
    double t, Phi;
    (*this)(v, t, Phi);
    return t;
  }

  /// This evaluates the approximant for values of v
  void operator()(const double v, double& t, double& Phi) const {
    const double lnv = log(v);
    const double vFifth = fifth(v);
    const double vEighth = vFifth*v*v*v;
    t = (-5/(256.*nu*vEighth))*(1.0 + v*v*(t2 + v*(t3 + v*(t4 + v*(t5 + v*(t6 + t6Lnv*lnv + v*(t7 + v*v*v*(t10a+t10b + v*v*(t12a+t12b) ) ) ) ) ) ) ) );
    Phi = Phi0-(1/(32.*nu*vFifth))*(1.0 + v*v*(Phi2 + v*(Phi3 + v*(Phi4 + v*(Phi5 + Phi5Lnv*lnv + v*(Phi6 + Phi6Lnv*lnv + v*(Phi7 + v*v*v*(Phi10a+Phi10b + v*v*(Phi12a+Phi12b) ) ) ) ) ) ) ) );
  }
};

void WU::TaylorT2Tidal(const double delta, const double chis, const double chia, const double v0,
		  vector<double>& t, vector<double>& v, vector<double>& Phi,
		  const double love1, const double love2, const double compact1, const double compact2, const int NPoints)
{
  T2Tidal d(delta, chis, chia, v0, love1, love2, compact1, compact2);
  int nroot;
  vector<double>xb1(1),xb2(1);
  zbrak(d,0.1,1.0,10000,xb1,xb2,nroot);
  double vMax=0.999;
  if(nroot>0) { vMax=zriddr(d,xb1[0],xb2[0],fabs(1.0-xb1[0])*1.e-8); }
  const double dv = (vMax-v0)/double(NPoints-1);
  v.resize(NPoints);
  t.resize(NPoints);
  Phi.resize(NPoints);
  for(int i=0; i<NPoints; ++i) {
    v[i] = v0+i*dv;
    d(v[i],t[i],Phi[i]);
  }
  return;
}