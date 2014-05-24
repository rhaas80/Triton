import scipy.optimize, scipy.interpolate
import numpy

import SpecError


def HybridizationFunctional(p, 
                            tNR_cut, phiNR_cut, AmpNR_cut,
                            tPN, phiPN, AmpPN, 
                            matching_type,
                            ForLeastSq=1):
    """Time-shift post-Newtonian waveform, interpolate to NR data-points,
    and return difference.  This function is used in the least-squares
    matching between PN and NR.
    
     p   -- parameters being optimized
            p[0]=time-shift, p[1]=phase-shift 
     tNR, phiNR, AmpNR -- time, phase and amplitude of NR waveform.
            These arrays must have been cut to include only data-points
            inside the integration interval being minimized.
     tPN, phiPN, AmpPN -- time, phase and amplitude of post-Newtonian waveform 
            This data-set is interpolated to tNR, so it must be sufficiently
            long to completely overlap tNR.
     matching_type -- 1 (delta-phase)
                      2 |h1-h2|
            
     RETURNS:  
       if ForLeastSq!=1 -- see matching_type
       otherwise"       -- a touple: (rms difference, intphiPN-phiNR, (intAmpPN-AmpNR)/AmpNR)"""

#    print "HybridizationFunctional p=", p
    shiftedtPN=tPN+p[0]
    shiftedphiPN=phiPN+p[1]

    # interpolate PN-phase to NR datapoints
    if(shiftedtPN[-1]<tNR_cut[-1]):
        print "Warning! HybridizationFunctional: TimeShift=%g results in PN-waveform\n"\
            "ending before end of matching interval tPN_end=%g, t_max=%g"%\
        (p[0], shiftedtPN[-1], tNR_cut[-1])
              
        intphiPN=0.*phiNR_cut+(shiftedtPN[-1]-tNR_cut[-1])
    else:
        # there's a memory leak somewhere.  Feeding in the full PN waveforms
        # into interp1d results in out-of-memory-errors for long waveforms. 
        idx=(shiftedtPN-(tNR_cut[0]-100))*(shiftedtPN-(tNR_cut[-1]+100))<0
        #interp=scipy.interpolate.interp1d(shiftedtPN[idx], shiftedphiPN[idx], kind='cubic', copy=False)
        #intphiPN=interp(tNR_cut)
        tck = scipy.interpolate.splrep(shiftedtPN[idx], shiftedphiPN[idx])
        intphiPN=scipy.interpolate.splev(tNR_cut, tck)
        del tck
        #print "interpolated intphiPN, intphiPN.shape=", intphiPN.shape
        #del interp
        #interp=scipy.interpolate.interp1d(shiftedtPN[idx], AmpPN[idx], kind='cubic', copy=False)
        #intAmpPN=interp(tNR_cut)
        #del interp
        tck = scipy.interpolate.splrep(shiftedtPN[idx], AmpPN[idx])
        intAmpPN=scipy.interpolate.splev(tNR_cut, tck)
        del tck
    if(matching_type==1):
        temp=intphiPN-phiNR_cut
    else:
        if(matching_type==2):
            temp=numpy.sqrt( (intAmpPN*numpy.cos(intphiPN) 
                              - AmpNR_cut*numpy.cos(phiNR_cut))**2
                             +(intAmpPN*numpy.sin(intphiPN) 
                               - AmpNR_cut*numpy.sin(phiNR_cut))**2
                             )
        else:
            SpecHybrids.Error("unknown matching_type %i"%mstching_type)
                
    if(ForLeastSq):
 #       print "returning mean(temp)=",numpy.sqrt((temp**2).mean())
        return temp
    # compute root-mean-square
    res=numpy.sqrt( (temp**2).mean()) 
 #   print "returning res=", res
    return (res,intphiPN-phiNR_cut, (intAmpPN-AmpNR_cut)/AmpNR_cut)


################################################################

def ComputeOmega(t, phase):
    omega=phase.copy()
    omega[1:-1] = (phase[2:]-phase[0:-2])/(t[2:]-t[0:-2])
    # attach less accurate first/last point, to avoid pains
    # with different sized arrays
    #omega[0] = (phase[1]-phase[0])/(t[1]-t[0])
    #omega[-1] = (phase[-1]-phase[-2])/(t[-1]-t[-2])
    omega[0]=omega[1]
    omega[-1]=omega[-2]
    return omega
    
    
def Find_tmin_tmax(tNR, phiNR, omega_min, omega_max):
    omegaNR=ComputeOmega(tNR, phiNR)

### find indices over which we'll be averaging
    idx_min=numpy.where(omegaNR>omega_min)[0][0]
    idx_max=numpy.where(omegaNR>omega_max)[0][0]
    idx=range(idx_min,idx_max+1)
    tNR_min=tNR[idx_min]
    tNR_max=tNR[idx_max]
    return (idx, tNR_min, tNR_max)


# perform least-square fit of PN to NR, return [DeltaT, DeltaPhi]
# to be added to PN-wave form for best-fit.
def LeastSquareFit(tNR, phiNR, AmpNR,
                   tPN, phiPN, AmpPN, 
                   omega_min, omega_max,
                   matching_type):
    
    idx,tmin,tmax=Find_tmin_tmax(tNR,phiNR, omega_min, omega_max)
### find start frequency in PN waveform, to get
### initial guesses for minimization
    omegaPN=ComputeOmega(tPN, phiPN)
    
    idx_min=numpy.where(omegaPN>omega_min)[0][0]
    Dt0=tNR[idx[0]]-tPN[idx_min]
    Dphase0=phiNR[idx[0]]-phiPN[idx_min]
    p_in=[Dt0, Dphase0]  # params over which we minimize
    
#### NOTE TO HARALD
# Given h(t) = A e^(i phi), how can one compute A and phi of Psi4=d^2h/dt^2
#
# A e^{i phi}
# (A' + i A omega) e^{i phi} 
# (A'' + 2 i A' omega + i A omega'  -A omega^2) e^{i phi} 
# phase_{Psi4} = phase_h + arg(A''-A omega^2) + i (2A' omega + A omega') 
#### END NOTE TO HARALD
    
    tNR_cut=tNR[idx]
    phiNR_cut=phiNR[idx]
    AmpNR_cut=AmpNR[idx]
    p_out,success=scipy.optimize.leastsq(HybridizationFunctional, p_in, args=(tNR_cut, phiNR_cut, AmpNR_cut, tPN, phiPN, AmpPN, matching_type))
    
    res_in=HybridizationFunctional(p_in,
                                   tNR_cut,phiNR_cut,AmpNR_cut,
                                   tPN,phiPN,AmpPN,matching_type,
                                   ForLeastSq=0)
    res_out=HybridizationFunctional(p_out,
                                    tNR_cut,phiNR_cut,AmpNR_cut,
                                    tPN,phiPN,AmpPN,
                                    matching_type,
                                    ForLeastSq=0)

    #print "p_in=", p_in, "res_in=",res_in[0]
    #print "p_out=", p_out, "res_out=",res_out[0]
    return p_out,res_out[0]

################################################################

# simply adaptor function to use the generic HybridizationFunctional
# for 1-D minimizations over DeltaPhi.
def HybridizationFunctional_FixedDeltaT(p, 
                                        tNR_cut, phiNR_cut, AmpNR_cut,
                                        tPN, phiPN, AmpPN, 
                                        matching_type,
                                        DeltaT):
    
    return HybridizationFunctional([DeltaT, p[0]], 
                                   tNR_cut, phiNR_cut, AmpNR_cut,
                                   tPN, phiPN, AmpPN, 
                                   matching_type)



# perform least-square fit of PN to NR, fitting only DeltaPhi.  Returns [DeltaPhi]
# which is to be added to PN wave-form for best fit, given DeltaT.
def LeastSquareFit_FixedDeltaT(tNR, phiNR, AmpNR,
                               tPN, phiPN, AmpPN, 
                               omega_min, omega_max,
                               DeltaT,
                               matching_type):
    idx,tmin,tmax=Find_tmin_tmax(tNR,phiNR, omega_min, omega_max)
### find start frequency in PN waveform, to get
### initial guesses for minimization
    omegaPN=ComputeOmega(tPN, phiPN)
    
    idx_min=numpy.where(omegaPN>omega_min)[0][0]
    Dt0=tNR[idx[0]]-tPN[idx_min]
    Dphase0=phiNR[idx[0]]-phiPN[idx_min]
    p_in=[Dphase0]  # params over which we minimize
    
    tNR_cut=tNR[idx]
    phiNR_cut=phiNR[idx]
    AmpNR_cut=AmpNR[idx]
    p_out,success=scipy.optimize.leastsq(HybridizationFunctional_FixedDeltaT, p_in, args=(tNR_cut, phiNR_cut, AmpNR_cut, tPN, phiPN, AmpPN, matching_type, DeltaT))
    
    res_in=HybridizationFunctional([DeltaT, p_in[0]],
                                   tNR_cut,phiNR_cut,AmpNR_cut,
                                   tPN,phiPN,AmpPN,matching_type,
                                   ForLeastSq=0)
    res_out=HybridizationFunctional([DeltaT, p_out],
                                    tNR_cut,phiNR_cut,AmpNR_cut,
                                    tPN,phiPN,AmpPN,
                                    matching_type,
                                    ForLeastSq=0)

    #print "p_in=", p_in, "res_in=",res_in[0]
    #print "p_out=", p_out, "res_out=",res_out[0]
    return p_out,res_out[0]


################################################################
# Perform least squares fit, make nice plot, including
# contor plot varying DeltaT, DeltaPhi.
def PerformFitWithContourPlot(tNR, phiNR, tPN, phiPN, omega_min, omega_max):

    # find index range, do some diagnostic output
    idx, tNR_min, tNR_max=Find_tmin_tmax(tNR, phiNR, omega_min, omega_max)
    print "len(idx)=",len(idx)
    phiNR_min=phiNR[idx[0]]
    phiNR_max=phiNR[idx[-1]]
    print
    print "Matching interval %g<omega<%g  -->  %g<t_NR<%g"%(omega_min, omega_max, tNR_min, tNR_max)
    print "tmax-tmin=%g, N_GWcycles=%g, N_datapoints=%i"%(tNR_max-tNR_min,  (phiNR_max-phiNR_min)/2/pi,idx[-1]-idx[0]+1)  

    # do work
    p,res =LeastSquareFit(tNR, phiNR, tPN, phiPN, omega_min, omega_max)
    print "Best fit DeltaT=%g, DeltaPhi=%g with rms-residual=%0.2g"%(p[0],p[1], res)

#### NOTE TO HARALD
# Given h(t) = A e^(i phi), how can one compute A and phi of Psi4=d^2h/dt^2
#
# A e^{i phi}
# (A' + i A omega) e^{i phi} 
# (A'' + 2 i A' omega + i A omega'  -A omega^2) e^{i phi} 
# phase_{Psi4} = phase_h + arg(A''-A omega^2) + i (2A' omega + A omega') 
#### END NOTE TO HARALD
    
    

    #### GENERATE PLOT #####
    tNR_cut=tNR[idx]
    phiNR_cut=phiNR[idx]
    #res_in=HybridizationFunctional(p_in,tNR_cut,phiNR_cut,tPN,phiPN,ForLeastSq=0)
    res_out=HybridizationFunctional(p,tNR[idx],phiNR[idx],tPN,phiPN,ForLeastSq=0)

    #print "p_in=", p_in, "res_in=",res_in[0]
    
    ### Phase-difference for best-fit params
    subplot(2,1,1)
    plot(tNR_cut, res_out[1])
    title("phase difference PN-NR, omega_match=[%g,%g]\nDeltaT=%g, DeltaPhi=%g, rms-difference=%0.2g"%(omega_min,omega_max,p[0], p[1], res_out[0]))
    
### generate contour plot around best-fit params
    
    deltat = numpy.arange(-15.0, 15.0, 0.5)
    deltaphi = numpy.arange(-4*res_out[0], 4.01*res_out[0], 0.5*res_out[0])
    PHI,T = numpy.meshgrid(deltaphi, deltat)
    RES=T.copy()
    for Ti in range(0,deltat.shape[0]):
        for phii in range(0,deltaphi.shape[0]):
            RES[Ti,phii],bla=HybridizationFunctional([p[0]+deltat[Ti],
                                                      p[1]+deltaphi[phii]+deltat[Ti]*0.5*(omega_min+omega_max) 
                                                      ]
                                                     ,tNR_cut,phiNR_cut,tPN,phiPN,ForLeastSq=0)
            
            
    # sanity check, because minimization will proceed even if 
    # PN waveform is too short
    if(tPN[-1]+p[0] < tNR_cut[-1]+15):
        pylab.text(0.5*(tNR_max+tNR_min),0, "WARNING! PN-WAVFEFORM SHORT",
                   horizontalalignment='center',
                   verticalalignment='center', color='red',size='x-large'
                   )


    subplot(2,1,2)
#title("rms contour plot around best fit")
    CS=pylab.contour(T,PHI,RES)
    pylab.clabel(CS, inline=1, fontsize=10)
    pylab.gca().set_xlabel("dT")
    pylab.gca().set_ylabel("dphi+dT*omega_avg")
    plot([0],[0],'ok')
    pylab.text(0,0,"%0.2g"%(res_out[0]))

    # sanity check, because minimization will proceed even if 
    # PN waveform is too short
    if(tPN[-1]+p[0] < tNR_cut[-1]+10):
        pylab.text(0,0, "WARNING! PN-WAVFEFORM SHORT",
                   horizontalalignment='center',
                   verticalalignment='center', color='red',size='x-large'
                   )

    savefig("Hybrid.pdf")

#################################################################

def SurveyMatchingInterval(tNR, phiNR, tPN, phiPN, bound_min, bound_max):

    omega1=numpy.arange(bound_min, (bound_max, bound_max-bound_min)/10.0001)
    omega2=numpy.arange(bound_min, (bound_max, bound_max-bound_min)/10.0001)
    OMEGA1,OMEGA2=numpy.meshgrid(omega1, omega2)
    RES=OMEGA1.copy()
    DELTAT=OMEGA1.copy()
    for i1 in range(0,omega1.shape[0]):
        for i2 in range(0,omega2.shape[0]):

            if(omega1[i1]<omega2[i2]):
                omega_min=omega1[i1]
                omega_max=omega2[i2]
            else:
                omega_max=omega1[i1]
                omega_min=omega2[i2]
            p,res=LeastSquareFit(tNR, phiNR, tPN, phiPN, omega_min, omega_max)
            RES[i1,i2]=res
            DELTAT[i1,i2]=p[0]
            
    subplot(2,1,1)
#title("rms contour plot around best fit")
    CS=pylab.contour(OMEGA1, OMEGA2, DELTAT)
    pylab.clabel(CS, inline=1, fontsize=10)
    pylab.gca().set_xlabel("omega1")
    pylab.gca().set_ylabel("omega2")


    subplot(2,1,2)
#title("rms contour plot around best fit")
    CS=pylab.contour(OMEGA1, OMEGA2, RES)
    pylab.clabel(CS, inline=1, fontsize=10)
    pylab.gca().set_xlabel("omega1")
    pylab.gca().set_ylabel("omega2")

    savefig("SurveyMatchingInterval.pdf")

 ################################################################


