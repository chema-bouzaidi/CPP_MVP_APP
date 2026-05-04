#ifndef CONTROLEURADMIN_H
#define CONTROLEURADMIN_H

#include "Controleur.h"
#include "User.h"
#include "Admin.h"

class ControleurAdmin : public Controleur {
public:
    ControleurAdmin(InterfaceUtilisateur& vue, Modele& modele)
        : Controleur(vue, modele) {}

    void run();
    void createUser(const User& user);
    void deleteUser(const User& user);
    void banUser(const User& user);
protected:
    Admin currentAdmin;
};

#endif
