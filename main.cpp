#include <Arduino.h>
#include <Stream.h>
#include <SPI.h>
#include <string.h>
#include <Adafruit_NeoPixel.h>
#include "MasterWireTools/MasterWireTools.h"
#include "constants.h"
#include "OSGEthernetTools/OSGEthernetDriver.h"
#include "OSGEthernetTools/OSGTcpConnection.h"

OSGEthernetDriver* eth0;
OSGTcpConnection* tcp_conn;
MasterWireTools* wire;

void setup() {

	//start wire for our TWI/I2C work.
	// Wire.begin();
	wire = new MasterWireTools();
	
	//start serial for our computer connection
	Serial.begin(9600);

	#ifdef DEBUG
		Serial.println("Initializing...");
	#endif

	//start the interwebz.
	eth0 = new OSGEthernetDriver();

	//initialize the tcp connection
	tcp_conn = new OSGTcpConnection();

	//tell it to make a new strip
	wire->sendMessage("NEOPIXELSTRIP:12:9:INIT", 1);
	delay(1000);
	




}

void loop() {
	eth0->loop();
	// #ifdef DEBUG
	// 	Serial.println("Hello World2");
	// #endif

	//rainbow!
	wire->sendMessage("NEOPIXELSTRIP:12:9:RAINBOW", 1);
	delay(2000);

}

int main(void)
{
	
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

