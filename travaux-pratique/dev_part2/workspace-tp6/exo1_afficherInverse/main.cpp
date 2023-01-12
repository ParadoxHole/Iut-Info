/* afficherInverseFichierTexte
   But : afficher à l'écran le contenu d'un fichier de texte, 
         dans l'ordre inverse de leur place dans le fichier.
   Date : 09/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 1 de la feuille de  TD n°6 - R1.01 
*/
#include <iostream>
#include "fichierTexte.h"
#include "pile.h"
//
using namespace std;

/* Déclaration des sous-programmes 
    -------------------------------*/
    void afficherInverseFichierTexte(string nomSysFic);
   // affiche à l'écran le contenu d'un fichier de texte de nom systeme nomFic.
   // L'affichage est à l'envers, cad :
   // dernière ligne du fichier texte --> 1ere ligne écran
   //...
   // 1ère ligne du fichier texte --> derniere ligne de l'écran

int main()
{
    string nomSystemeficSource ;    // nom système du fichier à consulter

    cout << "Afficher l'INVERSE du contenu d'un fichier de texte" << endl;
    cout << "-----------------------------------------------------" << endl << endl;
    cout << "nom du fichier a afficher : ";
    cin >> nomSystemeficSource;
    afficherInverseFichierTexte(nomSystemeficSource);
    cout << endl << endl;

    cout << endl <<  "...au revoir..." << endl;
    return 0;
}


/* Corps des sous-programmes 
   -------------------------*/
void afficherInverseFichierTexte(string nomSysFic)
{
      UnFichierTexte fic;
      associer(fic, nomSysFic);
      ouvrir (fic, consultation);

      UnePile p;
      initialiser(p);

      string ligne;
      bool fdf = false;
      while (true)
      {
         lireLigne(fic, ligne, fdf);
         
         if (fdf) break;
         empiler(p, ligne);
      }
}
