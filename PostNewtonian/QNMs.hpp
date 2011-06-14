#ifndef QNMS_HPP
#define QNMS_HPP

#include "Matrix.hpp"

/// omegalmn = omegaRe + i*omegaIm
/// Psi_4^{(lmn)} = Almn * exp(i * omegalmn * (t-t0))

namespace WaveformUtilities {
  
  /// This function replaces the last two arguments with the real and imaginary parts of omegalmn
  void QNM(const int L, const int M, const int N, const double chi, double& omegaRe, double& omegaIm);
  
  WaveformUtilities::Matrix<int> QNMLMs();
  
}

#endif // QNMS_HPP
