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
  _timeout_time = timeoutTime;
  _previous_time = millis();
}

void Insomnia::set_time(unsigned long timeoutTime) {
  _timeout_time = timeoutTime;
  _previous_time = millis();
}

void Insomnia::reset_time() { _previous_time = millis(); }

void Insomnia::set_flag_activated(bool setActive) { _timeout_is_marked_activated = setActive; }

bool Insomnia::is_marked_activated() // returns true if timeout is active
{
  return _timeout_is_marked_activated;
}

bool Insomnia::has_timed_out() // returns true if timeout time has been reached
{
  bool timeoutTimedOut;
  if (millis() - _previous_time > _timeout_time) {
    timeoutTimedOut = true;
  } else {
    timeoutTimedOut = false;
  }
  return timeoutTimedOut;
}

bool Insomnia::delay_time_is_up(unsigned long delayTime) {
  _delay_time = delayTime;
  if (!_delay_is_active) {
    _previous_time = millis();
    _delay_is_active = true;
  } else if (millis() - _previous_time > _delay_time) {
    _delay_is_active = false;
    return (1);
  }
  return (0);
}

unsigned long Insomnia::get_remaining_delay_time() {
  unsigned long timePassed = millis() - _previous_time;
  unsigned long timeRemaining;
  if (_delay_time > timePassed) {
    timeRemaining = _delay_time - timePassed;
  } else {
    timeRemaining = 0;
  }
  return timeRemaining;
}

unsigned long Insomnia::get_remaining_timeout_time() {
  unsigned long timePassed = millis() - _previous_time;
  unsigned long timeRemaining;
  if (_timeout_time > timePassed) {
    timeRemaining = _timeout_time - timePassed;
  } else {
    timeRemaining = 0;
  }
  return timeRemaining;
}
