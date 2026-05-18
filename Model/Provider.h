
//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H


#include <string>
#include <list>
#include "../TypeUtil/Period.h"
#include "Cleaner.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    std::list<Cleaner> getCleaners();

    void addCleaner(Cleaner cleaner);

    std::string getUserId() const;
    
    std::string getPassword() const;
//------------------------------------------------- Surcharge d'opérateurs
    Provider & operator = ( const Provider & unProvider );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Provider ( const Provider & unProvider );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Provider ( std::string providerId, std::string name );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    std::string providerId;
    std::string name;
    std::list<Cleaner> cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H

