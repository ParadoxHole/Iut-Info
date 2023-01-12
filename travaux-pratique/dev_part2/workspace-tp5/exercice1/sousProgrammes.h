#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>
using namespace std;

void afficherFichierTexte (string nomSysFic);
// affiche à l'écran le contenu d'un fichier de texte de nom systeme nomFic

void etendreFichierTexte(string nomSysFicSource, string nomSysFicCible);
// transfère le contenu d'un fichier de texte nomSysFicSource en fin d'un autre fichier 
// de texte nomSysFicCible.
// Les fichiers sont identifiés par leurs noms système

void viderFichierTexte(string nomSysFic);
// Si le fichier de nom système nomSysFic existe déjà, le vide de ses éléments,
// Si le fichier n'existe pas, le crée vide.

#endif
