#ifndef LUDCMP_HPP
#define LUDCMP_HPP
#include <vector>

struct LUdcmp
{
  int n;
  std::vector<std::vector<double> > lu;
  std::vector<int> indx;
  double d;
  LUdcmp(const std::vector<std::vector<double> >& a);
  void solve(const std::vector<double>& b, std::vector<double>& x);
  void solve(const std::vector<std::vector<double> >& b, std::vector<std::vector<double> >& x);
  void inverse(std::vector<std::vector<double> >& ainv);
  double det();
  void mprove(const std::vector<double>& b, std::vector<double>& x);
  const std::vector<std::vector<double> >& aref;
};


#endif // LUDCMP_HPP
