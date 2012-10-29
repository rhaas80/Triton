// -*- c++ -*-

%module SWSHs


/////////////////////////////////////////////////
//// These will be needed by the c++ wrapper ////
/////////////////////////////////////////////////
%{
  #include "Utilities/SWSHs.hpp"
%}


//////////////////////////////////////////////////////////////////////
//// The following translates between c++ and python types nicely ////
//////////////////////////////////////////////////////////////////////
//// This lets me use numpy.array in the code below
%pythoncode %{
  import numpy;
  %}
//// Make sure std::complex is dealt with appropriately
%include "std_complex.i"
//%template(complexd) std::complex<double>; // Don't do this; the template is already instantiated
//// Make sure std::vectors are dealt with appropriately
%include "std_vector.i"
namespace std {
  %template(vectord) vector<double>;
  %template(vectorcd) vector<std::complex<double> >;
};
////
%include <typemaps.i>
%apply double *INOUT { double& amp };
%apply double *INOUT { double& arg };
//////////////////////////////////////////////////////////////////////

%feature("pythonappend") WaveformUtilities::SWSH() %{ if isinstance(val, tuple) : val = numpy.array(val) %}

%include "Utilities/SWSHs.hpp"
