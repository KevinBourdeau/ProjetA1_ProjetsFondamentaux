#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

 typedef struct donnees donnees; //composition du type donnees
 struct donnees
    {
        int temps;
        int pouls;
        donnees* nextDonnees; //pointeur sur l'element suivant
    };

donnees *chargerDonnee();
void ajouterDonneeListe(donnees *AjouterDonnee, donnees *DerniereListe);
donnees *creerDonnee (int temps, int pouls);




#endif
