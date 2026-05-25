#if !defined(PROVIDER_H)
#define PROVIDER_H

#include <string>
#include <list>
#include "User.h"
#include "Cleaner.h"

class Provider : public User
{
public:
    const std::list<Cleaner>& getCleaners() const;
    void addCleaner(Cleaner cleaner);

    std::string getProviderId() const;   // same as getUserId()
    std::string getName() const;

    Provider & operator=(const Provider& p);
    Provider(const Provider& p);
    Provider(std::string userId, std::string password, std::string name);
    Provider();
    virtual ~Provider();

protected:
    std::string name;
    std::list<Cleaner> cleaners;
};

#endif // PROVIDER_H
