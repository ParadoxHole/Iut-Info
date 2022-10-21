/*
 Programme : rechercheVoyelle
 But : recherche d'une voyelle dans une chaîne de charactère
 Date de dernière modification : 21/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    string mot;
    bool palindrome = true;


    // TRAITEMENTS
    cin >> mot;
    // NB_CASES, tab, tabInv >> inverserTableau >> tabInv ******************************************
    for (unsigned short int i = 0; i < (mot.size()/2); i++)
    {
        if (mot[i] != mot[mot.size()-1-i])
        {
            palindrome = false;
        } 
    }

    // NB_CASES, tabInv >> afficherTableau >> ecran ************************************************
    if (palindrome)
    {
        cout << "ce mot est un palindrome";
    }
    else
    {
        cout << "ce mot n'est pas un palindrome";
    }
    
    return 0;
}