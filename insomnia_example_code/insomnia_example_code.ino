#include <Insomnia.h> // https://github.com/chischte/insomnia-delay-library.git

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
Insomnia timeout(5000);

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A NO-SLEEP-DELAY:
Insomnia blinkDelay; //use no brackets for a delay

// CREATE AN SECOND DELAY:
Insomnia runtimePrintDelay; //use no brackets for a delay

// VARIABLES JUST FOR DEMONSTRATION PURPOSES:

//CHOOSE DEMO MODES:
bool timeoutDemo = 1; // set 1 to see it in action, set 0 to minimize serial print traffic
bool delayDemo = 0;   // set 1 to see it in action, set 0 to minimize serial print traffic
bool runtimeDemo = 0; // set 1 to see it in action, set 0 to minimize serial print traffic

void setup() {
  Serial.begin(9600);
  Serial.println("EXIT SETUP");

  // SET A DIFFERENT TIMEOUT TIME:
  timeout.setTime(7000);
  // does reset the stopwatch
}

void loop() {
  //*****************************************************************************
  // TIMEOUT DEMO
  //*****************************************************************************
  if (timeoutDemo) {
    timeout.setActive(1); // enables the timeout countdown
                          // does not reset the stopwatch

    // BASIC TIMEOUT ACTION WITHOUT REQUEST OF ACTIVE STATE:
    if (timeout.timedOut()) { // returns true if timeout time has been reached
      // activate emergency stop or whatever;
    }
    // PRINT THE REMAINING TIMEOUT TIME:
    Serial.print("REMAINING TIMEOUT TIME: ");
    Serial.print(timeout.remainingTimeoutTime());
    Serial.println(" ms");

    // TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
    if (timeout.active()) { // returns true if timeout is active
      if (timeout.timedOut()) { // returns true if timeout time has been reached
        Serial.println("TIMEOUT TIMED OUT ...RESET");
        timeout.resetTime(); //restart the timeout countdown
        delay(2000);
      }
    }
  }
  //*****************************************************************************
  // DELAY DEMO
  //*****************************************************************************
  if (delayDemo) {
    // USE OF THE NO-SLEEP-DELAY FUNCTION
    // use a seperate instance for every delay used

    if (blinkDelay.delayTimeUp(3000)) { // delay time 500ms
      static bool blinkTestState;
      blinkTestState = !blinkTestState;
      Serial.print("BLINK STATE: ");
      Serial.println(blinkTestState);
      delay(2000);
    }

    // PRINT THE REMAINING DELAY TIME:
    Serial.print("REMAINING BLINK-DELAY TIME: ");
    Serial.print(blinkDelay.remainingDelayTime());
    Serial.println(" ms");
  }

  //*****************************************************************************
  // RUNTIME DEMO
  //*****************************************************************************
  if (runtimeDemo) {
    // CALCULATE RUNTIME
    // to demonstrate that the insomnia-delay does not put the program to sleep
    static unsigned long previousTime;
    unsigned long runtime = micros() - previousTime;
    if (runtimePrintDelay.delayTimeUp(1000)) {
      Serial.print("RUNTIME OF THE LOOP: ");
      Serial.print(runtime);
      Serial.println(" microseconds");
    }
    previousTime = micros();
  }

}

