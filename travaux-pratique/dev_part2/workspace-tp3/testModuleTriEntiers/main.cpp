/*
 Programme : testTrisTableauxEntiers
 But :  Tester les sous-programmes de la bibliothèque triTableauxEntiers
 Date de dernière modification : 19/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°3 (+ feuille de TD n°2 et feuille TP n°2)
*/


#include <iostream>
using namespace std;

/*---------------------------------------------------------------*/
/*  Déclarations des éléments et sous-programmes communs aux tests
  ---------------------------------------------------------------*/
const unsigned int TAILLE = 10;		// taille des tableaux du module

void afficher (int tab[], unsigned int lgTab);
/* But : affiche à l'écran le contenu du carré tableau de lgTab entiers */

/*---------------------------------------------------------*/
/*  Déclarations des sous-programmes servant à faire les tests
  ---------------------------------------------------------*/
void testTriBulle_entiers();
// test du sous-programme triBulle() du module

/*-------------------------*/
/* MAIN
---------------------------*/
int main()
{
    testTriBulle_entiers();
    return 0;
}

/*  ---------------------------------------------------*/
 /* Corps des sous-programmes servant à faire les tests
  -----------------------------------------------------*/

  void testTriBulle_entiers()
{
   const unsigned int TAILLE = 10 ;

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard

   cout << " ------------------   TRI BULLE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);

    // monTab1, TAILLE >> triBulle >> monTab
    //  triBulle(tableau1, TAILLE) ;                      /**A DECOMMENTER**/

    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;
}

/*=========================================================================================
  PRIMITIVES d'ENTREE / SORTIE
  =========================================================================================*/
   void afficher (int tab[], unsigned int lgTab)
   {
        if (lgTab > 0)
        {
            cout << "{";
            for (unsigned short int i = 0; i<lgTab-1; i++)
            {
                cout << tab[i] << ", " ;

            };
            cout << tab[lgTab-1] << "} "<< endl;
        }
        else
        {
            cout << "tableau vide " << endl;
        }
  }