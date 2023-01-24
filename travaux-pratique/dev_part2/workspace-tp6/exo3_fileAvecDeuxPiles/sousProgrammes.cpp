#include "sousProgrammes.h"

void initialiser(File &f){
    initialiser(f.pile1);
    initialiser(f.pile2);
}

void enfiler(File &f, int x){
    empiler(f.pile1, x);
}

void defiler(File &f){
    int x;
    while(!estVide(f.pile1)){
        empiler(f.pile2, sommet(f.pile1));
        depiler(f.pile1);
    }
    depiler(f.pile2);
    while(!estVide(f.pile2)){
        empiler(f.pile1, sommet(f.pile2));
        depiler(f.pile2);
    }
}

void defiler(File &f, UnElement &element){
    int x;
    while(!estVide(f.pile1)){
        empiler(f.pile2, sommet(f.pile1));
        depiler(f.pile1);
    }
    depiler(f.pile2, element);
    while(!estVide(f.pile2)){
        empiler(f.pile1, sommet(f.pile2));
        depiler(f.pile2);
    }
}

bool estVide(File f){
    return estVide(f.pile1);
}

int sommet(File f){
    int x;
    while(!estVide(f.pile1)){
        empiler(f.pile2, sommet(f.pile1));
        depiler(f.pile1);
    }
    x = sommet(f.pile2);
    while(!estVide(f.pile2)){
        empiler(f.pile1, sommet(f.pile2));
        depiler(f.pile2);
    }
    return x;
}
