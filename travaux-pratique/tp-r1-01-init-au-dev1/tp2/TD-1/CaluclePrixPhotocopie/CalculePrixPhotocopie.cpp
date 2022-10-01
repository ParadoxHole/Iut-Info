/*
 Programme : CalculPrixPhotocopie
 But :  Calculer le prix de nombre de photocopie en fonction d'une réduction ou non
 Date de dernière modification : 13/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    int nbPhotocopie; // Le nombre de photocopie à payer saisie par l'utilisateur
    string abonneC; // variable qui traduira son text en booléen saisie par l'utilisateur
    float prixAPayer; // Résultat du calcule du prix à payer pour le client

    const int prixPhotocopie = 30; // Le prix d'une photocopie
    const float reduc = 0.9; // le taux de la rédusction



    // TRAITEMENTS
    // clavier >> saisirNombrePhtocopie >> nbPhotocopie
    cout << "Saisir le nombre de photocopie :  ";
    cin >> nbPhotocopie;

    // nbPhotocopie, prixPhotocopie >> calculerPrix >> prixAPayer
    prixAPayer = nbPhotocopie*prixPhotocopie;

    // clavier >> clientAbonné >> abonneC
    cout << "le client est-il abonne ? :";
    cin >> abonneC;

    // Effectue le calcule de la réduction si le client est abonné
    // reduc >> calculeReduc >> prixAPayer
    if (abonneC == "Oui" || abonneC == "oui" ){
        prixAPayer = prixAPayer*reduc;
    }
    
    // PrixAPayer >> afficherPrixAPayer >> écran
    cout << "Prix :" << prixAPayer/100 << "€" << endl;

    return 0;
}