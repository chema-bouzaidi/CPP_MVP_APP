
//---------- Interface de la classe <PrivateSensor> (fichier PrivateSensor.h) ----------------
#if ! defined ( PRIVATE_SENSOR_H )
#define PRIVATE_SENSOR_H


#include <string>
#include "Sensor.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateSensor>
//
//
//------------------------------------------------------------------------

class PrivateSensor: public Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void flagAsUnreliable();

    void removeAbberantData();

//------------------------------------------------- Surcharge d'opérateurs
    PrivateSensor & operator = ( const PrivateSensor & unPrivateSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PrivateSensor ( const PrivateSensor & unPrivateSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PrivateSensor ( std::string sensorId, float latitude, float longitude );
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateSensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PrivateSensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string ownerId;
    bool isReliable;

};

//-------------------------------- Autres définitions dépendantes de <PrivateSensor>

#endif // PRIVATE_SENSOR_H

