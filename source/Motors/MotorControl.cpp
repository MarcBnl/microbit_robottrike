#include "MotorControl.h"

// namespace mtrCtrl{

    MotorControl::MotorControl(void):
        motor1F(),
        motor2F()
    {      
        //FIXME
        motor1F.reverseDirections();
        //OR
        //motor2F.reverseDirections();
    };

    void MotorControl::setMotorFunction(int function)
    {
        switch (function){
            case 0://COAST:
                motor1F.coast();
                motor2F.coast();
                break;
            case 1://REVERSE:
                motor1F.reverse();
                motor2F.reverse();
                break;
            case 2://FORWARD:
                motor1F.forward();
                motor2F.forward();
                break;
            case 3://BRAKE:
                motor1F.brake();
                motor2F.brake();
                break;
            case 4://SPIN:
                motor1F.forward();
                motor2F.reverse();
                wait_us(spinDuration_us);
                motor1F.coast();
                motor2F.coast();
                break;
            default:
                motor1F.coast();
                motor2F.coast();
                break;
        }
    };

    void MotorControl::getMotorFunction(int &funcM1, int &funcM2)
    {
        funcM1=motor1F.getFunction();
        funcM2=motor2F.getFunction();
    };

// } /*mtrCtrl*/    