#ifndef CONTROLEURAGENCE_H
#define CONTROLEURAGENCE_H
#include <vector>
#include <algorithm>

#include "Controleur.h"
#include "../Model/Agency.h"
#include "../Model/Sensor.h"
#include "../TypeUtil/Period.h"

class ControleurAgence : public Controleur {
public:
    ControleurAgence(InterfaceUtilisateur& vue, Modele& modele, User* user)
        : Controleur(vue, modele), currentUser(user) {}

    void run();
    void analyzeSensorsData();
    void analyzePrivateSensors();
    bool checkSensorFunctioning(const Sensor& s);
    void removeOutliers(const Sensor& s);
    void markSensorDefective(const Sensor& s);
    std::vector<std::pair<float, Sensor*>> findSimilarSensors(const Sensor& refSensor, const Period& period);
protected:
    User* currentUser;
};

#endif
