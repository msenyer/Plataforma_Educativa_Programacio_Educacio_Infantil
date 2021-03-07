// Bluetooth.h

#ifndef _BLUETOOTH_h
#define _BLUETOOTH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SoftwareSerial.h>
#include "Car.h"
#include "Vector.h"


using namespace std;

class Car;
#define MAXDATALENGTH 100
#define MAXINSTRUCTIONS 5


class Bluetooth {
private:							
	int pinTx, pinRx;
	int count;				
	SoftwareSerial *btSerial;		
	char receivedChars[MAXDATALENGTH+1];
	char instructions[MAXINSTRUCTIONS];
	boolean newData = false;
	Car *car;						

	Vector<String> splitString(String str);
	
public:
					
	Bluetooth(int, int, Car*);
	void receive();
	void processCommand();
	void btRun();
	void showCount();


};
#endif

