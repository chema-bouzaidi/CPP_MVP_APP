//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ----------------

#include "Provider.h"


//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Provider & Provider::operator = ( const Provider & unProvider )
{
    if ( this != &unProvider )
    {
        providerId = unProvider.providerId;
        name       = unProvider.name;
        cleaners   = unProvider.cleaners;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider )
    : providerId( unProvider.providerId ),
      name( unProvider.name ),
      cleaners( unProvider.cleaners )
{
}

Provider::Provider ( std::string providerId, std::string name )
    : providerId( providerId ),
      name( name )
{
}

Provider::Provider ( )
    : providerId( "" ),
      name( "" )
{
}

Provider::~Provider ( )
{
}

//------------------------------------------------------- Méthodes publiques
std::list<Cleaner> Provider::getCleaners ( )
{
    return cleaners;
}

void Provider::addCleaner ( Cleaner cleaner )
{
    cleaners.push_back( cleaner );
}