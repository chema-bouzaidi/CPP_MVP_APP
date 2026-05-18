#ifndef CONTROLEURADMIN_H
#define CONTROLEURADMIN_H

#include "Controleur.h"
#include "../Model/User.h"
#include "../Model/Admin.h"

class ControleurAdmin : public Controleur {
public:
    ControleurAdmin(InterfaceUtilisateur& vue, Modele& modele, User* user)
        : Controleur(vue, modele), currentUser(user) {}

    void run();
    void createUser(const User& user);
    void deleteUser(const User& user);
    void banUser(const User& user);
protected:
    User* currentUser;
};

#endif
