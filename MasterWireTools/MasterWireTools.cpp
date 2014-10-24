#include "MasterWireTools.h"

void MasterWireTools::sendMessage(char* message, int device_num) {
	// #ifdef DEBUG
		Serial.print("Sending: ");
		Serial.println(message);
	// #endif

	Wire.beginTransmission(device_num);
	Wire.write(message);
	Wire.endTransmission();
}