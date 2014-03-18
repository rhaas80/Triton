#ifndef ECCENTRICITY_HPP
#define ECCENTRICITY_HPP

#include <vector>

namespace WaveformUtilities {

  double Eccentricity_rDot(const std::vector<double>& t, const std::vector<double>& rDot,
                           const double r0, const double Omega0, double& DeltarDot, double& DeltaPhiDot);

}

#endif // ECCENTRICITY_HPP
