#! /usr/bin/env python

import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import PyGW

OpeningAngle = np.pi/7.
Omega = 1./20.

length = 20000
t = PyGW.vectord(np.linspace(0., 15*np.pi/(Omega*np.cos(OpeningAngle)), num=length))
R = PyGW.vectorq(length)
X = PyGW.vectorq(length)
Y = PyGW.vectorq(length)
Z = PyGW.vectorq(length)
X_MinRot = PyGW.vectorq(length)
Y_MinRot = PyGW.vectorq(length)
Z_MinRot = PyGW.vectorq(length)
x = PyGW.Quaternion(0, 1, 0, 0)
y = PyGW.Quaternion(0, 0, 1, 0)
z = PyGW.Quaternion(0, 0, 0, 1)
one = PyGW.Quaternion(1, 0, 0, 0)

def QuatSqrt(Q) :
    return (one+Q)/np.sqrt(2+2*Q[0])

fig1 = plt.figure('GammaZero')
ax1 = fig1.add_subplot(111, projection='3d')
fig2 = plt.figure('MinRot')
ax2 = fig2.add_subplot(111, projection='3d')

for j,OverallRotation in enumerate([PyGW.Quaternion(1,0,0,0), QuatSqrt(-PyGW.Quaternion(0,OpeningAngle/5.0,OpeningAngle/7.0,0).exp()*z)]) :
    
    for i in range(length) :
        phi = Omega*t[i]
        v = OverallRotation*PyGW.Quaternion(0, np.sin(OpeningAngle)*np.cos(phi), np.sin(OpeningAngle)*np.sin(phi), np.cos(OpeningAngle))*OverallRotation.Conjugate()
        R[i] = QuatSqrt(-v*z)
    
    R_MinRot = PyGW.MinimalRotation(R, t)
    
    R_z = (PyGW.Quaternion(0,0,0,(2.53*np.pi/9.)*j)).exp()
    
    for i in range(length) :
        X[i] = OverallRotation.Conjugate()*R[i]*x*R[i].Conjugate()*OverallRotation
        Y[i] = OverallRotation.Conjugate()*R[i]*y*R[i].Conjugate()*OverallRotation
        Z[i] = OverallRotation.Conjugate()*R[i]*z*R[i].Conjugate()*OverallRotation
        X_MinRot[i] = R_z.Conjugate()*OverallRotation.Conjugate()*R_MinRot[i]*x*R_MinRot[i].Conjugate()*OverallRotation*R_z
        Y_MinRot[i] = R_z.Conjugate()*OverallRotation.Conjugate()*R_MinRot[i]*y*R_MinRot[i].Conjugate()*OverallRotation*R_z
        Z_MinRot[i] = R_z.Conjugate()*OverallRotation.Conjugate()*R_MinRot[i]*z*R_MinRot[i].Conjugate()*OverallRotation*R_z
    
    ax1.plot([X[i].Components()[1] for i in range(len(X))],
            [X[i].Components()[2] for i in range(len(X))],
            [X[i].Components()[3] for i in range(len(X))],
            label='X')
    ax1.plot([Y[i].Components()[1] for i in range(len(Y))],
            [Y[i].Components()[2] for i in range(len(Y))],
            [Y[i].Components()[3] for i in range(len(Y))],
            label='Y')
    ax1.plot([Z[i].Components()[1] for i in range(len(Z))],
            [Z[i].Components()[2] for i in range(len(Z))],
            [Z[i].Components()[3] for i in range(len(Z))],
            label='Z')
    ax1.legend()
    plt.show()
    ax2.plot([X_MinRot[i].Components()[1] for i in range(len(X_MinRot))],
            [X_MinRot[i].Components()[2] for i in range(len(X_MinRot))],
            [X_MinRot[i].Components()[3] for i in range(len(X_MinRot))],
            label='X_MinRot')
    ax2.plot([Y_MinRot[i].Components()[1] for i in range(len(Y_MinRot))],
            [Y_MinRot[i].Components()[2] for i in range(len(Y_MinRot))],
            [Y_MinRot[i].Components()[3] for i in range(len(Y_MinRot))],
            label='Y_MinRot')
    ax2.plot([Z_MinRot[i].Components()[1] for i in range(len(Z_MinRot))],
            [Z_MinRot[i].Components()[2] for i in range(len(Z_MinRot))],
            [Z_MinRot[i].Components()[3] for i in range(len(Z_MinRot))],
            label='Z_MinRot')
    ax2.legend()
    plt.show()
