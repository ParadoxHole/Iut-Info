/*
 Programme : afficherLigne
 But :  afficher le nombre de ligne entrez par l'utilisateur
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    unsigned int nombreLigne; // Le nombreLigne saisie par l'utilisateur
    int ligne; // Le nombre qui permet l'itération

    // TRAITEMENTS
    // clavier >> saisirnombreLigne >> nombreLigne *******************************************************
    cout << "Entrez un nombre de ligne à afficher: ";
    cin >> nombreLigne;

    // signe >> afficherLigne >> écran *******************************************************************
    for (ligne = 0 ; ligne < nombreLigne ; ligne++)
    {
        cout << "*****\n" ;
    }

    return 0;
}