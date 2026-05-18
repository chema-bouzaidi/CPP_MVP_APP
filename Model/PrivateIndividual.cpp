//---------- Réalisation de la classe <PrivateIndividual> (fichier PrivateIndividual.cpp) ----------------

#include "PrivateIndividual.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
PrivateIndividual & PrivateIndividual::operator = ( const PrivateIndividual & unPrivateIndividual )
{
    if ( this != &unPrivateIndividual )
    {
        User::operator=( unPrivateIndividual );
        privateId  = unPrivateIndividual.privateId;
        points     = unPrivateIndividual.points;
        isReliable = unPrivateIndividual.isReliable;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
PrivateIndividual::PrivateIndividual ( const PrivateIndividual & unPrivateIndividual )
    : User( unPrivateIndividual ),
      privateId( unPrivateIndividual.privateId ),
      points( unPrivateIndividual.points ),
      isReliable( unPrivateIndividual.isReliable )
{
}

PrivateIndividual::PrivateIndividual(std::string userId, std::string password,
    std::string role, std::string privateId, int points, std::string sId)
    : User(userId, password, role),
      privateId(privateId),
      sensorId(sId),
      points(points),
      isReliable(true)
{
}

PrivateIndividual::PrivateIndividual()
    : User(), privateId(""), sensorId(""), points(0), isReliable(true) {}

PrivateIndividual::~PrivateIndividual() {}

std::string PrivateIndividual::getSensorId() const { return sensorId; }
int         PrivateIndividual::getPoints() const   { return points; }
bool        PrivateIndividual::getIsReliable() const { return isReliable; }
void        PrivateIndividual::addPoints(int n)    { points += n; }
void        PrivateIndividual::ban()               { isReliable = false; points = 0; }
