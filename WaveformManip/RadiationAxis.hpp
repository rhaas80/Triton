#ifndef RADIATIONAXIS_HPP
#define RADIATIONAXIS_HPP

/// These functions find the radiation axis of a waveform, at an
/// instant, or as a function of time.

#include "Waveform.hpp"
#include "Quaternions.hpp"
#include <vector>

namespace WaveformUtilities {
  
  /// These functions return the axis of the Schmidt frame (the third
  /// Euler angle to find that frame is zero).  More explicitly, the
  /// *coordinates* should be rotated by (alpha, beta, 0) in order to
  /// maximize the quantity |h_{2,2}|^2 + |h_{2,-2}|^2 in the new
  /// frame.  Alternatively, it is possible to rotate the *physical
  /// system* by (0, -beta, -alpha).
  /// 
  /// Note that there is an ambiguity in the direction of the
  /// radiation axis; it could be either along (beta, gamma) or
  /// opposite to it.  Also, whenever beta is close to 0 or pi, gamma
  /// will be inaccurate because that is the singularity of Euler
  /// rotations.
  void RadiationAxis(const WaveformObjects::Waveform& W, const unsigned int tStep, double& alpha, double& beta);
  void RadiationAxis(const WaveformObjects::Waveform& W, std::vector<double>& alpha, std::vector<double>& beta,
		     const double alphaGuess=0.0, const double betaGuess=0.0);
  void RadiationAxis(const WaveformObjects::Waveform& W, std::vector<WaveformUtilities::Quaternion>& Q);
  
  /// This function finds the Owen frame, given the Schmidt frame
  void MinimalRotation(const std::vector<double>& alpha, const std::vector<double>& beta, std::vector<double>& gamma, const std::vector<double>& t);
  
  /// This function finds the Owen frame directly from the Waveform,
  /// all in one go.  To produce the simplified waveform, do
  ///   W.RotateCoordinates(alpha, beta, gamma);
  /// with the result after calling this function.
  void MinimalRotation(const WaveformObjects::Waveform& W, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma,
		       const double alphaGuess=0.0, const double betaGuess=0.0);
  void MinimalRotation(const WaveformObjects::Waveform& W, std::vector<WaveformUtilities::Quaternion>& Q);
  
}

#endif // RADIATIONAXIS_HPP
