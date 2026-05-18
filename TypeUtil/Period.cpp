/*************************************************************************
                           Period  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Period> (fichier Period.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Period.h"
#include "TimeStamp.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Period::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Period & Period::operator = ( const Period & unePeriod )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Period::Period ( const Period & unePeriod )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Period>" << endl;
#endif
} //----- Fin de Period (constructeur de copie)


Period::Period ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Period>" << endl;
#endif
} //----- Fin de Period


Period::~Period ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Period>" << endl;
#endif
} //----- Fin de ~Period

bool Period::contains (TimeStamp tStart, TimeStamp tEnd)
{
    bool start_apres = (this->startDate >= tStart);
    bool end_avant = (this->endDate <= tEnd);

    return (start_apres && end_avant);
} 


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
