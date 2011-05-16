#include "EOBModel.hpp"

#include <cmath>
using std::sqrt;

void WaveformUtilities::EOBMetricWithSpin::operator()(const double r_new) {
  if(r==r_new) { return; }
  r = r_new;
  choke;
  drdrstar = sqrt(Deltat*DeltaR) / (r*r+chieff*chieff);
  drstardr = 1.0 / drstardr;
  return;
}

void WaveformUtilities::EOBHamiltonianWithSpin::operator()(const double r_new, const double prstar_new, const double pPhi_new) {
  g(r);
  if(r==r_new && prstar==prstar_new && pPhi_new) { return; }
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  choke;
  return;
}

