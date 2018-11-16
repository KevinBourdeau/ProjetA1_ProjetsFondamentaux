#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
#include "donnees.h"


void affichagedonnee(donnees *listeDonnees);
void affichageliste(donnees *listeDonnees);
void tempsPrecis(donnees *listeDonnees, int temps);
void moyenne(donnees *listeDonnees, int debut, int fin);
void maxmin(donnees *listeDonnees) ;
void nombreLigne(donnees *listeDonnees);
void trisPoulsCroissant(donnees *listeDonnees);
void trisPoulsDecroissant(donnees *listeDonnees);
void trisPoulsCroissant(donnees *listeDonnees);
void trisTempsDecroissant(donnees *listeDonnees);
void echange (donnees *encours , donnees *encoursGrand);

#endif
