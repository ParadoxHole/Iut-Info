/*
 Programme : SigneDunNombre
 But :  Renvoie le signe d'un nombre
 Date de dernière modification : 20/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double nombre; // Le nombre saisie par l'utilisateur dont on veut le signe
    string signe; // La reponse afficher 

    // TRAITEMENTS
    // clavier >> saisirNombre >> nombre ****************************************************
    cout << "Saisir un nombre, n'importe lequel soyez fou:  ";
    cin >> nombre;

    // nombre >> verifierSigne >> signe *****************************************************
    if(nombre < 0)
        {signe = "negatif";}
    else if(nombre > 0)
        {signe = "positif";}
    else
        {signe = "nul";}

    // signe >> afficherResultat >> écran ****************************************************
    cout << "ce nombre que vous avez choisi vous meme comme un grand est : "<< signe << endl;

    return 0;
}