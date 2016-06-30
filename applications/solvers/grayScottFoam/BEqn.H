
//- Equation for species B implicit
if (implicit)
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
//- Equation for species B explicit
{
    fvScalarMatrix BEqn
    (
        fvm::ddt(B)
     ==
        Db * fvc::laplacian(B)
      + C * A*B*B
      - (f + k)*B
    );

    BEqn.solve();
}
