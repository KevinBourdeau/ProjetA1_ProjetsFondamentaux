#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "donnees.h"
#include "actions.h"
#include "menu.h"
#include "generationCode.h"


int main()
{
    int choixmenu = 0;

    while (choixmenu>= 0 && choixmenu <3){

    printf("\nQuel menu voulez vous ?\n\n");
    printf("(1) Controler les leds\n");
    printf("(2) Traitement de donnes\n");
    printf("(0) Quitter\n");
    scanf("%d",&choixmenu );


    switch (choixmenu){
    case 1 :
        menuled();
        break ;

    case 2 :
        menu();
        break;

    case 0:
        return 0 ;
        break ;

    default :
        printf("erreur de selection\n");
        break ;
    }
    }
}
