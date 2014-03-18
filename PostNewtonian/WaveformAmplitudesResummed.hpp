#ifndef WAVEFORMAMPLITUDESRESUMMED_HPP
#define WAVEFORMAMPLITUDESRESUMMED_HPP

#include <vector>

namespace WaveformUtilities {

  template <class Metric, class Hamiltonian>
  class WaveformAmplitudesResummed {
  private:
    const Metric& g;
    const Hamiltonian& H;
  public:
    WaveformAmplitudesResummed(const double idelta, const double ichis, const double ichia, const Metric& ig, const Hamiltonian& iH);
    void Hhat(const int L, const int M, const double v, double& Re, double& Im) const;
    void rhOverM(const int L, const int M, const double v, const double psi, double& Mag, double& Arg) const;
    void rhOverM(const int L, const int M, const std::vector<double>& v, const std::vector<double>& psi, std::vector<double>& Mag, std::vector<double>& Arg) const;
  };

  template <class Metric, class Hamiltonian>
  class WaveformAmplitudesResummedSumMMagSquared {
  private:
  public:
    WaveformAmplitudesResummedSumMMagSquared(const double delta, const double chis, const double chia, const Metric& ig, const Hamiltonian& iH);
    double SumMMagSquared(const double v) const;
  };

}

#endif // WAVEFORMAMPLITUDESRESUMMED_HPP
