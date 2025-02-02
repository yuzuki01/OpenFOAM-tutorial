#include "argList.H"
#include "timeControl.H"
#include "fvMesh.H"
#include "findRefCell.H"


int main(int argc, char *argv[]) {

#include "setRootCase.H"
#include "createTime.H"
#include "createMesh.H"

    using namespace Foam;
    Info << "Read mesh:" << mesh.name() << endl;

#include "createFields.H"

    auto &bound = mesh.boundary();

    forAll(mesh.faces(), facei)
    {
        auto &own = mesh.owner()[facei];
        auto area = mesh.magFaceAreas()[facei];
        if (mesh.isInternalFace(facei)) {
            auto &nei = mesh.neighbour()[facei];
            Info << "inner face:" << facei
                 << " own:" << own
                 << " nei:" << nei
                 << " area:" << area << endl;
        } else {
            auto& tmp = mesh.faceOwner()[facei];
            Info << "bound face:" << facei
                 << " own:" << own
                 << " patch-name: " << tmp
                 << endl;
        }
    }

    forAll(U.boundaryFieldRef(), patchi) {
        auto &patch = bound[patchi];
        auto &U_patch = U.boundaryFieldRef()[patchi];
        Info << "bound-" << patchi << ": " << patch.name() << " type:" << patch.type() << endl;
        forAll(U_patch, facei)
        {
            Info << "  U_patch id:" << facei << " value:" << U_patch[facei] << endl;
        }
    }

    return 0;
}
