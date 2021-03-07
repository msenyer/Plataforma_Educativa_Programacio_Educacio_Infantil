// 
// 
// 

#include "ShiftRegister.h"

#define NUMBEROFSHIFTREGS 2
#define DATAWIDTH NUMBEROFSHIFTREGS*8	//each shift register has 8 data bits
#define PULSEWIDTH 5	//microseconds
#define MAXINSTRUCTIONS 5
#define NUMINSTRUCTIONS 3
#define INITIALBIT1 1
#define INITIALBIT2 4

int count1, count2;

ShiftRegister::ShiftRegister(int data, int load, int clk, int clkE) {

	this->dataPin = data;
	this->loadPin = load;
	this->clockPin = clk;
	this->clockEnablePin = clkE;

	pinMode(this->dataPin, INPUT);
	pinMode(this->loadPin, OUTPUT);
	pinMode(this->clockPin, OUTPUT);
	pinMode(this->clockEnablePin, OUTPUT);


	digitalWrite(this->clockPin, LOW);
	digitalWrite(this->loadPin, HIGH);
}

unsigned int ShiftRegister::readShiftRegs() {

	long bitVal;
	unsigned int bytesVal = 0;

	// Trigger a parallel Load to latch the state of the data lines,
	//asynchronous parallel load
	digitalWrite(this->clockEnablePin, HIGH);
	digitalWrite(this->loadPin, LOW);
	// delay
	delayMicroseconds(PULSEWIDTH);

	// serial input
	digitalWrite(this->loadPin, HIGH);
	digitalWrite(this->clockEnablePin, LOW);


	for (int i = 0; i < DATAWIDTH; i++)
	{
		bitVal = digitalRead(this->dataPin);

		//Set the corresponding bit in bytesVal.

		bytesVal |= (bitVal << ((DATAWIDTH - 1) - i));   // |= assignment by bitwise OR (bit by bit), shifts with every new i value

														 /* Pulse the Clock (rising edge shifts the next bit).
														 */
		digitalWrite(this->clockPin, HIGH);
		delayMicroseconds(PULSEWIDTH);
		digitalWrite(this->clockPin, LOW);
	}

	return(bytesVal);
}

void ShiftRegister::displayPinValues(unsigned int pinValues)
{
	Serial.println("Pin States:");

	for (int i = 1; i < DATAWIDTH; i++) // modified in order to not display last bit (displays from d15 to d1). 
	{
		Serial.print("  Pin-");
		Serial.print(i);
		Serial.print(": ");

		if ((pinValues >> i) & 1)
			Serial.print("HIGH");
		else
			Serial.print("LOW");

		Serial.println();
	}

	Serial.println();
}

int ShiftRegister::detectPinValues(unsigned int pinValues, int count1, int count2) {


	Serial.println("Pin States:");

	for (int i = count1; i < count2; i++)
	{

		if ((pinValues >> i) & 1) {
			if ((pinValues >> (i + 1)) & 1) {
				Serial.println("Error");
				return 1;
			}
			else {
				Serial.println("Right");
				return 2;
			}
		}

		else if ((pinValues >> (i + 1)) & 1) {
			if ((pinValues >> (i + 2)) & 1) {
				Serial.println("Error");
				return 1;
			}
			else {
				Serial.println("Center");
				return 3;
			}
		}

		else if ((pinValues >> (i + 2)) & 1) {
			Serial.println("Left");
			return 4;
		}

		else {
			Serial.println("Nothing");
			return 5;
		}
	}
}


Vector<int> ShiftRegister::exportInstruction(unsigned int pinValues) {

	Vector<int> results;

	int count1 = INITIALBIT1;
	int count2 = INITIALBIT2;

	for (int i = 0; i < MAXINSTRUCTIONS; i++) {
		results.push_back(this->detectPinValues(pinValues, count1, count2));
		count1 = count1 + NUMINSTRUCTIONS;
		count2 = count2 + NUMINSTRUCTIONS;
		
	}


	return results;
}