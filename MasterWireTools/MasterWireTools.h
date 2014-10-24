#ifndef MASTERWIRETOOLS_H
#define MASTERWIRETOOLS_H
#include <Wire.h>
#include <SPI.h>

class MasterWireTools {
public:

	//master constructor
	MasterWireTools() {
		Wire.begin();
		Serial.println("Hello World 3");
	}	

	void sendMessage(char* message, int device_num);

};

#endif /* MASTERWIRETOOLS_H */