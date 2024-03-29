#include <iostream>
#include "fichierTexte.h"
#include "sousProgrammes.h"
//
using namespace std;

int main()
{
    UnFichierTexte ficCible;        // fichier de texte à modifier
    string nomSystemeficSource ;    // nom système du fichier à consulter
    string nomSystemeficCible ;     // nom système du fichier à modifier
    char choix ;

    do
    {
        // afficher menu
        cout << endl << "FEUILLES DE TD 5 & TP 5 - FICHIERS TEXTE - EXERCICE 1 - ALGORITHMES SUR FICHIERS DE LIGNES" << endl << endl;
        cout << "a : Afficher le contenu d'un fichier de texte" << endl;
        cout << "e : Etendre un fichier avec le contenu d'un autre fichier" << endl;
        cout << "v : Vider un fichier existant = Creer un nouveau fichier vide"<< endl;
        cout << "q : Quitter"<< endl;

       // Saisie-cerif reponse >> choix
        do
        {
            cout << endl << "votre choix ? " ;
            cin >> choix;
            cout << " " << endl;
        }
        while (!
                ((toupper(choix) == 'Q') || (toupper(choix) == 'A')||(toupper(choix) == 'E')||(toupper(choix) == 'V'))
              );

        // choix >> traiter action demandee
        switch (toupper(choix))
        {
        case 'A' :
            // A.- Affichage à l'écran du contenu d'un fichier texte
            // saisie du nom système du fichier concerné
            cout << "A - Affichage a l'ecran du contenu d'un fichier texte" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "nom du fichier a afficher : ";
            cin >> nomSystemeficSource;
            afficherFichierTexte(nomSystemeficSource);
            break;
        case 'E' :
            // E.- Extension d'un fichier avec le contenu d'un autre fichier"
            // saisie des noms système des fichiers concernés
            cout << endl << endl << "E - Estension (EN FIN) d'un autre fichier avec le contenu d'un autre fichier" << endl;
            cout <<                 "------------------------------------------------" << endl;
            cout << "nom du fichier CIBLE (a etendre) : ";
            cin >> nomSystemeficCible;
            cout << "nom du fichier SOURCE (contenu ajoute) : ";
            cin >> nomSystemeficSource;
            etendreFichierTexte(nomSystemeficSource, nomSystemeficCible) ;
            break;
        case 'V' :
            // vider un fichier
            // saisie du nom système du fichier concerné
            cout << "  - Vider un fichier texte" << endl;
            cout << "--------------------------" << endl;
            cout << "nom du fichier a vider / creer vide : ";
            cin >> nomSystemeficCible;
            viderFichierTexte(nomSystemeficCible);
            break;
        }

        cout << endl << endl;

    }
    while ( !(toupper(choix) == 'Q'));

    cout << endl <<  "...au revoir..." << endl;
    return 0;
}
