
#include "PNOrbitalPhasingT1.hpp"

//#define _USESTDVECTOR_
//#define _USENRERRORCLASS_
//#include "nr3.h"
//#include "odeint.h"
//#include "stepper.h"
//#include "stepperdopr5.h"
//#ifndef EulerGamma
//#define EulerGamma 0.5772156649015328606065120900824024
//#endif // EulerGamma

#include "ODEIntegrator.hpp"
typedef int NRerror;

using namespace std;

class T1 {
private:
  double delta;
  double nu;
  double chis;
  double chia;
  double PNOrder;
  
public:
  T1(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), chia(ichia), PNOrder(PNPhaseOrder) {}
  
  void operator() (const double t, const std::vector<double>& y, std::vector<double>& dydt) {
    const double& v=y[0];
    switch(int(2.*PNOrder)) {
    case 0:
      dydt[0]= (32*nu/5.)*pow(y[0],9);
      break;
      
    case 1:
      dydt[0]= (32*nu/5.)*pow(y[0],9);
      break;
      
    case 2:
      dydt[0]= (32*nu/5.)*pow(y[0],9)*((-336 + pow(v,2)*(1247 + 980*nu))/(-336 + pow(v,2)*(504 + 56*nu)));
      break;
      
    case 3:
      dydt[0]= (32*nu/5.)*pow(y[0],9)*((-336 + pow(v,2)*(1247 + 980*nu + v*(924*chis - 1344*M_PI + 924*chia*delta - 1008*chis*nu)))/(-336 + pow(v,2)*(504 + 56*nu + v*(-2240*chis - 2240*chia*delta + 1120*chis*nu))));
      break;
      
    case 4:
      dydt[0]= (32*nu/5.)*pow(y[0],9)*((-9072 + pow(v,2)*(33669 + 26460*nu + v*(24948*chis - 36288*M_PI + 24948*chia*delta - 27216*chis*nu + v*(44711 - 18711*pow(chia,2) - 18711*pow(chis,2) - 37422*chia*chis*delta - 166878*nu + 72576*pow(chia,2)*nu + 2268*pow(chis,2)*nu - 32760*pow(nu,2)))))/(-9072 + pow(v,2)*(13608 + 1512*nu + v*(-60480*chis - 60480*chia*delta + 30240*chis*nu + v*(91854 + 27216*pow(chia,2) + 27216*pow(chis,2) + 54432*chia*chis*delta - 64638*nu - 108864*pow(chia,2)*nu + 1134*pow(nu,2))))));
      break;
      
    case 5:
      dydt[0]= (32*nu/5.)*pow(y[0],9)*((18144 + pow(v,2)*(-67338 - 52920*nu + v*(-49896*chis + 72576*M_PI - 49896*chia*delta + 54432*chis*nu + v*(-89422 + 37422*pow(chia,2) + 37422*pow(chis,2) + 74844*chia*chis*delta + 333756*nu - 145152*pow(chia,2)*nu - 4536*pow(chis,2)*nu + 65520*pow(nu,2) + v*(-71442*chis - 40824*pow(chia,2)*chis - 13608*pow(chis,3) - 221157*M_PI - 71442*chia*delta - 13608*pow(chia,3)*delta - 40824*chia*pow(chis,2)*delta + 471240*chis*nu + 122472*pow(chia,2)*chis*nu + 40824*pow(chis,3)*nu - 440748*M_PI*nu + 357840*chia*delta*nu + 13608*pow(chia,3)*delta*nu + 40824*chia*pow(chis,2)*delta*nu - 316512*chis*pow(nu,2))))))/(18144 + pow(v,2)*(-27216 - 3024*nu + v*(120960*chis + 120960*chia*delta - 60480*chis*nu + v*(-183708 - 54432*pow(chia,2) - 54432*pow(chis,2) - 108864*chia*chis*delta + 129276*nu + 217728*pow(chia,2)*nu - 2268*pow(nu,2) + v*(508032*chis + 508032*chia*delta - 853776*chis*nu - 218736*chia*delta*nu + 14112*chis*pow(nu,2)))))));
      break;
      
    case 6:
      dydt[0]= (32*nu/5.)*pow(y[0],9)*((-209563200.0 + pow(v,2)*(777753900.0 + 611226000.0*nu + v*(576298800.0*chis - 838252800.0*M_PI + 576298800.0*chia*delta - 628689600.0*chis*nu + v*(1032824100.0 - 432224100.0*pow(chia,2) - 432224100.0*pow(chis,2) - 864448200.0*chia*chis*delta - 3854881800.0*nu + 1676505600.0*pow(chia,2)*nu + 52390800*pow(chis,2)*nu - 756756000.0*pow(nu,2) + v*(825155100.0*chis + 471517200.0*pow(chia,2)*chis + 157172400.0*pow(chis,3) + 2554363350.0*M_PI + 825155100.0*chia*delta + 157172400.0*pow(chia,3)*delta + 471517200.0*chia*pow(chis,2)*delta - 5442822000.0*chis*nu - 1414551600.0*pow(chia,2)*chis*nu - 471517200.0*pow(chis,3)*nu + 5090639400.0*M_PI*nu - 4133052000.0*chia*delta*nu - 157172400.0*pow(chia,3)*delta*nu - 471517200.0*chia*pow(chis,2)*delta*nu + 3655713600.0*chis*pow(nu,2) + v*(-19931218557.0 + 3416878080.0*EulerGamma - 1117670400.0*pow(M_PI,2) + 3625933850.0*nu - 179001900.0*pow(M_PI,2)*nu + 6542127900.0*pow(nu,2) + 501270000.0*pow(nu,3) + 1708439040.0*log(16*pow(v,2))))))))/(-209563200.0 + pow(v,2)*(314344800.0 + 34927200*nu + v*(-1397088000.0*chis - 1397088000.0*chia*delta + 698544000.0*chis*nu + v*(2121827400.0 + 628689600.0*pow(chia,2) + 628689600.0*pow(chis,2) + 1257379200.0*chia*chis*delta - 1493137800.0*nu - 2514758400.0*pow(chia,2)*nu + 26195400*pow(nu,2) + v*(-5867769600.0*chis - 5867769600.0*chia*delta + 9861112800.0*chis*nu + 2526400800.0*chia*delta*nu - 162993600.0*chis*pow(nu,2) + v*(8840947500.0 - 50127808500.0*nu + 1790019000.0*pow(M_PI,2)*nu + 1353429000.0*pow(nu,2) + 5659500*pow(nu,3))))))));
      break;
      
    case 7:
      dydt[0]= (32*nu/5.)*pow(y[0],9)*((-209563200.0 + pow(v,2)*(777753900.0 + 611226000.0*nu + v*(576298800.0*chis - 838252800.0*M_PI + 576298800.0*chia*delta - 628689600.0*chis*nu + v*(1032824100.0 - 432224100.0*pow(chia,2) - 432224100.0*pow(chis,2) - 864448200.0*chia*chis*delta - 3854881800.0*nu + 1676505600.0*pow(chia,2)*nu + 52390800*pow(chis,2)*nu - 756756000.0*pow(nu,2) + v*(825155100.0*chis + 471517200.0*pow(chia,2)*chis + 157172400.0*pow(chis,3) + 2554363350.0*M_PI + 825155100.0*chia*delta + 157172400.0*pow(chia,3)*delta + 471517200.0*chia*pow(chis,2)*delta - 5442822000.0*chis*nu - 1414551600.0*pow(chia,2)*chis*nu - 471517200.0*pow(chis,3)*nu + 5090639400.0*M_PI*nu - 4133052000.0*chia*delta*nu - 157172400.0*pow(chia,3)*delta*nu - 471517200.0*chia*pow(chis,2)*delta*nu + 3655713600.0*chis*pow(nu,2) + v*(-19931218557.0 + 3416878080.0*EulerGamma - 1117670400.0*pow(M_PI,2) + 3625933850.0*nu - 179001900.0*pow(M_PI,2)*nu + 6542127900.0*pow(nu,2) + 501270000.0*pow(nu,3) + v*(6771303000.0*M_PI - 26043199875.0*M_PI*nu - 13401580500.0*M_PI*pow(nu,2)) + 1708439040.0*log(16*pow(v,2))))))))/(-209563200.0 + pow(v,2)*(314344800.0 + 34927200*nu + v*(-1397088000.0*chis - 1397088000.0*chia*delta + 698544000.0*chis*nu + v*(2121827400.0 + 628689600.0*pow(chia,2) + 628689600.0*pow(chis,2) + 1257379200.0*chia*chis*delta - 1493137800.0*nu - 2514758400.0*pow(chia,2)*nu + 26195400*pow(nu,2) + v*(-5867769600.0*chis - 5867769600.0*chia*delta + 9861112800.0*chis*nu + 2526400800.0*chia*delta*nu - 162993600.0*chis*pow(nu,2) + v*(8840947500.0 - 50127808500.0*nu + 1790019000.0*pow(M_PI,2)*nu + 1353429000.0*pow(nu,2) + 5659500*pow(nu,3))))))));
      break;
      
    default:
      cerr <<"Somehow PNOrder=" << PNOrder <<") didn't break from any switches..." <<endl;
      exit(1);
    } //switch(int(2*PNOrder))
    
    dydt[1]=y[0]*y[0]*y[0];
  }
};

void TaylorT1(const double delta, const double chis, const double chia, const double v0,
	      std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi, const double PNPhaseOrder, const int nsave, const bool denseish) {
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8)); //10/pow(v0,8);
  const double rtol=1.0e-10, atol=0.0, h1=1.0e2, hmin=1.0e-3, t0=-GuessedLength, t1=0.0;
  std::vector<double> ystart(2);
  ystart[0]=v0;
  ystart[1]=0.0;
  Output out(nsave);
  T1 d(delta, chis, chia, PNPhaseOrder);
  Odeint< ::StepperDopr853<T1> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d, denseish);
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
