#! /usr/bin/env python

"""
Demonstrate usage of the extrapolation script for H5 files.

This is an example script to demonstrate how to run extrapolation.
The variables below should be set to other values so that they make
sense.  But otherwise, this is a working example.  To run, simply make
this script executable and run from the command prompt.
For a list of other options that may be adjusted, see the help text of
the 'Extrapolate' class in 'Triton_IS_FOR_OLD_DATA/PyGW_IS_FOR_OLD_DATA/Extrapolate_h5.py' by running
  import PyGW_IS_FOR_OLD_DATA.Extrapolate_h5
  help(PyGW_IS_FOR_OLD_DATA.Extrapolate_h5.Extrapolate)
from within python.

To extrapolate non-H5 files, see the similar file named
'Triton_IS_FOR_OLD_DATA/Examples/ExtrapolationExample.py'.

"""

from PyGW_IS_FOR_OLD_DATA import PickChMass
from PyGW_IS_FOR_OLD_DATA.Extrapolate_h5 import Extrapolate

D = {}
D['InputDirectory'] = '/path/to/data/directory'  # May be relative or absolute
D['OutputDirectory'] = '/path/to/output/directory'  # May be relative or absolute
D['ChMass'] = PickChMass('/path/to/Horizons/directory/Horizons.h5')  # In the same units as the input data

Extrapolate(Dictionary=D)
