import WignerD
import math

# [alpha, beta, gamma] = [1.19, 2.04, 3.03]
# [alpha, beta, gamma] = [0.1, 0.04, 0.03]
# [alpha, beta, gamma] = [0.0, 0.0, 0.0]
# [alpha, beta, gamma] = [1.0, 0.0, 0.0]
# [alpha, beta, gamma] = [1.0, pi-1e-10, 0.0]
[alpha, beta, gamma] = [1.0, pi+1e-5, 0.0]
# [alpha, beta, gamma] = [1.0, pi, 0.0]

Q = WignerD.Quaternion(alpha,beta,gamma)

Threshold = 4e-15
Worst = 0.0

print("[alpha, beta, gamma] = {}".format((alpha, beta, gamma)))
print("Q = {}".format(Q))

for l in range(9) :
    for mp in range(-l,l+1) :
        for m in range(-l,l+1) :
            D_E = WignerD.WignerDMatrix  (l,mp,m, alpha,beta,gamma)
            D_Q = WignerD.WignerDMatrix_Q(l,mp,m, Q)
            [Mag_E, Arg_E] = D_E.Value()
            [Mag_Q, Arg_Q] = D_Q.Value()
            MagDiff = abs(Mag_E-Mag_Q)
            if(MagDiff>Threshold) :
                print("Bad Mag: ", l, mp, m, Mag_E, Mag_Q, Mag_E-Mag_Q)
            Worst = max(Worst, MagDiff)
            ArgDiff = abs(math.fmod(abs(Arg_E-Arg_Q)+Threshold, 2*pi))-Threshold
            if(ArgDiff>Threshold and abs(Mag_E)>Threshold) :
                print("Bad Arg: ", l, mp, m, Arg_E,Arg_Q, abs(math.fmod(abs(Arg_E-Arg_Q)+Threshold, 2*pi)-Threshold))
            if(abs(Mag_E)>Threshold) :
                Worst = max(Worst, ArgDiff)

print("Worst difference = {}.".format(Worst))
if(Worst<Threshold) :
    print("\nNo differences greater than Threshold = {}!".format(Threshold))
