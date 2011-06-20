% f = TurnOn(t, tOn)
% 
%   This function returns data intended to multiply a
%   function, to take it from zero at the beginning of the set
%   of times "t", to one at time "tOn" and thereafter.  The
%   transition function has the form (1-cos)/2, going through
%   a half cycle between the initial time and "tOn".  This
%   function may be used for shorter transients in an FFT, for
%   example, by multiplying the data with a suitably slow turn
%   on.

function f = TurnOn(t, tOn)
    
    t0 = t(1);
    f = ones(size(t));
    I = find(t<tOn);
    f(I) = (1 - cos(pi*(t(I)-t0)/(tOn-t0))) / 2;
    
end
