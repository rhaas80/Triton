#ifndef EOBORBITALPHASING_HPP
#define EOBORBITALPHASING_HPP

#include <vector>

void EOB(const double delta, const double chia, const double chis, const double v0,
	 std::vector<double>& t, std::vector<double>& v, std::vector<double>& phi,
	 const double PNPhaseOrder, //=3.5, 
	 std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi,
	 const int nsave=40, const bool denseish=true);

#endif // EOBORBITALPHASING_HPP
