#include <JeeLib.h>

ISR(WDT_vect) { Sleepy::watchdogEvent(); }

const int LED_1 = 13;
const int LED_2 = 12;
 
void setup() {  
  pinMode(LED_1, OUTPUT);  
  pinMode(LED_2, OUTPUT);      
}

void loop() {
  digitalWrite(LED_2, HIGH);    
  int level = analogRead(A0);  
  digitalWrite(LED_2, LOW);
 
  if (level > 300) {
    digitalWrite(LED_1, HIGH);    
  } else {    
    digitalWrite(LED_1, LOW);
  }  

  Sleepy::loseSomeTime(1000);    
}
