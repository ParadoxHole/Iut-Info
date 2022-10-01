/*
 Programme : saisiNote
 But :  demande une note
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float note; // La note saisie par l'utilisateur

    // TRAITEMENTS
    // clavier >> saisiEtVerifNote >> note ****************************************************
    while (true){
        // clavier >> saisirNote >> note
        cout << "Saisir une valeur entre 0 et 20: ";
        cin >> note;

        //note >> verifNote >> break
        if (note <= 20 && note >= 0){
            break;
        }
    }

    // signe >> afficherMerci >> écran ****************************************************
    cout << "Merci."<< endl;

    return 0;
}