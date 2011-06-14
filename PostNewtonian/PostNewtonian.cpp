#include "PostNewtonian.hpp"

double WaveformUtilities::nuOFdelta(const double delta) {
  return (1.0-delta*delta)/4.0;
}

double WaveformUtilities::deltaOFq(const double q) {
  return (q-1.0)/(q+1.0);
}

double WaveformUtilities::FinalSpinApproximation(const double delta, const double chis) {
  double guess = sqrt(12)*nuOFdelta(delta)-3.87128*nuOFdelta(delta)*nuOFdelta(delta)+4.02788*nuOFdelta(delta)*nuOFdelta(delta)*nuOFdelta(delta);
  guess = (guess<chis ? chis : guess);
  return (guess>0.998 ? 0.998 : guess);
}
