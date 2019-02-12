#ifndef _mpu6050_H
#define _mpu6050_H
#include <arduino.h>

#include "I2C.h"

  /* IMU Data */
static double accX, accY, accZ;
static double gyroX, gyroY, gyroZ;
static int16_t tempRaw;


static uint32_t timer;
static uint8_t i2cData[14]; // Buffer for I2C data

// TODO: Make calibration routine

void init_MPU();
void loop_MPU();


#endif
