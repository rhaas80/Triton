#ifndef ORBITALPHASING_T2_HPP
#define ORBITALPHASING_T2_HPP

#include <vector>

namespace WaveformUtilities {
  
  void TaylorT2(const double delta, const double chis, const double v0,
		std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		const int NPoints=5000);
  
}

#endif // ORBITALPHASING_T2_HPP
