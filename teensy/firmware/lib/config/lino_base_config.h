#ifndef LINO_BASE_CONFIG_H
#define LINO_BASE_CONFIG_H

//uncomment the base you're building
#define LINO_BASE DIFFERENTIAL_DRIVE // 2WD and Tracked robot w/ 2 motors
// #define LINO_BASE SKID_STEER      // 4WD robot
// #define LINO_BASE ACKERMANN       // Car-like steering robot w/ 2 motors
// #define LINO_BASE ACKERMANN1      // Car-like steering robot w/ 1 motor
// #define LINO_BASE MECANUM         // Mecanum drive robot

//uncomment the motor driver you're using
// #define USE_L298_DRIVER
#define USE_BTS7960_DRIVER
// #define USE_ESC

//uncomment the IMU you're using
// #define USE_GY85_IMU
#define USE_MPU6050_IMU
// #define USE_MPU9150_IMU
// #define USE_MPU9250_IMU

#define DEBUG 1

#define K_P 0.6 // P constant
#define K_I 0.3 // I constant
#define K_D 0.5 // D constant

//define your robot' specs here
#define MAX_RPM 95                // motor's maximum RPM - from Arlo motor mount document, should be the same
// Encoder resolution is 2.5 degrees per click, quadranture 36 position encoder on the drive shaft, 144 clicks per rev
#define COUNTS_PER_REV 144        // wheel encoder's no of ticks per rev 
#define WHEEL_DIAMETER 0.1524     // wheel's diameter in meters 6"*2.54=15.24cm from Eddie robot documentation
#define PWM_BITS 8                // PWM Resolution of the microcontroller -> doesent matter with BTS7960_DRIVER

// ??? check which distance is used in the calculations??? 
// measured on the robot outside to outside = 0.425
// between = 0.3615
// middle width to middle width = 0.3925
// for now we will be using the distance between the wheels --> 0.3615
#define LR_WHEELS_DISTANCE 0.3615  // distance between left and right wheels
#define FR_WHEELS_DISTANCE 0.30   // N/A-> distance between front and rear wheels. Ignore this if you're on 2WD/ACKERMANN
#define MAX_STEERING_ANGLE 0.415  // N/A-> max steering angle. This only applies to Ackermann steering

//=================BIGGER ROBOT SPEC (BTS7960)=============================
// #define K_P 0.05  // P constant
// #define K_I 0.9   // I constant
// #define K_D 0.1   // D constant

// define your robot' specs here
// #define MAX_RPM 45               // motor's maximum RPM
// #define COUNTS_PER_REV 4000      // wheel encoder's no of ticks per rev
// #define WHEEL_DIAMETER 0.15      // wheel's diameter in meters
// #define PWM_BITS 8               // PWM Resolution of the microcontroller
// #define LR_WHEELS_DISTANCE 0.32  // distance between left and right wheels
// #define FR_WHEELS_DISTANCE 0.38  // distance between front and back wheels. Ignore this if you're on 2WD/ACKERMANN
//================= END OF BIGGER ROBOT SPEC =============================

/*
ROBOT ORIENTATION
         FRONT
    MOTOR1  MOTOR2  (2WD/ACKERMANN)
    MOTOR3  MOTOR4  (4WD/MECANUM)  
         BACK
*/

/*
Arduino Mega pins used in the setup below:

Int0 Pin 2    --> MOTOR1_ENCODER_A
Int1 Pin 3    --> MOTOR1_ENCODER_B    
Int2 Pin 18   --> MOTOR2_ENCODER_A
Int3 Pin 19   --> MOTOR2_ENCODER_B
Int4 Pin 20 SDA --> for IMU I2C
Int5 Pin 21 SCL --> for IMU I2C

Pin  22 MOTOR1_IN_A   
Pin  23 MOTOR1_IN_B   
Pin  24 MOTOR2_IN_A 
Pin  25 MOTOR2_IN_B  

Pins 30 to 42 are used as placeholders
*/


/// ENCODER PINS
#define MOTOR1_ENCODER_A 2  //Int0 Pin 2
#define MOTOR1_ENCODER_B 3  //Int1 Pin 3 

#define MOTOR2_ENCODER_A 18 //Int2 Pin 18
#define MOTOR2_ENCODER_B 19 //Int3 Pin 19 

#define MOTOR3_ENCODER_A 30  //Placeholder (set to unused mega pin)
#define MOTOR3_ENCODER_B 31  //Placeholder (set to unused mega pin)

#define MOTOR4_ENCODER_A 32  //Placeholder (set to unused mega pin)
#define MOTOR4_ENCODER_B 33  //Placeholder (set to unused mega pin)

//MOTOR PINS
#ifdef USE_L298_DRIVER
  #define MOTOR_DRIVER L298

  #define MOTOR1_PWM 21
  #define MOTOR1_IN_A 20
  #define MOTOR1_IN_B 1

  #define MOTOR2_PWM 5
  #define MOTOR2_IN_A 8
  #define MOTOR2_IN_B 6

  #define MOTOR3_PWM 22
  #define MOTOR3_IN_A 23
  #define MOTOR3_IN_B 0

  #define MOTOR4_PWM 4
  #define MOTOR4_IN_A 2
  #define MOTOR4_IN_B 3

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif 

#ifdef USE_BTS7960_DRIVER
  #define MOTOR_DRIVER BTS7960  

  #define MOTOR1_PWM 34   //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR1_IN_A 22  
  #define MOTOR1_IN_B 23  

  #define MOTOR2_PWM 35   //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR2_IN_A 24  
  #define MOTOR2_IN_B 25  

  #define MOTOR3_PWM 36   //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR3_IN_A 37  //Placeholder (set to unused mega pin)
  #define MOTOR3_IN_B 38  //Placeholder (set to unused mega pin)

  #define MOTOR4_PWM 39   //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR4_IN_A 40  //Placeholder (set to unused mega pin)
  #define MOTOR4_IN_B 41  //Placeholder (set to unused mega pin)

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif

#ifdef USE_ESC
  #define MOTOR_DRIVER ESC  

  #define MOTOR1_PWM 1 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR1_IN_A 21
  #define MOTOR1_IN_B 20

  #define MOTOR2_PWM 8 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR2_IN_A 5
  #define MOTOR2_IN_B 6

  #define MOTOR3_PWM 0 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR3_IN_A 22
  #define MOTOR3_IN_B 23

  #define MOTOR4_PWM 2 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR4_IN_A 4
  #define MOTOR4_IN_B 3

  #define PWM_MAX 400
  #define PWM_MIN -PWM_MAX
#endif

#define STEERING_PIN 42 //DON'T TOUCH THIS! This is just a placeholder

#endif
