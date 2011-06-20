#ifndef PNAMPLITUDES_HPP
#define PNAMPLITUDES_HPP

#include <vector>

void PNAmplitudes(const int L, const int M, const std::vector<double>& v, const std::vector<double>& Phi, const double delta,
		  const double chia, const double chis, std::vector<double>& amp, std::vector<double>& phi, const double PNAmpOrder=3.);

#endif // PNAMPLITUDES_HPP
