#include <Arduino.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include <Wire.h>

#define MPU 0x68    //MPU6050 i2c direccion

MPU6050 mpu;
int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;

boolean contexto=1;

void setup() {

  Wire.begin();
  Serial.begin(9600);

  mpu.initialize();
  
  Serial.println(mpu.testConnection() ? "MPU6050 is ready":"MPU6050 error");
}

void loop() {
  mpu.getAcceleration(&AcX, &AcY, &AcZ);
  mpu.getRotation(&GyX, &GyY, &GyZ);

  Serial.print("Aceleracion:\t");
  Serial.print(AcX); Serial.print("\t");
  Serial.print(AcY); Serial.print("\t");
  Serial.print(AcZ); Serial.print("\t\tRotacion:\t\t");
  Serial.print(GyX); Serial.print("\t");
  Serial.print(GyY); Serial.print("\t");
  Serial.println(GyZ);
}