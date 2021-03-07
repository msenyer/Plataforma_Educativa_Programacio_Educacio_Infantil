/*
 Name:		Main_Master.ino
 Created:	1/2/2017 12:12:27 PM
 Author:	Maria Senyé
*/


#include "Switch.h"
#include "LedMaster.h"
#include "BluetoothMaster.h"
#include "ShiftRegister.h"
#include "Bluetooth.h"


Bluetooth *bt;
ShiftRegister *sr;
Switch *sw;
LedMaster *led;

unsigned int oldPinValues, pinValues;

void setup() {
	
	Serial.begin(38400);

	bt = new Bluetooth(8, 9);
	sr = new ShiftRegister(5, 3, 4, 2);
	sw = new Switch(6);
	led = new LedMaster(7);

	oldPinValues = sr->readShiftRegs();
	sr->displayPinValues(oldPinValues);

}


void loop() {

	pinValues = sr->readShiftRegs();

	if (pinValues != oldPinValues)
	{
		Serial.println("*Pin value change detected*");
		sr->displayPinValues(pinValues);
		oldPinValues = pinValues;
	}

	
	if (sw->isPressed()) {
		led->ledOn();
		delay(500);
		led->ledOff();

		// exportinstruction
		/*
		for (int i = 0; i < 5; i++) {
			sendInfo(results[i]);
			delay(INSDELAY);
		}*/

	}
}
