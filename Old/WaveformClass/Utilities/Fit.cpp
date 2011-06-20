#include "Fit.hpp"
#include <cstdio>
#include <cmath>
using namespace std;

int Fit::Order=0; /* <NewStuff/> */

template<class T>
inline T SQR(const T a) {return a*a;}

template<class T>
inline void SWAP(T &a, T &b) {T dum=a; a=b; b=dum;}

template<class T>
inline T abs(const T b) { return (b<0 ? -b : b); }

inline double MAX(const double& A, const double& B) { return (A>B ? A : B); }

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

typedef std::vector<std::vector<double> > MatDoub, MatDoub_IO, MatDoub_O;

void gaussj(MatDoub_IO &a, MatDoub_IO &b)
{
  /* <Replacement> */
  /* int i,icol,irow,j,k,l,ll,n=a.nrows(),m=b.ncols(); */
  int i,icol=0,irow=0,j,k,l,ll,n=a.size(),m=b[0].size();
  /* </Replacement> */
  double big,dum,pivinv;
  std::vector<int> indxc(n),indxr(n),ipiv(n);
  for (j=0;j<n;j++) ipiv[j]=0;
  for (i=0;i<n;i++) {
    big=0.0;
    for (j=0;j<n;j++)
      if (ipiv[j] != 1)
	for (k=0;k<n;k++) {
	  if (ipiv[k] == 0) {
	    if (fabs(a[j][k]) >= big) {
	      big=fabs(a[j][k]);
	      irow=j;
	      icol=k;
	    }
	  }
	}
    ++(ipiv[icol]);
    if (irow != icol) {
      for (l=0;l<n;l++) SWAP(a[irow][l],a[icol][l]);
      for (l=0;l<m;l++) SWAP(b[irow][l],b[icol][l]);
    }
    indxr[i]=irow;
    indxc[i]=icol;
    if (a[icol][icol] == 0.0) throw("gaussj: Singular Matrix");
    pivinv=1.0/a[icol][icol];
    a[icol][icol]=1.0;
    for (l=0;l<n;l++) a[icol][l] *= pivinv;
    for (l=0;l<m;l++) b[icol][l] *= pivinv;
    for (ll=0;ll<n;ll++)
      if (ll != icol) {
	dum=a[ll][icol];
	a[ll][icol]=0.0;
	for (l=0;l<n;l++) a[ll][l] -= a[icol][l]*dum;
	for (l=0;l<m;l++) b[ll][l] -= b[icol][l]*dum;
      }
  }
  for (l=n-1;l>=0;l--) {
    if (indxr[l] != indxc[l])
      for (k=0;k<n;k++)
	SWAP(a[k][indxr[l]],a[k][indxc[l]]);
  }
}

/* void gaussj(MatDoub_IO &a) */
/* { */
/*   MatDoub b(a.nrows(),0); */
/*   gaussj(a,b); */
/* } */


/* <NewStuff> */
double Fit::Evaluate(const double x) {
  double p=a[Order];
  for(int j=Order-1; j>=0; --j) p=p*x+a[j];
  return p;
}

Fit::Fit(const vector<double> &xx, const vector<double> &yy, const vector<double> &ssig, const int Ord)
  : ndat(xx.size()), x(xx), y(yy), sig(ssig), funcs(&PolynomialBasis) {
  Order = Ord;
  ma = Ord+1; //funcs(x[0]).size();
  a = vector<double>(ma, 0.0);
  covar = vector<vector<double> >(ma, vector<double>(ma, 0.0));
  ia = vector<bool>(ma, false);
  for (int i=0;i<ma;i++) ia[i] = true;
}
/* </NewStuff> */

Fit::Fit(const vector<double> &xx, const vector<double> &yy, const vector<double> &ssig, vector<double> funks(const double))
  : ndat(xx.size()), x(xx), y(yy), sig(ssig), funcs(funks)
{
  ma = funcs(x[0]).size();
  /* <Replacements> */
  /* a.resize(ma); */
  /* covar.resize(ma,ma); */
  /* ia.resize(ma); */
  a = vector<double>(ma, 0.0);
  covar = vector<vector<double> >(ma, vector<double>(ma, 0.0));
  ia = vector<bool>(ma, false);
  /* </Replacements> */
  for (int i=0;i<ma;i++) ia[i] = true;
}

void Fit::fit() {
  int i,j,k,l,m,mfit=0;
  double ym,wt,sum,sig2i;
  vector<double> afunc(ma);
  for (j=0;j<ma;j++) if (ia[j]) mfit++;
  if (mfit == 0) throw("lfit: no parameters to be fitted");
  /* <Replacements> */
  /* MatDoub temp(mfit,mfit,0.),beta(mfit,1,0.); */
  vector<vector<double> > temp(mfit, vector<double>(mfit, 0.0));
  vector<vector<double> > beta(mfit, vector<double>(1, 0.0));
  /* </Replacements> */
  for (i=0;i<ndat;i++) {
    afunc = funcs(x[i]);
    ym=y[i];
    if (mfit < ma) {
      for (j=0;j<ma;j++)
	if (!ia[j]) ym -= a[j]*afunc[j];
    }
    sig2i=1.0/SQR(sig[i]);
    for (j=0,l=0;l<ma;l++) {
      if (ia[l]) {
	wt=afunc[l]*sig2i;
	for (k=0,m=0;m<=l;m++)
	  if (ia[m]) temp[j][k++] += wt*afunc[m];
	beta[j++][0] += ym*wt;
      }
    }
  }
  for (j=1;j<mfit;j++) for (k=0;k<j;k++) temp[k][j]=temp[j][k];
  gaussj(temp,beta);
  for (j=0,l=0;l<ma;l++) if (ia[l]) a[l]=beta[j++][0];
  chisq=0.0;
  for (i=0;i<ndat;i++) {
    afunc = funcs(x[i]);
    sum=0.0;
    for (j=0;j<ma;j++) sum += a[j]*afunc[j];
    chisq += SQR((y[i]-sum)/sig[i]);
  }
  for (j=0;j<mfit;j++) for (k=0;k<mfit;k++) covar[j][k]=temp[j][k];
  for (i=mfit;i<ma;i++)
    for (j=0;j<i+1;j++) covar[i][j]=covar[j][i]=0.0;
  k=mfit-1;
  for (j=ma-1;j>=0;j--) {
    if (ia[j]) {
      for (i=0;i<ma;i++) SWAP(covar[i][k],covar[i][j]);
      for (i=0;i<ma;i++) SWAP(covar[k][i],covar[j][i]);
      k--;
    }
  }
}


void FitNonlinear::fit() {
  int j,k,l,iter,done=0;
  double alamda=.001,ochisq;
  vector<double> atry(ma),beta(ma),da(ma);
  mfit=0;
  for (j=0;j<ma;j++) if (ia[j]) mfit++;
  //// !!! REPLACEMENTS !!!
  MatDoub oneda(vector<vector<double> >(mfit,vector<double>(1, 0.0))),
    temp(vector<vector<double> >(mfit, vector<double>(mfit, 0.0)));
  //MatDoub oneda(mfit,1), temp(mfit,mfit);
  mrqcof(a,alpha,beta);
  for (j=0;j<ma;j++) atry[j]=a[j];
  ochisq=chisq;
  for (iter=0;iter<ITMAX;iter++) {
    if (done==NDONE) alamda=0.;
    for (j=0;j<mfit;j++) {
      for (k=0;k<mfit;k++) covar[j][k]=alpha[j][k];
      covar[j][j]=alpha[j][j]*(1.0+alamda);
      for (k=0;k<mfit;k++) temp[j][k]=covar[j][k];
      oneda[j][0]=beta[j];
    }
    gaussj(temp,oneda);
    for (j=0;j<mfit;j++) {
      for (k=0;k<mfit;k++) covar[j][k]=temp[j][k];
      da[j]=oneda[j][0];
    }
    if (done==NDONE) {
      covsrt(covar);
      covsrt(alpha);
      return;
    }
    for (j=0,l=0;l<ma;l++)
      if (ia[l]) atry[l]=a[l]+da[j++];
    mrqcof(atry,covar,da);
    if (fabs(chisq-ochisq) < MAX(tol,tol*chisq)) done++;
    if (chisq < ochisq) {
      alamda *= 0.1;
      ochisq=chisq;
      for (j=0;j<mfit;j++) {
	for (k=0;k<mfit;k++) alpha[j][k]=covar[j][k];
	beta[j]=da[j];
      }
      for (l=0;l<ma;l++) a[l]=atry[l];
    } else {
      alamda *= 10.0;
      chisq=ochisq;
    }
  }
  throw("Fitmrq too many iterations");
}


void FitNonlinear::mrqcof(const vector<double> &a, MatDoub_O &alpha, vector<double> &beta) {
  int i,j,k,l,m;
  double ymod,wt,sig2i,dy;
  vector<double> dyda(ma);
  for (j=0;j<mfit;j++) {
    for (k=0;k<=j;k++) alpha[j][k]=0.0;
    beta[j]=0.;
  }
  chisq=0.;
  for (i=0;i<ndat;i++) {
    funcs(x[i],a,ymod,dyda);
    sig2i=1.0/(sig[i]*sig[i]);
    dy=y[i]-ymod;
    for (j=0,l=0;l<ma;l++) {
      if (ia[l]) {
	wt=dyda[l]*sig2i;
	for (k=0,m=0;m<l+1;m++)
	  if (ia[m]) alpha[j][k++] += wt*dyda[m];
	beta[j++] += dy*wt;
      }
    }
    chisq += dy*dy*sig2i;
  }
  for (j=1;j<mfit;j++)
    for (k=0;k<j;k++) alpha[k][j]=alpha[j][k];
}

void FitNonlinear::covsrt(MatDoub_IO &covar) {
  int i,j,k;
  for (i=mfit;i<ma;i++)
    for (j=0;j<i+1;j++) covar[i][j]=covar[j][i]=0.0;
  k=mfit-1;
  for (j=ma-1;j>=0;j--) {
    if (ia[j]) {
      for (i=0;i<ma;i++) SWAP(covar[i][k],covar[i][j]);
      for (i=0;i<ma;i++) SWAP(covar[k][i],covar[j][i]);
      k--;
    }
  }
}

