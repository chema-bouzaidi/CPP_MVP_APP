#ifndef CONTROLEURAGENCE_H
#define CONTROLEURAGENCE_H
#include <list>

#include "Controleur.h"
#include "../Model/Agency.h"
#include "../Model/Sensor.h"
#include "../TypeUtil/Period.h"

class ControleurAgence : public Controleur {
public:
    ControleurAgence(InterfaceUtilisateur& vue, Modele& modele)
        : Controleur(vue, modele) {}

    void run();
    void analyzeSensorsData();
    void analyzePrivateSensors();
    bool checkSensorFunctioning(const Sensor& s);
    void removeOutliers(const Sensor& s);
    void markSensorDefective(const Sensor& s);
    list<Sensor*> findSimilarSensors(const Sensor& refSensor, const Period& period);
protected:
    Agency currentAgency;
};

#endif
