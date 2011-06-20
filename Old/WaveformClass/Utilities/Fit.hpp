#ifndef FIT_HPP
#define FIT_HPP

#include <vector>

class Fit {
public:
  static int Order; /* <NewStuff/> */
  int ndat, ma;
  const std::vector<double> &x,&y,&sig;
  std::vector<double> (*funcs)(const double);
  std::vector<bool> ia;
  std::vector<double> a;
  std::vector<std::vector<double> > covar;
  double chisq;
  
public:
  /* <NewStuff> */
  double Evaluate(const double x);
  static std::vector<double> PolynomialBasis(const double x) {
    std::vector<double> ans(Order+1);
    ans[0] = 1.0;
    for (int i=1;i<Order+1;i++) { ans[i] = x*ans[i-1]; }
    return ans;
  }
  Fit(const std::vector<double> &xx, const std::vector<double> &yy, const std::vector<double> &ssig, const int Ord);
  /* </NewStuff> */
  
  Fit(const std::vector<double> &xx, const std::vector<double> &yy, const std::vector<double> &ssig, std::vector<double> funks(const double));
  
  void hold(const int i, const double val) {ia[i]=false; a[i]=val;}
  void free(const int i) {ia[i]=true;}
  void fit();
};


class FitNonlinear {
public:
  static const int NDONE=4, ITMAX=5000;
  int ndat, ma, mfit;
  const std::vector<double> &x,&y,&sig;
  double tol;
  void (*funcs)(const double, const std::vector<double> &, double &, std::vector<double> &);
  std::vector<bool> ia;
  std::vector<double> a;
  std::vector<std::vector<double> > alpha;
  std::vector<std::vector<double> > covar;
  double chisq;
  
public:
  FitNonlinear(const std::vector<double> &xx, const std::vector<double> &yy, const std::vector<double> &ssig, const std::vector<double> &aa,
	       void funks(const double, const std::vector<double> &, double &, std::vector<double> &), const double TOL=1.e-3)
    : ndat(xx.size()), ma(aa.size()), x(xx), y(yy), sig(ssig),
      //// !!! REPLACEMENTS !!! (initializing alpha and covar)
      tol(TOL), funcs(funks), ia(ma), a(aa), alpha(std::vector<std::vector<double> >(ma, std::vector<double>(ma, 0.0))),
      covar(std::vector<std::vector<double> >(ma, std::vector<double>(ma, 0.0)))
  { for (int i=0;i<ma;i++) ia[i] = true; }
  
  void hold(const int i, const double val) {ia[i]=false; a[i]=val;}
  void free(const int i) {ia[i]=true;}
  void fit();
  void mrqcof(const std::vector<double> &a, std::vector<std::vector<double> > &alpha, std::vector<double> &beta);
  void covsrt(std::vector<std::vector<double> > &covar);
};


#endif // FIT_HPP
