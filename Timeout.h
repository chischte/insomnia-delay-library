/*
 * *****************************************************************************
 Timeout.h
 Library to add timeout functions to an Arduino program
 Michael Wettstein
 September 2019, Zürich
 * *****************************************************************************
 */

#ifndef Timeout_h
#define Timeout_h

#include "Arduino.h"

class Timeout
{
public:
  // FUNTIONS:
  Timeout(int eepromSize, int numberOfValues);
  void setTimeoutTime(int timeoutTime); // increases the value by one
  void startTimeoutWatch(unsigned int timeoutTime);
  void resetTime();
  bool requestTimeout(); // sets value
 
 // VARIABLES:
  // n.a.

private:
  // FUNCTIONS:
  long eepromRead(int sourceAdress);
  void eepromWrite(long newValue, int destinationAddress);
  void eepromMonitorWriteCycles();
  void eepromMoveStorageLocation();
  int calculateAddress(int valueNumber);

  // VARIABLES:
  int _storeLocation;
  int _maxStoreLocation;
  int _storeWriteCounterCounter;
  int _numberOfValues;
  long _numberOfWriteCycles;

};
#endif
