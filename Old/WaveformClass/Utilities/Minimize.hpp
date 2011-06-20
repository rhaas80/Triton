#ifndef MINIMIZE_HPP
#define MINIMIZE_HPP

#include "VectorFunctions.hpp"
#include <limits>
#include <cmath>

class Bracketmethod {
public:
  double ax,bx,cx,fa,fb,fc;
  template <class T>
  void bracket(const double a, const double b, T& func);
  inline void shft2(double& a, double& b, const double c);
  inline void shft3(double& a, double& b, double& c, const double d);
  inline void mov3(double& a, double& b, double& c, const double d, const double e,
		   const double f);
};

class Brent : public Bracketmethod {
public:
  double xmin,fmin;
  const double tol;
  Brent(const double toll=3.0e-8) : tol(toll) {}
  template <class T>
  double minimize(T& func);
};

template <class T>
void Bracketmethod::bracket(const double a, const double b, T& func) {
  const double GOLD=1.618034,GLIMIT=100.0,TINY=1.0e-20;
  ax=a; bx=b;
  double fu;
  fa=func(ax);
  fb=func(bx);
  if (fb > fa) {
    swap(ax,bx);
    swap(fb,fa);
  }
  cx=bx+GOLD*(bx-ax);
  fc=func(cx);
  while (fb > fc) {
    double r=(bx-ax)*(fb-fc);
    double q=(bx-cx)*(fb-fa);
    double u=bx-((bx-cx)*q-(bx-ax)*r)/
      (2.0*sign(max(fabs(q-r),TINY),q-r));
    double ulim=bx+GLIMIT*(cx-bx);
    if ((bx-u)*(u-cx) > 0.0) {
      fu=func(u);
      if (fu < fc) {
	ax=bx;
	bx=u;
	fa=fb;
	fb=fu;
	return;
      } else if (fu > fb) {
	cx=u;
	fc=fu;
	return;
      }
      u=cx+GOLD*(cx-bx);
      fu=func(u);
    } else if ((cx-u)*(u-ulim) > 0.0) {
      fu=func(u);
      if (fu < fc) {
	shft3(bx,cx,u,u+GOLD*(u-cx));
	shft3(fb,fc,fu,func(u));
      }
    } else if ((u-ulim)*(ulim-cx) >= 0.0) {
      u=ulim;
      fu=func(u);
    } else {
      u=cx+GOLD*(cx-bx);
      fu=func(u);
    }
    shft3(ax,bx,cx,u);
    shft3(fa,fb,fc,fu);
  }
}

inline void Bracketmethod::shft2(double& a, double& b, const double c)
{
  a=b;
  b=c;
}

inline void Bracketmethod::shft3(double& a, double& b, double& c, const double d)
{
  a=b;
  b=c;
  c=d;
}

inline void Bracketmethod::mov3(double& a, double& b, double& c, const double d, const double e, const double f)
{
  a=d; b=e; c=f;
}

template <class T>
double Brent::minimize(T& func)
{
  const int ITMAX=100;
  const double CGOLD=0.3819660;
  const double ZEPS=std::numeric_limits<double>::epsilon()*1.0e-3;
  double a,b,d=0.0,etemp,fu,fv,fw,fx;
  double p,q,r,tol1,tol2,u,v,w,x,xm;
  double e=0.0;
	
  a=(ax < cx ? ax : cx);
  b=(ax > cx ? ax : cx);
  x=w=v=bx;
  fw=fv=fx=func(x);
  for (int iter=0;iter<ITMAX;iter++) {
    xm=0.5*(a+b);
    tol2=2.0*(tol1=tol*fabs(x)+ZEPS);
    if (fabs(x-xm) <= (tol2-0.5*(b-a))) {
      fmin=fx;
      return xmin=x;
    }
    if (fabs(e) > tol1) {
      r=(x-w)*(fx-fv);
      q=(x-v)*(fx-fw);
      p=(x-v)*q-(x-w)*r;
      q=2.0*(q-r);
      if (q > 0.0) p = -p;
      q=fabs(q);
      etemp=e;
      e=d;
      if (fabs(p) >= fabs(0.5*q*etemp) || p <= q*(a-x)
	  || p >= q*(b-x))
	d=CGOLD*(e=(x >= xm ? a-x : b-x));
      else {
	d=p/q;
	u=x+d;
	if (u-a < tol2 || b-u < tol2)
	  d=sign(tol1,xm-x);
      }
    } else {
      d=CGOLD*(e=(x >= xm ? a-x : b-x));
    }
    u=(fabs(d) >= tol1 ? x+d : x+sign(tol1,d));
    fu=func(u);
    if (fu <= fx) {
      if (u >= x) a=x; else b=x;
      shft3(v,w,x,u);
      shft3(fv,fw,fx,fu);
    } else {
      if (u < x) a=u; else b=u;
      if (fu <= fw || w == x) {
	v=w;
	w=u;
	fv=fw;
	fw=fu;
      } else if (fu <= fv || v == x || v == w) {
	v=u;
	fv=fu;
      }
    }
  }
  std::cerr << "Too many iterations in brent" << std::endl;
  throw(1);
  //throw("Too many iterations in brent");
}


struct Dbrent : Bracketmethod {
  double xmin,fmin;
  const double tol;
  Dbrent(const double toll=3.0e-8) : tol(toll) {}
  template <class T>
  double minimize(T &funcd)
  {
    const int ITMAX=100;
    const double ZEPS=std::numeric_limits<double>::epsilon()*1.0e-3;
    bool ok1,ok2;
    double a,b,d=0.0,d1,d2,du,dv,dw,dx,e=0.0;
    double fu,fv,fw,fx,olde,tol1,tol2,u,u1,u2,v,w,x,xm;
    
    a=(ax < cx ? ax : cx);
    b=(ax > cx ? ax : cx);
    x=w=v=bx;
    fw=fv=fx=funcd(x);
    dw=dv=dx=funcd.df(x);
    for (int iter=0;iter<ITMAX;iter++) {
      xm=0.5*(a+b);
      tol1=tol*abs(x)+ZEPS;
      tol2=2.0*tol1;
      if (abs(x-xm) <= (tol2-0.5*(b-a))) {
	fmin=fx;
	return xmin=x;
      }
      if (abs(e) > tol1) {
	d1=2.0*(b-a);
	d2=d1;
	if (dw != dx) d1=(w-x)*dx/(dx-dw);
	if (dv != dx) d2=(v-x)*dx/(dx-dv);
	u1=x+d1;
	u2=x+d2;
	ok1 = (a-u1)*(u1-b) > 0.0 && dx*d1 <= 0.0;
	ok2 = (a-u2)*(u2-b) > 0.0 && dx*d2 <= 0.0;
	olde=e;
	e=d;
	if (ok1 || ok2) {
	  if (ok1 && ok2)
	    d=(abs(d1) < abs(d2) ? d1 : d2);
	  else if (ok1)
	    d=d1;
	  else
	    d=d2;
	  if (abs(d) <= abs(0.5*olde)) {
	    u=x+d;
	    if (u-a < tol2 || b-u < tol2)
	      //d=SIGN(tol1,xm-x);
	      d = xm-x >= 0 ? (tol1 >= 0 ? tol1 : -tol1) : (tol1 >= 0 ? -tol1 : tol1);
	  } else {
	    d=0.5*(e=(dx >= 0.0 ? a-x : b-x));
	  }
	} else {
	  d=0.5*(e=(dx >= 0.0 ? a-x : b-x));
	}
      } else {
	d=0.5*(e=(dx >= 0.0 ? a-x : b-x));
      }
      if (abs(d) >= tol1) {
	u=x+d;
	fu=funcd(u);
      } else {
	//u=x+SIGN(tol1,d);
	u = x + d >= 0 ? (tol1 >= 0 ? tol1 : -tol1) : (tol1 >= 0 ? -tol1 : tol1);
	fu=funcd(u);
	if (fu > fx) {
	  fmin=fx;
	  return xmin=x;
	}
      }
      du=funcd.df(u);
      if (fu <= fx) {
	if (u >= x) a=x; else b=x;
	mov3(v,fv,dv,w,fw,dw);
	mov3(w,fw,dw,x,fx,dx);
	mov3(x,fx,dx,u,fu,du);
      } else {
	if (u < x) a=u; else b=u;
	if (fu <= fw || w == x) {
	  mov3(v,fv,dv,w,fw,dw);
	  mov3(w,fw,dw,u,fu,du);
	} else if (fu < fv || v == x || v == w) {
	  mov3(v,fv,dv,u,fu,du);
	}
      }
    }
    std::cerr << "Too many iterations in routine dbrent" << std::endl;
    throw(1);
    //throw("Too many iterations in routine dbrent");
  }
};



/////////////////////////////////////////////////////////////////////////
///// Multi-dimensional


template <class T>
struct F1dim {
  const std::vector<double> &p;
  const std::vector<double> &xi;
  int n;
  T &func;
  std::vector<double> xt;
  F1dim(const std::vector<double> &pp, const std::vector<double> &xii, T &funcc) : p(pp),
						   xi(xii), n(pp.size()), func(funcc), xt(n) {}
  double operator() (const double x)
  {
    for (int j=0;j<n;j++)
      xt[j]=p[j]+x*xi[j];
    return func(xt);
  }
};
template <class T>
struct Linemethod {
  std::vector<double> p;
  std::vector<double> xi;
  T &func;
  int n;
  Linemethod(T &funcc) : func(funcc) {}
  double linmin()
  {
    double ax,xx,xmin;
    n=p.size();
    F1dim<T> f1dim(p,xi,func);
    ax=0.0;
    xx=1.0;
    Brent brent;
    brent.bracket(ax,xx,f1dim);
    xmin=brent.minimize(f1dim);
    for (int j=0;j<n;j++) {
      xi[j] *= xmin;
      p[j] += xi[j];
    }
    return brent.fmin;
  }
};
template <class T>
struct Df1dim {
  const std::vector<double> &p;
  const std::vector<double> &xi;
  int n;
  T &funcd;
  std::vector<double> xt;
  std::vector<double> dft;
  Df1dim(const std::vector<double> &pp, const std::vector<double> &xii, T &funcdd) : p(pp),
						     xi(xii), n(pp.size()), funcd(funcdd), xt(n), dft(n) {}
  double operator()(const double x)
  {
    for (int j=0;j<n;j++)
      xt[j]=p[j]+x*xi[j];
    return funcd(xt);
  }
  double df(const double x)
  {
    double df1=0.0;
    funcd.df(xt,dft);
    for (int j=0;j<n;j++)
      df1 += dft[j]*xi[j];
    return df1;
  }
};
template <class T>
struct Dlinemethod {
  std::vector<double> p;
  std::vector<double> xi;
  T &func;
  int n;
  Dlinemethod(T &funcc) : func(funcc) {}
  double linmin()
  {
    double ax,xx,xmin;
    n=p.size();
    Df1dim<T> df1dim(p,xi,func);
    ax=0.0;
    xx=1.0;
    Dbrent dbrent;
    dbrent.bracket(ax,xx,df1dim);
    xmin=dbrent.minimize(df1dim);
    for (int j=0;j<n;j++) {
      xi[j] *= xmin;
      p[j] += xi[j];
    }
    return dbrent.fmin;
  }
};
template <class T>
struct Powell : Linemethod<T> {
  int iter;
  double fret;
  using Linemethod<T>::func;
  using Linemethod<T>::linmin;
  using Linemethod<T>::p;
  using Linemethod<T>::xi;
  const double ftol;
  Powell(T &func, const double ftoll=3.0e-8) : Linemethod<T>(func),
					     ftol(ftoll) {}
  std::vector<double> minimize(const std::vector<double> &pp)
  {
    int n=pp.size();
    std::vector<std::vector<double> > ximat(n,std::vector<double>(n,0.0));
    for (int i=0;i<n;i++) ximat[i][i]=1.0;
    return minimize(pp,ximat);
  }
  std::vector<double> minimize(const std::vector<double> &pp, std::vector<std::vector<double> > &ximat)
  {
    const int ITMAX=200;
    const double TINY=1.0e-25;
    double fptt;
    int n=pp.size();
    p=pp;
    std::vector<double> pt(n),ptt(n);
    xi.resize(n);
    fret=func(p);
    for (int j=0;j<n;j++) pt[j]=p[j];
    for (iter=0;;++iter) {
      double fp=fret;
      int ibig=0;
      double del=0.0;
      for (int i=0;i<n;i++) {
	for (int j=0;j<n;j++) xi[j]=ximat[j][i];
	fptt=fret;
	fret=linmin();
	if (fptt-fret > del) {
	  del=fptt-fret;
	  ibig=i+1;
	}
      }
      if (2.0*(fp-fret) <= ftol*(abs(fp)+abs(fret))+TINY) {
	return p;
      }
      if (iter == ITMAX) { std::cerr << "powell exceeding maximum iterations." << std::endl; throw(1); }
      //if (iter == ITMAX) throw("powell exceeding maximum iterations.");
      for (int j=0;j<n;j++) {
	ptt[j]=2.0*p[j]-pt[j];
	xi[j]=p[j]-pt[j];
	pt[j]=p[j];
      }
      fptt=func(ptt);
      if (fptt < fp) {
	//double t=2.0*(fp-2.0*fret+fptt)*SQR(fp-fret-del)-del*SQR(fp-fptt);
	double t=2.0*(fp-2.0*fret+fptt)*(fp-fret-del)*(fp-fret-del)-del*(fp-fptt)*(fp-fptt);
	if (t < 0.0) {
	  fret=linmin();
	  for (int j=0;j<n;j++) {
	    ximat[j][ibig-1]=ximat[j][n-1];
	    ximat[j][n-1]=xi[j];
	  }
	}
      }
    }
  }
};
template <class T>
struct Frprmn : Linemethod<T> {
  int iter;
  double fret;
  using Linemethod<T>::func;
  using Linemethod<T>::linmin;
  using Linemethod<T>::p;
  using Linemethod<T>::xi;
  const double ftol;
  Frprmn(T &funcd, const double ftoll=3.0e-8) : Linemethod<T>(funcd),
					      ftol(ftoll) {}
  std::vector<double> minimize(const std::vector<double> &pp)
  {
    const int ITMAX=200;
    const double EPS=1.0e-18;
    const double GTOL=1.0e-8;
    double gg,dgg;
    int n=pp.size();
    p=pp;
    std::vector<double> g(n),h(n);
    xi.resize(n);
    double fp=func(p);
    func.df(p,xi);
    for (int j=0;j<n;j++) {
      g[j] = -xi[j];
      xi[j]=h[j]=g[j];
    }
    for (int its=0;its<ITMAX;its++) {
      iter=its;
      fret=linmin();
      if (2.0*abs(fret-fp) <= ftol*(abs(fret)+abs(fp)+EPS))
	return p;
      fp=fret;
      func.df(p,xi);
      double test=0.0;
      //double den=MAX(abs(fp),1.0);
      double den= abs(fp)>1.0 ? abs(fp) : 1.0;
      for (int j=0;j<n;j++) {
	//double temp=abs(xi[j])*MAX(abs(p[j]),1.0)/den;
	double temp=abs(xi[j])*(abs(p[j])>1.0 ? abs(p[j]) : 1.0)/den;
	if (temp > test) test=temp;
      }
      if (test < GTOL) return p;
      dgg=gg=0.0;
      for (int j=0;j<n;j++) {
	gg += g[j]*g[j];
	//			  dgg += xi[j]*xi[j];
	dgg += (xi[j]+g[j])*xi[j];
      }
      if (gg == 0.0)
	return p;
      double gam=dgg/gg;
      for (int j=0;j<n;j++) {
	g[j] = -xi[j];
	xi[j]=h[j]=g[j]+gam*h[j];
      }
    }
    std::cerr << "Too many iterations in frprmn" << std::endl;
    throw(1);
    //throw("Too many iterations in frprmn");
  }
};


////////////////////////////////////////////////
struct Amoeba {
  const double ftol;
  int nfunc;
  int mpts;
  int ndim;
  double fmin;
  std::vector<double> y;
  std::vector<std::vector<double> > p;
  Amoeba(const double ftoll) : ftol(ftoll) {}
  inline void SWAP(double &a, double &b){double dum=a; a=b; b=dum;}
  template <class T>
  std::vector<double> minimize(const std::vector<double> &point, const double del, T &func)
  {
    std::vector<double> dels(point.size(),del);
    return minimize(point,dels,func);
  }
  template <class T>
  std::vector<double> minimize(const std::vector<double> &point, const std::vector<double> &dels, T &func)
  {
    int ndim=point.size();
    std::vector<std::vector<double> > pp(ndim+1, std::vector<double>(ndim));
    for (int i=0;i<ndim+1;i++) {
      for (int j=0;j<ndim;j++)
	pp[i][j]=point[j];
      if (i !=0 ) pp[i][i-1] += dels[i-1];
    }
    return minimize(pp,func);
  }
  template <class T>
  std::vector<double> minimize(const std::vector<std::vector<double> > &pp, T &func)
  {
    const int NMAX=5000;
    const double TINY=1.0e-10;
    int ihi,ilo,inhi;
//     mpts=pp.nrows();
//     ndim=pp.ncols();
    mpts=pp.size();
    ndim=pp[0].size();
    std::vector<double> psum(ndim),pmin(ndim),x(ndim);
    p=pp;
    y.resize(mpts);
    for (int i=0;i<mpts;i++) {
      for (int j=0;j<ndim;j++)
	x[j]=p[i][j];
      y[i]=func(x);
    }
    nfunc=0;
    get_psum(p,psum);
    for (;;) {
      ilo=0;
      ihi = y[0]>y[1] ? (inhi=1,0) : (inhi=0,1);
      for (int i=0;i<mpts;i++) {
	if (y[i] <= y[ilo]) ilo=i;
	if (y[i] > y[ihi]) {
	  inhi=ihi;
	  ihi=i;
	} else if (y[i] > y[inhi] && i != ihi) inhi=i;
      }
      double rtol=2.0*abs(y[ihi]-y[ilo])/(abs(y[ihi])+abs(y[ilo])+TINY);
      if (rtol < ftol) {
	SWAP(y[0],y[ilo]);
	for (int i=0;i<ndim;i++) {
	  SWAP(p[0][i],p[ilo][i]);
	  pmin[i]=p[0][i];
	}
	fmin=y[0];
	return pmin;
      }
      if (nfunc >= NMAX) { std::cerr << "NMAX exceeded" << std::endl; throw(1); }
      //if (nfunc >= NMAX) throw("NMAX exceeded");
      nfunc += 2;
      double ytry=amotry(p,y,psum,ihi,-1.0,func);
      if (ytry <= y[ilo])
	ytry=amotry(p,y,psum,ihi,2.0,func);
      else if (ytry >= y[inhi]) {
	double ysave=y[ihi];
	ytry=amotry(p,y,psum,ihi,0.5,func);
	if (ytry >= ysave) {
	  for (int i=0;i<mpts;i++) {
	    if (i != ilo) {
	      for (int j=0;j<ndim;j++)
		p[i][j]=psum[j]=0.5*(p[i][j]+p[ilo][j]);
	      y[i]=func(psum);
	    }
	  }
	  nfunc += ndim;
	  get_psum(p,psum);
	}
      } else --nfunc;
    }
  }
  inline void get_psum(const std::vector<std::vector<double> > &p, std::vector<double> &psum)
  {
    for (int j=0;j<ndim;j++) {
      double sum=0.0;
      for (int i=0;i<mpts;i++)
	sum += p[i][j];
      psum[j]=sum;
    }
  }
  template <class T>
  double amotry(std::vector<std::vector<double> > &p, std::vector<double> &y, std::vector<double> &psum,
	      const int ihi, const double fac, T &func)
  {
    std::vector<double> ptry(ndim);
    double fac1=(1.0-fac)/ndim;
    double fac2=fac1-fac;
    for (int j=0;j<ndim;j++)
      ptry[j]=psum[j]*fac1-p[ihi][j]*fac2;
    double ytry=func(ptry);
    if (ytry < y[ihi]) {
      y[ihi]=ytry;
      for (int j=0;j<ndim;j++) {
	psum[j] += ptry[j]-p[ihi][j];
	p[ihi][j]=ptry[j];
      }
    }
    return ytry;
  }
};



#endif // MINIMIZE_HPP
