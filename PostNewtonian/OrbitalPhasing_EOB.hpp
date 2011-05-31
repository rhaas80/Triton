#ifndef ORBITALPHASING_EOB_HPP
#define ORBITALPHASING_EOB_HPP

#include "NumericalRecipes.hpp"
#include "ODEIntegrator.hpp"
#include "Fit.hpp"
#include "VectorFunctions.hpp"
typedef int NRerror;

namespace WaveformUtilities {
  
  template <class Metric, class Hamiltonian, class Torque>
  void EOB(const Metric& g, const Hamiltonian& H, const Torque& T,
	   const double delta, const double chis, const double v0,
	   std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	   std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi,
	   const int nsave=40, const bool denseish=true, const double rtol=1e-10);
  
  #include "OrbitalPhasing_EOB.tpp"
  
}

#endif // ORBITALPHASING_EOB_HPP
