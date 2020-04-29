//- Equation for species A implicit
if (implicit)
{
    fvScalarMatrix AEqn
    (
        fvm::ddt(A)
      + fvm::div(phi, A)
     ==
        fvm::laplacian(Da, A)
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
      + fvc::div(phi, A)
     ==
        fvc::laplacian(Da, A)
      - C * B*B*A
      + f * (1-A)
    );

    AEqn.solve();
}
