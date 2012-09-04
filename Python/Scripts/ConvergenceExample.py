#! /usr/bin/env python

"""
Demonstrate usage of the convergence script.

This is an example script to demonstrate how to run convergence.  The
variables below should be set to other values so that they make sense.
But otherwise, this is a working example.  To run, simply make this
script executable and run from the command prompt.  For a list of
other options that may be adjusted, see the help text of the
'Convergence' class in PyGWConvergence.py.

"""

from PyGWConvergence import Convergence

D = {}
D['LevList'] = ['../Lev1', '../Lev2', '../Lev3']  # Paths may be relative
D['RWZFiles'] = 'rh_ExtrapolatedN{ExtrapOrder}.dat'

Convergence(Dictionary=D)
