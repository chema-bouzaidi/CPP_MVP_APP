
//---------- Interface de la classe <PrivateIndividual> (fichier PrivateIndividual.h) ----------------
#if ! defined ( PRIVATE_INDIVIDUAL_H )
#define PRIVATE_INDIVIDUAL_H


#include <string>
#include "User.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateIndividual>
//
//
//------------------------------------------------------------------------

class PrivateIndividual: public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    PrivateIndividual & operator = ( const PrivateIndividual & unPrivateIndividual );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PrivateIndividual ( const PrivateIndividual & unPrivateIndividual );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PrivateIndividual (  std::string userId, std::string password, std::string role, std::string privateId, int points );
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateIndividual ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PrivateIndividual ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string privateId;
    int points;
    bool isReliable;

};

//-------------------------------- Autres définitions dépendantes de <PrivateIndividual>

#endif // PRIVATE_INDIVIDUAL_H

