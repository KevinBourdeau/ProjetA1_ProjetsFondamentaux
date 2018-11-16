#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

void menuled(){

    printf("Quelle mode de clignotement voulez vous ?\n");
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
           parametre(selection);
        }
    else {
            printf("erreur de condition");
        }
    }



