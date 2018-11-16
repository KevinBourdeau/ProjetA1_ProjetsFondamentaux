#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "actions.h"
#include "donnees.h"


void affichagedonnee(donnees *listeDonnees) // Affiche une structure de type donnees
    {
           printf("Temps : %d    Pouls : %d\n",
                   listeDonnees->temps,
                   listeDonnees->pouls);
    }

void affichageliste(donnees *listeDonnees) //affiche toutes les donnees
{
    donnees *donneeAAfficher = listeDonnees->nextDonnees;
    while(donneeAAfficher->nextDonnees != NULL) //verifie qu'il existe un element suivant
    {
        affichagedonnee(donneeAAfficher);
        donneeAAfficher = donneeAAfficher->nextDonnees; //parcours la liste
    }
    affichagedonnee(donneeAAfficher); //done la derniere donnee
}

void tempsPrecis(donnees *listeDonnees , int temps) //trouve le pouls en fonction d'un temps donnee
{
    donnees *encours;
    encours = listeDonnees->nextDonnees;

    while (encours != NULL)
    {
        if (encours->temps == temps)
        {
        affichagedonnee(encours);
        }
    encours = encours->nextDonnees;
    }
}

void moyenne(donnees *listeDonnees, int debut, int fin) //done pouls moyen sur plage temps
{
    donnees *encours;
    encours = listeDonnees->nextDonnees;
    float moy = 0;

    while (encours != NULL)
    {
        if (encours->temps >= debut && encours->temps <= fin)
        {
            moy = moy + encours->pouls; //somme des pouls
        }
    encours = encours ->nextDonnees;
    }
    moy = (moy / (1000+fin-debut))*1000 ; //divise par le nombre de terme (temps en millisec donc *1000)
    printf("voici la moyenne du pouls de %d a %d est %f\n", debut, fin, moy);
}

void maxmin(donnees *listeDonnees) //trouve valeur max et min
{
    donnees *encours;
    encours = listeDonnees->nextDonnees;
    donnees *maxpouls;
    maxpouls = listeDonnees->nextDonnees;
    donnees *minpouls;
    minpouls = listeDonnees->nextDonnees;

        while (encours != NULL)
        {
            if (encours->pouls > maxpouls->pouls) //cherche max
            {
                maxpouls = encours;
            }
            if (encours->pouls < minpouls->pouls)//cherche min
            {
                minpouls = encours;
            }
            encours = encours->nextDonnees;
        }
        printf("le pouls maximum est pour ");
        affichagedonnee(maxpouls);
        printf("le pouls minimum est pour ");
        affichagedonnee(minpouls);
}

void nombreLigne(donnees *listeDonnees) //affiche nombre de ligne de donnees
{
    donnees *encours;
    encours = listeDonnees->nextDonnees;
    int ligne=0;

        while (encours != NULL)
        {
          encours = encours->nextDonnees;
          ligne=ligne+1; //compteur à chaque fois qu'on change de donnee
        }
    printf("Le nombre de ligne de donnees est %d \n", ligne);
}


void trisPoulsCroissant(donnees *listeDonnees) //trie le pouls de facon croissant
{
    int permutation ;//temoin pour permutation entre deux valeurs
    donnees *encours;
    donnees *encoursGrand;
    encoursGrand = NULL;

    if (listeDonnees == NULL)
        return;

    do
    {
        permutation  = 0 ; //pas de permutation
        encours = listeDonnees->nextDonnees;

        while (encours->nextDonnees != encoursGrand)
        {
            if (encours->pouls > encours->nextDonnees->pouls)
            {
                echange(encours,encours->nextDonnees);
                permutation = 1 ; //permutation
            }
            encours = encours->nextDonnees;
        }
        encours = encoursGrand;
    }
    while (permutation);
    affichageliste(listeDonnees);
}

void echange (donnees *encours , donnees *encoursGrand)//inverse le pouls et temps de deux donnees
{
   int temps;
   int pouls;

    pouls = encoursGrand->pouls;
    encoursGrand->pouls = encours->pouls;
    encours->pouls = pouls;

    temps = encoursGrand->temps;
    encoursGrand->temps = encours->temps;
    encours->temps = temps;
}

void trisTempsDecroissant(donnees *listeDonnees) //trie le temps de facon decroissant
{
    int permutation ;
    donnees *encours;
    donnees *encoursGrand;
    encoursGrand = NULL;

    if (listeDonnees == NULL)
        return;

    do
    {
        permutation  = 0 ;
        encours = listeDonnees->nextDonnees;

        while (encours->nextDonnees != encoursGrand)
        {
            if (encours->temps < encours->nextDonnees->temps)
            {
                echange(encours,encours->nextDonnees);
                permutation = 1 ;
            }
            encours = encours->nextDonnees;
        }
        encours = encoursGrand;
    }
    while (permutation);
    affichageliste(listeDonnees);
}

void trisPoulsDecroissant(donnees *listeDonnees) //trie le pouls de facon decroissante
{
    int permutation  ;
    donnees *encours;
    donnees *encoursGrand;
    encoursGrand = NULL;

    if (listeDonnees == NULL)
        return;

    do
    {
        permutation  = 0 ;
        encours = listeDonnees->nextDonnees;

        while (encours->nextDonnees != encoursGrand)
        {
            if (encours->pouls < encours->nextDonnees->pouls)
            {
                echange(encours,encours->nextDonnees);
                permutation = 1 ;
            }
            encours = encours->nextDonnees;
        }
        encours = encoursGrand;
    }
    while (permutation);
    affichageliste(listeDonnees);
}
