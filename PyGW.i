// -*- c++ -*-

%module PyGW
 #pragma SWIG nowarn=401,509

%exception {
  try {
    $action;
  } catch(int i) {
    PyErr_SetString(PyExc_RuntimeError, "Unknown exception");
    return NULL;
  }
}

%include "PyGW/PyGW_Doc.i"

/////////////////////////////////////////////////
//// These will be needed by the c++ wrapper ////
/////////////////////////////////////////////////
%{
  #define SWIG 1
  #include <iostream>
  #include <sstream>
  #include <iomanip>
  #include "Objects/WaveformAtAPoint.hpp"
  #include "Objects/WaveformAtAPointFT.hpp"
  #include "Objects/Waveforms.hpp"
  #include "Utilities/Quaternions.hpp"
  #include "Utilities/SWSHs.hpp"
%}


//////////////////////////////////////////////////////////////////////
//// The following translates between c++ and python types nicely ////
//////////////////////////////////////////////////////////////////////
//// This lets me use numpy.array in the code below
%pythoncode %{
  import numpy;
  %}
//// Make sure std::strings are dealt with appropriately
%include "std_string.i"
//// Make sure std::vectors are dealt with appropriately
%include "std_vector.i"
namespace std {
  %template(vectori) vector<int>;
  %template(vectord) vector<double>;
  %template(vectors) vector<string>;
  %template(vectorvectori) vector<vector<int> >;
  %template(vectorvectord) vector<vector<double> >;
};
//// This should help python understand matrices
%ignore WaveformUtilities::Matrix::operator=;
%ignore WaveformUtilities::Matrix::operator[];
%rename(__getitem__) WaveformUtilities::Matrix<int>::operator[] const;
%rename(__getitem__) WaveformUtilities::Matrix<double>::operator[] const;
%include "Utilities/Matrix.hpp"
namespace WaveformUtilities {
  %template(MatrixInt) Matrix<int>;
  %template(MatrixDouble) Matrix<double>;
};
//// I need to use my Quaternion class, to pass arguments into PyGW
%ignore WaveformUtilities::Quaternion::operator=;
%rename(__getitem__) WaveformUtilities::Quaternion::operator [](unsigned int const) const;
%rename(__setitem__) WaveformUtilities::Quaternion::operator [](unsigned int const);
%include "Utilities/Quaternions.hpp"
%extend WaveformUtilities::Quaternion {
  //// This function is called when printing a Quaternion object
  std::string __str__() {
    std::stringstream S;
    S << std::setprecision(14) << "["
      << $self->operator[](0) << ", "
      << $self->operator[](1) << ", "
      << $self->operator[](2) << ", " 
      << $self->operator[](3) << "]";
    return S.str();
  }
  // This prints the Quaternion nicely at the prompt
  %pythoncode{
    def __repr__(self):
        return 'PyGW.Quaternion('+repr(self[0])+', '+repr(self[1])+', '+repr(self[2])+', '+repr(self[3])+')'
  };
 };
namespace std {
  %template(vectorq) vector<WaveformUtilities::Quaternion>;
}
// Make SWSHs available
%include <typemaps.i>
%apply double *INOUT { double& amp };
%apply double *INOUT { double& arg };
%feature("pythonappend") WaveformUtilities::SWSH() %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%include "Utilities/SWSHs.hpp"


//////////////////////////////////////////////////////////////////////


////////////////////////////////////
//// Read in the Waveform class ////
////////////////////////////////////
//// Ignore things that don't translate well...
%ignore operator<<;
%ignore WaveformObjects::Waveform::operator=;
//// ...and rename things that do
%rename(__div__) WaveformObjects::Waveform::operator/;
%rename(__getitem__) WaveformObjects::Waveform::operator[] const;
//// These will convert the output data to numpy.ndarray for easier use
%feature("pythonappend") WaveformObjects::Waveform::T() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::R() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Frame() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::LM() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Mag() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Arg() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Omega2m2() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Flux() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
//// Parse the header file to generate wrappers
%include "Objects/Waveform.hpp"
//// Make any additions to the Waveform class here
%extend WaveformObjects::Waveform {
  //// This function is called when printing the Waveform object
  std::string __str__() {
    std::stringstream S;
    S << ($self->HistoryStr()) << "###\n"
      << "### # In python:\n"
      << "### import PyGW\n"
      << "### print(this)" << std::endl << std::setprecision(14);
    for(unsigned int t=0; t<$self->NTimes(); ++t) {
      S << $self->T(t) << " ";
      for(unsigned int mode=0; mode<$self->NModes(); ++mode) {
	S << $self->Mag(mode, t) << " " << $self->Arg(mode, t) << " ";
      }
      S << std::endl;
    }
    return S.str();
  }
  //// Allow Waveform objects to be pickled
  %insert("python") %{
    def __getstate__(self) :
      return (self.HistoryStr(),
	      self.TypeIndex(),
	      self.TimeScale(),
	      self.T(),
	      self.R(),
	      self.Frame(),
	      self.LM(),
	      self.Mag(),
	      self.Arg()
	      )
    __safe_for_unpickling__ = True
    def __reduce__(self) :
        return (Waveform, (), self.__getstate__())
    def __setstate__(self, data) :
      self.SetHistory(data[0])
      self.SetTypeIndex(data[1])
      self.SetTimeScale(data[2])
      self.SetT(data[3])
      self.SetR(data[4])
      self.SetFrame(data[5])
      self.SetLM(MatrixInt(data[6].tolist()))
      self.SetMag(MatrixDouble(data[7]))
      self.SetArg(MatrixDouble(data[8]))
  %}
 };


////////////////////////////////////////////
//// Read in the WaveformAtAPoint class ////
////////////////////////////////////////////
//// Parse the header file to generate wrappers
%include "Objects/WaveformAtAPoint.hpp"


//////////////////////////////////////////////
//// Read in the WaveformAtAPointFT class ////
//////////////////////////////////////////////
//// Parse the header file to generate wrappers
%include "Objects/WaveformAtAPointFT.hpp"


/////////////////////////////////////
//// Read in the Waveforms class ////
/////////////////////////////////////
//// Make sure vectors of Waveform are understood
namespace std {
  %template(vectorW) vector<WaveformObjects::Waveform>;
};
//// Ignore this, as neither const nor non-const will work (copy constructor issues?)
%ignore WaveformObjects::Waveforms::operator[];
%rename(__getitem__) WaveformObjects::Waveforms::operator[] const;
//// Parse the header file to generate wrappers
%include "Objects/Waveforms.hpp"
%extend WaveformObjects::Waveforms {
  void __setitem__(int i, const WaveformObjects::Waveform& W) {
    $self->operator[](i) = W;
    return;
  }
 };


//// Add a function to read the new h5 format for multiple radii
//// Note that this is defined in the PyGW namespace
%insert("python") %{

def PickChMass(File='Horizons.h5') :
    """
    Deduce the best Christodoulou mass by finding the mode.
    """
    import h5py
    import os
    if(os.path.isdir(File)) :
        File = File + 'Horizons.h5'
    try :
        f=h5py.File(File, 'r')
    except IOError :
        print("PickChMass could not open the file '{}'".format(File))
        raise
    ChMass = f['AhA.dir/ChristodoulouMass.dat'][:,1]+f['AhB.dir/ChristodoulouMass.dat'][:,1]
    f.close()
    hist, bins = numpy.histogram(ChMass, bins=len(ChMass))
    return bins[hist.argmax()]

def MonotonicIndices(T, MinTimeStep=1.e-5) :
    """
    Given an array of times, return the indices that make the array strictly monotonic.
    """
    import numpy
    Ind = range(len(T))
    Size = len(Ind)
    i=1
    while(i<Size) :
        if(T[Ind[i]]<=T[Ind[i-1]]+MinTimeStep) :
            j=0
            while(T[Ind[j]]+MinTimeStep<T[Ind[i]]) :
                j += 1
            # erase data from j (inclusive) to i (exclusive)
            Ind = numpy.delete(Ind, range(j,i))
            Size = len(Ind)
            i = j-1
        i += 1
    return Ind

def ReadFiniteRadiusData(ChMass=1.0, Dir='.', File='rh_FiniteRadii_CodeUnits.h5', Radii=[]) :
    """
    Read data at various radii, and offset by tortoise coordinate.
    """
    import h5py
    import PyGW
    import re
    import numpy
    YlmRegex = re.compile(r"""Y_l(?P<L>[0-9]+)_m(?P<M>[-+0-9]+)\.dat""")
    try :
        f = h5py.File(Dir+'/'+File, 'r')
    except IOError :
        print("PickChMass could not open the file '{}'".format(File))
        raise
    WaveformNames = list(f)
    if(not Radii) :
        # If the list of Radii is empty, figure out what they are
        Radii = [m.group('r') for Name in list(f) for m in [re.compile(r"""R(?P<r>.*?)\.dir""").search(Name)] if m]
    else :
        # Pare down the WaveformNames list appropriately
        WaveformNames = [Name for Name in WaveformNames for Radius in Radii for m in [re.compile(Radius).search(Name)] if m]
    NWaveforms = len(WaveformNames)
    Ws = PyGW.Waveforms(NWaveforms)
    TempW = PyGW.Waveform()
    for n in range(NWaveforms) :
        W = f[WaveformNames[n]]
        NTimes = W['AverageLapse.dat'].shape[0]
        T = W['AverageLapse.dat'][:,0]
        if( not (W['ArealRadius.dat'].shape[0]==NTimes) ) :
            raise ValueError("The number of time steps in this dataset should be {0}; ".format(NTimes) +
                             "it is {0} in ArealRadius.dat.".format(W['ArealRadius.dat'].shape[0]))
        ArealRadius = W['ArealRadius.dat'][:,1]
        AverageLapse = W['AverageLapse.dat'][:,1]
        CoordRadius = W['CoordRadius.dat'][0,1]
        InitialAdmEnergy = W['InitialAdmEnergy.dat'][0,1]
        YLMdata = [DataSet for DataSet in list(W) for m in [YlmRegex.search(DataSet)] if m]
        YLMdata = sorted(YLMdata, key=lambda DataSet : [int(YlmRegex.search(DataSet).group('L')), int(YlmRegex.search(DataSet).group('M'))])
        LM = sorted([[int(m.group('L')), int(m.group('M'))] for DataSet in YLMdata for m in [YlmRegex.search(DataSet)] if m])
        NModes = len(LM)
        Mag = numpy.empty((NModes, NTimes))
        Arg = numpy.empty((NModes, NTimes))
        m = 0
        for DataSet in YLMdata :
            if( not (W[DataSet].shape[0]==NTimes) ) :
                raise ValueError("The number of time steps in this dataset should be {0}; ".format(NTimes) +
                                 "it is {0} in {1}.".format(W[DataSet].shape[0], DataSet))
            Mag[m,:] = W[DataSet][:,1]
            Arg[m,:] = W[DataSet][:,2]
            m += 1
            #print("n={0}; m={1}; DataSet={2}".format(n, m, DataSet))
        TempW.AppendHistory("### # Python read from {}.".format(WaveformNames[n]))
        Indices = MonotonicIndices(T)
        BadIndices = numpy.setdiff1d(range(len(T)), Indices)
        TempW.SetT(T[Indices])
        TempW.SetLM(PyGW.MatrixInt(LM))
        TempW.SetMag(PyGW.MatrixDouble(numpy.delete(Mag, BadIndices, 1)))
        TempW.SetArg(PyGW.MatrixDouble(numpy.delete(Arg, BadIndices, 1)))
        TempW.ConvertReImToMagArg()
        for i,type in enumerate(TempW.Types) :
            if(File.find(type)>-1) :
                TempW.SetTypeIndex(i)
                break
        TempW.SetArealRadius(ArealRadius[Indices])
        TempW.RescaleMagForRadius(CoordRadius*ChMass)
        TempW.SetTimeFromAverageLapse(AverageLapse[Indices], InitialAdmEnergy)
        TempW.TortoiseRetard(InitialAdmEnergy)
        if(ChMass != 1.0) : TempW.SetTotalMassToOne(ChMass)
        Ws[n] = TempW
    f.close()
    Ws.AppendHistory("### PyGW.ReadFiniteRadiusData(ChMass={0}, Dir='{1}', File='{2}')".format(ChMass, Dir, File))
    return Ws,InitialAdmEnergy,Radii

def OutputToNRAR(W, FileName) :
    from h5py import File
    from numpy import array, exp
    # Open the file for output
    try :
        F = File(FileName, 'w')
    except IOError : # If that did not work...
        print("OutputToNRAR was unable to open the file '{}'.".format(FileName))
        raise # re-raise the exception after the informative message above
    # Construct a simplified waveform type string
    Wtype = W.Type().lower().replace('over','').replace('r','').replace('m','').replace('dot','')
    # Now write all the data to various groups in the file
    F.create_dataset('History', data=W.HistoryStr()+'\n### OutputToNRAR(W, {})'.format(FileName))
    for i_m in range(W.NModes()) : # Step through all the modes, storing the real and imaginary parts
        ell,m = W.LM(i_m)
        F.create_dataset("{0}_l{1}_m{2:+}_.asc".format(Wtype, ell, m),
                         data=numpy.array( [ [t, d.real, d.imag] for t,d in zip(W.T(), W.Mag(i_m)*numpy.exp(1j*W.Arg(i_m))) ] ) )
    # Close the file and we are done
    F.close()


  %}
