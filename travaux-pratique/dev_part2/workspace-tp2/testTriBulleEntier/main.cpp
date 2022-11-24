/*
 Programme : testTriBulle_entiers
 But :  Tester le sous-programme triBulle qui trie un tableau d'entiers par ordre croissant de valeurs 
 Date de dernière modification : 19/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°2
*/

#include <iostream>
using namespace std;

/*---------------------------------------------------------*/
/*  Déclarations des sous-programmes servant à faire les tests
  ---------------------------------------------------------*/

void testTriBulle_entiers();
// test du triBulle croissant d'un tableau d'entiers

void afficher (const int tab[],unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur 
         significative (tableau 'vide') */

/*----------------------------------------*/
/* Déclarations des  sous-programmes testés 
----------------------------------------- */
void triBulle (int tab[],unsigned int nbTab);
/* But : tri CROISSANT du tableau tab, contenant nbTab éléments entiers, selon la méthode du tri BULLE */

/*---------------------------*/
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

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié, valeurs au hasard


   cout << " ------------------   TRI BULLE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);

    // monTab1, TAILLE >> triBulle >> monTab
    triBulle (tableau1, TAILLE);

    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    //remplir monTab avec des valeurs au hasard
    /*for (unsigned int i = 0; i < TAILLE; i++)
        tableau1[i] = rand() % 100 - 50; // valeurs entre -50 et 49
*/
}

void afficher (const int tab[],unsigned short int lgTab)
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

void tribulle(int tab[], unsigned int nbTab)
{
    int i, j, temp;
    for (i = 0; i < nbTab; i++)
    {
        for (j = 0; j < nbTab - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}