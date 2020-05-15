/*
 * *****************************************************************************
 * Insomnia.cpp
 * Library to add timeout functions to an Arduino program
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 * https://github.com/chischte/insomnia-delay-library.git
 * *****************************************************************************
 */

#include "Insomnia.h"
#include "Arduino.h"

Insomnia::Insomnia(unsigned long timeoutTime /*= 5000*/) {
  _timeoutTime = timeoutTime;
  _previousTime = millis();
}

void Insomnia::setTime(unsigned long timeoutTime) {
  _timeoutTime = timeoutTime;
  _previousTime = millis();
}

void Insomnia::resetTime() { _previousTime = millis(); }

void Insomnia::set_flag_activated(bool setActive) { _timeoutActivated = setActive; }

bool Insomnia::active() // returns true if timeout is active
{
  return _timeoutActivated;
}

bool Insomnia::timedOut() // returns true if timeout time has been reached
{
  bool timeoutTimedOut;
  if (millis() - _previousTime > _timeoutTime) {
    timeoutTimedOut = true;
  } else {
    timeoutTimedOut = false;
  }
  return timeoutTimedOut;
}

bool Insomnia::delayTimeUp(unsigned long delayTime) {
  _delayTime = delayTime;
  if (!_delayActive) {
    _previousTime = millis();
    _delayActive = true;
  } else if (millis() - _previousTime > _delayTime) {
    _delayActive = false;
    return (1);
  }
  return (0);
}

unsigned long Insomnia::remainingDelayTime() {
  unsigned long timePassed = millis() - _previousTime;
  unsigned long timeRemaining;
  if (_delayTime > timePassed) {
    timeRemaining = _delayTime - timePassed;
  } else {
    timeRemaining = 0;
  }
  return timeRemaining;
}

unsigned long Insomnia::remainingTimeoutTime() {
  unsigned long timePassed = millis() - _previousTime;
  unsigned long timeRemaining;
  if (_timeoutTime > timePassed) {
    timeRemaining = _timeoutTime - timePassed;
  } else {
    timeRemaining = 0;
  }
  return timeRemaining;
}
