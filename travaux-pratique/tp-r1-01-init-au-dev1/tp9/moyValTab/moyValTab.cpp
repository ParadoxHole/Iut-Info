/*
 Programme : moyValTab
 But :  moyenne des valeurs d'un tableau de nombres
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void afficherTableau(const float tab[],unsigned short int nbCases);
/*afficher un tableau joliment*/

float moy(const float notes[],unsigned short int NB_CASES);
// moyenne des valeurs d'un tableau de nombres

int main(void)
{
    //VARIABLES
    const unsigned short int nb = 5;
    float tab[nb]={5,12,14,9,5};

    // TRAITEMENTS
    afficherTableau(tab,nb);
    cout << "la moyenne est " << moy(tab,nb);

    return 0;
}

void afficherTableau(const float tab[],unsigned short int nbCases)
{
    cout << "[";
    for (int i = 0; i < nbCases; i++)
    {
        cout << tab[i] << " ";
    }
    cout <<"]"<< endl;
}

float moy(const float notes[],unsigned short int NB_CASES)
// moyenne des valeurs d'un tableau de nombres
{
    //VARIABLES
    float somme = 0; //la somme des notes 

    // TRAITEMENTS
    for(unsigned short int i=0 ; i < NB_CASES ; i++)
    {
        somme += notes[i];
    }
    return somme/static_cast<float>(NB_CASES);
}