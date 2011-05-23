#ifndef EOBORBITALPHASING_HPP
#define EOBORBITALPHASING_HPP

#include <vector>

namespace WaveformUtilities {
  
  void EOB(const double delta, const double chis, const double v0,
	   std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	   std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi,
	   const int nsave=40, const bool denseish=true, const double rtol=1e-10);
  
}

#endif // EOBORBITALPHASING_HPP
