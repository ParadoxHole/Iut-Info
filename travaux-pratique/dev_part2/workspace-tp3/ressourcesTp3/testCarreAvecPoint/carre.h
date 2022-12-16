#ifndef CARRE_H
#define CARRE_H

#include <iostream>
using namespace std;
#include "point.h"

// Catégorie init ************************************************************

struct Carre
{
    Point point;
    unsigned int cote;
};

void initCarre(Carre & pCarre, int pAbscisse, int pOrdonnee, unsigned int pCote);

void initCarre(Carre & pCarre1, const Carre & pCarre2);

void initCarre(Carre & pCarre, const Point & pPoint, unsigned int pCote);

// Catégorie afficher **************************************************************

void afficher (const Carre & pCarre);


// Catégorie get *****************************************************************


 
int getAbscisse (const Carre & pCarre) ;
/* But : retourne la valeur du champ abscisse */

int getOrdonnee (const Carre & pCarre) ;
/* But : retourne la valeur du champ ordonnee */

unsigned int getCote (const Carre & pCarre) ;
/* But : retourne la valeur du champ cote */


// Catégorie set *****************************************************************

void setAbscisse (Carre & pCarre, int pAbscisse) ;
/* But : modifie le champ abscisse du paramètre pAbscisse */

void setOrdonnee (Carre & pCarre, int pOrdonnee) ;
/* But : modifie le champ abscisse du paramètre pOrdonnee */

void setCote (Carre & pCarre, int pCote) ;
/* But : modifie le champ abscisse du paramètre pCote */

// Catégorie update **************************************************************
void decalerDe(Carre & pCarre, int pDeltaX, int pDeltaY);

void redimensionner(Carre & pCarre, double scale);

void deplacerVers(Carre & pCarre, int pAbscisse, int pOrdonnee);

void deplacerVers(Carre & pCarre, const Point & pPoint);

bool estEgal(Carre & pCarre1, const Carre & pCarre2);

bool estEnContact(const Carre & pCarre1, const Carre & pCarre2);

#endif