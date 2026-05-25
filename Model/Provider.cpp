#include "Provider.h"

Provider & Provider::operator=(const Provider& p)
{
    if (this != &p)
    {
        User::operator=(p);
        name     = p.name;
        cleaners = p.cleaners;
    }
    return *this;
}

Provider::Provider(const Provider& p)
    : User(p), name(p.name), cleaners(p.cleaners) {}

Provider::Provider(std::string userId, std::string password, std::string n)
    : User(userId, password, "provider"), name(n) {}

Provider::Provider() : User(), name("") {}

Provider::~Provider() {}

const std::list<Cleaner>& Provider::getCleaners() const { return cleaners; }
void Provider::addCleaner(Cleaner c)              { cleaners.push_back(c); }
std::string Provider::getProviderId() const       { return getUserId(); }
std::string Provider::getName() const             { return name; }

bool Provider::ownsCleaner(const std::string& cleanerId) const
{
    for (const Cleaner& c : cleaners)
        if (c.getCleanerId() == cleanerId) return true;
    return false;
}
