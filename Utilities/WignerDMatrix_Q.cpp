#define WIGNERDMATRIX_Q_CPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "WignerDMatrix_Q.hpp"
#include <cstdlib>
#include <limits>
#include "Utilities.hpp"

using std::sqrt;
using std::atan2;
using std::numeric_limits;
using WaveformUtilities::WignerDMatrix_Q;

void WaveformUtilities::WignerD_Q(const int L, const int MP, const int M, const Quaternion& R, double& mag, double& arg) {
  WignerDMatrix_Q Q(L, MP, M, R);
  Q.Value(mag, arg);
  return;
}

// (Qz[3] - I Qz[0])^(m + mp) (Qz[1] + I Qz[2])^(m - mp)

WignerDMatrix_Q::WignerDMatrix_Q(const int iL, const int iMP, const int iM, const Quaternion iR)
  : L(-2), MP(-2), M(-2),
    Calculator(&WignerDMatrix_Q::Uninitialized),
    R(0,0,0,0), RzRbar3(0.),
    Mag_Rz_3_0(0.), Mag_Rz_1_2(0.),
    Arg_Rz_3_0(0.), Arg_Rz_1_2(0.),
    Recalculated(false), ValMag(0.0), ValArg(0.0)
{
  SetQuaternion(iR);
  SetElement(iL, iMP, iM);
}

WignerDMatrix_Q::WignerDMatrix_Q(const WignerDMatrix_Q& D)
  : L(-2), MP(-2), M(-2),
    Calculator(&WignerDMatrix_Q::Uninitialized),
    R(0,0,0,0), RzRbar3(0.),
    Mag_Rz_3_0(0.), Mag_Rz_1_2(0.),
    Arg_Rz_3_0(0.), Arg_Rz_1_2(0.),
    Recalculated(false), ValMag(0.0), ValArg(0.0)
{
  SetQuaternion(D.R);
  SetElement(D.L, D.MP, D.M);
}

// WignerDMatrix_Q& WignerDMatrix_Q::operator=(const WignerDMatrix_Q& D) {
//   L = D.L;
//   MP = D.MP;
//   M = D.M;
//   Calculator = D.Calculator;
//   R = D.R;
//   RzRbar3 = D.RzRbar3;
//   Mag_Rz_3_0 = D.Mag_Rz_3_0;
//   Mag_Rz_1_2 = D.Mag_Rz_1_2;
//   Arg_Rz_3_0 = D.Arg_Rz_3_0;
//   Arg_Rz_1_2 = D.Arg_Rz_1_2;
//   Recalculated = D.Recalculated;
//   ValMag = D.ValMag;
//   ValArg = D.ValArg;
//   return *this;
// }

void WignerDMatrix_Q::Value(double& Mag, double& Arg) {
  // if(Recalculated) {
  //   Mag=ValMag;
  //   Arg=ValArg;
  //   return;
  // }
  Mag = (this->*Calculator)();
  Arg = 0.0;
  if(std::abs(Mag)==0.0) { return; }
  if(std::abs(Arg_Rz_3_0)>3*numeric_limits<double>::epsilon() || M+MP>0) {
    Arg += Arg_Rz_3_0*(M+MP);
  }
  if(std::abs(Arg_Rz_1_2)>3*numeric_limits<double>::epsilon() || M-MP>0) {
    Arg += Arg_Rz_1_2*(M-MP);
  }
  if(Mag<-3*numeric_limits<double>::epsilon()) {
    Mag *= -1;
    Arg -= M_PI;
  }
  // ValMag=Mag;
  // ValArg=Arg;
  // Recalculated=true;
  // std::cout << "l=" << L << "\tmp=" << MP << "\tM=" << M << std::setprecision(16) << "\tMag=" << Mag << "\tArg=" << Arg << "\t:\t"
  // 	    << R << " " << RzRbar3 << " " << Mag_Rz_3_0 << " " << Mag_Rz_1_2 << " " << Arg_Rz_3_0 << " " << Arg_Rz_1_2 << std::endl;
  return;
}

void WignerDMatrix_Q::ValueReIm(double& Re, double& Im) {
  double Mag, Arg;
  Value(Mag, Arg);
  Re = Mag*cos(Arg);
  Im = Mag*sin(Arg);
  return;
}

void WignerDMatrix_Q::SetQuaternion(const Quaternion& iR) {
  // if(R==iR) { return; }
  const Quaternion iRNormalized = iR.Normalized();
  // if(R==iRNormalized) { return; }
  Recalculated = false;
  R = iRNormalized;
  if(std::abs(R[0])<2*numeric_limits<double>::epsilon()) { R[0]=0.0; }
  if(std::abs(R[1])<2*numeric_limits<double>::epsilon()) { R[1]=0.0; }
  if(std::abs(R[2])<2*numeric_limits<double>::epsilon()) { R[2]=0.0; }
  if(std::abs(R[3])<2*numeric_limits<double>::epsilon()) { R[3]=0.0; }
  Quaternion Rz = R*Quaternion(0,0,0,1);
  RzRbar3 = (Rz*(R.Conjugate()))[3];
  Mag_Rz_3_0 = sqrt(Rz[0]*Rz[0]+Rz[3]*Rz[3]);
  Mag_Rz_1_2 = sqrt(Rz[1]*Rz[1]+Rz[2]*Rz[2]);
  if(Mag_Rz_3_0<3*numeric_limits<double>::epsilon()) {
    Mag_Rz_3_0 = 0.0;
    Arg_Rz_3_0 = 0.0;
  } else {
    Arg_Rz_3_0 = atan2(-Rz[0], Rz[3]);
  }
  if(Mag_Rz_1_2<3*numeric_limits<double>::epsilon()) {
    Mag_Rz_1_2 = 0.0;
    Arg_Rz_1_2 = 0.0;
  } else {
    Arg_Rz_1_2 = atan2( Rz[2], Rz[1]);
  }
  // std::cout << R << " " << RzRbar3 << " " << Mag_Rz_3_0 << " " << Mag_Rz_1_2 << " " << Arg_Rz_3_0 << " " << Arg_Rz_1_2 << std::endl;
  return;
}

void WignerDMatrix_Q::SetElement(const int iL, const int iMP, const int iM) {
  if(iL==L && iMP==MP && iM==M) { return; }
  Recalculated = false;
  
  if(iL<0) {
    Calculator = &WignerDMatrix_Q::Uninitialized;
    return;
  }
  
  if(iL>8) {
    std::cerr << "\nL=" << iL << std::endl;
    throw("This L value not yet implemented for Wigner D matrices.");
  }
  
  if(std::abs(iMP)>iL || std::abs(iM)>iL) {
    std::cerr << "\nL=" << iL << "  MP=" << iMP << "  M=" << iM << std::endl;
    throw("Bad MP or M, out of range for Wigner D matrix.");
  }
  
  L=iL;
  MP=iMP;
  M=iM;
  
  
  if(R[0]==1.0) { // We can test equality because the value was set precisely in SetQuaternion if applicable
    if(MP==M) {
      Calculator = &WignerDMatrix_Q::Identity;
    } else {
      Calculator = &WignerDMatrix_Q::Zero;
    }
    return;
  }
  
  
  
  switch(L) {
  case 8:
    switch(M) {
    case -8:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg8;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg8;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg8;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg8;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg8;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg8;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg8;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg8;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg8;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg8;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg8;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg8;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg8;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg8;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg8;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg8;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg8;
        return;
      } // switch(MP)
      return;
      
    case -7:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg7;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg7;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg7;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg7;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg7;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg7;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg7;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg7;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg7;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg7;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg7;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg7;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg7;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg7;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg7;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg7;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg7;
        return;
      } // switch(MP)
      return;
      
    case -6:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg6;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg6;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg6;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg6;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg6;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg6;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg6;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg6;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg6;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg6;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg6;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg6;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg6;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg6;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg6;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg6;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg6;
        return;
      } // switch(MP)
      return;
      
    case -5:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg5;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg5;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg5;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg5;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg5;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg5;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg5;
        return;
      } // switch(MP)
      return;
      
    case -4:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg4;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg4;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg4;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg4;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg4;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg4;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg4;
        return;
      } // switch(MP)
      return;
      
    case -3:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg3;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg3;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg3;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg3;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg3;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg3;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg3;
        return;
      } // switch(MP)
      return;
      
    case -2:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg2;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg2;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg2;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg2;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg2;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg2;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_neg1;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_neg1;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_neg1;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_neg1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_neg1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_neg1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_neg1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_neg1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_neg1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_neg1;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_neg1;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_neg1;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_0;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_0;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_0;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_0;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_0;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_0;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_0;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_0;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_0;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_0;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_0;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_0;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_1;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_1;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_1;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_1;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_1;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_1;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_2;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_2;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_2;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_2;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_2;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_2;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_2;
        return;
      } // switch(MP)
      return;
      
    case 3:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_3;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_3;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_3;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_3;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_3;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_3;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_3;
        return;
      } // switch(MP)
      return;
      
    case 4:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_4;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_4;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_4;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_4;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_4;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_4;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_4;
        return;
      } // switch(MP)
      return;
      
    case 5:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_5;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_5;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_5;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_5;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_5;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_5;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_5;
        return;
      } // switch(MP)
      return;
      
    case 6:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_6;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_6;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_6;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_6;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_6;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_6;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_6;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_6;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_6;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_6;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_6;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_6;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_6;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_6;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_6;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_6;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_6;
        return;
      } // switch(MP)
      return;
      
    case 7:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_7;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_7;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_7;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_7;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_7;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_7;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_7;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_7;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_7;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_7;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_7;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_7;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_7;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_7;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_7;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_7;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_7;
        return;
      } // switch(MP)
      return;
      
    case 8:
      switch(MP) {
      case -8:
        Calculator = &WignerDMatrix_Q::D_8_neg8_8;
        return;
      case -7:
        Calculator = &WignerDMatrix_Q::D_8_neg7_8;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_8_neg6_8;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_8_neg5_8;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_8_neg4_8;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_8_neg3_8;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_8_neg2_8;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_8_neg1_8;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_8_0_8;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_8_1_8;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_8_2_8;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_8_3_8;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_8_4_8;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_8_5_8;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_8_6_8;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_8_7_8;
        return;
      case 8:
        Calculator = &WignerDMatrix_Q::D_8_8_8;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 7:
    switch(M) {
    case -7:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg7;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg7;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg7;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg7;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg7;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg7;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg7;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg7;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg7;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg7;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg7;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg7;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg7;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg7;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg7;
        return;
      } // switch(MP)
      return;
      
    case -6:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg6;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg6;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg6;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg6;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg6;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg6;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg6;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg6;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg6;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg6;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg6;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg6;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg6;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg6;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg6;
        return;
      } // switch(MP)
      return;
      
    case -5:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg5;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg5;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg5;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg5;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg5;
        return;
      } // switch(MP)
      return;
      
    case -4:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg4;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg4;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg4;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg4;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg4;
        return;
      } // switch(MP)
      return;
      
    case -3:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg3;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg3;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg3;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg3;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg3;
        return;
      } // switch(MP)
      return;
      
    case -2:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg2;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg2;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg2;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg2;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_neg1;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_neg1;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_neg1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_neg1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_neg1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_neg1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_neg1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_neg1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_neg1;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_neg1;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_0;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_0;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_0;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_0;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_0;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_0;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_0;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_0;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_0;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_0;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_1;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_1;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_1;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_1;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_2;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_2;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_2;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_2;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_2;
        return;
      } // switch(MP)
      return;
      
    case 3:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_3;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_3;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_3;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_3;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_3;
        return;
      } // switch(MP)
      return;
      
    case 4:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_4;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_4;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_4;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_4;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_4;
        return;
      } // switch(MP)
      return;
      
    case 5:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_5;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_5;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_5;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_5;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_5;
        return;
      } // switch(MP)
      return;
      
    case 6:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_6;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_6;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_6;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_6;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_6;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_6;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_6;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_6;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_6;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_6;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_6;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_6;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_6;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_6;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_6;
        return;
      } // switch(MP)
      return;
      
    case 7:
      switch(MP) {
      case -7:
        Calculator = &WignerDMatrix_Q::D_7_neg7_7;
        return;
      case -6:
        Calculator = &WignerDMatrix_Q::D_7_neg6_7;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_7_neg5_7;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_7_neg4_7;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_7_neg3_7;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_7_neg2_7;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_7_neg1_7;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_7_0_7;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_7_1_7;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_7_2_7;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_7_3_7;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_7_4_7;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_7_5_7;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_7_6_7;
        return;
      case 7:
        Calculator = &WignerDMatrix_Q::D_7_7_7;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 6:
    switch(M) {
    case -6:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_neg6;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_neg6;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_neg6;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_neg6;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_neg6;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_neg6;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_neg6;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_neg6;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_neg6;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_neg6;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_neg6;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_neg6;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_neg6;
        return;
      } // switch(MP)
      return;
      
    case -5:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_neg5;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_neg5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_neg5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_neg5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_neg5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_neg5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_neg5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_neg5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_neg5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_neg5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_neg5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_neg5;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_neg5;
        return;
      } // switch(MP)
      return;
      
    case -4:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_neg4;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_neg4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_neg4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_neg4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_neg4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_neg4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_neg4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_neg4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_neg4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_neg4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_neg4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_neg4;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_neg4;
        return;
      } // switch(MP)
      return;
      
    case -3:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_neg3;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_neg3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_neg3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_neg3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_neg3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_neg3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_neg3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_neg3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_neg3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_neg3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_neg3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_neg3;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_neg3;
        return;
      } // switch(MP)
      return;
      
    case -2:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_neg2;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_neg2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_neg2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_neg2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_neg2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_neg2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_neg2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_neg2;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_neg1;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_neg1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_neg1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_neg1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_neg1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_neg1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_neg1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_neg1;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_0;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_0;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_0;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_0;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_0;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_0;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_0;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_0;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_1;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_1;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_2;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_2;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_2;
        return;
      } // switch(MP)
      return;
      
    case 3:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_3;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_3;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_3;
        return;
      } // switch(MP)
      return;
      
    case 4:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_4;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_4;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_4;
        return;
      } // switch(MP)
      return;
      
    case 5:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_5;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_5;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_5;
        return;
      } // switch(MP)
      return;
      
    case 6:
      switch(MP) {
      case -6:
        Calculator = &WignerDMatrix_Q::D_6_neg6_6;
        return;
      case -5:
        Calculator = &WignerDMatrix_Q::D_6_neg5_6;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_6_neg4_6;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_6_neg3_6;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_6_neg2_6;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_6_neg1_6;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_6_0_6;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_6_1_6;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_6_2_6;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_6_3_6;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_6_4_6;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_6_5_6;
        return;
      case 6:
        Calculator = &WignerDMatrix_Q::D_6_6_6;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 5:
    switch(M) {
    case -5:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_neg5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_neg5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_neg5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_neg5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_neg5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_neg5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_neg5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_neg5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_neg5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_neg5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_neg5;
        return;
      } // switch(MP)
      return;
      
    case -4:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_neg4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_neg4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_neg4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_neg4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_neg4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_neg4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_neg4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_neg4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_neg4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_neg4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_neg4;
        return;
      } // switch(MP)
      return;
      
    case -3:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_neg3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_neg3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_neg3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_neg3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_neg3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_neg3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_neg3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_neg3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_neg3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_neg3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_neg3;
        return;
      } // switch(MP)
      return;
      
    case -2:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_neg2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_neg2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_neg2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_neg2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_neg2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_neg2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_neg1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_neg1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_neg1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_neg1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_neg1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_neg1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_0;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_0;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_0;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_0;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_0;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_0;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_1;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_1;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_2;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_2;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_2;
        return;
      } // switch(MP)
      return;
      
    case 3:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_3;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_3;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_3;
        return;
      } // switch(MP)
      return;
      
    case 4:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_4;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_4;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_4;
        return;
      } // switch(MP)
      return;
      
    case 5:
      switch(MP) {
      case -5:
        Calculator = &WignerDMatrix_Q::D_5_neg5_5;
        return;
      case -4:
        Calculator = &WignerDMatrix_Q::D_5_neg4_5;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_5_neg3_5;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_5_neg2_5;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_5_neg1_5;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_5_0_5;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_5_1_5;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_5_2_5;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_5_3_5;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_5_4_5;
        return;
      case 5:
        Calculator = &WignerDMatrix_Q::D_5_5_5;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 4:
    switch(M) {
    case -4:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_neg4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_neg4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_neg4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_neg4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_neg4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_neg4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_neg4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_neg4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_neg4;
        return;
      } // switch(MP)
      return;
      
    case -3:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_neg3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_neg3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_neg3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_neg3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_neg3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_neg3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_neg3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_neg3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_neg3;
        return;
      } // switch(MP)
      return;
      
    case -2:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_neg2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_neg2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_neg2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_neg2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_neg1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_neg1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_neg1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_neg1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_0;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_0;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_0;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_0;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_1;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_1;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_2;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_2;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_2;
        return;
      } // switch(MP)
      return;
      
    case 3:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_3;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_3;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_3;
        return;
      } // switch(MP)
      return;
      
    case 4:
      switch(MP) {
      case -4:
        Calculator = &WignerDMatrix_Q::D_4_neg4_4;
        return;
      case -3:
        Calculator = &WignerDMatrix_Q::D_4_neg3_4;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_4_neg2_4;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_4_neg1_4;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_4_0_4;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_4_1_4;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_4_2_4;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_4_3_4;
        return;
      case 4:
        Calculator = &WignerDMatrix_Q::D_4_4_4;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 3:
    switch(M) {
    case -3:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_neg3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_neg3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_neg3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_neg3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_neg3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_neg3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_neg3;
        return;
      } // switch(MP)
      return;
      
    case -2:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_neg2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_neg2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_neg1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_neg1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_0;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_0;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_1;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_1;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_2;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_2;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_2;
        return;
      } // switch(MP)
      return;
      
    case 3:
      switch(MP) {
      case -3:
        Calculator = &WignerDMatrix_Q::D_3_neg3_3;
        return;
      case -2:
        Calculator = &WignerDMatrix_Q::D_3_neg2_3;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_3_neg1_3;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_3_0_3;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_3_1_3;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_3_2_3;
        return;
      case 3:
        Calculator = &WignerDMatrix_Q::D_3_3_3;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 2:
    switch(M) {
    case -2:
      switch(MP) {
      case -2:
        Calculator = &WignerDMatrix_Q::D_2_neg2_neg2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_2_neg1_neg2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_2_0_neg2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_2_1_neg2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_2_2_neg2;
        return;
      } // switch(MP)
      return;
      
    case -1:
      switch(MP) {
      case -2:
        Calculator = &WignerDMatrix_Q::D_2_neg2_neg1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_2_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_2_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_2_1_neg1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_2_2_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -2:
        Calculator = &WignerDMatrix_Q::D_2_neg2_0;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_2_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_2_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_2_1_0;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_2_2_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -2:
        Calculator = &WignerDMatrix_Q::D_2_neg2_1;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_2_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_2_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_2_1_1;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_2_2_1;
        return;
      } // switch(MP)
      return;
      
    case 2:
      switch(MP) {
      case -2:
        Calculator = &WignerDMatrix_Q::D_2_neg2_2;
        return;
      case -1:
        Calculator = &WignerDMatrix_Q::D_2_neg1_2;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_2_0_2;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_2_1_2;
        return;
      case 2:
        Calculator = &WignerDMatrix_Q::D_2_2_2;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 1:
    switch(M) {
    case -1:
      switch(MP) {
      case -1:
        Calculator = &WignerDMatrix_Q::D_1_neg1_neg1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_1_0_neg1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_1_1_neg1;
        return;
      } // switch(MP)
      return;
      
    case 0:
      switch(MP) {
      case -1:
        Calculator = &WignerDMatrix_Q::D_1_neg1_0;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_1_0_0;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_1_1_0;
        return;
      } // switch(MP)
      return;
      
    case 1:
      switch(MP) {
      case -1:
        Calculator = &WignerDMatrix_Q::D_1_neg1_1;
        return;
      case 0:
        Calculator = &WignerDMatrix_Q::D_1_0_1;
        return;
      case 1:
        Calculator = &WignerDMatrix_Q::D_1_1_1;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  case 0:
    switch(M) {
    case 0:
      switch(MP) {
      case 0:
        Calculator = &WignerDMatrix_Q::D_0_0_0;
        return;
      } // switch(MP)
      return;
      
    } // switch(M)
    return;
    
  } // switch(L)
  
  throw("Shouldn't have gotten here");
  return;
}
