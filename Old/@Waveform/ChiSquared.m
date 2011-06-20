% Chi = ChiSquared(W1, W2, t0, t1)
% Chi = ChiSquared(W1, W2, t0, t1, Quantity)
% 
%   This function returns the chi-squared difference between
%   two Waveform objects, over the time interval [t0, t1].
%   "Quantity" is the quantity for comparison, which can be any of
%     'Phase', 'Amp', 'ReIm'
%   The default is 'Phase'.  The relevant data is interpolated
%   to a common time grid.  The result is then given by
%     Chi = sum(sum((Delta Quantity).^2)) / length(Quantity);
%   For 'ReIm', both the real and imaginary parts are summed.


function Chi = ChiSquared(varargin)

W1 = varargin{1};
W2 = varargin{2};
t0 = varargin{3};
t1 = varargin{4};
if(nargin>=5)
    Quantity = varargin{5};
else
    Quantity = 'Phase';
end;

%%% Find minimum and maximum times common to both data sets
%% Need equally spaced time steps for the integration below !!!
%Time = TimeIntersection(W1.Time(find(W1.Time>t0 & W1.Time<t1)), W2.Time(find(W2.Time>t0 & W2.Time<t1)));
MinTime = t0;
MaxTime = t1;
if(MinTime < W1.Time(1));   MinTime = W1.Time(1); end;
if(MaxTime > W1.Time(end)); MaxTime = W1.Time(end); end;
if(MinTime < W2.Time(1));   MinTime = W2.Time(1); end;
if(MaxTime > W2.Time(end)); MaxTime = W2.Time(end); end;
T1 = W1.Time(find(W1.Time>=MinTime & W1.Time<=MaxTime));
T2 = W2.Time(find(W2.Time>=MinTime & W2.Time<=MaxTime));
TimeStep = min( (T1(end)-T1(1))/length(T1), (T2(end)-T2(1))/length(T2) );
Time = (MinTime:TimeStep:MaxTime)';

switch lower(Quantity)
  case 'reim'
    if(size(W1.Amp,2)~=size(W2.Amp,2));
        error('This function is not yet implemented for ''ReIm''.');
    end;
    %%% Interpolate the data to a common Time grid
    ReDiff = interp1(W1.Time, Re(W1), Time) ...
             - interp1(W2.Time, Re(W2), Time);
    ImDiff = interp1(W1.Time, Im(W1), Time) ...
             - interp1(W2.Time, Im(W2), Time);
    %%% Evaluate the ChiSquared value
    if isempty(ReDiff)
        Chi = 1.e300;
    else
        Chi = sum( sum( ReDiff.^2 + ImDiff.^2 ) ) ...
              / (2*length(ImDiff));
    end
    
  case 'phase'
    %%% Take the smaller of the sizes of the input data
    if(size(W1.Amp,2)~=size(W2.Amp,2));
        warning(['There are different numbers of data sets for\n' ...
                 'the two Waveform objects.  I''m assuming\n' ...
                 'that they match. This may not be true.'], '');
    end;
    Size = min(size(W1.Amp,2),size(W2.Amp,2));
    %%% Interpolate the data to a common Time grid
    PhiDiff = interp1(W1.Time, W1.Phi(:,1:Size), Time) ...
              - interp1(W2.Time, W2.Phi(:,1:Size), Time);
    %%% Evaluate the ChiSquared value using the phases
    if isempty(PhiDiff)
        Chi = 1.e300;
    else
        Chi = sum(sum(PhiDiff.^2)) / length(PhiDiff);
    end
    
  case 'amp'
    %%% Take the smaller of the sizes of the input data
    if(size(W1.Amp,2)~=size(W2.Amp,2));
        warning(['There are different numbers of data sets for\n' ...
                 'the two Waveform objects.  I''m assuming\n' ...
                 'that they match. This may not be true.'], '');
    end;
    Size = min(size(W1.Amp,2), size(W2.Amp,2));
    %%% Interpolate the data to a common Time grid
    AmpDiff = interp1(W1.Time, W1.Amp(:,1:Size), Time) ...
              - interp1(W2.Time, W2.Amp(:,1:Size), Time);
    %%% Evaluate the ChiSquared value using the phases
    if isempty(AmpDiff)
        Chi = 1.e300;
    else
        Chi = sum(sum(AmpDiff.^2)) / length(AmpDiff);
    end
    
end; % switch

end
