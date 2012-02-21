from matplotlib.pyplot import ion
from matplotlib.pyplot import ioff
from PyGW.plots import sphere_coordinates
from PyGW.plots import sphere_points
from PyGW.plots import data_on_sphere
from PyGW.plots import plot_sphere

def animate_sphere(W, OutputFileName, TimeSteps = 500, PhiSteps = 200, ThetaSteps = 100, Quantities=['real', 'imag', 'mag'], DPI=250) :
    
    vartheta, varphi = sphere_coordinates(ThetaSteps, PhiSteps)
    x,y,z = sphere_points(vartheta, varphi)
    Normalization = abs(data_on_sphere(W, W.Peak22TimeIndex(), vartheta, varphi)).max()
    print("Normalization = ", Normalization)
    
    ioff()
    TIndexStep = W.NTimes()/int(TimeSteps)
    for FrameIndex,t in enumerate(range(0, W.NTimes(), TIndexStep)) :
        print(str(t/TIndexStep) + ' of ' + str(TimeSteps))
        Figs = plot_sphere(W, t, Normalization, Quantities, vartheta=vartheta, varphi=varphi, x=x, y=y, z=z)
        for i in range(len(Figs)) :
            Figs[i].savefig(OutputFileName + '_' + Quantities[i].lower() + '_Frame%04d.png' % FrameIndex, dpi=DPI, transparent=True)
    ion()
