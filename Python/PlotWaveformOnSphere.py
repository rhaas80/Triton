def SphereCoordinates(ThetaSteps=100, PhiSteps=200) :
    """
    Returns a tuple of numpy arrays containing the appropriate
    vartheta and varphi coordinates on a sphere.
    """
    import numpy
    vartheta = numpy.linspace(0, numpy.pi, ThetaSteps)
    varphi = numpy.linspace(0, 2 * numpy.pi, PhiSteps)
    return (vartheta, varphi)


def SpherePoints(vartheta, varphi, Radius=1) :
    """
    Simply returns the (x,y,z) coordinates of the points given by
    spherical coordinates (vartheta, varphi).
    """
    import numpy
    x = Radius*numpy.outer(numpy.sin(vartheta), numpy.cos(varphi))
    y = Radius*numpy.outer(numpy.sin(vartheta), numpy.sin(varphi))
    z = Radius*numpy.outer(numpy.cos(vartheta), numpy.ones(numpy.size(varphi)))
    return (x,y,z)


def WaveformDataOnSphere(W, TimeIndex, vartheta, varphi) :
    """
    Given the Waveform object W, some integer TimeIndex, and spherical
    coordinates (vartheta, varphi), this returns a numpy array of the
    complex data evaluated at those spherical coordinates.
    """
    from SWSHs import SWSH
    import numpy
    nmodes = W.NModes()
    varthetalen = len(vartheta)
    varphilen = len(varphi)
    ComplexDataOnSphere = numpy.zeros([varthetalen, varphilen], dtype=complex)
    for mode in range(nmodes) :
        for varthetaIndex in range(varthetalen) :
            TestA = numpy.ones_like(varphi)*vartheta[varthetaIndex]
            TestB = varphi
            ComplexDataOnSphere[varthetaIndex] += \
                array(SWSH(W.L(mode), W.M(mode), numpy.ones_like(varphi)*vartheta[varthetaIndex], varphi)) \
                * (W.Mag(mode, TimeIndex) * exp(complex(0,W.Arg(mode,TimeIndex))))
    return ComplexDataOnSphere


def WaveformColorsOnSphere(WaveformData, Normalization=1, Quantities=['real', 'imag', 'mag']) :
    """
    Given an array of complex WaveformData evaluated at points
    (presumably on a sphere), this function converts those values
    (normalized by the Normalization constant) into colors.  By
    default, the real and imaginary parts and magnitude are evaluated.
    """
    import matplotlib.cm
    Colors = []
    varthetalen = WaveformData.shape[0]
    varphilen = WaveformData.shape[1]
    for quantity in Quantities :
        colors = numpy.empty(WaveformData.shape, dtype=tuple)
        if quantity.lower() == 'real' :
            colors = matplotlib.cm.jet( 0.5 * ( (WaveformData.real/Normalization) + 1.0 ) );
        elif quantity.lower() == 'imag' :
            colors = matplotlib.cm.jet( 0.5 * ( (WaveformData.imag/Normalization) + 1.0 ) );
        elif quantity.lower() == 'mag' :
            colors = matplotlib.cm.jet( 0.5 * ( (abs(WaveformData)/Normalization) + 1.0 ) );
        else :
            raise NameError('Unknown quantity: "' + quantity + '"')
        Colors.append(colors)
    return Colors


def PlotWaveformOnSphere(W, TimeIndex, Normalization=0, Quantities=['real', 'imag', 'mag'],
                         ThetaSteps=100, PhiSteps=200, vartheta=(), varphi=(), x=(), y=(), z=()) :
    from mpl_toolkits.mplot3d import Axes3D
    import matplotlib.pyplot
    import numpy
    if ((vartheta.size==0) or (varphi.size==0)) :
        vartheta, varphi = SphereCoordinates(ThetaSteps, PhiSteps)
    ComplexDataOnSphere = WaveformDataOnSphere(W, TimeIndex, vartheta, varphi)
    if (Normalization<=0.0) : Normalization = abs(ComplexDataOnSphere).max()
    Colors = WaveformColorsOnSphere(ComplexDataOnSphere, Normalization, Quantities)
    xyzshape = (len(vartheta),len(varphi))
    if ((x.size==0) or (y.size==0) or (z.size==0) or (x.shape!=xyzshape) or (y.shape!=xyzshape) or (z.shape!=xyzshape)) :
        x,y,z = SpherePoints(vartheta, varphi)
    Figs = []
    for i,quantity in enumerate(Quantities) :
        fig = matplotlib.pyplot.figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.set_xticks(())
        ax.set_yticks(())
        ax.set_zticks(())
        fig.tight_layout(pad=0.1)
        Surface = ax.plot_surface(x, y, z,  rstride=1, cstride=1, linewidth=0, antialiased=False, facecolors=Colors[i])
        TimeText = ax.text2D(0.05, 0.92, r'$t = '+str(round(W.T(TimeIndex),1))+'$\n'+quantity, transform=ax.transAxes)
        matplotlib.pyplot.draw()
        Figs.append(fig)
    return Figs


def AnimateWaveformOnSphere(W, OutputFileName, TimeSteps = 500, PhiSteps = 200, ThetaSteps = 100, Quantities=['real', 'imag', 'mag'], DPI=250) :
    import matplotlib.pyplot
    import numpy
    
    vartheta, varphi = SphereCoordinates(ThetaSteps, PhiSteps)
    x,y,z = SpherePoints(vartheta, varphi)
    Normalization = abs(WaveformDataOnSphere(W, W.Peak22TimeIndex(), vartheta, varphi)).max()
    print("Normalization = ", Normalization)
    
    plt.ioff()
    TIndexStep = W.NTimes()/int(TimeSteps)
    for FrameIndex,t in enumerate(range(0, W.NTimes(), TIndexStep)) :
        print(str(t/TIndexStep) + ' of ' + str(TimeSteps))
        Figs = PlotWaveformOnSphere(W, t, Normalization, Quantities, vartheta=vartheta, varphi=varphi, x=x, y=y, z=z)
        for i in range(len(Figs)) :
            Figs[i].savefig(OutputFileName + '_' + Quantities[i].lower() + '_Frame%04d.png' % FrameIndex, dpi=DPI, transparent=True)
    plt.ion()
    


def AnimateWaveformOnSphere_OLD(W, OutputFileName, PlayFor = 30, PhiSteps = 200, ThetaSteps = 100, Part = 'real') :
    """
    AnimateWaveformOnSphere(W, OutputFileName, PlayFor=30, 
                            PhiSteps=200, ThetaSteps=100, Part='real')
    
    This function takes the Waveform object W containing -2Ylm data,
    and plots the value of the waveform on the sphere.
    
    The output files are stored in <FileName>_real_Frame0001.png, etc.
    Assemble these into an animated gif using the Imagemagick
    'convert' utility, with a command line like
      convert -delay 10 -loop 4 q1_real_Frame*.png q1_real.gif
    """
    
    DPI = 200 # savefig resolution
    
    from mpl_toolkits.mplot3d import Axes3D
    import matplotlib.pyplot as plt
    import numpy as np
    from SWSHs import SWSH
    
    plt.ioff()
    
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.set_xticks(())
    ax.set_yticks(())
    ax.set_zticks(())
    fig.tight_layout(pad=0.1)
    
    phi = np.linspace(0, 2 * np.pi, PhiSteps)
    theta = np.linspace(0, np.pi, ThetaSteps)
    
    #     x = np.outer(np.sin(theta), np.cos(phi))
    #     y = np.outer(np.sin(theta), np.sin(phi))
    #     z = np.outer(np.cos(theta), np.ones(np.size(phi)))
    x = np.outer(np.cos(phi), np.sin(theta))
    y = np.outer(np.sin(phi), np.sin(theta))
    z = np.outer(np.ones(np.size(phi)), np.cos(theta))
    
    philen = len(phi)
    thetalen = len(theta)
    
    colors = np.empty(x.shape, dtype=tuple)
    
    FrameIndex = -1
    TIndexStep = int((W.NTimes()+1)/(24*PlayFor))
    TotalFrames = W.NTimes()/TIndexStep
    for t in range(0, W.NTimes(), TIndexStep) :
        print(str(t/TIndexStep) + ' of ' + str(TotalFrames))
        FrameIndex += 1
        values_c = np.zeros(x.shape, dtype=complex)
        for mode in range(W.NModes()) :
            for Iphi in range(philen) :
                values_c[Iphi] += array(SWSH(W.L(mode), W.M(mode), theta, np.ones_like(theta)*phi[Iphi])) * (W.Mag(mode, t) * exp(complex(0,W.Arg(mode,t))))
        
        mags = sqrt(values_c.real**2 + values_c.imag**2)
        maxmag = mags.max()
        values_r = values_c.real
        values_i = values_c.imag
        
        for Iphi in range(philen) :
            for Itheta in range(thetalen) :
                if Part.lower() == 'mag' :
                    colors[Iphi, Itheta] = cm.jet( 0.5 * ( (mags[Iphi, Itheta]/maxmag) + 1.0 ) )
                elif Part.lower() == 'real' :
                    colors[Iphi, Itheta] = cm.jet( 0.5 * ( (values_r[Iphi, Itheta]/maxmag) + 1.0 ) )
                elif Part.lower() == 'imag' :
                    colors[Iphi, Itheta] = cm.jet( 0.5 * ( (values_i[Iphi, Itheta]/maxmag) + 1.0 ) )
                else :
                    raise NameError('Unknown Part: ' + Part)
        
        Surface = ax.plot_surface(x+2.5, y, z,  rstride=1, cstride=1, linewidth=0, antialiased=False, facecolors=colors)
        TimeText = ax.text2D(0.05, 0.95, r'$t = '+str(round(W.T(t),1))+'$', transform=ax.transAxes)
        plt.draw()
        savefig(OutputFileName + '_' + Part.lower() + '_Frame%04d.png' % FrameIndex, dpi=DPI)
        ax.collections.remove(Surface)
        TimeText.remove()
        
        
    plt.ion()
