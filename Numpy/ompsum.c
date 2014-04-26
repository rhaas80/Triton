#if 0 
from distutils.core import setup, Extension
import numpy
import sys

# define the extension module
ompsum = Extension('ompsum', sources=['ompsum.c'],
                   include_dirs=[numpy.get_include()],
                   extra_compile_args = ['-fopenmp',
                                         '-Wall', '-std=gnu99',
                                         '-Ofast', '-g', '-march=native',
                                         '-funroll-loops', '-mfma4', '-mavx',
                                         '-ftree-vectorizer-verbose=1'],
                   extra_link_args=['-lgomp'],)
# run the setup
setup(ext_modules=[ompsum])
sys.exit(0)
""" "# turn C code into python docstring
#endif

#include <assert.h>
#include <stddef.h>

#ifdef _OPENMP
#include "omp.h"
#else
#define omp_get_num_threads() 1
#define omp_get_thread_num() 0
#endif

// double precision input and double precision output
static double omp_sum_double(const double *val, const size_t nvals)
{
  double sum = 0.;
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    double sum_loc = 0.;
    const double * restrict val_loc = val+first;
    for(size_t j = 0 ; j < length ; ++j) {
      sum_loc += val_loc[j];
    }
#pragma omp atomic
    sum += sum_loc;
  }
  return sum;
}

// single precision input but double precision output
static double omp_sum_float(const float *val, const size_t nvals)
{
  double sum = 0.;
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    double sum_loc = 0.;
    const float * restrict val_loc = val+first;
    for(size_t j = 0 ; j < length ; ++j) {
      sum_loc += val_loc[j];
    }
#pragma omp atomic
    sum += sum_loc;
  }
  return (float)sum;
}

// boilerplate code copied from scipy lecture at
// http://scipy-lectures.github.io/advanced/interfacing_with_c/interfacing_with_c.html#id1
// some code copied from www.phys.cwru.edu/courses/p250/numpybook.pdf
#include <Python.h>
#include <numpy/arrayobject.h>

/*  wrapped omp_sum function */
static PyObject* ompsum_func(PyObject* self, PyObject* args)
{

    PyArrayObject *in_array;

    /*  parse single numpy array argument */
    if (!PyArg_ParseTuple(args, "O!", &PyArray_Type, &in_array))
        return NULL;

    /* consistency check */
    if (PyArray_NDIM(in_array) != 1 ||
        !(PyArray_TYPE(in_array) == NPY_DOUBLE ||
          PyArray_TYPE(in_array) == NPY_FLOAT)) {
      PyErr_Format(PyExc_ValueError,
                   "input array is %d-dimensional or not of type double or float",
                   PyArray_NDIM(in_array));
      return NULL;
    }
    if (in_array->strides[0] != sizeof(double) &&
        in_array->strides[0] != sizeof(float)) {
      PyErr_Format(PyExc_ValueError,
                   "input array has non unit stride %zd bytes",
                   in_array->strides[0]);
      return NULL;
    }

    /* do actual work */
    const ssize_t nvals = PyArray_DIM(in_array, 0);
    double sum;
    if(in_array->strides[0] == sizeof(double))
      sum = omp_sum_double((double*)in_array->data, nvals);
    else if(in_array->strides[0] == sizeof(float))
      sum = omp_sum_float((float*)in_array->data, nvals);
    else
      assert(0 && "Internal error"), sum=0.;

    /*  construct the output from sum, from c double to python float */
    return Py_BuildValue("f", sum);
}

/*  define functions in module */
static PyMethodDef OmpSumMethods[] =
{
     {"sum", ompsum_func, METH_VARARGS,
         "compute the sum of a numpy array"},
     {NULL, NULL}
};

/* module initialization */
PyMODINIT_FUNC
initompsum(void)
{
     (void) Py_InitModule3("ompsum", OmpSumMethods, "provide omp enabled fast sum");
     import_array();
}

#if 0
" """
#endif
