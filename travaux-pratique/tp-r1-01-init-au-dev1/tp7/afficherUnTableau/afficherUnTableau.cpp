/*
 Programme : afficherUnTableau
 But : afficher un tableau
 Date de dernière modification : 20/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    const unsigned short int NB_CASES = 6;         // nombre de cases du tableau
    short int tab[NB_CASES] = {5, 8, 9, 64, 5, 4}; // tableau à afficher

    // TRAITEMENTS
    // NB_CASES, tab >> afficherTableau >> ecran ***************************************************
    for (int i = 0; i < NB_CASES; i++)
    {
        cout << tab[i] << " ";
    }

    return 0;
}