/*
 Programme : sommeEntier
 But :  afficher la somme des entier de 1 et une borne entrée par l'utilisateur
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nombre; //nombre entré par l'utilisateur 
    int i; // es por la bouclos

    // TRAITEMENTS
    // clavier >> saisiNombre >> nombre ************************************************************
    cout << "Entrez un nombre et les 5 suivant s'afficheront: ";
    cin >> nombre;

    // i, nombre >> afficherNombres >> ecran *********************************
    for (i = nombre ; i < nombre+6 ; i++)
    {
        cout << i << "; ";
    }

    return 0;
}