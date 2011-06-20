% Wo = Extrapolate(Ws)
% Wo = Extrapolate(Ws, PolynomialOrder)
% Wo = Extrapolate(Ws, PolynomialOrder, OneOverR)
% [Wo, Wu, Wl] = Extrapolate(...)
% 
%   This function takes a cell array of Waveform objects, and
%   extrapolates them -- using a polynomial in 1/Radius of
%   order PolynomialOrder -- to a radius of 1/OneOverR.  The
%   default PolynomialOrder is 3, and the default value of
%   OneOverR is 0.0, which extrapolates to infinite radius.
%   
%   The function assumes that the input Waveforms are already
%   offset in the desired way.  It then finds the largest span
%   of time for which sufficient data exists, and interpolates
%   each Waveform to that time span.  If the original Waveform
%   did not contain data for that time, the data will be set
%   to zero, and its error set to 'inf', which will give it no
%   weight in the final extrapolation.
%   
%   When there are three output arguments, the second and
%   third outputs are Waveforms containing the upper and lower
%   (respectively) confidence intervals.  The meaning of these
%   intervals is subject to the meaning of the weights
%   assigned in this function, which is -- for now -- fairly
%   arbitrary.  More specifically, all waveforms are given
%   equal weight, as long as the data exists at the time in
%   question.

function varargout = Extrapolate(varargin)
    Clock = clock;
    
    
    %%% See 'help predint' for the description of these options.
    ConfidenceInterval = 0.95;
    IntervalOption = 'observation'; % 'functional';
    SimultaneousOption = 'on'; % 'off';
    
    
    %%% Process the input arguments
    Ws = varargin{1};
    PolynomialOrder = 3;
    ExtrapolateToOneOverR = 0.0;
    if(nargin>=2 && ~isempty(varargin{2}));
        PolynomialOrder = varargin{2};
        if(PolynomialOrder>9);
            error(['This is not yet supported for polynomial\n' ...
                   'orders greater than 9.  Matlab trivially\n' ...
                   'supports 9 and lower.  Higher values can\n' ...
                   'be added by changing the ''fittype'' line\n' ...
                   'in this file.'], '');
        end;
        if(PolynomialOrder+1 > length(Ws));
            error(['Not enough data sets for an order %d ' ...
                   'Polynomial.'], PolynomialOrder);
        end;
    end;
    if(nargin>=3 && ~isempty(varargin{3}));
        ExtrapolateToOneOverR = varargin{3};
    end;
    
    
    %%% Create the new Time grid
    TimeDiff =  10^200;
    MinTimes =  10^200 * ones(length(Ws), 1);
    MaxTimes = -10^200 * ones(length(Ws), 1);
    for k = 1:length(Ws);
        MinTimes(k) = Ws{k}.Time(1);
        MaxTimes(k) = Ws{k}.Time(end);
        TimeDiff = min(TimeDiff, ...
                       (Ws{k}.Time(end)-Ws{k}.Time(1))/(length(Ws{k}.Time)));
    end;
    MinTimes = sort(MinTimes, 1, 'ascend');
    MaxTimes = sort(MaxTimes, 1, 'descend');
    Time = (MinTimes(PolynomialOrder+1) : TimeDiff : ...
            MaxTimes(PolynomialOrder+1))';  % This assumes
                                            % *increasing* min
                                            % times from one
                                            % Waveform to the
                                            % next.
    
    
    %%% Construct the basic new Waveform
    Wo = Ws{1};
    Wo.Identifier = sprintf('%s:%.2d:%.2d:%f', date, Clock(4:6));
    if(ExtrapolateToOneOverR ~= 0);
        Wo.Radius = 1/ExtrapolateToOneOverR;
    else;
        Wo.Radius = 0;
    end;
    Wo.PhaseOffset = zeros(1,size(Wo.Phi, 2));
    Wo.TimeOffset = 0.0;
    % Everything else can stay the same, for now
    
    
    %%% Loop through the Waveforms, interpolating to the new
    %%%   Time and creating the error data
    AmpErrors = cell(length(Ws), 1);
    PhiErrors = cell(length(Ws), 1);
    for k = 1:length(Ws);
        %%% Check that the basic data structures agree
        if(~strcmp(Ws{k}.Type, Wo.Type));
            error(['Waveform %d has type %s, which\ndoes not ' ...
                   'match previous Waveforms.'], k, Ws{k}.Type);
        end;
        if(length(Ws{k}.LM)~=length(Wo.LM) || ...
           sum(sum(Ws{k}.LM~=Wo.LM))>0);
            error(['Waveform %d has LM data which does not ' ...
                   'match previous Waveforms.'], k);
        end;
        if(length(Ws{k}.ThetaPhi)~=length(Wo.ThetaPhi) || ...
           sum(sum(Ws{k}.ThetaPhi~=Wo.ThetaPhi))>0);
            error(['Waveform %d has ThetaPhi data which does not ' ...
                   'match previous Waveforms.'], k);
        end;
        
        %%% Interpolate, setting data outside the original
        %%%   Time range to inf.
        OriginalTi = Ws{k}.Time(1);
        OriginalTf = Ws{k}.Time(end);
        %        Ws{k} = Interpolate(Ws{k}, Time, 0);
        Ws{k} = Interpolate(Ws{k}, Time, inf);
        
        %%% Make up some basic error information
        Errors = 1e-10 * ones(size(Ws{k}.Amp, 1), ...
                              size(Ws{k}.Amp, 2));
%         Errors(find(Ws{k}.Time<OriginalTi), :) = inf;
%         Errors(find(Ws{k}.Time>OriginalTf), :) = inf;
        Errors(find(isinf(Ws{k}.Amp)), :) = inf;
        AmpErrors{k} = Errors;
        PhiErrors{k} = AmpErrors{k};
        % !!! This should be improved to account for
        % near-field effects, noise, etc.
        
    end; % loop over input Waveforms for interpolation
    
    %%% Make sure the output Waveforms are set up right
    Wo.Time = Ws{1}.Time;
    Wo.Amp = Ws{1}.Amp;
    Wo.Phi = Ws{1}.Phi;
    if(nargout == 3);
        WoUpper = Wo;
        WoLower = Wo;
    end;
    
    
    %%% Do the extrapolation to the desired radius
    FitType = ...
        fittype(sprintf('poly%d', PolynomialOrder));
    Size = size(Wo.Amp, 2);
    Amp = zeros(length(Ws), 1);
    AmpWeights = zeros(length(Ws), 1);
    Phi = zeros(length(Ws), 1);
    PhiWeights = zeros(length(Ws), 1);
    OneOverRadii = zeros(length(Ws), 1);
    %DataTime = 0;
    %FitTime = 0;
    %EvalTime = 0;
    %PredTime = 0;
    NumberOfFits = zeros(length(Time), 1);
    Times = inf*ones(Size,1);
    for l = 1:Size;
        Temp = clock;
        %%% !!!! Correct this to account for length(Ws)
        ExpectedTime = EstimateTime(Times, l, nargin, length(Time));
        disp(sprintf(['\nComponent %d of %d.  length(Time) = %d\n' ...
                      'Expected time for this component is about ' ...
                      '%d min %.2g sec.  Starting at %d:%.2d:%.2d.\n' ...
                      'Total remaining time is about %d min %.2g sec.'], ...
                     l, Size, length(Time), floor(ExpectedTime/60), ...
                     ExpectedTime-60*floor(ExpectedTime/60), ...
                     Temp(4:5), round(Temp(6)), ...
                     floor((Size-l)*ExpectedTime/60), ...
                     (Size-l)*ExpectedTime-60*floor((Size-l)*ExpectedTime/60)));
        tic
            for k = 1:length(Time);
                %%% Get the data for this time step and component
                %tic
                for m = 1:length(Ws);
                    Amp(m) = Ws{m}.Amp(k, l);
                    AmpWeights(m) = AmpErrors{m}(k, l).^-2;
                    Phi(m) = Ws{m}.Phi(k, l);
                    PhiWeights(m) = PhiErrors{m}(k, l).^-2;
                    if(length(Ws{m}.Radius)>1);
                        OneOverRadii(m) = 1 / (Ws{m}.Radius(k));
                    else;
                        OneOverRadii(m) = 1 / (Ws{m}.Radius);
                    end;
                end;
                OneOverRadii(find(isinf(OneOverRadii))) = 0.0;
                %DataTime = DataTime + toc;
                %%% Fit to the polynomial
                %tic
                OneOverRadii = OneOverRadii(find(PhiWeights));
                Amp = Amp(find(PhiWeights));
                Phi = Phi(find(PhiWeights));
%                 disp(sprintf(['Time = %05.0f; 1/R = %d %d; Amp = %d %d; Phi = ' ...
%                               '%d %d'], Time(k), size(OneOverRadii), size(Amp), size(Phi)));
                if(nargout==2);
                    NumberOfFits(k) = length(Phi);
                end;
                AmpFit = fit(OneOverRadii, Amp, ...
                             FitType, ...%'Weight', AmpWeights, ...
                             'Normalize', 'on');
                PhiFit = fit(OneOverRadii, Phi, ...
                             FitType, ...%'Weight', PhiWeights, ...
                             'Normalize', 'on');
                %FitTime = FitTime + toc;
                %%% Record the extrapolated data in Wo
                %tic
                Wo.Amp(k, l) = feval(AmpFit, ExtrapolateToOneOverR);
                Wo.Phi(k, l) = feval(PhiFit, ExtrapolateToOneOverR);
                %EvalTime = EvalTime + toc;
                %%% If necessary, record the prediction intervals
                if(nargout == 3);
                    %tic
                    AmpInt = predint(AmpFit, ExtrapolateToOneOverR, ...
                                     ConfidenceInterval, ...
                                     IntervalOption, SimultaneousOption);
                    PhiInt = predint(PhiFit, ExtrapolateToOneOverR, ...
                                     ConfidenceInterval, ...
                                     IntervalOption, SimultaneousOption);
                    WoUpper.Amp(k, l) = AmpInt(2);
                    WoLower.Amp(k, l) = AmpInt(1);
                    WoUpper.Phi(k, l) = PhiInt(2);
                    WoLower.Phi(k, l) = PhiInt(1);
                    %PredTime = PredTime + toc;
                end;
            end; % loop over Time steps
        Times(l) = toc;
        disp(sprintf('Elapsed time is %d min %.2g sec.', ...
                     floor(Times(l)/60), ...
                     Times(l)-60*floor(Times(l)/60)));
    end; % loop over components
    
    %disp(sprintf('DataTime = %.16g;', DataTime));
    %disp(sprintf('FitTime = %.16g;', FitTime));
    %disp(sprintf('EvalTime = %.16g;', EvalTime));
    %disp(sprintf('PredTime = %.16g;', PredTime));
    
    
    %%% Write the PostProcessing cell
    PostProcessing = cell(8,1);
    global EmailAddress;
    if(size(EmailAddress)==[0 0]);
        [s EmailAddress] = system('echo -n `whoami`@`hostname`');
    end;
    PostProcessing{1} = '[constructor]';
    PostProcessing{2} = sprintf('User = ''%s'';', EmailAddress);
    PostProcessing{3} = sprintf('InputPwd = ''%s'';', pwd);
    PostProcessing{4} = ...
        sprintf('InputDate = ''%s %.2d:%.2d:%f'';', ...
                date, Clock(4:6));
    PostProcessing{5} = sprintf('Identifier = ''%s'';', ...
                                Wo.Identifier);
    PostProcessing{6} = ...
        sprintf('this = Extrapolate(Ws, %d, %.16g);', ...
                PolynomialOrder, ExtrapolateToOneOverR);
    PostProcessing{7} = '';
    PostProcessing{8} = '[input-waveforms-short-metadata]';
    clear Clock;
    for k = 1:length(Ws);
        PostProcessing = ...
            [PostProcessing; ...
             {sprintf('[begin-input-waveform-%d]', k)}; ...
             GetShortMetadata(Ws{k}); ...
             {sprintf('[end-input-waveform-%d]', k)}; ...
            ];
    end;
    Wo.PostProcessing = [PostProcessing; {''}; {'[post-processing]'}];
    
    
    %%% Finalize the output
    varargout{1} = Wo;
    if(nargout==2);
        varargout{2} = NumberOfFits;
    end;
    if(nargout == 3);
        WoUpper.PostProcessing = ...
            [PostProcessing; ...
             {''}; {'[post-processing]'}; ...
             {sprintf(['%% this = %.16g%% upper confidence ', ...
                       'interval on the extrapolated waveform'], ...
                      ConfidenceInterval)}];
        WoLower.PostProcessing = ...
            [PostProcessing; ...
             {''}; {'[post-processing]'}; ...
             {sprintf(['%% this = %.16g%% lower confidence ', ...
                       'interval on the extrapolated waveform'], ...
                      ConfidenceInterval)}];
        varargout{2} = WoUpper;
        varargout{3} = WoLower;
    end;
    
end



%%% The following functions are local to this file



%%% This function just returns the [constructor] portion of
%%%   the PostProcessing cell for the Waveform.  This is so
%%%   that the extrapolated Waveform won't have a ridiculously
%%%   huge metadata file, but will have (hopefully) sufficient
%%%   information on where it came from.
function ShortMetadata = GetShortMetadata(Wi)
    for k=2:size(Wi.PostProcessing);
        if(~isempty(regexpi(Wi.PostProcessing{k,:}, '^\[')));
            break;
        end;
    end;
    ShortMetadata = Wi.PostProcessing(1:k-2,:);
    for k=length(Wi.PostProcessing):-1:1;
        if(~isempty(regexpi(Wi.PostProcessing{k,:}, ...
                            '^\[post-processing]')));
            break;
        end;
    end;
    ShortMetadata = [ShortMetadata; ...
                     Wi.PostProcessing(k:end,:)];
end



%%% This function estimates the amount of time needed for an
%%%   extrapolation of a given l,m.
function EstimatedTime = EstimateTime(ElapsedTimes, l, NArgin, LengthOfTime)
    WeightingFactor = ...
        exp(-8*(([1:(l-1) (l-length(ElapsedTimes)):0]) - l)...
               .^2/length(ElapsedTimes)^2)';
    WeightedTimes = ElapsedTimes;
    WeightedTimes(find(isinf(ElapsedTimes))) = .024*LengthOfTime;
    WeightedTimes = WeightingFactor.*WeightedTimes;
    EstimatedTime = sum(WeightedTimes)/sum(WeightingFactor);
    if(NArgin==3) EstimatedTime = 2*EstimatedTime; end;
end
