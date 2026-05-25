#include "Modele.h"
#include "Admin.h"
#include "Agency.h"
#include "PrivateIndividual.h"
#include "PrivateSensor.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

// ---- Constructeurs / destructeur -------------------------------------------

Modele::Modele() {}

Modele::Modele(const Modele&) {}   // shallow — not intended for real copy

Modele & Modele::operator=(const Modele&) { return *this; }

Modele::~Modele()
{
    for (Measurement* p : measurements) delete p;
    for (Sensor* p : sensors)           delete p;
    for (User* p : users)               delete p;  // owns Providers too (via User*)
    for (Cleaner* p : cleaners)         delete p;
    for (Attribute* p : attributes)     delete p;
    // providers are NOT deleted here — they're already owned by 'users'
}

// ---- Chargement CSV ---------------------------------------------------------

void Modele::loadCSVData()
{
    // 1. Read users.csv → build map sensorId → userId (private individuals)
    std::map<std::string, std::string> privateSensorMap;
    {
        std::ifstream f("data/users.csv");
        if (!f) std::cerr << "Warning: cannot open data/users.csv\n";
        std::string line;
        while (std::getline(f, line))
        {
            if (line.empty()) continue;
            std::istringstream ss(line);
            std::string userId, sensorId;
            std::getline(ss, userId,   ';');
            std::getline(ss, sensorId, ';');
            if (!userId.empty() && !sensorId.empty())
                privateSensorMap[sensorId] = userId;
        }
    }

    // 2. Read attributes.csv
    {
        std::ifstream f("data/attributes.csv");
        if (!f) std::cerr << "Warning: cannot open data/attributes.csv\n";
        std::string line;
        bool header = true;
        while (std::getline(f, line))
        {
            if (line.empty()) continue;
            if (header) { header = false; continue; }  // skip header
            std::istringstream ss(line);
            std::string id, unit, desc;
            std::getline(ss, id,   ';');
            std::getline(ss, unit, ';');
            std::getline(ss, desc, ';');
            if (!id.empty())
                attributes.push_back(new Attribute(id, id, unit));
        }
    }

    // 3. Read sensors.csv
    {
        std::ifstream f("data/sensors.csv");
        if (!f) std::cerr << "Warning: cannot open data/sensors.csv\n";
        std::string line;
        while (std::getline(f, line))
        {
            if (line.empty()) continue;
            std::istringstream ss(line);
            std::string id, latStr, lonStr;
            std::getline(ss, id,     ';');
            std::getline(ss, latStr, ';');
            std::getline(ss, lonStr, ';');
            if (id.empty()) continue;
            float lat = std::stof(latStr);
            float lon = std::stof(lonStr);
            if (privateSensorMap.count(id))
                sensors.push_back(new PrivateSensor(id, lat, lon, privateSensorMap[id]));
            else
                sensors.push_back(new Sensor(id, lat, lon));
        }
    }

    // 4. Create PrivateIndividual users
    for (std::map<std::string,std::string>::iterator it = privateSensorMap.begin(); it != privateSensorMap.end(); ++it)
    {
        const std::string& sId  = it->first;
        const std::string& uId  = it->second;
        users.push_back(new PrivateIndividual(uId, uId, "private", uId, 0, sId));
    }

    // 5. Hardcoded institutional accounts (demo)
    users.push_back(new Admin("admin",   "admin",   "admin",   "admin001"));
    users.push_back(new Agency("agency", "agency",  "agency",  "agency001"));

    // 6. Read measurements.csv
    {
        std::ifstream f("data/measurements.csv");
        if (!f) std::cerr << "Warning: cannot open data/measurements.csv\n";
        std::string line;
        while (std::getline(f, line))
        {
            if (line.empty()) continue;
            std::istringstream ss(line);
            std::string tsStr, sensorId, attrId, valStr;
            std::getline(ss, tsStr,    ';');
            std::getline(ss, sensorId, ';');
            std::getline(ss, attrId,   ';');
            std::getline(ss, valStr,   ';');
            if (tsStr.empty() || sensorId.empty() || valStr.empty()) continue;
            float val = std::stof(valStr);
            Measurement* m = new Measurement(TimeStamp(tsStr), sensorId, attrId, val);
            measurements.push_back(m);

            Sensor* s = findSensorById(sensorId);
            if (s) s->addMeasurement(m);
        }
    }

    // 7. Read cleaners.csv
    {
        std::ifstream f("data/cleaners.csv");
        if (!f) std::cerr << "Warning: cannot open data/cleaners.csv\n";
        std::string line;
        while (std::getline(f, line))
        {
            if (line.empty()) continue;
            std::istringstream ss(line);
            std::string id, latStr, lonStr, startStr, stopStr;
            std::getline(ss, id,       ';');
            std::getline(ss, latStr,   ';');
            std::getline(ss, lonStr,   ';');
            std::getline(ss, startStr, ';');
            std::getline(ss, stopStr,  ';');
            if (id.empty()) continue;
            float lat = std::stof(latStr);
            float lon = std::stof(lonStr);
            cleaners.push_back(new Cleaner(id, lat, lon,
                                            TimeStamp(startStr), TimeStamp(stopStr)));
        }
    }

    // 8. Read providers.csv — create Provider user accounts and link cleaners
    {
        std::ifstream f("data/providers.csv");
        if (!f) std::cerr << "Warning: cannot open data/providers.csv\n";
        std::string line;
        while (std::getline(f, line))
        {
            if (line.empty()) continue;
            std::istringstream ss(line);
            std::string providerId, cleanerId;
            std::getline(ss, providerId, ';');
            std::getline(ss, cleanerId,  ';');
            if (providerId.empty()) continue;
            // userId == providerId, password == providerId (demo)
            Provider* p = new Provider(providerId, providerId, providerId);
            Cleaner*  c = findCleanerById(cleanerId);
            if (c) p->addCleaner(*c);
            providers.push_back(p);
            users.push_back(p);   // Provider is also a User now
        }
    }

    std::cout << "Data loaded: "
              << sensors.size()      << " sensors, "
              << measurements.size() << " measurements, "
              << cleaners.size()     << " cleaners, "
              << users.size()        << " users.\n";
}

// ---- Authentification -------------------------------------------------------

User* Modele::authenticateUser(const std::string& id, const std::string& pwd)
{
    for (User* u : users)
        if (u->getUserId() == id && u->getPassword() == pwd)
            return u;
    return nullptr;
}

// ---- Getters ----------------------------------------------------------------

std::list<User*>&        Modele::getUsers()        { return users; }
std::list<Sensor*>&      Modele::getSensors()      { return sensors; }
std::list<Cleaner*>&     Modele::getCleaners()     { return cleaners; }
std::list<Measurement*>& Modele::getMeasurements() { return measurements; }
std::list<Attribute*>&   Modele::getAttributes()   { return attributes; }
std::list<Provider*>&    Modele::getProviders()    { return providers; }

// ---- Lookup -----------------------------------------------------------------

Sensor* Modele::findSensorById(const std::string& id)
{
    for (Sensor* s : sensors)
        if (s->getSensorId() == id) return s;
    return nullptr;
}

User* Modele::findUserById(const std::string& id)
{
    for (User* u : users)
        if (u->getUserId() == id) return u;
    return nullptr;
}

Cleaner* Modele::findCleanerById(const std::string& id)
{
    for (Cleaner* c : cleaners)
        if (c->getCleanerId() == id) return c;
    return nullptr;
}

Provider* Modele::findProviderById(const std::string& id)
{
    for (Provider* p : providers)
        if (p->getProviderId() == id) return p;
    return nullptr;
}
