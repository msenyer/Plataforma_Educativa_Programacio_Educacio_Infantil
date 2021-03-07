// ShiftRegister.h

#ifndef _SHIFTREGISTER_h
#define _SHIFTREGISTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Vector.h"

class ShiftRegister {
private:
	int dataPin, loadPin, clockPin, clockEnablePin;


public:

	ShiftRegister(int, int, int, int);
	unsigned int readShiftRegs();
	void displayPinValues(unsigned int);
	int detectPinValues(unsigned int);
	Vector<int> exportInstruction(unsigned int pinValues);
	//Vector<int> exportInstruction(unsigned int);
};

#endif

