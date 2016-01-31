#include <Bounce2.h>

int homePin = 2;
int pulsePin = 4;

int counter = -1;
int lastPulseValue = 0;

bool dialingStarted = false;
long lastSentNumber = 0;

Bounce pulse = Bounce();
Bounce home = Bounce();

void setup() {
  pinMode(pulsePin, INPUT_PULLUP);
  pinMode(homePin, INPUT_PULLUP);

  pulse.attach(pulsePin);
  pulse.interval(20);

  home.attach(homePin);
  home.interval(30);

  Serial.begin(9600);
}

void loop() {
  home.update();
  pulse.update();

  int isHome = home.read();
  int pulseValue = pulse.read();

  if (isHome && counter >= 0) {
    if (counter > 0) {
      dialingStarted = true;
      Serial.println(counter - 1);
      lastSentNumber = millis();
    }

    counter = -1;
  }

  if (isHome && (millis() - lastSentNumber >= 2000)) {
    if (dialingStarted) {
      Serial.println("h");
      dialingStarted = false;
    }
  }

  if (!isHome && pulseValue == HIGH && lastPulseValue != HIGH) {
    counter++;
  }

  lastPulseValue = pulseValue;
}
