#ifndef QRDECOMPOSITION_HPP
#define QRDECOMPOSITION_HPP

#include "NumericalRecipes.hpp"

namespace WaveformUtilities {

  struct QRdcmp {
    Int n;
    MatDoub qt, r;
    Bool sing;
    QRdcmp(MatDoub_I &a);
    void solve(VecDoub_I &b, VecDoub_O &x);
    void qtmult(VecDoub_I &b, VecDoub_O &x);
    void rsolve(VecDoub_I &b, VecDoub_O &x);
    void update(VecDoub_I &u, VecDoub_I &v);
    void rotate(const Int i, const Doub a, const Doub b);
  };

}

#endif // QRDECOMPOSITION_HPP
