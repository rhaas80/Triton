#include "Minimize_MultiDim.hpp"
#include "VectorFunctions.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using WaveformUtilities::dfpmin;
using WaveformUtilities::Funcd;

const double func_Offset = 0.036668902468014292876;
const double func_Min =    1.057801324517890132876;

class Functor {
public:
  Functor() { }
  double operator() (const vector<double>& x) const {
    return func_Offset + 1.0234589e4*pow((x[0]-func_Min), 4) + 3.789e2*pow((x[0]-func_Min), 2) + (1-cos(0.09243*(x[0]-func_Min))) + (x[1]*x[1]);
  }
  void df(const vector<double>& x, vector<double>& dfdx) const {
    dfdx[0] = 1.0234589e4*4*pow((x[0]-func_Min), 3) + 3.789e2*2*(x[0]-func_Min) + 0.09243*sin(0.09243*(x[0]-func_Min));
    dfdx[1] = 2*x[1];
    return;
  }
};

double func(const vector<double>& x) {
  return func_Offset + 1.0234589e4*pow((x[0]-func_Min), 4) + 3.789e2*pow((x[0]-func_Min), 2) + (1-cos(0.09243*(x[0]-func_Min))) + 1e10*(x[1]*x[1]);
}
typedef double (DoubleFunction)(const vector<double>& x);

int main() {
  const unsigned int Prec = 18;
  const double Tolerance = 2.0e-15;
  vector<double> Func_Min(2, func_Min);
  Func_Min[1]=0.0;
  int Iterations=0;
  double fret;

  Functor f;
//   Funcd<DoubleFunction> f(func);
  vector<double> p(2,-1.02349812);
  dfpmin(p, Tolerance, Iterations, fret, f);

  cout << "Exact:" << endl;
  cout << "xmin=" << setprecision(Prec) << Func_Min << "\tfmin=" << setprecision(Prec) << func_Offset << endl;
  cout << "Numerical:" << endl;
  cout << "xmin=" << setprecision(Prec) << p << "\tfmin=" << setprecision(Prec) << fret << endl;
  cout << "Iterations=" << Iterations << endl;
  return 0;
}
