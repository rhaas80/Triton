#ifndef ORBITALPHASING_T4_HPP
#define ORBITALPHASING_T4_HPP

#include <vector>

namespace WaveformUtilities {
  
  void TaylorT4(const double delta, const double chis, const double chia, const double v0,
		std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		const int nsave=500, const bool denseish=true);
  
}

#endif // ORBITALPHASING_T4_HPP
