#include "NumericalRecipes.hpp"
#include "ODEIntegrator.hpp"
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

class DampedHarmonicOscillator {
private:
  double Mass;
  double SpringCoefficient;
  double DampingCoefficient;
  double Initialy;
  double Initialv;
public:
  DampedHarmonicOscillator(const double M, const double SpringCoeff, const double DampingCoeff, const double y0, const double v0)
    : Mass(M), SpringCoefficient(SpringCoeff), DampingCoefficient(DampingCoeff), Initialy(y0), Initialv(v0) { }
  void operator() (const double x, const std::vector<double>& y, std::vector<double>& dydx) {
    dydx[0]=y[1];
    dydx[1]=(-DampingCoefficient*y[1]-SpringCoefficient*y[0])/Mass;
  }
  double y(const double t) const {
    return (Initialy*sqrt(-pow(DampingCoefficient,2) + 4*Mass*SpringCoefficient)*cos((sqrt(-pow(DampingCoefficient,2) + 4*Mass*SpringCoefficient)*t)/(2.*Mass)) +
     (DampingCoefficient*Initialy + 2*Initialv*Mass)*sin((sqrt(-pow(DampingCoefficient,2) + 4*Mass*SpringCoefficient)*t)/(2.*Mass)))/(exp((DampingCoefficient*t)/(2.*Mass))*sqrt(-pow(DampingCoefficient,2) + 4*Mass*SpringCoefficient));
  }
  double amplitude(const double t) const {
    return Initialy*exp(-DampingCoefficient*t);
  }
};

int main() {

  vector<double> t1, t2;

  {
  const int nvar=2;
  const double atol=0.0, rtol=1.0e-13, h1=0.01, hmin=0.0, x1=0.0, x2=2000.0;
  std::vector<double> ystart(nvar);
  ystart[0]=2.0;
  ystart[1]=0.0;
  WU::Output out(20);
  DampedHarmonicOscillator d(1, 1, 0.05, ystart[0], ystart[1]);
  //WU::Odeint< WU::StepperDopr853<DampedHarmonicOscillator> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d,true);
  WU::Odeint< WU::StepperBS<DampedHarmonicOscillator> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d,true);
  ode.integrate();
  cout << out.count << endl;

//   cout << "# [1] = t"
//        << "\n# [2] = y"
//        << "\n# [3] = v"
//        << "\n# [4] = Exacty"
//        << "\n# [5] = AbsoluteErrory"
//        << "\n# [6] = RelativeErrory" << endl;
//   for (int i=0;i<out.count;i++) {
//     const double T = out.xsave[i];
//     const double y = out.ysave[0][i];
//     const double v = out.ysave[1][i];
//     const double Exacty = d.y(T);
//     const double Errory = y-Exacty;
//     const double amp = d.amplitude(T);
//     cout << T << " " << y << " " << v << " " << Exacty << " " << Errory << " " << Errory/amp << endl;
//   }

  t1.swap(out.xsave);
  t1.resize(out.count);
  }


  {
  const int nvar=2;
  const double atol=0.0, rtol=1.0e-13, h1=0.01, hmin=0.0, x1=0.0, x2=2000.0;
  std::vector<double> ystart(nvar);
  ystart[0]=2.0;
  ystart[1]=0.0;
  WU::Output out(20);
  DampedHarmonicOscillator d(1, 1, 0.05, ystart[0], ystart[1]);
  //WU::Odeint< WU::StepperDopr853<DampedHarmonicOscillator> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d,true);
  WU::Odeint< WU::StepperBS<DampedHarmonicOscillator> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d,true);
  ode.integrate();
  cout << out.count << endl;

//   cout << "# [1] = t"
//        << "\n# [2] = y"
//        << "\n# [3] = v"
//        << "\n# [4] = Exacty"
//        << "\n# [5] = AbsoluteErrory"
//        << "\n# [6] = RelativeErrory" << endl;
//   for (int i=0;i<out.count;i++) {
//     const double T = out.xsave[i];
//     const double y = out.ysave[0][i];
//     const double v = out.ysave[1][i];
//     const double Exacty = d.y(T);
//     const double Errory = y-Exacty;
//     const double amp = d.amplitude(T);
//     cout << T << " " << y << " " << v << " " << Exacty << " " << Errory << " " << Errory/amp << endl;
//   }
  t2.swap(out.xsave);
  t2.resize(out.count);
  }

  cout << "t1==t2 = " << (t1==t2) << "\ttrue=" << true << endl;

  return 0;
}
