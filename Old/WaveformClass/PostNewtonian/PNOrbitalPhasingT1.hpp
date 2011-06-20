#ifndef PNORBITALPHASINGT1_HPP
#define PNORBITALPHASINGT1_HPP

#include <vector>

void TaylorT1(const double delta, const double chia, const double chis, const double v0,
              std::vector<double>& t, std::vector<double>& v, std::vector<double>& phi,
              const double PNPhaseOrder=3.5, const int nsave=250, const bool denseish=true);

#endif // PNORBITALPHASINGT1_HPP
