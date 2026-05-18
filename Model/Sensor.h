
//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H


#include <string>
#include <list>
#include "Measurement.h"
#include "../TypeUtil/Period.h"
#include "../TypeUtil/Coordinates.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    std::list<Measurement> getMeasurements(Periode periode);

    Coordinates getPosition();
    
    void markDefective();


//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor ( std::string sensorId, float latitude, float longitude );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string sensorId;
    float latitude;
    float longitude;
    bool isFunctional;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H

