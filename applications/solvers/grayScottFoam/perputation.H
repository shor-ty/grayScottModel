
//- Add a perputation to field A and B
{
    scalarField& AField = A.internalField();
    scalarField& BField = B.internalField(); 

    //- New object of class Random
    Random obj(1);

    forAll(AField, cellI)
    {
        //- Random number between 0 - 1
        const scalar randNumber(obj.scalar01());

        bool addPerputation = false;

        //- Perpuataion +- of p percentage
        if (obj.bit())
        {
            addPerputation = true;
        }            

        if (addPerputation)
        {

            AField[cellI] *= (1 + p * randNumber/100);
            BField[cellI] *= (1 + p * randNumber/100);
        }
        else
        {

            AField[cellI] *= (1 - p * randNumber/100);
            BField[cellI] *= (1 - p * randNumber/100);
        }

    }

    A.write();
    B.write();
}
