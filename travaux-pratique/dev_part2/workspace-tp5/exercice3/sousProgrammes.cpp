#include <iostream>
//#include <fstream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

// Sous-programmes utilisés par les sous-programmes de cryptage
// ---------------------------------------------------------------------
string genererNom(string nom);
/* retourne un nouveau nom de fichier contenant --> _crypted
   cas de figure :
   nom    -->  nouveauNom généré     : motif
   .           .                     : nom de fichier illégal, la fonction retourne le paramètre initial donné
   .h          .h_crypted            : le point est ici unla marque d'un fichier caché, "_crypted" est donc ajouté
                                       en fin de nom pour que le nouveau nom de fichier soit aussi un nom de fichier caché
   x.          x._crypted            : pas de suffixe après la point, "_crypted" ajouté en fin de nom
   x           x_crypted             : pas de suffixe, "_crypted" ajouté en fin de nom
   x.h         x_crypted.h           : "_crypted" inséré avant le point de suffixe
   x.js        x_crypted.js          : "_crypted" inséré avant le point de suffixe
   x.cpp       x_crypted.cpp         : "_crypted" inséré avant le point de suffixe
   x.data      x_crypted.data        : "_crypted" inséré avant le point de suffixe
   x.config    x_crypted.config      : "_crypted" inséré avant le point de suffixe
   x.texinfo   x_crypted.texinfo     : "_crypted" inséré avant le point de suffixe
   x.12345678  x.12345678_crypted    : au dela de 7 caractères après le point, on considère
                                       que le point fait partie du nom du fichier et ne marque pas
                                       un suffixe --> "_crypted" ajouté en fin de nom
   ../x.h      ../x_crypted.h
   ../x        ../x_crypted
   ./x.h       ./x_crypted.h
   ./x         ./x_crypted

    sources : https://fr.wikipedia.org/wiki/Extension_de_nom_de_fichier
              https://fr.wikipedia.org/wiki/Liste_d%27extensions_de_fichiers

    cas particulier non (ou mal traité) : x.tar.gz --> x.tar_crypted.gz
   */
// ---------------------------------------------------------------------

string cryptage(string nomSysFicSource)
{
    // Version SIMPLE

    UnFichierTexte FicSource;
    associer(FicSource, nomSysFicSource);
    ouvrir(FicSource, consultation);

    UnFichierTexte FicCible;
    string nomSysFicCible = genererNom(nomSysFicSource);
    associer(FicCible, nomSysFicCible);
    ouvrir(FicCible, creation);

    char caractere;
    bool fdf;

    while (true)
    {
        lireCar(FicSource, caractere, fdf);
        if (fdf)
        {
            break;
        }
        switch (caractere)
        {
            {
            case 'a':
            case 'A':
                caractere = 'e';
                break;
            case 'e':
            case 'E':
                caractere = 'i';
                break;
            case 'i':
            case 'I':
                caractere = 'o';
                break;
            case 'o':
            case 'O':
                caractere = 'u';
                break;
            case 'u':
            case 'U':
                caractere = 'y';
                break;
            case 'y':
            case 'Y':
                caractere = 'a';
                break;
            }
        }
        ecrire(FicCible, caractere);
    }
    fermer(FicSource);
    fermer(FicCible);
    return nomSysFicCible;
}
string cryptage(string nomSysFicSource, string nomSysFicCodes)
{
    UnFichierTexte FicSource;
    associer(FicSource, nomSysFicSource);
    ouvrir(FicSource, consultation);

    UnFichierTexte FicCodes;
    associer(FicCodes, nomSysFicCodes);

    UnFichierTexte FicCible;
    string nomSysFicCible = genererNom(nomSysFicSource);
    associer(FicCible, nomSysFicCible);
    ouvrir(FicCible, creation);

    char caractere;
    string ligne;

    bool fdf;
    bool fdfCodes;

    while (true)
    {
        lireCar(FicSource, caractere, fdf);
        if (fdf)
        {
            break;
        }
        ouvrir(FicCodes, consultation);
        while (true)
        {
            lireLigne(FicCodes, ligne, fdfCodes);
            if (fdfCodes)
            {
                break;
            }
            if (ligne[0] == caractere)
            {
                unsigned short int i = 1;
                while (ligne[i] == ' ')
                {
                    i++;
                }
                caractere = ligne[i];
                break;
            } 
        }
        fermer(FicCodes);
        ecrire(FicCible, caractere);
    }

    fermer(FicSource);
    fermer(FicCible);
    return nomSysFicCible;
}

// ---------------------------------------------------------------------
// Corps des sous-programmes utilisés par les sous-programmes de cryptage
string genererNom(string nom)
{
    enum UnCas
    {
        nomIllegal,
        ajouterEnFin,
        insererAvantPoint
    };
    string nouveauNom = "";
    bool trouvePoint = false;
    bool trouveSlash = false;
    unsigned int posPoint; // position du dernier point, s'il en existe dans la chaîne nom
    unsigned int posSlash; // position du dernier slash, s'il en existe dans la chaîne nom
    UnCas cas;

    // nom >> determiner position dernierSlash >> posSlash
    for (unsigned int i = 0; i < nom.length(); i++)
    {
        if (nom[i] == '/')
        {
            trouveSlash = true;
            posSlash = i;
        }
    }
    // nom, trouveSlash, [posSlash] >> Déterminer position du dernier point >> trouvé, posPoint
    if (trouveSlash)
    {
        // on cherche le point de suffixe après les caractères indiquant le chemin relatif
        for (unsigned int i = posSlash + 1; i < nom.length(); i++)
        {
            if (nom[i] == '.')
            {
                trouvePoint = true;
                posPoint = i;
            }
        }
    }
    else
    {
        // on cherche le point de suffixe dès le début du nom de fichier
        for (unsigned int i = 0; i < nom.length(); i++)
        {
            if (nom[i] == '.')
            {
                trouvePoint = true;
                posPoint = i;
            }
        }
    }

    // posPoint, mot >> Analyse de la situation >> cas
    if (trouvePoint && (posPoint == 0) && nom.length() == 1)
    {
        // le nom ne contient qu'un point --> mauvais nom de fichier, on ne fait rien
        cas = nomIllegal;
    }
    else if (trouvePoint && (posPoint == 0) && nom.length() > 1)
    {
        // le nom démarre par un point --> c'est un fichier caché, on ajoute _crypted en fin de nom (après le point)
        cas = ajouterEnFin;
    }
    else if (trouvePoint && (posPoint > 0))
    {
        // mot contient au moins un point.
        // le dernier . est considéré comme . de suffixe si la longueur du suffixe est <= 7
        // sinon, le . est considéré comme faisant partie du nom de fichier
        if (((nom.length() - posPoint - 1) <= 7) && ((nom.length() - posPoint - 1) > 0))
        {
            cas = insererAvantPoint;
        }
        else
        {
            cas = ajouterEnFin;
        }
    }
    else // !trouve
    {
        // pas de point, ajout de la chaîne en fin de nom
        cas = ajouterEnFin;
    }

    // cas, posPoint, nom >> Generer le nouveaunom selon le cas >> nouveauNom
    switch (cas)
    {
    case nomIllegal:
        nouveauNom = nom;
        break;
    case ajouterEnFin:
        nouveauNom = nom + "_crypted";
        break;
    case insererAvantPoint:
        // ajouter la partie avant le point
        for (unsigned int i = 0; i < posPoint; i++)
        {
            nouveauNom = nouveauNom + nom[i];
        }

        // ajouter le tterme "_crypted" et le point
        nouveauNom = nouveauNom + "_crypted.";

        // ajouter la fin
        for (unsigned int i = posPoint + 1; i < nom.length(); i++)
        {
            nouveauNom = nouveauNom + nom[i];
        }
        break;
    }

    return nouveauNom;
}
