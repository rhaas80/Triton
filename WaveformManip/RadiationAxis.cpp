#include "NumericalRecipes.hpp"

#include "RadiationAxis.hpp"

#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Minimize_MultiDim.hpp"
#include "Quaternions.hpp"
#include "Interpolate.hpp"
#include "ODEIntegrator.hpp"

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
    const double cbetao2 = cos(x[1]/2.0);
    const double sbetao2 = sin(x[1]/2.0);
    const double c1alpha = cos(x[0]);
    const double s1alpha = sin(x[0]);
    const double c2alpha = c1alpha*c1alpha-s1alpha*s1alpha;
    const double s2alpha = 2*s1alpha*c1alpha;
    const double c3alpha = (4*c1alpha*c1alpha-3)*c1alpha;
    const double s3alpha = s1alpha*(3-4*s1alpha*s1alpha);
    const double c4alpha = c2alpha*c2alpha-s2alpha*s2alpha;
    const double s4alpha = 2*s2alpha*c2alpha;
    return -1.*pow(cbetao2,8)*(pow(hIm22,2) + pow(hRe22,2) + pow(hRe2Neg2,2)) - 4.*pow(cbetao2,7)*(hIm22*hRe21 - 1.*hIm21*hRe22 + hIm2Neg2*hRe2Neg1 - 1.*hIm2Neg1*hRe2Neg2)*s1alpha*sbetao2 - 2.*pow(cbetao2,6)*(2.*(pow(hIm21,2) + pow(hRe21,2) + pow(hRe2Neg1,2)) + 2.4494897427831781*(c2alpha*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) + ((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2))*s2alpha))*pow(sbetao2,2) - 4.*pow(cbetao2,5)*(c3alpha*(hIm22*hIm2Neg1 - 1.*hIm21*hIm2Neg2 + hRe22*hRe2Neg1 - 1.*hRe21*hRe2Neg2) + 2.4494897427831781*((hIm21 + hIm2Neg1)*hRe20 - 1.*hIm20*(hRe21 + hRe2Neg1))*s1alpha + (hIm2Neg2*hRe21 - 1.*hIm2Neg1*hRe22 + hIm22*hRe2Neg1 - 1.*hIm21*hRe2Neg2)*s3alpha)*pow(sbetao2,3) - 4.*pow(cbetao2,4)*(3.*(pow(hIm20,2) + pow(hRe20,2)) + 4.*c2alpha*(hIm21*hIm2Neg1 + hRe21*hRe2Neg1) + c4alpha*(hIm22*hIm2Neg2 + hRe22*hRe2Neg2) + 4.*(-1.*hIm2Neg1*hRe21 + hIm21*hRe2Neg1)*s2alpha + (-1.*hIm2Neg2*hRe22 + hIm22*hRe2Neg2)*s4alpha)*pow(sbetao2,4) - 4.*pow(cbetao2,3)*(c3alpha*(-1.*hIm22*hIm2Neg1 + hIm21*hIm2Neg2 - 1.*hRe22*hRe2Neg1 + hRe21*hRe2Neg2) + 2.4494897427831781*(-1.*(hIm21 + hIm2Neg1)*hRe20 + hIm20*(hRe21 + hRe2Neg1))*s1alpha + (-1.*hIm2Neg2*hRe21 + hIm2Neg1*hRe22 - 1.*hIm22*hRe2Neg1 + hIm21*hRe2Neg2)*s3alpha)*pow(sbetao2,5) - 2.*pow(cbetao2,2)*(2.*(pow(hIm21,2) + pow(hRe21,2) + pow(hRe2Neg1,2)) + 2.4494897427831781*(c2alpha*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) + ((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2))*s2alpha))*pow(sbetao2,6) - 4.*cbetao2*(-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2)*s1alpha*pow(sbetao2,7) - 1.*(pow(hIm22,2) + pow(hRe22,2) + pow(hRe2Neg2,2))*pow(sbetao2,8) - 4.*pow(cbetao2,2)*pow(hIm2Neg1,2)*pow(sbetao2,2)*(pow(cbetao2,4) + pow(sbetao2,4)) + 4.*c1alpha*cbetao2*(cbetao2 - 1.*sbetao2)*sbetao2*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2) + pow(cbetao2,2)*(-1.*hIm21*(2.4494897427831781*hIm20 + hIm22) + hIm2Neg1*(2.4494897427831781*hIm20 + hIm2Neg2) - 1.*hRe21*(2.4494897427831781*hRe20 + hRe22) + hRe2Neg1*(2.4494897427831781*hRe20 + hRe2Neg2))*pow(sbetao2,2) + (-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2)*pow(sbetao2,4)) - 1.*pow(hIm2Neg2,2)*(pow(cbetao2,8) + pow(sbetao2,8));
  }
  void df(const std::vector<double>& x, std::vector<double>& dfdx) const {
    const double cbetao2 = cos(x[1]/2.0);
    const double sbetao2 = sin(x[1]/2.0);
    const double c1alpha = cos(x[0]);
    const double s1alpha = sin(x[0]);
    const double c2alpha = c1alpha*c1alpha-s1alpha*s1alpha;
    const double s2alpha = 2*s1alpha*c1alpha;
    const double c3alpha = (4*c1alpha*c1alpha-3)*c1alpha;
    const double s3alpha = s1alpha*(3-4*s1alpha*s1alpha);
    const double c4alpha = c2alpha*c2alpha-s2alpha*s2alpha;
    const double s4alpha = 2*s2alpha*c2alpha;
    dfdx[0] = -4.*cbetao2*sbetao2*(4.*c4alpha*pow(cbetao2,3)*(-1.*hIm2Neg2*hRe22 + hIm22*hRe2Neg2)*pow(sbetao2,3) - 4.*pow(cbetao2,3)*(hIm22*hIm2Neg2 + hRe22*hRe2Neg2)*s4alpha*pow(sbetao2,3) + 3.*c3alpha*pow(cbetao2,2)*(hIm2Neg2*hRe21 - 1.*hIm2Neg1*hRe22 + hIm22*hRe2Neg1 - 1.*hIm21*hRe2Neg2)*(cbetao2 - 1.*sbetao2)*pow(sbetao2,2)*(cbetao2 + sbetao2) + 3.*pow(cbetao2,2)*(-1.*hIm22*hIm2Neg1 + hIm21*hIm2Neg2 - 1.*hRe22*hRe2Neg1 + hRe21*hRe2Neg2)*s3alpha*(cbetao2 - 1.*sbetao2)*pow(sbetao2,2)*(cbetao2 + sbetao2) - 1.*c1alpha*(cbetao2 - 1.*sbetao2)*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2) + pow(cbetao2,2)*(-1.*hIm22*hRe21 + hIm21*(-2.4494897427831781*hRe20 + hRe22) - 1.*hIm2Neg2*hRe2Neg1 + 2.4494897427831781*hIm20*(hRe21 + hRe2Neg1) + hIm2Neg1*(-2.4494897427831781*hRe20 + hRe2Neg2))*pow(sbetao2,2) + (-1.*hIm22*hRe21 + hIm21*hRe22 - 1.*hIm2Neg2*hRe2Neg1 + hIm2Neg1*hRe2Neg2)*pow(sbetao2,4)) + s1alpha*(cbetao2 - 1.*sbetao2)*(cbetao2 + sbetao2)*(pow(cbetao2,4)*(-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2) + pow(cbetao2,2)*(-1.*hIm21*(2.4494897427831781*hIm20 + hIm22) + hIm2Neg1*(2.4494897427831781*hIm20 + hIm2Neg2) - 1.*hRe21*(2.4494897427831781*hRe20 + hRe22) + hRe2Neg1*(2.4494897427831781*hRe20 + hRe2Neg2))*pow(sbetao2,2) + (-1.*hIm21*hIm22 + hIm2Neg1*hIm2Neg2 - 1.*hRe21*hRe22 + hRe2Neg1*hRe2Neg2)*pow(sbetao2,4)) + c2alpha*cbetao2*sbetao2*(2.4494897427831781*pow(cbetao2,4)*((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2)) + 8.*pow(cbetao2,2)*(-1.*hIm2Neg1*hRe21 + hIm21*hRe2Neg1)*pow(sbetao2,2) + 2.4494897427831781*((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2))*pow(sbetao2,4)) + cbetao2*s2alpha*sbetao2*(-2.4494897427831781*pow(cbetao2,4)*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) - 8.*pow(cbetao2,2)*(hIm21*hIm2Neg1 + hRe21*hRe2Neg1)*pow(sbetao2,2) - 2.4494897427831781*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2))*pow(sbetao2,4)));
    dfdx[1] = -2.*(4.*c4alpha*pow(cbetao2,3)*(hIm22*hIm2Neg2 + hRe22*hRe2Neg2)*(cbetao2 - 1.*sbetao2)*pow(sbetao2,3)*(cbetao2 + sbetao2) + 4.*pow(cbetao2,3)*(-1.*hIm2Neg2*hRe22 + hIm22*hRe2Neg2)*s4alpha*(cbetao2 - 1.*sbetao2)*pow(sbetao2,3)*(cbetao2 + sbetao2) - 1.*c3alpha*pow(cbetao2,2)*(-1.*hIm22*hIm2Neg1 + hIm21*hIm2Neg2 - 1.*hRe22*hRe2Neg1 + hRe21*hRe2Neg2)*pow(sbetao2,2)*(3.*pow(cbetao2,4) - 10.*pow(cbetao2,2)*pow(sbetao2,2) + 3.*pow(sbetao2,4)) + pow(cbetao2,2)*(hIm2Neg2*hRe21 - 1.*hIm2Neg1*hRe22 + hIm22*hRe2Neg1 - 1.*hIm21*hRe2Neg2)*s3alpha*pow(sbetao2,2)*(3.*pow(cbetao2,4) - 10.*pow(cbetao2,2)*pow(sbetao2,2) + 3.*pow(sbetao2,4)) + 2.*sbetao2*(-1.*pow(cbetao2,3) + cbetao2*pow(sbetao2,2))*(pow(cbetao2,4)*(-1.*pow(hIm21,2) + pow(hIm22,2) - 1.*pow(hIm2Neg1,2) + pow(hIm2Neg2,2) - 1.*pow(hRe21,2) + pow(hRe22,2) - 1.*pow(hRe2Neg1,2) + pow(hRe2Neg2,2)) + pow(cbetao2,2)*(-6.*pow(hIm20,2) + 2.*pow(hIm21,2) + pow(hIm22,2) + 2.*pow(hIm2Neg1,2) + pow(hIm2Neg2,2) + pow(hRe22,2) + 2.*(-3.*pow(hRe20,2) + pow(hRe21,2) + pow(hRe2Neg1,2)) + pow(hRe2Neg2,2))*pow(sbetao2,2) + (-1.*pow(hIm21,2) + pow(hIm22,2) - 1.*pow(hIm2Neg1,2) + pow(hIm2Neg2,2) - 1.*pow(hRe21,2) + pow(hRe22,2) - 1.*pow(hRe2Neg1,2) + pow(hRe2Neg2,2))*pow(sbetao2,4)) + cbetao2*s2alpha*(cbetao2 - 1.*sbetao2)*sbetao2*(cbetao2 + sbetao2)*(2.4494897427831781*pow(cbetao2,4)*((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2)) - 2.*pow(cbetao2,2)*(2.4494897427831781*(hIm22 - 1.*hIm2Neg2)*hRe20 + 8.*hIm2Neg1*hRe21 - 8.*hIm21*hRe2Neg1 + 2.4494897427831781*hIm20*(-1.*hRe22 + hRe2Neg2))*pow(sbetao2,2) + 2.4494897427831781*((hIm22 - 1.*hIm2Neg2)*hRe20 + hIm20*(-1.*hRe22 + hRe2Neg2))*pow(sbetao2,4)) + c2alpha*cbetao2*(cbetao2 - 1.*sbetao2)*sbetao2*(cbetao2 + sbetao2)*(2.4494897427831781*pow(cbetao2,4)*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2)) - 2.*pow(cbetao2,2)*(-8.*hIm21*hIm2Neg1 + 2.4494897427831781*hIm20*(hIm22 + hIm2Neg2) - 8.*hRe21*hRe2Neg1 + 2.4494897427831781*hRe20*(hRe22 + hRe2Neg2))*pow(sbetao2,2) + 2.4494897427831781*(hIm20*(hIm22 + hIm2Neg2) + hRe20*(hRe22 + hRe2Neg2))*pow(sbetao2,4)) + s1alpha*(pow(cbetao2,8)*(hIm22*hRe21 - 1.*hIm21*hRe22 + hIm2Neg2*hRe2Neg1 - 1.*hIm2Neg1*hRe2Neg2) + pow(cbetao2,6)*(-7.*hIm22*hRe21 + hIm21*(7.34846922834953429*hRe20 + 7.*hRe22) - 7.*hIm2Neg2*hRe2Neg1 - 7.34846922834953429*hIm20*(hRe21 + hRe2Neg1) + hIm2Neg1*(7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,2) + 24.494897427831781*pow(cbetao2,4)*(-1.*(hIm21 + hIm2Neg1)*hRe20 + hIm20*(hRe21 + hRe2Neg1))*pow(sbetao2,4) + pow(cbetao2,2)*(-7.*hIm22*hRe21 + hIm21*(7.34846922834953429*hRe20 + 7.*hRe22) - 7.*hIm2Neg2*hRe2Neg1 - 7.34846922834953429*hIm20*(hRe21 + hRe2Neg1) + hIm2Neg1*(7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,6) + (hIm22*hRe21 - 1.*hIm21*hRe22 + hIm2Neg2*hRe2Neg1 - 1.*hIm2Neg1*hRe2Neg2)*pow(sbetao2,8)) + c1alpha*(pow(cbetao2,8)*(hIm21*hIm22 - 1.*hIm2Neg1*hIm2Neg2 + hRe21*hRe22 - 1.*hRe2Neg1*hRe2Neg2) + pow(cbetao2,6)*(hIm21*(7.34846922834953429*hIm20 - 7.*hIm22) + hIm2Neg1*(-7.34846922834953429*hIm20 + 7.*hIm2Neg2) + hRe21*(7.34846922834953429*hRe20 - 7.*hRe22) + hRe2Neg1*(-7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,2) + 24.494897427831781*pow(cbetao2,4)*(hIm20*(-1.*hIm21 + hIm2Neg1) + hRe20*(-1.*hRe21 + hRe2Neg1))*pow(sbetao2,4) + pow(cbetao2,2)*(hIm21*(7.34846922834953429*hIm20 - 7.*hIm22) + hIm2Neg1*(-7.34846922834953429*hIm20 + 7.*hIm2Neg2) + hRe21*(7.34846922834953429*hRe20 - 7.*hRe22) + hRe2Neg1*(-7.34846922834953429*hRe20 + 7.*hRe2Neg2))*pow(sbetao2,6) + (hIm21*hIm22 - 1.*hIm2Neg1*hIm2Neg2 + hRe21*hRe22 - 1.*hRe2Neg1*hRe2Neg2)*pow(sbetao2,8)));
    return;
  }
}; // class MaximizeMagSum



void WaveformUtilities::RadiationAxis(const Waveform& W, const unsigned int tStep, double& alpha, double& beta) {
  vector<double> AlphaBeta(2, 0.0);
  const double Tolerance = 5.0e-11; // 5e-11 seems to be optimal for this problem
  int Iterations1=0, Iterations2=0;
  double MagSum = 0.0;
  MaximizeMagSum Minimizer(W);
  Minimizer.SetT(tStep);
  try {
    WaveformUtilities::dfpmin(AlphaBeta, Tolerance, Iterations1, MagSum, Minimizer);
  } catch(int) { }
  try {
    WaveformUtilities::dfpmin(AlphaBeta, Tolerance, Iterations2, MagSum, Minimizer);
  } catch(int) { }
  alpha = fmod(AlphaBeta[0], 2*M_PI);
  beta = fmod(AlphaBeta[1], M_PI);
  return;
}

void WaveformUtilities::RadiationAxis(const Waveform& W, vector<double>& alpha, vector<double>& beta,
				      const double alphaGuess, const double betaGuess) {
  alpha.resize(W.NTimes());
  beta.resize(W.NTimes());
  vector<double> AlphaBeta(2, 0.0);
  AlphaBeta[0] = alphaGuess;
  AlphaBeta[1] = betaGuess;
  const double Tolerance = 5.0e-11; // 5e-11 seems to be optimal for this problem
  int Iterations=0, Iterations1=0, Iterations2=0;
  double MagSum = 0.0;
  MaximizeMagSum Minimizer(W);
  for(unsigned int tStep=0; tStep<W.NTimes(); ++tStep) {
    Minimizer.SetT(tStep);
    try {
      WaveformUtilities::dfpmin(AlphaBeta, Tolerance, Iterations1, MagSum, Minimizer);
    } catch(int) { cerr << "Time = " << W.T(tStep) << endl; }
    try {
      WaveformUtilities::dfpmin(AlphaBeta, Tolerance, Iterations2, MagSum, Minimizer);
    } catch(int) { cerr << "Time = " << W.T(tStep) << endl; }
    //cerr << W.T(tStep) << " " << Iterations1+Iterations2 << endl; // Print number of iterations this step
    Iterations += Iterations1+Iterations2;
    Iterations1=0;
    Iterations2=0;
    if(tStep==0) {
      AlphaBeta[0] = fmod(AlphaBeta[0], 2*M_PI);
      AlphaBeta[1] = fmod(AlphaBeta[1], M_PI);
    }
    alpha[tStep] = AlphaBeta[0];
    beta[tStep] = AlphaBeta[1];
  }
  //cerr << "Tolerance=" << Tolerance << "\tAvgIterations=" << Iterations/double(W.NTimes()) << endl;
  return;
}

void WaveformUtilities::RadiationAxis(const Waveform& W, vector<Quaternion>& Q) {
  Q.resize(W.NTimes());
  vector<double> AlphaBeta(2, 0.0);
  vector<double> Axis(3, 0.0);
  const double Tolerance = 5.0e-11; // 5e-11 seems to be optimal for this problem
  int Iterations=0, Iterations1=0, Iterations2=0;
  double MagSum = 0.0;
  MaximizeMagSum Minimizer(W);
  for(unsigned int tStep=0; tStep<W.NTimes(); ++tStep) {
    Minimizer.SetT(tStep);
    try {
      WaveformUtilities::dfpmin(AlphaBeta, Tolerance, Iterations1, MagSum, Minimizer);
    } catch(int) { }
    try {
      WaveformUtilities::dfpmin(AlphaBeta, Tolerance, Iterations2, MagSum, Minimizer);
    } catch(int) { }
    //cerr << W.T(tStep) << " " << Iterations1+Iterations2 << endl; // Print number of iterations this step
    Iterations += Iterations1+Iterations2;
    Iterations1=0;
    Iterations2=0;
    if(tStep==0) {
      AlphaBeta[0] = fmod(AlphaBeta[0], 2*M_PI);
      AlphaBeta[1] = fmod(AlphaBeta[1], M_PI);
    }
    Axis[0] = -sin(AlphaBeta[0]);
    Axis[1] = cos(AlphaBeta[0]);
    Q[tStep] = Quaternion(AlphaBeta[1], Axis);
  }
  //cerr << "Tolerance=" << Tolerance << "\tAvgIterations=" << Iterations/double(W.NTimes()) << endl;
  return;
}

class GammaRHS {
private:
  WaveformUtilities::SplineInterpolator spline;
public:
  GammaRHS(const std::vector<double>& t, const std::vector<double>& gammaDot)
    : spline(t, gammaDot) { }
  void operator() (const double x, const std::vector<double>& y, std::vector<double>& dydx) {
    dydx[0] = spline.interp(x);
    return;
  }
};

void WaveformUtilities::MinimalRotation(const vector<double>& alpha, const vector<double>& beta, vector<double>& gamma, const vector<double>& t) {
  if(alpha.size() != beta.size()) {
    cerr << "\nalpha.size()=" << alpha.size() << "\tbeta.size()=" << beta.size() << endl;
    throw("Size mismatch in MinimalRotation.");
  }
  
  /// This form uses the Euler angles directly
  vector<double> gammaDot = -dydx(alpha, t)*cos(beta);
//   gamma = cumtrapz(t, gammaDot);
//   gamma = -alpha*cos(beta) + cumtrapz(t, dydx(cos(beta), t)*alpha);
  gamma = -alpha*cos(beta) + cumtrapz(t, -sin(beta)*dydx(beta,t)*alpha);
  
//   /// This form uses the quaternions, which might be smoother near
//   /// singularities of the Euler angles.
//   Quaternion Z(0, 0, 0, 1);
//   vector<Quaternion> Q_S = Quaternions(alpha, beta, vector<double>(beta.size(), 0));
//   vector<double> gammaDot = 2*Re( dQdt(Q_S, t) * (Z * Conjugate(Q_S)) );
  
//   /// This integrates gammaDot as naively as possible
//   gamma = cumtrapz(t, gammaDot);
  
//   /// This integrates gammaDot using spline interpolation and ODE integration
//   /// NOTE: This is a lot slower, and hasn't made any difference in basic tests
//   GammaRHS RHS(t, gammaDot);
//   const int nvar=1;
//   const double atol=0.0, rtol=1.0e-10, h1=0.01, hmin=0.0, x1=t[0], x2=t.back();
//   std::vector<double> ystart(nvar);
//   ystart[0]=0.0;
//   WaveformUtilities::Output out(20);
//   WaveformUtilities::Odeint< WaveformUtilities::StepperDopr853<GammaRHS> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,RHS,true);
//   ode.integrate();
//   out.xsave.resize(out.count);
//   out.ysave[0].resize(out.count);
//   gamma = WaveformUtilities::Interpolate(out.xsave, out.ysave[0], t);
  
//   // Check the result
//   vector<Quaternion> Q = Quaternions(alpha, beta, gamma);
//   vector<double> gammaErr = 2*Re( dQdt(Q, t) * (Z * Conjugate(Q)) );
//   cout << "MinimalRotation: avg(|gammaDot|)=" << avg(fabs(gammaErr)) << "  max(|gammaDot|)=" << maxfabs(gammaErr) << endl;
  
  return;
}

void WaveformUtilities::MinimalRotation(const Waveform& W, vector<double>& alpha, vector<double>& beta, vector<double>& gamma,
					const double alphaGuess, const double betaGuess) {
  RadiationAxis(W, alpha, beta, alphaGuess, betaGuess);
  MinimalRotation(alpha, beta, gamma, W.T());
  return;
}

void WaveformUtilities::MinimalRotation(const Waveform& W, vector<Quaternion>& Q) {
  vector<double> alpha(W.NTimes()), beta(W.NTimes());
  RadiationAxis(W, alpha, beta);
  Q.resize(W.NTimes());
  for(unsigned int i=0; i<Q.size(); ++i) {
    Q[i] = Quaternion(cos(beta[i]/2.0), -sin(beta[i]/2.0)*sin(alpha[i]), sin(beta[i]/2.0)*cos(alpha[i]), 0);
  }
  return;
}

inline double SQR(const double x) { return x*x; }
#include <complex>
const complex<double> I(0.0, 1.0);

// vector<double> WaveformUtilities::AngularMomentumVector(const Waveform& W, const unsigned int tIndex) {
//   vector<double> L(3, 0.0);
//   const int ell=2;
//   unsigned int lm=0;
//   for(int m=-ell; m<=ell; ++m) {
//     if(W.L(lm) != ell || W.M(lm) != m) {
//       cerr << "\nlm=" << lm << "\tell=" << ell << "\tm=" << m << "\tW.L(lm)=" << W.L(lm) << "\tW.M(lm)=" << W.M(lm) << endl;
//       throw("Unknown ordering in W.LM()");
//     }
//     unsigned int lmp=0;
//     for(int mp=-ell; mp<=ell; ++mp) {
//       if(W.L(lmp) != ell || W.M(lmp) != mp) {
// 	cerr << "\nlmp=" << lmp << "\tell=" << ell << "\tmp=" << mp << "\tW.L(lmp)=" << W.L(lmp) << "\tW.M(lmp)=" << W.M(lmp) << endl;
// 	throw("Unknown ordering in W.LM()");
//       }
//       complex<double> Lplus =
// 	(m+1==mp
// 	 ? sqrt((ell-m)*(ell+m+1))*W.Mag(lm, tIndex)*exp(I*W.Arg(lm, tIndex))*W.Mag(lmp, tIndex)*exp(-I*W.Arg(lmp, tIndex))
// 	 : complex<double>(0.0, 0.0));
//       complex<double> Lminus =
// 	(m-1==mp
// 	 ? sqrt((ell+m)*(ell-m+1))*W.Mag(lm, tIndex)*exp(I*W.Arg(lm, tIndex))*W.Mag(lmp, tIndex)*exp(-I*W.Arg(lmp, tIndex))
// 	 : complex<double>(0.0, 0.0));
//       L[0] += real(0.5*(Lplus + Lminus));
//       L[1] += real(0.5*(Lplus - Lminus)/I);
//       lmp++;
//     }
//     L[2] += SQR(m*W.Mag(lm, tIndex));
//     lm++;
//   }
//   return L/WaveformUtilities::norm(L);
// }

void WaveformUtilities::AngularMomentumVector(const Waveform& W, vector<vector<double> >& l) {
  l.resize(W.NTimes(), vector<double>(3, 0.0));
  for(unsigned int tIndex=0; tIndex<W.NTimes(); ++tIndex) {
    cerr << "\nt=" << W.T(tIndex) << endl;
    vector<complex<double> > L(3, 0.0);
    const int ell=2;
    unsigned int lm=0;
    for(int m=-ell; m<=ell; ++m) {
      cerr << "\tm=" << m << endl;
      if(W.L(lm) != ell || W.M(lm) != m) {
	cerr << "\nlm=" << lm << "\tell=" << ell << "\tm=" << m << "\tW.L(lm)=" << W.L(lm) << "\tW.M(lm)=" << W.M(lm) << endl;
	throw("Unknown ordering in W.LM()");
      }
      unsigned int lmp=0;
      for(int mp=-ell; mp<=ell; ++mp) {
	if(W.L(lmp) != ell || W.M(lmp) != mp) {
	  cerr << "\nlmp=" << lmp << "\tell=" << ell << "\tmp=" << mp << "\tW.L(lmp)=" << W.L(lmp) << "\tW.M(lmp)=" << W.M(lmp) << endl;
	  throw("Unknown ordering in W.LM()");
	}
	complex<double> Lplus =
	  (m+1==mp
  	   ? sqrt((ell-m)*(ell+m+1))*W.Mag(lm, tIndex)*exp(I*W.Arg(lm, tIndex))*W.Mag(lmp, tIndex)*exp(I*W.Arg(lmp, tIndex))
	   : complex<double>(0.0, 0.0));
	complex<double> Lminus =
	  (m-1==mp
  	   ? sqrt((ell+m)*(ell-m+1))*W.Mag(lm, tIndex)*exp(I*W.Arg(lm, tIndex))*W.Mag(lmp, tIndex)*exp(I*W.Arg(lmp, tIndex))
	   : complex<double>(0.0, 0.0));
	L[0] += (0.5*(Lplus + Lminus));
	L[1] += (0.5*(Lplus - Lminus)/I);
	cerr << "\t\tmp=" << mp << "\tLplus=" << Lplus << "\tLminus=" << Lminus << endl;
	lmp++;
      }
      cerr << "\t\tLz=" << m*SQR(W.Mag(lm, tIndex)) << endl;
      L[2] += m*SQR(W.Mag(lm, tIndex));
      lm++;
    }
    //cerr << W.T(tIndex) << ": " << L[0] << ", " << L[1] << ", " << L[2] << endl;
    l[tIndex][0] = real(L[0]);
    l[tIndex][1] = real(L[1]);
    l[tIndex][2] = real(L[2]);
    //l[tIndex] = l[tIndex]/WaveformUtilities::norm(l[tIndex]);
  }
  return;
}
