
//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H


#include <string>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    std::string getRole();


//------------------------------------------------- Surcharge d'opérateurs
    User & operator = ( const User & unUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    User ( std::string userId, std::string password, std::string role );
    // Mode d'emploi :
    //
    // Contrat :
    //

    User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string userId;
    std::string password;
    std::string role;

};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // USER_H

