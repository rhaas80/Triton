#include <iostream>
#include "VectorFunctions.hpp"
#include "Quaternions.hpp"
#include "Utilities.hpp"

using namespace std;
using WaveformUtilities::Quaternion;
using WaveformUtilities::Squad;

int main() {
  vector<double> x(3,0.0), y(3,0.0), z(3,0.0);
  x[0] = 1.;
  y[1] = 1.;
  z[2] = 1.;

  Quaternion a(M_PI/2., x);
  Quaternion b(M_PI/2., y);
  Quaternion c(M_PI/2., z);
  // cout << "a: " << a << endl;
  // cout << "b: " << b << endl;
  // cout << "c: " << c << endl;
  // cout << "a*x*abar" << a * x * a.inverse() << endl;
  // cout << "b*x*bbar" << b * x * b.inverse() << endl;
  // cout << "c*x*cbar" << c * x * c.inverse() << endl;
  // cout << "a*y*abar" << a * y * a.inverse() << endl;
  // cout << "b*y*bbar" << b * y * b.inverse() << endl;
  // cout << "c*y*cbar" << c * y * c.inverse() << endl;
  // cout << "a*z*abar" << a * z * a.inverse() << endl;
  // cout << "b*z*bbar" << b * z * b.inverse() << endl;
  // cout << "c*z*cbar" << c * z * c.inverse() << endl;

  vector<Quaternion> qIn(5);
  qIn[0] = Quaternion(0., x).normalized();
  qIn[1] = Quaternion(M_PI/2., x).normalized();
  qIn[2] = Quaternion(M_PI/2., x+y).normalized();
  qIn[3] = Quaternion(M_PI/2., y).normalized();
  qIn[4] = Quaternion(8*M_PI/20., x+y).normalized();
  vector<double> tIn(5);
  tIn[0] = -10.0;
  tIn[1] = 5.0;
  tIn[2] = 10.0;
  tIn[3] = 15.0;
  tIn[4] = 20.0;
  const unsigned int NSteps = 40;
  vector<double> tOut(NSteps);
  for(unsigned int i=0; i<NSteps; ++i) {
    tOut[i] = tIn[0] + i*(tIn.back()-tIn[0])/(NSteps-1.0);
  }
  vector<Quaternion> qOut(Squad(qIn, tIn, tOut));

  for(unsigned int i=0; i<5; ++i) {
    vector<double> vec = (qIn[i]*Quaternion(z)*qIn[i].inverse()).vec();
    cout << tIn[i] << " " << vec[0] << " " << vec[1] << " " << vec[2] << endl;
  }
  for(unsigned int i=0; i<NSteps; ++i) {
    vector<double> vec = (qOut[i]*Quaternion(z)*qOut[i].inverse()).vec();
    cout << tOut[i] << " " << vec[0] << " " << vec[1] << " " << vec[2] << endl;
  }

  return 0;
}
