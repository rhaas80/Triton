#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include "SavitzkyGolaySmoothing.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}


// IO
ostream& operator<<(ostream& out, const vector<double>& v) {
  for(unsigned int i=0; i<v.size()-1; ++i) {
    out << v[i] << ", ";
  }
  out << v[v.size()-1] << flush;
  return out;
}

ostream& operator<<(ostream& out, const vector<int>& v) {
  for(unsigned int i=0; i<v.size()-1; ++i) {
    out << v[i] << ", ";
  }
  out << v[v.size()-1] << flush;
  return out;
}


// Arithmetic
vector<double> operator+(const vector<double>& a, const double& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] + b;
  }
  return c;
}
vector<double> operator-(const vector<double>& a, const double& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] - b;
  }
  return c;
}
vector<double> operator*(const vector<double>& a, const double& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] * b;
  }
  return c;
}
vector<double> operator/(const vector<double>& a, const double& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] / b;
  }
  return c;
}
vector<double> operator+(const double& a, const vector<double>& b) { return b+a; }
vector<double> operator-(const double& a, const vector<double>& b) {
  vector<double> c = b;
  for(unsigned int i=0; i<b.size(); ++i) {
    c[i] = a - b[i];
  }
  return c;
}
vector<double> operator*(const double& a, const vector<double>& b) { return b*a; }
vector<double> operator/(const double& a, const vector<double>& b) {
  vector<double> c = b;
  for(unsigned int i=0; i<b.size(); ++i) {
    c[i] = a / b[i];
  }
  return c;
}
vector<vector<double> > operator+(const vector<vector<double> >& a, const double& b) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] + b;
    }
  }
  return c;
}
vector<vector<double> > operator-(const vector<vector<double> >& a, const double& b) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] - b;
    }
  }
  return c;
}
vector<vector<double> > operator*(const vector<vector<double> >& a, const double& b) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] * b;
    }
  }
  return c;
}
vector<vector<double> > operator/(const vector<vector<double> >& a, const double& b) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] / b;
    }
  }
  return c;
}
vector<double> operator+(const vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] + b[i];
  }
  return c;
}
vector<double> operator-(const vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] - b[i];
  }
  return c;
}
vector<double> operator*(const vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] * b[i];
  }
  return c;
}
vector<double> operator/(const vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] / b[i];
  }
  return c;
}
vector<vector<double> > operator+(const vector<vector<double> >& a, const vector<vector<double> >& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  if(a.size()==0) return a;
  if(a[0].size()!=b[0].size()) { throw("Different sizes inside!"); }
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}
vector<vector<double> > operator-(const vector<vector<double> >& a, const vector<vector<double> >& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  if(a.size()==0) return a;
  if(a[0].size()!=b[0].size()) { throw("Different sizes inside!"); }
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] - b[i][j];
    }
  }
  return c;
}
vector<vector<double> > operator*(const vector<vector<double> >& a, const vector<vector<double> >& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  if(a.size()==0) return a;
  if(a[0].size()!=b[0].size()) { throw("Different sizes inside!"); }
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] * b[i][j];
    }
  }
  return c;
}
vector<vector<double> > operator/(const vector<vector<double> >& a, const vector<vector<double> >& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  if(a.size()==0) return a;
  if(a[0].size()!=b[0].size()) { throw("Different sizes inside!"); }
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      c[i][j] = a[i][j] / b[i][j];
    }
  }
  return c;
}

vector<vector<double> >& operator+=(std::vector<std::vector<double> >& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      a[i][j] += b;
    }
  }
  return a;
}

vector<vector<double> >& operator-=(std::vector<std::vector<double> >& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      a[i][j] -= b;
    }
  }
  return a;
}

vector<vector<double> >& operator*=(std::vector<std::vector<double> >& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      a[i][j] *= b;
    }
  }
  return a;
}

vector<vector<double> >& operator/=(std::vector<std::vector<double> >& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    for(unsigned int j=0; j<a[i].size(); ++j) {
      a[i][j] /= b;
    }
  }
  return a;
}

vector<double>& operator+=(vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b[i];
  }
  return a;
}

vector<double>& operator-=(vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] -= b[i];
  }
  return a;
}

vector<double>& operator*=(vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] *= b[i];
  }
  return a;
}

vector<double>& operator/=(vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] /= b[i];
  }
  return a;
}

vector<double>& operator+=(vector<double>& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b;
  }
  return a;
}

vector<double>& operator-=(vector<double>& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] -= b;
  }
  return a;
}

vector<double>& operator*=(vector<double>& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] *= b;
  }
  return a;
}

vector<double>& operator/=(vector<double>& a, const double b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] /= b;
  }
  return a;
}

vector<double>& operator-(vector<double>& a) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] = -a[i];
  }
  return a;
}

vector<complex<double> > operator-(const vector<complex<double> >& a, const double& b) {
  vector<complex<double> > c(a.size());
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = a[i] - b;
  }
  return c;
}

// Higher-level functions
vector<double> sqrt(const vector<double>& a) {
  vector<double> b = a;
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = sqrt(a[i]);
  }
  return b;
}

vector<double> exp(const vector<double>& a) {
  vector<double> b = a;
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = exp(a[i]);
  }
  return b;
}

vector<double> log(const vector<double>& a) {
  vector<double> b = a;
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = log(a[i]);
  }
  return b;
}

vector<double> log10(const vector<double>& a) {
  vector<double> b = a;
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = log10(a[i]);
  }
  return b;
}

vector<double> sin(const vector<double>& a) {
  vector<double> b = a;
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = sin(a[i]);
  }
  return b;
}

vector<double> cos(const vector<double>& a) {
  vector<double> b = a;
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = cos(a[i]);
  }
  return b;
}

vector<vector<double> > sin(const vector<vector<double> >& a) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    for(unsigned int j=0; j<c[i].size(); ++j) {
      c[i][j] = sin(a[i][j]);
    }
  }
  return c;
}

vector<vector<double> > cos(const vector<vector<double> >& a) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    for(unsigned int j=0; j<c[i].size(); ++j) {
      c[i][j] = cos(a[i][j]);
    }
  }
  return c;
}

vector<vector<double> > fabs(const vector<vector<double> >& a) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    for(unsigned int j=0; j<c[i].size(); ++j) {
      c[i][j] = fabs(a[i][j]);
    }
  }
  return c;
}

vector<double> fabs(const vector<double>& a) {
  vector<double> c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = fabs(a[i]);
  }
  return c;
}

double maxfabs(const std::vector<double>& a) {
  double b=fabs(a[0]);
  for(unsigned int i=1; i<a.size(); ++i) { b = (b<fabs(a[i]) ? fabs(a[i]) : b); }
  return b;
}

double maxmag(const std::vector<double>& a, const std::vector<double>& b) {
  double c=sqrt(a[0]*a[0]+b[0]*b[0]);
  double d=0.0;
  for(unsigned int i=1; i<a.size(); ++i) {
    d = sqrt(a[i]*a[i]+b[i]*b[i]);
    if(c<d) { c = d; }
  }
  return c;
}

vector<double> pow(const vector<double>& a, const double& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = pow(a[i], b);
  }
  return c;
}

vector<double> pow(const double& a, const vector<double>& b) {
  vector<double> c(b.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = pow(a, b[i]);
  }
  return c;
}

vector<double> pow(const vector<double>& a, const vector<double>& b) {
  if(a.size()!=b.size()) { throw("Different sizes!"); }
  vector<double> c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = pow(a[i], b[i]);
  }
  return c;
}

vector<double> fmod(const vector<double>& a, const double& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = fmod(a[i], b);
  }
  return c;
}

vector<vector<double> > fmod(const vector<vector<double> >& a, const double& b) {
  vector<vector<double> > c = a;
  for(unsigned int i=0; i<c.size(); ++i) {
    for(unsigned int j=0; j<c[i].size(); ++j) {
      c[i][j] = fmod(a[i][j], b);
    }
  }
  return c;
}

vector<double> atan2(const vector<double>& a, const vector<double>& b) {
  vector<double> c = a;
  for(unsigned int i=0; i<a.size(); ++i) {
    c[i] = atan2(a[i], b[i]);
  }
  return c;
}

vector<complex<double> > exp(const vector<complex<double> >& a) {
  vector<complex<double> > b(a.size());
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = exp(a[i]);
  }
  return b;
}

vector<double> diff(const vector<double>& In) {
  vector<double> Out(In.size()-1, 0.0);
  for(unsigned int i=0; i<Out.size()-1; ++i) {
    Out[i] = In[i+1]-In[i];
  }
  Out.pop_back();
  return Out;
}

double sum(const vector<double>& In) {
  double Out = 0.0;
  for(unsigned int i=0; i<In.size(); ++i) {
    Out += In[i];
  }
  return Out;
}

double avg(const vector<double>& In) { return sum(In)/double(In.size()); }

double trapz(const vector<double>& t, const vector<double>& f) {
  double Integral = 0.0;
  for(unsigned int i=1; i<f.size(); ++i) {
    Integral += ( (f[i] + f[i-1])*(t[i]-t[i-1]) / 2.0 );
  }
  return Integral;
}

vector<double> cumtrapz(const vector<double>& t, const vector<double>& f) {
  vector<double> Integral(f.size(), 0.0);
  for(unsigned int i=1; i<f.size(); ++i) {
    Integral[i] = Integral[i-1] + ( (f[i] + f[i-1])*(t[i]-t[i-1]) / 2.0 );
  }
  return Integral;
}

vector<double> dydx(const vector<double>& y, const vector<double>& x) {
  if(y.size()==0) { return vector<double>(0); }
  vector<double> D = y;
  const unsigned int i1 = y.size()-1;
  D[0] = (y[1]-y[0]) / (x[1]-x[0]);
  for(unsigned int i=1; i<i1; ++i) {
    D[i] = (y[i+1]-y[i-1]) / (x[i+1]-x[i-1]);
  }
  D[i1] = (y[i1]-y[i1-1]) / (x[i1]-x[i1-1]);
  return D;
}

void dydxSmooth(vector<double>& y, vector<double>& x, const int NLeft, const int NRight, const int PolyOrder, const int DerivOrder) {
  if(((x.size()) & (x.size()-1)) != 0) { // We need to pad to a uniformly spaced power of two
    unsigned int N = static_cast<unsigned int>(pow(2.0,ceil(log2(x.size()))));
    double dx = (x[x.size()-1]-x[0])/(N-1);
    vector<double> x2(N, 0.0);
    for(unsigned int i=0; i<N; ++i) {
      x2[i] = x[0] + i*dx;
    }
    y = Interpolate(x, y, x2);
    x = x2;
  }
  double h = min(diff(x));
  y = (Fac(DerivOrder)/h)*SavitzkyGolaySmoothing(y, NLeft, NRight, PolyOrder, DerivOrder);
  return;
}

class TimeSeqRef {
  // This class is just used by the Intersection and Union functions below, and shouldn't be visible outside this file
private:
  const vector<double>& a;  // Earliest part
  const vector<double>& b;  // Middle part
  const vector<double>& c;  // Last part
  unsigned int aSize, bSize, cSize, Size;
public:
  TimeSeqRef(const vector<double>& aa, const vector<double>& bb, const vector<double>& cc)
    : a(aa), b(bb), c(cc), aSize(aa.size()), bSize(b.size()), cSize(c.size()), Size(aSize+bSize+cSize) { }
  unsigned int size() const { return Size; }
  double operator[](const unsigned int I) const {
    if(I<aSize) { return a[I]; }
    else if(I<aSize+bSize) { return b[I-aSize]; }
    else if(I<Size) { return c[I-aSize-bSize]; }
    else {
      cerr << "Bad index I=" << I << " >= Size=" << Size << endl;
      exit(1);
    }
  }
};

vector<double> Intersection(const TimeSeqRef& t1, const TimeSeqRef& t2, const double& MinStep=0.0, const double& MinTime=0.0) {
  vector<double> t(t1.size()+t2.size(), 0.0);
  double min1 = t1[0];
  double min2 = t2[0];
  double mint = max(max(min1, min2), MinTime);
  double max1 = t1[t1.size()-1];
  double max2 = t2[t2.size()-1];
  double maxt = min(max1, max2);
  t[0] = mint;
  unsigned int I = 0, I1 = 0, I2 = 0;
  while(t[I] <= maxt) {
    I++;
    while(t[I-1]>t1[I1+1]) { I1++; }
    while(t[I-1]>t2[I2+1]) { I2++; }
    if(I1==0 && I2>0 && t[I-1]<t1[I1]) {
      t[I] = t[I-1] + max(t2[I2+1]-t2[I2], MinStep);
    } else if(I2==0 && I1>0 && t[I-1]<t2[I2]) {
      t[I] = t[I-1] + max(t1[I1+1]-t1[I1], MinStep);
    } else {
      t[I] = t[I-1] + max(min(t1[I1+1]-t1[I1], t2[I2+1]-t2[I2]), MinStep);
    }
  }
  t.erase(t.begin()+I, t.end()); //// Only take the relevant part
  return t;
}

vector<double> Intersection(const vector<double>& t1, const vector<double>& t2, const double& MinStep, const double& MinTime) {
  vector<double> e(0);
  return Intersection(TimeSeqRef(e,t1,e), TimeSeqRef(e,t2,e), MinStep, MinTime);
}

vector<double> Intersection(const vector<vector<double> >& Times, const double& MinStep, const double& MinTime) {
  std::vector<double> Time = Times[0];
  //// Get the intersection of all the time data
  for(unsigned int i=1; i<Times.size(); ++i) {
    Time = Intersection(Time, Times[i], MinStep, MinTime);
  }
  return Time;
}

vector<double> Union(const vector<double>& t1, const vector<double>& t2, const double& MinStep) {
  vector<double> t1a(0), t1c(0), t2a(0), t2c(0);
  double min1 = t1[0];
  double min2 = t2[0];
  double mint = min(min1, min2);
  double max1 = t1[t1.size()-1];
  double max2 = t2[t2.size()-1];
  double maxt = max(max1, max2);
  if(min1-MinStep>mint) { t1a = vector<double>(1, mint); }
  if(min2-MinStep>mint) { t2a = vector<double>(1, mint); }
  if(max1+MinStep<maxt) { t1c = vector<double>(1, maxt); }
  if(max2+MinStep<maxt) { t2c = vector<double>(1, maxt); }
  return Intersection(TimeSeqRef(t1a, t1, t1c), TimeSeqRef(t2a, t2, t2c), MinStep, -1.0e290);
}

vector<double> Unwrap(const vector<double>& In) {
  // Compare Matlab's unwrap.m file
  vector<double> Out = In;
  double Dp = 0.0;
  double Dps = 0.0;
  double CumCorr = 0.0;
  
  // Dp will contain the incremental phase variations;
  // Dps will contain the equivalents, confined to [-pi,pi)
  // CumCorr will contain the incremental phase corrections
  for(unsigned int i=1; i<In.size(); ++i) {
    Dp = In[i]-In[i-1];
    // C++'s fmod is unlike Matlab's negative 'a' values, so:
    if(Dp+M_PI<0) {
      Dps = M_PI - fmod(-Dp-M_PI, 2.0*M_PI);
    } else {
      Dps = fmod(Dp+M_PI, 2.0*M_PI) - M_PI;
    }
    if(Dps==-M_PI && Dp>0) { Dps = M_PI; }
    CumCorr += Dps - Dp;
    Out[i] += CumCorr;
  }
  
  return Out;
}

void AmpPhi(const vector<double>& Re, const vector<double>& Im,
	    vector<double>& amp, vector<double>& phi)
{
  if(amp.size() != Re.size()) { amp = Re; }
  if(phi.size() != Re.size()) { phi = Re; }
  
  for(unsigned int j=0; j<phi.size(); ++j) { // Loop over time
    amp[j] = sqrt(Re[j]*Re[j]+Im[j]*Im[j]);
    phi[j] = atan2(Im[j], Re[j]);
  }
  phi = Unwrap(phi);
}

void ReIm(const vector<vector<double> >& amp, const vector<vector<double> >& phi,
	  vector<vector<double> >& Re, vector<vector<double> >& Im)
{
  if(amp.size() != Re.size() || amp[0].size() != Re[0].size()) { Re = amp; }
  if(amp.size() != Im.size() || amp[0].size() != Im[0].size()) { Im = amp; }
  
  for(unsigned int i=0; i<Re.size(); ++i) {
    for(unsigned int j=0; j<Re[i].size(); ++j) {
      Re[i][j] = amp[i][j]*cos(phi[i][j]);
      Im[i][j] = amp[i][j]*sin(phi[i][j]);
    }
  }
}



//// Miscellaneous helpers
double Fac(const int n) {
  static vector<double> a(171);
  static bool initialize=true;
  if (initialize) {
    initialize = false;
    a[0] = 1.0;
    a[1] = 1.0;
    for (unsigned int i=2;i<171;++i) {
      a[i] = i*a[i-1];
    }
  }
  if (n < 0 || n > 170) {
    cerr << "\nFac out of range" << endl;
    exit(1);
  }
  return a[n];
}

double DoubleFac(const int n) {
  static vector<double> a(301);
  static bool initialize=true;
  if (initialize) {
    initialize = false;
    a[0] = 1.0;
    a[1] = 1.0;
    a[2] = 2.0;
    for (unsigned int i=2;i<301;++i) {
      a[i] = i*a[i-2];
      ++i;
      a[i] = i*a[i-2];
    }
  }
  if (n < 0 || n > 300) {
    cerr << "\nDoubleFac out of range" << endl;
    exit(1);
  }
  return a[n];
}

double LogFac(const int n) {
  static const int NTOP=2000;
  static vector<double> a(NTOP);
  static bool initialize=true;
  if (initialize) {
    initialize = false;
    for (int i=0;i<NTOP;i++) a[i] = LogGamma(i+1.);
  }
  if (n < 0) {
    cerr << "\nNegative arg in LogFac" << endl;
    exit(1);
  }
  if (n < NTOP) return a[n];
  return LogGamma(n+1.);
}

double LogGamma(const double& xx) {
  int j;
  double x,tmp,y,ser;
  static const double cof[14]={57.1562356658629235,-59.5979603554754912,
			       14.1360979747417471,-0.491913816097620199,.339946499848118887e-4,
			       .465236289270485756e-4,-.983744753048795646e-4,.158088703224912494e-3,
			       -.210264441724104883e-3,.217439618115212643e-3,-.164318106536763890e-3,
			       .844182239838527433e-4,-.261908384015814087e-4,.368991826595316234e-5};
  if (xx <= 0) {
    cerr << "\nBad arg in LogGamma" << endl;
    exit(1);
  }
  y=x=xx;
  tmp = x+5.24218750000000000;
  tmp = (x+0.5)*log(tmp)-tmp;
  ser = 0.999999999999997092;
  for (j=0;j<14;j++) ser += cof[j]/++y;
  return tmp+log(2.5066282746310005*ser/x);
}

complex<double> LogGamma(const complex<double>& xx) {
  int j;
  complex<double> x,tmp,y,ser;
  static const double cof[14]={57.1562356658629235,-59.5979603554754912,
			       14.1360979747417471,-0.491913816097620199,.339946499848118887e-4,
			       .465236289270485756e-4,-.983744753048795646e-4,.158088703224912494e-3,
			       -.210264441724104883e-3,.217439618115212643e-3,-.164318106536763890e-3,
			       .844182239838527433e-4,-.261908384015814087e-4,.368991826595316234e-5};
  if (arg(xx)>M_PI/2.0 && arg(x)<3*M_PI/2.0) {
    cerr << "\nBad arg in LogGamma" << endl;
    exit(1);
  }
  y=x=xx;
  tmp = x+5.24218750000000000;
  tmp = (x+0.5)*log(tmp)-tmp;
  ser = 0.999999999999997092;
  for (j=0;j<14;j++) {
    y=y+complex<double>(1,0);
    ser += cof[j]/y;
  }
  return tmp+log(2.5066282746310005*ser/x);
}

vector<complex<double> > LogGamma(const vector<complex<double> >& xx) {
  vector<complex<double> > yy(xx.size());
  for(unsigned int i=0; i<yy.size(); ++i) {
    yy[i] = LogGamma(xx[i]);
  }
  return yy;
}
