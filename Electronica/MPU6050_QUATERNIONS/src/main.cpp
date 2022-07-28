//**************************************************************//
//  Name    : xxxxxxxxxxxx, xxxxxxxxxxx                         //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Descripcion programa                              //
//          :                                                   //
//****************************************************************

#include <Arduino.h>

#include <MPU6050_6Axis_MotionApps20.h>
#include <I2Cdev.h>

#if (I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE) && !defined (PARTICLE)
    #include "Wire.h"
#endif

void DMP_init();
void Start_device();

MPU6050 mpu;

bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
		#if defined (PARTICLE)
			Wire.setSpeed(CLOCK_SPEED_400KHZ);
			Wire.begin();
		#else
			Wire.begin();
			TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
	  #endif

    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
  
  Serial.begin(115200);

  Serial.println("Arrancamo perro");
  mpu.initialize();

  Serial.println(mpu.testConnection() ? "Todo ok" : "Todo mal");

  mpu.setXAccelOffset(-2351);
  mpu.setYAccelOffset(-707);
  mpu.setZAccelOffset(1036);
  mpu.setXGyroOffset(30);
  mpu.setYGyroOffset(40);
  mpu.setZGyroOffset(10);

  DMP_init();
  Start_device();
}

void loop() {
  if (!dmpReady) return;
  
  while (!mpuInterrupt && fifoCount < packetSize){
    //do struff
  }
  
  mpuInterrupt = 0;
  mpuIntStatus = mpu.getIntStatus();

  fifoCount = mpu.getFIFOCount();

  if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));
  }
  else if ((mpuIntStatus & 0x02) > 0) {
    // wait for correct available data length, should be a VERY short wait
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

    // read a packet from FIFO
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    
    // track FIFO count here in case there is > 1 packet available
    // (this lets us immediately read more without waiting for an interrupt)
    fifoCount -= packetSize;

    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    Serial.print("\t");
    Serial.print(ypr[0]);
    Serial.print("\t");
    Serial.print(ypr[1]);
    Serial.print("\t");
    Serial.print(ypr[2]);
    Serial.println("\t");
  }
}

void DMP_init(){
  Serial.println(F("Initializing DMP..."));
  devStatus = mpu.dmpInitialize();

  if (devStatus == 0)
  {
    Serial.print("Enabling DMP");
    mpu.setDMPEnabled(true);
    Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
    attachInterrupt(0, dmpDataReady, RISING);
    
    Serial.println(F("DMP ready! Waiting for first interrupt..."));
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  }
  else {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  } 
}

void Start_device(){
   Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available());                 // wait for data
  while (Serial.available() && Serial.read());
}