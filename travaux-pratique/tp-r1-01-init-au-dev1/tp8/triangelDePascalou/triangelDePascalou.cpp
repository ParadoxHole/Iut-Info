/*
 Programme : triangleDePascalou
 But : héhéhé c'est po bien de faire so, hey mon ami ta tu vus le super triangle de mon bonne ami pascal
 Date de dernière modification : 27/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
#include <math.h>
using namespace std;

void triangleDePascalou(int tailleTab);
/*calculé combien d'etudiant ont eu la moyenne et combien n'ont pas eu la moyenne*/

int main(void)
{
    // VARIABLES
    const unsigned int tailleTab = 10;

    triangleDePascalou(tailleTab);

    return 0;
}

void triangleDePascalou(int tailleTab)
{
    for(int i = 0; i < tailleTab; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout <<endl;
    }
}