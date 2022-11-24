/*  CORPS du Module Personne
     contient la définition du type Personne
     -------------------------------------------*/

#include "personne.h"
#include <iostream>
using namespace std;

/* Corps des sous-programmes déclarés dans l'Interface du module
-----------------------------------------------------------------*/

void afficher (const Personne& personne)
{
    cout << "  {" << personne.nom << ", " << personne.prenom << ", { " ;
    cout <<        personne.adresse.numRue << ", " ;
    cout <<        personne.adresse.nomRue << ", ";
    cout <<        personne.adresse.codePostal << ", ";
    cout <<        personne.adresse.nomVille << " }";
    cout << "}";
}