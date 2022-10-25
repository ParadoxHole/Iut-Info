/*
 Programme : Memotron
 But :  Retenir un carre de chiffre et répondre au question pour avoir le meilleur score
 Date de dernière modification : 19/10/2022
 Auteur : BodinMaximilien, RodriguesMatteo
 Remarques : la manière d'afficher le message d'erreur est compléxifié par un choix d'user interface
 Nous avons voulu afficher les accents, les "cout" sont parfois un peu compliqué à lire
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
    unsigned short int chiffrePairs;        // Nombre de chiffre pair du memotron
    unsigned short int chiffreImpairs;      // Nombre de chiffre impair du memotron
    unsigned short int centreDuCarre;       // nombre au centre du memotron
    unsigned short int chiffrePlusGrand;    // Le plus grand chiffre du memotron
    unsigned short int chiffrePlusPetit;    // Le plus petit chiffre du memotron
    unsigned short int scoreJoueur;         // ChiffrePlusGrand
    unsigned short int indiceCentreDuCarre; // indice du chiffre qui est au centre du carré

    /*afficherCarreEtCalculerQuestion*/
    unsigned short int chiffreAleatoire; // Chiffre aléatoire generer pour former le memotron

    /*poserQuestionEtTraiterReponse*/
    unsigned short int bonneReponse;         // Bonne réponse à la question posé
    unsigned short int reponseJoueur;        // Saisie de la réponse par le joueur
    unsigned short int numQuestionAleatoire; // Chiffre aléatoire qui permet de choisir la question

    // TRAITEMENTS

    // clavier >> initialiserLaPartie >>  scoreJoueur, tailleCarre, tempMemorisation, debugModeActif ***********************************

    // >> initialisatierLesVariables >> scoreJoueur, tailleCarre, tempMemorisation, debugModeActif, erreurSaisie
    scoreJoueur = 0;
    tailleCarre = 3;
    tempMemorisation = 10;
    debugModeActif = false;
    erreurSaisie = false;

    // tailleCarre, tempMemorisation, debugModeActif, erreurSaisie >> parametrageMenuDemarrer >> tailleCarre, tempMemorisation, debugModeActif
    while (true)
    {

        // scoreJoueur, tailleCarre, tempMemorisation, debugModeActif, erreurSaisie >> afficherMenuDemarrer >> erreurDeSaisie******************************

        // >> afficherNomDuJeu >> ecran
        afficherTexteEnCouleur("**MEMOTRON**", jaune, true);

        // tailleCarre >> afficherLaTailleActuel >> ecran
        if (tailleCarre == 3)
        {
            cout << "1/ Augmenter la taille du carre a 5 (actuellement 3)" << endl;
        }
        else
        {
            cout << "1/ Diminuer la taille du carre a 3 (actuellement 5)" << endl;
        }

        // tempMemorisation >> afficherLaDureeActuel >> ecran
        if (tempMemorisation == 10)
        {
            cout << "2/ Augmenter la temps de memorisation a 15s (actuellement 10s)" << endl;
        }
        else
        {
            cout << "2/ Diminuer la temps de memorisation a 10s (actuellement 15s)" << endl;
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

        // >> afficherJouer >> ecran
        cout << "4/ Jouer" << endl
             << endl;

        // erreurSaisie >> afficherMessageDerreur >> ecran, erreurSaisie
        if (erreurSaisie)
        {
            afficherTexteEnCouleur("Veuillez enter un chiffre entre 1 et 4 !", rouge, true);
            erreurSaisie = false;
        } // le message d'erreur est mit avant la saisie de l'utilisateur

        // clavier >> saisieChoixJoueur >> choixJoueur ****************************************************************************************************
        cout << "Votre choix : ";
        cin >> choixJoueur;
        effacer();

        // tailleCarre, tempMemorisation, debugModeActif, choixJoueur >> traiterChoixJoueur >> tailleCarre, tempMemorisation, debugModeActif, erreurSaisie *************************************
        if (choixJoueur == 4)
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

    // scoreJoueur, tailleCarre, tempMemorisation, debugModeActif >> joueurLaPartie >> scoreJoueur, bonneReponse **********************************************
    do
    {
        // tailleCarre >> initialiserLesVariableDeReponse >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, indiceCentreDuCarre
        chiffrePairs = 0;
        chiffreImpairs = 0;
        chiffrePlusGrand = 1; // initialiser au nombre le plus petit possible
        chiffrePlusPetit = 9; // initialiser au nombre le plus grand possible
        indiceCentreDuCarre = static_cast<unsigned short int>((tailleCarre * tailleCarre + 1) / 2);

        // >> afficherNomDuJeu >> ecran
        afficherTexteEnCouleur("**MEMOTRON**", jaune, true);

        // tailleCarre, indiceCentreDuCarre >> afficherCarreEtAssignerResultat >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand *********************
        for (int i = 1; i < (tailleCarre * tailleCarre) + 1; i++) // i est initialiser à 1 pour que le retour à la ligne se fasse correctement
        {
            // >> genererEtAfficherChiffreMemotron >> chiffreAleatoire *************************************************************************
            chiffreAleatoire = static_cast<unsigned short int>(random(1, 9));
            cout << chiffreAleatoire << " ";

            // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, indiceCentreDuCarre >> calculerReponse >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand

            // chiffreAleatoire, chiffrePairs, chiffreImpairs >> associerPairsImpairs >> chiffrePairs, chiffreImpairs
            chiffreAleatoire % 2 == 0 ? chiffrePairs++ : chiffreImpairs++;

            // i, chiffreAleatoire, indiceCentreDuCarre >> trouverChiffreAuCentre >> centreDuCarre
            if (i == indiceCentreDuCarre)
            {
                centreDuCarre = chiffreAleatoire;
            }

            // chiffreAleatoire,chiffrePlusGrand >> trouverChiffrePlusGrand >> chiffrePlusGrand
            if (chiffrePlusGrand < chiffreAleatoire)
            {
                chiffrePlusGrand = chiffreAleatoire;
            }

            // chiffreAleatoire,chiffrePlusPetit >> trouverChiffrePlusPetit >> chiffrePlusPetit
            if (chiffrePlusPetit > chiffreAleatoire)
            {
                chiffrePlusPetit = chiffreAleatoire;
            }

            // i, tailleCarre >> retourALaLigne >> ecran
            if (i % tailleCarre == 0)
            {
                cout << endl;
            }
        }

        // scoreJoueur >> affciherScoreActuel >> ecran
        cout << endl
             << "Votre score actuel: " << scoreJoueur << endl
             << endl;

        // tempMemorisation, debugModeActif >> lancerLeCompteARebours >> ecran ***********************************************************************************
        if (!debugModeActif)
        {
            cout << endl;
            afficherTexteEnCouleur("Compte a rebours: ", rouge, false);

            for (short int i = tempMemorisation; i >= 0; i--)
            {
                afficherNombreEnCouleur(i, rouge, false);
                cout << " ";
                pause(1);
            }

            effacer();
        }

        // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, score >> genererQuestionEtTraiterReponse >> scoreJoueur, bonneReponse
        // >> choisirUneQuestionAuHazard >> numQuestionAleatoire
        numQuestionAleatoire = static_cast<unsigned short int>(random(1, 5));

        // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, numQuestionAleatoire >> DeterminerEtAfficherQuestion >> bonneReponse
        switch (numQuestionAleatoire)
        {
        case 1:
            // centreDuCarre,bonneReponse >> Question 1 >> bonneReponse
            cout << "Quel etait le chiffre au centre du carre ? ";
            bonneReponse = centreDuCarre;
            break;
        case 2:
            // chiffrePlusGrand,bonneReponse >> Question 2 >> bonneReponse
            cout << "Quel etait le chiffre le plus grand present dans le carre ? ";
            bonneReponse = chiffrePlusGrand;
            break;
        case 3:
            // chiffrePlusPetit,bonneReponse >> Question 3 >> bonneReponse
            cout << "Quel etait le chiffre le plus petit present dans le carre ? ";
            bonneReponse = chiffrePlusPetit;
            break;
        case 4:
            // chiffrePairs,bonneReponse >> Question 4 >> bonneReponse
            cout << "Combien y avait-il de chiffres pairs dans le carre ? ";
            bonneReponse = chiffrePairs;
            break;
        case 5:
            // chiffreImpairs,bonneReponse >> Question 5 >> bonneReponse
            cout << "Combien y avait-il de chiffres impairs dans le carre ? ";
            bonneReponse = chiffreImpairs;
            break;
        }

        // clavier >> saisirReponseJoueur >> reponseJoueur
        cin >> reponseJoueur;

        // reponseJoueur, bonneReponse, scoreJoueur >> traiterReponse >> ScoreJoueur
        if (reponseJoueur == bonneReponse)
        {
            // scoreJoueur >> incrementerScoreJoueur >> scoreJoueur
            scoreJoueur++;

            // scoreJoueur >> afficherReponseEtScore >> ecran
            cout << endl;
            afficherTexteEnCouleur("Bonne reponse !", vert, true);
            cout << "Votre nouveau score est " << scoreJoueur << endl;
            pause(2); // l'écran reste visible 2 secondes
            effacer();
        }
    } while (reponseJoueur == bonneReponse);

    // scoreJoueur, bonneReponse >> FinaliserLaPartie >> ecran
    cout << endl;
    afficherTexteEnCouleur("Vous avez perdu, la reponse attendue etait ", rouge, false);
    afficherNombreEnCouleur(bonneReponse, rouge, true);
    cout << "Votre score final est " << scoreJoueur << endl;

    return 0;
}