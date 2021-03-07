#include "Bluetooth.h"
#include "Car.h"


Bluetooth::Bluetooth(int rx, int tx, Car* c)	
{
	this->pinRx = rx;
	this->pinTx = tx;
	this->car = c;
	this->btSerial = new SoftwareSerial(this->pinRx, this->pinTx);
	this->btSerial->begin(38400);
	count = 0;
}

void Bluetooth::showCount() {
	Serial.println(count);
}

void Bluetooth::receive()
{
	static boolean recvInProgress = false;
	static byte ndx = 0;
	char startMarker = '<';
	char endMarker = '>';
	

	if (this->btSerial->available()){

		char rc = this->btSerial->read();
		if (recvInProgress == true){
			if (rc != endMarker){
				if (ndx < MAXDATALENGTH) { receivedChars[ndx] = rc; ndx++; }
			}
			else{
				receivedChars[ndx] = '\0'; // terminate the string
				//Serial.println(receivedChars);
				recvInProgress = false;
				ndx = 0;
				newData = true;
			}
		}
		else if (rc == startMarker) { 
			recvInProgress = true; 
		}
	}
}

void Bluetooth::processCommand()
{
	newData = false;
	//Serial.print("recieved data = ");  
	//Serial.println(receivedChars);

	Vector<String> insArray = this->splitString(receivedChars);
	
	for (int i = 0; i < 5; i++) {
		String instruction = insArray[i];

		if (strcmp("FORWARD", instruction.c_str()) == 0
			|| strcmp("LEFT", instruction.c_str()) == 0
			|| strcmp("RIGHT", instruction.c_str()) == 0
			|| strcmp("ERROR", instruction.c_str()) == 0
			|| strcmp("NOTHING", instruction.c_str()) == 0) {

			this->car->addInstruction(instruction.c_str());

		}
	}
}


void Bluetooth::btRun()
{
		
	this->receive();                // check to see if we have received any new commands
	if (newData) {
		this->processCommand();
	}    // if we have a new command do something	
}


Vector<String> Bluetooth::splitString(String str) {
	int io = str.indexOf(",");
	int ioB = 0;
	int i = 0;
	Vector<String> vect;
	String lastString = "";
	Serial.println(str);
	while (io != -1) {	
		lastString = str.substring(ioB, io);
		vect.push_back(lastString);
		ioB = io+1;
		io = str.indexOf(",", ioB);
		//Serial.println(lastString);
		i++;
	}
	vect.push_back(str.substring(ioB, str.length()));
	return vect;
	
}

