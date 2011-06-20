% Xo = MakeFinite(Xi)
% 
%   This function removes 'NaN' and 'inf' values from a matrix
%   by setting those values to zero.  This is particularly
%   useful in dealing with FFTs, because many calculations
%   with frequency involve dividing by the frequency, which
%   will occasionally introduce an 'inf' value.

function Xo = MakeFinite(Xi)
    
    Xo = Xi;
    Xo(find(isnan(Xo))) = 0.0;
    Xo(find(isinf(Xo))) = 0.0;
    
end
