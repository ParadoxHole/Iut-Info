/*
 Programme : moyenneValTab
 But : moyenne des Valeurs Tableau
 Date de dernière modification : 20/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    const unsigned short int NB_CASES = 6;        // nombre de cases du tableau
    float tab[NB_CASES] = {5, -8, 9, -64, 5, -4}; // tableau à afficher
    float somme;                                  // moyenne des valeurs tableau ajouté
    float resultat;                               // moyenne des Valeurs Tableau

    // TRAITEMENTS
    // NB_CASES, tab >> moyenneValTab >> somme ***************************************************
    for (unsigned short int i = 0; i < NB_CASES; i++)
    {
        somme += tab[i];
    }

    // resultat, somme, NB_CASES >> calculerResultat *********************************************
    resultat = somme / NB_CASES;

    // resultat >> afficherResultat >> ecran *****************************************************
    cout << resultat;

    return 0;
}