#ifndef ORBITALPHASING_T1_HPP
#define ORBITALPHASING_T1_HPP

#include <vector>

namespace WaveformUtilities {
  
  void TaylorT1(const double delta, const double chis, const double v0,
		std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		const int nsave=250, const bool denseish=true);
  
}

#endif // ORBITALPHASING_T1_HPP
