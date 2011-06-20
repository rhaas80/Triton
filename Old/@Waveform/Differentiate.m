% Wo = Differentiate(Wi)
% Wo = Differentiate(Wi, 'Twice')
% 
%   This returns a copy of the input Waveform, with the real
%   and imaginary parts differentiated.  If 'Twice' is entered
%   as the second argument, the Waveform is efficiently
%   differentiated twice.  If the Waveform is in the frequency
%   domain, differentiation is done using multiplication by
%   the frequency.

function Wo = Differentiate(varargin)

Wo = varargin{1};

if(nargin==1);
    if(~isempty(regexpi(Wo.Type, 'F{')));
        F = Wo.Time;
        Halfway = ceil((length(F)+1)/2);
        F(Halfway:end) = F(Halfway:end) - F(end);
        Wo.Amp = Wo.Amp .* abs(2*pi*F);
        Wo.Phi = Wo.Phi + pi/2;
        Wo.Phi(Halfway:end) = Wo.Phi(Halfway:end) + pi;
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'f{h}'
            Wo.Type = 'F{hDot}'
          case 'f{hdot}'
            Wo.Type = 'F{Psi4}'
          case 'f{psi4}'
            Wo.Type = 'F{Psi4Dot}';
            warning(['Differentiating a Waveform of type %s.\n' ...
                     'This might not be what you want.'], Wo.Type);
          case 'f{rhoverm}'
            Wo.Type = 'F{rhDot}'
          case 'f{rhdot}'
            Wo.Type = 'F{rMPsi4}'
          case 'f{rmpsi4}'
            Wo.Type = 'F{rMSquaredPsi4Dot}'
            warning(['Differentiating a Waveform of type %s.\n' ...
                     'This might not be what you want.'], Wo.Type);
          otherwise
            Wo.Type = 'Unknown';
            warning(['Differentiating a Waveform of type %s.\n' ...
                     'This might not be what you want.'], Wo.Type);
        end;
    else;
        %%% Differentiate the data
%         dydt = DifferentiateDataSet(Wo.Time,Complex(Wo));
        dAmpdt = DifferentiateDataSet(Wo.Time, Wo.Amp);
        dPhidt = DifferentiateDataSet(Wo.Time, Wo.Phi);
        dydt = (dAmpdt + i*Wo.Amp.*dPhidt) .* exp(i*Wo.Phi);
        %%% Translate into Abs and Phi data
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(dydt);
        Wo.PhaseOffset = zeros(1, size(Wo.Phi, 2));
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'h'
            Wo.Type = 'hDot';
          case 'hdot'
            Wo.Type = 'Psi4';
          case 'psi4'
            Wo.Type = 'Psi4Dot';
            warning(['Differentiating a Waveform of type %s.\n' ...
                     'This might not be what you want.'], Wo.Type);
          case 'rhoverm'
            Wo.Type = 'rhDot';
          case 'rhdot'
            Wo.Type = 'rMPsi4';
          case 'rmpsi4'
            Wo.Type = 'rMSquaredPsi4Dot';
            warning(['Differentiating a Waveform of type %s.\n' ...
                     'This might not be what you want.'], Wo.Type);
          otherwise
            Wo.Type = 'Unknown';
            warning(['Differentiating a Waveform of type %s.\n' ...
                     'This might not be what you want.'], Wo.Type);
        end;
    end; % if(~isempty(regexpi(Wo.Type, 'F{')));
    %%% Note in PostProcessing
    Wo.PostProcessing = [Wo.PostProcessing; ...
                        {'this = Differentiate(this);'}];
    
elseif(nargin==2 && strcmp(lower(varargin{2}), 'twice'));
    if(~isempty(regexpi(Wo.Type, 'F{')));
        F = Wo.Time;
        Halfway = ceil((length(F)+1)/2);
        F(Halfway:end) = F(Halfway:end) - F(end);
        Wo.Amp = Wo.Amp .* (4*pi^2*F.^2);
        Wo.Phi = Wo.Phi + pi;
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'f{h}'
            Wo.Type = 'F{Psi4}'
          case 'f{hdot}'
            Wo.Type = 'F{Psi4Dot}'
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{psi4}'
            Wo.Type = 'F{Psi4DDot}'
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{rhoverm}'
            Wo.Type = 'F{rMPsi4}'
          case 'f{rhdot}'
            Wo.Type = 'F{rMSquaredPsi4Dot}'
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'f{rmpsi4}'
            Wo.Type = 'F{rMCubedPsi4DDot}'
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          otherwise
            Wo.Type = 'Unknown';
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
        end;
        
    else;
        %%% Differentiate the data
%         dydt = DifferentiateDataSet(Wo.Time,Complex(Wo));
%         d2ydt2 = DifferentiateDataSet(Wo.Time,dydt);
        dAmpdt = DifferentiateDataSet(Wo.Time, Wo.Amp);
        dPhidt = DifferentiateDataSet(Wo.Time, Wo.Phi);
        d2Ampdt2 = DifferentiateDataSet(Wo.Time, dAmpdt);
        d2Phidt2 = DifferentiateDataSet(Wo.Time, dPhidt);
        d2ydt2 = (d2Ampdt2 + 2*i*dAmpdt.*dPhidt ...
                  + i*Wo.Amp.*d2Phidt2 - Wo.Amp.*(dPhidt.^2)) ...
                 .* exp(i*Wo.Phi);
        %%% Translate into Abs and Phi data
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(d2ydt2);
        Wo.PhaseOffset = zeros(1, size(Wo.Phi, 2));
        %%% Re-establish the type
        switch lower(Wo.Type)
          case 'h'
            Wo.Type = 'Psi4';
          case 'hdot'
            Wo.Type = 'Psi4Dot';
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'psi4'
            Wo.Type = 'Psi4DDot';
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'rhoverm'
            Wo.Type = 'rMPsi4';
          case 'rhdot'
            Wo.Type = 'rMSquaredPsi4Dot';
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          case 'rmpsi4'
            Wo.Type = 'rMCubedPsi4DDot';
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
          otherwise
            Wo.Type = 'Unknown';
            warning(['Differentiating a Waveform of type %s twice' ...
                     '.\nThis might not be what you want.'], Wo.Type);
        end;
    end; % if(~isempty(regexpi(Wo.Type, 'F{')));
    %%% Note in PostProcessing
    Wo.PostProcessing = [Wo.PostProcessing; ...
                        {'this = Differentiate(this, ''Twice'');'}];
else;
    error('Don''t understand input arguments.');
end; % if(nargin==1)

end % function
