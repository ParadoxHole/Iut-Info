#include "pile.h"
#include<iostream> // pour l'usage du type string
using namespace std;


void initialiser (UnePile& p)
{
  while (!p.empty())
    p.pop();
}


unsigned int taille (const UnePile& p)
{
  return static_cast <unsigned int> (p.size());
}

bool estVide (const UnePile& p)
{
  return p.empty();
}


UnElement sommet (const UnePile& p)
{

  if(!p.empty())
    return p.top();
  else
      throw string("pileVide");
}


void empiler (UnePile& p, UnElement e)
{
  p.push(e);
}


void depiler (UnePile& p)
{
  if(!p.empty())
    p.pop();
  else
      throw string("pileVide");
}


void depiler (UnePile& p, UnElement& e)
{
  if(!p.empty())
    {
      e = p.top();
      p.pop();
    }
  else
      throw string("pileVide");
}

void remplirContenant(const unsigned short int NB_VALEURS, UnePile& p){
  for(unsigned short int i = 0; i < NB_VALEURS; i++)
    {
      empiler(p, UnElement(i));
    }
}
