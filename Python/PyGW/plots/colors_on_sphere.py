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
