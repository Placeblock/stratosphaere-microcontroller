#include "MPUSensor.h"
#include <iostream>
#include <Wire.h>

const uint8_t MPU_ADDRESS = 0x68;

MPUData::MPUData(int16_t acc_x, 
            int16_t acc_y,
            int16_t acc_z,
            int16_t gyro_x,
            int16_t gyro_y,
            int16_t gyro_z,
            double temperature) {
    this->acc_x = acc_x;
    this->acc_y = acc_y;
    this->acc_z = acc_z;
    this->gyro_x = gyro_x;
    this->gyro_y = gyro_y;
    this->gyro_z = gyro_z;
    this->temperature = temperature;
}

void MPUSensor::configure() {
  Wire.beginTransmission(MPU_ADDRESS); // I2C Transmission
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

MPUData MPUSensor::getData() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x3B);
  Wire.endTransmission(true);
  Wire.requestFrom(MPU_ADDRESS, (size_t) 7*2, true);
  int16_t acc_x = Wire.read()<<8 | Wire.read();
  int16_t acc_y = Wire.read()<<8 | Wire.read();
  int16_t acc_z = Wire.read()<<8 | Wire.read();
  int16_t temperature = Wire.read()<<8 | Wire.read();
  int16_t gyro_x = Wire.read()<<8 | Wire.read();
  int16_t gyro_y = Wire.read()<<8 | Wire.read();
  int16_t gyro_z = Wire.read()<<8 | Wire.read();
  return {acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z, temperature/340.00+36.53};
}