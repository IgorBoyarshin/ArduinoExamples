// RECEIVER
// Expected a number [0..2].
// Based on it inverts the state of the LED corresponding to this number.
// Flashed a green LED on each reception.
// Flashed a red LED on each number reception that is outta bounds.

#include <VirtualWire.h>

const int LED_GREEN = 13;
const int LED_RED = 12;
const int LED_1 = 8;
const int LED_2 = 9;
const int LED_3 = 10;

const int RX_PIN = 2;

void setup() {
  vw_set_rx_pin(RX_PIN);
  vw_setup(2000);
  vw_rx_start();

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

bool stateOn = true;

void loop() {
  uint8_t buff[VW_MAX_MESSAGE_LEN];
  uint8_t buff_length = VW_MAX_MESSAGE_LEN; // receive no more than this

  digitalWrite(LED_RED, LOW);
  if (vw_get_message(buff, &buff_length)) {
    digitalWrite(LED_GREEN, HIGH);

    switch (buff[0]) {
      case 0:
        digitalWrite(LED_1, stateOn ? HIGH : LOW);
        stateOn = !stateOn;
        break;
      case 1:
        digitalWrite(LED_2, stateOn ? HIGH : LOW);
        stateOn = !stateOn;
        break;
      case 2:
        digitalWrite(LED_3, stateOn ? HIGH : LOW);
        stateOn = !stateOn;
        break;
      default:
        digitalWrite(LED_RED, HIGH);
        break;
    }
    
    digitalWrite(LED_GREEN, LOW);
  }
}
