% To = TimeUnion(T1, T2)
% To = TimeUnion(T1, T2, MinStep)
% 
%   This function returns a time vector with the union of the
%   times in the two input vectors.  For regions in which only
%   one input T exists, the original data is returned; for
%   regions in which both exist, the minimum time step at each
%   time is used to construct a common set of times.  In
%   particular, in regions for which both time sets exist, the
%   returned data is just the output of the function 
%   TimeIntersection(T1, T2).
%   
%   Either input may also be a Waveform object, in which case
%   the Time data from that object is used.

function To = TimeUnion(varargin)
    T1 = varargin{1};
    T2 = varargin{2};
    if(nargin==3);
        MinStep = varargin{3};
    else;
        MinStep = 0;
    end;
    if(isa(T1, 'Waveform'));
        T1 = T1.Time;
    end;
    if(isa(T2, 'Waveform'));
        T2 = T2.Time;
    end;
    
%     if(length(T1)==length(T2) && sum(T1-T2)==0);
%         To = T1;
%     else;
        min1 = min(T1);
        min2 = min(T2);
        max1 = max(T1);
        max2 = max(T2);
        To = [T1(find(T1<(min2-MinStep))); T2(find(T2<(min1-MinStep))); TimeIntersection(T1, T2, MinStep); T1(find(T1>(max2+MinStep))); T2(find(T2>(max1+MinStep)))];
%     end;
end
