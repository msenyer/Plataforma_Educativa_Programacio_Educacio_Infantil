// 
// 
// 

#include "BluetoothMaster.h"

BluetoothMaster::BluetoothMaster(int rx, int tx) {

	this->pinRx = rx;
	this->pinTx = tx;
	this->btSerial = new SoftwareSerial(this->pinRx, this->pinTx);
	this->btSerial->begin(38400);
}

void BluetoothMaster::sendInfo(int instruction) {

	switch (instruction) {

	case 1:
		this->btSerial->println("<ERROR>");
		Serial.println("ERROR");
		delay(25);
		break;

	case 2:
		this->btSerial->println("<RIGHT>");
		Serial.println("<RIGHT>");
		delay(25);
		break;

	case 3:
		this->btSerial->println("<FORWARD>");
		Serial.println("<FORWARD>");
		delay(25);
		break;

	case 4:
		this->btSerial->println("<LEFT>");
		Serial.println("<LEFT>");
		delay(25);
		break;

	case 5:
		this->btSerial->println("<NOTHING>");
		Serial.println("<NOTHING>");
		delay(25);
		break;

	default:
		break;

	}

}



