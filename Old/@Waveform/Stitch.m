% Wo = Stitch(W1, W2, t1, t2)
% Wo = Stitch(W1, W2, t1, t2, MinStep)
% 
%   This function takes two Waveform objects, and stitches
%   them together with a linear transition function between
%   times t1 and t2, acting on the amplitude and phase (rather
%   than the real and imaginary parts, say).  Before time t1,
%   the result is the same as W1, though possibly interpolated
%   to a finer time grid.  After time t2, the result is the
%   same as W2, possibly interpolated.  MinStep is the optional
%   minimum time step to be used in the stitched product.

function Wo = Stitch(varargin)
    
    W1 = varargin{1};
    W2 = MatchPhases(varargin{2}, W1);
    t1 = varargin{3};
    t2 = varargin{4};
    if(nargin>4 && ~isempty(varargin{5}));
        MinStep = varargin{5};
    else;
        MinStep = 0.0;
    end;
    
    %%% Find time parameters for new time data
    Time = TimeUnion(W1.Time, W2.Time, MinStep);
    
    %%% Interpolate the data to the common Time grid, if necessary
    if(length(Time)~=length(W1.Time) || sum(Time~=W1.Time)~=0);
        W1 = Interpolate(W1, Time, 0);
    end;
    if(length(Time)~=length(W2.Time) || sum(Time~=W2.Time)~=0);
        W2 = Interpolate(W2, Time, 0);
    end;
    
    %%% Construct a vector containing the transition factor
    %%% Here, we take the factor to be 1 for times less than
    %%% t1; 0 for times greater than t2; and linearly
    %%% interpolated between these two values.
    Transition = ones(size(Time));
    I1 = find(Time>t1, 1, 'first');
    I2 = find(Time<t2, 1, 'last');
    T1 = Time(I1);
    T2 = Time(I2);
    TDiff = T1-T2;
    if(TDiff==0); % Handle the t1==t2 case
        TDiff = 1;
    end;
    Transition(I1:I2) = (Time(I1:I2)-T2)/TDiff;
    Transition((I2+1):end) = 0.0;
    
    %%% Construct the data with the transition
    Wo = W1;
    for k=1:size(Wo.Amp,2);
        Wo.Amp(:,k) = Transition .* W1.Amp(:,k) ...
            + (1-Transition) .* W2.Amp(:,k);
        Wo.Phi(:,k) = Transition .* W1.Phi(:,k) ...
            + (1-Transition) .* W2.Phi(:,k);
    end;
    Wo.PhaseOffset = zeros(1,size(Wo.Amp,2));
    Wo.TimeOffset = 0.0;
    
    %%% Re-name the Identifier
    Wo.Identifier = sprintf('%sS%s', W1.Identifier, ...
                                  W2.Identifier);
    
    %%% Combine the post-processing cells
    if(nargin==6 && strcmp(varargin{6}, 'NoPostProcessingChange'));
        % Don't change Wo.PostProcessing
        % This is mostly so Filter can be less clunky
    else;
        Wo.PostProcessing = ...
            [Wo.PostProcessing; ...
             {sprintf(['this.Identifier = ''%s'';'], ...
                      Wo.Identifier)}; ...
             {sprintf('[begin-post-processing-%s]', ...
                      W1.Identifier)}; ...
             W1.PostProcessing; ...
             {sprintf('[end-post-processing-%s]', ...
                      W1.Identifier)}; ...
             {sprintf('[begin-post-processing-%s]', ...
                      W2.Identifier)}; ...
             W2.PostProcessing; ...
             {sprintf('[end-post-processing-%s]', ...
                      W2.Identifier)}; ...
             {sprintf('Stitch(%s, %s, %.16g, %.16g);', ...
                      W1.Identifier, W2.Identifier, ...
                      t1, t2)}];
    end;
    
end
