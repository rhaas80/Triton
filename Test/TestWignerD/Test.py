import WignerD
import math

alpha = 0.1
beta = 0.04
gamma = 0.03
Q = WignerD.Quaternion(alpha,beta,gamma)
print(alpha, beta, gamma)
print(Q)

AnyBad = False

for l in range(9) :
    for mp in range(-l,l+1) :
        for m in range(-l,l+1) :
            D_E = WignerD.WignerDMatrix  (l,mp,m, alpha,beta,gamma)
            D_Q = WignerD.WignerDMatrix_Q(l,mp,m, Q)
            [Mag_E, Arg_E] = D_E.Value()
            [Mag_Q, Arg_Q] = D_Q.Value()
            if(abs(Mag_E-Mag_Q)>1e-13) :
                print("Bad Mag: ", l, mp, m, Mag_E, Mag_Q)
                AnyBad = True
            if(abs(math.fmod(Arg_E-Arg_Q, 2*pi))>1e-12 and abs(Mag_E)>0.0) :
                print("Bad Arg: ", l, mp, m, Arg_E,Arg_Q)
                AnyBad = True

if(not AnyBad) :
    print("No differences!")
