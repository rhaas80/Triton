///////////////////////////////////////////////////////////////
// Re-written from pycontainer.swg to convert to numpy arrays //
////////////////////////////////////////////////////////////////

%fragment("StdSequenceTraits","header",
	  fragment="StdTraits",
	  fragment="SwigPySequence_Cont")
{
  namespace swig {
    template <class SwigPySeq, class Seq>
      inline void
      assign(const SwigPySeq& swigpyseq, Seq* seq) {
      // seq->assign(swigpyseq.begin(), swigpyseq.end()); // not used as not always implemented
      typedef typename SwigPySeq::value_type value_type;
      typename SwigPySeq::const_iterator it = swigpyseq.begin();
      for (;it != swigpyseq.end(); ++it) {
	seq->insert(seq->end(),(value_type)(*it));
      }
    }

    template <class Seq, class T = typename Seq::value_type >
      struct traits_asptr_stdseq {
	typedef Seq sequence;
	typedef T value_type;

	static int asptr(PyObject *obj, sequence **seq) {
	  if (obj == Py_None || SWIG_Python_GetSwigThis(obj)) {
	    sequence *p;
	    if (::SWIG_ConvertPtr(obj,(void**)&p,
				  swig::type_info<sequence>(),0) == SWIG_OK) {
	      if (seq) *seq = p;
	      return SWIG_OLDOBJ;
	    }
	  } else if (PySequence_Check(obj)) {
	    try {
	      SwigPySequence_Cont<value_type> swigpyseq(obj);
	      if (seq) {
		sequence *pseq = new sequence();
		assign(swigpyseq, pseq);
		*seq = pseq;
		return SWIG_NEWOBJ;
	      } else {
		return swigpyseq.check() ? SWIG_OK : SWIG_ERROR;
	      }
	    } catch (std::exception& e) {
	      if (seq) {
		if (!PyErr_Occurred()) {
		  PyErr_SetString(PyExc_TypeError, e.what());
		}
	      }
	      return SWIG_ERROR;
	    }
	  }
	  return SWIG_ERROR;
	}
      };

    template <class Seq, class T = typename Seq::value_type >
      struct traits_from_stdseq {
	typedef Seq sequence;
	typedef T value_type;
	typedef typename Seq::size_type size_type;
	typedef typename sequence::const_iterator const_iterator;

	static PyObject *from(const sequence& seq) {
	  %#ifdef SWIG_PYTHON_EXTRA_NATIVE_CONTAINERS
	    swig_type_info *desc = swig::type_info<sequence>();
	  if (desc && desc->clientdata) {
	    return SWIG_NewPointerObj(new sequence(seq), desc, SWIG_POINTER_OWN);
	  }
	  %#endif
	     size_type size = seq.size();
	  if (size <= (size_type)INT_MAX) {
	    PyObject *obj = PyTuple_New((int)size);
	    int i = 0;
	    for (const_iterator it = seq.begin();
		 it != seq.end(); ++it, ++i) {
	      PyTuple_SetItem(obj,i,swig::from<value_type>(*it));
	    }
	    return obj;
	  } else {
	    PyErr_SetString(PyExc_OverflowError,"sequence size not valid in python");
	    return NULL;
	  }
	}
      };

    template <typename T>
    int Numpy_TypeName();
    
    template <class Seq, class T = typename Seq::value_type >
    struct traits_from_stdseq_numpy_1d {
      typedef Seq sequence;
      typedef T value_type;
      typedef typename Seq::size_type size_type;
      typedef typename sequence::const_iterator const_iterator;
      
      static PyObject *from(const sequence& seq) {
	unsigned int count=0;
	printf("Step %d\n", ++count);
	%#ifdef SWIG_PYTHON_EXTRA_NATIVE_CONTAINERS
	  swig_type_info *desc = swig::type_info<sequence>();
	if (desc && desc->clientdata) {
	  return SWIG_NewPointerObj(new sequence(seq), desc, SWIG_POINTER_OWN);
	}
	%#endif
	   size_type size = seq.size();
	printf("Step %d\n", ++count);
	if (size <= (size_type)INT_MAX) {
	  // 	    PyObject *obj = PyTuple_New((int)size);
	  // 	    int i = 0;
	  // 	    for (const_iterator it = seq.begin();
	  // 		 it != seq.end(); ++it, ++i) {
	  // 	      PyTuple_SetItem(obj,i,swig::from<value_type>(*it));
	  // 	    }
	  // 	    return obj;
	  int nd = 1;
	  npy_intp dims[1] = { size };
	printf("Step %d\n", ++count);
	  PyObject* array = PyArray_SimpleNew(nd, dims, Numpy_TypeName<T>());
	printf("Step %d\n", ++count);
	  
// 	  if (!array || !require_dimensions(array, 1) ||
// 	      !require_size(array, size, 1)) SWIG_fail;
	  return array;
	} else {
	  PyErr_SetString(PyExc_OverflowError,"sequence size not valid in python");
	  return NULL;
	}
      }
    };
    
    template <class Seq, class T = typename Seq::value_type >
    struct traits_from_stdseq_numpy_2d {
      typedef Seq sequence;
      typedef T value_type;
      typedef typename Seq::size_type size_type;
      typedef typename sequence::const_iterator const_iterator;
      
      static PyObject *from(const sequence& seq) {
	%#ifdef SWIG_PYTHON_EXTRA_NATIVE_CONTAINERS
	  swig_type_info *desc = swig::type_info<sequence>();
	if (desc && desc->clientdata) {
	  return SWIG_NewPointerObj(new sequence(seq), desc, SWIG_POINTER_OWN);
	}
	%#endif;
	size_type size1 = seq.size();
	if (size1 <= (size_type)INT_MAX) {
	  // 	    PyObject *obj = PyTuple_New((int)size);
	  // 	    int i = 0;
	  // 	    for (const_iterator it = seq.begin();
	  // 		 it != seq.end(); ++it, ++i) {
	  // 	      PyTuple_SetItem(obj,i,swig::from<value_type>(*it));
	  // 	    }
	  // 	    return obj;
	  int nd = 2;
	  size_type size2 = size1==0 ? 0 : seq[0].size();
	  if (!(size2 <= (size_type)INT_MAX)) {
	    PyErr_SetString(PyExc_OverflowError,"sequence size2 not valid in python");
	    return NULL;
	  }
	  npy_intp dims[2] = { size1, size2 };
	  PyObject* array = PyArray_SimpleNew(nd, dims, Numpy_TypeName<typename T::value_type>());
	  
// 	  if (!array || !require_dimensions(array, 1) ||
// 	      !require_size(array, size, 1)) SWIG_fail;
	  return array;
	} else {
	  PyErr_SetString(PyExc_OverflowError,"sequence size1 not valid in python");
	  return NULL;
	}
      }
    };
  }
}



///////////////////////////////////////////////////////////
// The following is the original content of std_vector.i //
///////////////////////////////////////////////////////////

/*
  Vectors
*/

%fragment("StdVectorTraits","header",fragment="StdSequenceTraits")
{
  namespace swig {
    //%{
    template <class T>
    struct traits_asptr<std::vector<T> >  {
      static int asptr(PyObject *obj, std::vector<T> **vec) {
	return traits_asptr_stdseq<std::vector<T> >::asptr(obj, vec);
      }
    };
    
    template <class T>
    struct traits_from<std::vector<T> > {
      static PyObject *from(const std::vector<T>& vec) {
	return traits_from_stdseq<std::vector<T> >::from(vec);
      }
    };
    //%}
    
    %define %std_vector_numpy_traits(DATA_TYPE, DATA_TYPECODE);
    template <>
    struct traits_from<std::vector<DATA_TYPE> > {
      static PyObject *from(const std::vector<DATA_TYPE>& vec) {
	return traits_from_stdseq_numpy_1d<std::vector<DATA_TYPE> >::from(vec);
      }
    };
    template <>
    struct traits_from<std::vector<std::vector<DATA_TYPE> > > {
      static PyObject *from(const std::vector<std::vector<DATA_TYPE> >& vec) {
	return traits_from_stdseq_numpy_2d<std::vector<std::vector<DATA_TYPE> > >::from(vec);
      }
    };
    template <>
    int Numpy_TypeName<DATA_TYPE>() { return DATA_TYPECODE; }
    %enddef    /* %std_vector_numpy_traits() macro */
    %std_vector_numpy_traits(signed char       , NPY_BYTE     );
    %std_vector_numpy_traits(unsigned char     , NPY_UBYTE    );
    %std_vector_numpy_traits(short             , NPY_SHORT    );
    %std_vector_numpy_traits(unsigned short    , NPY_USHORT   );
    %std_vector_numpy_traits(int               , NPY_INT      );
    %std_vector_numpy_traits(unsigned int      , NPY_UINT     );
    %std_vector_numpy_traits(long              , NPY_LONG     );
    %std_vector_numpy_traits(unsigned long     , NPY_ULONG    );
    %std_vector_numpy_traits(long long         , NPY_LONGLONG );
    %std_vector_numpy_traits(unsigned long long, NPY_ULONGLONG);
    %std_vector_numpy_traits(float             , NPY_FLOAT    );
    %std_vector_numpy_traits(double            , NPY_DOUBLE   );
  }
}

#define %swig_vector_methods(Type...) %swig_sequence_methods(Type)
#define %swig_vector_methods_val(Type...) %swig_sequence_methods_val(Type);

%include <std/std_vector.i>

