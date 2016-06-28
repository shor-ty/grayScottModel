    Info<< "Reading field A\n" << endl;

    volScalarField A
    (
        IOobject
        (
            "A",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field B\n" << endl;

    volScalarField B
    (
        IOobject
        (
            "B",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );


    Info<< "Reading diffusivity Du\n" << endl;

    dimensionedScalar Da
    (
        transportProperties.lookup("Da")
    );

    Info<< "Reading diffusivity Dv\n" << endl;

    dimensionedScalar Db
    (
        transportProperties.lookup("Db")
    );

    Info<< "Reading f and k options\n" << endl;

    const Switch method(transportProperties.lookup("fields"));

    autoPtr<volScalarField> kPtr(NULL);

    autoPtr<volScalarField> fPtr(NULL);

    if (method)
    {
        kPtr.reset
        (
            new volScalarField
            (
                IOobject
                (
                    "k",
                    runTime.timeName(),
                    mesh,
                    IOobject::MUST_READ,
                    IOobject::NO_WRITE
                ),
                mesh
            )
        );

        fPtr.reset
        (
            new volScalarField
            (
                IOobject
                (
                    "f",
                    runTime.timeName(),
                    mesh,
                    IOobject::MUST_READ,
                    IOobject::NO_WRITE
                ),
                mesh
            )
        );
    }
    else
    {
        Info<< "Constant values of k and f are used\n" << endl;

        Info<< "Reading rate of conversion k\n" << endl;

        dimensionedScalar kValue
        (
            transportProperties.lookup("k")
        );

        Info<< "Reading rate of progress f\n" << endl;

        dimensionedScalar fValue
        (
            transportProperties.lookup("f")
        );

        IOobject kIO
        (
            "k",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        );

        kPtr.reset
        (
            new volScalarField
            (
                kIO,
                mesh,
                kValue,
                zeroGradientFvPatchField<scalar>::typeName
            )
        );

        IOobject fIO
        (
            "f",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        );

        fPtr.reset
        (
            new volScalarField
            (
                fIO,
                mesh,
                fValue,
                zeroGradientFvPatchField<scalar>::typeName
            )
        );
    }


    //- This is only for units
    dimensionedScalar C
    (
        "C",
        dimensionSet(0,0,-1,0,0,0,0),
        scalar(1)
    );

    //- Perputation in percent
    const scalar p = readScalar(transportProperties.lookup("p"));

    const volScalarField& f = fPtr();
    const volScalarField& k = fPtr();

    //- Add some small perputation to the fields
    #include "perputation.H"
