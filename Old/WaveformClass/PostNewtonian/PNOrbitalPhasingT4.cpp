#include "PNOrbitalPhasingT4.hpp"

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

class T4 {
private:
  double delta;
  double nu;
  double chis;
  double chia;
  double PNOrder;
  
public:
  T4(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder)
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
    dydt[0]= (32*nu/5.)*pow(y[0],9)*(1 + pow(v,2)*(-2.2113095238095237 - (11*nu)/4. + pow(v,2)*(-3.3169642857142856 - (9059*nu)/2016. - (11*pow(nu,2))/24. + pow(v,2)*(-4.975446428571429 - (4901*nu)/672. - (17375*pow(nu,2))/12096. - (11*pow(nu,3))/144.))));
      break;
      
    case 3:
    dydt[0]= (32*nu/5.)*pow(y[0],9)*(1 + pow(v,2)*(-2.2113095238095237 - (11*nu)/4. + v*((-113*chis)/12. + 4*M_PI - (113*chia*delta)/12. + (19*chis*nu)/3. + v*(-3.3169642857142856 - (9059*nu)/2016. - (11*pow(nu,2))/24. + v*((311*chis)/504. + 6*M_PI + (311*chia*delta)/504. + (529*chis*nu)/28. + (2*M_PI*nu)/3. + (1207*chia*delta*nu)/72. - (73*chis*pow(nu,2))/9. + v*(-4.975446428571429 + (565*pow(chis,2))/9. - (80*chis*M_PI)/3. + (1130*chia*chis*delta)/9. - (80*chia*M_PI*delta)/3. + (565*pow(chia,2)*pow(delta,2))/9. - (4901*nu)/672. - (1325*pow(chis,2)*nu)/18. + (40*chis*M_PI*nu)/3. - (1325*chia*chis*delta*nu)/18. - (17375*pow(nu,2))/12096. + (190*pow(chis,2)*pow(nu,2))/9. - (11*pow(nu,3))/144. + v*((7741*chis)/336. + 9*M_PI + (7741*chia*delta)/336. + (5113*chis*nu)/108. + 2*M_PI*nu + (83471*chia*delta*nu)/1512. - (63325*chis*pow(nu,2))/3024. + (M_PI*pow(nu,2))/9. + (2527*chia*delta*pow(nu,2))/432. - (311*chis*pow(nu,3))/108.)))))));
      break;
      
    case 4:
    dydt[0]= (32*nu/5.)*pow(y[0],9)*(1 + pow(v,2)*(-2.2113095238095237 - (11*nu)/4. + v*((-113*chis)/12. + 4*M_PI - (113*chia*delta)/12. + (19*chis*nu)/3. + v*(1.8795745149911816 + (81*pow(chia,2))/16. + (81*pow(chis,2))/16. + (81*chia*chis*delta)/8. + (13661*nu)/2016. - 20*pow(chia,2)*nu - (pow(chis,2)*nu)/4. + (59*pow(nu,2))/18. + v*((311*chis)/504. + 6*M_PI + (311*chia*delta)/504. + (529*chis*nu)/28. + (2*M_PI*nu)/3. + (1207*chia*delta*nu)/72. - (73*chis*pow(nu,2))/9. + v*(-19.570147156084655 + (215*pow(chia,2))/224. + (128495*pow(chis,2))/2016. - (80*chis*M_PI)/3. + (128495*chia*chis*delta)/1008. - (80*chia*M_PI*delta)/3. + (565*pow(chia,2)*pow(delta,2))/9. - (350645*nu)/217728. - (2435*pow(chia,2)*nu)/224. - (23441*pow(chis,2)*nu)/288. + (40*chis*M_PI*nu)/3. - (12733*chia*chis*delta*nu)/144. + (613591*pow(nu,2))/24192. + (89*pow(chia,2)*pow(nu,2))/3. + (1517*pow(chis,2)*pow(nu,2))/72. + (175*pow(nu,3))/864. + v*((-5821429*chis)/54432. - 62*pow(chia,2)*chis - 62*pow(chis,3) + (99*M_PI)/2. + 12*pow(chia,2)*M_PI + 12*pow(chis,2)*M_PI - (5821429*chia*delta)/54432. - 62*pow(chia,3)*delta - 186*chia*pow(chis,2)*delta + 24*chia*chis*M_PI*delta - 124*pow(chia,2)*chis*pow(delta,2) + (6572711*chis*nu)/54432. + (6773*pow(chia,2)*chis*nu)/24. + (901*pow(chis,3)*nu)/24. - (53*M_PI*nu)/2. - 48*pow(chia,2)*M_PI*nu + (95089*chia*delta*nu)/2016. + (739*pow(chia,3)*delta*nu)/3. + (881*chia*pow(chis,2)*delta*nu)/12. - (330125*chis*pow(nu,2))/6048. - (428*pow(chia,2)*chis*pow(nu,2))/3. - (5*pow(chis,3)*pow(nu,2))/6. + (11*M_PI*pow(nu,2))/18. - (17483*chia*delta*pow(nu,2))/864. + (2239*chis*pow(nu,3))/216.)))))));
      break;
      
    case 5:
    dydt[0]= (32*nu/5.)*pow(y[0],9)*(1 + pow(v,2)*(-2.2113095238095237 - (11*nu)/4. + v*((-113*chis)/12. + 4*M_PI - (113*chia*delta)/12. + (19*chis*nu)/3. + v*(1.8795745149911816 + (81*pow(chia,2))/16. + (81*pow(chis,2))/16. + (81*chia*chis*delta)/8. + (13661*nu)/2016. - 20*pow(chia,2)*nu - (pow(chis,2)*nu)/4. + (59*pow(nu,2))/18. + v*((-31571*chis)/1008. - (9*pow(chia,2)*chis)/4. - (3*pow(chis,3))/4. - (4159*M_PI)/672. - (31571*chia*delta)/1008. - (3*pow(chia,3)*delta)/4. - (9*chia*pow(chis,2)*delta)/4. + (5791*chis*nu)/63. + (27*pow(chia,2)*chis*nu)/4. + (9*pow(chis,3)*nu)/4. - (189*M_PI*nu)/8. + (1165*chia*delta*nu)/24. + (3*pow(chia,3)*delta*nu)/4. + (9*chia*pow(chis,2)*delta*nu)/4. - (79*chis*pow(nu,2))/3. + v*(-19.570147156084655 + (215*pow(chia,2))/224. + (128495*pow(chis,2))/2016. - (80*chis*M_PI)/3. + (128495*chia*chis*delta)/1008. - (80*chia*M_PI*delta)/3. + (565*pow(chia,2)*pow(delta,2))/9. - (350645*nu)/217728. - (2435*pow(chia,2)*nu)/224. - (23441*pow(chis,2)*nu)/288. + (40*chis*M_PI*nu)/3. - (12733*chia*chis*delta*nu)/144. + (613591*pow(nu,2))/24192. + (89*pow(chia,2)*pow(nu,2))/3. + (1517*pow(chis,2)*pow(nu,2))/72. + (175*pow(nu,3))/864. + v*((-2529407*chis)/27216. - (523*pow(chia,2)*chis)/8. - (505*pow(chis,3))/8. + (13985*M_PI)/448. + 12*pow(chia,2)*M_PI + 12*pow(chis,2)*M_PI - (2529407*chia*delta)/27216. - (505*pow(chia,3)*delta)/8. - (1515*chia*pow(chis,2)*delta)/8. + 24*chia*chis*M_PI*delta - 124*pow(chia,2)*chis*pow(delta,2) + (10772921*chis*nu)/54432. + (7007*pow(chia,2)*chis*nu)/24. + (979*pow(chis,3)*nu)/24. - (261955*M_PI*nu)/4032. - 48*pow(chia,2)*M_PI*nu + (845827*chia*delta*nu)/6048. + (742*pow(chia,3)*delta*nu)/3. + (917*chia*pow(chis,2)*delta*nu)/12. - (398017*chis*pow(nu,2))/2016. - (3397*pow(chia,2)*chis*pow(nu,2))/24. - (11*pow(chis,3)*pow(nu,2))/24. - (55*M_PI*pow(nu,2))/16. - (41551*chia*delta*pow(nu,2))/864. + (pow(chia,3)*delta*pow(nu,2))/8. + (3*chia*pow(chis,2)*delta*pow(nu,2))/8. + (2045*chis*pow(nu,3))/216.)))))));
      break;
      
    case 6:
    dydt[0]= (32*nu/5.)*pow(y[0],9)*(1 + pow(v,2)*(-2.2113095238095237 - (11*nu)/4. + v*((-113*chis)/12. + 4*M_PI - (113*chia*delta)/12. + (19*chis*nu)/3. + v*(1.8795745149911816 + (81*pow(chia,2))/16. + (81*pow(chis,2))/16. + (81*chia*chis*delta)/8. + (13661*nu)/2016. - 20*pow(chia,2)*nu - (pow(chis,2)*nu)/4. + (59*pow(nu,2))/18. + v*((-31571*chis)/1008. - (9*pow(chia,2)*chis)/4. - (3*pow(chis,3))/4. - (4159*M_PI)/672. - (31571*chia*delta)/1008. - (3*pow(chia,3)*delta)/4. - (9*chia*pow(chis,2)*delta)/4. + (5791*chis*nu)/63. + (27*pow(chia,2)*chis*nu)/4. + (9*pow(chis,3)*nu)/4. - (189*M_PI*nu)/8. + (1165*chia*delta*nu)/24. + (3*pow(chia,3)*delta*nu)/4. + (9*chia*pow(chis,2)*delta*nu)/4. - (79*chis*pow(nu,2))/3. + v*(117.72574285227559 + (215*pow(chia,2))/224. + (128495*pow(chis,2))/2016. - (1712*EulerGamma)/105. - (80*chis*M_PI)/3. + (16*pow(M_PI,2))/3. + (128495*chia*chis*delta)/1008. - (80*chia*M_PI*delta)/3. + (565*pow(chia,2)*pow(delta,2))/9. - (56198689*nu)/217728. - (2435*pow(chia,2)*nu)/224. - (23441*pow(chis,2)*nu)/288. + (40*chis*M_PI*nu)/3. + (451*pow(M_PI,2)*nu)/48. - (12733*chia*chis*delta*nu)/144. + (541*pow(nu,2))/896. + (89*pow(chia,2)*pow(nu,2))/3. + (1517*pow(chis,2)*pow(nu,2))/72. - (5605*pow(nu,3))/2592. + v*((-2529407*chis)/27216. - (523*pow(chia,2)*chis)/8. - (505*pow(chis,3))/8. + (13985*M_PI)/448. + 12*pow(chia,2)*M_PI + 12*pow(chis,2)*M_PI - (2529407*chia*delta)/27216. - (505*pow(chia,3)*delta)/8. - (1515*chia*pow(chis,2)*delta)/8. + 24*chia*chis*M_PI*delta - 124*pow(chia,2)*chis*pow(delta,2) + (10772921*chis*nu)/54432. + (7007*pow(chia,2)*chis*nu)/24. + (979*pow(chis,3)*nu)/24. - (261955*M_PI*nu)/4032. - 48*pow(chia,2)*M_PI*nu + (845827*chia*delta*nu)/6048. + (742*pow(chia,3)*delta*nu)/3. + (917*chia*pow(chis,2)*delta*nu)/12. - (398017*chis*pow(nu,2))/2016. - (3397*pow(chia,2)*chis*pow(nu,2))/24. - (11*pow(chis,3)*pow(nu,2))/24. - (55*M_PI*pow(nu,2))/16. - (41551*chia*delta*pow(nu,2))/864. + (pow(chia,3)*delta*pow(nu,2))/8. + (3*chia*pow(chis,2)*delta*pow(nu,2))/8. + (2045*chis*pow(nu,3))/216.) - (856*log(16))/105. - (1712*log(v))/105.))))));
      break;
      
    case 7:
    dydt[0]= (32*nu/5.)*pow(y[0],9)*(1 + pow(v,2)*(-2.2113095238095237 - (11*nu)/4. + v*((-113*chis)/12. + 4*M_PI - (113*chia*delta)/12. + (19*chis*nu)/3. + v*(1.8795745149911816 + (81*pow(chia,2))/16. + (81*pow(chis,2))/16. + (81*chia*chis*delta)/8. + (13661*nu)/2016. - 20*pow(chia,2)*nu - (pow(chis,2)*nu)/4. + (59*pow(nu,2))/18. + v*((-31571*chis)/1008. - (9*pow(chia,2)*chis)/4. - (3*pow(chis,3))/4. - (4159*M_PI)/672. - (31571*chia*delta)/1008. - (3*pow(chia,3)*delta)/4. - (9*chia*pow(chis,2)*delta)/4. + (5791*chis*nu)/63. + (27*pow(chia,2)*chis*nu)/4. + (9*pow(chis,3)*nu)/4. - (189*M_PI*nu)/8. + (1165*chia*delta*nu)/24. + (3*pow(chia,3)*delta*nu)/4. + (9*chia*pow(chis,2)*delta*nu)/4. - (79*chis*pow(nu,2))/3. + v*(117.72574285227559 + (215*pow(chia,2))/224. + (128495*pow(chis,2))/2016. - (1712*EulerGamma)/105. - (80*chis*M_PI)/3. + (16*pow(M_PI,2))/3. + (128495*chia*chis*delta)/1008. - (80*chia*M_PI*delta)/3. + (565*pow(chia,2)*pow(delta,2))/9. - (56198689*nu)/217728. - (2435*pow(chia,2)*nu)/224. - (23441*pow(chis,2)*nu)/288. + (40*chis*M_PI*nu)/3. + (451*pow(M_PI,2)*nu)/48. - (12733*chia*chis*delta*nu)/144. + (541*pow(nu,2))/896. + (89*pow(chia,2)*pow(nu,2))/3. + (1517*pow(chis,2)*pow(nu,2))/72. - (5605*pow(nu,3))/2592. + v*((-2529407*chis)/27216. - (523*pow(chia,2)*chis)/8. - (505*pow(chis,3))/8. - (4415*M_PI)/4032. + 12*pow(chia,2)*M_PI + 12*pow(chis,2)*M_PI - (2529407*chia*delta)/27216. - (505*pow(chia,3)*delta)/8. - (1515*chia*pow(chis,2)*delta)/8. + 24*chia*chis*M_PI*delta - 124*pow(chia,2)*chis*pow(delta,2) + (10772921*chis*nu)/54432. + (7007*pow(chia,2)*chis*nu)/24. + (979*pow(chis,3)*nu)/24. + (358675*M_PI*nu)/6048. - 48*pow(chia,2)*M_PI*nu + (845827*chia*delta*nu)/6048. + (742*pow(chia,3)*delta*nu)/3. + (917*chia*pow(chis,2)*delta*nu)/12. - (398017*chis*pow(nu,2))/2016. - (3397*pow(chia,2)*chis*pow(nu,2))/24. - (11*pow(chis,3)*pow(nu,2))/24. + (91495*M_PI*pow(nu,2))/1512. - (41551*chia*delta*pow(nu,2))/864. + (pow(chia,3)*delta*pow(nu,2))/8. + (3*chia*pow(chis,2)*delta*pow(nu,2))/8. + (2045*chis*pow(nu,3))/216.) - (856*log(16))/105. - (1712*log(v))/105.))))));
      break;
      
    default:
      cerr <<"Somehow PNOrder=" << PNOrder <<") didn't break from any switches..." <<endl;
      exit(1);
    } //switch(int(2*PNOrder))
    
    dydt[1]=y[0]*y[0]*y[0];
  }
  
};

bool ContinueIntegratingT4(const double& x, const std::vector<double>& y, const std::vector<double>& dydx) {
  return (dydx[0]>0);
}

void TaylorT4(const double delta, const double chis, const double chia, const double v0,
	      std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi, const double PNPhaseOrder, const int nsave, const bool denseish) {
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8)); //10/pow(v0,8);
  const double rtol=1.0e-10, atol=0.0, h1=1.0e2, hmin=1.0e-3, t0=-GuessedLength, t1=0.0;
  std::vector<double> ystart(2);
  ystart[0]=v0;
  ystart[1]=0.0;
  Output out(nsave);
  T4 d(delta, chis, chia, PNPhaseOrder);
  Odeint< ::StepperDopr853<T4> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d, denseish, ContinueIntegratingT4);
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
