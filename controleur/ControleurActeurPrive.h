#ifndef CONTROLEURACTEURPRIVE_H
#define CONTROLEURACTEURPRIVE_H

#include "Controleur.h"
#include "PrivateIndividual.h"
#include "PrivateSensor.h"

class ControleurActeurPrive : public Controleur {
public:
    ControleurActeurPrive(InterfaceUtilisateur& vue, Modele& modele)
        : Controleur(vue, modele) {}

    void run();
    void consultPoints();
    void consultSensorMeasurements(const PrivateSensor& sensor);
protected:
    PrivateIndividual currentUser;
};

#endif
