#ifndef WIGNERDMATRIX_HPP
#define WIGNERDMATRIX_HPP

/// These functions compute the Wigner D matrices.  Note that m' comes
/// before m.

namespace WaveformUtilities {

  class WignerDMatrix {
  private: // Member data
    int L, MP, M;
    void (*Calculator)(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag);
    double alpha, beta, gamma;
    double sinbetaovertwo, cosbetaovertwo;
  public: // Constructors
    WignerDMatrix(const int L=-1, const int MP=-1, const int M=-1,
                  const double ialpha=0.0, const double ibeta=0.0, const double igamma=0.0);
  public: // Setty methods
    void SetAngles(const double ialpha, const double ibeta, const double igamma);
    void SetElement(const int iL, const int iMP, const int iM);
  public: // Get the value of this matrix element at this angle
    void Value(double& Mag, double& Arg);
    void ValueReIm(double& Re, double& Im);
  };

  void WignerD(const int L, const int MP, const int M, const double alpha, const double beta, const double gamma, double& mag, double& arg);

}

#endif // WIGNERDMATRIX_HPP
