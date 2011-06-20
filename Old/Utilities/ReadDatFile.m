% Reads a data file.  If there is just one input argument, the data is
% assumed to have a first column of time; subsequent even columns are
% returned as ColA; subsequent odd columns are returned as ColB; if there
% is an even number of columns, ColB has zeros in its last column.
%
% If there are two input arguments, and the second one is 'Radius', the
% data is assumed to be a column of time, next to a column of radius.

function varargout = ReadDatFile(varargin)

FileName = varargin{1};

% Check to see that we can read the file
File = fopen(FileName);
if (File == -1)
    error(strcat('Cannot open "', FileName, '" for reading'));
end
fclose(File);


try % This is just here to suggest a solution in the event of failure

switch nargin
  case 1
    NewData = importdata(FileName);
    if(strcmp(class(NewData),'double'));
        try
            Time = NewData(:,1);
        catch
            NewData = importdata(FileName,' ');
            Time = NewData(:,1);
        end
        Size = size(NewData,2);
        ColA = NewData(:,2:2:Size);
        if(mod(Size,2)==1)
            ColB = NewData(:,3:2:Size);
        else
            ColB = [NewData(:,3:2:Size) ...
                    zeros(size(NewData,1),1)];
        end
        Header = cell(1,1);
        Header{1} = 'Empty header';
    else;
        try
            Time = NewData.data(:,1);
        catch
            NewData = importdata(FileName,' ');
            Time = NewData.data(:,1);
        end
        Size = size(NewData.data,2);
        ColA = NewData.data(:,2:2:Size);
        if(mod(Size,2)==1)
            ColB = NewData.data(:,3:2:Size);
        else
            ColB = [NewData.data(:,3:2:Size) ...
                    zeros(size(NewData.data,1),1)];
        end
        Header = NewData.textdata;
    end;
    varargout{1} = Time;
    varargout{2} = ColA;
    varargout{3} = ColB;
    varargout{4} = Header;
    
  case 2
    if(strcmpi(varargin{2},'Radius') || strcmpi(varargin{2},'Other'))
        NewData = importdata(FileName);
        try
            Time = NewData.data(:,1);
        catch
            NewData = importdata(FileName,' ');
            Time = NewData.data(:,1);
        end
        Radius = NewData.data(:,2);
        Header = NewData.textdata;
        varargout{1} = Time;
        varargout{2} = Radius;
        if(nargout==3)
            varargout{3} = Header;
        end
    else
        error('Do not understand input arguments\n\t%s\n\t%s', ...
              varargin{1}, varargin{2});
    end
    
end

catch
    error(['Problem reading the input file %s\nThere may be an ' ...
           'unprotected number in the header (each should be ' ...
           'inside parentheses or brackets).'],FileName);
end

end
