#if !defined(MODELE_H)
#define MODELE_H

#include <list>
#include <string>
#include "User.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "Attribute.h"
#include "Provider.h"

class Modele
{
public:
    void loadCSVData();

    // Authentication — returns nullptr if credentials are wrong
    User* authenticateUser(const std::string& userId, const std::string& password);

    // Getters
    std::list<User*>&        getUsers();
    std::list<Sensor*>&      getSensors();
    std::list<Cleaner*>&     getCleaners();
    std::list<Measurement*>& getMeasurements();
    std::list<Attribute*>&   getAttributes();
    std::list<Provider*>&    getProviders();

    // Lookup by ID
    Sensor*   findSensorById(const std::string& id);
    User*     findUserById(const std::string& id);
    Cleaner*  findCleanerById(const std::string& id);
    Provider* findProviderById(const std::string& id);

    Modele & operator=(const Modele& m);
    Modele(const Modele& m);
    Modele();
    virtual ~Modele();

private:
    std::list<User*>        users;
    std::list<Sensor*>      sensors;
    std::list<Cleaner*>     cleaners;
    std::list<Measurement*> measurements;  // owned; sensors hold non-owning pointers
    std::list<Attribute*>   attributes;
    std::list<Provider*>    providers;
};

#endif // MODELE_H
