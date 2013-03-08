#ifndef FIT_HPP
#define FIT_HPP

#include "NumericalRecipes.hpp"
#include "GaussJordanElimination.hpp"
#include "SingularValueDecomposition.hpp"
//using WaveformUtilities::SVD;
#include "Utilities.hpp"

namespace WaveformUtilities {
  
  class PolynomialBasisFunctions {
  private:
    unsigned int Order;
  public:
    PolynomialBasisFunctions(const unsigned int Ord) : Order(Ord) { }
    VecDoub operator()(Doub x) const {
      VecDoub ans(Order+1);
      ans[0] = 1.0;
      for (unsigned int i=1;i<Order+1;i++) { ans[i] = x*ans[i-1]; }
      return ans;
    }
    Doub operator()(VecDoub_I& a, Doub x) const {
      double p=a[Order];
      for(int j=Order-1; j>=0; --j) p=p*x+a[j];
      return p;
    }
    VecDoub operator()(VecDoub_I &xx) const { // This is just for testing multi-dimensional fits
      if(Order != 2) Throw1WithMessage("This hack was programmed only for Order==2");
      VecDoub ans(6);
      Doub x=xx[0], y=xx[1];
      ans[0] = 1;
      ans[1] = x;
      ans[2] = y;
      ans[3] = x*x;
      ans[4] = x*y;
      ans[5] = y*y;
      return ans;
    }
  };
  
  template <class BasisFunctions>
  struct Fit {
    Int ndat, ma;
    VecDoub_I &x,&y,&sig;
    //VecDoub (*funcs)(const Doub); // <replaced />
    const BasisFunctions& funcs; // <replacement />
    VecBool ia;
    
    VecDoub a;
    MatDoub covar;
    Doub chisq;
    
    //Fit(VecDoub_I &xx, VecDoub_I &yy, VecDoub_I &ssig, VecDoub funks(const Doub)) // <replaced />
    Fit(VecDoub_I &xx, VecDoub_I &yy, VecDoub_I &ssig, const BasisFunctions& funks) // <replacement />
      : ndat(xx.size()), x(xx), y(yy), sig(ssig), funcs(funks) {
      ma = funcs(x[0]).size();
      a.resize(ma);
      covar.resize(ma,ma);
      ia.resize(ma);
      for (Int i=0;i<ma;i++) ia[i] = true;		
    }
    
    void hold(const Int i, const Doub val) {ia[i]=false; a[i]=val;}
    void free(const Int i) {ia[i]=true;}
    
    void fit() {
      Int i,j,k,l,m,mfit=0;
      Doub ym,wt,sum,sig2i;
      VecDoub afunc(ma);
      for (j=0;j<ma;j++) if (ia[j]) mfit++;
      if (mfit == 0) Throw1WithMessage("lfit: no parameters to be fitted");
      MatDoub temp(mfit,mfit,0.),beta(mfit,1,0.);
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
  };
  
  
  template <class BasisFunctions>
  struct FitSVD {
    Int ndat, ma;
    Doub tol;
    VecDoub_I *x,&y,&sig;
    //VecDoub (*funcs)(const Doub);
    const BasisFunctions& funcs;
    VecDoub a;
    MatDoub covar;
    Doub chisq;
    
    MatDoub_I *xmd;
    // VecDoub (*funcsmd)(VecDoub_I &);
    const BasisFunctions& funcsmd;
    
    FitSVD(VecDoub_I &xx, VecDoub_I &yy, VecDoub_I &ssig,
	   //VecDoub funks(const Doub), const Doub TOL=1.e-12)
	   const BasisFunctions& funks, const Doub TOL=1.e-12)
      : ndat(yy.size()), x(&xx), y(yy), sig(ssig),
	funcs(funks), tol(TOL), xmd(NULL), funcsmd(funks) {}
    
    void fit() {
      Int i,j,k;
      Doub tmp,thresh,sum;
      if (x) ma = funcs((*x)[0]).size();
      else ma = funcsmd(row(*xmd,0)).size();
      a.resize(ma);
      covar.resize(ma,ma);
      MatDoub aa(ndat,ma);
      VecDoub b(ndat),afunc(ma);
      for (i=0;i<ndat;i++) {
	if (x) afunc=funcs((*x)[i]);
	else afunc=funcsmd(row(*xmd,i));
	tmp=1.0/sig[i];
	for (j=0;j<ma;j++) aa[i][j]=afunc[j]*tmp;
	b[i]=y[i]*tmp;
      }
      WaveformUtilities::SVD svd(aa);
      thresh = (tol > 0. ? tol*svd.w[0] : -1.);
      svd.solve(b,a,thresh);
      chisq=0.0;
      for (i=0;i<ndat;i++) {
	sum=0.;
	for (j=0;j<ma;j++) sum += aa[i][j]*a[j];
	chisq += SQR(sum-b[i]);
      }
      for (i=0;i<ma;i++) {
	for (j=0;j<i+1;j++) {
	  sum=0.0;
	  for (k=0;k<ma;k++) if (svd.w[k] > svd.tsh)
			       sum += svd.v[i][k]*svd.v[j][k]/SQR(svd.w[k]);
	  covar[j][i]=covar[i][j]=sum;
	}
      }
    }
    
    // The following three lines were moved up in this file for compilation
    //MatDoub_I *xmd;
    // // VecDoub (*funcsmd)(VecDoub_I &);
    //const BasisFunctions& funcsmd;
    
    FitSVD(MatDoub_I &xx, VecDoub_I &yy, VecDoub_I &ssig,
	   //VecDoub funks(VecDoub_I &), const Doub TOL=1.e-12)
	   const BasisFunctions& funks, const Doub TOL=1.e-12)
      : ndat(yy.size()), x(NULL), y(yy), sig(ssig),
	funcs(funks), tol(TOL), xmd(&xx), funcsmd(funks) {}
    
    VecDoub row(MatDoub_I &a, const Int i) {
      Int j,n=a.ncols();
      VecDoub ans(n);
      for (j=0;j<n;j++) ans[j] = a[i][j];
      return ans;
    }
  };
  
  
  template <class BasisFunctions>
  struct FitNonlinear {
    //static const Int NDONE=4, ITMAX=1000; // increasing ITMAX
    static const Int NDONE=4, ITMAX=5000;
    Int ndat, ma, mfit;
    VecDoub_I &x,&y,&sig;
    Doub tol;
    //void (*funcs)(const Doub, VecDoub_I &, Doub &, VecDoub_O &); // replacing this with line below
    const BasisFunctions& funcs; // makes this class templated on a functor
    VecBool ia;
    MatDoub alpha;
    VecDoub a;
    MatDoub covar;
    Doub chisq;
    
    //FitNonlinear(VecDoub_I &xx, VecDoub_I &yy, VecDoub_I &ssig, VecDoub_I &aa,       // replacing these with lines below
    //		 void funks(const Doub, VecDoub_I &, Doub &, VecDoub_O &), const Doub
    FitNonlinear(VecDoub_I &xx, VecDoub_I &yy, VecDoub_I &ssig, VecDoub_I &aa,         // makes this class templated on a functor
		 const BasisFunctions& funks, const Doub
		 TOL=1.e-3) : ndat(xx.size()), ma(aa.size()), x(xx), y(yy), sig(ssig),
			      tol(TOL), funcs(funks), ia(ma), alpha(ma,ma), a(aa), covar(ma,ma) {
      for (Int i=0;i<ma;i++) ia[i] = true;
    }
    
    void hold(const Int i, const Doub val) {ia[i]=false; a[i]=val;}
    void free(const Int i) {ia[i]=true;}
    
    void fit() {
      Int j,k,l,iter,done=0;
      Doub alamda=.001,ochisq;
      VecDoub atry(ma),beta(ma),da(ma);
      mfit=0;
      for (j=0;j<ma;j++) if (ia[j]) mfit++;
      MatDoub oneda(mfit,1), temp(mfit,mfit);
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
	//if (abs(chisq-ochisq) < MAX(tol,tol*chisq)) done++;
	if (std::abs(chisq-ochisq) < MAX(tol,tol*chisq)) done++;
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
      Throw1WithMessage("Fitmrq too many iterations");
    }
    
    void mrqcof(VecDoub_I &a, MatDoub_O &alpha, VecDoub_O &beta) {
      Int i,j,k,l,m;
      Doub ymod,wt,sig2i,dy;
      VecDoub dyda(ma);
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
    
    void covsrt(MatDoub_IO &covar) {
      Int i,j,k;
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
    
  };

  
}

#endif // FIT_HPP
