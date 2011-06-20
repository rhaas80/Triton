% Wo = ifft(Wi)
% 
%   This function returns a copy of the input Waveform, with
%   the Amp and Phi data replaced by Amp and Phi data for its
%   inverse FFT.  The Waveform's type is altered appropriately.
%   
%   Note that the data returned is the discrete ifft, in
%   Matlab's normalization.  The set of times returned is
%   j/(N*Df) with j running from 0 to N-1.
%   
%   
%   See also Waveform/fft.

function Wo = ifft(Wi)
    
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
    
    
    %%% Do the ifft
    if(isempty(regexpi(Wo.Type, 'F{')));
        warning(['This Waveform appears to be a time-domain \n' ...
                 'object.  If so, this should probably be \n' ...
                 'processed by the function Waveform/fft.\n']);
%         %%% This is a frequency-domain Waveform
%         [Wo.Amp Wo.Phi] = SplitToAmpPhi(ifft(Complex(Wo)));
%         Wo.Time = linspace(0, 1/min(diff(Wo.Time)), length(Wo.Time))';
%         Wo.Type = regexprep(Wo.Type, 'F{(.*)}', '$1', 'preservecase');
%         Wo.PostProcessing = ...
%             [Wo.PostProcessing; {'this = ifft(Wi);'}; ...
%              {sprintf('this.Type = ''%s'';', Wo.Type)}];
    end;
    %%% Interpolate to uniform frequency grid, if necessary
    Freq = Wo.Time;
    MinFreqStep = min(diff(Freq));
    MaxFreqStep = max(diff(Freq));
    if(MinFreqStep~=MaxFreqStep);
        Freq = (Freq(1):MinFreqStep:Freq(end))';
        Wo = Interpolate(Wo, Freq);
    end;
    %%% Do the work
    [Wo.Amp Wo.Phi] = SplitToAmpPhi(ifft(Complex(Wo)));
    Wo.Time = ((0:(length(Freq)-1))/(length(Freq)*MinFreqStep))';
    Wo.Type = regexprep(Wo.Type, 'F{(.*)}', '$1', 'preservecase');
    %%% Record in PostProcessing
    Wo.PostProcessing = ...
        [Wo.PostProcessing; {'this = ifft(Wi);'}; ...
         {['this.Type = ''' Wo.Type ''';']}];
    
    
end % function
