from mpl_toolkits.mplot3d import Axes3D
from matplotlib.pyplot import figure
from matplotlib.pyplot import draw
from PyGW.plots import sphere_coordinates
from PyGW.plots import sphere_points
from PyGW.plots import data_on_sphere
from PyGW.plots import colors_on_sphere

def plot_sphere(W, TimeIndex, Normalization=0, Quantities=['real', 'imag', 'mag'],
                         ThetaSteps=100, PhiSteps=200, vartheta=(), varphi=(), x=(), y=(), z=()) :
    if ((vartheta.size==0) or (varphi.size==0)) :
        vartheta, varphi = sphere_coordinates(ThetaSteps, PhiSteps)
    ComplexDataOnSphere = data_on_sphere(W, TimeIndex, vartheta, varphi)
    if (Normalization<=0.0) : Normalization = abs(ComplexDataOnSphere).max()
    Colors = colors_on_sphere(ComplexDataOnSphere, Normalization, Quantities)
    xyzshape = (len(vartheta),len(varphi))
    if ((x.size==0) or (y.size==0) or (z.size==0) or (x.shape!=xyzshape) or (y.shape!=xyzshape) or (z.shape!=xyzshape)) :
        x,y,z = sphere_points(vartheta, varphi)
    Figs = []
    for i,quantity in enumerate(Quantities) :
        fig = figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.set_xticks(())
        ax.set_yticks(())
        ax.set_zticks(())
        fig.tight_layout(pad=0.1)
        Surface = ax.plot_surface(x, y, z,  rstride=1, cstride=1, linewidth=0, antialiased=False, facecolors=Colors[i])
        TimeText = ax.text2D(0.05, 0.92, r'$t = '+str(round(W.T(TimeIndex),1))+'$\n'+quantity, transform=ax.transAxes)
        fig.draw()
        Figs.append(fig)
    return Figs
