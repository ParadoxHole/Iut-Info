/*
 Programme : calculerPrixReduit
 But : calculer prix réduit 
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void calculerPrixReduit(float prix, float reduc, float& prixReduit);
/*afficher un prix réduit*/

int main(void)
{
    // VARIABLES
    float prix = 17.50;
    float reduc = 50;
    float prixReduit;

    // TRAITEMENTS
    calculerPrixReduit(prix, reduc,prixReduit);
    cout << prixReduit;
    return 0;
}

void calculerPrixReduit(float prix, float reduc, float& prixReduit)
/*afficher un prix réduit*/
{
    prixReduit = prix - (prix * (reduc/100)); //calcul de la réduction
}