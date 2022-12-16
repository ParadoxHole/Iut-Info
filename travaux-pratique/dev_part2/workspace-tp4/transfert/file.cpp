#include "file.h"
#include<iostream> // pour l'usage du type string
using namespace std;


void initialiser (UneFile& f)
{
  while (!f.empty())
    f.pop();
}


unsigned int taille (const UneFile& f)
{
  return static_cast<unsigned int> (f.size());
}

bool estVide (const UneFile& f)
{
  return f.empty();
}

UnElement premier (const UneFile& f)
{
  if(!f.empty())
    return f.front();
  else
    {
      cerr << "fileVide" << endl;
      throw string("fileVide");
    }
}

void enfiler (UneFile& f, UnElement e)
{
  f.push(e);
}


void defiler (UneFile& f)
{
  if(!f.empty())
    f.pop();
  else
    {
      cerr << "fileVide" << endl;
      throw string("fileVide");
    }
}

void defiler (UneFile& f, UnElement& e)
{
  if(!f.empty())
    {
      e = f.front();
      f.pop();
    }
  else
    {
      cerr << "fileVide" << endl;
      throw string("fileVide");
    }
}

void remplirContenant (const unsigned short int NB_VALEURS, UneFile& f){
  for(unsigned short int i = 0; i < NB_VALEURS; i++)
    {
      enfiler(f, UnElement(i));
    }
}