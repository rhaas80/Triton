#ifndef WIGNERDMATRIX_Q_HPP
#define WIGNERDMATRIX_Q_HPP

#include "Quaternions.hpp"

namespace WaveformUtilities {
  
  /// Compute Wigner D matrix elements in terms of a quaternion.
  class WignerDMatrix_Q {
    /// Note that m' comes before m in the argument lists.
    /// 
    /// The reason for using a class is to speed up the evaluation.
    /// For example, frequently the function will be called many times
    /// with the same (l,m',m); rather than re-switching, we just
    /// store the appropriate information.  Alternatively, the
    /// function may be called many times with the same quaternion;
    /// rather than recalculating the intermediate values that go into
    /// the calculation, we just store them.
  private: // Member data
    int L, MP, M;
    double (WignerDMatrix_Q::*Calculator)();
    Quaternion R;
    double RzRbar3;
    double Mag_Rz_3_0, Mag_Rz_1_2;
    double Arg_Rz_3_0, Arg_Rz_1_2;
    bool Recalculated;
    double ValMag, ValArg;
  private: // member functions for calculating the actual values
    #ifdef WIGNERDMATRIX_Q_CPP
    #include "WignerDMatrix_Q.ipp"
    #endif
  public: // Constructors
    WignerDMatrix_Q(const int iL=-1, const int iMP=-1, const int iM=-1, const Quaternion iR=Quaternion(1,0,0,0));
    WignerDMatrix_Q(const WignerDMatrix_Q& D);
  private: // We disable this and don't define it
    WignerDMatrix_Q& operator=(const WignerDMatrix_Q& D);
  public: // Setty methods
    void SetQuaternion(const Quaternion& iR);
    void SetElement(const int iL, const int iMP, const int iM);
  public: // Get the value of this matrix element at this angle
    void Value(double& Mag, double& Arg);
    void ValueReIm(double& Re, double& Im);
  };
  
  /// Evaluate the requested Wigner D matrix element.
  /// 
  /// Note that m' comes before m in the argument list.
  /// 
  /// This function instantiates an object of class WignerDMatrix_Q.
  /// If this function is called multiple times, it would almost
  /// certainly be more efficient to use the class directly, rather
  /// than this function.
  void WignerD_Q(const int L, const int MP, const int M, const Quaternion& R, double& mag, double& arg);
  
}

#endif // WIGNERDMATRIX_Q_HPP
