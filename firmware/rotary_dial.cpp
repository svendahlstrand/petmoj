#include <arduino.h>
#include "./rotary_dial.h"

RotaryDial::RotaryDial() {
  home_ = Bounce();
  pulse_ = Bounce();

  lastPulseState_ = LOW;
  isHome_ = true;
  counter_ = -1;
  next_ = -1;
}

void RotaryDial::begin(int homePin, int pulsePin) {
  pinMode(homePin, INPUT_PULLUP);
  pinMode(pulsePin, INPUT_PULLUP);

  home_.attach(homePin);
  home_.interval(30);

  pulse_.attach(pulsePin);
  pulse_.interval(20);
}

void RotaryDial::update() {
  home_.update();
  pulse_.update();

  isHome_ = home_.read();
  int pulseState = pulse_.read();

  if (isHome_ && counter_ >= 0) {
    if (counter_ > 0) {
      next_ = counter_ - 1;
    }

    counter_ = -1;
  }

  if (!isHome_ && pulseState == HIGH && lastPulseState_ != HIGH) {
    counter_++;
  }

  lastPulseState_ = pulseState;
}

bool RotaryDial::isHome() {
  return isHome_;
}

bool RotaryDial::hasNext() {
  return next_ > -1;
}

int RotaryDial::getNext() {
  char tmp = next_;
  next_ = -1;

  return tmp;
}
