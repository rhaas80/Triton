#!/usr/bin/env python

"""
setup.py file for python code associated with Project Triton.

To install for an individual user, run
  python setup.py install --user
The entire code will build, be packaged up nicely, and installed in
python's default user directory.  Now, 'import PyGW' may be run from a
python instance started in any directory on the system.
"""

## distutils doesn't build swig modules in the correct order by
## default -- the python module is installed first.  This will pop
## 'build_ext' to the beginning of the command list.
from distutils.command.build import build
build.sub_commands = sorted(build.sub_commands, key=lambda sub_command: int(sub_command[0]!='build_ext'))

## I also need to copy the SWIG-generated python script PyGW.py to
## PyGW/__init__.py so that it gets installed correctly.
from distutils.command.build_ext import build_ext as _build_ext
from distutils.file_util import copy_file
class build_ext(_build_ext):
    """Specialized Python source builder for moving SWIG module."""
    def run(self):
        _build_ext.run(self)
        copy_file('PyGW.py', 'PyGW/__init__.py')

## Now load the basic necessities
from distutils.core import setup, Extension
import os
import glob




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
                          extra_compile_args = ['-w'], # turn off all warnings
                          # extra_link_args = [], 
                          # export_symbols = [], # export these symbols for shared extensions
                          language='c++',
                          swig_opts=['-c++'], # '-globals', 'constants', 
                          )

## This function does the actual work of build everything and
## installing it.
setup(name = 'PyGW',
      version = '2',
      description = 'Python interface for manipulating Waveform objects',
      # long_description = ,
      author = 'Michael Boyle',
      author_email = 'michael.oliver.boyle@gmail.com',
      # maintainer = 'Michael Boyle',
      # maintainer_email = 'michael.oliver.boyle@gmail.com',
      url = 'https://www.black-holes.org/wiki/documentation/waveforms',
      # download_url = 'https://www.black-holes.org/wiki/documentation/waveforms',
      packages = ['PyGW'],
      # py_modules = ,
      scripts = ['PyGW/Scripts/ConvergenceExample.py', 'PyGW/Scripts/ExtrapolationExample.py', 'PyGW/Scripts/ExtrapolationExample_h5.py'],
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
      cmdclass={'build_ext': build_ext},
      # data_files = ,
      # package_dir = 
      )
