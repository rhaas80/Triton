#include "VectorFunctions.hpp"
#include <cmath>
#include <limits>
#include <sstream>
#include "Utilities.hpp"
namespace WU = WaveformUtilities;
using WU::Matrix;
using std::vector;
using std::complex;
using std::cerr;
using std::flush;
using std::endl;
using std::ostream;
using std::min;
using std::max;
using std::string;
using std::stringstream;
using std::numeric_limits;


// Local to this file
bool DimensionsAgree(const vector<double>& a, const vector<double>& b) {
  if(a.size() != b.size()) {
    cerr << "\na.size()=" << a.size() << "\tb.size()=" << b.size() << endl;
    return false;
  }
  return true;
}

bool DimensionsAgree(const Matrix<double>& a, const Matrix<double>& b) {
  if(a.nrows() != b.nrows() || a.ncols() != b.ncols()) {
    cerr << "\na.nrows()=" << a.nrows() << "\tb.nrows()=" << b.nrows() << endl;
    cerr << "a.ncols()=" << a.ncols() << "\tb.ncols()=" << b.ncols() << endl;
    return false;
  }
  return true;
}


// IO
ostream& operator<<(ostream& out, const vector<double>& v) {
  for(unsigned int i=0; i<v.size()-1; ++i) {
    out << v[i] << ", ";
  }
  out << v.back() << flush;
  return out;
}

ostream& operator<<(ostream& out, const vector<int>& v) {
  for(unsigned int i=0; i<v.size()-1; ++i) {
    out << v[i] << ", ";
  }
  out << v.back() << flush;
  return out;
}

ostream& operator<<(ostream& out, const Matrix<double>& M) {
  for(unsigned int i=0; i<M.nrows(); ++i) {
    out << M[i] << endl;
  }
  return out;
}

ostream& operator<<(ostream& out, const Matrix<int>& M) {
  for(unsigned int i=0; i<M.nrows(); ++i) {
    out << M[i] << endl;
  }
  return out;
}

string RowFormat(const vector<double>& v) {
  stringstream RowForm("");
  RowForm << "[";
  if(v.size()>0) {
    for(unsigned int i=0; i<v.size()-1; ++i) {
      RowForm << v[i] << ", ";
    }
    RowForm << v.back();
  }
  RowForm << "]";
  return RowForm.str();
}

string RowFormat(const vector<int>& v) {
  stringstream RowForm("");
  RowForm << "[";
  if(v.size()>0) {
    for(unsigned int i=0; i<v.size()-1; ++i) {
      RowForm << v[i] << ", ";
    }
    RowForm << v.back();
  }
  RowForm << "]";
  return RowForm.str();
}

string RowFormat(const WaveformUtilities::Matrix<double>& m) {
  stringstream RowForm("");
  RowForm << "[ ";
  if(m.nrows()>0) {
    for(unsigned int i=0; i<m.nrows()-1; ++i) {
      RowForm << RowFormat(m[i]) << ", ";
    }
    RowForm << RowFormat(m[m.nrows()-1]);
  }
  RowForm << " ]";
  return RowForm.str();
}

string RowFormat(const WaveformUtilities::Matrix<int>& m) {
  stringstream RowForm("");
  RowForm << "[ ";
  if(m.nrows()>0) {
    for(unsigned int i=0; i<m.nrows()-1; ++i) {
      RowForm << RowFormat(m[i]) << ", ";
    }
    RowForm << RowFormat(m[m.nrows()-1]);
  }
  RowForm << " ]";
  return RowForm.str();
}


// Arithmetic
vector<double> operator+(const vector<double>& a, const double& b) {
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]+b;
  }
  return c;
}
vector<double> operator-(const vector<double>& a, const double& b) {
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]-b;
  }
  return c;
}
vector<double> operator*(const vector<double>& a, const double& b) {
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]*b;
  }
  return c;
}
vector<double> operator/(const vector<double>& a, const double& b) {
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]/b;
  }
  return c;
}

vector<double> operator+(const double& a, const vector<double>& b) {
  vector<double> c(b.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a+b[i];
  }
  return c;
}
vector<double> operator-(const double& a, const vector<double>& b) {
  vector<double> c(b.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a-b[i];
  }
  return c;
}
vector<double> operator*(const double& a, const vector<double>& b) {
  vector<double> c(b.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a*b[i];
  }
  return c;
}
vector<double> operator/(const double& a, const vector<double>& b) {
  vector<double> c(b.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a/b[i];
  }
  return c;
}

vector<double> operator+(const vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]+b[i];
  }
  return c;
}
vector<double> operator-(const vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]-b[i];
  }
  return c;
}
vector<double> operator*(const vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]*b[i];
  }
  return c;
}
vector<double> operator/(const vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  vector<double> c(a.size());
  for(unsigned int i=0; i<c.size(); ++i) {
    c[i] = a[i]/b[i];
  }
  return c;
}

vector<double>& operator+=(vector<double>& a, const double& b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b;
  }
  return a;
}
vector<double>& operator-=(vector<double>& a, const double& b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] -= b;
  }
  return a;
}
vector<double>& operator*=(vector<double>& a, const double& b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] *= b;
  }
  return a;
}
vector<double>& operator/=(vector<double>& a, const double& b) {
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] /= b;
  }
  return a;
}

vector<double>& operator+=(vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b[i];
  }
  return a;
}
vector<double>& operator-=(vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b[i];
  }
  return a;
}
vector<double>& operator*=(vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b[i];
  }
  return a;
}
vector<double>& operator/=(vector<double>& a, const vector<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int i=0; i<a.size(); ++i) {
    a[i] += b[i];
  }
  return a;
}

vector<double> operator-(const vector<double>& a) {
  vector<double> b(a.size());
  for(unsigned int i=0; i<b.size(); ++i) {
    b[i] = -a[i];
  }
  return b;
}


Matrix<double> operator+(const Matrix<double>& a, const double& b) {
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]+b;
    }
  }
  return c;
}
Matrix<double> operator-(const Matrix<double>& a, const double& b) {
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]-b;
    }
  }
  return c;
}
Matrix<double> operator*(const Matrix<double>& a, const double& b) {
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]*b;
    }
  }
  return c;
}
Matrix<double> operator/(const Matrix<double>& a, const double& b) {
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]/b;
    }
  }
  return c;
}

Matrix<double> operator+(const double& a, const Matrix<double>& b) {
  Matrix<double> c(b.nrows(), b.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a+b[row][col];
    }
  }
  return c;
}
Matrix<double> operator-(const double& a, const Matrix<double>& b) {
  Matrix<double> c(b.nrows(), b.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a-b[row][col];
    }
  }
  return c;
}
Matrix<double> operator*(const double& a, const Matrix<double>& b) {
  Matrix<double> c(b.nrows(), b.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a*b[row][col];
    }
  }
  return c;
}
Matrix<double> operator/(const double& a, const Matrix<double>& b) {
  Matrix<double> c(b.nrows(), b.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a/b[row][col];
    }
  }
  return c;
}

Matrix<double> operator+(const Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]+b[row][col];
    }
  }
  return c;
}
Matrix<double> operator-(const Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]-b[row][col];
    }
  }
  return c;
}
Matrix<double> operator*(const Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]*b[row][col];
    }
  }
  return c;
}
Matrix<double> operator/(const Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> c(a.nrows(), a.ncols());
  for(unsigned int row=0; row<c.nrows(); ++row) {
    for(unsigned int col=0; col<c.ncols(); ++col) {
      c[row][col] = a[row][col]/b[row][col];
    }
  }
  return c;
}

Matrix<double>& operator+=(Matrix<double>& a, const double& b) {
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] += b;
    }
  }
  return a;
}
Matrix<double>& operator-=(Matrix<double>& a, const double& b) {
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] -= b;
    }
  }
  return a;
}
Matrix<double>& operator*=(Matrix<double>& a, const double& b) {
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] *= b;
    }
  }
  return a;
}
Matrix<double>& operator/=(Matrix<double>& a, const double& b) {
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] /= b;
    }
  }
  return a;
}

Matrix<double>& operator+=(Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] += b[row][col];
    }
  }
  return a;
}
Matrix<double>& operator-=(Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] -= b[row][col];
    }
  }
  return a;
}
Matrix<double>& operator*=(Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] *= b[row][col];
    }
  }
  return a;
}
Matrix<double>& operator/=(Matrix<double>& a, const Matrix<double>& b) {
  if(! DimensionsAgree(a,b)) { Throw1WithMessage("Size disagreement"); }
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      a[row][col] /= b[row][col];
    }
  }
  return a;
}

Matrix<double> operator-(const Matrix<double>& a) {
  Matrix<double> b(a.nrows(), a.ncols());
  for(unsigned int row=0; row<b.nrows(); ++row) {
    for(unsigned int col=0; col<b.ncols(); ++col) {
      b[row][col] = -a[row][col];
    }
  }
  return b;
}

vector<double> cos(const vector<double>& theta) {
  vector<double> y(theta.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = cos(theta[i]);
  }
  return y;
}
vector<double> sin(const vector<double>& theta) {
  vector<double> y(theta.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = sin(theta[i]);
  }
  return y;
}
vector<double> tan(const vector<double>& theta) {
  vector<double> y(theta.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = tan(theta[i]);
  }
  return y;
}
vector<double> acos(const vector<double>& y) {
  vector<double> theta(y.size());
  for(unsigned int i=0; i<theta.size(); ++i) {
    theta[i] = acos(y[i]);
  }
  return theta;
}
vector<double> asin(const vector<double>& y) {
  vector<double> theta(y.size());
  for(unsigned int i=0; i<theta.size(); ++i) {
    theta[i] = asin(y[i]);
  }
  return theta;
}
vector<double> atan(const vector<double>& y) {
  vector<double> theta(y.size());
  for(unsigned int i=0; i<theta.size(); ++i) {
    theta[i] = atan(y[i]);
  }
  return theta;
}
vector<double> atan2(const vector<double>& Im, const vector<double>& Re) {
  if(! DimensionsAgree(Im,Re)) { Throw1WithMessage("Size disagreement"); }
  vector<double> theta(Im.size());
  for(unsigned int i=0; i<theta.size(); ++i) {
    theta[i] = atan2(Im[i], Re[i]);
  }
  return theta;
}
vector<double> cosh(const vector<double>& theta) {
  vector<double> y(theta.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = cosh(theta[i]);
  }
  return y;
}
vector<double> sinh(const vector<double>& theta) {
  vector<double> y(theta.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = sinh(theta[i]);
  }
  return y;
}
vector<double> tanh(const vector<double>& theta) {
  vector<double> y(theta.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = tanh(theta[i]);
  }
  return y;
}
vector<double> exp(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = exp(x[i]);
  }
  return y;
}
vector<double> log(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = log(x[i]);
  }
  return y;
}
vector<double> log10(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = log10(x[i]);
  }
  return y;
}
vector<double> pow(const vector<double>& base, const vector<double>& exponent) {
  if(! DimensionsAgree(base,exponent)) { Throw1WithMessage("Size disagreement"); }
  vector<double> y(base.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = pow(base[i], exponent[i]);
  }
  return y;
}
vector<double> pow(const vector<double>& base, const double& exponent) {
  vector<double> y(base.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = pow(base[i], exponent);
  }
  return y;
}
vector<double> sqrt(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = sqrt(x[i]);
  }
  return y;
}
vector<double> ceil(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = ceil(x[i]);
  }
  return y;
}
vector<double> fabs(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = fabs(x[i]);
  }
  return y;
}
vector<double> floor(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = floor(x[i]);
  }
  return y;
}
vector<double> fmod(const vector<double>& numerator, const vector<double>& denominator) {
  if(! DimensionsAgree(numerator,denominator)) { Throw1WithMessage("Size disagreement"); }
  vector<double> y(numerator.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = fmod(numerator[i], denominator[i]);
  }
  return y;
}
vector<double> fmod(const vector<double>& numerator, const double& denominator) {
  vector<double> y(numerator.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = fmod(numerator[i], denominator);
  }
  return y;
}

Matrix<double> cos(const Matrix<double>& theta) {
  Matrix<double> y(theta.nrows(), theta.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = cos(theta[row][col]);
    }
  }
  return y;
}
Matrix<double> sin(const Matrix<double>& theta) {
  Matrix<double> y(theta.nrows(), theta.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = sin(theta[row][col]);
    }
  }
  return y;
}
Matrix<double> tan(const Matrix<double>& theta) {
  Matrix<double> y(theta.nrows(), theta.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = tan(theta[row][col]);
    }
  }
  return y;
}
Matrix<double> acos(const Matrix<double>& y) {
  Matrix<double> theta(y.nrows(), y.ncols());
  for(unsigned int row=0; row<theta.nrows(); ++row) {
    for(unsigned int col=0; col<theta.ncols(); ++col) {
      theta[row][col] = acos(y[row][col]);
    }
  }
  return theta;
}
Matrix<double> asin(const Matrix<double>& y) {
  Matrix<double> theta(y.nrows(), y.ncols());
  for(unsigned int row=0; row<theta.nrows(); ++row) {
    for(unsigned int col=0; col<theta.ncols(); ++col) {
      theta[row][col] = asin(y[row][col]);
    }
  }
  return theta;
}
Matrix<double> atan(const Matrix<double>& y) {
  Matrix<double> theta(y.nrows(), y.ncols());
  for(unsigned int row=0; row<theta.nrows(); ++row) {
    for(unsigned int col=0; col<theta.ncols(); ++col) {
      theta[row][col] = atan(y[row][col]);
    }
  }
  return theta;
}
Matrix<double> atan2(const Matrix<double>& Im, const Matrix<double>& Re) {
  if(! DimensionsAgree(Re,Im)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> theta(Re.nrows(), Re.ncols());
  for(unsigned int row=0; row<theta.nrows(); ++row) {
    for(unsigned int col=0; col<theta.ncols(); ++col) {
      theta[row][col] = atan2(Im[row][col], Re[row][col]);
    }
  }
  return theta;
}
Matrix<double> cosh(const Matrix<double>& theta) {
  Matrix<double> y(theta.nrows(), theta.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = cosh(theta[row][col]);
    }
  }
  return y;
}
Matrix<double> sinh(const Matrix<double>& theta) {
  Matrix<double> y(theta.nrows(), theta.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = sinh(theta[row][col]);
    }
  }
  return y;
}
Matrix<double> tanh(const Matrix<double>& theta) {
  Matrix<double> y(theta.nrows(), theta.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = tanh(theta[row][col]);
    }
  }
  return y;
}
Matrix<double> exp(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = exp(x[row][col]);
    }
  }
  return y;
}
Matrix<double> log(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = log(x[row][col]);
    }
  }
  return y;
}
Matrix<double> log10(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = log10(x[row][col]);
    }
  }
  return y;
}
Matrix<double> pow(const Matrix<double>& base, const Matrix<double>& exponent) {
  if(! DimensionsAgree(base,exponent)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> y(base.nrows(), base.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = pow(base[row][col], exponent[row][col]);
    }
  }
  return y;
}
Matrix<double> pow(const Matrix<double>& base, const double& exponent) {
  Matrix<double> y(base.nrows(), base.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = pow(base[row][col], exponent);
    }
  }
  return y;
}
Matrix<double> sqrt(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = sqrt(x[row][col]);
    }
  }
  return y;
}
Matrix<double> ceil(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = ceil(x[row][col]);
    }
  }
  return y;
}
Matrix<double> fabs(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = fabs(x[row][col]);
    }
  }
  return y;
}
Matrix<double> floor(const Matrix<double>& x) {
  Matrix<double> y(x.nrows(), x.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = floor(x[row][col]);
    }
  }
  return y;
}
Matrix<double> fmod(const Matrix<double>& numerator, const Matrix<double>& denominator) {
  if(! DimensionsAgree(numerator,denominator)) { Throw1WithMessage("Size disagreement"); }
  Matrix<double> y(numerator.nrows(), numerator.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = fmod(numerator[row][col], denominator[row][col]);
    }
  }
  return y;
}
Matrix<double> fmod(const Matrix<double>& numerator, const double& denominator) {
  Matrix<double> y(numerator.nrows(), numerator.ncols());
  for(unsigned int row=0; row<y.nrows(); ++row) {
    for(unsigned int col=0; col<y.ncols(); ++col) {
      y[row][col] = fmod(numerator[row][col], denominator);
    }
  }
  return y;
}

double WU::dot(const vector<double>& x, const vector<double>& y) {
  if(x.size()!=3 || y.size()!=3) {
    cerr << "\nx.size()=" << x.size() << "\ty.size()=" << y.size() << endl;
    Throw1WithMessage("The dot product is only defined for 3-vectors");
  }
  return x[0]*y[0] + x[1]*y[1] + x[2]*y[2];
}

vector<double> WU::dot(const vector<vector<double> >& x, const vector<vector<double> >& y) {
  if(x.size()!=3 || y.size()!=3) {
    cerr << "\nx.size()=" << x.size() << "\ty.size()=" << y.size() << endl;
    Throw1WithMessage("The dot product is only defined for 3-vectors");
  }
  return x[0]*y[0] + x[1]*y[1] + x[2]*y[2];
}

vector<double> WU::cross(const vector<double>& x, const vector<double>& y) {
  if(x.size()!=3 || y.size()!=3) {
    cerr << "\nx.size()=" << x.size() << "\ty.size()=" << y.size() << endl;
    Throw1WithMessage("The cross product is only defined for 3-vectors");
  }
  vector<double> z(3, 0.0);
  z[0] = x[1]*y[2] - x[2]*y[1];
  z[1] = x[2]*y[0] - x[0]*y[2];
  z[2] = x[0]*y[1] - x[1]*y[0];
  return z;
}

double WU::norm(const vector<double>& x) {
  if(x.size()==0) { return 0.0; }
  double b=0.0;
  for(unsigned int i=0; i<x.size(); ++i) { b += x[i]*x[i]; }
  return sqrt(b);
}

vector<double> WU::norm(const vector<vector<double> >& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<y.size(); ++i) {
    y[i] = WU::norm(x[i]);
  }
  return y;
}

inline vector<double> WU::square(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=square(x[i]);
  }
  return y;
}

inline vector<double> WU::cube(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=cube(x[i]);
  }
  return y;
}

inline vector<double> WU::fourth(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=fourth(x[i]);
  }
  return y;
}

inline vector<double> WU::fifth(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=fifth(x[i]);
  }
  return y;
}

inline vector<double> WU::sixth(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=sixth(x[i]);
  }
  return y;
}

inline vector<double> WU::seventh(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=seventh(x[i]);
  }
  return y;
}

inline vector<double> WU::eighth(const vector<double>& x) {
  vector<double> y(x.size());
  for(unsigned int i=0; i<x.size(); ++i) {
    y[i]=eighth(x[i]);
  }
  return y;
}

double WU::maxfabs(const vector<double>& x) {
  if(x.size()==0) { return 0.0; }
  double b=fabs(x[0]);
  for(unsigned int i=1; i<x.size(); ++i) { b = (b<fabs(x[i]) ? fabs(x[i]) : b); }
  return b;
}

double WU::maxmag(const vector<double>& Re, const vector<double>& Im) {
  if(! DimensionsAgree(Re,Im)) { Throw1WithMessage("Size disagreement"); }
  if(Re.size()==0) { return 0.0; }
  double c=sqrt(Re[0]*Re[0]+Im[0]*Im[0]);
  for(unsigned int i=1; i<Im.size(); ++i) {
    const double d = sqrt(Re[i]*Re[i]+Im[i]*Im[i]);
    if(c<d) { c = d; }
  }
  return c;
}

double WU::maxfabs(const Matrix<double>& x) {
  if(x.nrows()==0 || x.ncols()==0) { return 0.0; }
  double b=fabs(x[0][0]);
  for(unsigned int row=0; row<x.nrows(); ++row) {
    for(unsigned int col=0; col<x.ncols(); ++col) {
      double c = fabs(x[row][col]);
      if(b<c) { b = c; }
    }
  }
  return b;
}

double WU::maxmag(const Matrix<double>& Re, const Matrix<double>& Im) {
  if(! DimensionsAgree(Re,Im)) { Throw1WithMessage("Size disagreement"); }
  if(Re.nrows()==0 || Re.ncols()==0) { return 0.0; }
  double c=sqrt(Re[0][0]*Re[0][0]+Im[0][0]*Im[0][0]);
  for(unsigned int row=0; row<Im.nrows(); ++row) {
    for(unsigned int col=0; col<Im.ncols(); ++col) {
      double d = sqrt(Re[row][col]*Re[row][col]+Im[row][col]*Im[row][col]);
      if(c<d) { c = d; }
    }
  }
  return c;
}


// Integral, derivative, etc.
vector<double> WU::diff(const vector<double>& In) {
  vector<double> Out(In.size()-1);
  for(unsigned int i=0; i<Out.size(); ++i) {
    Out[i] = In[i+1]-In[i];
  }
  return Out;
}

double WU::sum(const vector<double>& In) {
  double Out = 0.0;
  for(unsigned int i=0; i<In.size(); ++i) {
    Out += In[i];
  }
  return Out;
}

double WU::max(const vector<double>& In) {
  double Out = In[0];
  for(unsigned int i=1; i<In.size(); ++i) {
    if(In[i]>Out) { Out = In[i]; }
  }
  return Out;
}

double WU::min(const vector<double>& In) {
  double Out = In[0];
  for(unsigned int i=1; i<In.size(); ++i) {
    if(In[i]<Out) { Out = In[i]; }
  }
  return Out;
}

int WU::max(const vector<int>& In) {
  int Out = In[0];
  for(unsigned int i=1; i<In.size(); ++i) {
    if(In[i]>Out) { Out = In[i]; }
  }
  return Out;
}

int WU::min(const vector<int>& In) {
  int Out = In[0];
  for(unsigned int i=1; i<In.size(); ++i) {
    if(In[i]<Out) { Out = In[i]; }
  }
  return Out;
}

double WU::avg(const vector<double>& In) { return sum(In)/double(In.size()); }

double WU::trapz(const vector<double>& t, const vector<double>& f) {
  if(! DimensionsAgree(t,f)) { Throw1WithMessage("Size disagreement"); }
  double Integral = 0.0;
  for(unsigned int i=1; i<f.size(); ++i) {
    Integral += ( (f[i] + f[i-1])*(t[i]-t[i-1]) / 2.0 );
  }
  return Integral;
}

vector<double> WU::cumtrapz(const vector<double>& t, const vector<double>& f) {
  if(! DimensionsAgree(t,f)) { Throw1WithMessage("Size disagreement"); }
  if(f.size()==0) { return vector<double>(0); }
  vector<double> Integral(f.size());
  Integral[0] = 0.0;
  for(unsigned int i=1; i<f.size(); ++i) {
    Integral[i] = Integral[i-1] + ( (f[i] + f[i-1])*(t[i]-t[i-1]) / 2.0 );
  }
  return Integral;
}

vector<double> WU::dydx(const vector<double>& y, const vector<double>& x) {
  if(! DimensionsAgree(y,x)) { Throw1WithMessage("Size disagreement"); }
  if(y.size()<3) { cerr << "\nsize=" << y.size() << endl; Throw1WithMessage("Not enough points for a derivative"); }
  vector<double> D = y;
  const unsigned int i1 = y.size()-1;
  double hprev = x[1]-x[0];
  D[0] = (y[1]-y[0]) / hprev;
  for(unsigned int i=1; i<i1; ++i) {
    const double hnext = x[i+1]-x[i];
    /// Sundquist and Veronis, Tellus XXII (1970), 1
    D[i] = (y[i+1] - y[i-1]*WU::square(hnext/hprev) - y[i]*(1-WU::square(hnext/hprev))) / (hnext*(1+hnext/hprev));
    hprev = hnext;
  }
  D[i1] = (y[i1]-y[i1-1]) / (x[i1]-x[i1-1]);
  return D;
}

vector<double> WU::Intersection(const vector<double>& t1, const vector<double>& t2, const double MinStep, const double MinTime) {
  if(t1.size()==0) {
    Throw1WithMessage("t1 is empty");
  }
  if(t2.size()==0) {
    Throw1WithMessage("t2 is empty");
  }
  vector<double> t(t1.size()+t2.size());
  double min1 = t1[0];
  double min2 = t2[0];
  double mint = std::max(std::max(min1, min2), MinTime);
  double max1 = t1.back();
  double max2 = t2.back();
  double maxt = std::min(max1, max2);
  if(mint > max1 || mint > max2) {
    cerr << "\nmin(t1)=" << min1 << "\tmin(t2)=" << min2 << endl;
    cerr << "max(t1)=" << max1 << "\tmax(t2)=" << max2 << endl;
    Throw1WithMessage("Empty intersection");
  }
  t[0] = mint;
  unsigned int I=0, I1=0, I2=0;
  const unsigned int size1=t1.size(), size2=t2.size();
  while(t[I] < maxt) {
    // adjust I1 to ensure that t[I] is in the interval ( t1[I1-1], t1[I1] ]
    if(t[I]<min1 || t[I]>max1) { // if t[I] is less than the smallest t1, or greater than the largest t1, I1=0;
      I1=0;
    } else {
      I1 = std::max(I1, (unsigned int)1);
      while(t[I]>t1[I1] && I1<size1) { I1++; }
    }
    // adjust I2 to ensure that t[I] is in the interval ( t2[I2-1], t2[I2] ]
    if(t[I]<min2 || t[I]>max2) { // if t[I] is less than the smallest t2, or greater than the largest t2, I2=0;
      I2=0;
    } else {
      I2 = std::max(I2, (unsigned int)1);
      while(t[I]>t2[I2] && I2<size2) { I2++; }
    }
    t[I+1] = t[I] + std::max(std::min(t1[I1]-t1[I1-1], t2[I2]-t2[I2-1]), MinStep);
    if(t[I+1]>maxt) { break; }
    I++;
  }
  t.erase(t.begin()+I+1, t.end()); // only take the relevant part of the reserved vector
  return t;
}

vector<double> WU::Intersection(const vector<vector<double> >& Times, const double MinStep, const double MinTime) {
  vector<double> Time = Times[0];
  // Get the intersection of all the time data
  for(unsigned int i=1; i<Times.size(); ++i) {
    Time = Intersection(Time, Times[i], MinStep, MinTime);
  }
  return Time;
}

vector<double> WU::Union(const vector<double>& t1, const vector<double>& t2, const double MinStep) {
  if(t1.size()==0) {
    cerr << "\nt1 is empty at " << __LINE__ << " of " << __FILE__ << ".  Returning trivial Union." << endl;
    return vector<double>(t2);
  }
  if(t2.size()==0) {
    cerr << "\nt2 is empty at " << __LINE__ << " of " << __FILE__ << ".  Returning trivial Union." << endl;
    return vector<double>(t1);
  }
  vector<double> t(t1.size()+t2.size()+4);
  double min1 = t1[0];
  double min2 = t2[0];
  double mint = std::min(min1, min2);
  double max1 = t1.back();
  double max2 = t2.back();
  double maxt = std::max(max1, max2);
  if(min2 > max1 || min1 > max2) {
    cerr << "\nmin(t1)=" << min1 << "\tmin(t2)=" << min2 << endl;
    cerr << "max(t1)=" << max1 << "\tmax(t2)=" << max2 << endl;
    Throw1WithMessage("Disjoint Union");
  }
  t[0] = mint;
  unsigned int I=0, I1=0, I2=0;
  const unsigned int size1=t1.size(), size2=t2.size();
  while(t[I] < maxt) {
    // adjust I1 to ensure that t[I] is in the interval ( t1[I1-1], t1[I1] ]
    if(t[I]<min1 || t[I]>max1) { // if t[I] is less than the smallest t1, or greater than the largest t1, I1=0;
      I1=0;
    } else {
      I1 = std::max(I1, (unsigned int)1);
      while(t[I]>t1[I1] && I1<size1) { I1++; }
    }
    // adjust I2 to ensure that t[I] is in the interval ( t2[I2-1], t2[I2] ]
    if(t[I]<min2 || t[I]>max2) { // if t[I] is less than the smallest t2, or greater than the largest t2, I2=0;
      I2=0;
    } else {
      I2 = std::max(I2, (unsigned int)1);
      while(t[I]>t2[I2] && I2<size2) { I2++; }
    }
    if(I1==0) {
      t[I+1] = t[I] + std::max(t2[I2]-t2[I2-1], MinStep);
    } else if(I2==0) {
      t[I+1] = t[I] + std::max(t1[I1]-t1[I1-1], MinStep);
    } else {
      t[I+1] = t[I] + std::max(std::min(t1[I1]-t1[I1-1], t2[I2]-t2[I2-1]), MinStep);
    }
    if(t[I+1]>maxt) { break; }
    I++;
  }
  t.erase(t.begin()+I+1, t.end()); // only take the relevant part of the reserved vector
  return t;
}

vector<double> WU::Unwrap(const vector<double>& In) {
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
    // C++'s fmod is unlike Matlab's for negative values, so:
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

vector<double>& WU::Unwrap(vector<double>& Vec, const unsigned int i1, const unsigned int i2) {
  // Compare Matlab's unwrap.m file
  double Dp = 0.0;
  double Dps = 0.0;
  double CumCorr = 0.0;
  unsigned int i=0;
  
  // Dp will contain the incremental phase variations;
  // Dps will contain the equivalents, confined to [-pi,pi)
  // CumCorr will contain the incremental phase corrections
  for(i=(i1<1?1:i1); i<Vec.size()&&i<i2; ++i) {
    Dp = Vec[i]-Vec[i-1];
    Vec[i-1] += CumCorr;
    // C++'s fmod is unlike Matlab's for negative values, so:
    if(Dp+M_PI<0) {
      Dps = M_PI - fmod(-Dp-M_PI, 2.0*M_PI);
    } else {
      Dps = fmod(Dp+M_PI, 2.0*M_PI) - M_PI;
    }
    if(Dps==-M_PI && Dp>0) { Dps = M_PI; }
    CumCorr += Dps - Dp;
  }
  Vec[i-1] += CumCorr;
  
  return Vec;
}

void WU::MagArg(const vector<double>& Re, const vector<double>& Im,
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

void WU::ReIm(const vector<vector<double> >& amp, const vector<vector<double> >& phi,
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

unsigned int WU::maxIndex(const vector<double>& a) {
  double max=a[0];
  unsigned int Index=0;
  for(unsigned int i=1; i<a.size(); ++i) {
    if(a[i]>max) {
      max = a[i];
      Index = i;
    }
  }
  return Index;
}

// Miscellaneous helpers
double WU::Factorial(const int n) {
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
    cerr << "\nn=" << n << endl;
    Throw1WithMessage("Fac out of range");
  }
  return a[n];
}

double WU::DoubleFactorial(const int n) {
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
    cerr << "\nn=" << n << endl;
    Throw1WithMessage("DoubleFac out of range");
  }
  return a[n];
}

double WU::LogFactorial(const int n) {
  static const int NTOP=2000;
  static vector<double> a(NTOP);
  static bool initialize=true;
  if (initialize) {
    initialize = false;
    for (int i=0;i<NTOP;i++) a[i] = LogGammaFunction(i+1.);
  }
  if (n < 0) {
    cerr << "\nn=" << n << endl;
    Throw1WithMessage("Negative arg in LogFac");
  }
  if (n < NTOP) return a[n];
  return LogGammaFunction(n+1.);
}

double WU::LogGammaFunction(const double xx) {
  int j;
  double x,tmp,y,ser;
  static const double cof[14]={57.1562356658629235,-59.5979603554754912,
			       14.1360979747417471,-0.491913816097620199,.339946499848118887e-4,
			       .465236289270485756e-4,-.983744753048795646e-4,.158088703224912494e-3,
			       -.210264441724104883e-3,.217439618115212643e-3,-.164318106536763890e-3,
			       .844182239838527433e-4,-.261908384015814087e-4,.368991826595316234e-5};
  if (xx <= 0) {
    cerr << "\nxx=" << xx << endl;
    Throw1WithMessage("Bad arg in LogGamma");
  }
  y=x=xx;
  tmp = x+5.24218750000000000;
  tmp = (x+0.5)*log(tmp)-tmp;
  ser = 0.999999999999997092;
  for (j=0;j<14;j++) ser += cof[j]/++y;
  return tmp+log(2.5066282746310005*ser/x);
}

complex<double> WU::LogGammaFunction(const complex<double>& xx) {
  int j;
  complex<double> x,tmp,y,ser;
  static const double cof[14]={57.1562356658629235,-59.5979603554754912,
			       14.1360979747417471,-0.491913816097620199,.339946499848118887e-4,
			       .465236289270485756e-4,-.983744753048795646e-4,.158088703224912494e-3,
			       -.210264441724104883e-3,.217439618115212643e-3,-.164318106536763890e-3,
			       .844182239838527433e-4,-.261908384015814087e-4,.368991826595316234e-5};
  if (arg(xx)>M_PI/2.0 && arg(x)<3*M_PI/2.0) {
    cerr << "\nxx=" << xx << "\targ(xx)=" << arg(xx) << endl;
    Throw1WithMessage("Bad arg in LogGamma");
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

vector<complex<double> > WU::LogGammaFunction(const vector<complex<double> >& xx) {
  vector<complex<double> > yy(xx.size());
  for(unsigned int i=0; i<yy.size(); ++i) {
    yy[i] = LogGammaFunction(xx[i]);
  }
  return yy;
}


/// NaN and inf checks
bool WU::hasnan(const vector<double>& a) {
  for(unsigned int i=0; i<a.size(); ++i) {
    if(isnan(a[i])) {
      cerr << "\nNaN at i=" << i << endl;
      return true;
    }
  }
  return false;
}
bool WU::hasnan(const WaveformUtilities::Matrix<double>& a) {
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      if(isnan(a[row][col])) {
	cerr << "\nNaN at (row,col)=(" << row << "," << col << ")" << endl;
	return true;
      }
    }
  }
  return false;
}
bool WU::hasinf(const vector<double>& a) {
  for(unsigned int i=0; i<a.size(); ++i) {
    if(isinf(a[i])) {
      cerr << "\nInf at i=" << i << endl;
      return true;
    }
  }
  return false;
}
bool WU::hasinf(const WaveformUtilities::Matrix<double>& a) {
  for(unsigned int row=0; row<a.nrows(); ++row) {
    for(unsigned int col=0; col<a.ncols(); ++col) {
      if(isinf(a[row][col])) {
	cerr << "\nInf at (row,col)=(" << row << "," << col << ")" << endl;
	return true;
      }
    }
  }
  return false;
}
bool WU::ismonotonic(const vector<double>& a) {
  bool Return=true;
  if(a[1]<a[0]) { // Decreasing
    for(unsigned int i=1; i<a.size(); ++i) {
      if(a[i]>=a[i-1]) {
	cerr << "\nNon-montonicity: a[" << i << "]=" << a[i] << "  a[" << i-1 << "]=" << a[i-1] <<  endl;
	Return=false;
      }
    }
  } else if(a[1]>a[0]) { // Increasing
    for(unsigned int i=1; i<a.size(); ++i) {
      if(a[i]<=a[i-1]) {
	cerr << "\nNon-montonicity: a[" << i << "]=" << a[i] << "  a[" << i-1 << "]=" << a[i-1] <<  endl;
	Return=false;
      }
    }
  } else { // Equal
    cerr << "\nNon-montonicity (equality): a[1]=" << a[1] << "  a[0]=" << a[0] <<  endl;
    Return=false;
  }
  return Return;
}

// bool WU::ismonotonic(const vector<double>& a) {
//   if(a[1]<a[0]) { // Decreasing
//     for(unsigned int i=1; i<a.size(); ++i) {
//       if(a[i]>=a[i-1]) {
// 	cerr << "\nNon-montonicity: a[" << i << "]=" << a[i] << "  a[" << i-1 << "]=" << a[i-1] <<  endl;
// 	return false;
//       }
//     }
//   } else if(a[1]>a[0]) { // Increasing
//     for(unsigned int i=1; i<a.size(); ++i) {
//       if(a[i]<=a[i-1]) {
// 	cerr << "\nNon-montonicity: a[" << i << "]=" << a[i] << "  a[" << i-1 << "]=" << a[i-1] <<  endl;
// 	return false;
//       }
//     }
//   } else { // Equal
//     cerr << "\nNon-montonicity (equality): a[1]=" << a[1] << "  a[0]=" << a[0] <<  endl;
//     return false;
//   }
//   return true;
// }

