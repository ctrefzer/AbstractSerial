#include "SerialConfig.h"

SerialConfig::SerialConfig(
    uint8_t bitOrder,
    uint8_t dataMode,
    uint8_t clockDivider
  ) : _bitOrder(bitOrder),
      _dataMode(dataMode),
      _clockDivider(clockDivider) {}

uint8_t
SerialConfig::getBitOrder() const {
  return _bitOrder;
}

uint8_t
SerialConfig::getDataMode() const {
  return _dataMode;
}

uint8_t
SerialConfig::getClockDivider() const {
  return _clockDivider;
}

void
SerialConfig::applySpi() const {
  SPI.setBitOrder(_bitOrder);
  SPI.setDataMode(_dataMode);
  if (0 != _clockDivider) {
    SPI.setClockDivider(_clockDivider);
  }
}
