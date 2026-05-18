#include "ControleurEntreprise.h"
#include "../Model/Modele.h"
#include "../Model/AirQualityCalculator.h"
#include "../Model/Provider.h"
#include "../Vue/InterfaceUtilisateur.h"
#include "../TypeUtil/Coordinates.h"
#include "../TypeUtil/Period.h"

#include <iostream>

void ControleurEntreprise::run()
{
    vue.displayMessage("Connecte en tant que Provider : " + currentUser->getUserId());

    Provider* provider = dynamic_cast<Provider*>(currentUser);

    bool running = true;
    while (running)
    {
        int choice = vue.displayMenu("Menu Entreprise",
            {"Voir mes purificateurs",
             "Analyser l'impact d'un purificateur",
             "Calculer le rayon de nettoyage",
             "Calculer le niveau d'amelioration",
             "Se deconnecter"});

        switch (choice)
        {
        case 1:
        {
            vue.displayTitle("Mes purificateurs");
            if (provider)
            {
                for (const Cleaner& c : provider->getCleaners())
                    std::cout << "  " << c.getCleanerId()
                              << " | lat=" << c.getLatitude()
                              << " lon=" << c.getLongitude()
                              << " | actif du " << c.getStartTime().toString()
                              << " au " << c.getStopTime().toString() << "\n";
            }
            else vue.displayMessage("Aucun purificateur associe.");
            break;
        }
        case 2:
        {
            std::string cId = vue.readString("ID du purificateur : ");
            Cleaner* c = modele.findCleanerById(cId);
            if (!c) { vue.displayError("Purificateur introuvable."); break; }
            Statistics s = analyzeCleanerImpact(*c);
            vue.displayStatistics(s);
            break;
        }
        case 3:
        {
            std::string cId = vue.readString("ID du purificateur : ");
            Cleaner* c = modele.findCleanerById(cId);
            if (!c) { vue.displayError("Purificateur introuvable."); break; }
            Statistics s = getCleanedRadius(*c);
            vue.displayStatistics(s);
            break;
        }
        case 4:
        {
            std::string cId = vue.readString("ID du purificateur : ");
            Cleaner* c = modele.findCleanerById(cId);
            if (!c) { vue.displayError("Purificateur introuvable."); break; }
            Statistics s = getImprovementLevel(*c);
            vue.displayStatistics(s);
            break;
        }
        case 5:
            running = false;
            break;
        default:
            vue.displayError("Choix invalide.");
        }
    }
}

Statistics ControleurEntreprise::analyzeCleanerImpact(const Cleaner& cleaner)
{
    AirQualityCalculator calc;
    float impact = calc.computeCleanerImpact(
        cleaner, modele.getSensors(), modele.getMeasurements());

    Coordinates pos(cleaner.getLatitude(), cleaner.getLongitude());
    Period period(cleaner.getStartTime(), cleaner.getStopTime());

    return Statistics(pos, cleaner.getCleanerRadius(), period, 0,
                      impact, "Impact ATMO du purificateur " + cleaner.getCleanerId());
}

Statistics ControleurEntreprise::getCleanedRadius(const Cleaner& cleaner)
{
    AirQualityCalculator calc;
    float radius = calc.computeCleanedRadius(
        cleaner, modele.getSensors(), modele.getMeasurements());

    Coordinates pos(cleaner.getLatitude(), cleaner.getLongitude());
    Period period(cleaner.getStartTime(), cleaner.getStopTime());

    return Statistics(pos, radius, period, 1,
                      radius, "Rayon de nettoyage du purificateur " + cleaner.getCleanerId());
}

Statistics ControleurEntreprise::getImprovementLevel(const Cleaner& cleaner)
{
    // Improvement level = ATMO improvement as percentage
    AirQualityCalculator calc;
    Coordinates pos(cleaner.getLatitude(), cleaner.getLongitude());
    float r = cleaner.getCleanerRadius();
    Period beforePeriod(TimeStamp("2019-01-01 00:00:00"), cleaner.getStartTime());
    Period activePeriod(cleaner.getStartTime(), cleaner.getStopTime());

    float before = calc.computeAverageQuality(
        modele.getSensors(), modele.getMeasurements(), pos, r, beforePeriod);
    float during = calc.computeAverageQuality(
        modele.getSensors(), modele.getMeasurements(), pos, r, activePeriod);

    float pct = (before > 0) ? ((before - during) / before) * 100.0f : 0.0f;

    return Statistics(pos, r, activePeriod, 2,
                      pct, "Amelioration (%) du purificateur " + cleaner.getCleanerId());
}
