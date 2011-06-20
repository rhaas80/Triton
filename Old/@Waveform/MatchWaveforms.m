% Wo = MatchWaveforms(W1, W2, t0, t1)
% Wo = MatchWaveforms(Quantity, W1, W2, t0, t1)
% Wo = MatchWaveforms('Omega', W1, W2, Omega, t0, t1)
% Wo = MatchWaveforms('f', W1, W2, f)
% Wo = MatchWaveforms('Amp', W1, W2, Amp, t0, t1)
% Wo = MatchWaveforms('Abdul', W1, W2)
% 
%   This is basically a wrapper function to MatchParameters,
%   which returns a copy of the first Waveform object with the
%   necessary adjustments made to match the second.  Input
%   arguments are basically the same as for MatchParameters,
%   except that 'Wo = MatchWaveforms(W1, W2, t0, t1)' assumes
%   'Phi' matching.  Also, Abdul's matching method has been
%   implemented.  This version hasn't been thoroughly
%   debugged, however.

function varargout = MatchWaveforms(varargin)

if(~isa(varargin{1},'char') || ~strcmp(lower(varargin{1}),'abdul'));
    %%% Copy the data
    if(isa(varargin{1},'Waveform'));
        W = varargin{1};
        RI1 = varargin{1}.Identifier;
        RI2 = varargin{2}.Identifier;
    elseif(isa(varargin{2},'Waveform'));
        W = varargin{2};
        RI1 = varargin{2}.Identifier;
        RI2 = varargin{3}.Identifier;
    else;
        error('Do not understand input arguments');
    end;
    
    %%% Find the offset
    switch nargin
      case 3
        [TimeOffset PhaseOffset] = ...
            MatchParameters(varargin{1}, varargin{2}, varargin{3});
      case 4
        [TimeOffset PhaseOffset] = ...
            MatchParameters(varargin{1}, varargin{2}, varargin{3}, ...
                            varargin{4});
      case 5
        [TimeOffset PhaseOffset] = ...
            MatchParameters(varargin{1}, varargin{2}, varargin{3}, ...
                            varargin{4}, varargin{5});
      case 6
        [TimeOffset PhaseOffset] = ...
            MatchParameters(varargin{1}, varargin{2}, varargin{3}, ...
                            varargin{4}, varargin{5}, varargin{6});
      otherwise
        error('Wrong number of input arguments.');
    end;
    
    %%% Make a note of what we've done
    switch nargin
      case 3
        W.PostProcessing = ...
            [W.PostProcessing; ...
             {sprintf('this = MatchWaveforms(%s, %s, %s)', ...
                      varargin{1}, RI1, RI2)}];
      case 4
        if(strcmpi(varargin{1}, 'f'));
            W.PostProcessing = ...
                [W.PostProcessing; ...
                 {sprintf(['this = MatchWaveforms(''f'', %s, %s, %.16g, ' ...
                           '%.16g)'], RI1, RI2, varargin{4})}];
        else;
            W.PostProcessing = ...
                [W.PostProcessing; ...
                 {sprintf(['this = MatchWaveforms(%s, %s, %.16g, ' ...
                           '%.16g)'], RI1, RI2, varargin{3}, ...
                          varargin{4})}];
        end;
      case 5
        W.PostProcessing = ...
            [W.PostProcessing; ...
             {sprintf(['this = MatchWaveforms(%s, %s, %s, %.16g, ' ...
                       '%.16g)'], varargin{1}, RI1, RI2, ...
                      varargin{4}, varargin{5})}];
      case 6
        W.PostProcessing = ...
            [W.PostProcessing; ...
             {sprintf(['this = MatchWaveforms(%s, %s, %s, %.16g, ' ...
                       '%.16g, %.16g)'], varargin{1}, RI1, RI2, ...
                       varargin{4}, varargin{5}, varargin{6})}];
    end;
    
    %%% Do the offset
    if(strcmpi(varargin{1}, 'f'));
        varargout{1} = varargin{2};
        varargout{1}.Phi = varargin{2}.Phi ...
            - 2*pi*varargin{2}.Time*TimeOffset - PhaseOffset;
    else;
        varargout{1} = ...
            Offset('Phase', Offset('Time', W, TimeOffset), PhaseOffset);
    end;
    
else;
    % Match à la Abdul
    warning('This implementation may be buggy.');
    varargout{1} = varargin{2};
    WA = MakePhiStrictlyMonotonic(MatchPhases( ...
        varargin{2}, varargin{3}));
    WB = MakePhiStrictlyMonotonic(varargin{3});
    
    MinPhiA = min(WA.Phi(:,1));
    MaxPhiA = max(WA.Phi(:,1));
    MinPhiB = min(WB.Phi(:,1));
    MaxPhiB = max(WB.Phi(:,1));
    MinPhi = max(MinPhiA,MinPhiB);
    MaxPhi = min(MaxPhiA,MaxPhiB);
    
    LateIndex = find(WB.Phi(:,1)>MinPhi, 1, 'last');
    EarlyIndex = find(WB.Phi(:,1)<MaxPhi, 1, 'first');
    
    Times = interp1(WA.Phi(:,1), WA.Time, ...
                    WB.Phi(EarlyIndex:LateIndex, 1), 'cubic');
    varargout{1}.Time = WB.Time(EarlyIndex:LateIndex);
    if(numel(WA.TimeOffset)==1);
        varargout{1}.TimeOffset = ...
            WA.TimeOffset + WB.Time(EarlyIndex:LateIndex) - Times;
    else;
        varargout{1}.TimeOffset = ...
            interp1(WA.Time,WA.TimeOffset,Times, 'cubic') + ...
            WB.Time(EarlyIndex:LateIndex) - Times;
    end;
    varargout{1}.Phi = WB.Phi(EarlyIndex:LateIndex,:);
    Amp = zeros(size(Times,1),size(varargout{1}.Amp,2));
    for k = 1:size(varargout{1}.Amp,2);
        Amp(:,k) = interp1(WA.Time,varargout{1}.Amp(:,k),Times, ...
                           'cubic');
    end;
    varargout{1}.Amp = Amp;
    if(numel(WA.Radius)==1);
        varargout{1}.Radius = WA.Radius;
    else;
        varargout{1}.Radius = interp1(WA.Time,WA.Radius, ...
                                      Times, 'cubic');
    end;
    if(nargout==2);
        varargout{2} = WB;
    end;
    
    RI1 = varargin{2}.Identifier;
    RI2 = varargin{3}.Identifier;
    varargout{1}.PostProcessing = ...
            [varargout{1}.PostProcessing; ...
             {sprintf('this = MatchWaveforms(%s, %s, %s)', ...
                      varargin{1}, RI1, RI2)}];
    
end;

end





%%% This is a helper function for Abdul's offset method.  It
%%% works in a brute-force way: starting from the center of
%%% the time axis and working outwards, it ensures that the
%%% previous (following) Phi value is in the correct sense; if
%%% not, it simply moves the Phi value in the appropriate
%%% direction.  For consecutive values that would be the same,
%%% it just interpolates linearly to the next different Phi
%%% value.
function Wo = MakePhiStrictlyMonotonic(Wi)
Wo = Wi;
EarlyIndex  = round(length(Wo.Time)*3/8);
MiddleIndex = round(length(Wo.Time)*1/2);
LateIndex   = round(length(Wo.Time)*5/8);
Sign = sign(Wo.Phi(LateIndex)-Wo.Phi(EarlyIndex));
Phi = Wo.Phi;

% Start at the center, and work outwards, simply equating
% neighboring values of Phi if they're non-monotonic
for k = (MiddleIndex:size(Wo.Time,1));
    if(Sign*Phi(k) < Sign*Phi(k-1));
        Phi(k) = Phi(k-1);
    end;
end;
for k = (MiddleIndex-1:-1:1);
    if(Sign*Phi(k) > Sign*Phi(k+1));
        Phi(k) = Phi(k+1);
    end;
end;

% Now, make sure that everything is _strictly_ monotonic
k=2;
while(k<=size(Phi,1));
    Firstk = k;
    while(Phi(k)==Phi(k-1) && k<size(Phi,1))
        k = k+1;
    end;
    if(k>Firstk);
        if(k~=size(Phi,1));
            Phi((Firstk-1):k) = ...
                (Wo.Time((Firstk-1):k) - Wo.Time(Firstk-1)) ...
                *(Phi(k)-Phi(Firstk-1)) ...
                /(Wo.Time(k)-Wo.Time(Firstk-1)) ...
                + Phi(Firstk-1);
        else;
            Phi((Firstk-1):k) = ...
                (Wo.Time((Firstk-1):k) - Wo.Time(Firstk-1)) ...
                *(Phi(k)-Phi(Firstk-2)) ...
                /(Wo.Time(k)-Wo.Time(Firstk-1)) ...
                + Phi(Firstk-1);
        end;
    end;
    k = k+1;
end;

Wo.Phi = Phi;
end
