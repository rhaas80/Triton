% PSD = InitialLIGOPSD(f)
% PSD = InitialLIGOPSD(f, 'NoCutoffs')
% 
%   This function returns the analytic initial-LIGO design noise
%   curve S_n(|f|), with input argument f being the frequency or
%   set of frequencies on which to evaluate, in Hertz.
%   
%   Note that the Nyquist frequency (2048Hz) is hard coded,
%   which is probably the generally right thing to do.
%   However, the seismic wall at 40Hz is also hard coded,
%   which may not be the best thing generally.
%   
%   If the option 'NoCutoffs' is given, the seismic wall and
%   Nyquist frequency cutoffs will not be imposed.

function PSD = InitialLIGOPSD(varargin)
    
    f = varargin{1};
    
    x = abs(f)/150.0;
    PSD = (4.49*x).^(-56.0) + 0.16*x.^(-4.52) + 0.52 + 0.32*x.^2;
    PSD = PSD*9.0e-46;
    
    if(nargin==2 && strcmp(lower(varargin{2}), 'nocutoffs'));
        % Do nothing more
    elseif(nargin==2);
        error('Don''t understand input argument %s.', varargin{2});
    else;
        %%% Seismic wall
        PSD( find(f<40) ) = inf;
        %%% Nyquist frequency
        PSD( find(f>2048) ) = inf;
    end;
    
end
