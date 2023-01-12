#include "sousProgrammes.h"
#include "fichierTexte.h"
#include <iostream>
using namespace std;

void afficherFichierTexte(string nomSysFic)
{
	UnFichierTexte f;
	associer(f, nomSysFic);
	ouvrir(f, consultation);
	string chaine;
	bool finFichier;
	while (true)
	{
		lireLigne(f, chaine, finFichier);
		if(finFichier){
			break;
		}
		cout << chaine << endl;
	}
	fermer(f);
}

void etendreFichierTexte (string nomSysFicSource, string nomSysFicCible)
{
	UnFichierTexte fSource, fCible;
	associer(fSource, nomSysFicSource);
	associer(fCible, nomSysFicCible);

	ouvrir(fSource, consultation);
	ouvrir(fCible, extension);

	string chaine;
	bool finFichier;
	while (true)
	{
		lireLigne(fSource, chaine, finFichier);
		if(finFichier){
			break;
		}
		ecrireLigne(fCible, chaine);
	}

	fermer(fSource);
	fermer(fCible);
}

void viderFichierTexte(string nomSysFic)
{
	UnFichierTexte f;
	associer(f, nomSysFic);
	ouvrir(f, creation);
	fermer(f);
}