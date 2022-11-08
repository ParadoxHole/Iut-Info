/*
 Programme : verifNote
 But : Vérifié si un nombre est une note ou pas
 Date de dernière modification : 26/10/2022
 Auteur : maxou
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

struct Adresse
{
    string numRue;           // le numéro de rue (par exemple 2bis)
    string nomRue;           // Le nom de la rue (par exemple allée du Parc Montaury)
    unsigned int codePostal; // Le code postal (par exemple 64600)
    string ville;            // le nom de la ville (par exemple Anglet)
};

struct Personne
{
    string nom;      // Le nom de la personne
    string prenom;   // Le prénom de la personne
    Adresse adresse; // L'adresse de la personne
};

Adresse adresse(Personne personne);
// retourne l'adresse du mec

int main(void)
{
    const unsigned int NBRE_EMPLOYES = 15; // nombre d'employés dans la structure
    Personne listeEmployes[NBRE_EMPLOYES] = { // nom, prénom et adresse des employés
      {"Almeras", "Valentin", {"29", "impasse Michelle Reynaud", 64600, "Anglet"}},
      {"Gueguen", "Lucie", {"631bis", "rue Leconte", 64100, "Bayonne"}},
      {"Pomeroy", "Thibault", {"158", "boulevard Devaux", 64200, "Biarritz"}},
      {"Souchon", "Elodie", {"68", "chemin Eric Pascal", 64200, "Biarritz"}},
      {"Besnard", "Emmanuel", {"08", "place Ferrand", 64600, "Anglet"}},
      {"Gaudreau", "Lucien", {"46", "impasse Simone Humbert", 64100, "Bayonne"}},
      {"Duret", "Christelle", {"02bis", "Chemin Imbert", 64200, "Biarritz"}},
      {"Laffitte", "Anna", {"31", "rue Lemoins", 64600, "Anglet"}},
      {"Barbier", "Remi", {"88", "impasse Richard Marin", 64100, "Bayonne"}},
      {"Blondeau", "Denise", {"83", "avenue Laroche", 64200, "Biarritz"}},
      {"Berlioz", "Gabriel", {"55", "rue Descamps", 64100, "Bayonne"}},
      {"Dupont", "Benjamin", {"40", "boulevard Duvois", 64200, "Biarritz"}},
      {"Maret", "Ludovic", {"76", "impasse de Meunier", 64600, "Anglet"}},
      {"Boutin", "Alain", {"13", "boulevard de Guillou", 64200, "Biarritz"}},
      {"Dubuisson", "Marie", {"24", "rue Capucine Chevallier", 64600, "Anglet"}}
    };

    cout << adresse(listeEmployes[1]).ville ;

    return 0;
}


Adresse adresse(Personne personne)
{
    return personne.adresse;
}
