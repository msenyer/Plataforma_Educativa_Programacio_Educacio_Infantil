#include "Buzzer.h"

Buzzer::Buzzer(int p1) {
	this->pin1 = p1;		
	pinMode(this->pin1, OUTPUT);
}

void Buzzer::toneValid() {
	
	digitalWrite(this->pin1, LOW);
	delay(50);
	digitalWrite(this->pin1, HIGH);
	delay(50);
	digitalWrite(this->pin1, LOW);
	delay(50);
	digitalWrite(this->pin1, HIGH);
	delay(1000);
}

void Buzzer::toneOn() {

	digitalWrite(this->pin1, LOW);
	
}

void Buzzer::toneOff() {

	digitalWrite(this->pin1, HIGH);

}