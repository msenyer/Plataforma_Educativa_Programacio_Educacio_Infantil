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

void BluetoothMaster::sendInfo(Vector<int> instruction) {
	String stringSend = "<";
	//Serial.println("vector size: " + instruction.size());
	for (int i = (instruction.size()-1); i >= 0; i--) {
		String str = "";
		switch (instruction[i]) {
			case 1:
				str += "ERROR";
				Serial.println("ERROR");
				delay(25);
				break;

			case 2:
				str += "RIGHT";
				Serial.println("<RIGHT>");
				delay(25);
				break;

			case 3:
				str += "FORWARD";
				Serial.println("<FORWARD>");
				delay(25);
				break;

			case 4:
				str += "LEFT";
				Serial.println("<LEFT>");
				delay(25);
				break;

			case 5:
				str += "NOTHING";
				Serial.println("<NOTHING>");
				delay(25);
				break;

			default:
				break;

			}
		if (strcmp("<", stringSend.c_str())!=0) {
			str = "," + str;
		}
		stringSend += str;
	}
	

	stringSend += ">";


	Serial.println(stringSend);
	this->btSerial->println(stringSend);
}

