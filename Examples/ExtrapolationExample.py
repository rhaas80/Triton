#! /usr/bin/env python

"""
Demonstrate usage of the extrapolation script for non-H5 files.

This is an example script to demonstrate how to run extrapolation.
The variables below should be set to other values so that they make
sense.  But otherwise, this is a working example.  To run, simply make
this script executable and run from the command prompt.
For a list of other options that may be adjusted, see the help text of
the 'Extrapolate' class in PyGWExtrapolate.py.

Note that numerous other options are avilable; see the docstring in
Triton/Python/Scripts/PyGWExtrapolate for more information.

To extrapolate H5 files, see the similar file named
'ExtrapolationExample_h5.py'.

"""

from PyGW.Extrapolate import Extrapolate

D = {}
D['InputDirectory'] = '/path/to/data/directory'  # May be relative
D['OutputDirectory'] = '/path/to/output/directory'  # May be relative
D['ADMMass'] = 1.01  # In the same units as the input data
D['ChMass'] = 0.99  # In the same units as the input data

Extrapolate(Dictionary=D)
