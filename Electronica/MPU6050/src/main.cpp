//**************************************************************//
//  Name    : xxxxxxxxxxxx, xxxxxxxxxxx                         //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Descripcion programa                              //
//          :                                                   //
//****************************************************************

#include <Arduino.h>
#include <I2Cdev.h>
#include <MPU6050.h>

//-2304   -726    1034    24      36      11

#if (I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE) && !defined (PARTICLE)
  #include "Wire.h"
#endif

MPU6050 mpu;

typedef struct Datos{
  int16_t RAW_ACC_X;
  int16_t RAW_ACC_Y;
  int16_t RAW_ACC_Z;
}sensor;

sensor accelerogyro;
const float ACC_G = 9.8;

void convercion(sensor *RAW_DATA);

void setup(){
  Wire.begin();
  Serial.begin(115200);

  mpu.initialize();
  
  mpu.setXAccelOffset(-2304);
  mpu.setYAccelOffset(-726);
  mpu.setZAccelOffset(1034);
  mpu.setXGyroOffset(24);
  mpu.setYGyroOffset(36);
  mpu.setZGyroOffset(11);

  Serial.println(mpu.testConnection() ? "Todo OK" : "Todo MAL");
}

void loop(){
  accelerogyro.RAW_ACC_X = mpu.getAccelerationX();
  accelerogyro.RAW_ACC_Y = mpu.getAccelerationY();
  accelerogyro.RAW_ACC_Z = mpu.getAccelerationZ();

  convercion(&accelerogyro);

}

void convercion(sensor *RAW_DATA){
  float j = ACC_G / 16384;
  float ACC_X = (*RAW_DATA).RAW_ACC_X * j;
  float ACC_Y = (*RAW_DATA).RAW_ACC_Y * j;
  float ACC_Z = (*RAW_DATA).RAW_ACC_Z * j;
  Serial.print("[m/s^2]\t");
  Serial.print(ACC_X);
  Serial.print("\t");
  Serial.print(ACC_Y);
  Serial.print("\t");
  Serial.print(ACC_Z);
  Serial.println("\t|\t");
}