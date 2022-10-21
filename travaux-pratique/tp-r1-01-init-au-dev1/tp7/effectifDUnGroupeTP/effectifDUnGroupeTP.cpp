/*
 Programme : effectifDUnGroupeTP
 But : afficher combien d'étudiant sont inscrits dans un groupe de TP
 Date de dernière modification : 21/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    struct Etudiant
    {
        string nom;
        string prenom;
        unsigned short int td;
        unsigned short int tp;
    };

    const unsigned int EFFECTIF_S1 = 15;
    const unsigned int EFFECTIF_S3 = 60;

    Etudiant etudiantsS1[EFFECTIF_S1] = {
    {"Almeras", "Valentin", 1, 1}, {"Gueguen", "Lucie", 1, 1},
    {"Pomeroy", "Thibault", 1, 1}, {"Souchon", "Elodie", 1, 2},
    {"Besnard", "Emmanuel", 1, 2}, {"Gaudreau", "Lucien", 2, 3},
    {"Duret", "Christelle", 2, 3}, {"Laffitte", "Anna", 2, 4},
    {"Barbier", "Remi", 2, 4},     {"Blondeau", "Denise", 2, 4},
    {"Berlioz", "Gabriel", 2, 4},  {"Dupont", "Benjamin", 3, 5},
    {"Maret", "Ludovic", 3, 5},    {"Boutin", "Alain", 3, 5},
    {"Dubuisson", "Marie", 3, 5}
    };
    Etudiant etudiantsS3[EFFECTIF_S3];

    unsigned short int nbEtudiant;
    unsigned short int tp;

    // TRAITEMENTS
    // clavier >> saisieTp >> tp
    cout << "Entrez un numero de TP: ";
    cin >> tp;

    // EFFECTIF_S1, etudiantsS1,tp >> compterEtudiant >> nbEtudiant ***************************************************
    for(unsigned short int i = 0 ; i< EFFECTIF_S1 ; i++){
        if (etudiantsS1[i].tp == tp)
        {
            nbEtudiant++;
        }
    }

    // nbEtudiant >> affichernbEtudiant >> ecran *****************************************************
    cout << "il y a " << nbEtudiant << " dans ce tp";
    
    return 0;
}