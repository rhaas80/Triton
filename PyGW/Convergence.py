#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Measure convergence for a series of Cauchy resolutions, and optionally
for a series of extrapolation orders.

"""

## We use a class just to be able to set the parameters nicely.  This
## should be treated basically like a function.
class Convergence :
    """
    Class to evaluate convergence of numerical waveforms.
    
    Construct this object to read Waveform data from various files,
    corresponding to different Levs and/or extrapolation orders.
    Various options are available for aligning the waveforms.  (This
    feature in particular makes this script useful for evaluating
    convergence with extrapolation order, whereas the extrapolation
    itself does no alignment when calculating convergence.)
    
    Options	 	        Defaults
    =================================================================
    OutputDirectory	 "./"
        This directory will be made if it does not exist.
    
    LevList                     ['../Lev4', '../Lev5', '../Lev6']
        List of strings corresponding to (relative or absolute) path
        names for directories containing the waveform data.
    
    BestLev                     LevList[-1]
        This should be a string (probably from the list above)
        corresponding to the best Lev, for which convergence of the
        extrapolation will be calculated.  If this is the empty
        string, that step will be skipped.
    
    RWZFiles                    'rhOverM_ExtrapolatedN{ExtrapOrder}.dat'
    Psi4Files                   ''
    FluxFiles                   ''
        Python-formatted file names for the data sets.  Note that
        '{ExtrapOrder}' should NOT be removed or replaced; it is
        automatically converted into the number of the relevant
        extrapolation order.
    
    WaveformFormat              'MagArg'
        A string containing the waveform's format, which can be either
        'MagArg' or 'ReIm'.
    
    ExtrapolationOrders         [-1, 5]
        List of extrapolation orders to be compared for convergence of
        the Levs.  That is, each of these numbers is held fixed, and
        the Levs are compared.
    
    BestExtrapolationh          self.BestLev+'/'+(self.RWZFiles.format(ExtrapOrder=self.ExtrapolationOrders[0]))
        If this is non-empty, this file will be read, and the flux
        will be measured as a function of time.  The corresponding
        time will be marked on the output plots.
    
    ConvergenceAlignmentT1      3.0e300
    ConvergenceAlignmentT2      3.0e300
        If these numbers do not have their default values, they will
        be used as the time windows over which the waveforms should be
        aligned.
    
    MutualAlignmentApproximant  ''
    delta                       0.0
    chis                        0.0
    chia                        0.0
    v0                          0.144
        If these parameters are given, a PN waveform will be
        constructed with the given parameters and aligned to the first
        waveform.  The second waveform will then be alligned to this
        shifted PN waveform.
    
    DifferenceFiles             '{DataType}_{Quantity1}-{Quantity2}_{Constant}'+AlignmentString+'.dat'
        Python-formatted string naming the output difference files.
        For python, things between curly braces '{}' are replaced with
        named arguments given below.  The named arguments are:
        'DataType' as the waveform's type (such as 'rhOverM');
        'Quantity1' and 'Quantity2' are the last distinct elements of
        the input paths; 'Constant' is the quantity held constant in
        the two cases, such as extrapolation order or Lev.
    
    OutputNSamplesPerCycle22    0
        Output data at roughly a certain number of samples per cycle
        of the 2,2 mode, rather than at (roughly) the input times.
        This helps reduce ridiculous file sizes, and improve the speed
        of PDF files.  But high-frequency features may be lost.  If
        this is 0, all input samples will be output.
    
    DropBeforeTime              -3.0e300
        Drop data before this time.  (Might correspond to a
        junk-radiation time, for example.)
    
    DropAfterTime               3.0e300
        Drop data after this time.
    
    """
    
    def SetParameter(self, VariableName, DefaultValue) :
        if VariableName in self.ParameterDictionary :
            setattr(self, VariableName, self.ParameterDictionary[VariableName])
        else :
            setattr(self, VariableName, DefaultValue)
    
    def __init__ (self, Dictionary={}, FileName="") :
        import PyGW
        import PyGW.plot
        import sys
        import os
        import matplotlib.pyplot as plt
        import matplotlib as mpl
        mpl.rcParams['axes.color_cycle'] = ['#000000', '#cc79a7', '#d55e00', '#0072b2', '#f0e442', '#56b4e9', '#e69f00', '#2b9f78']
        
        self.ParameterDictionary=Dictionary
        
        # Set up the parameters, using default values or the value
        # stored in the Dictionary.
        self.SetParameter('OutputDirectory', "./")
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
        self.SetParameter('MutualAlignmentApproximant', '')
        self.SetParameter('delta', 0.0)
        self.SetParameter('chis', 0.0)
        self.SetParameter('chia', 0.0)
        self.SetParameter('v0', 0.144)
        AlignmentString = ''
        if(self.ConvergenceAlignmentT1!=3.0e300 and self.ConvergenceAlignmentT2!=3.0e300) :
            AlignmentString = '_Aligned{2}_{0}--{1}'.format(self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2, self.MutualAlignmentApproximant)
        self.SetParameter('DifferenceFiles', '{DataType}_{Quantity1}-{Quantity2}_{Constant}'+AlignmentString+'.dat')
        self.SetParameter('OutputNSamplesPerCycle22', 0)
        self.SetParameter('DropBeforeTime', -3.0e300)
        self.SetParameter('DropAfterTime', 3.0e300)
        
        # If there's an input file, read it in, which may reset some
        # of the above values.
        if(FileName!="") :
            execfile(FileName)
        
        # If output directory name is empty string, assume it is "./"
        if(not self.OutputDirectory) : self.OutputDirectory = "./"
        
        # Try to make the output directory
        if not os.path.exists(self.OutputDirectory) :
            os.makedirs(self.OutputDirectory)
        
        # If we can, find the max flux time
        MaxFluxTime=3.0e300;
        if(self.BestExtrapolationh!='') :
            if(self.BestExtrapolationh.endswith('.h5')) :
                FluxW = PyGW.ReadFromNRAR(self.BestExtrapolationh)
            else :
                FluxW = PyGW.Waveform(self.BestExtrapolationh, self.WaveformFormat)
            #FluxW.Differentiate()
            FluxW.DropBefore(200)
            MaxFluxTime = FluxW.PeakFluxTime()
            print("MaxFluxTime={0}".format(MaxFluxTime))
        
        # Do the Lev convergence
        # Diff0 = PyGW.Waveform()
        # Diff1 = PyGW.Waveform()
        Diff = PyGW.Waveforms(2)
        for Files in [self.RWZFiles, self.Psi4Files] :
            if(Files!='') :
                for i in range(len(self.ExtrapolationOrders)) :
                    figmag = plt.figure(0)
                    figarg = plt.figure(1)
                    for iLev in range(1,len(self.LevList)) :
                        LastLev = self.LevList[iLev-1]
                        NextLev = self.LevList[iLev]
                        LastFile = (LastLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                        NextFile = (NextLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                        if(LastFile==NextFile) :
                            raise(ValueError("LastFile=NextFile='{0}'.  These should be different.  "
                                             "A python format string is probably missing from 'RWZFiles'={1} "
                                             "or 'Psi4Files'".format(LastFile, self.RWZFiles, self.Psi4Files)))
                        sys.stdout.write("Computing {0} - {1} ... ".format(LastFile, NextFile))
                        sys.stdout.flush()
                        if(LastFile.endswith('.h5')) :
                            Diff[0] = PyGW.ReadFromNRAR(LastFile)
                        else :
                            Diff[0] = PyGW.Waveform(LastFile, self.WaveformFormat);
                        if(NextFile.endswith('.h5')) :
                            Diff[1] = PyGW.ReadFromNRAR(NextFile)
                        else :
                            Diff[1] = PyGW.Waveform(NextFile, self.WaveformFormat);
                        if(self.ConvergenceAlignmentT1!=3.0e300 and self.ConvergenceAlignmentT2!=3.0e300) :
                            if(self.MutualAlignmentApproximant!='') :
                                PN = PyGW.Waveform(self.MutualAlignmentApproximant, self.delta, self.chis, self.chia, self.v0,
                                                   tuple(tuple(x) for x in Diff[0].LM()));
                                PN.AddToTime(Diff[0].Peak22Time()-PN.T(PN.NTimes()-1));
                                PN.AlignTo(Diff[0], self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                                Diff[1].AlignTo(PN, self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                            else :
                                Diff[1].AlignTo(Diff[0], self.ConvergenceAlignmentT1, self.ConvergenceAlignmentT2);
                        Diff.AlignPhases();
                        Index1 = LastLev.rfind("/")
                        Index2 = NextLev.rfind("/")
                        Quantity1 = LastLev[Index1+1:]
                        Quantity2 = NextLev[Index2+1:]
                        while(Quantity1==Quantity2) :
                            Index1Old = Index1
                            Index2Old = Index2
                            Index1 = LastLev[:Index1].rfind("/")
                            Index2 = NextLev[:Index2].rfind("/")
                            Quantity1 = LastLev[Index1+1:Index1Old]
                            Quantity2 = NextLev[Index2+1:Index2Old]
                            if(Index1==-1 or Index2==-1) : break
                        DiffFile = self.DifferenceFiles.format(DataType=Diff[0].Type(),
                                                               Quantity1=Quantity1,
                                                               Quantity2=Quantity2,
                                                               Constant=("N"+str(self.ExtrapolationOrders[i])))
                        sys.stdout.write("\n\tand printing {0} ... ".format(self.OutputDirectory+"/"+DiffFile))
                        sys.stdout.flush()
                        Diff[0] = Diff[0]/Diff[1];
                        Diff[1].NSamplesPerCycle22(self.OutputNSamplesPerCycle22);
                        if(self.OutputNSamplesPerCycle22!=0) : Diff[0].Interpolate(Diff[1]);
                        if(self.DropBeforeTime!=-3.0e300) : Diff[0].DropBefore(self.DropBeforeTime);
                        if(self.DropAfterTime!=3.0e300) : Diff[0].DropAfter(self.DropAfterTime);
                        PyGW.Output(self.OutputDirectory+"/"+DiffFile, Diff[0]);
                        sys.stdout.write("\n\tand plotting ... ")
                        sys.stdout.flush()
                        plt.figure(0)
                        Diff[0].plot('LogMag', Modes=[[2,2]], label=r'({0})$ - $({1})'.format(LastLev, NextLev))
                        plt.figure(1)
                        Diff[0].plot('LogArg', Modes=[[2,2]], label=r'({0})$ - $({1})'.format(LastLev, NextLev))
                        print("☺")
                    
                    plt.figure(0)
                    plt.legend(loc=2)
                    plt.gca().set_ylim(1e-8, 100)
                    if(MaxFluxTime!=3.0e300) :
                        plt.gca().axvline(x=MaxFluxTime, ls='--')
                    figmag.savefig(self.OutputDirectory+"/"+'{DataType}_LevConvergence_{Constant}_Mag{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                                        Constant=("N"+str(self.ExtrapolationOrders[i])),
                                                                                                                        Alignment=AlignmentString))
                    plt.close(figmag)
                    plt.figure(1)
                    plt.legend(loc=2)
                    plt.gca().set_ylim(1e-8, 100)
                    if(MaxFluxTime!=3.0e300) :
                        plt.gca().axvline(x=MaxFluxTime, ls='--')
                    figarg.savefig(self.OutputDirectory+"/"+'{DataType}_LevConvergence_{Constant}_Arg{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                                        Constant=("N"+str(self.ExtrapolationOrders[i])),
                                                                                                                        Alignment=AlignmentString))
                    plt.close(figarg)
        
        if(self.FluxFiles!='') :
            from scipy.interpolate import UnivariateSpline
            from numpy import genfromtxt, savetxt
            for i in range(len(self.ExtrapolationOrders)) :
                figflux = plt.figure(2)
                for iLev in range(1,len(self.LevList)) :
                    LastLev = self.LevList[iLev-1]
                    NextLev = self.LevList[iLev]
                    LastFile = (LastLev + "/" + self.FluxFiles).format(ExtrapOrder=self.ExtrapolationOrders[i])
                    NextFile = (NextLev + "/" + self.FluxFiles).format(ExtrapOrder=self.ExtrapolationOrders[i])
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
                    sys.stdout.write("\n\tand printing {0} ... ".format(self.OutputDirectory+"/"+DiffFile))
                    sys.stdout.flush()
                    DiffFileHandle = open(self.OutputDirectory+"/"+DiffFile, 'w')
                    DiffFileHandle.write("# [1] = M*omega_hdot(2,-2)\n# [2] = FluxA-FluxB\n# [3] = (FluxA-FluxB)/PNFluxA\n")
                    savetxt(DiffFileHandle, transpose((OmegaA, FluxDiff, FluxDiff/PNFlux)))
                    DiffFileHandle.close()
                    sys.stdout.write("\n\tand plotting ... ")
                    sys.stdout.flush()
                    plt.figure(2)
                    plt.plot(OmegaA, FluxDiff/PNFlux, label='({0})$ - $({1})'.format(LastLev[LastLev.rfind("/")+1:], NextLev[NextLev.rfind("/")+1:]))
                    print("☺")
                plt.figure(2)
                plt.legend(loc=2)
                plt.gca().set_xlim(0, 1)
                plt.gca().set_ylim(0, 2)
                plt.xlabel(r'$M\, \omega_{\dot{h}_{2,-2}}$')
                plt.ylabel(r'$\mathrm{Flux} / \mathrm{Flux}_{\mathrm{pN}}$')
                figarg.savefig(self.OutputDirectory+"/"+'Flux_LevConvergence_{Constant}{Alignment}.pdf'.format(Constant=("N"+str(self.ExtrapolationOrders[i])),
                                                                                                          Alignment=AlignmentString))
                plt.close(figflux)
        
        # Do the extrapolation convergence
        for Files in [self.RWZFiles, self.Psi4Files] :
            if( (Files!='') and (self.BestLev!='') ) :
                figmag = plt.figure(0)
                figarg = plt.figure(1)
                for i in range(1,len(self.ExtrapolationOrders)) :
                    Higher = (self.BestLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i])
                    Lower  = (self.BestLev + "/" + Files).format(ExtrapOrder=self.ExtrapolationOrders[i-1])
                    if(Higher==Lower) :
                        raise(ValueError("Higher=Lower='{0}'.  These should be different.  "
                                         "A python format string is probably missing from 'RWZFiles'={1} "
                                         "or 'Psi4Files'={2}".format(LastFile, self.RWZFiles, self.Psi4Files)))
                    sys.stdout.write("Computing {0} - {1} ... ".format(Higher, Lower))
                    sys.stdout.flush()
                    if(Higher.endswith('.h5')) :
                        Diff[0] = PyGW.ReadFromNRAR(Higher)
                    else :
                        Diff[0] = PyGW.Waveform(Higher, self.WaveformFormat);
                    if(Lower.endswith('.h5')) :
                        Diff[1] = PyGW.ReadFromNRAR(Lower)
                    else :
                        Diff[1] = PyGW.Waveform(Lower, self.WaveformFormat);
                    if( (self.ConvergenceAlignmentT1!=3.0e300) and (self.ConvergenceAlignmentT2!=3.0e300) ) :
                        if(self.MutualAlignmentApproximant!='') :
                            PN = PyGW.Waveform(self.MutualAlignmentApproximant, self.delta, self.chis, self.chia, self.v0,
                                               tuple(tuple(x) for x in Diff[0].LM()));
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
                    sys.stdout.write("\n\tand printing {0} ... ".format(self.OutputDirectory+"/"+DiffFile))
                    sys.stdout.flush()
                    Diff[0] = Diff[0]/Diff[1];
                    Diff[1].NSamplesPerCycle22(self.OutputNSamplesPerCycle22);
                    if(self.OutputNSamplesPerCycle22!=0) : Diff[0].Interpolate(Diff[1]);
                    if(self.DropBeforeTime!=-3.0e300) : Diff[0].DropBefore(self.DropBeforeTime);
                    if(self.DropAfterTime!=3.0e300) : Diff[0].DropAfter(self.DropAfterTime);
                    PyGW.Output(self.OutputDirectory+"/"+DiffFile, Diff[0])
                    sys.stdout.write("\n\tand plotting ... ")
                    sys.stdout.flush()
                    plt.figure(0)
                    Diff[0].plot('LogMag', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                    plt.figure(1)
                    Diff[0].plot('LogArg', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                    print("☺")
                plt.figure(0)
                plt.legend(loc=2)
                plt.gca().set_ylim(1e-8, 10)
                if(MaxFluxTime!=3.0e300) :
                    plt.gca().axvline(x=MaxFluxTime, ls='--')
                figmag.savefig(self.OutputDirectory+"/"+'{DataType}_ExtrapConvergence_{Constant}_Mag{Alignment}.pdf'.format(DataType=Diff[0].Type(),
                                                                                                                       Constant=self.BestLev[self.BestLev.rfind("/")+1:],
                                                                                                                       Alignment=AlignmentString))
                plt.close(figmag)
                plt.figure(1)
                plt.legend(loc=2)
                plt.gca().set_ylim(1e-8, 100)
                if(MaxFluxTime!=3.0e300) :
                    plt.gca().axvline(x=MaxFluxTime, ls='--')
                figarg.savefig(self.OutputDirectory+"/"+'{DataType}_ExtrapConvergence_{Constant}_Arg{Alignment}.pdf'.format(DataType=Diff[0].Type(),
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
            Convergence(FileName=os.path.basename(filename))
            os.chdir(OriginalDir)
    else :
        Convergence()
