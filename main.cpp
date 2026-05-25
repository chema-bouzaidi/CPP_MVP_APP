#include "Model/Modele.h"
#include "Vue/InterfaceUtilisateur.h"
#include "controleur/Authentifieur.h"

int main()
{
    Modele modele;
    modele.loadCSVData();

    InterfaceUtilisateur vue;
    Authentifieur auth(vue, modele);
    auth.run();

    return 0;
}
