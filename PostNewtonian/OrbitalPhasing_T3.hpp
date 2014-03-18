#ifndef ORBITALPHASING_T3_HPP
#define ORBITALPHASING_T3_HPP

#include <vector>

namespace WaveformUtilities {

  void TaylorT3(const double delta, const double chis, const double chia, const double v0,
                std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
                const int NPoints=5000);

}

#endif // ORBITALPHASING_T3_HPP
