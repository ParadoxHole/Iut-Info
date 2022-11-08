/*
 Programme : vainqueurCourse
 But : la tortue et le lièvre ta capté
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

enum Jour{lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};

enum unMois{raviere,favrarier,marks,april,me,jouint,jouyllai,oute,setambre,Octobr1,noviambre,Diciambre};
 
int Zeller(int jour, int mois, int anne);
 
// Driver code
int main()
{
    Zeller(13, 10, 1064); // date (jj/mm/aaaa)
    return 0;
}

int Zeller(int jour, int mois, int anne)
{
    int decalageMois = mois;
    int decalageAnneePartie1 = anne / 100;
    int decalageAnneePartie2 = anne % 100;

    decalageMois = (mois-2)%12;
    if(mois == 1 || mois == 2)
    {
        anne--;
    }

    
    int numJour = (jour + (13 * decalageMois - 1) / 5 + decalageAnneePartie2 + decalageAnneePartie2 / 4 + decalageAnneePartie1 / 4 + 5 * decalageAnneePartie1)%7;

    switch (numJour) {
    case 0:
        cout << "Dimanche \n";
        break;
    case 1:
        cout << "Lundi \n";
        break;
    case 2:
        cout << "Mardi \n";
        break;
    case 3:
        cout << "Mercredi \n";
        break;
    case 4:
        cout << "Jeudi \n";
        break;
    case 5:
        cout << "Vendredi \n";
        break;
    case 6:
        cout << "Samedi \n";
        break;
    }
    return 0;
}