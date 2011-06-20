#include "Waveform.hpp"
#include "GaussJordanElimination.hpp"
#include "QuasinormalModes.hpp"
#include "EOBOrbitalPhasing.hpp"
#include "PNOrbitalPhasingT1.hpp"
#include "PNOrbitalPhasingT2.hpp"
#include "PNOrbitalPhasingT3.hpp"
#include "PNOrbitalPhasingT4.hpp"
#include "NoiseCurves.hpp"
#include "Units.hpp"
#include "VectorFunctions.hpp"
#include "EasyParser.hpp"
#include "Interpolate.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

const complex<double> PositiveI(0.0,  1.0);
const complex<double> NegativeI(0.0, -1.0);

double TransitionFunction_Ramp(const double x) {
  if(x<=0.0) return 0.0;
  if(x>=1.0) return 1.0;
  return x;
}

double TransitionFunction(const double x) {
  if(x<=0.0) return 0.0;
  if(x>=1.0) return 1.0;
  return 1.0/(1.0+exp(1.0/(x-1.0) + 1.0/x));
}

int main() {
  
  vector<vector<double> > QChis(4, vector<double>(2));
  QChis[0][0] = 1.00; QChis[0][1] = 0.00;
  QChis[1][0] = 1.00; QChis[1][1] = 0.95;
  QChis[2][0] = 10.0; QChis[2][1] = 0.00;
  QChis[3][0] = 10.0; QChis[3][1] = 0.95;
  
  for(unsigned int qchis=0; qchis<QChis.size(); qchis++) {
    const double PNOrder(3.5);
    const double q(QChis[qchis][0]);
    const double delta( (q-1)/(q+1) );
    const double chis(QChis[qchis][1]);
    const double chia(0.0);
    
    cout << "==================================================================\n"
	 << "q = " << q << "\nchis = " << chis << endl;
    
    const double DetectorMinFreq=AdvLIGOSeismicWall;
    const double WaveformMinOmega=2.0*M_PI*DetectorMinFreq/2.0;
    const double MinMass=5.0;  // Total binary mass in solar masses
    const double Minomega=0.005;  // Hybridization angular GW frequency (dimensionless)
    const double v0=min(pow(0.49*Minomega, 1.0/3.0),
			pow(NewtonsConstant*MinMass*SolarMass*(0.49*WaveformMinOmega)/(SpeedOfLight*SpeedOfLight*SpeedOfLight), 1.0/3.0));
    cout << "v0=" << v0 << " r0=" << pow(v0, -2.0) << " delta=" << delta << " chis=" << chis << "\n" << endl;
    
    const double Deltatmatch(0.1);
    const double nu((1.0-delta*delta)/4.0);
    const double chiKerr(min(0.998, max(chis, sqrt(12)*nu-3.87128*nu*nu+4.02788*nu*nu*nu)));
    
    cout << "Creating EOB inspiral data ... " << endl;
    const Waveform Inspiral("EOB", delta, chis, chia, v0, PNOrder, AvailableQNMLMs());
    const double tEnd(Inspiral.Time.back());
    cout << "☺" << endl;
    
    
    //// Set up the QNM waveform
    Waveform QNM(Inspiral);
    const double dt(0.25);
    const double tLength(500);
    QNM.Time.resize(Inspiral.Time.size()+int(tLength/dt));
    for(unsigned int i=Inspiral.Time.size(); i<QNM.Time.size(); ++i) {
      QNM.Time[i] = tEnd+(i-Inspiral.Time.size()+1)*dt;
    }
    for(unsigned int i=0; i<QNM.LM.size(); ++i) {
      QNM.amp[i].resize(QNM.Time.size());
      QNM.phi[i].resize(QNM.Time.size());
    }
    QNM.Radius.resize(QNM.Time.size());
    
    //// Loop over (L,M)
    for(unsigned int lm=0; lm<Inspiral.LM.size(); ++lm) {
      const int L(Inspiral.LM[lm][0]);
      const int M(Inspiral.LM[lm][1]);
      cout << "\n(l,m)=(" << Inspiral.LM[lm] << ")" << endl;
      
      //// If this mode should be exactly zero, let it be
      if(delta==0.0 && !(M%2==0)) {
	cout << "Assuming zero data" << endl;
	QNM.amp[lm] = vector<double>(QNM.Time.size(), 0.0);
	QNM.phi[lm] = vector<double>(QNM.Time.size(), 0.0);
	continue;
      }
      
      //// Get the QNM frequency
      const complex<double> sigma( M<0 ? -conj(QNMFrequencies(L,M,0,chiKerr)) : QNMFrequencies(L,M,0,chiKerr) );
      
      //// Extract the invertible data of the l,m mode
      const unsigned int iEnd=Inspiral.amp[lm].size()-1;
      const unsigned int iPeak=maxIndex(Inspiral.amp[lm]);
      const double tDropBefore(Inspiral.Time[iPeak]);
      unsigned int i=iPeak;
      i++;
      while(Inspiral.amp[lm][i] < Inspiral.amp[lm][i-1] && i<Inspiral.amp[lm].size()) { ++i; }
      const unsigned int iBad=i;
      const double tDropAfter(Inspiral.Time[iBad]);
      Waveform InspiralLM(Inspiral[lm].DropBefore(tDropBefore).DropAfter(tDropAfter));
      
      //// Find the solution
      vector<double> F( dydx(InspiralLM.amp[0], InspiralLM.Time) + (InspiralLM.amp[0] * abs(imag(sigma))) );
      vector<double> T(InspiralLM.Time);
      {
	unsigned int k=1;
	while(F[k]<F[k-1]) { ++k; }
	F.erase(F.begin()+k, F.end());
	T.erase(T.begin()+k, T.end());
      }
      double tmatch( Interpolate(F, T, 0.0) );
      if(tmatch<tDropBefore || tmatch>tDropAfter) {
	cout << "Redoing tmatch find!" << endl;
	InspiralLM = Inspiral[lm].DropBefore(tDropBefore);
	const double tLength = InspiralLM.Time.back()-InspiralLM.Time[0];
	for(unsigned int j=0; j<InspiralLM.Time.size(); ++j) {
	  InspiralLM.amp[0][j] *= (1.0-TransitionFunction((InspiralLM.Time[j]-InspiralLM.Time[0])/tLength));
	  QNM.amp[lm][j+iPeak] = InspiralLM.amp[0][j];
	}
	F = dydx(InspiralLM.amp[0], InspiralLM.Time) + (InspiralLM.amp[0] * abs(imag(sigma)));
	T = InspiralLM.Time;
	{
	  unsigned int k=1;
	  while(F[k]<F[k-1]) { ++k; }
	  F.erase(F.begin()+k, F.end());
	  T.erase(T.begin()+k, T.end());
	}
	tmatch = Interpolate(F, T, 0.0);
	
      }
      InspiralLM = InspiralLM.Interpolate(tmatch);
      const complex<double> Alm0( (InspiralLM.Amp(0,0))*exp(PositiveI*InspiralLM.Phi(0,0)) );
      i=iPeak;
      while(tmatch>QNM.Time[i] && i<QNM.Time.size()) { ++i; }
      const unsigned int iMatch=i; // iMatch points at or to the right of tmatch
      
      //// Read data into the QNM waveform
      const double phiPeak = QNM.phi[lm][iPeak];
      const double omegaPeak = (QNM.phi[lm][iPeak+1]-QNM.phi[lm][iPeak-1]) / (QNM.Time[iPeak+1]-QNM.Time[iPeak-1]);
      const double omegaQNM = -real(sigma);
      cout << "tPeak=" << tDropBefore << " tmatch=" << tmatch << " tBad=" << tDropAfter << " omegaPeak=" << omegaPeak << " omegaQNM=" << omegaQNM << endl;
      vector<double> omegaTransition(iMatch-iPeak, omegaPeak);
      for(unsigned int k=1; k<omegaTransition.size(); ++k) {
	omegaTransition[k] = omegaPeak + (omegaQNM-omegaPeak)*TransitionFunction_Ramp((QNM.Time[k+iPeak]-QNM.Time[iPeak])/(QNM.Time[iMatch-1]-QNM.Time[iPeak]));
      }
      vector<double> phiTransition(iMatch-iPeak, phiPeak);
      for(unsigned int k=1; k<phiTransition.size(); ++k) {
	phiTransition[k] = phiTransition[k-1] + (QNM.Time[k+iPeak]-QNM.Time[k+iPeak-1])*(omegaTransition[k]+omegaTransition[k-1])/2.0;
      }
      for(unsigned int j=iPeak; j<iMatch; ++j) {
	QNM.phi[lm][j] = phiTransition[j-iPeak];
      }
      const double phiOffset = phiTransition.back() + omegaTransition.back()*(tmatch-QNM.Time[iMatch-1]);
      for(unsigned int j=iMatch; j<QNM.Time.size(); ++j) {
	complex<double> qnm(Alm0*exp( NegativeI * sigma * (QNM.Time[j]-tmatch) ));
	QNM.amp[lm][j] = abs(qnm);
	QNM.phi[lm][j] = arg(qnm) + phiOffset - arg(Alm0);
      }
      QNM.phi[lm] = Unwrap(QNM.phi[lm]);
    }
    
    //// Output to file
    cout << "\n\nWriting Output/rhOverM_EOBTotalWaveform_q" << DoubleToString(q) << "_chis" << DoubleToString(chis) << ".dat ... " << flush;
    ofstream ofW(("Output/rhOverM_EOBTotalWaveform_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + ".dat").c_str(), ofstream::out);
    ofW << setprecision(14) << QNM << flush;
    ofW.close();
    cout << "☺\n\n\n" << endl;
    
  } //// QChis loop
  
  return 0;
}
