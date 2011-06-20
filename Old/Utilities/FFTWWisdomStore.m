% FFTWWisdomStore
% FFTWWisdomStore(Directory)
% FFTWWisdomStore(Directory, FileName)
% 
%   This function stores the current FFTW wisdom in a text
%   file.  Recalling this later makes FFTs more efficient.  By
%   default, the wisdom is stored in the current directory as
%   'FFTWWisdom'.  If one argument is present, that is assumed
%   to be the directory in which to put that file.  If two
%   arguments are present, the second is assumed to be the
%   file name.
%   
%   Note that "fftw('planner', 'measure')", or something
%   similar, should be used before performing any FFTs to make
%   this relevant.
%   
%   This data can be reloaded later, using FFTWWisdomRecall.

function FFTWWisdomStore(varargin)
    Dir = './';
    FileName = 'FFTWWisdom';
    if(nargin>=1);
        Dir = varargin{1};
    end;
    if(nargin==2);
        FileName = varargin{2};
    end;
    STR = fftw('dwisdom');
    FID = fopen([Dir FileName], 'w');
    fprintf(FID, '%s', STR);
    fclose(FID);
end
