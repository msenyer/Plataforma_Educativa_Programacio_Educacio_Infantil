// Car.h

#ifndef _CAR_h
#define _CAR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Led.h"
#include "Buzzer.h"
#include "Bluetooth.h"
#include "Motor.h"
#include "StateQueue.h"



class Bluetooth;
#define MAXDATALENGTH 100


class Car {
private: 

	Motor *motorLeft, *motorRight;
	Bluetooth *bt;
	Buzzer *bz;
	Led *ledRed, *ledYellow;
	String state;
	StateQueue queue;

public:

	enum State {
		WAIT,
		RIGHT,
		LEFT,
		FORWARD,
		STOP
	};

	
	bool newData;

	Car(int, int, int, int, int, int, int, int, int, int, int); 
	void init();
	void forward();
	void right();
	void left();
	void stop();
	void listen();
	void check();
	void falseInstruction();
	void addInstruction(String);
	String getInstruction();
	void run();
	

};

#endif

