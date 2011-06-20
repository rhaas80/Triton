% SNR = SignalToNoiseRatio(s, PSD)
% 
%   This function returns the signal-to-noise ratio of a
%   signal with respect to the given power spectral density of
%   noise, assuming that the signal is optimally detected.
%   This is simply a wrapper function, which takes the square
%   root of the inner product of the signal with itself.

function SNR = SignalToNoiseRatio(s, PSD)
    
    SNR = sqrt(InnerProduct(s, s, PSD));
    
end
