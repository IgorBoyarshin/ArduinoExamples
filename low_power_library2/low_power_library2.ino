#include <LowPower.h>

void setup() {}

void loop() {
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
}
