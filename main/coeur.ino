#include "coeur.h"


void parametre(){ //selection du mode avec la valeur provonant de l'utilisateur
    switch (selection){
    case 1 :
    choix();
    break;
    case 2 :
    unesurdeux();
    break;
    case 3 :
    unesurtrois();
    break;
    case 4 : 
    clignote();
    break;
    case 5 :
    chenille();
    break;
    case 6:
    bonus();
    break;
  }
}

void choix(){ //alume une led
  i= random (2,11); //choix de la le qui clignote
  digitalWrite(i,HIGH);
  delay(battement/4);
  digitalWrite(i,LOW);
  delay(battement/4);
  }

void unesurdeux(){ //clignote toute une sur deux 
  for(i=2;i<12;i=i+2)
  { 
    delay(1); // delais invisible a l'oeil pour allumer chaque led une par une, mais visible en meme temps
    digitalWrite(i,HIGH);
  }
  delay(battement/4); //delais leds allumees
  for(i=2;i<12;i=i+2)
  {
    delay(1); //delais invisible 
    digitalWrite(i,LOW);
  }
  delay(battement/4); //delais leds eteintes
}
void clignote(){ //tout clignote
    for(i=2;i<12;i++)
    { 
      delay(1); // delais invisible a l'oeil pour allumer chaque led une par une, mais visible en meme temps
      digitalWrite(i,LOW);
    }
    delay(battement/2); //delais leds allumees
    
    for(i=2;i<12;i++)//eteint les leds
    {
      delay(1); //delais invisible 
      digitalWrite(i,HIGH);
    }
  delay(battement/2); //delais leds eteintes
}

void chenille(){ //clignote une par une
for (int i=2 ; i < 12 ; i++)
{
    digitalWrite(i, HIGH);
    delay(battement/40);
    digitalWrite(i, LOW);
    delay(battement/40);
  }
}

void unesurtrois(){ //clignote toutes une sur trois
  for(i=2;i<12;i=i+3)
  { 
    delay(1); // delais invisible a l'oeil pour allumer chaque led une par une, mais visible en meme temps
    digitalWrite(i,LOW);
  }
  delay(battement/2); //delais leds allumees
  for(i=2;i<12;i=i+3)//eteint les leds
  {
    delay(1); //delais invisible 
    digitalWrite(i,HIGH);
  }
  delay(battement/2); //delais leds eteintes
}

void bonus(){ //chenille qui s'efface que a la fin
   for(i=2;i<12;i++) //allume les leds
   {
    digitalWrite(i,LOW);
    delay(10); //delais invisible
    digitalWrite(i, HIGH); 
    delay(battement/2);
  }
  for(i=2;i<12;i++)//eteint les leds
  {
    digitalWrite(i,HIGH);
    delay(10); //delais invisible
    digitalWrite(i, LOW);
    delay(battement/2);
  }
}




  
