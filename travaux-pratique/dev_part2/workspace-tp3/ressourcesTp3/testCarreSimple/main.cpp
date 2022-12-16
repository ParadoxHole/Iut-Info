/**
 * Fichier : main.cpp
 * But : Programme de test du module Carre 
 * Auteur : Pantxika Dagorret
 * date : 20-11-2023
 * Référence : feuille de TD n°3, exercice 2
*/
#include "carre.h"
#include <iostream>
using namespace std;

int main(void)
{
    Carre carre1; 
	Carre carre2;

	// 0,0,1, 20,20,10 >> init >> carre1, carre2
	initCarre(carre1, 0, 0, 10);
	initCarre(carre2, carre1);
	afficherEtatApresAction("init (carre1, 0, 0, 10); init (carre2, carre1);", carre1, carre2);

	// 18,18,10 >> init >> carre2
	initCarre (carre2, 18, 18, 10);
	afficherEtatApresAction("init (carre2, 18, 18, 10);", carre1, carre2);

	// carre1, 11 >> decaler >> carre1
	decalerDe (carre1, 11, 11);
	afficherEtatApresAction( "decalerDe (carre1, 11, 11);" , carre1, carre2);

	// carre1, 0.8 >> redimensionner >> carre1
	redimensionner (carre1, 0.5);
	afficherEtatApresAction( "redimensionner (carre1, 0.5);" , carre1, carre2);

	// carre1, 13,13 >> deplacerVers >> carre1
	deplacerVers (carre1, 13, 13);
	afficherEtatApresAction("deplacerVers (carre1, 13, 13);", carre1, carre2);

	return 0;
}