function OmegaDotOut = SmoothedOmegaDot(W, Order, WindowLength)
    
    [TimeOut OmegaDotOut] = DifferentiateDataSet(W.Time, (DifferentiateDataSet(W.Time, W.Phi)));
    OmegaDotOut = interp1(TimeOut, OmegaDotOut, W.Time);
    Dt = (W.Time(end)-W.Time(1)) / (length(W.Time)-1);
    
    [b, g] = sgolay(Order, WindowLength);
    HalfWin  = ((WindowLength+1)/2) - 1;
    for n = (WindowLength+1)/2 : length(W.Phi)-(WindowLength+1)/2;
        % 1st derivative
        %OmegaDotOut(n) =   dot(g(:,2), W.Phi(n - HalfWin: n + HalfWin)) / Dt;
        % 2nd derivative
        OmegaDotOut(n) = 2*dot(g(:,3)', W.Phi(n - HalfWin: n + HalfWin))' / (Dt*Dt);
    end;
    
end
