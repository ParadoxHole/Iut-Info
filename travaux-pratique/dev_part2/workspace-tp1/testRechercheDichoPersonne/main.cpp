/*
 Programme : testRechercheDichoDecPersonne. 
 But :  Tester la conformité du sous-programme recherchePremiereOccDec
        effectuant une recherche dichotomique dans un tableau d'enregistrements (de type Personne) 
		trié par ordre décroissant sur le champ nom
 Date de dernière modification : 17/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°1
*/

#include <iostream>
#include "personne.h"

using namespace std;

/* Les sous-programmes servant à faire les tests 
------------------------------------------------ */
void testRechercheDichoDecPersonne();  // test de recherchePremiereOccDec() sur un tableau d'enregistrements
void afficher (const Personne tab[],unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide') */


/* Les sous-programmes testés 
----------------------------- */
void recherchePremiereOccDec  (const Personne tab[],unsigned int lgTab,string val,unsigned int& pos,bool& trouve);
/* But : étant donnés val, une variable chaîne de caractères et le tableau tab, de lgTab cases de type Personne, 
       ordonné par ordre décroissant selon le champ nom,
       recherche la première occurrence de val, selon un parcours dichotomique du tableau.
       Si elle est trouvée, trouve = vrai et pos = l'indice où elle a été trouvée
       Sinon, trouve = faux	
   pré-condition : tab est ordonné par ordre décroissant sur le champ nom */


/* MAIN
---------------------------*/
int main()
{
    //testRechercheDichoDecEntier();
    testRechercheDichoDecPersonne();
    return 0;
}
/*---------------------------*/


/* Corps des sous-programmes servant à faire les tests  
------------------------------------------------------ */
void testRechercheDichoDecPersonne()
{
    const unsigned short int TAILLE = 10;
    Personne tableau[TAILLE] =         // tableau d'enregistrements trié décroissant selon le NOM
        {
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},                               
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}}
        }; 

    string valCherchee;     
    unsigned int position; // 1ere position trouvee de la valeur cherchee, si elle est trouvée dans tab
    bool valTrouvee;       // indicateur de reussite / échec de la recherche

    afficher (tableau, TAILLE);

    // Tester : tableau, "Dijon-Duboue"
    valCherchee = "Dijon-Duboue";
    /**A COMPLETER-1 **/       // appel du sous-programme de recherche

    // valTrouvee, [position], valCherchee >> exploiter résultat >> (écran)
    if (valTrouvee)
    {
        cout << valCherchee << " trouvee ?  " << "VRAI, " << position << endl;
    }
    else
    {
        cout << valCherchee << " trouvee ? " << "FAUX,  -- " << endl;
    }                            
}

void afficher (const Personne tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{" << endl;
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            afficher (tab[i]); 
            cout << "," << endl;

        };
         afficher (tab[lgTab-1]); 
         cout << endl << "}" << endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

/*---------------------------*/

/* Corps des sous-programmes à tester 
-------------------------------------*/

void recherchePremiereOccDec (const Personne tab[],unsigned int lgTab,string val,unsigned int& pos,bool& trouve)
{
    
    int bInf = 0;  // borne inferieure de l'espace de recherche, calculee
    int bSup = lgTab -1;  // borne inferieure de l'espace de recherche, calculee
    unsigned int milieu; // indice du milieu de l'espace de recherche.
    
    // initialiser la recherche
    pos =0;
    trouve = false;

    while(bInf <= bSup)
    {
        milieu = (bInf+bSup)/2;

        if (tab[milieu] == val)
        {
            pos = milieu;
            trouve = true;
            break;
        }
        
        if (tab[milieu] > val )
        {
            bInf = milieu +1;
        } else {
            bSup = milieu -1;
        }
    }
}