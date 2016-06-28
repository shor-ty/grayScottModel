
//- Equation for species A
{
    fvScalarMatrix AEqn
    (
        fvm::ddt(A)
     ==
        Da * fvm::laplacian(A)
      - C * fvm::Sp(B*B, A)
      + f
      - fvm::Sp(f, A)
    );

    AEqn.solve();
}
