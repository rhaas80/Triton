function OmegaOut = SmoothedOmega(W, Order, WindowLength)
    
    [TimeOut OmegaOut] = DifferentiateDataSet(W.Time, W.Phi);
    OmegaOut = interp1(TimeOut, OmegaOut, W.Time);
    Dt = (W.Time(end)-W.Time(1)) / (length(W.Time)-1);
    
    [b, g] = sgolay(Order, WindowLength);
    HalfWin  = ((WindowLength+1)/2) - 1;
    for n = (WindowLength+1)/2 : length(W.Phi)-(WindowLength+1)/2;
        % 1st derivative
        OmegaOut(n) =   dot(g(:,2), W.Phi(n - HalfWin: n + HalfWin)) / Dt;
        % 2nd differential
        %OmegaDotOut(n) = 2*dot(g(:,3)', W.Phi(n - HalfWin: n + HalfWin))' / (Dt*Dt);
    end;
    
end
