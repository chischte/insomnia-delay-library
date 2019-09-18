/*
 * *****************************************************************************
 Timeout.cpp
 Library to store values on the non volatile arduino EEPROM
 Michael Wettstein
 September 2019, Zürich
 * *****************************************************************************
 */

#include "Arduino.h"
#include "Timeout.h"

Timeout::Timeout(unsigned long)
{
 
}

  Timeout::void resetTime()
  {
  }
  
  Timeout::void setActive(bool setActive)
  {
  }
  
  Timeout::active() // returns true if timeout is active
  {
  bool timeoutActive
  return timeoutActive;
  }
  
  
  Timeout::out() // returns true if timeout time has been reached
  {
  bool timeOutTimedOut;
  return timeOutTimedOut;
  }
  
  Timeout::changeTime(unsigned long);
  {
  }