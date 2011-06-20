%% This script extrapolates with the methods of
%% arXiv:0905.3177.  Specifically, it uses a retarded time
%% given by Eq. (14) of that paper.



%% These numbers are for 0093g only
ADMMass = 2.062309278958920799596;    %in KIPS, for 0093g
IRRMass = 2.0*1.03904905570956374;    %in KIPS, for 0093g;
%% Please note that the dat files have not been rescaled by mass;
%%   they need to be rescaled by IRRMass.

WaveformDir = '0093g_L7_Feb09';

Directory = ['/home/boyle/' WaveformDir '/'];
%Directory = ['/Users/boyle/Research/Data/' WaveformDir '/'];
OutputBase = [Directory 'Extrapolated/ExtrapN%d'];

LapseName = [Directory 'LapseSurfaceIntegral_R%04.0fm.dat'];
AreaName  = [Directory 'SurfaceArea_R%04.0fm.dat'];
WaveformName = [Directory 'rPsi4_R%04.0fm_U8+.dat'];

%0050 0060 
R = [0075 0085 0100 0110 0130 0140 0150 0160 0170 0180 0190 0200 0210 0225];

Ws = cell(length(R),1);
k=1;


%% Loop over all the radii, getting and adjusting the input data
for r=R;
    disp(sprintf('Reading Waveform %d of %d.', k, length(R)));
    % Read the waveform into a temporary Waveform
    Temp = Waveform(sprintf(WaveformName,r), 'ReIm', -666);
    
    %% Get rid of some L,M components
    Temp = Temp(find(Temp.LM(:,2)>=0)); % Keep only m>=0
    %Temp = Temp([3 5]); % Keep only (l,m)=[(2,0) (2,2)];
    %Temp = Temp([5 21 11 19 45 31 43 77]); % Keep only (l,m)=(2,2), (4,4), (3,2), (4,2), (6,6), (5,4), (8,8)
    
    %% Make sure M=0 components are dealt with properly
    M0Components = find(Temp.LM(:,2)==0);
    if(~isempty(M0Components));
        for M0Component = M0Components;
            Temp.Amp(:,M0Component) = Temp.Amp(:,M0Component) .* cos(Temp.Phi(:,M0Component));
            Temp.Phi(:,M0Component) = 0*Temp.Phi(:,M0Component);
        end;
    end;
    
    % Read in Lapse and Area
    [LapseTime Lapse] = ReadDatFile(sprintf(LapseName,r),'Radius');
    [AreaTime Area] = ReadDatFile(sprintf(AreaName,r),'Radius');
    
    % Interpolate to make sure everything's at the same time
    Lapse = interp1(LapseTime,Lapse,Temp.Time);
    Area = interp1(AreaTime,Area,Temp.Time);
    Lapse = Lapse ./ Area;
    Temp.Radius = sqrt(Area/(4*pi));
    
    % Do the calculation to get retarded time, ensuring that
    %   the initial time does not change.
    Temp.Time = Temp.Time(1) + ...
        cumtrapz(Temp.Time, ...
                 Lapse ./ sqrt(1-2*ADMMass./(Temp.Radius)));
    
    % Do tortoise-coordinate retardation
    Temp = Offset('Tortoise', Temp, ADMMass);
    
    % Rescale and save the data as Ws{k}
    Temp.Type = 'rMPsi4'; % My script assumes 'rPsi4' from the
                          % filename
    Ws{k} = Scale(Temp, IRRMass);
    
    % Make sure this waveform's phase matches the previous
    % one's at the halfway time.
    if(k>1);
        Ws{k} = MatchPhases(Ws{k}, Ws{k-1});
    end;
    
    % Move on to the next one
    k = k+1;
end;


%% Run the extrapolations
disp('Running extrapolations');
Ns = [2 3 4 5];
%Ns = [1 2 3 4 5];
for n = Ns;
    disp(sprintf('Working on N=%d.', n));
    Temp = Extrapolate(Ws, n);
    assignin('base', sprintf('rMPsi4_N%d', n), Temp);
    Output(Temp, sprintf(OutputBase, n), ...
           'ReIm', '(t-r*)/M');
    disp(sprintf('Finished %d.\n', n));
end;


%% Quick convergence test
for k = 1:(length(Ns)-1);
    Temp = eval(sprintf('rMPsi4_N%d/rMPsi4_N%d', Ns(k), Ns(k+1)));
    assignin('base', sprintf('rMPsi4_N%d_N%d', Ns(k), Ns(k+1)), ...
             Temp);
    Output(Temp, sprintf([Directory 'Extrapolated/Convergence_N%d_N%d'], ...
                         Ns(k), Ns(k+1)), 'AmpPhi', '(t-r*)/M');
end;
