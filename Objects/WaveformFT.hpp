#ifndef WAVEFORMFT_HPP
#define WAVEFORMFT_HPP

#include "WaveformAtAPoint.hpp"

namespace WaveformObjects {
  
  /// The WaveformFT class is a derived class, constructed from waveforms evaluated at a
  /// point, using the given complex detector response (F+ + i*Fx) -- or more particularly,
  /// its amplitude and phase.
  class WaveformFT : public WaveformAtAPoint {
  private:  // Member data
    bool Normalized;
    
  public:  // Constructors and Destructor
    WaveformFT();
    WaveformFT(const WaveformAtAPoint& W, const unsigned int WindowNCycles=1,
	       const double DetectorResponseAmp=1.0, const double DetectorResponsePhase=0.0);
    ~WaveformFT() { }
    
  public: // Access functions
    inline const double F(const unsigned int i) const { return T(i); }
    inline const std::vector<double>& F() const { return T(); }
    
  public:  // Member functions
    double InnerProduct(const WaveformFT& B, const std::vector<double>& InversePSD) const;
    double SNR(const std::vector<double>& InversePSD) const;
    double Match(const WaveformFT& B, const std::vector<double>& InversePSD) const;
    double Match(const WaveformFT& B, const std::string& Detector="AdvLIGO_ZeroDet_HighP") const;
    WaveformFT& Normalize(const std::vector<double>& InversePSD);
    WaveformFT& ZeroAbove(const double Frequency);
    WaveformFT operator-(const WaveformFT& b) const;
    WaveformFT operator*(const double b) const;
  }; // class
  
} // namespace WaveformObjects

std::ostream& operator<<(std::ostream& os, const WaveformObjects::WaveformFT& a);

#endif // WAVEFORMFT_HPP
