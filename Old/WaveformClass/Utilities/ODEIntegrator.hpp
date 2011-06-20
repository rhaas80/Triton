#ifndef ODEINTEGRATOR_HPP
#define ODEINTEGRATOR_HPP

//// I've added the final option 'denseish' to the Odeint object.
///  With this flag set, the Output object's nsave will be interpreted
///  as the number of points in a timestep interval to save.

#include "VectorFunctions.hpp"
#include "LUdcmp.hpp"
#include <limits>
#include <cmath>
#include <vector>
#include <iostream>

namespace {

struct Output {
  int kmax;
  int nvar;
  int nsave;
  bool dense;
  int count;
  double x1,x2,xout,dxout;
  std::vector<double> xsave;
  std::vector<std::vector<double> > ysave;
  Output() : kmax(-1),dense(false),count(0) {}
  Output(const int nsavee) : kmax(500),nsave(nsavee),count(0),xsave(kmax) {
    dense = nsave > 0 ? true : false;
  }
  void init(const int neqn, const double xlo, const double xhi) {
    nvar=neqn;
    if (kmax == -1) return;
    // REPLACEMENT!!!
    ysave = std::vector<std::vector<double> >(nvar, std::vector<double>(kmax, 0.0));
    //ysave.resize(nvar,kmax);
    if (dense) {
      x1=xlo;
      x2=xhi;
      xout=x1;
      dxout=(x2-x1)/nsave;
    }
  }
  void resize() {
    int kold=kmax;
    kmax *= 2;
    std::vector<double> tempvec(xsave);
    xsave.resize(kmax);
    for (int k=0; k<kold; k++)
      xsave[k]=tempvec[k];
    std::vector<std::vector<double> > tempmat(ysave);
    // REPLACEMENT!!!
    ysave = std::vector<std::vector<double> >(nvar, std::vector<double>(kmax, 0.0));
    //ysave.resize(nvar,kmax);
    for (int i=0; i<nvar; i++)
      for (int k=0; k<kold; k++)
	ysave[i][k]=tempmat[i][k];
  }
  template <class Stepper>
  void save_dense(Stepper &s, const double xout, const double h) {
    if (count == kmax) resize();
    for (int i=0;i<nvar;i++)
      ysave[i][count]=s.dense_out(i,xout,h);
    xsave[count++]=xout;
  }
  void save(const double x, const std::vector<double> &y) {
    if (kmax <= 0) return;
    if (count == kmax) resize();
    for (int i=0;i<nvar;i++)
      ysave[i][count]=y[i];
    xsave[count++]=x;
  }
  template <class Stepper>
  void out(const int nstp,const double x, const std::vector<double> &y, Stepper &s, const double h) {
    if (!dense) {
      std::cerr << "dense output not set in Output!" << std::endl;
      throw(1);
    }
    if (nstp == -1) {
      save(x,y);
      xout += dxout;
    } else {
      while ((x-xout)*(x2-x1) > 0.0) {
	save_dense(s,xout,h);
	xout += dxout;
      }
    }
  }
};
template<class Stepper>
struct Odeint {
  // REPLACEMENT!!!
  static const int MAXSTP=5000000;
  //static const int MAXSTP=50000;
  double EPS;
  int nok;
  int nbad;
  int nvar;
  double x1,x2,hmin;
  bool dense;
  // ADDITIONS!!!
  bool denseish;
  bool (*ContinueIntegration)(const double& x, const std::vector<double>& y, const std::vector<double>& dydx);
  /////// and related statements below
  std::vector<double> y,dydx;
  std::vector<double> &ystart;
  Output &out;
  typename Stepper::Dtype &derivs;
  Stepper s;
  int nstp;
  double x,h;
  Odeint(std::vector<double> &ystartt,const double xx1,const double xx2,
	 const double atol, const double rtol, const double h1,
	 const double hminn, Output &outt, typename Stepper::Dtype &derivss, const bool denseishh=false,
	 bool (*ContinueIntegrating)(const double& x, const std::vector<double>& y, const std::vector<double>& dydx) = NULL);
  void integrate();
};

template<class Stepper>
Odeint<Stepper>::Odeint(std::vector<double> &ystartt, const double xx1, const double xx2,
			const double atol, const double rtol, const double h1, const double hminn,
			Output &outt,typename Stepper::Dtype &derivss, const bool denseishh,
			bool (*Continue)(const double& x, const std::vector<double>& y, const std::vector<double>& dydx))
  : nok(0),nbad(0),nvar(ystartt.size()),x1(xx1),x2(xx2),hmin(hminn),dense(outt.dense),denseish(denseishh),ContinueIntegration(Continue),
    y(nvar),dydx(nvar),ystart(ystartt),out(outt),derivs(derivss),s(y,dydx,x,atol,rtol,dense),x(xx1) {
  EPS=std::numeric_limits<double>::epsilon();
  h=sign(h1,x2-x1);
  for (int i=0;i<nvar;i++) y[i]=ystart[i];
  out.init(s.neqn,x1,x2);
}

template<class Stepper>
void Odeint<Stepper>::integrate() {
  derivs(x,y,dydx);
  if (dense) {
    if(denseish) { out.dxout = h/double(out.nsave); } /// ADDITION!!!
    out.out(-1,x,y,s,h);
  } else {
    out.save(x,y);
  }
  for (nstp=0;nstp<MAXSTP;nstp++) {
    if ((x+h*1.0001-x2)*(x2-x1) > 0.0)
      h=x2-x;
    s.step(h,derivs);
    if (s.hdid == h) ++nok; else ++nbad;
    if (dense) {
      if(denseish) { out.dxout = s.hdid/double(out.nsave); } /// ADDITION!!!
      out.out(nstp,x,y,s,s.hdid);
    } else {
      out.save(x,y);
    }
    if ((x-x2)*(x2-x1) >= 0.0) {
      for (int i=0;i<nvar;i++) ystart[i]=y[i];
      if (out.kmax > 0 && std::abs(out.xsave[out.count-1]-x2) > 100.0*std::abs(x2)*EPS)
	out.save(x,y);
      return;
    }
    if (std::abs(s.hnext) <= hmin) {
      std::cerr << "Step size smaller than requested in Odeint.  Returning now." << std::endl;
      return;//throw(1);
    }
    if (ContinueIntegration!=NULL && !ContinueIntegration(x, y, dydx)) {
      std::cerr << "Right-hand side asked to stop integration.  Returning now." << std::endl;
      return;//throw(1);
    }
    h=s.hnext;
  }
  std::cerr << "Too many steps in routine Odeint" << std::endl;
  throw(1);
}

struct StepperBase {
  double &x;
  double xold;
  std::vector<double> &y,&dydx;
  double atol,rtol;
  bool dense;
  double hdid;
  double hnext;
  double EPS;
  int n,neqn;
  std::vector<double> yout,yerr;
  StepperBase(std::vector<double> &yy, std::vector<double> &dydxx, double &xx, const double atoll,
	      const double rtoll, bool dens) : x(xx),y(yy),dydx(dydxx),atol(atoll),
					     rtol(rtoll),dense(dens),n(y.size()),neqn(n),yout(n),yerr(n) {}
};
  
  inline double MAX(const double& a, const double& b) { return (a>b ? a : b); }
  inline double MIN(const double& a, const double& b) { return (a<b ? a : b); }
  inline double SQR(const double& a) { return a*a; }
  
//#include "StepperDopr5.hpp" /// Dopr5 shouldn't be used; used Dop853
#include "StepperDopr853.hpp"
#include "StepperBS.hpp"
#include "StepperRoss.hpp"

}

#endif // ODEINTEGRATOR_HPP
