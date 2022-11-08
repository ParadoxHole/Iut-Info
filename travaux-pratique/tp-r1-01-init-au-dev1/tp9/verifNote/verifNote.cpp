/*
 Programme : verifNote
 But : Vérifié si un nombre est une note ou pas
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

bool estUneNote(double nb);
// Vérifié si un nombre est une note ou pas

int main(void)
{
    // VARIABLES
    double nb = 5.6; // un nombre juste une nombre qui est cool et vraiment swag

    // TRAITEMENTS
    if(estUneNote(nb))
    {
        cout << "ce nombre est note";
    }else{
        cout << "pas une note";
    }
    return 0;
}

bool estUneNote(double nb)
// Vérifié si un nombre est une note ou pas
{
    return nb <= 20 && nb >=0;
}