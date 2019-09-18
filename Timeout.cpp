/*
 * *****************************************************************************
 * Timeout.cpp
 * Library to add timeout functions to an Arduino program
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 * https://github.com/chischte/timeout-library.git
 * *****************************************************************************
 */

#include "Arduino.h"
#include "Timeout.h"

Timeout::Timeout(unsigned long timeoutTime) {
    _timeoutTime = timeoutTime;
    _previousTime = millis();
}

void Timeout::resetTime() {
    _previousTime = millis();
}

void Timeout::setActive(bool setActive) {
    _timeoutActive = setActive;
    _previousTime=millis();
}

bool Timeout::active() // returns true if timeout is active
{
    return _timeoutActive;
}

bool Timeout::timedOut() // returns true if timeout time has been reached
{
    bool timeoutTimedOut;
    if (millis() - _previousTime > _timeoutTime) {
        timeoutTimedOut = true;
    } else {
        timeoutTimedOut = false;
    }
    return timeoutTimedOut;
}

void Timeout::setTime(unsigned long timeoutTime) {
    _timeoutTime = timeoutTime;
}
