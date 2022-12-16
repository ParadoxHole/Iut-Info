#include "carre.h"
#include <iostream>
using namespace std;

bool estEgal (const Carre & pCarre1, const Carre & pCarre2);
bool estEnContact (const Carre & pCarre1, const Carre & pCarre2);
bool estDans (const Carre & pCarre1, const Carre & pCarre2);

// Catégorie init **************************************************************

void initCarre ( Carre & pCarre, int pAbscisse, int pOrdonnee, unsigned int pCote){
    setAbscisse(pCarre, pAbscisse);
    setOrdonnee(pCarre, pOrdonnee);
    setCote(pCarre, pCote);
}

void initCarre (Carre & pCarre1, const Carre & pCarre2){
    setAbscisse(pCarre1, getAbscisse(pCarre2));
    setOrdonnee(pCarre1, getOrdonnee(pCarre2));
    setCote(pCarre1, getCote(pCarre2));
}

void initCarre (Carre & pCarre, const Point & pPoint, unsigned int pCote){
    setAbscisse(pCarre, pPoint.abscisse);
    setOrdonnee(pCarre, pPoint.ordonnee);
    setCote(pCarre, pCote);
}



// Catégorie afficher **************************************************************

void afficher (const Carre & pCarre){
    cout << "abscisse : " << getAbscisse(pCarre) << endl;
    cout << "ordonnee : " << getOrdonnee(pCarre) << endl;
    cout << "cote : " << getCote(pCarre) << endl;
}

// Catégorie get *****************************************************************


int getAbscisse (const Carre & pCarre) {
    return getAbscisse(pCarre.point);
}

int getOrdonnee (const Carre & pCarre){
    return getOrdonnee(pCarre.point);
}

unsigned int getCote (const Carre & pCarre){
    return pCarre.cote;
}
 

// Catégorie set *****************************************************************
void setAbscisse (Carre & pCarre, int pAbscisse){
    pCarre.point.abscisse = pAbscisse;
}

void setOrdonnee (Carre & pCarre, int pOrdonnee){
    pCarre.point.ordonnee = pOrdonnee;
}

void setCote (Carre & pCarre, int pCote){
    pCarre.cote = pCote;
}

// Catégorie update **************************************************************
void decalerDe(Carre & pCarre, int pDeltaX, int pDeltaY){
    setAbscisse(pCarre, getAbscisse(pCarre) + pDeltaX);
    setOrdonnee(pCarre, getOrdonnee(pCarre) + pDeltaY);
}

void redimensionner(Carre & pCarre, double scale){
    setCote(pCarre, static_cast<unsigned int>(getCote(pCarre) * scale));
}

void deplacerVers(Carre & pCarre, int pAbscisse, int pOrdonnee){
    setAbscisse(pCarre, pAbscisse);
    setOrdonnee(pCarre, pOrdonnee);
}

void deplacerVers(Carre & pCarre, const Point & pPoint){
    setAbscisse(pCarre, pPoint.abscisse);
    setOrdonnee(pCarre, pPoint.ordonnee);
}

//catégorie comparer **************************************************************

bool estEgal (const Carre & pCarre1, const Carre & pCarre2){
    return (getAbscisse(pCarre1) == getAbscisse(pCarre2) // Leurs abscisses sont égales
            && 
            getOrdonnee(pCarre1) == getOrdonnee(pCarre2) // Leurs ordonnées sont égales
            && 
            getCote(pCarre1) == getCote(pCarre2)); // Leurs cotés sont égaux
}

bool estEnContact (const Carre & pCarre1, const Carre & pCarre2){
    return (estDans(pCarre1, getAbscisse(pCarre2), getOrdonnee(pCarre2))                                            // extrémité supérieure gauche de pCarre2
            || 
            estDans(pCarre1, getAbscisse(pCarre2) + getCote(pCarre2), getOrdonnee(pCarre2))                         // extrémité supérieure droite de pCarre2
            || 
            estDans(pCarre1, getAbscisse(pCarre2), getOrdonnee(pCarre2) + getCote(pCarre2))                         // extrémité inférieure gauche de pCarre2
            || 
            estDans(pCarre1, getAbscisse(pCarre2) + getCote(pCarre2), getOrdonnee(pCarre2) + getCote(pCarre2))      // extrémité inférieure droite de pCarre2
            ||
            estDans(pCarre2, getAbscisse(pCarre1), getOrdonnee(pCarre1))                                            // extrémité supérieure gauche de pCarre1
            ||
            estDans(pCarre2, getAbscisse(pCarre1) + getCote(pCarre1), getOrdonnee(pCarre1))                         // extrémité supérieure droite de pCarre1
            ||
            estDans(pCarre2, getAbscisse(pCarre1), getOrdonnee(pCarre1) + getCote(pCarre1))                         // extrémité inférieure gauche de pCarre1
            ||
            estDans(pCarre2, getAbscisse(pCarre1) + getCote(pCarre1), getOrdonnee(pCarre1) + getCote(pCarre1))      // extrémité inférieure droite de pCarre1
            );
}

bool estDans(const Carre & pCarre, int pAbscisse, int pOrdonnee){
    return (pAbscisse >= getAbscisse(pCarre)                                               // inférieur à l'abscisse du carré
            && pAbscisse <= getAbscisse(pCarre) + static_cast<int>(getCote(pCarre))       // supérieur à l'abscisse du carré + son côté
            && pOrdonnee >= getOrdonnee(pCarre)                                            // inférieur à l'ordonnée du carré
            && pOrdonnee <= getOrdonnee(pCarre) + static_cast<int>(getCote(pCarre))       // supérieur à l'ordonnée du carré + son côté
            );   
}