% To = TimeIntersection(T1, T2)
% To = TimeIntersection(T1, T2, MinStep)
% 
%   This function returns a vector with the intersetcion of
%   the times in the two input vectors.  For times covered by
%   both data sets, the minimum time step at each time is used
%   to construct a common set of times.
%   
%   Either input may also be a Waveform object, in which case
%   the Time data from that object is used.

function To = TimeIntersection(varargin)
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
        mint = max(min1, min2);
        max1 = max(T1);
        max2 = max(T2);
        maxt = min(max1, max2);
        to = [T1(find(T1>=min2 & T1<=max2)); T2(find(T2>=min1 & T2<=max1))];
        if(length(to)>0);
            I = 1;
            to(1) = mint;
            I1 = find(T1>mint, 1, 'first');
            I2 = find(T2>mint, 1, 'first');
            while(to(I)<maxt);
                while(T1(I1)<=to(I) && I1<length(T1)-1); I1=I1+1; end;
                while(T2(I2)<=to(I) && I2<length(T2)-1); I2=I2+1; end;
                dt = max( min(T1(I1+1)-T1(I1), T2(I2+1)-T2(I2)), MinStep);
                to(I+1) = to(I) + dt;
                I = I+1;
            end;
            To = to(1:I-1);
        else;
            To = [];
        end;
%     end;
end

