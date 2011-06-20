% Wo = Pad(Wi, 'End', EndFactor);
% Wo = Pad(Wi, 'Begin', BeginFactor);
% 
%   This function returns a copy of the input Waveform, padded
%   with zeros.  The input factor is used to extend the Time
%   data by that factor.  'Begin' and 'End' choose which part
%   of the Waveform will be extended.

function Wo = Pad(varargin)
    Wo = varargin{1};
    EndFactor = 1;
    BeginFactor = 1;
    PostProcessing = 'this = Pad(this';
    for k=2:nargin;
        if(isa(varargin{k}, 'char'));
            switch lower(varargin{k});
              case 'end'
                EndFactor = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''End'', %.16g', EndFactor)];
              case {'begin', 'beginning'}
                BeginFactor = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''Begin'', %.16g', BeginFactor)];
              otherwise
                error('Don''t understand option %s', varargin{k});
            end;
        else;
            % ignore it
        end;
    end;
    
    Time = Wo.Time;
    if(EndFactor ~= 1);
        Time = interp1(1:length(Time), Time, ...
                       1:EndFactor*length(Time), 'pchip', 'extrap');
    end;
    if(BeginFactor ~= 1);
        Time = interp1(1:length(Time), Time, ...
                       1:BeginFactor*length(Time), 'pchip', 'extrap');
    end;
    if(EndFactor ~= 1 || BeginFactor ~= 1);
        Wo = Interpolate(Wo, Time, 0);
    end;
    
    Wo.PostProcessing = [Wo.PostProcessing; [PostProcessing ');']];
end
