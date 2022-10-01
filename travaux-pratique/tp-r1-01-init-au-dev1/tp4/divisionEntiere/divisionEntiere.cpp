/*
 Programme : divisionEntiere
 But : c'est la divison entière
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int dividende; // Le dividende de la division
    int diviseur; // Le diviseur de la division
    int quotient; // Le quotient de la division
    int reste;
    int progression;

    // TRAITEMENTS

    // clavier >> saisirDividende >> dividende ************************************************************
    cout << "Entrez un dividende: ";
    cin >> dividende;

    // clavier >> saisirDiviseur >> diviseur 
    cout << "Entrez un diviseur: ";
    cin >> diviseur;



    // dividende, diviseur, quotient, reste, progression >> diviser >> quotient, reste ********************
    for (progression = 0 ; progression < dividende ; progression += diviseur)
    {
        if (progression+diviseur <= dividende){
            quotient += 1;
        }
    }
    //diviseur, progression >> trouverReste >> reste 
    reste = abs(dividende-progression);

    // quotient, reste >> afficherQuotientEtReste>> ecran *************************************************
    cout << "le quotient est: " << quotient << endl;
    cout << "le reste est: " << reste;

 
    return 0;
}