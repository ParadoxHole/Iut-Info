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
        tailleCarre == 3 ? cout << "1/ Augmenter la taille du carr" << char(130) << " " << char(133) << " 5 (actuellement 3)" << endl : cout << "1/ Diminuer la taille du carr" << char(130) << " " << char(133) << " 3 (actuellement 5)" << endl;

        // tempMemorisation >> afficherLaDureeActuel >> ecran
        tempMemorisation == 10 ? cout << "2/ Augmenter la temps de m" << char(130) << "morisation " << char(133) << " 15s (actuellement 10s)" << endl : cout << "2/ Diminuer la temps de m" << char(130) << "morisation " << char(133) << " 10s (actuellement 15s)" << endl;

        // debugModeActif >> afficherEtatDuModeDebug >> ecran
        debugModeActif ? cout << "3/ D" << char(130) << "sactiver le mode debug" << endl : cout << "3/ Activer le mode debug" << endl;

        // afficherJouer >> ecran
        cout << "4/ Jouer\n"
             << endl;

        // erreurSaisie >> afficherMessageDerreur >> ecran, erreurSaisie
        if (erreurSaisie)
        {
            afficherTexteEnCouleur("Veuillez enter un chiffre entre 1 et 4 !", rouge, true);
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

        // erreurSaisie >> mettreErreurDeSaisieAVrai >> erreurSaisie
        default:
            erreurSaisie = true;
            break;
        }
    }

    // tailleCarre, tempMemorisation, debugModeActif >> joueurLaPartie >> scoreJoueur, bonneReponse
    do
    {
        // >> initialiserLesVariableDeReponse >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand
        chiffrePairs = 0;
        chiffreImpairs = 0;
        chiffrePlusGrand = 0;
        chiffrePlusPetit = 0;

        // >> afficherNomDuJeu >> ecran
        afficherTexteEnCouleur("**MEMOTRON**", jaune, true);

        // tailleCarre >> afficherCarre >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand *********************
        for (int i = 1; i < (tailleCarre * tailleCarre) + 1; i++) // i est initialiser à 1 pour que le retour à la ligne se fasse correctement
        {
            // >> afficherEtGenererChiffreMemotron >> chiffreAleatoire *************************************************************************
            chiffreAleatoire = random(1, 9);
            cout << chiffreAleatoire << " ";

            // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand >> calculerQuestion >> chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand

            // chiffreAleatoire, chiffrePairs, chiffreImpairs >> associerPairImpair >> chiffrePairs, chiffreImpairs
            chiffreAleatoire % 2 == 0 ? chiffrePairs += 1 : chiffreImpairs += 1;

            // i, tailleCarre, chiffreAleatoire, centreDuCarre >> trouverChiffreAuCentre >> centreDuCarre
            if (i == (tailleCarre * tailleCarre + 1) / 2)
            {
                centreDuCarre = chiffreAleatoire;
            }
            
            // i >> initaliserAuPremierPassage >> chiffrePlusGrand, chiffrePlusPetit
            if (i == 1)
            {
                chiffrePlusGrand = chiffreAleatoire;
                chiffrePlusPetit = chiffreAleatoire;
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

            // i, tailleCarre >> retourALaLigne >> ecran ***************************************************************************************
            if (i % tailleCarre == 0)
            {
                cout << "\n";
            }
        }

        // scoreJoueur >> affciherScoreActuel >> ecran ******************************************************************************************
        cout << "\nVotre score actuel: " << scoreJoueur << endl
             << "\n";

        // tempMemorisation, debugModeActif >> lancerLeCompteARebours >> ecran ***********************************************************************************
        if (!debugModeActif)
        {
            afficherTexteEnCouleur("\nCompte a rebours: ", rouge, false);

            for (short int i = tempMemorisation; i >= 0; i--)
            {
                afficherNombreEnCouleur(i, rouge, false);
                cout << " ";
                Sleep(1000);
            }

            effacer();
        }

        // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, score >> gererQuestion >> scoreJoueur ***************
        // >> choisirUneQuestionAuHazard >> numQuestionAleatoire
        numQuestionAleatoire = random(1, 5);

        // chiffrePairs, chiffreImpairs, centreDuCarre, chiffrePlusPetit, chiffrePlusGrand, numQuestionAleatoire >> DeterminerEtAfficherQuestion >>bonneReponse
        switch (numQuestionAleatoire)
        {
        case 1:
            // Question 1
            cout << "Quel " << char(130) << "tait le chiffre au centre du carr" << char(130) << " ? ";
            bonneReponse = centreDuCarre;
            break;
        case 2:
            // Question 2
            cout << "Quel " << char(130) << "tait le chiffre le plus grand pr" << char(130) << "sent dans le carr" << char(130) << " ? ";
            bonneReponse = chiffrePlusGrand;
            break;
        case 3:
            // Question 3
            cout << "Quel " << char(130) << "tait le chiffre le plus petit pr" << char(130) << "sent dans le carr" << char(130) << " ? ";
            bonneReponse = chiffrePlusPetit;
            break;
        case 4:
            // Question 4
            cout << "Combien y avait-il de chiffres pairs dans le carr" << char(130) << " ? ";
            bonneReponse = chiffrePairs;
            break;
        case 5:
            // Question 5
            cout << "Combien y avait-il de chiffres impairs dans le carr" << char(130) << " ? ";
            bonneReponse = chiffreImpairs;
            break;
        }

        // clavier >> saisirReponseJoueur >> reponseJoueur
        cin >> reponseJoueur;

        // reponseJoueur, bonneReponse, scoreJoueur >> traiterReponse >> ScoreJoueur
        if (reponseJoueur == bonneReponse)
        {
            // scoreJoueur >> incrementerScoreJoueur >> scoreJoueur
            scoreJoueur += 1;

            // scoreJoueur >> afficherReponseEtScore >> ecran
            afficherTexteEnCouleur("\nBonne reponse !", vert, true);
            cout << "Votre nouveau score est " << scoreJoueur << endl;
            Sleep(2000); // l'écran reste visible 2 secondes
            effacer();
        }
    } while (reponseJoueur == bonneReponse);

    // scoreJoueur, bonneReponse >> FinaliserLaPartie
    afficherTexteEnCouleur("\nVous avez perdu, la reponse attendue etait ", rouge, false);
    afficherNombreEnCouleur(bonneReponse, rouge, true);
    cout << "Votre score final est " << scoreJoueur << endl;

    return 0;
}