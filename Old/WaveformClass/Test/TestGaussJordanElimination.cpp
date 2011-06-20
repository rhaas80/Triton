#include "GaussJordanElimination.hpp"
#include "VectorFunctions.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
  vector<complex<double> > Garbage(3);
  Garbage[0] = complex<double>(-1, 1);
  Garbage[1] = complex<double>(2,0);
  Garbage[2] = complex<double>(3,0);
  vector<vector<complex<double> > > A(3, vector<complex<double> >(3));
  vector<vector<complex<double> > > B(A.size(), vector<complex<double> >(1,complex<double>(1.0, 2.0)));
  for(unsigned int i=0; i<A.size(); ++i) {
    for(unsigned int j=0; j<A[i].size(); ++j) {
      A[i][j] = complex<double>(2+i+j,0)+Garbage[i];
    }
  }
  A[0][1] = complex<double>(3,0);
  for(unsigned int i=0; i<A.size(); ++i) {
    for(unsigned int j=0; j<A[i].size(); ++j) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for(unsigned int i=0; i<B.size(); ++i) {
    for(unsigned int j=0; j<B[i].size(); ++j) {
      cout << B[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  vector<vector<complex<double> > > Aoriginal(A);
  vector<vector<complex<double> > > Boriginal(B);
  GaussJordanElimination(A, B);
  for(unsigned int i=0; i<B.size(); ++i) {
    for(unsigned int j=0; j<B[i].size(); ++j) {
      cout << setprecision(16) << real(B[i][j]) << "+I*" << imag(B[i][j]);
    }
    if(i<B.size()-1) { cout << ", " << flush; } else { cout << endl; }
  }
  cout << endl;
  for(unsigned int i=0; i<A.size(); ++i) {
    complex<double> Sum(0.0,0.0);
    for(unsigned int j=0; j<A[i].size(); ++j) {
      Sum += Aoriginal[i][j]*B[j][0];
    }
    cout << setprecision(17) << Sum - Boriginal[i][0] << endl;
  }
  cout << endl;
  return 0;
}

// int main() {
//   vector<double> Garbage(3);
//   Garbage[0] = -1;
//   Garbage[1] = 2;
//   Garbage[2] = 3;
//   vector<vector<double> > A(3, vector<double>(3, 0.0));
//   vector<vector<double> > B(A.size(), vector<double>(1,1.0));
//   for(unsigned int i=0; i<A.size(); ++i) {
//     for(unsigned int j=0; j<A[i].size(); ++j) {
//       A[i][j] = 2+i+j+Garbage[i];
//       cout << A[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
//   for(unsigned int i=0; i<B.size(); ++i) {
//     for(unsigned int j=0; j<B[i].size(); ++j) {
//       cout << B[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
//   vector<vector<double> > Aoriginal(A);
//   vector<vector<double> > Boriginal(B);
//   GaussJordanElimination(A, B);
//   for(unsigned int i=0; i<B.size(); ++i) {
//     for(unsigned int j=0; j<B[i].size(); ++j) {
//       cout << B[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
//   for(unsigned int i=0; i<A.size(); ++i) {
//     double Sum = 0.0;
//     for(unsigned int j=0; j<A[i].size(); ++j) {
//       Sum += Aoriginal[i][j]*B[j][0];
//     }
//     cout << setprecision(17) << Sum - Boriginal[i][0] << endl;
//   }
//   cout << endl;
//   return 0;
// }
