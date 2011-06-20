#ifndef QUASINORMALMODES_HPP
#define QUASINORMALMODES_HPP

#include <vector>
#include <complex>

void QNMFrequencies(const int& L, const int& M, const int& N, const double& chi, double& omegaRe, double& omegaIm);
std::complex<double> QNMFrequencies(const int& L, const int& M, const int& N, const double& chi);

std::vector<std::vector<int> > AvailableQNMLMs();

#endif // QUASINORMALMODES_HPP
