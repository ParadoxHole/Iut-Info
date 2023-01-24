#include "liste.h"
#include <stdlib.h> // pour l'usage de la fonction exit
#include<iostream> // pour l'usage du type string
using namespace std;


/****************************/
/*       CONSTRUCTEUR       */
/****************************/

void initialiser (UneListe& l)
{
  l.listeElements.clear();
  l.positionElementCourant = 0;
  l.pointeurElementCourant = l.listeElements.begin();
}


/****************************/
/*       OBSERVATEURS       */
/****************************/

unsigned int taille (const UneListe& l)
{
  return static_cast<unsigned int>(l.listeElements.size());
}

unsigned int positionCourante (const UneListe& l)
{
    if (l.positionElementCourant > 0)
    {
      return l.positionElementCourant;
    }
    else 
    {
      cerr << "pasDeParcoursEnCours" << endl;     
      throw string("pasDeParcoursEnCours");
    }
}

bool estVide (const UneListe& l)
{
  return l.listeElements.empty();
}

UnElement elementCourant(const UneListe& l)
{
    if (l.positionElementCourant == 0)
    {
      cerr << "pasDeParcoursEnCours" << endl;
      throw string("pasDeParcoursEnCours");
    }
    else
    {
      //return *(l.pointeurElementCourant);
      UneListe copieListe = l;
      UneListeElements::iterator pointeurCourant =  copieListe.listeElements.begin();
      for (unsigned int i = 1 ; i < l.positionElementCourant ; i++)
      {
        pointeurCourant++;
      }
      return *pointeurCourant;
            
    }
}


UnElement elementEn(const UneListe& l, unsigned int pos)
{
  UneListe copieListe = l;

  if (pos > l.listeElements.size() || pos < 1)
    {
      cerr << "positionInvalide" << endl;
      throw string("positionInvalide");
    }
  else
    {
      UneListeElements::iterator pointeurCourant =  copieListe.listeElements.begin();
      for (unsigned int i = 1 ; i < pos ; i++)
      {
        pointeurCourant++;
      }
      return *pointeurCourant;
    }  
}

bool parcoursEnCours (const UneListe& l)
{
  return (l.positionElementCourant > 0);
}



/****************************/
/*        MODIFICATEURS     */
/****************************/


/* PRIMITIVES DE DEPLACEMENT  */

void allerDebut(UneListe& l)
{
  if (l.listeElements.size() != 0)
    {
      l.positionElementCourant = 1;
      l.pointeurElementCourant = l.listeElements.begin();
    }
  else 
  {
    l.positionElementCourant = 0;
  }
}


void allerFin(UneListe& l)
{
  if (l.listeElements.size() != 0)
    {
      l.positionElementCourant = static_cast<unsigned int>(l.listeElements.size());
      l.pointeurElementCourant = l.listeElements.end();
    }
  else 
  {
    l.positionElementCourant = 0;
  }
}


void allerEn(UneListe& l, unsigned int pos)
{

  if (pos > l.listeElements.size() || pos < 1)
  {
    cerr << "positionInvalide" << endl;
    throw string("positionInvalide");

  }
  else
    {
      l.pointeurElementCourant =   l.listeElements.begin();
      l.positionElementCourant = 1;

      for (unsigned int i = 1 ; i < pos ; i++)
        {
          l.pointeurElementCourant++;
          l.positionElementCourant++;
        }
    }
}


void avancer (UneListe& l)
{
  if (l.positionElementCourant == 0)
  {
      cerr << "pasDeParcoursEnCours" << endl;
      throw string("pasDeParcoursEnCours");
  }
  else
    {
      if (l.positionElementCourant ==  l.listeElements.size())
      {
        l.positionElementCourant = 0;
      }
      else
        {
          l.pointeurElementCourant++; 
          l.positionElementCourant++;
        }
    }
}


void reculer (UneListe& l)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    {
      if (l.positionElementCourant ==  1)
      {
        l.positionElementCourant = 0;
      }
      else
        {
          l.pointeurElementCourant--; 
          l.positionElementCourant--;
        }
    }
}


/* PRIMITIVES D'INSERTION */


void insererFin (UneListe& l, UnElement e)
{
  l.listeElements.push_back(e);
}

void insererDebut (UneListe& l, UnElement e)
{
  l.listeElements.push_front(e);

  if (l.positionElementCourant > 0)
  {
    l.positionElementCourant++;
  }
}


void insererDevantCourant (UneListe& l, UnElement e)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    {
      UneListeElements::iterator pointeurCourant =  l.listeElements.begin();
      for (unsigned int i = 1 ; i < l.positionElementCourant ; i++)
      {
        pointeurCourant++;
      }
      l.listeElements.insert(pointeurCourant, e);
      l.positionElementCourant++;
    }
}


void insererDerriereCourant (UneListe& l, UnElement e)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    {
      UneListeElements::iterator pointeurCourant =  l.listeElements.begin();
      for (unsigned int i = 1 ; i <= l.positionElementCourant ; i++)
      {
        pointeurCourant++;
      }
      l.listeElements.insert(pointeurCourant, e);
  }
}


void insererEn(UneListe& l, unsigned int pos, UnElement e)
{
  if (pos > (l.listeElements.size()+1) || pos < 1)
  {
    cerr << "positionInvalide" << endl;
    throw string("positionInvalide");
  }
  else
    {
      UneListeElements::iterator pointeurCourant =  l.listeElements.begin();

      for (unsigned int i = 1 ; i < pos ; i++)
      {
        pointeurCourant++;
      }
      l.listeElements.insert(pointeurCourant, e);

      /* L'element courant reste inchange mais sa position doit
         peut-etre etre mise a jour */
      if (l.positionElementCourant >= pos) // on a supprime l'element courant
        {
          l.positionElementCourant++;
        }
    }
}



/* PRIMITIVES DE SUPPRESSION  */

void supprimerDebut (UneListe& l)
{

  if (l.listeElements.size() == 0)
  {
    cerr << "positionInvalide" << endl;
    throw string("positionInvalide");
  }
  else
    {
      l.listeElements.pop_front(); 

      if (l.positionElementCourant == 1) // on a supprime l'element courant
        {
        l.positionElementCourant = 0;
        }
      else
        if (l.positionElementCourant > 1)
          {
            /* La postion de l'element courant est decrementee 
               car la tete a ete supprimee */
            l.positionElementCourant--;
          }        
    }
}


void supprimerFin (UneListe& l)
{
  if (l.listeElements.size() == 0)
  {
    cerr << "positionInvalide" << endl;
    throw string("positionInvalide");
  }
  else
    {
      if (l.positionElementCourant == l.listeElements.size()) // on supprime l'element courant
        {
          l.positionElementCourant = 0;
        }
      l.listeElements.pop_back();
    }
}



void supprimerCourant (UneListe& l)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    {
      UneListeElements::iterator pointeurCourant = l.listeElements.begin();
      for (unsigned int i = 1 ; i < l.positionElementCourant ; i++)
        {
          pointeurCourant++;
        } 
      if (positionCourante (l) == taille(l)) 
		  // élément courant = dernier. Il n'y aura plus de courant
	  {    
      l.listeElements.erase(pointeurCourant);
      l.positionElementCourant = 0;
	  }
	  else 
		  // élément courant n'est pas le dernier. Son suivant sera le courant.
	  {  
      l.listeElements.erase(pointeurCourant);
      l.positionElementCourant++;
      l.pointeurElementCourant++;
	  }
    }
}

void supprimerDerriereCourant (UneListe& l)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    if (l.positionElementCourant == l.listeElements.size())
    {
      cerr << "pasDeSuivant" << endl; 
      throw string("pasDeSuivant");   
    }
    else
      {
        /* Note : on ne fait pas directement 
           l.listeElements.erase(++l.pointeurElementCourant)
           car selon les operations precedemment effectuees sur la liste,
           la valeur de l.pointeurElementCourant n'est pas toujours pertinente
        */

        UneListeElements::iterator pointeurCourant =  l.listeElements.begin();
        for (unsigned int i = 1 ; i <= l.positionElementCourant ; i++)
        {
          pointeurCourant++;
        }
        l.listeElements.erase(pointeurCourant);
      }
}


void supprimerDevantCourant (UneListe& l)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    if (l.positionElementCourant == 1)
    {
      cerr << "pasDePrecedent" << endl;   
      throw string("pasDePrecedent");     
    }
    else
      {
        /* Note : on ne fait pas directement 
          l.listeElements.erase(--l.pointeurElementCourant)
          car selon les operations precedemment effectuees sur la liste,
          la valeur de l.pointeurElementCourant n'est pas toujours pertinente
        */

        UneListeElements::iterator pointeurCourant =  l.listeElements.begin();
        for (unsigned int i = 1 ; i < l.positionElementCourant-1 ; i++)
        {
          pointeurCourant++;
        }
        l.listeElements.erase(pointeurCourant);

        /* L'element courant reste inchange mais sa position doit etre
          mise a jour */
        l.positionElementCourant--;
      }
}

void supprimerEn(UneListe& l, unsigned int pos)
{
  if (pos > (l.listeElements.size()) || pos < 1)
  {
    cerr << "positionInvalide" << endl;
    throw string("positionInvalide");
  }
  else
    {
	 // s'il s'agit de la position courante, on agit comme supprimerCourant
	 if (pos == positionCourante(l))
	 {
		supprimerCourant(l);
	 }
	 else
	 {
		  // pos n'est pas la position de l'élément courant
		  UneListeElements::iterator pointeurCourant =  l.listeElements.begin();

		  for (unsigned int i = 1 ; i < pos ; i++)
		  {
			pointeurCourant++;
		  }
		  l.listeElements.erase(pointeurCourant);        		
          /* L'element courant reste inchange mais sa position doit
             etre mise a jour si positionCourante > pos */		
		   if (l.positionElementCourant > pos)
          {
            l.positionElementCourant--;
          }
	 }
    }
}


/* PRIMITIVES DE REMPLACEMENT */

void remplacerDebut (UneListe& l, UnElement e)
{
  if (l.listeElements.size() == 0)
  {
    cerr << "listeVide" << endl;
    throw string("listeVide");
  }
  else
  {
    *(l.listeElements.begin()) = e;
  }
}


void remplacerFin (UneListe& l, UnElement e)
{
  if (l.listeElements.size() == 0)
  {
    cerr << "listeVide" << endl;
    throw string("listeVide");
  }

  else
  {
    *(--l.listeElements.end()) = e;
  }
}



void remplacerCourant (UneListe& l,  UnElement e)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
  {
    *(l.pointeurElementCourant) = e;
  }
}


void remplacerDevantCourant (UneListe& l, UnElement e)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl;
    throw string("pasDeParcoursEnCours");
  }
  else
    if (l.positionElementCourant == 1)
    {
      cerr << "pasDePrecedent" << endl;
      throw string("pasDePrecedent");
    }

    else
      {
        UneListeElements::iterator pointeurCourant =  l.listeElements.begin();
        for (unsigned int i = 1 ; i < l.positionElementCourant-1 ; i++)
        {
          pointeurCourant++;
        }
        *(pointeurCourant) = e;
      }
}


void remplacerDerriereCourant (UneListe& l, UnElement e)
{
  if (l.positionElementCourant == 0)
  {
    cerr << "pasDeParcoursEnCours" << endl; 
    throw string("pasDeParcoursEnCours");
  }

  else
    if (l.positionElementCourant == l.listeElements.size())
    {
      cerr << "pasDeSuivant" << endl;
      throw string("pasDeSuivant");
    }

    else
      {
        UneListeElements::iterator pointeurCourant =  l.listeElements.begin();
        for (unsigned int i = 1 ; i <= l.positionElementCourant ; i++)
        {
          pointeurCourant++;
        }
        *(pointeurCourant) = e;
      }
}


void remplacerEn(UneListe& l, unsigned int pos, UnElement e)
{
  if (pos > (l.listeElements.size()) || pos < 1)
  {
    cerr << "positionInvalide" << endl;
    throw string("positionInvalide");
  }
  else
    {
      UneListeElements::iterator pointeurCourant =  l.listeElements.begin();

      for (unsigned int i = 1 ; i < pos ; i++)
      {
        pointeurCourant++;
      }
      *(pointeurCourant) = e;
    }
}
