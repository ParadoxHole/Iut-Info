/* Transfert
   But : transferts de contenus entre piles et files. 
   Date : 12/12/2022
   Auteur : Pantxika Dagorret
   Remarque : Codage des exercices de la feuille de TD n°4 - R1.01
*/
#include <iostream>
using namespace std; 
#include "pile.h"
#include "file.h"


/* Déclarations des sous-programmes 
-----------------------------------*/

void afficher(const UnePile& pPile);
// affiche le contenu de la pPile et la restitue en l'état

void afficher(const UneFile& pFile);
// affiche le contenu de la pFile et la restitue en l'état

void testAfficherPile();
void testAfficherFile();
// But tester les sous-programmes d'affichage d'une Pile et File

void testTransferts_executionsABC();
// But : Programme de test pour l'exercice n°3 de la feuille de TD n°6

void transfertContenu(UnePile& p1, UnePile& p2);
/* Transfert le contenu de la pile p1 dans la pile p2
   Genere l'exception "pileVide" si la pile p1 est vide */

void transfertContenu(UneFile& f1, UneFile& f2);
/* Transfert le contenu de la file f1 dans la file f2
   Genere l'exception "fileVide" si la file f1 est vide */

void transfertContenu(UnePile& p1, UneFile& f2);
/* Transfert le contenu de la file p1 dans la file f2
   Genere l'exception "fileVide" si la file f1 est vide */

void transfertContenu(UneFile& f1, UnePile& p2);
/* Transfert le contenu de la file f1 dans la file p2
   Genere l'exception "fileVide" si la file f1 est vide */



int main()
{
   cout << "Test d'affichage d'une Pile :" << endl;
   testAfficherPile();
   cout << "Test d'affichage d'une File :" << endl;
   testAfficherFile();
   cout << "Test des transferts :" << endl;
   testTransferts_executionsABC();
   return 0;
}


/* Corps des sous-programmes 
----------------------------*/

void afficher(const UnePile& pPile)
{
   UnePile copiePile = pPile;
   while (!estVide(copiePile))
   {
      cout << int(sommet(copiePile)) << " ";
      depiler(copiePile);
   }
   cout << endl;
}

void afficher(const UneFile& pFile)
{
   UneFile copieFile = pFile;
   while (!estVide(copieFile))
   {
      cout << int(premier(copieFile)) << " ";
      defiler(copieFile);
   }
   cout << endl;
}

void testAfficherPile()
{
   //Déclaration et initialisation de la pile
    UnePile maPile;
    initialiser(maPile);

    // Ajout d'éléments dans la pile
    empiler(maPile, 0); empiler(maPile, 1);
    empiler(maPile, 2); empiler(maPile, 3);
    empiler(maPile, 4); empiler(maPile, 5);

    afficher(maPile);
}

void testAfficherFile()
{
   //Déclaration et initialisation de la file
    UneFile maFile;
    initialiser(maFile);

    // Ajout d'éléments dans la pile
    enfiler(maFile, 0); enfiler(maFile, 1);
    enfiler(maFile, 2); enfiler(maFile, 3);
    enfiler(maFile, 4); enfiler(maFile, 5);

    afficher(maFile);
}

void testTransferts_executionsABC()
{
   
   const unsigned int NB_VALEURS = 4;
   UnePile pile_1;  // contenant_1
   UnePile pile_2;  // contenant_2
   UneFile file_1;  // contenant_1
   UneFile file_2;  // contenant_2

   /* ------------------   trouverLeContenant : exécution_A, avec :
      contenant_1 : pile
      contenant_2 : pile
   ----------------------------------------------------------------*/
                       
   cout << "execution A " << endl;
   // initialisations >> pile_1, pile_2
   initialiser (pile_1);
   initialiser (pile_2);
   // pile_1 (vide) >> remplir Contenant >> pile_1
   remplirContenant(NB_VALEURS, pile_1);
   // pile_1, pile_2 (vide) >> transfertContenu >> pile_1 (vide), pile_2
   transfertContenu (pile_1, pile_2);
   // pile_2 >> affichage
   afficher(pile_2);

   /* --------------------   trouverLeContenant : exécution_B, avec :
      contenant_1 : file
      contenant_2 : pile
      ----------------------------------------------------------------*/
   cout << "execution B " << endl;
   // initialisations >> file_1, pile_2
   initialiser (file_1);
   initialiser (pile_2);
   // file_1 (vide) >> remplir Contenant >> file_1
   remplirContenant(NB_VALEURS, file_1);
   // file_1, pile_2 (vide) >> transfertContenu >> file_1 (vide), pile_2
   transfertContenu(file_1, pile_2);
   // pile_2 >> affichage   
   afficher(pile_2);

  /* --------------------   trouverLeContenant : exécution_C, avec :
      contenant_1 : pile
      contenant_2 : file
      ----------------------------------------------------------------*/
   cout << "execution C " << endl;
   // initialisations >> pile_1, file_2
   initialiser (pile_1);
   initialiser (file_2);
    // pile_1 (vide) >> remplir Contenant >> pile_1
   remplirContenant(NB_VALEURS, pile_1);
   // pile_1, file_2 (vide) >> transfertContenu >> pile_1 (vide), file_2   
   transfertContenu (pile_1, file_2);
   // file_2 >> affichage  
   afficher(file_2);
}

void transfertContenu (UnePile& p1, UnePile& p2){
  if(!estVide(p1)){
    while(!estVide(p1)){
      UnElement e;
      depiler(p1, e);
      empiler(p2, e);
    } 
  }
  else
    throw string("pileVide");
}

void transfertContenu(UneFile& f1, UneFile& f2){
  if (!f1.empty()){
    while(!estVide(f1)){
        UnElement e;
        defiler(f1, e);
        enfiler(f2, e);
      }
  }
  else
    throw string("fileVide");
}

void transfertContenu(UnePile& p1, UneFile& f2){
  if (!p1.empty()){
    while(!estVide(p1)){
        UnElement e;
        depiler(p1, e);
        enfiler(f2, e);
      }
  }
  else
    throw string("pileVide");
}

void transfertContenu(UneFile& f1, UnePile& p2){
  if (!f1.empty()){
    while(!estVide(f1)){
        UnElement e;
        defiler(f1, e);
        empiler(p2, e);
      }
  }
  else
    throw string("fileVide");
}

