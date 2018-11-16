#include "donnees.h"
#include "actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generationCode.h"
#include "menu.h"

 void menu() //menu pour le traitement de donnees
 {

 	int select = 1 ;
 	int a = 0;
 	int b = 0;

 	donnees *listeDonnees = NULL;

 	while (select >= 0 && select < 10)

    {
        printf("\nVeuillez choisir un des modes d'affichage\n");
		printf("(1) Afficher fichier\n");
		printf("(2) Trier les donnees \n");
		printf("(3) Moyenne des pouls pour une plage temps \n");
		printf("(4) Valeur maximale/minimum du pouls\n");
		printf("(5) Rechercher pouls d'un temps precis\n");
		printf("(6) Afficher le nombre de ligne de donnees\n");
		printf("(0) Quitter\n");


		scanf("%d",&select);

		switch(select)
        {
            case 0 :
                return 0 ;
                break ;

            case 1 :
                system("cls");
                listeDonnees = chargerDonnee();
                affichageliste(listeDonnees);

                break;

            case 2 :
                system("cls");
                printf("\n Que voulez vous trier ?\n");
                printf("(1) Trier le pouls en mode croissant\n");
                printf("(2) Trier le pouls en mode decroissant\n");
                printf("(3) Trier le temps en mode decroissant\n");
                scanf("%d", &a);
                switch (a)
                {
                    case 1 :
                    trisPoulsCroissant(listeDonnees);
                    break;

                    case 2 :
                    trisPoulsDecroissant(listeDonnees);
                    break ;

                    case 3 :
                    trisTempsDecroissant(listeDonnees);
                    break;

                    default:
                    printf("erreur de selection\n");
                }

                break;

            case 3 :
                printf("Donnez une plage de temps dont vous voulez la moyenne du pouls\n");
                printf("Donnez la premiere valeur de la plage de temps : ");
                scanf("%d", &a);
                printf("Donnez la derniere valeur de la plage de temps : ");
                scanf("%d", &b);
                moyenne(listeDonnees, a, b);
                break;

            case 4 :
                maxmin(listeDonnees);
                break;

            case 5 :
                printf("Donnez le temps dont vous voulez le pouls : ");
                scanf("%d", &a);
                tempsPrecis(listeDonnees, a);
                break;

            case 6 :
                nombreLigne(listeDonnees);
                break;

            default :
                printf("erreur de selection\n");
                break;
            }
    }

 }


void menuled() //menu pour commander les leds (Arduino)
{
    printf("\nQuelle mode de clignotement voulez vous ?\n");
    printf("(1) 1 led\n");
    printf("(2) 1 sur 2\n");
    printf("(3) 1 sur 3\n");
    printf("(4) clignote\n");
    printf("(5) chenille\n");
    printf("(6) bonus\n");


    scanf("%d",&selection);

    if (selection <= 6 && selection >0)
    {
        printf("marche");
        parametre(selection); //lance la fonction parametre
    }
    else
    {
        printf("erreur de condition");
    }
}



