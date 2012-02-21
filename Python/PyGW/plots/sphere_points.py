from numpy import outer
from numpy import sin
from numpy import cos
from numpy import ones

def sphere_points(vartheta, varphi, Radius=1) :
    """
    Simply returns the (x,y,z) coordinates of the points given by
    spherical coordinates (vartheta, varphi).
    """
    x = Radius*outer(sin(vartheta), cos(varphi))
    y = Radius*outer(sin(vartheta), sin(varphi))
    z = Radius*outer(cos(vartheta), ones(size(varphi)))
    return (x,y,z)
