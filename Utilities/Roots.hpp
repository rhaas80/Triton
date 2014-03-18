#ifndef ROOTS_HPP
#define ROOTS_HPP

#include "NumericalRecipes.hpp"

namespace WaveformUtilities {

  template <class T>
  void zbrak(T &fx, const Doub x1, const Doub x2, const Int n, VecDoub_O &xb1,
             VecDoub_O &xb2, Int &nroot)
  {
    Int nb=20;
    xb1.resize(nb);
    xb2.resize(nb);
    nroot=0;
    Doub dx=(x2-x1)/n;
    Doub x=x1;
    Doub fp=fx(x1);
    for (Int i=0;i<n;i++) {
      Doub fc=fx(x += dx);
      if (fc*fp <= 0.0) {
        xb1[nroot]=x-dx;
        xb2[nroot++]=x;
        if(nroot == nb) {
          VecDoub tempvec1(xb1),tempvec2(xb2);
          xb1.resize(2*nb);
          xb2.resize(2*nb);
          for (Int j=0; j<nb; j++) {
            xb1[j]=tempvec1[j];
            xb2[j]=tempvec2[j];
          }
          nb *= 2;
        }
      }
      fp=fc;
    }
  }

  template <class T>
  Doub zriddr(T &func, const Doub x1, const Doub x2, const Doub xacc) {
    const Int MAXIT=60;
    Doub fl=func(x1);
    Doub fh=func(x2);
    if ((fl > 0.0 && fh < 0.0) || (fl < 0.0 && fh > 0.0)) {
      Doub xl=x1;
      Doub xh=x2;
      Doub ans=-9.99e99;
      for (Int j=0;j<MAXIT;j++) {
        Doub xm=0.5*(xl+xh);
        Doub fm=func(xm);
        Doub s=sqrt(fm*fm-fl*fh);
        if (s == 0.0) return ans;
        Doub xnew=xm+(xm-xl)*((fl >= fh ? 1.0 : -1.0)*fm/s);
        if (abs(xnew-ans) <= xacc) return ans;
        ans=xnew;
        Doub fnew=func(ans);
        if (fnew == 0.0) return ans;
        if (SIGN(fm,fnew) != fm) {
          xl=xm;
          fl=fm;
          xh=ans;
          fh=fnew;
        } else if (SIGN(fl,fnew) != fl) {
          xh=ans;
          fh=fnew;
        } else if (SIGN(fh,fnew) != fh) {
          xl=ans;
          fl=fnew;
        } else Throw1WithMessage("never get here.");
        if (abs(xh-xl) <= xacc) return ans;
      }
      Throw1WithMessage("zriddr exceed maximum iterations");
    }
    else {
      if (fl == 0.0) return x1;
      if (fh == 0.0) return x2;
      Throw1WithMessage("root must be bracketed in zriddr.");
    }
  }

  template <class T>
  Doub zbrent(T &func, const Doub x1, const Doub x2, const Doub tol)
  {
    const Int ITMAX=100;
    const Doub EPS=numeric_limits<Doub>::epsilon();
    Doub a=x1,b=x2,c=x2,d,e,fa=func(a),fb=func(b),fc,p,q,r,s,tol1,xm;
    if ((fa > 0.0 && fb > 0.0) || (fa < 0.0 && fb < 0.0))
      Throw1WithMessage("Root must be bracketed in zbrent");
    fc=fb;
    for (Int iter=0;iter<ITMAX;iter++) {
      if ((fb > 0.0 && fc > 0.0) || (fb < 0.0 && fc < 0.0)) {
        c=a;
        fc=fa;
        e=d=b-a;
      }
      if (abs(fc) < abs(fb)) {
        a=b;
        b=c;
        c=a;
        fa=fb;
        fb=fc;
        fc=fa;
      }
      tol1=2.0*EPS*abs(b)+0.5*tol;
      xm=0.5*(c-b);
      if (abs(xm) <= tol1 || fb == 0.0) return b;
      if (abs(e) >= tol1 && abs(fa) > abs(fb)) {
        s=fb/fa;
        if (a == c) {
          p=2.0*xm*s;
          q=1.0-s;
        } else {
          q=fa/fc;
          r=fb/fc;
          p=s*(2.0*xm*q*(q-r)-(b-a)*(r-1.0));
          q=(q-1.0)*(r-1.0)*(s-1.0);
        }
        if (p > 0.0) q = -q;
        p=abs(p);
        Doub min1=3.0*xm*q-abs(tol1*q);
        Doub min2=abs(e*q);
        if (2.0*p < (min1 < min2 ? min1 : min2)) {
          e=d;
          d=p/q;
        } else {
          d=xm;
          e=d;
        }
      } else {
        d=xm;
        e=d;
      }
      a=b;
      fa=fb;
      if (abs(d) > tol1)
        b += d;
      else
        b += SIGN(tol1,xm);
      fb=func(b);
    }
    Throw1WithMessage("Maximum number of iterations exceeded in zbrent");
  }


}

#endif // ROOTS_HPP
