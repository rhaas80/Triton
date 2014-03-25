#!/usr/bin/python

#This script has the process of creating hybrid NSNS (and BBH) waveforms
#then determining their overlap.

ScriptsDir = "/mnt/data/rhaas/postdoc/gr/Triton/Scripts"
DataDir = "/mnt/data/rhaas/postdoc/papers/NsNsInspirals/data"
NoiseDir = "/mnt/data/rhaas/postdoc/gr/noise"
Zwicky = "/home/rhaas/mnt/zwicky/"

import sys
sys.path.append(ScriptsDir)
from OverlapUtils import *
import numpy as np
import PyGW_IS_FOR_OLD_DATA as PyGW
#import PyGW.plot
import matplotlib
import math

import cProfile
pr = cProfile.Profile()
pr.enable()


###
#Set up the parameters and load the data
totalmass = 1.643704202509977*2
q1        = 1.
delta1    = (q1-1.)/(q1+1.)
mode      = PyGW.MatrixInt(1,2,2)
nsnsorbs  = 18.

f0 = 10 #Hz, frequency to start the computation

# dual hybrid calculation hybridizing a NR NsNs with a hybrid Bbh waveform


v0 = (0.95*f0*Scale()*totalmass*math.pi)**(1./3.) #Start waves a bit sooner for windowing

# first get the "real" waveform which is the NsNs hybrid
# Load the NR data

NSNS  = []
NSNS.append(PyGW.Waveform(DataDir+"/Lev0/rh_CceR2090_l2_m2.dat", 'ReIm'))
NSNS.append(PyGW.Waveform(DataDir+"/Lev1/rh_CceR2090_l2_m2.dat", 'ReIm'))
NSNS.append(PyGW.Waveform(DataDir+"/Lev2/rh_CceR2090_l2_m2.dat", 'ReIm'))

BBH   = PyGW.Waveform(Zwicky+"/home/kbarkett/Caltech/Scripts/NSNS_Tidal_Scripts/BBH/rhOverM_Extrapolated_N3.dat", 'MagArg')
BBH   = BBH[4]
BBH.UniformTimeToPowerOfTwo()

# Generate the PN waveforms
PN  = PyGW.Waveform('TaylorT4',delta1,0.,0.,v0,mode)
PNT = PyGW.Waveform('TaylorT4Tidal',0,0.,0.,v0,0.07124843942665074,0.07124843942665074,0.16001855052369648,0.16001855052369648)
PNT = PNT[4]

###
#Hybridize waveforms

#NSNS waveforms
TIDAL = []
for i in range(len(NSNS)):
  indexm, timem, phasem, magm = FindMerger(NSNS[i])
  orbindex                    = TimeNOrbitsBeforeMerger(NSNS[i].Arg(0),indexm,phasem,nsnsorbs)
  dt                          = NSNS[i].T()[1]-NSNS[i].T(0)
  indhi, indlo                = GWFrequencyInterval(NSNS[i].Arg(0),indexm,dt,np.gradient(abs(NSNS[i].Arg(0)),dt)[orbindex],.1)
  
  TIDAL.append(Hybridize(PNT,NSNS[i],timem,NSNS[i].T(indhi),NSNS[i].T(indlo)))
  TIDAL[i].AddToTime(-TIDAL[i].T()[-1])
  del indexm, timem, phasem, magm, orbindex, dt, indhi, indlo


#BBH single hybrid waveform

indexm, timem, phasem, magm = FindMerger(BBH)
orbindex                    = TimeNOrbitsBeforeMerger(BBH.Arg(0),indexm,phasem,nsnsorbs)
dt                          = BBH.T()[1]-BBH.T(0)
indhi, indlo                = GWFrequencyInterval(BBH.Arg(0),indexm,dt,np.gradient(abs(BBH.Arg(0)),dt)[orbindex],.1)


VAC = Hybridize(PN,BBH,timem,BBH.T(indhi),BBH.T(indlo))
VAC.AddToTime(-VAC.T()[-1])
del indexm, timem, phasem, magm, orbindex, dt, indhi, indlo

# dual-hybrid between BBH single hybrid and NsNs NR waveform
for bbhnsnsorbs in range(18,4,-1):
  indexm, timem, phasem, magm = FindMerger(NSNS[-1])
  orbindex                    = TimeNOrbitsBeforeMerger(NSNS[-1].Arg(0),indexm,phasem,bbhnsnsorbs)
  dt                          = NSNS[-1].T()[1]-NSNS[-1].T(0)
  indhi, indlo                = GWFrequencyInterval(NSNS[-1].Arg(0),indexm,dt,np.gradient(abs(NSNS[-1].Arg(0)),dt)[orbindex],.1)
  
  TRIPPLE = Hybridize(VAC,NSNS[-1],timem,NSNS[-1].T(indhi),NSNS[-1].T(indlo))
  TRIPPLE.AddToTime(-TRIPPLE.T()[-1])
  del indexm, timem, phasem, magm, orbindex, dt, indhi, indlo


  ###
  # Overlap Prep

  # Noise curve, using optimal aLIGO curve
  LIGO = np.loadtxt(NoiseDir+"/ZERO_DET_high_P.txt")
  LIGOfreq = LIGO[:,0]
  LIGOsig  = LIGO[:,1]

  # Set up waveforms with enough datapoints for fft
  tdiff          = -1.0*max(TRIPPLE.T(0),VAC.T(0))
  npoints, dtime = NumberOfPointsPowerOfTwo(LIGOfreq[-1],tdiff,totalmass,18000000)
  times          = np.linspace(-tdiff,0,npoints)

  TRIPPLE.Interpolate(times)

  TIDAL[-1].Interpolate(times)

  widen, df = WideningFactorPowerOfTwo(.1,dtime,totalmass,npoints,18000000)
  dtime = dtime*Scale()*totalmass
  totalpoints = int(npoints*widen)

  ###
  # Fourier Transforms
  # h = (h+) - 1j*(hx)

  fcTID = FFTWiden(WindowPlanckTaper(times, times[0],times[0]+1000,times[-1]-10,times[-1])*TIDAL[-1].Mag(0)*np.exp(-TIDAL[-1].Arg(0)*1j).real,totalpoints,npoints)*dtime
  fsTID = FFTWiden(WindowPlanckTaper(times, times[0],times[0]+1500,times[-1]-10,times[-1])*TIDAL[-1].Mag(0)*np.exp(-TIDAL[-1].Arg(0)*1j).imag*-1.0,totalpoints,npoints)*dtime

  fcTRI = FFTWiden(WindowPlanckTaper(times, times[0],times[0]+1000,times[-1]-10,times[-1])*TRIPPLE.Mag(0)*np.exp(-TRIPPLE.Arg(0)*1j).real,totalpoints,npoints)*dtime
  fsTRI = FFTWiden(WindowPlanckTaper(times, times[0],times[0]+1500,times[-1]-10,times[-1])*TRIPPLE.Mag(0)*np.exp(-TRIPPLE.Arg(0)*1j).imag*-1.0,totalpoints,npoints)*dtime

  freqs = np.fft.fftfreq(fcTID.size,d=dtime)
  df = freqs[1]-freqs[0]

  """
  figure(1)
  for i in range(len(fcTID)):
    loglog(freqs,abs(fcTID[i]))
    loglog(freqs,abs(fsTID[i]))

  loglog(freqs,abs(fcVAC))
  loglog(freqs,abs(fsVAC))
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

  noisecurve = np.interp(freqs[indexl:indexh],LIGOfreq,LIGOsig)

  fcTIDnoise = fcTID[indexl:indexh]/noisecurve
  fsTIDnoise = fsTID[indexl:indexh]/noisecurve

  # Include noise into f-waveforms so speed up computations later
  fcTRInoise = fcTRI[indexl:indexh]/noisecurve
  fsTRInoise = fsTRI[indexl:indexh]/noisecurve

  # initialize dataarray the first time around
  try:
      datarray
  except NameError:
      datarray = []

  #When computing the overlaps and comparing, only the actual data (i.e. choose only the real part) is passed on to the function

  #Test, the overlap should be 1 and the shifts and error should be 0
  dtshift, dphishift, overlap, rel_error = ComputeOverlap(freqs[indexl:indexh],fcTIDnoise,fcTIDnoise,fsTIDnoise,1.0)


  ## compute overlap between tripple waveform and highest accuracy NsNs assuming NsNs is the 'real' waveform
  dtshift, dphishift, overlap, rel_error = ComputeOverlap(freqs[indexl:indexh],fcTIDnoise,fcTRInoise,fsTRInoise,1.0)
  dh_by_h = np.sqrt(2.*(1.-overlap))
  datarray.append([f0,bbhnsnsorbs,dtshift[0],dphishift,dh_by_h,overlap,rel_error])
  print [f0,bbhnsnsorbs,dtshift[0],dphishift,dh_by_h,overlap,rel_error]


np.savetxt("datarray.dat", datarray)
pr.disable()
#pr.print_stats(sort='cumtime')
