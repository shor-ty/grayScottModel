
//- Equation for species B
{
    fvScalarMatrix BEqn
    (
        fvm::ddt(B)
     ==
        fvm::laplacian(Db, B)
      + C * fvm::Sp(A*B, B)
      - fvm::Sp(f, B)
      - fvm::Sp(k, B)
    );

    BEqn.solve();
}
