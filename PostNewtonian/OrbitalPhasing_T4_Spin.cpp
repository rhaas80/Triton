#include "NumericalRecipes.hpp"

#include "OrbitalPhasing_T4_Spin.hpp"

#include "ODEIntegrator.hpp"
#include "VectorFunctions.hpp"
namespace WU = WaveformUtilities;
typedef int NRerror;
using WaveformUtilities::cumtrapz;
using WaveformUtilities::dydx;
using WaveformUtilities::Output;
using WaveformUtilities::Odeint;
using WaveformUtilities::StepperDopr853;
using std::vector;

inline double SQR(const double x) { return x*x; }
inline double CUB(const double x) { return x*x*x; }

namespace T4SpinLocal {
  
  void cross(double& x, double& y, double& z, const vector<double>& a, const vector<double>& b) {
    vector<double> c = WaveformUtilities::cross(a, b);
    x=c[0];
    y=c[1];
    z=c[2];
    return;
  }
  
  double dot(const vector<double>& a, const vector<double>& b) {
    return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
  }
  
  vector<double> dot(const vector<double>& x1, const vector<double>& y1, const vector<double>& z1,
		     const vector<double>& x2, const vector<double>& y2, const vector<double>& z2) {
    vector<double> d(x1.size(), 0.0);
    for(unsigned int i=0; i<d.size(); ++i) {
      d[i] = x1[i]*x2[i]+y1[i]*y2[i]+z1[i]*z2[i];
    }
    return d;
  }
}

class T4Spin {
private:
  double delta, nu;
  vector<double> chis, chia;
  double chischis, chischia, chiachia, chisLNHat, chiaLNHat;
  double dvdt2, dvdt3, dvdt4, dvdt5, dvdt6, dvdt6Ln4v, dvdt7;
  
public:
  T4Spin(const double idelta, const vector<double>& chi1, const vector<double>& chi2)
    : delta(idelta),
      nu((1.0-delta*delta)/4.0),
      chis(0.5*(chi1+chi2)),
      chia(0.5*(chi1-chi2)),
      chischis(T4SpinLocal::dot(chis,chis)),
      chischia(T4SpinLocal::dot(chis,chia)),
      chiachia(T4SpinLocal::dot(chia,chia)),
      chisLNHat(chis[2]),
      chiaLNHat(chia[2]),
      dvdt2(-2.2113095238095237 - 2.75*nu),
      dvdt3(0.08333333333333333*(150.79644737231007 - 113.*chisLNHat - 113.*chiaLNHat*delta + 76.*chisLNHat*nu)),
      dvdt4(0.00005511463844797178*(34103. - 44037.*chiachia + 135891.*pow(chiaLNHat,2) - 44037.*chischis + 135891.*pow(chisLNHat,2) - 88074.*chischia*delta + 271782.*chiaLNHat*chisLNHat*delta + 122949.*nu + 181440.*chiachia*nu - 544320.*pow(chiaLNHat,2)*nu - 5292.*chischis*nu + 756.*pow(chisLNHat,2)*nu + 59472.*pow(nu,2))),
      dvdt5(0.000496031746031746*(-39197.65153883985 - 63142.*chisLNHat - 4536.*chiachia*chisLNHat - 1512.*chischis*chisLNHat - 63142.*chiaLNHat*delta - 1512.*chiachia*chiaLNHat*delta - 4536.*chiaLNHat*chischis*delta - 149627.77490517468*nu + 185312.*chisLNHat*nu + 13608.*chiachia*chisLNHat*nu + 4536.*chischis*chisLNHat*nu + 97860.*chiaLNHat*delta*nu + 1512.*chiachia*chiaLNHat*delta*nu + 4536.*chiaLNHat*chischis*delta*nu - 53088.*chisLNHat*pow(nu,2))),
      dvdt6(2.385915084327783e-9*(6.745934508094527e10 - 1.3565475e8*chiachia + 5.3794125e8*pow(chiaLNHat,2) - 1.3565475e8*chischis - 4.937716571870764e10*chisLNHat + 2.684976525e10*pow(chisLNHat,2) - 4.937716571870764e10*chiaLNHat*delta - 2.713095e8*chischia*delta + 5.36995305e10*chiaLNHat*chisLNHat*delta + 2.6311824e10*pow(chiaLNHat,2)*pow(delta,2) - 6.931556164404614e10*nu + 2.28534075e9*chiachia*nu - 6.84146925e9*pow(chiaLNHat,2)*nu + 1.37598615e9*chischis*nu + 3.247920233941658e10*chisLNHat*nu - 3.548967345e10*pow(chisLNHat,2)*nu + 3.1187079e9*chischia*delta*nu - 4.01793777e10*chiaLNHat*chisLNHat*delta*nu + 2.53066275e8*pow(nu,2) - 6.2170416e9*chiachia*pow(nu,2) + 1.86511248e10*pow(chiaLNHat,2)*pow(nu,2) - 2.03742e7*chischis*pow(nu,2) + 8.8511346e9*pow(chisLNHat,2)*pow(nu,2) - 9.063285e8*pow(nu,3))),
      dvdt6Ln4v(-16.304761904761904),
      dvdt7(-3.440012789087038 - 18.84955592153876*(chiachia + chischis - 3.*pow(chisLNHat,2) + 2.*chischia*delta - 3.*chiaLNHat*(chiaLNHat + 2.*chisLNHat*delta)) + 0.000036743092298647854*(-2.512188e6*pow(chisLNHat,3) - 7.536564e6*chiaLNHat*pow(chisLNHat,2)*delta + chiaLNHat*delta*(-2.529407e6 + 794178.*chiachia - 2.512188e6*pow(chiaLNHat,2) + 732942.*chischis + 1.649592e6*chischia*delta) + chisLNHat*(-2.529407e6 + 732942.*chiachia + 794178.*chischis + 1.649592e6*chischia*delta - 2.512188e6*pow(chiaLNHat,2)*(1. + 2.*pow(delta,2)))) + (186.31130043424588 + 75.39822368615503*chiachia - 226.1946710584651*pow(chiaLNHat,2) + 53.1875*pow(chisLNHat,3) + 369.5*pow(chiaLNHat,3)*delta + 0.00016534391534391533*chiaLNHat*(845827. - 738864.*chiachia + 29904.*chischis)*delta + 106.65277777777777*chiaLNHat*pow(chisLNHat,2)*delta - 0.000018371546149323927*chisLNHat*(-1.0772921e7 + 7.13097e6*chiachia - 2.3022846e7*pow(chiaLNHat,2) + 674730.*chischis + 1.914948e6*chischia*delta))*nu + 0.00016534391534391533*(1.1497600793607924e6 + 3.*(-398017. + 146076.*chiachia - 431424.*pow(chiaLNHat,2) - 1204.*chischis)*chisLNHat + 840.*pow(chisLNHat,3) + 7.*chiaLNHat*(-41551. + 108.*chiachia + 324.*chischis)*delta)*pow(nu,2) + 9.467592592592593*chisLNHat*pow(nu,3))
  { }
  
  void operator() (const double t, const vector<double>& y, vector<double>& dydt) {
    const double& v=y[0];
    vector<double> S1(3, 0.0), S2(3, 0.0), LN(3, 0.0);
    S1[0] = y[2]; S1[1] = y[3]; S1[2] = y[4];
    S2[0] = y[5]; S2[1] = y[6]; S2[2] = y[7];
    LN[0] = y[8]; LN[1] = y[9]; LN[2] = y[10];
    const vector<double> LNHat = LN / sqrt(T4SpinLocal::dot(LN,LN));
    const vector<double> chi1 = S1/SQR((1+delta)/2.);
    const vector<double> chi2 = S2/SQR((1-delta)/2.);
    chis = (0.5*(chi1+chi2));
    chia = (0.5*(chi1-chi2));
    chischis = (T4SpinLocal::dot(chis,chis));
    chischia = (T4SpinLocal::dot(chis,chia));
    chiachia = (T4SpinLocal::dot(chia,chia));
    chisLNHat = (T4SpinLocal::dot(chis,LNHat));
    chiaLNHat = (T4SpinLocal::dot(chia,LNHat));
    dvdt2 = (-2.2113095238095237 - 2.75*nu);
    dvdt3 = (0.08333333333333333*(150.79644737231007 - 113.*chisLNHat - 113.*chiaLNHat*delta + 76.*chisLNHat*nu));
    dvdt4 = (0.00005511463844797178*(34103. - 44037.*chiachia + 135891.*pow(chiaLNHat,2) - 44037.*chischis + 135891.*pow(chisLNHat,2) - 88074.*chischia*delta + 271782.*chiaLNHat*chisLNHat*delta + 122949.*nu + 181440.*chiachia*nu - 544320.*pow(chiaLNHat,2)*nu - 5292.*chischis*nu + 756.*pow(chisLNHat,2)*nu + 59472.*pow(nu,2)));
    dvdt5 = (0.000496031746031746*(-39197.65153883985 - 63142.*chisLNHat - 4536.*chiachia*chisLNHat - 1512.*chischis*chisLNHat - 63142.*chiaLNHat*delta - 1512.*chiachia*chiaLNHat*delta - 4536.*chiaLNHat*chischis*delta - 149627.77490517468*nu + 185312.*chisLNHat*nu + 13608.*chiachia*chisLNHat*nu + 4536.*chischis*chisLNHat*nu + 97860.*chiaLNHat*delta*nu + 1512.*chiachia*chiaLNHat*delta*nu + 4536.*chiaLNHat*chischis*delta*nu - 53088.*chisLNHat*pow(nu,2)));
    dvdt6 = (2.385915084327783e-9*(6.745934508094527e10 - 1.3565475e8*chiachia + 5.3794125e8*pow(chiaLNHat,2) - 1.3565475e8*chischis - 4.937716571870764e10*chisLNHat + 2.684976525e10*pow(chisLNHat,2) - 4.937716571870764e10*chiaLNHat*delta - 2.713095e8*chischia*delta + 5.36995305e10*chiaLNHat*chisLNHat*delta + 2.6311824e10*pow(chiaLNHat,2)*pow(delta,2) - 6.931556164404614e10*nu + 2.28534075e9*chiachia*nu - 6.84146925e9*pow(chiaLNHat,2)*nu + 1.37598615e9*chischis*nu + 3.247920233941658e10*chisLNHat*nu - 3.548967345e10*pow(chisLNHat,2)*nu + 3.1187079e9*chischia*delta*nu - 4.01793777e10*chiaLNHat*chisLNHat*delta*nu + 2.53066275e8*pow(nu,2) - 6.2170416e9*chiachia*pow(nu,2) + 1.86511248e10*pow(chiaLNHat,2)*pow(nu,2) - 2.03742e7*chischis*pow(nu,2) + 8.8511346e9*pow(chisLNHat,2)*pow(nu,2) - 9.063285e8*pow(nu,3)));
    dvdt6Ln4v = (-16.304761904761904);
    dvdt7 = (-3.440012789087038 - 18.84955592153876*(chiachia + chischis - 3.*pow(chisLNHat,2) + 2.*chischia*delta - 3.*chiaLNHat*(chiaLNHat + 2.*chisLNHat*delta)) + 0.000036743092298647854*(-2.512188e6*pow(chisLNHat,3) - 7.536564e6*chiaLNHat*pow(chisLNHat,2)*delta + chiaLNHat*delta*(-2.529407e6 + 794178.*chiachia - 2.512188e6*pow(chiaLNHat,2) + 732942.*chischis + 1.649592e6*chischia*delta) + chisLNHat*(-2.529407e6 + 732942.*chiachia + 794178.*chischis + 1.649592e6*chischia*delta - 2.512188e6*pow(chiaLNHat,2)*(1. + 2.*pow(delta,2)))) + (186.31130043424588 + 75.39822368615503*chiachia - 226.1946710584651*pow(chiaLNHat,2) + 53.1875*pow(chisLNHat,3) + 369.5*pow(chiaLNHat,3)*delta + 0.00016534391534391533*chiaLNHat*(845827. - 738864.*chiachia + 29904.*chischis)*delta + 106.65277777777777*chiaLNHat*pow(chisLNHat,2)*delta - 0.000018371546149323927*chisLNHat*(-1.0772921e7 + 7.13097e6*chiachia - 2.3022846e7*pow(chiaLNHat,2) + 674730.*chischis + 1.914948e6*chischia*delta))*nu + 0.00016534391534391533*(1.1497600793607924e6 + 3.*(-398017. + 146076.*chiachia - 431424.*pow(chiaLNHat,2) - 1204.*chischis)*chisLNHat + 840.*pow(chisLNHat,3) + 7.*chiaLNHat*(-41551. + 108.*chiachia + 324.*chischis)*delta)*pow(nu,2) + 9.467592592592593*chisLNHat*pow(nu,3));
    dydt[0] = (6.4*nu)*CUB(CUB(v))
      * (1.0 + v*v*(dvdt2 + v*(dvdt3 + v*(dvdt4 + v*(dvdt5 + v*(dvdt6 + dvdt6Ln4v*log(4.0*v) + v*(dvdt7) ) ) ) ) ) );
    dydt[1]=CUB(v);
    const double powv5 = v*v*dydt[1];
    // Omega_{1,2} taken from Eq. (4.5) of http://arxiv.org/abs/1212.5520v1
    const double Omega1 = powv5 * (0.75*(1-delta) + 0.5*nu
				   + v*v*(0.5625*(1-delta)+1.25*nu*(1+0.5*delta)-0.041666666666666667*nu*nu
					  + v*v*(0.84375 + delta*(-0.84375 + (4.875 - 0.15625*nu)*nu) + nu*(0.1875 + (-3.28125 - 0.020833333333333332*nu)*nu))));
    const double Omega2 = powv5 * (0.75*(1+delta) + 0.5*nu
				   + v*v*(0.5625*(1+delta)+1.25*nu*(1-0.5*delta)-0.041666666666666667*nu*nu
					  + v*v*(0.84375 - delta*(-0.84375 + (4.875 - 0.15625*nu)*nu) + nu*(0.1875 + (-3.28125 - 0.020833333333333332*nu)*nu))));
    const double m2overm1 = (1-delta)/(1+delta);
    const double S2Mag = sqrt(T4SpinLocal::dot(S2,S2));
    const double chi2LNHat = chisLNHat - chiaLNHat;
    const double m1overm2 = (1+delta)/(1-delta);
    const double S1Mag = sqrt(T4SpinLocal::dot(S1,S1));
    const double chi1LNHat = chisLNHat + chiaLNHat;
    const vector<double> OmegaLN = v*powv5 * ((2+1.5*m2overm1-1.5*(v/nu)*(S2Mag*chi2LNHat)) * S1 + (2+1.5*m1overm2-1.5*(v/nu)*(S1Mag*chi1LNHat)) * S2);
    T4SpinLocal::cross(dydt[2], dydt[3], dydt[4], Omega1*LNHat, S1);
    T4SpinLocal::cross(dydt[5], dydt[6], dydt[7], Omega2*LNHat, S2);
    T4SpinLocal::cross(dydt[8], dydt[9], dydt[10], OmegaLN, LN);
  }
  
  bool ContinueIntegrating(const double& t, const vector<double>& y, const vector<double>& dydt) const {
    return (dydt[0]>0.0 && y[0]<1.0);
  }
  
};

typedef bool (T4Spin::*ContinueTest)(const double& t, const vector<double>& y, const vector<double>& dydt) const;

void WU::TaylorT4Spin(const double delta, const vector<double>& chi1, const vector<double>& chi2, const double v0,
		      vector<double>& t, vector<double>& v, vector<double>& Phi,
		      vector<double>& chis, vector<double>& chia, vector<double>& alpha, vector<double>& beta, vector<double>& gamma,
		      const int nsave, const bool denseish)
{
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  const double rtol=1.0e-10, atol=1.0e-15, h1=1.0e2, hmin=1.0e-3, t0=-GuessedLength, t1=0.0;
  vector<double> ystart(11);
  ystart[0]=v0;                          // v
  ystart[1]=0.0;                         // Phi
  ystart[2] = chi1[0]*SQR((1+delta)/2);  // S1_x
  ystart[3] = chi1[1]*SQR((1+delta)/2);  // S1_y
  ystart[4] = chi1[2]*SQR((1+delta)/2);  // S1_z
  ystart[5] = chi2[0]*SQR((1-delta)/2);  // S2_x
  ystart[6] = chi2[1]*SQR((1-delta)/2);  // S2_y
  ystart[7] = chi2[2]*SQR((1-delta)/2);  // S2_z
  ystart[8] = 0.0;                       // LNHat_x
  ystart[9] = 0.0;                       // LNHat_y
  ystart[10] = 1;                        // LNHat_z
  //std::cerr << "Initial conditions: " << ystart << std::endl;
  Output out(nsave);
  T4Spin d(delta, chi1, chi2);
  ContinueTest test = &T4Spin::ContinueIntegrating;
  Odeint<StepperDopr853<T4Spin> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d,denseish,test);
  try {
    ode.integrate();
  } catch(NRerror err) { }
  
  out.xsave.resize(out.count);
  t.swap(out.xsave);
  t -= t.back();
  out.ysave.resize(out.ysave.nrows(), out.count);
  v.swap(out.ysave[0]);
  Phi.swap(out.ysave[1]);
  
  out.ysave[2] *= 2/SQR(1+delta);
  out.ysave[3] *= 2/SQR(1+delta);
  out.ysave[4] *= 2/SQR(1+delta);
  out.ysave[5] *= 2/SQR(1-delta);
  out.ysave[6] *= 2/SQR(1-delta);
  out.ysave[7] *= 2/SQR(1-delta);
  chis = T4SpinLocal::dot(out.ysave[8], out.ysave[9], out.ysave[10], out.ysave[2]+out.ysave[5], out.ysave[3]+out.ysave[6], out.ysave[4]+out.ysave[7]);
  chia = T4SpinLocal::dot(out.ysave[8], out.ysave[9], out.ysave[10], out.ysave[2]-out.ysave[5], out.ysave[3]-out.ysave[6], out.ysave[4]-out.ysave[7]);
  
  alpha = WaveformUtilities::Unwrap(atan2(out.ysave[9], out.ysave[8]));
  beta = WaveformUtilities::Unwrap(acos(out.ysave[10]));
  gamma = -alpha*out.ysave[10] + cumtrapz(t, dydx(out.ysave[10], t)*alpha);
  
  return;
}


void WU::TaylorT4Spin(const double delta, const vector<double>& chi1, const vector<double>& chi2, const double v0,
		      vector<double>& t, vector<double>& v, vector<double>& Phi,
		      vector<vector<double> >& S1, vector<vector<double> >& S2, vector<vector<double> >& LNHat,
		      const int nsave, const bool denseish)
{
  const double nu( (1.0-delta*delta)/4.0 );
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  const double rtol=1.0e-10, atol=1.0e-15, h1=1.0e2, hmin=1.0e-3, t0=-GuessedLength, t1=0.0;
  vector<double> ystart(11);
  ystart[0]=v0;                          // v
  ystart[1]=0.0;                         // Phi
  ystart[2] = chi1[0]*SQR((1+delta)/2);  // S1_x
  ystart[3] = chi1[1]*SQR((1+delta)/2);  // S1_y
  ystart[4] = chi1[2]*SQR((1+delta)/2);  // S1_z
  ystart[5] = chi2[0]*SQR((1-delta)/2);  // S2_x
  ystart[6] = chi2[1]*SQR((1-delta)/2);  // S2_y
  ystart[7] = chi2[2]*SQR((1-delta)/2);  // S2_z
  ystart[8] = 0.0;                       // LNHat_x
  ystart[9] = 0.0;                       // LNHat_y
  ystart[10] = 1;                        // LNHat_z
  //std::cerr << "Initial conditions: " << ystart << std::endl;
  Output out(nsave);
  T4Spin d(delta, chi1, chi2);
  ContinueTest test = &T4Spin::ContinueIntegrating;
  Odeint<StepperDopr853<T4Spin> > ode(ystart,t0,t1,atol,rtol,h1,hmin,out,d,denseish,test);
  try {
    ode.integrate();
  } catch(NRerror err) { }
  
  out.xsave.resize(out.count);
  t.swap(out.xsave);
  t -= t.back();
  out.ysave.resize(out.ysave.nrows(), out.count);
  v.swap(out.ysave[0]);
  Phi.swap(out.ysave[1]);
  
  S1.resize(3);
  S1[0].swap(out.ysave[2]);
  S1[1].swap(out.ysave[3]);
  S1[2].swap(out.ysave[4]);
  S2.resize(3);
  S2[0].swap(out.ysave[5]);
  S2[1].swap(out.ysave[6]);
  S2[2].swap(out.ysave[7]);
  LNHat.resize(3);
  LNHat[0].swap(out.ysave[8]);
  LNHat[1].swap(out.ysave[9]);
  LNHat[2].swap(out.ysave[10]);
  
  return;
}
