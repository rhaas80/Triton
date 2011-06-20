#include "PNOrbitalPhasingT3.hpp"

#ifndef EulerGamma
#define EulerGamma 0.5772156649015328606065120900824024
#endif
#include "VectorFunctions.hpp"
#include "Minimize.hpp"
#include <cmath>
using namespace std;
typedef int NRerror;



class T3 {
private:
  double delta;
  double nu;
  double chis;
  double chia;
  double PNOrder;
  double v0;
  
public:
  bool Findv0;
  
public:
  T3(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder, const double iv0)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), chia(ichia), PNOrder(PNPhaseOrder), v0(iv0), Findv0(true) {}
  
  double operator()(const double t) const {
    if(Findv0) {
      vector<double> v(1, 0.0);
      vector<double> Phi(1, 0.0);
      vPhi(v, vector<double>(1, t), Phi);
      return (v[0]-v0)*(v[0]-v0);
    } else {
      vector<double> v(1, 0.0);
      vector<double> Phi(1, 0.0);
      vPhi(v, vector<double>(1, t), Phi);
      return -v[0];
    }
  }
  
  void vPhi(vector<double>& v, const vector<double>& t, vector<double>& Phi) const {
    const vector<double> tauToNegativeOne8th = pow((-nu/5.0)*t,-1./8.);
    switch(int(2*PNOrder)) {
    case 0:
      v = (0.5*tauToNegativeOne8th);
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)));
      break;
      
    case 1:
      v = (0.5*tauToNegativeOne8th);
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)));
      break;
      
    case 2:
      v = (0.5*tauToNegativeOne8th)*(1 + (0.09213789682539683 + (11*nu)/96.)*pow(tauToNegativeOne8th,2));
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)))*(1 + (0.46068948412698413 + (55*nu)/96.)*pow(tauToNegativeOne8th,2));
      break;
      
    case 3:
      v = (0.5*tauToNegativeOne8th)*(1 + pow(tauToNegativeOne8th,2)*(0.09213789682539683 + (11*nu)/96. + ((113*chis)/480. - M_PI/10. + (113*chia*delta)/480. - (19*chis*nu)/120.)*tauToNegativeOne8th));
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)))*(1 + pow(tauToNegativeOne8th,2)*(0.46068948412698413 + (55*nu)/96. + ((113*chis)/64. - (3*M_PI)/4. + (113*chia*delta)/64. - (19*chis*nu)/16.)*tauToNegativeOne8th));
      break;
      
    case 4:
      v = (0.5*tauToNegativeOne8th)*(1 + pow(tauToNegativeOne8th,2)*(0.09213789682539683 + (11*nu)/96. + tauToNegativeOne8th*((113*chis)/480. - M_PI/10. + (113*chia*delta)/480. - (19*chis*nu)/120. + (0.034302088438818816 - (81*pow(chia,2))/1024. - (81*pow(chis,2))/1024. - (81*chia*chis*delta)/512. + (13543*nu)/258048. + (5*pow(chia,2)*nu)/16. + (pow(chis,2)*nu)/256. + (871*pow(nu,2))/18432.)*tauToNegativeOne8th)));
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)))*(1 + pow(tauToNegativeOne8th,2)*(0.46068948412698413 + (55*nu)/96. + tauToNegativeOne8th*((113*chis)/64. - (3*M_PI)/4. + (113*chia*delta)/64. - (19*chis*nu)/16. + (0.6418722070533943 - (1215*pow(chia,2))/1024. - (1215*pow(chis,2))/1024. - (1215*chia*chis*delta)/512. + (284875*nu)/258048. + (75*pow(chia,2)*nu)/16. + (15*pow(chis,2)*nu)/256. + (1855*pow(nu,2))/2048.)*tauToNegativeOne8th)));
      break;
      
    case 5:
      v = (0.5*tauToNegativeOne8th)*(1 + pow(tauToNegativeOne8th,2)*(0.09213789682539683 + (11*nu)/96. + tauToNegativeOne8th*((113*chis)/480. - M_PI/10. + (113*chia*delta)/480. - (19*chis*nu)/120. + tauToNegativeOne8th*(0.034302088438818816 - (81*pow(chia,2))/1024. - (81*pow(chis,2))/1024. - (81*chia*chis*delta)/512. + (13543*nu)/258048. + (5*pow(chia,2)*nu)/16. + (pow(chis,2)*nu)/256. + (871*pow(nu,2))/18432. + ((1387051*chis)/1.93536e6 + (3*pow(chia,2)*chis)/128. + pow(chis,3)/128. - (32701*M_PI)/322560. + (1387051*chia*delta)/1.93536e6 + (pow(chia,3)*delta)/128. + (3*chia*pow(chis,2)*delta)/128. - (177703*chis*nu)/241920. - (9*pow(chia,2)*chis*nu)/128. - (3*pow(chis,3)*nu)/128. + (51*M_PI*nu)/1280. - (463*chia*delta*nu)/23040. - (pow(chia,3)*delta*nu)/128. - (3*chia*pow(chis,2)*delta*nu)/128. - (301*chis*pow(nu,2))/5760.)*tauToNegativeOne8th))));
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)))*(1 + pow(tauToNegativeOne8th,2)*(0.46068948412698413 + (55*nu)/96. + tauToNegativeOne8th*((113*chis)/64. - (3*M_PI)/4. + (113*chia*delta)/64. - (19*chis*nu)/16. + tauToNegativeOne8th*(0.6418722070533943 - (1215*pow(chia,2))/1024. - (1215*pow(chis,2))/1024. - (1215*chia*chis*delta)/512. + (284875*nu)/258048. + (75*pow(chia,2)*nu)/16. + (15*pow(chis,2)*nu)/256. + (1855*pow(nu,2))/2048. + ((-735505*chis)/64512. - (45*pow(chia,2)*chis)/128. - (15*pow(chis,3))/128. + (38645*M_PI)/21504. - (735505*chia*delta)/64512. - (15*pow(chia,3)*delta)/128. - (45*chia*pow(chis,2)*delta)/128. + (12265*chis*nu)/1152. + (135*pow(chia,2)*chis*nu)/128. + (45*pow(chis,3)*nu)/128. - (65*M_PI*nu)/256. - (65*chia*delta*nu)/128. + (15*pow(chia,3)*delta*nu)/128. + (45*chia*pow(chis,2)*delta*nu)/128. + (85*chis*pow(nu,2))/64.)*tauToNegativeOne8th*log(tauToNegativeOne8th)))));
      break;
      
    case 6:
      v = (0.5*tauToNegativeOne8th)*(1 + pow(tauToNegativeOne8th,2)*(0.09213789682539683 + (11*nu)/96. + tauToNegativeOne8th*((113*chis)/480. - M_PI/10. + (113*chia*delta)/480. - (19*chis*nu)/120. + tauToNegativeOne8th*(0.034302088438818816 - (81*pow(chia,2))/1024. - (81*pow(chis,2))/1024. - (81*chia*chis*delta)/512. + (13543*nu)/258048. + (5*pow(chia,2)*nu)/16. + (pow(chis,2)*nu)/256. + (871*pow(nu,2))/18432. + tauToNegativeOne8th*((1387051*chis)/1.93536e6 + (3*pow(chia,2)*chis)/128. + pow(chis,3)/128. - (32701*M_PI)/322560. + (1387051*chia*delta)/1.93536e6 + (pow(chia,3)*delta)/128. + (3*chia*pow(chis,2)*delta)/128. - (177703*chis*nu)/241920. - (9*pow(chia,2)*chis*nu)/128. - (3*pow(chis,3)*nu)/128. + (51*M_PI*nu)/1280. - (463*chia*delta*nu)/23040. - (pow(chia,3)*delta*nu)/128. - (3*chia*pow(chis,2)*delta*nu)/128. - (301*chis*pow(nu,2))/5760. + tauToNegativeOne8th*(-0.8396678976282939 - (160681*pow(chia,2))/917504. - (108937*pow(chis,2))/2.064384e8 + (107*EulerGamma)/840. - (107*chis*M_PI)/300. + (47*pow(M_PI,2))/600. - (108937*chia*chis*delta)/1.032192e8 - (107*chia*M_PI*delta)/300. + (10057*pow(chia,2)*pow(delta,2))/57600. + (25070977133.0*nu)/1.2485394432e10 + (1112087*pow(chia,2)*nu)/2.064384e6 - (2960411*pow(chis,2)*nu)/6.4512e6 + (331*chis*M_PI*nu)/1200. - (451*pow(M_PI,2)*nu)/6144. - (2288167*chia*chis*delta*nu)/3.6864e6 - (4096439*pow(nu,2))/1.48635648e8 + (303*pow(chia,2)*pow(nu,2))/512. + (270071*pow(chis,2)*pow(nu,2))/1.8432e6 + (175777*pow(nu,3))/5.308416e6 + (107*log(256))/6720. + (107*log(tauToNegativeOne8th))/840.))))));
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)))*(1 + pow(tauToNegativeOne8th,2)*(0.46068948412698413 + (55*nu)/96. + tauToNegativeOne8th*((113*chis)/64. - (3*M_PI)/4. + (113*chia*delta)/64. - (19*chis*nu)/16. + tauToNegativeOne8th*(0.6418722070533943 - (1215*pow(chia,2))/1024. - (1215*pow(chis,2))/1024. - (1215*chia*chis*delta)/512. + (284875*nu)/258048. + (75*pow(chia,2)*nu)/16. + (15*pow(chis,2)*nu)/256. + (1855*pow(nu,2))/2048. + tauToNegativeOne8th*(tauToNegativeOne8th*(14.407006107939047 + (372975*pow(chia,2))/131072. - (1188991*pow(chis,2))/1.96608e6 - (107*EulerGamma)/56. + (969*chis*M_PI)/160. - (53*pow(M_PI,2))/40. - (1188991*chia*chis*delta)/983040. + (969*chia*M_PI*delta)/160. - (52997*pow(chia,2)*pow(delta,2))/15360. - (126510089885.0*nu)/4.161798144e9 - (5967725*pow(chia,2)*nu)/688128. + (3553639*pow(chis,2)*nu)/430080. - (369*chis*M_PI*nu)/80. + (2255*pow(M_PI,2)*nu)/2048. + (2696633*chia*chis*delta*nu)/245760. + (154565*pow(nu,2))/1.835008e6 - (5095*pow(chia,2)*pow(nu,2))/512. - (317929*pow(chis,2)*pow(nu,2))/122880. - (1179625*pow(nu,3))/1.769472e6 - (107*log(256))/448. - (107*log(tauToNegativeOne8th))/56.) + ((-735505*chis)/64512. - (45*pow(chia,2)*chis)/128. - (15*pow(chis,3))/128. + (38645*M_PI)/21504. - (735505*chia*delta)/64512. - (15*pow(chia,3)*delta)/128. - (45*chia*pow(chis,2)*delta)/128. + (12265*chis*nu)/1152. + (135*pow(chia,2)*chis*nu)/128. + (45*pow(chis,3)*nu)/128. - (65*M_PI*nu)/256. - (65*chia*delta*nu)/128. + (15*pow(chia,3)*delta*nu)/128. + (45*chia*pow(chis,2)*delta*nu)/128. + (85*chis*pow(nu,2))/64.)*log(tauToNegativeOne8th))))));
      break;
      
    case 7:
      v = (0.5*tauToNegativeOne8th)*(1 + pow(tauToNegativeOne8th,2)*(0.09213789682539683 + (11*nu)/96. + tauToNegativeOne8th*((113*chis)/480. - M_PI/10. + (113*chia*delta)/480. - (19*chis*nu)/120. + tauToNegativeOne8th*(0.034302088438818816 - (81*pow(chia,2))/1024. - (81*pow(chis,2))/1024. - (81*chia*chis*delta)/512. + (13543*nu)/258048. + (5*pow(chia,2)*nu)/16. + (pow(chis,2)*nu)/256. + (871*pow(nu,2))/18432. + tauToNegativeOne8th*((1387051*chis)/1.93536e6 + (3*pow(chia,2)*chis)/128. + pow(chis,3)/128. - (32701*M_PI)/322560. + (1387051*chia*delta)/1.93536e6 + (pow(chia,3)*delta)/128. + (3*chia*pow(chis,2)*delta)/128. - (177703*chis*nu)/241920. - (9*pow(chia,2)*chis*nu)/128. - (3*pow(chis,3)*nu)/128. + (51*M_PI*nu)/1280. - (463*chia*delta*nu)/23040. - (pow(chia,3)*delta*nu)/128. - (3*chia*pow(chis,2)*delta*nu)/128. - (301*chis*pow(nu,2))/5760. + tauToNegativeOne8th*(-0.8396678976282939 - (160681*pow(chia,2))/917504. - (108937*pow(chis,2))/2.064384e8 + (107*EulerGamma)/840. - (107*chis*M_PI)/300. + (47*pow(M_PI,2))/600. - (108937*chia*chis*delta)/1.032192e8 - (107*chia*M_PI*delta)/300. + (10057*pow(chia,2)*pow(delta,2))/57600. + (25070977133.0*nu)/1.2485394432e10 + (1112087*pow(chia,2)*nu)/2.064384e6 - (2960411*pow(chis,2)*nu)/6.4512e6 + (331*chis*M_PI*nu)/1200. - (451*pow(M_PI,2)*nu)/6144. - (2288167*chia*chis*delta*nu)/3.6864e6 - (4096439*pow(nu,2))/1.48635648e8 + (303*pow(chia,2)*pow(nu,2))/512. + (270071*pow(chis,2)*pow(nu,2))/1.8432e6 + (175777*pow(nu,3))/5.308416e6 + ((4074790483.0*chis)/1.560674304e9 - (1121*pow(chia,2)*chis)/7168. - (3237*pow(chis,3))/14336. - (15419335*M_PI)/1.30056192e8 + (57*pow(chia,2)*M_PI)/256. + (57*pow(chis,2)*M_PI)/256. + (4074790483.0*chia*delta)/1.560674304e9 - (3237*pow(chia,3)*delta)/14336. - (9711*chia*pow(chis,2)*delta)/14336. + (57*chia*chis*M_PI*delta)/128. - (1067*pow(chia,2)*chis*pow(delta,2))/2048. - (869712071.0*chis*nu)/3.90168576e8 + (88271*pow(chia,2)*chis*nu)/86016. + (14929*pow(chis,3)*nu)/86016. - (75703*M_PI*nu)/774144. - (7*pow(chia,2)*M_PI*nu)/8. - (pow(chis,2)*M_PI*nu)/64. + (30187*chia*delta*nu)/114688. + (87455*pow(chia,3)*delta*nu)/86016. + (39625*chia*pow(chis,2)*delta*nu)/86016. - (2237903*chis*pow(nu,2))/1.548288e6 - (1787*pow(chia,2)*chis*pow(nu,2))/1536. - (181*pow(chis,3)*pow(nu,2))/1536. + (14809*M_PI*pow(nu,2))/387072. - (115739*chia*delta*pow(nu,2))/221184. - (17*pow(chia,3)*delta*pow(nu,2))/512. - (51*chia*pow(chis,2)*delta*pow(nu,2))/512. + (14341*chis*pow(nu,3))/55296.)*tauToNegativeOne8th + (107*log(256))/6720. + (107*log(tauToNegativeOne8th))/840.))))));
      Phi = (-1./(nu*pow(tauToNegativeOne8th,5)))*(1 + pow(tauToNegativeOne8th,2)*(0.46068948412698413 + (55*nu)/96. + tauToNegativeOne8th*((113*chis)/64. - (3*M_PI)/4. + (113*chia*delta)/64. - (19*chis*nu)/16. + tauToNegativeOne8th*(0.6418722070533943 - (1215*pow(chia,2))/1024. - (1215*pow(chis,2))/1024. - (1215*chia*chis*delta)/512. + (284875*nu)/258048. + (75*pow(chia,2)*nu)/16. + (15*pow(chis,2)*nu)/256. + (1855*pow(nu,2))/2048. + tauToNegativeOne8th*(tauToNegativeOne8th*(14.407006107939047 + (372975*pow(chia,2))/131072. - (1188991*pow(chis,2))/1.96608e6 - (107*EulerGamma)/56. + (969*chis*M_PI)/160. - (53*pow(M_PI,2))/40. - (1188991*chia*chis*delta)/983040. + (969*chia*M_PI*delta)/160. - (52997*pow(chia,2)*pow(delta,2))/15360. - (126510089885.0*nu)/4.161798144e9 - (5967725*pow(chia,2)*nu)/688128. + (3553639*pow(chis,2)*nu)/430080. - (369*chis*M_PI*nu)/80. + (2255*pow(M_PI,2)*nu)/2048. + (2696633*chia*chis*delta*nu)/245760. + (154565*pow(nu,2))/1.835008e6 - (5095*pow(chia,2)*pow(nu,2))/512. - (317929*pow(chis,2)*pow(nu,2))/122880. - (1179625*pow(nu,3))/1.769472e6 + ((-5386538891.0*chis)/2.60112384e8 + (325681*pow(chia,2)*chis)/229376. + (1350103*pow(chis,3))/688128. + (188516689.0*M_PI)/1.73408256e8 - (3663*pow(chia,2)*M_PI)/2048. - (3663*pow(chis,2)*M_PI)/2048. - (5386538891.0*chia*delta)/2.60112384e8 + (1350103*pow(chia,3)*delta)/688128. + (1350103*chia*pow(chis,2)*delta)/229376. - (3663*chia*chis*M_PI*delta)/1024. + (73173*pow(chia,2)*chis*pow(delta,2))/16384. + (86900563*chis*nu)/5.308416e6 - (1024291*pow(chia,2)*chis*nu)/114688. - (170243*pow(chis,3)*nu)/114688. + (488825*M_PI*nu)/516096. + (225*pow(chia,2)*M_PI*nu)/32. + (63*pow(chis,2)*M_PI*nu)/512. - (42122335*chia*delta*nu)/1.2386304e7 - (3004235*pow(chia,3)*delta*nu)/344064. - (441829*chia*pow(chis,2)*delta*nu)/114688. + (37576769*chis*pow(nu,2))/3.096576e6 + (39275*pow(chia,2)*chis*pow(nu,2))/4096. + (3823*pow(chis,3)*pow(nu,2))/4096. - (141769*M_PI*pow(nu,2))/516096. + (138941*chia*delta*pow(nu,2))/36864. + (1075*pow(chia,3)*delta*pow(nu,2))/4096. + (3225*chia*pow(chis,2)*delta*pow(nu,2))/4096. - (31841*chis*pow(nu,3))/18432.)*tauToNegativeOne8th - (107*log(256))/448. - (107*log(tauToNegativeOne8th))/56.) + ((-735505*chis)/64512. - (45*pow(chia,2)*chis)/128. - (15*pow(chis,3))/128. + (38645*M_PI)/21504. - (735505*chia*delta)/64512. - (15*pow(chia,3)*delta)/128. - (45*chia*pow(chis,2)*delta)/128. + (12265*chis*nu)/1152. + (135*pow(chia,2)*chis*nu)/128. + (45*pow(chis,3)*nu)/128. - (65*M_PI*nu)/256. - (65*chia*delta*nu)/128. + (15*pow(chia,3)*delta*nu)/128. + (45*chia*pow(chis,2)*delta*nu)/128. + (85*chis*pow(nu,2))/64.)*log(tauToNegativeOne8th))))));
      break;
      
    default:
      cerr << "Somehow PNOrder=" << PNOrder << " didn't break from any switches..." << endl;
      exit(1);
    } // switch(int(2.0*PNPhaseOrder))
    
    return;
  }
};


void TaylorT3(const double delta, const double chis, const double chia, const double v0,
	      std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	      const double PNPhaseOrder, const unsigned int NPoints)
{
  const double nu((1.0-delta*delta)/4.0);
  bool BadPoints(false);
  
  //// The T3 object 'd' serves as a functor, first to find the time at which v(t)=v0,
  //// then -- after d.Findv0=false is set -- to find the time at which v(t) is a maximum.
  T3 d(delta, chis, chia, PNPhaseOrder, v0);
  
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
  d.Findv0 = false;
  Minimizer.ax = t0;
  Minimizer.bx = -10.;
  Minimizer.cx = 0.0;
  double v1Bad(1.0);
  try {
    const double t1 = Minimizer.minimize(d);
    v1Bad = pow(-256*nu*t1/5., -1./8.);
  } catch(NRerror err) {
    cerr << "\nCouldn't find max of v(t) in TaylorT3.  Assuming it continues to v=1." << endl;
    BadPoints = true;
  }
  t = vector<double>(NPoints, 0.0);
  for(unsigned int i=0; i<NPoints; ++i) {
    t[i] = (-5.0/(256.0*nu))*pow(v0Bad + (v1Bad-v0Bad)*i/double(NPoints-1),-8);
  }
  
  // Evaluate v and Phi for the chosen t
  d.vPhi(v, t, Phi);
  
  //// If we couldn't find the max of v(t), remove v>1 from the data
  if(BadPoints) {
    unsigned int i=0;
    while(v[i]<1.0) { ++i; }
    v.erase(v.begin()+i, v.end());
    t.erase(t.begin()+i, t.end());
    Phi.erase(Phi.begin()+i, Phi.end());
    //t = t-t[t.size()-1];
  }
  
  return;
}
