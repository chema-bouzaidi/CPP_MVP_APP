#ifndef AUTHENTIFIEUR_H
#define AUTHENTIFIEUR_H
#include <string>
using namespace std;

#include "Controleur.h"

class Authentifieur : public Controleur {
public:
    Authentifieur(InterfaceUtilisateur& vue, Modele& modele)
        : Controleur(vue, modele) {}

    void run();
    bool login(const string& id, const string& pwd);
    void logout();
    
};

#endif
