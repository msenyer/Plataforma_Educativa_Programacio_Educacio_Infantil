// 
// 
// 

#include "LedMaster.h"

LedMaster::LedMaster(int p1) {
	this->pin = p1;
	pinMode(this->pin, OUTPUT);
}

void LedMaster::ledOn() {
	digitalWrite(this->pin, HIGH);
}

void LedMaster::ledOff() {
	digitalWrite(this->pin, LOW);
}