import numpy as np
import PyGW
import PyGW.plot
import matplotlib
import math
import ctypes

def int32_to_uint32(i):
  return ctypes.c_uint32(i).value

scale = .00000492686088
totalmass = 1.643704202509977*2
q1=1.
delta1 = (q1-1.)/(q1+1)
mode   = PyGW.MatrixInt(1,2,2)

love1 = 0.07124843942665074
love2 = love1
compact1 = 0.16001855052369648
compact2 = compact1

PN4  = PyGW.Waveform('TaylorT4',delta1,0.,0.,.01**(1./3.),mode)
PN4T = PyGW.Waveform('TaylorT4Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN4T = PN4T[4]

PN2  = PyGW.Waveform('TaylorT2',delta1,0.,0.,.01**(1./3.),mode)
PN2T = PyGW.Waveform('TaylorT2Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN2T = PN2T[4]

PN1  = PyGW.Waveform('TaylorT1',delta1,0.,0.,.01**(1./3.),mode)
PN1T = PyGW.Waveform('TaylorT1Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN1T = PN1T[4]

### Plot comparison
"""
figure(1);PN4.plot('Mag');PN4T.plot('Mag');
figure(2);PN4.plot('Arg');PN4T.plot('Arg');

figure(3);PN2.plot('Mag');PN2T.plot('Mag');
figure(4);PN2.plot('Arg');PN2T.plot('Arg');

figure(5);PN1.plot('Mag');PN1T.plot('Mag');
figure(6);PN1.plot('Arg');PN1T.plot('Arg');
"""
### If T2Tidal bends backwards on itself, use these commands:
pn2tmax = argmax(PN2T.T())
PN2T.Interpolate(PN2T.T()[:pn2tmax])
#Restricting the domain with the Interpolate function seems to work perfectly well
"""
PN2Ttest = PyGW.Waveform('TaylorT2Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN2Ttest = PN2Ttest[4]
sum(abs(PN2Ttest.Mag(0)[:pn2tmax]-PN2T.Mag(0))+abs(PN2Ttest.Arg(0)[:pn2tmax]-PN2T.Arg(0)))

figure(3);PN2.plot('Mag');PN2Ttest.plot('Mag');PN2T.plot('Mag');
figure(4);PN2.plot('Arg');PN2Ttest.plot('Arg');PN2T.plot('Arg');
"""
### Sums = 0 if waveforms are equivalent (use when love1=love2=0; otherwise likely get errors)
sum(abs(PN1T.Mag(0)-PN1.Mag(0))+abs(PN1T.Arg(0)-PN1.Arg(0)))
sum(abs(PN2T.Mag(0)-PN2.Mag(0))+abs(PN2T.Arg(0)-PN2.Arg(0)))
sum(abs(PN4T.Mag(0)-PN4.Mag(0))+abs(PN4T.Arg(0)-PN4.Arg(0)))

### Compare the PN with and without tidal terms
figure(11);
plot(PN1.T(),PN1.Mag(0),'k');
plot(PN2.T(),PN2.Mag(0),'r');
plot(PN4.T(),PN4.Mag(0),'b');
plot(PN1T.T(),PN1T.Mag(0),'k--');
plot(PN2T.T(),PN2T.Mag(0),'r--');
plot(PN4T.T(),PN4T.Mag(0),'b--');

figure(12);
plot(PN1.T(),PN1.Arg(0),'k');
plot(PN2.T(),PN2.Arg(0),'r');
plot(PN4.T(),PN4.Arg(0),'b');
plot(PN1T.T(),PN1T.Arg(0),'k--');
plot(PN2T.T(),PN2T.Arg(0),'r--');
plot(PN4T.T(),PN4T.Arg(0),'b--');

# Try aligning the waveforms
PN4T.AlignTo(PN4,PN4.T(0)+1000,PN4T.T(0)+2000)
PN2T.AlignTo(PN4,PN4.T(0)+1000,PN4T.T(0)+2000)
PN2.AlignTo(PN4,PN4.T(0)+1000,PN4T.T(0)+2000)
PN1T.AlignTo(PN4,PN4.T(0)+1000,PN4T.T(0)+2000)
PN1.AlignTo(PN4,PN4.T(0)+1000,PN4T.T(0)+2000)

figure(13);
plot(PN1.T(),PN1.Mag(0),'k');
plot(PN2.T(),PN2.Mag(0),'r');
plot(PN4.T(),PN4.Mag(0),'b');
plot(PN1T.T(),PN1T.Mag(0),'k--');
plot(PN2T.T(),PN2T.Mag(0),'r--');
plot(PN4T.T(),PN4T.Mag(0),'b--');

figure(14);
plot(PN1.T(),PN1.Arg(0),'k');
plot(PN2.T(),PN2.Arg(0),'r');
plot(PN4.T(),PN4.Arg(0),'b');
plot(PN1T.T(),PN1T.Arg(0),'k--');
plot(PN2T.T(),PN2T.Arg(0),'r--');
plot(PN4T.T(),PN4T.Arg(0),'b--');

### Test symmetry between the objects (ensure I coded that part up right)
love1 = 0.07124843942665074
love2 = 2*love1
compact1 = 0.16001855052369648
compact2 = 2*compact1

PN4Ta = PyGW.Waveform('TaylorT4Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN4Ta = PN4Ta[4]
PN2Ta = PyGW.Waveform('TaylorT2Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN2Ta = PN2Ta[4]
PN1Ta = PyGW.Waveform('TaylorT1Tidal',delta1,0.,0.,.01**(1./3.),love1,love2,compact1,compact2)
PN1Ta = PN1Ta[4]

PN4Tb = PyGW.Waveform('TaylorT4Tidal',delta1,0.,0.,.01**(1./3.),love2,love1,compact2,compact1)
PN4Tb = PN4Tb[4]
PN2Tb = PyGW.Waveform('TaylorT2Tidal',delta1,0.,0.,.01**(1./3.),love2,love1,compact2,compact1)
PN2Tb = PN2Tb[4]
PN1Tb = PyGW.Waveform('TaylorT1Tidal',delta1,0.,0.,.01**(1./3.),love2,love1,compact2,compact1)
PN1Tb = PN1Tb[4]

sum(abs(PN1Ta.Mag(0)-PN1Tb.Mag(0))+abs(PN1Ta.Arg(0)-PN1Tb.Arg(0)))
sum(abs(PN2Ta.Mag(0)-PN2Tb.Mag(0))+abs(PN2Ta.Arg(0)-PN2Tb.Arg(0)))
sum(abs(PN4Ta.Mag(0)-PN4Tb.Mag(0))+abs(PN4Ta.Arg(0)-PN4Tb.Arg(0)))