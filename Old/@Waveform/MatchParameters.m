% [dTime dPhi] = MatchParameters(Quantity, W1, W2, t0, t1)
% [dTime dPhi] = MatchParameters('Omega', W1, W2, Omega, t0, t1)
% [dTime dPhi] = MatchParameters('Amp', W1, W2, Amp, t0, t1)
% [dTime dPhi] = MatchParameters('f', W1 ,W2, fFiducial)
% 
%   Given two input Waveform objects, this function returns
%   the time and phase offsets (and optionally other
%   quantities) needed to match the first input data to the
%   second data, in the requested quantity.
%   
%   Quantity is the quantity to be matched between the two
%   objects, and may be any of
%     'Phi', 'Peak', 'PrecisePeak'; 'Amp', 'Omega'
%   The default is 'Phi', which matches by minimizing the
%   ChiSquared difference in the given quantity.  'Omega'
%   attempts to find the given frequency somewhere in the time
%   interval [t0, t1], in the two data sets, and returns the
%   differences in time and phase.  'Amp' does the same, using
%   amplitude in place of frequency.  'Peak' find the peak
%   amplitude in the two data sets, using only the data points
%   present.  'PrecisePeak' attempts to interpolate to find
%   the maximum at some point between the given data points by
%   interpolation.  The 'f' matching method is intended for
%   frequency-domain waveforms.


function varargout = MatchParameters(varargin)

if(nargin==4 && isa(varargin{1},'Waveform'));
    switch nargout
      case 2
        [A B] = MatchParameters('Phase',varargin{1}, ...
                                varargin{2},varargin{3}, ...
                                varargin{4});
        varargout{1} = A;
        varargout{2} = B;
      case 3
        [A B C] = MatchParameters('Phase',varargin{1}, ...
                                  varargin{2},varargin{3}, ...
                                  varargin{4});
        varargout{1} = A;
        varargout{2} = B;
        varargout{3} = C;
      case 4
        [A B C D] = MatchParameters('Phase',varargin{1}, ...
                                    varargin{2},varargin{3}, ...
                                    varargin{4});
        varargout{1} = A;
        varargout{2} = B;
        varargout{3} = C;
        varargout{4} = D;
    end;
    return;
end;

switch lower(varargin{1})
  case {'phi', 'phase'}
    t0 = varargin{4};
    t1 = varargin{5};
    I = 1;
    if(length(varargin{2}.LM)>0);
        I = find(varargin{2}.LM(:,1)==2 & varargin{2}.LM(:,2)==2);
        if(length(I)==0);
            warning('Couldn''t find the 2,2 mode');
            I = 1;
        end;
    end;
    W2 = WaveformSubset(varargin{2}, I);
    W3 = WaveformSubset(varargin{3}, I);
    TempFunction = @(x) ...
        (ChiSquared(...
            DoPhaseOffset(Offset(W2,x), ...
                          W3,t0,t1), ...
            W3,t0,t1));
    varargout{1} = fminsearch(TempFunction, ...
                              varargin{3}.Time(end)- ...
                              varargin{2}.Time(end));
%     varargout{2} = FindPhaseOffset(Offset(varargin{2}, ...
%                                           varargout{1}), ...
%                                    varargin{3},t0,t1);
    if(size(varargin{2}.LM,1)>1);
        dPhi = FindPhaseOffset(Offset(W2, varargout{1}), ...
                               W3,t0,t1);
        varargout{2} = dPhi / (varargin{2}.LM(I,2));
    else;
        varargout{2} = FindPhaseOffset(Offset(varargin{2}, ...
                                              varargout{1}), ...
                                       varargin{3},t0,t1);
    end;
    if(nargout==4);
        ChiSq = ChiSquared(Offset('Phase', ...
                                  Offset(varargin{2}, ...
                                         varargout{1}), ...
                                  varargout{2}), ...
                           varargin{3},t0,t1);
        TempFunction2 = @(x) ((TempFunction(x)-2*ChiSq)^2);
        varargout{3} = abs(fminsearch(TempFunction2, ...
                                      varargout{2})-varargout{1});
        varargout{4} = varargout{3}*Omega(varargin{3},(t1+t0)/2);
    end;
    
    %     case 'amp'
    %         t0 = varargin{4};
    %         t1 = varargin{5};
    %         TempFunction = @(x) ...
    %             (ChiSquared(...
    %                 DoPhaseOffset(Offset(varargin{2}(1),x), ...
    %                               varargin{3}(1),t0,t1), ...
    %                 varargin{3}(1),t0,t1,'Amp'));
    %         varargout{1} = fminsearch(TempFunction, ...
    %                                   varargin{3}.Time(end)- ...
    %                                   varargin{2}.Time(end));
    %         varargout{2} = FindPhaseOffset(Offset(varargin{2}, ...
    %                                               varargout{1}), ...
    %                                        varargin{3},t0,t1);
    %         if nargout==4
    %             ChiSq = ChiSquared(Offset('Phase', ...
    %                                       Offset(varargin{2}, ...
    %                                              varargout{1}), ...
    %                                       varargout{2}), ...
    %                                varargin{3},t0,t1, 'Amp');
    %             TempFunction2 = @(x) ((TempFunction(x)-2*ChiSq)^2);
    %             varargout{3} = abs(fminsearch(TempFunction2, ...
    %                                           varargout{2})-varargout{1});
    %             varargout{4} = varargout{3}*Omega(varargin{3},(t1+t0)/2);
    %         end
    
  case 'omega'
    switch nargin
      case 6
        [Time1 Phase1 Amp1] = Find(varargin{2}, ...
                                   varargin{4}, ...
                                   'Omega', ...
                                   varargin{5},varargin{6});
        [Time2 Phase2 Amp2] = Find(varargin{3}, ...
                                   varargin{4}, ...
                                   'Omega', ...
                                   varargin{5},varargin{6});
      case 5
        [Time1 Phase1 Amp1] = Find(varargin{2}, ...
                                   varargin{4}, ...
                                   'Omega',varargin{5});
        [Time2 Phase2 Amp2] = Find(varargin{3}, ...
                                   varargin{4}, ...
                                   'Omega',varargin{5});
      case 4
        [Time1 Phase1 Amp1] = Find(varargin{2}, ...
                                   varargin{4},'Omega');
        [Time2 Phase2 Amp2] = Find(varargin{3}, ...
                                   varargin{4},'Omega');
      otherwise
        error(['MatchParameters_Omega: Wrong number of ' ...
               'arguments.']);
    end; % switch
    varargout{1} = Time2-Time1;
    varargout{2} = Phase2-Phase1;
    if(nargout==3);
        varargout{3} = Amp2-Amp1;
    end;
    
  case 'f'
    % This assumes that the Waveforms are frequency-domain objects
    Phi1TildePrime = interp1q(varargin{2}.Time, Omega(varargin{2}), varargin{4});
    Phi2TildePrime = interp1q(varargin{3}.Time, Omega(varargin{3}), varargin{4});
    varargout{1} = (Phi1TildePrime - Phi2TildePrime)/(2*pi);
    Phi1Tilde = interp1q(varargin{2}.Time, varargin{2}.Phi, varargin{4});
    Phi2Tilde = interp1q(varargin{3}.Time, varargin{3}.Phi, varargin{4});
    varargout{2} = Phi1Tilde - Phi2Tilde - 2*pi*varargin{4}*varargout{1};
    
  case {'amp','amplitude'}
    switch nargin
      case 6
        [Time1 Phase1 Amp1] = Find(varargin{2}, ...
                                   varargin{4}, ...
                                   'Amplitude', ...
                                   varargin{5},varargin{6});
        [Time2 Phase2 Amp2] = Find(varargin{3}, ...
                                   varargin{4}, ...
                                   'Amplitude', ...
                                   varargin{5},varargin{6});
      case 5
        [Time1 Phase1 Amp1] = Find(varargin{2}, ...
                                   varargin{4}, ...
                                   'Amplitude',varargin{5});
        [Time2 Phase2 Amp2] = Find(varargin{3}, ...
                                   varargin{4}, ...
                                   'Amplitude',varargin{5});
      case 4
        [Time1 Phase1 Amp1] = Find(varargin{2}, ...
                                   varargin{4},'Amplitude');
        [Time2 Phase2 Amp2] = Find(varargin{3}, ...
                                   varargin{4},'Amplitude');
      otherwise
        error(['MatchParameters_Amplitude: Wrong number ' ...
               'of arguments.']);
    end; % switch
    varargout{1} = Time2-Time1;
    varargout{2} = Phase2-Phase1;
    if(nargout==3);
        varargout{3} = Amp2-Amp1;
    end;
    
  case {'max','maxamp','maxamplitude','peak','peakpower'}
    [ValueA,IndexA] = max(varargin{2}.Amp(:,1));
    [ValueB,IndexB] = max(varargin{3}.Amp(:,1));
    varargout{1} = varargin{3}.Time(IndexB)-varargin{2}.Time(IndexA);
    varargout{2} = varargin{3}.Phi(IndexB)-varargin{2}.Phi(IndexA);
    if(nargout==3);
        varargout{3}=varargin{3}.Amp(IndexB)-varargin{2}.Amp(IndexA);
    end;
    
  case {'precisepeak'}
    warning('This function is buggy, and shouldn''t be trusted.');
    n = 10;
    Order = 2;
    [ValueA,IndexA] = max(varargin{2}.Amp(:,1));
    [ValueB,IndexB] = max(varargin{3}.Amp(:,1));
    pA = polyfit(varargin{2}.Time(IndexA-n:IndexA+n, 1), ...
                 varargin{2}.Amp( IndexA-n:IndexA+n, 1), Order);
    pB = polyfit(varargin{3}.Time(IndexB-n:IndexB+n, 1), ...
                 varargin{3}.Amp( IndexB-n:IndexB+n, 1), Order);
    TimeA = - pA(2)/(2*pA(1));
    TimeB = - pB(2)/(2*pB(1));
    varargout{1} = TimeB - TimeA;
    varargout{2} = 0;% ...
%         FindPhaseOffset(Offset(varargin{2}, varargout{1}), ...
%                         varargin{3}, -inf, inf);
    figure;
    PlotAmplitudes(varargin{2}, varargin{3});
    plot(TimeA, polyval(pA, TimeA), 'o');
    plot(TimeB, polyval(pB, TimeB), '+');
    
end;

end



%%% The following functions are local to this file


function W = DoPhaseOffset(W1, W2, t0, t1)
W = Offset('Phase',W1,FindPhaseOffset(W1,W2,t0,t1));
end % function DoPhaseOffset


function Phase = FindPhaseOffset(W1, W2, t0, t1)

% Find minimum and maximum times common to both data sets
MinTime = t0;
MaxTime = t1;
if(MinTime < W1.Time(1));   MinTime = W1.Time(1);   end;
if(MaxTime > W1.Time(end)); MaxTime = W1.Time(end); end;
if(MinTime < W2.Time(1));   MinTime = W2.Time(1);   end;
if(MaxTime > W2.Time(end)); MaxTime = W2.Time(end); end;

% Interpolate the data to a common Time grid
T1 = W1.Time(find(W1.Time>=MinTime & W1.Time<=MaxTime));
T2 = W2.Time(find(W2.Time>=MinTime & W2.Time<=MaxTime));
TimeStep = min( (T1(end)-T1(1))/length(T1), (T2(end)-T2(1))/length(T2) );
Time = (MinTime:TimeStep:MaxTime)';
PhiDiff = interp1(W1.Time,W1.Phi,Time,'cubic') ...
    - interp1(W2.Time,W2.Phi,Time,'cubic');

% The desired phase is then just the integral of the phase
% difference, divided by the time of integration.  Because of
% the interpolation we've just done, the integration can be
% done quickly and easily:
Phase = -sum(PhiDiff)/length(Time);
end % function FindPhaseOffset
