%module WaveformObjects
%{
  #define SWIG_FILE_WITH_INIT
  // Includes the header in the wrapper code
  #include "Waveform.hpp"
%}

%include numpy.i

%init %{
  import_array();
%}

// Make sure std strings and vectors are dealt with appropriately
%include "std_string.i"
%include "std_vector.i"
%apply const std::string& {std::string* foo};
namespace std {
   %template(vectori) vector<int>;
   %template(vectord) vector<double>;
   %template(vectorvectord) vector<vector<double> >;
   %template(vectors) vector<string>;
};

// Try to handle Matrix objects as numpy arrays
%ignore WaveformUtilities::Matrix::operator=;
%ignore WaveformUtilities::Matrix::operator[];
%include "../Utilities/Matrix.hpp"
namespace WaveformUtilities {
  %template(matrixd) Matrix<double>;
  %template(matrixi) Matrix<int>;
  //  #if defined(SWIGPYTHON)
  %typemap(out) Matrix { // From C++ to python
    $result = numpy.empty($1.nrows(), $1.ncols());
    for(unsigned int i=0; i<$1.nrows(); ++i) {
      for(unsigned int j=0; j<$1.ncols(); ++j) {
	$result[i][j] = $1[i][j];
      }
    }
  }
  %typemap(in) Matrix<double> { // From python to C++
    $1 = Matrix<double>($input.nrows(), $input.ncols());
    for(unsigned int i=0; i<$1.nrows(); ++i) {
      for(unsigned int j=0; j<$1.ncols(); ++j) {
	$1[i][j] = $input[i][j];
      }
    }
  }
  %typemap(memberin) Matrix<double> { // From python to C++
    $1 = Matrix<double>($input.nrows(), $input.ncols());
    for(unsigned int i=0; i<$1.nrows(); ++i) {
      for(unsigned int j=0; j<$1.ncols(); ++j) {
	$1[i][j] = $input[i][j];
      }
    }
  }
  //  #else
  //    #warning no "in" typemap defined for Matrix objects
  //  #endif
}


// Ignore things that don't translate well
%ignore WaveformObjects::Waveform::operator=;
%ignore WaveformObjects::Waveform::operator[];
%ignore operator<<;

/* %extend WaveformObjects::Waveform { */
/*     double __getitem__(int i) { */
/*       return g->data[row][i]; */
/*     }; */
/*  } */

// Parse the header file to generate wrappers
%include "Waveform.hpp"

//%rename(__divide__) WaveformObjects::Waveform::operator/;
