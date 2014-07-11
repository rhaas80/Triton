#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T1_Tidal.hpp"

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

using std::cout;

inline double CUB(const double x) { return x*x*x; }

class T1Tidal {
private:
  double nu, m1, m2;
  double dvdtNum2, dvdtNum3, dvdtNum4, dvdtNum5, dvdtNum6, dvdtNum6Ln4v, dvdtNum7;
  double dvdtDen2, dvdtDen3, dvdtDen4, dvdtDen5, dvdtDen6;
  double dvdtNum10a, dvdtNum10b, dvdtNum12a, dvdtNum12b; //tidal terms
  double dvdtDen10a, dvdtDen10b, dvdtDen12a, dvdtDen12b;
  double tidalcoeffa, tidalcoeffb;

public:
  T1Tidal(const double delta, const double chis, const double chia, const double love1, const double love2, const double compact1, const double compact2)
    : m1((delta+1.0)/2.0),
      m2(1.0-m1),
      nu((1.0-delta*delta)/4.0),

      tidalcoeffa( love1*m1*m1*m1*m1/(compact1*compact1*compact1*compact1*compact1) ),
      tidalcoeffb( love2*m2*m2*m2*m2/(compact2*compact2*compact2*compact2*compact2) ),

      dvdtNum2(-3.7113095238095237 - 2.9166666666666665*nu),
      dvdtNum3(12.566370614359172 - 2.75*chis - 2.75*chia*delta + 3.*chis*nu),
      dvdtNum4(0.00011022927689594356*(-44711. + 18711.*pow(chia,2) + 18711.*pow(chis,2) + 37422.*chia*chis*delta + 166878.*nu - 72576.*pow(chia,2)*nu - 2268.*pow(chis,2)*nu + 32760.*pow(nu,2))),
      dvdtNum5(0.000496031746031746*(-77198.35627666199 - 7938.*chis - 4536.*pow(chia,2)*chis - 1512.*pow(chis,3) - 7938.*chia*delta - 1512.*pow(chia,3)*delta - 4536.*chia*pow(chis,2)*delta - 153850.07543159934*nu + 52360.*chis*nu + 13608.*pow(chia,2)*chis*nu + 4536.*pow(chis,3)*nu + 39760.*chia*delta*nu + 1512.*pow(chia,3)*delta*nu + 4536.*chia*pow(chis,2)*delta*nu - 35168.*chis*pow(nu,2))),
      dvdtNum6(4.771830168655566e-9*(2.8989907702972633e10 - 7.132257270479993e9*chis - 7.132257270479993e9*chia*delta - 1.8592559099566429e9*nu + 7.461438375271377e9*chis*nu - 6.5421279e9*pow(nu,2) - 5.0127e8*pow(nu,3))),
      dvdtNum6Ln4v(-16.304761904761904),
      dvdtNum7(0.00041335978835978834*(-245572.01454580695 + 944497.8401531961*nu + 486029.51625156973*pow(nu,2))),

      //dvdtNum10a( 4.*tidalcoeffa*(3.-2.*m1) ),
      //dvdtNum10b( 4.*tidalcoeffb*(3.-2.*m2) ),
      //dvdtNum12a( -1./42.*tidalcoeffa*(704.+m1*(1803.+7.*m1*(-643.+310.*m1))) ),
      //dvdtNum12b( -1./42.*tidalcoeffb*(704.+m2*(1803.+7.*m2*(-643.+310.*m2))) ),

      dvdtDen2(-1.5 - 0.16666666666666666*nu),
      dvdtDen3(-3.3333333333333335*(-2.*chis - 2.*chia*delta + chis*nu)),
      dvdtDen4(0.125*(-81. - 24.*pow(chia,2) - 24.*pow(chis,2) - 48.*chia*chis*delta + 57.*nu + 96.*pow(chia,2)*nu - 1.*pow(nu,2))),
      dvdtDen5(0.3888888888888889*(72.*chis + 72.*chia*delta - 121.*chis*nu - 31.*chia*delta*nu + 2.*chis*pow(nu,2))),
      dvdtDen6(-0.0038580246913580245*(10935. - 40149.69585598816*nu + 1674.*pow(nu,2) + 7.*pow(nu,3)))

      //dvdtDen10a( -36.*tidalcoeffa*(m2) ),
      //dvdtDen10b( -36.*tidalcoeffb*(m1) ),
      //dvdtDen12a( -77.*tidalcoeffa*m2*(3.+2.*m1+3.*m1*m1) ),
      //dvdtDen12b( -77.*tidalcoeffb*m1*(3.+2.*m2+3.*m2*m2) )

  {
      dvdtNum10a = 4.*tidalcoeffa*(3.-2.*m1);
      dvdtNum10b = 4.*tidalcoeffb*(3.-2.*m2);
      dvdtNum12a = -1./42.*tidalcoeffa*(704.+m1*(1803.+7.*m1*(-643.+310.*m1)));
      dvdtNum12b = -1./42.*tidalcoeffb*(704.+m2*(1803.+7.*m2*(-643.+310.*m2)));
      dvdtDen10a = -36.*tidalcoeffa*(m2);
      dvdtDen10b = -36.*tidalcoeffb*(m1);
      dvdtDen12a = -77.*tidalcoeffa*m2*(3.+2.*m1+3.*m1*m1)/3.;
      dvdtDen12b = -77.*tidalcoeffb*m1*(3.+2.*m2+3.*m2*m2)/3.;
 }

  void operator() (const double t, const vector<double>& y, vector<double>& dydt) {
    const double& v=y[0];
    const double cubv=CUB(v);
    dydt[0] = (6.4*nu)*CUB(cubv)
      * (1.0 + v*v*(dvdtNum2 + v*(dvdtNum3 + v*(dvdtNum4 + v*(dvdtNum5 + v*(dvdtNum6 + dvdtNum6Ln4v*log(4.0*v) + v*(dvdtNum7 + cubv*(dvdtNum10a+dvdtNum10b + v*v*(dvdtNum12a+dvdtNum12b) ) ) ) ) ) ) ) )
      / (1.0 + v*v*(dvdtDen2 + v*(dvdtDen3 + v*(dvdtDen4 + v*(dvdtDen5 + v*(dvdtDen6 + cubv*v*(dvdtDen10a+dvdtDen10b + v*v*(dvdtDen12a+dvdtDen12b) ) ) ) ) ) ) );
    dydt[1]=cubv;
  }

  bool ContinueIntegrating(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (dydt[0]>0.0 && y[0]<1.0);
  }

};

typedef bool (T1Tidal::*ContinueTest)(const double& t, const vector<double>& y, const vector<double>& dydt) const;

void WU::TaylorT1Tidal(const double delta, const double chis, const double chia, const double v0,
		  vector<double>& t, vector<double>& v, vector<double>& Phi,
		  const double love1, const double love2, const double compact1, const double compact2, const int nsave, const bool denseish)
{
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  const double rtol=1.0e-11, atol=0.0, h1=1.0e2, hmin=1.0e-3, t0=-GuessedLength, t1=0.0;
  vector<double> ystart(2);
  ystart[0]=v0;
  ystart[1]=0.0;
  Output out(nsave);
  T1Tidal d(delta, chis, chia, love1, love2, compact1, compact2);
  ContinueTest test = &T1Tidal::ContinueIntegrating;
  Odeint<StepperDopr853<T1Tidal> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d,denseish,test);
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