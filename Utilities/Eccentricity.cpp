#include "NumericalRecipes.hpp"

#include "VectorFunctions.hpp"
#include "Fit.hpp"
#include "Eccentricity.hpp"

class Eccentricity_rDotFit {
public:
  Eccentricity_rDotFit() { }
  void operator()(const Doub x, VecDoub_I &a, Doub &y, VecDoub_O &dyda) const {
    //// Model: y(x) =  a0 + a1*x + a2*cos(a3*x+a4);
    y = a[0] + a[1]*x + a[2]*cos(a[3]*x+a[4]);
    dyda[0] = 1.0;
    dyda[1] = x;
    dyda[2] = cos(a[3]*x+a[4]);
    dyda[3] = -a[2]*sin(a[3]*x+a[4])*x;
    dyda[4] = -a[2]*sin(a[3]*x+a[4]);
    return;
  }
};

class Eccentricity_rDotDotFit {
public:
  Eccentricity_rDotDotFit() { }
  void operator()(const double x, const std::vector<double> &a, double &y, std::vector<double> &dyda) const {
    //// Model: y(x) =  -a0*sin(a1*x+a2);
    y = -a[0]*sin(a[1]*x+a[2]);
    dyda[0] = -sin(a[1]*x+a[2]);
    dyda[1] = -a[0]*cos(a[1]*x+a[2])*x;
    dyda[2] = -a[0]*cos(a[1]*x+a[2]);
    return;
  }
};


double WaveformUtilities::Eccentricity_rDot(const std::vector<double>& t, const std::vector<double>& rDot,
					    const double r0, const double Omega0, double& DeltarDot, double& DeltaPhiDot) {
  //// Do the fit to the model:
  ////   rDot(t) = vbar0 + arbar0*t + Br*cos(omegar*t+phir)
  
  //// First fit to rDotDot to find phase, frequency, and amplitude
  std::vector<double> rDotDot = dydx(rDot, t);
  std::vector<double> aDotDotGuesses(3);
  aDotDotGuesses[0] = 0.5*(max(rDotDot)-min(rDotDot));
  aDotDotGuesses[1] = Omega0;
  aDotDotGuesses[2] = 0.0;
  std::vector<double> rDotDotMinusAvg = rDotDot-avg(rDotDot);
  std::vector<double> TrivialSigmas(t.size(), 1.0);
  Eccentricity_rDotDotFit e_dd;
  FitNonlinear<Eccentricity_rDotDotFit> rDotDotFit(t, rDotDotMinusAvg, TrivialSigmas, aDotDotGuesses, e_dd, 1.e-8);
  rDotDotFit.hold(0, aDotDotGuesses[0]);
  rDotDotFit.hold(1, aDotDotGuesses[1]);
  rDotDotFit.fit();
  rDotDotFit.free(1);
  rDotDotFit.fit();
  rDotDotFit.free(0);
  rDotDotFit.fit();
  
  //// Next fit to rDot to find all parameters
  std::vector<double> aDotGuesses(5);
  aDotGuesses[0] = avg(rDot);
  aDotGuesses[1] = avg(rDotDot);
  aDotGuesses[2] = rDotDotFit.a[0] / rDotDotFit.a[1];
  aDotGuesses[3] = rDotDotFit.a[1];
  aDotGuesses[4] = rDotDotFit.a[2];
  Eccentricity_rDotFit e_d;
  FitNonlinear<Eccentricity_rDotFit> rDotFit(t, rDot, TrivialSigmas, aDotGuesses, e_d, 1.e-8);
  rDotFit.fit();
  
  //// Adjust the parameters
  //double& vbar0 = rDotFit.a[0];
  //double& arbar0 = rDotFit.a[1];
  double& Br = rDotFit.a[2];
  double& omegar = rDotFit.a[3];
  double& phir = rDotFit.a[4];
  DeltarDot = -Br * cos(phir); // Eq. (71) of arXiv:1012.1549
  DeltaPhiDot = Br * omegar * sin(phir) / (2* r0 * Omega0);  // Eq. (73) of arXiv:1012.1549
  
  //// Return the measured eccentricity
  return -Br / (r0 * omegar);
}
