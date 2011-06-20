% n = NoiseRealization(Length, PSD)
% n = NoiseRealization(Length, SampleFreq, PSD)
% 
%   This function returns a vector of Gaussian noise, colored
%   by the input PSD.  The vector is meant to represent a time
%   series of detector data


function n = NoiseRealization(varargin)
    Length = varargin{1};
    if(isa(varargin{2}, 'double'));
        SampleFreq = varargin{2};
        PSD = varargin{3};
    else;
        SampleFreq = 4096;
        PSD = varargin{2};
    end;
    
    % Make the f vector
    Nyquist = floor(Length/2);
    f = 0 : (Length ;
    PSD = PSD(abs([f(1:(Nyquist-1)); (f(Nyquist:end)-f(end))]));
    f = ( 0 : SampleFreq/Length : SampleFreq-1 )';
    
    n = ifft( fft(wgn(Length, 1, 0)) .* sqrt(PSD(abs(f))) );
end;
