#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

#include "../Waveform.hpp"

#include "Interpolate.hpp"
#include "Minimize.hpp"
#include "FileIO.hpp"
#include "SWSHs.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Units.hpp"
#include "PostNewtonian.hpp"
#include "Quaternions.hpp"
#include "Minimize_MultiDim.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::setprecision;
using std::stringstream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::min;
using std::max;
using std::ios_base;



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



void RadiationAxis(const Waveform& W, std::vector<double>& alpha, std::vector<double>& beta,
		   const double alphaGuess=0.0, const double betaGuess=0.0) {
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

/// Alter gamma to enforce the minimal-rotation condition.
void MinimalRotation(const std::vector<double>& alpha, const std::vector<double>& beta, std::vector<double>& gamma, const std::vector<double>& t) {
  if(alpha.size() != beta.size() || alpha.size() != t.size()) {
    cerr << "\nalpha.size()=" << alpha.size() << "\tbeta.size()=" << beta.size() << "\tt.size()=" << t.size() << endl;
    throw("Size mismatch in MinimalRotation.");
  }
  
  vector<double> gammaDot = -dydx(alpha, t)*cos(beta);
  gamma = -alpha*cos(beta) + cumtrapz(t, -sin(beta)*dydx(beta,t)*alpha);
  
  return;
}

/// Given the radiation axis, return the frame which minimizes rotation.
std::vector<WaveformUtilities::Quaternion> MinimalRotation(const std::vector<double>& alpha, const std::vector<double>& beta,
							   const std::vector<double>& t, const unsigned int NIterations=5) {
  if(alpha.size() != beta.size() || alpha.size() != t.size()) {
    cerr << "\nalpha.size()=" << alpha.size() << "\tbeta.size()=" << beta.size() << "\tt.size()=" << t.size() << endl;
    throw("Size mismatch in MinimalRotation.");
  }
  
  // Find the minimal-rotation frame using the Euler-angle method
  vector<double> gammaDot = -dydx(alpha, t)*cos(beta);
  vector<double> gamma = -alpha*cos(beta) + cumtrapz(t, -sin(beta)*dydx(beta,t)*alpha);
  vector<WaveformUtilities::Quaternion> MinRotFrame = WaveformUtilities::Quaternions(alpha, beta, gamma);
  
  // Now use that frame with the quaternion method for better numerics
  const Quaternion z(0.,0.,0.,1.);
  for(unsigned int iteration=0; iteration<NIterations; ++iteration) {
    // Note that Component0 gives -1 times the dot product of two vectors 
    const vector<double> negativegammaover2 = SplineIntegral(t, Component0( conjugate(MinRotFrame) * CenteredDifferencing(MinRotFrame, t) * z ));
    for(unsigned int i=0; i<negativegammaover2.size(); ++i) {
      MinRotFrame[i] = MinRotFrame[i] * (negativegammaover2[i]*z).exp();
    }
    string FileName = "MinRotPhaseConvergence_" + DoubleToString(iteration+1) + "of" + DoubleToString(NIterations) + ".dat";
    ofstream File(FileName.c_str());
    File << "# [1] = t\n# [2] = gamma\n";
    for(unsigned int i=0; i<negativegammaover2.size(); ++i) {
      File << t[i] << " " << -2*negativegammaover2[i] << endl;
    }
    File.close();
  }
  
  // gammaDot = 2*Component0( SquadVelocities(t, MinRotFrame) * z * Conjugate(MinRotFrame) );
  // gamma = SplineIntegral(t, gammaDot);
  // cerr << "The correction to gamma is:\n" << gamma << endl;
  // for(unsigned int i=0; i<gamma.size(); ++i) {
  //   MinRotFrame[i] = MinRotFrame[i] * (gamma[i]*z).exp();
  // }
  // gammaDot = 2*Component0( SquadVelocities(t, MinRotFrame) * z * Conjugate(MinRotFrame) );
  // gamma = SplineIntegral(t, gammaDot);
  // cerr << "\n\n\n\n\n\n\nThe second correction to gamma is:\n" << gamma << endl;
  // for(unsigned int i=0; i<gamma.size(); ++i) {
  //   MinRotFrame[i] = MinRotFrame[i] * (gamma[i]*z).exp();
  // }
  // gammaDot = 2*Component0( SquadVelocities(t, MinRotFrame) * z * Conjugate(MinRotFrame) );
  // gamma = SplineIntegral(t, gammaDot);
  // cerr << "\n\n\n\n\n\n\nThe third correction to gamma is:\n" << gamma << endl;
  // for(unsigned int i=0; i<gamma.size(); ++i) {
  //   MinRotFrame[i] = MinRotFrame[i] * (gamma[i]*z).exp();
  // }
  // gammaDot = 2*Component0( SquadVelocities(t, MinRotFrame) * z * Conjugate(MinRotFrame) );
  // gamma = SplineIntegral(t, gammaDot);
  // cerr << "\n\n\n\n\n\n\nThe fourth correction to gamma is:\n" << gamma << endl;
  // for(unsigned int i=0; i<gamma.size(); ++i) {
  //   MinRotFrame[i] = MinRotFrame[i] * (gamma[i]*z).exp();
  // }
  // gammaDot = 2*Component0( SquadVelocities(t, MinRotFrame) * z * Conjugate(MinRotFrame) );
  // gamma = SplineIntegral(t, gammaDot);
  // cerr << "\n\n\n\n\n\n\nThe fifth correction to gamma is:\n" << gamma << endl;
  // for(unsigned int i=0; i<gamma.size(); ++i) {
  //   MinRotFrame[i] = MinRotFrame[i] * (gamma[i]*z).exp();
  // }
  
  return MinRotFrame;
}


/// Transform the Waveform to the naive radiation frame.
Waveform& WaveformObjects::Waveform::TransformToSchmidtFrame(const double alpha0Guess, const double beta0Guess) {
  /// This function finds the radiation axis, then rotates the
  /// coordinates in which the physical system is expressed (by
  /// calling RotateCoordinates) to align with that frame.  Note that
  /// the rotation in this case always has the third Euler angle
  /// (gamma) set to 0.
  /// 
  /// We define the Euler angles (alpha, beta, gamma) using the
  /// z-y'-z'' convention, where the first rotation is through an
  /// angle alpha about the z axis, the second through beta about the
  /// (new) y' axis, and the third through gamma about the (new) z''
  /// axis.  Note that this is equivalent to rotations in the opposite
  /// order about the fixed set of axes z-y-z.
  /// 
  /// See PRD 84, 124011 (2011) for more details.
  history << "### this->TransformToSchmidtFrame(" << alpha0Guess << ", " << beta0Guess << ");" << endl;
  vector<double> alpha(NTimes(), 0.0), beta(NTimes(), 0.0), gamma(NTimes(), 0.0);
  RadiationAxis(*this, alpha, beta, alpha0Guess, beta0Guess);
  gamma = vector<double>(NTimes(), 0.0);
  return this->RotateCoordinates(alpha, beta, gamma);
}

/// Transform the Waveform to the minimal-rotation radiation frame.
Waveform& WaveformObjects::Waveform::TransformToMinimalRotationFrame(const double alpha0Guess, const double beta0Guess, const unsigned int NIterations) {
  /// This function finds the minimal-rotation radiation axis, then
  /// rotates the coordinates in which the physical system is
  /// expressed (by calling RotateCoordinates) to align with that
  /// frame.
  /// 
  /// We define the Euler angles (alpha, beta, gamma) using the
  /// z-y'-z'' convention, where the first rotation is through an
  /// angle alpha about the z axis, the second through beta about the
  /// (new) y' axis, and the third through gamma about the (new) z''
  /// axis.  Note that this is equivalent to rotations in the opposite
  /// order about the fixed set of axes z-y-z.
  /// 
  /// See PRD 84, 124011 (2011) for more details.
  history << "### this->TransformToMinimalRotationFrame(" << alpha0Guess << ", " << beta0Guess << ", " << NIterations << ");" << endl;
  vector<double> alpha(NTimes(), 0.0), beta(NTimes(), 0.0), gamma(NTimes(), 0.0);
  RadiationAxis(*this, alpha, beta, alpha0Guess, beta0Guess);
  // MinimalRotation(alpha, beta, gamma, T());
  // this->RotateCoordinates(alpha, beta, gamma);
  vector<Quaternion> MinRotFrame = MinimalRotation(alpha, beta, T(), NIterations);
  this->RotateCoordinates(MinRotFrame);
  return *this;
}

/// Transform the Waveform back to the original frame.
Waveform& WaveformObjects::Waveform::TransformToStandardFrame() {
  /// Simply reverses the total rotation given to the Waveform up to
  /// this point.  Assuming all such rotations have been correctly
  /// recorded in the Waveform object (which should not require any
  /// user intervention), this should return the Waveform as
  /// originally measured in the simulation code's frame, modulo any
  /// time-regridding, rescaling, etc.
  this->RotateCoordinates(this->Frame());
  return *this;
}

/// Transform the Waveform back to a stationary frame.
Waveform& WaveformObjects::Waveform::TransformToStationaryFrame(const WaveformUtilities::Quaternion Q) {
  /// The input quaternion may be used to specify the orientation of
  /// the final frame relative to the frame in which the Waveform was
  /// originally measured.  Compare `TransformToStandardFrame()`.
  this->RotateCoordinates(Q.conjugate()*(this->Frame()));
  return *this;
}
