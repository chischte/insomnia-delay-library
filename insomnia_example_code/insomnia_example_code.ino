#include <Insomnia.h> // https://github.com/chischte/insomnia-timer-library.git

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
Insomnia timeout(5000);

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A NO-SLEEP-DELAY:
Insomnia blinkDelay; //use no brackets for a delay

// CREATE AN SECOND DELAY FOR THE RUNTIME SERIALPRINT:
Insomnia runtimePrintDelay; //use no brackets for a delay

//VARIABLES JUST FOR DEMO PURPOSES:
bool blinkTestState;
unsigned long previousTime;

void setup()
{
  Serial.begin(9600);
  Serial.println("EXIT SETUP");
}

void loop()
{
  timeout.setActive(1); // enables the timeout countdown
                        //does not reset stopwatch

  // BASIC TIMEOUT ACTION WITHOUT REQUEST OF ACTIVE STATE:
  if (timeout.timedOut())
  { // returns true if timeout time has been reached
    // activate emergency stop or whatever;
  }

  ///*
  // TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
  if (timeout.active())
  { // returns true if timeout is active
    if (timeout.timedOut())
    { // returns true if timeout time has been reached
      Serial.println("TIMEOUT TIMED OUT ...RESET");
      timeout.resetTime(); //restart the timeout countdown
    }
  }

  // USE OF THE NO-SLEEP-DELAY FUNCTION
  // USE INDIVIDUAL INSTANCES IF USING MORE THAN ONE DELAY

  if (blinkDelay.delayTimeUp(500))
  {
    blinkTestState = !blinkTestState;
    Serial.print("BLINK STATE: ");
    Serial.println(blinkTestState);
  }

  // CALCULATE RUNTIME
  // TO DEMONSRATE THAT THE DELAY DOES NOT KEEP THE PROGRAM WAITING

  unsigned long runtime = millis()-previousTime;
  previousTime = millis();
  if (runtimePrintDelay.delayTimeUp(1000))
  {
    Serial.print("RUNTIME OF THE LOOP: ");
    Serial.print(runtime);
    Serial.println(" ms (time for the serial prints)");
  }
//*/
}
