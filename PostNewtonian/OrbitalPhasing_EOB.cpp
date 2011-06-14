#include "OrbitalPhasing_EOB.hpp"

void WaveformUtilities::EOB(const double delta, const double chis, const double chia, const double v0,
			    std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
			    const int nsave, const bool denseish, const double rtol)
{
  const EOBMetricWithSpin g(delta, chis, chia);
  const EOBHamiltonianWithSpin H(delta, chis, chia, g);
  const Flux_Pade44LogFac F(delta, chis);
  const Torque_KFPhi<Flux_Pade44LogFac> T(delta, chis, F);
  std::vector<double> r, prstar, pPhi;
  EOB(g, H, T, delta, chis, chia, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish, rtol);
  return;
}
