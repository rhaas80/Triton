def PlotWaveformOnSphere(W, OutputFileName, PlayFor = 30, PhiSteps = 200, ThetaSteps = 100, Part = 'real'):
    """
    PlotWaveformOnSphere(W, OutputFileName, PlayFor=30, 
                         PhiSteps=200, ThetaSteps=100, Part='real')
    
    This function takes the Waveform object W containing -2Ylm data,
    and plots the value of the waveform on the sphere.
    """
    
    from mpl_toolkits.mplot3d import Axes3D
    import matplotlib.pyplot as plt
    import numpy as np
    from scipy.special import sph_harm
    
    import GravitationalWaves as GW
    
    # try:
    #     W
    # except ValueError:
    #     W = GW.Waveform("/Users/boyle/Research/Data/q1_s0_s0/rMPsi4_ExtrapolatedN-1.dat", "MagArg")
    
    from SWSHs import SWSH
    
    PlayFor = 30 # seconds at 24 frames per second
    PhiSteps = 300
    ThetaSteps = 150
    Part = 'real'
    
    plt.ioff()
    
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    fig.tight_layout(pad=0.1)
    
    phi = np.linspace(0, 2 * np.pi, PhiSteps)
    theta = np.linspace(0, np.pi, ThetaSteps)
    
    x = np.outer(np.cos(phi), np.sin(theta))
    y = np.outer(np.sin(phi), np.sin(theta))
    z = np.outer(np.ones(np.size(phi)), np.cos(theta))
    
    philen = len(phi)
    thetalen = len(theta)
    
    colors = np.empty(x.shape, dtype=tuple)
    
    FrameIndex = -1
    TIndexStep = int((W.NTimes()+1)/(24*PlayFor))
    TotalFrames = W.NTimes()/TIndexStep
    for t in range(0, W.NTimes(), TIndexStep):
        print(str(t/TIndexStep) + ' of ' + str(TotalFrames))
        FrameIndex += 1
        values_c = np.zeros(x.shape, dtype=complex)
        for mode in range(W.NModes()):
            for Iphi in range(philen):
                values_c[Iphi] += array(SWSH(W.L(mode), W.M(mode), theta, np.ones_like(theta)*phi[Iphi])) * (W.Mag(mode, t) * exp(complex(0,W.Arg(mode,t))))
        
        mags = sqrt(values_c.real**2 + values_c.imag**2)
        maxmag = mags.max()
        values_r = values_c.real
        values_i = values_c.imag
        
        for Iphi in range(philen):
            for Itheta in range(thetalen):
                if Part.lower() == 'mag':
                    colors[Iphi, Itheta] = cm.jet( 0.5 * ( (mags[Iphi, Itheta]/maxmag) + 1.0 ) )
                elif Part.lower() == 'real':
                    colors[Iphi, Itheta] = cm.jet( 0.5 * ( (values_r[Iphi, Itheta]/maxmag) + 1.0 ) )
                elif Part.lower() == 'imag':
                    colors[Iphi, Itheta] = cm.jet( 0.5 * ( (values_i[Iphi, Itheta]/maxmag) + 1.0 ) )
                else:
                    raise NameError('Unknown Part: ' + Part)
        
        Surface = ax.plot_surface(x+2.5, y, z,  rstride=1, cstride=1, linewidth=0, antialiased=False, facecolors=colors)
        TimeText = ax.text2D(0.05, 0.95, r'$t = '+str(round(W.T(t),1))+'$', transform=ax.transAxes)
        
        #plt.show()
        
        plt.draw()
        
        if Part.lower() == 'mag':
            savefig(OutputFileName + '_Frame%04d.png' % FrameIndex)
        elif Part.lower() == 'real':
            savefig(OutputFileName + '_Frame%04d.png' % FrameIndex)
        elif Part.lower() == 'imag':
            savefig(OutputFileName + '_Frame%04d.png' % FrameIndex)
        else:
            raise NameError('Unknown Part: ' + Part)
        
        ax.collections.remove(Surface)
        TimeText.remove()
        
        
    plt.ion()
