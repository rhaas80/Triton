#include "NumericalRecipes.hpp"

#include "RadiationAxis.hpp"

#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Minimize_MultiDim.hpp"

using namespace std;

using WaveformObjects::Waveform;

// Note that this object should be *minimized* in order to maximize
// the quantity |h_{2,2}|^2 + |h_{2,-2}|^2.  Minimization is the
// typical behavior of numerical routines, so this should be natural.
class MaximizeMagSum {
private:
  const WaveformObjects::Waveform& W;
  unsigned int t;
  double hRe2Neg2, hIm2Neg2, hRe2Neg1, hIm2Neg1, hRe20, hIm20, hRe21, hIm21, hRe22, hIm22;
public:
  MaximizeMagSum(const WaveformObjects::Waveform& iW)
    : W(iW), t(0),
      hRe2Neg2(W.Mag(0,t)*cos(W.Arg(0,t))), hIm2Neg2(W.Mag(0,t)*sin(W.Arg(0,t))),
      hRe2Neg1(W.Mag(1,t)*cos(W.Arg(1,t))), hIm2Neg1(W.Mag(1,t)*sin(W.Arg(1,t))),
      hRe20(W.Mag(2,t)*cos(W.Arg(2,t))), hIm20(W.Mag(2,t)*sin(W.Arg(2,t))),
      hRe21(W.Mag(3,t)*cos(W.Arg(3,t))), hIm21(W.Mag(3,t)*sin(W.Arg(3,t))),
      hRe22(W.Mag(4,t)*cos(W.Arg(4,t))), hIm22(W.Mag(4,t)*sin(W.Arg(4,t))) { }
  void SetT(const unsigned int T) {
    t = T;
    hRe2Neg2=(W.Mag(0,t)*cos(W.Arg(0,t))); hIm2Neg2=(W.Mag(0,t)*sin(W.Arg(0,t)));
    hRe2Neg1=(W.Mag(1,t)*cos(W.Arg(1,t))); hIm2Neg1=(W.Mag(1,t)*sin(W.Arg(1,t)));
    hRe20=(W.Mag(2,t)*cos(W.Arg(2,t))); hIm20=(W.Mag(2,t)*sin(W.Arg(2,t)));
    hRe21=(W.Mag(3,t)*cos(W.Arg(3,t))); hIm21=(W.Mag(3,t)*sin(W.Arg(3,t)));
    hRe22=(W.Mag(4,t)*cos(W.Arg(4,t))); hIm22=(W.Mag(4,t)*sin(W.Arg(4,t)));
  }
  double operator() (const std::vector<double>& x) const {
    const double cbetao2 = cos(x[0]/2.0);
    const double sbetao2 = sin(x[0]/2.0);
    const double c1gamma = cos(x[1]);
    const double s1gamma = sin(x[1]);
    const double c2gamma = c1gamma*c1gamma-s1gamma*s1gamma;
    const double s2gamma = 2*s1gamma*c1gamma;
    const double c3gamma = (4*c1gamma*c1gamma-3)*c1gamma;
    const double s3gamma = s1gamma*(3-4*s1gamma*s1gamma);
    const double c4gamma = c2gamma*c2gamma-s2gamma*s2gamma;
    const double s4gamma = 2*s2gamma*c2gamma;
    return -1.*pow(cbetao2,8)*(pow(hIm22,2) + pow(hRe22,2) + pow(hRe2Neg2,2)) - 4.*pow(cbetao2,7)*(-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2)*s1gamma*sbetao2 - 2.*pow(cbetao2,6)*(2.*(pow(hIm21,2) + pow(hRe21,2) + pow(hRe2Neg1,2)) + 2.4494897427831781*(c2gamma*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) + ((-1.*hIm22 + hIm2Neg2)*hRe20 + hIm20*(hRe22 - 1.*hRe2Neg2))*s2gamma))*pow(sbetao2,2) - 4.*pow(cbetao2,5)*(c3gamma*(hIm22*hIm2Neg1 - 1.*hIm21*hIm2Neg2 + hRe22*hRe2Neg1 - 1.*hRe21*hRe2Neg2) + 2.4494897427831781*(-1.*(hIm21 + hIm2Neg1)*hRe20 + hIm20*(hRe21 + hRe2Neg1))*s1gamma + (-1.*hIm2Neg2*hRe21 + hIm2Neg1*hRe22 - 1.*hIm22*hRe2Neg1 + hIm21*hRe2Neg2)*s3gamma)*pow(sbetao2,3) - 4.*pow(cbetao2,4)*(3.*(pow(hIm20,2) + pow(hRe20,2)) + 4.*c2gamma*(hIm21*hIm2Neg1 + hRe21*hRe2Neg1) + c4gamma*(hIm22*hIm2Neg2 + hRe22*hRe2Neg2) + 4.*(hIm2Neg1*hRe21 - 1.*hIm21*hRe2Neg1)*s2gamma + (hIm2Neg2*hRe22 - 1.*hIm22*hRe2Neg2)*s4gamma)*pow(sbetao2,4) - 4.*pow(cbetao2,3)*(c3gamma*(-1.*hIm22*hIm2Neg1 + hIm21*hIm2Neg2 - 1.*hRe22*hRe2Neg1 + hRe21*hRe2Neg2) + 2.4494897427831781*((hIm21 + hIm2Neg1)*hRe20 - 1.*hIm20*(hRe21 + hRe2Neg1))*s1gamma + (hIm2Neg2*hRe21 - 1.*hIm2Neg1*hRe22 + hIm22*hRe2Neg1 - 1.*hIm21*hRe2Neg2)*s3gamma)*pow(sbetao2,5) - 2.*pow(cbetao2,2)*(2.*(pow(hIm21,2) + pow(hRe21,2) + pow(hRe2Neg1,2)) + 2.4494897427831781*(c2gamma*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) + ((-1.*hIm22 + hIm2Neg2)*hRe20 + hIm20*(hRe22 - 1.*hRe2Neg2))*s2gamma))*pow(sbetao2,6) - 4.*cbetao2*(hIm22*hRe21 - 1.*hIm21*hRe22 + hIm2Neg2*hRe2Neg1 - 1.*hIm2Neg1*hRe2Neg2)*s1gamma*pow(sbetao2,7) - 1.*(pow(hIm22,2) + pow(hRe22,2) + pow(hRe2Neg2,2))*pow(sbetao2,8) - 4.*pow(cbetao2,2)*pow(hIm2Neg1,2)*pow(sbetao2,2)*(pow(cbetao2,4) + pow(sbetao2,4)) + 4.*c1gamma*cbetao2*(cbetao2 - 1.*sbetao2)*sbetao2*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2) + pow(cbetao2,2)*(-1.*hIm21*(2.4494897427831781*hIm20 + hIm22) + hIm2Neg1*(2.4494897427831781*hIm20 + hIm2Neg2) - 1.*hRe21*(2.4494897427831781*hRe20 + hRe22) + hRe2Neg1*(2.4494897427831781*hRe20 + hRe2Neg2))*pow(sbetao2,2) + (-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2)*pow(sbetao2,4)) - 1.*pow(hIm2Neg2,2)*(pow(cbetao2,8) + pow(sbetao2,8));
  }
  void df(const std::vector<double>& x, std::vector<double>& dfdx) const {
    const double cbetao2 = cos(x[0]/2.0);
    const double sbetao2 = sin(x[0]/2.0);
    const double c1gamma = cos(x[1]);
    const double s1gamma = sin(x[1]);
    const double c2gamma = c1gamma*c1gamma-s1gamma*s1gamma;
    const double s2gamma = 2*s1gamma*c1gamma;
    const double c3gamma = (4*c1gamma*c1gamma-3)*c1gamma;
    const double s3gamma = s1gamma*(3-4*s1gamma*s1gamma);
    const double c4gamma = c2gamma*c2gamma-s2gamma*s2gamma;
    const double s4gamma = 2*s2gamma*c2gamma;
    dfdx[0] = -2.*(4.*c4gamma*pow(cbetao2,3)*(hIm22*hIm2Neg2 + hRe22*hRe2Neg2)*(cbetao2 - 1.*sbetao2)*pow(sbetao2,3)*(cbetao2 + sbetao2) - 4.*pow(cbetao2,3)*(-1.*hIm2Neg2*hRe22 + hIm22*hRe2Neg2)*s4gamma*(cbetao2 - 1.*sbetao2)*pow(sbetao2,3)*(cbetao2 + sbetao2) + c3gamma*pow(cbetao2,2)*(hIm22*hIm2Neg1 - 1.*hIm21*hIm2Neg2 + hRe22*hRe2Neg1 - 1.*hRe21*hRe2Neg2)*pow(sbetao2,2)*(3.*pow(cbetao2,4) - 10.*pow(cbetao2,2)*pow(sbetao2,2) + 3.*pow(sbetao2,4)) + pow(cbetao2,2)*(-1.*hIm2Neg2*hRe21 + hIm2Neg1*hRe22 - 1.*hIm22*hRe2Neg1 + hIm21*hRe2Neg2)*s3gamma*pow(sbetao2,2)*(3.*pow(cbetao2,4) - 10.*pow(cbetao2,2)*pow(sbetao2,2) + 3.*pow(sbetao2,4)) - 2.*cbetao2*(cbetao2 - 1.*sbetao2)*sbetao2*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*pow(hIm21,2) + pow(hIm22,2) - 1.*pow(hRe21,2) + pow(hRe22,2) - 1.*pow(hRe2Neg1,2) + pow(hRe2Neg2,2)) + pow(cbetao2,2)*(-6.*pow(hIm20,2) + 2.*pow(hIm21,2) + pow(hIm22,2) + pow(hRe22,2) + 2.*(-3.*pow(hRe20,2) + pow(hRe21,2) + pow(hRe2Neg1,2)) + pow(hRe2Neg2,2))*pow(sbetao2,2) + (-1.*pow(hIm21,2) + pow(hIm22,2) - 1.*pow(hRe21,2) + pow(hRe22,2) - 1.*pow(hRe2Neg1,2) + pow(hRe2Neg2,2))*pow(sbetao2,4)) + cbetao2*s2gamma*sbetao2*(-1.*pow(cbetao2,2) + pow(sbetao2,2))*(2.4494897427831781*pow(cbetao2,4)*((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2)) - 2.*pow(cbetao2,2)*(2.4494897427831781*(hIm22 - 1.*hIm2Neg2)*hRe20 + 8.*hIm2Neg1*hRe21 - 8.*hIm21*hRe2Neg1 + 2.4494897427831781*hIm20*(-1.*hRe22 + hRe2Neg2))*pow(sbetao2,2) + 2.4494897427831781*((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2))*pow(sbetao2,4)) + c2gamma*cbetao2*(cbetao2 - 1.*sbetao2)*sbetao2*(cbetao2 + sbetao2)*(2.4494897427831781*pow(cbetao2,4)*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) - 2.*pow(cbetao2,2)*(-8.*hIm21*hIm2Neg1 + 2.4494897427831781*hIm20*(hIm22 + hIm2Neg2) - 8.*hRe21*hRe2Neg1 + 2.4494897427831781*hRe20*(hRe22 + hRe2Neg2))*pow(sbetao2,2) + 2.4494897427831781*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2))*pow(sbetao2,4)) + s1gamma*(pow(cbetao2,8)*(-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2) + pow(cbetao2,6)*(7.*hIm22*hRe21 - 1.*hIm21*(7.34846922834953429*hRe20 + 7.*hRe22) + 7.*hIm2Neg2*hRe2Neg1 + 7.34846922834953429*hIm20*(hRe21 + hRe2Neg1) - 1.*hIm2Neg1*(7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,2) - 24.494897427831781*pow(cbetao2,4)*(-1.*(hIm21 + hIm2Neg1)*hRe20 + hIm20*(hRe21 + hRe2Neg1))*pow(sbetao2,4) + pow(cbetao2,2)*(7.*hIm22*hRe21 - 1.*hIm21*(7.34846922834953429*hRe20 + 7.*hRe22) + 7.*hIm2Neg2*hRe2Neg1 + 7.34846922834953429*hIm20*(hRe21 + hRe2Neg1) - 1.*hIm2Neg1*(7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,6) + (-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2)*pow(sbetao2,8)) + c1gamma*(pow(cbetao2,8)*(hIm21*hIm22 - 1.*hIm2Neg1*hIm2Neg2 + hRe21*hRe22 - 1.*hRe2Neg1*hRe2Neg2) + pow(cbetao2,6)*(hIm21*(7.34846922834953429*hIm20 - 7.*hIm22) + hIm2Neg1*(-7.34846922834953429*hIm20 + 7.*hIm2Neg2) + hRe21*(7.34846922834953429*hRe20 - 7.*hRe22) + hRe2Neg1*(-7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,2) + 24.494897427831781*pow(cbetao2,4)*(hIm20*(-1.*hIm21 + hIm2Neg1) + hRe20*(-1.*hRe21 + hRe2Neg1))*pow(sbetao2,4) + pow(cbetao2,2)*(hIm21*(7.34846922834953429*hIm20 - 7.*hIm22) + hIm2Neg1*(-7.34846922834953429*hIm20 + 7.*hIm2Neg2) + hRe21*(7.34846922834953429*hRe20 - 7.*hRe22) + hRe2Neg1*(-7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,6) + (hIm21*hIm22 - 1.*hIm2Neg1*hIm2Neg2 + hRe21*hRe22 - 1.*hRe2Neg1*hRe2Neg2)*pow(sbetao2,8)) + 2.*cbetao2*sbetao2*(pow(hIm2Neg1,2)*pow(pow(cbetao2,2) - 1.*pow(sbetao2,2),3) + pow(hIm2Neg2,2)*(-1.*pow(cbetao2,6) + pow(sbetao2,6))));
    dfdx[1] = -4.*cbetao2*sbetao2*(4.*c4gamma*pow(cbetao2,3)*(hIm2Neg2*hRe22 - 1.*hIm22*hRe2Neg2)*pow(sbetao2,3) - 4.*pow(cbetao2,3)*(hIm22*hIm2Neg2 + hRe22*hRe2Neg2)*s4gamma*pow(sbetao2,3) + 3.*c3gamma*pow(cbetao2,2)*(-1.*hIm2Neg2*hRe21 + hIm2Neg1*hRe22 - 1.*hIm22*hRe2Neg1 + hIm21*hRe2Neg2)*(cbetao2 - 1.*sbetao2)*pow(sbetao2,2)*(cbetao2 + sbetao2) + 3.*pow(cbetao2,2)*(-1.*hIm22*hIm2Neg1 + hIm21*hIm2Neg2 - 1.*hRe22*hRe2Neg1 + hRe21*hRe2Neg2)*s3gamma*(cbetao2 - 1.*sbetao2)*pow(sbetao2,2)*(cbetao2 + sbetao2) + c2gamma*cbetao2*sbetao2*(2.4494897427831781*pow(cbetao2,4)*((-1.*hIm22 + hIm2Neg2)*hRe20 + hIm20*(hRe22 - 1.*hRe2Neg2)) + 8.*pow(cbetao2,2)*(hIm2Neg1*hRe21 - 1.*hIm21*hRe2Neg1)*pow(sbetao2,2) + 2.4494897427831781*((-1.*hIm22 + hIm2Neg2)*hRe20 + hIm20*(hRe22 - 1.*hRe2Neg2))*pow(sbetao2,4)) + c1gamma*(cbetao2 - 1.*sbetao2)*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2) + pow(cbetao2,2)*(-1.*hIm22*hRe21 + hIm21*(-2.4494897427831781*hRe20 + hRe22) - 1.*hIm2Neg2*hRe2Neg1 + 2.4494897427831781*hIm20*(hRe21 + hRe2Neg1) + hIm2Neg1*(-2.4494897427831781*hRe20 + hRe2Neg2))*pow(sbetao2,2) + (-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2)*pow(sbetao2,4)) + s1gamma*(cbetao2 - 1.*sbetao2)*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2) + pow(cbetao2,2)*(-1.*hIm21*(2.4494897427831781*hIm20 + hIm22) + hIm2Neg1*(2.4494897427831781*hIm20 + hIm2Neg2) - 1.*hRe21*(2.4494897427831781*hRe20 + hRe22) + hRe2Neg1*(2.4494897427831781*hRe20 + hRe2Neg2))*pow(sbetao2,2) + (-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2)*pow(sbetao2,4)) + cbetao2*s2gamma*sbetao2*(-2.4494897427831781*pow(cbetao2,4)*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) - 8.*pow(cbetao2,2)*(hIm21*hIm2Neg1 + hRe21*hRe2Neg1)*pow(sbetao2,2) - 2.4494897427831781*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2))*pow(sbetao2,4)));
    return;
  }
}; // class MaximizeMagSumn




void WaveformUtilities::RadiationAxis(const Waveform& W, const unsigned int tStep, double& beta, double& gamma) {
  vector<double> BetaGamma(2, 0.0);
  const double Tolerance = 5.0e-11;
  int Iterations1=0, Iterations2=0;
  double MagSum = 0.0;
  MaximizeMagSum Minimizer(W);
  Minimizer.SetT(tStep);
  try {
    WaveformUtilities::dfpmin(BetaGamma, Tolerance, Iterations1, MagSum, Minimizer);
  } catch(int) { }
  try {
    WaveformUtilities::dfpmin(BetaGamma, Tolerance, Iterations2, MagSum, Minimizer);
  } catch(int) { }
  BetaGamma = fmod(BetaGamma, M_PI);
  beta = BetaGamma[0];
  gamma = BetaGamma[1];
  return;
}

void WaveformUtilities::RadiationAxis(const Waveform& W, vector<double>& beta, vector<double>& gamma) {
  beta.resize(W.NTimes());
  gamma.resize(W.NTimes());
  vector<double> BetaGamma(2, 0.0);
  const double Tolerance = 5.0e-11;
  int Iterations1=0, Iterations2=0;
  double MagSum = 0.0;
  MaximizeMagSum Minimizer(W);
  for(unsigned int tStep=0; tStep<W.NTimes(); ++tStep) {
    Minimizer.SetT(tStep);
    try {
      WaveformUtilities::dfpmin(BetaGamma, Tolerance, Iterations1, MagSum, Minimizer);
    } catch(int) { }
    try {
      WaveformUtilities::dfpmin(BetaGamma, Tolerance, Iterations2, MagSum, Minimizer);
    } catch(int) { }
    if(tStep==0) { BetaGamma = fmod(BetaGamma, M_PI); }
    beta[tStep] = BetaGamma[0];
    gamma[tStep] = BetaGamma[1];
  }
  return;
}

void WaveformUtilities::YawFreeFrame(vector<double>& alpha, const vector<double>& beta, const vector<double>& gamma) {
  if(beta.size() != gamma.size()) {
    cerr << "\nbeta.size()=" << beta.size() << "  gamma.size()=" << gamma.size() << endl;
    throw("Size mismatch in YawFreeFrame.");
  }
  alpha.resize(gamma.size());
  
  throw("This one hasn't been programmed yet!");
  return;
}

void WaveformUtilities::YawFreeFrame(const Waveform& W, vector<double>& alpha, vector<double>& beta, vector<double>& gamma) {
  RadiationAxis(W, beta, gamma);
  YawFreeFrame(alpha, beta, gamma);
  return;
}
