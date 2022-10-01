/*
 Programme : sommeEntier
 But :  afficher la somme des entier de 1 et une borne entrée par l'utilisateur
 Date de dernière modification : 30/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    unsigned int borneEntier; // La borne saisie par l'utilisateur
    unsigned int entiersDansBoucle; // Le nombre qui permet l'itération
    unsigned int entiers = 1; // L'entier à ajouter à chaque itération, on peut demander à l'utilisateur de l'indiquer 
    long int somme; // Le résultat de la somme des entiers 

    // TRAITEMENTS
    // clavier >> saisirBorne >> borneEntier ************************************************************
    cout << "Entrez la borne maximal: ";
    cin >> borneEntier;

    // borneEntier, entiersDansBoucle, entiers >> calculeSomme >> somme *********************************
    for (entiersDansBoucle = 0 ; entiersDansBoucle < borneEntier ; entiersDansBoucle++)
    {
        somme += entiers;
        entiers += 1;
    }

    // somme >> afficherSomme >> ecran ******************************************************************
    cout << "somme des entiers: "<< somme <<endl;
    return 0;
}