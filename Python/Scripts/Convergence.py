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
        import PyGW.plot
        import sys
        import matplotlib.pyplot as plt
        self.ParameterDictionary=Dictionary
        
        # Set up the parameters, using default values or the value
        # stored in the Dictionary.
        self.SetParameter('LevList', ['../Lev4', '../Lev5', '../Lev6'])
        self.SetParameter('BestLev', self.LevList[-1])
        self.SetParameter('Psi4Files', '')
        self.SetParameter('RWZFiles', 'rhOverM_ExtrapolatedN{ExtrapOrder}.dat')
        self.SetParameter('FluxFiles', '')
        self.SetParameter('WaveformFormat', 'MagArg')
        self.SetParameter('ExtrapolationOrders', [-1, 5])
        self.SetParameter('BestExtrapolationh', self.BestLev+'/'+(self.RWZFiles.format(ExtrapOrder=self.ExtrapolationOrders[0])))
        self.SetParameter('ConvergenceAlignmentT1', 3.0e300)
        self.SetParameter('ConvergenceAlignmentT2', 3.0e300)
        AlignmentString = ''
        if(self.ConvergenceAlignmentT1!=3.0e300 and self.ConvergenceAlignmentT2!=3.0e300) :
            AlignmentString = '_Aligned_{0}--{1}'.format(self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2)
        self.SetParameter('DifferenceFiles', '{DataType}_{Quantity1}-{Quantity2}_{Constant}'+AlignmentString+'.dat')
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
        
        # If we can, find the max flux time
        MaxFluxTime=3.0e300;
        if(self.BestExtrapolationh!='') :
            FluxW = PyGW.Waveform(self.BestExtrapolationh, self.WaveformFormat)
            FluxW.Differentiate()
            MaxFluxTime = FluxW.PeakFluxTime()
        
        # Do the Lev convergence
        # Diff0 = PyGW.Waveform()
        # Diff1 = PyGW.Waveform()
        Diff = PyGW.Waveforms(2)
        for Files in [self.RWZFiles, self.Psi4Files] :
            if(Files!='') :
                for i in range(len(self.ExtrapolationOrders)) :
                    figmag = plt.figure('Mag')
                    figarg = plt.figure('Arg')
                    for iLev in range(1,len(self.LevList)) :
                        LastLev = self.LevList[iLev-1]
                        NextLev = self.LevList[iLev]
                        LastFile = (LastLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                        NextFile = (NextLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                        sys.stdout.write("Computing {0} - {1} ... ".format(LastFile, NextFile))
                        sys.stdout.flush()
                        Diff[0] = PyGW.Waveform(LastFile, self.WaveformFormat);
                        Diff[1] = PyGW.Waveform(NextFile, self.WaveformFormat);
                        if(self.ConvergenceAlignmentT1!=3.0e300 and self.ConvergenceAlignmentT2!=3.0e300) :
                            if(self.MutualAlignmentApproximant!='') :
                                PN = PyGW.Waveform(self.MutualAlignmentApproximant, self.delta, self.chis, self.chia, self.v0, Diff[0].LM());
                                PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
                                PN = PN.AlignTo(Diff[0], self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                                Diff[1] = Diff[1].AlignTo(PN, self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                            else :
                                Diff[1] = Diff[1].AlignTo(Diff[0], self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                        Diff.AlignPhases();
                        DiffFile = self.DifferenceFiles.format(DataType=Diff[0].Type(),
                                                               Quantity1=LastLev[LastLev.rfind("/")+1:],
                                                               Quantity2=NextLev[NextLev.rfind("/")+1:],
                                                               Constant=("N"+str(self.ExtrapolationOrders[i])))
                        sys.stdout.write("and printing {} ... ".format(DiffFile))
                        sys.stdout.flush()
                        Diff[0] = Diff[0]/Diff[1];
                        Diff[1].NSamplesPerCycle22(self.OutputNSamplesPerCycle22);
                        if(self.OutputNSamplesPerCycle22!=0) : Diff[0].Interpolate(Diff[1]);
                        if(self.DropBeforeTime!=-3.0e300) : Diff[0].DropBefore(self.DropBeforeTime);
                        if(self.DropAfterTime!=3.0e300) : Diff[0].DropAfter(self.DropAfterTime);
                        PyGW.Output(DiffFile, Diff[0]);
                        sys.stdout.write("and plotting ... ")
                        sys.stdout.flush()
                        plt.figure('Mag')
                        Diff[0].plot('LogMag', Modes=[[2,2]], label=r'$({0}) - ({1})$'.format(LastLev, NextLev))
                        plt.figure('Arg')
                        Diff[0].plot('LogArg', Modes=[[2,2]], label=r'$({0}) - ({1})$'.format(LastLev, NextLev))
                        print("☺")
                    
                    plt.figure('Mag')
                    plt.legend(loc=2)
                    plt.gca().set_ylim(1e-8, 10)
                    if(MaxFluxTime!=3.0e300) :
                        plt.gca().axvline(x=MaxFluxTime, ls='--')
                    figmag.savefig('{DataType}_LevConvergence_{Constant}_Mag{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                    Constant=("N"+str(self.ExtrapolationOrders[i])),
                                                                                                    Alignment=AlignmentString))
                    plt.close(figmag)
                    plt.figure('Arg')
                    plt.legend(loc=2)
                    plt.gca().set_ylim(1e-8, 10)
                    if(MaxFluxTime!=3.0e300) :
                        plt.gca().axvline(x=MaxFluxTime, ls='--')
                    figarg.savefig('{DataType}_LevConvergence_{Constant}_Arg{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                    Constant=("N"+str(self.ExtrapolationOrders[i])),
                                                                                                    Alignment=AlignmentString))
                    plt.close(figarg)
        
        if(self.FluxFiles!='') :
            from scipy.interpolate import UnivariateSpline
            from numpy import genfromtxt, savetxt
            for i in range(len(self.ExtrapolationOrders)) :
                figflux = plt.figure('Flux')
                for iLev in range(1,len(self.LevList)) :
                    LastLev = self.LevList[iLev-1]
                    NextLev = self.LevList[iLev]
                    LastFile = (LastLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                    NextFile = (NextLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                    sys.stdout.write("Computing {0} - {1} ... ".format(LastFile, NextFile))
                    sys.stdout.flush()
                    T,OmegaB,FluxB,PNFlux,NormalizedFlux = transpose(genfromtxt(LastFile))
                    T,OmegaA,FluxA,PNFlux,NormalizedFlux = transpose(genfromtxt(NextFile))
                    del T, NormalizedFlux
                    FluxDiff = FluxA - UnivariateSpline(OmegaB, FluxB, s=0)(OmegaA)
                    DiffFile = self.DifferenceFiles.format(DataType='Flux',
                                                           Quantity1=LastLev[LastLev.rfind("/")+1:],
                                                           Quantity2=NextLev[NextLev.rfind("/")+1:],
                                                           Constant=("N"+str(self.ExtrapolationOrders[i])))
                    sys.stdout.write("and printing {} ... ".format(DiffFile))
                    sys.stdout.flush()
                    DiffFileHandle = open(DiffFile, 'w')
                    DiffFileHandle.write("# [1] = M*omega_hdot(2,-2)\n# [2] = FluxA-FluxB\n# [3] = (FluxA-FluxB)/PNFluxA\n")
                    savetxt(DiffFileHandle, transpose((OmegaA, FluxDiff, FluxDiff/PNFlux)))
                    DiffFileHandle.close()
                    sys.stdout.write("and plotting ... ")
                    sys.stdout.flush()
                    plt.figure('Flux')
                    plt.plot(OmegaA, FluxDiff/PNFlux, label=''.format())
                    print("☺")
                plt.figure('Flux')
                plt.legend(loc=2)
                plt.gca().set_xlim(0, 1)
                plt.gca().set_ylim(0, 2)
                plt.xlabel(r'$M\, \omega_{\dot{h}_{2,-2}}$')
                plt.ylabel(r'$\mathrm{Flux} / \mathrm{Flux}_{\mathrm{pN}}$')
                figarg.savefig('Flux_LevConvergence_{Constant}{Alignment}.pdf'.format(Constant=("N"+str(self.ExtrapolationOrders[i])),
                                                                                      Alignment=AlignmentString))
                plt.close(figflux)
        
        # Do the extrapolation convergence
        for Files in [self.RWZFiles, self.Psi4Files] :
            if( (Files!='') and (self.BestLev!='') ) :
                figmag = plt.figure('Mag')
                figarg = plt.figure('Arg')
                for i in range(1,len(self.ExtrapolationOrders)) :
                    Higher = (self.BestLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                    Lower  = (self.BestLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i-1])
                    sys.stdout.write("Computing {0} - {1} ... ".format(Higher, Lower))
                    sys.stdout.flush()
                    Diff[0] = PyGW.Waveform(Higher, self.WaveformFormat);
                    Diff[1] = PyGW.Waveform(Lower, self.WaveformFormat);
                    if( (self.ConvergenceAlignmentT1!=3.0e300) and (self.ConvergenceAlignmentT2!=3.0e300) ) :
                        if(self.MutualAlignmentApproximant!='') :
                            PN = PyGW.Waveform(self.MutualAlignmentApproximant, self.delta, self.chis, self.chia, self.v0, Diff[0].LM());
                            PN.AddToTime(Diff[0].Peak22Time()-PN.T().back());
                            PN.AlignTo(Diff[0], self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                            Diff[1].AlignTo(PN, self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                        else :
                            Diff[1].AlignTo(Diff[0], self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                    Diff.AlignPhases();
                    DiffFile = self.DifferenceFiles.format(DataType=Diff[0].Type(),
                                                           Quantity1=("N"+str(self.ExtrapolationOrders[i])),
                                                           Quantity2=("N"+str(self.ExtrapolationOrders[i-1])),
                                                           Constant=self.BestLev[self.BestLev.rfind("/")+1:])
                    sys.stdout.write("and printing {0} ... ".format(DiffFile))
                    sys.stdout.flush()
                    Diff[0] = Diff[0]/Diff[1];
                    Diff[1].NSamplesPerCycle22(self.OutputNSamplesPerCycle22);
                    if(self.OutputNSamplesPerCycle22!=0) : Diff[0].Interpolate(Diff[1]);
                    if(self.DropBeforeTime!=-3.0e300) : Diff[0].DropBefore(self.DropBeforeTime);
                    if(self.DropAfterTime!=3.0e300) : Diff[0].DropAfter(self.DropAfterTime);
                    PyGW.Output(DiffFile, Diff[0])
                    sys.stdout.write("and plotting ... ")
                    sys.stdout.flush()
                    plt.figure('Mag')
                    Diff[0].plot('LogMag', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                    plt.figure('Arg')
                    Diff[0].plot('LogArg', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                    print("☺")
                plt.figure('Mag')
                plt.legend(loc=2)
                plt.gca().set_ylim(1e-8, 10)
                if(MaxFluxTime!=3.0e300) :
                    plt.gca().axvline(x=MaxFluxTime, ls='--')
                figmag.savefig('{DataType}_ExtrapConvergence_{Constant}_Mag{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                   Constant=self.BestLev[self.BestLev.rfind("/")+1:],
                                                                                                   Alignment=AlignmentString))
                plt.close(figmag)
                plt.figure('Arg')
                plt.legend(loc=2)
                plt.gca().set_ylim(1e-8, 10)
                if(MaxFluxTime!=3.0e300) :
                    plt.gca().axvline(x=MaxFluxTime, ls='--')
                figarg.savefig('{DataType}_ExtrapConvergence_{Constant}_Arg{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                   Constant=self.BestLev[self.BestLev.rfind("/")+1:],
                                                                                                   Alignment=AlignmentString))
                plt.close(figarg)
        



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
