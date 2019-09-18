#include <Timeout.h> // https://github.com/chischte/timeout-library.git

// CREATE AN INSTANCE OF THE LIBRARY CLASS:
Timeout timeout(5000);

void setup() {
    Serial.begin(9600);
    Serial.println("EXIT SETUP");
}

void loop() {

    timeout.setActive(1); // enables the timeout countdown
    timeout.setTime(5000); // sets another timeout time
    timeout.resetTime(); //restart the timeout countdown

    // TIMEOUT ACTION:
    if (timeout.active()) { // returns true if timeout is active
        if (timeout.timedOut()) { // returns true if timeout time has been reached

            // activate emergency stop or whatever;
        }
    }
}
