// 
// 
// 

#include "Switch.h"

Switch::Switch(int p1) {
	this->pin = p1;
	pinMode(this->pin, INPUT_PULLUP);
}

bool Switch::isPressed() {
	if (digitalRead(this->pin) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
