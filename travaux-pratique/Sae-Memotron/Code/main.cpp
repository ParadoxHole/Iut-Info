/*
 Programme : Memotron
 But :  Retenir un carre de chiffre et répondre au question pour avoir le meilleur score
 Date de dernière modification : 4/10/2022
 Auteur : BodinMaximilien, RodriguesMatteo
 Remarques :
*/

#include "game-tools.h"
#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    /*initialiserLaPartie*/
    unsigned short int tailleCarre;      // La taille du carré du memotron généré
    unsigned short int tempMemorisation; // Le temps de memorisation d'ont dispose le joueur
    bool debugModeActif;                 // Indique l'etat du mode de débogage Actif/Inactif
    bool erreurSaisie;                   // Indique si il y a eu une erreur dans la saisie
    unsigned short int choixJoueur;      // Le choix du joueur

    /*jouerLaPartie*/
    unsigned short int chiffrePairs;     // Nombre de chiffre pair du memotron
    unsigned short int chiffreImpairs;   // Nombre de chiffre impair du memotron
    unsigned short int centreDuCarre;    // nombre au centre du memotron
    unsigned short int chiffrePlusGrand; // Le plus grand chiffre du memotron
    unsigned short int chiffrePlusPetit; // Le plus petit chiffre du memotron
    unsigned short int scoreJoueur;      // ChiffrePlusGrand

    /*afficherCarreEtCalculerQuestion*/
    unsigned short int chiffreAleatoire; // Chiffre aléatoire generer pour former le memotron

    /*poserQuestionEtTraiterReponse*/
    unsigned short int bonneReponse;         // Bonne réponse à la question posé
    unsigned short int reponseJoueur;        // Saisie de la réponse par le joueur
    unsigned short int numQuestionAleatoire; // Chiffre aléatoire qui permet de choisir la question

    // TRAITEMENTS

    // clavier >> initialiserLaPartie >> tailleCarre, tempMemorisation, debugModeActif ***********************************

    // initialiser les variables >> tailleCarre, tempMemorisation, debugModeActif, erreurSaisie
    tailleCarre = 3;
    tempMemorisation = 10;
    debugModeActif = false;
    erreurSaisie = false;

    // tailleCarre, tempMemorisation, debugModeActif, erreurSaisie >> parametrageMenuDemarrer >> tailleCarre, tempMemorisation, debugModeActif
    while (true)
    {

        // tailleCarre, tempMemorisation, debugModeActif, erreurSaisie >> afficherMenuDemarrer >> erreurDeSaisie******************************

        // >> afficherNomDuJeu >> ecran
        cout << "**MEMOTRON**" << endl;

        // tailleCarre >> afficherLaTailleActuel >> ecran
        if (tailleCarre == 3)
        {
            cout << "1/ Augmenter la taille du carre à 5 (actuellement 3)" << endl;
        }
        else
        {
            cout << "1/ Diminuer la taille du carre à 3 (actuellement 5)" << endl;
        }

        // tempMemorisation >> afficherLaDureeActuel >> ecran
        if (tempMemorisation == 10)
        {
            cout << "2/ Augmenter la temps de memorisation à 15s (actuellement 10s)" << endl;
        }
        else
        {
            cout << "2/ Diminuer la temps de memorisation à 10s (actuellement 15s)" << endl;
        }

        // debugModeActif >> afficherEtatDuModeDebug >> ecran
        if (debugModeActif)
        {
            cout << "3/ Desactiver le mode debug" << endl;
        }
        else
        {
            cout << "3/ Activer le mode debug" << endl;
        }

        // afficherJouer >> ecran
        cout << "4/ Jouer\n"
             << endl;

        // erreurSaisie >> afficherMessageDerreur >> ecran, erreurSaisie
        if (erreurSaisie)
        {
            cout << "Veuillez enter une chiffre entre 1 et 4 !" << endl;
            erreurSaisie = false;
        }

        // saisieChoixJoueur >> choixJoueur ****************************************************************************************************
        cout << "Votre choix : ";
        cin >> choixJoueur;
        effacer();

        // choixJoueur >> traiterChoixJoueur >> tailleCarre, tempMemorisation, debugModeActif, erreurSaisie*************************************
        if (choixJoueur == 4) // le giga commentaire
        {
            break;
        }

        switch (choixJoueur)
        {
        // tailleCarre >> changerTaille >> tailleCarre
        case 1:
            tailleCarre = (tailleCarre == 3) ? 5 : 3;
            break;

        // tempMemorisation >> changerTemp >> tempMemorisation
        case 2:
            tempMemorisation = (tempMemorisation == 10) ? 15 : 10;
            break;

        // debugModeActif >> changerdebugMode >> debugModeActif
        case 3:
            debugModeActif = (debugModeActif) ? false : true;
            break;

        // >> mettreErreurDeSaisieAVrai >> erreurSaisie
        default:
            erreurSaisie = true;
            break;
        }
    }

    // tailleCarre, tempMemorisation, debugModeActif >> joueurLaPartie >> écran
    while (true)
    {
        // tailleCarre >> afficherCarre >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand *********************
        for (int i = 1; i < (tailleCarre * tailleCarre)+1; i++) // i est initialiser à 1 pour que le retour à la ligne se fasse correctement
        {
            // >> afficherEtGenererChiffreMemotron >> chiffreAleatoire
            chiffreAleatoire = random(1,9);
            cout << chiffreAleatoire << " ";

            // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand >> calculerQuestion >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand
            
            // chiffreAleatoire, chiffrePairs, chiffreImpairs >> associerPairImpair >> chiffrePairs, chiffreImpairs
            chiffreAleatoire % 2 == 0 ? chiffrePairs += 1 : chiffreImpairs += 1;

            // i, tailleCarre, chiffreAleatoire, centreDuCarre >> trouverChiffreAuCentre >> centreDuCarre
            if (i == (tailleCarre*tailleCarre+1)/2)
            {
                centreDuCarre = chiffreAleatoire;
            }
            

            // i, tailleCarre >> retourALaLigne >> ecran
            if (i % tailleCarre == 0)
            {
                cout << "\n";
            }
        }
        // scoreJoueur >> affciherScoreActuel >> ecran *****************************************************************************************

        // tempMemorisation >> lancerLeCompteARebour >> ecran ***********************************************************************************

        // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, score >> gererQuestion >> scoreJoueur ***************
        // >> choisirUneQuestionAuHazard >> numQuestionAleatoire
        // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, numQuestionAleatoire >> DeterminerEtAfficherQuestion >>bonneReponse
        switch (numQuestionAleatoire)
        {
        case 1:
            //
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            //
            break;
        case 5:
            //
            break;
        }
        // >> saisirReponseJoueur >> reponseJoueur
        // reponseJoueur, bonneReponse, scoreJoueur >> traiterReponse >> ScoreJoueur
        if (reponseJoueur = bonneReponse)
        {
            // scoreJoueur >> incrementerScoreJoueur >> scoreJoueur

            // scoreJoueur >> afficherReponseEtScore >> ecran
        }
        else
        {
            break;
        }
        
    }

    return 0;
}