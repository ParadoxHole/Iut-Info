/*
 Programme : valeurAbsolue
 But : trouver la valeur absolue
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

double valAbs(double nb);
//retourne la veleur absolue d'un nombre

int main(void)
{
    // VARIABLES
    double nb = -5.6; // un nombre juste une nombre qui est cool et vraiment swag
    
    // TRAITEMENTS
    cout << "valeur absolue de "<< nb << " est : " << valAbs(nb) << endl;
    return 0;
}

double valAbs(double nb)
//retourne la veleur absolue d'un nombre
{
    return nb < 0 ? -nb : nb ;
}