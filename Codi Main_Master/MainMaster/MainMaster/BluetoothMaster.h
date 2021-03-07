// BluetoothMaster.h

#ifndef _BLUETOOTHMASTER_h
#define _BLUETOOTHMASTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
	#include <SoftwareSerial.h>
	
#ifndef VECTOR_H
	#include "Vector.h"
#endif

class BluetoothMaster {
private:
	int pinRx, pinTx;
	SoftwareSerial *btSerial;

public:

	BluetoothMaster(int, int);
	void sendInfo(Vector<int>);

};

	


#endif

