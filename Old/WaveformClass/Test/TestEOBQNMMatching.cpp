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

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

const complex<double> PositiveI(0.0,  1.0);
const complex<double> NegativeI(0.0, -1.0);

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
    
    if(chis>0) cout << "\n\n\n\n\n\n";
    cout << "==================================================================\n"
	 << "q = " << q << "\nchis = " << chis << endl;
    
    const double DetectorMinFreq=AdvLIGOSeismicWall;
    const double WaveformMinOmega=2.0*M_PI*DetectorMinFreq/2.0;
    const double MinMass=5.0;  // Total binary mass in solar masses
    const double Minomega=0.005;  // Hybridization angular GW frequency (dimensionless)
    const double v0=min(pow(0.98*Minomega, 1.0/3.0),
			pow(NewtonsConstant*MinMass*SolarMass*(WaveformMinOmega)/(SpeedOfLight*SpeedOfLight*SpeedOfLight), 1.0/3.0));
    cerr << "v0=" << v0 << " r0=" << pow(v0, -2.0) << " delta=" << delta << " chis=" << chis << "\n\n" << endl;
    
    const int NOvertones(4);
    const double Deltatmatch(3.0*(NOvertones-1));
    const double nu((1.0-delta*delta)/4.0);
    const double chiKerr(min(0.998, max(chis, sqrt(12)*nu-3.87128*nu*nu+4.02788*nu*nu*nu)));
    
    cout << "Creating EOB inspiral data ... " << endl;
    const Waveform Inspiral("EOB", delta, chis, chia, v0, PNOrder, AvailableQNMLMs());
    cout << "☺" << endl;
    
    const double tmatch(Inspiral.Peak22Time());
    cout << "tmatch = " << tmatch << endl;
    vector<double> t(NOvertones);
    for(unsigned int alpha=0; alpha<NOvertones-2; ++alpha) {
      t[alpha] = tmatch - Deltatmatch*(1.0-double(alpha+1)/double(NOvertones));
    }
    t[NOvertones-2] = tmatch - Deltatmatch;
    t[NOvertones-1] = tmatch;
    
    //// Set up the QNM waveform
    Waveform QNM;
    const double dt(0.25);
    const double tLength(500);
    QNM.Type=2;
    QNM.TimeScale="(t-r*)/M";
    QNM.LM=Inspiral.LM;
    QNM.Time.resize(t.size()+int(tLength/dt)-1);
    QNM.Time[0] = tmatch-Deltatmatch;
    for(unsigned int i=1; i<t.size()-1; ++i) {
      QNM.Time[i] = t[i-1];
    }
    QNM.Time[t.size()-1] = tmatch;
    for(unsigned int i=t.size(); i<QNM.Time.size(); ++i) {
      QNM.Time[i] = tmatch+(i-t.size()+1)*dt;
    }
    QNM.amp=vector<vector<double> >(Inspiral.LM.size(), vector<double>(QNM.Time.size()));
    QNM.phi=vector<vector<double> >(Inspiral.LM.size(), vector<double>(QNM.Time.size()));
    
    //// Loop over (L,M)
    for(unsigned int lm=0; lm<Inspiral.LM.size(); ++lm) {
      const Waveform InspiralLM = (Inspiral[lm].DropBefore(-1000));
      const int L(Inspiral.LM[lm][0]);
      const int M(Inspiral.LM[lm][1]);
      cout << "\n(l,m)=(" << Inspiral.LM[lm] << ")" << endl;
      
      //// Get the QNM frequencies
      vector<complex<double> > sigmas(NOvertones);
      for(unsigned int N=0; N<sigmas.size(); ++N) {
	sigmas[N] = QNMFrequencies(L,M,N,chiKerr);
	if(M<0) { sigmas[N] = -conj(sigmas[N]); }
      }
      
      //// Set up the matrices for solution
      vector<vector<complex<double> > > QNMFactors(NOvertones, vector<complex<double> >(NOvertones));
      for(unsigned int N=0; N<NOvertones; ++N) {
	unsigned int alpha=0;
	for(alpha=0; alpha<NOvertones-2; ++alpha) {
	  QNMFactors[alpha][N] = exp( NegativeI * sigmas[N] * (t[alpha]-tmatch) );
	}
	QNMFactors[alpha][N] = NegativeI * sigmas[N] * exp( NegativeI * sigmas[N] * (t[alpha]-tmatch) );
	++alpha;
	QNMFactors[alpha][N] = NegativeI * sigmas[N] * exp( NegativeI * sigmas[N] * (t[alpha]-tmatch) );
      }
      vector<complex<double> > InspiralFactors(NOvertones);
      double PhiOffsetLM(0.0);
      {
	Waveform WInspiralFactors(InspiralLM);
	WInspiralFactors = WInspiralFactors.Interpolate(t);
	PhiOffsetLM = WInspiralFactors.phi[0][NOvertones-1];
	unsigned int alpha=0;
	for(alpha=0; alpha<NOvertones-2; ++alpha) {
	  InspiralFactors[alpha] = (WInspiralFactors.Amp(0, alpha))*exp(PositiveI*WInspiralFactors.Phi(0, alpha));
	}
	WInspiralFactors = InspiralLM.Differentiate().Interpolate(t);
	InspiralFactors[alpha] = (WInspiralFactors.Amp(0, alpha))*exp(PositiveI*WInspiralFactors.Phi(0, alpha));
	++alpha;
	InspiralFactors[alpha] = (WInspiralFactors.Amp(0, alpha))*exp(PositiveI*WInspiralFactors.Phi(0, alpha));
      }
      
      //// Find the solution
      GaussJordanElimination(QNMFactors, InspiralFactors);
      cout << "A_{lmn} = " << flush;
      for(unsigned int i=0; i<InspiralFactors.size(); ++i) {
	cout << real(InspiralFactors[i]) << "+I*" << imag(InspiralFactors[i]);
	if(i<InspiralFactors.size()-1) cout << ", ";
      }
      cout << "\nFit at times=" << t << endl << endl;
      
      //// Read data into the QNM waveform
      for(unsigned int i=0; i<QNM.Time.size(); ++i) {
	complex<double> qnm(InspiralFactors[0]*exp( NegativeI * sigmas[0] * (QNM.Time[i]-tmatch) ));
	for(unsigned int j=1; j<sigmas.size(); ++j) {
	  qnm += InspiralFactors[j]*exp( NegativeI * sigmas[j] * (QNM.Time[i]-tmatch) );
	}
	QNM.amp[lm][i] = abs(qnm);
	QNM.phi[lm][i] = arg(qnm);
      }
      QNM.phi[lm] = Unwrap(QNM.phi[lm]);
      QNM.phi[lm] = QNM.phi[lm] + (PhiOffsetLM - QNM.phi[lm][t.size()-1]);
    }
    
    //// Attach to the inspiral waveform
    Waveform EOB(Inspiral.HybridizeWith(QNM, tmatch-Deltatmatch, tmatch));
    
    //// Output to files
    cout << "Writing Output/rhOverM_EOBTotalWaveform_q" << DoubleToString(q) << "_chis" << DoubleToString(chis) << ".dat ... " << flush;
    ofstream ofW(("Output/rhOverM_EOBTotalWaveform_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + ".dat").c_str(), ofstream::out);
    ofW << setprecision(12) << EOB << flush;
    ofW.close();
    cout << "☺" << endl;
    cout << "Writing Output/rhOverM_QNMWaveform_q" << DoubleToString(q) << "_chis" << DoubleToString(chis) << ".dat ... " << flush;
    ofstream ofQ(("Output/rhOverM_QNMWaveform_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + ".dat").c_str(), ofstream::out);
    ofQ << setprecision(12) << QNM << flush;
    ofQ.close();
    cout << "☺" << endl;
    cout << "Writing Output/rhOverM_InspiralWaveform_q" << DoubleToString(q) << "_chis" << DoubleToString(chis) << ".dat ... " << flush;
    ofstream ofI(("Output/rhOverM_InspiralWaveform_q" + DoubleToString(q) + "_chis" + DoubleToString(chis) + ".dat").c_str(), ofstream::out);
    ofI << setprecision(12) << Inspiral << flush;
    ofI.close();
    cout << "☺" << endl;
    
  } //// QChis loop
  
  return 0;
}
