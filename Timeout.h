/*
 * *****************************************************************************
 Timeout.h
 Library to add timeout functions to an Arduino program
 Michael Wettstein
 September 2019, Zürich
 * *****************************************************************************
 Notes:
 * *****************************************************************************
 */

#ifndef Timeout_h
#define Timeout_h

#include "Arduino.h"

class Timeout
{
public:
  // FUNTIONS:
    Timeout(unsigned long timeoutTime);
  void resetTime();
  void setActive(bool setActive)
  bool active(); // returns true if timeout is active
  bool out(); // returns true if timeout time has been reached
  void changeTime(unsigned long);
  
 // VARIABLES:
  // n.a.

private:
  // FUNCTIONS:
  // n.a.

  // VARIABLES:
 unsigned long _previousTime
 
 
};
#endif
