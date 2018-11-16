#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

void parametre(int mode) //ecrit dans param.h (Arduino)
{
    FILE *fichier = NULL; //initialise le pointeur
    fichier = fopen("main/param.h", "w"); //ouvre le fichier en mode ecriture

    if (fichier!=NULL)
    {
        fprintf(fichier, "int selection = %d ; ", mode); //ecrit dans le fichier
        fclose(fichier); //ferme le fichier
    }
    else
    {
       printf("\nfichier pas trouvé");
    }
}

