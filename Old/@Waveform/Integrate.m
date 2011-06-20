% Wo = Integrate(Wi)
% Wo = Integrate(Wi, 'Twice')
% Wo = Integrate(Wi, 'Once', f0)
% Wo = Integrate(Wi, 'Twice', f0)
% 
%   This returns a copy of the input Waveform object, with
%   the real and imaginary data integrated.  If 'Twice' is
%   entered as the second argument, the double integral is
%   computed slightly more efficiently than two single
%   integrals.  If the Waveform is in the frequency-domain,
%   integration is done using division by the frequency.  If, in addition, there is a third argument, frequencies below that will be filtered

function Wo = Integrate(varargin)


Wo = varargin{1};

if(nargin==1 || (nargin==2 && strcmp(lower(varargin{2}), 'once'));
    if(~isempty(regexpi(Wo.Type, 'F{')));
        F = Wo.Time;
        Halfway = ceil((length(F)+1)/2);
        F(Halfway:end) = F(Halfway:end) - F(end);
        Wo.Amp = Wo.Amp ./ abs(2*pi*F);
        Wo.Amp(1) = 0;
        Wo.Amp(end) = 0;
        Wo.Phi = Wo.Phi - pi/2;
        Wo.Phi(Halfway:end) = Wo.Phi(Halfway:end) - pi;
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'f{h}'
            Wo.Type = 'F{Inth}';
            warning(['Integrating a Waveform of type %s' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{hdot}'
            Wo.Type = 'F{h}';
          case 'f{psi4}'
            Wo.Type = 'F{hDot}';
          case 'f{rhoverm}'
            Wo.Type = 'F{Intrh}';
            warning(['Integrating a Waveform of type %s' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{rhdot}'
            Wo.Type = 'F{rhOverM}';
          case 'f{rmpsi4}'
            Wo.Type = 'F{rhDot}';
          otherwise
            Wo.Type = 'Unknown';
            warning(['Integrating a Waveform of type %s' ...
                     '.\nThis might not be what you want.'], Wo.Type);
        end;
    else;
        %%% Do the naive integral
        Integral = cumtrapz(Wo.Time,Complex(Wo),1);
        %%% Remove the average from the integral
        Avg = sum(Integral,1)/size(Integral,1);
        for k = 1:size(Integral,2)
            Integral(:,k) = Integral(:,k) - Avg(k);
        end
        %%% Translate into Abs and Phi data
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(Integral);
        Wo.PhaseOffset = zeros(1, size(Wo.Phi, 2));
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'h'
            Wo.Type = 'Inth';
            warning(['Integrating a Waveform of type %s' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'rhoverm'
            Wo.Type = 'Intrh';
            warning(['Integrating a Waveform of type %s' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'rhdot'
            Wo.Type = 'rhOverM';
          case 'hdot'
            Wo.Type = 'h';
          case 'psi4'
            Wo.Type = 'hDot';
          case 'rmpsi4'
            Wo.Type = 'rhDot';
          otherwise
            Wo.Type = 'Unknown';
            warning(['Integrating a Waveform of type %s' ...
                     '.\nThis might not be what you want.'], Wo.Type);
        end;
    end; % if(~isempty(regexpi(Wo.Type, 'F{')));
    %%% Make a note of what we've done
    Wo.PostProcessing = [Wo.PostProcessing; ...
                        {'this = Integrate(this);'}];
elseif(nargin==2 && strcmp(lower(varargin{2}), 'twice'));
    if(~isempty(regexpi(Wo.Type, 'F{')));
        F = Wo.Time;
        Halfway = ceil((length(F)+1)/2);
        F(Halfway:end) = F(Halfway:end) - F(end);
        for i=1:size(Wo.Amp,2)
            Wo.Amp(:,i) = Wo.Amp(:,i) ./ (4*pi^2*F.^2);
        end;
        Wo.Phi = Wo.Phi - pi;
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'f{h}'
            Wo.Type = 'F{IntInth}';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{rhoverm}'
            Wo.Type = 'F{IntIntrhOverMCubed}';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{rhdot}'
            Wo.Type = 'F{IntrhOverMSquared}';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{hdot}'
            Wo.Type = 'F{Inth}';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{psi4}'
            Wo.Type = 'F{h}';
          case 'f{rmpsi4}'
            Wo.Type = 'F{rhOverM}';
          otherwise
            Wo.Type = 'Unknown';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
        end; % switch
    else;
        %%% Do the naive integral once
        Integral = cumtrapz(Wo.Time,Complex(Wo),1);
        %%% Remove the average from the integral
        Avg = sum(Integral,1)/size(Integral,1);
        for k = 1:size(Integral,2)
            Integral(:,k) = Integral(:,k) - Avg(k);
        end
        %%% Do the naive integral again
        Integral = cumtrapz(Wo.Time,Integral,1);
        %%% Remove the average from the integral again
        Avg = sum(Integral,1)/size(Integral,1);
        for k = 1:size(Integral,2)
            Integral(:,k) = Integral(:,k) - Avg(k);
        end
        %%% Translate into Abs and Phi data
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(Integral);
        Wo.PhaseOffset = zeros(1, size(Wo.Phi, 2));
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'h'
            Wo.Type = 'IntInth';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'rhoverm'
            Wo.Type = 'IntIntrhOverMCubed';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'rhdot'
            Wo.Type = 'IntrhOverMSquared';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'hdot'
            Wo.Type = 'Inth';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'psi4'
            Wo.Type = 'h';
          case 'rmpsi4'
            Wo.Type = 'rhOverM';
          otherwise
            Wo.Type = 'Unknown';
            warning(['Integrating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
        end; % switch
    end; % if(~isempty(regexpi(Wo.Type, 'F{')));
    %%% Make a note of what we've done
    Wo.PostProcessing = [Wo.PostProcessing; ...
                        {'this = Integrate(this, ''Twice'');'}];
    
end; % if(nargin==1);

end % function
