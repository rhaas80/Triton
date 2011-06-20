% FFTWWisdomRecall
% FFTWWisdomRecall(Directory)
% FFTWWisdomRecall(Directory, FileName)
% 
%   This function recalls FFTW wisdom from a text file.
%   Recalling this data can make FFTs more efficient, if FFTs
%   of the same length need to be calculated later.  By
%   default, the wisdom is stored in the current directory as
%   'FFTWWisdom'.  If one argument is present, that is assumed
%   to be the directory in which to put the file is found.  If two
%   arguments are present, the second is assumed to be the
%   file name.
%   
%   This data can be saved, using FFTWWisdomStore.

function FFTWWisdomRecall(varargin)
    Dir = './';
    FileName = 'FFTWWisdom';
    if(nargin>=1);
        Dir = varargin{1};
    end;
    if(nargin==2);
        FileName = varargin{2};
    end;
    FID = fopen([Dir FileName]);
    if (FID ~= -1);
        File = textscan(FID, '%s', 'Delimiter', '\n');
        File = char(File{1})';
        fftw('dwisdom', File);
    end;
    fclose(FID);
end
