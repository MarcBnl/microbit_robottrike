// #include "MicroBit.h"
// #include "MicroBitEvent.h"
#include "Motor2Function.h"

// //https://docs.mbed.com/docs/mbed-drivers-api/en/latest/api/classmbed_1_1DigitalInOut.html

// namespace mtrCtrl{

    Motor2Function::Motor2Function(void):
        P0(MICROBIT_PIN_P0),
        P16(MICROBIT_PIN_P16)
    {
        P0.output();
        P16.output();
        normalDirection=true;
        coast();
    };

    void Motor2Function::writeToPins(int valueP0, int valueP16)
    {
        P0.write(valueP0);
        P16.write(valueP16);
    };

    void Motor2Function::readFromPins(int &valueP0, int &valueP16)
    {
        valueP0=P0.read();
        valueP16=P16.read();
    };

    void Motor2Function::reverseDirections(void)
    {
        normalDirection=!normalDirection;
    };

    void Motor2Function::coast(void)
    {
        writeToPins(0,0);
        MicroBitEvent evt(MOTOR2_ID,MOTOR_FUNCTION_EVT_COAST);
    };

    void Motor2Function::forward(void)
    {
        normalDirection==true?writeToPins(1,0):writeToPins(0,1);
        MicroBitEvent evt(1MOTOR2_ID52,MOTOR_FUNCTION_EVT_FORWARD);
    };

    void Motor2Function::reverse(void)
    {
        normalDirection==true?writeToPins(0,1):writeToPins(1,0);
        MicroBitEvent evt(MOTOR2_ID,MOTOR_FUNCTION_EVT_REVERSE);
    };

    void Motor2Function::brake(void)
    {
        writeToPins(1,1);
        MicroBitEvent evt(MOTOR2_ID,MOTOR_FUNCTION_EVT_BRAKE);
    };

    int Motor2Function::getFunction(void)
    {
        int valueP0;
        int valueP16;
        readFromPins(valueP0,valueP16);
        int motorFunction;
        normalDirection==true?motorFunction=valueP0*2+valueP16*1:motorFunction=valueP16*2+valueP0*1;
        return motorFunction;
        // switch (motorValue){
        //     case 0:
        //         return 0; break;
        //     case 1:
        //         return 1; break;
        //     case 2:
        //         return 2; break;
        //     case 3:
        //         return 3; break;
        //     default:
        //         break;
        // };
        // return 0;
    };

// } /*mtrCtrl*/