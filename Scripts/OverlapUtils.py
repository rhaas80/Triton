from scipy.optimize import fmin
import numpy as np
from math import pi
import PyGW
import ctypes

# Compute the noise weighted inner product of two waves that are
# have been converted to their frequency domain
# Assumes that both waves and the noise curve are already aligned
# to a common, uniformly spaced array of frequencies and are 
# given only in the range to be integrated.
# Integrated using Trapazoidal rule to avoid extra interpolations

# Inputs:
# wave1: First of two frequency waves
# wave2: Second of two frequency waves
# noisesqrt: square root of the noise curve
# deltaf: frequency interval of each point
def NoiseWeightedFreqInnerProduct(wave1, wave2, noisesqrt, deltaf):

  integ = np.conjugate(wave1)*wave2

  integrand = 2.0*(integ.real)/(noisesqrt**2)
  length = len(integ)

  # The factor of 2 in front is canceled out by the 1/2 by trapezoid rule
  total = (integrand[0]+2*sum(integrand[1:-1])+integrand[-1])*deltaf
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
def OverlapMaxing(dt, freqs, fwave_ref, fwave_tem_c, fwave_tem_s, noise_sqrt):

  fwave_tem_c_shifted = fwave_tem_c*np.exp(2*pi*1j*freqs*dt)
  fwave_tem_s_shifted = fwave_tem_s*np.exp(2*pi*1j*freqs*dt)

  deltaf = freqs[1]-freqs[0]
  NWFIc = NoiseWeightedFreqInnerProduct(fwave_ref, fwave_tem_c_shifted, noise_sqrt, deltaf)
  NWFIs = NoiseWeightedFreqInnerProduct(fwave_ref, fwave_tem_s_shifted, noise_sqrt, deltaf)

  return -abs(np.sqrt(NWFIc**2 + NWFIs**2))


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
  wave1fNoise = wave1f/noisecurve
  wave2cfNoise = wave2cf/noisecurve
  wave2sfNoise = wave2sf/noisecurve

  set_ftol=abs(1.0e-9*OverlapMaxing(0,freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, 1.0))

  # Make sure fmin looks in both positive and negative deltat so it peeks
  # in both directions to find the best choice. Takes up time so can be
  # removed if reasonalbly confident it won't find a local minimum in the
  # wrong direction
  test_plus, test_plus_res, iterations, funcalls, warnflag   = fmin( OverlapMaxing, 0., args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, 1.0), maxiter = 5, ftol = set_ftol, full_output=True)
  test_minus, test_minus_res, iterations, funcalls, warnflag = fmin( OverlapMaxing, -0.0001, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, 1.0), maxiter = 5, ftol = set_ftol, full_output=True)

  if abs(test_plus_res) > abs(test_minus_res):
    t0 = test_plus
  else:
    t0 = test_minus

  dt_max, numerator, iterations, funcalls, warnflag = fmin( OverlapMaxing, t0, args=(freqs, wave1fNoise, wave2cfNoise, wave2sfNoise, 1.0), ftol=set_ftol, full_output=True)

  # Compute the phase shift corresponding to the maximized time shift
  dphi = np.arctan2(NoiseWeightedFreqInnerProduct(wave1fNoise,wave2sfNoise*np.exp(2*pi*1j*freqs*dt_max),1.0,df), NoiseWeightedFreqInnerProduct(wave1fNoise,wave2cfNoise*np.exp(2*pi*1j*freqs*dt_max),1.0,df))

  #if (-np.sin(dphi)-np.cos(dphi)>=0):
  #  dphi = dphi+pi

  # Compute the full waveform which maximizes the overlap
  h = (wave2cfNoise*np.cos(dphi)+np.sin(dphi)*wave2sfNoise)*np.exp(2*pi*1j*freqs*dt_max)

  overlap = abs(numerator)/((NoiseWeightedFreqInnerProduct(wave1fNoise,wave1fNoise,1.0,df)*NoiseWeightedFreqInnerProduct(h,h,1.0,df))**(1./2.))
  deltah = wave1fNoise-h
  rel_error = np.sqrt(1.0*NoiseWeightedFreqInnerProduct(deltah,deltah,1.0,df)/NoiseWeightedFreqInnerProduct(h,h,1.0,df))

  return dt_max, dphi, overlap, rel_error

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

def GWFrequencyInterval(Arg,indexm,dt,w_0,deltaw):
  # Computes the indices corresponding to the lower and upper bounds
  # of a frequency interval on a given phase array some time before merger

  # Inputs:
  # Arg: array of phase points uniformly spaced in time by dt
  # indexm: index correpsonding to merger
  # dt: time difference between two points in Arg
  # w_0: frequency at center of interval
  # deltaw: width of frequency interval
  deriv  = np.gradient(abs(Arg),dt)
  indexhi=0
  indexlo=0
  for i in range(indexm):
    if deriv[indexm-i]>=w_0*(1.+deltaw/2.):
      indexhi = indexm-i
    elif deriv[indexm-i]>=w_0*(1.-deltaw/2.):
      indexlo = indexm-i
    else:
      break
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
  deltaphi = width*(integrand[0] + 2.*sum(integrand[1:-1]) + integrand[-1])/2./(t2-t1)

  PN.AddToTime(deltat)
  PN.SetArg(0,PN.Arg(0)-deltaphi)
  return PN.HybridizeWith(NR,t1,t2)

def Hybridize(PN,NR,timem,t1,t2):
  # Generates a hybrid waveform from the two given waveforms

  # Inputs:
  # PN: The first waveform (left half of hybrid); a post-newtonian is often used
  # NR: The second waveform (right half of hybrid); generally an numerical waveform
  # timem: Time of merger (or max amplitude) in the NR waveform
  # t1: Start of the hybridization interval
  # t2: End of the hybridization interval
  

  PN.AddToTime(-PN.T()[-1]+timem)
  PN.AlignTo(NR,t1,t2)
  PN.AlignTo(NR,t1,t2) # don't know why, but seems to want it twice
  return PN.HybridizeWith(NR,t1,t2)

def NumberOfPointsPowerOfTwo(maxfreq,tdiff,totalmass,nlimit):
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
  scale = .00000492686088

  # Extra factor of 1/2 since np.fft.fft also gives negative frequencies
  while (maxfreq>npoints/tdiff/scale/totalmass/2):
    npoints=npoints*2
    if(npoints>nlimit):
      npoints=npoints/2
      print "Number of Points limit reached, stopping at: ", npoints
      break
    dt = 1.0*tdiff/(npoints-1)

  return npoints,dt

def WideningFactorPowerOfTwo(df_limit,dt,totalmass,npoints,nlimit):
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

  scale = .00000492686088
  widen = 1
  dt = dt*scale*totalmass
  df = 1./(npoints*dt)

  while (df > df_limit):
    widen = widen*2
    if (npoints*widen>nlimit):
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

  ind1 = np.argmin(abs(times-t1))
  if (times[ind1]>=t1):
    ind1=ind1-1

  ind2 = np.argmin(abs(times-t2))
  if (times[ind2]<t2):
    ind2=ind2+1

  ind3 = np.argmin(abs(times-t3))
  if (times[ind3]>=t3):
    ind3=ind3-1

  ind4 = np.argmin(abs(times-t4))
  if (times[ind4]<t4):
    ind4=ind4+1

  y = (t2-t1)/(times[ind1:ind2]-t1) + (t2-t1)/(times[ind1:ind2]-t2)
  z = +(t3-t4)/(times[ind3:ind4]-t3) + (t3-t4)/(times[ind3:ind4]-t4)
  window = np.empty(len(times))
  window[:ind1]     = 0.
  window[ind1:ind2] = 1./(np.exp(y)+1)
  window[ind2:ind3] = 1.
  window[ind3:ind4] = 1./(np.exp(z)+1)
  window[ind4:]     = 0.
  #window = np.piecewise(times, [times<=t1, times<t2, times<=t3, times<t4, times>=t4], [0., 1./(np.exp(y)+1.), 1., 1./(np.exp(z)+1.), 0.])
  return window

def FFTWiden(waveform,totalpoints,npoints):
  # Computes the FFT of a waveform that needs to be padded with extra zeros
  # in order that the frequency resolution is fine enough.

  # Inputs:
  # waveform: will compute the fft of this waveform, must be uniform in time
  # totalpoints: the total points including the extra padding
  # npoints: length of the waveform without the extra padding

  wave=np.zeros(totalpoints, dtype=complex)
  wave[0:npoints]=(waveform)
  return np.fft.fft(wave) #Need to multiply by dt to normalize

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
