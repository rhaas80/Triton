#ifndef WIGNERDMATRIX_HPP
#define WIGNERDMATRIX_HPP

/// These functions compute the Wigner D matrices.  Note that m' comes before m.

namespace WaveformUtilities {
  
  class WignerDMatrix {
  private: // Member data
    int L, MP, M;
    void (*Calculator)(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag);
    double alpha, beta, gamma;
    double sinbetaovertwo, cosbetaovertwo;
  public: // Constructors
    WignerDMatrix(const int L=-1, const int MP=-1, const int M=-1);
  public: // Setty methods
    void Element(const int L, const int MP, const int M);
    void Angles(const double ialpha, const double ibeta, const double igamma);
  public: // Getty method
    void Value(double& Mag, double& Arg);
  };
  
  //void WignerD(const int L, const int MP, const int M, const double vartheta, const double varphi, double& amp, double& arg);
  
}

#endif // WIGNERDMATRIX_HPP
