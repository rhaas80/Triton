"""
This submodule specializes the usual pyplot.plot function to be used
as methods with Waveform objects.

"""

from matplotlib.pyplot import plot
from warnings import warn
from numpy import array, empty

def plot(this, WaveformPart='Mag', Modes=(), *pyplot_args, **pyplot_kwargs) :
    """
    This function should be called as a method of the Waveform class,
    e.g., as
    
    >>> W.plot('Mag', Modes=((2,2), (2,-2)), c='r')
    
    where W is a Waveform objects.  The first parameter should be a
    string --- one of ('Mag', 'Arg', 'Omega').  The second (optional)
    parameter is a tuple, where each element is either a mode index,
    or some (l,m).  Only modes included in this list will be plotted,
    unless the list is empty (the default), in which case all modes
    are plotted.  All following arguments are passed to the usual
    pyplot.plot function.
    
    """
    
    if (WaveformPart.lower()=='mag') :
        if (len(Modes)==0) :
            Lines = plot(this.T(), this.Mag().transpose(), pyplot_args, pyplot_kwargs)
        elif (len(Modes)==1) :
            Lines = plot(this.T(), this.Mag(Modes), pyplot_args, pyplot_kwargs)
        elif ((len(Modes)==2) and ((min(Modes)<0) or (Modes[0]<Modes[1]))) :
            Data = numpy.empty((2,this.NTimes()))
            Data[0] = this.Mag(Modes[0])
            Data[1] = this.Mag(Modes[1])
            Lines = plot(this.T(), Data.transpose(), pyplot_args, pyplot_kwargs)
        else :
            Modes = array(Modes)
            if (Modes.shape==(2,)) :
                warn("Ambiguous 'Modes' specification.  Assuming this is an (l,m) specification.", SyntaxWarning)
                #try: # Catch a bad (l,m) error
                Lines = plot(this.T(), this.Mag(this.FindModeIndex(Modes[0], Modes[1])), pyplot_args, pyplot_kwargs)
            else : # We're gonna have to do something special
                Data = numpy.empty(Modes.shape[0], this.NTimes())
                for i in range(Modes.shape[0]) :
                    if (type(Modes[i])==int) :
                        ModeIndex = Modes[i]
                    else :
                        ModeIndex = this.FindModeIndex(Modes[i][0], Modes[i][1])
                    Data[i] = this.Mag(ModeIndex)
                Lines = plot(this.T(), Data.transpose(), pyplot_args, pyplot_kwargs)
    else :
        print("Unsupported data type %s" % WaveformPart)
        return
    
    return Lines



# The following allows us to write things like
#   Waveform W
#   W.plot()
import PyGW.WaveformObjects
PyGW.Waveform.plot = PyGW.plot.plot
# PyGW.Waveform.semilogx = semilogx
# PyGW.Waveform.semilogy = semilogy
