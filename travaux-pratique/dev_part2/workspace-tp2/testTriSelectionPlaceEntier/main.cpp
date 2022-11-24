/*
 Programme : testTriParSelectionDePlace_entiers
 But :  Tester le sous-programme triParSelectionDePlace qui trie un tableau d'entiers par ordre croissant de valeurs
        selon la méthode de même nom
 Date de dernière modification : 19/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°2
*/

#include <iostream>
using namespace std;

/*---------------------------------------------------------*/
/*  Déclarations des sous-programmes servant à faire les tests
  ---------------------------------------------------------*/

void testTriParSelectionDePlace_entiers();
// test du tri par Sélection de place croissant d'un tableau d'entiers

void afficher (const int tab[],
               unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur 
         significative (tableau 'vide') */

/*----------------------------------------*/
/* Déclarations des  sous-programmes testés 
----------------------------------------- */
void  triParSelectionDePlace (int tab[],
                             unsigned int nbTab);
/* But : tri CROISSANT du tableau tab , contenant nbTab éléments, selon la méthode
         de Sélection de places */                                 


/*---------------------------*/
/* MAIN
---------------------------*/
int main()
{
    testTriParSelectionDePlace_entiers();
    return 0;
}

/*  ---------------------------------------------------*/
 /* Corps des sous-programmes servant à faire les tests
  -----------------------------------------------------*/

void testTriParSelectionDePlace_entiers()
{
    const unsigned int TAILLE = 10 ;

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard

   cout << " ------------------   TRI par SELECTION de PLACE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau1, TAILLE);

    // monTab1, TAILLE >> triBulle >> monTab
    /**A COMPLETER-2 **/
    
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;
}

void afficher (const int tab[],
               unsigned short int lgTab)
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

/*-----------------------------------*/
/* Corps des sous-programmes à tester 
-------------------------------------*/

void   triParSelectionDePlace (int tab[],
                             unsigned int nbTab)
{
    /**A COMPLETER-1 **/    
}
