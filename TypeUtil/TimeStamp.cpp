/*************************************************************************
                           TimeStamp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TimeStamp> (fichier TimeStamp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TimeStamp.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TimeStamp::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
TimeStamp & TimeStamp::operator = ( const TimeStamp & uneTimeStamp )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TimeStamp::TimeStamp ( const TimeStamp & uneTimeStamp )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TimeStamp>" << endl;
#endif
} //----- Fin de TimeStamp (constructeur de copie)


TimeStamp::TimeStamp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TimeStamp>" << endl;
#endif
} //----- Fin de TimeStamp

TimeStamp::TimeStamp ( ) : date(""){}


TimeStamp::~TimeStamp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TimeStamp>" << endl;
#endif
} //----- Fin de ~TimeStamp

std::string TimeStamp::toString() const
{
    return this->date;
}

bool TimeStamp::operator<=(const TimeStamp& t) const
{
    return this->date <= t.date;
}

bool TimeStamp::operator>=(const TimeStamp& t) const
{
    return this->date >= t.date;
}

bool TimeStamp::operator<(const TimeStamp& t) const
{
    return this->date < t.date;
}

bool TimeStamp::operator>(const TimeStamp& t) const
{
    return this->date > t.date;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées