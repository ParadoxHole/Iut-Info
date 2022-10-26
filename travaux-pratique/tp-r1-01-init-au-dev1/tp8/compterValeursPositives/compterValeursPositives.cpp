/*
 Programme : compterValeursPositives
 But : compter le nombre de Valeurs Positives d'un tableau
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

void compterValeursPositives(const int tableau[],int nombreCases, int& nbValPositive);
/*compter le nombre de Valeurs Positives d'un tableau*/

int main(void)
{
    // VARIABLES
    const short unsigned int NB_CASES = 6;
    int tab[NB_CASES] = {56,87,-28,12,2,-4};
    int nbValPositive;

    // TRAITEMENTS
    cout << "[";
    for (int i = 0; i < NB_CASES; i++)
    {
        cout << tab[i] << " ";
    }
    cout <<"]"<< endl;
    compterValeursPositives(tab, NB_CASES,nbValPositive);
    cout << "ce tableau a : "<< nbValPositive << " valeur(s) positive(s)";
    return 0;
}

void compterValeursPositives(const int tableau[],int nombreCases, int& nbValPositive)
{
    for(int i = 0 ; i < nombreCases ; i++)
    {
        if (tableau[i] > 0)
        {
            nbValPositive++;
        }
    }
}