// Water sensor power: 5V
// Flashed LED_2 on each read
// Lights LED_1 when there is water

#include <JeeLib.h>

ISR(WDT_vect) { Sleepy::watchdogEvent(); }

const int LED_1 = 13;
const int LED_2 = 12;

const int SENSOR_ANALOG_PIN = A0;
 
void setup() {  
  pinMode(LED_1, OUTPUT);  
  pinMode(LED_2, OUTPUT);      
}

void loop() {
  digitalWrite(LED_2, HIGH);    
  int level = analogRead(SENSOR_ANALOG_PIN);  
  digitalWrite(LED_2, LOW);
 
  if (level > 250) {
    digitalWrite(LED_1, HIGH);    
  } else {    
    digitalWrite(LED_1, LOW);
  }  

  Sleepy::loseSomeTime(1000);    
}
