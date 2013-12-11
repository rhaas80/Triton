import PyGW_IS_FOR_OLD_DATA
import PyGW_IS_FOR_OLD_DATA.plot

W = PyGW_IS_FOR_OLD_DATA.Waveform('../../Python/Examples/TestData/rMPsi4_ExtrapolatedN-1.dat', 'MagArg')
WE = PyGW_IS_FOR_OLD_DATA.Waveform(W)
WQ = PyGW_IS_FOR_OLD_DATA.Waveform(W)

# [alpha, beta, gamma] = [0.01, 0.05, 0.003]
[alpha, beta, gamma] = [1.01, 2.05, 4.003]
Q = PyGW_IS_FOR_OLD_DATA.Quaternion(alpha, beta, gamma)

WE.RotateCoordinates(alpha, beta, gamma)
WQ.RotateCoordinates(Q)

WDiff = WE/WQ

figure()
WDiff.plot('LogMag')
figure()
WDiff.plot('Arg')

print("Differences should be in the region of 1e-12 or less")
