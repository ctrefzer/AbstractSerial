//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

#include <SPI.h>
#include <AbstractSerial.h>

// HW SPI needs the following setup (works for ShiftOut as well):
//Pin 10 connected to ST_CP of 74HC595
//Pin 13 connected to SH_CP of 74HC595
//Pin 11 connected to DS of 74HC595

static const SerialConfig ic74hc595Config(MSBFIRST, SPI_MODE0, SPI_CLOCK_DIV128);

// uncomment this for ShiftOut() implementation
//static const ShiftConnection ic74hc595Connection(ic74hc595Config);

// uncomment this for SPI library implementation
//static const SpiConnection ic74hc595Connection(ic74hc595Config);


static SerialDaisyChain<uint8_t, 1> ic74hc595Array(&ic74hc595Connection);

void setup() {
}

void loop() {
  // count from 0 to 255 and display the number 
  // on the LEDs
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    ic74hc595Array.setData(0, numberToDisplay);
    ic74hc595Array.sendToHardware();
    
    // pause before next value:
    delay(250);
  }
}

