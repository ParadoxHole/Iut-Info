/*
 Programme : testRechercheDichoDecEntier. 
 But :  Tester la conformité du sous-programme recherchePremiereOccDec
        effectuant une recherche dichotomique dans un tableau d'entiers trié par ordre décroissant
 Date de dernière modification : 17/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°1
*/

#include <iostream>

using namespace std;

/* Les sous-programmes servant à faire les tests 
----------------------------------------------- */
void testRechercheDichoDecEntier();    // test de recherchePremiereOccDec() sur un tableau d'entiers

void afficher (const int tab[],unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide') */

/* Les sous-programmes testés 
----------------------------- */
void recherchePremiereOccDec  (const int tab[],unsigned int lgTab,int val,unsigned int& pos,bool& trouve);
/* But : étant donnés val, une variable entière et le tableau tab, de lgTab cases, 
       ordonné par ordre décroissant de valeurs,
       recherche la première occurrence de val, selon un parcours dichotomique du tableau.
       Si elle est trouvée, trouve = vrai et pos = l'indice où elle a été trouvée
       Sinon, trouve = faux	
   pré-condition : tab est ordonné par ordre décroissant de valeurs */


/* MAIN
---------------------------*/
int main()
{
    testRechercheDichoDecEntier();
    return 0;
}
/*---------------------------*/


/* Corps des sous-programmes servant à faire les tests 
------------------------------------------------------ */
void testRechercheDichoDecEntier()
{
    const unsigned int TAILLE = 8;
    int tableau[TAILLE] = {87,78,45,12,0,-8,-9,-15};

    int valCherchee ; // entier cherché dans tableau
    unsigned int position; // 1ere position trouvee de la valeur cherchee, si elle est trouvée dans tab
    bool valTrouvee;       // indicateur de reussite / échec de la recherche

    afficher (tableau, TAILLE);
    
    // Tester : tableau, 0
    cin >> valCherchee;

    // appel du sous-programme de recherche
    recherchePremiereOccDec(tableau,TAILLE,valCherchee,position,valTrouvee);

    // valTrouvee, [position], valCherchee >> exploiter résultat >> (écran)
    if (valTrouvee)
    {
        cout << valCherchee << " trouvee ? " << "VRAI, " << position <<  endl;
    }
    else
    {
        cout << valCherchee << " trouvee ? " << "FAUX,  -- " <<  endl;
    }

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

/*---------------------------*/


/* Corps des sous-programmes à tester 
-------------------------------------*/

void recherchePremiereOccDec  (const int tab[],unsigned int lgTab,int val,unsigned int& pos,bool& trouve)
{  
    int bInf = 0;  // borne inferieure de l'espace de recherche, calculee
    int bSup = lgTab -1;  // borne inferieure de l'espace de recherche, calculee
    unsigned int milieu; // indice du milieu de l'espace de recherche.
    
    // initialiser la recherche
    pos =0;
    trouve = false;
    // corps du sous-programme de recherche
    while(bInf <= bSup)
    {
        milieu = (bInf+bSup)/2;

        if (tab[milieu] == val)
        {
            pos = milieu;
            trouve = true;
            break;
        }

        // définit l'élement courant de tab à évaluer et comparer à val
        if (tab[milieu] > val )
        {
            bInf = milieu +1;
        } else {
            bSup = milieu -1;
        }
    }
}