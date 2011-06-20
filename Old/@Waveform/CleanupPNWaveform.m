% Wo = CleanupPNWaveform(Wi)
% 
%   This function returns a copy of the input Waveform object,
%   after removing data near the end (more than halfway) for
%   which the frequency is not monotonic, and removes
%   non-finite data.

function Wo = CleanupPNWaveform(Wi)
    
    %%% Find the turnover index
    Omega = Omega(Wi);
    Halfway = ceil(size(Omega,1)/2);
    Quarterway = floor(size(Omega,1)/4);
    Sign = sign(Omega(Halfway) - Omega(Quarterway));
    TurnoverIndex = 1;
    for k = Halfway:size(Omega,1);
        if( Sign*Omega(k) < Sign*Omega(k-1) );
            break;
        end;
        TurnoverIndex = k;
    end;
    
    %%% Remove the excess data
    Wo = Wi;
    Indices = 1:TurnoverIndex;
    BadIndices = isnan(Wi.Amp) + isnan(Wi.Phi) + ...
        isinf(Wi.Amp) + isinf(Wi.Phi);
    Indices = Indices(find(1-BadIndices));
    Wo.Time = Wo.Time(Indices);
    Wo.Amp = Wo.Amp(Indices);
    Wo.Phi = Wo.Phi(Indices);
    if(length(Wo.Radius)>1);
        Wo.Radius = Wo.Radius(Indices);
    end;
    if(length(Wi.TimeOffset)>1);
        Wo.TimeOffset = Wo.TimeOffset(Indices);
    end;
    
    %%% Record it
    Wo.PostProcessing = ...
        [Wo.PostProcessing; {'this = CleanupPNWaveform(this);'}];
    
end
