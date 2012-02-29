#include <iostream>
#include "VectorFunctions.hpp"
#include "QuaternionInterpolation.hpp"
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
  // cout << "a*x*abar" << a * x * a.Inverse() << endl;
  // cout << "b*x*bbar" << b * x * b.Inverse() << endl;
  // cout << "c*x*cbar" << c * x * c.Inverse() << endl;
  // cout << "a*y*abar" << a * y * a.Inverse() << endl;
  // cout << "b*y*bbar" << b * y * b.Inverse() << endl;
  // cout << "c*y*cbar" << c * y * c.Inverse() << endl;
  // cout << "a*z*abar" << a * z * a.Inverse() << endl;
  // cout << "b*z*bbar" << b * z * b.Inverse() << endl;
  // cout << "c*z*cbar" << c * z * c.Inverse() << endl;
  
  vector<Quaternion> qIn(5);
  qIn[0] = Quaternion(0., x).Normalized();
  qIn[1] = Quaternion(M_PI/2., x).Normalized();
  qIn[2] = Quaternion(M_PI/2., x+y).Normalized();
  qIn[3] = Quaternion(M_PI/2., y).Normalized();
  qIn[4] = Quaternion(8*M_PI/20., x+y).Normalized();
  vector<double> tIn(5);
  tIn[0] = 0.0;
  tIn[1] = 5.0;
  tIn[2] = 10.0;
  tIn[3] = 15.0;
  tIn[4] = 20.0;
  const unsigned int NSteps = 40;
  vector<double> tOut(NSteps);
  for(unsigned int i=0; i<NSteps; ++i) {
    tOut[i] = i*(tIn.back()-tIn[0])/(NSteps-1.0);
  }
  vector<Quaternion> qOut(Squad(tIn, qIn, tOut));
  
  for(unsigned int i=0; i<NSteps; ++i) {
    vector<double> vec = (qOut[i]*z*qOut[i].Inverse()).Vec();
    cout << tOut[i] << " " << vec[0] << " " << vec[1] << " " << vec[2] << endl;
  }
  
  return 0;
}
