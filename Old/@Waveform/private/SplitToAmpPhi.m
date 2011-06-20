function [Amp Phi] = SplitToAmpPhi(Complex)
    Amp = abs(Complex);
    Phi = Amp;
    for k = 1:size(Phi,2);
        Phi(:,k) = unwrap(angle(Complex(:,k)));
    end;
end
