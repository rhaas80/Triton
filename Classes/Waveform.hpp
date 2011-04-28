#ifndef WAVEFORM_HPP
#define WAVEFORM_HPP

#include <string>
#include <sstream>
#include "Matrix.hpp"

namespace WaveformObjects {
  
  class Waveform {
    friend class WaveformAtAPoint;
    friend class WaveformFT;
    
  public:  // Constructors and Destructor
    Waveform();
    Waveform(const Waveform& W);
    Waveform(const std::string& DataFileName, const std::string& Format);
    Waveform(const std::string& Approximant, const double delta, const double chis, const double chia, const double v0,
	     const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0,
	     const int nsave=-1, const bool denseish=true);
    ~Waveform() { }
    void clear() { t.clear(); r.clear(); lm.clear(); mag.clear(); arg.clear(); }
    
  private:  // Member data
    std::stringstream history;
    unsigned int typeIndex;
    std::string timeScale;
    std::vector<double> t;
    std::vector<double> r;
    WaveformUtilities::Matrix<int> lm;
    WaveformUtilities::Matrix<double> mag;
    WaveformUtilities::Matrix<double> arg;
    
  public:  // Member datum
    static std::vector<std::string> Types;
    
  public:  // Operators
    Waveform& operator=(const Waveform& b);
    Waveform operator/(const Waveform& b) const;
    
  private:  // Access functions
    // Basic Waveform information
    inline unsigned int& TypeIndex() { return typeIndex; }
    void SetHistory(const std::string& Hist) { history.str(Hist); }
    inline std::string& TimeScale() { return timeScale; }
    // Data from a single mode at an instant of time
    inline double& T(const unsigned int Time) { return t[Time]; }
    inline double& R(const unsigned int Time) { return r[Time]; }
    inline double& Mag(const unsigned int Mode, const unsigned int Time) { return mag[Mode][Time]; }
    inline double& Arg(const unsigned int Mode, const unsigned int Time) { return arg[Mode][Time]; }
    // Data from a single mode throughout time
    inline std::vector<double>& T() { return t; }
    inline std::vector<double>& R() { return r; }
    inline int& L(const unsigned int Mode) { return lm[Mode][0]; }
    inline int& M(const unsigned int Mode) { return lm[Mode][1]; }
    inline std::vector<int>& LM(const unsigned int Mode) { return lm[Mode]; }
    inline std::vector<double>& Mag(const unsigned int Mode) { return mag[Mode]; }
    inline std::vector<double>& Arg(const unsigned int Mode) { return arg[Mode]; }
    // Data for all modes throughout time
    inline WaveformUtilities::Matrix<int>& LM() { return lm; }
    inline WaveformUtilities::Matrix<double>& Mag() { return mag; }
    inline WaveformUtilities::Matrix<double>& Arg() { return arg; }
    
  public:  // Access functions
    // Basic Waveform information
    inline unsigned int NTimes() const { return t.size(); }
    inline unsigned int NModes() const { return lm.nrows(); }
    inline unsigned int TypeIndex() const { return typeIndex; }
    inline std::string History() const { return history.str(); }
    inline std::string TimeScale() const { return timeScale; }
    // Data from a single mode at an instant of time
    inline const double T(const unsigned int Time) const { return t[Time]; }
    inline const double R(const unsigned int Time) const { return r[Time]; }
    inline const double Mag(const unsigned int Mode, const unsigned int Time) const { return mag[Mode][Time]; }
    inline const double Arg(const unsigned int Mode, const unsigned int Time) const { return arg[Mode][Time]; }
    // Data from a single mode throughout time
    inline const std::vector<double>& T() const { return t; }
    inline const std::vector<double>& R() const { return r; }
    inline const int L(const unsigned int Mode) const { return lm[Mode][0]; }
    inline const int M(const unsigned int Mode) const { return lm[Mode][1]; }
    inline const std::vector<int>& LM(const unsigned int Mode) const { return lm[Mode]; }
    inline const std::vector<double>& Mag(const unsigned int Mode) const { return mag[Mode]; }
    inline const std::vector<double>& Arg(const unsigned int Mode) const { return arg[Mode]; }
    // Data for all modes throughout time
    inline const WaveformUtilities::Matrix<int>& LM() const { return lm; }
    inline const WaveformUtilities::Matrix<double>& Mag() const { return mag; }
    inline const WaveformUtilities::Matrix<double>& Arg() const { return arg; }
    
  public:  // Member functions
    // Handy description routines
    double Peak22Time() const;
    std::vector<double> Omega2m2(const double t1=-1e300, const double t2=1e300) const;
    bool HasNaNs() const;
    std::vector<double> Flux() const;
    
    // Interpolation routines
    Waveform& Interpolate(const std::vector<double>& Time);
    Waveform& Interpolate(const double Time);
    Waveform& Interpolate(const Waveform& b);
    
    // Trim or adjust time axis
    Waveform& AddToTime(const double t);
    Waveform& DropBefore(const double t);
    Waveform& DropAfter(const double t);
    Waveform& ZeroBefore(const double t);
    Waveform& UniformTimeToPowerOfTwo();
    
    // Used in extrapolation
    Waveform& SetArealRadius(const std::string& AreaFileName);
    Waveform& SetTimeFromLapseSurfaceIntegral(const std::string& LapseFileName, const double ADMMass);
    Waveform& TortoiseOffset(const double ADMMass);
    
    // Used before converting to frequency space
    Waveform& SetPhysicalMassAndDistance(const double TotalMassInSolarMasses, const double DistanceInMegaparsecs);
    
    // Useful for time saving or comparing very different waveforms
    Waveform& DropLMode(const int L);
    Waveform& DropLMMode(const int L, const int M);
    Waveform& DropOddMModes();
    Waveform& DropZeroMModes();
    Waveform& DropNegativeMModes();
    
    // Convert (mag,arg) to (re,im) for, e.g., m=0 modes
    Waveform& FixNonOscillatingData();
    Waveform& UnfixNonOscillatingData();
    
    // Align and hybridize waveforms
    Waveform& AlignTo(const Waveform& a, const double t1, const double t2);
    Waveform HybridizeWith(const Waveform& b, const double t1, const double t2, const double MinStep=0.005) const;
    Waveform& AlignTo_F(const Waveform& a, const double omega, const double omegat1=-1e300, const double omegat2=1e300,
			const double DeltaT=1e300, const double MinStep=0.005);
    Waveform HybridizeWith_F(const Waveform& a, const double omega, const double omegat1=-1e300, const double omegat2=1e300,
			     const double DeltaT=10.0, const double MinStep=0.005) const;
    
    // Nice, easy way of compressing and outputting to NINJA
    Waveform& MinimalGrid(const double MagTol=1.e-5, const double ArgTol=1.e-5);
    void OutputToNINJAFormat(const std::string& MetadataFileName) const;
    
    // Mostly useful for getting the flux
    Waveform& Differentiate();
    
  }; // class Waveform
  
} // namespace WaveformObjects

// Related function
std::ostream& operator<<(std::ostream& os, const WaveformObjects::Waveform& a);

#endif // WAVEFORM_HPP
