%% This is crucial to being able to use the Waveform class
addpath('/Users/boyle/Research/Current/WaveExtrapolation')
addpath('/Users/boyle/Research/Current/WaveExtrapolation/Utilities')

%% A few defaults I like
format long g;
set(0,'defaulttextfontsize',18);  %% For figures
set(0,'defaultaxesfontsize',16);  %% For figures
set(0, 'DefaultFigurePosition', [1440-560, 360, 560, 450]); %% For figures

%% Save *all* past work to diaries (Matlab's command history is
%%   annoyingly short)
try;
    load '/Users/boyle/.matlab/diarynumber.mat';
catch;
    DiaryNumber = 1;
end;
FileName = sprintf('/Users/boyle/.matlab/diaries/diary%u', ...
                   DiaryNumber);
diary(FileName);
clear FileName;
DiaryNumber = 1+DiaryNumber;
save '/Users/boyle/.matlab/diarynumber.mat';
clear DiaryNumber;

%% Some constants that come in handy
% global EmailAddress; EmailAddress = 'boyle@astro.cornell.edu';
G = 6.67428 * 10^-11;    % meters^3 kilograms^-1 seconds^-2
MSun = 1.98892 * 10^30;  % kilograms
c = 2.99792458 * 10^8;   % meters / seconds
OneMegaparsec = 3.08568025 * 10^22;  % meters; (=1 megaparsec);
r = OneMegaparsec;
EulerGamma = -psi(1);

%% Make the screen look nice, and change to my Research directory
clc
cd '~/Research'
clc
