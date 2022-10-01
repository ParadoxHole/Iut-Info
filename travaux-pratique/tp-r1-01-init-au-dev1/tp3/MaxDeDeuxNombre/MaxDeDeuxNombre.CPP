/*
 Programme : MaxDeTroisNombre
 But : Trouver le plus grand nombre parmis 3 nombre
 Date de dernière modification : 23/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float nombre1; // nombre1 saisie par l'utilisateur
    float nombre2; // nombre2 saisie par l'utilisateur
    float max; // le plus grand des deux nombres

    // TRAITEMENTS

    // clavier >> saisirNombres >> nombre1,nombre2 ***************************************************
    // clavier >> saisirNombre1>> nombre1
    cout << "Saisir le nombre1: ";
    cin >> nombre1;
    // clavier >> saisirNombre2 >> nombre2
    cout << "Saisir le nombre2: ";
    cin >> nombre2;

    // nombre1, nombre2 >> trouverNbPLusGrand >> max***************************************************
    if(nombre1 > nombre2){
        max = nombre1;
    }else if (nombre1 < nombre2){
        max = nombre2;
    }

    // nombre1, nombre2, max >> afficherResultat >> écran**********************************************
    if (nombre1 == nombre2){
        cout << "les 2 nombres sont egaux";
    }else{
        cout << "le nombre le plus grand est : " << max << endl;
    }

    return 0;
}