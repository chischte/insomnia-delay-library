#include <Insomnia.h> // https://github.com/chischte/insomnia-delay-library.git

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
Insomnia timeout(5000);

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A NO-SLEEP-DELAY:
Insomnia blinkDelay; //use no brackets for a delay

// CREATE AN SECOND DELAY:
Insomnia runtimePrintDelay; //use no brackets for a delay

// VARIABLES JUST FOR DEMONSTRATION PURPOSES:
bool blinkTestState;
unsigned long previousTime;

void setup() {
  Serial.begin(9600);
  Serial.println("EXIT SETUP");
}

void loop() {
  timeout.setActive(1); // enables the timeout countdown
                        // does not reset the stopwatch

  // BASIC TIMEOUT ACTION WITHOUT REQUEST OF ACTIVE STATE:
  if (timeout.timedOut()) { // returns true if timeout time has been reached
    // activate emergency stop or whatever;
  }

  // TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
  if (timeout.active()) { // returns true if timeout is active
    if (timeout.timedOut()) { // returns true if timeout time has been reached
      Serial.println("TIMEOUT TIMED OUT ...RESET");
      timeout.resetTime(); //restart the timeout countdown
    }
  }

  // USE OF THE NO-SLEEP-DELAY FUNCTION
  // use a seperate instance for every delay used

  if (blinkDelay.delayTimeUp(500)) { // delay time 500ms
    blinkTestState = !blinkTestState;
    Serial.print("BLINK STATE: ");
    Serial.println(blinkTestState);
  }

  // CALCULATE RUNTIME
  // to demonstrate that the delay does not put the program to sleep
  // the runtime is only that long because of the serial prints
  unsigned long runtime = millis() - previousTime;
  previousTime = millis();
  if (runtimePrintDelay.delayTimeUp(1000)) {
    Serial.print("RUNTIME OF THE LOOP: ");
    Serial.print(runtime);
    Serial.println(" ms");
  }
}
