//---------- Réalisation de la classe <Agency> (fichier Agency.cpp) ----------------

#include "Agency.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Agency & Agency::operator = ( const Agency & unAgency )
{
    if ( this != &unAgency )
    {
        User::operator=( unAgency );
        agencyId = unAgency.agencyId;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Agency::Agency ( const Agency & unAgency )
    : User( unAgency ),
      agencyId( unAgency.agencyId )
{
}

Agency::Agency (  std::string userId, std::string password, std::string role, std::string agencyId )
    : User( userId, password, role ),
      agencyId( agencyId )
{
}

Agency::Agency ( )
    : User( ),
      agencyId( "" )
{
}

Agency::~Agency ( )
{
}