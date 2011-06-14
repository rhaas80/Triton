#ifndef WAVEFORM_HPP
#define WAVEFORM_HPP

#include <string>
#include <sstream>
#include "Matrix.hpp"

namespace WaveformObjects {
  
  class Waveform {
    
  public:  // Constructors and Destructor
    Waveform();
    Waveform(const Waveform& W);
    Waveform(const std::string& DataFileName, const std::string& Format, const bool ZeroEnds=false);
    Waveform(const std::string& Approximant, const double delta, const double chis, const double chia, const double v0,
	     const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
	     const int nsave=-1, const bool denseish=true, const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0);
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
  public:
    static std::vector<std::string> Types;
    
  public:  // Operators
    Waveform& operator=(const Waveform& b);
    Waveform operator/(const Waveform& b) const;
    Waveform operator[](const unsigned int mode) const;
    void swap(Waveform& b);
    
  public:  // Getty access functions
    // Basic Waveform information
    inline const unsigned int NTimes() const { return t.size(); }
    inline const unsigned int NModes() const { return lm.nrows(); }
    inline const unsigned int TypeIndex() const { return typeIndex; }
    inline const std::string HistoryStr() const { return history.str(); }
    inline const std::string TimeScale() const { return timeScale; }
    inline const std::string Type() const { return Types[typeIndex]; }
    // Data from a single mode at an instant of time
    inline const double T(const unsigned int Time) const { return t[Time]; }
    inline const double R(const unsigned int Time) const { if(r.size()>1) {return r[Time]; } else { return r[0]; } }
    inline const double Mag(const unsigned int Mode, const unsigned int Time) const { return mag[Mode][Time]; }
    inline const double Arg(const unsigned int Mode, const unsigned int Time) const { return arg[Mode][Time]; }
    // Data from a single mode throughout time
    inline const std::vector<double>& T() const { return t; }
    inline const std::vector<double>& R() const { return r; }
    inline const int& L(const unsigned int Mode) const { return lm[Mode][0]; }
    inline const int& M(const unsigned int Mode) const { return lm[Mode][1]; }
    inline const std::vector<int>& LM(const unsigned int Mode) const { return lm[Mode]; }
    inline const std::vector<double>& Mag(const unsigned int Mode) const { return mag[Mode]; }
    inline const std::vector<double>& Arg(const unsigned int Mode) const { return arg[Mode]; }
    // Data for all modes throughout time
    inline const WaveformUtilities::Matrix<int>& LM() const { return lm; }
    inline const WaveformUtilities::Matrix<double>& Mag() const { return mag; }
    inline const WaveformUtilities::Matrix<double>& Arg() const { return arg; }
    
  public:  // Setty access functions
    // Basic Waveform information
    inline unsigned int& TypeIndexRef() { return typeIndex; }
    void SetHistory(const std::string& Hist) { history.str(Hist); history.seekp(0, std::ios_base::end); }
    inline std::stringstream& History() { return history; }
    inline std::string& TimeScaleRef() { return timeScale; }
    // Data from a single mode at an instant of time
    inline double& TRef(const unsigned int Time) { return t[Time]; }
    inline double& RRef(const unsigned int Time) { if(r.size()>1) {return r[Time]; } else { return r[0]; } }
    inline double& MagRef(const unsigned int Mode, const unsigned int Time) { return mag[Mode][Time]; }
    inline double& ArgRef(const unsigned int Mode, const unsigned int Time) { return arg[Mode][Time]; }
    // Data from a single mode throughout time
    inline std::vector<double>& TRef() { return t; }
    inline std::vector<double>& RRef() { return r; }
    inline int& LRef(const unsigned int Mode) { return lm[Mode][0]; }
    inline int& MRef(const unsigned int Mode) { return lm[Mode][1]; }
    inline std::vector<int>& LMRef(const unsigned int Mode) { return lm[Mode]; }
    inline std::vector<double>& MagRef(const unsigned int Mode) { return mag[Mode]; }
    inline std::vector<double>& ArgRef(const unsigned int Mode) { return arg[Mode]; }
    // Data for all modes throughout time
    inline WaveformUtilities::Matrix<int>& LMRef() { return lm; }
    inline WaveformUtilities::Matrix<double>& MagRef() { return mag; }
    inline WaveformUtilities::Matrix<double>& ArgRef() { return arg; }
    
  public:  // Member functions
    // Handy description routines
    double Peak22Time() const;
    std::vector<double> Omega2m2(const double t1=-1e300, const double t2=1e300) const;
    bool HasNaNs() const;
    std::vector<double> Flux() const;
    void SetTypeIndex(const unsigned int I) { typeIndex = I; }
    
    // Interpolation routines
    Waveform& Interpolate(const std::vector<double>& Time);
    Waveform& Interpolate(const std::vector<double>& Time, const double ExtrapVal);
    Waveform& Interpolate(const double Time);
    Waveform& Interpolate(const Waveform& b);
    Waveform& Interpolate(const Waveform& b, const double ExtrapVal);
    
    // Trim or adjust time axis
    Waveform& AddToTime(const double t);
    Waveform& DropBefore(const double t);
    Waveform& DropAfter(const double t);
    Waveform& ZeroBefore(const double t);
    Waveform& UniformTimeToPowerOfTwo();
    Waveform& UniformTime(const unsigned int N=200);
    
    // Used in extrapolation
    Waveform& SetArealRadius(const std::string& AreaFileName);
    Waveform& SetTimeFromLapseSurfaceIntegral(const std::string& LapseFileName, const double ADMMass);
    Waveform& TortoiseOffset(const double ADMMass);
    Waveform& SetTotalMassToOne(const double TotalMassInCurrentUnits);
    
    // Used before converting to frequency space
    Waveform& SetPhysicalMassAndDistance(const double TotalMassInSolarMasses, const double DistanceInMegaparsecs);
    
    // Useful for time saving or comparing very different waveforms
    Waveform& DropLMode(const int L);
    Waveform& DropLMMode(const int L, const int M);
    Waveform& DropOddMModes();
    Waveform& DropZeroMModes();
    Waveform& DropNegativeMModes();
    Waveform& Conjugate();
    
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
    Waveform& AttachQNMs(const double delta, const double chiKerr, double dt=0.0, const double TLength=500.0);
    
    // Nice, easy way of compressing and outputting to NINJA
    Waveform& MinimalGrid(const double MagTol=1.e-5, const double ArgTol=1.e-5);
    void OutputToNINJAFormat(const std::string& MetadataFileName) const;
    
    // Mostly useful for getting the flux
    Waveform& Differentiate();
    
  }; // class Waveform
  
} // namespace WaveformObjects

// Related functions
std::ostream& operator<<(std::ostream& os, const WaveformObjects::Waveform& a);
void Output(const std::string& FileName, const WaveformObjects::Waveform& a, const unsigned int precision=14);
void OutputSingleMode(std::ostream& os, const WaveformObjects::Waveform& a, const unsigned int Mode);
void OutputSingleMode(const std::string& FileName, const WaveformObjects::Waveform& a, const unsigned int Mode, const unsigned int precision=14);

#endif // WAVEFORM_HPP
