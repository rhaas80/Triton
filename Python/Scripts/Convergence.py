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
        self.SetParameter('RWZFiles', 'rhOverM_ExtrapolatedN{ExtrapOrder}.dat')
        self.SetParameter('FluxFiles', '')
        self.SetParameter('WaveformFormat', 'MagArg')
        self.SetParameter('ExtrapolationOrders', [-1, 2, 3, 4, 5, 6, 7, 8])
        self.SetParameter('DifferenceFiles', '{DataType}_{Quantity1}-{Quantity2}_{Constant}.dat')
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
        for iLev in range(1,len(LevList)) :
            LastLev = LevList[iLev-1]
            NextLev = LevList[iLev]
            for Files in [Psi4Files, RWZFiles] :
                if(not Files=='') :
                    for i in range(len(ExtrapolationOrders)) :
                        LastFile = (LastLev + "/" + Files).format(ExtrapOrder=ExtrapolationOrders[i])
                        NextFile = (NextLev + "/" + Files).format(ExtrapOrder=ExtrapolationOrders[i])
                        sys.stdout.write("Computing {0} - {1} ... ".format(LastFile, NextFile))
                        sys.stdout.flush()
                        Diff[0] = PyGW.Waveform(LastFile, WaveformFormat);
                        Diff[1] = PyGW.Waveform(NextFile, WaveformFormat);
                        if(ConvergenceAlignmentT1!=3.0e300 and ConvergenceAlignmentT1!=3.0e300) :
                            if(not MutualAlignmentApproximant=='') :
                                PN = PyGW.Waveform(MutualAlignmentApproximant, delta, chis, chia, v0, Diff[0].LM());
                                PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
                                PN = PN.AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
                                Diff[1] = Diff[1].AlignTo(PN, ConvergenceAlignmentT1, ConvergenceAlignmentT2);
                            else :
                                Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
                        Diff.AlignPhases();
                        DiffFile = DifferenceFiles.format(DataType=Diff[0].Type(),
                                                          Quantity1=LastLev[LastLev.rfind("/")+1],
                                                          Quantity2=NextLev[NextLev.rfind("/")+1],
                                                          Constant=("N"+str(ExtrapolationOrders[i])))
                        sys.stdout.write("and printing {} ... ".format(DiffFile))
                        sys.stdout.flush()
                        Diff[0] = Diff[0]/Diff[1];
                        Diff[1].NSamplesPerCycle22(OutputNSamplesPerCycle22);
                        if(OutputNSamplesPerCycle22!=0) : Diff[0].Interpolate(Diff[1]);
                        if(DropBeforeTime!=-3.0e300) : Diff[0].DropBefore(DropBeforeTime);
                        if(DropAfterTime!=3.0e300) : Diff[0].DropAfter(DropAfterTime);
                        Output(DiffFile, Diff[0]);
                        print("☺")
            if(not FluxFiles=='') :
                for i in range(len(ExtrapolationOrders)) :
                    from numpy import genfromtxt, savetxt
                    LastFile = (LastLev + "/" + Files).format(ExtrapOrder=ExtrapolationOrders[i])
                    NextFile = (NextLev + "/" + Files).format(ExtrapOrder=ExtrapolationOrders[i])
                    sys.stdout.write("Computing {0} - {1} ... ".format(LastFile, NextFile))
                    sys.stdout.flush()
                    T,OmegaB,FluxB,PNFlux,NormalizedFlux = transpose(genfromtxt(LastFile))
                    T,OmegaA,FluxA,PNFlux,NormalizedFlux = transpose(genfromtxt(NextFile))
                    del T, NormalizedFlux
                    from scipy.interpolate import UnivariateSpline
                    FluxDiff = FluxA - UnivariateSpline(OmegaB, FluxB, s=0)(OmegaA)
                    DiffFile = DifferenceFiles.format(DataType='Flux',
                                                      Quantity1=LastLev[LastLev.rfind("/")+1],
                                                      Quantity2=NextLev[NextLev.rfind("/")+1],
                                                      Constant=("N"+str(ExtrapolationOrders[i])))
                    sys.stdout.write("and printing {} ... ".format(DiffFile))
                    sys.stdout.flush()
                    DiffFileHandle = open(DiffFile, 'w')
                    DiffFileHandle.write("# [1] = M*omega_hdot(2,-2)\n# [2] = FluxA-FluxB\n# [3] = (FluxA-FluxB)/PNFluxA\n")
                    savetxt(DiffFileHandle, transpose((OmegaA, FluxDiff, FluxDiff/PNFlux)))
                    DiffFileHandle.close()
                    print("☺")
        
        # // Do the extrapolation convergence
        for Files in [Psi4Files, RWZFiles] :
            if( (not Files=='') and (not BestLev=='') ) :
                for i in range(1,len(ExtrapolationOrders)) :
                    Higher = (BestLev + "/" + Files).format(ExtrapOrder=ExtrapolationOrders[i])
                    Lower  = (BestLev + "/" + Files).format(ExtrapOrder=ExtrapolationOrders[i-1])
                    sys.stdout.write("Computing {0} - {1} ... ".format(Higher, Lower))
                    sys.stdout.flush()
                    Diff[0] = PyGW.Waveform(Higher, WaveformFormat);
                    Diff[1] = PyGW.Waveform(Lower, WaveformFormat);
                    if( (ConvergenceAlignmentT1!=3.0e300) and (ConvergenceAlignmentT1!=3.0e300) ) :
                        if(not MutualAlignmentApproximant=='') :
                            PN = PyGW.Waveform(MutualAlignmentApproximant, delta, chis, chia, v0, Diff[0].LM());
                            PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
                            PN.AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
                            Diff[1].AlignTo(PN, ConvergenceAlignmentT1, ConvergenceAlignmentT2);
                        else :
                            Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
                    Diff.AlignPhases();
                    DiffFile = DifferenceFiles.format(DataType=Diff[0].Type(),
                                                      Quantity1=("N"+str(ExtrapolationOrders[i])),
                                                      Quantity2=("N"+str(ExtrapolationOrders[i-1])),
                                                      Constant=BestLev[BestLev.rfind("/")+1])
                    sys.stdout.write("and printing {0} ... ".format(DiffFile))
                    sys.stdout.flush()
                    Diff[0] = Diff[0]/Diff[1];
                    Diff[1].NSamplesPerCycle22(OutputNSamplesPerCycle22);
                    if(OutputNSamplesPerCycle22!=0) : Diff[0].Interpolate(Diff[1]);
                    if(DropBeforeTime!=-3.0e300) : Diff[0].DropBefore(DropBeforeTime);
                    if(DropAfterTime!=3.0e300) : Diff[0].DropAfter(DropAfterTime);
                    Output(DiffFile, Diff[0])
                    print("☺")




if __name__ == "__main__":
    import sys
    if(len(sys.argv)>1) :
        import os
        OriginalDir = os.getcwd()
        for filename in sys.argv[1:] :
            os.chdir(os.path.dirname(filename))
            Convergence(os.path.basename(filename))
            os.chdir(OriginalDir)
    else :
        Convergence()