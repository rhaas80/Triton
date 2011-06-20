#ifndef PNORBITALPHASINGT2_HPP
#define PNORBITALPHASINGT2_HPP

#include <vector>

void TaylorT2(const double delta, const double chia, const double chis, const double v0,
              std::vector<double>& t, std::vector<double>& v, std::vector<double>& phi,
              const double PNPhaseOrder=3.5, const unsigned int NPoints=50000);

#endif // PNORBITALPHASINGT2_HPP
