% Wo = Offset(Wi, Offset)
% Wo = Offset(OffsetType, Wi, Offset)
% 
%   This function returns a copy of the input Waveform
%   object, offset by either the time or phase given by
%   Offset.  OffsetType may be one of 
%     'Time', 'Phase', 'Tortoise', 'ReIm'
%   The default is 'Time'.  'Tortoise' retards by the tortoise
%   coordinate, assuming that the Offset is the Mass, using
%   the Waveform's Radius data.  Option 'ReIm' just adds a
%   constant to the real and imaginary data.

function Wo = Offset(varargin)

if(nargin==2)
    Quantity = 'Time';
    Wi      = varargin{1};
    Offset   = varargin{2};
elseif(nargin==3)
    Quantity = varargin{1};
    Wi      = varargin{2};
    Offset   = varargin{3};
else
    error('Do not understand input arguments.')
end

Wo = Wi;

switch lower(Quantity)
  case {'phase', 'phi'}
    if(size(Wo.LM,1)>1 && length(Offset)==1);
        for i=1:size(Wo.Phi,2);
            Wo.Phi(:,i) = Wo.Phi(:,i) + Wo.LM(i,2)*Offset;
            Wo.PhaseOffset(i) = Wo.PhaseOffset(i) + Wo.LM(i,2)*Offset;
        end;
    else;
        for i=1:size(Wo.Phi,2);
            Wo.Phi(:,i) = Wo.Phi(:,i) + Offset(i);
        end;
        Wo.PhaseOffset = Wo.PhaseOffset + Offset;
    end;
    if(length(Offset)==1);
        Wo.PostProcessing = ...
            [Wo.PostProcessing; ...
             {sprintf('this = Offset(''Phase'', this, %.16g);', ...
                      Offset)}];
    else;
        Wo.PostProcessing = ...
            [Wo.PostProcessing; ...
             {['PhiOffsets = [' ...
              sprintf('%.16g, ', Offset(1:end-1)) ...
              sprintf('%.16g];', Offset(end))]}; ...
             {'this = Offset(''Phase'', this, PhiOffsets);'}];
    end;
    
  case 'time'
    Wo.Time = Wo.Time + Offset;
    Wo.TimeOffset = Wo.TimeOffset + Offset;
    if(length(Offset)==1);
        Wo.PostProcessing = ...
            [Wo.PostProcessing; ...
             {sprintf('this = Offset(''Time'', this, %.16g);', ...
                      Offset)}];
    else;
        Wo.PostProcessing = ...
            [Wo.PostProcessing; ...
             {['TimeOffsets = [' ...
              sprintf('%.16g, ', Offset(1:end-1)) ...
              sprintf('%.16g];', Offset(end))]}; ...
             {'this = Offset(''Time'', this, TimeOffsets);'}];
    end;
    
  case 'tortoise'
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = Offset(''Tortoise'', this, %.16g);', ...
                  Offset)}];
    Offset = -(Wi.Radius+2*Offset*log(Wi.Radius/(2*Offset)-1.0));
    Wo.Time = Wo.Time + Offset;
    Wo.TimeOffset = Wo.TimeOffset + Offset;
    
  case 'reim'
    Wo.PostProcessing = ...
        [Wo.PostProcessing; ...
         {sprintf('this = Offset(''ReIm'', this, %.16g);', ...
                  Offset)}];
    if (length(Offset)==1);
        [Wo.Amp Wo.Phi] = SplitToAmpPhi( Complex(Wi) + Offset );
    elseif(length(Offset)==size(Wo.Amp,2));
        Comp = Complex(Wi);
        for k=1:length(Offset);
            Comp(:,k) = Comp(:,k) + Offset(k);
        end;
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(Comp);
    elseif(size(Offset,1)==size(Wo.Amp,1) && size(Offset,2)==size(Wo.Amp,2));
        Comp = Complex(Wi);
        for k=1:size(Offset,2);
            Comp(:,k) = Comp(:,k) + Offset(:,k);
        end;
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(Comp);
    else;
        error(['Bad sizes in Offset(''ReIm''... with size(Offset) ' ...
               '= %d %d and size(Wo.Amp) = %d %d.'], ...
              size(Offset, 1), size(Offset, 2), ...
              size(Wo.Amp, 1), size(Wo.Amp, 2));
    end;
    
  otherwise
    error('Do not understand Quantity type.');
    
end;

end
