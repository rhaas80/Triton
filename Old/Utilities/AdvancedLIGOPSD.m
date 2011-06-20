% PSD = AdvancedLIGOPSD(f)
% PSD = AdvancedLIGOPSD(f, 'NoCutoffs')
% 
%   This function returns the analytic advanced-LIGO design noise
%   curve S_n(|f|) referred to as "Bench 6.2", with input
%   argument f being the frequency or set of frequencies on
%   which to evaluate, in Hertz.
%   
%   Note that the Nyquist frequency (2048Hz) is hard coded,
%   which is probably the generally right thing to do.
%   However, the seismic wall at 10Hz is also hard coded,
%   which may not be the best thing generally.
%   
%   If the option 'NoCutoffs' is given, the seismic wall and
%   Nyquist frequency cutoffs will not be imposed.

function PSD = AdvancedLIGOPSD(varargin)
    
    f = varargin{1};
    PSD = f;
    
    PSD = 1.0e11 * f.^(-13+(f-10)/8);
    
    Indices = find(f>600);
    PSD(Indices) = 4.4e-12 * f(Indices).^2.2;
    
    Indices = find(f>330 & f<=600);
    PSD(Indices) = 0.0000468 * ...
        f(Indices).^(-0.409 + ((f(Indices)-258).^1.96)/941192) - 7e-7;
    
    Indices = find(f>85 & f<=330);
    PSD(Indices) = 0.00004 * f(Indices).^-0.408;
    
    Indices = find(f>26 & f<=85);
    PSD(Indices) = 16.9201 * f(Indices).^-3.86474 + 6.389e-6;
    
    Indices = find(f>12 & f<=26);
    PSD(Indices) = 40 * f(Indices).^-4.1;
    
    %%% Overall normalization
    PSD = PSD*2.8e-42;
    
    if(nargin==2 && strcmp(lower(varargin{2}), 'nocutoffs'));
        % Do nothing more
    elseif(nargin==2);
        error('Don''t understand input argument %s.', varargin{2});
    else;
        %%% Seismic wall
        PSD( find(f<10) ) = inf;
        %%% Nyquist frequency
        %PSD( find(f>2048) ) = inf;
    end;
    
end


%%% This is precisely what Larne sent me
function power = pow(a, b)
    power = a.^b;
end
function p = bench_62_adv_ligo_psd( f )
    
    if(f > 600);
        p = 4.4e-12 * pow(f,2.2);
    elseif(f > 330);
        p = 0.0000468 * pow(f,-0.409 + pow(f-258, 1.96)/941192) - 7e-7;
    elseif (f > 85);
        p = 0.00004 * pow(f,-0.408);
    elseif (f > 26);
        p = 16.9201  * pow(f,-3.86474) + 6.389e-6;
    elseif (f > 12);
        p = 40      * pow(f,-4.100);
    else;
        p = 1.0e11  * pow(f,-13 + (f-10)/8);
    end;
    
    p = 2.8e-42*p;
    
end
