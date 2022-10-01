/*
 Programme : NumeroTP
 But :  Renvoie le signe d'un nombre
 Date de dernière modification : 20/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int TP; // numero du TP saisie par l'utilisateur

    // TRAITEMENTS
    // clavier >> saisirTP >> TP *******************************************
    cout << "Saisir votre numero de TD:  ";
    cin >> TP;

    // signe >> afficherTD >> écran *****************************************
    if(TP>0 && TP<=2){
        cout << "Vous etes dans le TD I";
    }else if(TP>2 && TP<=4){
        cout << "Vous etes dans le TD II";
    }else if (TP == 5){
        cout << "Vous etes dans le TD III";
    }else{
        cout << "qui etes vous sortez de ce batiment ou j'appelle la police";
    }

    return 0;
}