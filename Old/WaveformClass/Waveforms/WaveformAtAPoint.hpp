#ifndef WAVEFORMATAPOINT_HPP
#define WAVEFORMATAPOINT_HPP

#include "Waveform.hpp"

//// This class defines a derived class of a Waveform evaluated at a point.  A separate class is needed because
//// a Waveform evaluated at a point need not have a well defined (smooth, simple) amplitude and phase, and thus
//// must be stored as (Re,Im) data rather than (Amp,Phi) data.  The second constructor is provided because 
//// the memory requirements are prohibitive when interpolating an entire Waveform to a uniform time grid of
//// sufficient resolution to obtain a good FT of the data.  This constructor, then, constructs a uniform
//// time grid sized to the next power of two, using the input timestep and the time grid of the input Waveform,
//// and progressively interpolates each mode and evaluates it a the desired point.

class WaveformAtAPoint : public Waveform {
  friend class WaveformFT;
  friend std::ostream& operator<<(std::ostream& os, const WaveformAtAPoint& a);
  
private:  // Member data
  double vartheta;
  double varphi;
  
public:  // Constructors and Destructor
  WaveformAtAPoint() { }
  WaveformAtAPoint(const Waveform& W, const double Vartheta, const double Varphi);
  WaveformAtAPoint(const Waveform& W, const double dt, const double Vartheta, const double Varphi);
  ~WaveformAtAPoint() { }
  
public:  // Member functions
  WaveformAtAPoint& Window(const unsigned int NumStepsStart, const unsigned int NumStepsEnd=0);
  WaveformAtAPoint& PadToPowerOfTwo();
  inline const double& T(const unsigned int i) const { return Time[i]; }
  inline const double& Re(const unsigned int i) const { return amp[0][i]; }
  inline const double& Im(const unsigned int i) const { return phi[0][i]; }
  inline double& T(const unsigned int i) { return Time[i]; }
  inline double& Re(const unsigned int i) { return amp[0][i]; }
  inline double& Im(const unsigned int i) { return phi[0][i]; }
  inline const std::vector<double>& T() const { return Time; }
  inline const std::vector<double>& Re() const { return phi[0]; }
  inline const std::vector<double>& Im() const { return amp[0]; }
  inline std::vector<double>& T() { return Time; }
  inline std::vector<double>& Re() { return phi[0]; }
  inline std::vector<double>& Im() { return amp[0]; }
};

#endif // WAVEFORMATAPOINT_HPP
