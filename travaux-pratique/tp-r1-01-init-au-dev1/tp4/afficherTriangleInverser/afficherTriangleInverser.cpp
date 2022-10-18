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
    int nbDeLignes; // La nombre de ligne saisie par l'utilisateur
    const string ETOILE = "*"; // c'est une étoile

    // TRAITEMENTS
    // clavier >> saisirnbDeLignes >> nbDeLignes *******************************************************
    cout << "Entrez un nombre de ligne à afficher: ";
    cin >> nbDeLignes;

    // clavier >> saisiEtVerifNote >> note *************************************************
    for (int i = nbDeLignes; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            cout << ETOILE;
        }
        cout << endl;
    }

    return 0;
}