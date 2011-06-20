#ifndef PNORBITALPHASINGT4_HPP
#define PNORBITALPHASINGT4_HPP

#include <vector>

void TaylorT4(const double delta, const double chia, const double chis, const double v0,
              std::vector<double>& t, std::vector<double>& v, std::vector<double>& phi,
              const double PNPhaseOrder=3.5, const int nsave=250, const bool denseish=true);

#endif // PNORBITALPHASINGT4_HPP
