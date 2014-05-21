#!/usr/bin/env python

"""
setup.py file for python code associated with Project Triton_IS_FOR_OLD_DATA.

To install for an individual user, run
  python setup.py install --user
The entire code will build, be packaged up nicely, and installed in
python's default user directory.  Now, 'import PyGW_IS_FOR_OLD_DATA' may be run from a
python instance started in any directory on the system.
"""

## Make sure the old version of PyGW is gone
import os,glob,site,distutils.sysconfig
for installation_dir in [site.USER_SITE,
                         distutils.sysconfig.get_python_lib(standard_lib=True),
                         distutils.sysconfig.get_python_lib(),
                         distutils.sysconfig.get_python_lib(plat_specific=True)]:
    try:
        os.remove(glob.glob(os.path.join(installation_dir,'_PyGW*')))
        os.rmdir(os.path.join(installation_dir,'PyGW'))
        os.remove(glob.glob(os.path.join(installation_dir,'PyGW*')))
    except:
        pass

## distutils doesn't build swig modules in the correct order by
## default -- the python module is installed first.  This will pop
## 'build_ext' to the beginning of the command list.
from distutils.command.build import build
build.sub_commands = sorted(build.sub_commands, key=lambda sub_command: int(sub_command[0]!='build_ext'))

## I also need to copy the SWIG-generated python script PyGW_IS_FOR_OLD_DATA.py to
## PyGW_IS_FOR_OLD_DATA/__init__.py so that it gets installed correctly.
from distutils.command.build_ext import build_ext as _build_ext
from distutils.file_util import copy_file
class build_ext(_build_ext):
    """Specialized Python source builder for moving SWIG module."""
    def run(self):
        _build_ext.run(self)
        copy_file('PyGW_IS_FOR_OLD_DATA.py', 'PyGW_IS_FOR_OLD_DATA/__init__.py')

## Now load the basic necessities
from distutils.core import setup, Extension
import os
import glob

## Remove a compiler flag that doesn't belong there for C++
import distutils.sysconfig as ds
cfs=ds.get_config_vars()
for key, value in cfs.iteritems():
    if(type(cfs[key])==str) :
        cfs[key] = value.replace('-Wstrict-prototypes', '')\
                        .replace('-DNDEBUG', '') # never disable assert()

## This gets the list of files to build and the headers they depend on
CPPFiles = glob.glob("Utilities/*.cpp") + glob.glob("PostNewtonian/*.cpp") + glob.glob("Objects/*.cpp") + glob.glob("Objects/Waveform/*.cpp")
SourceFiles = CPPFiles + ['PyGW_IS_FOR_OLD_DATA.i']
DependencyFiles = [f.replace('.cpp','.hpp') for f in CPPFiles] + ['Utilities/WaveformUtilities_ErrorCodes.hpp']

## This class tells distutils how to compile the extension.
PyGW_IS_FOR_OLD_DATAExtension = Extension(name = '_PyGW_IS_FOR_OLD_DATA',
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
setup(name = 'PyGW_IS_FOR_OLD_DATA',
      version = '2.0.7',
      description = 'Python interface for manipulating Waveform objects',
      # long_description = ,
      author = 'Michael Boyle',
      author_email = 'michael.oliver.boyle@gmail.com',
      # maintainer = 'Michael Boyle',
      # maintainer_email = 'michael.oliver.boyle@gmail.com',
      url = 'https://www.black-holes.org/wiki/documentation/waveforms',
      # download_url = 'https://www.black-holes.org/wiki/documentation/waveforms',
      packages = ['PyGW_IS_FOR_OLD_DATA'],
      # py_modules = ,
      scripts = ['Examples/ConvergenceExample.py', 'Examples/ExtrapolationExample.py', 'Examples/ExtrapolationExample_h5.py'],
      ext_modules = [PyGW_IS_FOR_OLD_DATAExtension],
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
