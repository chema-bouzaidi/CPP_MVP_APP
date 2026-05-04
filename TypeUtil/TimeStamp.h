/*************************************************************************
                           TimeStamp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( TIMESTAMP_H )
#define TIMESTAMP_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TimeStamp>
//
//
//------------------------------------------------------------------------

class TimeStamp 
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
    TimeStamp & operator = ( const TimeStamp & uneTimeStamp );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TimeStamp ( const TimeStamp & uneTimeStamp );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TimeStamp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    TimeStamp (std::string dateStr);
    // Mode d'emploi :
    // a partir d'une chaine de caracteres de format "YEAR-MONTH-DAY HOUR-MIN-SEC"
    // Contrat :
    //

    virtual ~TimeStamp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string toString() const;

    bool operator <=(const TimeStamp& t) const;
    bool operator >=(const TimeStamp& t) const;
    bool operator <(const TimeStamp& t) const;
    bool operator >(const TimeStamp& t) const;



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    std::string date;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // TimeStamp_H

