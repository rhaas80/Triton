% W = Waveform('MetadataFileName');
% W = Waveform('FileName', 'Format', Radius)
% W = Waveform('FileName', 'Format', 'RadiusFileName')
% W = Waveform('SPA', M, η, f)
% W = Waveform(Type, PostProcessing, LM, ThetaPhi, Radius, Time, Amp, Phi)
%   
%   
%   The Waveform class is a structure containing a
%   time-domain waveform.  The constructor takes a file name
%   from which to read the data, a format for the data, and
%   radius information.  The format may be one of
%      'ReIm', 'ChiPhi', 'AmpPhi', 'PhiAmp', 'NegPhiAmp'
%   The data is assumed to be in columns, where the first
%   column is the time, and consecutice pairs of columns are
%   the real and imaginary parts; or the amplitude and
%   phase; etc.  Here phase is defined to be the result of
%   'unwrap(angle(Data))', which is the continuous version
%   of the standard 'arg' function.  Radius information may
%   either be the name of a file from which to read radius
%   data (columns: Time Radius), or a single real number, if
%   the radius is constant.
%   
%   There is also some support for frequency-domain data.  In
%   particular, fft(W) returns a Waveform object with
%   Frequency, FFT Amplitude, and FFT Phase stored as Time,
%   Amp, and Phi.  The Type of such a Waveform is 'F{%s}',
%   where %s is the Type of the original.  Note that not all
%   functions support frequency-domain Waveforms; only the
%   basics needed to compute Overlaps, for instance.
%   
%   The third constructor produces a Waveform of this type: an
%   SPA Waveform, for a system of total mass M (measured in
%   Solar masses) and symmetric mass ratio η=μ/M, evaluated at
%   frequencies f (measured in Hertz).  The source is placed
%   at a distance of 1 Mpc.  Note that the input set of
%   frequencies is assumed to include frequencies up to the
%   sampling frequency: f = (0, ..., fNyquist, ...,
%   fSampling).  This is the format that comes out of 'fft'.
%   The resulting Waveform will have power throughout this band.
%   
%   Finally, the last constructor creates a Waveform with the
%   given data.  Note that PostProcessing here is just a
%   string inserted into the PostProcessing data.

function W = Waveform(varargin)
    
    switch nargin;
      case 0  % Empty constructor
        Temp = clock;
        W.PostProcessing = cell(8,1);
        W.Type = 'Unknown';
        W.Identifier = sprintf('%s:%.2d:%.2d:%f', ...
                               date, Temp(4:6));
        global EmailAddress;
        if(size(EmailAddress)==[0 0]);
            [s EmailAddress] = system('echo -n `whoami`@`hostname`');
        end;
        W.PostProcessing{1} = '[constructor]';
        W.PostProcessing{2} = sprintf('User = ''%s'';', EmailAddress);
        W.PostProcessing{3} = sprintf('StartPwd = ''%s'';', pwd);
        W.PostProcessing{4} = ...
            sprintf('StartDate = ''%s %.2d:%.2d:%f'';', ...
                    date, Temp(4:6));
        W.PostProcessing{5} = sprintf('Identifier = ''%s'';', ...
                                      W.Identifier);
        W.PostProcessing{6} = 'this = Waveform();';
        W.PostProcessing{7} = '';
        W.PostProcessing{8} = '[post-processing]';
        clear Temp;
        W.LM = [];
        W.ThetaPhi = [];
        W.Radius = -1.0;
        W.Time = [];
        W.Amp = [];
        W.Phi = [];
        W.PhaseOffset = [];
        W.TimeOffset = 0.0;
        W = class(W, 'Waveform');
        % end case 0
        
      case 1  % Copy constructor and metadata file reader
        if (isa(varargin{1}, 'Waveform'));
            W = varargin{1};
        else;
            MetadataFileName = varargin{1};
            Path = regexp(MetadataFileName, '(.*)\/[^\/]*', 'tokens');
            if(length(Path)>0);
                Path = Path{1}{1};
            else;
                Path = '';
            end;
            PostProcessing = cell(1,1);
            PostProcessing{1} = ['this = Waveform(' MetadataFileName ');'];
            fid=fopen(MetadataFileName);
            while(true);
                tline = fgetl(fid);
                if ~ischar(tline), break, end;
                PostProcessing{end+1} = tline;
            end;
            fclose(fid);
            W = Waveform();
            k = 1;
            while(k<=length(PostProcessing));
                m = regexp(PostProcessing{k}, '^[^\#]*\[(.*?)-data\]', 'tokens');
                k = k+1;
                if(length(m)~=0);
                    if(length(regexpi(m{1}, 'ampphi', 'tokens'))~=0);
                        Format = 'AmpPhi';
                    else;
                        Format = 'ReIm';
                    end;
                    while(k<=length(PostProcessing));
                        m = regexp(PostProcessing{k}, '^[^\#]*\[', 'tokens');
                        if(length(m)~=0), break, end;
                        DataFileName = regexp(PostProcessing{k}, '.*= *(\S*)', 'tokens');
                        if(length(DataFileName)~=0);
                            W = Append(W, Waveform([Path '/' DataFileName{1}{1}], Format, 0));
                        end;
                        k = k+1;
                    end;
                end;
            end;
            W.PostProcessing = cell(2,1);
            W.PostProcessing{1} = sprintf('cd %s;', pwd);
            W.PostProcessing{2} = sprintf('this = Waveform(%s);', MetadataFileName);
        end;
        % end case 1
        
      case 3  % Reads a data file in the chosen format, along with
              % a radius data file
        DataFileName = varargin{1};
        DataFileType = varargin{2};
        RadiusData   = varargin{3};
        %%% Set up the fields
        Temp = clock;
        W.PostProcessing = cell(6,1);
        W.Type = 'Unknown';
        W.Identifier = sprintf('%s:%.2d:%.2d:%f', ...
                                     date, Temp(4:6));
        global EmailAddress;
        if(size(EmailAddress)==[0 0]);
            [s EmailAddress] = system('echo -n `whoami`@`hostname`');
        end;
        W.PostProcessing{1} = '[constructor]';
        W.PostProcessing{2} = sprintf('User = ''%s'';', EmailAddress);
        W.PostProcessing{3} = sprintf('InputPwd = ''%s'';', pwd);
        W.PostProcessing{4} = ...
            sprintf('InputDate = ''%s %.2d:%.2d:%f'';', ...
                    date, Temp(4:6));
        W.PostProcessing{5} = sprintf('DataFileName = ''%s'';', ...
                                      DataFileName);
        W.PostProcessing{6} = sprintf('Identifier = ''%s'';', ...
                                      W.Identifier);
        clear Temp;
        W.LM = [];
        W.ThetaPhi = [];
        W.Radius = -1.0;
        W.Time = [];
        W.Amp = [];
        W.Phi = [];
        [Time ColA ColB Header] = ReadDatFile(DataFileName);
        W.PhaseOffset = zeros(1,size(ColA,2));
        W.TimeOffset = 0.0;
        W.Time = Time;
        %%% Process the data
        switch lower(DataFileType);
          case 'reim'
            [W.Amp W.Phi] = SplitToAmpPhi(ColA + i*ColB);
          case 'chiphi'
            W.Amp = exp(ColA);
            W.Phi = ColB;
          case 'ampphi'
            W.Amp = ColA;
            W.Phi = ColB;
          case 'phiamp'
            W.Amp = ColB;
            W.Phi = ColA;
          case 'negphiamp'
            W.Amp = ColB;
            W.Phi = -ColA;
          otherwise
            error(['Do not understand data file type %s\nfor ' ...
                   'file %s'], DataFileType, DataFileName); 
        end;
        %%% Get the Radius
        if(isa(RadiusData,'numeric'));
            W.Radius = RadiusData;
            W.PostProcessing = [W.PostProcessing; ...
                {sprintf('Radius = %.16g;', RadiusData)}];
        elseif(isa(RadiusData,'char'));
            [RadiusTime W.Radius Header] = ...
                ReadDatFile(RadiusData, 'Radius');
            W.Radius = interp1(RadiusTime, W.Radius, W.Time);
            W.PostProcessing = [W.PostProcessing; ...
                {sprintf('RadiusFileName = ''%s'';', DataFileName)}];
            if(sum(isnan(W.Radius))>0);
                error(['Creating a Waveform object: \n\t%s' ...
                       'There is a NaN in the radius.  This ' ...
                       'usually happens when the time axes of ' ...
                       'the radius file and data file are ' ...
                       'mismatched.'], '');
            end;
        else;
            error('Do not understand the third input argument.');
        end;
        %%% Determine the Type, and the LM or ThetaPhi data
        W.Type = GetType(W.Type, DataFileName, Header);
        [W.LM W.ThetaPhi] = GetLMOrThetaPhi(DataFileName, Header);
        if(size(W.LM,1)+size(W.ThetaPhi,1) ~= size(W.Amp,2));
            warning(['Got %d LM elements, %d ThetaPhi elements, ' ...
                     'and %d data sets.'], size(W.LM,1), ...
                    size(W.ThetaPhi,1), size(W.Amp,2));
        end;
        %%% Add to the PostProcessing cell
        if(isa(RadiusData, 'double'));
            W.PostProcessing = ...
                [W.PostProcessing; ...
                 {sprintf(['this = Waveform(''%s'', ''%s'', ' ...
                           '%.16g);'], DataFileName, ...
                          DataFileType, RadiusData)}];
        else;
            W.PostProcessing = ...
                [W.PostProcessing; ...
                 {sprintf(['this = Waveform(''%s'', ''%s'', ' ...
                           '''%s'');'], DataFileName, ...
                          DataFileType, RadiusData)}];
        end;
        W.PostProcessing = ...
            [W.PostProcessing; ...
             {sprintf('this.Type = ''%s'';', W.Type)}; {''}; ...
             {sprintf('[begin-old-header-%s]', W.Identifier)}; ...
             Header; ...
             {sprintf('[end-old-header-%s]', W.Identifier)} ...
            ];
        %%% Read and include the old PostProcessing file
        tokens = regexp(DataFileName, ...
                    '(.*)_L.*_M.*\.dat', 'tokens');
        if(length(tokens)~=0);
            PostFileName = [char(tokens{1}) '.meta'];
        else;
            tokens = regexp(DataFileName, ...
                            '(.*)_Theta.*_Phi.*\.dat', 'tokens');
            if(length(tokens)~=0);
                PostFileName = [char(tokens{1}) '.post'];
            end;
        end;
        if(exist('PostFileName'));
            File = fopen(strcat(PostFileName));
            if (File ~= -1);
                PostFile = textscan(File,'%s','Delimiter','\n');
                PostFile = PostFile{1};
                W.PostProcessing = ...
                    [W.PostProcessing; {''}; ...
                     {sprintf('[begin-old-post-processing-%s]', ...
                              W.Identifier)}; ...
                     PostFile; ...
                     {sprintf('[end-old-post-processing-%s]', ...
                              W.Identifier)}; ...
                    ];
                fclose(File);
            end;
        end;
        %%% Finish up the PostProcessing cell
        W.PostProcessing = ...
            [W.PostProcessing; ...
             {''; '[post-processing]'}];
        W = class(W, 'Waveform');
        %%% Warn, if Type is unknown
        if(strcmp(lower(W.Type), 'unknown'));
            warning('Waveform''s Type is Unknown.');
        end;
        % end case 3
        
      case 4 % This creates an SPA Waveform object
        W = Waveform(varargin{1}, varargin{2}, varargin{3}, ...
                     varargin{4}, 3.5);
        
      case 5
        if(strcmp(lower(varargin{1}), 'spa'));
            G = 6.67259 * 10^-11;    % m^3 kg^-1 sec^-2
            MSun = 1.98892 * 10^30;  % kilograms
            c = 299792458;           % meters / second
            r = 3.08568025 * 10^22;  % (1 megaparsec) meters;
            
            M = varargin{2};
            eta = varargin{3};
            f = varargin{4};
            if(isa(f, 'Waveform'));
                f = f.Time;
            end;
            pNOrder = varargin{5};
            fISCO = (c^3) / (6^1.5 * pi * G * M * MSun);
            
            M = M * MSun;
            % M = (m1 + m2) * MSun;
            % mu = (m1 * m2 / M) * MSun^2;
            % eta = mu/M;
            mu = eta*M;
            
            Temp = clock;
            W.PostProcessing = cell(8,1);
            W.Type = 'F{h}';
            W.Identifier = ...
                sprintf(['SPA_M=%.16g_eta=%.16g_pNOrder=%.16g' ...
                         '_%s:%.2d:%.2d:%f'], ...
                        varargin{2}, eta, pNOrder, date, Temp(4:6));
            global EmailAddress;
            if(size(EmailAddress)==[0 0]);
                [s EmailAddress] = ...
                    system('echo -n `whoami`@`hostname`');
            end;
            W.PostProcessing{1} = '[constructor]';
            W.PostProcessing{2} = sprintf('User = ''%s'';', ...
                                          EmailAddress);
            W.PostProcessing{3} = ...
                sprintf('InputDate = ''%s %.2d:%.2d:%f'';', ...
                        date, Temp(4:6));
            W.PostProcessing{4} = sprintf('Identifier = ''%s'';', ...
                                          W.Identifier);
            W.PostProcessing{5} = 'Type = ''F{h}'';';
            W.PostProcessing{6} = ...
                sprintf(['this = Waveform(''SPA'', %.16g, ' ...
                         '%.16g, f, %.16g);'], M, eta, pNOrder);
            W.PostProcessing{7} = '';
            W.PostProcessing{8} = '[post-processing]';
            clear Temp;
            W.LM = [[2 2]];
            W.ThetaPhi = [];
            W.Radius = r;
            if(size(f,1)>size(f,2));
                W.Time = f;
            else;
                W.Time = f';
            end;
            W.Amp = ((2*G*MSun)/(c^2*r)) * ...
                    ((5*mu)/(96*MSun))^(1/2) * ...
                    (M/(pi^2*MSun))^(1/3) * ...
                    ((G*MSun)/(c^3))^(-1/6) * ...
                    (W.Time.^(-7/6));
            W.Phi = -Psi(M, eta, W.Time, pNOrder);
            W.Amp(ceil((length(W.Amp)+1)/2):end) = ...
                W.Amp(floor((length(W.Amp)+1)/2):-1:1);
            W.Phi(ceil((length(W.Phi)+1)/2):end) = ...
                2*W.Phi(ceil((length(W.Phi))/2)) ...
                -W.Phi(floor((length(W.Phi)+1)/2):-1:1);
            W.Amp(find(isnan(W.Amp))) = 0.0;
            W.Phi(find(isnan(W.Phi))) = 0.0;
            W.Amp(find(isinf(W.Amp))) = 0.0;
            W.Phi(find(isinf(W.Phi))) = 0.0;
            W.PhaseOffset = 0;
            W.TimeOffset = 0.0;
            W = class(W, 'Waveform');
        else;
            error('Don''t understand argument %s', varargin{1});
        end; % if(strcmp(lower(varargin{1}), 'SPA'));
        % end case 4
        
      case 8  % Explicit constructor
        Temp = clock;
        W.PostProcessing = cell(9,1);
        W.Type = varargin{1};
        W.Identifier = sprintf('%s:%.2d:%.2d:%f', ...
                               date, Temp(4:6));
        global EmailAddress;
        if(size(EmailAddress)==[0 0]);
            [s EmailAddress] = system('echo -n `whoami`@`hostname`');
        end;
        W.PostProcessing{1} = '[constructor]';
        W.PostProcessing{2} = sprintf('User = ''%s'';', EmailAddress);
        W.PostProcessing{3} = sprintf('StartPwd = ''%s'';', pwd);
        W.PostProcessing{4} = ...
            sprintf('StartDate = ''%s %.2d:%.2d:%f'';', ...
                    date, Temp(4:6));
        W.PostProcessing{5} = sprintf('Identifier = ''%s'';', ...
                                      W.Identifier);
        W.PostProcessing{6} = 'this = Waveform([explicit quantities]);';
        W.PostProcessing{7} = sprintf('%% %s', varargin{2});
        W.PostProcessing{8} = '';
        W.PostProcessing{9} = '[post-processing]';
        clear Temp;
        W.LM = varargin{3};
        W.ThetaPhi = varargin{4};
        W.Radius = varargin{5};
        W.Time = varargin{6};
        W.Amp = varargin{7};
        W.Phi = varargin{8};
        W.PhaseOffset = zeros(1,size(W.Phi,2));;
        W.TimeOffset = 0.0;
        W = class(W, 'Waveform');
        % end case 8
        
    end; % switch nargin
    
end % function Waveform


%%% The following functions are local to this file


function Type = GetType(Type, FileName, Header)
    
    %%% Strip the path from the FileName
    FileNameReg = regexp(FileName, '.*\/(.*)', 'tokens');
    if(length(FileNameReg)>0);
        FileName = char(FileNameReg{1});
    end;
    
    %%% Look for the info in the file name
    if(~isempty(regexpi(FileName, 'readmpsi4')) || ...
       ~isempty(regexpi(FileName, 'rmpsi4')));
        Type = 'rMPsi4';
        return;
    end;
    if(~isempty(regexpi(FileName, 'rpsi4')));
        Type = 'rPsi4';
        return;
    end;
    if(~isempty(regexpi(FileName, 'Psi4')));
        Type = 'Psi4';
        return;
    end;
    if(~isempty(regexpi(FileName, 'rhovereadm')) || ...
       ~isempty(regexpi(FileName, 'rhoverm')));
        Type = 'rhOverM';
        return;
    end;
    if(~isempty(regexpi(FileName, 'rh')));
        Type = 'rh';
        return;
    end;
    if(~isempty(regexpi(FileName, 'h')));
        Type = 'h';
        return;
    end;
    
    %%% Look for the info in the Header
    if(strcmp(Header{1,1},'Empty header'));
      warning('Empty header when looking for data type');
      return;
    end;
    Header = char(Header)';
    Header = Header(:)';
    Indices = regexp(Header, '# \[1\].*?#', 'end');
    Header = Header( Indices(end) : end );
    Index = regexp(Header, '# \[2\]');
    tokens = regexp(Header(Index:end), ...
                    '# \[2\] = (.*?)#', 'tokens');
    String = char(tokens{1});
    PossibleWaveformTypes = ...
        {'F{rMPsi4}', 'F{Psi4}', 'F{rhDot}', 'F{hDot}', ...
         'F{rhOverM}', 'F{h}', 'rMPsi4', 'Psi4', 'rhDot', 'hDot', ...
         'rhOverM', 'h'};
    for k = 1:length(PossibleWaveformTypes);
        t = PossibleWaveformTypes{k};
        if(~isempty(regexpi(String, t)));
            Type = t;
            return;
        end;
    end;
    
end % function GetType


function [LM ThetaPhi] = GetLMOrThetaPhi(FileName, Header)
    LM = [];
    ThetaPhi = [];
    
    %%% Strip the path from the FileName
    FileNameReg = regexp(FileName, '.*\/(.*)', 'tokens');
    if(length(FileNameReg)>0);
        FileName = char(FileNameReg{1});
    end;
    
    %%% Look for the information in the FileName.
    if(~isempty(regexpi(FileName, 'z-axis')) || ...
       ~isempty(regexpi(FileName, 'zaxis')));
        ThetaPhi = [0 0];
        return;
    end;
    if(~isempty(regexpi(FileName, '_Theta.*_Phi.*')));
        tokens = regexpi(FileName, '_Theta(.*)_Phi(.*).dat', 'tokens');
        ThetaPhi = str2double(char(tokens{1}))';
        return;
    end;
    if(~isempty(regexpi(FileName, '_L[0-9]*_M[-0-9]*')));
        tokens = regexpi(FileName, '_L([0-9]*)_M([-0-9]*)', 'tokens');
        LM = str2num(char(tokens{1}))';
        return;
    end;
    
    %%% Look for the information in the Header
    if(strcmp(Header{1,1},'Empty header'));
      warning('Empty header when looking for angle information');
      return;
    end;
    Header = char(Header)';
    Header = Header(:)';
    Indices = regexp(Header, '# \[1\].*?#', 'end');
    Header = Header( Indices(end) : end );
    Indices = regexp(Header, '# \[[^\]]*[02468]\]');
    for Ind = Indices;
        tokens = regexp(Header(Ind:end), ...
                        '# \[.*?[02468]\] = (.*?)#', 'tokens');
        String = char(tokens{1});
        if(~isempty(regexpi(String, 'z-axis')) || ...
           ~isempty(regexpi(String, 'zaxis')) );
            ThetaPhi = [ThetaPhi; [0 0]];
        end;
        if(~isempty(regexpi(String, '\(theta=.*phi=.*\)')));
            tokens = regexpi(String, ...
                             ['theta=([.eE+-0-9]*).*' ...
                              'phi=([.eE+-0-9]*)'], ...
                             'tokens');
            tp = str2num(char(tokens{1}))';
            ThetaPhi = [ThetaPhi; [tp(1) tp(2)]];
        end;
        if(~isempty(regexpi(String, '\([0-9]*,[-0-9]*\)')));
            tokens = regexpi(String, ...
                             '.*\(([0-9]*)[, ]*([-0-9]*)\)', ...
                             'tokens');
            lm = str2num(char(tokens{1}))';
            LM = [LM; [lm(1) lm(2)]];
        end;
        if(~isempty(regexpi(String, '\(l=.*m=.*\)')));
            tokens = regexpi(String, 'l=([0-9]*).*m=([-0-9]*)', ...
                             'tokens');
            lm = str2num(char(tokens{1}))';
            LM = [LM; [lm(1) lm(2)]];
        end;
    end;
    
end % function GetLMOrThetaPhi


function P = Psi(M, eta, f, pNOrder)
    
    G = 6.67259 * 10^-11;    % meters^3 kilograms^-1 seconds^-2
    MSun = 1.98892 * 10^30;  % kilograms
    c = 299792458;           % meters / second
    r = 3.08568025 * 10^22;  % meters;
    gamma = -psi(1);         % Euler's gamma constant;
    
%     warning(['This function is missing "beta" (the spin-orbit ' ...
%              'coupling) because I assume it is zero.']);
    beta = 0;
    
    if(pNOrder>=4.0); % "Extended" pN
        c40 = 3923.0;
    else;
        c40 = 0.0;
    end;
    if(pNOrder>=3.5);
        c35 = ...
            pi*(77096675.0/254016.0 + 378515.0*eta/1512.0 ...
                - 74045.0*eta*eta/756.0);
    else;
        c35 = 0.0;
    end;
    if(pNOrder>=3.0);
        c30 = (11583231236531.0/4694215680.0 ...
               - 640.0*pi*pi/3.0 - 6848*gamma/21.0) ...
              + eta*(-15335597827.0/3048192.0 ...
                     + 2255.0*pi*pi/12.0 - 47324.0/63.0 ...
                     - 7948.0/9.0) ...
              + eta*eta*76055.0/1728.0 ...
              - eta*eta*eta*127825.0/1296.0;
    else;
        c30 = 0.0;
    end;
    if(pNOrder>=2.5);
        c25a = pi*(38645.0/756.0 - 65.0*eta/9.0);
        c25b = 0;
    else;
        c25a = 0.0;
        c25b = 0.0;
    end;
    if(pNOrder>=2.0);
        c20 = 15293365.0/508032.0 ...
              + eta*(27145.0/504.0 + eta*3085.0/72.0);
    else;
        c20 = 0.0;
    end;
    if(pNOrder>=1.5);
        c15 = -4.0*(4.0*pi - beta);
    else;
        c15 = 0.0;
    end;
    if(pNOrder>=1.0);
        c10 = 3715.0/756.0 + eta*55.0/9.0;
    else;
        c10 = 0.0;
    end;
    c0 = 3.0/(eta*128.0);
    
    OneOverx = (pi*M*f*G/c^3).^(-1./3.);
    v0 = (pi*M*min(f)*G/c^3).^(1./3.);
    if(v0==0);
        v0 = (pi*M*min(diff(f))*G/c^3).^(1./3.);
    end;
    
    P = c0*OneOverx.*...
        (c20 + ...
         OneOverx.*(c15 + OneOverx.*(c10+OneOverx.*OneOverx))) + ...
        c0*(c25a*(1.0 + 3.0*log(1.0./(OneOverx*v0))) + ...
            c25b*log(1.0./(OneOverx*v0))) + ...
        c0*(c30-6848.0*log(4.0./OneOverx)/21.0).*(1.0./OneOverx) + ...
        c0*c35*(1.0./(OneOverx.*OneOverx)) + ...
        c0*c40*(-1.)*log(OneOverx).*...
        (1.0./(OneOverx.*OneOverx.*OneOverx));
    
end % function Psi
