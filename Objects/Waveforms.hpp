#ifndef WAVEFORMS_HPP
#define WAVEFORMS_HPP

#include "Waveform.hpp"

namespace WaveformObjects {
  
  class Waveforms {
    
  private:  // Member data
    std::stringstream history;
    std::vector<Waveform> Ws;
    bool CommonTimeSet;
    bool PhasesAligned;
    
  public:  // Constructors and Destructor
    Waveforms(const Waveforms& In);
    Waveforms(const int N=0);
    Waveforms(const std::vector<double>& Radii, const std::string& DataFile,
	      const std::string& AreaFile, const std::string& LapseFile,
	      const double& ADMMass, const double& ChMass, const bool ZeroEnds=false);
    Waveforms(const std::string& BBHFileName,
	      const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0),
	      const std::vector<double> Radii=std::vector<double>(0),
	      std::string Format="ht");
    Waveforms(const std::vector<std::string>& BBHDataSection,
	      const std::string Dir = "",
	      const WaveformUtilities::Matrix<int> LM=WaveformUtilities::Matrix<int>(0,0));
    ~Waveforms() { }
    
  public:  // Operators
    inline const Waveform& operator[](const int i) const { return Ws[i]; }
    inline Waveform& operator[](const int i) { return Ws[i]; }
    
  public:  // Member functions
    void SetCommonTime(const double& MinStep=0.005, const double& MinTime=0.0);
    void FixNonOscillatingData();
    void AlignPhases(const double& AlignmentPoint=0.5);
    void TortoiseAdvance(const double ADMMass=1, const bool ResetCommonTime=false);
    Waveform Extrapolate(const int ExtrapolationOrder=5, const bool UseSVD=true);
    Waveform Extrapolate(Waveform& Sigmas, const int ExtrapolationOrder=5, const bool UseSVD=true);
    Waveform ExtrapolateAndPreserveResiduals(Waveform& Sigmas, const int ExtrapolationOrder=5, const bool UseSVD=true);
    Waveform ExtrapolateAndPreserveResiduals(Waveform& Sigmas, const std::vector<double>& Times, const std::vector<double>& Omegas, const int ExtrapolationOrder=5, const bool UseSVD=true);
    Waveform Merge(const double& MinStep=0.0, const double& MinTime=0.0);
    void clear() { Ws.clear(); CommonTimeSet=false; PhasesAligned=false; }
    inline unsigned int size() { return Ws.size(); }
    
  }; // class
  
} // namespace

#endif // WAVEFORMS_HPP
