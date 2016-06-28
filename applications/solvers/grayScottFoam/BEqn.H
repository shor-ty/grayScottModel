
//- Equation for species B
{
    fvScalarMatrix BEqn
    (
        fvm::ddt(B)
     ==
        Db * fvm::laplacian(B)
      + C * fvm::Sp(A*B, B)
      - fvm::Sp(f, B)
      - fvm::Sp(k, B)
    );

    BEqn.solve();
}
