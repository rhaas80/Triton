#ifndef GAUSSJORDANELIMINATION_HPP
#define GAUSSJORDANELIMINATION_HPP

#include <complex>
#include <vector>

void GaussJordanElimination(std::vector<std::vector<double> >& A, std::vector<double>& b);
void GaussJordanElimination(std::vector<std::vector<double> >& A, std::vector<std::vector<double> >& B);
void GaussJordanElimination(std::vector<std::vector<std::complex<double> > >& A, std::vector<std::complex<double> >& b);
void GaussJordanElimination(std::vector<std::vector<std::complex<double> > >& A, std::vector<std::vector<std::complex<double> > >& B);

#endif // GAUSSJORDANELIMINATION_HPP
