#ifndef RADIATIONAXIS_HPP
#define RADIATIONAXIS_HPP

/// These functions find the radiation axis of a waveform, at an
/// instant, or as a function of time.

#include "Waveform.hpp"
#include <vector>

namespace WaveformUtilities {
  
  /// These functions return the axis of the Schmidt frame (the third
  /// Euler angle to find that frame is zero).  More explicitly, the
  /// physical system should be rotated by (0, beta, gamma) in order
  /// to align the radiation axis with the z axis.  Note that there is
  /// an ambiguity in the direction of the radiation axis; it could be
  /// either along (beta, gamma) or opposite it.  Also note that the
  /// coordinates could be rotated by (-gamma, -beta, 0) to align the
  /// z axis with the radiation axis.
  void RadiationAxis(const WaveformObjects::Waveform& W, const unsigned int tStep, double& beta, double& gamma);
  void RadiationAxis(const WaveformObjects::Waveform& W, std::vector<double>& beta, std::vector<double>& gamma);
  
  /// This function finds the Owen frame, given the Schmidt frame
  void YawFreeFrame(std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma);
  
  /// This function finds the Owen frame directly from the Waveform,
  /// all in one go
  void YawFreeFrame(const WaveformObjects::Waveform& W, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma);
  
}

#endif // RADIATIONAXIS_HPP
