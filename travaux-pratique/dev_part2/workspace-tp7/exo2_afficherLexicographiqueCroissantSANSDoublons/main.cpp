/* afficherLexicographiqueCroissantSANSDoublons
   But : A partir d'un fichier texte contennat des mots de la langue français, affiche ces mots triés par 
         ordre lexicographique croissant.   
         Seule une occurrence de chaque mot du fichier est aussi affichée  à l'écran.
   Date : 14/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 2 de la feuille de  TD n°7 - R1.01 
*/
#include <iostream>
using namespace std;
#include "fichierTexte.h"
#include "liste.h"

/* Déclaration des sous-programmes 
    -------------------------------*/
void afficherOrdreLexicoCroissantSansDoublons (string nomSys);
/* Etant donné un fichier texte composé de mots de la langue française, et dont le
   nom système est fourni par le paramètre nomSys. 
   Les propriétés di fichier sont les suivantes : il peut être vide, ses mots sont 
   séparés par des séparateurs tels que espace – tabulations - sauts de ligne et de 
   page, un même mot peut apparaître plusieurs fois dans le fichier.
   
   Ce sous-programme affiche à l’écran les mots du fichier, par ordre lexicographique
   croissant(= ordre du dictionnaire), et à raison de 1 par ligne. 
   Un mot répété plusieurs fois dans le fichier n’est affiché qu’une fois à l’écran.
*/



int main()
{
    // Déclaration et initialisation des éléments servant à la manipulation de fichiers
    string nomSysEntree = "data"; 

    afficherOrdreLexicoCroissantSansDoublons(nomSysEntree);
    cout << endl;
    
    return 0;
}

    /* Définitions des sous-programmes 
    -------------------------------*/

void afficherOrdreLexicoCroissantSansDoublons (string nomSys)
{
    cout << "afficherOrdreLexicoCroissantSansDoublons () en travaux...." << endl;

}