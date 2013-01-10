AbstractSerial library - an attempt to consolidate all kinds of serial
communication happening on Arduino via I2C, ShiftOut/ShiftIn, or hardware SPI.

I2C is TODO due to lack of hardware, Shift is WIP.


AbstractSerial.h
  convenience header for inclusion in the Sketch


Interfaces:

ISerialConnection.h
  consolidates knowledge and procedures for connection handling: pins and
  transmission modes involved, how to assert the specific device and
  send/receive data
  

Implementations:

I2cConnection.h
  I2C implementation of serial connection - TODO

SerialConfig.cpp
SerialConfig.h
  storage for SPI mode, frequency divider, and some methods implementing their
  consequences

SerialDaisyChain.h
  class template for using one connection to several endpoints like
  concatenated shift registers etc.

ShiftConnection.cpp
ShiftConnection.h
  implements connection via ShiftOut / ShiftIn Arduino standard library
  functions

SpiConnection.cpp
SpiConnection.h
  implements connection via hardware SPI Arduino standard library functions
