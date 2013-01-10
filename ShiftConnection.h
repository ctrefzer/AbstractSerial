#ifndef ShiftConnection_h
# define ShiftConnection_h

# include <stdint.h>
# include <Arduino.h>

# include "ISerialConnection.h"
# include "SerialConfig.h"


class ShiftConnection : public virtual ISerialConnection {
private:
  const SerialConfig& _config;

  const uint8_t _cs;
  const uint8_t _mosi;
  const uint8_t _miso;
  const uint8_t _sclk;
  
public:
  virtual void setupChannel() const;
  virtual void applyDeviceSettings() const;

  virtual void assert() const;
  virtual void deassert() const;

  virtual void send(uint8_t data) const;
  virtual uint8_t receive() const;

  ShiftConnection(const SerialConfig& config,
    uint8_t cs, uint8_t mosi, uint8_t miso, uint8_t sclk);
};

#endif /* ndef ShiftConnection_h */
