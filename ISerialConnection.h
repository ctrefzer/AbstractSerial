#ifndef ISerialConnection_h
# define ISerialConnection_h

#include <stdint.h>

#include <Arduino.h>
//#include <SPI.h>
#include "SerialConfig.h"


/* a connection stores knowledge of pins used and the mechanisms required to
 * send/receive data; the internals of how to communicate with the device
 * itself is to be defined someplace else */

class ISerialConnection {
public:
  /* prepare SPI modes et.al. */
  virtual void setupChannel() const =0;
  virtual void applyDeviceSettings() const =0;

  /* enable and disable the channel before/after transmission */
  virtual void assert() const =0;
  virtual void deassert() const =0;

  /* take care of actual data traffic */
  virtual void send(uint8_t byte) const =0;
  virtual uint8_t receive() const =0;
};

#endif /* ndef ISerialConnection_h */
