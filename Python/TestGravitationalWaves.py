# import GravitationalWaves

# W = GravitationalWaves.Waveform("/Users/boyle/Research/Data/UltimateRun/rMPsi4_ExtrapolatedN-1.dat", "MagArg")

# T = W.TRef()
# R = W.RRef()
# LM0 = W.LMRef(0)
# Mag0 = W.MagRef(0)
# Arg0 = W.ArgRef(0)
# LM = W.LMRef()
# Mag = W.MagRef()
# Arg = W.ArgRef()
# LM
# type(Mag)
# type(Arg)

# figure()
# plot(T, Mag0)
# figure()
# plot(T, Arg0)
# LM0



import GravitationalWaves
W = GravitationalWaves.Waveform("/Users/boyle/Research/Triton/Python/TestData/rMPsi4_ExtrapolatedN-1.dat", "MagArg")
T = W.T()
print(type(T))
# Omega2m2 = W.Omega2m2()
# print(type(Omega2m2))
# print(Omega2m2.shape)
# print(W.NTimes())