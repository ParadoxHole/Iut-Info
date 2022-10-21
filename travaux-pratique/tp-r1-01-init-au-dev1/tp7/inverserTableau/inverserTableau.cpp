/*
 Programme : inverserTableau
 But : inverser un Tableau
 Date de dernière modification : 21/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    const unsigned short int NB_CASES = 7;      // nombre de cases du tableau
    short int tab[NB_CASES] = {7, 3, 6, 1, 8, 4, 2}; // tableau à afficher
    short int tabInv[NB_CASES]; // le tableau qui permet l'inversion du tableau original

    // TRAITEMENTS
    // NB_CASES, tab, tabInv >> inverserTableau >> tabInv ******************************************
    for (unsigned short int i = 0; i < NB_CASES; i++)
    {
        tabInv[i] = tab[NB_CASES-1-i];
    }

    // NB_CASES, tabInv >> afficherTableau >> ecran ************************************************
    for (int i = 0; i < NB_CASES; i++)
    {
        cout << tabInv[i] << " ";
    }

    return 0;
}