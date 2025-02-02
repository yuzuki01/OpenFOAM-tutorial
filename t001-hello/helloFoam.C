#include "argList.H"
#include "foamVersion.H"


int main(int argc, char* argv[]) {

#include "setRootCase.H"

    Foam::Info << "Hello from OpenFOAM-" << Foam::FOAMversion << "." << Foam::endl;

    return 0;
}
