
#This script has the process of creating hybrid NSNS waveforms
#then determining their overlap.

ScriptsDir = "/home/rhaas/data/postdoc/gr/Triton/Scripts" #"/mnt/data/rhaas/postdoc/gr/Triton/Scripts"
DataDir = "." #"/mnt/data/rhaas/postdoc/papers/NsNsInspirals/data"
NoiseDir = "." #"/mnt/data/rhaas/postdoc/gr/noise"
#Zwicky = "/home/rhaas/mnt/zwicky/"

import sys
import os
sys.path.append(ScriptsDir)
sys.path.append(ScriptsDir+"/../Numpy/build/lib.linux-x86_64-2.7")
from OverlapUtils import *
import ompsum
from PyWaveform import *
import copy
import numpy as np
import PyGW_IS_FOR_OLD_DATA as PyGW
#import PyGW.plot
import matplotlib
import matplotlib.pyplot as plt
import math
import time

import inspect
#import cProfile
#pr = cProfile.Profile()
#pr.enable()

use_PyWaveform = True

def lineno():
    """Returns the current line number in our program."""
    return inspect.currentframe().f_back.f_lineno

f0 = 10. # approx 7.5e-4 for M=10M_sun (same as MacDonald et al CQG 28 134002)
#OM = [0.032, 0.035 , 0.038, 0.042, 0.046, 0.049, 0.052, 0.058, 0.064]
OM = [0.032, 0.035 ,0.038, 0.042, 0.046, 0.049, 0.052, 0.058, 0.064]
nsnsmass = 2*1.643704202509977
cache_waveforms = False # try caching PN and hybrids. Possibly dangerous.

def workfun(REFERENCE, TRIAL, LIGOfreq, LIGOsig, masses, omegareference,
            omegatrial):
    orbits_for_taper_window_t1 = 5.
    freq_resolution =  0.1*LIGOfreq[0]

    # this cannot be done since the input waveforms are still unevenly space
    """
    dtime = TRIAL.T(1) - TRIAL.T(0)
    if(np.any(TRIAL.T()[1:] - TRIAL.T()[:-1] != dtime)):
        raise ValueError("Non uniform time in trial waveform")
    if(np.any(REFERENCE.T()[1:] - REFERENCE.T()[:-1] != dtime)):
        raise ValueError("Non uniform time in reference waveform")
    if(np.any(REFERENCE.T() != TRIAL.T())):
        raise ValueError("Incompatible TRIAL and REFERENCE waveforms, times differ.")
    """

    ###
    # Fourier Transforms
    # h = (h+) - 1j*(hx)

    """
    REFERENCE1 = PyGW.Waveform(REFERENCE)
    fn = "../IlanaWaveformScripts/MacdonaldMatlab/uniform_%.3f.dat" % omegareference
    data = np.loadtxt(fn)
    # NB: we cannot start from an empty one since Triton does not provide us
    # with a means of creating modes
    REFERENCE.SetT(data[:,0])
    REFERENCE.SetArg(0,data[:,1])
    REFERENCE.SetMag(0,data[:,2])
    print len(REFERENCE.T()), len(REFERENCE1.T())
    print REFERENCE.T(0), REFERENCE.T()[-1]
    print REFERENCE1.T(0), REFERENCE1.T()[-1]
    """

    print "Begin windowing..."
    inds = np.nonzero(np.abs(REFERENCE.Arg(0)-REFERENCE.Arg(0)[0]) > orbits_for_taper_window_t1 * 4.*math.pi)[0]
    time_for_five_orbits = REFERENCE.T(inds[0]) - REFERENCE.T(0)
    times = REFERENCE.T()
    #window = KechanWindow(times, 8, 0.001, 90, len(times))
    window = WindowPlanckTaper(times, times[0],times[0]+time_for_five_orbits, times[-1]-100,times[-1])
    windowedMag = REFERENCE.Mag(0) * window
    REFERENCE.SetMag(0, windowedMag)
    del times

    # same window as for REFERENCE waveform
    inds = np.nonzero(np.abs(TRIAL.Arg(0)-TRIAL.Arg(0)[0]) > orbits_for_taper_window_t1 * 4.*math.pi)[0]
    time_for_five_orbits = TRIAL.T(inds[0]) - TRIAL.T(0)
    times = TRIAL.T()
    #window = KechanWindow(times, 8, 0.001, 90, len(times))
    window = WindowPlanckTaper(times, times[0],times[0]+time_for_five_orbits, times[-1]-100,times[-1])
    windowedMag = TRIAL.Mag(0) * window
    TRIAL.SetMag(0, windowedMag)
    del times
    print "Done windowing..."

    """
    times1=times
    REF1=REF

    fn = "../IlanaWaveformScripts/MacdonaldMatlab/windowed_%.3f.dat" % omegareference
    data = np.loadtxt(fn)
    times = data[:,0]
    REF = data[:,1] + 1j*data[:,2]
    plt.plot(times, REF.real)
    plt.plot(times1, REF1.real)
    plt.show()
    print times[1]-times[0]
    print times1[1]-times1[0]
    print len(times), len(times1)
    plt.plot(times, REF.real-REF1.real)
    plt.show()
    """

    # sample frequently enough so that FFT capturs highest LIGO frequency
    
    #dtime = 1. # Ilana's choice
    # use highest frequency as Nyquist frequency
    # NB: this could be made mass dependent
    dtime = 0.5 / max_freq / (Scale() * np.amax(masses))

    # clip to common time interval
    t1 = max(np.amin(REFERENCE.T()),np.amin(TRIAL.T()))
    t2 = min(np.amax(REFERENCE.T()),np.amax(TRIAL.T()))
    print "Times: ",t1,t2,dtime
    print "Ref:" , np.amin(REFERENCE.T()), np.amax(REFERENCE.T())
    print "Trial:" , np.amin(TRIAL.T()), np.amax(TRIAL.T())

    print "Beginning ffts..."
    # zero pad to power of two to make splitting into sections easier
    # this does not work since we have onot yet interpolated
    """
    if (len(TRI) != len(REF)):
        raise ValueError("Internal error: REF and TRI of different length: %d, %d" % \
                         (len(REF), len(TRI)))
    """
    totalfftlen = 1
    while (totalfftlen < np.ceil(t2-t1)/dtime):
        totalfftlen *= 2
    print "fftlen: ",totalfftlen
    times = t1+dtime*np.arange(totalfftlen)
    """
    REF = np.append(REF, np.zeros(totalfftlen - len(REF), dtype=REF.dtype))
    TRI = np.append(TRI, np.zeros(totalfftlen - len(TRI), dtype=TRI.dtype))
    """

    # do fft in chunks large enough to give desired frequency resolution
    # this should not make a difference as far as speed goes (or only as
    # 1+log(M)/log(N) for M chunks of size N) but for some reason it does
    # indeed matter
    min_duration = 2./freq_resolution / (Scale() * np.amin(masses))
    min_length = np.ceil(min_duration/dtime)
    if (t2-t1 < min_duration):
        #raise ValueError("Timeseries is too short for desired frequency resolution of %g: %g" % \
        #                 (freq_resolution, len(REF)*dtime))
        print ("Timeseries is too short for desired frequency resolution of %g: %g" % \
               (freq_resolution, (t2-t1)*Scale()*np.amin(masses)))
        min_length = len(times)
    fftlen = 1
    while (fftlen < min_length):
        fftlen *= 2
    if (totalfftlen % fftlen != 0):
        raise ValueError("Length of FFT data is not divisible by fftlen: (%d,%d)" % \
                         (totalfftlen, fftlen))

    fREF = np.zeros(fftlen, dtype=np.complex128)
    fTRI = np.zeros(fftlen, dtype=np.complex128)
    print "Using %d FFT chunks (speedup %g) of length %d (%g s)" % \
           (totalfftlen/fftlen,
            1.+np.log(totalfftlen/fftlen)/np.log(totalfftlen),
            fftlen, fftlen*dtime*Scale()*np.amax(masses))
    REFERENCE.SetupForInterpolation()
    TRIAL.SetupForInterpolation()
    for i in range(0,totalfftlen,fftlen):
        wREF = REFERENCE.Interpolated(times[i:i+fftlen], extrap_to_zero=True)
        REF = ompsum.rect(wREF.Mag(0), wREF.Arg(0))
        wTRI = TRIAL.Interpolated(times[i:i+fftlen], extrap_to_zero=True)
        TRI = ompsum.rect(wTRI.Mag(0), wTRI.Arg(0))
        fREF += np.fft.fft(np.conj(REF))
        fTRI += np.fft.fft(np.conj(TRI))
    REFERENCE.FinishInterpolation()
    TRIAL.FinishInterpolation()
    fcREF, fsREF = UnpackTwoFFT(fREF)
    fcTRI, fsTRI = UnpackTwoFFT(fTRI)
    print "done with fft"

    """
    TRIAL1 = PyGW.Waveform(TRIAL)
    fn = "../IlanaWaveformScripts/MacdonaldMatlab/uniform_%.3f.dat" % omegatrial
    data = np.loadtxt(fn)
    # NB: we cannot start from an empty one since Triton does not provide us
    # with a means of creating modes
    TRIAL.SetT(data[:,0])
    TRIAL.SetArg(0,data[:,1])
    TRIAL.SetMag(0,data[:,2])
    print len(TRIAL.T()), len(TRIAL1.T())
    print TRIAL.T(0), TRIAL.T()[-1]
    print TRIAL1.T(0), TRIAL1.T()[-1]
    plt.semilogy(TRIAL.T(), np.abs(TRIAL.Mag(0)-TRIAL1.Mag(0))/TRIAL1.Mag(0), label="Mag")
    plt.semilogy(TRIAL.T(), np.abs(TRIAL.Arg(0)-TRIAL1.Arg(0))/TRIAL1.Arg(0), label="Arg")
    plt.legend(loc='best')
    plt.show()
    """


    """
    times1=times
    TRI1=TRI

    fn = "../IlanaWaveformScripts/MacdonaldMatlab/windowed_%.3f.dat" % omegatrial
    data = np.loadtxt(fn)
    times = data[:,0]
    TRI = data[:,1] + 1j*data[:,2]
    
    plt.plot(times, TRI.real)
    plt.plot(times1, TRI1.real)
    plt.show()
    print times[1]-times[0]
    print times1[1]-times1[0]
    print len(times), len(times1)
    plt.show()
    """

    #data = np.array((REFERENCE.T(), REFERENCE.Arg(0), REFERENCE.Mag(0))).transpose()
    #np.savetxt("windowed_%f.txt"%omegareference, data)
    #data = np.array((TRIAL.T(), TRIAL.Arg(0), TRIAL.Mag(0))).transpose()
    #np.savetxt("windowed_%f.txt"%omegatrial, data)
    #sys.exit(0)

    """
    freqs = np.fft.fftfreq(len(fcTRI),d=dtime)
    print freqs[1]
    print dtime
    print len(freqs)/2
    n = len(freqs)/2
    data = np.array((freqs[:n], fcTRI.real[:n], fcTRI.imag[:n], fsTRI.real[:n], fsTRI.imag[:n], fcREF.real[:n], fcREF.imag[:n])).transpose()
    np.savetxt("fftall.dat", data)
    sys.exit(0)
    """

    results = []
    for totalmass in masses:
        freqs = np.fft.fftfreq(fcTRI.size,d=dtime*Scale()*totalmass)
        df = freqs[1]-freqs[0]

        indexl = np.nonzero(freqs >= LIGOfreq[0])[0][0]
        try:
            indexh = np.nonzero(freqs >= LIGOfreq[-1])[0][0]
        except IndexError:
            indexh = np.argmax(freqs)

        print "FFT resolution: ", freqs[1] # freqs[0] is zero frequency
        print "Upper FFT bound: ", freqs[len(freqs)/2-1]
        print "Lower frequency bound: ", freqs[indexl], "\tIndexl: ", indexl
        print "Upper frequency bound: ", freqs[indexh-1], "\tIndexh: ", indexh-1
        print "Total number of freqs: ", freqs.size
        print "Number of points for integral: ", indexh-indexl
        print "df: ", df

        #data = np.loadtxt("../IlanaWaveformScripts/MacdonaldMatlab/fftall.dat")
        #ilanaFreqs = data[:,0]
        #ilanafcREF = data[:,1] + 1j*data[:,2]
        #ilanafsREF = data[:,3] + 1j*data[:,4]
        #ilanafcTRI = data[:,5] + 1j*data[:,6]
        #freqs = ilanaFreqs
        #indexl = 0
        #indexh = len(freqs)
        #fcREF = ilanafcREF
        #fsREF = ilanafsREF
        #fcTRI = ilanafcTRI

        inv_noisecurve = 1./np.interp(freqs[indexl:indexh],LIGOfreq,LIGOsig)

        fcTRInoise = fcTRI[indexl:indexh]*inv_noisecurve

        # Include noise into f-waveforms so speed up computations later
        fcREFnoise = fcREF[indexl:indexh]*inv_noisecurve
        fsREFnoise = fsREF[indexl:indexh]*inv_noisecurve

        #data = np.array((freqs[indexl:indexh],
        #                 fcREFnoise.real, fcREFnoise.imag,
        #                 fsREFnoise.real, fsREFnoise.imag,
        #                 fcTRInoise.real, fcTRInoise.imag,
        #                 1/inv_noisecurve)).\
        #                transpose()
        #np.savetxt("fftNoisetall.dat", data)
        #sys.exit(0)

        dtshift, dphishift, overlap, rel_error = \
          ComputeOverlap(freqs[indexl:indexh],fcTRInoise,fcREFnoise,fsREFnoise,
                         None)
        dh_over_h = np.sqrt(2.*(1.-overlap))

        print "dtshift: ",dtshift
        print "dphishift: ",dphishift
        print "mass: ",totalmass
        print "overlap: ",overlap
        print "dh_h: ",dh_over_h
        results.append((totalmass, omegareference, omegatrial, overlap, dh_over_h, rel_error))
        sys.stdout.flush()
    return results

def MakeHybrid(PN, NR, omega, frac_omega):
    indexm, timem, phasem, magm = FindMerger(NR)
    """
    fn = "../IlanaWaveformScripts/Hybridization/hybrid_%.3f.dat" % omegareference
    data = np.loadtxt(fn)
    # NB: we cannot start from an empty one since Triton does not provide us
    # with a means of creating modes
    REFERENCE.SetT(data[:,0])
    REFERENCE.SetArg(0,data[:,1])
    REFERENCE.SetMag(0,data[:,2])
    """

    HYBRID = HybridizeHP(PN,NR,timem, omega*(1-frac_omega/2), omega*(1+frac_omega/2))
    HYBRID.AddToTime(-HYBRID.T()[-1])

    return HYBRID

allmasses = [
#float(sys.argv[1])
 nsnsmass,
#    1.1681854e+02, 1.0818126e+02,
#    1.0018260e+02, 9.2775341e+01, 8.5915756e+01, 7.9563352e+01, 7.3680630e+01,
#    6.8232862e+01, 6.3187889e+01, 5.8515928e+01, 5.4189402e+01, 5.0182768e+01,
#    4.6472375e+01, 4.3036320e+01, 3.9854318e+01, 3.6907586e+01, 3.4178728e+01,
#    3.1651635e+01, 2.9311390e+01, 2.7144176e+01, 2.5137201e+01, 2.3278617e+01,
#    2.1557452e+01, 1.9963546e+01, 1.8487490e+01, 1.7120569e+01, 1.5854716e+01,
#    1.4682456e+01, 1.3596871e+01, 1.2591551e+01, 1.1660562e+01, 1.0798408e+01,
#    1.0000000e+01
]


results = []
for m in allmasses:
    masses = [m]

    # generate waveforms long enough for lowest mass (so we generate them only once)
    minimummass = min(masses)
    # division by 2 is to convert from GW wave frequency (f0) to orbital frequency
    v0 = (0.95*f0/2.*Scale()*minimummass*math.pi)**(1./3.) #Start waves a bit sooner for windowing

    #NR = PyGW.Waveform(Zwicky+"/home/kbarkett/Caltech/Scripts/NSNS_Tidal_Scripts/BBH/rhOverM_Extrapolated_N3.dat", 'MagArg')
    if (use_PyWaveform):
        NR = PyWaveform()
        #NR.LoadFromFile("rhOverM_Extrapolated_N3.dat", usecols=(0,9,10))
        #NR.LoadFromFile("../IlanaWaveformScripts/Hybridization/hNR.dat", usecols=(0,2,1))
        #NR.LoadFromFile("BBH_0066/Lev5/Y_l2_m2_ArgMag.dat", usecols=(0,2,1))
        NR.LoadFromFile(DataDir+"/Lev2/rh_CceR2090_l2_m2_ArgMag.dat", usecols=(0,2,1))
    else:
        NR = PyGW.Waveform("rhOverM_Extrapolated_N3.dat", 'MagArg')
        NR = NR[4]
    #NR.DropBefore(NR.T()[0]+1500.) # chop of some junk radiation
    #NR = PyGW.Waveform(DataDir+"/Lev2/rh_CceR2090_l2_m2.dat", 'ReIm')
    time_to_worldtube = 2090 / nsnsmass # assumes signal speed = 1
    NR.DropBefore(NR.T()[0]+time_to_worldtube+200.) # chop of some junk radiation
    """
    t0 = NR.T()[0]
    t1 = NR.T()[-1]
    numcells = np.floor(t1-t0)
    times = t0 + np.arange(numcells+1)
    NR.Interpolate(times)
    """
    #NR.SetArg(0,-NR.Arg(0))

    data = np.array((NR.T(), NR.Arg(0), NR.Mag(0))).transpose()
    np.savetxt("hNR_ArgMag_l2_m2.dat", data, header="t, Arg, Mag")

    """
    fn = "../IlanaWaveformScripts/Hybridization/hNR.dat"
    data = np.loadtxt(fn)
    # NB: we cannot start from an empty one since Triton does not provide us
    # with a means of creating modes
    NR.SetT(data[:,0])
    NR.SetArg(0,data[:,1])
    NR.SetMag(0,data[:,2])
    """

    #TritonPN = PyGW.Waveform('TaylorT3',0,0.,0.,v0)
    TritonPN = PyGW.Waveform('TaylorT4Tidal',0,0.,0.,v0,0.07124843942665074,0.07124843942665074,0.16001855052369648,0.16001855052369648)
    if (use_PyWaveform):
        PN = PyWaveform(TritonPN[4])
    else:
        PN = PyGW.Waveform(TritonPN[4])
    del TritonPN
    """
    t0 = PN.T()[0]
    t1 = PN.T()[-1]
    numcells = np.floor(t1-t0)
    times = t0 + np.arange(numcells+1)
    PN.Interpolate(times)
    """
    PN.SetArg(0,-PN.Arg(0))

    data = np.array((PN.T(), PN.Arg(0), PN.Mag(0))).transpose()
    np.savetxt("hPN_ArgMag_f%g_M%g_l2_m2.dat" % (f0, minimummass), data, header="t, Arg, Mag, v0 = %g" % v0)

    ##fn = "../IlanaWaveformScripts/Hybridization/hPN.dat"
    #fn = "/home/rhaas/tmp/LAL_TaylorT3_ArgMag_l2m2.dat"
    #fn = "/mnt/data/rhaas/postdoc/papers/NrErrorAssessment/PnWaveforms/PN_22_TaylorT3_35_30_3228orb_20ppo_ArgMag.dat"
    #fn = "/home/rhaas/tmp/LAL_TaylorT3Tidal_ArgMag_l2m2.dat"
    #PN = PyWaveform()
    #PN.LoadFromFile(fn, usecols=(0,2,1))

    PN.AddToTime(PN.T()[-1])
    PN.DropAfter(PN.T()[-1]-100.) # drop data very close to merger

    # Noise curve, using optimal aLIGO curve
    LIGO = np.loadtxt(NoiseDir+"/ZERO_DET_high_P.txt")
    LIGOfreq = LIGO[:,0]
    LIGOsig  = LIGO[:,1]
    max_freq = LIGOfreq[-1]

    #plt.plot(PN.T(), PN.Arg(0))
    #plt.plot(NR.T(), NR.Arg(0))
    #plt.show()

    for itrial in range(len(OM)): #(len(OM)-1,): #
        omegatrial = OM[itrial]
        fn = "hHybrid_%g_M%g_MagArg_l2_m2.dat" % (omegatrial, minimummass)
        if(cache_waveforms and os.access(fn, os.R_OK)):
            if (use_PyWaveform):
                orig_TRIAL = PyWaveform()
                orig_TRIAL.LoadFromFile(fn)
            else:
                orig_TRIAL = PyGW.Waveform(fn, 'MagArg')
        else:
            if (use_PyWaveform):
                orig_TRIAL = MakeHybrid(copy.deepcopy(PN), copy.deepcopy(NR), omegatrial, 0.1)
            else:
                orig_TRIAL = MakeHybrid(PyGW.Waveform(PN), PyGW.Waveform(NR), omegatrial, 0.1)
            data = np.array((orig_TRIAL.T(), orig_TRIAL.Mag(0), orig_TRIAL.Arg(0))).transpose()
            np.savetxt(fn, data, header="t, Mag, Arg")
        #fn = "../IlanaWaveformScripts/Hybridization/hybrid_%.3f.dat" % omegatrial
        #data = np.loadtxt(fn)
        ## NB: we cannot start from an empty one since Triton does not provide us
        ## with a means of creating modes
        #orig_TRIAL.SetT(data[:,0])
        #orig_TRIAL.SetArg(0,data[:,1])
        #orig_TRIAL.SetMag(0,data[:,2])
        for ireference in range(itrial+1):
            # make a copy of TRIAL waveform since we modify it
            if (use_PyWaveform):
                TRIAL = copy.deepcopy(orig_TRIAL)
            else:
                TRIAL = PyGW.Waveform(orig_TRIAL)

            omegareference = OM[ireference]
            fn = "hHybrid_%g_M%g_MagArg_l2_m2.dat" % (omegareference, minimummass)
            if(cache_waveforms and os.access(fn, os.R_OK)):
                if (use_PyWaveform):
                    REFERENCE = PyWaveform()
                    REFERENCE.LoadFromFile(fn)
                else:
                    REFERENCE = PyGW.Waveform(fn, 'MagArg')
            else:
                if (use_PyWaveform):
                    REFERENCE = MakeHybrid(copy.deepcopy(PN), copy.deepcopy(NR), omegareference, 0.1)
                else:
                    REFERENCE = MakeHybrid(PyGW.Waveform(PN), PyGW.Waveform(NR), omegareference, 0.1)
                data = np.array((REFERENCE.T(), REFERENCE.Mag(0), REFERENCE.Arg(0))).transpose()
                np.savetxt(fn, data, header="t, Mag, Arg")
            #fn = "../IlanaWaveformScripts/Hybridization/hybrid_%.3f.dat" % omegareference
            #data = np.loadtxt(fn)
            ## NB: we cannot start from an empty one since Triton does not provide us
            ## with a means of creating modes
            #REFERENCE.SetT(data[:,0])
            #REFERENCE.SetArg(0,data[:,1])
            #REFERENCE.SetMag(0,data[:,2])

            # align in time at merger
            indexmTRIAL, timemTRIAL, phasemTRIAL, magmTRIAL = FindMerger(TRIAL)
            indexmREFERENCE, timemREFERENCE, phasemREFERENCE, magmREFERENCE = FindMerger(REFERENCE)
            TRIAL.AddToTime(timemREFERENCE-timemTRIAL)
            #print "TRIAL.T(0)",TRIAL.T(0)
            #print "TRIAL.T(indexmTRIAL)",TRIAL.T(indexmTRIAL)
            #plt.plot(TRIAL.T(), (TRIAL.Arg(0)-TRIAL.Arg(0)[indexmTRIAL])/(4*np.pi))
            #plt.show()
            #sys.exit(0)

            # we interpolate inside of workfun since we do the FFT in chunks
            # and it seems to be faster to interpolate in the same chunks (it
            # also saves on memory)

            # pass in copies since some of PyGW's routines modify their argument
            if (use_PyWaveform):
                results += workfun(copy.deepcopy(REFERENCE), copy.deepcopy(TRIAL),
                                   LIGOfreq, LIGOsig, masses , omegareference, omegatrial)
            else:
                results += workfun(PyGW.Waveform(REFERENCE), PyGW.Waveform(TRIAL),
                                   LIGOfreq, LIGOsig, masses , omegareference, omegatrial)

np.savetxt("dh_over_h_Ilana.dat", results,
           header = "totalmass, omegareference, omegatrial, overlap, dh_over_h, rel_error")
