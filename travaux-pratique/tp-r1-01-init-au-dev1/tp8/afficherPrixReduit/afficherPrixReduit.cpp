/*
 Programme : afficherPrixReduit
 But : afficher prix réduit 
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void calclerPrixReduit(float prix, float reduc);
/*afficher un prix réduit*/

int main(void)
{
    // TRAITEMENTS
    calclerPrixReduit(17.50, 50);
    return 0;
}

void calclerPrixReduit(float prix, float reduc)
/*afficher un prix réduit*/
{
    cout << "le prix reduit de " << prix << " a " << reduc << "\% est " << prix - (prix * (reduc/100));
}