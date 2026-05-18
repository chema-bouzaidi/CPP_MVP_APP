
//---------- Interface de la classe <ExternalCompany> (fichier ExternalCompany.h) ----------------
#if ! defined ( EXTERNAL_COMPANY_H )
#define EXTERNAL_COMPANY_H

#include <string>
#include "User.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ExternalCompany>
//
//
//------------------------------------------------------------------------

class ExternalCompany: public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    ExternalCompany & operator = ( const ExternalCompany & anExternalCompany );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ExternalCompany ( const ExternalCompany & anExternalCompany );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ExternalCompany ( std::string userId, std::string password, std::string role, std::string companyId, std::string providerId );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ExternalCompany ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ExternalCompany ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string companyId;
    std::string providerId;
};

//-------------------------------- Autres définitions dépendantes de <ExternalCompany>

#endif // EXTERNAL_COMPANY_H

