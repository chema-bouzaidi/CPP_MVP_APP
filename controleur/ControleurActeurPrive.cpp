#include "ControleurActeurPrive.h"
#include "../Model/Modele.h"
#include "../Model/PrivateSensor.h"
#include "../Model/AirQualityCalculator.h"
#include "../Vue/InterfaceUtilisateur.h"
#include "../TypeUtil/Period.h"

#include <iostream>
#include <list>

void ControleurActeurPrive::run()
{
    if (!currentUser)
    {
        vue.displayError("Utilisateur prive non defini.");
        return;
    }

    vue.displayMessage("Connecte en tant que Particulier : " + currentUser->getUserId());

    bool running = true;
    while (running)
    {
        int choice = vue.displayMenu("Menu Particulier",
            {"Consulter mes points de fiabilite",
             "Consulter les mesures de mon capteur",
             "Se deconnecter"});

        switch (choice)
        {
        case 1:
            consultPoints();
            break;
        case 2:
            consultSensorMeasurements();
            break;
        case 3:
            running = false;
            break;
        default:
            vue.displayError("Choix invalide.");
        }
    }
}

void ControleurActeurPrive::consultPoints()
{
    vue.displayTitle("Points de fiabilite");
    std::cout << "  Utilisateur : " << currentUser->getUserId() << "\n"
              << "  Points      : " << currentUser->getPoints() << "\n"
              << "  Fiable      : " << (currentUser->getIsReliable() ? "oui" : "non") << "\n";
}

void ControleurActeurPrive::consultSensorMeasurements()
{
    std::string sensorId = currentUser->getSensorId();
    if (sensorId.empty())
    {
        vue.displayError("Aucun capteur associe a ce compte.");
        return;
    }

    Sensor* sensor = modele.findSensorById(sensorId);
    if (!sensor)
    {
        vue.displayError("Capteur introuvable : " + sensorId);
        return;
    }

    std::string start = vue.readString("Date debut (YYYY-MM-DD HH:MM:SS) : ");
    std::string end   = vue.readString("Date fin   (YYYY-MM-DD HH:MM:SS) : ");
    TimeStamp ts1(start), ts2(end);
    if (ts2<ts1)

    {
        vue.displayError("Choix de dates invalide ");
        return;

    }
    Period period(ts1, ts2);

    std::list<Measurement> meas = sensor->getMeasurements(period);
    vue.displayTitle("Mesures du capteur " + sensorId);
    for (const Measurement& m : meas)
    {
        std::cout << "  " << m.getTimestamp().toString()
                  << " | " << m.getAttributeId()
                  << " = " << m.getValue() << " µg/m3\n";
    }
    if (meas.empty())
        vue.displayMessage("Aucune mesure pour cette periode.");

    // Reward: add points for consulting data (engagement)
    currentUser->addPoints(1);
}
