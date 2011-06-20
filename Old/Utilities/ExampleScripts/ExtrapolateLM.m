
WaveformDir = '08Jan04aEv1';
Lev = 'Lev5';

ADMMass = 2.229264043530484684652;
AHMassA = 1.0945067450501402;
AHMassB = 1.0945067450502433;
ChMassA = 1.12322374934066;
ChMassB = 1.12322374934082;
AHMass = AHMassA + AHMassB;
ChMass = ChMassA + ChMassB;




OutputBase = [WaveformDir '_' Lev '_N%d'];


R = [0075 0079 0080 0083 0088 0093 0099 0106 0114 0124 0134 0147 ...
     0160 0163 0183 0207 0240 0285 0320 0350]; % 0040
Directory = ['/Users/boyle/Research/Waveforms/Spinning/' ...
             WaveformDir '/' Lev '/'];
LapseName = [Directory 'LapseSurfaceIntegral_R%04.0fm.dat'];
AreaName = [Directory 'SurfaceArea_R%04.0fm.dat'];
WaveformName = [Directory 'rPsi4_R%04.0fm_U8+.dat'];


%% Read the data in
Ws = cell(length(R),1);
l=1;
for r=R;
    r
    Temp = Waveform(sprintf(WaveformName,r),'ReIm',-666);
    Temp = Temp(3);
    Temp.Type = 'rMPsi4';
    
    % Read in Lapse and Area
    [LapseTime Lapse] = ReadDatFile(sprintf(LapseName,r),'Radius');
    [AreaTime Area] = ReadDatFile(sprintf(AreaName,r),'Radius');
    
    % Interpolate to Temp.Time
    Lapse = interp1(LapseTime,Lapse,Temp.Time);
    Area = interp1(AreaTime,Area,Temp.Time);
    
    % Get the areal radius in code units
    ArealRadius = sqrt(Area/(4*pi));
    
    % Divide Lapse by Area, subtract sqrt(1-2M/r)-1,
    % integrate, and add to time
    Lapse = 1 + Lapse./Area - sqrt(1-2*ADMMass./ArealRadius);
    DeltaT = cumtrapz(Temp.Time,Lapse);
    Temp.Time = DeltaT;
    
    % Do tortoise-coordinate retardation
    Temp.Radius = ArealRadius;
    Temp = Offset('Tortoise', Temp, ADMMass);
    
    Ws{l} = Scale(Temp, ChMass);
    if(l>1);
        Ws{l} = MatchPhases(Ws{l}, Ws{l-1});
    end;
    l = l+1;
end;


%% Run the extrapolations
disp('Running extrapolations');
Ns = [1 2 3 4 5];
for n = Ns;
    disp(sprintf('Working on %d.', n));
    Temp = Extrapolate(Ws, n);
    assignin('base', sprintf('W%d', n), Temp);
    Output(Temp, [Directory sprintf(OutputBase, n)], ...
           'ReIm', '(t-r*)/m');
    disp(sprintf('Finished %d.\n', n));
end;
