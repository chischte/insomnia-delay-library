/*
 * *****************************************************************************
 * Insomnia.cpp
 * Library to add timeout functions to an Arduino program
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 * https://github.com/chischte/timeout-library.git
 * *****************************************************************************
 */

#include "Arduino.h"
#include "Insomnia.h"

Insomnia::Insomnia(int timeoutTime = 5000)
{
  _timeoutTime = timeoutTime;
  _previousTime = millis();
}

void Insomnia::setTime(unsigned long timeoutTime)
{
  _timeoutTime = timeoutTime;
}

void Insomnia::resetTime()
{
  _previousTime = millis();
}

void Insomnia::setActive(bool setActive)
{
  _timeoutActive = setActive;
}

bool Insomnia::active() // returns true if timeout is active
{
  return _timeoutActive;
}

bool Insomnia::timedOut() // returns true if timeout time has been reached
{
  bool timeoutTimedOut;
  if (millis() - _previousTime > _timeoutTime)
  {
    timeoutTimedOut = true;
  }
  else
  {
    timeoutTimedOut = false;
  }
  return timeoutTimedOut;
}

bool Insomnia::delayTimeUp(unsigned long delay_time)
{
  if (!_delayActive)
  {
    _previousTime = millis();
    _delayActive = true;
  }
  else if (millis() - _previousTime > delay_time)
  {
    _delayActive = false;
    return (1);
  }
  return (0);
}
