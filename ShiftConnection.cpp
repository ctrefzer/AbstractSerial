# include "ShiftConnection.h"

ShiftConnection::ShiftConnection(
    const SerialConfig& config,
    uint8_t cs,
    uint8_t mosi,
    uint8_t miso,
    uint8_t sclk
  ) : _config(config),
      _cs(cs),
      _mosi(mosi),
      _miso(miso),
      _sclk(sclk) {}

void
ShiftConnection::setupChannel() const {
  pinMode(_cs, OUTPUT);
  pinMode(_sclk, OUTPUT);
  deassert();
}

void
ShiftConnection::assert() const {
  // TODO: ?evaluate SPI mode in config and respect CPOL?
  digitalWrite(_cs, LOW);
}

void
ShiftConnection::deassert() const {
  // TODO: ?evaluate SPI mode in config and respect CPOL?
  digitalWrite(_cs, HIGH);
}

void
ShiftConnection::send(uint8_t data) const {
  pinMode(_mosi, OUTPUT);
  // TODO: ?retrieve CPHA from SPI mode and preinit _sclk?
  shiftOut(_mosi, _sclk, _config.getBitOrder(), data);
}

uint8_t
ShiftConnection::receive() const {
  pinMode(_mosi, INPUT);
  // TODO: ?retrieve CPHA from SPI mode and preinit _sclk?
  return shiftIn(_mosi, _sclk, _config.getBitOrder());
}
