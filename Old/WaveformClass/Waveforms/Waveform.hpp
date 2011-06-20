#ifndef WAVEFORM_HPP
#define WAVEFORM_HPP

#include <vector>
#include <string>

class Waveform {
  friend class Waveforms;
  friend class WaveformAtAPoint;
  friend class WaveformFT;
  friend class WaveformMatcher;
  friend Waveform CSSDiff(const Waveform& A, const Waveform& B);
  friend std::ostream& operator<<(std::ostream& os, const Waveform& a);
  #ifndef MAIN_FUNCTION_HAS_PARAMETERS
  friend int main(void);
  #else
  friend int main(int argc, char* argv[]);
  #endif
  
public:  // Constructors and Destructor
  Waveform();
  Waveform(const Waveform& W);
  Waveform(const std::string& DataFileName, const std::string& Format="ReIm");
  Waveform(const std::string& Approximant, const double delta, const double chis, const double chia, const double v0, const double PNOrder=3.5,
	   const std::vector<std::vector<int> >& LMs=std::vector<std::vector<int> >(0), const int nsave=-1, const bool denseish=true, const double PNAmpOrder=3.0);
  ~Waveform() { }
  void clear() { LM.clear(); Radius.clear(); Time.clear(); amp.clear(); phi.clear(); }
  
public:  // Member data
  int Type;
  std::string TimeScale;
  
private:  // Member data
  std::vector<std::vector<int> > LM;
  std::vector<double> Radius;
  std::vector<double> Time;
  std::vector<std::vector<double> > amp;
  std::vector<std::vector<double> > phi;
  
public:  // Operators
  Waveform operator/(const Waveform& b) const;
  Waveform& operator=(const Waveform& b);
  Waveform operator[](const unsigned int index) const;
  //Waveform operator()(const int& L, const int& M) const;
  
protected: // Member functions
  Waveform& ScaleAmp(const double S);
  
public:  // Access functions
  const double& T(const unsigned int t) const { return Time[t]; }
  const double& Amp(const unsigned int Mode, const unsigned int t) const { return amp[Mode][t]; }
  const double& Phi(const unsigned int Mode, const unsigned int t) const { return phi[Mode][t]; }
  double& T(const unsigned int t) { return Time[t]; }
  double& Amp(const unsigned int Mode, const unsigned int t) { return amp[Mode][t]; }
  double& Phi(const unsigned int Mode, const unsigned int t) { return phi[Mode][t]; }
  const std::vector<double>& T() const { return Time; }
  const std::vector<double>& Amp(const unsigned int Mode) const { return amp[Mode]; }
  const std::vector<double>& Phi(const unsigned int Mode) const { return phi[Mode]; }
  std::vector<double>& T() { return Time; }
  std::vector<double>& Amp(const unsigned int Mode) { return amp[Mode]; }
  std::vector<double>& Phi(const unsigned int Mode) { return phi[Mode]; }
  const std::vector<std::vector<double> >& Amp() const { return amp; }
  const std::vector<std::vector<double> >& Phi() const { return phi; }
  std::vector<std::vector<double> >& Amp() { return amp; }
  std::vector<std::vector<double> >& Phi() { return phi; }
  const std::vector<std::vector<int> >& LMModes() const { return LM; }
  
public:  // Member functions
  static std::vector<std::string> Types;
  unsigned int Length() const { return Time.size(); }
  double Peak22Time() const;
  std::vector<double> Omega22() const;
  std::vector<double> Omega2m2(const double t1=-1e300, const double t2=1e300) const;
  void Omega2m2Smooth(std::vector<double>& Omega, std::vector<double>& Time, const int NLeft=16, const int NRight=16, const int PolyOrder=4) const;
  std::vector<double> Omega2m2Smooth(const int NLeft, const int NRight, const int PolyOrder) const;
  Waveform ZeroBefore(const double t) const;
  Waveform UniformTime() const;
  Waveform UniformTimeToPowerOfTwo() const;
  Waveform Differentiate() const;
  Waveform& SetArealRadius(const std::string& AreaFileName);
  Waveform& SetTimeFromLapseSurfaceIntegral(const std::string& LapseFileName, const double ADMMass);
  Waveform& TortoiseOffset(const double ADMMass);
  Waveform& SetTotalMassToOne(const double TotalMassInCurrentUnits);
  Waveform& SetPhysicalMass(const double TotalMassInSolarMasses);
  Waveform& SetPhysicalDistance(const double DistanceInMegaparsecs);
  Waveform SetPhysicalMass(const double TotalMassInSolarMasses) const;
  Waveform SetPhysicalDistance(const double DistanceInMegaparsecs) const;
  Waveform& Interpolate(const std::vector<double>& Time);
  Waveform& Interpolate(const double& Time);
  Waveform& Interpolate(const Waveform& b);
  Waveform& OffsetTime(const double& t);
  Waveform& DropBefore(const double& t);
  Waveform& DropAfter(const double& t);
  Waveform& DropLMode(const int L);
  Waveform& DropLMMode(const int L, const int M);
  Waveform& DropOddMModes();
  Waveform& DropZeroMModes();
  Waveform& DropNegativeMModes();
  Waveform& Conjugate();
  Waveform& FixNonOscillatingData();
  Waveform& UnfixNonOscillatingData();
  Waveform Interpolate(const std::vector<double>& Time) const;
  Waveform Interpolate(const double& Time) const;
  Waveform Interpolate(const Waveform& b) const;
  Waveform DropBefore(const double& t) const;
  std::vector<double> Flux() const;
  Waveform L2Norm() const;
  Waveform L2NormalizedDifference(const Waveform& b) const;
  Waveform MatchTo(const Waveform& a, const double t1, const double t2) const;
  Waveform HybridizeWith(const Waveform& b, const double t1, const double t2, const double MinStep=0.005) const;
  Waveform MatchToFrequency(const Waveform& a, const double omega, const double omegat1=-1e300, const double omegat2=1e300, const double DeltaT=1e300, const double MinStep=0.005) const;
  Waveform HybridizeFrequencyWith(const Waveform& a, const double omega, const double omegat1=-1e300, const double omegat2=1e300, const double DeltaT=10.0, const double MinStep=0.005) const;
  Waveform MinimalGrid(const double AmpTol=1.e-5, const double PhiTol=1.e-5) const;
  void OutputToNINJAFormat(const std::string& MetadataFileName) const;
  bool HasNaNs() const;
};


// Friends
Waveform CSSDiff(const Waveform& A, const Waveform& B);
std::ostream& operator<<(std::ostream& os, const Waveform& a);


#endif // WAVEFORM_HPP
