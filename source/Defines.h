#ifndef DEFINES_H
#define DEFINES_H


#define MOTOR1_ID                   1501  // Motor Control Pins 
#define MOTOR2_ID                   1502  // MOTOR1      MOTOR2
#define MOTOR_FUNCTION_EVT_ANY      -1    // P8  P12     P0  P16
#define MOTOR_FUNCTION_EVT_COAST    0     // 0   0       0   0
#define MOTOR_FUNCTION_EVT_REVERSE  1     // 0   1       0   1
#define MOTOR_FUNCTION_EVT_FORWARD  2     // 1   0       1   0
#define MOTOR_FUNCTION_EVT_BRAKE    3     // 1   1       1   1
#define MOTOR_FUNCTION_EVT_SPIN     4

#define SONAR_ID                    1601
#define SONAR_EVT_0PRCNT            0
#define SONAR_EVT_5PRCNT            1
#define SONAR_EVT_25PRCNT           2
#define SONAR_EVT_50PRCNT           3
#define SONAR_EVT_75PRCNT           4
#define SONAR_EVT_100PRCNT          5

#endif /*DEFINES_H*/