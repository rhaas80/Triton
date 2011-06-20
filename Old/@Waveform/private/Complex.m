function ComplexQuantity = Complex(W)

ComplexQuantity = W.Amp .* exp(i*W.Phi);
