#include "cardio.h"



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
    for (int i=2; i<12; i++){
      pinMode(i,OUTPUT);
      }
}

void loop() {
  // put your main code here, to run repeatedly:
lecture();

}
