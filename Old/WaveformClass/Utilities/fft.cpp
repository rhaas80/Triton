#include "fft.hpp"
#include <cmath>

#include <iostream>

using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

vector<double> TimeToFrequency(const vector<double>& Time) {
  // This returns the double-sided frequency-space equivalent of a time vector
  vector<double> Freq(Time.size(), 0.0);
  const int i0 = int(-floor((static_cast<int>(Time.size())-1.0)/2.0));
  const int i1 = int(Time.size());
  const double df = 1.0 / (i1 * (Time[1]-Time[0]));
  for(int i=0; i<i1; ++i) { Freq[i] = (i0+i)*df; }
  return Freq;
}

class VectorRearranger {
  // This class is basically just here to provide an indexing
  // operator like Num. Rec. wants, while using data stored
  // separately as real and imaginary parts.
  
protected: // Member data
  vector<double>& Real;
  vector<double>& Imag;
  unsigned int n;
  
public: // Constructor and destructor
  VectorRearranger(vector<double>& Re, vector<double>& Im)
    : Real(Re), Imag(Im), n(Real.size()) { }
  virtual ~VectorRearranger() { }
  
public: // Access function
  virtual double& operator[](const unsigned int i) { if(i%2==0) { return Real[i/2]; } else { return Imag[(i-1)/2]; } }
};

class VectorRearrangerReal : public VectorRearranger {
public: // Constructor
  VectorRearrangerReal(vector<double>& Re)
    : VectorRearranger(Re, Re) { }
  ~VectorRearrangerReal() { }
public: // Access function
  double& operator[](const unsigned int i) { return Real[i]; }
  unsigned int size() const { return Real.size(); }
};

void SwapVectorHalvesFromNumRecForm(vector<double>& V, const double Norm) {
  // Given a vector in Num. Rec. form (Fig. 12.2.2), this rearranges
  // its components to the more sensible (-fs/2,fs/2] form.
  double L=V[V.size()/2-1];
  double R=V[V.size()/2];
  unsigned int iHalf = V.size()/2;
  for(unsigned int i=0; i<iHalf-1; ++i) {
    V[i+iHalf-1]=V[i]/Norm;
    V[i] = V[i+iHalf+1]/Norm;
  }
  V[V.size()-2]=L/Norm;
  V[V.size()-1]=R/Norm;
  return;
}

void SwapVectorHalvesToNumRecForm(vector<double>& V, const double Norm) {
  // Given a vector in the more sensible (-fs/2,fs/2] form, this
  // rearranges its components to Num. Rec. form (Fig. 12.2.2).
  double L=V[V.size()-2];
  double R=V[V.size()-1];
  unsigned int iHalf = V.size()/2;
  for(unsigned int i=iHalf-2; i>=1; --i) {
    V[i+iHalf+1]=V[i]/Norm;
    V[i] = V[i+iHalf-1]/Norm;
  }
  V[iHalf+1]=V[0]/Norm;
  V[0] = V[iHalf-1]/Norm;
  V[iHalf-1]=L/Norm;
  V[iHalf-0]=R/Norm;
  return;
}

void four1(VectorRearranger& Data, const unsigned int n, const int isign);

void  fft(const vector<double>& ReT, const vector<double>& ImT, vector<double>& ReF, vector<double>& ImF) {
  ReF = ReT;
  ImF = ImT;
  VectorRearranger Data(ReF, ImF);
  four1(Data, ReT.size(), -1);
  SwapVectorHalvesFromNumRecForm(ReF, static_cast<double>(ReT.size()));
  SwapVectorHalvesFromNumRecForm(ImF, static_cast<double>(ReT.size()));
  return;
}

void  ifft(const vector<double>& ReF, const vector<double>& ImF, vector<double>& ReT, vector<double>& ImT) {
  ReT = ReF;
  ImT = ImF;
  SwapVectorHalvesToNumRecForm(ReT);
  SwapVectorHalvesToNumRecForm(ImT);
  VectorRearranger Data(ReT, ImT);
  four1(Data, ReF.size(), 1);
  return;
}

void fft (const vector<double>& T, const vector<double>& ReT, const vector<double>& ImT, vector<double>& F, vector<double>& ReF, vector<double>& ImF) {
  F = TimeToFrequency(T);
  fft(ReT, ImT, ReF, ImF);
  return;
}


//// Numerical Recipes routine
template<class T>
inline void SWAP(T &a, T &b) {T dum=a; a=b; b=dum; return;}
void four1(VectorRearranger& data, const unsigned int n, const int isign) {
  int nn,mmax,m,j,istep,i;
  double wtemp,wr,wpr,wpi,wi,theta,tempr,tempi;
  if (n<2 || n&(n-1)) throw("n must be power of 2 in four1");
  nn = n << 1;
  j = 1;
  for (i=1;i<nn;i+=2) {
    if (j > i) {
      SWAP(data[j-1],data[i-1]);
      SWAP(data[j],data[i]);
    }
    m=n;
    while (m >= 2 && j > m) {
      j -= m;
      m >>= 1;
    }
    j += m;
  }
  mmax=2;
  while (nn > mmax) {
    istep=mmax << 1;
    theta=isign*(2*M_PI/mmax);
    wtemp=sin(0.5*theta);
    wpr = -2.0*wtemp*wtemp;
    wpi=sin(theta);
    wr=1.0;
    wi=0.0;
    for (m=1;m<mmax;m+=2) {
      for (i=m;i<=nn;i+=istep) {
	j=i+mmax;
	tempr=wr*data[j-1]-wi*data[j];
	tempi=wr*data[j]+wi*data[j-1];
	data[j-1]=data[i-1]-tempr;
	data[j]=data[i]-tempi;
	data[i-1] += tempr;
	data[i] += tempi;
      }
      wr=(wtemp=wr)*wpr-wi*wpi+wr;
      wi=wi*wpr+wtemp*wpi+wi;
    }
    mmax=istep;
  }
  return;
}

void realft(vector<double>& Data, const int isign) {
  VectorRearrangerReal data(Data);
  int i,i1,i2,i3,i4,n=data.size();
  double c1=0.5,c2,h1r,h1i,h2r,h2i,wr,wi,wpr,wpi,wtemp;
  double theta=3.141592653589793238/double(n>>1);
  if (isign == 1) {
    c2 = -0.5;
    four1(data,n/2,1);
  } else {
    c2=0.5;
    theta = -theta;
  }
  wtemp=sin(0.5*theta);
  wpr = -2.0*wtemp*wtemp;
  wpi=sin(theta);
  wr=1.0+wpr;
  wi=wpi;
  for (i=1;i<(n>>2);i++) {
    i2=1+(i1=i+i);
    i4=1+(i3=n-i1);
    h1r=c1*(data[i1]+data[i3]);
    h1i=c1*(data[i2]-data[i4]);
    h2r= -c2*(data[i2]+data[i4]);
    h2i=c2*(data[i1]-data[i3]);
    data[i1]=h1r+wr*h2r-wi*h2i;
    data[i2]=h1i+wr*h2i+wi*h2r;
    data[i3]=h1r-wr*h2r+wi*h2i;
    data[i4]= -h1i+wr*h2i+wi*h2r;
    wr=(wtemp=wr)*wpr-wi*wpi+wr;
    wi=wi*wpr+wtemp*wpi+wi;
  }
  if (isign == 1) {
    data[0] = (h1r=data[0])+data[1];
    data[1] = h1r-data[1];
  } else {
    data[0]=c1*((h1r=data[0])+data[1]);
    data[1]=c1*(h1r-data[1]);
    four1(data,n/2,-1);
  }
}

void convlv(const vector<double>& data, const vector<double>& respns, const int isign, vector<double>& ans) {
  int i,no2,n=data.size(),m=respns.size();
  double mag2,tmp;
  vector<double> temp(n);
  temp[0]=respns[0];
  for (i=1;i<(m+1)/2;i++) {
    temp[i]=respns[i];
    temp[n-i]=respns[m-i];
  }
  for (i=(m+1)/2;i<n-(m-1)/2;i++)
    temp[i]=0.0;
  for (i=0;i<n;i++)
    ans[i]=data[i];
  realft(ans,1);
  realft(temp,1);
  no2=n>>1;
  if (isign == 1) {
    for (i=2;i<n;i+=2) {
      tmp=ans[i];
      ans[i]=(ans[i]*temp[i]-ans[i+1]*temp[i+1])/no2;
      ans[i+1]=(ans[i+1]*temp[i]+tmp*temp[i+1])/no2;
    }
    ans[0]=ans[0]*temp[0]/no2;
    ans[1]=ans[1]*temp[1]/no2;
  } else if (isign == -1) {
    for (i=2;i<n;i+=2) {
      if ((mag2=(temp[i])*(temp[i])+(temp[i+1])*(temp[i+1])) == 0.0)
	throw("Deconvolving at response zero in convlv");
      tmp=ans[i];
      ans[i]=(ans[i]*temp[i]+ans[i+1]*temp[i+1])/mag2/no2;
      ans[i+1]=(ans[i+1]*temp[i]-tmp*temp[i+1])/mag2/no2;
    }
    if (temp[0] == 0.0 || temp[1] == 0.0)
      throw("Deconvolving at response zero in convlv");
    ans[0]=ans[0]/temp[0]/no2;
    ans[1]=ans[1]/temp[1]/no2;
  } else throw("No meaning for isign in convlv");
  realft(ans,-1);
  return;
}

vector<double> convlv(const vector<double>& data, const vector<double>& respns, const int isign) {
  vector<double> ans(data.size());
  convlv(data, respns, isign, ans);
  return ans;
}
