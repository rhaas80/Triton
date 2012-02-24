"""
This submodule specializes the usual pyplot.plot function to be used
as methods with Waveform objects.

"""

from matplotlib.pyplot import plot as matplotlibpyplotplot
from matplotlib.pyplot import semilogx as matplotlibpyplotsemilogx
from matplotlib.pyplot import semilogy as matplotlibpyplotsemilogy
from matplotlib.pyplot import loglog as matplotlibpyplotloglog
from matplotlib.pyplot import xlabel, ylabel, tight_layout
from warnings import warn
from numpy import array, empty, transpose

def plot(this, WaveformPart='Mag', Modes=(), *pyplot_args, **pyplot_kwargs) :
    """
    This function should be called as a method of the Waveform class,
    e.g., as
    
    >>> W.plot('Mag', Modes=((2,2), (2,-2)), c='r')
    
    where W is a Waveform object.  The first parameter should be a
    string --- one of ('Mag', 'LogMag', 'LogLogMag', 'Arg', 'Omega').
    The second (optional) parameter is a tuple, where each element is
    either a mode index, or some (l,m).  Only modes included in this
    list will be plotted, unless the list is empty (the default), in
    which case all modes are plotted.  All following arguments are
    passed to the usual pyplot.plot function.
    
    """
    
    TypeDict = {
        "rMPsi4" : r'r M \Psi_4',
        "rhdot" : r'r \dot{h}',
        "rhOverM" : r'r h / M',
        "rPsi4" : r'r \Psi_4',
        "rhdot" : r'r \dot{h}',
        "rh" : r'r h',
        "MPsi4" : r'M \Psi_4',
        "hdot" : r'\dot{h}',
        "hOverM" : r'h/M',
        "Psi4" : r'\Psi_4',
        "hdot" : r'\dot{h}',
        "h": r'h'
        }
    
    XLabel=r'$(t-r_\ast)/M$'
    YLabel=''
    
    # if (WaveformPart.lower()=='mag') :
    #     YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $' # r'$\mathrm{Mag}\left\{ a \right\}$'
    #     if (type(Modes)==int or len(Modes)==1) :
    #         Lines = matplotlibpyplotplot(this.T(), this.Mag(Modes), *pyplot_args, **pyplot_kwargs)
    #     elif (len(Modes)==0) :
    #         Lines = matplotlibpyplotplot(this.T(), this.Mag().transpose(), *pyplot_args, **pyplot_kwargs)
    #     elif ((len(Modes)==2) and ((Modes[0]<2) or (Modes[0]<abs(Modes[1])))) :
    #         Data = (this.Mag(Modes[0]), this.Mag(Modes[1]))
    #         Data = transpose(Data)
    #         Lines = matplotlibpyplotplot(this.T(), Data, *pyplot_args, **pyplot_kwargs)
    #         #Lines = matplotlibpyplotplot(this.T(), transpose((this.Mag(Modes[0]),this.Mag(Modes[1]))), *pyplot_args, **pyplot_kwargs)
    #     else :
    #         Modes = array(Modes)
    #         if (Modes.shape==(2,)) :
    #             warn("Ambiguous 'Modes' specification.  Assuming this is an (l,m) specification.", SyntaxWarning)
    #             #try: # Catch a bad (l,m) error
    #             Lines = matplotlibpyplotplot(this.T(), this.Mag(this.FindModeIndex(int(Modes[0]), int(Modes[1]))), *pyplot_args, **pyplot_kwargs)
    #         else :
    #             Data = empty([Modes.shape[0], this.NTimes()], dtype=float)
    #             for i in range(Modes.shape[0]) :
    #                 if (type(Modes[i])==int) :
    #                     ModeIndex = Modes[i]
    #                 else :
    #                     ModeIndex = this.FindModeIndex(int(Modes[i][0]), int(Modes[i][1]))
    #                 Data[i] = this.Mag(ModeIndex)
    #             Lines = matplotlibpyplotplot(this.T(), Data.transpose(), *pyplot_args, **pyplot_kwargs)
    # else :
    #     print("Unsupported data type %s" % WaveformPart)
    #     return []
    
    if (WaveformPart.lower()=='mag') :
        YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotplot
        quantity = this.Mag
    elif (WaveformPart.lower()=='logmag') :
        YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotsemilogy
        quantity = this.Mag
    elif (WaveformPart.lower()=='loglogmag') :
        YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotloglog
        quantity = this.Mag
    elif (WaveformPart.lower()=='arg') :
        YLabel =r'$\mathrm{Arg} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotplot
        quantity = this.Arg
    else :
        print("Unsupported data type %s" % WaveformPart)
        return []
    
    if (type(Modes)==int or len(Modes)==1) :
        Lines = styledplot(this.T(), quantity(Modes), *pyplot_args, **pyplot_kwargs)
    elif (len(Modes)==0) :
        Lines = styledplot(this.T(), quantity().transpose(), *pyplot_args, **pyplot_kwargs)
    elif ((len(Modes)==2) and ((Modes[0]<2) or (Modes[0]<abs(Modes[1])))) :
        Lines = styledplot(this.T(), transpose((quantity(Modes[0]),quantity(Modes[1]))), *pyplot_args, **pyplot_kwargs)
    else :
        Modes = array(Modes)
        if (Modes.shape==(2,)) :
            warn("Ambiguous 'Modes' specification.  Assuming this is an (l,m) specification.", SyntaxWarning)
            #try: # Catch a bad (l,m) error
            Lines = styledplot(this.T(), quantity(this.FindModeIndex(int(Modes[0]), int(Modes[1]))), *pyplot_args, **pyplot_kwargs)
        else :
            Data = empty([Modes.shape[0], this.NTimes()], dtype=float)
            for i in range(Modes.shape[0]) :
                if (type(Modes[i])==int) :
                    ModeIndex = Modes[i]
                else :
                    ModeIndex = this.FindModeIndex(int(Modes[i][0]), int(Modes[i][1]))
                Data[i] = quantity(ModeIndex)
                Lines = styledplot(this.T(), Data.transpose(), *pyplot_args, **pyplot_kwargs)
    
    xlabel(XLabel)
    ylabel(YLabel)
    try :
        tight_layout(pad=0.1)
    except RuntimeError :
        
    
    return Lines



# The following allows us to write things like
#   Waveform W
#   W.plot()
import PyGW
PyGW.WaveformObjects.Waveform.plot = plot
