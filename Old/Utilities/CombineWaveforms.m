% W = CombineWaveforms(W1, W2, ...)
% 
%   This function takes any number of Waveforms, assuming that
%   they have indentical time information (perhaps various L,M
%   data sets) and combines them into a single Waveform.

function W = CombineWaveforms(varargin)
    
    W = CombineTwoWaveforms(varargin{1}, varargin{2});
    for j = 3:nargin;
        W = CombineTwoWaveforms(W, varargin{j});
    end;
    
end



function W = CombineTwoWaveforms(W1, W2)
    
    W = W1;
    W.PostProcessing = [ W1.PostProcessing; W2.PostProcessing ];
    %'Type'
    W.Identifier = [ W1.Identifier '_' W2.Identifier ];
    W.LM = [ W1.LM; W2.LM ];
    W.ThetaPhi = [ W1.ThetaPhi; W2.ThetaPhi ];
    %'Radius'
    %'Time'
    W.Amp = [ W1.Amp'; W2.Amp' ]';
    W.Phi = [ W1.Phi'; W2.Phi' ]';
    W.PhaseOffset = [ W1.PhaseOffset; W2.PhaseOffset ];
    W.TimeOffset = [ W1.TimeOffset; W2.TimeOffset ];
    
end
