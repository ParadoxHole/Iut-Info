/* Module UneListe
   Permet de manipuler des listes
   Plusieurs listes peuvent etre manipulees a condition qu'elles contiennent
   toutes le meme type d'elements 
   */

#ifndef LISTE_H
#define LISTE_H

#include <list>
#include <iostream>
using namespace std;

/* ***************************************************** 
   DEFINITION DU TYPE DES ELEMENTS CONTENUS DANS LA LISTE 
   *****************************************************

   Pour faire une liste avec des types de base :
   typedef int UnElement;


   Pour faire une liste avec des elements de type struct :
   typedef struct
   {
   int coordX; // abscisse du point
   int coordY; // ordonnee du point
   } UnElement;


   Pour faire une liste avec des elements dont le type est defini dans un autre fichier :
   #include "leFichierOuEstDefiniLeType.h"
   typedef leTypeDefiniDansLeFichier UnElement;
*/

typedef int UnElement;

/* *************************************************** 
   NE MODIFIER AUCUNE LIGNE EN DESSOUS DE CE MESSAGE */

typedef list<UnElement> UneListeElements;

typedef struct
{
  UneListeElements listeElements;
  unsigned int positionElementCourant = 0;
  UneListeElements::iterator pointeurElementCourant ;
} UneListe;
/* *************************************************** */


/*=======================================================
   P R I M I T I V E S    de    L I S T E S 
========================================================*/


/****************************/
/*       INITIALISATEUR       */
/****************************/

void initialiser (UneListe& l);
// Initialise ou re-initialise une liste



/****************************/
/*       OBSERVATEURS       */
/****************************/

unsigned int taille (const UneListe& l);
// Retourne le nombre d'elements stockes dans la liste l

unsigned int positionCourante (const UneListe& l);
/* Retourne la position de l'element courant.
   Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */
   
bool estVide (const UneListe& l);
// Retourne vrai si la liste l est vide, faux sinon

UnElement elementCourant(const UneListe& l);
/* Retourne la valeur de l'element courant
   Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */

UnElement elementEn(const UneListe& l, unsigned int pos);
/* Retoune la valeur de l'element situe en position pos dans la liste l
   Genere l'erreur positionInvalide si pos > taille(l) ou pos < 1 */

bool parcoursEnCours (const UneListe& l);
/* Retourne vrai si on est en train de parcourir la liste et qu'il existe un
   element courant. Retourne faux dans le cas contraire */ 



/****************************/
/*        MODIFICATEURS        */
/****************************/

/* PRIMITIVES DE DEPLACEMENT  */

void allerDebut(UneListe& l);
// Se positionne au debut de la liste l. 

void avancer (UneListe& l);
/* Avance dans la liste. 
   Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */

void reculer (UneListe& l);
/* Recule dans la liste
   Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */

void allerFin(UneListe& l);
// Se positionne au fin de la liste l. 

void allerEn(UneListe& l, unsigned int pos);
/* Se positionne en position pos dans la liste l. 
   Genere l'erreur positionInvalide si pos > taille(l) ou pos < 1 */



/* PRIMITIVES D'AJOUT */

void insererDebut (UneListe& l, UnElement e);
/* Ajoute l'element e en tete de la liste l. L'element courant (s'il existe)
   est inchange mais sa postion est incrementee. */ 

void insererFin (UneListe& l, UnElement e);
// Ajoute l'element e en fin de la liste l 

void insererDevantCourant (UneListe& l, UnElement e);
/*  Ajoute l'element e devant l'element courant de la liste l. 
    L'element courant est inchange mais sa postion est incrementee. 
    Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */

void insererDerriereCourant (UneListe& l, UnElement e);
/*  Ajoute l'element e derrière l'element courant de la liste l 
    Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */


void insererEn(UneListe& l, unsigned int pos, UnElement e);
/*  Ajoute l'element e en position pos dans la liste l.
    S'il y a un element courant et que pos < positionCourante(l),
    l'element courant reste inchange mais sa position est incrementee. 
    Genere l'erreur positionInvalide si pos > taille(l)+1 ou pos < 1 */



/* PRIMITIVES DE SUPPRESSION  */

void supprimerCourant (UneListe& l);
/*  Supprime l'element courant de la liste l. 
    Si ce n'est pas le dernier, son suivant devient l'élément courant
	Si c'est le dernier, l'élément courant n'est plus défini (parcours terminé). 
    Genere l'erreur pasDeParcoursEnCours si aucun element courant n'est defini */

void supprimerDebut (UneListe& l);
/*  Supprime l'element en tete de la liste l. Si l'element en tete de liste est
    l'element courant, aucun nouvel element courant n'est defini. 
    S'il y a un element courant et que positionCourante(l) > 1,
    l'element courant reste inchange mais sa position est decrementee. 
    Genere l'erreur positionInvalide si la liste ne contient aucun element */

void supprimerFin (UneListe& l);
/*  Supprime l'element en fin de la liste l. Si l'element en fin de liste est
    l'element courant, aucun nouvel element courant n'est defini. 
    Genere l'erreur positionInvalide si la liste ne contient aucun element */

void supprimerDerriereCourant (UneListe& l);
/*  Supprime l'element qui se situe apres l'element courant dans la liste l 
    Genere l'erreur :
    - pasDeParcoursEnCours si aucun element courant n'est defini 
    - pasDeSuivant si l'element courant est le dernier element de l */

void supprimerDevantCourant (UneListe& l);
/*  Supprime l'element qui se situe avant l'element courant dans la liste l.
    La position de l'element courant est decrementee.
    Genere l'erreur :
    - pasDeParcoursEnCours si aucun element courant n'est defini 
    - pasDePrecedent si l'element courant est le premier element de l */

void supprimerEn(UneListe& l, unsigned int pos);
/*  Supprime l'element qui se situe en position pos dans la liste l.
    Si l'element situe en position pos est l'element courant, aucun
    nouvel element courant n'est defini suite a la suppression
    S'il y a un element courant et que pos < positionCourante(l),
    l'element courant reste inchange mais sa position est decrementee. 
    Genere l'erreur positionInvalide si pos > taille(l) ou pos < 1 */



/* PRIMITIVES DE REMPLACEMENT */

void remplacerDebut (UneListe& l, UnElement e);
/* Remplace l'element situe en tete de la liste l par l'element e.
   Genere l'erreur positionInvalide si la liste ne comporte aucun element */

void remplacerFin (UneListe& l, UnElement e);
/* Remplace l'element situe en fin de la liste l par l'element e.
   Genere l'erreur positionInvalide si la liste ne comporte aucun element */

void remplacerCourant (UneListe& l,  UnElement e);
/* Remplace l'element courant de la liste l par l'element e
   Genere l'erreur pasDeParcoursEnCours  si aucun element courant n'est defini */

void remplacerDevantCourant (UneListe& l,  UnElement e);
/*  Remplace par e l'element qui se situe avant l'element courant dans la liste l.
    Genere l'erreur :
    - pasDeParcoursEnCours si aucun element courant n'est defini 
    - pasDePrecedent si l'element courant est le premier element de l */

void remplacerDerriereCourant (UneListe& l, UnElement e);
/*  Remplace par e l'element qui se situe apres l'element courant dans la liste l.
    Genere l'erreur :
    - pasDeParcoursEnCours si aucun element courant n'est defini 
    - pasDeSuivant si l'element courant est le dernier element de l */

void remplacerEn(UneListe& l, unsigned int pos, UnElement e);
/*  Remplace l'element en position pos dans la liste l par l'element e.
    Genere l'erreur positionInvalide si pos > taille(l) ou pos < 1 */

#endif
