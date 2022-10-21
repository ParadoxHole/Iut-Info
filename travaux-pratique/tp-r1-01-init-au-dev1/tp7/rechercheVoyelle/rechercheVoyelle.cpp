/*
 Programme : rechercheVoyelle
 But : recherche d'une voyelle dans une chaîne de charactère
 Date de dernière modification : 21/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    string mot = "heheheha";                          // le mot
    char voyelle[6] = {'a', 'e', 'i', 'o', 'u', 'y'}; // tableau qui contiente TOUTEs les voyelles TOUTEs
    short unsigned int prVoyelle;                     // la position de la première voyelle
    short unsigned int drVoyelle;                     // la position de la dernière voyelle

    // TRAITEMENTS
    // prVoyelle, mot, voyelle[] >> trouverPremierVoyelle >> prVoyelle ******************************************
    for (unsigned short int i = 0; i < mot.size(); i++)
    {
        if ((mot[i] == voyelle[0] || mot[i] == voyelle[1] || mot[i] == voyelle[2] || mot[i] == voyelle[3] || mot[i] == voyelle[4] || mot[i] == voyelle[5]) && prVoyelle == 0)
        {
            prVoyelle = i;
        }
    }
    // prVoyelle >> afficherPremierVoyelle >> ecran ************************************************
    cout << "La premiere voyelle: " << prVoyelle << endl;

    // mot, voyelle[] >> afficherPosVoyelle >> ecran ******************************************
    cout << "la position des voyelles: " << endl;
    for (unsigned short int i = 0; i < mot.size(); i++)
    {
        if (mot[i] == voyelle[0] || mot[i] == voyelle[1] || mot[i] == voyelle[2] || mot[i] == voyelle[3] || mot[i] == voyelle[4] || mot[i] == voyelle[5])
        {
            cout << i << " ";
        }
    }

    // drVoyelle, mot, voyelle[] >> trouverDerniereVoyelle >> drVoyelle ******************************************
    for (unsigned short int i = 0; i < mot.size(); i++)
    {
        if (mot[i] == voyelle[0] || mot[i] == voyelle[1] || mot[i] == voyelle[2] || mot[i] == voyelle[3] || mot[i] == voyelle[4] || mot[i] == voyelle[5])
        {
            drVoyelle = i;
        }
    }
    // prVoyelle >> afficherPremierVoyelle >> ecran ************************************************
    cout << endl
         << "La derniere voyelle: " << drVoyelle;

    return 0;
}