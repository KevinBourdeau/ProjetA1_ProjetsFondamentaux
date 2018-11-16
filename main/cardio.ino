#include "cardio.h"
long freq;
long temps;
float pouls;


void lecture(){
 
  pouls = random(1000, 1333);
  temps = millis();
  freq = (pouls/1000)*60;
  Serial.print(temps); //affiche le temps en sec
  Serial.print(" ; ");
  Serial.println(freq);
  battement = (1000000/pouls);
  parametre();
  delay(battement/2);
  
}
