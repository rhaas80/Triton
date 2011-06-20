% WaveOut = InterpolateToMinimalGrid(WaveIn, AmpTolerance, PhiTolerance)
%   
%   The purpose of this function is to take a Waveform object,
%   and reduce the number of Time points to the minimum
%   required to maintain reasonable accuracy.  This accuracy
%   level is defined by the difference between the points
%   present in the initial data and the new (shorter) data
%   interpolated to those points, using naive linear
%   interpolation.  The method is naive, taking only the
%   first and last points in the Waveform, then including the
%   original point nearest to the center of any interval for
%   which the interpolation of either Amp or Phi to that
%   point is less accurate than *Tolerance, and repeating
%   until there are no more such points.  Note that the
%   AmpTolerance is a relative difference in amplitudes, while
%   the PhiTolerance is absolute.


%% The method here is to start with the absolute minimal grid
%% (the first and last input time steps), and increase
%% resolution until we can linearly interpolate to
%% intermediate points with sufficient accuracy.
function WaveOut = InterpolateToMinimalGrid(varargin)
    
    WaveIn = varargin{1};
    Times = zeros(size(WaveIn.Time));
    Times(1) = 1;
    Times(end) = 1;
    
    AmpTolerance = varargin{2};
    PhiTolerance = varargin{3};
    
    if(nargin>3);
        Merger = varargin{4};
        ApproxOmega = (-5/8) * (Merger-WaveIn.Time).^(-3/8);
%         LastReal = find(imag(ApproxOmega)==0, 1, 'last');
%         ApproxOmega(LastReal+1:end) = ApproxOmega(LastReal);
        ApproxOmegaDot = (96/5) * ((1/4)^(3/5)*1^(2/5))^(5/3) * abs(ApproxOmega).^(11/3);
        Dt = sqrt(abs(PhiTolerance./ApproxOmegaDot));
        Time = WaveIn.Time(1);
        Index = 1;
        while(Index < length(WaveIn.Time));
            dt = WaveIn.Time(Index+1) - WaveIn.Time(Index);
            Change = floor(Dt(Index)/dt);
            if(Change<1); Change = 1; end;
            Index = Index + Change;
            if(Index >= length(WaveIn.Time)); continue; end;
            Times(Index) = 1;
        end;
        figure;
        plot(WaveIn.Time(find(Times)), 'o');
    end;
        
        
        
        
        
%     if(nargin>3);
%         % Dt = varargin{4};
%         Dt = sqrt(abs(PhiTolerance./varargin{4}));
%         if(nargin>4);
%             Dt = min(Dt, sqrt(abs(AmpTolerance./varargin{5})));
%         end;
%         Time = WaveIn.Time(1);
%         Index = 1;
%         dt = (WaveIn.Time(end) - WaveIn.Time(1)) / (length(WaveIn.Time)-1);
%         while(Index < length(WaveIn.Time));
%             Change = floor(Dt(Index)/dt);
%             if(Change<1); Change = 1; end;
%             Index = Index + Change;
%             if(Index >= length(WaveIn.Time)); continue; end;
%             Times(Index) = 1;
%         end;
%         figure;
%         plot(WaveIn.Time(find(Times)), 'o');
%         LastIndex = 1;
%         tocs = 0;
%         while(Index<length(WaveIn.Time));
%             tic;
%             Index = find(WaveIn.Time<Time+Dt(Index), 1, 'last');
%             tocs = tocs + toc;
%             if(Index==LastIndex);
%                 Index = Index + 1;
%             end;
%             LastIndex = Index;
%             Time = WaveIn.Time(Index);
%             Times(Index) = 1;
%         end;
%         disp(sprintf('The finds took %.16g seconds.', tocs));
%     end;
    
    Problems = ProblemPoints(WaveIn, Times, AmpTolerance, PhiTolerance);
    % Loop through, checking if our Time grid is fine enough.
    % If not, make the Time grid finer by including the
    % midpoint in any region with problems.
    NTries = 1;
    while(~isempty(Problems));
        tic;
        Times(Problems) = 1;
        Problems = ProblemPoints(WaveIn, Times, AmpTolerance, PhiTolerance);
        NTries = NTries + 1;
        tocs = toc;
        disp(sprintf('Try %d took %g seconds.', NTries, tocs));
    end;
    disp(sprintf('Finished in %d tries.', NTries));
    
    % !!! Might want to loop through more finely here; checking
    % every point.
    
    WaveOut = Interpolate(WaveIn, WaveIn.Time(find(Times)));
    figure;
    plot(WaveOut.Time, 'o');
end

function Intervals = GetIntervals(Times)
    % This returns a 2xN array, where the left element is the
    % index of the beginning of an interval, and the right
    % element is the index of the end of the interval.
    Intervals = find(Times);
    Intervals = [Intervals(1:end-1)'; Intervals(2:end)']';
end


%% This function returns a vector of points where there isn't
%% enough resolution.
function Problems = ProblemPoints(WaveIn, Times, AmpTol, PhiTol)
    Intervals = GetIntervals(Times);
    Problems = [];
    for i = 1:size(Intervals,1);
        j0 = Intervals(i,1); % index of start of interval
        j1 = Intervals(i,2); % index of end of interval
        if(j1-j0==1);  % Don't try to refine if the beginning
            continue;  %   and end are consecutive.
        end;
        jm = ceil((j0+j1)/2); % index of middle of interval
        t0 = WaveIn.Time(j0);
        t1 = WaveIn.Time(j1);
        tm = WaveIn.Time(jm);
        A0 = WaveIn.Amp(j0);
        A1 = WaveIn.Amp(j1);
        Am = WaveIn.Amp(jm);
        AmpDiff = (Am - interp1q([t0 t1]', [A0 A1]', tm))/Am;
        if(~isnan(AmpDiff) && ~isinf(AmpDiff));
            if(abs(AmpDiff) > AmpTol);
                Problems(end+1) = jm;
                continue;
            end;
        end;
        P0 = WaveIn.Phi(j0);
        P1 = WaveIn.Phi(j1);
        Pm = WaveIn.Phi(jm);
        if(abs(Pm - interp1q([t0 t1]', [P0 P1]', tm)) > PhiTol);
            Problems(end+1) = jm;
            continue;
        end;
    end;
    %plot(Times,'o-');
end
