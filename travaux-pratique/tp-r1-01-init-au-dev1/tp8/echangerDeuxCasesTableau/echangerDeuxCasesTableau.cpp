/*
 Programme : echangerDeuxCasesTableau
 But : echanger Deux Cases Dans Un Tableau d'entiers 
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void echangerDeuxCasesTableau(int& entier1, int& entier2);
/*echanger Deux Cases Dans Un Tableau d'entiers*/

int main(void)
{
    // VARIABLES
    const short unsigned int NB_CASES = 5;
    int tab[NB_CASES] = {56,87,28,12,2};

    // TRAITEMENTS
    cout << tab[2] <<" "<< tab[3]<< endl;
    echangerDeuxCasesTableau(tab[2], tab[3]);
    cout << tab[2] <<" "<< tab[3];
    return 0;
}

void echangerDeuxCasesTableau(int& entier1, int& entier2)
{
    int copieEntier1 = entier1;
    entier1 = entier2;
    entier2 = copieEntier1;
}