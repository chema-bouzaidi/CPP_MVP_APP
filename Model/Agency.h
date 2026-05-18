
//---------- Interface de la classe <Agency> (fichier Agency.h) ----------------
#if ! defined ( AGENCY_H )
#define AGENCY_H

#include <string>
#include "User.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Agency>
//
//
//------------------------------------------------------------------------

class Agency: public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    Agency & operator = ( const Agency & unAgency );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Agency ( const Agency & unAgency );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Agency (  std::string userId, std::string password, std::string role, std::string agencyId );

    Agency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Agency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string agencyId;

};

//-------------------------------- Autres définitions dépendantes de <Agency>

#endif // AGENCY_H

