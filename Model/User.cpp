//---------- Réalisation de la classe <User> (fichier User.cpp) ----------------

#include "User.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
User & User::operator = ( const User & unUser )
{
    if ( this != &unUser )
    {
        userId   = unUser.userId;
        password = unUser.password;
        role     = unUser.role;
    }
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
User::User ( const User & unUser )
    : userId( unUser.userId ),
      password( unUser.password ),
      role( unUser.role )
{
}

User::User ( std::string userId, std::string password, std::string role )
    : userId( userId ),
      password( password ),
      role( role )
{
}

User::User ( )
    : userId( "" ),
      password( "" ),
      role( "" )
{
}

User::~User ( )
{
}

//------------------------------------------------------- Méthodes publiques
std::string User::getRole ( )
{
    return role;
}
