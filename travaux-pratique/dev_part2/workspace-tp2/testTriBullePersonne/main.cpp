/*
 Programme : testTriBulle_personnes
 But :  Tester le sous-programme triBulle qui trie un tableau d'enregistrements par ordre croissant de valeurs ,
        selon le champ NOM de l'enregistrement
 Date de dernière modification : 19/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°2
*/

#include "personne.h"
#include <iostream>
using namespace std;

/*---------------------------------------------------------*/
/*  Déclarations des sous-programmes servant à faire les tests
  ---------------------------------------------------------*/

void testTriBulle_personnes();
// test du triBulle croissant selon le champ .nom d'un tableau de Personnes

void afficher(const Personne tab[],
                unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments de type Personne
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide') */ 

/*----------------------------------------*/
/* Déclarations des  sous-programmes testés 
----------------------------------------- */
void   triBulle (Personne tab[],
                 unsigned int nbTab);
/* But : tri CROISSANT du tableau tab, contenant nbTab éléments de type Personne, 
         selon la méthode du tri BULLE */

/*---------------------------*/
/* MAIN
---------------------------*/
int main()
{
    testTriBulle_personnes();
    return 0;
}

/*  ---------------------------------------------------*/
 /* Corps des sous-programmes servant à faire les tests
  -----------------------------------------------------*/

void testTriBulle_personnes()
{
    const unsigned short int TAILLE = 10;
    Personne tableau1[TAILLE] =   {                                                 // en désordre quelconque, avec doublons
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Marquesuzaa", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}}, 
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},      
        {"Marquesuzaa", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},        
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}}                              
        };
        // remarquer l'ordre des 3 Marquesuzaa

    cout << " ------------------   TRI BULLE croissant - tableau de PERSONNES --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);

    // monTab1, TAILLE >> triBulle >> monTab
    /**A COMPLETER-2 **/
    
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // le tri Bulle est stable : 
    // - AVANT le tri, les 3 Marquesuzaa etaient dans un certain ordre : Philippe, Christophe, Patrick
    // - APRES le tri, les 3 Marquesuzaa sont dans le même ordre --> le triBulle respecte l'ordre initial des doublons  

}

void afficher(const Personne tab[],
                unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{" << endl;
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            afficher(tab[i]) ; 
            cout << ", " << endl ;

        };
        afficher(tab[lgTab-1]);
        cout << endl <<"} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

/*-----------------------------------*/
/* Corps des sous-programmes à tester 
-------------------------------------*/
void   triBulle (Personne tab[],
                 unsigned int nbTab)
{
    /**A COMPLETER-1 **/
}

