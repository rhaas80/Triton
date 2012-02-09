// -*- c++ -*-

%module GravitationalWaves
%{
  #define SWIG_FILE_WITH_INIT
  #include "../Objects/Waveform.hpp"
%}

%include numpy.i

%init %{
  import_array();
%}

// Make sure std::strings are dealt with appropriately
%include "std_string.i"
%apply const std::string& {std::string* foo};
%apply std::string* foo { std::string& };


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
%ignore WaveformObjects::Waveform::operator[];
%ignore WaveformObjects::Waveform::TypeIndexRef();
%ignore WaveformObjects::Waveform::History();
%ignore WaveformObjects::Waveform::TimeScaleRef();
%ignore WaveformObjects::Waveform::TRef(const unsigned int Time);
%ignore WaveformObjects::Waveform::RRef(const unsigned int Time);
%ignore WaveformObjects::Waveform::MagRef(const unsigned int Mode, const unsigned int Time);
%ignore WaveformObjects::Waveform::ArgRef(const unsigned int Mode, const unsigned int Time);
%ignore WaveformObjects::Waveform::TRef();
%ignore WaveformObjects::Waveform::RRef();
%ignore WaveformObjects::Waveform::LRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::MRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::LMRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::MagRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::ArgRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::LMRef();
%ignore WaveformObjects::Waveform::MagRef();
%ignore WaveformObjects::Waveform::ArgRef();

// ...and rename things that do
%rename(__divide__) WaveformObjects::Waveform::operator/;



// Parse the header file to generate wrappers
%include "../Objects/Waveform.hpp"



// Add any additions to the Waveform class here
%extend WaveformObjects::Waveform {
  
  
//   char *__str__() {
//     char temp[1024];
//     return temp;
//   }
 };
