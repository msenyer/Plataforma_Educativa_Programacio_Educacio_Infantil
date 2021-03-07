
#include "SoftwareSerial.h"
#include "Switch.h"
#include "LedMaster.h"
#include "BluetoothMaster.h"
#ifndef VECTOR_H
	#include "Vector.h"
#endif
#include "ShiftRegister.h"
#include "BluetoothMaster.h"

#define MAXINSTRUCTIONS 5
#define BT1 8
#define BT2 9
#define DATAPIN 5
#define LOADPIN 3
#define CLKPIN 4
#define CLKENPIN 2
#define SWITCH 6
#define LED 7

BluetoothMaster *bt;
ShiftRegister *sr;
Switch *sw;
LedMaster *led;

unsigned int oldPinValue, pinValue;

void setup() {

	Serial.begin(38400);

	bt = new BluetoothMaster(BT1, BT2);
	sr = new ShiftRegister(DATAPIN, LOADPIN, CLKPIN, CLKENPIN);
	sw = new Switch(SWITCH);
	led = new LedMaster(LED);

	oldPinValue = sr->readShiftRegs();
	sr->displayPinValues(oldPinValue);

}


void loop() {

	pinValue = sr->readShiftRegs();

	if (pinValue != oldPinValue)
	{
		Serial.println("*Pin value change detected*");
		sr->displayPinValues(pinValue);
		oldPinValue = pinValue;
	}


	if (sw->isPressed()) {
		led->ledOn();
		delay(500);
		led->ledOff();

		// exportinstruction

		Vector<int> res = sr->exportInstruction(pinValue);
		bt->sendInfo(res);
	}
}
