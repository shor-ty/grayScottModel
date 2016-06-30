//- Equation for species A implicit
if (implicit)
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
//- Equation for species A explicit 
else
{
    fvScalarMatrix AEqn
    (
        fvm::ddt(A)
     ==
        Da * fvc::laplacian(A)
      - C * B*B*A
      + f * (1-A)
    );

    AEqn.solve();
}
