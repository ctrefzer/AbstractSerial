#ifndef SerialDaisyChain_h
# define SerialDaisyChain_h

# include <stdint.h>

# include <Arduino.h>
# include <SPI.h>

# include "ISerialConnection.h"


/* T should correspond to a type supposed to be sent to / received from hardware
 * in chunks of bytes.  For 74hc595 this could be byte or uint8_t, for pga23xx
 * perhaps uint8_t[2].  */
template <class T, size_t N>
class SerialDaisyChain {

private:
  const ISerialConnection* _conn;
  T _data[N];


public:
  SerialDaisyChain(const ISerialConnection* conn) : _conn(conn) {
    // initialize pins et.al.
    _conn->setupChannel();
  }



  T getData(size_t ofs, T value) const {
    if (0 <= ofs && ofs < N) {
      return _data[ofs];
    } else {
      return (T)0;
    }
  }

  void setData(size_t ofs, T value) {
    if (0 <= ofs && ofs < N) {
      _data[ofs] = value;
    }
  }



  void sendToHardware() const {
    _conn->applyDeviceSettings(); // restore proper SPI mode etc.
    _conn->assert();
    
    uint8_t *chunk = (uint8_t *) _data; // need to send byte wise
    for (size_t i=0; i<N*(sizeof(T)/sizeof(uint8_t)); ++i) {
      /*
      Serial.print("about to send chunk at ");
      Serial.print(i);
      Serial.print(" with value ");
      Serial.println(chunk[i]);
      */
      _conn->send(chunk[i]);
    }

    _conn->deassert();
  }


  
  void receiveFromHardware() {
    _conn->applyDeviceSettings(); // restore proper SPI mode etc.

    // TODO: implementation ;) I only send to my stuff so far...
  }
};


#endif /* ndef SerialDaisyChain_h */
