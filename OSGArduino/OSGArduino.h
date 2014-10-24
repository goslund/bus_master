// 
// File:   OSGArduino.h
// Author: geoff
//
// Created on October 13, 2013, 3:05 PM
//

#ifndef _OSGARDUINO_H
#define	_OSGARDUINO_H

#include <Arduino.h>
#include "../OSGEthernetTools/OSGEthernetDriver.h"
#include "../OSGEthernetTools/OSGTcpConnection.h"
#include <MemoryFree/MemoryFree.h>
#include "../NeoPixel/NeoPixel.h"
#include "../NeoPixel/NeoPixelStrip.h"
#include "../NeoPixel/NeoPixelController.h"
#include "../NeoPixel/NeoPixelOperation.h"


class OSGArduino {
private:
    OSGEthernetDriver* eth0;
    OSGTcpConnection* socket;
    NeoPixelController* controller;
    NeoPixelStrip* test_strip;
    NeoPixel* test_pixels;
    NeoPixelProgressiveLoop* operations;
    // NeoPixelProgressiveLoop* p1;
    int* pointer;
public:
    OSGArduino()
    {
      // eth0 = new OSGEthernetDriver();
      // //Serial.println(freeMemory());

      // socket = new OSGTcpConnection(); 
      // // Serial.println(freeMemory());

      // controller = NeoPixelController::getInstance();
      // Serial.println(freeMemory());

      test_strip = new NeoPixelStrip();
      test_strip->init(12, 9);

      
      // test_strip->rainbow(1000);

  

      test_pixels = new NeoPixel[test_strip->getSize()];
      operations = new NeoPixelProgressiveLoop[test_strip->getSize()];
      int i;
      for (i=0; i < test_strip->getSize(); i++) {
        // test_pixels[i] = NeoPixel(test_strip, i);
        test_pixels[i].setStrip(test_strip);
        test_pixels[i].setPixelNum(i);
        operations[i].setPixel(&test_pixels[i]);
        operations[i].setWait(40);
        // test_pixels[i]->check();
        test_pixels[i].setPixelColor(0,0,0); 
        //operations[i] = new NeoPixelProgressiveLoop(test_pixels[i], 10);
          
      }

      //p1 = new NeoPixelProgressiveLoop(&test_pixels[0], 100);
      // Serial.print("pixel 0: ");
      // Serial.println(test_pixels[0].getPixelNum());

      // Serial.println(freeMemory());
    };

    

    void loop() {

      // Serial.print("pixel 0: ");
      // Serial.println(test_pixels[0].getPixelNum());


      // p1->loop();

      // for(int i = 0; i < test_strip->getSize(); i++) {
      //   operations[i].loop();
      // }

      

      // operations[0].loop();
      // operations[3].loop();
      // operations[5].loop();
      // operations[7].loop();
      // operations[9].loop();
      // operations[11].loop();
      
      // p2->loop();
      // p3->loop();
      // controller->loop();
      // eth0->loop();
      // socket->loop();
    }


};


#endif	/* _OSGARDUINO_H */  