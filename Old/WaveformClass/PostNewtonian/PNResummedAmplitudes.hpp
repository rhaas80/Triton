#ifndef PNRESUMMEDAMPLITUDES_HPP
#define PNRESUMMEDAMPLITUDES_HPP

#include <vector>

void PNResummedAmplitudes(const int L, const int M, const std::vector<double>& r, const std::vector<double>& v, const std::vector<double>& vPhi,
			  const std::vector<double>& Phi,
			  const std::vector<double>& Omega, const std::vector<double>& pPhi, const std::vector<double>& Heff, const std::vector<double>& Hreal,
			  const double delta, const double chia, const double chis, std::vector<double>& amp, std::vector<double>& phi,
			  const double PNAmpOrder=3.);

#endif // PNRESUMMEDAMPLITUDES_HPP
