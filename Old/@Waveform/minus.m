% Wo = W1-W2
%
%  This function simply subtracts two Waveform objects, by
%  subtracting the amplitude and phase separately.  The data
%  are interpolated to the largest, finest common time
%  grid.

function Wo = minus(W1, W2)
    Wo = MatchPhases(W1, W2);
    
    % Take the smaller of the sizes of the input data
    Size = min(size(Wo.Amp,2),size(W2.Amp,2));
    
%     % Find minimum and maximum times common to both data sets
%     MinTime = -10^200;
%     MaxTime =  10^200;
%     if(MinTime < Wo.Time(1));   MinTime = Wo.Time(1);   end;
%     if(MaxTime > Wo.Time(end)); MaxTime = Wo.Time(end); end;
%     if(MinTime < W2.Time(1));   MinTime = W2.Time(1);   end;
%     if(MaxTime > W2.Time(end)); MaxTime = W2.Time(end); end;
    
    % Interpolate the data to a common Time grid
    if( length(Wo.Time)~=length(W2.Time) || sum(Wo.Time~=W2.Time)>0 );
        %TimeStep = min(min(diff(Wo.Time)),min(diff(W2.Time)));
        %Time = (MinTime:TimeStep:MaxTime)';
        Time = TimeIntersection(W1.Time, W2.Time);
        AmpI1 = interp1(Wo.Time,Wo.Amp(:,1:Size),Time,'cubic');
        PhiI1 = interp1(Wo.Time,Wo.Phi(:,1:Size),Time,'cubic');
        AmpI2 = interp1(W2.Time,W2.Amp(:,1:Size),Time,'cubic');
        PhiI2 = interp1(W2.Time,W2.Phi(:,1:Size),Time,'cubic');
    else;
        Time = Wo.Time;
        AmpI1 = Wo.Amp(:,1:Size);
        PhiI1 = Wo.Phi(:,1:Size);
        AmpI2 = W2.Amp(:,1:Size);
        PhiI2 = W2.Phi(:,1:Size);
    end;
    
    % Update the Waveform data
    Wo.Time = Time;
    Wo.Amp = AmpI1 - AmpI2;
    Wo.Phi = PhiI1 - PhiI2;
    Wo.TimeOffset = 0;
    Wo.PhaseOffset = zeros(1,size(Wo.Amp,2));
    if(ndims(Wo.Radius)==ndims(W2.Radius) && ...
       sum(Wo.Radius~=W2.Radius)==0);
        Wo.Radius = W2.Radius;
    else;
        Wo.Radius = -1.0;
    end;
    Wo.Identifier = sprintf('%s-%s',W1.Identifier, ...
                                  W2.Identifier);
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = minus(%s, %s);', W1.Identifier, ...
                  W2.Identifier)}; ...
         {sprintf('this.Identifier = ''%s'';', Wo.Identifier)}];
    
end
