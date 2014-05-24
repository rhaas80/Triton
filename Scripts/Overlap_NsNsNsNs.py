#!/usr/bin/python

#This script has the process of creating hybrid NSNS waveforms
#then determining their overlap.

ScriptsDir = "/mnt/data/rhaas/postdoc/gr/Triton/Scripts"
DataDir = "/mnt/data/rhaas/postdoc/papers/NsNsInspirals/data"
NoiseDir = "/mnt/data/rhaas/postdoc/gr/noise"
Zwicky = "/home/rhaas/mnt/zwicky/"

import sys
sys.path.append(ScriptsDir)
sys.path.append(ScriptsDir+"/../Numpy/build/lib.linux-x86_64-2.7")
from OverlapUtils import *
import numpy as np
import PyGW_IS_FOR_OLD_DATA as PyGW
#import PyGW.plot
import matplotlib
import matplotlib.pyplot as plt
import math
import gc

from inspect import currentframe, getframeinfo
import cProfile
pr = cProfile.Profile()
pr.enable()

###
#Set up the parameters and load the data
totalmass = 1.643704202509977*2
time_to_worldtube = 2090 / totalmass # assumes signal speed = 1
orbits_for_taper_window_t1 = 5.
q1        = 1.
delta1    = (q1-1.)/(q1+1.)
mode      = PyGW.MatrixInt(1,2,2)
OM = [ 0.03 ,  0.0325  , 0.035  ,
       0.0375 ,  0.04, 0.0425  ,  0.045 ,  0.0475 ,  0.05 ,  0.0525  ,  0.055 ,
       0.0575 ,  0.06 ]

f0 = 10 #Hz, frequency to start the computation

# hybrid calculation hybridizing a NR NsNs with a tidally perturbed PN waveform
# and comparing hybrids obtained using different matching frequencies


v0 = (0.95*f0*Scale()*totalmass*math.pi)**(1./3.) #Start waves a bit sooner for windowing

# first get the "real" waveform which is the NsNs hybrid
# Load the NR data

NSNS = PyGW.Waveform(DataDir+"/Lev1/rh_CceR2090_l2_m2.dat", 'ReIm')

# Generate the PN waveforms
#PNT = PyGW.Waveform('TaylorT4Tidal',0,0.,0.,v0,0.07124843942665074,0.07124843942665074,0.16001855052369648,0.16001855052369648)
PNT = PyGW.Waveform('TaylorT4Tidal',0,0.,0.,v0,0.07124843942665074,0.07124843942665074,0.16001855052369648,0.16001855052369648)
PNT = PNT[4]
# Noise curve, using optimal aLIGO curve
LIGO = np.loadtxt(NoiseDir+"/ZERO_DET_high_P.txt")
LIGOfreq = LIGO[:,0]
LIGOsig  = LIGO[:,1]
LIGOmaxfreq = LIGOfreq[-1]


"""
print len(NSNS.T())
print len(PNT.T())

# thin out data to speed up test computations. Remove for final data
NSNS.UniformTime(len(NSNS.T())/10)
PNT.UniformTime(len(PNT.T())/10)

print len(NSNS.Arg(0))
print len(PNT.Arg(0))
"""


###
#Hybridize waveforms

header = ", ".join(["f0","omegatrial","omegareference","dtshift",
                    "dphishift","dh_over_h","overlap","rel_error"])

for itrial in range(len(OM)):
    omegatrial = OM[itrial]
    TRIAL = HybridizeUsingAngularFrequencyInterval(PNT,NSNS,omegatrial,0.1)
    """
    print "ome:"
    print omegatrial
    print np.gradient(abs(NSNS.Arg(0)),dt)[orbindex]
    ntimes = np.arange(-1800.,1500.,1)
    nPNT = PyGW.Waveform(PNT).Interpolate(ntimes)
    nNSNS = PyGW.Waveform(NSNS).Interpolate(ntimes)
    nTRIAL = PyGW.Waveform(TRIAL).Interpolate(ntimes)
    #plt.plot(nPNT.T(), nPNT.Arg(0), label="PNT")
    #plt.plot(nNSNS.T(), nNSNS.Arg(0), label="NSNS")
    #plt.plot(nTRIAL.T(), nTRIAL.Arg(0), label="TRIAL")
    #plt.legend()
    plt.plot(-(NSNS.Arg(0)-NSNS.Arg(0)[indexm])/4/np.pi, np.gradient(abs(NSNS.Arg(0)),dt))
    plt.gca().set_ylim(0.,0.06)
    #plt.hlines(omegatrial,-4000.,3000.)
    #plt.hlines(np.gradient(abs(NSNS.Arg(0)),dt)[orbindex],-4000.,3000.)
    ylim = plt.gca().get_ylim()
    #plt.vlines(NSNS.T(indhi),ylim[0],ylim[1])
    #plt.vlines(NSNS.T(indlo),ylim[0],ylim[1])
    plt.show()
    #plt.plot(TRIAL.T(), TRIAL.Mag(0))
    #ylim = plt.gca().get_ylim()
    #plt.vlines(NSNS.T(indhi),ylim[0],ylim[1])
    #plt.vlines(NSNS.T(indlo),ylim[0],ylim[1])
    #plt.show()
    """
    TRIAL.AddToTime(-TRIAL.T()[-1])
    """
    print NSNS.T()[0]
    print NSNS.T()[-1]
    tmin = NSNS.T(indhi) - 3500.
    tmax = NSNS.T(indlo) + 1500.
    newtimes = np.arange(tmin,tmax,(tmax-tmin)/10001.)
    nTRIAL = TRIAL.Interpolate(newtimes)
    nPNT = PNT.Interpolate(newtimes)
    nNSNS = NSNS.Interpolate(newtimes)
    plt.plot(nPNT.T(), nPNT.Arg(0) - nTRIAL.Arg(0), label="PNT")
    plt.plot(nNSNS.T(), nNSNS.Arg(0) - nTRIAL.Arg(0), label="NSNS")
    ylim = plt.gca().get_ylim()
    plt.vlines(NSNS.T(indhi),ylim[0],ylim[1])
    plt.vlines(NSNS.T(indlo),ylim[0],ylim[1])
    plt.legend()
    plt.show()
    plt.plot(nPNT.T(), nPNT.Mag(0) - nTRIAL.Mag(0), label="PNT")
    plt.plot(nNSNS.T(), nNSNS.Mag(0) - nTRIAL.Mag(0), label="NSNS")
    ylim = plt.gca().get_ylim()
    plt.vlines(NSNS.T(indhi),ylim[0],ylim[1])
    plt.vlines(NSNS.T(indlo),ylim[0],ylim[1])
    plt.legend()
    plt.show()
    plt.plot(nTRIAL.T(), np.cos(nTRIAL.Arg(0)), label="TRIAL")
    ylim = plt.gca().get_ylim()
    plt.vlines(NSNS.T(indhi),ylim[0],ylim[1])
    plt.vlines(NSNS.T(indlo),ylim[0],ylim[1])
    plt.legend()
    plt.show()
    continue
    """

    # reference hybrid for the trial. Only makes sense for larger frequencies
    for ireference in range(0, itrial+1):
      omegareference = OM[ireference]
      REFERENCE = HybridizeUsingAngularFrequencyInterval(PNT,NSNS,omegareference,0.1)
      REFERENCE.AddToTime(-REFERENCE.T()[-1])

      ###
      # Overlap Prep

      # Set up waveforms with enough datapoints for fft
      tdiff          = -1.0*max(REFERENCE.T(0),TRIAL.T(0))
      npoints, dtime = NumberOfPointsPowerOfTwo(LIGOmaxfreq,tdiff,totalmass,18000000)
      times          = np.linspace(-tdiff,0,npoints)
      print len(times)

      REFERENCE.Interpolate(times)

      TRIAL.Interpolate(times)

      #mint = max(TRIAL.T()[0],PNT.T()[0])
      #maxt = min(TRIAL.T()[-1],PNT.T()[-1])
      #newtimes = times[(times > mint)*(times < maxt)]
      #print len(newtimes)
      #nPNT = PyGW.Waveform(PNT).Interpolate(newtimes)

      #mint = max(TRIAL.T()[0],NSNS.T()[0])
      #maxt = min(TRIAL.T()[-1],NSNS.T()[-1])
      #newtimes = times[(times > mint)*(times < maxt)]
      #print len(newtimes)
      #nNSNS = PyGW.Waveform(NSNS).Interpolate(newtimes)

      #plt.plot(nPNT.T(), nPNT.Arg(0)/6.28/2,label="PN")
      #plt.plot(nNSNS.T(), nNSNS.Arg(0)/6.28/2,label="NSNS")
      #plt.vlines([NSNS.T(indhi),timem,NSNS.T(indlo)],plt.gca().get_ylim()[0],plt.gca().get_ylim()[1])
      #plt.legend(loc='best')
      #plt.show()

      widen, df = WideningFactorPowerOfTwo(.1,dtime,totalmass,npoints,18000000)
      dtime = dtime*Scale()*totalmass
      totalpoints = int(npoints*widen)

      ###
      # Fourier Transforms
      # h = (h+) - 1j*(hx)

      inds = np.nonzero(np.abs(REFERENCE.Arg(0)-REFERENCE.Arg(0)[0]) > orbits_for_taper_window_t1 * 2.*math.pi)[0]
      time_for_five_orbits = times[inds[0]] - times[0]
      #print "i:",inds[0], (time_for_five_orbits-times[0])

      window = WindowPlanckTaper(times, times[0],times[0]+time_for_five_orbits,times[-1]-100,times[-1])

      windowed = window*TRIAL.Mag(0)*np.exp(-TRIAL.Arg(0)*1j)
      fcTRI = FFTWiden(windowed.real,totalpoints,npoints)*dtime
      fsTRI = FFTWiden(-windowed.imag,totalpoints,npoints)*dtime

      windowed = window*REFERENCE.Mag(0)*np.exp(-REFERENCE.Arg(0)*1j)
      fcREF = FFTWiden(windowed.real,totalpoints,npoints)*dtime
      fsREF = FFTWiden(-windowed.imag,totalpoints,npoints)*dtime

      freqs = np.fft.fftfreq(fcTRI.size,d=dtime)
      df = freqs[1]-freqs[0]

      """
      figure(1)
      loglog(freqs,abs(fcTRI))
      loglog(freqs,abs(fsTRI))

      loglog(freqs,abs(fcTID))
      loglog(freqs,abs(fsTID))
      """

      freqmax = f0
      for i in range(totalpoints/2):
        if(freqs[i]>=freqmax):
          indexl=i-1
          break

      if(freqs[totalpoints/2-1]<LIGOfreq[-1]):
        indexh=totalpoints/2

      if(freqs[totalpoints/2-1]>=LIGOfreq[-1]):
        for i in range(totalpoints/2):
            if(freqs[i]>=LIGOfreq[-1]):
              indexh=i
              break
              
      print "Lower frequency bound: ", freqs[indexl], "\tIndexl: ", indexl
      print "Upper frequency bound: ", freqs[indexh-1], "\tIndexh: ", indexh-1, "\n"

      inv_noisecurve = 1./np.interp(freqs[indexl:indexh],LIGOfreq,LIGOsig)

      fcTRInoise = fcTRI[indexl:indexh]*inv_noisecurve
      fsTRInoise = fsTRI[indexl:indexh]*inv_noisecurve

      # Include noise into f-waveforms so speed up computations later
      fcREFnoise = fcREF[indexl:indexh]*inv_noisecurve
      fsREFnoise = fsREF[indexl:indexh]*inv_noisecurve

      """
      # convert to single precision to speed up compuation
      freqs = freqs.astype(np.float32)
      fcTRInoise = fcTRInoise.astype(np.complex64)
      fsTRInoise = fsTRInoise.astype(np.complex64)
      fcREFnoise = fcREFnoise.astype(np.complex64)
      fsREFnoise = fsREFnoise.astype(np.complex64)
      """

      # initialize dataarray the first time around
      try:
          datarray
      except NameError:
          datarray = []

      #When computing the overlaps and comparing, only the actual data (i.e. choose only the real part) is passed on to the function

      #Test, the overlap should be 1 and the shifts and error should be 0
      if(not datarray):
          dtshift, dphishift, overlap, rel_error = \
            ComputeOverlap(freqs[indexl:indexh],fcTRInoise,fcTRInoise,fsTRInoise,
                           None)
          print "Self test for overlap compuation returned (dtshift, dphishift, overlap, rel_error)=(%g,%g,%g,%g)" % \
                             (dtshift, dphishift, overlap, rel_error)

      gc.collect()

      ## compute overlap between trial waveform and reference waveform
      dtshift, dphishift, overlap, rel_error = \
        ComputeOverlap(freqs[indexl:indexh],fcTRInoise,fcREFnoise,fsREFnoise,
                       None)
      dh_over_h = np.sqrt(2.*(1.-overlap))
      output = [f0,omegatrial,omegareference,dtshift[0],dphishift,
                dh_over_h,overlap,rel_error]
      datarray.append(output)
      print output

np.savetxt("dh_over_h_nsnsnsns.dat", datarray, header=header)
pr.disable()
pr.print_stats(sort='cumtime')
