#include "Led.h"

Led::Led(int p1) {
	this->pin = p1;
	pinMode(this->pin, OUTPUT);
}


void Led::ledOn(){
	digitalWrite(this->pin, HIGH);
}

void Led::ledOff() {
	digitalWrite(this->pin, LOW);
}