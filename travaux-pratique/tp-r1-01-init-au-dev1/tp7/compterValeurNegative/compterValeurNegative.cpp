/*
 Programme : compterValeurNegative
 But : compter le nombre de valeur negative
 Date de dernière modification : 20/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    const short int NB_CASES = 6;                     // nombre de cases du tableau
    short int tab[NB_CASES] = {5, -8, 9, -64, 5, -4}; // tableau à afficher
    unsigned short int nbValeurNegative = 0;          // nombre de valeur negative

    // TRAITEMENTS
    // NB_CASES, tab >> compterValeurNegative >> nbValeurNegative ***************************************************
    for (int i = 0; i < NB_CASES; i++)
    {
        if (tab[i] < 0)
        {
            nbValeurNegative++;
        }
    }

    // nbValeurNegative >> afficherValeurNegative >> ecran **********************************************************
    cout << nbValeurNegative;

    return 0;
}