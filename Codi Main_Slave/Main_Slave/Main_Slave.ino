// --------------------------------------------------------------------------- Initialization
#include "Node.h"
#include "StateQueue.h"
#include "Car.h"
#include "Led.h"
#include "Buzzer.h"
#include "Bluetooth.h"
#include "Motor.h"
#include "SoftwareSerial.h"

#define PIN1 3
#define PIN2 5
#define PIN3 10
#define PIN4 11
#define SPEED 175	// motor left
#define SPEED2 155	//motor right
#define BZPIN 6
#define RLED 12
#define YLED 13
#define BT1 8	//RX
#define BT2 9	//TX
//#define STOPTIME 1500	//temps que volem que duri una instrucció

#define TESTMODE false	// switch to 'true' to test the proper working of the vehicle


Car *cotxe;

// --------------------------------------------------------------------------- Setup
void setup() {
	
	Serial.begin(38400);
	cotxe = new Car(PIN1, PIN2, PIN3, PIN4, BZPIN, RLED, YLED, BT1, BT2, SPEED, SPEED2);
	cotxe->init();
	if (TESTMODE) {
		cotxe->check();
	}
}



// --------------------------------------------------------------------------- Loop
void loop() {
	
	cotxe->listen();
	cotxe->run();
	
}