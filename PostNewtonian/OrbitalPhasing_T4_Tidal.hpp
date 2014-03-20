#ifndef ORBITALPHASING_T4_TIDAL_HPP
#define ORBITALPHASING_T4_TIDAL_HPP

#include <vector>

namespace WaveformUtilities {
  
  void TaylorT4Tidal(const double delta, const double chis, const double chia, const double v0,
		std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi, 
		const double love1, const double love2, const double compact1, const double compact2, const int nsave=500, const bool denseish=true);
  
}

#endif // ORBITALPHASING_T4_TIDAL_HPP