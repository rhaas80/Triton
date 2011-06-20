% p = InnerProduct(s, h, PSD)
% p = InnerProduct(s, h, PSD, 'Normalize')
% 
%   This function returns the usual data-analysis inner
%   product between two Waveforms, relative to the given PSD.
%   Each Waveform may be in either the time domain or the
%   frequency domain.  If interpolation needs to happen, the
%   first input Waveform is chosen as the fiducial one, and
%   the second is interpolated to its Time or Frequency data.
%   Please note that interpolation is often less reliable in
%   the frequency domain due to larger and more rapid
%   variations in amplitude and phase.  The PSD should be a
%   function handle (e.g., @InitialLIGOPSD).
%   
%   By default, the input Waveforms are not normalized before
%   the inner product is returned.  However, if the option
%   'Normalize' is passed, the result will be normalized.

function p = InnerProduct(varargin)
    
    s = varargin{1};
    h = varargin{2};
    PSD = varargin{3};
    Normalize = false;
    if(nargin==4);
        if(strcmp(lower(varargin{4}), 'normalize'));
            Normalize = true;
        else;
            error('Don''t understand input argument 4.');
        end;
    end;
    
    if(length(s.LM)>2 || length(h.LM)>2 || ...
       length(s.ThetaPhi)>2 || length(h.ThetaPhi)>2);
        error(['\nThis function is not implemented for Waveform\n' ...
               'objects with multiple data sets.'], '');
    end;
    
    %%% Make sure that the Waveforms are evaluated at the same
    %%% Time or Frequency values.
    if(length(s.Time)~=length(h.Time));
        h = Interpolate(h, s);
    end;
    if(sum(s.Time~=h.Time)~=0);
        warning(['\nThe lengths of the Waveforms match, but the\n' ...
                 'Time data do not.  Continuing, on the\n' ...
                 'assumption that one is in the frequency\n' ...
                 'domain, and the other in the time domain.'], '');
    end;
    
    %%% Make sure the Waveforms are now in the frequency domain
    if(isempty(regexpi(s.Type, 'F{')));
        s = fft(s);
    end;
    if(isempty(regexpi(h.Type, 'F{')));
        h = fft(h);
    end;
    
    %%% Get the normalization
    Nyquist = floor(length(s.Time)/2);
    f = s.Time;
    s = Complex(s);
    h = Complex(h);
    PSD = PSD(abs([f(1:(Nyquist-1)); (f(Nyquist:end)-f(end))]));
    
    %%% Get the inner product
    p = InnerProductLocal(f, s, h, PSD);
    if(Normalize);
        if(p~=0); % otherwise, N will probably be NaN anyway
            p = p/sqrt(InnerProductLocal(f, s, s, PSD));
            p = p/sqrt(InnerProductLocal(f, h, h, PSD));
        end;
    end;
    
end




%%% This function is local to this file.  It assumes that the
%%% frequencies for the two signals are equal, and that all data
%%% is in the form of a vector.
function p = InnerProductLocal(f, s1, s2, PSD)
    p = 2 * real(trapz(f, s1.*conj(s2)./PSD)) ...
        / (min(diff(f))^2 * (length(f)^2));
end
