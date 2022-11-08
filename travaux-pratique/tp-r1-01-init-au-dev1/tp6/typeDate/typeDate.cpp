/*
 Programme : afficherTriangleInverser
 But :  afficher un truc moche nul
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    enum unMois{janvier,favrarier,marks,april,may,jouin,jouillai,out,setambre,Octobri,novembre,Diciambre};
    struct UneDate{
        unsigned short int jour;
        unMois mois;
        int annee;
    };

    UneDate date1;

    cout << "Renseignez le jour";
    cin >> date1.jour;
    cout << "Renseignez le mois";

    cout << "Renseignez le annee";
    cin >> date1.annee;


    // TRAITEMENTS
    // clavier >> saisirnbTemperature >> temperatures *******************************************************


    return 0;
}