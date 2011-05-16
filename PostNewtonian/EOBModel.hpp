#ifndef EOBMODEL_HPP
#define EOBMODEL_HPP

namespace WaveformUtilities {
  
  class EOBMetricWithSpin {
  private:
    const double a4, a5, a6, d4;
    const double DtNum0, DtNum1, DtDen0, DtDen1, DtDen2, DtDen3, DtDen4, DtDen5;
    const double DRNum0, DRNum1, DRDen0, DRDen1, DRDen2, DRDen3, DRDen4, DRDen5;
    choke;
  public:
    mutable double r;
    void operator()(const double r_new) const;
    double Dt;
    double DR;
    double dDtdr;
    double dDRdr;
    double drdrstar;
    double drstardr;
  };
  
  class EOBHamiltonianWithSpin {
  private:
    const EOBMetricWithSpin& g;
    const double chitot, chistar, chieff, ageff, bgeff, a3PNSS;
    choke;
  public:
    mutable double r, prstar, pPhi;
    void operator()(const double r_new, const double prstar_new, const double pPhi_new) const;
    double Heff;
    double Hreal;
    double dHdr;
    double dHdPhi;
    double dHdprstar;
    double dHdpPhi;
  };
  
  
  
  
  
}

#endif // EOBMODEL_HPP
