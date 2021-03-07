// State.h

#ifndef _STATE_h
#define _STATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class State {

private:
	String s;


public:

	State(String);
	String getState();
	void setState(String);

};

#endif

