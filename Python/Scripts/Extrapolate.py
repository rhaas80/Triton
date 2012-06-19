#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Extrapolate a series of waveforms from a set of dat files.

"""

def Extrapolate(FileName="", Dictionary={}) :
    
    # Set the defaults
    Radii = []
    if 'Radii' in Dictionary :
        Radii = Dictionary['Radii']
    ExtrapolationOrders = [-1, 2, 3, 4, 5, 6, 7, 8]
    if 'ExtrapolationOrders' in Dictionary :
        ExtrapolationOrders = Dictionary['ExtrapolationOrders']
    InputDirectory = "./"
    if 'InputDirectory' in Dictionary :
        InputDirectory = Dictionary['InputDirectory']
    OutputDirectory = "./"
    if 'OutputDirectory' in Dictionary :
        OutputDirectory = Dictionary['OutputDirectory']
    DataFiles = ["rh_R%04.0fm.dat", "rPsi4_R%04.0fm_U8+.dat"]
    if 'DataFiles' in Dictionary :
        DataFiles = Dictionary['DataFiles']
    AreaFile = "SurfaceArea_R%04.0fm.dat"
    if 'AreaFile' in Dictionary :
        AreaFile = Dictionary['AreaFile']
    LapseFile = "LapseSurfaceIntegral_R%04.0fm.dat"
    if 'LapseFile' in Dictionary :
        LapseFile = Dictionary['LapseFile']
    ADMMass = 1.0
    if 'ADMMass' in Dictionary :
        ADMMass = Dictionary['ADMMass']
    ChMass = 1.0
    if 'ChMass' in Dictionary :
        ChMass = Dictionary['ChMass']
    ExtrapolatedFiles = "ExtrapolatedN%d.dat"
    if 'ExtrapolatedFiles' in Dictionary :
        ExtrapolatedFiles = Dictionary['ExtrapolatedFiles']
    DifferenceFiles = "ExtrapConvergence_N%d-N%d.dat"
    if 'DifferenceFiles' in Dictionary :
        DifferenceFiles = Dictionary['DifferenceFiles']
    SigmaFiles = "SigmaN%d.dat"
    if 'SigmaFiles' in Dictionary :
        SigmaFiles = Dictionary['SigmaFiles']
    
    # If there's an input file, read it in
    if(FileName!="") :
        execfile(FileName)
    
    # For some compatibility with old input files
    try :
        DataFile
    except NameError :
        pass # We expect it to be undefined, so that's fine
    else :
        DataFiles = [DataFile]
    
    # Do the extrapolation, looping over the different types of data in DataFiles
    import PyGW
    import numpy as npy
    from time import time
    import sys
    import os
    MaxFluxTime = -1000.0;
    for DataFile in DataFiles :
        # If the list of radii is empty, try to find the files
        if(Radii==[]) :
            import commands
            FilePrefix = DataFile.split('_')[0]
            GetRadiiCommand = r"""ls {0}/{1}_* 2> /dev/null""".format(InputDirectory, FilePrefix)
            Radii = commands.getoutput(GetRadiiCommand).split('\n')
            Radii = [r.replace(r"""{0}/{1}_R""".format(InputDirectory, FilePrefix),'').replace('m.dat','') for r in Radii]
            if(Radii==[]) : # If there are no such files, just issue an error and exit
                raise IOError("Could not find any files starting with '{0}_' in {1}.".format(FilePrefix, InputDirectory))
        
        # Make sure there are enough radii to do the requested extrapolations
        if((len(Radii) <= max(ExtrapolationOrders)) and (max(ExtrapolationOrders)>-1)) :
            raise ValueError("Not enough data sets ({0}) for max extrapolation order (N={1}).".format(len(Radii), max(ExtrapolationOrders)))
        if(-len(Radii)>min(ExtrapolationOrders)) :
            raise ValueError("Not enough data sets ({0}) for min extrapolation order (N={1}).".format(len(Radii), min(ExtrapolationOrders)))
        
        # Read in the Waveforms and set things up nicely
        Ws = PyGW.Waveforms(npy.array([float(s) for s in Radii]), InputDirectory+DataFile, InputDirectory+AreaFile, InputDirectory+LapseFile, ADMMass, ChMass, False);
        Ws.SetCommonTime();
        Ws.FixNonOscillatingData();
        
        # Loop over all the ExtrapolationOrders, doing the dirty business
        import PyGW.plot
        import matplotlib.pyplot as plt
        Last = PyGW.Waveform()
        figmag = plt.figure('Mag')
        figarg = plt.figure('Arg')
        MaxFluxTime = -1000.0;
        WFType = ''
        for i in range(len(ExtrapolationOrders)) :
            print("Extrapolating with order N={}.".format(ExtrapolationOrders[i]))
            
            # Extrapolate
            Time1 = time()
            Sigmas = PyGW.Waveform()
            Extrap = Ws.Extrapolate(Sigmas, ExtrapolationOrders[i]);
            Time2 = time()
            Extrap.UnfixNonOscillatingData();
            
            # Output the data
            print("Finished N={0} in {1} seconds.".format(ExtrapolationOrders[i], Time2-Time1))
            ExtrapolatedFile = "{0}_{1}".format(Extrap.Type(), ExtrapolatedFiles) % ExtrapolationOrders[i]
            SigmaFile = "{0}_{1}".format(Extrap.Type(), SigmaFiles) % ExtrapolationOrders[i]
            sys.stdout.write("Writing {}... ".format(OutputDirectory+"/"+ExtrapolatedFile))
            sys.stdout.flush()
            if not os.path.exists(OutputDirectory) :
                os.makedirs(OutputDirectory)
            PyGW.Output(OutputDirectory+"/"+ExtrapolatedFile, Extrap)
            sys.stdout.write("and {}... ".format(OutputDirectory+"/"+SigmaFile))
            sys.stdout.flush()
            PyGW.Output(OutputDirectory+"/"+SigmaFile, Extrap)
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
                DifferenceFile = (Extrap.Type() + "_" + DifferenceFiles) % (ExtrapolationOrders[i], ExtrapolationOrders[i-1])
                sys.stdout.write("Writing {}... ".format(OutputDirectory+"/"+DifferenceFile))
                sys.stdout.flush()
                PyGW.Output(OutputDirectory+"/"+DifferenceFile, Diff)
                print("☺")
                sys.stdout.write("Plotting... ")
                sys.stdout.flush()
                plt.figure('Mag')
                Diff.plot('LogMag', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(ExtrapolationOrders[i], ExtrapolationOrders[i-1]))
                plt.figure('Arg')
                Diff.plot('LogArg', Modes=[[2,2]], label=r'$(N={0}) - (N={1})$'.format(ExtrapolationOrders[i], ExtrapolationOrders[i-1]))
                print("☺")
            
            # Save this one for the convergence plots
            Last.swap(Extrap);
        
        plt.figure('Mag')
        plt.legend(loc=2)
        plt.gca().set_ylim(1e-8, 10)
        plt.gca().axvline(x=MaxFluxTime, ls='--')
        figmag.savefig('{0}/ExtrapConvergence_Mag_{1}.pdf'.format(OutputDirectory, WFType))
        plt.close(figmag)
        plt.figure('Arg')
        plt.legend(loc=2)
        plt.gca().set_ylim(1e-8, 10)
        plt.gca().axvline(x=MaxFluxTime, ls='--')
        figarg.savefig('{0}/ExtrapConvergence_Arg_{1}.pdf'.format(OutputDirectory, WFType))
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
