% 



function varargout = Find(varargin)

Quantity = 'Omega';
TimeA = -10^200;
TimeB =  10^200;

if(nargin>=3);
    if(isa(varargin{3},'char'));
        Quantity = varargin{3};
        if(nargin>=4);
            TimeA = varargin{4};
            if(nargin==5);
                TimeB = varargin{5};
            end;
        end;
    else;
        TimeA = varargin{3};
        if(nargin==4);
            TimeB = varargin{4};
        end;
    end;
end;
if(nargin>5);
    error('Too many arguments.');
end;

if(TimeA~=-10^200 || TimeB~=10^200);
    varargin{1} = Trim(varargin{1}, 'KeepAfter', TimeA, ...
                       'KeepBefore', TimeB);
end;

switch lower(Quantity)
  case {'amp','amplitude'}
    Time  = interp1(varargin{1}.Amp(:,1), varargin{1}.Time, varargin{2});
    %figure; plot(varargin{1}.Time,varargin{1}.Amp(:,1),'-',Time,varargin{2},'o')
    %figure; plot(varargin{1}.Time,varargin{1}.Phi,'-',Time,Phase,'o')
    for i = 1:length(Time);
        if (isnan(Time(i)));% || isnan(Phase(i)))
            warning(strcat(...
                'NaN in FindAmplitude\n',...
                'Most likely, the input Amplitude=%.16g\n',...
                'is not found in the input waveform.\n\n'),...
                    varargin{2}(i));
        end;
    end;
    varargout{1} = Time;
    if(nargout==2 || nargout==3);
        varargout{2} = interp1(varargin{1}.Time, varargin{1}.Phi, Time);
    end;
    if(nargout==3);
        varargout{3} = interp1(varargin{1}.Time, varargin{1}.Amp, Time);
    end;
    
  case {'phi','phase'}
    Time  = interp1(varargin{1}.Phi(:,1), varargin{1}.Time, varargin{2});
    figure; plot(varargin{1}.Time,varargin{1}.Phi(:,1),'-',Time,varargin{2},'o')
    for i = 1:length(Time);
        if (isnan(Time(i)));% || isnan(Phase(i)))
            warning(strcat(...
                'NaN in FindPhase\n',...
                'Most likely, the input Phase=%.16g\n',...
                'is not found in the input waveform.\n\n'),...
                    varargin{2}(i));
        end;
    end;
    varargout{1} = Time;
    if(nargout==2 || nargout==3);
        varargout{2} = varargin{2};
    end;
    if(nargout==3);
        varargout{3} = interp1(varargin{1}.Time, varargin{1}.Amp, Time);
    end;
    
  case 'omega'
    % Interpolate [Omega1 Time1] to Omega, thus finding
    % the time at which that frequency occurs
    omega = Omega(varargin{1});
    Time  = interp1(omega(:,1), varargin{1}.Time, varargin{2});
    %Phase = interp1(varargin{1}.Time, varargin{1}.Phi, Time);
    %Amp   = interp1(varargin{1}.Time, varargin{1}.Amp, Time);
    %figure; plot(varargin{1}.Time,omega(:,1),'-',Time,varargin{2},'o')
    %figure; plot(varargin{1}.Time,varargin{1}.Phi,'-',Time,Phase,'o')
    for i = 1:length(Time);
        if (isnan(Time(i)));% || isnan(Phase(i)))
            warning(strcat(...
                'NaN in FindOmega\n',...
                'Most likely, the input Omega=%.16g\n',...
                'is not found in the input waveform.\n\n'),varargin{2}(i));
        end;
    end;
    varargout{1} = Time;
    if(nargout==2 || nargout==3);
        varargout{2} = interp1(varargin{1}.Time, varargin{1}.Phi, Time);
    end
    if(nargout==3);
        varargout{3} = interp1(varargin{1}.Time, varargin{1}.Amp, Time);
    end

end; % switch    

end % function Find
