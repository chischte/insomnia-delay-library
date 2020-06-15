#include <Insomnia.h> // https://github.com/chischte/insomnia-delay-library.git

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
Insomnia timeout(5000);

// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A NO-SLEEP-DELAY:
Insomnia blink_delay; // use no brackets for a delay

// CREATE AN SECOND DELAY:
Insomnia runtime_print_delay; // use no brackets for a delay

// VARIABLES JUST FOR DEMONSTRATION PURPOSES:

// CHOOSE DEMO MODES:
bool timeout_demo = 1; // set 1 to see it in action, set 0 to minimize serial print traffic
bool delay_demo = 0; // set 1 to see it in action, set 0 to minimize serial print traffic
bool runtime_demo = 0; // set 1 to see it in action, set 0 to minimize serial print traffic

void setup() {
  Serial.begin(9600);
  Serial.println("EXIT SETUP");

  // SET A DIFFERENT TIMEOUT TIME:
  timeout.set_time(7000);
  // does reset the stopwatch
}

void loop() {
  //*****************************************************************************
  // TIMEOUT DEMO
  //*****************************************************************************
  if (timeout_demo) {
    timeout.set_flag_activated(1); // marks the timeout as activated
        // does not reset the stopwatch

    // BASIC TIMEOUT ACTION WITHOUT REQUEST OF ACTIVE STATE:
    if (timeout.has_timed_out()) { // returns true if timeout time has been reached
      // activate emergency stop or whatever;
    }
    // PRINT THE REMAINING TIMEOUT TIME:
    Serial.print("REMAINING TIMEOUT TIME: ");
    Serial.print(timeout.get_remaining_timeout_time());
    Serial.println(" ms");

    // TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
    if (timeout.is_marked_activated()) { // returns true if timeout is active
      if (timeout.has_timed_out()) { // returns true if timeout time has been reached
        Serial.println("TIMEOUT TIMED OUT ...RESET");
        timeout.reset_time(); // restart the timeout countdown
        delay(2000);
      }
    }
  }
  //*****************************************************************************
  // DELAY DEMO
  //*****************************************************************************
  if (delay_demo) {
    // USE OF THE NO-SLEEP-DELAY FUNCTION
    // use a seperate instance for every delay used

    if (blink_delay.delay_time_is_up(3000)) { // delay time 3000ms
      static bool blink_test_state;
      blink_test_state = !blink_test_state;
      Serial.print("BLINK STATE: ");
      Serial.println(blink_test_state);
      delay(2000);
    }

    // PRINT THE REMAINING DELAY TIME:
    Serial.print("REMAINING BLINK-DELAY TIME: ");
    Serial.print(blink_delay.get_remaining_delay_time());
    Serial.println(" ms");
  }

  //*****************************************************************************
  // RUNTIME DEMO
  //*****************************************************************************
  if (runtime_demo) {
    // CALCULATE RUNTIME
    // to demonstrate that the insomnia-delay does not put the program to sleep
    static unsigned long previous_time;
    unsigned long runtime = micros() - previous_time;
    if (runtime_print_delay.delay_time_is_up(1000)) {
      Serial.print("RUNTIME OF THE LOOP: ");
      Serial.print(runtime);
      Serial.println(" microseconds");
    }
    previous_time = micros();
  }
}
