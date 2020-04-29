//- Equation for species B implicit
if (implicit)
{
    fvScalarMatrix BEqn
    (
        fvm::ddt(B)
      + fvm::div(phi, B)
     ==
        fvm::laplacian(Db, B)
      + C * fvm::Sp(A*B, B)
      - fvm::Sp(f, B)
      - fvm::Sp(k, B)
    );

    BEqn.solve();
}
//- Equation for species B explicit
else
{
    fvScalarMatrix BEqn
    (
        fvm::ddt(B)
      + fvc::div(phi, B)
     ==
        fvc::laplacian(Db, B)
      + C * A*B*B
      - (f + k)*B
    );

    BEqn.solve();
}
