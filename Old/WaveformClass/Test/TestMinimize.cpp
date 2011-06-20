#include "Minimize.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

class Function {
private:
  double Center;
  double Min;
public:
  unsigned int Calls;
  Function(const double C, const double M) : Center(C), Min(M), Calls(0) { }
  double operator()(const double a) { Calls++; return (a-Center)*(a-Center)+Min; };
};

int main () {
  Function g(10.313431689322341893021828, 73.8663);
  Brent brent;
  brent.bracket(-20.3, 78.6, g);
  cout << g.Calls << " function calls in bracket." << endl;
  g.Calls=0;
  double xmin = brent.minimize(g);
  cout << g.Calls << " function calls in minimize." << endl;
  cout << setprecision(16) << "xmin=" << xmin << " g(xmin)=" << g(xmin) << endl;
  return 0;
}
