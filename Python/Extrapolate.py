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
            raise InputError("Not enough data sets ({0}) for max extrapolation order (N={1}).".format(len(Radii), max(ExtrapolationOrders)))
        if(-len(Radii)>min(ExtrapolationOrders)) :
            raise InputError("Not enough data sets ({0}) for min extrapolation order (N={1}).".format(len(Radii), min(ExtrapolationOrders)))
        
        # Read in the Waveforms and set things up nicely
        Ws = PyGW.Waveforms(npy.array([float(s) for s in Radii]), InputDirectory+DataFile, InputDirectory+AreaFile, InputDirectory+LapseFile, ADMMass, ChMass, False);
        Ws.SetCommonTime();
        Ws.FixNonOscillatingData();
        
        # Loop over all the ExtrapolationOrders, doing the dirty business
        Last = PyGW.Waveform()
        for i in range(len(ExtrapolationOrders)) :
            print("Extrapolating with order N={}.".format(ExtrapolationOrders[i]))
            
            # Extrapolate
            Time1 = time()
            Extrap = Ws.Extrapolate(ExtrapolationOrders[i]);
            Time2 = time()
            Extrap.UnfixNonOscillatingData();
            
            # Output the data
            print("Finished N={0} in {1} seconds.".format(ExtrapolationOrders[i], Time2-Time1))
            ExtrapolatedFile = "{0}_{1}".format(Extrap.Type(), ExtrapolatedFiles) % ExtrapolationOrders[i]
            sys.stdout.write("Writing {}... ".format(OutputDirectory+"/"+ExtrapolatedFile))
            sys.stdout.flush()
            if not os.path.exists(OutputDirectory) :
                os.makedirs(OutputDirectory)
            PyGW.Output(OutputDirectory+"/"+ExtrapolatedFile, Extrap)
            print("☺")
            
            # Compare to the last one
            if(i>0) :
                Diff = Extrap/Last;
                DifferenceFile = (Extrap.Type() + "_" + DifferenceFiles) % (ExtrapolationOrders[i], ExtrapolationOrders[i-1])
                sys.stdout.write("Writing {}... ".format(OutputDirectory+"/"+DifferenceFile))
                sys.stdout.flush()
                PyGW.Output(OutputDirectory+"/"+DifferenceFile, Diff)
                print("☺")
                import PyGW.plot
                import matplotlib.pyplot as plt
                fig = plt.figure()
                Diff.plot('LogMag', Modes=[[2,2]])
                fig.legend()
                fig.savefig('{0}/ExtrapConvergence_Mag_N{1}-N{2}.pdf'.format(OutputDirectory, ExtrapolationOrders[i], ExtrapolationOrders[i-1]))
                plt.close(fig)
                fig = plt.figure()
                Diff.plot('LogArg', Modes=[[2,2]])
                fig.legend()
                fig.savefig(OutputDirectory+'/ExtrapConvergence_Arg.pdf')
                plt.close(fig)
            
            # Save this one for the convergence plots
            Last.swap(Extrap);
            

if __name__ == "__main__":
    import sys
    if(len(sys.argv)>1) :
        import os
        OriginalDir = os.getcwd()
        for filename in sys.argv[1:] :
            os.chdir(os.path.dirname(filename))
            Extrapolate(filename)
            os.chdir(OriginalDir)
    else :
        Extrapolate()
