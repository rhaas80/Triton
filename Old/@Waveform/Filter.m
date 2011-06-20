% Wo = Filter(B, A, Wi, ...)
% Wo = Filter(Wi, N, wn, ...)
% 
% Wo = Filter(..., 'StartTime', StartTime, ...)
% Wo = Filter(..., 'EndTime', EndTime, ...)
% Wo = Filter(..., 'ResampleFactor', Factor, ...)
% Wo = Filter(..., 'ReIm', ...)
% 
%   This function returns a copy of the input Waveform,
%   filtering the Amp and Phi data.  The first form is
%   analogous to the input of the 'filtfilt' function, taking
%   filter-parameter vectors B and A, and using them to filter
%   the data in Wi.  The second form feeds the arguments N and
%   wn into the 'butter' function, and uses the
%   filter-parameter vectors it returns.  Note that, Matlab
%   essentially assumes that the Time parameter is uniform.
%   Thus, if Wi's Time parameter is non-uniform (e.g., finer
%   near the merger), data in the finer region will have a
%   lower effective filter frequency.
%   
%   The optional arguments 'StartTime' and 'EndTime' specify
%   times at which the filter should begin and end,
%   respectively.  These just feed the filtered and input
%   Waveforms through Stitch, using the input Waveform before
%   StartTime, and after EndTime, and the filtered Waveform in
%   between.  If StartTime or EndTime has two elements, the
%   transition is made smoothly.  (See the documentation for
%   'Stitch'.)  If either argument is absent, the filtering
%   simply begins at the beginning of the data, or ends at the
%   end.
%   
%   The optional argument 'ResampleFactor' refines the data by
%   Factor, by interpolating the Amp and Phi data (via the
%   'Interpolate' function) to a Time grid that is Factor
%   times finer.  (If Factor is less than 1, the data becomes
%   less fine.)
%   
%   Finally, the option 'ReIm' filters the real and imaginary
%   data, rather than the Amp and Phi data.

function Wo = Filter(varargin)
    
    %%% Process the input arguments
    StartTime = [-10^200 -10^200];
    EndTime = [10^200 10^200];
    ResampleFactor = 1;
    ReIm = false;
    if(isa(varargin{1}, 'Waveform'));
        Wo = varargin{1};
        [B A] = butter(varargin{2}, varargin{3});
        PostProcessing = sprintf('this = Filter(this, %d, %.16g', ...
                                 varargin{2}, varargin{3});
    elseif(isa(varargin{3}, 'Waveform'));
        Wo = varargin{3};
        B = varargin{1};
        A = varargin{2};
        Wo.PostProcessing = ...
            [Wo.PostProcessing; ...
             {['B = [' sprintf('%.16g ', B(1:end-1)) ...
              sprintf('%.16g];', B(end))]}; ...
             {['A = [' sprintf('%.16g ', A(1:end-1)) ...
              sprintf('%.16g];', A(end))]}];
        PostProcessing = 'this = Filter(B, A, this';
    else;
        error('Don''t understand input arguments.');
    end;
    for k = 4:nargin;
        if(isa(varargin{k}, 'char'));
            switch lower(varargin{k})
              case 'reim'
                ReIm = true;
                PostProcessing = [PostProcessing ', ''ReIm'''];
              case 'resamplefactor'
                ResampleFactor = varargin{k+1};
                PostProcessing = ...
                    [PostProcessing ', ''ResampleFactor'', ' ...
                     sprintf('%.16g', ResampleFactor)];
              case 'starttime'
                StartTime = varargin{k+1};
                if(numel(StartTime)==1);
                    PostProcessing = ...
                        [PostProcessing ', ''StartTime'', ' ...
                         sprintf('%.16g', StartTime)];
                    StartTime = [StartTime StartTime];
                elseif(numel(StartTime)==2);
                    PostProcessing = ...
                        [PostProcessing ', ''StartTime'', ' ...
                         sprintf('[%.16g %.16g]', StartTime)];
                else;
                    error('Too many elements in StartTime.');
                end;
              case 'endtime'
                EndTime = varargin{k+1};
                if(numel(EndTime)==1);
                    PostProcessing = ...
                        [PostProcessing ', ''EndTime'', ' ...
                         sprintf('%.16g', EndTime)];
                    EndTime = [EndTime EndTime];
                elseif(numel(EndTime)==2);
                    PostProcessing = ...
                        [PostProcessing ', ''EndTime'', ' ...
                         sprintf('[%.16g %.16g]', EndTime)];
                    %EndTime = [EndTime EndTime];
                else;
                    error('Too many elements in EndTime.');
                end;
              otherwise
                error('Don''t understand option %s.', varargin{k});
            end;
        elseif(isa(varargin{k}, 'double'));
            % skip
        else;
            error('Don''t understand option number %d.', k);
        end;
    end;
    
    %%% If nothing needs to be done, return
    if(StartTime(1)>EndTime(2) || StartTime(1)>Wo.Time(end) || ...
       EndTime(2)<Wo.Time(1));
        warning(['No filtering done because input StartTime=' ...
                 '[%.16g %.16g]\nand EndTime=[%.16g %.16g] ' ...
                 'request times outside of the Waveform''s ' ...
                 'Time [%.16g %.16g].'], ...
                StartTime, EndTime, Wo.Time(1), Wo.Time(end));
        return;
    end;
    
    %%% Interpolate to finer grid, if necessary
    if(ResampleFactor~=1);
        Time = ...
            interp1(1:length(Wo.Time), Wo.Time, ...
                    (ResampleFactor : ...
                     ResampleFactor*length(Wo.Time)) ...
                    / ResampleFactor )';
        Wo = Interpolate(Wo, Time);
    end;
    Wi = Wo;
    
    %%% Do the filtering
    if(ReIm);
        [Wo.Amp Wo.Phi] = SplitToAmpPhi(filtfilt(B, A, Complex(Wo)));
    else;
        Wo.Amp = filtfilt(B, A, Wo.Amp);
        Wo.Phi = filtfilt(B, A, Wo.Phi);
    end;
    
    %%% If necessary, Stitch the filtered and input Waveforms
    if(StartTime(2)>-10^200 && StartTime(1)<Wo.Time(1));
        warning(['StartTime(1)=%.16g is earlier than the ' ...
                 'beginning of the Waveform at %.16g.'], ...
                StartTime(1), Wo.Time(1));
    end;
    if(StartTime(2)>Wo.Time(1));
        Wo = Stitch(Wi, Wo, StartTime(1), StartTime(2), [], ...
                    'NoPostProcessingChange');
    end;
    if(EndTime(1)<10^200 && EndTime(2)>Wo.Time(end));
        warning(['EndTime(2)=%.16g is later than the ' ...
                 'end of the Waveform at %.16g.'], ...
                EndTime(2), Wo.Time(end));
    end;
    if(EndTime(1)<Wo.Time(end));
        Wo = Stitch(Wo, Wi, EndTime(1), EndTime(2), [], ...
                    'NoPostProcessingChange');
    end;
    
    %%% Record what we've done
    Wo.PostProcessing = [Wo.PostProcessing; {[PostProcessing ');']}];
    
end
