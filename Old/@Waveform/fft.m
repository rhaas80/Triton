% Wo = fft(Wi)
% 
% Wo = fft(..., 'Re')
% Wo = fft(..., 'Im')
% Wo = fft(..., 'Complex')
% 
% Wo = fft(..., 'LIGO')
% 
%   This function returns a copy of the input Waveform, with
%   the Amp and Phi data replaced by Amp and Phi data for its
%   FFT.  The Waveform's type is altered appropriately.
%   Optionally, the part to transform may be chosen as one of
%     'Re', 'Im', 'Complex'
%   The default is 'Re'.  If the option 'LIGO' is included,
%   and the input Waveform is in the time domain, the set of
%   frequencies of the output Waveform is the one Initial LIGO
%   would see, assuming that the units of Time are seconds.
%   
%   Note that the data returned is the discrete fft, in
%   Matlab's normalization.  That is, it must be multiplied by
%   the time step [Dt = 1/(N*Df)] to obtain the more usual
%   continuous fft, which should be roughly invariant with
%   respect to discretization.
%   
%   The set of frequencies returned is j/(N*Dt) with j running
%   from 0 to N-1.
%   
%   
%   See also Waveform/ifft.

function Wo = fft(varargin)
    
    %%% Process the input arguments
    Wo = varargin{1};
    Part = 'Re';
    LIGO = false;
    for k = 2:nargin;
        switch lower(varargin{k})
          case 're'
            Part = 'Re';
          case 'im'
            Part = 'Im';
          case 'complex'
            Part = 'Complex';
          case 'ligo'
            LIGO = true;
          otherwise
            error('Don''t understand option %s.', varargin{k});
        end;
    end;
    
    
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
    
    
    %%% Do the ifft or fft
    if(~isempty(regexpi(Wo.Type, 'F{')));
        warning(['This Waveform appears to be a frequency-domain \n' ...
                 'object.  If so, this should probably be \n' ...
                 'processed by the function Waveform/ifft.\n']);
%         %%% This is a frequency-domain Waveform
%         [Wo.Amp Wo.Phi] = SplitToAmpPhi(ifft(Complex(Wo)));
%         Wo.Time = linspace(0, 1/min(diff(Wo.Time)), length(Wo.Time))';
%         Wo.Type = regexprep(Wo.Type, 'F{(.*)}', '$1', 'preservecase');
%         Wo.PostProcessing = ...
%             [Wo.PostProcessing; {'this = ifft(Wi);'}; ...
%              {sprintf('this.Type = ''%s'';', Wo.Type)}];
    end;
    %%% Interpolate to uniform time grid, if necessary
    Time = Wo.Time;
    MinTimeStep = min(diff(Time));
    MaxTimeStep = max(diff(Time));
    if(MinTimeStep~=MaxTimeStep);
        Time = (Time(1):MinTimeStep:Time(end))';
        Wo = Interpolate(Wo, Time);
    end;
    %%% Get the part of the data to be FFTed
    switch lower(Part)
      case 're'
        Data = Re(Wo);
      case 'im'
        Data = Im(Wo);
      case 'complex'
        Data = Complex(Wo);
    end;
    %%% Do the work
    [Wo.Amp Wo.Phi] = SplitToAmpPhi(fft(Data));
    Wo.Time = ((0:(length(Time)-1))/(length(Time)*MinTimeStep))';
    Wo.Type = ['F{' Wo.Type '}'];
    %%% If requested, interpolate to a LIGO-ish frequency scale
    if(LIGO);
        Command = sprintf('fft(Wi, ''%s'', ''LIGO'');', Part);
        warning(['Interpolation to LIGO frequencies may not be ' ...
                 'correct yet.']);
        LIGOf = ( 0 : 4096/length(Wo.Time) : 4096-1 )';
        Wo = Interpolate(Wo, LIGOf, 0);
    else;
        Command = sprintf('fft(Wi, ''%s'');', Part);
    end;
    %%% Record in PostProcessing
    Wo.PostProcessing = ...
        [Wo.PostProcessing; {Command}; ...
         {['this.Type = ''' Wo.Type ''';']}];
    
    
end % function
