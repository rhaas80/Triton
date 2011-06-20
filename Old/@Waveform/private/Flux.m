function varargout = Flux(W)
    
    if(~strcmp(lower(W.Type), 'rhdot'));
        warning(['You are asking for the flux from a Waveform, ' ...
                 'but the Waveform''s type seems not to be ' ...
                 'rhDot.  If this is true, the "Flux" will not ' ...
                 'be the intended quantity.']);
    end;
    if(size(W.LM, 1) == 0);
        warning(['The Waveform has no L,M data.  This ' ...
                 'Waveform may represent data at particular ' ...
                 'angles.']);
    end;
    
    Flux = zeros(length(W.Time), 1);
    Amp = W.Amp;
    for k=1:size(W.Amp,2);
        Flux = Flux + Amp(:,k).*Amp(:,k);
    end;
    
%     warning('I assume that L,M and L,-M are both stored, and the sum runs over all stored values.');
    Flux = Flux/(16*pi);
    
    if(nargout==2);
        varargout{1} = W.Time;
        varargout{2} = Flux;
    else;
        varargout{1} = Flux;
    end;
    
end
