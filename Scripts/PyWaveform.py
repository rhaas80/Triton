import scipy
import numpy as np

# I'm sure there is some special way to mark packages, I'll do so later.
class PyWaveform:
    def __init__(self, other=None, T=None, Mag=None, Arg=None):
        if(other):
            self.T_ = np.copy(other.T())
            self.Mag_ = np.copy(other.Mag(0))
            self.Arg_ = np.copy(other.Arg(0))
            if (T!=None or Mag != None or Arg != None):
                raise ValueError("Copy-constructor takes only one argument, not %d" % (T!=None)+(Mag!=None)+(Arg!=None))
        else:
            self.T_ = np.copy(T)
            self.Mag_ = np.copy(Mag)
            self.Arg_ = np.copy(Arg)
        self.useSpline = True
        self.usePchip = False
    def LoadFromFile(self, fn, usecols = None):
        self.T_, self.Mag_, self.Arg_ = np.loadtxt(fn, unpack=True,
                                                   usecols=usecols)
    def T(self, idx=None):
        if(idx == None):
            return self.T_
        else:
            return self.T_[idx]
    def Mag(self, idx=None):
        if(idx != 0):
            raise ValueError("Only idx = 0 is supported right now, not %d" % idx)
        return self.Mag_
    def Arg(self, idx=None):
        if(idx != 0):
            raise ValueError("Only idx = 0 is supported right now, not %d" % idx)
        return self.Arg_
    def AddToTime(self, dtime):
        self.T_ += dtime
    def SetT(self, T):
        self.T_ = np.copy(T)
    def SetArg(self, idx, Arg):
        if(idx != 0):
            raise ValueError("Only idx = 0 is supported right now, not %d" % idx)
        self.Arg_ = np.copy(Arg)
    def SetMag(self, idx, Mag):
        if(idx != 0):
            raise ValueError("Only idx = 0 is supported right now, not %d" % idx)
        self.Mag_ = np.copy(Mag)
    def DropBefore(self, time):
        # '>' is what PyGW does
        idx = self.T_ > time
        self.T_ = self.T_[idx]
        self.Mag_ = self.Mag_[idx]
        self.Arg_ = self.Arg_[idx]
    def DropAfter(self, time):
        # '<=' is what PyGW does
        idx = self.T_ <= time
        self.T_ = self.T_[idx]
        self.Mag_ = self.Mag_[idx]
        self.Arg_ = self.Arg_[idx]
    def SetupForInterpolation(self):
        if (self.useSpline):
            self.tckArg_ = scipy.interpolate.splrep(self.T(),self.Arg(0))
            self.tckMag_ = scipy.interpolate.splrep(self.T(),self.Mag(0))
        if (self.usePchip):
            self.intpArg_ = scipy.interpolate.PchipInterpolator(self.T(), self.Arg(0))
            self.intpMag_ = scipy.interpolate.PchipInterpolator(self.T(), self.Mag(0))
    def Interpolated(self, times, extrap_to_zero=False):
        retval = PyWaveform()
        if(extrap_to_zero):
            intp_idx = (times >= self.T(0)) * (times <= self.T(-1))
            intp_times = times[intp_idx]
        else:
            intp_times = times
        if(len(intp_times)):
            if (self.useSpline):
                newarg = scipy.interpolate.splev(intp_times, self.tckArg_)
                newmag = scipy.interpolate.splev(intp_times, self.tckMag_)
            if (self.usePchip):
                newmag = self.intpMag_(intp_times)
                newarg = self.intpArg_(intp_times)
        retval.SetT(times)
        if(extrap_to_zero and len(intp_times) < len(times)):
            extrap_newarg = np.zeros(len(times))
            if(len(intp_times)):
                extrap_newarg[intp_idx] = newarg
            retval.SetArg(0, extrap_newarg)
            extrap_newmag = np.zeros(len(times))
            if(len(intp_times)):
                extrap_newmag[intp_idx] = newmag
            retval.SetMag(0, extrap_newmag)
        else:
            retval.SetArg(0, newarg)
            retval.SetMag(0, newmag)
        return retval
    def FinishInterpolation(self):
        if (self.useSpline):
            self.tckArg_ = None
            self.tckMag_ = None
        if (self.usePchip):
            self.intpArg_ = None
            self.intpMag_ = None
