#ifndef SWSHS_HPP
#define SWSHS_HPP

/// These functions compute the spin-weight s=-2 spherical harmonics

#include <vector>

namespace WaveformUtilities {
  
  void SWSH(const int L, const int M, const double vartheta, const double varphi, double& amp, double& arg);
  void SWSH(const std::vector<std::vector<int> >& LM, const double vartheta, const double varphi, std::vector<double>& amp, std::vector<double>& arg);
  
}

#endif // SWSHS_HPP
