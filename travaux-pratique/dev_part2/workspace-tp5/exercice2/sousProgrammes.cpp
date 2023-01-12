#include <iostream>
#include <sstream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

float moyennePluviometrique (string nomSysFic)
{
    UnFichierTexte f;
    associer(f, nomSysFic);
    ouvrir(f, consultation);
    string chaine;
    bool finFichier;
    float somme = 0;
    int nbLignes = 0;
    while (true)
    {
        lireLigne(f, chaine, finFichier);
        if(finFichier){
            break;
        }
        stringstream ss(chaine);
        float pluie;
        ss >> pluie;
        somme += pluie;
        nbLignes++;
    }

    return -30.0;
}
