//---------- Réalisation de la classe <PrivateSensor> (fichier PrivateSensor.cpp) ----------------

#include "PrivateSensor.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
PrivateSensor & PrivateSensor::operator = ( const PrivateSensor & unPrivateSensor )
{
    if ( this != &unPrivateSensor )
    {
        Sensor::operator=( unPrivateSensor );   // copie des attributs de Sensor
        ownerId    = unPrivateSensor.ownerId;
        isReliable = unPrivateSensor.isReliable;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
PrivateSensor::PrivateSensor ( const PrivateSensor & unPrivateSensor )
    : Sensor( unPrivateSensor ),
      ownerId( unPrivateSensor.ownerId ),
      isReliable( unPrivateSensor.isReliable )
{
}

PrivateSensor::PrivateSensor ( std::string sensorId, float latitude, float longitude )
    : Sensor( sensorId, latitude, longitude ),
      ownerId( "" ),
      isReliable( true )
{
}

PrivateSensor::PrivateSensor ( )
    : Sensor( ),
      ownerId( "" ),
      isReliable( true )
{
}

PrivateSensor::~PrivateSensor ( )
{
}

//------------------------------------------------------- Méthodes publiques
void PrivateSensor::flagAsUnreliable ( )
{
    isReliable = false;
}

void PrivateSensor::removeAbberantData ( )
{
}