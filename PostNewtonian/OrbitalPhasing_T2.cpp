#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T2.hpp"

#include "Roots.hpp"
#include "VectorFunctions.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;
using WaveformUtilities::zbrak;
using WaveformUtilities::zriddr;
using WaveformUtilities::fifth;
using WaveformUtilities::eighth;
using std::vector;

class T2 {
private:
  double delta;
  double nu;
  double chis;
  double Phi0;
  double t2, t3, t4, t5, t6, t6Lnv, t7;
  double Phi2, Phi3, Phi4, Phi5Lnv, Phi6, Phi6Lnv, Phi7;
  
public:
  T2(const double idelta, const double ichis, const double v0)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), Phi0(0.0),
      t2(2.9484126984126986 + (11*nu)/3.),
      t3(chis*(15.066666666666666 - (152*nu)/15.) - (32*M_PI)/5.),
      t4(6.020630590199042 + pow(chis,2)*(-10.125 + nu/2.) + (5429*nu)/504. + (617*pow(nu,2))/72.),
      t5(pow(chis,3)*(4 - 12*nu) + chis*(195.244708994709 - (4960*nu)/27. - (68*pow(nu,2))/3.) - (7729*M_PI)/252. + (13*nu*M_PI)/3.),
      t6(88.26007501566575 + 661.6641095351773*nu - 8.802662037037036*pow(nu,2) + 19.72608024691358*pow(nu,3) + chis*(-475.4276882432553 + 326.72563597333846*nu) + pow(chis,2)*(10.186011904761903 - 258.4940476190476*nu + 81.66666666666666*pow(nu,2))),
      t6Lnv(65.21904761904761),
      t7(pow(chis,3)*(-195.67857142857142 + (4415*nu)/42. - (668*pow(nu,2))/3.) + chis*(2685.423859783111 - (878933759*nu)/381024. - (2289311*pow(nu,2))/1512. + (14341*pow(nu,3))/54.) - (15419335*M_PI)/127008. - (75703*nu*M_PI)/756. + (14809*pow(nu,2)*M_PI)/378. + pow(chis,2)*(228*M_PI - 16*nu*M_PI)),
      Phi2(3.685515873015873 + (55*nu)/12.),
      Phi3(chis*(23.541666666666668 - (95*nu)/6.) - 10*M_PI),
      Phi4(15.051576475497606 + (27145*nu)/1008. + (3085*pow(nu,2))/144. + pow(chis,2)*(-25.3125 + (5*nu)/4.)),
      Phi5Lnv(pow(chis,3)*(-7.5 + (45*nu)/2.) + chis*(-366.08382936507934 + (3100*nu)/9. + (85*pow(nu,2))/2.) + (38645*M_PI)/672. - (65*nu*M_PI)/8.),
      Phi6(-110.3250937695822 + chis*(594.2846103040692 - 408.4070449666731*nu) - 827.0801369189717*nu + 11.003327546296296*pow(nu,2) - 24.657600308641975*pow(nu,3) + pow(chis,2)*(-12.732514880952381 + 323.1175595238095*nu - 102.08333333333333*pow(nu,2))),
      Phi6Lnv(-81.52380952380952),
      Phi7(pow(chis,3)*(61.14955357142857 - (22075*nu)/672. + (835*pow(nu,2))/12.) + chis*(-839.1949561822221 + (4394668795.0*nu)/6.096384e6 + (11446555.0*pow(nu,2))/24192. - (71705*pow(nu,3))/864.) + (77096675.0*M_PI)/2.032128e6 + (378515*nu*M_PI)/12096. - (74045*pow(nu,2)*M_PI)/6048. + pow(chis,2)*((-285*M_PI)/4. + 5*nu*M_PI))
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
    t = (-5/(256.*nu*vEighth))*(1.0 + v*v*(t2 + v*(t3 + v*(t4 + v*(t5 + v*(t6 + t6Lnv*lnv + v*(t7) ) ) ) ) ) );
    Phi = Phi0-(1/(32.*nu*vFifth))*(1.0 + v*v*(Phi2 + v*(Phi3 + v*(Phi4 + v*(Phi5Lnv*lnv + v*(Phi6 + Phi6Lnv*lnv + v*(Phi7) ) ) ) ) ) );
  }
};

void WU::TaylorT2(const double delta, const double chis, const double v0,
		  vector<double>& t, vector<double>& v, vector<double>& Phi,
		  const int NPoints)
{
  T2 d(delta, chis, v0);
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
