#ifndef FLUX_HPP
#define FLUX_HPP

#include "WaveformAmplitudes.hpp"
#include "WaveformAmplitudesResummed.hpp"
#include "VectorFunctions.hpp"

namespace WaveformUtilities {

  class Flux_Base {
  protected:
    mutable double v;
  public:
    mutable double Flux;
    Flux_Base() : v(0.0), Flux(0.0) { }
    double operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const;
  };

  class TidalHeating : public Flux_Base {
  private:
    const double N;
  public:
    TidalHeating(const double delta, const double chis, const double chia);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };

  class Flux_Taylor : public Flux_Base {
  private:
    const double nu, F0, F2, F3, F4, F5, F6, F6lnv, F7;
  public:
    Flux_Taylor(const double delta, const double chis, const double chia);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };


  class Flux_Taylor8 : public Flux_Base {
  private:
    const double nu, F0, F2, F3, F4, F5, F6, F6lnv, F7, F8, F8lnv;
  public:
    Flux_Taylor8(const double delta, const double chis, const double chia);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };


  class Flux_Pade44LogConst : public Flux_Base {
  private:
    const double nu, N;
    const double f2, f3, f4, f5, f6, f6lnv, f7, f8, f8lnv;
    const double FNum0, FNum0lnv, FNum0lnv2, FNum1, FNum1lnv, FNum1lnv2, FNum2, FNum2lnv, FNum2lnv2, FNum3, FNum3lnv, FNum3lnv2, FNum4, FNum4lnv, FNum4lnv2, FNum4lnv3;
    const double FDen0, FDen0lnv, FDen0lnv2, FDen1, FDen1lnv, FDen1lnv2, FDen2, FDen2lnv, FDen2lnv2, FDen3, FDen3lnv, FDen3lnv2, FDen4, FDen4lnv, FDen4lnv2, FDen4lnv3;
  public:
    Flux_Pade44LogConst(const double delta, const double chis, const double chia);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };


  class Flux_Pade44LogFac : public Flux_Base {
  private:
    const double nu, N, vPole, vLSO;
    const double flogfac6, flogfac8;
    const double f1, f2, f3, f4, f5, f6, f7, f8;
    const double FNum0, FNum1, FNum2, FNum3, FNum4;
    const double FDen0, FDen1, FDen2, FDen3, FDen4;
  public:
    Flux_Pade44LogFac(const double delta, const double chis, const double chia);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };


  class Flux_SumAmplitudes : public Flux_Base, private WaveformAmplitudesSumMMagSquared {
  private:
    const double N;
  public:
    Flux_SumAmplitudes(const double delta, const double chis, const double chia);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };


  template <class Metric, class Hamiltonian>
  class Flux_SumAmplitudesResummed : public Flux_Base, private WaveformAmplitudesResummedSumMMagSquared<Metric, Hamiltonian> {
  private:
    mutable double r, prstar, pPhi;
    const double N;
  public:
    Flux_SumAmplitudesResummed(const double delta, const double chis, const double chia, const Metric& ig, const Hamiltonian& iH);
    double operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const;
  };


  template <class Flux>
  class Torque_KFPhi {
  private:
    const double nu;
    const Flux& F;
    mutable double v, r, prstar, pPhi;
  public:
    typedef Flux FluxType;
    mutable double Torque;
    Torque_KFPhi(const double delta, const double chis, const double chia, const Flux& iF);
    template <class H> Torque_KFPhi(const double delta, const double chis, const double chia, const Flux& iF, const H& Ham);
    double operator()(const double v_new, const double r_new=0.0, const double prstar_new=0.0, const double pPhi_new=0.0) const;
  };

  /// This choice is significantly slower, and makes only a miniscule difference in the result
//   template <class HamiltonianCircular, class Flux>
//   class Torque_nKFPhi {
//   private:
//     const double nu;
//     const HamiltonianCircular& Hcirc;
//     const Flux& F;
//     mutable double v, r, prstar, pPhi;
//   public:
//     typedef Flux FluxType;
//     mutable double Torque;
//     Torque_nKFPhi(const double delta, const double chis, const double chia, const Flux& iF, const HamiltonianCircular& iHcirc);
//     double operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const;
//   };

  #include "Flux.tpp"

}

#endif // FLUX_HPP
