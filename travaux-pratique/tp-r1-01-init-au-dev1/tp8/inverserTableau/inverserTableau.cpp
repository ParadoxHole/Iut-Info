/*
 Programme : inverserTableau
 But : inverser les valeurs d'un tableau
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void inverserTableau(int tableau[],short unsigned int nombreCases);
/*inverser les valeurs d'un tableau*/

void afficherTableau(const int tab[],int nbCases);
/*afficher un tableau joliment*/

void echangerDeuxCasesTableau(int& entier1, int& entier2);
/*afficher un prix réduit*/

int main(void)
{
    // VARIABLES
    const short unsigned int NB_CASES = 7;
    int tab[NB_CASES] = {56,87,-28,12,2,-4,8};

    // TRAITEMENTS
    afficherTableau(tab,NB_CASES);
    inverserTableau(tab,NB_CASES);
    afficherTableau(tab,NB_CASES);
    return 0;
}

void inverserTableau(int tableau[],short unsigned int nombreCases)
{
    for(int i = 0 ; i < nombreCases/2 ; i++)
    {
        echangerDeuxCasesTableau(tableau[i],tableau[nombreCases-1-i]);
    }
}

void afficherTableau(const int tab[],int nbCases)
{
    cout << "[";
    for (int i = 0; i < nbCases; i++)
    {
        cout << tab[i] << " ";
    }
    cout <<"]"<< endl;
}

void echangerDeuxCasesTableau(int& entier1, int& entier2)
{
    int copieEntier1 = entier1;
    entier1 = entier2;
    entier2 = copieEntier1;
}