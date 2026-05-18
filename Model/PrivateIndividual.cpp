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

PrivateIndividual::PrivateIndividual (  std::string userId, std::string password, std::string role, std::string privateId, int points )
    : User( userId, password, role ),
      privateId( privateId ),
      points( points ),
      isReliable( true )
{
}

PrivateIndividual::PrivateIndividual ( )
    : User( ),
      privateId( "" ),
      points( 0 ),
      isReliable( true )
{
}

PrivateIndividual::~PrivateIndividual ( )
{
}
