#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

// contient la définition du type File implémentée àl'aide de 2 piles d'entiers non signés
// ainsi que les déclarations des primitives habituelles de gestion de cette file

#include "pile.h"
struct File
{
    UnePile pile1;
    UnePile pile2;
};

// Primitives e gestion d'une telle File 

void initialiser(File &f);
// But : initialise la file f

void enfiler(File &f, int x);
// But : ajoute l'entier x à la file f

void defiler(File &f);
// But : supprime l'entier en tête de file f

void defiler(File &f, int &x);
// But : supprime l'entier en tête de file f et le place dans x

bool estVide(File f);
// But : teste si la file f est vide

int sommet(File f);
// But : retourne l'entier en tête de file f

#endif
