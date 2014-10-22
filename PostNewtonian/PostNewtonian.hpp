#ifndef POSTNEWTONIAN_HPP
#define POSTNEWTONIAN_HPP

#include "NumericalRecipes.hpp"

namespace WaveformUtilities {
  const int PNLMax = 8;

  double nuOFdelta(const double delta);
  double deltaOFq(const double q);

  double FinalSpinApproximation(const double delta, const double chis);
}

#include "OrbitalPhasing_T1.hpp"
#include "OrbitalPhasing_T2.hpp"
#include "OrbitalPhasing_T3.hpp"
#include "OrbitalPhasing_T4.hpp"
#include "OrbitalPhasing_T4_Spin.hpp"
#include "OrbitalPhasing_EOB.hpp"
#include "OrbitalPhasing_T1_Tidal.hpp"
#include "OrbitalPhasing_T2_Tidal.hpp"
#include "OrbitalPhasing_T3_Tidal.hpp"
#include "OrbitalPhasing_T4_Tidal.hpp"
#include "QNMs.hpp"
#include "WaveformAmplitudes.hpp"
// #include "WaveformAmplitudesResummed.hpp"

#endif // POSTNEWTONIAN_HPP
