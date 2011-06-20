% Wo = Trim(Wi, 'DropAfter', Time, ...)
% Wo = Trim(Wi, 'KeepBefore', Time, ...)
% 
% Wo = Trim(Wi, 'DropBefore', Time, ...)
% Wo = Trim(Wi, 'KeepAfter', Time, ...)
% 
% Wo = Trim(Wi, 'ZeroBefore', Time, ...)
% Wo = Trim(Wi, 'ZeroAfter', Time, ...)
% Wo = Trim(Wi, 'ZeroUpToNyquist', Time, ...)
% 
% Wo = Trim(Wi, 'Prune', Step, ...)
% Wo = Trim(Wi, 'Refine', Factor, ...)
% 
%   This function returns a copy of the input Waveform
%   object, trimmed in the requested way.  "DropAfter" and
%   "KeepBefore" are synonyms, which drop all data after the
%   requested time, or keep all data before that time.
%   Similarly, "DropBefore" and "KeepAfter" are synonyms that
%   do the opposite.  "ZeroBefore" and "ZeroAfter" set the
%   amplitude of the input Waveform before or after the given
%   time to zero.  "ZeroUpToNyquist" sets the amplitude of the
%   input Waveform after the given frequency to zero, taking
%   into account the reflection about the Nyquist
%   frequency. "Prune" removes time points, keeping only 
%   every Step data point.  "Refine" does the opposite of
%   "Prune", making the time grid Factor times finer (thus,
%   "Refine" does not actually reduce the amount of data).
%   
%   Note that any of these arguments may be combined.  If the
%   same (or a synonymous) argument is given more than once,
%   the last one will overwrite earlier ones.

function Wo = Trim(varargin)
    
    %%% Set up defaults
    PostProcessing = 'this = Trim(this';
    DropAfter = 10^200;
    DropBefore = -10^200;
    ZeroAfter = 10^200;
    ZeroBefore = -10^200;
    ZeroUpToNyquist = -10^200;
    Step = 1;
    Factor = 1;
    
    %%% Read input arguments
    Wo = varargin{1};
    for k=2:nargin;
        if(isa(varargin{k}, 'char'));
            switch lower(varargin{k})
              case {'dropafter', 'keepbefore'}
                DropAfter = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, DropAfter)];
                CheckType(Wo.Type, 'DropAfter');
              case {'dropbefore', 'keepafter'}
                DropBefore = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, DropBefore)];
                CheckType(Wo.Type, 'DropBefore');
              case 'zeroafter'
                ZeroAfter = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, ZeroAfter)];
              case 'zerobefore'
                ZeroBefore = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, ZeroBefore)];
              case 'zerouptonyquist'
                ZeroUpToNyquist = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, ZeroUpToNyquist)];
              case 'prune'
                Step = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, Step)];
                CheckType(Wo.Type, 'Prune');
              case 'refine'
                Factor = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ...
                     sprintf(', ''%s'', %.16g', ...
                             varargin{k}, Factor)];
                CheckType(Wo.Type, 'Refine');
              otherwise
                error('Don''t understand input ''%s''.', varargin{k});
            end;
        else;
            % ignore
        end;
    end;
    
    %%% Create the new Time grid
    Time = Wo.Time;
    Time = Time(find(Time<DropAfter));
    Time = Time(find(Time>DropBefore));
    if(Step~=1);
        Time = Time(1:Step:end);
    end;
    if(Factor~=1);
        Time = (Time(1) : min(diff(Time))/Factor : Time(end))';
    end;
    
    %%% If necessary, interpolate to the new grid, or zero data
    if(Time(1)>Wo.Time(1) || Time(end)<Wo.Time(end) || ...
       Step~=1 || Factor~=1);
        Wo = Interpolate(Wo, Time);
    end;
    if(ZeroAfter~=10^200 || ZeroBefore~=-10^200);
        Wo.Amp(find(Time>ZeroAfter), :) = 0.0;
        Wo.Amp(find(Time<ZeroBefore), :) = 0.0;
    end;
    if(ZeroUpToNyquist~=-10^200);
        %Indices = find(Time>ZeroUpToNyquist);
        %Indices = find(Time(Indices)<ZeroUpToNyquist);
        Wo.Amp(find(Time>ZeroUpToNyquist & ...
                    Time<(Time(end)-ZeroUpToNyquist)), :) = 0.0;
    end;
    
    %%% Finish up the PostProcessing
    Wo.PostProcessing = [Wo.PostProcessing; {[PostProcessing ');']}];
    
end % function


function CheckType(Type, Argument)
    if(~isempty(regexpi(Type, 'F{')));
        warning(['\nYou are Trimming a Waveform of Type %s,\n' ...
                 'which is in the frequency domain, with %s.\n' ...
                 'This may conflict with the implicit \n' ...
                 'normalization of Fourier transforms, which\n' ...
                 'involves the length of the data.'], Type, Argument);
    end;
end





function T = RefineGrid(W, Times)
    
end


function Wo = MinimalGrid(Wi, AmpTol, PhiTol)
    Times = zeros(size(WaveIn.Time));
    Times(1) = 1;
    Times(end) = 1;
    RefineGrid(W, Times);
    Wo = Interpolate(Wi, Wi.Time(find(Times)));
end
