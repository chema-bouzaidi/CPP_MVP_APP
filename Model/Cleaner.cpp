//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ----------------

#include "Cleaner.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Cleaner & Cleaner::operator = ( const Cleaner & unCleaner )
{
    if ( this != &unCleaner )
    {
        cleanerId  = unCleaner.cleanerId;
        latitude   = unCleaner.latitude;
        longitude  = unCleaner.longitude;
        startTime  = unCleaner.startTime;
        stopTime   = unCleaner.stopTime;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
    : cleanerId( unCleaner.cleanerId ),
      latitude( unCleaner.latitude ),
      longitude( unCleaner.longitude ),
      startTime( unCleaner.startTime ),
      stopTime( unCleaner.stopTime )
{}

Cleaner::Cleaner ( )
    : cleanerId( "" ),
      latitude( 0.0f ),
      longitude( 0.0f )
{}

Cleaner::~Cleaner ( )
{
}

//------------------------------------------------------- Méthodes publiques
float Cleaner::getCleanerRadius ( )
{

}

bool Cleaner::isActiveAt ( TimeStamp time )
{

}