% Wo = W .* Data
% 
%  This function multiplies the complex data of a Waveform by
%  some other array of data, assuming that the Data has the
%  same time values.

function Wo = times(W, Data)
    
    if(length(W.Time) ~= length(Data));
        error('Wrong length of Data for multiplication.');
    end;
    
    Wo = W;
    
    % Update the Waveform data
    [Wo.Amp Wo.Phi] = SplitToAmpPhi(Complex(W) .* Data);
    Wo.Identifier = sprintf('%s_times_data', W.Identifier);
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = times(%s, Data);', W.Identifier)}; ...
         {sprintf('this.Identifier = ''%s'';', Wo.Identifier)}];
    
end
