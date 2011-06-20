% Wo = SPA(Wi)
%   
%   This function takes a time-domain Waveform and returns its
%   stationary-phase approximation.

function Wo = SPA(Wi)
    
    Wo = Wi;
    
    %%% Make sure there are no NaNs or Infs in the input
    if(sum(sum(isnan(Wo.Amp)))~=0 || sum(sum(isinf(Wo.Amp)))~=0);
        Wo.Amp(find(isnan(Wo.Amp))) = 0;
        Wo.Amp(find(isinf(Wo.Amp))) = 0;
        warning('Found NaN or Inf elements in Amp.  Setting to 0.');
    end;
    if(sum(sum(isnan(Wo.Phi)))~=0 || sum(sum(isinf(Wo.Phi)))~=0);
        Wo.Phi(find(isnan(Wo.Phi))) = 0;
        Wo.Phi(find(isinf(Wo.Phi))) = 0;
        warning('Found NaN or Inf elements in Phi.  Setting to 0.');
    end;
    
    %%% Check that this is a time-domain Waveform
    if(~isempty(regexpi(Wo.Type, 'F{')));
        warning(['This Waveform appears to be a frequency-domain \n' ...
                 'object.  If so, this should probably be \n' ...
                 'processed by the function Waveform/ifft.\n']);
    end;
    
    
    %%% Interpolate to uniform time grid, if necessary
    Time = Wo.Time;
    MinTimeStep = min(diff(Time));
    MaxTimeStep = max(diff(Time));
    if(MinTimeStep~=MaxTimeStep);
        Time = (Time(1):MaxTimeStep:Time(end))';
        Wo = Interpolate(Wo, Time);
    end;
    %%% Do the work
    PhiDot = abs(Omega(Wo))/2;
    F = PhiDot/pi;
    Phi = Wo.Phi/2;
    Wo.Time = ((0:(length(Time)-1))/(length(Time)*MinTimeStep))';
    phi = interp1(F, Phi, Wo.Time, 'linear', 0);
    TwoPiFT = interp1(F, Time, Wo.Time, 'linear', 0);
    Wo.Phi = -(TwoPiFT - 2*phi - pi/4);
    A = interp1(F, Wo.Amp, Wo.Time, 'linear', 0);
    FDot = interp1(F, DifferentiateDataSet(Time, F), Wo.Time, ...
                   'linear', 1);
    Wo.Amp = (0.5/MinTimeStep) * 0.5 * A ./ sqrt(FDot);
    Wo.Type = ['F{' Wo.Type '}'];
    disp(MinTimeStep);
    %%% If requested, interpolate to a LIGO-ish frequency scale
    if(0); %LIGO);
        error('This is cruft!!!');
        Command = sprintf('fft(Wi, ''%s'', ''LIGO'');', Part);
        warning(['Interpolation to LIGO frequencies may not be ' ...
                 'correct yet.']);
        LIGOf = ( 0 : 4096/length(Wo.Time) : 4096-1 )';
        Wo = Interpolate(Wo, LIGOf, 0);
    else;
        Command = 'this = SPA(this);';
    end;
    %%% Record in PostProcessing
    Wo.PostProcessing = ...
        [Wo.PostProcessing; {Command}; ...
         {['this.Type = ''' Wo.Type ''';']}];
    
end
