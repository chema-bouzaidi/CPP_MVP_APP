#include "InterfaceUtilisateur.h"
#include "../Model/Sensor.h"
#include "../Model/Measurement.h"
#include "../Model/Cleaner.h"
#include "../Model/Statistics.h"

#include <iostream>
#include <iomanip>
#include <limits>

InterfaceUtilisateur::InterfaceUtilisateur()  {}
InterfaceUtilisateur::~InterfaceUtilisateur() {}

void InterfaceUtilisateur::displayMessage(const std::string& msg) const
{
    std::cout << msg << std::endl;
}

void InterfaceUtilisateur::displayError(const std::string& msg) const
{
    std::cerr << "[ERREUR] " << msg << std::endl;
}

void InterfaceUtilisateur::displaySeparator() const
{
    std::cout << std::string(50, '-') << std::endl;
}

void InterfaceUtilisateur::displayTitle(const std::string& title) const
{
    displaySeparator();
    std::cout << "  " << title << std::endl;
    displaySeparator();
}

std::string InterfaceUtilisateur::readString(const std::string& prompt) const
{
    std::cout << prompt;
    std::string s;
   
    std::getline(std::cin, s);
    return s;
}

float InterfaceUtilisateur::readFloat(const std::string& prompt) const
{
    std::cout << prompt;
    float v = 0;
    std::cin >> v;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return v;
}

int InterfaceUtilisateur::readInt(const std::string& prompt) const
{
    std::cout << prompt;
    int v = 0;
    std::cin >> v;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return v;
}

int InterfaceUtilisateur::displayMenu(const std::string& title,
                                      const std::vector<std::string>& options) const
{
    displayTitle(title);
    for (size_t i = 0; i < options.size(); ++i)
        std::cout << "  " << (i + 1) << ". " << options[i] << "\n";
    displaySeparator();
    int choice = readInt("Votre choix : ");
    if (choice < 1 || choice > static_cast<int>(options.size()))
        return -1;
    return choice;
}

void InterfaceUtilisateur::displaySensors(const std::list<Sensor*>& sensors) const
{
    displayTitle("Capteurs");
    for (Sensor* s : sensors)
    {
        std::cout << "  " << s->getSensorId()
                  << " | lat=" << std::fixed << std::setprecision(4) << s->getPosition().getLatitude()
                  << " lon="   << s->getPosition().getLongitude()
                  << " | "     << (s->getIsFunctional() ? "operationnel" : "HORS SERVICE")
                  << "\n";
    }
}

void InterfaceUtilisateur::displayMeasurements(const std::list<Measurement*>& meas) const
{
    displayTitle("Mesures");
    for (Measurement* m : meas)
    {
        std::cout << "  " << m->getTimestamp().toString()
                  << " | " << m->getSensorId()
                  << " | " << m->getAttributeId()
                  << " = "  << std::fixed << std::setprecision(2) << m->getValue()
                  << " µg/m3\n";
    }
}

void InterfaceUtilisateur::displayCleaners(const std::list<Cleaner*>& cleaners) const
{
    displayTitle("Purificateurs (Cleaners)");
    for (Cleaner* c : cleaners)
    {
        std::cout << "  " << c->getCleanerId()
                  << " | lat=" << c->getLatitude()
                  << " lon=" << c->getLongitude()
                  << " | actif du " << c->getStartTime().toString()
                  << " au " << c->getStopTime().toString()
                  << " | rayon=" << c->getCleanerRadius() << " km\n";
    }
}

void InterfaceUtilisateur::displayStatistics(const Statistics& stats) const
{
    stats.display();
}

std::pair<std::string, std::string> InterfaceUtilisateur::readCredentials() const
{
    displayTitle("AirWatcher — Connexion");
    std::string id  = readString("Identifiant : ");
    std::string pwd = readString("Mot de passe : ");
    return {id, pwd};
}
