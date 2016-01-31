#include "./rotary_dial.h"

const int homePin = 2;
const int pulsePin = 4;

RotaryDial rotaryDial = RotaryDial();

void setup() {
  Serial.begin(9600);
  rotaryDial.begin(homePin, pulsePin);
}

void loop() {
  rotaryDial.update();

  if (rotaryDial.hasNext()) {
    Serial.println(rotaryDial.getNext());
  }
}
