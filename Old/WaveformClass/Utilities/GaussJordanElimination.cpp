#include "GaussJordanElimination.hpp"
#include <cstdio>
#include <cmath>
using namespace std;

template<class T>
inline T SQR(const T a) {return a*a;}

template<class T>
inline void SWAP(T &a, T &b) {T dum=a; a=b; b=dum;}

// template<class T>
// inline T abs(const T b) { return (b<0 ? -b : b); }

inline double MAX(const double& A, const double& B) { return (A>B ? A : B); }

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

typedef std::vector<std::vector<double> > MatDoub, MatDoub_IO, MatDoub_O;

void GaussJordanElimination(MatDoub_IO &A, vector<double> &b) {
  MatDoub_IO B(b.size(), vector<double>(1, 0.0));
  for(unsigned int i=0; i<b.size(); ++i) {
    B[i][0] = b[i];
  }
  GaussJordanElimination(A,B);
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = B[i][0];
  }
  return;
}

void GaussJordanElimination(MatDoub_IO &a, MatDoub_IO &b)
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
    if (a[icol][icol] == 0.0) throw("GaussJordanElimination: Singular Matrix");
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


typedef std::vector<std::vector<complex<double> > > CMatDoub, CMatDoub_IO, CMatDoub_O;

void GaussJordanElimination(CMatDoub_IO &A, vector<complex<double> > &b) {
  CMatDoub_IO B(b.size(), vector<complex<double> >(1, 0.0));
  for(unsigned int i=0; i<b.size(); ++i) {
    B[i][0] = b[i];
  }
  GaussJordanElimination(A,B);
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = B[i][0];
  }
  return;
}

void GaussJordanElimination(CMatDoub_IO &a, CMatDoub_IO &b)
{
  /* <Replacements> */
  /* int i,icol,irow,j,k,l,ll,n=a.nrows(),m=b.ncols(); */
  int i,icol=0,irow=0,j,k,l,ll,n=a.size(),m=b[0].size();
  /* double big, dum,pivinv; */
  double big;
  complex<double> dum,pivinv;
  /* </Replacements> */
  std::vector<int> indxc(n),indxr(n),ipiv(n);
  for (j=0;j<n;j++) ipiv[j]=0;
  for (i=0;i<n;i++) {
    big=0.0;
    for (j=0;j<n;j++)
      if (ipiv[j] != 1)
	for (k=0;k<n;k++) {
	  if (ipiv[k] == 0) {
	    if (abs(a[j][k]) >= big) {
	      big=abs(a[j][k]);
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
    if (abs(a[icol][icol]) == 0.0) throw("GaussJordanElimination (complex): Singular Matrix");
    pivinv=1.0/a[icol][icol];
    a[icol][icol]=complex<double>(1.0, 0.0);
    for (l=0;l<n;l++) a[icol][l] *= pivinv;
    for (l=0;l<m;l++) b[icol][l] *= pivinv;
    for (ll=0;ll<n;ll++)
      if (ll != icol) {
	dum=a[ll][icol];
	a[ll][icol]=complex<double>(0.0, 0.0);
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

/* void gaussj(CMatDoub_IO &a) */
/* { */
/*   CMatDoub b(a.nrows(),0); */
/*   gaussj(a,b); */
/* } */
