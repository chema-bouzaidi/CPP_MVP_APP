#ifndef CONTROLEURENTREPRISE_H
#define CONTROLEURENTREPRISE_H
#include "Controleur.h"

#include "../Model/Provider.h"
#include "../Model/Cleaner.h"
#include "../Model/Statistics.h"

class ControleurEntreprise : public Controleur {
public:
    ControleurEntreprise(InterfaceUtilisateur& vue, Modele& modele, User* user)
        : Controleur(vue, modele), currentUser(user) {}

    void run();
    Statistics analyzeCleanerImpact(const Cleaner& cleaner);
    Statistics getCleanedRadius(const Cleaner& cleaner);
    Statistics getImprovementLevel(const Cleaner& cleaner);
protected:
    User* currentUser;

};

#endif
