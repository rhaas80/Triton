import sys
import ompsum
from PyWaveform import *
from scipy.optimize import fmin
from scipy.signal import hann
import scipy.interpolate
import numpy as np
from math import pi
import PyGW_IS_FOR_OLD_DATA as PyGW
import ctypes
import copy
import warnings
import SpecHybrids

import matplotlib.pyplot as plt

use_PyWaveform = True

# Compute the noise weighted inner product of two waves that are
# have been converted to their frequency domain
# Assumes that both waves and the noise curve are already aligned
# to a common, uniformly spaced array of frequencies and are 
# given only in the range to be integrated.
# Integrated using Trapazoidal rule to avoid extra interpolations

# Inputs:
# wave1: First of two frequency waves
# wave2: Second of two frequency waves
# noisesqrt: square root of the noise curve, None if there is no noise
# deltaf: frequency interval of each point
def NoiseWeightedFreqInnerProduct(wave1, wave2, noisesqrt, deltaf):

  integ = (np.conjugate(wave1)*wave2).real.astype(np.float64)

  if noisesqrt:
    integrand = integ/noisesqrt**2
  else:
    integrand = integ
  length = len(integ)

  # The factor of 2 in front is canceled out by the 1/2 by trapezoid rule
  # we then gain another factor of 2 due to conj(g)*h+g*conj(h) = 2*Re(conj(g)*h)
  total = 2.*(integrand[0]+2*ompsum.sum(integrand[1:-1])+integrand[-1])*deltaf
  return total


# Compute the (negative) unnormalized overlap between to waveforms
# for a minimization function like in ComputeOverlap
# This script assumes the inputs are both fft functions evenly spaced over
# the same array of frequencies along with the intended noise curve similarly
# spaced. Assumes that only the frequency range of integration as been
# determined before this function call, so integrals will be over the full
# frequency array. Does not compute the phase shift.

# Inputs:
# dt: the time shift between the waveforms and is the variable to maximize over.
# freqs: array of uniformly spaced frequency points to integrate over
# fwave_ref: assumed to be the fft of the 'data' or 'correct' waveform
# fwave_tem_c: fft of the real part of the template waveform
# fwave_tem_s: fft of the imag part of the template waveform
# noise_sqrt: square root of the noise curve to be integrated over
# TODO rewrite as C code
def OverlapMaxing(dt, freqs, fwave_ref, fwave_tem_c, fwave_tem_s, noise_sqrt):
  
  retvalC = ompsum.OverlapMaxing(dt, freqs, fwave_ref, fwave_tem_c, fwave_tem_s)

  #print "olap: %g %g" % (dt, retvalC)

  return retvalC

  phases = (2*pi*dt)*freqs
  """
  # this is actually faster than exp(1j*angle) since it does compute the
  # exp(real) part of exp(complex)
  # faster even would be np.sincos (if it existed) or some expi(...) or
  # np.cumprod the later is likely going to have gigantic truncation errors
  exp_freqs = np.empty(phases.shape,dtype=np.complex128)
  exp_freqs.real = np.cos(phases)
  exp_freqs.imag = np.sin(phases)
  """
  exp_freqs = ompsum.expi(phases)
  """
  for i in range(phases.shape[0]):
    if exp2_freqs[i] != exp_freqs[i]:
        print exp2_freqs[i], exp_freqs[i], exp2_freqs[i] - exp_freqs[i]
  """
  fwave_tem_c_shifted = fwave_tem_c*exp_freqs
  fwave_tem_s_shifted = fwave_tem_s*exp_freqs

  deltaf = freqs[1]-freqs[0]
  # TODO: add yet another test that this is uniformly spaced
  NWFIc = NoiseWeightedFreqInnerProduct(fwave_ref, fwave_tem_c_shifted, noise_sqrt, deltaf)
  NWFIs = NoiseWeightedFreqInnerProduct(fwave_ref, fwave_tem_s_shifted, noise_sqrt, deltaf)
  #print "c: %s s: %s" % (NWFIc,NWFIs)

  # Compute the phase shift corresponding to the maximized time shift
  dphi = np.arctan2(NWFIs, NWFIc)

  #if (-np.sin(dphi)-np.cos(dphi)>=0):
  #  dphi = dphi+pi

  # Compute the full waveform which maximizes the overlap
  h = fwave_tem_c_shifted*np.cos(dphi)+np.sin(dphi)*fwave_tem_s_shifted

  # compute dot product between h and reference
  numerator =  NoiseWeightedFreqInnerProduct(fwave_ref,h,noise_sqrt,deltaf)

  norm_h = NoiseWeightedFreqInnerProduct(h,h,noise_sqrt,deltaf)
  norm_ref = NoiseWeightedFreqInnerProduct(fwave_ref,fwave_ref,noise_sqrt,deltaf)
  overlap = np.abs(numerator)/(np.sqrt(norm_ref*norm_h))

  dh = h - fwave_ref
  retval = NoiseWeightedFreqInnerProduct(dh, dh, noise_sqrt, deltaf)

  #retval = -overlap
  #retval = -abs(np.sqrt(NWFIc**2 + NWFIs**2))

  print "olap: %g %g %g %g" % (dt, retval, retvalC, retvalC/retval)

  return retval


# Computes the maximum overlap between two waveforms along with the time
# and phase shift needed to maximize the overlap and the value of
# ||dh||/||h|| where dh is the difference between the shifted first waveform
# and the second, unaltered waveform

# Look in arxiv:1102.5128 at eqn. (25) and (26) for discussion of this method.

# Inputs:
# freqs: Array of frequencies corresponding to the fft of the waveforms
# wave1f: fft of the first waveform, this is the reference waveform and
#	will not be altered during the computation
# wave2cf: fft of the real part of the second waveform (h_plus), this is
#	the waveform that will be scaled along with wave2sf in order to
#	maximize overlap
# wave2sf: fft of the imaginary part of the second waveform (h_cross), this
#	is the waveform that will be scaled along with wave2cf in order to
#	maximize overlap
# noisecurve: Square root of the noise curve to be used for computing the
#	noise wieghted inner product
def ComputeOverlap(freqs, wave1f, wave2cf, wave2sf, noisecurve):

  df = freqs[1]-freqs[0]
  if(np.any(np.abs(freqs[1:]-freqs[:-1] - df) > 1e-4*np.abs(df))):
    raise ValueError("Non uniform frequency steps detected: difference %g from %g" % \
                     (np.amax(np.abs(freqs[1:]-freqs[:-1] - df)), df))
  if noisecurve:
    inv_noise = 1./noisecurve
    wave1fNoise = wave1f*inv_noise
    wave2cfNoise = wave2cf*inv_noise
    wave2sfNoise = wave2sf*inv_noise
  else:
    wave1fNoise = wave1f
    wave2cfNoise = wave2cf
    wave2sfNoise = wave2sf

  set_ftol=abs(1.0e-15*OverlapMaxing(0,freqs, wave2cfNoise, wave2cfNoise, wave2sfNoise, None))

  # Make sure fmin looks in both positive and negative deltat so it peeks
  # in both directions to find the best choice. Takes up time so can be
  # removed if reasonalbly confident it won't find a local minimum in the
  # wrong direction
  oldstdout = sys.stdout
  try:
    class NullWriter(object):
      def write(self,arg): pass
    #sys.stdout = NullWriter()
    test_plus, test_plus_res, iterations, funcalls, warnflag   = fmin( OverlapMaxing, +1e-5, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, None), maxiter = 5, ftol = set_ftol, full_output=True)
    test_minus, test_minus_res, iterations, funcalls, warnflag = fmin( OverlapMaxing, -1e-5, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, None), maxiter = 5, ftol = set_ftol, full_output=True)
  finally:
    sys.stdout = oldstdout

  if abs(test_plus_res) > abs(test_minus_res):
    t0 = test_plus
  else:
    t0 = test_minus

  # neg_overlap
  dt_max, dhdh, iterations, funcalls, warnflag = fmin( OverlapMaxing, t0, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, 1.0), ftol=set_ftol, full_output=True)

  # Compute the phase shift corresponding to the maximized time shift
  phases = np.exp(2*pi*1j*freqs*dt_max)
  wave2cfNoise_shifted = wave2cfNoise*phases
  wave2sfNoise_shifted = wave2sfNoise*phases
  dphi = np.arctan2(NoiseWeightedFreqInnerProduct(wave1fNoise,wave2sfNoise_shifted,None,df),
                    NoiseWeightedFreqInnerProduct(wave1fNoise,wave2cfNoise_shifted,None,df))

  #if (-np.sin(dphi)-np.cos(dphi)>=0):
  #  dphi = dphi+pi

  # Compute the full waveform which maximizes the overlap
  h = wave2cfNoise_shifted*np.cos(dphi)+np.sin(dphi)*wave2sfNoise_shifted

  norm_h = NoiseWeightedFreqInnerProduct(h,h,None,df)
  norm_ref = NoiseWeightedFreqInnerProduct(wave1fNoise,wave1fNoise,None,df)
  numerator =  NoiseWeightedFreqInnerProduct(wave1fNoise,h,None,df)
  overlap = np.abs(numerator)/(np.sqrt(norm_ref*norm_h)) #- neg_overlap
  deltah = wave1fNoise-h
  rel_error = np.sqrt(NoiseWeightedFreqInnerProduct(deltah,deltah,None,df)/np.sqrt(norm_h*norm_ref))

  return dt_max, dphi, overlap, rel_error

# Inputs:
# freqs: Array of frequencies corresponding to the fft of the waveforms
# wave1f: fft of the first waveform, this is the reference waveform and
#	will not be altered during the computation
# wave2cf: fft of the real part of the second waveform (h_plus), this is 
#	the waveform that will be scaled along with wave2sf in order to
#	maximize overlap
# wave2sf: fft of the imaginary part of the second waveform (h_cross), this
#	is the waveform that will be scaled along with wave2cf in order to
#	maximize overlap
# noisecurve: Square root of the noise curve to be used for computing the
#	noise wieghted inner product
def ComputeMaxOverlapWaveform(freqs, wave1f, wave2cf, wave2sf, noisecurve):

  df = freqs[1]-freqs[0]
  if noisecurve:
    inv_noise = 1./noisecurve
    wave1fNoise = wave1f*inv_noise
    wave2cfNoise = wave2cf*inv_noise
    wave2sfNoise = wave2sf*inv_noise
  else:
    wave1fNoise = wave1f
    wave2cfNoise = wave2cf
    wave2sfNoise = wave2sf

  set_ftol=abs(1.0e-12*OverlapMaxing(0,freqs, wave2cfNoise, wave2cfNoise, wave2sfNoise, None))

  # Make sure fmin looks in both positive and negative deltat so it peeks
  # in both directions to find the best choice. Takes up time so can be
  # removed if reasonalbly confident it won't find a local minimum in the
  # wrong direction
  oldstdout = sys.stdout
  try:
    class NullWriter(object):
      def write(self,arg): pass
    sys.stdout = NullWriter()
    test_plus, test_plus_res, iterations, funcalls, warnflag   = fmin( OverlapMaxing, +1e-4, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, None), maxiter = 5, ftol = set_ftol, full_output=True)
    test_minus, test_minus_res, iterations, funcalls, warnflag = fmin( OverlapMaxing, -1e-4, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, None), maxiter = 5, ftol = set_ftol, full_output=True)
  finally:
    sys.stdout = oldstdout

  if abs(test_plus_res) > abs(test_minus_res):
    t0 = test_plus
  else:
    t0 = test_minus

  dt_max, numerator, iterations, funcalls, warnflag = fmin( OverlapMaxing, t0, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, None), ftol=set_ftol, full_output=True)

  # Compute the phase shift corresponding to the maximized time shift
  phases = np.exp(2*pi*1j*freqs*dt_max)
  dphi = np.arctan2(NoiseWeightedFreqInnerProduct(wave1fNoise,wave2sfNoise*phases,None,df),
                    NoiseWeightedFreqInnerProduct(wave1fNoise,wave2cfNoise*phases,None,df))

  #if (-np.sin(dphi)-np.cos(dphi)>=0):
  #  dphi = dphi+pi

  # Compute the full waveform which maximizes the overlap
  h = (wave2cfNoise*np.cos(dphi)+np.sin(dphi)*wave2sfNoise)*np.exp(2*pi*1j*freqs*dt_max)

  return h

#==============================================================================

# Series of functions which can be used to help with computing hybridization
# or fft's but are not directly involved with the calculation of overlaps

def int32_to_uint32(i):
  # Casting from signed integer to unsigned integer

  return ctypes.c_uint32(i).value

def Scale():
  # Returns the scale factor for conversion from seconds to solar masses

  return .00000492686088

def FindMerger(Wave):
  # Finds the time and phase corresponding to the merger by locating the point
  # of maximum amplitude. If the wave does not reach merger, then should just
  # return the end time and phase

  # Input:
  # Wave: PyGW.Waveform object to find the merger of, assumed to be only the
  #	(2,2) mode of the waveform

  indexm1 = Wave.Mag(0).argmax()
  indexm  = int32_to_uint32(indexm1)
  timem   = Wave.T(indexm)
  phasem  = abs(Wave.Arg(0)[indexm])
  magm    = Wave.Mag(0)[indexm]

  return indexm, timem, phasem, magm

def TimeNOrbitsBeforeMerger(Arg,indexm,phasem,N):
  # Finds the index correpsonding to the time when the phase
  # is N number of orbits before merger

  # Input:
  # Arg: The phase of the Gravitational Waveform (not the orbital phase,
  # 	factor of 2 difference)
  # indexm: indice corresponding to the time of merger on the phase
  # phasem: phase of the waveform at the time of merger
  # N: number of orbits before merger to find the index

  a = 4.*pi*N
  for i in range(indexm):
    if abs(abs(Arg[indexm-i])-phasem) < a:
      index = indexm-i

  return index

def TimeOmegaBeforeMerger(Arg,indexm,dt,omegatrial):
  # Finds the index correpsonding to the time when the wave frequency is omega
  raise ValueError("Don't use this, since it assumes constant spacing in time but does not verify")

  # Input:
  # Arg: The phase of the Gravitational Waveform (not the orbital phase,
  # 	factor of 2 difference)
  # indexm: indice corresponding to the time of merger on the phase
  # dt: time step used to compute omeag
  # omegatrial: angular frequency that we want to find
  omega = np.gradient(abs(Arg),dt)
  if(omega[indexm] < omegatrial):
    raise ValueError("Trial frequency %g higher than merger frequency %g" % (omegatrial, omega[indexm]))
  ind = omega[:indexm] < omegatrial
  return np.nonzero(ind)[0][-1]
  

def GWFrequencyInterval(Arg,indexm,dt,w_0,deltaw,only_full_cycles=False):
  # Computes the indices corresponding to the lower and upper bounds
  # of a frequency interval on a given phase array some time before merger

  # Inputs:
  # Arg: array of phase points uniformly spaced in time by dt
  # indexm: index correpsonding to merger
  # dt: time difference between two points in Arg
  # w_0: frequency at center of interval
  # deltaw: width of frequency interval
  # only_full_cycles: make sure that matching interval spans an integer number
  # of cycles
  #if (deltaw < 0):
  #  raise ValueError("Relative width of frequency interval must be positive but is %g" % deltaw)
  deriv  = np.gradient(abs(Arg),dt)
  indexhi=0
  indexlo=0
  w_hi = w_0*(1.+deltaw/2.)
  w_lo = w_0*(1.-deltaw/2.)
  indexhi = np.nonzero(deriv[:indexm] <= w_hi)[0][-1]
  indexlo = np.nonzero(deriv[:indexhi] <= w_lo)[0][-1]
  if only_full_cycles:
    target_range = np.ceil(np.abs(Arg[indexhi] - \
                                  Arg[indexlo])/(2.*np.pi)) * 2*np.pi
    full_cycle_indexhi = indexhi
    full_cycle_indexlo = indexlo
    while np.abs(Arg[full_cycle_indexhi] - Arg[full_cycle_indexlo]) < \
          target_range:
      if (np.abs(Arg[indexhi] - Arg[full_cycle_indexhi+1]) < \
          np.abs(Arg[indexlo] - Arg[full_cycle_indexlo-1])):
        full_cycle_indexhi += 1
      else:
        full_cycle_indexlo -= 1
    if (np.abs(Arg[full_cycle_indexhi] - Arg[full_cycle_indexlo]) < \
        target_range):
      raise ValueError(\
              "Unexpect loop exit: range %g is not yet large enough %g" % \
              (np.abs(Arg[full_cycle_indexhi] - Arg[full_cycle_indexlo]),
               target_range))
    if not (full_cycle_indexhi >= indexhi and full_cycle_indexlo <= indexlo):
      raise ValueError(\
              "Unexpected outcome growing range: (%d,%d) does not enclose (%d,%d)" % \
              (full_cycle_indexlo,full_cycle_indexhi,indexlo,indexhi))
    indexhi = full_cycle_indexhi
    indexlo = full_cycle_indexlo
  return indexlo, indexhi

def HybridizeWithTbias(PN,NR,timem,deltat,t1,t2):
  # Hybridizes the first waveform to the second with an intentional temporal
  # shift from perfect alignment in the first.

  # Inputs:
  # PN: The first waveform (left half of hybrid); a post-newtonian is often used
  # NR: The second waveform (right half of hybrid); generally an numerical waveform
  # timem: Time of merger (or max amplitude) in the NR waveform
  # deltat: In intentional temporal shift from alignment in PN waveform
  # t1: Start of the hybridization interval
  # t2: End of the hybridization interval

  PN.AddToTime(-PN.T()[-1]+timem)
  PN.AlignTo(NR,t1,t2)
  PN.AlignTo(NR,t1,t2)

  # Use these to calculate deltaphi then apply to the originals
  NR_1 = PyGW.Waveform(NR)
  PN_1 = PyGW.Waveform(PN)

  width=(t2-t1)/1000.
  times=np.empty(1001)
  for i in range(len(times)):
    times[i]=t1+width*i

  NR_1.Interpolate(times)
  PN_1.Interpolate(times+deltat)
  # Waveform must be restricted to the 2,2 mode when passed to function
  integrand = NR_1.Arg(0)-PN_1.Arg(0)

  # Eqn 79 in arxiv: 0804.4184
  # Integrate using trapezoid rule
  deltaphi = width*(integrand[0] + 2.*np.sum(integrand[1:-1]) + integrand[-1])/2./(t2-t1)

  PN.AddToTime(deltat)
  PN.SetArg(0,PN.Arg(0)-deltaphi)
  return PN.HybridizeWith(NR,t1,t2)

def HybridizeUsingAngularFrequencyInterval(PN,NR,omega,frac_omega):
  # Generates a hybrid waveform from the two given waveforms

  # Inputs:
  # PN: The first waveform (left half of hybrid); a post-newtonian is often used
  # NR: The second waveform (right half of hybrid); generally an numerical waveform
  # omega: central frequency of hybridization interval
  # frac_omega: width of hybridization interval as fraction of omega
  indexm, timem, phasem, magm = FindMerger(NR)
  dt                          = NR.T()[1]-NR.T()[0]
  if(np.any(np.abs(NR.T()[1:]-NR.T()[:-1] - dt) > 1e-4*np.abs(dt))):
    raise ValueError("Non uniform timestep detected: difference %g from %g" % \
                     (np.amax(np.abs(NR.T()[1:]-NR.T()[:-1] - dt)), dt))
  deriv = np.gradient(abs(NR.Arg(0)),dt)
  indhi, indlo                = GWFrequencyInterval(NR.Arg(0),indexm,dt,omega,
                                                    frac_omega,
                                                    only_full_cycles=True)
  return Hybridize(PN,NR,timem,NR.T(indhi),NR.T(indlo))

def HybridizeHP(PN,NR,timem,omega_min,omega_max):
    matching_type = 1 # (delta-phase)

    p,res=SpecHybrids.LeastSquareFit(NR.T(), NR.Arg(0), NR.Mag(0),
                                     PN.T(), PN.Arg(0), PN.Mag(0),
                                     omega_min, omega_max,
                                     matching_type)
    idx, tNR_min, tNR_max=SpecHybrids.Find_tmin_tmax(NR.T(), NR.Arg(0), omega_min, omega_max)
    

    BestDeltaT=p[0]
    BestDeltaPhi=p[1]
    print "Time offset and phase offset: ", BestDeltaT, BestDeltaPhi
    # cropped from ConstructHybridWaveform.py
    PN.AddToTime(BestDeltaT)
    phase = PN.Arg(0) + BestDeltaPhi
    PN.SetArg(0, phase)
    useTritonHybrid = False
    if useTritonHybrid: # this linearly blends
        # drop all NR data before PN begins (behaves strange otherwise)
        if(use_PyWaveform):
            cutNR = np.deepcopy(NR)
        else:
            cutNR = PyGW.Waveform(NR)
        cutNR.DropBefore(tNR_min)
        HYBRID = PN.HybridizeWith(cutNR,tNR_min,tNR_max)
    useCosHybrid = True
    if useCosHybrid:
        t0 = tNR_min
        t1 = tNR_max
        tPN = PN.T()
        tNR = NR.T()
        dataPN = np.array((PN.Arg(0), PN.Mag(0))).transpose()
        dataNR = np.array((NR.Arg(0), NR.Mag(0))).transpose()

        # copied from Harald Pfeiffer's ConstructHybridWaveForm script
        ################
        # for t<t0, use PN waveform
        ################
        tOut=tPN[ tPN<t0 ]
        dataOut=dataPN[ tPN<t0, : ]
        
        #print "tOut.shape=",tOut.shape
        #print "dataOut.shape=",dataOut.shape
        
        ################
        # for t0<= t <= t1 
        # interpolate PN-data to NR data-points, 
        # and blend using cos(...)
        ################
        tblend = tNR[ (tNR >= t0) & (tNR <= t1) ]
        blendNR = dataNR[ (tNR >= t0) & (tNR <= t1) ]
        
        #interp=scipy.interpolate.interp1d(tPN[tPN>t0-200.], dataPN[tPN>t0-200.],axis=0,kind='cubic')
        #blendPN=interp(tblend)
        blendPN = np.zeros((len(tblend),2))
        print "t0: ", t0
        print "tPN: ", tPN[0], tPN[-1]
        spl =  scipy.interpolate.splrep(tPN[tPN>t0-200.], dataPN[tPN>t0-200.,0])
        blendPN[:,0] = scipy.interpolate.splev(tblend, spl, ext=2)
        spl =  scipy.interpolate.splrep(tPN[tPN>t0-200.], dataPN[tPN>t0-200.,1])
        blendPN[:,1] = scipy.interpolate.splev(tblend, spl, ext=2)
        
        # weighting function
        f=0.5+0.5*np.cos((tblend-t0)*np.pi/(t1-t0))
        temp=blendPN
        temp[:,0] = f*blendPN[:,0]+(1.-f)*blendNR[:,0]
        temp[:,1] = f*blendPN[:,1]+(1.-f)*blendNR[:,1]
        
        #print "f.shape=",f.shape
        #print "blendPN.shape=", blendPN.shape
        #print "blendNR.shape=", blendNR.shape
        #print "tOut.shape=",tOut.shape
        #print "dataOut.shape=",dataOut.shape
        #print "temp.shape=", temp.shape
        
        tOut=np.append(tOut, tblend)
        dataOut=np.append(dataOut, temp,axis=0)
        #print "tOut.shape=",tOut.shape
        #print "dataOut.shape=",dataOut.shape
        
        ################
        # np.append NR-only data
        ################
        tOut=np.append( tOut, tNR[tNR>t1] )
        dataOut=np.append( dataOut, dataNR[ tNR>t1, :], axis=0 )
        #print "tOut.shape=",tOut.shape
        #print "dataOut.shape=",dataOut.shape
        
        if(use_PyWaveform):
            HYBRID = PyWaveform()
        else:
            # cannot create a non-empty Waveform object it seems, so need to copy
            HYBRID = PyGW.Waveform(PN)
        HYBRID.SetT(tOut)
        HYBRID.SetMag(0, dataOut[:,1])
        HYBRID.SetArg(0, dataOut[:,0])
    return HYBRID

def Hybridize(PN,NR,timem,t1,t2):
  # Generates a hybrid waveform from the two given waveforms

  # Inputs:
  # PN: The first waveform (left half of hybrid); a post-newtonian is often used
  # NR: The second waveform (right half of hybrid); generally an numerical waveform
  # timem: Time of merger (or max amplitude) in the NR waveform
  # t1: Start of the hybridization interval
  # t2: End of the hybridization interval
  
  #print "timem %g, t1 %g, t2 %g" % (timem,t1,t2)
  PN.AddToTime(-PN.T()[-1]+timem)
  PN.AlignTo(NR,t1,t2)
  PN.AlignTo(NR,t1,t2) # don't know why, but seems to want it twice
  HYBRID = PN.HybridizeWith(NR,t1,t2)
  """
  times = np.linspace(NR.T(0),PN.T()[-1],num=20000)
  sPN = PyGW.Waveform(PN)
  sPN.Interpolate(times)
  sNR = PyGW.Waveform(NR)
  sNR.Interpolate(times)
  sHYBRID = PyGW.Waveform(HYBRID)
  sHYBRID.Interpolate(times)
  #plt.plot(sPN.T(),(sPN.Mag(0)-sHYBRID.Mag(0))/sHYBRID.Mag(0), label='PN')
  #plt.plot(sNR.T(),(sNR.Mag(0)-sHYBRID.Mag(0))/sHYBRID.Mag(0), label='NR')
  plt.plot(sPN.T(),sPN.Mag(0), label='PN')
  plt.plot(sNR.T(),sNR.Mag(0), label='NR')
  plt.plot(sNR.T(),sHYBRID.Mag(0), label='HYBRID')
  ylim = plt.gca().get_ylim()
  plt.vlines(t1, ylim[0], ylim[1])
  plt.vlines(t2, ylim[0], ylim[1])
  plt.legend(loc='best')
  plt.show()
  """
  return HYBRID

def NumberOfPointsPowerOfTwo(maxfreq,tdiff,totalmass,nlimit=None):
  # Determines how many points needed in order that the fft will reach the
  # maximum frequency given. The frequency is given in Hz while the time is 
  # given in units of (t-r*)/M and converted to determine number of points.
  # Looks only at powers of two so that the fft is optimized.

  # Inputs:
  # maxfreq: the maximum frequency the fft needs to reach
  # tdiff: the time width of the waveform in (t-r*)/M units
  # totalmass: the total mass of the system in units of solar mass
  # nlimit: an upper limit on the number of points for the fft 
  npoints = pow(2,12)
  dt = 1.0*tdiff/(npoints-1)
  scale = Scale()

  # Extra factor of 1/2 since np.fft.fft also gives negative frequencies
  while (maxfreq>npoints/tdiff/scale/totalmass/2):
    npoints=npoints*2
    if(nlimit and npoints>nlimit):
      npoints=npoints/2
      print "Number of Points limit reached, stopping at: ", npoints
      break
    dt = 1.0*tdiff/(npoints-1)

  return npoints,dt

def WideningFactorPowerOfTwo(df_limit,dt,totalmass,npoints,nlimit=None):
  # Determines how wide to make the array by increasing powers of two is
  # needed in order to that the frequency resolution of the fft is less than
  # required. Frequencies must be given in Hz while the time will be in
  # units of (t-r*)/M and then converted as needed

  # Inputs:
  # df_limit: in Hz, the frequency resolution requested
  # dt: in (t-r*)/M, the temporal resolution of the waveform that will be fft'ed
  # totalmass: total mass of the system considered, in units of solar mass
  # npoints: number of points in the waveform already
  # nlimit: an upper limit on the number of points for the fft
  # Returns:
  # (widen, df)
  # widen: factor by which to enlrge the domain (power of two)
  # df: resulting frequency resolution (Hz)

  scale = Scale()
  widen = 1
  dt = dt*scale*totalmass
  df = 1./(npoints*dt)

  while (df > df_limit):
    widen = widen*2
    if (nlimit and npoints*widen>nlimit):
      widen = widen/2
      print "Number of Points limit reached, stopping at: ", npoints*widen
      break
    df=1./(widen*npoints*dt)

  return widen,df

def WindowAsymHann(a,b,times):
  # Creates an asymmetric windowing function due to the asymmetric nature
  # of gravitational waveforms; left half uses hann window with parameter a
  # and right half uses hann window with parameter b

  # Input:
  # a: Hann window function parameter for left half
  # b: Hann window function parameter for right half
  # times: array of time values where to compute the window function

  tstart = times[0]
  tdiff  = times[-1]-times[0]
  return np.piecewise(times,[times<=tstart+a/2*tdiff, times>=tstart+tdiff*(1-b/2)], [.5*(1+np.cos(pi*(2/a*(times-tstart)/tdiff-1))),.5*(1-np.cos(pi*(2/b*(times-tstart)/tdiff-2/b+1))),1])

def WindowPlanckTaper(times, t1, t2, t3, t4):
  # Creates a Planck-taper function as a window for an FFT

  # Input:
  # times: array of time values where to compute the window function
  # t1: beginning of the windowing function; goes to 0 before t1
  # t2: end of first windowing interval; function is 1 between t2 and t3
  # t3: start of second windowing interval; function is 1 between t2 and t3
  # t4: end of windowing function; function is 0 after t4

  try:
    ind1 = np.nonzero(times>t1)[0][0]
  except IndexError:
    ind1 = len(times)
  try:
    ind2 = np.nonzero(times>=t2)[0][0]
  except IndexError:
    ind2 = len(times)
  try:
    ind3 = np.nonzero(times>t3)[0][0]
  except IndexError:
    ind3 = len(times)
  try:
    ind4 = np.nonzero(times>=t4)[0][0]
  except IndexError:
    ind4 = len(times)

  #print t1,t2,t3,t4
  #print ind1, ind2, ind3, ind4
  #print times[0], times[-1]

  y = +(t2-t1)/(times[ind1:ind2]-t1) + (t2-t1)/(times[ind1:ind2]-t2)
  z = +(t3-t4)/(times[ind3:ind4]-t3) + (t3-t4)/(times[ind3:ind4]-t4)
  window = np.empty(len(times))
  window[:ind1]     = 0.
  with warnings.catch_warnings():
    warnings.simplefilter('ignore', category=RuntimeWarning)
    window[ind1:ind2] = 1./(np.exp(y)+1)
  window[ind2:ind3] = 1.
  with warnings.catch_warnings():
    warnings.simplefilter('ignore', category=RuntimeWarning)
    window[ind3:ind4] = 1./(np.exp(z)+1)
  window[ind4:]     = 0.
  #window = np.piecewise(times, [times<=t1, times<t2, times<=t3, times<t4, times>=t4], [0., 1./(np.exp(y)+1.), 1., 1./(np.exp(z)+1.), 0.])
  return window

# same as WindowPlanckTaper, just different arguments
def KechanWindow(t, e1, e2, ta, tb):
    # the annoying -1 is due to differences in indexing in python and matlab
    wT = np.zeros(len(t))
    t1 = ta
    t2 = np.floor(ta*(1+2*e1))
    t3 = np.floor(tb*(1-2*e2))
    t4 = tb
    z1 = (t[t2-1] - t[t1-1])/(t - t[t1-1]) + (t[t2-1] - t[t1-1])/(t - t[t2-1])
    z2 = (t[t3-1] - t[t4-1])/(t - t[t3-1]) + (t[t3-1] - t[t4-1])/(t - t[t4-1])
    wT[t1-1:t2] = 1./(np.exp(z1[t1-1:t2]) + 1)
    wT[t2-1:t3] = 1.
    wT[t3-1:t4-1] = 1./(np.exp(z2[t3-1:t4-1]) + 1)
    return wT


def FFTWiden(waveform,totalpoints,npoints):
  # Computes the FFT of a waveform that needs to be padded with extra zeros
  # in order that the frequency resolution is fine enough.

  # Inputs:
  # waveform: will compute the fft of this waveform, must be uniform in time
  # totalpoints: the total points including the extra padding
  # npoints: length of the waveform without the extra padding

  wave=np.empty(totalpoints, dtype=complex)
  wave[0:npoints]=waveform
  wave[npoints:]=0.
  return np.fft.fft(wave) #Need to multiply by dt to normalize

def UnpackTwoFFT(f):
    # upacks the result of FFT of two real functions that were packed into real
    # and imaginary part of a complex function into two separate fourier
    # transformed arrays. This follows NR's twofft routine described in section
    # 12.3 of "Numerical Recipes in C++", Press and Teukolsky and Vetterling
    # and Flannery, 2nd edition, Cambdrige University Press, ISBN 0-521-75033-4

    # Inputs:
    # f : the fft of g + j*h (both g and ha are real)
    # Result:
    # (g(f), h(f)) : Tuple of Fourier transforms of g and h
    N = len(f)
    fc = np.empty_like(f)
    fs = np.empty_like(f)
    # 0 frequency coefficient
    fc[0] = f[0].real
    fs[0] = f[0].imag
    # all others, the Nyquist frequency coefficient sits in the middle and is
    # used twice
    fc[1:] = 1./2 * (f[1:N:1] + np.conj(f[N-1:0:-1]))
    fs[1:] = 1./2j * (f[1:N:1] - np.conj(f[N-1:0:-1]))
    return (fc,fs)

def NoiseCurveLimits(freqs, freq_min, freq_max):
  # Returns the indices corresponding to the minimum and maximum
  # frequencies requested.

  # Inputs:
  # freqs: array of uniformly spaced frequencies
  # freq_min: minimum frequency requested
  # freq_max: maximum frequency requested

  indexl = 0
  indexh = 0
  totalpoints = len(freqs)

  for i in range(totalpoints/2):
    if(freqs[i] >= freq_min):
      indexl=i-1
      break

  if(freqs[totalpoints/2-1] < freq_max):
    indexh = totalpoints/2
  else:
    for i in range(totalpoints/2):
      if(freqs[i] >= freq_max):
	indexh = i
	break

  print "Lower frequency bound: ", freqs[indexl]
  print "Upper frequency bound: ", freqs[indexh-1]

  return indexl, indexh

def SmoothedClipBelowFreq(waveform, total_mass,
    freqmin, smoothing_width, taper_width):
  # first computes the instantaneous frequency averaged over segments of
  # smoothing_width milliseconds then removes the data before the time this
  # frequency reaches freqmin using a one sided Hann window of width
  # taper_width milliseconds centered at this time. 
  #
  # Assumptions: * grid spacing in time is uniform
  #              * time in waveform is measured in total_mass M_sun
  min_omega =  (2.*pi) * freqmin
  dt = (waveform.T()[1] - waveform.T()[0])
  if(np.any(np.abs((waveform.T()[1:] - waveform.T()[:-1]) / dt - 1.) > 1e-8)):
    raise ValueError("Non uniform timesteps in waveform")
  dt *= total_mass * Scale()
  taper_width_points = np.floor(taper_width*1e-3/dt)
  # rolling averaged of angular frequency
  smoothing_width_points = np.ceil(smoothing_width*1e-3/dt)
  smoothing_window = np.ones(smoothing_width_points,dtype='float64') / \
                     smoothing_width_points
  smoothed_omega = np.convolve(smoothing_window,
                               np.gradient(abs(waveform.Arg(0)), dt),
                               mode='same')
  # beginning and end of kept region
  transition_index = np.nonzero(smoothed_omega >= min_omega)[0][0]
  # clip with smooth transition on the left side and hard cut on the right
  retval = PyGW.Waveform(waveform)
  for i in range(len(retval.Mag())):
    newmag = retval.Mag(i)
    newmag[transition_index-taper_width_points:transition_index+1] *= \
      hann(2*taper_width_points+1)[0:taper_width_points+1]
    # Mag() actually returns a copy of the data (since it is wrapped in a numpy
    # object by the SWIG wrapper)
    retval.SetMag(0,newmag)
  tmin = retval.T()[transition_index-taper_width_points]
  # RH: there seems to be a bug in Triton that causes SEGFAULTs when
  # DropBefore/DropAfter are used. I suspect there is an issue with the
  # returned Waveform& reference
  retval.DropBefore(tmin)
  return retval

"""
def InnerProduct(freqs, fwave1, fwave2, noisecurve):
  df = freqs[1]-freqs[0]
  integrand = 2.*abs(fwave1*fwave2.conjugate()+fwave1.conjugate()*fwave2)/(noisecurve**2)
  integmid  = np.interp(freqs[0:-1]+df/2,freqs,abs(integrand))
  simps=np.empty(len(integmid))
  for i in range(len(integmid)):
    simps[i] = integrand[i]+4.0*integmid[i]+integrand[i+1]
  return abs(sum(simps))*df/6

def Overlap(freqs,fwave1,fwave2,noisecurve):
  denom1 = InnerProduct(freqs,fwave1,fwave1,noisecurve)
  denom2 = InnerProduct(freqs,fwave2,fwave2,noisecurve)
  numer  = InnerProduct(freqs,fwave1,fwave2,noisecurve)

  overlap  = abs(numer)/((denom1*denom2)**(1./2.))
  mismatch = 1-overlap
  return overlap, mismatch
"""
