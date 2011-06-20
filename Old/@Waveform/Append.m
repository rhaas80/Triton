% W = Append(W1, W2)
% 
%   This function returns a Waveform based on W1, with fields
%   from W2 appended.  Note that PostProcessing, TimeOffset,
%   PhaseOffset, and possibly other fields are not appended.


function W = Append(W1, W2)
    if(~strcmp(W1.Type,'Unknown') && ~strcmpi(W1.Type, W2.Type));
        disp(sprintf('W1.Type = %s; W2.Type = %s;', W1.Type, W2.Type));
        error('Mismatching Waveform Types in Append');
    end;
    
    W = W1;
    W.Type = W2.Type; % in case W1 is an empty Waveform
    
    % Interpolate the data to a common Time grid if necessary
    if(length(W.Time)==0);
        W.Time = W2.Time;
    end;
    if(length(W.Time)~=length(W2.Time) || sum(W.Time~=W2.Time)>0);
        W2 = Interpolate(W2, W1.Time);
    end;
    
    W.LM = [W1.LM; W2.LM];
    W.ThetaPhi = [W1.ThetaPhi; W2.ThetaPhi];
    W.PhaseOffset = [W1.PhaseOffset; W2.PhaseOffset];
    W.Amp = [W1.Amp W2.Amp];
    W.Phi = [W1.Phi W2.Phi];
end
