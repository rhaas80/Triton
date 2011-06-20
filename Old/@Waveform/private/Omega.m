function varargout = Omega(W)

[TimeOut OmegaOut] = DifferentiateDataSet(W.Time, W.Phi);
if(nargout==2);
    varargout{1} = TimeOut;
    varargout{2} = OmegaOut;
else;
    varargout{1} = interp1(TimeOut, OmegaOut, W.Time);
end;
