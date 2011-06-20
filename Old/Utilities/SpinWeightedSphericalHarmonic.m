
% This function returns the value of a spin-weighted
% spherical, at a given theta and phi coordinate.  Input are:
%  1  -- spin weight
%  2  -- l-value
%  3  -- m-value
%  4  -- theta
%  5  -- phi
% [6] -- spin gauge (default=0)

function SWSH = SpinWeightedSphericalHarmonic(varargin)
s     = varargin{1};
l     = varargin{2};
m     = varargin{3};
theta = varargin{4};
phi   = varargin{5};
zeta  = 0;
if(nargin>=6);
    zeta = varargin{6};
end;

SWSH = 0;
if(abs(s) > l);
    error('abs(s=%.16g) should be less than or equal to l=%.16g.', ...
          s, l);
end;

if(abs(m) > l);
    error('abs(s=%.16g) should be less than or equal to l=%.16g.', ...
          m, l);
end;

for r = max(0, m-s):min(l-s, l+m);
    SWSH = SWSH + ((-1)^(l-r-s)) * binomial(l-s,r) * ...
           binomial(l+s,r+s-m) * exp(i*m*phi) * ...
           ((sin(theta/2))^((2*l)-(2*r)-s+m)) * ...
           ((cos(theta/2))^((2*r)+s-m));
end;

SWSH = SWSH * exp(i*s*zeta) * ((-1)^m) * ...
       sqrt((factorial(l+m)*factorial(l-m)*(2*l+1)) ...
            / (factorial(l+s)*factorial(l-s)*4*pi));

end


function b = binomial(n,k)
b = 0;
if(min(k)>=0 && max(k)<=min(n));
    b = factorial(n) / (factorial(k) * factorial(n-k));
end;
end

function Good = RemoveNaNs(Bad)
Good = Bad;
[I J] = find(isnan(Bad));
for k=1:size([I J],1);
    Good(I(k),J(k)) = 0;
end;
end
