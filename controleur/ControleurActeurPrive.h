#ifndef CONTROLEURACTEURPRIVE_H
#define CONTROLEURACTEURPRIVE_H

#include "Controleur.h"
#include "../Model/PrivateIndividual.h"
#include "../Model/PrivateSensor.h"

class ControleurActeurPrive : public Controleur {
public:
    ControleurActeurPrive(InterfaceUtilisateur& vue, Modele& modele,
                          PrivateIndividual* user)
        : Controleur(vue, modele), currentUser(user) {}

    void run();
    void consultPoints();
    void consultSensorMeasurements();
protected:
    PrivateIndividual* currentUser;
};

#endif
