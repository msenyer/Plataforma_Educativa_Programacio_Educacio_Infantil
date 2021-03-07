
// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



class Motor {
private:
	int pin1, pin2;
	int speed;
public:
	Motor();				
	Motor(int, int, int);		
	void fwd();				
	void bkwd();			
	void stop();			
	int getSpeed();
	void setSpeed(int);
};

#endif

