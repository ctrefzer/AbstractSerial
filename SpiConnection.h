#ifndef SpiConnection_h
# define SpiConnection_h

# include <stdint.h>

# include <Arduino.h>
# include <SPI.h>

# include "ISerialConnection.h"
# include "SerialConfig.h"


class SpiConnection : public virtual ISerialConnection {
private:
  const SerialConfig& _config;

  /* Arduino HW SPI specific pins */
  static const uint8_t _csDefault = 10;
  // unused
  //static const uint8_t _mosi = 11;
  //static const uint8_t _miso = 12;
  //static const uint8_t _sclk = 13;

  /* defaults to _cs, others are possible */
  const uint8_t _cs;

public:
  virtual void setupChannel() const;
  virtual void applyDeviceSettings() const;

  virtual void assert() const;
  virtual void deassert() const;

  virtual void send(uint8_t data) const;
  virtual uint8_t receive() const;

  SpiConnection(const SerialConfig& config);
  SpiConnection(const SerialConfig& config, uint8_t cs);
};

#endif /* ndef SpiConnection_h */
