#ifndef OSGCOMMANDPARSER_H
#define OSGCOMMANDPARSER_H
#include "../NeoPixel/NeoPixelController.h"

class OSGCommandParser {
private:
	char* command;
	NeoPixelController* controller;
public:
	OSGCommandParser() {

	}

	void parseCommand(char* module, char* command) {
		Serial.print(F("module: "));
		Serial.println(module);

		Serial.print(F("parseCommand: "));
		Serial.println(command);

		if(strcmp(module, "NEOPIXEL") == 0) {
			NeoPixelController::getInstance()->parseCommand(command);
		}
	}
};


#endif /* OSGCOMMANDPARSER_H */