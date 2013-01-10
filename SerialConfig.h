#ifndef SerialConfig_h
# define SerialConfig_h

# include <stdint.h>

# include <Arduino.h>
# include <SPI.h>

class SerialConfig {
private:
  uint8_t _bitOrder;     // MSBFIRST xor LSBFIRST
  uint8_t _dataMode;     // SPI_MODE0..3
  uint8_t _clockDivider; // SPI_CLOCK_DIV2..128

public:
  SerialConfig(
    uint8_t bitOrder,
    uint8_t dataMode,
    uint8_t clockDivider
  );

  uint8_t getBitOrder() const;
  uint8_t getDataMode() const;
  uint8_t getClockDivider() const;

  void applySpi() const;
};

#endif // ndef SerialConfig_h
