#ifndef ORBITALPHASING_EOB_HPP
#define ORBITALPHASING_EOB_HPP

#include "NumericalRecipes.hpp"
#include "ODEIntegrator.hpp"
#include "Fit.hpp"
#include "Eccentricity.hpp"
#include "VectorFunctions.hpp"
#include "EOBModel.hpp"
#include "Flux.hpp"
typedef int NRerror;

namespace WaveformUtilities {
  
  /// Call using pre-defined Metric, Hamiltonian, and Torque
  template <class Metric, class Hamiltonian, class Torque>
  void EOB(const Metric& g, const Hamiltonian& H, const Torque& T,
	   const double delta, const double chis, const double chia, const double v0,
	   std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	   std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi,
	   const int nsave=40, const bool denseish=true, const double rtol=1e-9);
  
  /// Alternatively, just use my favorite choices, for a standard PN interface
  void EOB(const double delta, const double chis, const double chia, const double v0,
	   std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	   const int nsave=40, const bool denseish=true, const double rtol=1e-9);
  
  #include "OrbitalPhasing_EOB.tpp"
  
}

#endif // ORBITALPHASING_EOB_HPP
