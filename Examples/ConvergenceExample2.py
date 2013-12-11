import PyGW_IS_FOR_OLD_DATA
import PyGW_IS_FOR_OLD_DATA.plot

Levs = ['Lev3', 'Lev4', 'Lev5']

Files = [Lev+'/rhOverM_Asymptotic_GeometricUnits.h5/OutermostExtraction.dir' for Lev in Levs]

for i in range(1,len(Files)) :
    WA = PyGW_IS_FOR_OLD_DATA.ReadFromNRAR(Files[i-1])
    WB = PyGW_IS_FOR_OLD_DATA.ReadFromNRAR(Files[i])
    Diff = WB/WA # Normalized difference; magnitudes = (WB-WA)/WA
    Diff.plot('LogMag', (2,2), label=Levs[i]+'-'+Levs[i-1]) # plot magnitude of difference of (2,2) mode on log scale

PyGW_IS_FOR_OLD_DATA.plot.mpl.pyplot.legend(loc='upper left')
PyGW_IS_FOR_OLD_DATA.plot.mpl.pyplot.savefig('Convergence.png')
