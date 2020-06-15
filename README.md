# insomnia-library 

**Library to add "no-sleep" delays and timeout functions to an Arduino program**



How to use the library to create a no-sleep-delay:
-------------------------------------------------
	// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A DELAY:
	Insomnia example_delay;

	// USE DELAY:
	if (example_delay.delay_time_is_up(500)) { // delay time 500ms
	  // do stuff if delay times up
	}

	// PRINT THE REMAINING DELAY TIME:
	Serial.println(blink_delay.get_remaining_delay_time());

	// create a separate instance for every delay and timeout that can be used simultaneously
	// delays in series do not wait on each other
	
How to use the library to create a timeout function:
------------------------------------------------
	// CREATE AN INSTANCE OF THE LIBRARY CLASS FOR A TIMEOUT TIMER:
	Insomnia timeout(5000);

	// BASIC TIMEOUT ACTION:
	if (timeout.has_timed_out()) {
	  // activate emergency stop or whatever;
	}

	// ADDITIONALY A TIMOUT CAN BE FLAGED ACTIVE OR INACTIVE:
	timeout.set_flag_activated(); 
	// does not reset the stopwatch
	// this is completely optional and has no other effect than act as a flag

	// TIMEOUT ACTION WITH REQUEST OF ACTIVE STATE:
	if (timeout.is_marked_activated()) {
	  if (timeout.timed_has_timed_out()) { 
	    // do stuff
	    timeout.reset_time(); // restart the timeout countdown
	  }
	}

	// SET A DIFFERENT TIMEOUT TIME:
	timeout.set_time(112233);
	// does reset the stopwatch

	// PRINT THE REMAINING TIMEOUT TIME:
	Serial.println(timeout.get_remaining_timeout_time());
	
 **An example of how the functions can be used can be found in the example code.**	

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.


