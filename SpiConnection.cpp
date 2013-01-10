#include "SpiConnection.h"

SpiConnection::SpiConnection(
    const SerialConfig& config
  ) : _config(config),
      _cs(_csDefault) {}

SpiConnection::SpiConnection(
    const SerialConfig& config,
    uint8_t cs
  ) : _config(config),
      _cs(cs) {}

void
SpiConnection::setupChannel() const {
  SPI.begin();
  pinMode(_cs, OUTPUT);
  deassert();
}

void
SpiConnection::applyDeviceSettings() const {
  _config.applySpi();
}

void
SpiConnection::assert() const {
  // TODO: ?evaluate SPI mode in config and respect CPOL?
  digitalWrite(_cs, LOW);
}

void
SpiConnection::deassert() const {
  // TODO: ?evaluate SPI mode in config and respect CPOL?
  digitalWrite(_cs, HIGH);
}

void
SpiConnection::send(uint8_t data) const {
  SPI.transfer(data);
}

uint8_t
SpiConnection::receive() const {
  return SPI.transfer(0);
}
