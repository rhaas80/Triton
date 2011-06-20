
template<class T>
inline T SQR(const T a) {return a*a;}

template<class T>
inline const T &MAX(const T &a, const T &b)
        {return b > a ? (b) : (a);}

inline float MAX(const double &a, const float &b)
        {return b > a ? (b) : float(a);}

inline float MAX(const float &a, const double &b)
        {return b > a ? float(b) : (a);}

template<class T>
inline const T &MIN(const T &a, const T &b)
        {return b < a ? (b) : (a);}

inline float MIN(const double &a, const float &b)
        {return b < a ? (b) : float(a);}

inline float MIN(const float &a, const double &b)
        {return b < a ? float(b) : (a);}

#define throw(message) \
{printf("ERROR: %s\n     in file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

template <class D>
struct StepperBS : StepperBase {
  typedef D Dtype;
  static const int KMAXX=8,IMAXX=KMAXX+1;
  int k_targ;
  std::vector<int> nseq;
  std::vector<int> cost;
  std::vector<std::vector<double> > table;
  std::vector<double> dydxnew;
  int mu;
  std::vector<std::vector<double> > coeff;
  std::vector<double> errfac;
  std::vector<std::vector<double> > ysave;
  std::vector<std::vector<double> > fsave;
  std::vector<int> ipoint;
  std::vector<double> dens;
  StepperBS(std::vector<double> &yy, std::vector<double> &dydxx, double &xx, const double atol,
	    const double rtol, bool dens);
  void step(const double htry,D &derivs);
  virtual void dy(const std::vector<double> &y, const double htot, const int k, std::vector<double> &yend,
		  int &ipt, D &derivs);
  void polyextr(const int k, std::vector<std::vector<double> > &table, std::vector<double> &last);
  virtual void prepare_dense(const double h,const std::vector<double> &dydxnew, const std::vector<double> &ysav,
			     const std::vector<double> &scale, const int k, double &error);
  virtual double dense_out(const int i,const double x,const double h);
  virtual void dense_interp(const int n, std::vector<double> &y, const int imit);
};
template <class D>
StepperBS<D>::StepperBS(std::vector<double> &yy,std::vector<double> &dydxx,double &xx,
			const double atoll,const double rtoll, bool dens) :
  StepperBase(yy,dydxx,xx,atoll,rtoll,dens),nseq(IMAXX),cost(IMAXX),
  table(KMAXX,n),dydxnew(n),coeff(IMAXX,IMAXX),errfac(2*IMAXX+2),ysave(IMAXX,n),
  fsave(IMAXX*(2*IMAXX+1),n),ipoint(IMAXX+1),dens((2*IMAXX+5)*n) {
  EPS=std::numeric_limits<double>::epsilon();
  if (dense)
    for (int i=0;i<IMAXX;i++)
      nseq[i]=4*i+2;
  else
    for (int i=0;i<IMAXX;i++)
      nseq[i]=2*(i+1);
  cost[0]=nseq[0]+1;
  for (int k=0;k<KMAXX;k++) cost[k+1]=cost[k]+nseq[k+1];
  hnext=-1.0e99;
  double logfact=-log10(MAX(1.0e-12,rtol))*0.6+0.5;
  k_targ=MAX(1,MIN(KMAXX-1,int(logfact)));
  for (int k = 0; k<IMAXX; k++) {
    for (int l=0; l<k; l++) {
      double ratio=double(nseq[k])/nseq[l];
      coeff[k][l]=1.0/(ratio*ratio-1.0);
    }
  }
  for (int i=0; i<2*IMAXX+1; i++) {
    int ip5=i+5;
    errfac[i]=1.0/(ip5*ip5);
    double e = 0.5*sqrt(double(i+1)/ip5);
    for (int j=0; j<=i; j++) {
      errfac[i] *= e/(j+1);
    }
  }
  ipoint[0]=0;
  for (int i=1; i<=IMAXX; i++) {
    int njadd=4*i-2;
    if (nseq[i-1] > njadd) njadd++;
    ipoint[i]=ipoint[i-1]+njadd;
  }
}
template <class D>
double StepperBS<D>::dense_out(const int i,const double x,const double h) {
  double theta=(x-xold)/h;
  double theta1=1.0-theta;
  double yinterp=dens[i]+theta*(dens[n+i]+theta1*(dens[2*n+i]*theta
						+dens[3*n+i]*theta1));
  if (mu<0)
    return yinterp;
  double theta05=theta-0.5;
  double t4=SQR(theta*theta1);
  double c=dens[n*(mu+4)+i];
  for (int j=mu;j>0; j--)
    c=dens[n*(j+3)+i]+c*theta05/j;
  yinterp += t4*c;
  return yinterp;
}
template <class D>
void StepperBS<D>::dense_interp(const int n, std::vector<double> &y, const int imit) {
  double y0,y1,yp0,yp1,ydiff,aspl,bspl,ph0,ph1,ph2,ph3,fac1,fac2;
  std::vector<double> a(31);
  for (int i=0; i<n; i++) {
    y0=y[i];
    y1=y[2*n+i];
    yp0=y[n+i];
    yp1=y[3*n+i];
    ydiff=y1-y0;
    aspl=-yp1+ydiff;
    bspl=yp0-ydiff;
    y[n+i]=ydiff;
    y[2*n+i]=aspl;
    y[3*n+i]=bspl;
    if (imit < 0) continue;
    ph0=(y0+y1)*0.5+0.125*(aspl+bspl);
    ph1=ydiff+(aspl-bspl)*0.25;
    ph2=-(yp0-yp1);
    ph3=6.0*(bspl-aspl);
    if (imit >= 1) {
      a[1]=16.0*(y[5*n+i]-ph1);
      if (imit >= 3) {
	a[3]=16.0*(y[7*n+i]-ph3+3*a[1]);
	for (int im=5; im <=imit; im+=2) {
	  fac1=im*(im-1)/2.0;
	  fac2=fac1*(im-2)*(im-3)*2.0;
	  a[im]=16.0*(y[(im+4)*n+i]+fac1*a[im-2]-fac2*a[im-4]);
	}
      }
    }
    a[0]=(y[4*n+i]-ph0)*16.0;
    if (imit >= 2) {
      a[2]=(y[n*6+i]-ph2+a[0])*16.0;
      for (int im=4; im <=imit; im+=2) {
	fac1=im*(im-1)/2.0;
	fac2=im*(im-1)*(im-2)*(im-3);
	a[im]=(y[n*(im+4)+i]+a[im-2]*fac1-a[im-4]*fac2)*16.0;
      }
    }
    for (int im=0; im<=imit; im++)
      y[n*(im+4)+i]=a[im];
  }
}
template <class D>
void StepperBS<D>::dy(const std::vector<double> &y,const double htot,const int k,std::vector<double> &yend,
		      int &ipt,D &derivs) {
  std::vector<double> ym(n),yn(n);
  int nstep=nseq[k];
  double h=htot/nstep;
  for (int i=0;i<n;i++) {
    ym[i]=y[i];
    yn[i]=y[i]+h*dydx[i];
  }
  double xnew=x+h;
  derivs(xnew,yn,yend);
  double h2=2.0*h;
  for (int nn=1;nn<nstep;nn++) {
    if (dense && nn == nstep/2) {
      for (int i=0;i<n;i++)
	ysave[k][i]=yn[i];
    }
    if (dense && fabs(nn-nstep/2) <= 2*k+1) {
      ipt++;
      for (int i=0;i<n;i++)
	fsave[ipt][i]=yend[i];
    }
    for (int i=0;i<n;i++) {
      double swap=ym[i]+h2*yend[i];
      ym[i]=yn[i];
      yn[i]=swap;
    }
    xnew += h;
    derivs(xnew,yn,yend);
  }
  if (dense && nstep/2 <= 2*k+1) {
    ipt++;
    for (int i=0;i<n;i++)
      fsave[ipt][i]=yend[i];
  }
  for (int i=0;i<n;i++)
    yend[i]=0.5*(ym[i]+yn[i]+h*yend[i]);
}
template <class D>
void StepperBS<D>::polyextr(const int k, std::vector<std::vector<double> > &table, std::vector<double> &last) {
  int l=last.size();
  for (int j=k-1; j>0; j--)
    for (int i=0; i<l; i++)
      table[j-1][i]=table[j][i]+coeff[k][j]*(table[j][i]-table[j-1][i]);
  for (int i=0; i<l; i++)
    last[i]=table[0][i]+coeff[k][0]*(table[0][i]-last[i]);
}
template <class D>
void StepperBS<D>::prepare_dense(const double h,const std::vector<double> &dydxnew,
				 const std::vector<double> &ysav,const std::vector<double> &scale,const int k,double &error) {
  mu=2*k-1;
  for (int i=0; i<n; i++) {
    dens[i]=ysav[i];
    dens[n+i]=h*dydx[i];
    dens[2*n+i]=y[i];
    dens[3*n+i]=dydxnew[i]*h;
  }
  for (int j=1; j<=k; j++) {
    double dblenj=nseq[j];
    for (int l=j; l>=1; l--) {
      double factor=SQR(dblenj/nseq[l-1])-1.0;
      for (int i=0; i<n; i++)
	ysave[l-1][i]=ysave[l][i]+(ysave[l][i]-ysave[l-1][i])/factor;
    }
  }
  for (int i=0; i<n; i++)
    dens[4*n+i]=ysave[0][i];
  for (int kmi=1; kmi<=mu; kmi++) {
    int kbeg=(kmi-1)/2;
    for (int kk=kbeg; kk<=k; kk++) {
      double facnj=pow(nseq[kk]/2.0,kmi-1);
      int ipt=ipoint[kk+1]-2*kk+kmi-3;
      for (int i=0; i<n; i++)
	ysave[kk][i]=fsave[ipt][i]*facnj;
    }
    for (int j=kbeg+1; j<=k; j++) {
      double dblenj=nseq[j];
      for (int l=j; l>=kbeg+1; l--) {
	double factor=SQR(dblenj/nseq[l-1])-1.0;
	for (int i=0; i<n; i++)
	  ysave[l-1][i]=ysave[l][i]+
	    (ysave[l][i]-ysave[l-1][i])/factor;
      }
    }
    for (int i=0; i<n; i++)
      dens[(kmi+4)*n+i]=ysave[kbeg][i]*h;
    if (kmi == mu) continue;
    for (int kk=kmi/2; kk<=k; kk++) {
      int lbeg=ipoint[kk+1]-1;
      int lend=ipoint[kk]+kmi;
      if (kmi == 1) lend += 2;
      for (int l=lbeg; l>=lend; l-=2)
	for (int i=0; i<n; i++)
	  fsave[l][i]=fsave[l][i]-fsave[l-2][i];
      if (kmi == 1) {
	int l=lend-2;
	for (int i=0; i<n; i++)
	  fsave[l][i]=fsave[l][i]-dydx[i];
      }
    }
    for (int kk=kmi/2; kk<=k; kk++) {
      int lbeg=ipoint[kk+1]-2;
      int lend=ipoint[kk]+kmi+1;
      for (int l=lbeg; l>=lend; l-=2)
	for (int i=0; i<n; i++)
	  fsave[l][i]=fsave[l][i]-fsave[l-2][i];
    }
  }
  dense_interp(n,dens,mu);
  error=0.0;
  if (mu >= 1) {
    for (int i=0; i<n; i++)
      error += SQR(dens[(mu+4)*n+i]/scale[i]);
    error=sqrt(error/n)*errfac[mu-1];
  }
}
template <class D>
void StepperBS<D>::step(const double htry,D &derivs) {
  const double STEPFAC1=0.65,STEPFAC2=0.94,STEPFAC3=0.02,STEPFAC4=4.0,
    KFAC1=0.8,KFAC2=0.9;
  static bool first_step=true,last_step=false;
  static bool forward,reject=false,prev_reject=false;
  int i,k;
  double fac,h,hnew,hopt_int=0,err;
  bool firstk;
  std::vector<double> hopt(IMAXX),work(IMAXX);
  std::vector<double> ysav(n),yseq(n);
  std::vector<double> ymid(n),scale(n);
  work[0]=0;
  h=htry;
  forward = h>0 ? true : false;
  for (i=0;i<n;i++) ysav[i]=y[i];
  if (h != hnext && !first_step) {
    last_step=true;
  }
  if (reject) {
    prev_reject=true;
    last_step=false;
  }
  reject=false;
  firstk=true;
  hnew=fabs(h);
 interp_error:
  while (firstk || reject) {
    h = forward ? hnew : -hnew;
    firstk=false;
    reject=false;
    if (fabs(h) <= fabs(x)*EPS)
      throw("step size underflow in StepperBS");
    int ipt=-1;
    for (k=0; k<=k_targ+1;k++) {
      dy(ysav,h,k,yseq,ipt,derivs);
      if (k == 0)
	y=yseq;
      else
	for (i=0;i<n;i++)
	  table[k-1][i]=yseq[i];
      if (k != 0) {
	polyextr(k,table,y);
	err=0.0;
	for (i=0;i<n;i++) {
	  scale[i]=atol+rtol*MAX(fabs(ysav[i]),fabs(y[i]));
	  err+=SQR((y[i]-table[0][i])/scale[i]);
	}
	err=sqrt(err/n);
	double expo=1.0/(2*k+1);
	double facmin=pow(STEPFAC3,expo);
	if (err == 0.0)
	  fac=1.0/facmin;
	else {
	  fac=STEPFAC2/pow(err/STEPFAC1,expo);
	  fac=MAX(facmin/STEPFAC4,MIN(1.0/facmin,fac));
	}
	hopt[k]=fabs(h*fac);
	work[k]=cost[k]/hopt[k];
	if ((first_step || last_step) && err <= 1.0)
	  break;
	if (k == k_targ-1 && !prev_reject && !first_step && !last_step) {
	  if (err <= 1.0)
	    break;
	  else if (err>SQR(nseq[k_targ]*nseq[k_targ+1]/(nseq[0]*nseq[0]))) {
	    reject=true;
	    k_targ=k;
	    if (k_targ>1 && work[k-1]<KFAC1*work[k])
	      k_targ--;
	    hnew=hopt[k_targ];
	    break;
	  }
	}
	if (k == k_targ) {
	  if (err <= 1.0)
	    break;
	  else if (err>SQR(nseq[k+1]/nseq[0])) {
	    reject=true;
	    if (k_targ>1 && work[k-1]<KFAC1*work[k])
	      k_targ--;
	    hnew=hopt[k_targ];
	    break;
	  }
	}
	if (k == k_targ+1) {
	  if (err > 1.0) {
	    reject=true;
	    if (k_targ>1 && work[k_targ-1]<KFAC1*work[k_targ])
	      k_targ--;
	    hnew=hopt[k_targ];
	  }
	  break;
	}
      }
    }
    if (reject)
      prev_reject=true;
  }
  derivs(x+h,y,dydxnew);
  if (dense) {
    prepare_dense(h,dydxnew,ysav,scale,k,err);
    hopt_int=h/MAX(pow(err,1.0/(2*k+3)),0.01);
    if (err > 10.0) {
      hnew=fabs(hopt_int);
      reject=true;
      prev_reject=true;
      goto interp_error;
    }
  }
  dydx=dydxnew;
  xold=x;
  x+=h;
  hdid=h;
  first_step=false;
  int kopt;
  if (k == 1)
    kopt=2;
  else if (k <= k_targ) {
    kopt=k;
    if (work[k-1] < KFAC1*work[k])
      kopt=k-1;
    else if (work[k] < KFAC2*work[k-1])
      kopt=MIN(k+1,KMAXX-1);
  } else {
    kopt=k-1;
    if (k > 2 && work[k-2] < KFAC1*work[k-1])
      kopt=k-2;
    if (work[k] < KFAC2*work[kopt])
      kopt=MIN(k,KMAXX-1);
  }
  if (prev_reject) {
    k_targ=MIN(kopt,k);
    hnew=MIN(fabs(h),hopt[k_targ]);
    prev_reject=false;
  }
  else {
    if (kopt <= k)
      hnew=hopt[kopt];
    else {
      if (k<k_targ && work[k]<KFAC2*work[k-1])
	hnew=hopt[k]*cost[kopt+1]/cost[k];
      else
	hnew=hopt[k]*cost[kopt]/cost[k];
    }
    k_targ=kopt;
  }
  if (dense)
    hnew=MIN(hnew,fabs(hopt_int));
  if (forward)
    hnext=hnew;
  else
    hnext=-hnew;	
}
