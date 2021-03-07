// LedMaster.h

#ifndef _LEDMASTER_h
#define _LEDMASTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class LedMaster {

private:
	int pin;

public:
	LedMaster(int);
	void ledOn();
	void ledOff();
};

#endif

