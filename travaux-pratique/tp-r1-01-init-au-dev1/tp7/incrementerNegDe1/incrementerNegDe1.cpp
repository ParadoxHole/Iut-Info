/*
 Programme : incrementerNegDe1
 But : incrementer les chiffres Negatif De 1
 Date de dernière modification : 20/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    const unsigned short int NB_CASES = 6;      // nombre de cases du tableau
    short int tab[NB_CASES] = {5, -8, 9, -64, 5, -4}; // tableau à afficher

    // TRAITEMENTS
    // NB_CASES, tab >> incrementerNegDe1 >> ecran ***************************************************
    for (unsigned short int i = 0; i < NB_CASES; i++)
    {
        if (tab[i] < 0)
        {
            tab[i]++;
        }

        cout << tab[i] << " ";
    }

    return 0;
}