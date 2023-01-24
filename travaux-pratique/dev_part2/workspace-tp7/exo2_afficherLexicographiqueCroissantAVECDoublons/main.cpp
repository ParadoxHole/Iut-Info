/* afficherLexicographiqueCroissantAVECDoublons
   But : A partir d'un fichier texte contennat des mots de la langue français, affiche ces mots triés par 
         ordre lexicographique croissant.   
         Toutes les occurrences d'un même mot dans le fichier sont aussi affichées à l'écran.
   Date : 14/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 2 de la feuille de  TD n°7 - R1.01 
*/
#include <iostream>
using namespace std;
#include "fichierTexte.h"
#include "liste.h"


enum Trouving{plusGrandTrouve, pasDePlusGrand, dejaPresent};

/* Déclaration des sous-programmes 
    -------------------------------*/
void afficherOrdreLexicoCroissantAvecDoublons (string nomSys);
/* Etant donné un fichier texte composé de mots de la langue française, et dont le
   nom système est fourni par le paramètre nomSys. 
   Les propriétés di fichier sont les suivantes : il peut être vide, ses mots sont 
   séparés par des séparateurs tels que espace – tabulations - sauts de ligne et de 
   page, un même mot peut apparaître plusieurs fois dans le fichier.
   
   Ce sous-programme affiche à l’écran les mots du fichier, par ordre lexicographique
   croissant(= ordre du dictionnaire), et à raison de 1 par ligne. 
   Un mot répété plusieurs fois dans le fichier est affiché autant de fois à l’écran.
*/

void rechercherPlaceMotDansListe (UneListe& pListe, string mot, bool& fdf, Trouving& trouve);
/* Cherche dans la liste pListe la place du mot mot. 
   Si le mot est déjà présent dans la liste, fdf est vrai, et trouve est égal à dejaPresent.
   Si le mot n'est pas présent dans la liste, fdf est faux, et trouve est égal à pasDePlusGrand
   si le mot est plus grand que tous les mots de la liste, ou égal à plusGrandTrouve si le mot
   est plus petit que tous les mots de la liste.
*/
void rechercheDicotomique (UneListe& pListe, string mot, bool& fdf, Trouving& trouve);


int main()
{
    // Déclaration et initialisation des éléments servant à la manipulation de fichiers
    string nomSysEntree = "data"; 

    afficherOrdreLexicoCroissantAvecDoublons(nomSysEntree);
    cout << endl;
    
    return 0;
}

    /* Définitions des sous-programmes 
    -------------------------------*/

void rechercherPlaceMotDansListe (UneListe& pListe, string mot, Trouving& trouve)
{

    trouve = pasDePlusGrand;
    allerDebut(pListe);

    while(parcoursEnCours(pListe))
    {
        if (elementCourant(pListe) == mot)
        {
            trouve = dejaPresent;
            break;
        }
        else if (elementCourant(pListe) > mot)
        {
            trouve = plusGrandTrouve;
            break;
        }
        avancer(pListe);
    }
}

void rechercheDicotomique (UneListe& pListe, string mot, Trouving& trouve)
{
    // initialisation la recherche

    // calcul bInf bSup
    int bInf = 1;
    int bSup = taille(pListe);

    string motCourant;



    // effectue le calcule
    while (true)
    {
        if (bInf > bSup)
        {

            break;
        }
        int milieu = (bInf + bSup) / 2;

        motCourant = elementEn(pListe, milieu);

        if (motCourant == mot)
        {
            trouve = dejaPresent;
            break;
        }
        else if (motCourant > mot)
        {
            bSup = milieu - 1;
            trouve = plusGrandTrouve;
        }
        else
        {
            bInf = milieu + 1;
            trouve = pasDePlusGrand;
        }
    }


}

void afficherOrdreLexicoCroissantAvecDoublons (string nomSys)
{
    UneListe maListe;
    initialiser(maListe);

    //preparation des fichiers
    UnFichierTexte ficEntree;
    associer(ficEntree, nomSys);
    ouvrir(ficEntree, consultation);

    bool fdf;
    
    Trouving trouve;
    string mot;

    //parcours fichier
    while(true){
        lireMot(ficEntree, mot, fdf);

        if (fdf)
        {
            break;
        }


        cout << "on cherche " << mot << endl;
        rechercheDicotomique(maListe, mot, trouve);

        
        // insertion du mot dans la liste
        switch (trouve)
        {
        case plusGrandTrouve:
            cout << "on insere devant" << endl;
            insererDevantCourant(maListe, mot);
            break;
        case pasDePlusGrand:
            cout << "on insere en fin" << endl;
            insererFin(maListe, mot);
            break;
        case dejaPresent:
            cout << "on insere devant doublon" << endl;
            insererDevantCourant(maListe, mot);
            break;
        }

        cout << "--------------" << endl;
    }

    fermer(ficEntree);

    afficherSequentiel(maListe);
}