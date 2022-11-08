/*
 Programme : vainqueurCourse
 But : la tortue et le lièvre ta capté
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include "game-tools.h"
#include <iostream>
using namespace std;

string vainqueur();
// la tortue et le lièvre ta capté

int main(void)
{
    // TRAITEMENTS
    for(unsigned short int i=0 ; i < 15 ; i++)
    {
        cout << vainqueur() << endl;
    }
    return 0;
}

string vainqueur()
// la tortue et le lièvre ta capté
{
    // VARIABLES
    unsigned short int de;          // variables du dé
    unsigned short int tortue = 0;  // la variable de la tortue

    // TRAITEMENTS
    while(tortue < 6 && de != 6 )
    {
        de = static_cast<unsigned short int>(random(1, 6));
        if (de<6)
        {
            tortue = static_cast<unsigned short int>(tortue + de);
        }
    }
    return de == 6 ? "lievre" : "tortue";
}