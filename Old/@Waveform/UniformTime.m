% Wout = UniformTime(Win)
% Wout = UniformTime(Win, TimeStep)
%   
%   This function returns a copy of the input Waveform with a
%   uniform time step, of size equal to the average time step
%   of the input waveform.  If the optional second parameter
%   is passed, it is used as the time step instead.

function W = UniformTime(varargin)
    W = varargin{1};
    if(nargin==1);
        TimeStep = abs((W.Time(end)-W.Time(1))/length(W.Time));
    else;
        TimeStep = varargin{2};
    end;
    W = Interpolate(W, min(W.Time) : TimeStep : max(W.Time));
end
