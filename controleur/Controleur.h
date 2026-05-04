#ifndef CONTROLEUR_H
#define CONTROLEUR_H

class InterfaceUtilisateur;
class Modele;

class Controleur {
protected:
    InterfaceUtilisateur& vue;
    Modele& modele;

public:
    Controleur(InterfaceUtilisateur& vue, Modele& modele)
        : vue(vue), modele(modele) {}

    virtual ~Controleur() {}
    //methode abstraite
    virtual void run() = 0;
};

#endif
