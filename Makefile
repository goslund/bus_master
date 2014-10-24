# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG = uno

ARDUINO_LIBS = \
	Wire \
	SPI \
	Adafruit_NeoPixel \
	EthernetV2_0 \
	MemoryFree

ARDUINO_DIR = /home/geoff/arduino-1.0.5

ARDMK_DIR = /home/geoff/projects/arduino_makefile

AVR_TOOLS_DIR = /usr/

LOCAL_CPP_SRCS = \
	$(wildcard *.cpp) \
	$(wildcard NeoPixel/*.cpp) \
	$(wildcard MasterWireTools/*.cpp)



include $(ARDMK_DIR)/Arduino.mk