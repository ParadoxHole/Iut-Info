/**
 * Fichier : point.h
 * But : entête du module Point immplémentant le Type Abstrait de Données (TAD) Point
 * Auteur : Pantxika Dagorret
 * date : 20-11-2023
 */
#ifndef POINT_H
#define POINT_H

struct Point 
{
	int abscisse; 
	int ordonnee; 
};

const Point ORIGINE_PLAN = { 0,0 } ;

/* -------------------------------------------------------------------------------------------
   Getters et setters (accès et Modification individuelle) de chaque chmap de l'enregistrement 
   -------------------------------------------------------------------------------------------*/ 
int getAbscisse (const Point& pPoint);
int getOrdonnee (const Point& pPoint);
/* But : retourne respectivement abscisse et ordonnée du paramètre pPoint */

void setAbscisse (Point& pPoint, int pAbscisse);
void setOrdonnee (Point& pPoint, int pOrdonnee);
/* But : Affecte la valeur du second paramètre au champ correspondant du paramètre pPoint */

/* --------------
   Observateurs 
   -------------*/
bool estOriginePlan (const Point& pPoint);
/* But : retourne true si le paramètre pPoint a les mêmes coordonnées (abscisse, ordonnée) que le point ORIGINE_PLAN */


/* --------------
   Initialisation 
   --------------*/
void init (Point& pPoint, int pAbscisse, int pOrdonnee);
/* But : initialise les champs du paramètre pPoint avec les paramètres qui suivent */
void init (Point& pPoint, const Point& pModele);
/* But : initialise tous les champq du paramètre pPoint à partir des champs du paramètre PModele */

/* ------------------
   Entrées / Sorties 
   ------------------*/
   void afficher (const Point& pPoint);
/* But : affiche à l'écran le contenu du paramètre pPoint */

#endif