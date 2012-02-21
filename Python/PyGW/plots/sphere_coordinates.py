from numpy import linspace
from numpy import pi

def sphere_coordinates(ThetaSteps=100, PhiSteps=200) :
    """
    Returns a tuple of numpy arrays containing the appropriate
    vartheta and varphi coordinates on a sphere.
    """
    vartheta = linspace(0, pi, ThetaSteps)
    varphi = linspace(0, 2 * pi, PhiSteps)
    return (vartheta, varphi)
