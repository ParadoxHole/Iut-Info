#include "carre.h"
#include <iostream>
using namespace std;

bool estEgal (const Carre & pCarre1, const Carre & pCarre2);
bool estEnContact (const Carre & pCarre1, const Carre & pCarre2);

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


// Catégorie afficher **************************************************************

void afficher (const Carre & pCarre){
    cout << "abscisse : " << getAbscisse(pCarre) << endl;
    cout << "ordonnee : " << getOrdonnee(pCarre) << endl;
    cout << "cote : " << getCote(pCarre) << endl;
}

void afficherEtatApresAction (string pLibelleAction, const Carre & pCarre1, const Carre & pCarre2){
    cout << endl;
    cout << pLibelleAction << endl;
    cout << "carre1 : " ;  afficher(pCarre1);
    cout << "carre2 : " ;  afficher(pCarre2);
    
    if (estEgal (pCarre1, pCarre2))
    {
        cout << "Les 2 carres sont egaux " << endl;
    }
    else
    {
        cout << "Les 2 carres sont differents " << endl;
    }
    
    if (estEnContact (pCarre1, pCarre2))
    {
        cout << "Les 2 carres sont en contact " << endl;
    }
    else
    {
        cout << "Les 2 carres ne sont pas en contact " << endl;
    }
}

// Catégorie get *****************************************************************


int getAbscisse (const Carre & pCarre) {
    return pCarre.abscisse;
}

int getOrdonnee (const Carre & pCarre){
    return pCarre.ordonnee;
}

unsigned int getCote (const Carre & pCarre){
    return pCarre.cote;
}
 

// Catégorie set *****************************************************************
void setAbscisse (Carre & pCarre, int pAbscisse){
    pCarre.abscisse = pAbscisse;
}

void setOrdonnee (Carre & pCarre, int pOrdonnee){
    pCarre.ordonnee = pOrdonnee;
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
    setCote(pCarre, getCote(pCarre) * scale);
}

void deplacerVers(Carre & pCarre, int pAbscisse, int pOrdonnee){
    setAbscisse(pCarre, pAbscisse);
    setOrdonnee(pCarre, pOrdonnee);
}

//catégorie comparer **************************************************************

bool estEgal (const Carre & pCarre1, const Carre & pCarre2){
    if(getAbscisse(pCarre1) == getAbscisse(pCarre2) && getOrdonnee(pCarre1) == getOrdonnee(pCarre2) && getCote(pCarre1) == getCote(pCarre2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool estEnContact (const Carre & pCarre1, const Carre & pCarre2){
    if(getAbscisse(pCarre1) == getAbscisse(pCarre2) && getOrdonnee(pCarre1) == getOrdonnee(pCarre2) && getCote(pCarre1) == getCote(pCarre2))
    {
        return true;
    }
    else
    {
        return false;
    }
}