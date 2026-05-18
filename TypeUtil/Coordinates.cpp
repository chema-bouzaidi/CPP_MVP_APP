/*************************************************************************
                           Coordinates  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Coordinates> (fichier Coordinates.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordinates.h"
#include <cmath>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Coordinates::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Coordinates & Coordinates::operator = ( const Coordinates & uneCoordinates )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Coordinates::Coordinates ( const Coordinates & uneCoordinates )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Coordinates>" << endl;
#endif
} //----- Fin de Coordinates (constructeur de copie)


Coordinates::Coordinates ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Coordinates>" << endl;
#endif
} //----- Fin de Coordinates


Coordinates::~Coordinates ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Coordinates>" << endl;
#endif
} //----- Fin de ~Coordinates

float Coordinates::distanceto (const Coordinates & unCoordinates)
{
    // on multiplie par 111 et par 77 par en France 1 degre de latitude est  environ egal a 111km
    // et un degre de longitude vaut environ 77 km (sinon on aurait la distance en degrés)
    float dy = (this->latitude - unCoordinates.latitude) * 111.0f;
    float dx = (this->longitude - unCoordinates.longitude) * 77.0f;

    return std::sqrt(dx*dx + dy*dy);
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
