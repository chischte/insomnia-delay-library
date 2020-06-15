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

Insomnia::Insomnia(unsigned long timeout_time /*= 5000*/) {
  _timeout_time = timeout_time;
  _previous_time = millis();
}

void Insomnia::set_time(unsigned long timeout_time) {
  _timeout_time = timeout_time;
  _previous_time = millis();
}

void Insomnia::reset_time() { _previous_time = millis(); }

void Insomnia::set_unstarted() { _delay_is_active = false; }

void Insomnia::set_flag_activated(bool setActive) { _timeout_is_marked_activated = setActive; }

bool Insomnia::is_marked_activated() // returns true if timeout is active
{
  return _timeout_is_marked_activated;
}

bool Insomnia::has_timed_out() // returns true if timeout time has been reached
{
  bool timeout_timed_out;
  if (millis() - _previous_time > _timeout_time) {
    timeout_timed_out = true;
  } else {
    timeout_timed_out = false;
  }
  return timeout_timed_out;
}

bool Insomnia::delay_time_is_up(unsigned long delay_time) {
  _delay_time = delay_time;
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
  unsigned long time_passed = millis() - _previous_time;
  unsigned long time_remaining;
  if (_delay_time > time_passed) {
    time_remaining = _delay_time - time_passed;
  } else {
    time_remaining = 0;
  }
  return time_remaining;
}

unsigned long Insomnia::get_remaining_timeout_time() {
  unsigned long time_passed = millis() - _previous_time;
  unsigned long time_remaining;
  if (_timeout_time > time_passed) {
    time_remaining = _timeout_time - time_passed;
  } else {
    time_remaining = 0;
  }
  return time_remaining;
}
