#include "Motor.h"


Motor::Motor() {
	this->pin1 = 2;
	this->pin2 = 3;
	this->speed = 255;
	pinMode(this->pin1, OUTPUT);
	pinMode(this->pin2, OUTPUT);
}

Motor::Motor(int p1, int p2, int speed) {
	this->pin1 = p1;
	this->pin2 = p2;
	this->speed = speed;
	pinMode(this->pin1, OUTPUT);
	pinMode(this->pin2, OUTPUT);
}

void Motor::fwd() {
	analogWrite(this->pin1, 0);
	analogWrite(this->pin2, this->speed);
}

void Motor::bkwd() {
	analogWrite(this->pin1, this->speed);
	analogWrite(this->pin2, 0);
}

void Motor::stop() {
	analogWrite(this->pin1, 0);
	analogWrite(this->pin2, 0);
}

int Motor::getSpeed() {
	return this->speed;
}

void Motor::setSpeed(int s) {
	this->speed = s;
}