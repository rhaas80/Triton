#include "ODEIntegrator.hpp"
#include "VectorFunctions.hpp"
using namespace std;

#define throw(message) \
{printf("ERROR: %s\n     in file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

/// y0' = y1;
/// y1' = ((1-y0^2)*y1-y0)/eps;
/// J00 = dy0/dy0 = 0
/// J01 = dy0/dy1 = 1
/// J10 = dy1/dy0 = (-2*y0*y1-1)/eps
/// J11 = dy1/dy1 = (1-y0^2)/eps
class rhs_van {
private:
  double eps;
public:
  rhs_van(double epss) : eps(epss) {}
  void jacobian(const double& x, const std::vector<double>& y, std::vector<double>& dydx, std::vector<std::vector<double> >& dydy) {
    dydx[0]= y[1];
    dydx[1]=((1.0-y[0]*y[0])*y[1]-y[0])/eps;
    dydy[0][0] = 0;
    dydy[0][1] = 1;
    dydy[1][0] = (-2*y[0]*y[1]-1)/eps;
    dydy[1][1] = (1-y[0]*y[0])/eps;
    return;
  }
  void operator() (const double x, const std::vector<double>& y, std::vector<double>& dydx) {
    //cout << x << "\n" << y << "\n" << dydx << "\n\n";
    dydx[0]= y[1];
    dydx[1]=((1.0-y[0]*y[0])*y[1]-y[0])/eps;
  }
};

class rhs_kiwi {
private:
  double eps;
public:
  rhs_kiwi(double epss) : eps(epss) {}
  void operator() (const double x, const std::vector<double>& y, std::vector<double>& dydx) {
    //cout << x << "\n" << y << "\n" << dydx << "\n\n";
    dydx[0]=x;
    dydx[1]=M_PI*y[0]*y[0];
  }
};

int main() {
  
  const int nvar=2;
  const double atol=1.0e-5, rtol=1.0e-8, h1=0.01, hmin=0.0, x1=0.0, x2=2.0;
  std::vector<double> ystart(nvar);
  ystart[0]=2.0;
  ystart[1]=0.0;
  Output out(20);
  rhs_van d(1.0e-3);
  //Odeint< ::StepperDopr853<rhs_kiwi> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d, true);
  //Odeint< ::StepperBS<rhs_kiwi> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d, true);
  Odeint< ::StepperRoss<rhs_van> > ode(ystart,x1,x2,atol,rtol,h1,hmin,out,d, true);
  ode.integrate();
  
  for (int i=0;i<out.count;i++)
    cout << out.xsave[i] << " " << out.ysave[0][i] << " " << out.ysave[1][i] << endl;
  
  return 0;
}
