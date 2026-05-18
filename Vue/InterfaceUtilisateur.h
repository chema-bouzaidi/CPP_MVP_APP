#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <string>
#include <list>
#include <vector>
#include <utility>

class Sensor;
class Measurement;
class Cleaner;
class User;
class Statistics;

class InterfaceUtilisateur
{
public:
    InterfaceUtilisateur();
    ~InterfaceUtilisateur();

    // Display helpers
    void displayMessage(const std::string& msg) const;
    void displayError(const std::string& msg) const;
    void displaySeparator() const;
    void displayTitle(const std::string& title) const;

    // Input helpers
    std::string readString(const std::string& prompt) const;
    float       readFloat(const std::string& prompt) const;
    int         readInt(const std::string& prompt) const;

    // Menu: display numbered choices, return chosen index (1-based)
    int displayMenu(const std::string& title,
                    const std::vector<std::string>& options) const;

    // Domain display
    void displaySensors(const std::list<Sensor*>& sensors) const;
    void displayMeasurements(const std::list<Measurement*>& meas) const;
    void displayCleaners(const std::list<Cleaner*>& cleaners) const;
    void displayStatistics(const Statistics& stats) const;

    // Auth prompts — returns {id, password}
    std::pair<std::string, std::string> readCredentials() const;
};

#endif // INTERFACEUTILISATEUR_H
