% O = Overlap(s, h, PSD)
% [O Dt Dphi] = Overlap(s, h, PSD)
%   
%   This function returns the normalized inner product of
%   Waveforms s and h relative to the power spectral density
%   PSD, maximized over arrival time and phase.  The
%   function's arguments are treated the same as those to the
%   function InnerProduct.  If three return values are
%   requested, the second and third are the time and phase
%   offsets to be applied to the second Waveform to obtain the
%   maximal Overlap.  In the frequency domain, this means
%     h -> h .* exp(i*2*pi*Dt*f + i*Dphi) .
%   
%   See also Waveform/InnerProduct.

function varargout = Overlap(s, h, PSD)
    
    if(length(s.LM)>2 || length(h.LM)>2 || ...
       length(s.ThetaPhi)>2 || length(h.ThetaPhi)>2);
        error(['\nThis function is not implemented for Waveform\n' ...
               'objects with multiple data sets.'], '');
    end;
    
    %%% Make sure that the Waveforms are evaluated at the same
    %%% Time or Frequency values.
    if(length(s.Time)~=length(h.Time));
        h = Interpolate(h, s, 0);
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
    f = s.Time;
    s = Complex(s);
    h = Complex(h);
    N = length(f);
    Df = min(diff(f));
    fj = Df * [0:floor(N/2) -floor((N-1)/2):-1];
    PSD = PSD(abs(f));
    Normalizer = 1/sqrt(InnerProductLocal(f, s, s, PSD));
    Normalizer = Normalizer/sqrt(InnerProductLocal(f, h, h, PSD));
    
    %figure; loglog(f, PSD, f, abs(s), f, abs(h));
    
    %%% Get the overlap
    %% Note that both expressions below are correct, because
    %% of the definition of "ifft".
    O = 2 * ifft(Normalizer*s.*conj(h)./PSD) / (N * Df);
    %O = 2 * fft(Normalizer*s.*conj(h)./PSD) / (N^2 * Df);
    if(nargout==3);
        [Max Index] = max(abs(O));
        varargout{1} = Max;
        varargout{2} = (Index-1) / (N*Df); % Dt
        varargout{3} = angle(O(Index)); % Dphi;
    else;
        varargout{1} = max(abs(O)); % Overlap;
    end;
end




%%% This function is local to this file.  It assumes that the
%%% frequencies for the two signals are equal, and that all data
%%% is in the form of a vector.
function p = InnerProductLocal(f, s1, s2, PSD)
    p = 2 * real(sum(s1.*conj(s2)./PSD)) ...
        / ((length(f)^2) * min(diff(f)));
end
