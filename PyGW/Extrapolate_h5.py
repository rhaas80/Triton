#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Extrapolate a series of waveforms from a single h5 file.

This file contains a class to do the extrapolation.  For details, see
the help text of the Extrapolate class.

"""

## We use a class just to be able to set the parameters nicely.  This
## should be treated basically like a function.
class Extrapolate :
    """
    Class used to set options and do extrapolation from a single h5 file.
    
    Construct this object to read Waveform data, lapse, and surface
    area data for a series of radii, and extrapolate to infinite
    radius.
    
    Options	 	 Defaults
    =================================================================
    Radii	 	 []
        List of strings containing the radii to use.  If none are
        input, all data files that can be found are used.
    
    ExtrapolationOrders	 [-1, 2, 3, 4, 5, 6, 7, 8]
        Negative numbers correspond to extracted data, counting 
        down from the outermost extraction radius (which is -1).
    
    InputDirectory	 "./"
        Where to find the input data.  Can be relative or absolute.
    
    OutputDirectory	 "./"
        This directory will be made if it does not exist.
    
    DataFiles	 	 ["rh_FiniteRadii_CodeUnits.h5"]
        These are sprintf-formatted file names, where each of Radii
        are converted to doubles and substituted into these strings.
        These are the input data required for extrapolation.
    
    ChMass	 	 1.0
        This is assumed to be in the same units as the rest of the
        input data.
    
    ExtrapolatedFiles	 "ExtrapolatedN%d.dat"
    DifferenceFiles	 "ExtrapConvergence_N%d-N%d.dat"
    SigmaFiles	 	 "SigmaN%d.dat"
        These are sprintf-formatted output file names, where the
        extrapolation order is substituted into these strings.
    
    UseSVD	 	 True
        Use SVD to do the fitting.  This should generally be true, and
        is here to support comparisons with old results.
    
    UseOmegas	 	 True
        Whether or not to extrapolate as a function of lambda/r =
        1/r*omega, where lambda is the instantaneous wavelength.  If
        this is True, the extrapolation will usually not converge for
        high N; if this is False, SVD will generally cause the
        convergence to appear to fall to roundoff, though the accuracy
        presumably is not so great.
    
    PlotFormat 	 	 'png'
        The format of output plots.  This can be the empty string, in
        which case no plotting is done.  Or, these can be any of the
        formats supported by your installation of matplotlib.
    
    MinTimeStep          0.005
        The smallest allowed time step in the output data.
    
    EarliestTime         -3.0e300
        The earliest time in the output data.  For values less than 0,
        some of the data corresponds to times when only junk radiation
        is present.
    
    """
    
    def SetParameter(self, VariableName, DefaultValue) :
        if VariableName in self.ParameterDictionary :
            setattr(self, VariableName, self.ParameterDictionary[VariableName])
        else :
            setattr(self, VariableName, DefaultValue)
    
    def __init__ (self, Dictionary={}, FileName="") :
        import PyGW
        import numpy as npy
        from time import time
        import sys
        import os
        
        self.ParameterDictionary=Dictionary
        
        # Set up the parameters, using default values or the value
        # stored in the Dictionary.
        self.SetParameter('Radii', [])
        self.SetParameter('ExtrapolationOrders', [-1, 2, 3, 4, 5, 6, 7, 8])
        self.SetParameter('InputDirectory', "./")
        self.SetParameter('OutputDirectory', "./")
        self.SetParameter('DataFiles', ["rh_FiniteRadii_CodeUnits.h5"])
        # self.SetParameter('ADMMass', 1.0)
        self.SetParameter('ChMass', 1.0)
        self.SetParameter('ExtrapolatedFiles', "ExtrapolatedN%d.dat")
        self.SetParameter('DifferenceFiles', "ExtrapConvergence_N%d-N%d.dat")
        self.SetParameter('SigmaFiles', "SigmaN%d.dat")
        self.SetParameter('UseSVD', True)
        self.SetParameter('UseOmegas', True)
        self.SetParameter('PlotFormat', 'png')
        self.SetParameter('MinTimeStep', 0.005)
        self.SetParameter('EarliestTime', -3.0e300)
        
        # If there's an input file, read it in
        if(FileName!="") :
            execfile(FileName)
        
        # Don't bother loading modules unless we're plotting
        if(self.PlotFormat) :
            import PyGW.plot
            import matplotlib.pyplot as plt
        
        # For some compatibility with old input files
        try :
            DataFile
        except NameError :
            pass # We expect it to be undefined, so that's fine
        else :
            self.DataFiles = [DataFile]
        
        # If directory names are empty strings, assume they are "./"
        if(not self.InputDirectory)  : self.InputDirectory  = "./"
        if(not self.OutputDirectory) : self.OutputDirectory = "./"
        
        # Do the extrapolation, looping over the different types of data in DataFiles
        MaxFluxTime = -1000.0;
        for DataFile in self.DataFiles :
            # Read in the Waveforms and set things up nicely
            Ws,self.ADMMass,self.Radii = PyGW.ReadFiniteRadiusData(self.ChMass, self.InputDirectory, DataFile, self.Radii)
            Ws.SetCommonTime(self.MinTimeStep, self.EarliestTime);
            Ws.FixNonOscillatingData();
            
            # Make sure there are enough radii to do the requested extrapolations
            if((len(self.Radii) <= max(self.ExtrapolationOrders)) and (max(self.ExtrapolationOrders)>-1)) :
                raise ValueError("Not enough data sets ({0}) for max extrapolation order (N={1}).".format(len(self.Radii), max(self.ExtrapolationOrders)))
            if(-len(self.Radii)>min(self.ExtrapolationOrders)) :
                raise ValueError("Not enough data sets ({0}) for min extrapolation order (N={1}).".format(len(self.Radii), min(self.ExtrapolationOrders)))
            
            # Loop over all the ExtrapolationOrders, doing the dirty business
            Last = PyGW.Waveform()
            if(self.PlotFormat) :
                figmag = plt.figure(0)
                figarg = plt.figure(1)
            WFType = ''
            for i in range(len(self.ExtrapolationOrders)) :
                print("Extrapolating with order N={0}.".format(self.ExtrapolationOrders[i]))
                
                # Extrapolate
                Time1 = time()
                Sigma = PyGW.Waveform()
                if(self.UseOmegas) :
                    Extrap = Ws.Extrapolate(Sigma, Ws[0].T(), -0.5*Ws[0].Omega2m2(), self.ExtrapolationOrders[i], self.UseSVD);
                else :
                    Extrap = Ws.Extrapolate(Sigma, self.ExtrapolationOrders[i], self.UseSVD);
                Time2 = time()
                Extrap.UnfixNonOscillatingData();
                
                # Output the data
                print("Finished N={0} in {1} seconds.".format(self.ExtrapolationOrders[i], Time2-Time1))
                ExtrapolatedFile = "{0}_{1}".format(Extrap.Type(), self.ExtrapolatedFiles) % self.ExtrapolationOrders[i]
                SigmaFile = "{0}_{1}".format(Extrap.Type(), self.SigmaFiles) % self.ExtrapolationOrders[i]
                sys.stdout.write("Writing {0}... ".format(self.OutputDirectory+"/"+ExtrapolatedFile))
                sys.stdout.flush()
                if not os.path.exists(self.OutputDirectory) :
                    os.makedirs(self.OutputDirectory)
                if (ExtrapolatedFile.endswith('.h5')) :
                    PyGW.OutputToNRAR(self.OutputDirectory+"/"+ExtrapolatedFile, Extrap)
                else :
                    PyGW.Output(self.OutputDirectory+"/"+ExtrapolatedFile, Extrap)
                if(self.ExtrapolationOrders[i]>=0) :
                    sys.stdout.write("and {0}... ".format(self.OutputDirectory+"/"+SigmaFile))
                    sys.stdout.flush()
                    if (SigmaFile.endswith('.h5')) :
                        PyGW.OutputToNRAR(self.OutputDirectory+"/"+SigmaFile, Sigma)
                    else :
                        PyGW.Output(self.OutputDirectory+"/"+SigmaFile, Sigma)
                print("☺")
                
                # Compare to the last one
                if(i==0) :
                    if(not 'Psi4' in Extrap.Type()) :
                        Extrap_hdot = PyGW.Waveform(Extrap)
                        Extrap_hdot.Differentiate()
                        MaxFluxTime = Extrap_hdot.PeakFluxTime()
                        del Extrap_hdot
                    WFType = Extrap.Type()
                else :
                    Diff = Extrap/Last;
                    DifferenceFile = (Extrap.Type() + "_" + self.DifferenceFiles) % (self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1])
                    sys.stdout.write("Writing {0}... ".format(self.OutputDirectory+"/"+DifferenceFile))
                    sys.stdout.flush()
                    if (DifferenceFile.endswith('.h5')) :
                        PyGW.OutputToNRAR(self.OutputDirectory+"/"+DifferenceFile, Diff)
                    else :
                        PyGW.Output(self.OutputDirectory+"/"+DifferenceFile, Diff)
                    print("☺")
                    if(self.PlotFormat) :
                        sys.stdout.write("Plotting... ")
                        sys.stdout.flush()
                        plt.figure(0)
                        Diff.plot('LogMag', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                        plt.figure(1)
                        Diff.plot('LogArg', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                        print("☺")
                
                # Save this one for the convergence plots
                Last.swap(Extrap)
            
            if(self.PlotFormat) :
                plt.figure(0)
                plt.legend(borderpad=.2, labelspacing=0.1, handlelength=1.5, handletextpad=0.1, loc='lower left', prop={'size':'small'})
                plt.gca().set_ylim(1e-11, 10)
                plt.gca().axvline(x=MaxFluxTime, ls='--')
                figmag.savefig('{0}/ExtrapConvergence_Mag_{1}.{2}'.format(self.OutputDirectory, WFType, self.PlotFormat))
                plt.close(figmag)
                plt.figure(1)
                plt.legend(borderpad=.2, labelspacing=0.1, handlelength=1.5, handletextpad=0.1, loc='lower left', prop={'size':'small'})
                plt.gca().set_ylim(1e-11, 10)
                plt.gca().axvline(x=MaxFluxTime, ls='--')
                figarg.savefig('{0}/ExtrapConvergence_Arg_{1}.{2}'.format(self.OutputDirectory, WFType, self.PlotFormat))
                plt.close(figarg)


if __name__ == "__main__":
    import sys
    if(len(sys.argv)>1) :
        import os
        OriginalDir = os.getcwd()
        for filename in sys.argv[1:] :
            os.chdir(os.path.dirname(filename))
            Extrapolate(FileName=os.path.basename(filename))
            os.chdir(OriginalDir)
    else :
        Extrapolate()
