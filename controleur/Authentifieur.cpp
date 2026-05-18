#include "Authentifieur.h"
#include "ControleurAdmin.h"
#include "ControleurAgence.h"
#include "ControleurEntreprise.h"
#include "ControleurActeurPrive.h"
#include "../Model/Modele.h"
#include "../Model/PrivateIndividual.h"
#include "../Vue/InterfaceUtilisateur.h"

#include <iostream>
#include <string>

void Authentifieur::run()
{
    vue.displayMessage("=== Bienvenue sur AirWatcher ===");
    vue.displayMessage("(tapez 'quit' comme identifiant pour quitter)\n");

    while (true)
    {
        std::pair<std::string,std::string> creds = vue.readCredentials();
        std::string id  = creds.first;
        std::string pwd = creds.second;
        if (id == "quit") break;

        if (login(id, pwd))
        {
            User* user = modele.findUserById(id);
            std::string role = user->getRole();

            vue.displayMessage("Connexion reussie ! Role : " + role);

            if (role == "admin")
            {
                ControleurAdmin ctrl(vue, modele, user);
                ctrl.run();
            }
            else if (role == "agency")
            {
                ControleurAgence ctrl(vue, modele, user);
                ctrl.run();
            }
            else if (role == "provider")
            {
                ControleurEntreprise ctrl(vue, modele, user);
                ctrl.run();
            }
            else if (role == "private")
            {
                PrivateIndividual* pi = dynamic_cast<PrivateIndividual*>(user);
                ControleurActeurPrive ctrl(vue, modele, pi);
                ctrl.run();
            }
        }
        else
        {
            vue.displayError("Identifiant ou mot de passe incorrect.");
        }
    }

    vue.displayMessage("\nAu revoir !");
}

bool Authentifieur::login(const std::string& id, const std::string& pwd)
{
    return modele.authenticateUser(id, pwd) != nullptr;
}

void Authentifieur::logout()
{
    vue.displayMessage("Deconnexion.");
}
