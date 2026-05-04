/*************************************************************************
                           Coordinates  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( COORDINATES_H )
#define COORDINATES_H
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Coordinates>
//
//
//------------------------------------------------------------------------

class Coordinates 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Coordinates & operator = ( const Coordinates & uneCoordinates );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Coordinates ( const Coordinates & uneCoordinates );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Coordinates ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Coordinates ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    float distanceto (const Coordinates & unCoordinates);
    // Mode d'emploi :
    // vérifie si dans ce TimeStamp est compris le startDate et le endDate
    // Contrat :
    //
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    float latitude;
    float longitude;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // COORDINATES_H
