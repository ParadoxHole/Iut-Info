/* rangPAireValeursConsecutives
   But : Tester lle sous-programme Etant donné un fichier texte, éventuellement vide, contenant des nombres entiers,   
         Recherche la première paire d'entiers égaux consécutifs égaux à une valeurCherchée
         précédemment saisie par l'utilisateur.
         Le sous-programme indique si une telle paire a été trouvée, et dans ce cas, le rang, dans le 
         fichier, de la première valeur de la paire.
   Date : 09/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 2 de la feuille de  TD n°6 - R1.01 
*/
#include <iostream>
using namespace std;
#include "fichierTexte.h"

/* Déclaration des sous-programmes 
    -------------------------------*/
    void rangPaireValeursConsecutives (string nomSysteme, 
                                       int valCherchee,
                                       bool& trouve,
                                       unsigned int& rangVal1);
   /*But : Etant donne un fichier texte, éventuellement vide, contenant des nombres entiers,   
         font le nomSysteme est fourni en paramètre, et une valeur entière valCherchée, 
         recherche dans le fichier la première paire de valeurs consécutives de valCherchée.
         Si une telle paire est trouvée, retourne VRAI dans trouve, et dans rangVal1, le rang de la première 
         valeur de la paire - en commençant à 1.
         Si aucune paire n'est trouvée, retourne FAUX dans trouve.
         */

int main()
{
    int valeurCherchee;     // valeur cherchée dans le fichier
    string nomSystemeDuFichier = "ficEntiers.txt";   // nom système du fichier à analyser
    bool paireTrouvee ;     // indique la réussite / échec de la recherche
    unsigned int position ;  // position dans le fichier, de la première valeur de la paire, lorsque trouvée

    // (clavier) >> saisie >> valCjherchee
    cout << "Quelle valeur chercher ? " ;
    cin >> valeurCherchee;

    // nomSystemeDuFichier, valeurCherchee >> recherche 1 occ >> paireTrouvee, [position]
    rangPaireValeursConsecutives (nomSystemeDuFichier, valeurCherchee, paireTrouvee, position);

    // paireTrouvee, [position] >> afficher Résulat (ecran)
    if (paireTrouvee)
    {
        cout << "Une premiere paire de valeurs consecutives de " << valeurCherchee << " a ete trouvee en positions (";
        cout <<  position << " - " << position+1 << ")" << endl;
    }
    else
    {
        cout << "pas de paire de valeurs consecutives egales a " << valeurCherchee << endl;
    }

    return 0;
    }

void rangPaireValeursConsecutives (string nomSysteme, 
                                   int valCherchee,
                                   bool& trouve,
                                   unsigned int& rangVal1)
{

}
