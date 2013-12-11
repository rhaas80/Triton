// -*- c++ -*-

%module WignerD

%exception {
  try {
    $action;
  } catch(int i) {
    PyErr_SetString(PyExc_RuntimeError, "Unknown exception");
    return NULL;
  }
}

/////////////////////////////////////////////////
//// These will be needed by the c++ wrapper ////
/////////////////////////////////////////////////
%{
  #include <iostream>
  #include <sstream>
  #include <iomanip>
  #include "../../Utilities/Matrix.hpp"
  #include "../../Utilities/Quaternions.hpp"
  #include "../../Utilities/WignerDMatrix.hpp"
  #include "../../Utilities/WignerDMatrix_Q.hpp"
%}


//////////////////////////////////////////////////////////////////////
//// The following translates between c++ and python types nicely ////
//////////////////////////////////////////////////////////////////////
//// This lets me use numpy.array in the code below
%pythoncode %{
  import numpy;
  %}

%include <typemaps.i>
%apply double *OUTPUT { double& Mag };
%apply double *OUTPUT { double& Arg };
%apply double *OUTPUT { double& Re };
%apply double *OUTPUT { double& Im };
// %apply double *INOUT { double& Mag };
// %apply double *INOUT { double& Arg };
// %apply double *INOUT { double& Re };
// %apply double *INOUT { double& Im };

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
%include "../../Utilities/Matrix.hpp"
namespace WaveformUtilities {
  %template(MatrixInt) Matrix<int>;
  %template(MatrixDouble) Matrix<double>;
};
//// I need to use my Quaternion class, to pass arguments into PyGW_IS_FOR_OLD_DATA
%ignore WaveformUtilities::Quaternion::operator=;
%ignore WaveformUtilities::Quaternion::operator[];
%rename(__getitem__) WaveformUtilities::Quaternion::operator[] const;
%include "../../Utilities/Quaternions.hpp"
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

//////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////
//// This reads in the WignerDMatrix class ////
///////////////////////////////////////////////
//// Parse the header file to generate wrappers
%include "../../Utilities/WignerDMatrix.hpp"

/////////////////////////////////////////////////
//// This reads in the WignerDMatrix_Q class ////
/////////////////////////////////////////////////
//// Parse the header file to generate wrappers
%include "../../Utilities/WignerDMatrix_Q.hpp"
