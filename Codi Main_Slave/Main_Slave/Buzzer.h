// Buzzer.h

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Buzzer {
private: 
	int pin1;

public:
	Buzzer(int);
	void toneValid();
	void toneOn();
	void toneOff();
};

#endif

