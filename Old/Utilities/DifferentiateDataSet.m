% dydx = DifferentiateDataSet(x, y)
%   
%   Input should be a vector x, and a matrix y, with the same
%   length in dimension 1.  In this case, the argument is
%   (x,y), and dy/dx is returned.
% 
%   Alternatively, input should be a single matrix.  The first
%   column is considered to be time; remaining columns are
%   considered to be the data to be differentiated. 
% 
%   Output is the differentiated data, interpolated to the
%   input X, with NaNs removed.

function varargout = DifferentiateDataSet(varargin)

if nargin==2
    XDiff = varargin{1}(2:end-1);
    if(min(diff(XDiff))/max(diff(XDiff))>1.001 || ...
       min(diff(XDiff))/max(diff(XDiff))<0.999);
        warning(['This function has not been tested on ' ...
                 'non-uniform grids, but this grid appears to ' ...
                 'be non-uniform.']);
    end;
    if(size(varargin{2},2)>size(varargin{2},1));
        Transpose = true;
        YDiff = varargin{2}(:,2:end-1)';
    else;
        Transpose = false;
        YDiff = varargin{2}(2:end-1,:);
    end;
    for i = 2:(size(varargin{2},1)-1);
        YDiff(i-1,:) = (varargin{2}(i+1,:)-varargin{2}(i-1,:)) / (varargin{1}(i+1)-varargin{1}(i-1));
    end;
    
    if(sum(isnan(YDiff))>0)
        [XDiff YDiff] = RemoveNANs(XDiff,YDiff);
    end
    DyDx = interp1(XDiff,YDiff,varargin{1}, 'linear', 'extrap');
    if nargout==2
        varargout{1} = varargin{1};
        varargout{2} = DyDx;
    elseif nargout==1
        varargout{1} = DyDx;
    else
        error('Wrong number of output arguments.');
    end;
    
elseif nargin==1
    XDiff = varargin{1}(2:end-1,1);
    YDiff = varargin{1}(2:end-1,2:end);
    
    for i = 2:(size(varargin{1},1)-1);
        YDiff(i-1,:) = (varargin{1}(i+1,2:end)-varargin{1}(i-1,2:end)) / (varargin{1}(i+1,1)-varargin{1}(i-1,1));
    end;

    DyDx = interp1(XDiff,YDiff,varargin{1}(:,1),'linear','extrap');
    
    if nargout==2
        varargout{1} = varargin{1}(:,1);
        varargout{2} = DyDx;
    elseif nargout==1
        varargout{1} = DyDx;
    else
        error('Wrong number of output arguments.');
    end;

else
    error('Wrong number of input arguments.');
end;


function [Xo Yo] = RemoveNANs(Xi, Yi)

Xo = zeros(1,(size(Yi,2)-sum(isnan(Yi))));
Yo = zeros((size(Yi,1)-sum(isnan(Yi))),size(Yi,2));

j = 1;
for i = 1:length(Xi)
    if(sum(isnan(Yi(i,:)))==0)
        Xo(j) = Xi(i);
        Yo(j,:) = Yi(i,:);
        j = j+1;
    end
end
Xo = Xo';
