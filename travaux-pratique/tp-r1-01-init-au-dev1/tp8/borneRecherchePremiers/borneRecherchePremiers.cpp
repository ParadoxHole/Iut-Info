/*
 Programme : borneRecherchePremiers
 But : 
 Date de dernière modification : 27/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
#include <math.h>
using namespace std;

void borneRecherchePremiers(bool tab[], int tailleTab);
/*calculé combien d'etudiant ont eu la moyenne et combien n'ont pas eu la moyenne*/

int main(void)
{
    // VARIABLES
    const unsigned int tailleTab = 10000;
    bool tableau[tailleTab];

    borneRecherchePremiers(tableau, tailleTab);

    for(int i = 0; i < tailleTab; i++)
    {
        if(tableau[i])
        {
            cout << i << " ";
        }
    }


    return 0;
}

void borneRecherchePremiers(bool tab[], int tailleTab)
{
    tab[0] = false;
    tab[1] = false;

    for(int i = 2; i < tailleTab; i++)
    {
        tab[i] = true;
    }

    for (int i = 0; i < sqrt(tailleTab); i++)
    {
        if (tab[i])
        {
            for(int j = i + 1; j < tailleTab; j++)
            {
                if(j % i == 0)
                {
                    tab[j]=false;
                }
            }
        }
    }
}