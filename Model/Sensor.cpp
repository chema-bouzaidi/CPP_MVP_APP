//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ----------------

#include "Sensor.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Sensor & Sensor::operator = ( const Sensor & unSensor )
{
    if ( this != &unSensor )
    {
        sensorId     = unSensor.sensorId;
        latitude     = unSensor.latitude;
        longitude    = unSensor.longitude;
        isFunctional = unSensor.isFunctional;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
    : sensorId( unSensor.sensorId ),
      latitude( unSensor.latitude ),
      longitude( unSensor.longitude ),
      isFunctional( unSensor.isFunctional )
{
}

Sensor::Sensor ( std::string sensorId, float latitude, float longitude )
    : sensorId( sensorId ),
      latitude( latitude ),
      longitude( longitude ),
      isFunctional( true )
{
}

Sensor::Sensor ( )
    : sensorId( "" ),
      latitude( 0.0f ),
      longitude( 0.0f ),
      isFunctional( true )
{
}

Sensor::~Sensor ( )
{
}

//------------------------------------------------------- Méthodes publiques
std::list<Measurement> Sensor::getMeasurements ( Period periode )
{
    
}

Coordinates Sensor::getPosition ( )
{
    
}

void Sensor::markDefective ( )
{
    isFunctional = false;
}