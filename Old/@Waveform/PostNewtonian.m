% Syntax changing!! This is just a test function as yet.

function W = PostNewtonian(W, phi, t, v, nu, L, M)
    
%     omega = DifferentiateDataSet(t', phi')';
%     psi = phi - (2*omega).*log(omega/1);
    
    W.LM = [L; M]';
    W.Radius = 0;
    W.Time = t';
    [W.Amp W.Phi] = Waveforms_LM(phi, t, v, nu, L, M);
    W.Type = 'rhOverM';
    
end
