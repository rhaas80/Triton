"""
This module provides various utilities for plotting Waveform objects
with spherical-harmonic data on spheres.

"""


from numpy import linspace
from numpy import pi
def sphere_coordinates(ThetaSteps=100, PhiSteps=200) :
    """
    Returns a tuple of numpy arrays containing the appropriate
    vartheta and varphi coordinates on a sphere.
    """
    vartheta = linspace(0, pi, ThetaSteps)
    varphi = linspace(0, 2 * pi, PhiSteps)
    return (vartheta, varphi)


from numpy import outer
from numpy import sin
from numpy import cos
from numpy import ones
def sphere_points(vartheta, varphi, Radius=1) :
    """
    Simply returns the (x,y,z) coordinates of the points given by
    spherical coordinates (vartheta, varphi).
    """
    x = Radius*outer(sin(vartheta), cos(varphi))
    y = Radius*outer(sin(vartheta), sin(varphi))
    z = Radius*outer(cos(vartheta), ones(size(varphi)))
    return (x,y,z)


from SWSHs import SWSH
from numpy import array
from numpy import zeros
from numpy import empty_like
def data_on_sphere(W, TimeIndex, vartheta, varphi) :
    """
    Given the Waveform object W, some integer TimeIndex, and spherical
    coordinates (vartheta, varphi), this returns a numpy array of the
    complex data evaluated at those spherical coordinates.
    """
    nmodes = W.NModes()
    varthetalen = len(vartheta)
    varphilen = len(varphi)
    ComplexDataOnSphere = zeros([varthetalen, varphilen], dtype=complex)
    thisvartheta = empty_like(varphi)
    for mode in range(nmodes) :
        for varthetaIndex in range(varthetalen) :
            thisvartheta.fill(vartheta[varthetaIndex])
            ComplexDataOnSphere[varthetaIndex] += \
                array(SWSH(W.L(mode), W.M(mode), thisvartheta, varphi)) \
                * (W.Mag(mode, TimeIndex) * exp(complex(0,W.Arg(mode,TimeIndex))))
    return ComplexDataOnSphere


from matplotlib.cm import jet
def colors_on_sphere(WaveformData, Normalization=1, Quantities=['real', 'imag', 'mag']) :
    """
    Given an array of complex WaveformData evaluated at points
    (presumably on a sphere), this function converts those values
    (normalized by the Normalization constant) into colors.  By
    default, the real and imaginary parts and magnitude are evaluated.
    """
    Colors = []
    for quantity in Quantities :
        colors = numpy.empty(WaveformData.shape, dtype=tuple)
        if quantity.lower() == 'real' :
            colors = jet( 0.5 * ( (WaveformData.real/Normalization) + 1.0 ) );
        elif quantity.lower() == 'imag' :
            colors = jet( 0.5 * ( (WaveformData.imag/Normalization) + 1.0 ) );
        elif quantity.lower() == 'mag' :
            colors = jet( 0.5 * ( (abs(WaveformData)/Normalization) + 1.0 ) );
        else :
            raise NameError('Unknown quantity: "' + quantity + '"')
        Colors.append(colors)
    return Colors


from mpl_toolkits.mplot3d import Axes3D
from matplotlib.pyplot import figure
from matplotlib.pyplot import draw
def plot_sphere(W, TimeIndex, Normalization=0, Quantities=['real', 'imag', 'mag'],
                         ThetaSteps=100, PhiSteps=200, vartheta=(), varphi=(), x=(), y=(), z=()) :
    """
    This plots the real or imaginary part or magnitude of the complex
    Waveform data on the sphere.
    
    """
    if ((vartheta.size==0) or (varphi.size==0)) :
        vartheta, varphi = sphere_coordinates(ThetaSteps, PhiSteps)
    ComplexDataOnSphere = data_on_sphere(W, TimeIndex, vartheta, varphi)
    if (Normalization<=0.0) : Normalization = abs(ComplexDataOnSphere).max()
    Colors = colors_on_sphere(ComplexDataOnSphere, Normalization, Quantities)
    xyzshape = (len(vartheta),len(varphi))
    if ((x.size==0) or (y.size==0) or (z.size==0) or (x.shape!=xyzshape) or (y.shape!=xyzshape) or (z.shape!=xyzshape)) :
        x,y,z = sphere_points(vartheta, varphi)
    Figs = []
    for i,quantity in enumerate(Quantities) :
        fig = figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.set_xticks(())
        ax.set_yticks(())
        ax.set_zticks(())
        fig.tight_layout(pad=0.1)
        Surface = ax.plot_surface(x, y, z,  rstride=1, cstride=1, linewidth=0, antialiased=False, facecolors=Colors[i])
        TimeText = ax.text2D(0.05, 0.92, r'$t = '+str(round(W.T(TimeIndex),1))+'$\n'+quantity, transform=ax.transAxes)
        fig.draw()
        Figs.append(fig)
    return Figs


from matplotlib.pyplot import ion
from matplotlib.pyplot import ioff
def animate_sphere(W, OutputFileName, TimeSteps = 500, PhiSteps = 200, ThetaSteps = 100, Quantities=['real', 'imag', 'mag'], DPI=250) :
    
    vartheta, varphi = sphere_coordinates(ThetaSteps, PhiSteps)
    x,y,z = sphere_points(vartheta, varphi)
    Normalization = abs(data_on_sphere(W, W.Peak22TimeIndex(), vartheta, varphi)).max()
    print("Normalization = ", Normalization)
    
    ioff()
    TIndexStep = W.NTimes()/int(TimeSteps)
    for FrameIndex,t in enumerate(range(0, W.NTimes(), TIndexStep)) :
        print(str(t/TIndexStep) + ' of ' + str(TimeSteps))
        Figs = plot_sphere(W, t, Normalization, Quantities, vartheta=vartheta, varphi=varphi, x=x, y=y, z=z)
        for i in range(len(Figs)) :
            Figs[i].savefig(OutputFileName + '_' + Quantities[i].lower() + '_Frame%04d.png' % FrameIndex, dpi=DPI, transparent=True)
    ion()
