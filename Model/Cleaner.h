
//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H


#include <string>
#include <list>
#include "../TypeUtil/Period.h"
#include "../TypeUtil/TimeStamp.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool  isActiveAt(const TimeStamp& time) const;

    std::string getCleanerId() const;
    float       getLatitude() const;
    float       getLongitude() const;
    TimeStamp   getStartTime() const;
    TimeStamp   getStopTime() const;


//------------------------------------------------- Surcharge d'opérateurs
    Cleaner & operator = ( const Cleaner & unCleaner );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( const Cleaner & unCleaner );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cleaner(std::string cleanerId, float lat, float lon,
            TimeStamp start, TimeStamp stop);

    Cleaner();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cleaner ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string cleanerId;
    float latitude;
    float longitude;
    TimeStamp startTime;
    TimeStamp stopTime;
    

};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H

