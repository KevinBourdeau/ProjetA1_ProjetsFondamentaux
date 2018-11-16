#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "donnees.h"


donnees *chargerDonnee ()
{
    donnees *listeDonnee = NULL;
    donnees *donneePrecedente = NULL;
    donnees *donneeActuelle = NULL;

    int temps;
    int pouls;
    char lignes[500];
    int verifFermeture = 1;

    FILE *fichier; //initialise pointeur sur fichier
    listeDonnee = malloc(sizeof(donnees)); // Attribut la taille de ma strucutre
    donneeActuelle = listeDonnee;

    fichier = fopen("Battement_coeur/Battements.csv", "r"); //charge de fichier en mode lecture

    if (fichier == NULL)
    {
        printf("Le fichier n'a pas pu etre ouvert\n");
    }

    else
    {
            printf("Le fichier a ete ouvert\n");
            memset(lignes,' ', 500); //recopie le fichier en chaine de caractere
            while(fgets(lignes, 500, fichier)) //lit et range les caracteres
            {
                sscanf(lignes, "%d ; %d\n", &temps, &pouls);
                donneePrecedente = creerDonnee(temps, pouls); //creation de type donnee
                ajouterDonneeListe(donneePrecedente, donneeActuelle); //ajout du nouvel elements
                donneeActuelle = donneePrecedente;
            }
    }
    verifFermeture = fclose(fichier);
    if(verifFermeture == 0)
    {
        printf("Succes fermeture du fichier\n");
    }
    else
    {
        printf("Echec fermeture du fichier\n");
    }
    return listeDonnee ;
}

void ajouterDonneeListe(donnees *AjouterDonnee, donnees *DerniereListe) //ajout d'un element a la liste chainee
{
    DerniereListe->nextDonnees = AjouterDonnee;
}

donnees *creerDonnee (int temps, int pouls) //creation de type donnee
{
    donnees *DonneeACreer;
    DonneeACreer = malloc(sizeof(donnees)); //alloue de la place memoire

    DonneeACreer->pouls = pouls;
    DonneeACreer->temps = temps;
    DonneeACreer->nextDonnees = NULL;

    return DonneeACreer;
}


