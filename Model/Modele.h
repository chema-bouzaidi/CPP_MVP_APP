
//---------- Interface de la classe <Modele> (fichier Modele.h) ----------------
#if ! defined ( MODELE_H )
#define MODELE_H

#include <list>
#include <string>
#include "User.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Measurement.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Modele>
//
//
//------------------------------------------------------------------------

class Modele
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void start();

    void loadCSVData();

    User authenticateUser(std::string userId, std::string password);

    std::list<User*> getUsers();

    std::list<Sensor*> getSensors();

    std::list<Cleaner*> getCleaners();

    std::list<Measurement*> getMeasurements();

//------------------------------------------------- Surcharge d'opérateurs
    Modele & operator = ( const Modele & unModele );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Modele ( const Modele & unModele );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
    std::list<User*> users;
    std::list<Sensor*> sensors;
    std::list<Cleaner*> cleaners;
    std::list<Measurement*> measurements;

};

//-------------------------------- Autres définitions dépendantes de <Modele>

#endif // MODELE_H

