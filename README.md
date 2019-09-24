# insomnia-library 

**Library to add "no-sleep" delays and timeout functions to an Arduino program**


How to use the library to create a no-sleep-delay
-------------------------------------------------
	// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A DELAY:
	Insomnia exampleDelay;
	// use a seperate instance for every delay used
	// delays in series do not wait on each other
	
	
	// USE DELAY:
	if (exampleDelay.delayTimeUp(500)) { // delay time 500ms
	  // do stuff if delay times up
	}
	
How to use the library to create a timeout function
------------------------------------------------
	// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
	Insomnia timeout(5000);

	// BASIC TIMEOUT ACTION:
	if (timeout.timedOut()) {
	  // activate emergency stop or whatever;
	}
  	
  	// SET A DIFFERENT TIMEOUT TIME:
  	timeout.setTime(1000);
  	// does not reset the stopwatch
  	
	// ADDITIONALY A TIMOUT CAN BE FLAGED ACTIVE OR INACTIVE:
	timeout.setActive(1); 
	// does not reset the stopwatch
  	// this is completely optional and has no other effect than act as a flag
	
	// TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
	if (timeout.active()) {
	  if (timeout.timedOut()) { 
	    // do stuff
	    timeout.resetTime(); // restart the timeout countdown
	  }
	}

 **An example of how the functions can be used can be found in the example code "insomnia_example_code".**	

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.


