template <class Metric, class Hamiltonian>
Flux_SumAmplitudesResummed<Metric, Hamiltonian>::Flux_SumAmplitudesResummed(const double delta, const double chis, const double chia, const Metric& ig, const Hamiltonian& iH)
  : WaveformUtilities::WaveformAmplitudesResummedSumMMagSquared<Metric, Hamiltonian>(delta, chis, chia, ig, iH),
    N(1.0/(16.0*M_PI))
{ }

template <class Metric, class Hamiltonian>
double Flux_SumAmplitudesResummed<Metric, Hamiltonian>::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new && r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return Flux; }
  v = v_new;
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  return Flux = N*WaveformUtilities::sixth(v)*WaveformUtilities::WaveformAmplitudesResummedSumMMagSquared<Metric, Hamiltonian>::SumMMagSquared(v, r, prstar, pPhi);
}


template <class Flux>
Torque_KFPhi<Flux>::Torque_KFPhi(const double delta, const double chis, const double chia, const Flux& iF)
  : nu((1.0-delta*delta)/4.0), F(iF),
    v(0.0), r(0.0), prstar(0.0), pPhi(0.0), Torque(0.0)
{ }

template <class Flux> template <class Ham>
Torque_KFPhi<Flux>::Torque_KFPhi(const double delta, const double chis, const double chia, const Flux& iF, const Ham& H)
  : nu((1.0-delta*delta)/4.0), F(iF),
    v(0.0), r(0.0), prstar(0.0), pPhi(0.0), Torque(0.0)
{ }

template <class Flux>
double Torque_KFPhi<Flux>::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
  if(v==v_new && r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return Torque; }
  v = v_new;
  r = r_new;
  prstar = prstar_new;
  pPhi = pPhi_new;
  F(v, r, prstar, pPhi);
  return Torque = -F.Flux/(nu*cube(v));
}


// template <class HamiltonianCircular, class Flux>
// Torque_nKFPhi<HamiltonianCircular, Flux>::Torque_nKFPhi(const double delta, const double chis, const Flux& iF, const HamiltonianCircular& iHcirc)
//   : nu((1.0-delta*delta)/4.0), Hcirc(iHcirc), F(iF),
//     v(0.0), r(0.0), prstar(0.0), pPhi(0.0), Torque(0.0)
// { }

// template <class HamiltonianCircular, class Flux>
// double Torque_nKFPhi<HamiltonianCircular, Flux>::operator()(const double v_new, const double r_new, const double prstar_new, const double pPhi_new) const {
//   if(v==v_new && r==r_new && prstar==prstar_new && pPhi==pPhi_new) { return Torque; }
//   v = v_new;
//   r = r_new;
//   prstar = prstar_new;
//   pPhi = pPhi_new;
//   Hcirc(r, 0.0, pPhi);
//   F(v, r, prstar, pPhi);
//   /// Eqs. (65) and (66) of Boyle et al., 2008: PRD 78, 104020
//   /// r_Omega := (dH/dpPhi)^(-2/3) = (Omega_circ)^(-2/3)
//   /// VPhi := Omega * r_Omega
//   /// VPhi^6 = v^18 * (dH/dpPhi)^(-4)
//   /// v^3 / VPhi^6 = (dH/dpPhi)^4 / v^15
//   return Torque = -F.Flux * std::pow(Hcirc.dHdpPhi,4) / (nu*std::pow(v,15));
// }
