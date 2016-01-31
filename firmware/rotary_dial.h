#ifndef PETMOJ_ROTARY_DIAL_H
#define PETMOJ_ROTARY_DIAL_H

#include <Bounce2.h>

class RotaryDial {
 public:
  explicit RotaryDial();
  void begin(int homePin, int pulsePin);
  void update();
  bool isHome();
  bool hasNext();
  int getNext();

 private:
   Bounce home_;
   Bounce pulse_;

   int lastPulseState_;
   bool isHome_;
   int counter_;
   int next_;
};

#endif  // PETMOJ_ROTARY_DIAL_H
