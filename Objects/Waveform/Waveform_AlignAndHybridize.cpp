#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

#include "../Waveform.hpp"

#include "Interpolate.hpp"
#include "Minimize.hpp"
#include "FileIO.hpp"
#include "SWSHs.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Units.hpp"
#include "PostNewtonian.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::setprecision;
using std::stringstream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::min;
using std::max;
using std::ios_base;


class WaveformAligner {
  friend class Waveform;
protected:
  const Waveform& a, b;
  vector<double> t, arga;
  int LMa, LMb;
public:
  WaveformAligner(const Waveform& A, const Waveform& B, const double t1, const double t2)
    : a(A), b(B), t(a.T()), arga(0), LMa(-1), LMb(-1)
  {
    if(a.NModes() != b.NModes()) {
      cerr << "\nTrying to Align Waveforms with mismatched LM data." << endl;
      cerr << "a.NModes()=" << a.NModes() << "\tb.NModes()=" << b.NModes() << endl;
      Throw1WithMessage("Different number of modes");
    }
    if(a.LM() != b.LM()) {
      cerr << "\nTrying to Align Waveforms with mismatched LM data." << endl;
      cerr << "a.LM()=" << a.LM() << "\nb.LM()=" << b.LM() << endl;
      Throw1WithMessage("Different modes");
    }
    if(t1<a.T(0)) {
      cerr << "\nAlignment time t1=" << t1 << " does not occur in Waveform A (which has A.T(0)=" << A.T(0) << ")." << endl;
      Throw1WithMessage("Bad matching time for Waveform A");
    }
    if(t1<b.T(0)) {
      cerr << "\nAlignment time t1=" << t1 << " does not occur in Waveform B (which has B.T(0)=" << B.T(0) << ")." << endl;
      Throw1WithMessage("Bad matching time for Waveform B");
    }
    if(t2>a.T().back()) {
      cerr << "\nAlignment time t2=" << t2 << " does not occur in Waveform A (which has A.T(-1)=" << A.T().back() << ")." << endl;
      Throw1WithMessage("Bad matching time for Waveform A");
    }
    if(t2>B.T().back()) {
      cerr << "\nAlignment time t2=" << t2 << " does not occur in Waveform B (which has B.T(-1)=" << B.T().back() << ")." << endl;
      Throw1WithMessage("Bad matching time for Waveform B");
    }
    unsigned int i=0;
    //ORIENTATION!!! following loops
    for(i=0; i<a.NModes(); ++i) {
      if(a.L(i)==2 && a.M(i)==2) { LMa=i; break; }
    }
    if(LMa==-1) {
      cerr << "\na.LM()=" << a.LM() << endl;
      Throw1WithMessage("Can't find the 2,2 component of Waveform a!");
    }
    for(i=0; i<b.NModes(); ++i) {
      if(b.L(i)==2 && b.M(i)==2) { LMb=i; break; }
    }
    if(LMb==-1) {
      cerr << "\nb.LM()=" << b.LM() << endl;
      Throw1WithMessage("Can't find the 2,2 component of Waveform b!");
    }
    arga = a.Arg(LMa);
    i=t.size()-1;
    while(t[i]>t2 && i>0) { --i; }
    t.erase(t.begin()+i, t.end());
    arga.erase(arga.begin()+i, arga.end());
    i=0;
    while(i<a.T().size() && a.T(i)<t1) { ++i; }
    t.erase(t.begin(), t.begin()+i);
    arga.erase(arga.begin(), arga.begin()+i);
  }

  int LM_a() { return LMa; }

  double darg(const double dt, const unsigned int mode) const {
    vector<double> argA = WaveformUtilities::Interpolate(a.T(), a.Arg(mode), t);
    vector<double> argB = WaveformUtilities::Interpolate(b.T(), b.Arg(mode), t-dt);
    // return trapz(t, argA-argB) / (t.back()-t[0]);
    return SplineCumulativeIntegral(t, argA-argB) / (t.back()-t[0]);
  }

  double operator()(const double dt) const {
    vector<double> argb = WaveformUtilities::Interpolate(b.T(), b.Arg(LMb), t-dt);
    // double darg = trapz(t, arga-argb) / (t.back()-t[0]);
    // return trapz(t, (arga-argb-darg)*(arga-argb-darg));
    double darg = SplineCumulativeIntegral(t, arga-argb) / (t.back()-t[0]);
    return SplineCumulativeIntegral(t, (arga-argb-darg)*(arga-argb-darg));
  }
};

/// Align phases of two Waveforms to within 2*pi at a fractional time in this Waveform of tFrac.
Waveform& WaveformObjects::Waveform::AlignPhasesToTwoPi(const Waveform& a, const double tFrac) {
  if(tFrac<0 || tFrac>1) {
    cerr << "\ntFrac=" << tFrac << endl;
    Throw1WithMessage("Bad fraction");
  }
  History() << "### this->AlignPhasesToTwoPi(a, " << tFrac << ");\n" << flush;
  const int Ithis=int(tFrac*NTimes());
  Waveform b(a);
  b.Interpolate(T(Ithis));
  for(unsigned int mode=0; mode<b.NModes() && mode<NModes(); ++mode) {
    ArgRef(mode) += (2.0 * M_PI * round((b.Arg(mode,0)-Arg(mode,Ithis))/(2.0*M_PI)));
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::AlignTo(const Waveform& a, const double t1, const double t2) {
  History() << "### this->AlignTo(a, " << t1 << ", " << t2 << ");\n#" << flush;
  WaveformAligner Align(a, *this, t1, t2);
  Brent Minimizer;
  Minimizer.ax = max(t1-t2, T(0)-t1);
  Minimizer.bx = 0.0;
  Minimizer.cx = min(t2-t1, T().back()-t2);
  double dt = Minimizer.minimize(Align);
  const double darg22 = Align.darg(dt, Align.LM_a());
  this->AddToTime(dt);
  int Ia=0;
  int Ithis=0;
  while(a.T(Ia)<t2 && Ia<int(a.NTimes())) { Ia++; }
  while(T(Ithis)<t2 && Ithis<int(NTimes())) { Ithis++; }
  for(unsigned int mode=0; mode<a.NModes() && mode<NModes(); ++mode) {
    ArgRef(mode) += (2.0 * M_PI * round((a.Arg(mode,Ia)-Arg(mode,Ithis)-M(mode)*darg22/2.0)/(2.0*M_PI))) + M(mode)*darg22/2.0;
  }
  History() << "#### this->RotatePhase(" << darg22/2.0 << "); # Pseudo-command: Add (m times this phase) to each mode's phase." << endl;
  return *this;
}

Waveform& WaveformObjects::Waveform::AlignWithIntermediate(const Waveform& a, Waveform Intermediate, const double t1, const double t2) {
  History() << "### this->AlignWithIntermediate(a, b, "  << t1 << ", " << t2 << ");\n#" << flush;
  Intermediate.AlignTo(a, t1, t2);
  History() << "#" << flush;
  this->AlignTo(Intermediate, t1, t2);
  return *this;
}

Waveform WaveformObjects::Waveform::HybridizeWith(const Waveform& b, const double t1, const double t2, const double MinStep) const {
  if(NModes() != b.NModes()) {
    cerr << "\nTrying to Align Waveforms with mismatched LM data." << endl;
    cerr << "NModes()=" << NModes() << "\tb.NModes()=" << b.NModes() << endl;
    Throw1WithMessage("Different number of modes");
  }
  if(LM() != b.LM()) {
    cerr << "\nTrying to Align Waveforms with different LM data." << endl;
    cerr << "LM()=" << LM() << "\nb.LM()=" << b.LM() << endl;
    Throw1WithMessage("Different modes");
  }
  Waveform c(*this);
  c.TRef() = Union(T(), b.T(), MinStep);
  int it=c.NTimes()-1;
  while(c.T(it)>b.T().back() && it>0) { --it; }
  c.TRef().erase(c.TRef().begin()+it, c.TRef().end());
  c.RRef() = vector<double>(1, 0.0);
  c.MagRef().resize(NModes(), c.NTimes());
  c.ArgRef().resize(NModes(), c.NTimes());
  unsigned int J01=0, J12=c.NTimes()-1;
  while(c.T(J01)<t1 && J01<c.NTimes()) { J01++; }
  while(c.T(J12)>t2 && J12>0) { J12--; }
  const double TransitionLength=max(1.0,double(J12-J01-1.0)); // This is an int that will be used for division
  //ORIENTATION!!! Following loop
  for(unsigned int Mode=0; Mode<NModes(); ++Mode) {
    SplineInterpolator SplineMagA(  T(),   mag[Mode]);
    SplineInterpolator SplineMagB(b.T(), b.mag[Mode]);
    SplineInterpolator SplineArgA(  T(),   Arg(Mode));
    SplineInterpolator SplineArgB(b.T(), b.Arg(Mode));
    for(unsigned int j=0; j<J01; ++j) {
      c.MagRef(Mode,j) = SplineMagA.interp(c.T(j));
      c.ArgRef(Mode,j) = SplineArgA.interp(c.T(j));
    }
    for(unsigned int j=J01; j<J12; ++j) {
      const double Transition = double(j-J01)/TransitionLength;
      c.MagRef(Mode,j) = SplineMagA.interp(c.T(j))*(1.0-Transition) + SplineMagB.interp(c.T(j))*Transition;
      c.ArgRef(Mode,j) = SplineArgA.interp(c.T(j))*(1.0-Transition) + SplineArgB.interp(c.T(j))*Transition;
    }
    for(unsigned int j=J12; j<c.NTimes(); ++j) {
      c.MagRef(Mode,j) = SplineMagB.interp(c.T(j));
      c.ArgRef(Mode,j) = SplineArgB.interp(c.T(j));
    }
  }

  // Check for NaNs
  c.HasNaNs();

  return c;
}

inline double sign(const double x) {
  return (x<0 ? -1.0 : 1.0);
}

Waveform& WaveformObjects::Waveform::AlignTo_F(const Waveform& a, const double omega, const double t1, const double t2, const double DeltaT, const double MinStep) {
  if(omega==0.0) {
    cerr << "\nThe frequency input to AlignTo_F is exactly 0.0.  This will give you garbage" << endl;
    Throw1WithMessage("Bad frequency");
  }
  unsigned int i=0;
  double T1(t1), T2(t2);
  if(T1<a.T(0)) { T1=a.T(0); }
  if(T1<  T(0)) { T1=  T(0); }
  if(T2>a.T().back()) { T2=a.T().back(); }
  if(T2>  T().back()) { T2=  T().back(); }
  WaveformAligner Align(a, *this, T1, T2);
  vector<double> NewTimeA(a.T());
  vector<double> NewOmegaA(a.Omega2m2());
  const double NewOmegaASign = sign(NewOmegaA[NewOmegaA.size()/2]);
  vector<double> NewTimeB(T());
  vector<double> NewOmegaB(Omega2m2());
  const double NewOmegaBSign = sign(NewOmegaB[NewOmegaB.size()/2]);
  try {
    /// Make sure A only includes data before T2
    i=NewTimeA.size()-1;
    while(NewTimeA[i]>T2 && i>0) { --i; }
    if(i!=NewTimeA.size()-1) {
      NewTimeA.erase(NewTimeA.begin()+i, NewTimeA.begin()+NewTimeA.size());
      NewOmegaA.erase(NewOmegaA.begin()+i, NewOmegaA.begin()+NewOmegaA.size());
    }
    /// Make sure A only includes data after T1
    i=0;
    while(i<NewTimeA.size() && NewTimeA[i]<T1) { ++i; }
    if(i!=0) {
      NewTimeA.erase(NewTimeA.begin(), NewTimeA.begin()+i);
      NewOmegaA.erase(NewOmegaA.begin(), NewOmegaA.begin()+i);
    }
    /// Make sure NewOmegaA gets up to abs(omega), but is strictly monotonically increasing before it
    i=1;
    while(i<NewOmegaA.size() && NewOmegaASign*NewOmegaA[i]<fabs(omega)) { ++i; }
    while(i>0 && NewOmegaASign*NewOmegaA[i-1]<NewOmegaASign*NewOmegaA[i]) { --i; }
    if(i!=1) {
      NewTimeA.erase(NewTimeA.begin(), NewTimeA.begin()+i);
      NewOmegaA.erase(NewOmegaA.begin(), NewOmegaA.begin()+i);
    }
    /// Make sure NewOmegaA gets past abs(omega), and is strictly monotonically increasing afterward
    i=1;
    while(i<NewTimeA.size() && NewOmegaASign*NewOmegaA[i]<fabs(omega)) { ++i; }
    while(i<NewTimeA.size() && NewOmegaASign*NewOmegaA[i]>NewOmegaASign*NewOmegaA[i-1]) { ++i; }
    if(i!=1) {
      NewTimeA.erase(NewTimeA.begin()+i, NewTimeA.begin()+NewTimeA.size());
      NewOmegaA.erase(NewOmegaA.begin()+i, NewOmegaA.begin()+NewOmegaA.size());
    }

    /// Make sure B only includes data before T2
    i=NewTimeB.size()-1;
    while(NewTimeB[i]>T2 && i>0) { --i; }
    if(i!=NewTimeB.size()-1) {
      NewTimeB.erase(NewTimeB.begin()+i, NewTimeB.begin()+NewTimeB.size());
      NewOmegaB.erase(NewOmegaB.begin()+i, NewOmegaB.begin()+NewOmegaB.size());
    }
    /// Make sure B only includes data after T1
    i=0;
    while(i<NewTimeB.size() && NewTimeB[i]<T1) { ++i; }
    if(i!=0) {
      NewTimeB.erase(NewTimeB.begin(), NewTimeB.begin()+i);
      NewOmegaB.erase(NewOmegaB.begin(), NewOmegaB.begin()+i);
    }
    /// Make sure NewOmegaB gets up to fabs(omega), but is strictly monotonically increasing before it
    i=1;
    while(i<NewOmegaB.size() && NewOmegaBSign*NewOmegaB[i]<fabs(omega)) { ++i; }
    while(i>0 && NewOmegaBSign*NewOmegaB[i-1]<NewOmegaBSign*NewOmegaB[i]) { --i; }
    if(i>1) {
      NewTimeB.erase(NewTimeB.begin(), NewTimeB.begin()+i);
      NewOmegaB.erase(NewOmegaB.begin(), NewOmegaB.begin()+i);
    }
    /// Make sure NewOmegaB gets past fabs(omega), and is strictly monotonically increasing afterward
    i=1;
    while(i<NewOmegaB.size() && NewOmegaBSign*NewOmegaB[i]<fabs(omega)) { ++i; }
    while(i<NewTimeB.size() && NewOmegaBSign*NewOmegaB[i]>NewOmegaBSign*NewOmegaB[i-1]) { ++i; }
    if(i>1) {
      NewTimeB.erase(NewTimeB.begin()+i, NewTimeB.begin()+NewTimeB.size());
      NewOmegaB.erase(NewOmegaB.begin()+i, NewOmegaB.begin()+NewOmegaB.size());
    }
  } catch (char* str) {
    cerr << "Bad news from AlignTo_F: " << str << endl
         << "\nThe frequency requested is probably out of range of one or both of the Waveforms, or your t1 and t2 are too restrictive.\n" << endl;
    exit(1);
  }
  const double TA = WaveformUtilities::Interpolate(NewOmegaA, NewTimeA, NewOmegaASign*fabs(omega));
  NewOmegaA.clear();
  NewTimeA.clear();
  const double TB = WaveformUtilities::Interpolate(NewOmegaB, NewTimeB, NewOmegaBSign*fabs(omega));
  NewOmegaB.clear();
  NewTimeB.clear();

  const double dt = TA-TB;
  TRef() += dt;
  for(unsigned int i=0; i<a.NModes() && i<NModes(); ++i) {
    ArgRef(i) += WaveformUtilities::Interpolate(a.T(), a.Arg(i), TA) - WaveformUtilities::Interpolate(T(), Arg(i), TA);
  }

  if(DeltaT!=1e300) {
    //cerr << "\nomega=" << omega << "\tTA=" << TA << "\tt1=" << max(TA-DeltaT, max(a.T(0), T(0)))
    //     << "\tt2=" << min(TA+DeltaT, min(a.T(a.NTimes()-1), T(NTimes()-1))) << endl;
    *this = this->HybridizeWith(a, std::max(TA-DeltaT, std::max(a.T(0), T(0))), std::min(TA+DeltaT, std::min(a.T().back(), T().back())), MinStep);
  }

  return *this;
}

Waveform WaveformObjects::Waveform::HybridizeWith_F(const Waveform& a, const double omega, const double omegat1, const double omegat2, const double DeltaT, const double MinStep) const {
  Waveform b(*this);
  b.AlignTo_F(a, omega, omegat1, omegat2, DeltaT, MinStep);
  return b;
}

Waveform& WaveformObjects::Waveform::AttachQNMs(const double delta, const double chiKerr, double dt, const double TLength) {
//   if(LM() != QNMLMs()) {
//     cerr << "LM=" << LM() << "\nQNMLMs()=" << QNMLMs() << endl;
//     Throw1WithMessage("Bad input LMs.");
//   }

  if(dt==0.0) { dt = 2*M_PI/(4*2.07); } // 2.07 -> MAX(omegaRe of all the QNM modes)
  History() << "### this->AttachQNMs(" << chiKerr << ", " << dt << ", " << TLength << ");" << endl;

  /// Add the new times, and resize everything as appropriate
  const double TPeak = Peak22Time();
  const double TEnd = T().back();
  unsigned int QNMi1=0;
  while(T(QNMi1)<TPeak) { ++QNMi1; }
  {
    const double ExtrapVal = 0.0;
    vector<double> NewTimes(int(floor(TLength/dt)), TPeak);
    for(unsigned int i=1; i<NewTimes.size(); ++i) {
      NewTimes[i] += i*dt;
    }
    NewTimes = Union(T(), NewTimes, dt/2.0);
    cout << "NewTimes[0]=" << NewTimes[0] << "\tNewTimes.back()=" << NewTimes.back() << endl;
    cout << "T(0)=" << T(0) << "\tT().back()=" << T().back() << endl;
    this->Interpolate(NewTimes, ExtrapVal);
  }

//   const unsigned int NTimesEnd = NTimes();
//   TRef().resize(NTimes()+int(floor(TLength/dt)), T().back());
//   for(unsigned int i=0; i<NTimes()-NTimesEnd; ++i) {
//     TRef(i+NTimesEnd) += (i+1)*dt;
//   }
//   if(R().size()>1) { RRef().resize(NTimes(), 0.0); }
//   MagRef().resize(NModes(), NTimes(), 0.0);
//   ArgRef().resize(NModes(), NTimes(), 0.0);

  for(unsigned int mode=0; mode<NModes(); ++mode) {
    //// If this mode should be exactly zero, let it be
    if(delta==0.0 && !(M(mode)%2==0)) {
      continue;
    }

    //// Get the QNM frequency
    double omegaRe, omegaIm;
    QNM(L(mode), M(mode), 0, chiKerr, omegaRe, omegaIm);

    //// Extract the invertible data of the l,m mode
    unsigned int iPeak=maxIndex(Mag(mode));
    const double tDropBefore(T(iPeak));
    unsigned int i=iPeak;
    i++;
    while(Mag(mode, i) < Mag(mode, i-1) && T(i)<TEnd) { ++i; }
    const unsigned int iBad=i;
    const double tDropAfter(T(iBad));
    Waveform InspiralLM((this->operator[](mode)).DropBefore(tDropBefore).DropAfter(tDropAfter));

    //// Find the solution.  Most of this is dedicated to making sure the interpolation of Fvec and Tvec is well-posed
    vector<double> Fvec = dydx(InspiralLM.Mag(0), InspiralLM.T()) + (InspiralLM.Mag(0) * abs(omegaIm));
    vector<double> Tvec = InspiralLM.T();
    {
      unsigned int k=1;
      if(Fvec[0]>0.0) {
        while(Fvec[k]>Fvec[k-1] && k<Fvec.size()) { ++k; }
        Fvec.erase(Fvec.begin(), Fvec.begin()+k);
        Tvec.erase(Tvec.begin(), Tvec.begin()+k);
        k=1;
      }
      while(Fvec[k]<Fvec[k-1]) { ++k; }
      Fvec.erase(Fvec.begin()+k, Fvec.end());
      Tvec.erase(Tvec.begin()+k, Tvec.end());
    }
    double tmatch = WaveformUtilities::Interpolate(Fvec, Tvec, 0.0);

    if((delta==deltaOFq(10.0) && chiKerr==FinalSpinApproximation(deltaOFq(10), 0.95))) {
      //cout << "Redoing tmatch find! (tailored to q==10 && chis==0.95)" << endl;
      iPeak = NTimes()-1;
      while(T(iPeak) > -40.0 && iPeak>1) { --iPeak; }
      QNMi1 = iPeak;
      InspiralLM = (this->operator[](mode)).DropBefore(T(iPeak)).DropAfter(TEnd-1.0);
      //cout << "InspiralLM.NTimes()=" << InspiralLM.NTimes()
      //     << " InspiralLM.T(0)=" << InspiralLM.T(0)
      //     << " InspiralLM.T().back()=" << InspiralLM.T().back() << endl;
      const double tLength = InspiralLM.T().back()-InspiralLM.T(0);
      for(unsigned int j=0; j<InspiralLM.NTimes(); ++j) {
        InspiralLM.MagRef(0,j) *= (1.0-TransitionFunction_Smooth((InspiralLM.T(j)-InspiralLM.T(0))/tLength));
        MagRef(mode, j+iPeak) = InspiralLM.Mag(0, j);
      }
      Fvec = dydx(InspiralLM.Mag(0), InspiralLM.T()) + (InspiralLM.Mag(0) * abs(omegaIm));
      Tvec = InspiralLM.T();
      {
        unsigned int k=1;
        while(Fvec[k]>Fvec[k-1] && k<Fvec.size()) { ++k; }
        Fvec.erase(Fvec.begin(), Fvec.begin()+k);
        Tvec.erase(Tvec.begin(), Tvec.begin()+k);
        k=1;
        while(Fvec[k]<Fvec[k-1] && k<Fvec.size()) { ++k; }
        Fvec.erase(Fvec.begin()+k, Fvec.end());
        Tvec.erase(Tvec.begin()+k, Tvec.end());
      }
      tmatch = WaveformUtilities::Interpolate(Fvec, Tvec, 0.0);
    } else if(tmatch<tDropBefore || tmatch>tDropAfter) {
      //cout << "Redoing tmatch find!" << endl;
      InspiralLM = (this->operator[](mode)).DropBefore(tDropBefore).DropAfter(TEnd);
      const double tFakeRingdown = std::min(InspiralLM.T(0)+50.0, InspiralLM.T().back());
      const double tLength = tFakeRingdown-InspiralLM.T(0);
      for(unsigned int j=0; j<InspiralLM.NTimes(); ++j) {
        InspiralLM.MagRef(0, j) *= (1.0-TransitionFunction_Smooth((InspiralLM.T(j)-InspiralLM.T(0))/tLength));
        MagRef(mode, j+iPeak) = InspiralLM.Mag(0, j);
      }
      Fvec = dydx(InspiralLM.Mag(0), InspiralLM.T()) + (InspiralLM.Mag(0) * abs(omegaIm));
      Tvec = InspiralLM.T();
      {
        unsigned int k=1;
        if(Fvec[0]>0.0) {
          while(Fvec[k]>Fvec[k-1] && k<Fvec.size()) { ++k; }
          Fvec.erase(Fvec.begin(), Fvec.begin()+k);
          Tvec.erase(Tvec.begin(), Tvec.begin()+k);
          k=1;
        }
        while(Fvec[k]<Fvec[k-1]) { ++k; }
        Fvec.erase(Fvec.begin()+k, Fvec.end());
        Tvec.erase(Tvec.begin()+k, Tvec.end());
      }
      tmatch = WaveformUtilities::Interpolate(Fvec, Tvec, 0.0);
      //if(L(mode)==2 && M(mode)==2) {
      //  ofstream ofs("Outputs/F.dat", ofstream::out);
      //  for(unsigned int k=0; k<Fvec.size(); ++k) {
      //  ofs << setprecision(14) << Tvec[k] << " " << Fvec[k] << " " << InspiralLM.Mag(0, k) << endl;
      //}
      //ofs.close();
      //}
    }
    InspiralLM = InspiralLM.Interpolate(tmatch);
    const double Alm0Re = (InspiralLM.Mag(0,0))*cos(InspiralLM.Arg(0,0));
    const double Alm0Im = (InspiralLM.Mag(0,0))*sin(InspiralLM.Arg(0,0));
    i=iPeak;
    while(tmatch>T(i) && i<NTimes()) { ++i; }
    const unsigned int iMatch=i; // iMatch points at or to the right of tmatch

    //// Read data into the QNM portion of the waveform
    const double phiPeak = Arg(mode, iPeak);
    const double omegaPeak = (Arg(mode, iPeak+1)-Arg(mode, iPeak-1)) / (T(iPeak+1)-T(iPeak-1));
    const double omegaQNM = omegaRe;
    //cout << "L=" << L(mode) << " M=" << M(mode) << setprecision(14) << " tPeak=" << tDropBefore << " tmatch=" << tmatch << " tBad=" << tDropAfter << " omegaPeak=" << omegaPeak << " omegaQNM=" << omegaQNM << endl;
    vector<double> omegaTransition(iMatch-iPeak, omegaPeak);
    for(unsigned int k=1; k<omegaTransition.size(); ++k) {
      omegaTransition[k] = omegaPeak + (omegaQNM-omegaPeak)*TransitionFunction_Linear((T(k+iPeak)-T(iPeak))/(T(iMatch-1)-T(iPeak)));
    }
    vector<double> phiTransition(iMatch-iPeak, phiPeak);
    for(unsigned int k=1; k<phiTransition.size(); ++k) {
      phiTransition[k] = phiTransition[k-1] + (T(k+iPeak)-T(k+iPeak-1))*(omegaTransition[k]+omegaTransition[k-1])/2.0;
    }
    for(unsigned int j=iPeak; j<iMatch; ++j) {
      ArgRef(mode, j) = phiTransition[j-iPeak];
    }
    const double phiOffset = phiTransition.back() + omegaTransition.back()*(tmatch-T(iMatch-1));
    for(unsigned int j=iMatch; j<NTimes(); ++j) {
      const double qnmRe = Alm0Re*cos(omegaRe*(T(j)-tmatch)) - Alm0Im*sin(omegaRe*(T(j)-tmatch));
      const double qnmIm = Alm0Im*cos(omegaRe*(T(j)-tmatch)) + Alm0Re*sin(omegaRe*(T(j)-tmatch));
      MagRef(mode, j) = sqrt(qnmRe*qnmRe + qnmIm*qnmIm) * exp(-omegaIm*(T(j)-tmatch));
      ArgRef(mode, j) = atan2(qnmIm, qnmRe) + phiOffset - atan2(Alm0Im, Alm0Re);
    }
    Unwrap(ArgRef(mode), QNMi1-10, NTimes()); // Unwrap just the new part of the data
  }
  return *this;
}
