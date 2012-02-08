// -*- c++ -*-

%module GravitationalWaves
%{
  #define SWIG_FILE_WITH_INIT
  // Includes the header in the wrapper code
  #include <vector>
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
template <class T>
class WaveformUtilities::Matrix;
%define %my_typemaps(DATA_TYPE, DATA_TYPECODE, DIM_TYPE)

// %typemap(in, fragment="NumPy_Fragments")
// (std::vector<DATA_TYPE>)
// (PyArrayObject* array=NULL, int is_new_object=0)
// {
//   // From python to C++
//   npy_intp size[1] = { $1_dim0 };
//   array = obj_to_array_contiguous_allow_conversion(&$input, DATA_TYPECODE,
//                                                    &is_new_object);
//   if (!array || !require_dimensions(array, 1) ||
//       !require_size(array, size, 1)) SWIG_fail;
//   $1 = ($1_ltype) array_data(array);
// }
%typemap(argout) //, fragment="NumPy_Backward_Compatibility"
  (std::vector<DATA_TYPE>&)
{
  // From C++ to python (argout &)
  npy_intp dims[1] = { $1->size() };
  PyObject * array = PyArray_SimpleNewFromData(1, dims, DATA_TYPECODE, (void*)( &((*($1))[0]) ));
  if (!array) SWIG_fail;
  $result = SWIG_Python_AppendOutput($result,array);
}
%typemap(argout) //, fragment="NumPy_Backward_Compatibility"
  (std::vector<DATA_TYPE>)
{
  // From C++ to python (argout)
  npy_intp dims[1] = { $1.size() };
  PyObject * array = PyArray_SimpleNewFromData(1, dims, DATA_TYPECODE, (void*)( &((*(&($1)))[0]) ));
  if (!array) SWIG_fail;
  $result = SWIG_Python_AppendOutput($result,array);
}
%typemap(out)//, fragment="NumPy_Backward_Compatibility")
  (std::vector<DATA_TYPE>&)
{
  // From C++ to python (out &)
  npy_intp dims[1] = { $1->size() };
  PyObject * array = PyArray_SimpleNewFromData(1, dims, DATA_TYPECODE, (void*)( &((*($1))[0]) ));
  if (!array) SWIG_fail;
  $result = SWIG_Python_AppendOutput($result,array);
}
%typemap(out)//, fragment="NumPy_Backward_Compatibility")
  (std::vector<DATA_TYPE>)
{
  // From C++ to python (out)
  npy_intp dims[1] = { $1.size() };
  PyObject * array = PyArray_SimpleNewFromData(1, dims, DATA_TYPECODE, (void*)( &((*(&($1)))[0]) ));
  if (!array) SWIG_fail;
  $result = SWIG_Python_AppendOutput($result,array);
}
%typemap(out)//, fragment="NumPy_Backward_Compatibility")
  (WaveformUtilities::Matrix<DATA_TYPE>&)
{
  // From C++ to python
  npy_intp dims[2] = { $1->ncols(), $1->nrows() };
  PyObject * array = PyArray_SimpleNewFromData(2, dims, DATA_TYPECODE, (void*)( *($1)->PtrsPtrs() ));
  if (!array) SWIG_fail;
  $result = SWIG_Python_AppendOutput($result,array);
}
%typemap(out)//, fragment="NumPy_Backward_Compatibility")
  (WaveformUtilities::Matrix<DATA_TYPE>)
{
  // From C++ to python
  npy_intp dims[2] = { $1.ncols(), $1.nrows() };
  PyObject * array = PyArray_SimpleNewFromData(2, dims, DATA_TYPECODE, (void*)( ($1)->PtrsPtrs() ));
  if (!array) SWIG_fail;
  $result = SWIG_Python_AppendOutput($result,array);
}
// %typemap(out)//, fragment="NumPy_Backward_Compatibility")
//   (WaveformUtilities::Matrix<DATA_TYPE>&)
// {
//   // From C++ to python
//   npy_intp dims[2] = { $1->ncols(), $1->nrows() };
//   PyObject * array = PyArray_SimpleNewFromData(2, dims, DATA_TYPECODE, (void*)( *($1)->PtrsPtrs() ));
//   if (!array) SWIG_fail;
//   $result = SWIG_Python_AppendOutput($result,array);
// }

%enddef // my_typemaps

 // This uses the above typemaps for various basic data types
%my_typemaps(signed char       , NPY_BYTE     , int)
%my_typemaps(unsigned char     , NPY_UBYTE    , int)
%my_typemaps(short             , NPY_SHORT    , int)
%my_typemaps(unsigned short    , NPY_USHORT   , int)
%my_typemaps(int               , NPY_INT      , int)
%my_typemaps(unsigned int      , NPY_UINT     , int)
%my_typemaps(long              , NPY_LONG     , int)
%my_typemaps(unsigned long     , NPY_ULONG    , int)
%my_typemaps(long long         , NPY_LONGLONG , int)
%my_typemaps(unsigned long long, NPY_ULONGLONG, int)
%my_typemaps(float             , NPY_FLOAT    , int)
%my_typemaps(double            , NPY_DOUBLE   , int)



// Try to handle Matrix objects as numpy arrays
%ignore WaveformUtilities::Matrix::operator=;
%ignore WaveformUtilities::Matrix::operator[];
%include "../Utilities/Matrix.hpp"


// Ignore things that don't translate well...
%ignore WaveformObjects::Waveform::operator=;
%ignore WaveformObjects::Waveform::operator[];
%ignore operator<<;
%ignore WaveformObjects::Waveform::History();
%ignore WaveformObjects::Waveform::LMRef();
%ignore WaveformObjects::Waveform::MagRef();
%ignore WaveformObjects::Waveform::ArgRef();

// ...and rename things that do
%rename(__divide__) WaveformObjects::Waveform::operator/;

// Parse the header file to generate wrappers
%include "../Objects/Waveform.hpp"

%extend WaveformObjects::Waveform {
  
 };
