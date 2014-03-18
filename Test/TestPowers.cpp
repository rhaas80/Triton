#include <cmath>
#include <ctime>
#include <iostream>
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::pow;
using namespace WaveformUtilities;

int main() {
  clock_t start,end;

  const unsigned int N=(1 << 25);
  vector<double> x(N);
  for(unsigned int i=0; i<N; ++i) {
    x[i] = -M_E + 1013.0*M_PI*i/double(N-1);
  }
  vector<double> y(N);

  cout << "sizeof(double) = " << sizeof(double) << endl;

  cout << N << " uses of pow ... " << endl;
  start = clock();
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],2);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],3);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],4);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],5);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],6);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],7);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],8);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],9);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = pow(x[i],10);
    //z = y;
  }
  end = clock();
  cout << "... took " << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;

  cout << N << " uses of my functions ... " << endl;
  start = clock();
  for(unsigned int i=0; i<N; ++i) {
    y[i] = square(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = cube(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = fourth(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = fifth(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = sixth(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = seventh(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = eighth(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = ninth(x[i]);
    //z = y;
  }
  for(unsigned int i=0; i<N; ++i) {
    y[i] = tenth(x[i]);
    //z = y;
  }
  end = clock();
  cout << "... took " << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;


  return 0;
}
