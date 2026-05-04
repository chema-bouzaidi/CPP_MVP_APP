#ifndef CONTROLEURENTREPRISE_H
#define CONTROLEURENTREPRISE_H
#include "Controleur.h"

#include "ExternalCompany.h"
#include "Agency.h"
#include "Statistics.h"

class ControleurEntreprise : public Controleur {
public:
    ControleurEntreprise(InterfaceUtilisateur& vue, Modele& modele)
        : Controleur(vue, modele) {}

    void run();
    Statistics analyzeCleanerImpact(const Cleaner& cleaner);
    Statistics getCleanedRadius(const Cleaner& cleaner);
    Statistics getImprovementLevel(const Cleaner& cleaner);
protected: 
    ExternalCompany currentCompany;

};

#endif
