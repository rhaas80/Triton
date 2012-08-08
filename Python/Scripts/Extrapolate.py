#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Extrapolate a series of waveforms from a set of dat files.

"""

## We use a class just to be able to set the parameters nicely.  This
## should be treated basically like a function.
class Extrapolate :
    def SetParameter(self, VariableName, DefaultValue) :
        if VariableName in self.ParameterDictionary :
            setattr(self, VariableName, self.ParameterDictionary[VariableName])
        else :
            setattr(self, VariableName, DefaultValue)
    
    def __init__ (self, FileName="", Dictionary={}) :
        import PyGW
        import PyGW.plot
        import numpy as npy
        import matplotlib.pyplot as plt
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
        self.SetParameter('DataFiles', ["rh_R%04.0fm.dat", "rPsi4_R%04.0fm_U8+.dat"])
        self.SetParameter('AreaFile', "SurfaceArea_R%04.0fm.dat")
        self.SetParameter('LapseFile', "LapseSurfaceIntegral_R%04.0fm.dat")
        self.SetParameter('ADMMass', 1.0)
        self.SetParameter('ChMass', 1.0)
        self.SetParameter('ExtrapolatedFiles', "ExtrapolatedN%d.dat")
        self.SetParameter('DifferenceFiles', "ExtrapConvergence_N%d-N%d.dat")
        self.SetParameter('SigmaFiles', "SigmaN%d.dat")
        self.SetParameter('UseSVD', True)
        self.SetParameter('UseOmegas', True)
        
        # If there's an input file, read it in
        if(FileName!="") :
            execfile(FileName)
        
        # For some compatibility with old input files
        try :
            DataFile
        except NameError :
            pass # We expect it to be undefined, so that's fine
        else :
            self.DataFiles = [DataFile]
        
        # Do the extrapolation, looping over the different types of data in DataFiles
        MaxFluxTime = -1000.0;
        for DataFile in self.DataFiles :
            # If the list of radii is empty, try to find the files
            if(self.Radii==[]) :
                import commands
                FilePrefix = DataFile.split('_')[0]
                GetRadiiCommand = r"""ls {0}/{1}_* 2> /dev/null""".format(self.InputDirectory, FilePrefix)
                self.Radii = commands.getoutput(GetRadiiCommand).split('\n')
                self.Radii = [r.replace(r"""{0}/{1}_R""".format(self.InputDirectory, FilePrefix),'').replace('m.dat','') for r in self.Radii]
                if(self.Radii==[]) : # If there are no such files, just issue an error and exit
                    raise IOError("Could not find any files starting with '{0}_' in {1}.".format(FilePrefix, self.InputDirectory))
            
            # Make sure there are enough radii to do the requested extrapolations
            if((len(self.Radii) <= max(self.ExtrapolationOrders)) and (max(self.ExtrapolationOrders)>-1)) :
                raise ValueError("Not enough data sets ({0}) for max extrapolation order (N={1}).".format(len(self.Radii), max(self.ExtrapolationOrders)))
            if(-len(self.Radii)>min(self.ExtrapolationOrders)) :
                raise ValueError("Not enough data sets ({0}) for min extrapolation order (N={1}).".format(len(self.Radii), min(self.ExtrapolationOrders)))
            
            # Read in the Waveforms and set things up nicely
            Ws = PyGW.Waveforms(npy.array([float(s) for s in self.Radii]),
                                self.InputDirectory+DataFile, self.InputDirectory+self.AreaFile, self.InputDirectory+self.LapseFile,
                                self.ADMMass, self.ChMass, False);
            Ws.SetCommonTime();
            Ws.FixNonOscillatingData();
            
            # Loop over all the ExtrapolationOrders, doing the dirty business
            import PyGW.plot
            import matplotlib.pyplot as plt
            Last = PyGW.Waveform()
            figmag = plt.figure('Mag')
            figarg = plt.figure('Arg')
            WFType = ''
            for i in range(len(self.ExtrapolationOrders)) :
                print("Extrapolating with order N={}.".format(self.ExtrapolationOrders[i]))
                
                # Extrapolate
                Time1 = time()
                Sigma = PyGW.Waveform()
                if(UseOmegas) :
                    Extrap = Ws.Extrapolate(Sigma, Ws[0].T(), -0.5*Ws[0].Omega2m2(), self.ExtrapolationOrders[i], self.UseSVD);
                else :
                    Extrap = Ws.Extrapolate(Sigma, self.ExtrapolationOrders[i], self.UseSVD);
                Time2 = time()
                Extrap.UnfixNonOscillatingData();
                
                # Output the data
                print("Finished N={0} in {1} seconds.".format(self.ExtrapolationOrders[i], Time2-Time1))
                ExtrapolatedFile = "{0}_{1}".format(Extrap.Type(), self.ExtrapolatedFiles) % self.ExtrapolationOrders[i]
                SigmaFile = "{0}_{1}".format(Extrap.Type(), self.SigmaFiles) % self.ExtrapolationOrders[i]
                sys.stdout.write("Writing {}... ".format(self.OutputDirectory+"/"+ExtrapolatedFile))
                sys.stdout.flush()
                if not os.path.exists(self.OutputDirectory) :
                    os.makedirs(self.OutputDirectory)
                PyGW.Output(self.OutputDirectory+"/"+ExtrapolatedFile, Extrap)
                if(self.ExtrapolationOrders[i]>=0) :
                    sys.stdout.write("and {}... ".format(self.OutputDirectory+"/"+SigmaFile))
                    sys.stdout.flush()
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
                    sys.stdout.write("Writing {}... ".format(self.OutputDirectory+"/"+DifferenceFile))
                    sys.stdout.flush()
                    PyGW.Output(self.OutputDirectory+"/"+DifferenceFile, Diff)
                    print("☺")
                    sys.stdout.write("Plotting... ")
                    sys.stdout.flush()
                    plt.figure('Mag')
                    Diff.plot('LogMag', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                    plt.figure('Arg')
                    Diff.plot('LogArg', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(self.ExtrapolationOrders[i], self.ExtrapolationOrders[i-1]))
                    print("☺")
                
                # Save this one for the convergence plots
                Last.swap(Extrap);
            
            plt.figure('Mag')
            plt.legend(borderpad=.2, labelspacing=0.1, handlelength=1.5, handletextpad=0.1, loc='lower left', prop={'size':'small'})
            plt.gca().set_ylim(1e-11, 10)
            plt.gca().axvline(x=MaxFluxTime, ls='--')
            figmag.savefig('{0}/ExtrapConvergence_Mag_{1}.pdf'.format(self.OutputDirectory, WFType))
            plt.close(figmag)
            plt.figure('Arg')
            plt.legend(borderpad=.2, labelspacing=0.1, handlelength=1.5, handletextpad=0.1, loc='lower left', prop={'size':'small'})
            plt.gca().set_ylim(1e-11, 10)
            plt.gca().axvline(x=MaxFluxTime, ls='--')
            figarg.savefig('{0}/ExtrapConvergence_Arg_{1}.pdf'.format(self.OutputDirectory, WFType))
            plt.close(figarg)


if __name__ == "__main__":
    import sys
    if(len(sys.argv)>1) :
        import os
        OriginalDir = os.getcwd()
        for filename in sys.argv[1:] :
            os.chdir(os.path.dirname(filename))
            Extrapolate(os.path.basename(filename))
            os.chdir(OriginalDir)
    else :
        Extrapolate()
