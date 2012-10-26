#!/usr/bin/env python

"""
setup.py file for python code associated with Project Triton.

To install for an individual user, run
  python setup.py install --user
The entire code will build, be packaged up nicely, and installed in
python's default user directory.  Now, 'import PyGW' may be run from a
python instance started in any directory on the system.
"""

from distutils.core import setup, Extension
import os
import glob

## distutils doesn't build swig modules in the correct order by
## default -- the python module is installed first.  This will pop
## 'build_ext' to the beginning of the command list.
from distutils.command.build import build
build.sub_commands = sorted(build.sub_commands, key=lambda sub_command: int(sub_command[0]!='build_ext'))

## This gets the list of files to build and the headers they depend on
CPPFiles = glob.glob("Utilities/*.cpp") + glob.glob("PostNewtonian/*.cpp") + glob.glob("Objects/*.cpp") + glob.glob("Objects/Waveform/*.cpp")
SourceFiles = CPPFiles + ['PyGW.i']
DependencyFiles = [f.replace('.cpp','.hpp') for f in CPPFiles] + ['Utilities/WaveformUtilities_ErrorCodes.hpp']

## This class tells distutils how to compile the extension.
PyGWExtension = Extension(name = '_PyGW',
                          sources = SourceFiles,
                          depends = DependencyFiles,
                          include_dirs=['Utilities', 'PostNewtonian', 'Objects'], #, '/opt/local/include'], 
                          # library_dirs=['/opt/local/lib'], 
                          # libraries=['gsl', 'gslcblas'], 
                          # runtime_library_dirs = [], 
                          define_macros = [('GitRevision', '"{0}"'.format(os.popen('git rev-parse HEAD').read().strip()))],
                          # undef_macros = [],
                          # extra_objects = [], # other things to link with
                          # extra_compile_args = ['-Wno-sign-compare', '-Wno-conversion', '-Wno-reorder', '-Wno-unused-value', '-Wno-uninitialized'],
                          extra_compile_args = ['-w'], # turn off all warnings
                          # extra_link_args = [], 
                          # export_symbols = [], # export these symbols for shared extensions
                          language='c++',
                          swig_opts=['-c++', '-outdir', 'PyGW'] # '-globals', 'constants', 
                          )

## This function does the actual work of build everything and
## installing it.
setup(name = 'PyGW',
      version = '3',
      description = 'Python interface for manipulating Waveform objects',
      # long_description = ,
      author = 'Michael Boyle',
      author_email = 'michael.oliver.boyle@gmail.com',
      # maintainer = 'Michael Boyle',
      # maintainer_email = 'michael.oliver.boyle@gmail.com',
      url = 'http://www.black-holes.org/',
      # download_url = ,
      # packages = ,
      # py_modules = ['PyGW'],#, 'PyGW.plot', 'PyGW.plot_on_sphere'],
      # scripts = [],
      ext_modules = [PyGWExtension],
      # classifiers = ,
      # distclass = ,
      # script_name = ,
      # script_args = ,
      # options = ,
      # license = ,
      # keywords = ,
      # platforms = ,
      # cmdclass = ,
      # data_files = ,
      # package_dir = 
      packages = ['PyGW', 'PyGW.plot', 'PyGW.plot_on_sphere'],
      package_dir = {'PyGW':'PyGW', 'PyGW.plot':'PyGW', 'PyGW.plot_on_sphere':'PyGW'}
      )
