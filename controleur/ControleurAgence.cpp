#include "ControleurAgence.h"
#include "../Model/Modele.h"
#include "../Model/AirQualityCalculator.h"
#include "../Model/PrivateSensor.h"
#include "../Model/PrivateIndividual.h"
#include "../Vue/InterfaceUtilisateur.h"
#include "../TypeUtil/Coordinates.h"
#include "../TypeUtil/Period.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

void ControleurAgence::run()
{
    vue.displayMessage("Connecte en tant qu'Agence : " + currentUser->getUserId());

    bool running = true;
    while (running)
    {
        int choice = vue.displayMenu("Menu Agence",
            {"Analyser la qualite de l'air (zone + periode)",
             "Trouver capteurs similaires",
             "Marquer un capteur defectueux",
             "Analyser capteurs prives (valider fiabilite)",
             "Lister tous les capteurs",
             "Se deconnecter"});

        switch (choice)
        {
        case 1:
            analyzeSensorsData();
            break;
        case 2:
        {
            std::string sId = vue.readString("ID du capteur de reference : ");
            Sensor* s = modele.findSensorById(sId);
            if (!s) { vue.displayError("Capteur introuvable."); break; }

            std::string start = vue.readString("Date debut (YYYY-MM-DD HH:MM:SS) : ");
            std::string end   = vue.readString("Date fin   (YYYY-MM-DD HH:MM:SS) : ");
            TimeStamp ts1(start), ts2(end);
            Period period(ts1, ts2);

            auto similar = findSimilarSensors(*s, period);
            vue.displayTitle("Capteurs similaires a " + sId);
            int rank = 1;
            for (Sensor* sim : similar)
                std::cout << "  " << rank++ << ". " << sim->getSensorId() << "\n";
            break;
        }
        case 3:
        {
            std::string sId = vue.readString("ID du capteur a marquer defectueux : ");
            Sensor* s = modele.findSensorById(sId);
            if (!s) { vue.displayError("Capteur introuvable."); break; }
            markSensorDefective(*s);
            break;
        }
        case 4:
            analyzePrivateSensors();
            break;
        case 5:
            vue.displaySensors(modele.getSensors());
            break;
        case 6:
            running = false;
            break;
        default:
            vue.displayError("Choix invalide.");
        }
    }
}

void ControleurAgence::analyzeSensorsData()
{
    float lat    = vue.readFloat("Latitude du centre (ex: 45.5) : ");
    float lon    = vue.readFloat("Longitude du centre (ex: 2.5) : ");
    float radius = vue.readFloat("Rayon (km) : ");
    std::string start = vue.readString("Date debut (YYYY-MM-DD HH:MM:SS) : ");
    std::string end   = vue.readString("Date fin   (YYYY-MM-DD HH:MM:SS) : ");

    Coordinates center(lat, lon);
    TimeStamp ts1(start), ts2(end);
    Period period(ts1, ts2);

    AirQualityCalculator calc;
    float avg = calc.computeAverageQuality(
        modele.getSensors(), modele.getMeasurements(), center, radius, period);

    std::cout << "\nQualite moyenne de l'air (indice ATMO) : "
              << std::fixed << avg << " / 10\n";

    // Descriptive label
    std::string label;
    if      (avg == 0){
        label = "Aucun capteur trouve";
        std::cout << label << "\n";
        return;
    }
    if      (avg <= 2) label = "Tres bon";
    else if (avg <= 4) label = "Bon";
    else if (avg <= 6) label = "Moyen";
    else if (avg <= 8) label = "Mauvais";
    else               label = "Tres mauvais";
    std::cout << "Qualite : " << label << "\n";
}

void ControleurAgence::analyzePrivateSensors()
{
    vue.displayTitle("Analyse des capteurs prives");
    for (Sensor* s : modele.getSensors())
    {
        PrivateSensor* ps = dynamic_cast<PrivateSensor*>(s);
        if (!ps) continue;
        std::cout << "  Capteur prive : " << ps->getSensorId()
                  << " | proprietaire=" << ps->getOwnerId()
                  << " | fiable=" << (ps->getIsReliable() ? "oui" : "NON")
                  << "\n";
    }
}

bool ControleurAgence::checkSensorFunctioning(const Sensor& s)
{
    return s.getIsFunctional();
}

void ControleurAgence::removeOutliers(const Sensor& s)
{
    PrivateSensor* ps = dynamic_cast<PrivateSensor*>(modele.findSensorById(s.getSensorId()));
    if (ps) ps->removeAbberantData();
    vue.displayMessage("Donnees aberrantes supprimees pour : " + s.getSensorId());
}

void ControleurAgence::markSensorDefective(const Sensor& s)
{
    Sensor* found = modele.findSensorById(s.getSensorId());
    if (found) {
        PrivateSensor* ps = dynamic_cast<PrivateSensor*>(found);
        if (ps) ps->flagAsUnreliable();
        removeOutliers(s);
        PrivateIndividual* pi = dynamic_cast<PrivateIndividual*>(modele.findUserById(ps->getOwnerId()));
        if (pi) pi->ban();
    }
    vue.displayMessage("Capteur marque defectueux : " + s.getSensorId());
}

std::list<Sensor*> ControleurAgence::findSimilarSensors(
    const Sensor& refSensor, const Period& period)
{
    AirQualityCalculator calc;
    auto& allMeas = modele.getMeasurements();

    // Collect ref sensor measurements for the period
    std::list<Measurement*> refMeas;
    for (Measurement* m : allMeas)
        if (m->getSensorId() == refSensor.getSensorId() &&
            period.contains(m->getTimestamp()))
            refMeas.push_back(m);

    float refATMO = static_cast<float>(calc.computeATMO(refMeas));

    // Score each other sensor
    std::vector<std::pair<float, Sensor*>> scored;
    for (Sensor* s : modele.getSensors())
    {
        if (s->getSensorId() == refSensor.getSensorId()) continue;

        std::list<Measurement*> sMeas;
        for (Measurement* m : allMeas)
            if (m->getSensorId() == s->getSensorId() &&
                period.contains(m->getTimestamp()))
                sMeas.push_back(m);

        if (sMeas.empty()) continue;
        float sATMO = static_cast<float>(calc.computeATMO(sMeas));
        scored.push_back({std::abs(sATMO - refATMO), s});
    }

    std::sort(scored.begin(), scored.end(),
        [](const std::pair<float,Sensor*>& a, const std::pair<float,Sensor*>& b) {
            return a.first < b.first;
        });

    std::list<Sensor*> result;
    for (auto& p : scored) result.push_back(p.second);
    return result;
}
