#ifndef WAVEFORMFT_HPP
#define WAVEFORMFT_HPP

#include "WaveformAtAPoint.hpp"

// The WaveformFT class is a derived class, constructed from waveforms evaluated at a point,
// using the given complex detector response (F+ + i*Fx).

class WaveformFT : public Waveform {
  friend std::ostream& operator<<(std::ostream& os, const WaveformFT& a);
  
private:  // Member data
  double InitialTime;
  bool Normalized;
  
public:  // Constructors and Destructor
  WaveformFT();
  WaveformFT(const WaveformAtAPoint& W, const double DetectorResponseAmp=1.0, const double DetectorResponsePhase=0.0);
  ~WaveformFT() { }
  WaveformFT& operator=(const WaveformFT& In);
  
public:  // Member functions
  WaveformFT& Integrate(const unsigned int IntegrateNTimes);
  WaveformFT& Normalize(const std::vector<double>& InversePSD);
  double SNR(const std::vector<double>& InversePSD) const;
  double Match(const WaveformFT& B, const std::vector<double>& InversePSD) const;
  double Match(const WaveformFT& B, const std::string& Detector="AdvLIGO_ZeroDet_HighP") const;
  inline const double& Freq(const unsigned int i) const { return Time[i]; }
  inline const double& Amp(const unsigned int i) const { return amp[0][i]; }
  inline const double& Phi(const unsigned int i) const { return phi[0][i]; }
  inline double& Freq(const unsigned int i) { return Time[i]; }
  inline double& Amp(const unsigned int i) { return amp[0][i]; }
  inline double& Phi(const unsigned int i) { return phi[0][i]; }
  inline const std::vector<double>& Freq() const { return Time; }
  inline const std::vector<double>& Amp() const { return amp[0]; }
  inline const std::vector<double>& Phi() const { return phi[0]; }
  inline std::vector<double>& Freq() { return Time; }
  inline std::vector<double>& Amp() { return amp[0]; }
  inline std::vector<double>& Phi() { return phi[0]; }
};


#endif // WAVEFORMFT_HPP
