//---------- Réalisation de la classe <Admin> (fichier Admin.cpp) ----------------

#include "Admin.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Admin & Admin::operator = ( const Admin & unAdmin )
{
    if ( this != &unAdmin )
    {
        User::operator=( unAdmin );   // copie des attributs de User
        adminId = unAdmin.adminId;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Admin::Admin ( const Admin & unAdmin )
    : User( unAdmin ),
      adminId( unAdmin.adminId )
{
}

Admin::Admin ( )
    : User( ),
      adminId( "" )
{
}

Admin::Admin (  std::string userId, std::string password, std::string role, std::string adminId )
    : User( userId, password, role ),
      adminId( adminId )
{
}

Admin::~Admin ( )
{
}
