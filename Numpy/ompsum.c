#if 0 
from distutils.core import setup, Extension
import numpy
import sys

# define the extension module
ompsum = Extension('ompsum', sources=['ompsum.c'],
                   include_dirs=[numpy.get_include()],
                   extra_compile_args = ['-fopenmp',
                                         '-Wall', '-std=gnu99', '-g',
                                         '-O3', '-march=native',
                                         '-funroll-loops', #'-mavx',
                                         '-ftree-vectorizer-verbose=1'],
                   extra_link_args=['-lgomp'],)
# run the setup
setup(ext_modules=[ompsum])
sys.exit(0)
""" "# turn C code into python docstring
#endif

#include <assert.h>
#include <complex.h>
#include <math.h>
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

// double precision input and double precision output
static void omp_expi_double(const double *val, complex *out, const size_t nvals)
{
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    const double * restrict val_loc = val+first;
    complex * restrict out_loc = out+first;
    for(size_t j = 0 ; j < length ; ++j) {
      out_loc[j] = cexp(val_loc[j]*I);
    }
  }
}

// single precision input but double precision output
static void omp_expi_float(const float *val, complex *out, const size_t nvals)
{
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    const float * restrict val_loc = val+first;
    complex * restrict out_loc = out+first;
    for(size_t j = 0 ; j < length ; ++j) {
      out_loc[j] = cexp(val_loc[j]*I);
    }
  }
}

// double precision input and double precision output
static double omp_OverlapMaxing(const double dt, const double * restrict freqs,
                                const complex * restrict fwave_ref,
                                const complex * restrict fwave_tem_c,
                                const complex * restrict fwave_tem_s,
                                const size_t nvals)

{
  double NWFIc = 0.;
  double NWFIs = 0.;
  double dhdh = 0.;
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    assert(first >= 0);
    assert(first+length < nvals);

    const double deltaf = freqs[1]-freqs[0];
    const double two_PI_dt = 2.*M_PI*dt;
    const double * restrict freqs_loc = freqs+first;
    const complex * restrict fwave_ref_loc = fwave_ref+first;
    const complex * restrict fwave_tem_c_loc = fwave_tem_c+first;
    const complex * restrict fwave_tem_s_loc = fwave_tem_s+first;
    double NWFIc_loc = 0.;
    double NWFIs_loc = 0.;
    // this integral is missing the factor of 1/2 at the endpoints of the
    // trapezoid rule. We correct for this just below.
    for(size_t j = 0 ; j < length ; ++j) {
      const double phase = two_PI_dt*freqs_loc[j];
      const complex exp_freq = cexp(phase*I);
      const complex fwave_tem_c_shifted = fwave_tem_c_loc[j]*exp_freq;
      const complex fwave_tem_s_shifted = fwave_tem_s_loc[j]*exp_freq;
      NWFIc_loc += creal(conj(fwave_ref_loc[j])*fwave_tem_c_shifted);
      NWFIs_loc += creal(conj(fwave_ref_loc[j])*fwave_tem_s_shifted);
    }
    // correct for different weight at endpoints of integral
#pragma omp master
    for(size_t j = 0 ; j < nvals ; j += nvals-1) {
      const double phase = two_PI_dt*freqs[j];
      const complex exp_freq = cexp(phase*I);
      const complex fwave_tem_c_shifted = fwave_tem_c[j]*exp_freq;
      const complex fwave_tem_s_shifted = fwave_tem_s[j]*exp_freq;
      NWFIc_loc -= 0.5*creal(conj(fwave_ref[j])*fwave_tem_c_shifted);
      NWFIs_loc -= 0.5*creal(conj(fwave_ref[j])*fwave_tem_s_shifted);
    }
#pragma omp atomic
    NWFIc += NWFIc_loc;
#pragma omp atomic
    NWFIs += NWFIs_loc;
#pragma omp barrier
    const double dphi = atan2(NWFIs, NWFIc);
    const double cosdphi = cos(dphi);
    const double sindphi = sin(dphi);

    double dhdh_loc = 0.;
    // this integral is missing the factor of 1/2 at the endpoints of the
    // trapezoid rule. We correct for this just below.
    for(size_t j = 0 ; j < length ; ++j) {
      const double phase = two_PI_dt*freqs_loc[j];
      const complex exp_freq = cexp(phase*I);
      const complex fwave_tem_c_shifted = fwave_tem_c_loc[j]*exp_freq;
      const complex fwave_tem_s_shifted = fwave_tem_s_loc[j]*exp_freq;
      const complex h_loc = cosdphi*fwave_tem_c_shifted +
                            sindphi*fwave_tem_s_shifted;
      const complex h_loc_minus_g = h_loc - fwave_ref_loc[j];
      dhdh_loc += creal(h_loc_minus_g)*creal(h_loc_minus_g) +
                  cimag(h_loc_minus_g)*cimag(h_loc_minus_g);
    }
    // correct for different weight at endpoints of integral
#pragma omp master
    for(size_t j = 0 ; j < nvals ; j += nvals-1) {
      const double phase = two_PI_dt*freqs[j];
      const complex exp_freq = cexp(phase*I);
      const complex fwave_tem_c_shifted = fwave_tem_c[j]*exp_freq;
      const complex fwave_tem_s_shifted = fwave_tem_s[j]*exp_freq;
      const complex h_loc = cosdphi*fwave_tem_c_shifted +
                            sindphi*fwave_tem_s_shifted;
      const complex h_loc_minus_g = h_loc - fwave_ref[j];
      dhdh_loc -= 0.5*(creal(h_loc_minus_g)*creal(h_loc_minus_g) +
                       cimag(h_loc_minus_g)*cimag(h_loc_minus_g));
    }
    dhdh_loc *= 4*deltaf;
#pragma omp atomic
    dhdh += dhdh_loc;
  }
  return dhdh;
}

// double precision input and double precision output
static void omp_conjrect(const double *mag, const double *phase,
                     complex *out, const size_t nvals)
{
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    const double * restrict mag_loc = mag+first;
    const double * restrict phase_loc = phase+first;
    complex * restrict out_loc = out+first;
    for(size_t j = 0 ; j < length ; ++j) {
      out_loc[j] = mag_loc[j]*conj(cexp(phase_loc[j]*I));
    }
  }
}

// double precision input and double precision output
static void omp_rect(const double *mag, const double *phase,
                     complex *out, const size_t nvals)
{
#pragma omp parallel
  {
    const int nthreads = omp_get_num_threads();
    const int mythread = omp_get_thread_num();
    const size_t chunk = (nvals+nthreads-1)/nthreads;
    const size_t first = mythread * chunk;
    const size_t length = first+chunk <= nvals ? chunk : nvals-first;
    const double * restrict mag_loc = mag+first;
    const double * restrict phase_loc = phase+first;
    complex * restrict out_loc = out+first;
    for(size_t j = 0 ; j < length ; ++j) {
      out_loc[j] = mag_loc[j]*cexp(phase_loc[j]*I);
    }
  }
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
    if(PyArray_TYPE(in_array) == NPY_DOUBLE)
      sum = omp_sum_double((double*)in_array->data, nvals);
    else if(PyArray_TYPE(in_array) == NPY_FLOAT)
      sum = omp_sum_float((float*)in_array->data, nvals);
    else
      assert(0 && "Internal error"), sum=0.;

    /*  construct the output from sum, from c double to python float */
    return Py_BuildValue("f", sum);
}

/*  wrapped omp_expi function */
static PyObject* ompexpi_func(PyObject* self, PyObject* args)
{

    PyArrayObject *in_array;
    PyObject *out_array;

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

    /* allocate output object */
    out_array = PyArray_SimpleNew(PyArray_NDIM(in_array), in_array->dimensions, NPY_CDOUBLE);
    if (out_array == NULL)
      return NULL;

    /* do actual work */
    const ssize_t nvals = PyArray_DIM(in_array, 0);
    if(PyArray_TYPE(in_array) == NPY_DOUBLE)
      omp_expi_double((double*)in_array->data, (complex*)((PyArrayObject *)out_array)->data, nvals);
    else if(PyArray_TYPE(in_array) == NPY_FLOAT)
      omp_expi_float((float*)in_array->data, (complex*)((PyArrayObject *)out_array)->data, nvals);
    else
      assert(0 && "Internal error");

    /*  construct the output from sum, from c double to python float */
    return out_array;
}

/* helpers */
static int check_array_is_double(PyArrayObject *in_array)
{
  if (PyArray_NDIM(in_array) != 1 ||
      PyArray_TYPE(in_array) != NPY_DOUBLE) {
    PyErr_Format(PyExc_ValueError,
                 "input array is %d-dimensional or not of type double or float",
                 PyArray_NDIM(in_array));
    return 0;
  }
  if (in_array->strides[0] != sizeof(double)) {
    PyErr_Format(PyExc_ValueError,
                 "input array has non unit stride %zd bytes",
                 in_array->strides[0]);
    return 0;
  }
  return 1;
}

static int check_array_is_complex(PyArrayObject *in_array)
{
  if (PyArray_NDIM(in_array) != 1 ||
      PyArray_TYPE(in_array) != NPY_CDOUBLE) {
    PyErr_Format(PyExc_ValueError,
                 "input array is %d-dimensional or not of type double or float",
                 PyArray_NDIM(in_array));
    return 0;
  }
  if (in_array->strides[0] != sizeof(complex)) {
    PyErr_Format(PyExc_ValueError,
                 "input array has non unit stride %zd bytes",
                 in_array->strides[0]);
    return 0;
  }
  return 1;
}

/*  wrapped omp_OverlapMaxing function */
static PyObject* ompOverlapMaxing_func(PyObject* self, PyObject* args)
{

    double dt;
    PyArrayObject *freqs, *fwave_ref, *fwave_tem_c, *fwave_tem_s;

    /*  parse single double, and 4 numpy array arguments */
    if (!PyArg_ParseTuple(args, "dO!O!O!O!", &dt,
                          &PyArray_Type, &freqs,
                          &PyArray_Type, &fwave_ref,
                          &PyArray_Type, &fwave_tem_c,
                          &PyArray_Type, &fwave_tem_s))
        return NULL;

    /* consistency checks */
    if(!check_array_is_double(freqs) || !check_array_is_complex(fwave_ref) ||
       !check_array_is_complex(fwave_tem_c) || !check_array_is_complex(fwave_tem_s))
      return NULL;

    const ssize_t nvals = PyArray_DIM(freqs, 0);
    if (PyArray_DIM(fwave_ref, 0) != nvals || PyArray_DIM(fwave_tem_c, 0) != nvals ||
        PyArray_DIM(fwave_tem_s, 0) != nvals) {
      PyErr_Format(PyExc_ValueError, "input arrays have incosistent sizes");
      return NULL;
    }

    /* do actual work */
    double sum;
    sum = omp_OverlapMaxing(dt, (double*restrict)freqs->data,
                            (complex*restrict)fwave_ref->data,
                            (complex*restrict)fwave_tem_c->data,
                            (complex*restrict)fwave_tem_s->data, nvals);

    /*  construct the output from sum, from c double to python float */
    return Py_BuildValue("f", sum);
}

/*  wrapped omp_conjrect function */
static PyObject* ompconjrect_func(PyObject* self, PyObject* args)
{

    PyArrayObject *mag_array, *phase_array;
    PyObject *out_array;

    /*  parse single numpy array argument */
    if (!PyArg_ParseTuple(args, "O!O!", &PyArray_Type, &mag_array,
                          &PyArray_Type, &phase_array))
        return NULL;

    /* consistency check */
    if (!check_array_is_double(mag_array) ||
        !check_array_is_double(phase_array)) {
      PyErr_Format(PyExc_ValueError,
                   "input arrays are not onedimensional or not of type double");
      return NULL;
    }

    const ssize_t nvals = PyArray_DIM(mag_array, 0);
    if (PyArray_DIM(phase_array, 0) != nvals) {
      PyErr_Format(PyExc_ValueError, "input arrays have incosistent sizes");
      return NULL;
    }

    /* allocate output object */
    out_array = PyArray_SimpleNew(PyArray_NDIM(mag_array),
                                  mag_array->dimensions, NPY_CDOUBLE);
    if (out_array == NULL)
      return NULL;

    /* do actual work */
    omp_conjrect((double*)mag_array->data, (double*)phase_array->data,
             (complex*)((PyArrayObject *)out_array)->data, nvals);

    /*  construct the output from sum, from c double to python float */
    return out_array;
}

/*  wrapped omp_rect function */
static PyObject* omprect_func(PyObject* self, PyObject* args)
{

    PyArrayObject *mag_array, *phase_array;
    PyObject *out_array;

    /*  parse single numpy array argument */
    if (!PyArg_ParseTuple(args, "O!O!", &PyArray_Type, &mag_array,
                          &PyArray_Type, &phase_array))
        return NULL;

    /* consistency check */
    if (!check_array_is_double(mag_array) ||
        !check_array_is_double(phase_array)) {
      PyErr_Format(PyExc_ValueError,
                   "input arrays are not onedimensional or not of type double");
      return NULL;
    }

    const ssize_t nvals = PyArray_DIM(mag_array, 0);
    if (PyArray_DIM(phase_array, 0) != nvals) {
      PyErr_Format(PyExc_ValueError, "input arrays have incosistent sizes");
      return NULL;
    }

    /* allocate output object */
    out_array = PyArray_SimpleNew(PyArray_NDIM(mag_array),
                                  mag_array->dimensions, NPY_CDOUBLE);
    if (out_array == NULL)
      return NULL;

    /* do actual work */
    omp_rect((double*)mag_array->data, (double*)phase_array->data,
             (complex*)((PyArrayObject *)out_array)->data, nvals);

    /*  construct the output from sum, from c double to python float */
    return out_array;
}

/*  define functions in module */
static PyMethodDef OmpSumMethods[] =
{
     {"sum", ompsum_func, METH_VARARGS,
         "compute the sum of a numpy array"},
     {"expi", ompexpi_func, METH_VARARGS,
         "compute exp(i*angle) of the real angle numpy array"},
     {"OverlapMaxing", ompOverlapMaxing_func, METH_VARARGS,
         "compute overlap between two waveforms for given time shift"},
     {"conjrect", ompconjrect_func, METH_VARARGS,
         "construct the conjugate of a complex number given magnitude and phase"},
     {"rect", omprect_func, METH_VARARGS,
         "construct a complex number given magnitude and phase"},
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
