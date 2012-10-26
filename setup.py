#!/usr/bin/env python

"""
setup.py file for python code associated with Project Triton.

To install for an individual user, run
  python setup.py build_ext
  python setup.py install --user
Now, 'import PyGW' may be run from a python
instance started in any directory on the system.
"""

from distutils.sysconfig import get_config_var
get_config_var("PY_CFLAGS")  # make sure _config_vars is initialized
from distutils.sysconfig import _config_vars

_config_vars['PY_CFLAGS'] = _config_vars['PY_CFLAGS'].replace('-Wstrict-prototypes', '')

from distutils.core import setup, Extension
import os

PyGWExtension = Extension(name = '_PyGW',
                          sources = ['Objects/Waveform/Waveform_AdjustTime.cpp',
                                     'Objects/Waveform/Waveform_AlignAndHybridize.cpp',
                                     'Objects/Waveform/Waveform_Features.cpp',
                                     'Objects/Waveform/Waveform_Interpolate.cpp',
                                     'Objects/Waveform/Waveform_ManipulateModes.cpp',
                                     'Objects/Waveform/Waveform_Operators.cpp',
                                     'Objects/Waveform/Waveform_Output.cpp',
                                     'Objects/Waveform/Waveform_PhysicalConversions.cpp',
                                     'Objects/Waveform/Waveform_RadiationFrame.cpp',
                                     'Objects/Waveform/Waveform_Rotation.cpp',
                                     'Objects/Waveform.cpp',
                                     'Objects/WaveformAtAPoint.cpp',
                                     'Objects/WaveformAtAPointFT.cpp',
                                     'Objects/Waveforms.cpp',
                                     'PostNewtonian/EOBModel.cpp',
                                     'PostNewtonian/Flux.cpp',
                                     'PostNewtonian/OrbitalPhasing_EOB.cpp',
                                     'PostNewtonian/OrbitalPhasing_T1.cpp',
                                     'PostNewtonian/OrbitalPhasing_T2.cpp',
                                     'PostNewtonian/OrbitalPhasing_T3.cpp',
                                     'PostNewtonian/OrbitalPhasing_T4.cpp',
                                     'PostNewtonian/OrbitalPhasing_T4_Spin.cpp',
                                     'PostNewtonian/PostNewtonian.cpp',
                                     'PostNewtonian/QNMs.cpp',
                                     'PostNewtonian/WaveformAmplitudes.cpp',
                                     'Utilities/EasyParser.cpp',
                                     'Utilities/Eccentricity.cpp',
                                     'Utilities/fft.cpp',
                                     'Utilities/FileIO.cpp',
                                     'Utilities/GaussJordanElimination.cpp',
                                     'Utilities/Interpolate.cpp',
                                     'Utilities/LUDecomposition.cpp',
                                     'Utilities/NoiseCurves.cpp',
                                     'Utilities/QRDecomposition.cpp',
                                     'Utilities/Quaternions.cpp',
                                     'Utilities/SingularValueDecomposition.cpp',
                                     'Utilities/SWSHs.cpp',
                                     'Utilities/VectorFunctions.cpp',
                                     'Utilities/WignerDMatrix.cpp',
                                     'Utilities/WignerDMatrix_Q.cpp',
                                     'PyGW.i'],
                          depends = ['Objects/Waveform.hpp',
                                     'Objects/WaveformAtAPoint.hpp',
                                     'Objects/WaveformAtAPointFT.hpp',
                                     'Objects/Waveforms.hpp',
                                     'PostNewtonian/EOBModel.hpp',
                                     'PostNewtonian/Flux.hpp',
                                     'PostNewtonian/OrbitalPhasing_EOB.hpp',
                                     'PostNewtonian/OrbitalPhasing_T1.hpp',
                                     'PostNewtonian/OrbitalPhasing_T2.hpp',
                                     'PostNewtonian/OrbitalPhasing_T3.hpp',
                                     'PostNewtonian/OrbitalPhasing_T4.hpp',
                                     'PostNewtonian/OrbitalPhasing_T4_Spin.hpp',
                                     'PostNewtonian/PostNewtonian.hpp',
                                     'PostNewtonian/QNMs.hpp',
                                     'PostNewtonian/WaveformAmplitudes.hpp',
                                     'Utilities/EasyParser.hpp',
                                     'Utilities/Eccentricity.hpp',
                                     'Utilities/fft.hpp',
                                     'Utilities/FileIO.hpp',
                                     'Utilities/GaussJordanElimination.hpp',
                                     'Utilities/Interpolate.hpp',
                                     'Utilities/LUDecomposition.hpp',
                                     'Utilities/NoiseCurves.hpp',
                                     'Utilities/QRDecomposition.hpp',
                                     'Utilities/Quaternions.hpp',
                                     'Utilities/SingularValueDecomposition.hpp',
                                     'Utilities/SWSHs.hpp',
                                     'Utilities/VectorFunctions.hpp',
                                     'Utilities/WignerDMatrix.hpp',
                                     'Utilities/WignerDMatrix_Q.hpp'
                                     'Utilities/WaveformUtilities_ErrorCodes.hpp'],
                          include_dirs=['Utilities', 'PostNewtonian', 'Objects', '/opt/local/include'], 
                          library_dirs=['/opt/local/lib'], 
                          # libraries=['gsl', 'gslcblas'], 
                          # runtime_library_dirs = [], 
                          define_macros = [('GitRevision', '"{0}"'.format(os.popen('git rev-parse HEAD').read().strip()))],
                          # undef_macros = [],
                          # extra_objects = [], # other things to link with
                          # extra_compile_args = [],
                          # extra_link_args = [], 
                          # export_symbols = [], # export these symbols for shared extensions
                          language='c++',
                          swig_opts=['-c++', '-outdir', 'build'] # '-globals', 'constants', 
                          )

setup(name="PyGW",
      version='2',
      ext_modules = [PyGWExtension],
      py_modules = ["PyGW"])
