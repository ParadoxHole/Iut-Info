/* fileAvec2Piles
   But : Implementer une file d'entiers aveec 2 piles .
         Le module sousProgramme contient :
         - la définition d'un type File utilisant 2 piles, et
         - les primitives  de manipulation d'une telle file
   Date : 09/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage de l'exercice n°3 de la feuille de TD n°6 - R1.01
*/
#include <iostream>
using namespace std; 
#include "sousProgrammes.h"  // contient la définition du type File ainsi que les déclarations des primitives habituelles de gestion de cette file
#include "pile.h"            // contient la définition du type Pile ainsi que les déclarations des primitives habituelles de gestion de cette pile


int main()
{
   //  Déclaration d'une file MaFile de type File
   File maFile;

   // initialiser(maFile)
   initialiser(maFile);

   //ajout de 5 entiers dans maFile : 1, 2, 3, 4, 5
   for (int i = 1; i <= 5; i++)
   {
      enfiler(maFile, i);
   }


   // vider maFile en affichant soon contenu
   cout << "MaFile contient : ";
   while (!estVide(maFile))
   {
      cout << sommet(maFile) << " ";
      defiler(maFile);
   }
   cout << endl << endl;

   return 0;
}
