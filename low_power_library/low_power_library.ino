#include <JeeLib.h>

ISR(WDT_vect) { Sleepy::watchdogEvent(); } // Setup the watchdog

int led = 13; // LED_BUILTIN

void setup() {
 pinMode(led, OUTPUT);
}

void loop() {
 digitalWrite(led, HIGH);
 //delay(2000);
 Sleepy::loseSomeTime(500);

 digitalWrite(led, LOW);
 //delay(3000);
 Sleepy::loseSomeTime(500);
}
