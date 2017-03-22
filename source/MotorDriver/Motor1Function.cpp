// #include "Motor1Function.h"

// //https://docs.mbed.com/docs/mbed-drivers-api/en/latest/api/classmbed_1_1DigitalInOut.html

namespace mtrCtrl{

    Motor1Function::Motor1Function(void):
        P8(MICROBIT_PIN_P8),
        P12(MICROBIT_PIN_P12)
    {
        P8.output();
        P12.output();
        normalDirection=true;
    };

    void Motor1Function::writeToPins(int valueP8, int valueP12)
    {
        P8.write(valueP8);
        P12.write(valueP12);
    };

    void Motor1Function::readFromPins(int &valueP8, int &valueP12)
    {
        valueP8=P8.read();
        valueP12=P12.read();
    };

    void Motor1Function::reverseDirections(void)
    {
        normalDirection=!normalDirection;
    };

    void Motor1Function::coast(void)
    {
        writeToPins(0,0);
        MicrobitEvent evt(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_COAST);
    };

    void Motor1Function::forward(void)
    {
        normalDirection==true?writeToPins(1,0):writeToPins(0,1);
        MicrobitEvent evt(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_FORWARD);
    };

    void Motor1Function::reverse(void)
    {
        normalDirection==true?writeToPins(0,1):writeToPinswrite(1,0);
        MicrobitEvent evt(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_REVERSE);
    };

    void Motor1Function::brake(void)
    {
        writeToPins(1,1);
        MicrobitEvent evt(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_BRAKE);
    };

    MOTORFUNCTIONS Motor1Function::getFunction(void)
    {
        int valueP8;
        int valueP12;
        readFromPins(valueP8,valueP12);
        int motorValue;
        normalDirection==true?motorValue=valueP8*2+valueP12*1:motorValue=valueP12*2+valueP8*1;
        switch (motorValue){
            case 0:
                return COAST; break;
            case 1:
                return REVERSE; break;
            case 2:
                return FORWARD; break;
            case 3:
                return BRAKE; break;
            default:
        };
        return COAST;
    };

} /*mtrCtrl*/