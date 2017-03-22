// #include "Motor2Function.h"

// //https://docs.mbed.com/docs/mbed-drivers-api/en/latest/api/classmbed_1_1DigitalInOut.html

namespace mtrCtrl{

    Motor2Function::Motor2Function(void):
        P0(MICROBIT_PIN_P0),
        P16(MICROBIT_PIN_P16)
    {
        P0.ouput();
        P16.ouput();
        normalDirection=true;
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
    };

    void Motor2Function::forward(void)
    {
        normalDirection==true?writeToPins(1,0):writeToPins(0,1)
    };

    void Motor2Function::reverse(void)
    {
        normalDirection==true?writeToPins(0,1):writeToPins(1,0)
    };

    void Motor2Function::brake(void)
    {
        writeToPins(1,1);
    };

    MOTORFUNCTIONS Motor2Function::getFunction(void)
    {
        int valueP0;
        int valueP16;
        readFromPins(valueP0,valueP16);
        int motorValue;
        normalDirection==true?motorValue=valueP0*2+valuleP16*1:motorValue=valueP16*2+valueP0*1;
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