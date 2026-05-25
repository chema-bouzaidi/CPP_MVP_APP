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

Cleaner::Cleaner(std::string id, float lat, float lon,
                 TimeStamp start, TimeStamp stop)
    : cleanerId(id), latitude(lat), longitude(lon),
      startTime(start), stopTime(stop) {}

Cleaner::Cleaner()
    : cleanerId(""), latitude(0.0f), longitude(0.0f) {}

Cleaner::~Cleaner ( )
{
}

//------------------------------------------------------- Méthodes publiques
bool Cleaner::isActiveAt(const TimeStamp& time) const
{
    return (startTime <= time) && (time <= stopTime);
}

std::string Cleaner::getCleanerId() const { return cleanerId; }
float       Cleaner::getLatitude() const  { return latitude; }
float       Cleaner::getLongitude() const { return longitude; }
TimeStamp   Cleaner::getStartTime() const { return startTime; }
TimeStamp   Cleaner::getStopTime() const  { return stopTime; }