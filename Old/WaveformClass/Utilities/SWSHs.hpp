#ifndef SWSHS_HPP
#define SWSHS_HPP

#include <vector>

// These functions compute the spin-weight s=-2 spherical harmonics

void SWSH(const int L, const int M, const double& vartheta, const double& varphi, double& amp, double& phi);
void SWSH(const std::vector<std::vector<int> >& LM, const double& vartheta, const double& varphi, std::vector<double>& amp, std::vector<double>& phi);

#endif // SWSHS_HPP
