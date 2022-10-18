/*
 Programme : afficherTriangleInverser
 But :  afficher un truc moche nul
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    const unsigned int NB_CASES = 10; // Taille du tableau
    float temperatures [NB_CASES]; // Déclaration du tableau des temperature

    // TRAITEMENTS
    // clavier >> saisirnbTemperature >> temperatures *******************************************************
    for (int i= NB_CASES; i >= 0 ;i--){
        cout << "Entrez une temperature : \n";
        cin >> temperatures[i];
    }
    for(int i=0;i <= NB_CASES; i++){
        cout << "\ntemperture:";
        cout << temperatures[i];
    }

    return 0;
}