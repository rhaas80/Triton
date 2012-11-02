#! /usr/bin/env python

"""
Demonstrate usage of the convergence script.

This is an example script to demonstrate how to run convergence.  The
variables below should be set to other values so that they make sense.
But otherwise, this is a working example.  To run, simply make this
script executable and run from the command prompt.

Note that numerous other options are avilable; see the docstring in
Triton/Python/Scripts/PyGWConvergence.py for more information.

"""

from PyGW.Convergence import Convergence

D = {}

D['OutputDirectory'] = '/path/to/output/directory'  # May be relative or absolute

D['LevList'] = ['../Lev1', '../Lev2', '../Lev3']  # Paths may be relative

D['RWZFiles'] = 'rh_ExtrapolatedN{ExtrapOrder}.dat'
# Note: In the above '{ExtrapOrder}' should NOT be removed or replaced
#       with anything else; this is a python format string, and is
#       automatically replaced by a number corresponding to the
#       extrapolation orders you give as D['ExtrapolationOrders'],
#       which defaults to [-1,5].  See the docstring in
#       PyGWConvergence.py for more information.

Convergence(Dictionary=D)
