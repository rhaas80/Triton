% Wo = Scale(Wi, ScaleFactor)
% Wo = Scale(Wi, ScaleFactor, Quantity)
% 
%   This function returns a copy of the input Waveform
%   object, scaled by ScaleFactor in Quantity, which is one of
%     'All', 'Time', 'Amp', 'AmpAndTime', 'Radius', 'mks', 'LIGO'
%   The default is 'All', which scales the time, amplitude,
%   and radius.  The 'mks' and 'LIGO' options scale the
%   waveform into mks units, where ScaleFactor is in solar
%   masses, and the source is assumed to be at a distance of 1
%   Mpc.  The 'LIGO' option additionally interpolates to a
%   time grid with the resolution at which initial LIGO
%   actually observes.  Note that both of these options are
%   slightly subtle, in that we assume that a Waveform
%   object of type 'rhOverM', 'rhDot', or 'rMPsi4' is
%   dimensionless, and should be made dimensionful, and so
%   converted to types 'h', 'hDot', or 'Psi4', respectively.
%   On the other hand, we assume that 'h', 'hDot', or 'Psi4'
%   are already dimensionful, and should simply be scaled,
%   with no reference to actual physical quantities.

function Wo = Scale(varargin)

    Wo = varargin{1};
    ScaleFactor = varargin{2};
    if(nargin==3)
        Quantity = varargin{3};
    else
        Quantity = 'All';
    end
    
    switch lower(Quantity)
      case 'all'
        t0 = 0;%Wo.Time(1);
        Wo.Time = t0 + (Wo.Time-t0) ./ ScaleFactor;
        t0 = Wo.TimeOffset(1);
        Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) ./ ScaleFactor;
        Wo.Amp = RescaleAmplitude(Wo.Amp,ScaleFactor,Wo.Type);
        Wo.Radius = Wo.Radius ./ ScaleFactor;
      case 'time'
        t0 = 0;%Wo.Time(1);
        Wo.Time = t0 + (Wo.Time-t0) ./ ScaleFactor;
        t0 = Wo.TimeOffset(1);
        Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) ./ ScaleFactor;
      case {'amp','amplitude'}
        Wo.Amp = RescaleAmplitude(Wo.Amp,ScaleFactor,Wo.Type);
      case {'ampandtime','amplitudeandtime'}
        t0 = 0;%Wo.Time(1);
        Wo.Time = t0 + (Wo.Time-t0) ./ ScaleFactor;
        t0 = Wo.TimeOffset(1);
        Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) ./ ScaleFactor;
        Wo.Amp = RescaleAmplitude(Wo.Amp,ScaleFactor,Wo.Type);
      case 'radius'
        Wo.Radius = Wo.Radius ./ ScaleFactor;
      case {'mks', 'ligo'}
        G = 6.67259 * 10^-11;    % meters^3 kilograms^-1 seconds^-2
        c = 2.99792458 * 10^8;   % meters / seconds
        MSun = 1.98892 * 10^30;  % kilograms
        r = 3.08568025 * 10^22;  % meters; (1 megaparsec)
        M = ScaleFactor*MSun*G/c^3; % seconds;
        R = r/c; % seconds
        switch lower(Wo.Type)
          case 'h'
            t0 = 0;%Wo.Time(1);
            Wo.Time = t0 + (Wo.Time-t0) * ScaleFactor;
            t0 = 0;%Wo.TimeOffset(1);
            Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) * ScaleFactor;
            Wo.Amp = Wo.Amp * ScaleFactor;
          case 'hdot'
            t0 = 0;%Wo.Time(1);
            Wo.Time = t0 + (Wo.Time-t0) * ScaleFactor;
            t0 = 0;%Wo.TimeOffset(1);
            Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) * ScaleFactor;
            % Wo.Amp = Wo.Amp; % No need to do this
          case 'psi4'
            t0 = 0;%Wo.Time(1);
            Wo.Time = t0 + (Wo.Time-t0) * ScaleFactor;
            t0 = 0;%Wo.TimeOffset(1);
            Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) * ScaleFactor;
            Wo.Amp = Wo.Amp / ScaleFactor;
          case 'rhoverm'
            t0 = 0;%Wo.Time(1);
            Wo.Time = t0 + (Wo.Time-t0) * M;
            t0 = 0;%Wo.TimeOffset(1);
            Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) * M;
            Wo.Amp = Wo.Amp * (M/R);
            Wo.Type = 'h';
            Wo.PostProcessing = ...
                [Wo.PostProcessing; {'this.Type = ''h'';'}];
          case 'f{rhoverm}'
            Wo.Time = Wo.Time / M;
            Wo.Amp = Wo.Amp / (R/M);
            Wo.Type = 'F{h}';
            Wo.PostProcessing = ...
                [Wo.PostProcessing; {'this.Type = ''F{h}'';'}];
          case 'rhdot'
            t0 = 0;%Wo.Time(1);
            Wo.Time = t0 + (Wo.Time-t0) * M;
            t0 = 0;%Wo.TimeOffset(1);
            Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) * M;
            Wo.Amp = Wo.Amp / R;
            Wo.Type = 'hDot';
            Wo.PostProcessing = ...
                [Wo.PostProcessing; {'this.Type = ''hDot'';'}];
          case 'rmpsi4'
            t0 = 0;%Wo.Time(1);
            Wo.Time = t0 + (Wo.Time-t0) * M;
            t0 = 0;%Wo.TimeOffset(1);
            Wo.TimeOffset = t0 + (Wo.TimeOffset-t0) * M;
            Wo.Amp = Wo.Amp / (R*M);
            Wo.Type = 'Psi4';
            Wo.PostProcessing = ...
                [Wo.PostProcessing; {'this.Type = ''Psi4'';'}];
          otherwise
            error(['Trying to scale to MKS, with a waveform ' ...
                   'of\ntype ''%s''.  This is not supported.'], ...
                  Wo.Type);
        end;
        if(strcmp(lower(Quantity), 'ligo'));
            %% This is the LIGO sampling interval
            LIGOTime = Wo.Time(1):.000244140625:Wo.Time(end);
            Wo = Interpolate(Wo,LIGOTime);
        end;
      otherwise
        error('Don''t understand Quantity ''%s''', Quantity);
    end % switch Quantity
    
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = Scale(this, %.16g, ''%s'');', ...
                                 ScaleFactor, Quantity)}];
    
end % function Scale


function Amp2 = RescaleAmplitude(Amp1, ScaleFactor, Type)
switch lower(Type)
  case {'f{h}', 'h'}
    if(length(ScaleFactor)~=1);
        Amp2 = Amp1;
        for k=1:size(Amp1,2);
            Amp2(:,k) = Amp1(:,k) .* ScaleFactor;
        end;
    else;
        Amp2 = Amp1 * ScaleFactor;
    end;
  case {'rhoverm'}
    if(length(ScaleFactor)~=1);
        Amp2 = Amp1;
        for k=1:size(Amp1,2);
            Amp2(:,k) = Amp1(:,k) ./ ScaleFactor;
        end;
    else;
        Amp2 = Amp1 / ScaleFactor;
    end;
  case {'hdot', 'rhdot'}
    Amp2 = Amp1;
  case {'rmpsi4', 'psi4', 'f{psi4}'}
    if(length(ScaleFactor)~=1);
        Amp2 = Amp1;
        for k=1:size(Amp1,2);
            Amp2(:,k) = Amp1(:,k) .* ScaleFactor;
        end;
    else;
        Amp2 = Amp1 * ScaleFactor;
    end;
  otherwise
    error('Unsupported type %s.', Type);
end;
end % function RescaleAmplitude
