# insomnia-library 

**Library to add "no-sleep" delays and timeout functions to an Arduino program.**


Library Functions
-----------------

	**DELAY FUNCTION:**
	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A NO-SLEEP-DELAY:
	// use a seperate instance for every delay used
	Insomnia exampleDelay; //use no brackets for a delay
	
	// USE DELAY:
	if (exampleDelay.delayTimeUp(500)) { // delay time 500ms
    // do stuff if delay times up
	}
	
	
	
	**TIMEOUT FUNCTIONS:**
	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
	Insomnia timeout(5000);

	// BASIC TIMEOUT ACTION:
	if (timeout.timedOut()) { // returns true if timeout time has been reached
    // activate emergency stop or whatever;
	}
  
	// ADDITIONALY A TIMOUT CAN BE FLAGED ACTIVE OR INACTIVE
	// this is completely optional and has no other effect than act as a flag
	timeout.setActive(1); // does not reset the stopwatch
  
	// TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
	if (timeout.active()) { // returns true if timeout is active
		if (timeout.timedOut()) { // returns true if timeout time has been reached
		Serial.println("TIMEOUT TIMED OUT ...RESET");
		timeout.resetTime(); //restart the timeout countdown
		}
	}

 
 **An example of how the functions can be used can be found in the example code "insomnia_example_code".**	
  

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.
