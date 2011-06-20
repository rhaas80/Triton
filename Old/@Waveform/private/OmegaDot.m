function varargout = OmegaDot(W)

[TimeOut OmegaDotOut] = DifferentiateDataSet(W.Time, Omega(W));
if(nargout==2);
    varargout{1} = TimeOut;
    varargout{2} = OmegaDotOut;
else;
    varargout{1} = interp1(TimeOut, OmegaDotOut, W.Time);
end;
