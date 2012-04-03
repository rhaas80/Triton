#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Measure convergence for a series of Cauchy resolutions, and optionally
for a series of extrapolation orders.



"""

## We use a class just to be able to set the parameters nicely.  This
## should be treated basically like a function.
class Convergence :
    def SetParameter(self, VariableName, DefaultValue) :
        if VariableName in self.ParameterDictionary :
            setattr(self, VariableName, self.ParameterDictionary[VariableName])
        else :
            setattr(self, VariableName, DefaultValue)
    
    def __init__ (self, FileName="", Dictionary={}) :
        import PyGW
        import sys
        self.ParameterDictionary=Dictionary
        
        # Set up the parameters, using default values or the value
        # stored in the Dictionary.
        self.SetParameter('LevList', ['../Lev4', '../Lev5', '../Lev6'])
        self.SetParameter('BestLev', self.LevList[-1])
        self.SetParameter('Psi4Files', '')
        self.SetParameter('RWZFiles', 'rhOverM_ExtrapolatedN%d.dat')
        self.SetParameter('FluxFiles', '')
        self.SetParameter('WaveformFormat', 'MagArg')
        self.SetParameter('ExtrapolationOrders', [-1, 2, 3, 4, 5, 6, 7, 8])
        self.SetParameter('DifferenceFiles', '%s-%s_%s.dat')
        self.SetParameter('ConvergenceAlignmentT1', 3.0e300)
        self.SetParameter('ConvergenceAlignmentT2', 3.0e300)
        self.SetParameter('OutputNSamplesPerCycle22', 0)
        self.SetParameter('DropBeforeTime', -3.0e300)
        self.SetParameter('DropAfterTime', 3.0e300)
        self.SetParameter('MutualAlignmentApproximant', '')
        self.SetParameter('delta', 0.0)
        self.SetParameter('chis', 0.0)
        self.SetParameter('chia', 0.0)
        self.SetParameter('v0', 0.144)
        
        # If there's an input file, read it in, which may reset some
        # of the above values.
        if(FileName!="") :
            execfile(FileName)
        
        # Do the Lev convergence
        Diff = PyGW.Waveforms(2)
        # vector<double> FluxA(0), OmegaA(0), FluxB(0), OmegaB(0), PNFlux(0), FluxDiff(0);
        for iLev in range(1,len(LevList)) :
            LastLev = LevList[iLev-1]
            NextLev = LevList[iLev]
            if(not Psi4Files=='') :
                for i in range(len(ExtrapolationOrders)) :
                    LastFile = (LastLev + "/" + Psi4Files) % ExtrapolationOrders[i]
                    NextFile = (NextLev + "/" + Psi4Files) % ExtrapolationOrders[i]
                    sys.stdout.write("Computing {0} - {1} ... ".format(LastFile, NextFile))
                    sys.stdout.flush()
                    Diff[0] = PyGW.Waveform(LastFile, WaveformFormat);
                    Diff[1] = PyGW.Waveform(NextFile, WaveformFormat);
        if(ConvergenceAlignmentT1!=3.0e300 and ConvergenceAlignmentT1!=3.0e300) {
          if( not MutualAlignmentApproximant=='') {
            PN = PyGW.Waveform(MutualAlignmentApproximant, delta, chis, chia, v0, Diff[0].LM());
            PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
            PN = PN.AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
            Diff[1] = Diff[1].AlignTo(PN, ConvergenceAlignmentT1, ConvergenceAlignmentT2);
          } else {
            Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
          }
        }
  #       Diff.AlignPhases();
  #       sprintf(DiffFile, (Diff[0].Type() + "_" + DifferenceFiles).c_str(),
  #       	LastLev.substr(LastLev.rfind("/")+1).c_str(),
  #       	NextLev.substr(NextLev.rfind("/")+1).c_str(),
  #       	("N"+DoubleToString(ExtrapolationOrders[i])).c_str());
  #       cout << "and printing " << DiffFile << "... " << flush;
  #       Diff[0] = Diff[0]/Diff[1];
  #       Diff[1].NSamplesPerCycle22(OutputNSamplesPerCycle22);
  #       if(OutputNSamplesPerCycle22!=0) { Diff[0].Interpolate(Diff[1]); }
  #       if(DropBeforeTime!=-3.0e300) { Diff[0].DropBefore(DropBeforeTime); }
  #       if(DropAfterTime!=3.0e300) { Diff[0].DropAfter(DropAfterTime); }
  #       ofstream ofs(DiffFile, ofstream::out);
  #       ofs << setprecision(14) << flush;
  #       ofs << Diff[0];
  #       ofs.close();
  #       cout << "☺" << endl;
  #     }
                    
  #   if(!RWZFiles.empty()) for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
  #       char NextFile[1000], LastFile[1000], DiffFile[1000];
  #       sprintf(LastFile, (LastLev + "/" + RWZFiles).c_str(), ExtrapolationOrders[i]);
  #       sprintf(NextFile, (NextLev + "/" + RWZFiles).c_str(), ExtrapolationOrders[i]);
  #       cout << "Computing " << LastFile << " - " << NextFile << "... " << flush;
  #       Diff[0] = Waveform(LastFile, WaveformFormat);
  #       Diff[1] = Waveform(NextFile, WaveformFormat);
  #       if(ConvergenceAlignmentT1!=3.0e300 && ConvergenceAlignmentT1!=3.0e300) {
  #         if( ! MutualAlignmentApproximant.empty()) {
  #           Waveform PN(MutualAlignmentApproximant, delta, chis, chia, v0, Diff[0].LM());
  #           PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
  #           PN = PN.AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #           Diff[1] = Diff[1].AlignTo(PN, ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #         } else {
  #           Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #         }
  #       }
  #       Diff.AlignPhases();
  #       sprintf(DiffFile, (Diff[0].Type() + "_" + DifferenceFiles).c_str(),
  #       	LastLev.substr(LastLev.rfind("/")+1).c_str(),
  #       	NextLev.substr(NextLev.rfind("/")+1).c_str(),
  #       	("N"+DoubleToString(ExtrapolationOrders[i])).c_str());
  #       cout << "and printing " << DiffFile << "... " << flush;
  #       Diff[0] = Diff[0]/Diff[1];
  #       Diff[1].NSamplesPerCycle22(OutputNSamplesPerCycle22);
  #       if(OutputNSamplesPerCycle22!=0) { Diff[0].Interpolate(Diff[1]); }
  #       if(DropBeforeTime!=-3.0e300) { Diff[0].DropBefore(DropBeforeTime); }
  #       if(DropAfterTime!=3.0e300) { Diff[0].DropAfter(DropAfterTime); }
  #       ofstream ofs(DiffFile, ofstream::out);
  #       ofs << setprecision(14) << flush;
  #       ofs << Diff[0];
  #       ofs.close();
  #       cout << "☺" << endl;
  #     }
  #   if(!FluxFiles.empty()) for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
  #       char NextFile[1000], LastFile[1000], DiffFile[1000];
  #       string Header="";
  #       vector<double> T, NormalizedFlux;
  #       sprintf(LastFile, (LastLev + "/" + FluxFiles).c_str(), ExtrapolationOrders[i]);
  #       sprintf(NextFile, (NextLev + "/" + FluxFiles).c_str(), ExtrapolationOrders[i]);
  #       cout << "Computing " << LastFile << " - " << NextFile << "... " << flush;
  #       ReadFluxFile(LastFile, Header, T, OmegaB, FluxB, PNFlux, NormalizedFlux);
  #       ReadFluxFile(NextFile, Header, T, OmegaA, FluxA, PNFlux, NormalizedFlux);
  #       FluxDiff = FluxA - Interpolate(OmegaB, FluxB, OmegaA);
  #       sprintf(DiffFile, ("Flux_" + DifferenceFiles).c_str(),
  #       	LastLev.substr(LastLev.rfind("/")+1).c_str(),
  #       	NextLev.substr(NextLev.rfind("/")+1).c_str(),
  #       	("N"+DoubleToString(ExtrapolationOrders[i])).c_str());
  #       cout << "and printing " << DiffFile << "... " << flush;
  #       ofstream ofs(DiffFile, ofstream::out);
  #       ofs << "# [1] = M*omega_hdot(2,-2)\n"
  #           << "# [2] = FluxA-FluxB\n"
  #           << "# [3] = (FluxA-FluxB)/PNFluxA\n"
  #           << setprecision(8) << flush;
  #       for(unsigned int j=0; j<OmegaA.size(); ++j) {
  #         ofs << OmegaA[j] << " " << FluxDiff[j] << " " << FluxDiff[j]/PNFlux[j] << endl;
  #       }
  #       ofs.close();
  #       cout << "☺" << endl;
  #     }
  #   LastLev = NextLev;
  #   A = B+1;
  #   B = LevList.find(" ", B+1);
  #   NextLev = LevList.substr(A,B-A);
  
  # // Do the extrapolation convergence
  # if(!Psi4Files.empty() && !BestLev.empty()) for(unsigned int i=1; i<ExtrapolationOrders.size(); ++i) {
  #     char Higher[5000], Lower[5000], DiffFile[5000];
  #     sprintf(Higher, (BestLev + "/" + Psi4Files).c_str(), ExtrapolationOrders[i]);
  #     sprintf(Lower,  (BestLev + "/" + Psi4Files).c_str(), ExtrapolationOrders[i-1]);
  #     cout << "Computing " << Higher << " - " << Lower << "... " << flush;
  #     Diff[0] = Waveform(Higher, WaveformFormat);
  #     Diff[1] = Waveform(Lower, WaveformFormat);
  #     if(ConvergenceAlignmentT1!=3.0e300 && ConvergenceAlignmentT1!=3.0e300) {
  #       if( ! MutualAlignmentApproximant.empty()) {
  #         Waveform PN(MutualAlignmentApproximant, delta, chis, chia, v0, Diff[0].LM());
  #         PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
  #         PN = PN.AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #         Diff[1] = Diff[1].AlignTo(PN, ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #       } else {
  #         Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #       }
  #     }
  #     Diff.AlignPhases();
  #     sprintf(DiffFile, (Diff[0].Type() + "_" + DifferenceFiles).c_str(),
  #             ("N"+DoubleToString(ExtrapolationOrders[i])).c_str(),
  #             ("N"+DoubleToString(ExtrapolationOrders[i-1])).c_str(),
  #             (BestLev.substr(BestLev.rfind("/")+1)).c_str());
  #     cout << "and printing " << DiffFile << "... " << flush;
  #     Diff[0] = Diff[0]/Diff[1];
  #     Diff[1].NSamplesPerCycle22(OutputNSamplesPerCycle22);
  #     if(OutputNSamplesPerCycle22!=0) { Diff[0].Interpolate(Diff[1]); }
  #     if(DropBeforeTime!=-3.0e300) { Diff[0].DropBefore(DropBeforeTime); }
  #     if(DropAfterTime!=3.0e300) { Diff[0].DropAfter(DropAfterTime); }
  #     ofstream ofs(DiffFile, ofstream::out);
  #     ofs << setprecision(14) << flush;
  #     ofs << Diff[0];
  #     ofs.close();
  #     cout << "☺" << endl;
  #   }
  # if(!RWZFiles.empty() && !BestLev.empty()) for(unsigned int i=1; i<ExtrapolationOrders.size(); ++i) {
  #     char Higher[1000], Lower[1000], DiffFile[1000];
  #     sprintf(Higher, (BestLev + "/" + RWZFiles).c_str(), ExtrapolationOrders[i]);
  #     sprintf(Lower,  (BestLev + "/" + RWZFiles).c_str(), ExtrapolationOrders[i-1]);
  #     cout << "Computing " << Higher << " - " << Lower << "... " << flush;
  #     Diff[0] = Waveform(Higher, WaveformFormat);
  #     Diff[1] = Waveform(Lower, WaveformFormat);
  #     if(ConvergenceAlignmentT1!=3.0e300 && ConvergenceAlignmentT1!=3.0e300) {
  #       if( ! MutualAlignmentApproximant.empty()) {
  #         Waveform PN(MutualAlignmentApproximant, delta, chis, chia, v0, Diff[0].LM());
  #         PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
  #         PN = PN.AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #         Diff[1] = Diff[1].AlignTo(PN, ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #       } else {
  #         Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
  #       }
  #     }
  #     Diff.AlignPhases();
  #     sprintf(DiffFile, (Diff[0].Type() + "_" + DifferenceFiles).c_str(),
  #             ("N"+DoubleToString(ExtrapolationOrders[i])).c_str(),
  #             ("N"+DoubleToString(ExtrapolationOrders[i-1])).c_str(),
  #             (BestLev.substr(BestLev.rfind("/")+1)).c_str());
  #     cout << "and printing " << DiffFile << "... " << flush;
  #     Diff[0] = Diff[0]/Diff[1];
  #     Diff[1].NSamplesPerCycle22(OutputNSamplesPerCycle22);
  #     if(OutputNSamplesPerCycle22!=0) { Diff[0].Interpolate(Diff[1]); }
  #     if(DropBeforeTime!=-3.0e300) { Diff[0].DropBefore(DropBeforeTime); }
  #     if(DropAfterTime!=3.0e300) { Diff[0].DropAfter(DropAfterTime); }
  #     ofstream ofs(DiffFile, ofstream::out);
  #     ofs << setprecision(14) << flush;
  #     ofs << Diff[0];
  #     ofs.close();
  #     cout << "☺" << endl;
  #   }
  
        





if __name__ == "__main__":
    import sys
    if(len(sys.argv)>1) :
        import os
        OriginalDir = os.getcwd()
        for filename in sys.argv[1:] :
            os.chdir(os.path.dirname(filename))
            Convergence(filename)
            os.chdir(OriginalDir)
    else :
        Convergence()
