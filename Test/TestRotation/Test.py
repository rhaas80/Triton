import PyGW
import PyGW.plot

W = PyGW.Waveform('../../Python/Examples/TestData/rMPsi4_ExtrapolatedN-1.dat', 'MagArg')
WE = PyGW.Waveform(W)
WQ = PyGW.Waveform(W)

# [alpha, beta, gamma] = [0.01, 0.05, 0.003]
[alpha, beta, gamma] = [1.01, 2.05, 4.003]
Q = PyGW.Quaternion(alpha, beta, gamma)

WE.RotateCoordinates(alpha, beta, gamma)
WQ.RotateCoordinates(Q)

WDiff = WE/WQ

figure()
WDiff.plot('LogMag')
figure()
WDiff.plot('Arg')

print("Differences should be in the region of 1e-12 or less")
