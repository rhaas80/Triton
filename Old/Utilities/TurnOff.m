% f = TurnOff(t, tOff)
% 
%   This function returns data intended to multiply a
%   function, to take it from one at the beginning of the set
%   of times "t" through time "tOff", and to zero thereafter.
%   The transition function has the form (1+cos)/2, going through
%   a half cycle between "tOff" and the final time.  This
%   function may be used for shorter transients in an FFT, for
%   example, by multiplying the data with a suitably slow turn
%   on.

function f = TurnOff(t, tOff)
    
    t0 = t(end);
    f = ones(size(t));
    I = find(t>tOff);
    f(I) = (1 - cos(pi*(t0-t(I))/(t0-tOff))) / 2;
    
end
