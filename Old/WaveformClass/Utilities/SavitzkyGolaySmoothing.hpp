#ifndef SAVGOL_HPP
#define SAVGOL_HPP

#include <vector>

std::vector<double> SavitzkyGolaySmoothing(const std::vector<double>& y, const int NLeft=16, const int NRight=16, const int PolyOrder=4, const int DerivOrder=0);


#endif // SAVGOL_HPP
