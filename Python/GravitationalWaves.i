// -*- c++ -*-

%module GravitationalWaves
%{
  #include <iostream>
  #include <sstream>
  #include <iomanip>
  #include "../Objects/Waveform.hpp"
%}

//// This lets me use numpy.array's in the code below
%pythoncode %{
  import numpy;
  %}

// Make sure std::strings are dealt with appropriately
%include "std_string.i"
// %apply const std::string& { std::string* };
// %apply std::string* { std::string& };


// Make sure std::vectors are dealt with appropriately
%include "std_vector.i"
 //%include "std_vector_numpy.i"
namespace std {
  %template(vectori) vector<int>;
  %template(vectord) vector<double>;
  %template(vectorvectori) vector<vector<int> >;
  %template(vectorvectord) vector<vector<double> >;
};


// Treat Matrix objects as numpy arrays
%ignore WaveformUtilities::Matrix::operator=;
%ignore WaveformUtilities::Matrix::operator[];
%include "../Utilities/Matrix.hpp"


// Ignore things that don't translate well...
%ignore operator<<;
%ignore WaveformObjects::Waveform::operator=;
//%ignore WaveformObjects::Waveform::operator[];

// ...and rename things that do
%rename(__divide__) WaveformObjects::Waveform::operator/;
%rename(__getitem__) WaveformObjects::Waveform::operator[] const;

%feature("pythonappend") WaveformObjects::Waveform::T() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::R() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::LM() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Mag() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Arg() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Omega2m2() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}
%feature("pythonappend") WaveformObjects::Waveform::Flux() const %{ if isinstance(val, tuple) : val = numpy.array(val) %}

// Parse the header file to generate wrappers
%include "../Objects/Waveform.hpp"



// Add any additions to the Waveform class here
%extend WaveformObjects::Waveform {
  
  // This function is called when printing the 
  char *__str__() {
    std::stringstream S;
    S << ($self->HistoryStr()) << "###\n"
      << "### # In python:\n"
      << "### import GravitationalWaves\n"
      << "### print(this)" << std::endl << std::setprecision(14);
    for(unsigned int t=0; t<$self->NTimes(); ++t) {
      S << $self->T(t) << " ";
      for(unsigned int mode=0; mode<$self->NModes(); ++mode) {
	S << $self->Mag(mode, t) << " " << $self->Arg(mode, t) << " ";
      }
      S << std::endl;
    }
    std::string String(S.str());
    std::vector<char> CharVec(String.size() + 1);
    std::copy(String.begin(), String.end(), CharVec.begin());
    CharVec.push_back('\0');
    return &(CharVec[0]);
  }
  
 };
