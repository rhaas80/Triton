#include "Interpolate.hpp"

#include "NumericalRecipes.hpp"
#include "Utilities.hpp"

using namespace std;
namespace WU = WaveformUtilities;
using WU::Interpolator;
using WU::PolynomialInterpolator;
using WU::SplineInterpolator;


vector<double> WU::Interpolate(const vector<double>& X1, const vector<double>& Y1, const vector<double>& X2) {
  if(X1.size()==0) {
    cerr << "\nIn Interpolate: X1.size()==0 !!!\n" << endl;
    exit(1);
  }
  if(X2.size()==0) {
    cerr << "\nIn Interpolate: X2.size()==0 !!!\n" << endl;
    exit(1);
  }
  if(Y1.size()==0) {
    cerr << "\nIn Interpolate: Y1.size()==0 !!!\n" << endl;
    exit(1);
  }
  vector<double> Y2 = X2;
  WU::Interpolate(X1, Y1, X2, Y2);
  return Y2;
}

void WU::Interpolate(const vector<double>& X1, const vector<double>& Y1, const vector<double>& X2, vector<double>& Y2) {
  if(X1.size()==0) {
    cerr << "\nIn Interpolate: X1.size()==0 !!!\n" << endl;
    exit(1);
  }
  if(X2.size()==0) {
    cerr << "\nIn Interpolate: X2.size()==0 !!!\n" << endl;
    exit(1);
  }
  if(Y1.size()==0) {
    cerr << "\nIn Interpolate: Y1.size()==0 !!!\n" << endl;
    exit(1);
  }
  SplineInterpolator Spline(X1, Y1);
  if(Y2.size()!=X2.size()) {
    Y2 = vector<double>(X2.size(), 0.0);
  }
  for(unsigned int i=0; i<Y2.size(); ++i) {
    Y2[i] = Spline.interp(X2[i]);
  }
  return;
}

double WU::Interpolate(const std::vector<double>& X1, const std::vector<double>& Y1, const double& X2) {
  if(X1.size()==0) {
    cerr << "\nIn Interpolate: X1.size()==0 !!!\n" << endl;
    exit(1);
  }
  if(Y1.size()==0) {
    cerr << "\nIn Interpolate: Y1.size()==0 !!!\n" << endl;
    exit(1);
  }
  vector<double> x1(1, X2);
  vector<double> y1(WU::Interpolate(X1, Y1, x1));
  return y1[0];
}



Interpolator::Interpolator(const std::vector<double>& x, const vector<double>& y, int m)
  : n(x.size()), mm(m), jsav(0), cor(0), xx(x), yy(y)
{
  dj = MIN(1,int(pow(double(n),0.25)));
}

Int Interpolator::locate(const Doub x) {
  Int ju,jm,jl;
  if (n < 2 || mm < 2 || mm > n) throw("Interpolator::locate size error");
  Bool ascnd=(xx[n-1] >= xx[0]);
  jl=0;
  ju=n-1;
  while (ju-jl > 1) {
    jm = (ju+jl) >> 1;
    if (x >= xx[jm] == ascnd)
      jl=jm;
    else
      ju=jm;
  }
  cor = abs(jl-jsav) > dj ? 0 : 1;
  jsav = jl;
  return MAX(0,MIN(n-mm,jl-((mm-2)>>1)));
}

Int Interpolator::hunt(const Doub x) {
  Int jl=jsav, jm, ju, inc=1;
  if (n < 2 || mm < 2 || mm > n) throw("Interpolator::hunt size error");
  Bool ascnd=(xx[n-1] >= xx[0]);
  if (jl < 0 || jl > n-1) {
    jl=0;
    ju=n-1;
  } else {
    if (x >= xx[jl] == ascnd) {
      for (;;) {
	ju = jl + inc;
	if (ju >= n-1) { ju = n-1; break;}
	else if (x < xx[ju] == ascnd) break;
	else {
	  jl = ju;
	  inc += inc;
	}
      }
    } else {
      ju = jl;
      for (;;) {
	jl = jl - inc;
	if (jl <= 0) { jl = 0; break;}
	else if (x >= xx[jl] == ascnd) break;
	else {
	  ju = jl;
	  inc += inc;
	}
      }
    }
  }
  while (ju-jl > 1) {
    jm = (ju+jl) >> 1;
    if (x >= xx[jm] == ascnd)
      jl=jm;
    else
      ju=jm;
  }
  cor = abs(jl-jsav) > dj ? 0 : 1;
  jsav = jl;
  return MAX(0,MIN(n-mm,jl-((mm-2)>>1)));
}

Doub PolynomialInterpolator::rawinterp(Int jl, Doub x) {
  Int i,m,ns=0;
  Doub y,den,dif,dift,ho,hp,w;
  const Doub *xa = &xx[jl], *ya = &yy[jl];
  VecDoub c(mm),d(mm);
  dif=abs(x-xa[0]);
  for (i=0;i<mm;i++) {
    if ((dift=abs(x-xa[i])) < dif) {
      ns=i;
      dif=dift;
    }
    c[i]=ya[i];
    d[i]=ya[i];
  }
  y=ya[ns--];
  for (m=1;m<mm;m++) {
    for (i=0;i<mm-m;i++) {
      ho=xa[i]-x;
      hp=xa[i+m]-x;
      w=c[i+1]-d[i];
      if ((den=ho-hp) == 0.0) throw("PolynomialInterpolator::rawinterp error");
      den=w/den;
      d[i]=hp*den;
      c[i]=ho*den;
    }
    y += (dy=(2*(ns+1) < (mm-m) ? c[ns+1] : d[ns--]));
  }
  return y;
}


//void Spline_interp::sety2(const Doub *xv, const Doub *yv, Doub yp1, Doub ypn) <replaced />
void SplineInterpolator::sety2(VecDoub_I &xv, VecDoub_I &yv, Doub yp1, Doub ypn) {
  Int i,k;
  Doub p,qn,sig,un;
  Int n=y2.size();
  VecDoub u(n-1);
  if (yp1 > 0.99e99)
    y2[0]=u[0]=0.0;
  else {
    y2[0] = -0.5;
    u[0]=(3.0/(xv[1]-xv[0]))*((yv[1]-yv[0])/(xv[1]-xv[0])-yp1);
  }
  for (i=1;i<n-1;i++) {
    sig=(xv[i]-xv[i-1])/(xv[i+1]-xv[i-1]);
    p=sig*y2[i-1]+2.0;
    y2[i]=(sig-1.0)/p;
    u[i]=(yv[i+1]-yv[i])/(xv[i+1]-xv[i]) - (yv[i]-yv[i-1])/(xv[i]-xv[i-1]);
    u[i]=(6.0*u[i]/(xv[i+1]-xv[i-1])-sig*u[i-1])/p;
  }
  if (ypn > 0.99e99)
    qn=un=0.0;
  else {
    qn=0.5;
    un=(3.0/(xv[n-1]-xv[n-2]))*(ypn-(yv[n-1]-yv[n-2])/(xv[n-1]-xv[n-2]));
  }
  y2[n-1]=(un-qn*u[n-2])/(qn*y2[n-2]+1.0);
  for (k=n-2;k>=0;k--)
    y2[k]=y2[k]*y2[k+1]+u[k];
}
Doub SplineInterpolator::rawinterp(Int jl, Doub x)
{
  Int klo=jl,khi=jl+1;
  Doub y,h,b,a;
  h=xx[khi]-xx[klo];
  if (h == 0.0) throw("Bad input to routine SplineInterpolator::rawinterp");
  a=(xx[khi]-x)/h;
  b=(x-xx[klo])/h;
  y=a*yy[klo]+b*yy[khi]+((a*a*a-a)*y2[klo]
			 +(b*b*b-b)*y2[khi])*(h*h)/6.0;
  return y;
}
