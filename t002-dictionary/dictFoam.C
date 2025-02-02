#include "argList.H"
#include "IOdictionary.H"
#include "timeControl.H"
#include "dimensionSets.H"


using namespace Foam;


int main(int argc, char *argv[]) {

#include "setRootCase.H"
#include "createTime.H"
    
    IOdictionary transportProperties
            (
                    IOobject
                            (
                                    "physicalProperties",
                                    Time::constant(),
                                    runTime,
                                    IOobject::MUST_READ_IF_MODIFIED,
                                    IOobject::NO_WRITE
                            )
            );

    dimensionedScalar nu
            (
                    "nu",
                    Foam::dimKinematicViscosity,
                    transportProperties.lookup("nu")
            );

    Info << "nu=" << nu.value() << endl;

    return 0;
}
