#include "fft.hpp"

#include "NumericalRecipes.hpp"
#include "Utilities.hpp"

using namespace std;
namespace WU = WaveformUtilities;

vector<double> WU::TimeToFrequency(const vector<double>& Time) {
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
  virtual inline double& operator[](const unsigned int i) { if(i%2==0) { return Real[i/2]; } else { return Imag[(i-1)/2]; } }
  unsigned int size() const { return n; }
};

class VectorRearrangerReal : public VectorRearranger {
public: // Constructor
  VectorRearrangerReal(vector<double>& Re)
    : VectorRearranger(Re, Re) { }
  ~VectorRearrangerReal() { }
public: // Access function
  inline double& operator[](const unsigned int i) { return Real[i]; }
  unsigned int size() const { return Real.size(); }
};

void SwapVectorHalvesFromNumRecForm(vector<double>& V, const double Norm=1.0) {
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

void SwapVectorHalvesToNumRecForm(vector<double>& V, const double Norm=1.0) {
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

void four1(VectorRearranger& Data, const int n, const int isign);

void WU::fft(const vector<double>& ReT, const vector<double>& ImT, vector<double>& ReF, vector<double>& ImF) {
  ReF = ReT;
  ImF = ImT;
  VectorRearranger Data(ReF, ImF);
  four1(Data, ReT.size(), -1);
  SwapVectorHalvesFromNumRecForm(ReF, static_cast<double>(ReT.size()));
  SwapVectorHalvesFromNumRecForm(ImF, static_cast<double>(ReT.size()));
  return;
}

void WU::ifft(const vector<double>& ReF, const vector<double>& ImF, vector<double>& ReT, vector<double>& ImT) {
  ReT = ReF;
  ImT = ImF;
  SwapVectorHalvesToNumRecForm(ReT);
  SwapVectorHalvesToNumRecForm(ImT);
  VectorRearranger Data(ReT, ImT);
  four1(Data, ReF.size(), 1);
  return;
}

void WU::fft (const vector<double>& T, const vector<double>& ReT, const vector<double>& ImT, vector<double>& F, vector<double>& ReF, vector<double>& ImF) {
  F = TimeToFrequency(T);
  WU::fft(ReT, ImT, ReF, ImF);
  return;
}



//// Numerical Recipes routines
// void four1(Doub *data, const Int n, const Int isign) { // <replaced />
void four1(VectorRearranger& data, const Int n, const Int isign) {
  Int nn,mmax,m,j,istep,i;
  Doub wtemp,wr,wpr,wpi,wi,theta,tempr,tempi;
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
    theta=isign*(6.28318530717959/mmax);
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
}
//void four1(VecDoub_IO &data, const Int isign) { // <replaced />
void four1(VectorRearranger& data, const Int isign) {
  four1(data,data.size()/2,isign);
}

//void realft(VecDoub_IO &data, const Int isign) { // <replaced />
void realft(VecDoub_IO &Data, const Int isign) {
  VectorRearrangerReal data(Data);  cerr << "There may be an error here, at line " << __LINE__ << " of " << __FILE__ << endl;  // <added />
  Int i,i1,i2,i3,i4,n=data.size();
  Doub c1=0.5,c2,h1r,h1i,h2r,h2i,wr,wi,wpr,wpi,wtemp;
  Doub theta=3.141592653589793238/Doub(n>>1);
  if (isign == 1) {
    c2 = -0.5;
    four1(data,1);
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
    four1(data,-1);
  }
}

void convlv(VecDoub_I &data, VecDoub_I &respns, const Int isign, VecDoub_O &ans) {
  Int i,no2,n=data.size(),m=respns.size();
  Doub mag2,tmp;
  VecDoub temp(n);
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
      if ((mag2=SQR(temp[i])+SQR(temp[i+1])) == 0.0)
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
}

vector<double> convlv(const vector<double>& data, const vector<double>& respns, const int isign) {
  vector<double> ans(data.size());
  convlv(data, respns, isign, ans);
  return ans;
}
