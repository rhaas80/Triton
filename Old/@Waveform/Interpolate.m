% Wo = Interpolate(W1, Time)
% Wo = Interpolate(W1, W2)
% 
% Wo = Interpolate(..., Extrapolation)
% 
%   This function simply interpolates all data stored in the
%   input Waveform object to the times given by 'Time', or to
%   the same Time axis stored in W2.  Please note that
%   interpolation in the frequency domain should be approached
%   cautiously, because the data is often very dynamic.
%   
%   If the optional argument Extrapolation is present,
%   this will be passed to 'interp1' as the fifth 
%   argument.  It can either be the string 'extrap', if
%   extrapolation is desired, or a value to replace values
%   outside the original Time interval.  (See 'help interp1'
%   for more details.)  If this argument is not given, the
%   input Time vector will be reduced to a subset of W1.Time.

function Wo = Interpolate(varargin)

Wi = varargin{1};
Time = varargin{2};
if(nargin==3);
    ExVal = varargin{3};
else;
    ExVal = NaN;
end;


if(isa(Time, 'double'));
    
    Wo = Wi;
    
    %%% Make sure that Time is a subset of Wi.Time, if no
    %%%   ExVal is given.
    if(nargin~=3);
        if(Wi.Time(1)>Time(1));
            Time = Time(find(Time>Wi.Time(1),1,'first'):end);
        end;
        if(Wi.Time(end)<Time(end));
            Time = Time(1:find(Time<Wi.Time(end),1,'last'));
        end;
    end;
    
    %%% Rectify Time, if necessary
    if(size(Time,2)>1);
        Time = Time';
    end;
    
    %%% Do the interpolations
    Wo.Time = Time;
    Wo.Amp = interp1(Wi.Time, Wi.Amp, Time, 'pchip', ExVal);
    Wo.Phi = interp1(Wi.Time, Wi.Phi, Time, 'pchip', ExVal);
    if(length(Wi.Radius)>1);
        Wo.Radius = ...
            interp1(Wi.Time, Wi.Radius, Time, 'pchip', ExVal);
    end;
    if(length(Wi.TimeOffset)>1);
        Wo.TimeOffset = ...
            interp1(Wi.Time, Wi.TimeOffset, Time, 'pchip', ExVal);
    end;
    
    %%% Record it in the PostProcessing cell
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = Interpolate(this, [TimeArray], %.16g);', ...
                  ExVal)}];
    
elseif(isa(Time, 'Waveform'));
    
    %%% Check that the Waveforms are of the same type
    if(~isempty(regexpi(Wi.Type, 'F{')) && ...
       isempty(regexpi(Time.Type, 'F{')));
        error(['W1 seems to be in the frequency domain, but not ' ...
               'W2.']);
    end;
    if(isempty(regexpi(Wi.Type, 'F{')) && ...
       ~isempty(regexpi(Time.Type, 'F{')));
        error('W1 seems to be in the time domain, but not W2.');
    end;
    %%% Just send it back into this function, with the Time axis
    if(nargin==3);
        Wo = Interpolate(Wi, Time.Time, ExVal);
    else;
        Wo = Interpolate(Wi, Time.Time);
    end;
    %%% Record it in the PostProcessing cell
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = Interpolate(this, %s, %.16g);', ...
                  Wi.Identifier, Time.Identifier, ExVal)}];
    
else;
    
    error('Don''t understand second input argument of type %s.', ...
          class(Time));
    
end; % if(isa(Time, 'double'));

end % function Interpolate
