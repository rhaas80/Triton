#ifndef EOBMODEL_HPP
#define EOBMODEL_HPP

namespace WaveformUtilities {
  
  class EOBMetricNonspinning {
  private:
    const double nu, a4, a5, a6;
    const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
    const double Dinv0, Dinv2, Dinv3;
    mutable double r;
  public:
    EOBMetricNonspinning(const double delta);
    void operator()(const double r_new) const;
    mutable double Dt;
    mutable double Dr;
    mutable double dDtdr;
    mutable double dDrdr;
    mutable double drdrstar;
    mutable double drstardr;
  };
  
  class EOBHamiltonianNonspinning {
  private:
    const double nu;
    const EOBMetricNonspinning& g;
    mutable double r, prstar, pPhi;
  public:
    EOBHamiltonianNonspinning(const double delta, const EOBMetricNonspinning& ig);
    void operator()(const double r_new, const double prstar_new, const double pPhi_new) const;
    operator double() const { return H; }
    mutable double Heff;
    mutable double H;
    mutable double dHdr;
    mutable double dHdPhi;
    mutable double dHdprstar;
    mutable double dHdpPhi;
    mutable double v;
  };
  
  
  
  
  class EOBMetricWithSpin {
  private:
    const double nu, a4, a5, a6, chiKerr;
    const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
    const double Dinv0, Dinv2, Dinv3;
    mutable double r;
  public:
    EOBMetricWithSpin(const double delta, const double chis, const double chia);
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
    const double chi, chistar, chiKerr, a, b, aSSterm;
    const double sigmapPhi, sigmapr, sigmarinv, sigmaconst;
    mutable double r, prstar, pPhi;
  public:
    EOBHamiltonianWithSpin(const double delta, const double chis, const double chia, const EOBMetricWithSpin& ig);
    void operator()(const double r_new, const double prstar_new, const double pPhi_new) const;
    operator double() { return H; }
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
