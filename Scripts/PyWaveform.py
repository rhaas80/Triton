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
