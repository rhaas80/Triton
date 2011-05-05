#ifndef WAVEFORMATAPOINT_HPP
#define WAVEFORMATAPOINT_HPP

#include "Waveform.hpp"

namespace WaveformObjects {
  
  /// This class defines a derived class of a Waveform evaluated at a point.  A separate class is needed because
  /// a Waveform evaluated at a point need not have a well defined (smooth, simple) amplitude and phase, and thus
  /// must be stored as (Re,Im) data rather than (Amp,Phi) data.  The second constructor is provided because 
  /// the memory requirements are prohibitive when interpolating an entire Waveform to a uniform time grid of
  /// sufficient resolution to obtain a good FT of the data.  This constructor, then, constructs a uniform
  /// time grid sized to the next power of two, using the input timestep and the time grid of the input Waveform,
  /// and progressively interpolates each mode and evaluates it at the desired point.
  
  class WaveformAtAPoint : public Waveform {
    
  private:  // Member data
    double vartheta;
    double varphi;
    
  public:  // Constructors and Destructor
    WaveformAtAPoint() { }
    WaveformAtAPoint(const Waveform& W, const double dt, const double Vartheta, const double Varphi);
    ~WaveformAtAPoint() { }
    
  public: // Member functions
    inline double& VarthetaRef() { return vartheta; }
    inline double& VarphiRef() { return varphi; }
    inline double& ReRef(const unsigned int i) { return MagRef(0,i); }
    inline double& ImRef(const unsigned int i) { return ArgRef(0,i); }
    inline std::vector<double>& ReRef() { return MagRef(0); }
    inline std::vector<double>& ImRef() { return ArgRef(0); }
    
  public:  // Member functions
    inline const double Vartheta() const { return vartheta; }
    inline const double Varphi() const { return varphi; }
    inline const double Re(const unsigned int i) const { return Mag(0,i); }
    inline const double Im(const unsigned int i) const { return Arg(0,i); }
    inline const std::vector<double>& Re() const { return Mag(0); }
    inline const std::vector<double>& Im() const { return Arg(0); }
    
  };
  
} // namespace WaveformObjects

// Related function 
std::ostream& operator<<(std::ostream& os, const WaveformObjects::WaveformAtAPoint& a);
  
#endif // WAVEFORMATAPOINT_HPP
