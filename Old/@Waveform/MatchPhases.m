% Wo = MatchPhases(W1, W2)
% Wo = MatchPhases(W1, W2, Time)
% 
%   This function returns a copy of the first input Waveform
%   object, with its phase shifted by integer multiples of
%   2*pi to match the second Waveform object.  The point of
%   comparison is chosen to be halfway through the maximal
%   common time grid, unless the Time is explicitly given.


function Wo = MatchPhases(varargin)

Wo = varargin{1};

if(nargin==3);
    Time = varargin{3};
else;
    MinTime = max( varargin{1}.Time(1), varargin{2}.Time(1) );
    MaxTime = min( varargin{1}.Time(end), varargin{2}.Time(end) );
    Time = (MaxTime + MinTime) / 2;
end;

Size1 = size(varargin{1}.Phi,2);
Size2 = size(varargin{2}.Phi,2);
if(Size1 ~= Size2);
    warning(['The number of data sets for the waveforms do not\n' ...
             'match.  You may be making irrelevant comparisons.'], ...
            '');
end;
Size = min(Size1, Size2);

Index = find(Wo.Time>Time, 1);
if(length(Index)==0);
    error('The Waveforms do not contain the desired Time.');
end;
InterpolatedPhase = ...
    interp1(varargin{2}.Time, varargin{2}.Phi, Time, 'cubic');%Wo.Time(Index));

for k = 1:Size;
    % This should do the job completely
    LastPhase = InterpolatedPhase(k);
    Wo.Phi(:,k) = Wo.Phi(:,k) + ...
        2*pi*round((LastPhase-Wo.Phi(Index,k))/(2*pi));
    Wo.PhaseOffset(k) = Wo.PhaseOffset(k) + ...
        2*pi*round((LastPhase-Wo.Phi(Index,k))/(2*pi));

%     figure;
%     plot(Wo.Time, Wo.Phi(:,k), ...
%          varargin{1}.Time, varargin{1}.Phi(:,k), ...
%          varargin{2}.Time, varargin{2}.Phi(:,k));
    
    % Check to make sure it's right
    while(LastPhase-Wo.Phi(Index,k) >  pi)
        Wo.Phi(:,k) = Wo.Phi(:,k) + 2*pi;
        Wo.PhaseOffset(k) = Wo.PhaseOffset(k) + 2*pi;
    end;
    
    % Keep checking
    while(LastPhase-Wo.Phi(Index,k) < -pi)
        Wo.Phi(:,k) = Wo.Phi(:,k) - 2*pi;
        Wo.PhaseOffset(k) = Wo.PhaseOffset(k) - 2*pi;
    end;
    
end;

if(nargin==3);
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = MatchPhases(%s, %s, %.16g);', ...
                  varargin{1}.Identifier, ...
                  varargin{2}.Identifier, ...
                  varargin{3})}];
else;
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = MatchPhases(this, %s);', ...
                  varargin{2}.Identifier)}];
end;


end  % function
