
//---------- Interface de la classe <Admin> (fichier Admin.h) ----------------
#if ! defined ( ADMIN_H )
#define ADMIN_H

#include <string>
#include "User.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Admin>
//
//
//------------------------------------------------------------------------

class Admin: public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    Admin & operator = ( const Admin & unAdmin );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Admin ( const Admin & unAdmin );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Admin (  std::string userId, std::string password, std::string role, std::string adminId );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Admin ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Admin ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string adminId;

};

//-------------------------------- Autres définitions dépendantes de <Admin>

#endif // ADMIN_H

