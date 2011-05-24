#ifndef EOBMODEL_HPP
#define EOBMODEL_HPP

namespace WaveformUtilities {
  
  class EOBMetricNonspinning {
  private:
    const double nu, a4, a5, a6;
    const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
    const double Dinv0, Dinv2, Dinv3;
  public:
    mutable double r;
    EOBMetricNonspinning(const double delta);
    void operator()(const double r_new);
    double Dt;
    double DR;
    double dDtdr;
    double dDRdr;
    double drdrstar;
    double drstardr;
  };
  
  class EOBHamiltonianNonspinning {
  private:
    const double nu;
    EOBMetricNonspinning& g;
  public:
    mutable double r, prstar, pPhi;
    EOBHamiltonianNonspinning(const double delta, EOBMetricNonspinning& ig);
    void operator()(const double r_new, const double prstar_new, const double pPhi_new);
    operator double() { return H; }
    double Heff;
    double H;
    double dHdr;
    double dHdPhi;
    double dHdprstar;
    double dHdpPhi;
    double v;
  };
  
  
  
  
  class EOBMetricWithSpin {
  private:
    const double nu, a4, a5, a6, chikerr;
    const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
    const double Dinv0, Dinv2, Dinv3;
  public:
    mutable double r;
    EOBMetricWithSpin(const double delta, const double chis);
    void operator()(const double r_new);
    double Dt;
    double DR;
    double dDtdr;
    double dDRdr;
    double drdrstar;
    double drstardr;
  };
  
//   class EOBHamiltonianWithSpin {
//   private:
//     EOBMetricWithSpin& g;
//     const double nu, chitot, chistar, chieff, ageff, bgeff, a3PNSS;
//   public:
//     mutable double r, prstar, pPhi;
//     EOBHamiltonianWithSpin(const double delta, const double chis, const EOBMetricWithSpin& ig);
//     void operator()(const double r_new, const double prstar_new, const double pPhi_new) const;
//     operator double() { return H; }
//     double Heff;
//     double H;
//     double dHdr;
//     double dHdPhi;
//     double dHdprstar;
//     double dHdpPhi;
//     double v;
//   };
  
  
  
  
  
}

#endif // EOBMODEL_HPP
