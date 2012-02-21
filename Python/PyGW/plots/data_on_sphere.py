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
