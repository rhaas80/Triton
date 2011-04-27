#ifndef GAUSSJORDANELIMINATION_HPP
#define GAUSSJORDANELIMINATION_HPP

#include "NumericalRecipes.hpp"

void gaussj(MatDoub_IO &a, MatDoub_IO &b);
void cgaussj(MatComplex_IO &a, MatComplex_IO &b);

namespace WaveformUtilities {
  
  void GaussJordanElimination(WaveformUtilities::Matrix<double>& A, std::vector<double>& b);
  void GaussJordanElimination(WaveformUtilities::Matrix<double>& A, WaveformUtilities::Matrix<double>& B);
  void GaussJordanElimination(WaveformUtilities::Matrix<std::complex<double> >& A, std::vector<std::complex<double> >& b);
  void GaussJordanElimination(WaveformUtilities::Matrix<std::complex<double> >& A, WaveformUtilities::Matrix<std::complex<double> >& B);
  
}

#endif // GAUSSJORDANELIMINATION_HPP
