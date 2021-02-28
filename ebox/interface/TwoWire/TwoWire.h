#ifndef __TWOWIRE_H
#define __TWOWIRE_H
#include "ebox_core.h"
#include "stream.h"


#define I2C_BUFFER_LENGTH 128

typedef enum {
    I2C_ERROR_OK,
    I2C_ERROR_DATA_LONG,
    I2C_ERROR_ADDR_NACK_NO_RECV,
    I2C_ERROR_DATA_NACK_NO_RECV,
    I2C_ERROR_BUS,
    I2C_ERROR_TIMEOUT,

} i2c_err_t;

class TwoWire : public Stream
{

public:
    typedef enum 
    {
        K400,
        K300,
        K200,
        K100,
        K10,
    }Speed_t;

    
    // public methods
    TwoWire();
    TwoWire(Gpio *sclPin, Gpio *sdaPin);

    void begin();
    void begin(Speed_t speed);
    void setClock(Speed_t speed);

    void beginTransmission(uint8_t address);
    void beginTransmission(int address);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t sendStop);
    uint8_t requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize, uint8_t sendStop);
    
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
  
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);

    inline size_t write(unsigned long n)
    {
        return write((uint8_t)n);
    }
    inline size_t write(long n)
    {
        return write((uint8_t)n);
    }
    inline size_t write(unsigned int n)
    {
        return write((uint8_t)n);
    }
    inline size_t write(int n)
    {
        return write((uint8_t)n);
    }
      using       Print::write;

private:
    


    uint8_t rxBuffer[I2C_BUFFER_LENGTH];
    uint16_t rxIndex;
    uint16_t rxLength;

    uint8_t txBuffer[I2C_BUFFER_LENGTH];
    uint16_t txIndex;
    uint16_t txLength;
    uint8_t txAddress;

    uint8_t transmitting;

  // per object data
    Gpio            *_sda;
    Gpio            *_scl;
	uint8_t   	 	_bitDelay;	// i2c时序
    uint8_t     _err_at;


    // private methods
    i2c_err_t _write(const uint8_t *data, size_t);
    i2c_err_t _write(uint8_t address,const uint8_t *data, size_t quantity, int sendStop);
    size_t _read(uint8_t address,uint8_t *data, uint16_t quantity,uint8_t sendStop);


    //基础的i2c功能
    void _start(void);
    void _stop(void);
    i2c_err_t _waitAck();
    i2c_err_t _sendByte( uint8_t data);
    i2c_err_t  _send7bitsAddress(uint8_t slaveAddr, uint8_t WR);
    uint8_t _receiveByte();
    int8_t _sendAck();
    int8_t _sendNack();
    
        

};
#endif
