/*************************************************************************
                           Period  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( PERIOD_H )
#define PERIOD_H
#include "TimeStamp.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Period>
//
//
//------------------------------------------------------------------------

class Period 
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
    Period & operator = ( const Period & unePeriod );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Period ( const Period & unePeriod );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Period ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Period ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool contains(TimeStamp tStart, TimeStamp tEnd);
    // Mode d'emploi :
    // vérifie si dans ce TimeStamp est compris le startDate et le endDate
    // Contrat :
    //
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TimeStamp startDate;
    TimeStamp endDate;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // PERIOD_H
