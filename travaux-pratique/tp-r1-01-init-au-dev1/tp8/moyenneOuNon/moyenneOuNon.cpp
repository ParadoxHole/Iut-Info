/*
 Programme : moyenneOuNon
 But : calculé combien d'etudiant ont eu la moyenne et combien n'ont pas eu la moyenne
 Date de dernière modification : 27/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

struct UnEtudiant
    {
    string nom;    // nom de l'étudiant
    string prenom; // prénom de l'étudiant
    float note;    // note obtenue à l'examen
    };

void moyenneOuNon(const UnEtudiant notes[], int NbEtdiants, int& moyenneurs, int& nonMoyenneurs);
/*calculé combien d'etudiant ont eu la moyenne et combien n'ont pas eu la moyenne*/

int main(void)
{
    // VARIABLES

    // Nombre d'étudiants inscrits en semestre 1 :
    const unsigned int EFFECTIF_S1 = 15;
    int moyenneurs = 0;
    int nonMoyenneurs = 0;

    // Résultats examen du 15 février :
    UnEtudiant notesExamDu15fevrier[EFFECTIF_S1] = {
        {"Almeras", "Valentin", 15}, {"Gueguen", "Lucie", 8.5},
        {"Pomeroy", "Thibault", 4.5}, {"Souchon", "Elodie", 18},
        {"Besnard", "Emmanuel", 12}, {"Gaudreau", "Lucien", 0},
        {"Duret", "Christelle", 10.5}, {"Laffitte", "Anna", 13},
        {"Barbier", "Remi", 15}, {"Blondeau", "Denise", 7},
        {"Berlioz", "Gabriel", 9.5}, {"Dupont", "Benjamin", 3},
        {"Maret", "Ludovic", 13.5}, {"Boutin", "Alain", 12},
        {"Dubuisson", "Marie", 19}};

    moyenneOuNon(notesExamDu15fevrier, EFFECTIF_S1, moyenneurs, nonMoyenneurs);
    cout << "il y a " << moyenneurs << " etudiant qui ont eu la moyenne" << endl;
    cout << "il y a " << nonMoyenneurs << " etudiant qui n'ont pas eu la moyenne";

    return 0;
}

void moyenneOuNon(const UnEtudiant notes[], int NbEtdiants, int& moyenneurs, int& nonMoyenneurs)
{
    for (int i = 0; i < NbEtdiants; i++)
    {
        if (notes[i].note > 10)
        {
            nonMoyenneurs++;
        }
        else
        {
            moyenneurs++;
        }
    }
}