#include "Car.h"
#include "Buzzer.h"
#include "Led.h"
#include "Bluetooth.h"

#define STOPTIME 1700
#define STOPTIME2 1350
#define PAUSETIME 500


Car::Car(int ml1, int ml2, int mr1, int mr2, int pbz, int plr, int ply, int pbt1, int pbt2, int speed, int speed2) {
	this->state = "STOP";
	this->motorLeft = new Motor(ml1, ml2, speed);
	this->motorRight = new Motor(mr1, mr2, speed2);
	this->bz = new Buzzer(pbz);
	this->ledRed = new Led(plr);
	this->ledYellow = new Led(ply);
	this->bt = new Bluetooth(pbt1, pbt2, this);					
}

void Car::init() {
	this->bz->toneOff();
	this->ledRed->ledOff();
	this->ledYellow->ledOff();
	this->motorLeft->stop();
	this->motorRight->stop();
}

void Car::forward() {
	this->state = "FORWARD";
	
	this->motorLeft->setSpeed(175);
	this->motorRight->setSpeed(157);
	this->ledYellow->ledOn();
	this->motorLeft->fwd();
	this->motorRight->fwd();
	
	delay(STOPTIME);
	
	this->motorLeft->stop();
	this->motorRight->stop();
	this->ledYellow->ledOff();
	
	delay(PAUSETIME);
}

void Car::stop() {
	
	this->motorLeft->stop();
	this->motorRight->stop();
	this->state = "STOP";

	delay(PAUSETIME);
}

void Car::left() {
	
	this->state = "LEFT";

	this->ledYellow->ledOn();
	this->motorLeft->setSpeed(155);
	this->motorRight->setSpeed(185);
	this->motorLeft->bkwd();
	this->motorRight->fwd();

	
	delay(STOPTIME2);
	
	this->motorLeft->stop();
	this->motorRight->stop();
	this->ledYellow->ledOff();
	

	delay(PAUSETIME);
}

void Car::right() {
	
	this->state = "RIGHT";
	
	this->motorLeft->setSpeed(185);
	this->motorRight->setSpeed(155);
	this->ledYellow->ledOn();
	this->motorLeft->fwd();
	this->motorRight->bkwd();

	
	delay(STOPTIME2);
	
	this->motorLeft->stop();
	this->motorRight->stop();
	this->ledYellow->ledOff();
	

	delay(PAUSETIME);
}

void Car::listen() {
	this->bt->btRun();
}

void Car::check() {
	
	this->motorLeft->fwd();
	delay(1000);
	this->motorLeft->stop();
	this->motorRight->fwd();
	delay(1000);
	this->motorRight->stop();

	this->falseInstruction();
}


void Car::falseInstruction() {
	this->bz->toneOn();
	this->ledRed->ledOn();
	delay(450);
	this->bz->toneOff();
	this->ledRed->ledOff();

	delay(50);

	this->bz->toneOn();
	this->ledYellow->ledOn();
	delay(450);
	this->bz->toneOff();
	this->ledYellow->ledOff();
	
}

void Car::addInstruction(String newState)
{
	this->queue.push(newState);
	//this->queue.printQueue();
	//Serial.print("Queue size: ");
	//Serial.println(this->queue.size());
}

String Car::getInstruction() {
	
	if (this->queue.size() > 0) {
		String s = this->queue.pull();
		this->queue.printQueue();
		Serial.print("Queue size: ");
		Serial.println(this->queue.size());
		return s;
	}
	return "";
}

void Car::run() {
	
	String s;
	//this->queue.printQueue();
	if (this->state == "STOP") {
		this->state = "WAIT";
		
		s = this->getInstruction();
		
		if (s != "") {
			Serial.print("Instruction: ");
			Serial.println(s);
			
			if (s == "FORWARD") {
				this->forward();
				Serial.println("going forward");
			}

			else if (s == "RIGHT") {
				this->right();
			}

			else if (s == "LEFT") {
				this->left();
			}

			else if (s == "ERROR") {
				this->stop();
				this->falseInstruction();
			}

			else if (s == "NOTHING") {
				this->stop();
			}

		}

		this->state = "STOP";	
	}
}
