%% This script uses the technique described in the
%% equal-mass nonspinning merger paper


%% These numbers are for 0093g only
%% Note that the data in the input files used here are in
%%   units of the ADM mass.  The output will be rescaled 
%%   to units of IRRMass/ADMMass.
ADMMass = 2.062309278958920799596;    %in KIPS, for 0093g
IRRMass = 2.0*1.03904905570956374;    %in KIPS, for 0093g;

WaveformDir = '0093g_L6_L5a_L5cOct102008';

Directory = ['/data2/boyle/Waveforms/' WaveformDir '/'];
OutputBase = [Directory '../Extrapolated/' WaveformDir ...
              '_WithSecondLapseTrick_N%d'];

LapseName = [Directory 'LLapseSurfaceIntegral_R%04.0fm.dat'];
AreaName = [Directory 'LSurfaceArea_R%04.0fm.dat'];
WaveformName = [Directory 'LrEadmPsi4_R%04.0fm.dat'];

R = [0075 0085 0100 0110 0130 0140 0150 0160 0170 0180 0190 ...
     0200 0210 0225]; % 0050 0060

Ws = cell(length(R),1);
l=1;
for r=R;
    Temp = Waveform(sprintf(WaveformName,r), 'ReIm', -666);
    Temp = Temp(1);
    Temp.Type = 'rMPsi4';
    
    % Read in Lapse and Area-->ArealRadius
    [LapseTime Lapse] = ReadDatFile(sprintf(LapseName,r),'Radius');
    [AreaTime Area] = ReadDatFile(sprintf(AreaName,r),'Radius');
    
    % Interpolate to Temp.Time
    Lapse = interp1(LapseTime,Lapse,Temp.Time);
    Area = interp1(AreaTime,Area,Temp.Time);
    ArealRadius = sqrt(Area/(4*pi));
    
    % Divide Lapse by Area, and by sqrt(1-2M/r),
    % integrate, and add to time
    Lapse = (Lapse./Area) ./ sqrt(1-2./ArealRadius);
    DeltaT = cumtrapz(Temp.Time,Lapse);
    Temp.Time = Temp.Time(1) + DeltaT;
    
    % Do tortoise-coordinate retardation (ADMMass = 1 in the
    % current units)
    Temp.Radius = ArealRadius;
    Temp = Offset('Tortoise', Temp, 1);
    
    Ws{l} = Scale(Temp, IRRMass/ADMMass);
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
    Output(Temp, sprintf(OutputBase, n), ...
           'ReIm', '(t-r*)/m');
    disp(sprintf('Finished %d.\n', n));
end;
