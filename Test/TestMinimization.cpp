#include "Minimize.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using WaveformUtilities::Brent;

const double func_Offset = 0.036668902468014292876;
const double func_Min =    1.057801324517890132876;

double func(const double x) {
  return func_Offset + 1.0234589e40*pow((x-func_Min), 4) + 3.789e20*pow((x-func_Min), 2) + (1-cos(0.09243*(x-func_Min)));
}

int main() {
  const unsigned int Prec = 18;
  const double Tolerance = 2.0e-15;
  const double a = 1;
  const double b = 10;
  Brent Minimizer(Tolerance); // Tolerance is 3.0e-8 by default
  Minimizer.bracket(a, b, func); // a and b are known limits; func is the functor
  const double xmin = Minimizer.minimize(func); // xmin is the location of the minimum
  cout << "Exact:" << endl;
  cout << "xmin=" << setprecision(Prec) << func_Min << "\tfmin=" << setprecision(Prec) << func_Offset << endl;
  cout << "Numerical:" << endl;
  cout << "xmin=" << setprecision(Prec) << xmin << "\tfmin=" << setprecision(Prec) << func(xmin) << endl;
  return 0;
}
