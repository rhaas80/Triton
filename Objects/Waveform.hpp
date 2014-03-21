#ifndef WAVEFORM_HPP
#define WAVEFORM_HPP

#include <string>
#include <sstream>
#include "Quaternions.hpp"
#include "Matrix.hpp"

namespace WaveformObjects {

  class Waveform {

  public:  // Constructors and Destructor
    Waveform();
    Waveform(const Waveform& W);
    Waveform(const std::string& DataFileName, const std::string& Format, const bool ZeroEnds=false);
    Waveform(const std::string& BBHFileName,
             int SectionToUse=0,
             const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0));
    Waveform(const std::vector<std::string>& BBHDataSection,
             const std::string Dir = "",
             const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0));
    Waveform(const std::string& Approximant, const double delta, const double chis, const double chia, const double v0,
             const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
             const int nsave=-1, const bool denseish=true, const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0);
    Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
             const double v0,
             const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
             const int nsave=-1, const bool denseish=true, const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0);
    Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
             const double v0, std::vector<std::vector<double> >& S1, std::vector<std::vector<double> >& S2, std::vector<std::vector<double> >& LNHat,
             const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
             const int nsave=-1, const bool denseish=true, const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0);
    // Waveform(const std::string& Approximant, const double delta, const std::vector<double>& chi1, const std::vector<double>& chi2,
    //       const double v0, std::vector<double>& alpha, std::vector<double>& beta, std::vector<double>& gamma,
    //       const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
    //       const int nsave=-1, const bool denseish=true, const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0);

    //Constructor for the Taylor T4 Tidal Waveform
    Waveform(const std::string& Approximant, const double delta, const double chis,
	     const double chia, const double v0, const double love1, const double love2,
	     const double compact1, const double compact2,
	     const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
	     const int nsave=-1, const bool denseish=true,
	     const double PNPhaseOrder=3.5, const double PNAmplitudeOrder=3.0);

    ~Waveform() { }
    void swap(Waveform& b);
    void clear() { t.clear(); r.clear(); lm.clear(); mag.clear(); arg.clear(); }

  private:  // Member data
    std::stringstream history;
    unsigned int typeIndex;
    std::string timeScale;
    std::vector<double> t;
    std::vector<double> r;
    std::vector<WaveformUtilities::Quaternion> frame;
    WaveformUtilities::Matrix<int> lm;
    WaveformUtilities::Matrix<double> mag;
    WaveformUtilities::Matrix<double> arg;
  public:
    static std::vector<std::string> Types;

  public:  // Get-data access functions
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
    inline const WaveformUtilities::Quaternion& Frame(const unsigned int Time) const { if(frame.size()>1) {return frame[Time]; } else { return frame[0]; } }
    inline const double Mag(const unsigned int Mode, const unsigned int Time) const { return mag[Mode][Time]; }
    inline const double Arg(const unsigned int Mode, const unsigned int Time) const { return arg[Mode][Time]; }
    // Data from a single mode throughout time
    inline const std::vector<double>& T() const { return t; }
    inline const std::vector<double>& R() const { return r; }
    inline const std::vector<WaveformUtilities::Quaternion>& Frame() const { return frame; }
    inline const int L(const unsigned int Mode) const { return lm[Mode][0]; }
    inline const int M(const unsigned int Mode) const { return lm[Mode][1]; }
    inline const std::vector<int>& LM(const unsigned int Mode) const { return lm[Mode]; }
    inline const std::vector<double>& Mag(const unsigned int Mode) const { return mag[Mode]; }
    inline const std::vector<double>& Arg(const unsigned int Mode) const { return arg[Mode]; }
    // Data for all modes throughout time
    #if defined(SWIG) || defined(DOXYGEN)
    inline const std::vector<std::vector<int> >& LM() const { return lm.RawData(); }
    inline const std::vector<std::vector<double> >& Mag() const { return mag.RawData(); }
    inline const std::vector<std::vector<double> >& Arg() const { return arg.RawData(); }
    #else
    inline const WaveformUtilities::Matrix<int>& LM() const { return lm; }
    inline const WaveformUtilities::Matrix<double>& Mag() const { return mag; }
    inline const WaveformUtilities::Matrix<double>& Arg() const { return arg; }
    #endif

  public:  // Set-data implicit access functions
    #ifndef SWIG // Exclude the following from SWIG
    // Basic Waveform information
    inline unsigned int& TypeIndexRef() { return typeIndex; }
    inline std::stringstream& History() { return history; }
    inline std::string& TimeScaleRef() { return timeScale; }
    // Data from a single mode at an instant of time
    inline double& TRef(const unsigned int Time) { return t[Time]; }
    inline double& RRef(const unsigned int Time) { if(r.size()>1) {return r[Time]; } else { return r[0]; } }
    inline WaveformUtilities::Quaternion& FrameRef(const unsigned int Time) { if(frame.size()>1) {return frame[Time]; } else { return frame[0]; } }
    inline double& MagRef(const unsigned int Mode, const unsigned int Time) { return mag[Mode][Time]; }
    inline double& ArgRef(const unsigned int Mode, const unsigned int Time) { return arg[Mode][Time]; }
    // Data from a single mode throughout time
    inline std::vector<double>& TRef() { return t; }
    inline std::vector<double>& RRef() { return r; }
    inline std::vector<WaveformUtilities::Quaternion>& FrameRef() { return frame; }
    inline int& LRef(const unsigned int Mode) { return lm[Mode][0]; }
    inline int& MRef(const unsigned int Mode) { return lm[Mode][1]; }
    inline std::vector<int>& LMRef(const unsigned int Mode) { return lm[Mode]; }
    inline std::vector<double>& MagRef(const unsigned int Mode) { return mag[Mode]; }
    inline std::vector<double>& ArgRef(const unsigned int Mode) { return arg[Mode]; }
    // Data for all modes throughout time
    inline WaveformUtilities::Matrix<int>& LMRef() { return lm; }
    inline WaveformUtilities::Matrix<double>& MagRef() { return mag; }
    inline WaveformUtilities::Matrix<double>& ArgRef() { return arg; }
    #endif // Excluded the above from SWIG

  public:  // Set-data explicit access functions (mostly for SWIG)
    inline void AppendHistory(const std::string& Hist) { history << Hist; }
    inline void SetHistory(const std::string& Hist) { history.str(Hist); history.seekp(0, std::ios_base::end); }
    #if defined( SWIG ) || defined( DOXYGEN )
    inline void SetTypeIndex(const unsigned int NewTypeIndex) { typeIndex = NewTypeIndex; }
    inline void SetTimeScale(const std::string& NewTimeScale) { timeScale = NewTimeScale; }
    inline void SetT(const unsigned int Time, const double a) { t[Time] = a; }
    inline void SetT(const std::vector<double>& a) { t = a; }
    inline void SetR(const unsigned int Time, const double a) { r[Time] = a; }
    inline void SetR(const std::vector<double>& a) { r = a; }
    inline void SetFrame(const unsigned int Time, const WaveformUtilities::Quaternion& a) { frame[Time] = a; }
    inline void SetFrame(const std::vector<WaveformUtilities::Quaternion>& a) { frame = a; }
    inline void SetLM(const unsigned int Mode, const std::vector<int>& a) { lm[Mode] = a; }
    inline void SetLM(const WaveformUtilities::Matrix<int>& a) { lm = a; }
    inline void SetMag(const unsigned int Mode, const unsigned int Time, const double a) { mag[Mode][Time] = a; }
    inline void SetMag(const unsigned int Mode, const std::vector<double>& a) { mag[Mode] = a; }
    inline void SetMag(const WaveformUtilities::Matrix<double>& a) { mag = a; }
    inline void SetArg(const unsigned int Mode, const unsigned int Time, const double a) { arg[Mode][Time] = a; }
    inline void SetArg(const unsigned int Mode, const std::vector<double>& a) { arg[Mode] = a; }
    inline void SetArg(const WaveformUtilities::Matrix<double>& a) { arg = a; }
    #endif // Only used above for SWIG or doxygen

  public:  // Operators
    Waveform& operator=(const Waveform& b);
    Waveform operator[](const unsigned int mode) const;
    Waveform operator/(const Waveform& b) const;

  public:  // Member functions
    // Extract features
    unsigned int FindModeIndex(const int L, const int M) const;
    unsigned int Peak22TimeIndex() const;
    double Peak22Time() const;
    unsigned int PeakFluxTimeIndex() const;
    double PeakFluxTime() const;
    unsigned int PeakL2TimeIndex() const;
    double PeakL2Time() const;
    std::vector<double> Omega2m2(const double t1=-1e300, const double t2=1e300) const;
    bool HasNaNs() const;
    std::vector<double> Flux() const;
    std::vector<double> L2Norm() const;
    std::vector<double> L2NormDifference(const Waveform& b) const;
    Waveform& Differentiate();

    // Interpolation routines
    Waveform& Interpolate(const std::vector<double>& Time);
    Waveform& Interpolate(const std::vector<double>& Time, const double ExtrapVal);
    Waveform& Interpolate(const double Time);
    Waveform& Interpolate(const Waveform& b);
    Waveform& Interpolate(const Waveform& b, const double ExtrapVal);

    // Adjust time axis
    Waveform& AddToTime(const double t);
    Waveform& DropBefore(const double t);
    Waveform& DropAfter(const double t);
    Waveform& ZeroBefore(const double t);
    Waveform& UniformTimeToPowerOfTwo();
    Waveform& UniformTime(const unsigned int N=200);
    Waveform& NSamplesPerCycle22(const unsigned int N=20);
    Waveform& MakeTimeMonotonic(const double MinTimeStep=1.e-5);

    // Physical conversions for extrapolations or conversion to frequency space
    Waveform& SetArealRadius(const std::vector<double>& ArealRadius);
    Waveform& SetArealRadius(const std::string& AreaFileName);
    Waveform& RescaleMagForRadius(const double OldRadius);
    Waveform& SetTimeFromAverageLapse(const std::vector<double>& AverageLapse, const double ADMMass);
    Waveform& SetTimeFromLapseSurfaceIntegral(const std::string& LapseFileName, const double ADMMass);
    Waveform& TortoiseRetard(const double ADMMass);
    Waveform& TortoiseAdvance(const double ADMMass);
    Waveform& SetTotalMassToOne(const double TotalMassInCurrentUnits);
    Waveform& SetPhysicalMassAndDistance(const double TotalMassInSolarMasses, const double DistanceInMegaparsecs);

    // Manipulate (l,m) modes
    Waveform& DropLMode(const int L);
    Waveform& DropLMMode(const int L, const int M);
    Waveform& DropOddMModes();
    Waveform& DropZeroMModes();
    Waveform& DropNegativeMModes();
    Waveform& Conjugate();
    Waveform& HackOddLPlusM(); // Change sign of mode if l+m is odd (Hack to fix RWZ extraction)
    Waveform& FixNonOscillatingData(); // If M=0, convert to ReIm from MagArg
    Waveform& UnfixNonOscillatingData(); // If M=0, convert from ReIm to MagArg
    Waveform& ConvertReImToMagArg();
    Waveform& ConvertMagArgToReIm();

    // Align and hybridize waveforms
    Waveform& AlignPhasesToTwoPi(const Waveform& a, const double tFrac=0.25);
    Waveform& AlignTo(const Waveform& a, const double t1, const double t2);
    Waveform& AlignWithIntermediate(const Waveform& a, Waveform Intermediate, const double t1, const double t2);
    Waveform HybridizeWith(const Waveform& b, const double t1, const double t2, const double MinStep=0.005) const;
    Waveform& AlignTo_F(const Waveform& a, const double omega, const double omegat1=-1e300, const double omegat2=1e300,
                        const double DeltaT=1e300, const double MinStep=0.005);
    Waveform HybridizeWith_F(const Waveform& a, const double omega, const double omegat1=-1e300, const double omegat2=1e300,
                             const double DeltaT=10.0, const double MinStep=0.005) const;
    Waveform& AttachQNMs(const double delta, const double chiKerr, double dt=0.0, const double TLength=500.0);

    // Rotate by the given Euler angles or Quaternion
    Waveform& RotatePhysicalSystem(const double alpha, const double beta, const double gamma);
    Waveform& RotatePhysicalSystem(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma);
    Waveform& RotateCoordinates(const double alpha, const double beta, const double gamma);
    Waveform& RotateCoordinates(const std::vector<double>& alpha, const std::vector<double>& beta, const std::vector<double>& gamma);
    Waveform& RotatePhysicalSystem(const WaveformUtilities::Quaternion& Q);
    Waveform& RotatePhysicalSystem(const std::vector<WaveformUtilities::Quaternion>& Q);
    Waveform& RotateCoordinates(const WaveformUtilities::Quaternion& Q);
    Waveform& RotateCoordinates(const std::vector<WaveformUtilities::Quaternion>& Q);
    //Waveform& ReconcileAxisDirection(const Waveform& W, const double TimeFraction=0.5);

    // Radiation-frame utilities
    Waveform& TransformToSchmidtFrame(const double alpha0Guess=0.0, const double beta0Guess=0.0);
    Waveform& TransformToMinimalRotationFrame(const double alpha0Guess=0.0, const double beta0Guess=0.0, const unsigned int NIterations=5);
    Waveform& TransformToStandardFrame();
    Waveform& TransformToStationaryFrame(const WaveformUtilities::Quaternion Q=WaveformUtilities::Quaternion(1,0,0,0));

    // Nice, easy way of compressing and outputting to NINJA
    Waveform& MinimalGrid(const double MagTol=1.e-5, const double ArgTol=1.e-5);
    void OutputToNINJAFormat(const std::string& MetadataFileName, const std::string ExtractionRadiusString="", const std::string WaveformIdentifier="") const;

  }; // class Waveform

} // namespace WaveformObjects

// Output functions (non-members)
std::ostream& operator<<(std::ostream& os, const WaveformObjects::Waveform& a);
void Output(const std::string& FileName, const WaveformObjects::Waveform& a, const unsigned int precision=14);
void OutputSingleMode(std::ostream& os, const WaveformObjects::Waveform& a, const unsigned int Mode);
void OutputSingleMode(const std::string& FileName, const WaveformObjects::Waveform& a, const unsigned int Mode, const unsigned int precision=14);

#endif // WAVEFORM_HPP
