#ifndef WIGNERDMATRIX_Q_HPP
#define WIGNERDMATRIX_Q_HPP

#include "Quaternions.hpp"

namespace WaveformUtilities {
  
  /// These functions compute the Wigner D matrices in terms of a
  /// quaternion.  Note that m' comes before m in the argument lists.
  class WignerDMatrix_Q {
  private: // Member data
    int L, MP, M;
    double (WignerDMatrix_Q::*Calculator)();
    Quaternion R;
    double RzRbar3;
    double Mag_Rz_3_0, Mag_Rz_1_2;
    double Arg_Rz_3_0, Arg_Rz_1_2;
    bool Recalculated;
    double ValMag, ValArg;
    #ifdef WIGNERDMATRIX_Q_CPP
    #include "WignerDMatrix_Q.ipp"
    #endif
  public: // Constructors
    WignerDMatrix_Q(const int iL=-1, const int iMP=-1, const int iM=-1, const Quaternion iR=Quaternion(1,0,0,0));
    WignerDMatrix_Q(const WignerDMatrix_Q& D);
  private:
    WignerDMatrix_Q& operator=(const WignerDMatrix_Q& D);
  public: // Setty methods
    void SetQuaternion(const Quaternion& iR);
    void SetElement(const int iL, const int iMP, const int iM);
  public: // Get the value of this matrix element at this angle
    void Value(double& Mag, double& Arg);
    void ValueReIm(double& Re, double& Im);
  };
  
  void WignerD_Q(const int L, const int MP, const int M, const Quaternion& R, double& mag, double& arg);
  
}

#endif // WIGNERDMATRIX_Q_HPP
