#include "ControleurAdmin.h"
#include "../Model/Modele.h"
#include "../Model/Admin.h"
#include "../Model/Agency.h"
#include "../Model/Provider.h"
#include "../Model/PrivateIndividual.h"
#include "../Model/PrivateSensor.h"
#include "../Vue/InterfaceUtilisateur.h"

#include <iostream>
#include <vector>

void ControleurAdmin::run()
{
    vue.displayMessage("Connecte en tant qu'Administrateur : " + currentUser->getUserId());

    bool running = true;
    while (running)
    {
        int choice = vue.displayMenu("Menu Admin",
            {"Lister les utilisateurs",
             "Creer un utilisateur (demo)",
             "Supprimer un utilisateur",
             "Bannir un utilisateur (marquer hors service)",
             "Se deconnecter"});

        switch (choice)
        {
        case 1:
        {
            vue.displayTitle("Liste des utilisateurs");
            for (User* u : modele.getUsers())
                std::cout << "  " << u->getUserId() << " | role=" << u->getRole() << "\n";
            break;
        }
        case 2:
        {
            int typeChoice = vue.displayMenu("Type d'utilisateur a creer",
                {"Admin",
                 "Agency (agence gouvernementale)",
                 "Provider (entreprise / fournisseur de purificateurs)",
                 "PrivateIndividual (particulier)"});

            std::string id  = vue.readString("Identifiant : ");
            std::string pwd = vue.readString("Mot de passe : ");

            if (typeChoice == 1)
            {
                std::string adminId = vue.readString("AdminID interne : ");
                modele.getUsers().push_back(new Admin(id, pwd, "admin", adminId));
            }
            else if (typeChoice == 2)
            {
                std::string agencyId = vue.readString("AgencyID interne : ");
                modele.getUsers().push_back(new Agency(id, pwd, "agency", agencyId));
            }
            else if (typeChoice == 3)
            {
                std::string name = vue.readString("Nom de l'entreprise : ");
                Provider* p = new Provider(id, pwd, name);
                modele.getProviders().push_back(p);
                modele.getUsers().push_back(p);
            }
            else if (typeChoice == 4)
            {
                std::string privateId = vue.readString("PrivateID interne : ");
                std::string sensorId  = vue.readString("ID du capteur prive : ");
                modele.getUsers().push_back(
                    new PrivateIndividual(id, pwd, "private", privateId, 0, sensorId));
            }
            else
            {
                vue.displayError("Type invalide, utilisateur non cree.");
                break;
            }

            vue.displayMessage("Utilisateur '" + id + "' cree.");
            break;
        }
        case 3:
        {
            std::string id = vue.readString("Identifiant a supprimer : ");
            User* u = modele.findUserById(id);
            if (!u) { vue.displayError("Utilisateur introuvable."); break; }
            deleteUser(*u);
            break;
        }
        case 4:
        {
            std::string id = vue.readString("Identifiant a bannir : ");
            User* u = modele.findUserById(id);
            if (!u) { vue.displayError("Utilisateur introuvable."); break; }
            banUser(*u);
            break;
        }
        case 5:
            running = false;
            break;
        default:
            vue.displayError("Choix invalide.");
        }
    }
}

void ControleurAdmin::createUser(const User& user)
{
    vue.displayMessage("Utilisateur cree : " + user.getUserId());
}

void ControleurAdmin::deleteUser(const User& user)
{
    modele.getUsers().remove_if([&user](User* u) {
        return u->getUserId() == user.getUserId();
    });
    vue.displayMessage("Utilisateur supprime : " + user.getUserId());
}

void ControleurAdmin::banUser(const User& user)
{
    User* u = modele.findUserById(user.getUserId());
    PrivateIndividual* pi = dynamic_cast<PrivateIndividual*>(u);
    if (!pi)
    {
        vue.displayError("Seul un particulier (PrivateIndividual) peut etre banni.");
        return;
    }
    pi->ban();
    Sensor* s = modele.findSensorById(pi->getSensorId());
    PrivateSensor* ps = dynamic_cast<PrivateSensor*>(s);
    if (ps) ps->flagAsUnreliable();
    vue.displayMessage("Particulier banni et capteur marque non-fiable : " + user.getUserId());
}
