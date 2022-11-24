/**  MODULE Personne
     contient la définition du type Personne
     -------------------------------------------

 Date de dernière modification : 15/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°1
*/
#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
using namespace std;

// Définition des types du module
struct Adresse 
{
    string numRue; 
    string nomRue;
    unsigned short int codePostal;
    string nomVille; 
};

struct Personne
{
    string nom;
    string prenom;
    Adresse adresse;
};

// Primitives d'Entrée-Sortie
void afficher(const Personne& personne);
// Affiche sur une ligne le contenu de l'enregistrement passé en paramètre

#endif // PERSONNE_H