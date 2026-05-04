//---------- Réalisation de la classe <ExternalCompany> (fichier ExternalCompany.cpp) ----------------

#include "ExternalCompany.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
ExternalCompany & ExternalCompany::operator = ( const ExternalCompany & unExternalCompany )
{
    if ( this != &unExternalCompany )
    {
        User::operator=( unExternalCompany );
        companyId  = unExternalCompany.companyId;
        providerId = unExternalCompany.providerId;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
ExternalCompany::ExternalCompany ( const ExternalCompany & unExternalCompany )
    : User( unExternalCompany ),
      companyId( unExternalCompany.companyId ),
      providerId( unExternalCompany.providerId )
{
}

ExternalCompany::ExternalCompany ( std::string userId, std::string password, std::string role, std::string companyId, std::string providerId )
    : User( userId, password, role ),
      companyId( companyId ),
      providerId( providerId )
{
}

ExternalCompany::ExternalCompany ( )
    : User( ),
      companyId( "" ),
      providerId( "" )
{
}

ExternalCompany::~ExternalCompany ( )
{
}