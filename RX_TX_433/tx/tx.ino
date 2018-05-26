// TRANSMITTER
// Sends a number [0..2] each INTERVAL milliseconds.
// The number is iterated each time and goes in cycle.
// Flashed a green LED on each transmission

#include <VirtualWire.h>

const int LED_GREEN = 13;
const int TX_PIN = 3;
const int INTERVAL = 2000;

void setup() {
  pinMode(LED_GREEN, OUTPUT);  

  vw_set_tx_pin(TX_PIN);
  vw_setup(2000);
}

uint8_t count = 0;

void loop() {
  digitalWrite(LED_GREEN, HIGH);
  
  vw_send((uint8_t*) &count, 1);
  vw_wait_tx();
  
  digitalWrite(LED_GREEN, LOW);  
  
  count++;
  count %= 3;
  delay(INTERVAL);
}
