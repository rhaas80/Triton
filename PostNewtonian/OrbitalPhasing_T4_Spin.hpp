#ifndef ORBITALPHASING_T4_SPIN_HPP
#define ORBITALPHASING_T4_SPIN_HPP

#include <vector>

namespace WaveformUtilities {
  
  void TaylorT4Spin(const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2, const double v0,
		    std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		    std::vector<double>& chis, std::vector<double>& chia, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma,
		    const int nsave=500, const bool denseish=true);
  
  void TaylorT4Spin(const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2, const double v0,
		    std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		    std::vector<std::vector<double> >& S1, std::vector<std::vector<double> >& S2, std::vector<std::vector<double> >& LNHat,
		    const int nsave=500, const bool denseish=true);
  
}

#endif // ORBITALPHASING_T4_SPIN_HPP
