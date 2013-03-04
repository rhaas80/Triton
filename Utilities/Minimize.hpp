#ifndef MINIMIZE_HPP
#define MINIMIZE_HPP

#include "NumericalRecipes.hpp"
#include "VectorFunctions.hpp"

namespace WaveformUtilities {
  
  /// These minimization routines are copied directly from Numerical Recipes, 'mins.h'.
  /// Brent is the standard method for simple 1-D cases without calculated derivatives.
  /// Usage is something like:
  ///   Brent Minimizer(Tolerance); // Tolerance is 3.0e-8 by default
  ///   Minimizer.bracket(a, b, func); // a and b are known limits; func is the functor
  ///   xmin = Minimizer.minimize(func); // xmin is the location of the minimum
  /// Bad results are obtained if there is no real minimum in [a,b].  Tolerance should
  /// not be less than about sqrt(mach. prec.) unless you know what you're doing.
  
  struct Bracketmethod {
    Doub ax,bx,cx,fa,fb,fc;
    template <class T>
    void bracket(const Doub a, const Doub b, T &func)
    {
      const Doub GOLD=1.618034,GLIMIT=100.0,TINY=1.0e-20;
      ax=a; bx=b;
      Doub fu;
      fa=func(ax);
      fb=func(bx);
      if (fb > fa) {
	SWAP(ax,bx);
	SWAP(fb,fa);
      }
      cx=bx+GOLD*(bx-ax);
      fc=func(cx);
      while (fb > fc) {
	Doub r=(bx-ax)*(fb-fc);
	Doub q=(bx-cx)*(fb-fa);
	Doub u=bx-((bx-cx)*q-(bx-ax)*r)/
	  (2.0*SIGN(MAX(std::abs(q-r),TINY),q-r));
	Doub ulim=bx+GLIMIT*(cx-bx);
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
    inline void shft2(Doub &a, Doub &b, const Doub c)
    {
      a=b;
      b=c;
    }
    inline void shft3(Doub &a, Doub &b, Doub &c, const Doub d)
    {
      a=b;
      b=c;
      c=d;
    }
    inline void mov3(Doub &a, Doub &b, Doub &c, const Doub d, const Doub e,
		     const Doub f)
    {
      a=d; b=e; c=f;
    }
  };
  struct Brent : Bracketmethod {
    Doub xmin,fmin;
    const Doub tol;
    Brent(const Doub toll=3.0e-8) : tol(toll) {}
    template <class T>
    Doub minimize(T &func)
    {
      const Int ITMAX=100;
      const Doub CGOLD=0.3819660;
      const Doub ZEPS=numeric_limits<Doub>::epsilon()*1.0e-3;
      Doub a,b,d=0.0,etemp,fu,fv,fw,fx;
      Doub p,q,r,tol1,tol2,u,v,w,x,xm;
      Doub e=0.0;
      
      a=(ax < cx ? ax : cx);
      b=(ax > cx ? ax : cx);
      x=w=v=bx;
      fw=fv=fx=func(x);
      for (Int iter=0;iter<ITMAX;iter++) {
	xm=0.5*(a+b);
	tol2=2.0*(tol1=tol*std::abs(x)+ZEPS);
	if (std::abs(x-xm) <= (tol2-0.5*(b-a))) {
	  fmin=fx;
	  return xmin=x;
	}
	if (std::abs(e) > tol1) {
	  r=(x-w)*(fx-fv);
	  q=(x-v)*(fx-fw);
	  p=(x-v)*q-(x-w)*r;
	  q=2.0*(q-r);
	  if (q > 0.0) p = -p;
	  q=std::abs(q);
	  etemp=e;
	  e=d;
	  if (std::abs(p) >= std::abs(0.5*q*etemp) || p <= q*(a-x)
	      || p >= q*(b-x))
	    d=CGOLD*(e=(x >= xm ? a-x : b-x));
	  else {
	    d=p/q;
	    u=x+d;
	    if (u-a < tol2 || b-u < tol2)
	      d=SIGN(tol1,xm-x);
	  }
	} else {
	  d=CGOLD*(e=(x >= xm ? a-x : b-x));
	}
	u=(std::abs(d) >= tol1 ? x+d : x+SIGN(tol1,d));
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
      throw("Too many iterations in brent");
    }
  };
  
}

#endif // MINIMIZE_HPP
