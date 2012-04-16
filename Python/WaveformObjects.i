// -*- c++ -*-

%module WaveformObjects

%exception {
  try {
    $action;
  } catch(int i) {
    PyErr_SetString(PyExc_RuntimeError, "Unknown exception");
    return NULL;
  }
}

%include "WaveformObjects_Doc.i"

/////////////////////////////////////////////////
//// These will be needed by the c++ wrapper ////
/////////////////////////////////////////////////
%{
  #include <iostream>
  #include <sstream>
  #include <iomanip>
  #include "../Objects/Waveforms.hpp"
  #include "../Utilities/Quaternions.hpp"
  #include "../Utilities/QuaternionInterpolation.hpp"
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
  %template(vectorvectori) vector<vector<int> >;
  %template(vectorvectord) vector<vector<double> >;
};
//// This should help python understand matrices
%ignore WaveformUtilities::Matrix::operator=;
%ignore WaveformUtilities::Matrix::operator[];
%rename(__getitem__) WaveformUtilities::Matrix<int>::operator[] const;
%rename(__getitem__) WaveformUtilities::Matrix<double>::operator[] const;
%include "../Utilities/Matrix.hpp"
namespace WaveformUtilities {
  %template(MatrixInt) Matrix<int>;
  %template(MatrixDouble) Matrix<double>;
};
//// I need to use my Quaternion class, to pass arguments into PyGW
%ignore WaveformUtilities::Quaternion::operator=;
%rename(__getitem__) WaveformUtilities::Quaternion::operator[] const;
%rename(__setitem__) WaveformUtilities::Quaternion::operator[];
%include "../Utilities/Quaternions.hpp"
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
 };
namespace std {
  %template(vectorq) vector<WaveformUtilities::Quaternion>;
}
%include "../Utilities/QuaternionInterpolation.hpp"

//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////
//// This reads in the Waveform class ////
//////////////////////////////////////////
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
%include "../Objects/Waveform.hpp"
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
 };


///////////////////////////////////////////
//// This reads in the Waveforms class ////
///////////////////////////////////////////
//// Make sure vectors of Waveform are understood
namespace std {
  %template(vectorW) vector<WaveformObjects::Waveform>;
};
//// Ignore this, as neither const nor non-const will work (copy constructor issues?)
%ignore WaveformObjects::Waveforms::operator[];
%rename(__getitem__) WaveformObjects::Waveforms::operator[] const;
//// Parse the header file to generate wrappers
%include "../Objects/Waveforms.hpp"
%extend WaveformObjects::Waveforms {
  void __setitem__(int i, const WaveformObjects::Waveform& W) {
    $self->operator[](i) = W;
    return;
  }
 };
