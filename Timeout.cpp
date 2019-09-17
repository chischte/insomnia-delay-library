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

Timeout::Timeout(int eepromSize, int numberOfValues)
{
  // READ WHERE THE VALUES ARE STORED:
  _numberOfValues = numberOfValues;
  _maxStoreLocation = (eepromSize - 1) - (numberOfValues * 4);    //eeprom address is 0 indexed
  int valueRead;
  int valueAddress = 0;    // the storeLocation is always stored on EEPROM byte 0 and 1
  eeprom_read_block((void*) &valueRead, (void*) valueAddress, sizeof(valueRead));
  //-------------------------destination--------source--------size
  _storeLocation = valueRead;
  // IF STORELOCATION IS TO BIG OR TO SMALL, RESET IT TO 2
  // this can happen with a new board only
  if (_storeLocation > _maxStoreLocation || _storeLocation < 2)
  {
    _storeLocation = 2;
    int newValue = _storeLocation;
    int valueAddress = 0;
    // the adress of the storeLocation is always stored on byte 0 and 1;
    eeprom_write_block((void*) &newValue, (void*) valueAddress, sizeof(newValue));
    //--------------------------source------------destination---size}
}
  _numberOfWriteCycles = eepromRead(_storeLocation);
}

void Timeout::countOneUp(int valueNumber)
{
  int valueAddress = calculateAddress(valueNumber);
  long storedValue = eepromRead(valueAddress);
  long newValue = storedValue + 1;
  eepromWrite(newValue, valueAddress);
}

void Timeout::set(int valueNumber, long newValue)
{
  int valueAddress = calculateAddress(valueNumber);
  long storedValue = eepromRead(valueAddress);
  // CHECK IF VALUE HASN'T BEEN ASSIGNED YET: 
 if (newValue != storedValue)
  {
    eepromWrite(newValue, valueAddress);
  }
}

long Timeout::getValue(int valueNumber)
{
  int valueAddress = calculateAddress(valueNumber);
  long valueRead = eepromRead(valueAddress);
  return valueRead;
}

void Timeout::setAllZero()
{
  for (int i = 0; i < _numberOfValues; i++)
  {
    int valueAddress = calculateAddress(i);
    eepromWrite(0, valueAddress);
  }
}

int Timeout::calculateAddress(int valueNumber)
{
  int addressNumber = _storeLocation + 4 + valueNumber * 4;
  //shift 4 bytes for the writeCounter and 4 bytes for every new value
  return addressNumber;
}

long Timeout::eepromRead(int sourceAddress)
{
  long valueRead;
  eeprom_read_block((void*) &valueRead, (void*) sourceAddress, sizeof(valueRead));
  //-------------------------destination--------source---------size
  return valueRead;
}

void Timeout::eepromWrite(long newValue, int destinationAddress)
{
  eeprom_write_block((void*) &newValue, (void*) destinationAddress, sizeof(newValue));
  //--------------------------source------------destination---------size}
  eepromMonitorWriteCycles();
}

void Timeout::eepromMonitorWriteCycles()
{
  _numberOfWriteCycles++;
  if (_numberOfWriteCycles > 50)
  {
    eepromMoveStorageLocation();
    _numberOfWriteCycles = 0;
    int newValue = _numberOfWriteCycles;
    int destinationAddress = _storeLocation;
    eeprom_write_block((void*) &newValue, (void*) destinationAddress, sizeof(newValue));
    //--------------------------source------------destination---size}
	_storeWriteCounterCounter = 0;
  }

  _storeWriteCounterCounter++;
  if (_storeWriteCounterCounter >= 1000)  // every n-writes the writecountervalue will be stored
  {
    long newValue = _numberOfWriteCycles;
    int destinationAddress = _storeLocation;
    eeprom_write_block((void*) &newValue, (void*) destinationAddress, sizeof(newValue));
    //--------------------------source------------destination---size}
	_storeWriteCounterCounter = 0;
  }
}

void Timeout::eepromMoveStorageLocation()
{
  // CALCULATE NEW STORE LOCATION:
  int moveSizeInBytes = 4 + _numberOfValues * 4; //the long for the writeCounter is included
  int newStoreLocation = _storeLocation + moveSizeInBytes;
  if (newStoreLocation > _maxStoreLocation)
  {
    newStoreLocation = 2;
  }
  // COPY VALUES FROM OLD TO NEW LOCATION:
  for (int i = 0; i < _numberOfValues; i++)
  {
    int oldValueAddress = calculateAddress(i);
    long storedValue = eepromRead(oldValueAddress);
    int newValueAddress = newStoreLocation + 4 + (i * 4);

    long newValue = storedValue;
    int destinationAddress = newValueAddress;
    eeprom_write_block((void*) &newValue, (void*) destinationAddress, sizeof(newValue));
    //--------------------------source------------destination---size}
  }
  // CHANGE STORELOCATION ADDRESS:
  _storeLocation = newStoreLocation;
  int newValue = _storeLocation;
  int valueAddress = 0;
  // the adress of the storeLocation is always stored on byte 0 and 1;
  eeprom_write_block((void*) &newValue, (void*) valueAddress, sizeof(newValue));
  //--------------------------source------------destination---size}
}

void Timeout::printDebugInformation()
{
  char debugInfo[100];
  Serial.println("*******************************");
  sprintf(debugInfo, "STORELOCATION: %d     ", _storeLocation);
  Serial.print(debugInfo);
  sprintf(debugInfo, "WRITE COUNT: %ld", _numberOfWriteCycles);
  Serial.println(debugInfo);

  for (int i = 0; i < _numberOfValues; i++)
  {
    sprintf(debugInfo, "Value Number: %d  ", i);
    Serial.print(debugInfo);
    sprintf(debugInfo, "Value Adress: %d  ", calculateAddress(i));
    Serial.print(debugInfo);
    sprintf(debugInfo, "Value %d = %ld", i, getValue(i));
    Serial.println(debugInfo);
  }
  Serial.println("*******************************");
}
