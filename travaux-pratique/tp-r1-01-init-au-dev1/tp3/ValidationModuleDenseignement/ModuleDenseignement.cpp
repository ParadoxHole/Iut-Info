/*
 Programme : CalculeMoyenneModulo
 But :  Calculer la moyenne d'un élève avec les notes de ses 2 modulos
 Date de dernière modification : 20/09/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    float noteOral; // note de l'evaluation orale (coef1)
    float noteEcrit; // note de l'evaluation écrite (coef2)
    const int COEF_NOTE_ORAL = 1; // coeficient de la note Oral
    const int COEF_NOTE_ECRIT = 2; // coeficient de la note écrite
    const int NOTE_MINIMUM = 10; // note minimal pour recevoir 
    float moyenne; // Resultat du calcule de la moyenne des note 1 et 2 


    // TRAITEMENTS

    // clavier >> saisieDuNombre >> note1,note2****************************************************************

    // clavier >> saisirNoteOral >> note1
    cout << "Saisir la note d'oral (coef1):  ";
    cin >> noteOral;
    // clavier >> saisirNoteEcrit >> note2
    cout << "Saisir la note d'ecrit (coef2):  ";
    cin >> noteEcrit;

    // note1, note2 >> calculeMoyenne >> moyenne****************************************************************

    moyenne = (noteOral*COEF_NOTE_ORAL + noteEcrit*COEF_NOTE_ECRIT)/(COEF_NOTE_ORAL+COEF_NOTE_ECRIT);

    // moyenne >> afficherResultat >> écran ********************************************************************
    if (moyenne >= NOTE_MINIMUM){
        cout << "recu";
    }else{
        cout << "non-recu";
    }

    return 0;
}