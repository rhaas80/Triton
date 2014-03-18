#ifndef EOBMODEL_HPP
#define EOBMODEL_HPP

#include <string>

namespace WaveformUtilities {

  class EOBParameters {
  public:
    const double delta, nu, chis, chia, chi, chistar, chiKerr;
    double a4, a5, a6, d4, a, b, aSS;
  public:
    EOBParameters(const double delta, const double chis, const double chia,
                  const double gtt_a4, const double gtt_a5, const double gtt_a6, const double grr_d4,
                  const double HamGyro_a, const double HamGyro_b, const double Ham_aSS);
    EOBParameters(const double delta, const double chis, const double chia, const std::string& PaperRef="default");
  };



//   class EOBMetricNonspinning {
//   private:
//     const double nu, a4, a5, a6;
//     const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
//     const double Dinv0, Dinv2, Dinv3;
//     mutable double r;
//   public:
//     EOBMetricNonspinning(const double delta, const double chis=0, const double chia=0);
//     void operator()(const double r_new) const;
//     mutable double Dt;
//     mutable double Dr;
//     mutable double dDtdr;
//     mutable double dDrdr;
//     mutable double drdrstar;
//     mutable double drstardr;
//   };

//   class EOBHamiltonianNonspinning {
//   private:
//     const double nu;
//     const EOBMetricNonspinning& g;
//     mutable double r, prstar, pPhi;
//   public:
//     EOBHamiltonianNonspinning(const double delta, const double chis, const double chia, const EOBMetricNonspinning& ig);
//     void operator()(const double r_new, const double prstar_new, const double pPhi_new) const;
//     mutable double Heff;
//     mutable double H;
//     mutable double dHdr;
//     mutable double dHdPhi;
//     mutable double dHdprstar;
//     mutable double dHdpPhi;
//     mutable double v;
//   };




  class EOBMetricWithSpin {
  private:
    const double chiKerr;
    const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
    const double Dinv0, Dinv2, Dinv3, Dinv4;
    mutable double r;
  public:
    //EOBMetricWithSpin(const double delta, const double chis, const double chia);
    EOBMetricWithSpin(const EOBParameters& Par);
    void operator()(const double r_new) const;
    mutable double Dt;
    mutable double Dr;
    mutable double dDtdr;
    mutable double dDrdr;
    mutable double drdrstar;
    mutable double drstardr;
    mutable double ddrstardrdr;
  };

  class EOBHamiltonianWithSpin {
  private:
    const double nu;
    const EOBMetricWithSpin& g;
    const double chiKerr;
    const double aSSterm, sigmaconst, sigmarinv, sigmapPhi, sigmapr, sigmaprDr;
    mutable double r, prstar, pPhi;
  public:
    EOBHamiltonianWithSpin(const EOBParameters& Par, const EOBMetricWithSpin& ig);
    //EOBHamiltonianWithSpin(const double delta, const double chis, const double chia, const EOBMetricWithSpin& ig);
    void operator()(const double r_new, const double prstar_new, const double pPhi_new) const;
    mutable double Heff;
    mutable double H;
    mutable double dHdr;
    mutable double dHdPhi;
    mutable double dHdprstar;
    mutable double dHdpPhi;
    mutable double v;
  };


}

#endif // EOBMODEL_HPP
