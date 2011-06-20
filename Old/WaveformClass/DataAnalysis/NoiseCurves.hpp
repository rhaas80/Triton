#ifndef NOISECURVES_HPP
#define NOISECURVES_HPP

#include <vector>
#include <string>

// These functions return various noise curves as described in LIGO-T0900288-v3, and fit by Collin Capano.
// Noise curves implemented thus far are:
//   AdvLIGO_NSNSOptimal
//   AdvLIGO_ZeroDet_HighP
//   AdvLIGO_ZeroDet_LowP
std::vector<double> NoiseCurve(const std::vector<double>& F, const std::string& Detector="AdvLIGO_ZeroDet_HighP", const bool Invert=false, const double NoiseFloor=0.0);
std::vector<double> InverseNoiseCurve(const std::vector<double>& F, const std::string& Detector="AdvLIGO_ZeroDet_HighP", const double NoiseFloor=0.0);

// These constants are reported in the Advanced LIGO design study http://www.ligo.caltech.edu/docs/T/T010075-00.pdf
// Note that the sampling rate is frequently cut down by data analysts to 1/2 or 1/4 before any data is processed.
// Also note that a more realistic seismic wall early in Adv. LIGO's life will be more like 20Hz.
const double AdvLIGOSeismicWall(10.0); // Units of Hz
const double AdvLIGOSamplingFreq(16384.0); // Units of Hz

const double IniLIGOSeismicWall(40.0); // Units of Hz
const double IniLIGOSamplingFreq(8192.0); // Units of Hz

const double VirgoSeismicWall(10.0); // Units of Hz
const double VirgoSamplingFreq(16384.0); // Units of Hz

#endif // NOISECURVES_HPP
