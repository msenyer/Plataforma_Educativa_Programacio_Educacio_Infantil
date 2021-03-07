// Leds.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Led {
private:
	int pin;

public:
	Led(int);
	void ledOn();
	void ledOff();
};

#endif

