/*
 Programme : echangerDeuxEntiers
 But : echanger deux entiers 
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void echangerDeuxEntiers(int& entier1, int& entier2);
/*echanger deux entiers */

int main(void)
{
    // VARIABLES
    int nb1 = 12;
    int nb2 = 50;

    // TRAITEMENTS
    cout << nb1 <<" "<< nb2<< endl;
    echangerDeuxEntiers(nb1, nb2);
    cout << nb1 <<" "<< nb2;
    return 0;
}

void echangerDeuxEntiers(int& entier1, int& entier2)
{
    // VARIABLES
    int copieEntier1 = entier1;

    // TRAITEMENTS
    entier1 = entier2;
    entier2 = copieEntier1;
}