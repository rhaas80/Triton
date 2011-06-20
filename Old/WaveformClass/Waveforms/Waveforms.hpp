#ifndef WAVEFORMS_HPP
#define WAVEFORMS_HPP

#include "Waveform.hpp"

class Waveforms {
public:  // Constructors and Destructor
  Waveforms(const Waveforms& In);
  Waveforms(const int N=0);
  Waveforms(const std::vector<double>& Radii, const std::string& DataFile,
	    const std::string& AreaFile, const std::string& LapseFile,
	    const double& ADMMass, const double& ChMass);
  ~Waveforms() { }
  
public:  // Operators
  inline const Waveform& operator[](const int i) const { return Ws[i]; }
  inline Waveform& operator[](const int i) { return Ws[i]; }
  
public:  // Member functions
  void SetCommonTime(const double& MinStep=0.005, const double& MinTime=0.0);
  void FixNonOscillatingData();
  void AlignPhases(const double& AlignmentPoint=0.5);
  Waveform Extrapolate(const int ExtrapolationOrder=3);
  void clear() { Ws.clear(); CommonTimeSet=false; PhasesAligned=false; }
  
private:  // Member data
  std::vector<Waveform> Ws;
  bool CommonTimeSet;
  bool PhasesAligned;
};

#endif // WAVEFORMS_HPP
