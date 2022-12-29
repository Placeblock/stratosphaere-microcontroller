#include "MS5Sensor.h"
#include <iostream>
#include <Wire.h>

const uint8_t MS5_ADDRESS = 0x76;

MS5Data::MS5Data(int16_t pressure, int16_t temperature) {
    this->pressure = pressure;
    this->temperature = temperature;
}

void MS5Sensor::configure() {
  Wire.beginTransmission(MS5_ADDRESS);
  Wire.write(0x40);
  Wire.endTransmission(true);
}

MS5Data MS5Sensor::getData() {
  Wire.beginTransmission(MS5_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission(true);
  Wire.requestFrom(MS5_ADDRESS, (size_t) 3, true);
  int16_t pressure = Wire.read();
  int16_t temperature = Wire.read()<<8 | Wire.read();
  return {pressure, temperature};
}