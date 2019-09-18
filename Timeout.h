/*
 * *****************************************************************************
 * Timeout.h
 * Library to add timeout functions to an Arduino program
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 * https://github.com/chischte/timeout-library.git
 * *****************************************************************************
 */

#ifndef Timeout_h
#define Timeout_h

#include "Arduino.h"

class Timeout {
public:
    // FUNTIONS:
    Timeout(unsigned long timeoutTime);
    void resetTime();
    void setActive(bool setActive);
    bool active(); // returns true if timeout is active
    bool timedOut(); // returns true if timeout time has been reached
    void setTime(unsigned long);

    // VARIABLES:
    // n.a.

private:
    // FUNCTIONS:
    // n.a.

    // VARIABLES:
    unsigned long _previousTime;
    unsigned long _timeoutTime;
    bool _timeoutActive=false;

};
#endif
