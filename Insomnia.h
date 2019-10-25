/*
 * *****************************************************************************
 * Insomnia.h
 * Library to add "no-sleep" delay and timeout functions to an Arduino program
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 * https://github.com/chischte/insomnia-delay-library.git
 * *****************************************************************************
 */

#ifndef Insomnia_h
#define Insomnia_h

#include "Arduino.h"

class Insomnia {
public:
  // FUNTIONS:
  Insomnia(unsigned long timeoutTime = 5000);
  void resetTime();
  void setActive(bool setActive);
  bool active(); // returns true if timeout is active
  bool timedOut(); // returns true if timeout time has been reached
  void setTime(unsigned long);
  bool delayTimeUp(unsigned long delayTime);
  unsigned long remainingDelayTime();
  unsigned long remainingTimeoutTime();

  // VARIABLES:
  // n.a.

private:
  // FUNCTIONS:
  // n.a.

  // VARIABLES:
  unsigned long _previousTime = 0;
  unsigned long _timeoutTime = 0;
  unsigned long _delayTime = 0;
  bool _timeoutActive = true;
  bool _delayActive = false;

};
#endif
